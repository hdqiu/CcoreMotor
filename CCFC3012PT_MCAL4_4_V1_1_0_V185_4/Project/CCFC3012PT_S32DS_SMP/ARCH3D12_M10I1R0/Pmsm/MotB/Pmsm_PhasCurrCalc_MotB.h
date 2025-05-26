/*
 * File: Pmsm_PhasCurrCalc_MotB.h
 *
 * Code generated for Simulink model 'Pmsm_PhasCurrCalc_MotB'.
 *
 * Model version                  : 1.133
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Apr  9 11:09:46 2025
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

#ifndef RTW_HEADER_Pmsm_PhasCurrCalc_MotB_h_
#define RTW_HEADER_Pmsm_PhasCurrCalc_MotB_h_
#ifndef Pmsm_PhasCurrCalc_MotB_COMMON_INCLUDES_
#define Pmsm_PhasCurrCalc_MotB_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                             /* Pmsm_PhasCurrCalc_MotB_COMMON_INCLUDES_ */

#include "Pmsm_PhasCurrCalc_MotB_types.h"
#include <string.h>

/* Storage class 'PmsmDefault', for system '<Root>' */
typedef struct {
  uint32_T Delay_DSTATE[3];            /* '<S3>/Delay' */
  uint32_T Delay1_DSTATE[3];           /* '<S3>/Delay1' */
  uint32_T Delay2_DSTATE[3];           /* '<S3>/Delay2' */
  uint32_T Delay3_DSTATE[3];           /* '<S3>/Delay3' */
  uint32_T Delay4_DSTATE[3];           /* '<S3>/Delay4' */
  uint32_T Delay5_DSTATE[3];           /* '<S3>/Delay5' */
  uint32_T Delay6_DSTATE[3];           /* '<S3>/Delay6' */
  uint16_T Divide[3];                  /* '<S3>/Divide' */
  uint16_T OutportBufferForOut2;
  uint16_T OutportBufferForOut3;
  boolean_T icLoad;                    /* '<S3>/Delay' */
  boolean_T icLoad_g;                  /* '<S3>/Delay1' */
  boolean_T icLoad_j;                  /* '<S3>/Delay2' */
  boolean_T icLoad_a;                  /* '<S3>/Delay3' */
  boolean_T icLoad_f;                  /* '<S3>/Delay4' */
  boolean_T icLoad_d;                  /* '<S3>/Delay5' */
  boolean_T icLoad_h;                  /* '<S3>/Delay6' */
} Pmsm_PhasCurrCalc_MotB_PmsmDefault;

/* Model entry point functions */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_PhasCurrCalc_MotB_initialize(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Code 2 RAM */
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_PhasCurrCalc_MotB_step(void);

#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_PhasCurrCalc_MotB_terminate(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

extern Pmsm_PhasCurrCalc_MotB_PmsmDefault PmsmDefault_Pmsm_PhasCurrCalc_MotB;/* '<S3>/Delay' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Exported data declaration */

/* pmsm trusted bss 16bits */
/* Declaration for custom storage class: TRUSTED_BSS_16BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_AdcSampInPhasU_B;/* '<Root>/Phas_U_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_AdcSampInPhasV_B;/* '<Root>/Phas_V_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_AdcSampInPhasW_B;/* '<Root>/Phas_W_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_AdcSampInZeroU_B;/* '<Root>/Zero_U_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_AdcSampInZeroV_B;/* '<Root>/Zero_V_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_AdcSampInZeroW_B;/* '<Root>/Zero_W_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_FilterAdcZeroU_B;/* '<S1>/Signal Copy' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_FilterAdcZeroV_B;/* '<S1>/Signal Copy1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_FilterAdcZeroW_B;/* '<S1>/Signal Copy2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_PhasAdcU_B;   /* '<S1>/Signal Copy9' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_PhasAdcV_B;   /* '<S1>/Signal Copy11' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_PhasAdcW_B;   /* '<S1>/Signal Copy10' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_ZeroAdcU_B;   /* '<S1>/Signal Copy3' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_ZeroAdcV_B;   /* '<S1>/Signal Copy5' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_ZeroAdcW_B;   /* '<S1>/Signal Copy4' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 32bits */
/* Declaration for custom storage class: TRUSTED_BSS_32BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_PhasSampCurrU_B;/* '<S1>/Product' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_PhasSampCurrV_B;/* '<S1>/Product2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_PhasSampCurrW_B;/* '<S1>/Product1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 8bits */
/* Declaration for custom storage class: TRUSTED_BSS_8BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

extern boolean_T Pmsm_bl_ZeroIVld_B;   /* '<Root>/Zero_I_Vld' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Declaration for custom storage class: TRUSTED_DATA_32BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_PhsCurrUGain_B;/* Referenced by: '<S1>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_PhsCurrVGain_B;/* Referenced by: '<S1>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_PhsCurrWGain_B;/* Referenced by: '<S1>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S1>/Signal Copy7' : Eliminate redundant signal conversion block
 * Block '<S1>/Signal Copy8' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'Pmsm_PhasCurrCalc_MotB'
 * '<S1>'   : 'Pmsm_PhasCurrCalc_MotB/Pmsm_PhasCurrCalc_MotB'
 * '<S2>'   : 'Pmsm_PhasCurrCalc_MotB/Pmsm_PhasCurrCalc_MotB/Compare To Constant3'
 * '<S3>'   : 'Pmsm_PhasCurrCalc_MotB/Pmsm_PhasCurrCalc_MotB/Subsystem1'
 */
#endif                                /* RTW_HEADER_Pmsm_PhasCurrCalc_MotB_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
