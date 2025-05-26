/*
 * File: Pmsm_Foc.h
 *
 * Code generated for Simulink model 'Pmsm_Foc'.
 *
 * Model version                  : 1.151
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr 17 21:20:29 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Execution efficiency
 *    3. Safety precaution
 *    4. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pmsm_Foc_h_
#define RTW_HEADER_Pmsm_Foc_h_
#ifndef Pmsm_Foc_COMMON_INCLUDES_
#define Pmsm_Foc_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Pmsm_Foc_COMMON_INCLUDES_ */

#include "Pmsm_Foc_types.h"
#include <string.h>

/* Storage class 'PmsmDefault', for system '<Root>' */
typedef struct {
  real32_T TrigonometricFunction_o1;   /* '<S59>/Trigonometric Function' */
  real32_T TrigonometricFunction_o2;   /* '<S59>/Trigonometric Function' */
  real32_T Switch2;                    /* '<S46>/Switch2' */
  real32_T Switch2_a;                  /* '<S45>/Switch2' */
  real32_T Gain2;                      /* '<S38>/Gain2' */
  real32_T Add1;                       /* '<S38>/Add1' */
  real32_T Product;                    /* '<S29>/Product' */
  real32_T Product1;                   /* '<S29>/Product1' */
  real32_T Delay1_DSTATE_j;            /* '<S62>/Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S5>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S5>/Unit Delay1' */
  int16_T Delay_DSTATE_b;              /* '<S60>/Delay' */
  uint16_T DataTypeConversion;         /* '<S60>/Data Type Conversion' */
  boolean_T Pwm7_Pwm5_Select;          /* '<S51>/PWM7_PWM5_Select' */
  boolean_T icLoad;                    /* '<S62>/Delay1' */
  boolean_T VF_MODE;                   /* '<S16>/VF' */
  boolean_T Current_Loop_Controller_MODE;/* '<S1>/Current_Loop_Controller' */
} Pmsm_Foc_PmsmDefault;

/* Model entry point functions */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

extern void Pmsm_Foc_initialize(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

/* Code 2 RAM */
#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"

extern void Pmsm_Foc_step(void);

#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

extern void Pmsm_Foc_terminate(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED
#include "Pmsm_MemMap.h"

extern Pmsm_Foc_PmsmDefault PmsmDefault_Pmsm_Foc;/* '<S59>/Trigonometric Function' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED
#include "Pmsm_MemMap.h"

/* Exported data declaration */

/* pmsm trusted bss 16bits */
/* Declaration for custom storage class: TRUSTED_BSS_16BITS */
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_DbgTheta;     /* '<Root>/Dbg_Theta' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_Theta;        /* '<S16>/Switch1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 32bits */
/* Declaration for custom storage class: TRUSTED_BSS_32BITS */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_AlphaVoltCmd; /* '<S56>/Add2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_BetaVoltCmd;  /* '<S56>/Add3' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_BusCurrent;   /* '<S2>/Add1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_D_IGain;      /* '<Root>/D_IGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_D_PGain;      /* '<Root>/D_PGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgDutyU;     /* '<Root>/Dbg_DutyU' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgDutyV;     /* '<Root>/Dbg_DutyV' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgDutyW;     /* '<Root>/Dbg_DutyW' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgIdRef;     /* '<Root>/Dbg_IdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgIqRef;     /* '<Root>/Dbg_IqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgVdRef;     /* '<Root>/Dbg_VdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgVqRef;     /* '<Root>/Dbg_VqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DeadBand;     /* '<Root>/Deadband' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DeadZoneUalpha;/* '<S39>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DeadZoneUbeta;/* '<S39>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DutyU;        /* '<S14>/Gain2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DutyV;        /* '<S14>/Gain3' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DutyW;        /* '<S14>/Gain4' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_EmfComp_Vd;   /* '<S44>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_EmfComp_Vq;   /* '<S44>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FiltedId;     /* '<S11>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FiltedIq;     /* '<S12>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FlxIdRefIn;   /* '<Root>/FlxIdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FlxIqRefIn;   /* '<Root>/FlxIqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IU;           /* '<Root>/Current_U' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IV;           /* '<Root>/Current_V' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IW;           /* '<Root>/Current_W' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_Id;           /* '<S10>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IdRef;        /* '<S8>/Gain5' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_Iq;           /* '<S10>/Subtract' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IqRef;        /* '<S8>/Gain8' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_Is;           /* '<S10>/Sqrt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IuRef;        /* '<S9>/Subtract' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IvRef;        /* '<S9>/Add1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IwRef;        /* '<S9>/Subtract1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_LimitedPhasVBus;/* '<S30>/Product' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_MotorSpeed;   /* '<Root>/MotorSpeed' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_MotorTorque;  /* '<S3>/Product' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_PIVoltCmd;    /* '<S33>/Sqrt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_Q_IGain;      /* '<Root>/Q_IGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_Q_PGain;      /* '<Root>/Q_PGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_RxAddRy;      /* '<S51>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_VBus;         /* '<Root>/VBus' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_VdCmd;        /* '<S19>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_VqCmd;        /* '<S19>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_SensorTheta;  /* '<Root>/Theta' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 8bits */
/* Declaration for custom storage class: TRUSTED_BSS_8BITS */
#define PMSM_START_SEC_TRUSTED_BSS_8BITS
#include "Pmsm_MemMap.h"

extern boolean_T Pmsm_bl_FlxCtrlCmdFlgIn;/* '<Root>/FlxCtrlCmdFlg' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_8BITS
#include "Pmsm_MemMap.h"

extern boolean_T Pmsm_bl_PIVoltSaturatFlg;/* '<S30>/Relational Operator' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_8BITS
#include "Pmsm_MemMap.h"

extern boolean_T Pmsm_bl_Svpwm5or7SelFlg;/* '<S51>/Logical Operator1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_8BITS
#include "Pmsm_MemMap.h"

extern boolean_T Pmsm_bl_ZeroIVldSvpwmOut;/* '<S48>/Compare' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Declaration for custom storage class: TRUSTED_DATA_32BITS */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_AngCompCoeff;/* Referenced by: '<S59>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_DQ_IRefFdbErrLimit_MAX;/* Referenced by: '<S27>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_DeadZoneCompVal;/* Referenced by: '<S38>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_DnSelSvm7Val;/* Referenced by: '<S51>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_EmfVoltCompCoeff;/* Referenced by: '<S43>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_EmfVoltCompLimited;/* Referenced by: '<S43>/Constant5' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_Flux;/* Referenced by: '<S43>/Constant4' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_IdFdbLpfCoeff_C;/* Referenced by: '<S11>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_IqFdbLpfCoeff_C;/* Referenced by: '<S12>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_Kt;  /* Referenced by: '<S3>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_Ld;  /* Referenced by: '<S43>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_Lq;  /* Referenced by: '<S43>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_MotSpdLimit_MAX;/* Referenced by: '<S13>/Constant5' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_Rpm2eRads;/* Referenced by: '<S43>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_SvpwmRMax;/* Referenced by: '<S15>/Rmax' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_UpSelSvm5Val;/* Referenced by: '<S51>/Constant4' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VBus2VdVqLimited;/* Referenced by: '<S30>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VBusCurrGain;/* Referenced by: '<S2>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VBusCurrOffset;/* Referenced by: '<S2>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VBusLimit_MAX;/* Referenced by: '<S17>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VBusLimit_MIN;/* Referenced by: '<S17>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VbusFiltCoeff;/* Referenced by: '<S62>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VfAngIncStep_C;/* Referenced by: '<S60>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VfSpeed_C;/* Referenced by: '<S16>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted data 8bits */
/* Declaration for custom storage class: TRUSTED_DATA_8BITS */
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_AngCompEnable;/* Referenced by: '<S16>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_DeadZoneCompEnable;/* Referenced by: '<S6>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_EmfVoltCompEnable;/* Referenced by: '<S7>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_Svm5ForcEnb;/* Referenced by: '<S51>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_Svm5or7SelEnable;/* Referenced by: '<S51>/Constant6' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS
#include "Pmsm_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Propagation' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/Scope' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Propagation' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Propagation' : Unused code path elimination
 * Block '<S27>/Scope' : Unused code path elimination
 * Block '<S27>/Scope1' : Unused code path elimination
 * Block '<S27>/Scope2' : Unused code path elimination
 * Block '<S6>/Display' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Propagation' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Propagation' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Data Type Propagation' : Unused code path elimination
 * Block '<S7>/Display' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Data Type Propagation' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Propagation' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Propagation' : Unused code path elimination
 * Block '<S15>/Display' : Unused code path elimination
 * Block '<S15>/Display5' : Unused code path elimination
 * Block '<S15>/Display6' : Unused code path elimination
 * Block '<S15>/Display7' : Unused code path elimination
 * Block '<S51>/Scope' : Unused code path elimination
 * Block '<S51>/Scope1' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
 * Block '<S15>/Scope1' : Unused code path elimination
 * Block '<S55>/Display' : Unused code path elimination
 * Block '<S55>/Display1' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Scope4' : Unused code path elimination
 * Block '<S1>/Scope5' : Unused code path elimination
 * Block '<S1>/Scope8' : Unused code path elimination
 * Block '<S16>/Scope' : Unused code path elimination
 * Block '<S16>/Scope1' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Data Type Propagation' : Unused code path elimination
 * Block '<S62>/Scope' : Unused code path elimination
 * Block '<S10>/Gain' : Eliminated nontunable gain of 1
 * Block '<S55>/Gain' : Eliminated nontunable gain of 1
 * Block '<S16>/Signal Copy' : Eliminate redundant signal conversion block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Pmsm_Foc'
 * '<S1>'   : 'Pmsm_Foc/Pmsm_Foc'
 * '<S2>'   : 'Pmsm_Foc/Pmsm_Foc/CalcIbus'
 * '<S3>'   : 'Pmsm_Foc/Pmsm_Foc/CalcMotTorq'
 * '<S4>'   : 'Pmsm_Foc/Pmsm_Foc/CloseLoop_or_OpenLoop_Selection'
 * '<S5>'   : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller'
 * '<S6>'   : 'Pmsm_Foc/Pmsm_Foc/DeadZoneCompens'
 * '<S7>'   : 'Pmsm_Foc/Pmsm_Foc/EmfVoltCompens'
 * '<S8>'   : 'Pmsm_Foc/Pmsm_Foc/IdIqRef_Selection'
 * '<S9>'   : 'Pmsm_Foc/Pmsm_Foc/Idq2IuvwRef'
 * '<S10>'  : 'Pmsm_Foc/Pmsm_Foc/Iuvw2Idqs'
 * '<S11>'  : 'Pmsm_Foc/Pmsm_Foc/LPF'
 * '<S12>'  : 'Pmsm_Foc/Pmsm_Foc/LPF1'
 * '<S13>'  : 'Pmsm_Foc/Pmsm_Foc/MotorSpeedLimited'
 * '<S14>'  : 'Pmsm_Foc/Pmsm_Foc/PwmDutyUVW_Output'
 * '<S15>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM'
 * '<S16>'  : 'Pmsm_Foc/Pmsm_Foc/Theta2SinCos'
 * '<S17>'  : 'Pmsm_Foc/Pmsm_Foc/VBusLimited'
 * '<S18>'  : 'Pmsm_Foc/Pmsm_Foc/Vbus2MotUs'
 * '<S19>'  : 'Pmsm_Foc/Pmsm_Foc/VdVqCmd_Selection'
 * '<S20>'  : 'Pmsm_Foc/Pmsm_Foc/CloseLoop_or_OpenLoop_Selection/Compare To Constant'
 * '<S21>'  : 'Pmsm_Foc/Pmsm_Foc/CloseLoop_or_OpenLoop_Selection/Compare To Constant1'
 * '<S22>'  : 'Pmsm_Foc/Pmsm_Foc/CloseLoop_or_OpenLoop_Selection/Compare To Constant2'
 * '<S23>'  : 'Pmsm_Foc/Pmsm_Foc/CloseLoop_or_OpenLoop_Selection/Compare To Constant3'
 * '<S24>'  : 'Pmsm_Foc/Pmsm_Foc/CloseLoop_or_OpenLoop_Selection/Compare To Constant4'
 * '<S25>'  : 'Pmsm_Foc/Pmsm_Foc/CloseLoop_or_OpenLoop_Selection/Compare To Constant5'
 * '<S26>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/Command_Limited'
 * '<S27>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/PI_Controller'
 * '<S28>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/Command_Limited/Intergral_Windup_LoopBack'
 * '<S29>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/Command_Limited/VdqCmd_Scaled'
 * '<S30>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/Command_Limited/Voltage_Limited'
 * '<S31>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/Command_Limited/Voltage_Limited/Saturation Dynamic'
 * '<S32>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/Command_Limited/Voltage_Limited/Saturation Dynamic1'
 * '<S33>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/Command_Limited/Voltage_Limited/VdVqCmd2VsCmd'
 * '<S34>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/PI_Controller/DeadZone'
 * '<S35>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/PI_Controller/DeadZone1'
 * '<S36>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/PI_Controller/Saturation Dynamic'
 * '<S37>'  : 'Pmsm_Foc/Pmsm_Foc/Current_Loop_Controller/PI_Controller/Saturation Dynamic1'
 * '<S38>'  : 'Pmsm_Foc/Pmsm_Foc/DeadZoneCompens/Subsystem'
 * '<S39>'  : 'Pmsm_Foc/Pmsm_Foc/DeadZoneCompens/Subsystem1'
 * '<S40>'  : 'Pmsm_Foc/Pmsm_Foc/DeadZoneCompens/Subsystem/Saturation Dynamic'
 * '<S41>'  : 'Pmsm_Foc/Pmsm_Foc/DeadZoneCompens/Subsystem/Saturation Dynamic1'
 * '<S42>'  : 'Pmsm_Foc/Pmsm_Foc/DeadZoneCompens/Subsystem/Saturation Dynamic2'
 * '<S43>'  : 'Pmsm_Foc/Pmsm_Foc/EmfVoltCompens/Subsystem'
 * '<S44>'  : 'Pmsm_Foc/Pmsm_Foc/EmfVoltCompens/Subsystem1'
 * '<S45>'  : 'Pmsm_Foc/Pmsm_Foc/EmfVoltCompens/Subsystem/Saturation Dynamic'
 * '<S46>'  : 'Pmsm_Foc/Pmsm_Foc/EmfVoltCompens/Subsystem/Saturation Dynamic1'
 * '<S47>'  : 'Pmsm_Foc/Pmsm_Foc/MotorSpeedLimited/Saturation Dynamic1'
 * '<S48>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM/Compare To Constant3'
 * '<S49>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM/DutyABC_Allocation'
 * '<S50>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM/DutyLMS_Calculation'
 * '<S51>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM/Mode_Selection'
 * '<S52>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM/N_Calc'
 * '<S53>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM/Over_Mudulation'
 * '<S54>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM/Sector_Check'
 * '<S55>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM/iClarke'
 * '<S56>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM/iPark'
 * '<S57>'  : 'Pmsm_Foc/Pmsm_Foc/SVPWM/Mode_Selection/PWM7_PWM5_Select'
 * '<S58>'  : 'Pmsm_Foc/Pmsm_Foc/Theta2SinCos/Compare To Constant1'
 * '<S59>'  : 'Pmsm_Foc/Pmsm_Foc/Theta2SinCos/Subsystem'
 * '<S60>'  : 'Pmsm_Foc/Pmsm_Foc/Theta2SinCos/VF'
 * '<S61>'  : 'Pmsm_Foc/Pmsm_Foc/VBusLimited/Saturation Dynamic'
 * '<S62>'  : 'Pmsm_Foc/Pmsm_Foc/VBusLimited/Subsystem'
 */
#endif                                 /* RTW_HEADER_Pmsm_Foc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
