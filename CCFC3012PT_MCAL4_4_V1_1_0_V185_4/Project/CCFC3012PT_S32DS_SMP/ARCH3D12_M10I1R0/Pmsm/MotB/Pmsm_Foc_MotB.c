/*
 * File: Pmsm_Foc_MotB.c
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

#include <math.h>
#include "rtwtypes.h"
#include "Pmsm_Foc_MotB_private.h"
#include "Pmsm_Foc_MotB.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

Pmsm_Foc_MotB_PmsmDefault PmsmDefault_Pmsm_Foc_MotB;/* '<S59>/Trigonometric Function' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Exported data definition */

/* pmsm trusted bss 16bits */
/* Definition for custom storage class: TRUSTED_BSS_16BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_DbgTheta_B;          /* '<Root>/Dbg_Theta' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_SensorTheta_B;       /* '<Root>/Theta' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_Theta_B;             /* '<S16>/Switch1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 32bits */
/* Definition for custom storage class: TRUSTED_BSS_32BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_AlphaVoltCmd_B;      /* '<S56>/Add2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_BetaVoltCmd_B;       /* '<S56>/Add3' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_BusCurrent_B;        /* '<S2>/Add1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_D_IGain_B;           /* '<Root>/D_IGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_D_PGain_B;           /* '<Root>/D_PGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DbgDutyU_B;          /* '<Root>/Dbg_DutyU' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DbgDutyV_B;          /* '<Root>/Dbg_DutyV' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DbgDutyW_B;          /* '<Root>/Dbg_DutyW' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DbgIdRef_B;          /* '<Root>/Dbg_IdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DbgIqRef_B;          /* '<Root>/Dbg_IqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DbgVdRef_B;          /* '<Root>/Dbg_VdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DbgVqRef_B;          /* '<Root>/Dbg_VqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DeadBand_B;          /* '<Root>/Deadband' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DeadZoneUalpha_B;    /* '<S39>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DeadZoneUbeta_B;     /* '<S39>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DutyU_B;             /* '<S14>/Gain2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DutyV_B;             /* '<S14>/Gain3' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DutyW_B;             /* '<S14>/Gain4' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_EmfComp_Vd_B;        /* '<S44>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_EmfComp_Vq_B;        /* '<S44>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_FiltedId_B;          /* '<S11>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_FiltedIq_B;          /* '<S12>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_FlxIdRefIn_B;        /* '<Root>/FlxIdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_FlxIqRefIn_B;        /* '<Root>/FlxIqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_IU_B;                /* '<Root>/Current_U' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_IV_B;                /* '<Root>/Current_V' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_IW_B;                /* '<Root>/Current_W' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_IdRef_B;             /* '<S8>/Gain5' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_Id_B;                /* '<S10>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_IqRef_B;             /* '<S8>/Gain8' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_Iq_B;                /* '<S10>/Subtract' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_Is_B;                /* '<S10>/Sqrt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_IuRef_B;             /* '<S9>/Subtract' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_IvRef_B;             /* '<S9>/Add1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_IwRef_B;             /* '<S9>/Subtract1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_LimitedPhasVBus_B;   /* '<S30>/Product' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_MotorSpeed_B;        /* '<Root>/MotorSpeed' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_MotorTorque_B;       /* '<S3>/Product' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_PIVoltCmd_B;         /* '<S33>/Sqrt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_Q_IGain_B;           /* '<Root>/Q_IGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_Q_PGain_B;           /* '<Root>/Q_PGain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_RxAddRy_B;           /* '<S51>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_VBus_B;              /* '<Root>/VBus' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_VdCmd_B;             /* '<S19>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_VqCmd_B;             /* '<S19>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 8bits */
/* Definition for custom storage class: TRUSTED_BSS_8BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

boolean_T Pmsm_bl_FlxCtrlCmdFlgIn_B;   /* '<Root>/FlxCtrlCmdFlg' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

boolean_T Pmsm_bl_PIVoltSaturatFlg_B;  /* '<S30>/Relational Operator' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

boolean_T Pmsm_bl_Svpwm5or7SelFlg_B;   /* '<S51>/Logical Operator1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

boolean_T Pmsm_bl_ZeroIVldSvpwmOut_B;  /* '<S48>/Compare' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Definition for custom storage class: TRUSTED_DATA_32BITS */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_DnSelSvm7Val_B = 0.64F;/* Referenced by: '<S51>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_Flux_B = 0.00755555555F;/* Referenced by: '<S43>/Constant4' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_IqFdbLpfCoeff_C_B = 1.0F;/* Referenced by: '<S12>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_Kt_B = 0.034F;/* Referenced by: '<S3>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_Ld_B = 0.000101F;/* Referenced by: '<S43>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_Lq_B = 0.000101F;/* Referenced by: '<S43>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_Rpm2eRads_B = 0.314159274F;/* Referenced by: '<S43>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_SvpwmRMax_B = 0.84F;/* Referenced by: '<S15>/Rmax' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_UpSelSvm5Val_B = 0.74F;/* Referenced by: '<S51>/Constant4' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_VfAngIncStep_C_B = 0.32768F;/* Referenced by: '<S60>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Definition for custom storage class: TRUSTED_DATA_32BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_AngCompCoeff_B = 0.0F;/* Referenced by: '<S59>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B = 500.0F;/* Referenced by: '<S27>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_DeadZoneCompVal_B = 0.04F;/* Referenced by: '<S38>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_EmfVoltCompCoeff_B = 0.7F;/* Referenced by: '<S43>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_EmfVoltCompLimited_B = 0.8F;/* Referenced by: '<S43>/Constant5' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_IdFdbLpfCoeff_C_B = 1.0F;/* Referenced by: '<S11>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_MotSpdLimit_MAX_B = 15000.0F;/* Referenced by: '<S13>/Constant5' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_VBus2VdVqLimited_B = 0.8F;/* Referenced by: '<S30>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_VBusCurrGain_B = 1.0F;/* Referenced by: '<S2>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_VBusCurrOffset_B = 0.0F;/* Referenced by: '<S2>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_VBusLimit_MAX_B = 16.0F;/* Referenced by: '<S17>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_VBusLimit_MIN_B = 9.0F;/* Referenced by: '<S17>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_VbusFiltCoeff_B = 0.3F;/* Referenced by: '<S62>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_VfSpeed_C_B = 0.0F;/* Referenced by: '<S16>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 8bits */
/* Definition for custom storage class: TRUSTED_DATA_8BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

volatile boolean_T Pmsm_bl_AngCompEnable_B = false;/* Referenced by: '<S16>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

volatile boolean_T Pmsm_bl_DeadZoneCompEnable_B = false;/* Referenced by: '<S6>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

volatile boolean_T Pmsm_bl_EmfVoltCompEnable_B = false;/* Referenced by: '<S7>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

volatile boolean_T Pmsm_bl_Svm5ForcEnb_B = false;/* Referenced by: '<S51>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

volatile boolean_T Pmsm_bl_Svm5or7SelEnable_B = false;/* Referenced by: '<S51>/Constant6' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

/* Model step function */

/* Code 2 RAM */
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_Foc_MotB_step(void)
{
  real32_T cosOut;
  real32_T rtb_Add1_l;
  real32_T rtb_Divide;
  real32_T rtb_Gain;
  real32_T rtb_Gain1_e;
  real32_T rtb_Gain_p;
  real32_T rtb_Product_m3;
  real32_T rtb_Switch2;
  real32_T rtb_Switch2_gp;
  uint8_T rtb_Sector;
  uint8_T rtb_Subtract1_p_0;
  boolean_T rtb_Compare_gq;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator2_p;

  /* Sum: '<S2>/Add1' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/Current_U'
   *  Inport: '<Root>/Current_V'
   *  Inport: '<Root>/Current_W'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product2'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Add'
   */
  Pmsm_f32_BusCurrent_B = ((Pmsm_f32_DutyU_B * Pmsm_f32_IU_B + Pmsm_f32_DutyV_B *
    Pmsm_f32_IV_B) + Pmsm_f32_DutyW_B * Pmsm_f32_IW_B) * Pmsm_f32_VBusCurrGain_B
    + Pmsm_f32_VBusCurrOffset_B;

  /* Switch: '<S8>/Switch4' incorporates:
   *  Inport: '<Root>/FlxCtrlCmdFlg'
   */
  if (Pmsm_bl_FlxCtrlCmdFlgIn_B) {
    /* Gain: '<S8>/Gain5' incorporates:
     *  Inport: '<Root>/FlxIdRef'
     */
    Pmsm_f32_IdRef_B = Pmsm_f32_FlxIdRefIn_B;

    /* Gain: '<S8>/Gain8' incorporates:
     *  Inport: '<Root>/FlxIqRef'
     */
    Pmsm_f32_IqRef_B = Pmsm_f32_FlxIqRefIn_B;
  } else {
    /* Gain: '<S8>/Gain5' incorporates:
     *  Inport: '<Root>/Dbg_IdRef'
     */
    Pmsm_f32_IdRef_B = Pmsm_f32_DbgIdRef_B;

    /* Gain: '<S8>/Gain8' incorporates:
     *  Inport: '<Root>/Dbg_IqRef'
     */
    Pmsm_f32_IqRef_B = Pmsm_f32_DbgIqRef_B;
  }

  /* End of Switch: '<S8>/Switch4' */

  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S4>/Constant4'
   */
  rtb_LogicalOperator2_p = (Pmsm_u8_MotCmdSel_B == 6);

  /* Logic: '<S16>/Logical Operator1' */
  rtb_LogicalOperator1 = !rtb_LogicalOperator2_p;

  /* RelationalOperator: '<S25>/Compare' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S4>/Constant4'
   */
  rtb_Compare_gq = (Pmsm_u8_MotCmdSel_B == 7);

  /* Outputs for Enabled SubSystem: '<S16>/VF' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if (rtb_Compare_gq) {
    int16_T rtb_DataTypeConversion2;
    if (!PmsmDefault_Pmsm_Foc_MotB.VF_MODE) {
      /* InitializeConditions for Delay: '<S60>/Delay' */
      PmsmDefault_Pmsm_Foc_MotB.Delay_DSTATE_p = 0;
      PmsmDefault_Pmsm_Foc_MotB.VF_MODE = true;
    }

    /* Switch: '<S60>/Switch' incorporates:
     *  Abs: '<S60>/Abs'
     *  Constant: '<S16>/Constant'
     *  Constant: '<S60>/Constant1'
     *  Constant: '<S60>/Constant2'
     *  RelationalOperator: '<S60>/Relational Operator'
     */
    if (fabsf(Pmsm_f32_VfSpeed_C_B) > 0.99F) {
      /* Product: '<S60>/Product' incorporates:
       *  Constant: '<S60>/Constant'
       */
      rtb_Product_m3 = Pmsm_f32_VfAngIncStep_C_B * Pmsm_f32_VfSpeed_C_B;

      /* DataTypeConversion: '<S60>/Data Type Conversion2' */
      rtb_DataTypeConversion2 = (int16_T)floorf(rtb_Product_m3);

      /* Switch: '<S60>/Switch1' incorporates:
       *  RelationalOperator: '<S60>/Relational Operator1'
       */
      if (rtb_DataTypeConversion2 == 0) {
        /* Switch: '<S60>/Switch2' incorporates:
         *  Constant: '<S60>/Constant5'
         *  Constant: '<S60>/Constant6'
         *  Constant: '<S60>/Constant7'
         *  RelationalOperator: '<S60>/Relational Operator2'
         */
        if (rtb_Product_m3 > 0.0F) {
          rtb_DataTypeConversion2 = 1;
        } else {
          rtb_DataTypeConversion2 = -1;
        }

        /* End of Switch: '<S60>/Switch2' */
      }

      /* End of Switch: '<S60>/Switch1' */
    } else {
      rtb_DataTypeConversion2 = 0;
    }

    /* End of Switch: '<S60>/Switch' */

    /* Sum: '<S60>/Add' incorporates:
     *  Delay: '<S60>/Delay'
     */
    PmsmDefault_Pmsm_Foc_MotB.Delay_DSTATE_p += rtb_DataTypeConversion2;

    /* DataTypeConversion: '<S60>/Data Type Conversion' incorporates:
     *  Delay: '<S60>/Delay'
     */
    PmsmDefault_Pmsm_Foc_MotB.DataTypeConversion = (uint16_T)
      PmsmDefault_Pmsm_Foc_MotB.Delay_DSTATE_p;

    /* Switch: '<S16>/Switch1' */
    Pmsm_u16_Theta_B = PmsmDefault_Pmsm_Foc_MotB.DataTypeConversion;
  } else {
    PmsmDefault_Pmsm_Foc_MotB.VF_MODE = false;

    /* Switch: '<S16>/Switch6' incorporates:
     *  Switch: '<S16>/Switch1'
     */
    if (rtb_LogicalOperator1) {
      /* Switch: '<S16>/Switch1' incorporates:
       *  Inport: '<Root>/Theta'
       */
      Pmsm_u16_Theta_B = Pmsm_u16_SensorTheta_B;
    } else {
      /* Switch: '<S16>/Switch1' incorporates:
       *  Inport: '<Root>/Dbg_Theta'
       */
      Pmsm_u16_Theta_B = Pmsm_u16_DbgTheta_B;
    }

    /* End of Switch: '<S16>/Switch6' */
  }

  /* End of Outputs for SubSystem: '<S16>/VF' */

  /* Gain: '<S16>/Gain1' */
  rtb_Product_m3 = 9.58738E-5F * (real32_T)Pmsm_u16_Theta_B;

  /* Trigonometry: '<S16>/Trigonometric Function1' */
  cosOut = cosf(rtb_Product_m3);
  rtb_Product_m3 = sinf(rtb_Product_m3);

  /* Gain: '<S10>/Gain1' incorporates:
   *  Inport: '<Root>/Current_V'
   *  Inport: '<Root>/Current_W'
   *  Sum: '<S10>/Add2'
   */
  rtb_Gain1_e = (Pmsm_f32_IV_B - Pmsm_f32_IW_B) * 0.577350259F;

  /* Sum: '<S10>/Add' incorporates:
   *  Inport: '<Root>/Current_U'
   *  Product: '<S10>/Product2'
   *  Product: '<S10>/Product3'
   *  Trigonometry: '<S16>/Trigonometric Function1'
   */
  Pmsm_f32_Id_B = Pmsm_f32_IU_B * cosOut + rtb_Gain1_e * rtb_Product_m3;

  /* Sum: '<S11>/Add' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Sum: '<S11>/Subtract1'
   */
  Pmsm_f32_FiltedId_B = (1.0F - Pmsm_f32_IdFdbLpfCoeff_C_B) *
    Pmsm_f32_FiltedId_B + Pmsm_f32_Id_B * Pmsm_f32_IdFdbLpfCoeff_C_B;

  /* Sum: '<S10>/Subtract' incorporates:
   *  Inport: '<Root>/Current_U'
   *  Product: '<S10>/Product4'
   *  Product: '<S10>/Product5'
   *  Trigonometry: '<S16>/Trigonometric Function1'
   */
  Pmsm_f32_Iq_B = rtb_Gain1_e * cosOut - Pmsm_f32_IU_B * rtb_Product_m3;

  /* Sum: '<S12>/Add' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant1'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   *  Sum: '<S12>/Subtract1'
   */
  Pmsm_f32_FiltedIq_B = (1.0F - Pmsm_f32_IqFdbLpfCoeff_C_B) *
    Pmsm_f32_FiltedIq_B + Pmsm_f32_Iq_B * Pmsm_f32_IqFdbLpfCoeff_C_B;

  /* Delay: '<S62>/Delay1' */
  if (PmsmDefault_Pmsm_Foc_MotB.icLoad) {
    /* Sum: '<S62>/Add' incorporates:
     *  Inport: '<Root>/VBus'
     */
    PmsmDefault_Pmsm_Foc_MotB.Delay1_DSTATE_j = Pmsm_f32_VBus_B;
  }

  /* Sum: '<S62>/Add' incorporates:
   *  Constant: '<S62>/Constant'
   *  Constant: '<S62>/Constant1'
   *  Delay: '<S62>/Delay1'
   *  Inport: '<Root>/VBus'
   *  Product: '<S62>/Product'
   *  Product: '<S62>/Product1'
   *  Sum: '<S62>/Subtract1'
   */
  PmsmDefault_Pmsm_Foc_MotB.Delay1_DSTATE_j = (1.0F - Pmsm_f32_VbusFiltCoeff_B) *
    PmsmDefault_Pmsm_Foc_MotB.Delay1_DSTATE_j + Pmsm_f32_VBus_B *
    Pmsm_f32_VbusFiltCoeff_B;

  /* Switch: '<S61>/Switch2' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S17>/Constant3'
   *  RelationalOperator: '<S61>/LowerRelop1'
   *  RelationalOperator: '<S61>/UpperRelop'
   *  Switch: '<S61>/Switch'
   */
  if (PmsmDefault_Pmsm_Foc_MotB.Delay1_DSTATE_j > Pmsm_f32_VBusLimit_MAX_B) {
    rtb_Gain1_e = Pmsm_f32_VBusLimit_MAX_B;
  } else if (PmsmDefault_Pmsm_Foc_MotB.Delay1_DSTATE_j <
             Pmsm_f32_VBusLimit_MIN_B) {
    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S17>/Constant3'
     */
    rtb_Gain1_e = Pmsm_f32_VBusLimit_MIN_B;
  } else {
    rtb_Gain1_e = PmsmDefault_Pmsm_Foc_MotB.Delay1_DSTATE_j;
  }

  /* End of Switch: '<S61>/Switch2' */

  /* Gain: '<S18>/Gain' */
  rtb_Gain = 0.577350259F * rtb_Gain1_e;

  /* Switch: '<S47>/Switch2' incorporates:
   *  Constant: '<S13>/Constant5'
   *  Gain: '<S13>/Gain6'
   *  Inport: '<Root>/MotorSpeed'
   *  RelationalOperator: '<S47>/LowerRelop1'
   *  RelationalOperator: '<S47>/UpperRelop'
   *  Switch: '<S47>/Switch'
   */
  if (Pmsm_f32_MotorSpeed_B > Pmsm_f32_MotSpdLimit_MAX_B) {
    rtb_Switch2 = Pmsm_f32_MotSpdLimit_MAX_B;
  } else if (Pmsm_f32_MotorSpeed_B < -Pmsm_f32_MotSpdLimit_MAX_B) {
    /* Switch: '<S47>/Switch' incorporates:
     *  Gain: '<S13>/Gain6'
     */
    rtb_Switch2 = -Pmsm_f32_MotSpdLimit_MAX_B;
  } else {
    rtb_Switch2 = Pmsm_f32_MotorSpeed_B;
  }

  /* End of Switch: '<S47>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S7>/Subsystem' incorporates:
   *  EnablePort: '<S43>/Enable'
   */
  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (Pmsm_bl_EmfVoltCompEnable_B) {
    /* Product: '<S43>/Product' incorporates:
     *  Constant: '<S43>/Constant'
     */
    rtb_Gain_p = rtb_Switch2 * Pmsm_f32_Rpm2eRads_B;

    /* Product: '<S43>/Product4' incorporates:
     *  Constant: '<S43>/Constant2'
     *  Constant: '<S43>/Constant3'
     *  Constant: '<S43>/Constant4'
     *  Product: '<S43>/Product3'
     *  Sum: '<S43>/Add'
     */
    PmsmDefault_Pmsm_Foc_MotB.Switch2 = (Pmsm_f32_Id_B * Pmsm_f32_Ld_B +
      Pmsm_f32_Flux_B) * (Pmsm_f32_EmfVoltCompCoeff_B * rtb_Gain_p);

    /* Product: '<S43>/Product5' incorporates:
     *  Constant: '<S43>/Constant5'
     */
    rtb_Switch2_gp = rtb_Gain * Pmsm_f32_EmfVoltCompLimited_B;

    /* Switch: '<S46>/Switch2' incorporates:
     *  Gain: '<S43>/Gain1'
     *  RelationalOperator: '<S46>/LowerRelop1'
     *  RelationalOperator: '<S46>/UpperRelop'
     *  Switch: '<S46>/Switch'
     */
    if (PmsmDefault_Pmsm_Foc_MotB.Switch2 > rtb_Switch2_gp) {
      /* Product: '<S43>/Product4' incorporates:
       *  Switch: '<S46>/Switch2'
       */
      PmsmDefault_Pmsm_Foc_MotB.Switch2 = rtb_Switch2_gp;
    } else if (PmsmDefault_Pmsm_Foc_MotB.Switch2 < -rtb_Switch2_gp) {
      /* Product: '<S43>/Product4' incorporates:
       *  Gain: '<S43>/Gain1'
       *  Switch: '<S46>/Switch'
       *  Switch: '<S46>/Switch2'
       */
      PmsmDefault_Pmsm_Foc_MotB.Switch2 = -rtb_Switch2_gp;
    }

    /* End of Switch: '<S46>/Switch2' */

    /* Product: '<S43>/Product2' incorporates:
     *  Constant: '<S43>/Constant1'
     *  Constant: '<S43>/Constant2'
     *  Gain: '<S43>/Gain'
     *  Product: '<S43>/Product1'
     */
    PmsmDefault_Pmsm_Foc_MotB.Switch2_a = -(Pmsm_f32_Lq_B * Pmsm_f32_Iq_B *
      rtb_Gain_p) * Pmsm_f32_EmfVoltCompCoeff_B;

    /* Switch: '<S45>/Switch2' incorporates:
     *  Gain: '<S43>/Gain1'
     *  RelationalOperator: '<S45>/LowerRelop1'
     *  RelationalOperator: '<S45>/UpperRelop'
     *  Switch: '<S45>/Switch'
     */
    if (PmsmDefault_Pmsm_Foc_MotB.Switch2_a > rtb_Switch2_gp) {
      /* Product: '<S43>/Product2' incorporates:
       *  Switch: '<S45>/Switch2'
       */
      PmsmDefault_Pmsm_Foc_MotB.Switch2_a = rtb_Switch2_gp;
    } else if (PmsmDefault_Pmsm_Foc_MotB.Switch2_a < -rtb_Switch2_gp) {
      /* Product: '<S43>/Product2' incorporates:
       *  Gain: '<S43>/Gain1'
       *  Switch: '<S45>/Switch'
       *  Switch: '<S45>/Switch2'
       */
      PmsmDefault_Pmsm_Foc_MotB.Switch2_a = -rtb_Switch2_gp;
    }

    /* End of Switch: '<S45>/Switch2' */

    /* Gain: '<S44>/Gain' */
    Pmsm_f32_EmfComp_Vd_B = PmsmDefault_Pmsm_Foc_MotB.Switch2_a;

    /* Gain: '<S44>/Gain1' */
    Pmsm_f32_EmfComp_Vq_B = PmsmDefault_Pmsm_Foc_MotB.Switch2;
  } else {
    /* Gain: '<S44>/Gain' incorporates:
     *  Constant: '<S44>/Constant1'
     */
    Pmsm_f32_EmfComp_Vd_B = 0.0F;

    /* Gain: '<S44>/Gain1' incorporates:
     *  Constant: '<S44>/Constant1'
     */
    Pmsm_f32_EmfComp_Vq_B = 0.0F;
  }

  /* End of Switch: '<S44>/Switch' */
  /* End of Outputs for SubSystem: '<S7>/Subsystem' */

  /* Product: '<S18>/Divide' incorporates:
   *  Constant: '<S18>/Constant'
   */
  rtb_Divide = 1.73205078F / rtb_Gain1_e;

  /* Outputs for Enabled SubSystem: '<S1>/Current_Loop_Controller' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* Logic: '<S4>/Logical Operator' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S4>/Constant4'
   *  Inport: '<Root>/FlxCtrlCmdFlg'
   *  RelationalOperator: '<S22>/Compare'
   */
  if ((Pmsm_u8_MotCmdSel_B == 2) || Pmsm_bl_FlxCtrlCmdFlgIn_B) {
    real32_T rtb_Add_lw;
    real32_T rtb_Product2_d4;
    real32_T rtb_Product_d;
    if (!PmsmDefault_Pmsm_Foc_MotB.Current_Loop_Controller_MODE) {
      /* InitializeConditions for UnitDelay: '<S5>/Unit Delay2' */
      PmsmDefault_Pmsm_Foc_MotB.UnitDelay2_DSTATE = 0.0F;

      /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
      PmsmDefault_Pmsm_Foc_MotB.UnitDelay1_DSTATE = 0.0F;
      PmsmDefault_Pmsm_Foc_MotB.Current_Loop_Controller_MODE = true;
    }

    /* Sum: '<S27>/Sum1' */
    rtb_Gain_p = Pmsm_f32_IdRef_B - Pmsm_f32_FiltedId_B;

    /* Switch: '<S36>/Switch2' incorporates:
     *  Constant: '<S27>/Constant'
     *  Gain: '<S27>/Gain'
     *  RelationalOperator: '<S36>/LowerRelop1'
     *  RelationalOperator: '<S36>/UpperRelop'
     *  Switch: '<S36>/Switch'
     */
    if (rtb_Gain_p > Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B) {
      rtb_Gain_p = Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B;
    } else if (rtb_Gain_p < -Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B) {
      /* Switch: '<S36>/Switch' incorporates:
       *  Gain: '<S27>/Gain'
       */
      rtb_Gain_p = -Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B;
    }

    /* End of Switch: '<S36>/Switch2' */

    /* Switch: '<S34>/Switch' incorporates:
     *  Inport: '<Root>/Deadband'
     *  RelationalOperator: '<S34>/Relational Operator'
     *  RelationalOperator: '<S34>/Relational Operator1'
     *  Sum: '<S34>/Subtract'
     *  Switch: '<S34>/Switch1'
     *  UnaryMinus: '<S34>/Unary Minus'
     */
    if (rtb_Gain_p > Pmsm_f32_DeadBand_B) {
      rtb_Switch2_gp = rtb_Gain_p - Pmsm_f32_DeadBand_B;
    } else if (rtb_Gain_p < -Pmsm_f32_DeadBand_B) {
      /* Switch: '<S34>/Switch1' incorporates:
       *  Sum: '<S34>/Add'
       */
      rtb_Switch2_gp = rtb_Gain_p + Pmsm_f32_DeadBand_B;
    } else {
      /* Switch: '<S34>/Switch1' incorporates:
       *  Constant: '<S34>/Constant1'
       */
      rtb_Switch2_gp = 0.0F;
    }

    /* End of Switch: '<S34>/Switch' */

    /* Product: '<S27>/Product2' incorporates:
     *  Inport: '<Root>/D_PGain'
     */
    rtb_Product2_d4 = rtb_Switch2_gp * Pmsm_f32_D_PGain_B;

    /* Sum: '<S27>/Add3' incorporates:
     *  Inport: '<Root>/D_IGain'
     *  Product: '<S27>/Product3'
     *  UnitDelay: '<S5>/Unit Delay2'
     */
    rtb_Switch2_gp = rtb_Switch2_gp * Pmsm_f32_D_IGain_B +
      PmsmDefault_Pmsm_Foc_MotB.UnitDelay2_DSTATE;

    /* Sum: '<S30>/Add' incorporates:
     *  Sum: '<S27>/Add2'
     */
    rtb_Add_lw = (rtb_Product2_d4 + rtb_Switch2_gp) + Pmsm_f32_EmfComp_Vd_B;

    /* Switch: '<S31>/Switch2' incorporates:
     *  Gain: '<S30>/Gain'
     *  RelationalOperator: '<S31>/LowerRelop1'
     *  RelationalOperator: '<S31>/UpperRelop'
     *  Switch: '<S31>/Switch'
     */
    if (rtb_Add_lw > rtb_Gain) {
      rtb_Gain1_e = rtb_Gain;
    } else if (rtb_Add_lw < -rtb_Gain) {
      /* Switch: '<S31>/Switch' incorporates:
       *  Gain: '<S30>/Gain'
       */
      rtb_Gain1_e = -rtb_Gain;
    } else {
      rtb_Gain1_e = rtb_Add_lw;
    }

    /* End of Switch: '<S31>/Switch2' */

    /* Sum: '<S27>/Sum' */
    rtb_Gain_p = Pmsm_f32_IqRef_B - Pmsm_f32_FiltedIq_B;

    /* Switch: '<S37>/Switch2' incorporates:
     *  Constant: '<S27>/Constant'
     *  Gain: '<S27>/Gain'
     *  RelationalOperator: '<S37>/LowerRelop1'
     *  RelationalOperator: '<S37>/UpperRelop'
     *  Switch: '<S37>/Switch'
     */
    if (rtb_Gain_p > Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B) {
      rtb_Gain_p = Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B;
    } else if (rtb_Gain_p < -Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B) {
      /* Switch: '<S37>/Switch' incorporates:
       *  Gain: '<S27>/Gain'
       */
      rtb_Gain_p = -Pmsm_f32_DQ_IRefFdbErrLimit_MAX_B;
    }

    /* End of Switch: '<S37>/Switch2' */

    /* Switch: '<S35>/Switch' incorporates:
     *  Inport: '<Root>/Deadband'
     *  RelationalOperator: '<S35>/Relational Operator'
     *  RelationalOperator: '<S35>/Relational Operator1'
     *  Sum: '<S35>/Subtract'
     *  Switch: '<S35>/Switch1'
     *  UnaryMinus: '<S35>/Unary Minus'
     */
    if (rtb_Gain_p > Pmsm_f32_DeadBand_B) {
      rtb_Gain_p -= Pmsm_f32_DeadBand_B;
    } else if (rtb_Gain_p < -Pmsm_f32_DeadBand_B) {
      /* Switch: '<S35>/Switch1' incorporates:
       *  Sum: '<S35>/Add'
       */
      rtb_Gain_p += Pmsm_f32_DeadBand_B;
    } else {
      /* Switch: '<S35>/Switch1' incorporates:
       *  Constant: '<S35>/Constant1'
       */
      rtb_Gain_p = 0.0F;
    }

    /* End of Switch: '<S35>/Switch' */

    /* Product: '<S27>/Product' incorporates:
     *  Inport: '<Root>/Q_PGain'
     */
    rtb_Product_d = rtb_Gain_p * Pmsm_f32_Q_PGain_B;

    /* Sum: '<S27>/Add1' incorporates:
     *  Inport: '<Root>/Q_IGain'
     *  Product: '<S27>/Product1'
     *  UnitDelay: '<S5>/Unit Delay1'
     */
    rtb_Gain_p = rtb_Gain_p * Pmsm_f32_Q_IGain_B +
      PmsmDefault_Pmsm_Foc_MotB.UnitDelay1_DSTATE;

    /* Sum: '<S30>/Add1' incorporates:
     *  Sum: '<S27>/Add'
     */
    rtb_Add1_l = (rtb_Product_d + rtb_Gain_p) + Pmsm_f32_EmfComp_Vq_B;

    /* Switch: '<S32>/Switch2' incorporates:
     *  Gain: '<S30>/Gain'
     *  RelationalOperator: '<S32>/LowerRelop1'
     *  RelationalOperator: '<S32>/UpperRelop'
     *  Switch: '<S32>/Switch'
     */
    if (rtb_Add1_l > rtb_Gain) {
      rtb_Add1_l = rtb_Gain;
    } else if (rtb_Add1_l < -rtb_Gain) {
      /* Switch: '<S32>/Switch' incorporates:
       *  Gain: '<S30>/Gain'
       */
      rtb_Add1_l = -rtb_Gain;
    }

    /* End of Switch: '<S32>/Switch2' */

    /* Product: '<S30>/Product' incorporates:
     *  Constant: '<S30>/Constant'
     */
    Pmsm_f32_LimitedPhasVBus_B = Pmsm_f32_VBus2VdVqLimited_B * rtb_Gain;

    /* Sqrt: '<S33>/Sqrt' incorporates:
     *  Product: '<S33>/Product1'
     *  Product: '<S33>/Product2'
     *  Sum: '<S33>/Add'
     */
    Pmsm_f32_PIVoltCmd_B = sqrtf(rtb_Gain1_e * rtb_Gain1_e + rtb_Add1_l *
      rtb_Add1_l);

    /* RelationalOperator: '<S30>/Relational Operator' */
    Pmsm_bl_PIVoltSaturatFlg_B = (Pmsm_f32_LimitedPhasVBus_B >=
      Pmsm_f32_PIVoltCmd_B);

    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S33>/Constant1'
     *  Product: '<S30>/Product1'
     *  Product: '<S30>/Product2'
     *  RelationalOperator: '<S33>/Relational Operator'
     *  Sum: '<S28>/Subtract1'
     *  Switch: '<S28>/Switch1'
     *  Switch: '<S33>/Switch'
     *  UnitDelay: '<S5>/Unit Delay1'
     */
    if (Pmsm_bl_PIVoltSaturatFlg_B) {
      PmsmDefault_Pmsm_Foc_MotB.UnitDelay1_DSTATE = rtb_Gain_p;
    } else {
      if (Pmsm_f32_PIVoltCmd_B > 0.0001F) {
        /* Switch: '<S33>/Switch' */
        rtb_Gain = Pmsm_f32_PIVoltCmd_B;
      } else {
        /* Switch: '<S33>/Switch' incorporates:
         *  Constant: '<S33>/Constant1'
         */
        rtb_Gain = 0.0001F;
      }

      /* Product: '<S33>/Divide2' */
      rtb_Gain = 1.0F / rtb_Gain;
      rtb_Gain1_e = rtb_Gain1_e * Pmsm_f32_LimitedPhasVBus_B * rtb_Gain;
      rtb_Add1_l = rtb_Add1_l * Pmsm_f32_LimitedPhasVBus_B * rtb_Gain;
      PmsmDefault_Pmsm_Foc_MotB.UnitDelay1_DSTATE = (rtb_Add1_l - rtb_Product_d)
        - Pmsm_f32_EmfComp_Vq_B;
    }

    /* End of Switch: '<S30>/Switch' */

    /* Switch: '<S28>/Switch' incorporates:
     *  Abs: '<S30>/Abs'
     *  RelationalOperator: '<S30>/Relational Operator1'
     *  Sum: '<S28>/Subtract'
     *  UnitDelay: '<S5>/Unit Delay2'
     */
    if (fabsf(rtb_Add_lw) <= Pmsm_f32_LimitedPhasVBus_B) {
      PmsmDefault_Pmsm_Foc_MotB.UnitDelay2_DSTATE = rtb_Switch2_gp;
    } else {
      PmsmDefault_Pmsm_Foc_MotB.UnitDelay2_DSTATE = (rtb_Gain1_e -
        rtb_Product2_d4) - Pmsm_f32_EmfComp_Vd_B;
    }

    /* End of Switch: '<S28>/Switch' */

    /* Product: '<S29>/Product' */
    PmsmDefault_Pmsm_Foc_MotB.Product = rtb_Gain1_e * rtb_Divide;

    /* Product: '<S29>/Product1' */
    PmsmDefault_Pmsm_Foc_MotB.Product1 = rtb_Divide * rtb_Add1_l;
  } else {
    PmsmDefault_Pmsm_Foc_MotB.Current_Loop_Controller_MODE = false;
  }

  /* End of Logic: '<S4>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S1>/Current_Loop_Controller' */

  /* Outputs for Enabled SubSystem: '<S6>/Subsystem' incorporates:
   *  EnablePort: '<S38>/Enable'
   */
  /* Constant: '<S6>/Constant' */
  if (Pmsm_bl_DeadZoneCompEnable_B) {
    /* Switch: '<S41>/Switch2' incorporates:
     *  Constant: '<S38>/Constant'
     *  Gain: '<S38>/Gain'
     *  Inport: '<Root>/Current_V'
     *  RelationalOperator: '<S41>/LowerRelop1'
     *  RelationalOperator: '<S41>/UpperRelop'
     *  Switch: '<S41>/Switch'
     */
    if (Pmsm_f32_IV_B > Pmsm_f32_DeadZoneCompVal_B) {
      rtb_Switch2_gp = Pmsm_f32_DeadZoneCompVal_B;
    } else if (Pmsm_f32_IV_B < -Pmsm_f32_DeadZoneCompVal_B) {
      /* Switch: '<S41>/Switch' incorporates:
       *  Gain: '<S38>/Gain'
       */
      rtb_Switch2_gp = -Pmsm_f32_DeadZoneCompVal_B;
    } else {
      rtb_Switch2_gp = Pmsm_f32_IV_B;
    }

    /* End of Switch: '<S41>/Switch2' */

    /* Switch: '<S42>/Switch2' incorporates:
     *  Constant: '<S38>/Constant'
     *  Gain: '<S38>/Gain'
     *  Inport: '<Root>/Current_W'
     *  RelationalOperator: '<S42>/LowerRelop1'
     *  RelationalOperator: '<S42>/UpperRelop'
     *  Switch: '<S42>/Switch'
     */
    if (Pmsm_f32_IW_B > Pmsm_f32_DeadZoneCompVal_B) {
      rtb_Gain_p = Pmsm_f32_DeadZoneCompVal_B;
    } else if (Pmsm_f32_IW_B < -Pmsm_f32_DeadZoneCompVal_B) {
      /* Switch: '<S42>/Switch' incorporates:
       *  Gain: '<S38>/Gain'
       */
      rtb_Gain_p = -Pmsm_f32_DeadZoneCompVal_B;
    } else {
      rtb_Gain_p = Pmsm_f32_IW_B;
    }

    /* End of Switch: '<S42>/Switch2' */

    /* Switch: '<S40>/Switch2' incorporates:
     *  Constant: '<S38>/Constant'
     *  Gain: '<S38>/Gain'
     *  Inport: '<Root>/Current_U'
     *  RelationalOperator: '<S40>/LowerRelop1'
     *  RelationalOperator: '<S40>/UpperRelop'
     *  Switch: '<S40>/Switch'
     */
    if (Pmsm_f32_IU_B > Pmsm_f32_DeadZoneCompVal_B) {
      rtb_Gain = Pmsm_f32_DeadZoneCompVal_B;
    } else if (Pmsm_f32_IU_B < -Pmsm_f32_DeadZoneCompVal_B) {
      /* Switch: '<S40>/Switch' incorporates:
       *  Gain: '<S38>/Gain'
       */
      rtb_Gain = -Pmsm_f32_DeadZoneCompVal_B;
    } else {
      rtb_Gain = Pmsm_f32_IU_B;
    }

    /* End of Switch: '<S40>/Switch2' */

    /* Gain: '<S38>/Gain2' incorporates:
     *  Gain: '<S38>/Gain1'
     *  Sum: '<S38>/Add'
     */
    PmsmDefault_Pmsm_Foc_MotB.Gain2 = ((2.0F * rtb_Gain - rtb_Switch2_gp) -
      rtb_Gain_p) * 0.577350259F;

    /* Sum: '<S38>/Add1' */
    PmsmDefault_Pmsm_Foc_MotB.Add1 = rtb_Switch2_gp - rtb_Gain_p;
  }

  /* End of Outputs for SubSystem: '<S6>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S16>/Subsystem' incorporates:
   *  EnablePort: '<S59>/Enable'
   */
  /* Logic: '<S16>/Logical Operator' incorporates:
   *  Constant: '<S16>/Constant1'
   *  RelationalOperator: '<S58>/Compare'
   */
  if (Pmsm_bl_AngCompEnable_B && rtb_LogicalOperator1) {
    /* Gain: '<S59>/Gain' incorporates:
     *  Constant: '<S59>/Constant1'
     *  DataTypeConversion: '<S59>/Data Type Conversion'
     *  Inport: '<Root>/Theta'
     *  Product: '<S59>/Product'
     *  Sum: '<S59>/Add'
     */
    rtb_Gain_p = (real32_T)(uint16_T)((uint32_T)(uint16_T)(rtb_Switch2 *
      Pmsm_f32_AngCompCoeff_B) + Pmsm_u16_SensorTheta_B) * 9.58738E-5F;

    /* Trigonometry: '<S59>/Trigonometric Function' */
    PmsmDefault_Pmsm_Foc_MotB.TrigonometricFunction_o1 = sinf(rtb_Gain_p);

    /* Trigonometry: '<S59>/Trigonometric Function' */
    PmsmDefault_Pmsm_Foc_MotB.TrigonometricFunction_o2 = cosf(rtb_Gain_p);

    /* Switch: '<S16>/Switch' */
    rtb_Gain1_e = PmsmDefault_Pmsm_Foc_MotB.TrigonometricFunction_o1;
    rtb_Add1_l = PmsmDefault_Pmsm_Foc_MotB.TrigonometricFunction_o2;
  } else {
    /* Switch: '<S16>/Switch' incorporates:
     *  Trigonometry: '<S16>/Trigonometric Function1'
     */
    rtb_Gain1_e = rtb_Product_m3;
    rtb_Add1_l = cosOut;
  }

  /* End of Logic: '<S16>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S16>/Subsystem' */

  /* Switch: '<S19>/Switch1' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S4>/Constant4'
   *  Logic: '<S4>/Logical Operator2'
   *  RelationalOperator: '<S20>/Compare'
   */
  if (rtb_LogicalOperator2_p || rtb_Compare_gq || (Pmsm_u8_MotCmdSel_B == 3)) {
    /* Gain: '<S19>/Gain' incorporates:
     *  Inport: '<Root>/Dbg_VdRef'
     */
    Pmsm_f32_VdCmd_B = Pmsm_f32_DbgVdRef_B;

    /* Gain: '<S19>/Gain1' incorporates:
     *  Inport: '<Root>/Dbg_VqRef'
     */
    Pmsm_f32_VqCmd_B = Pmsm_f32_DbgVqRef_B;
  } else {
    /* Gain: '<S19>/Gain' */
    Pmsm_f32_VdCmd_B = PmsmDefault_Pmsm_Foc_MotB.Product;

    /* Gain: '<S19>/Gain1' */
    Pmsm_f32_VqCmd_B = PmsmDefault_Pmsm_Foc_MotB.Product1;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (Pmsm_bl_DeadZoneCompEnable_B) {
    /* Gain: '<S39>/Gain' */
    Pmsm_f32_DeadZoneUalpha_B = PmsmDefault_Pmsm_Foc_MotB.Gain2;

    /* Gain: '<S39>/Gain1' */
    Pmsm_f32_DeadZoneUbeta_B = PmsmDefault_Pmsm_Foc_MotB.Add1;
  } else {
    /* Gain: '<S39>/Gain' incorporates:
     *  Constant: '<S39>/Constant1'
     */
    Pmsm_f32_DeadZoneUalpha_B = 0.0F;

    /* Gain: '<S39>/Gain1' incorporates:
     *  Constant: '<S39>/Constant1'
     */
    Pmsm_f32_DeadZoneUbeta_B = 0.0F;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Sum: '<S56>/Add3' incorporates:
   *  Product: '<S56>/VdXSine'
   *  Product: '<S56>/VqXCosine'
   *  Sum: '<S56>/Add1'
   */
  Pmsm_f32_BetaVoltCmd_B = (Pmsm_f32_VdCmd_B * rtb_Gain1_e + Pmsm_f32_VqCmd_B *
    rtb_Add1_l) + Pmsm_f32_DeadZoneUbeta_B;

  /* Sum: '<S56>/Add2' incorporates:
   *  Product: '<S56>/VdXCosine'
   *  Product: '<S56>/VqXSine'
   *  Sum: '<S56>/Add'
   */
  Pmsm_f32_AlphaVoltCmd_B = (Pmsm_f32_VdCmd_B * rtb_Add1_l - Pmsm_f32_VqCmd_B *
    rtb_Gain1_e) + Pmsm_f32_DeadZoneUalpha_B;

  /* Sum: '<S55>/Subtract' incorporates:
   *  Constant: '<S55>/Constant'
   *  Constant: '<S55>/Constant1'
   *  Product: '<S55>/Product'
   *  Product: '<S55>/Product1'
   */
  rtb_Add1_l = 0.866025388F * Pmsm_f32_AlphaVoltCmd_B - 0.5F *
    Pmsm_f32_BetaVoltCmd_B;

  /* Sum: '<S55>/Subtract1' incorporates:
   *  Constant: '<S55>/Constant2'
   *  Constant: '<S55>/Constant3'
   *  Product: '<S55>/Product2'
   *  Product: '<S55>/Product3'
   */
  rtb_Gain_p = -0.866025388F * Pmsm_f32_AlphaVoltCmd_B - 0.5F *
    Pmsm_f32_BetaVoltCmd_B;

  /* Switch: '<S52>/Switch1' incorporates:
   *  Constant: '<S52>/Constant2'
   *  Constant: '<S52>/Constant3'
   */
  /* Gateway: Pmsm_Foc_MotB/SVPWM/Sector_Check */
  /* During: Pmsm_Foc_MotB/SVPWM/Sector_Check */
  /* Entry Internal: Pmsm_Foc_MotB/SVPWM/Sector_Check */
  /* Transition: '<S54>:27' */
  /*  % SectorCheck  */
  if (rtb_Add1_l > 0.0F) {
    rtb_Sector = 2U;
  } else {
    rtb_Sector = 0U;
  }

  /* End of Switch: '<S52>/Switch1' */

  /* Switch: '<S52>/Switch2' incorporates:
   *  Constant: '<S52>/Constant4'
   *  Constant: '<S52>/Constant5'
   */
  if (rtb_Gain_p > 0.0F) {
    rtb_Subtract1_p_0 = 4U;
  } else {
    rtb_Subtract1_p_0 = 0U;
  }

  /* End of Switch: '<S52>/Switch2' */

  /* Chart: '<S15>/Sector_Check' incorporates:
   *  Sum: '<S52>/Add'
   *  Switch: '<S52>/Switch'
   */
  switch ((int32_T)(((uint32_T)(Pmsm_f32_BetaVoltCmd_B > 0.0F) + rtb_Sector) +
                    rtb_Subtract1_p_0)) {
   case 1:
    /* Transition: '<S54>:29' */
    /* Transition: '<S54>:31' */
    rtb_Gain1_e = -rtb_Add1_l;
    rtb_Gain_p = -rtb_Gain_p;
    rtb_Sector = 2U;

    /* Transition: '<S54>:70' */
    /* Transition: '<S54>:71' */
    /* Transition: '<S54>:72' */
    /* Transition: '<S54>:73' */
    /* Transition: '<S54>:74' */
    /* Transition: '<S54>:75' */
    break;

   case 2:
    /* Transition: '<S54>:35' */
    /* Transition: '<S54>:36' */
    /* Transition: '<S54>:37' */
    rtb_Gain1_e = -rtb_Gain_p;
    rtb_Gain_p = -Pmsm_f32_BetaVoltCmd_B;
    rtb_Sector = 6U;

    /* Transition: '<S54>:71' */
    /* Transition: '<S54>:72' */
    /* Transition: '<S54>:73' */
    /* Transition: '<S54>:74' */
    /* Transition: '<S54>:75' */
    break;

   case 3:
    /* Transition: '<S54>:39' */
    /* Transition: '<S54>:8' */
    /* Transition: '<S54>:40' */
    rtb_Gain1_e = rtb_Add1_l;
    rtb_Gain_p = Pmsm_f32_BetaVoltCmd_B;
    rtb_Sector = 1U;

    /* Transition: '<S54>:72' */
    /* Transition: '<S54>:73' */
    /* Transition: '<S54>:74' */
    /* Transition: '<S54>:75' */
    break;

   case 4:
    /* Transition: '<S54>:16' */
    /* Transition: '<S54>:43' */
    /* Transition: '<S54>:44' */
    rtb_Gain1_e = -Pmsm_f32_BetaVoltCmd_B;
    rtb_Gain_p = -rtb_Add1_l;
    rtb_Sector = 4U;

    /* Transition: '<S54>:73' */
    /* Transition: '<S54>:74' */
    /* Transition: '<S54>:75' */
    break;

   case 5:
    /* Transition: '<S54>:10' */
    /* Transition: '<S54>:17' */
    /* Transition: '<S54>:24' */
    rtb_Gain1_e = Pmsm_f32_BetaVoltCmd_B;
    rtb_Sector = 3U;

    /* Transition: '<S54>:74' */
    /* Transition: '<S54>:75' */
    break;

   case 6:
    /* Transition: '<S54>:25' */
    /* Transition: '<S54>:13' */
    /* Transition: '<S54>:18' */
    rtb_Gain1_e = rtb_Gain_p;
    rtb_Gain_p = rtb_Add1_l;
    rtb_Sector = 5U;

    /* Transition: '<S54>:75' */
    break;

   default:
    /* Transition: '<S54>:19' */
    /* Transition: '<S54>:20' */
    /* Transition: '<S54>:15' */
    rtb_Gain1_e = (real32_T)0.0;
    rtb_Gain_p = (real32_T)0.0;
    rtb_Sector = 0U;
    break;
  }

  /* End of Chart: '<S15>/Sector_Check' */

  /* Chart: '<S15>/Over_Mudulation' incorporates:
   *  Constant: '<S15>/Rmax'
   */
  /* Gateway: Pmsm_Foc_MotB/SVPWM/Over_Mudulation */
  /* During: Pmsm_Foc_MotB/SVPWM/Over_Mudulation */
  /* Entry Internal: Pmsm_Foc_MotB/SVPWM/Over_Mudulation */
  /* Transition: '<S53>:14' */
  rtb_Add1_l = rtb_Gain1_e + rtb_Gain_p;
  rtb_Switch2 = Pmsm_f32_SvpwmRMax_B / rtb_Add1_l;
  if (rtb_Add1_l > Pmsm_f32_SvpwmRMax_B) {
    /* Transition: '<S53>:30' */
    rtb_Gain1_e *= rtb_Switch2;
    rtb_Gain_p *= rtb_Switch2;

    /* Transition: '<S53>:37' */
  } else {
    /* Transition: '<S53>:27' */
    /* Transition: '<S53>:38' */
  }

  /* End of Chart: '<S15>/Over_Mudulation' */

  /* Sum: '<S51>/Add' incorporates:
   *  Chart: '<S15>/DutyLMS_Calculation'
   */
  Pmsm_f32_RxAddRy_B = rtb_Gain1_e + rtb_Gain_p;

  /* Chart: '<S51>/PWM7_PWM5_Select' incorporates:
   *  Constant: '<S51>/Constant2'
   *  Constant: '<S51>/Constant4'
   */
  /* Gateway: Pmsm_Foc_MotB/SVPWM/Mode_Selection/PWM7_PWM5_Select */
  /* During: Pmsm_Foc_MotB/SVPWM/Mode_Selection/PWM7_PWM5_Select */
  /* Entry Internal: Pmsm_Foc_MotB/SVPWM/Mode_Selection/PWM7_PWM5_Select */
  /* Transition: '<S57>:34' */
  /*  % PWM7_PWM5_Select  */
  if (Pmsm_f32_RxAddRy_B > Pmsm_f32_UpSelSvm5Val_B) {
    /* Transition: '<S57>:36' */
    /* Transition: '<S57>:37' */
    PmsmDefault_Pmsm_Foc_MotB.Pwm7_Pwm5_Select = true;

    /* Transition: '<S57>:47' */
    /* Transition: '<S57>:56' */

    /* Transition: '<S57>:35' */
  } else if (Pmsm_f32_RxAddRy_B < Pmsm_f32_DnSelSvm7Val_B) {
    /* Transition: '<S57>:38' */
    /* Transition: '<S57>:39' */
    PmsmDefault_Pmsm_Foc_MotB.Pwm7_Pwm5_Select = false;

    /* Transition: '<S57>:56' */
  } else {
    /* Transition: '<S57>:50' */
    /* Transition: '<S57>:52' */
    /* Transition: '<S57>:48' */
  }

  /* End of Chart: '<S51>/PWM7_PWM5_Select' */

  /* Logic: '<S51>/Logical Operator1' incorporates:
   *  Constant: '<S51>/Constant1'
   *  Constant: '<S51>/Constant6'
   *  Logic: '<S51>/Logical Operator'
   */
  Pmsm_bl_Svpwm5or7SelFlg_B = ((PmsmDefault_Pmsm_Foc_MotB.Pwm7_Pwm5_Select ||
    Pmsm_bl_Svm5ForcEnb_B) && Pmsm_bl_Svm5or7SelEnable_B);

  /* Chart: '<S15>/DutyLMS_Calculation' incorporates:
   *  Switch: '<S51>/Switch'
   */
  /* Gateway: Pmsm_Foc_MotB/SVPWM/DutyLMS_Calculation */
  /* During: Pmsm_Foc_MotB/SVPWM/DutyLMS_Calculation */
  /* Entry Internal: Pmsm_Foc_MotB/SVPWM/DutyLMS_Calculation */
  /* Transition: '<S50>:18' */
  /*  % SVPWM 7  */
  if (!Pmsm_bl_Svpwm5or7SelFlg_B) {
    /* Transition: '<S50>:11' */
    /* Transition: '<S50>:14' */
    Pmsm_f32_DutyW_B = (((real32_T)1.0 - rtb_Gain1_e) - rtb_Gain_p) * (real32_T)
      0.5;
    rtb_Gain_p += Pmsm_f32_DutyW_B;
    rtb_Gain1_e += rtb_Gain_p;

    /* Transition: '<S50>:19' */
  } else {
    /* Transition: '<S50>:12' */
    /*  % SVPWM 5  U0  */
    /* Transition: '<S50>:17' */
    /* Transition: '<S50>:9' */
    Pmsm_f32_DutyW_B = (real32_T)0.0;
    rtb_Gain1_e = Pmsm_f32_RxAddRy_B;

    /* Transition: '<S50>:34' */
  }

  /* Chart: '<S15>/DutyABC_Allocation' */
  /* Gateway: Pmsm_Foc_MotB/SVPWM/DutyABC_Allocation */
  /* During: Pmsm_Foc_MotB/SVPWM/DutyABC_Allocation */
  /* Entry Internal: Pmsm_Foc_MotB/SVPWM/DutyABC_Allocation */
  /* Transition: '<S49>:17' */
  /*  % Allocate_DutyABC  */
  switch (rtb_Sector) {
   case 1:
    /* Transition: '<S49>:50' */
    /* Transition: '<S49>:24' */
    Pmsm_f32_DutyU_B = rtb_Gain1_e;
    Pmsm_f32_DutyV_B = rtb_Gain_p;

    /* Transition: '<S49>:70' */
    /* Transition: '<S49>:71' */
    /* Transition: '<S49>:72' */
    /* Transition: '<S49>:73' */
    /* Transition: '<S49>:74' */
    /* Transition: '<S49>:75' */
    break;

   case 2:
    /* Transition: '<S49>:29' */
    /* Transition: '<S49>:45' */
    /* Transition: '<S49>:47' */
    Pmsm_f32_DutyU_B = rtb_Gain_p;
    Pmsm_f32_DutyV_B = rtb_Gain1_e;

    /* Transition: '<S49>:71' */
    /* Transition: '<S49>:72' */
    /* Transition: '<S49>:73' */
    /* Transition: '<S49>:74' */
    /* Transition: '<S49>:75' */
    break;

   case 3:
    /* Transition: '<S49>:20' */
    /* Transition: '<S49>:52' */
    /* Transition: '<S49>:19' */
    Pmsm_f32_DutyU_B = Pmsm_f32_DutyW_B;
    Pmsm_f32_DutyV_B = rtb_Gain1_e;
    Pmsm_f32_DutyW_B = rtb_Gain_p;

    /* Transition: '<S49>:72' */
    /* Transition: '<S49>:73' */
    /* Transition: '<S49>:74' */
    /* Transition: '<S49>:75' */
    break;

   case 4:
    /* Transition: '<S49>:10' */
    /* Transition: '<S49>:37' */
    /* Transition: '<S49>:51' */
    Pmsm_f32_DutyU_B = Pmsm_f32_DutyW_B;
    Pmsm_f32_DutyV_B = rtb_Gain_p;
    Pmsm_f32_DutyW_B = rtb_Gain1_e;

    /* Transition: '<S49>:73' */
    /* Transition: '<S49>:74' */
    /* Transition: '<S49>:75' */
    break;

   case 5:
    /* Transition: '<S49>:22' */
    /* Transition: '<S49>:67' */
    /* Transition: '<S49>:56' */
    Pmsm_f32_DutyU_B = rtb_Gain_p;
    Pmsm_f32_DutyV_B = Pmsm_f32_DutyW_B;
    Pmsm_f32_DutyW_B = rtb_Gain1_e;

    /* Transition: '<S49>:74' */
    /* Transition: '<S49>:75' */
    break;

   case 6:
    /* Transition: '<S49>:65' */
    /* Transition: '<S49>:63' */
    /* Transition: '<S49>:57' */
    Pmsm_f32_DutyU_B = rtb_Gain1_e;
    Pmsm_f32_DutyV_B = Pmsm_f32_DutyW_B;
    Pmsm_f32_DutyW_B = rtb_Gain_p;

    /* Transition: '<S49>:75' */
    break;

   default:
    /* Transition: '<S49>:66' */
    /* Transition: '<S49>:58' */
    /* Transition: '<S49>:64' */
    Pmsm_f32_DutyU_B = (real32_T)0.5;
    Pmsm_f32_DutyV_B = (real32_T)0.5;
    Pmsm_f32_DutyW_B = (real32_T)0.5;
    break;
  }

  /* End of Chart: '<S15>/DutyABC_Allocation' */

  /* Switch: '<S14>/Switch2' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S4>/Constant4'
   *  Logic: '<S4>/Logical Operator1'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   */
  if ((Pmsm_u8_MotCmdSel_B > 7) || (Pmsm_u8_MotCmdSel_B == 4)) {
    /* Gain: '<S14>/Gain2' incorporates:
     *  Inport: '<Root>/Dbg_DutyU'
     */
    Pmsm_f32_DutyU_B = Pmsm_f32_DbgDutyU_B;

    /* Gain: '<S14>/Gain3' incorporates:
     *  Inport: '<Root>/Dbg_DutyV'
     */
    Pmsm_f32_DutyV_B = Pmsm_f32_DbgDutyV_B;

    /* Gain: '<S14>/Gain4' incorporates:
     *  Inport: '<Root>/Dbg_DutyW'
     */
    Pmsm_f32_DutyW_B = Pmsm_f32_DbgDutyW_B;
  }

  /* End of Switch: '<S14>/Switch2' */

  /* RelationalOperator: '<S48>/Compare' */
  Pmsm_bl_ZeroIVldSvpwmOut_B = !Pmsm_bl_Svpwm5or7SelFlg_B;

  /* Sqrt: '<S10>/Sqrt' incorporates:
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  Sum: '<S10>/Add1'
   */
  Pmsm_f32_Is_B = sqrtf(Pmsm_f32_Id_B * Pmsm_f32_Id_B + Pmsm_f32_Iq_B *
                        Pmsm_f32_Iq_B);

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Pmsm_f32_MotorTorque_B = Pmsm_f32_Iq_B * Pmsm_f32_Kt_B;

  /* Sum: '<S9>/Subtract' incorporates:
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Trigonometry: '<S16>/Trigonometric Function1'
   */
  Pmsm_f32_IuRef_B = Pmsm_f32_IdRef_B * cosOut - Pmsm_f32_IqRef_B *
    rtb_Product_m3;

  /* Gain: '<S9>/Gain' */
  rtb_Gain_p = -0.5F * Pmsm_f32_IuRef_B;

  /* Gain: '<S9>/Gain1' incorporates:
   *  Product: '<S9>/Product2'
   *  Product: '<S9>/Product3'
   *  Sum: '<S9>/Add'
   *  Trigonometry: '<S16>/Trigonometric Function1'
   */
  rtb_Gain1_e = (Pmsm_f32_IdRef_B * rtb_Product_m3 + Pmsm_f32_IqRef_B * cosOut) *
    0.866025388F;

  /* Sum: '<S9>/Add1' */
  Pmsm_f32_IvRef_B = rtb_Gain_p + rtb_Gain1_e;

  /* Sum: '<S9>/Subtract1' */
  Pmsm_f32_IwRef_B = rtb_Gain_p - rtb_Gain1_e;

  /* Update for Delay: '<S62>/Delay1' */
  PmsmDefault_Pmsm_Foc_MotB.icLoad = false;
}

#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Model initialize function */

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_Foc_MotB_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* custom signals */
  Pmsm_f32_BusCurrent_B = 0.0F;
  Pmsm_f32_IdRef_B = 0.0F;
  Pmsm_f32_IqRef_B = 0.0F;
  Pmsm_f32_Id_B = 0.0F;
  Pmsm_f32_FiltedId_B = 0.0F;
  Pmsm_f32_Iq_B = 0.0F;
  Pmsm_f32_FiltedIq_B = 0.0F;
  Pmsm_f32_EmfComp_Vd_B = 0.0F;
  Pmsm_f32_EmfComp_Vq_B = 0.0F;
  Pmsm_f32_VdCmd_B = 0.0F;
  Pmsm_f32_VqCmd_B = 0.0F;
  Pmsm_f32_DeadZoneUbeta_B = 0.0F;
  Pmsm_f32_BetaVoltCmd_B = 0.0F;
  Pmsm_f32_DeadZoneUalpha_B = 0.0F;
  Pmsm_f32_AlphaVoltCmd_B = 0.0F;
  Pmsm_f32_RxAddRy_B = 0.0F;
  Pmsm_f32_DutyU_B = 0.0F;
  Pmsm_f32_DutyV_B = 0.0F;
  Pmsm_f32_DutyW_B = 0.0F;
  Pmsm_f32_Is_B = 0.0F;
  Pmsm_f32_MotorTorque_B = 0.0F;
  Pmsm_f32_IuRef_B = 0.0F;
  Pmsm_f32_IvRef_B = 0.0F;
  Pmsm_f32_IwRef_B = 0.0F;
  Pmsm_f32_LimitedPhasVBus_B = 0.0F;
  Pmsm_f32_PIVoltCmd_B = 0.0F;
  Pmsm_u16_Theta_B = 0U;
  Pmsm_bl_Svpwm5or7SelFlg_B = false;
  Pmsm_bl_ZeroIVldSvpwmOut_B = false;
  Pmsm_bl_PIVoltSaturatFlg_B = false;

  /* Initialize Storage class 'PmsmDefault' */
  (void) memset((void *)&PmsmDefault_Pmsm_Foc_MotB, 0,
                sizeof(Pmsm_Foc_MotB_PmsmDefault));

  /* external inputs */
  Pmsm_bl_FlxCtrlCmdFlgIn_B = false;
  Pmsm_f32_FlxIdRefIn_B = 0.0F;
  Pmsm_f32_FlxIqRefIn_B = 0.0F;
  Pmsm_f32_DeadBand_B = 0.0F;
  Pmsm_f32_D_PGain_B = 0.0F;
  Pmsm_f32_D_IGain_B = 0.0F;
  Pmsm_f32_Q_PGain_B = 0.0F;
  Pmsm_f32_Q_IGain_B = 0.0F;
  Pmsm_f32_DbgIdRef_B = 0.0F;
  Pmsm_f32_DbgIqRef_B = 0.0F;
  Pmsm_f32_DbgVdRef_B = 0.0F;
  Pmsm_f32_DbgVqRef_B = 0.0F;
  Pmsm_f32_DbgDutyU_B = 0.0F;
  Pmsm_f32_DbgDutyV_B = 0.0F;
  Pmsm_f32_DbgDutyW_B = 0.0F;
  Pmsm_f32_IU_B = 0.0F;
  Pmsm_f32_IV_B = 0.0F;
  Pmsm_f32_IW_B = 0.0F;
  Pmsm_u16_SensorTheta_B = 0U;
  Pmsm_u16_DbgTheta_B = 0U;
  Pmsm_f32_MotorSpeed_B = 0.0F;
  Pmsm_f32_VBus_B = 0.0F;

  /* InitializeConditions for Delay: '<S62>/Delay1' */
  PmsmDefault_Pmsm_Foc_MotB.icLoad = true;

  /* SystemInitialize for Enabled SubSystem: '<S16>/VF' */
  /* InitializeConditions for Delay: '<S60>/Delay' */
  PmsmDefault_Pmsm_Foc_MotB.Delay_DSTATE_p = 0;

  /* End of SystemInitialize for SubSystem: '<S16>/VF' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/Current_Loop_Controller' */
  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay2' */
  PmsmDefault_Pmsm_Foc_MotB.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
  PmsmDefault_Pmsm_Foc_MotB.UnitDelay1_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S1>/Current_Loop_Controller' */

  /* SystemInitialize for Chart: '<S51>/PWM7_PWM5_Select' */
  PmsmDefault_Pmsm_Foc_MotB.Pwm7_Pwm5_Select = false;
}

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Model terminate function */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_Foc_MotB_terminate(void)
{
  /* (no terminate code required) */
}

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
