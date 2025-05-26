/*
 * File: Pmsm_RdcCalcThetaSpeed_MotB.c
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

#include "rtwtypes.h"
#include "Pmsm_RdcCalcThetaSpeed_MotB.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

Pmsm_RdcCalcThetaSpeed_MotB_PmsmDefault PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB;/* '<S4>/Delay' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Exported data definition */

/* pmsm trusted bss 16bits */
/* Definition for custom storage class: TRUSTED_BSS_16BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_RdcEAngleCnt_B;      /* '<Root>/RdcEAngleCnt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_RdcEAngle_B;         /* '<S2>/Subtract' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 32bits */
/* Definition for custom storage class: TRUSTED_BSS_32BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_RdcEAng2MSpd_B;      /* '<S4>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_RdcMSpd_B;           /* '<S3>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_RdcMSpd_Radps_B;     /* '<Root>/RdcMSpd_Radps' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 16bits */
/* Definition for custom storage class: TRUSTED_DATA_16BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"

volatile uint16_T Pmsm_u16_RdceThetaOffset_C_B = 0U;/* Referenced by: '<S2>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Definition for custom storage class: TRUSTED_DATA_32BITS */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_RdcMSpdCalcCoeff_C_B = 0.305175781F;/* Referenced by: '<S4>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Definition for custom storage class: TRUSTED_DATA_32BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_RdcMSpdCalcFiltCoeff_C_B = 0.2F;/* Referenced by: '<S4>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_RdcSpdFiltCoeff_C_B = 0.2F;/* Referenced by: '<S3>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* Model step function */

/* Code 2 RAM */
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_RdcCalcThetaSpeed_MotB_step(void)
{
  int32_T i;

  /* Sum: '<S2>/Subtract' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/RdcEAngleCnt'
   *  Product: '<S2>/Product'
   */
  Pmsm_u16_RdcEAngle_B = (uint16_T)((uint16_T)(Pmsm_u16_RdcEAngleCnt_B << 4) -
    Pmsm_u16_RdceThetaOffset_C_B);

  /* Delay: '<S4>/Delay' */
  if (PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB.icLoad) {
    for (i = 0; i < 10; i++) {
      PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB.Delay_DSTATE[i] =
        Pmsm_u16_RdcEAngle_B;
    }
  }

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  Delay: '<S4>/Delay'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Product: '<S4>/Product2'
   *  Sum: '<S4>/Subtract'
   *  Sum: '<S4>/Subtract1'
   */
  Pmsm_f32_RdcEAng2MSpd_B = (real32_T)(int16_T)((int16_T)Pmsm_u16_RdcEAngle_B -
    (int16_T)PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB.Delay_DSTATE[0]) *
    Pmsm_f32_RdcMSpdCalcCoeff_C_B * Pmsm_f32_RdcMSpdCalcFiltCoeff_C_B + (1.0F -
    Pmsm_f32_RdcMSpdCalcFiltCoeff_C_B) * Pmsm_f32_RdcEAng2MSpd_B;

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/RdcMSpd_Radps'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   *  Sum: '<S3>/Subtract1'
   */
  Pmsm_f32_RdcMSpd_B = 9.54929638F * Pmsm_f32_RdcMSpd_Radps_B *
    Pmsm_f32_RdcSpdFiltCoeff_C_B + (1.0F - Pmsm_f32_RdcSpdFiltCoeff_C_B) *
    Pmsm_f32_RdcMSpd_B;

  /* Update for Delay: '<S4>/Delay' */
  PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB.icLoad = false;
  for (i = 0; i < 9; i++) {
    PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB.Delay_DSTATE[i] =
      PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB.Delay_DSTATE[i + 1];
  }

  PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB.Delay_DSTATE[9] = Pmsm_u16_RdcEAngle_B;

  /* End of Update for Delay: '<S4>/Delay' */
}

#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Model initialize function */

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_RdcCalcThetaSpeed_MotB_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* custom signals */
  Pmsm_f32_RdcEAng2MSpd_B = 0.0F;
  Pmsm_f32_RdcMSpd_B = 0.0F;
  Pmsm_u16_RdcEAngle_B = 0U;

  /* Initialize Storage class 'PmsmDefault' */
  (void) memset((void *)&PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB, 0,
                sizeof(Pmsm_RdcCalcThetaSpeed_MotB_PmsmDefault));

  /* external inputs */
  Pmsm_u16_RdcEAngleCnt_B = 0U;
  Pmsm_f32_RdcMSpd_Radps_B = 0.0F;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  PmsmDefault_Pmsm_RdcCalcThetaSpeed_MotB.icLoad = true;
}

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Model terminate function */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_RdcCalcThetaSpeed_MotB_terminate(void)
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
