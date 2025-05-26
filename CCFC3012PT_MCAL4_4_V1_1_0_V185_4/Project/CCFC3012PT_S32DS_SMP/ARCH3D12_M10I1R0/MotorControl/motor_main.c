/*
 * motor_main.c
 *
 *  Created on: 2024年12月27日
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
#include "Sdadc_Rdc.h"
#include "Res_SoftAngleCalc.h"

__attribute__ ((section (".cpu0_dtcm_data"))) pmsmFOC_t FOC_P1;
__attribute__ ((section (".cpu1_dtcm_data"))) pmsmFOC_t FOC_P3;

extern Sdadc_Rdc g_RdcSdadc_a;
extern Sdadc_Rdc g_RdcSdadc_b;

resolverPospe_t   resolverPospe;	/* Resolver position and speed */
resolverPospe_t   resolverPospe_c;	/* Resolver position and speed */

/***************************************************************************//*!
 *
 * @brief   Get feedback signals from motor (currents, DCB voltage, position, speed)
 *
 * @param   pointer to structure of pmsmFOC_t type (defined in PMSM_struct.h)
 *
 * @return  none
 *
 ******************************************************************************/
void GetMotorControlVariables(pmsmFOC_t *ptr)
{
    tFrac32 sThRotMech, sThRotEl, sThRotElOffset;
    MotorControl_AnalogInputsType xAnalogOutputs;

    /* Phase Currents and DCB Voltage ***/
    if(ptr->motorID == MOTORCONTROL_INST_P3)
    {
    	MotorControl_GetAnalogInputs(MOTORCONTROL_INST_P3, MOTOR_CONTROL_RELATIVE_INTERPRET, &xAnalogOutputs);
    }
    else
    {
    	MotorControl_GetAnalogInputs(MOTORCONTROL_INST_P1, MOTOR_CONTROL_RELATIVE_INTERPRET, &xAnalogOutputs);
    }

    ptr->iAbcFbck.fltArg1 = xAnalogOutputs.f32PhaseCurrentA;
    ptr->iAbcFbck.fltArg2 = xAnalogOutputs.f32PhaseCurrentB;
    ptr->iAbcFbck.fltArg3 = xAnalogOutputs.f32PhaseCurrentC;
    ptr->uDcbFbck.raw   =  xAnalogOutputs.f32DCBusVoltage;
    ptr->uDcbFbck.filt = GDFLIB_FilterIIR1(ptr->uDcbFbck.raw, &ptr->uDcbFbck.IIR1_UdcbFilt);

}

void IPhDmaCbFunction_P1(void)
{
	static boolean faultDetected = FALSE;

	//计算旋变角度
	SuspendAllInterrupts();
	Res_PWMupdateCalc(&g_RdcSdadc_a, &ResXBPare_a);
    ResumeAllInterrupts();

	GetMotorControlVariables(&FOC_P1);

	FOC_P1.Resolver_SW.fltThRotEl = g_RdcSdadc_a.angleTrk.angleEst;

	FOC_P1.controlLoop.thRotEl = (g_RdcSdadc_a.angleTrk.angleEst - FOC_P1.Resolver_SW.fltThRotElOffset);
	if(FOC_P1.controlLoop.thRotEl > PI)
	{
		FOC_P1.controlLoop.thRotEl = FOC_P1.controlLoop.thRotEl - 2*PI;
	}
	if(FOC_P1.controlLoop.thRotEl < -PI)
	{
		FOC_P1.controlLoop.thRotEl = FOC_P1.controlLoop.thRotEl + 2*PI;
	}

	FOC_P1.controlLoop.wRotEl = g_RdcSdadc_a.angleTrk.speedLpf.out;

    state_table[FOC_P1.cntrState.event][FOC_P1.cntrState.state](&FOC_P1);

    if (FOC_P1.cntrState.state != reset)
    {
        faultDetected = TRUE;
        faultDetected &= FaultDetect(&FOC_P1);
    }
    if (faultDetected)
    {
        FOC_P1.cntrState.event = e_fault;
    }
}

void IPhDmaCbFunction_P3(void)
{
	static boolean faultDetected = FALSE;

	//计算旋变角度
	SuspendAllInterrupts();
	Res_PWMupdateCalc(&g_RdcSdadc_b, &ResXBPare_b);
    ResumeAllInterrupts();

	GetMotorControlVariables(&FOC_P3);

	FOC_P3.Resolver_SW.fltThRotEl = g_RdcSdadc_b.angleTrk.angleEst;

	FOC_P3.controlLoop.thRotEl = (g_RdcSdadc_b.angleTrk.angleEst - FOC_P3.Resolver_SW.fltThRotElOffset);
	if(FOC_P3.controlLoop.thRotEl > PI)
	{
		FOC_P3.controlLoop.thRotEl = FOC_P3.controlLoop.thRotEl - 2*PI;
	}
	if(FOC_P3.controlLoop.thRotEl < -PI)
	{
		FOC_P3.controlLoop.thRotEl = FOC_P3.controlLoop.thRotEl + 2*PI;
	}

	FOC_P3.controlLoop.wRotEl = g_RdcSdadc_b.angleTrk.speedLpf.out;


    state_table[FOC_P3.cntrState.event][FOC_P3.cntrState.state](&FOC_P3);

    if (FOC_P3.cntrState.state != reset)
    {
        faultDetected = TRUE;
        faultDetected &= FaultDetect(&FOC_P3);
    }
    if (faultDetected)
    {
        FOC_P3.cntrState.event = e_fault;
    }

}

void Motor_Id_Init()
{
    FOC_P1.motorID = MOTORCONTROL_INST_P1;
    FOC_P3.motorID = MOTORCONTROL_INST_P3;
}

