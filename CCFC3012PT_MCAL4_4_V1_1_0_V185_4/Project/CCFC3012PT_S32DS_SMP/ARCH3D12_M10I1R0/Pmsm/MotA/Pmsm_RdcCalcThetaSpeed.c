/*
 * File: Pmsm_RdcCalcThetaSpeed.c
 *
 * Code generated for Simulink model 'Pmsm_RdcCalcThetaSpeed'.
 *
 * Model version                  : 1.152
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Apr  9 11:24:32 2025
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
#include "Pmsm_RdcCalcThetaSpeed.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED
#include "Pmsm_MemMap.h"

Pmsm_RdcCalcThetaSpeed_PmsmDefault PmsmDefault_Pmsm_RdcCalcThetaSpeed;/* '<S4>/Delay' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED
#include "Pmsm_MemMap.h"

/* Exported data definition */

/* pmsm trusted bss 16bits */
/* Definition for custom storage class: TRUSTED_BSS_16BITS */
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_RdcEAngle;           /* '<S2>/Subtract' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_RdcEAngleCnt;        /* '<Root>/RdcEAngleCnt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 32bits */
/* Definition for custom storage class: TRUSTED_BSS_32BITS */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_RdcEAng2MSpd;        /* '<S4>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_RdcMSpd;             /* '<S3>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_RdcMSpd_Radps;       /* '<Root>/RdcMSpd_Radps' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted data 16bits */
/* Definition for custom storage class: TRUSTED_DATA_16BITS */
#define PMSM_START_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"

volatile uint16_T Pmsm_u16_RdceThetaOffset_C = 0U;/* Referenced by: '<S2>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_16BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Definition for custom storage class: TRUSTED_DATA_32BITS */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_RdcMSpdCalcCoeff_C = 0.305175781F;/* Referenced by: '<S4>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_RdcMSpdCalcFiltCoeff_C = 0.2F;/* Referenced by: '<S4>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_RdcSpdFiltCoeff_C = 0.2F;/* Referenced by: '<S3>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

/* Model step function */

/* Code 2 RAM */
#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"

void Pmsm_RdcCalcThetaSpeed_step(void)
{
  int32_T i;

  /* Sum: '<S2>/Subtract' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/RdcEAngleCnt'
   *  Product: '<S2>/Product'
   */
  Pmsm_u16_RdcEAngle = (uint16_T)((uint16_T)(Pmsm_u16_RdcEAngleCnt << 4) -
    Pmsm_u16_RdceThetaOffset_C);

  /* Delay: '<S4>/Delay' */
  if (PmsmDefault_Pmsm_RdcCalcThetaSpeed.icLoad) {
    for (i = 0; i < 10; i++) {
      PmsmDefault_Pmsm_RdcCalcThetaSpeed.Delay_DSTATE[i] = Pmsm_u16_RdcEAngle;
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
  Pmsm_f32_RdcEAng2MSpd = (real32_T)(int16_T)((int16_T)Pmsm_u16_RdcEAngle -
    (int16_T)PmsmDefault_Pmsm_RdcCalcThetaSpeed.Delay_DSTATE[0]) *
    Pmsm_f32_RdcMSpdCalcCoeff_C * Pmsm_f32_RdcMSpdCalcFiltCoeff_C + (1.0F -
    Pmsm_f32_RdcMSpdCalcFiltCoeff_C) * Pmsm_f32_RdcEAng2MSpd;

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Gain: '<S3>/Gain'
   *  Inport: '<Root>/RdcMSpd_Radps'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   *  Sum: '<S3>/Subtract1'
   */
  Pmsm_f32_RdcMSpd = 9.54929638F * Pmsm_f32_RdcMSpd_Radps *
    Pmsm_f32_RdcSpdFiltCoeff_C + (1.0F - Pmsm_f32_RdcSpdFiltCoeff_C) *
    Pmsm_f32_RdcMSpd;

  /* Update for Delay: '<S4>/Delay' */
  PmsmDefault_Pmsm_RdcCalcThetaSpeed.icLoad = false;
  for (i = 0; i < 9; i++) {
    PmsmDefault_Pmsm_RdcCalcThetaSpeed.Delay_DSTATE[i] =
      PmsmDefault_Pmsm_RdcCalcThetaSpeed.Delay_DSTATE[i + 1];
  }

  PmsmDefault_Pmsm_RdcCalcThetaSpeed.Delay_DSTATE[9] = Pmsm_u16_RdcEAngle;

  /* End of Update for Delay: '<S4>/Delay' */
}

#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"

/* Model initialize function */

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

void Pmsm_RdcCalcThetaSpeed_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* custom signals */
  Pmsm_f32_RdcEAng2MSpd = 0.0F;
  Pmsm_f32_RdcMSpd = 0.0F;
  Pmsm_u16_RdcEAngle = 0U;

  /* Initialize Storage class 'PmsmDefault' */
  (void) memset((void *)&PmsmDefault_Pmsm_RdcCalcThetaSpeed, 0,
                sizeof(Pmsm_RdcCalcThetaSpeed_PmsmDefault));

  /* external inputs */
  Pmsm_u16_RdcEAngleCnt = 0U;
  Pmsm_f32_RdcMSpd_Radps = 0.0F;

  /* InitializeConditions for Delay: '<S4>/Delay' */
  PmsmDefault_Pmsm_RdcCalcThetaSpeed.icLoad = true;
}

#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

/* Model terminate function */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

void Pmsm_RdcCalcThetaSpeed_terminate(void)
{
  /* (no terminate code required) */
}

#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
