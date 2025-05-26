/*
 * File: Pmsm_Foc_MotB.h
 *
 * Code generated for Simulink model 'Pmsm_Foc_MotB'.
 *
 * Model version                  : 1.156
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr 17 21:14:45 2025
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

#ifndef RTW_HEADER_Pmsm_Foc_MotB_h_
#define RTW_HEADER_Pmsm_Foc_MotB_h_
#ifndef Pmsm_Foc_MotB_COMMON_INCLUDES_
#define Pmsm_Foc_MotB_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Pmsm_Foc_MotB_COMMON_INCLUDES_ */

#include "Pmsm_Foc_MotB_types.h"
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
  int16_T Delay_DSTATE_p;              /* '<S60>/Delay' */
  uint16_T DataTypeConversion;         /* '<S60>/Data Type Conversion' */
  boolean_T Pwm7_Pwm5_Select;          /* '<S51>/PWM7_PWM5_Select' */
  boolean_T icLoad;                    /* '<S62>/Delay1' */
  boolean_T VF_MODE;                   /* '<S16>/VF' */
  boolean_T Current_Loop_Controller_MODE;/* '<S1>/Current_Loop_Controller' */
} Pmsm_Foc_MotB_PmsmDefault;

/* Model entry point functions */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_Foc_MotB_initialize(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Code 2 RAM */
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_Foc_MotB_step(void);

#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_Foc_MotB_terminate(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

extern Pmsm_Foc_MotB_PmsmDefault PmsmDefault_Pmsm_Foc_MotB;/* '<S59>/Trigonometric Function' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Exported data declaration */

/* pmsm trusted bss 16bits */
/* Declaration for custom storage class: TRUSTED_BSS_16BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_DbgTheta_B;   /* '<Root>/Dbg_Theta' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_SensorTheta_B;/* '<Root>/Theta' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_Theta_B;      /* '<S16>/Switch1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 32bits */
/* Declaration for custom storage class: TRUSTED_BSS_32BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_AlphaVoltCmd_B;/* '<S56>/Add2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_BetaVoltCmd_B;/* '<S56>/Add3' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_BusCurrent_B; /* '<S2>/Add1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_D_IGain_B;    /* '<Root>/D_IGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_D_PGain_B;    /* '<Root>/D_PGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgDutyU_B;   /* '<Root>/Dbg_DutyU' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgDutyV_B;   /* '<Root>/Dbg_DutyV' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgDutyW_B;   /* '<Root>/Dbg_DutyW' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgIdRef_B;   /* '<Root>/Dbg_IdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgIqRef_B;   /* '<Root>/Dbg_IqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgVdRef_B;   /* '<Root>/Dbg_VdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DbgVqRef_B;   /* '<Root>/Dbg_VqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DeadBand_B;   /* '<Root>/Deadband' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DeadZoneUalpha_B;/* '<S39>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DeadZoneUbeta_B;/* '<S39>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DutyU_B;      /* '<S14>/Gain2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DutyV_B;      /* '<S14>/Gain3' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_DutyW_B;      /* '<S14>/Gain4' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_EmfComp_Vd_B; /* '<S44>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_EmfComp_Vq_B; /* '<S44>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FiltedId_B;   /* '<S11>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FiltedIq_B;   /* '<S12>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FlxIdRefIn_B; /* '<Root>/FlxIdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_FlxIqRefIn_B; /* '<Root>/FlxIqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IU_B;         /* '<Root>/Current_U' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IV_B;         /* '<Root>/Current_V' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IW_B;         /* '<Root>/Current_W' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IdRef_B;      /* '<S8>/Gain5' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_Id_B;         /* '<S10>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IqRef_B;      /* '<S8>/Gain8' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_Iq_B;         /* '<S10>/Subtract' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_Is_B;         /* '<S10>/Sqrt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IuRef_B;      /* '<S9>/Subtract' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IvRef_B;      /* '<S9>/Add1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_IwRef_B;      /* '<S9>/Subtract1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_LimitedPhasVBus_B;/* '<S30>/Product' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_MotorSpeed_B; /* '<Root>/MotorSpeed' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_MotorTorque_B;/* '<S3>/Product' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_PIVoltCmd_B;  /* '<S33>/Sqrt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_Q_IGain_B;    /* '<Root>/Q_IGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_Q_PGain_B;    /* '<Root>/Q_PGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_RxAddRy_B;    /* '<S51>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_VBus_B;       /* '<Root>/VBus' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_VdCmd_B;      /* '<S19>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_VqCmd_B;      /* '<S19>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 8bits */
/* Declaration for custom storage class: TRUSTED_BSS_8BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern boolean_T Pmsm_bl_FlxCtrlCmdFlgIn_B;/* '<Root>/FlxCtrlCmdFlg' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern boolean_T Pmsm_bl_PIVoltSaturatFlg_B;/* '<S30>/Relational Operator' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern boolean_T Pmsm_bl_Svpwm5or7SelFlg_B;/* '<S51>/Logical Operator1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern boolean_T Pmsm_bl_ZeroIVldSvpwmOut_B;/* '<S48>/Compare' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Declaration for custom storage class: TRUSTED_DATA_32BITS */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_DnSelSvm7Val_B;/* Referenced by: '<S51>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_Flux_B;/* Referenced by: '<S43>/Constant4' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_IqFdbLpfCoeff_C_B;/* Referenced by: '<S12>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_Kt_B;/* Referenced by: '<S3>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_Ld_B;/* Referenced by: '<S43>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_Lq_B;/* Referenced by: '<S43>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_Rpm2eRads_B;/* Referenced by: '<S43>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_SvpwmRMax_B;/* Referenced by: '<S15>/Rmax' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_UpSelSvm5Val_B;/* Referenced by: '<S51>/Constant4' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VfAngIncStep_C_B;/* Referenced by: '<S60>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Declaration for custom storage class: TRUSTED_DATA_32BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_AngCompCoeff_B;/* Referenced by: '<S59>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B;/* Referenced by: '<S27>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_DeadZoneCompVal_B;/* Referenced by: '<S38>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_EmfVoltCompCoeff_B;/* Referenced by: '<S43>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_EmfVoltCompLimited_B;/* Referenced by: '<S43>/Constant5' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_IdFdbLpfCoeff_C_B;/* Referenced by: '<S11>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_MotSpdLimit_MAX_B;/* Referenced by: '<S13>/Constant5' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VBus2VdVqLimited_B;/* Referenced by: '<S30>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VBusCurrGain_B;/* Referenced by: '<S2>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VBusCurrOffset_B;/* Referenced by: '<S2>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VBusLimit_MAX_B;/* Referenced by: '<S17>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VBusLimit_MIN_B;/* Referenced by: '<S17>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VbusFiltCoeff_B;/* Referenced by: '<S62>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_VfSpeed_C_B;/* Referenced by: '<S16>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 8bits */
/* Declaration for custom storage class: TRUSTED_DATA_8BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_AngCompEnable_B;/* Referenced by: '<S16>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_DeadZoneCompEnable_B;/* Referenced by: '<S6>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_EmfVoltCompEnable_B;/* Referenced by: '<S7>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_Svm5ForcEnb_B;/* Referenced by: '<S51>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile boolean_T Pmsm_bl_Svm5or7SelEnable_B;/* Referenced by: '<S51>/Constant6' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
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
 * '<Root>' : 'Pmsm_Foc_MotB'
 * '<S1>'   : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB'
 * '<S2>'   : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/CalcIbus'
 * '<S3>'   : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/CalcMotTorq'
 * '<S4>'   : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/CloseLoop_or_OpenLoop_Selection'
 * '<S5>'   : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller'
 * '<S6>'   : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/DeadZoneCompens'
 * '<S7>'   : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/EmfVoltCompens'
 * '<S8>'   : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/IdIqRef_Selection'
 * '<S9>'   : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Idq2IuvwRef'
 * '<S10>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Iuvw2Idqs'
 * '<S11>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/LPF'
 * '<S12>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/LPF1'
 * '<S13>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/MotorSpeedLimited'
 * '<S14>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/PwmDutyUVW_Output'
 * '<S15>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM'
 * '<S16>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Theta2SinCos'
 * '<S17>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/VBusLimited'
 * '<S18>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Vbus2MotUs'
 * '<S19>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/VdVqCmd_Selection'
 * '<S20>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/CloseLoop_or_OpenLoop_Selection/Compare To Constant'
 * '<S21>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/CloseLoop_or_OpenLoop_Selection/Compare To Constant1'
 * '<S22>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/CloseLoop_or_OpenLoop_Selection/Compare To Constant2'
 * '<S23>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/CloseLoop_or_OpenLoop_Selection/Compare To Constant3'
 * '<S24>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/CloseLoop_or_OpenLoop_Selection/Compare To Constant4'
 * '<S25>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/CloseLoop_or_OpenLoop_Selection/Compare To Constant5'
 * '<S26>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/Command_Limited'
 * '<S27>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/PI_Controller'
 * '<S28>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/Command_Limited/Intergral_Windup_LoopBack'
 * '<S29>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/Command_Limited/VdqCmd_Scaled'
 * '<S30>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/Command_Limited/Voltage_Limited'
 * '<S31>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/Command_Limited/Voltage_Limited/Saturation Dynamic'
 * '<S32>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/Command_Limited/Voltage_Limited/Saturation Dynamic1'
 * '<S33>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/Command_Limited/Voltage_Limited/VdVqCmd2VsCmd'
 * '<S34>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/PI_Controller/DeadZone'
 * '<S35>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/PI_Controller/DeadZone1'
 * '<S36>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/PI_Controller/Saturation Dynamic'
 * '<S37>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Current_Loop_Controller/PI_Controller/Saturation Dynamic1'
 * '<S38>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/DeadZoneCompens/Subsystem'
 * '<S39>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/DeadZoneCompens/Subsystem1'
 * '<S40>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/DeadZoneCompens/Subsystem/Saturation Dynamic'
 * '<S41>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/DeadZoneCompens/Subsystem/Saturation Dynamic1'
 * '<S42>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/DeadZoneCompens/Subsystem/Saturation Dynamic2'
 * '<S43>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/EmfVoltCompens/Subsystem'
 * '<S44>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/EmfVoltCompens/Subsystem1'
 * '<S45>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/EmfVoltCompens/Subsystem/Saturation Dynamic'
 * '<S46>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/EmfVoltCompens/Subsystem/Saturation Dynamic1'
 * '<S47>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/MotorSpeedLimited/Saturation Dynamic1'
 * '<S48>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM/Compare To Constant3'
 * '<S49>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM/DutyABC_Allocation'
 * '<S50>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM/DutyLMS_Calculation'
 * '<S51>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM/Mode_Selection'
 * '<S52>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM/N_Calc'
 * '<S53>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM/Over_Mudulation'
 * '<S54>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM/Sector_Check'
 * '<S55>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM/iClarke'
 * '<S56>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM/iPark'
 * '<S57>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/SVPWM/Mode_Selection/PWM7_PWM5_Select'
 * '<S58>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Theta2SinCos/Compare To Constant1'
 * '<S59>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Theta2SinCos/Subsystem'
 * '<S60>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/Theta2SinCos/VF'
 * '<S61>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/VBusLimited/Saturation Dynamic'
 * '<S62>'  : 'Pmsm_Foc_MotB/Pmsm_Foc_MotB/VBusLimited/Subsystem'
 */
#endif                                 /* RTW_HEADER_Pmsm_Foc_MotB_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
