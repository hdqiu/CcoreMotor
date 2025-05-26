/*
 * File: Pmsm_RdcCalcThetaSpeed_MotB.h
 *
 * Code generated for Simulink model 'Pmsm_RdcCalcThetaSpeed_MotB'.
 *
 * Model version                  : 1.155
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Apr  9 11:11:26 2025
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

#ifndef RTW_HEADER_Pmsm_RdcCalcThetaSpeed_MotB_h_
#define RTW_HEADER_Pmsm_RdcCalcThetaSpeed_MotB_h_
#ifndef Pmsm_RdcCalcThetaSpeed_MotB_COMMON_INCLUDES_
#define Pmsm_RdcCalcThetaSpeed_MotB_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                        /* Pmsm_RdcCalcThetaSpeed_MotB_COMMON_INCLUDES_ */

#include "Pmsm_RdcCalcThetaSpeed_MotB_types.h"
#include <string.h>

/* Storage class 'PmsmDefault', for system '<Root>' */
typedef struct {
  uint16_T Delay_DSTATE[10];           /* '<S4>/Delay' */
  boolean_T icLoad;                    /* '<S4>/Delay' */
} Pmsm_RdcCalcThetaSpeed_MotB_PmsmDefault;

/* Model entry point functions */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_RdcCalcThetaSpeed_MotB_initialize(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Code 2 RAM */
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_RdcCalcThetaSpeed_MotB_step(void);

#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

extern void Pmsm_RdcCalcThetaSpeed_MotB_terminate(void);

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

extern Pmsm_RdcCalcThetaSpeed_MotB_PmsmDefault
  PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB;/* '<S4>/Delay' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Exported data declaration */

/* pmsm trusted bss 16bits */
/* Declaration for custom storage class: TRUSTED_BSS_16BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_RdcEAngleCnt_B;/* '<Root>/RdcEAngleCnt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern uint16_T Pmsm_u16_RdcEAngle_B;  /* '<S2>/Subtract' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 32bits */
/* Declaration for custom storage class: TRUSTED_BSS_32BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_RdcEAng2MSpd_B;/* '<S4>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_RdcMSpd_B;    /* '<S3>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern real32_T Pmsm_f32_RdcMSpd_Radps_B;/* '<Root>/RdcMSpd_Radps' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 16bits */
/* Declaration for custom storage class: TRUSTED_DATA_16BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile uint16_T Pmsm_u16_RdceThetaOffset_C_B;/* Referenced by: '<S2>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Declaration for custom storage class: TRUSTED_DATA_32BITS */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_RdcMSpdCalcCoeff_C_B;/* Referenced by: '<S4>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Declaration for custom storage class: TRUSTED_DATA_32BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_RdcMSpdCalcFiltCoeff_C_B;/* Referenced by: '<S4>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

extern volatile real32_T Pmsm_f32_RdcSpdFiltCoeff_C_B;/* Referenced by: '<S3>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

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
 * '<Root>' : 'Pmsm_RdcCalcThetaSpeed_MotB'
 * '<S1>'   : 'Pmsm_RdcCalcThetaSpeed_MotB/Pmsm_RdcCalcThetaSpeed_MotB'
 * '<S2>'   : 'Pmsm_RdcCalcThetaSpeed_MotB/Pmsm_RdcCalcThetaSpeed_MotB/Cnt2AngCalc'
 * '<S3>'   : 'Pmsm_RdcCalcThetaSpeed_MotB/Pmsm_RdcCalcThetaSpeed_MotB/Spd_Radps_2_Rpm'
 * '<S4>'   : 'Pmsm_RdcCalcThetaSpeed_MotB/Pmsm_RdcCalcThetaSpeed_MotB/Subsystem'
 */
#endif                           /* RTW_HEADER_Pmsm_RdcCalcThetaSpeed_MotB_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
