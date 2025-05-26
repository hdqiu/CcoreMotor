/*
 * MotorControl.c
 *
 *  Created on: 2024Äê12ÔÂ30ÈÕ
 *      Author: Administrator
 */
#include <gdflib.h>
#include <gflib.h>
#include <gmclib.h>
#include <mlib.h>
#include "state_machine.h"
#include "PMSM_appconfig.h"
#include "PMSM_struct.h"
#include "MotorControl_Types.h"
#include "pospe_sensor.h"

extern resolverPospe_t   resolverPospe;	/* Resolver position and speed */
extern resolverPospe_t   resolverPospe_c;	/* Resolver position and speed */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define CURRENT_CTRL_ZERO_CANCELATION (0)

#define AS_PHASE_CURRENTS_MASK (7U)
#define ATO_FREQ_HZ            ((float)20000)
#define CALIB_DURATION_CYCLES  (500U)

#define U_NOMINAL          ((float)60.0)
#define U_LIMIT_FACTOR    (0.54848275573F)
#define U_MAX              ((float)U_NOMINAL * FLOAT_DIVBY_SQRT3)
#define SPEED_MAX          (FLOAT_PI * ATO_FREQ_HZ)

#define KPI_CURRENT_SCALE  (I_MAX / U_MAX)
#define KPI_SPEED_SCALE    (SPEED_MAX / I_MAX)


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static boolean FocFastLoop(pmsmFOC_t *ptr);
static boolean FocSlowLoop(pmsmFOC_t *ptr);


/******************************************************************************
* FreeMASTER TSA tables
******************************************************************************/
/*
 * With TSA enabled, the user describes the global and static variables using
 * so-called TSA tables. There can be any number of tables defined in
 * the project files. Each table does have the identifier which should be
 * unique across the project.
 *
 * Note that you can declare variables as Read-Only or Read-Write.
 * The FreeMASTER driver denies any write access to the Read-Only variables
 * when TSA_SAFETY is enabled.
 */

/***************************************************************************//*!
 *
 * @brief   FAULT state
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 ******************************************************************************/
void stateFault(pmsmFOC_t *ptr)
{
    ptr->cntrState.state = fault;
    ptr->cntrState.event = e_fault;

    HAL_SetPwmOutput(ptr->motorID, PWM_OUT_DISABLE);

    if (ptr->cntrState.switchFaultClear)
    {
        /* Clear permanent faults */
        ptr->faultIDp.R = 0U;

        /* When all Faults cleared prepare for transition to next state */
        ptr->cntrState.readFault        = TRUE;
        ptr->cntrState.switchFaultClear = FALSE;
        ptr->cntrState.event            = e_fault_clear;
    }
}

/***************************************************************************//*!
 *
 * @brief   RESET state
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 * @details clear all application state variables and load default configuration
 *          of all parameters of the control algorithm (PI controllers, etc)
 ******************************************************************************/
void stateReset(pmsmFOC_t *ptr)
{
    ptr->cntrState.state = reset;

    /* IIR1 filter setting */
    ptr->uDcbFbck.IIR1_UdcbFilt.trFiltCoeff.fltA1 = UDCB_IIR_A1;
    ptr->uDcbFbck.IIR1_UdcbFilt.trFiltCoeff.fltB0 = UDCB_IIR_B0;
    ptr->uDcbFbck.IIR1_UdcbFilt.trFiltCoeff.fltB1 = UDCB_IIR_B1;

    ptr->Resolver_SW.fltmotorPP           = MOTOR_PP;
    ptr->Resolver_SW.s32motorPPscale      = MOTOR_PP_GAIN;
    ptr->Resolver_SW.s16motorPPscaleShift = MOTOR_PP_SHIFT;

    /* Scalar control variables */
    ptr->scalarControl.wRotReqRamp.fltRampUp   = (0.09425F);//2.0F * SCALAR_RAMP_UP / SPEED_MAX;
    ptr->scalarControl.wRotReqRamp.fltRampDown =  (0.09425F);//2.0F * SCALAR_RAMP_DOWN / SPEED_MAX;
    /*this is workaround because Freemaster doesn't allow such a value */
    ptr->scalarControl.VHzRatioReq             =  SCALAR_VHZ_FACTOR_GAIN;

    ptr->scalarControl.wElMax    = WEL_MAX;// / SPEED_MAX;
    ptr->scalarControl.wRotElReq = 0.0f;
    ptr->scalarControl.UmReq     = 0.0;

    ptr->scalarControl.integ.f32C1     = SCALAR_INTEG_GAIN;
    ptr->scalarControl.integ.u16NShift = SCALAR_INTEG_SHIFT;

    /*------------------------------------
     * FOC variables
     * ----------------------------------*/
    ptr->calib.calibCntr = CALIB_DURATION_CYCLES;

    ptr->align.duration = ALIGN_DURATION;
    ptr->align.counter  = ptr->align.duration;
    ptr->align.voltage  = ALIGN_VOLTAGE;

    /* D-axis PI parallel current controller */
    ptr->dAxisPIp.fltLowerLimit = -1.0; /* -Udc_max/sqrt3 */
    ptr->dAxisPIp.fltUpperLimit = 1.0;  /* Udc_max/sqrt3 */
    ptr->dAxisPIp.fltPropGain   = D_KP_GAIN * KPI_CURRENT_SCALE;
    ptr->dAxisPIp.fltIntegGain  = D_KI_GAIN * KPI_CURRENT_SCALE;
    ptr->dAxisPIp.fltInK_1      = 0.0;

    /* Q-axis PI parallel current controller */
    ptr->qAxisPIp.fltLowerLimit = -1.0; /* -Udc_max/sqrt3 */
    ptr->qAxisPIp.fltUpperLimit = 1.0;  /* Udc_max/sqrt3 */
    ptr->qAxisPIp.fltPropGain   = Q_KP_GAIN * KPI_CURRENT_SCALE;
    ptr->qAxisPIp.fltIntegGain  = Q_KI_GAIN * KPI_CURRENT_SCALE;
    ptr->qAxisPIp.fltInK_1      = 0.0;

    /* D-axis current loop - zero cancellation by 1st order filer */
    ptr->dAxisZC.trFiltCoeff.fltB0 = D_B0;
    ptr->dAxisZC.trFiltCoeff.fltB1 = D_B1;
    ptr->dAxisZC.trFiltCoeff.fltA1 = D_A1;
    GDFLIB_FilterIIR1Init(&(ptr->dAxisZC));

    /* Q-axis current loop - zero cancellation by 1st order filer */
    ptr->qAxisZC.trFiltCoeff.fltB0 = Q_B0;
    ptr->qAxisZC.trFiltCoeff.fltB1 = Q_B1;
    ptr->qAxisZC.trFiltCoeff.fltA1 = Q_A1;
    GDFLIB_FilterIIR1Init(&(ptr->qAxisZC));

    /* DC-bus voltage ripple elimination parameters */
    ptr->elimDcbRip.fltModIndex    = FLOAT_SQRT3_DIVBY_2;
    ptr->elimDcbRip.fltArgDcBusMsr = 0.0F;

    /*------------------------------------
     * Speed/Position
     * ----------------------------------*/
    ptr->speedPIp.fltPropGain  = 0.001;//SPEED_PI_PROP_GAIN * KPI_SPEED_SCALE;
    ptr->speedPIp.fltIntegGain = 0.0001;//SPEED_PI_INTEG_GAIN * KPI_SPEED_SCALE;

    ptr->speedPIp.fltUpperLimit   =  50.0;
    ptr->speedPIp.fltLowerLimit   = -50.0;
    ptr->speedPIp.fltInK_1        = 0.0F;
    ptr->speedPIp.fltIntegPartK_1 = 0.0F;

    ptr->controlLoop.speedRamp.fltState    = 0.0F;
    ptr->controlLoop.speedRamp.fltRampUp   = SPEED_RAMP_UP;// / SPEED_MAX;
    ptr->controlLoop.speedRamp.fltRampDown = SPEED_RAMP_DOWN;// / SPEED_MAX;

    ptr->cntrState.switchAppReset = FALSE;

    /* default setting of a control mode */
    ptr->cntrState.controlMode = currentCtrl;//
    /* clear initial GD fault */
    ptr->faultID.B.OverLoad  = 0;
    ptr->faultIDp.B.OverLoad = 0;

    /*Initialization state successfully finished */
    ptr->cntrState.event = e_reset_done;


    if(ptr->motorID == MOTORCONTROL_INST_P1)
    {
		//add by qhd offset
//		resolverPospe.offset = MLIB_ConvertPU_F32FLT(MLIB_Div(2.01028,FLOAT_PI));

		/* Resolver ATO observer - Controller parameters */
		resolverPospe.TrackObsrv.pParamPI.fltCC1sc					= POSPE_RES_TO_CC1;
		resolverPospe.TrackObsrv.pParamPI.fltCC2sc					= POSPE_RES_TO_CC2;
		resolverPospe.TrackObsrv.pParamPI.fltUpperLimit				= FLOAT_MAX;
		resolverPospe.TrackObsrv.pParamPI.fltLowerLimit				= FLOAT_MIN;
		/* resolver observer - Integrator parameters */
		resolverPospe.TrackObsrv.pParamInteg.fltC1					= POSPE_RES_TO_INTEG_GAIN;

		/* Clear ATO observer state variables */
		AMCLIB_TrackObsrvInit_FLT(&resolverPospe.TrackObsrv);
    }
    else
    {
        //add by qhd offset
//        resolverPospe_c.offset = MLIB_ConvertPU_F32FLT(MLIB_Div(0.51314,FLOAT_PI));

        /* Resolver ATO observer - Controller parameters */
        resolverPospe_c.TrackObsrv.pParamPI.fltCC1sc					= POSPE_RES_TO_CC1;
        resolverPospe_c.TrackObsrv.pParamPI.fltCC2sc					= POSPE_RES_TO_CC2;
        resolverPospe_c.TrackObsrv.pParamPI.fltUpperLimit				= FLOAT_MAX;
        resolverPospe_c.TrackObsrv.pParamPI.fltLowerLimit				= FLOAT_MIN;
        /* resolver observer - Integrator parameters */
        resolverPospe_c.TrackObsrv.pParamInteg.fltC1					= POSPE_RES_TO_INTEG_GAIN;

        /* Clear ATO observer state variables */
        AMCLIB_TrackObsrvInit_FLT(&resolverPospe_c.TrackObsrv);
    }

}

/***************************************************************************//*!
 *
 * @brief   INIT state - clear state variables
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 * @details clear all application state variables, while algorithm parameters
 *          remain unchanged. It means if user changed the parameters during last
 *          run state, those parameters will not be set to default.
 ******************************************************************************/
void stateInit(pmsmFOC_t *ptr)
{
    ptr->cntrState.state = init;

    HAL_SetPwmOutput(ptr->motorID, PWM_OUT_DISABLE);

    /*------------------------------------
     * Voltages
     * ----------------------------------*/
    ptr->uDQReq.fltArg1     = 0.0F;
    ptr->uDQReq.fltArg2     = 0.0F;
    ptr->uAlBeReq.fltArg1   = 0.0F;
    ptr->uAlBeReq.fltArg2   = 0.0F;

    ptr->scalarControl.integ.f32State = 0.0F;

    /*------------------------------------
     * Currents
     * ----------------------------------*/
    ptr->iDQReq.fltArg1     = 0.0F;
    ptr->iDQReq.fltArg2     = 0.0F;
    ptr->iDQReqZC.fltArg1   = 0.0F;
    ptr->iDQReqZC.fltArg2   = 0.0F;
    ptr->iDQFbck.fltArg1    = 0.0F;
    ptr->iDQFbck.fltArg2    = 0.0F;

    ptr->dAxisPIp.fltInK_1          = 0.0F;
    ptr->dAxisPIp.fltIntegPartK_1   = 0.0F;
    ptr->qAxisPIp.fltInK_1          = 0.0F;
    ptr->qAxisPIp.fltIntegPartK_1   = 0.0F;

    /*------------------------------------
     * Speed / position
     * ----------------------------------*/
    ptr->speedPIp.fltInK_1              = 0.0F;
    ptr->speedPIp.fltIntegPartK_1       = 0.0F;

    ptr->controlLoop.wRotElErr          = 0.0F;
    ptr->controlLoop.wRotElReq          = 0.0F;
    ptr->controlLoop.wRotElReqRamp      = 0.0F;
    ptr->controlLoop.speedRamp.fltState = 0.0F;

    ptr->Resolver_SW.fltThRotElOffset = 0.0F;

    /*------------------------------------
     * FOC general
     ------------------------------------*/
    ptr->align.counter           = ALIGN_DURATION;
    ptr->calib.calibCntr         = CALIB_DURATION_CYCLES;
    ptr->cntrState.speedLoopCntr = 0;

    /*------------------------------------
     * ETPU
     ------------------------------------*/
//    xAngleSpeedParams.eOutputAlignment     = MOTOR_CONTROL_ONTRIGGER_VALUE;
//    xAngleSpeedParams.eValueRepresentation = MOTOR_CONTROL_ELECTRIC_REPRES;

    /* the app was already running, so do deinit first */
    if (ptr->cntrState.event != e_reset_done)
    {
//        MotorControl_DeInit();
//        MotorControl_Init(&MotorControl_Config);
    }

    /* Initialization state successfully finished */
    ptr->cntrState.event = e_init_done;
}

/***************************************************************************//*!
 *
 * @brief   READY state
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 ******************************************************************************/
void stateReady(pmsmFOC_t *ptr)
{

    ptr->cntrState.state = ready;
    ptr->cntrState.event = e_ready;

    if (ptr->appRun_C)
    {
        ptr->cntrState.event = e_app_on;
    }
}

/***************************************************************************//*!
 *
 * @brief   CALIBRATION state - ADC calibration state
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 ******************************************************************************/
void stateCalib(pmsmFOC_t *ptr)
{


    ptr->cntrState.state = calib;
    ptr->cntrState.event = e_calib;

    if (ptr->calib.calibCntr == CALIB_DURATION_CYCLES)                              /* calib start */
    {
        HAL_SetPwmOutput(ptr->motorID, PWM_OUT_ENABLE);
        ptr->calib.calibCntr--;

    }
    else if (ptr->calib.calibCntr == 0U)
    {
//        MotorControl_CalibrationFinish(MOTORCONTROL_INST0, AS_PHASE_CURRENTS_MASK); /* calib finish */

        /* Calibration state successfully finished */
        ptr->cntrState.event = e_calib_done;
    }
    else                                                                            /* calib in progress */
    {
        ptr->calib.calibCntr--;
    }

}

/***************************************************************************//*!
 *
 * @brief   ALIGNMENT state - d-axes rotor alignment, position offset calibration
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 ******************************************************************************/
void stateAlign(pmsmFOC_t *ptr)
{
    ptr->cntrState.state = align;
    ptr->cntrState.event = e_align;

    if (ptr->align.counter == ptr->align.duration)                              /* align start */
    {
//        MotorControl_Enable(MOTORCONTROL_INST0);

        /* Function performs Sin(angle) and Cos (angle), angle = 0; */
        GFLIB_SinCos(0.0F, &ptr->thTransform);

        /* Q-Axis voltage is kept at zero */
        ptr->uDQReq.fltArg1 = ptr->align.voltage;
        ptr->uDQReq.fltArg2 = 0.0F;

        GMCLIB_ParkInv(&ptr->uAlBeReq, &ptr->thTransform, &ptr->uDQReq);

        SWLIBS_3Syst_FLT *pPhAbcDuty = &ptr->pwm.PhABC;
        ptr->svmSector = GMCLIB_SvmStd(pPhAbcDuty, &ptr->uAlBeReq);
        MotorControl_PhaseDutyCyclesType xDutyCycles;
        xDutyCycles.f32DutyCycleA = pPhAbcDuty->fltArg1;
        xDutyCycles.f32DutyCycleB = pPhAbcDuty->fltArg2;
        xDutyCycles.f32DutyCycleC = pPhAbcDuty->fltArg3;
        MotorControl_SetDutyCycles(ptr->motorID, MOTOR_CONTROL_RELATIVE_INTERPRET, xDutyCycles);

        ptr->align.counter--;
    }
    else if (ptr->align.counter == 0U)                                          /* align finish */
    {
        ptr->uDQReq.fltArg1 = (0.0F);
        ptr->uDQReq.fltArg2 = (0.0F);

        /* Store the non-zero electrical position as a position offset */
        ptr->Resolver_SW.fltThRotElOffset = ptr->Resolver_SW.fltThRotEl;

        /* Align state successfully finished */
        ptr->cntrState.event = e_align_done;
    }
    else                                                                        /* align in progress */
    {
        ptr->align.counter--;
    }


}

/***************************************************************************//*!
 *
 * @brief   RUN state
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 ******************************************************************************/
void stateRun(pmsmFOC_t *ptr)
{
    static boolean stateRunStatus = FALSE;
    MotorControl_PhaseDutyCyclesType xDutyCycles;

    ptr->cntrState.state = run;
    ptr->cntrState.event = e_run;

    if (ptr->appRun_C == 0U)
    {
        ptr->cntrState.event = e_app_off;
    }

    /* Arbitration of executing the slow speed loop */
    if (++ptr->cntrState.speedLoopCntr >= SPEED_LOOP_CNTR)
    {
        /* reset speed loop counter */
        ptr->cntrState.speedLoopCntr = 0;

		if(ptr->cntrState.controlMode==scalarCtrl){

				ptr->scalarControl.wRotElReq = (ptr->scalarControl.wRotElReq + 0.05F);

				if(ptr->scalarControl.wRotElReq >= 200.0F)
				{
					ptr->scalarControl.wRotElReq = 200.0F;
				}

			if (!ptr->btSpeedDown)
				ptr->scalarControl.wRotElReq = (ptr->scalarControl.wRotElReq - 0.5F);
		}
		else{
		// Manual speed control using Up/Down switch buttons SW2/SW3
//		if (!ptr->btSpeedUp)
//			ptr->controlLoop.wRotElReq = (ptr->controlLoop.wRotElReq + 0.5F);

//		if (!ptr->btSpeedDown)
//			ptr->controlLoop.wRotElReq = (ptr->controlLoop.wRotElReq - 0.5F);
		}
        /* calculate FOC fast loop - speed loop */
        stateRunStatus = FocSlowLoop(ptr);
    }

    stateRunStatus &= FocFastLoop(ptr);

    SWLIBS_2Syst uAlBeAbsolute;
    uAlBeAbsolute.fltArg1 = ptr->uAlBeReq.fltArg1/U_MAX;  /* (Udc_max/sqrt3) * Ualpha */
    uAlBeAbsolute.fltArg2 = ptr->uAlBeReq.fltArg2/U_MAX;  /* (Udc_max/sqrt3) * Ubeta */

//    SWLIBS_3Syst_FLT *pPhAbcDuty = &ptr->pwm.PhABC;
//    ptr->elimDcbRip.fltArgDcBusMsr = ptr->uDcbFbck.raw * U_DCB_MAX;
//    GMCLIB_ElimDcBusRip(&ptr->uAlBeReqDCB, &uAlBeAbsolute, &ptr->elimDcbRip);
//    ptr->svmSector = GMCLIB_SvmStd(pPhAbcDuty, &ptr->uAlBeReqDCB);
    ptr->svmSector = GMCLIB_SvmStd(&ptr->pwm.PhABC, &uAlBeAbsolute);

    xDutyCycles.f32DutyCycleA = ptr->pwm.PhABC.fltArg1;
    xDutyCycles.f32DutyCycleB = ptr->pwm.PhABC.fltArg2;
    xDutyCycles.f32DutyCycleC = ptr->pwm.PhABC.fltArg3;
    MotorControl_SetDutyCycles(ptr->motorID, MOTOR_CONTROL_RELATIVE_INTERPRET, xDutyCycles);
//    MotorControl_SetDutyCycles(MOTORCONTROL_INST_P1, MOTOR_CONTROL_RELATIVE_INTERPRET, xDutyCycles);
}

/***************************************************************************//*!
 *
 * @brief   Field Oriented Control - fast (current) loop calculations
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 ******************************************************************************/
static boolean FocFastLoop(pmsmFOC_t *ptr)
{
    scalarControl_t *pScalarCnt = &ptr->scalarControl;

    /* Transform the abc current into AlphaBeta frame */
    GMCLIB_Clark(&ptr->iAlBeFbck, &ptr->iAbcFbck);

    /* Application Cascade Control Structure - controlled by MCAT */
    switch (ptr->cntrState.controlMode)
    {
    /* Scalar (V/f) control mode - open loop control */
    case scalarCtrl:
        /* ramp in reference speed feed-forward path */
        ptr->scalarControl.wRotElReqRamp = GFLIB_Ramp(pScalarCnt->wRotElReq, &(pScalarCnt->wRotReqRamp));

        /* generated electrical position in Frac32 format */
        pScalarCnt->thScalarEl = GFLIB_IntegratorTR_F32(MLIB_ConvertPU_F32FLT(MLIB_Div(pScalarCnt->wRotElReqRamp, pScalarCnt->wElMax)),
                                                        &(pScalarCnt->integ));

        /* Required voltage = VHzRatio * Required Frequency (wRotEl required) */
        pScalarCnt->UmReq = MLIB_Mul(pScalarCnt->VHzRatioReq, pScalarCnt->wRotElReqRamp);

        /* transformation angle */
        /* Function performs Sin(angle) and Cos (angle), angle = pScalarCnt->thScalarEl; */
        GFLIB_SinCos(MLIB_Mul(MLIB_ConvertPU_FLTF32(pScalarCnt->thScalarEl), FLOAT_PI), &ptr->thTransform);

        ptr->uDQReq.fltArg1 = 0;
        ptr->uDQReq.fltArg2 = pScalarCnt->UmReq;

        break;

    /* Voltage FO control mode */
    case voltageCtrl:
        /* Function performs Sin(angle) and Cos (angle), angle = ptr->controlLoop.thRotEl; */
        GFLIB_SinCos(ptr->controlLoop.thRotEl, &ptr->thTransform);
        GMCLIB_Park(&ptr->iDQFbck, &ptr->thTransform, &ptr->iAlBeFbck);
        break;

    /* Current FO control mode */
    case currentCtrl:

    /* Speed FO control mode */
    case speedCtrl:
        /* Function performs Sin(angle) and Cos (angle), angle = ptr->controlLoop.thRotEl; */
        GFLIB_SinCos(ptr->controlLoop.thRotEl, &ptr->thTransform);

        GMCLIB_Park(&ptr->iDQFbck, &ptr->thTransform, &ptr->iAlBeFbck);

#if (CURRENT_CTRL_ZERO_CANCELATION == 1)
        ptr->iDQReqZC.fltArg1 = GDFLIB_FilterIIR1(ptr->iDQReq.fltArg1, &(ptr->dAxisZC));
        ptr->iDQReqZC.fltArg2 = GDFLIB_FilterIIR1(ptr->iDQReq.fltArg2, &(ptr->qAxisZC));
#else
        ptr->iDQReqZC.fltArg1 = ptr->iDQReq.fltArg1;
        ptr->iDQReqZC.fltArg2 = ptr->iDQReq.fltArg2;
#endif

        ptr->iDQErr.fltArg1 = MLIB_Sub(ptr->iDQReqZC.fltArg1, ptr->iDQFbck.fltArg1);
        ptr->iDQErr.fltArg2 = MLIB_Sub(ptr->iDQReqZC.fltArg2, ptr->iDQFbck.fltArg2);

        /* 95% of available DCbus recalculated to phase voltage = 0.95*uDCB/sqrt(3) */
        ptr->dAxisPIp.fltUpperLimit = MLIB_Mul(U_LIMIT_FACTOR, ptr->uDcbFbck.filt);
        ptr->dAxisPIp.fltLowerLimit = MLIB_Neg(ptr->dAxisPIp.fltUpperLimit);
        ptr->uDQReq.fltArg1 = GFLIB_ControllerPIpAW(ptr->iDQErr.fltArg1, &ptr->dAxisPIp);

        ptr->qAxisPIp.fltUpperLimit = MLIB_Mul(U_LIMIT_FACTOR, ptr->uDcbFbck.filt);
        ptr->qAxisPIp.fltLowerLimit = MLIB_Neg(ptr->qAxisPIp.fltUpperLimit);
        ptr->uDQReq.fltArg2 = GFLIB_ControllerPIpAW(ptr->iDQErr.fltArg2, &ptr->qAxisPIp);

        break;
    }

    /* DQ required voltages transformed to AlphaBeta frame */
    GMCLIB_ParkInv(&ptr->uAlBeReq, &ptr->thTransform, &ptr->uDQReq);

    return TRUE;
}

/***************************************************************************//*!
 *
 * @brief   Field Oriented Control - slow loop calculations
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 ******************************************************************************/
static boolean FocSlowLoop(pmsmFOC_t *ptr)
{
	const float omegaRotElLowThresh = (float)5.0 / SPEED_MAX;

    ptr->controlLoop.wRotElReqRamp = GFLIB_Ramp(ptr->controlLoop.wRotElReq, &(ptr->controlLoop.speedRamp));

    /* Speed FO control mode from MCAT */
    if (ptr->cntrState.controlMode == speedCtrl)
    {
        ptr->controlLoop.wRotElErr = MLIB_Sub(ptr->controlLoop.wRotElReqRamp, ptr->controlLoop.wRotEl);
        if ((MLIB_Abs(ptr->controlLoop.wRotElReqRamp) < omegaRotElLowThresh) &&
        	(MLIB_Abs(ptr->controlLoop.wRotElErr) < omegaRotElLowThresh))
        {
        	ptr->iDQReq.fltArg2 = 0.0f;
        }
        else
        {
			ptr->iDQReq.fltArg2 = GFLIB_ControllerPIpAW(ptr->controlLoop.wRotElErr, &(ptr->speedPIp));
        }
    }

    return TRUE;
}


/***************************************************************************//*!
 *
 * @brief   Fault Detect function
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 ******************************************************************************/
boolean FaultDetect(pmsmFOC_t *ptr)
{
    boolean faultDetectiontEvent = FALSE;

    /* Temporary Faults */
    /* TRIP:   Phase A over-current detected */
    ptr->faultID.B.OverPhaseACurrent = (ptr->iAbcFbck.fltArg1 > MLIB_Mul(I_PH_OVER, 0.9F)) ? TRUE : FALSE;

    /* TRIP:   Phase B over-current detected */
    ptr->faultID.B.OverPhaseBCurrent = (ptr->iAbcFbck.fltArg2 > MLIB_Mul(I_PH_OVER, 0.9F)) ? TRUE : FALSE;

    /* TRIP:   Phase C over-current detected */
    ptr->faultID.B.OverPhaseCCurrent = (ptr->iAbcFbck.fltArg3 > MLIB_Mul(I_PH_OVER, 0.9F)) ? TRUE : FALSE;

    /* TRIP:   DC-bus under-voltage */
    ptr->faultID.B.UnderDCBusVoltage = (ptr->uDcbFbck.raw < MLIB_Div(U_DCB_UNDER, 0.9F)) ? TRUE : FALSE;

    /* TRIP:   DC-bus over-voltage */
    ptr->faultID.B.OverDCBusVoltage = (ptr->uDcbFbck.raw > U_DCB_TRIP) ? TRUE : FALSE;


    /* Pending Faults */
    if (ptr->cntrState.state != fault)
    {
        /* Fault:   Phase A over-current detected */
        ptr->faultIDp.B.OverPhaseACurrent = (ptr->iAbcFbck.fltArg1 > I_PH_OVER) ? TRUE : ptr->faultIDp.B.OverPhaseACurrent;

        /* Fault:   Phase B over-current detected */
        ptr->faultIDp.B.OverPhaseBCurrent = (ptr->iAbcFbck.fltArg2 > I_PH_OVER) ? TRUE : ptr->faultIDp.B.OverPhaseBCurrent;

        /* Fault:   Phase C over-current detected */
        ptr->faultIDp.B.OverPhaseCCurrent = (ptr->iAbcFbck.fltArg3 > I_PH_OVER) ? TRUE : ptr->faultIDp.B.OverPhaseCCurrent;

    }

    /* If pending fault is present, the fault should be detected */
    if (ptr->faultIDp.R != 0U)
    {
        faultDetectiontEvent = TRUE;
    }

    return faultDetectiontEvent;
}
