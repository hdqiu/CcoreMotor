/*==================================================================================================
*   Copyright 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms. By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
==================================================================================================*/

#ifndef PMSM_STRUCT_H_
#define PMSM_STRUCT_H_

/******************************************************************************
 * Includes
 ******************************************************************************/
#include "SWLIBS_Typedefs.h"
//#include "Resolver.h"
//#include "ATO.h"
//#include "Current_meas.h"
//#include "Voltage_meas.h"
//#include "MC33937_spi_routines.h"
//#include "MC33937_routines.h"
//#include "Voltage_gener.h"

#include "gflib.h"
#include "gmclib.h"
#include "gdflib.h"

/******************************************************************************
 | Typedefs and structures       (scope: module-local)
 -----------------------------------------------------------------------------*/
typedef enum
{
    encoder     = 0,
    resolver    = 1,
    sensorless  = 2
} sensorOptions_t; /* Application position/speed feedback type*/

typedef enum
{
    scalarCtrl  = 0,
    voltageCtrl = 1,
    currentCtrl = 2,
    speedCtrl   = 3
} focCascadeStruc; /* Application cascade control type - aligned with MCAT*/

typedef enum
{
    reset = 0,
    init  = 1,
    fault = 2,
    ready = 3,
    calib = 4,
    align = 5,
    run   = 6
} AppStates; /* Application state identification user type*/

typedef enum
{
    e_reset         = 0,
    e_reset_done    = 1,
    e_fault         = 2,
    e_fault_clear   = 3,
    e_init_done     = 4,
    e_ready         = 5,
    e_app_on        = 6,
    e_calib         = 7,
    e_calib_done    = 8,
    e_align         = 9,
    e_align_done    = 10,
    e_run           = 11,
    e_app_off       = 12
} AppEvents; /* Application event identification user type*/

/*------------------------------------------------------------------------*//*!
@brief  Structure defines controller board available user buttons and switch
*//*-------------------------------------------------------------------------*/
typedef struct{
    volatile tU16   upButton;	// SW2 button
    volatile tU16   downButton;	// SW3 button
    volatile tU16   flipFlop;	// SW Run
}userButtonConfig_t;

/*! Application fault status user type */
typedef union
{
    volatile tU32 R;
    struct
    {
        volatile tU32 CTU_Error         : 1;    /* Error in CTU h/w initialization*/
        volatile tU32 ADC_Error         : 1;    /* Error in ADC h/w initialization*/
        volatile tU32 FLEXPWM_Error     : 1;    /* Error in FlexPWM h/w initialization */
        volatile tU32                   : 4;    /* RESERVED */
        volatile tU32 InitError         : 1;    /* Error during app. initialization */
        volatile tU32 CalibError        : 1;    /* Error during calibration */
        volatile tU32 AlignError        : 1;    /* Error during alignment */
        volatile tU32 FOCError          : 1;    /* Error during alignment */
        volatile tU32                   : 10;   /* RESERVED */
        volatile tU32 OffCancError      : 1;    /* Offset Cancellation Error flag */
        volatile tU32 OverPhaseCCurrent : 1;    /* OverCurrent fault flag */
        volatile tU32 OverPhaseBCurrent : 1;    /* OverCurrent fault flag */
        volatile tU32 OverPhaseACurrent : 1;    /* OverCurrent fault flag */
        volatile tU32 OverHeating       : 1;    /* Overheating fault flag */
        volatile tU32 WrongHardware     : 1;    /* Wrong hardware fault flag */
        volatile tU32 MainsFault        : 1;    /* Mains out of range */
        volatile tU32 OverLoad          : 1;    /* Overload Flag */
        volatile tU32 OverDCBusCurrent  : 1;    /* OverCurrent fault flag */
        volatile tU32 UnderDCBusVoltage : 1;    /* Undervoltage fault flag */
        volatile tU32 OverDCBusVoltage  : 1;    /* Overvoltage fault flag */
    } B;
} AppFaultStatus; /* Application fault status user type*/

/*------------------------------------------------------------------------*//*!
 @brief  Structure containing raw ADC results
 *//*-------------------------------------------------------------------------*/
typedef struct
{
    AppStates           state;                  /* Application states of a State Machine */
    AppEvents           event;                  /* Application events of a State Machine */
    tBool               switchAppOnOff;         /* Application On/Off s/w switch */
    tBool               switchAppOnOffState;    /* Last value of switchAppOnOff */
    tBool               switchFaultClear;       /* Clear faults s/w switch */
    tBool               switchAppReset;         /* Reset the application, call RESET state */
    tBool               loadDefSetting;			/* load default setting of FOC algorithm */
    sensorOptions_t     switchSensor;   		/* Choose encoder/resolver/sensorless position/speed feedback */
    tBool               readFault;				/* Read fault status */
    tS16                ledFlashCounter;		/* counter for LED toggle period */
    focCascadeStruc     controlMode;			/* defines the control mode within a control structure; range(0 - 3) */

    tS16                speedLoopCntr;          /* rate between speed and current loop */
} driveStates_t;

/*------------------------------------------------------------------------*//*!
 @brief  Structure containing raw ADC results
 *//*-------------------------------------------------------------------------*/
typedef struct
{
    tFrac32                     thScalarEl;		/* El. position entering the scalar control */
    tFloat                      wRotElReq;		/* Required frequency [in rad/s] of supply voltage for scalar control */
    tFloat                      wRotElReqRamp;  /* Required frequency [in rad/s] as a ramp */
    tFloat                      wElMax; 		/* Required frequency as a ramp */
    tFloat                      UmReq;			/* Required magnitude of supply voltage for scalar control */
    tFloat                      VHzRatioReq;	/* V/f ratio */
    GFLIB_INTEGRATOR_TR_T_F32   integ;          /* F32 integrator -> position wrapping around +-1 */
    GFLIB_RAMP_T                wRotReqRamp;
} scalarControl_t;

/*------------------------------------------------------------------------*//*!
 @brief  Structure containing position/speed module variables
 *//*-------------------------------------------------------------------------*/
typedef struct
{
    tFloat          thRotEl;		/* El. position entering to the control loop */
    tFloat          wRotEl;			/* El. speed entering to the control loop */
    tFloat          wRotElReq;		/* Required el. speed */
    tFloat          wRotElReqRamp;	/* Required el. speed converted to the ramp shape */
    tFloat          wRotElErr;		/* Error of the el. speed entering to speed controller */
    tS16            speedLoopCntr;	/* rate between speed and current loop */

    GFLIB_RAMP_T    speedRamp;		/* Speed ramp function */
} controlLoop_t;

/*------------------------------------------------------------------------*//*!
 @brief  Structure containing position/speed module variables
 *//*-------------------------------------------------------------------------*/
typedef struct
{
    tFloat  voltage;    /* DC voltage used for rotor alignment - default */
    tFloat  current;    /* DC current might be use for alignment as well */

    tU16    counter;	/* defines the ALIGN state duration */
    tU16    duration;	/* defines the ALIGN state duration */
} alignment_t;

typedef struct
{
    // userLedConfig_t             ledIndic;	/* user LEDs h/w initialization */
    userButtonConfig_t          buttons;		/* user buttons and switch h/w initialization */
//    resolver_hw_cfg_t           Resolver;       /* resolver peripheral h/w initialization */
//    ph_current_meas_hw_cfg_t    phCurrents;     /* phase currents meas. h/w initialization */
//    dcb_voltage_meas_hw_cfg_t   uDcb;           /* DC-bus voltage meas. h/w initialization */
//    MC33937_hw_cfg_t            MC33937;        /* 3-ph pre-driver MC33937 h/w initialization */
//    flexPWM_hw_cfg_t            flexPWM;        /* FlexPWM module h/w initialization */
} S32K3XX_DevKit_t;


/*------------------------------------------------------------------------*//*!
 @brief  Structure containing
 *//*-------------------------------------------------------------------------*/
typedef struct                                                                              // TODO just temporary
{
    tU32 u16Sub0;
    tU32 u16Sub1;
    tU32 u16Sub2;
    tU32 u16Sub3;
} flexPWM_submodules;

/*------------------------------------------------------------------------*//*!
 @brief  Structure containing
 *//*-------------------------------------------------------------------------*/
typedef struct                                                                              // TODO just temporary
{
    SWLIBS_3Syst_FLT PhABC;
    flexPWM_submodules DutyCycle;

    volatile tU32 moduloSub0;
    volatile tU32 moduloSub1;
    volatile tU32 moduloSub2;
} flexPWM_sw_t;

typedef struct
{
    volatile tU16 calibCntr;
//    volatile tU16 calibDone;
//    volatile tU16 calibInitDone;
} phCurrent_calib_t;

typedef struct
{
    tFloat    raw;   /*! raw value */
    tFloat    filt;  /*! filtered value */
} filtSpeed_t;

typedef struct
{
//    tFloat          fltThRotErr;        /* Position (theta) error entering the ATO algorithm */
    tFloat          fltThRotMec;        /* Mechanical (0-360deg) position */
    tFloat          fltThRotEl;         /* Electrical position of the motor */
    tFloat          fltThRotElOffset;   /* Electrical position of the motor */

    filtSpeed_t     wRotMec;            /* Angular mechanical speed [rads-1] of the motor */
    filtSpeed_t     wRotEl;             /* Angular electrical speed [rads-1] of the motor */

    tFloat          fltmotorPP;             /* number of motor pole-pairs */
    tFrac32         s32motorPPscale;        /* Scale of motor pole pairs - fixed point interpretation */
    tS16            s16motorPPscaleShift;   /* Scale of motor pole pairs - fixed point interpretation */
} ATO_observer_t;

/*------------------------------------------------------------------------*//*!
 @brief  Structure contains data of measured phase currents, DC offsets and MA filter
 *//*-------------------------------------------------------------------------*/
typedef struct
{
    SWLIBS_3Syst_FLT    raw;
    SWLIBS_3Syst_FLT    filt;
    SWLIBS_3Syst_FLT    dcOffset;

    phCurrent_calib_t   calib;

    tU32                svmSector;   /* Space Vector Modulation sector */

    GDFLIB_FILTER_MA_T  MAF_PhA;	 /* Moving average filter setting */
    GDFLIB_FILTER_MA_T  MAF_PhB;	 /* Moving average filter setting */
    GDFLIB_FILTER_MA_T  MAF_PhC;	 /* Moving average filter setting */
} ph_current_meas_data_t;

typedef struct
{
    tFloat raw;     /*! raw value */
    tFloat filt;    /*! filtered value */

    GDFLIB_FILTER_IIR1_T IIR1_UdcbFilt;  /* DC bus voltage filter settings */
} dcb_voltage_meas_data_t;

/*------------------------------------------------------------------------*//*!
 @brief  Structure containing the FOC structure, sensors, actuator, control variables
 *//*-------------------------------------------------------------------------*/
/*! General structure for  */
typedef struct
{
    AppFaultStatus              faultID;        /* Application faults */
    AppFaultStatus              faultIDp;       /* Application fault flags */
    tU32                        svmSector;      /* Space Vector Modulation sector */
    SWLIBS_2Syst                iDQFbck;        /* dq - axis feedback currents */
    SWLIBS_2Syst                iDQReq;         /* dq - axis required currents, given by speed PI */
    SWLIBS_2Syst                iDQReqZC;       /* Transfer function zeros cancellation in current branch */
    SWLIBS_2Syst                iDQErr;         /* Error between the reference and feedback signal */
    SWLIBS_2Syst                uDQReq;         /* dq - axis required voltages given by current PIs */
    SWLIBS_2Syst                thTransform;    /* Transformation angle - for Park transformation */
    SWLIBS_2Syst                iAlBeFbck;      /* Alpha/Beta - axis feedback currents */
    SWLIBS_2Syst                uAlBeReq;       /* Required dq currents transformed into the Alpha/Beta orth. system */
    SWLIBS_2Syst                uAlBeReqDCB;    /* Alpha/Beta required voltages after DC Bus ripple elimination */

    GMCLIB_ELIMDCBUSRIP_T       elimDcbRip;     /* Predefined structure related to DC Bus voltage ripple elimination */

    GDFLIB_FILTER_IIR1_T        dAxisZC;		/* d-axis current zero cancellation */
    GDFLIB_FILTER_IIR1_T        qAxisZC;		/* q-axis current zero cancellation */
    GFLIB_CONTROLLER_PIAW_P_T   dAxisPIp;		/* d-axis current PI controller */
    GFLIB_CONTROLLER_PIAW_P_T   qAxisPIp;		/* q-axis current PI controller */
    GFLIB_CONTROLLER_PIAW_P_T   speedPIp;       /* Speed Loop PI controller */

    scalarControl_t             scalarControl;	/* Scalar Control states variables */
    driveStates_t               cntrState;		/* Control states variables */
    controlLoop_t               controlLoop;	/* Position/Speed variables in Speed control loop */

    alignment_t                 align;			/* Alignment procedure */
    phCurrent_calib_t           calib;

    SWLIBS_3Syst_FLT            iAbcFbck;       /* SENSOR - three phases current feedback */
//    ph_current_meas_data_t   iAbcFbck;
    dcb_voltage_meas_data_t     uDcbFbck;		/* SENSOR - raw/filtered value of the DCbus voltage feedback */
//    resolver_data_t             Resolver;		/* SENSOR - resolver s/w data type */
    ATO_observer_t              Resolver_SW;	/* SENSOR - Angle Tracking Observer s/w data type */
    flexPWM_sw_t                pwm;			/* ACTUATOR - flexPWM s/w data type */
//    MC33937_T                   MC33937;		/* ACTUATOR - 3-ph. pre-driver s/w data type */

    S32K3XX_DevKit_t            S32K3XX_HW;	/* HW initialization of DevKit related modules */

    volatile tU8                btSpeedUp;      /* button on power stage to speed up Motor */
    volatile tU8                btSpeedDown;    /* button on power stage to slow down Motor */

    tU8                         motorID;        /* unique motor identifier */
    volatile tU8                         appRun_C;
} pmsmFOC_t;

#endif /* PMSM_STRUCT_H_ */
