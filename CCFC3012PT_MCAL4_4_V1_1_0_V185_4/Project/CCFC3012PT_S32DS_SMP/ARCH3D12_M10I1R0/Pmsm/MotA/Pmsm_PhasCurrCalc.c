/*
 * File: Pmsm_PhasCurrCalc.c
 *
 * Code generated for Simulink model 'Pmsm_PhasCurrCalc'.
 *
 * Model version                  : 1.128
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed Apr  9 11:23:15 2025
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
#include "Pmsm_PhasCurrCalc.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED
#include "Pmsm_MemMap.h"

Pmsm_PhasCurrCalc_PmsmDefault PmsmDefault_Pmsm_PhasCurrCalc;/* '<S3>/Delay' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED
#include "Pmsm_MemMap.h"

/* Exported data definition */

/* pmsm trusted bss 16bits */
/* Definition for custom storage class: TRUSTED_BSS_16BITS */
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInPhasU;      /* '<Root>/Phas_U_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInPhasV;      /* '<Root>/Phas_V_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInPhasW;      /* '<Root>/Phas_W_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInZeroU;      /* '<Root>/Zero_U_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInZeroV;      /* '<Root>/Zero_V_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInZeroW;      /* '<Root>/Zero_W_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_FilterAdcZeroU;      /* '<S1>/Signal Copy' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_FilterAdcZeroV;      /* '<S1>/Signal Copy1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_FilterAdcZeroW;      /* '<S1>/Signal Copy2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_PhasAdcU;            /* '<S1>/Signal Copy9' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_PhasAdcV;            /* '<S1>/Signal Copy11' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_PhasAdcW;            /* '<S1>/Signal Copy10' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_ZeroAdcU;            /* '<S1>/Signal Copy3' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_ZeroAdcV;            /* '<S1>/Signal Copy5' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_ZeroAdcW;            /* '<S1>/Signal Copy4' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 32bits */
/* Definition for custom storage class: TRUSTED_BSS_32BITS */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_PhasSampCurrU;       /* '<S1>/Product' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_PhasSampCurrV;       /* '<S1>/Product2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_PhasSampCurrW;       /* '<S1>/Product1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 8bits */
/* Definition for custom storage class: TRUSTED_BSS_8BITS */
#define PMSM_START_SEC_TRUSTED_BSS_8BITS
#include "Pmsm_MemMap.h"

boolean_T Pmsm_bl_ZeroIVld;            /* '<Root>/Zero_I_Vld' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Definition for custom storage class: TRUSTED_DATA_32BITS */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_PhsCurrUGain = 0.122070312F;/* Referenced by: '<S1>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_PhsCurrVGain = 0.122070312F;/* Referenced by: '<S1>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_PhsCurrWGain = 0.122070312F;/* Referenced by: '<S1>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS
#include "Pmsm_MemMap.h"

/* Model step function */

/* Code 2 RAM */
#define PMSM_START_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"

void Pmsm_PhasCurrCalc_step(void)
{
  /* Outputs for Enabled SubSystem: '<S1>/Subsystem1' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* Inport: '<Root>/Zero_I_Vld' */
  if (Pmsm_bl_ZeroIVld) {
    uint32_T rtb_Delay1_idx_0;
    uint32_T rtb_Delay1_idx_1;
    uint32_T rtb_Delay1_idx_2;
    uint32_T rtb_Delay2_idx_0;
    uint32_T rtb_Delay2_idx_1;
    uint32_T rtb_Delay2_idx_2;
    uint32_T rtb_Delay3_idx_0;
    uint32_T rtb_Delay3_idx_1;
    uint32_T rtb_Delay3_idx_2;
    uint32_T rtb_Delay4_idx_0;
    uint32_T rtb_Delay4_idx_1;
    uint32_T rtb_Delay4_idx_2;
    uint32_T rtb_Delay5_idx_0;
    uint32_T rtb_Delay5_idx_1;
    uint32_T rtb_Delay5_idx_2;
    uint32_T rtb_Delay_idx_0;
    uint32_T rtb_Delay_idx_1;
    uint32_T rtb_Delay_idx_2;

    /* Delay: '<S3>/Delay' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc.icLoad) {
      PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[0] = Pmsm_u16_AdcSampInZeroU;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[1] = Pmsm_u16_AdcSampInZeroV;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[2] = Pmsm_u16_AdcSampInZeroW;
    }

    rtb_Delay_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[0];
    rtb_Delay_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[1];
    rtb_Delay_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[2];

    /* Delay: '<S3>/Delay1' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc.icLoad_g) {
      PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[0] = Pmsm_u16_AdcSampInZeroU;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[1] = Pmsm_u16_AdcSampInZeroV;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[2] = Pmsm_u16_AdcSampInZeroW;
    }

    rtb_Delay1_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[0];
    rtb_Delay1_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[1];
    rtb_Delay1_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[2];

    /* Delay: '<S3>/Delay2' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc.icLoad_j) {
      PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[0] = Pmsm_u16_AdcSampInZeroU;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[1] = Pmsm_u16_AdcSampInZeroV;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[2] = Pmsm_u16_AdcSampInZeroW;
    }

    rtb_Delay2_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[0];
    rtb_Delay2_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[1];
    rtb_Delay2_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[2];

    /* Delay: '<S3>/Delay3' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc.icLoad_a) {
      PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[0] = Pmsm_u16_AdcSampInZeroU;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[1] = Pmsm_u16_AdcSampInZeroV;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[2] = Pmsm_u16_AdcSampInZeroW;
    }

    rtb_Delay3_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[0];
    rtb_Delay3_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[1];
    rtb_Delay3_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[2];

    /* Delay: '<S3>/Delay4' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc.icLoad_f) {
      PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[0] = Pmsm_u16_AdcSampInZeroU;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[1] = Pmsm_u16_AdcSampInZeroV;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[2] = Pmsm_u16_AdcSampInZeroW;
    }

    rtb_Delay4_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[0];
    rtb_Delay4_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[1];
    rtb_Delay4_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[2];

    /* Delay: '<S3>/Delay5' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc.icLoad_d) {
      PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[0] = Pmsm_u16_AdcSampInZeroU;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[1] = Pmsm_u16_AdcSampInZeroV;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[2] = Pmsm_u16_AdcSampInZeroW;
    }

    rtb_Delay5_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[0];
    rtb_Delay5_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[1];
    rtb_Delay5_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[2];

    /* Delay: '<S3>/Delay6' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc.icLoad_h) {
      PmsmDefault_Pmsm_PhasCurrCalc.Delay6_DSTATE[0] = Pmsm_u16_AdcSampInZeroU;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay6_DSTATE[1] = Pmsm_u16_AdcSampInZeroV;
      PmsmDefault_Pmsm_PhasCurrCalc.Delay6_DSTATE[2] = Pmsm_u16_AdcSampInZeroW;
    }

    /* Update for Delay: '<S3>/Delay' */
    PmsmDefault_Pmsm_PhasCurrCalc.icLoad = false;

    /* Update for Delay: '<S3>/Delay1' */
    PmsmDefault_Pmsm_PhasCurrCalc.icLoad_g = false;

    /* Update for Delay: '<S3>/Delay2' */
    PmsmDefault_Pmsm_PhasCurrCalc.icLoad_j = false;

    /* Update for Delay: '<S3>/Delay3' */
    PmsmDefault_Pmsm_PhasCurrCalc.icLoad_a = false;

    /* Update for Delay: '<S3>/Delay4' */
    PmsmDefault_Pmsm_PhasCurrCalc.icLoad_f = false;

    /* Update for Delay: '<S3>/Delay5' */
    PmsmDefault_Pmsm_PhasCurrCalc.icLoad_d = false;

    /* Update for Delay: '<S3>/Delay6' */
    PmsmDefault_Pmsm_PhasCurrCalc.icLoad_h = false;

    /* Product: '<S3>/Divide' incorporates:
     *  Delay: '<S3>/Delay'
     *  Delay: '<S3>/Delay1'
     *  Delay: '<S3>/Delay2'
     *  Delay: '<S3>/Delay3'
     *  Delay: '<S3>/Delay4'
     *  Delay: '<S3>/Delay5'
     *  Delay: '<S3>/Delay6'
     *  Inport: '<Root>/Zero_U_Adc'
     *  Sum: '<S3>/Add'
     */
    PmsmDefault_Pmsm_PhasCurrCalc.Divide[0] = (uint16_T)
      ((((((((Pmsm_u16_AdcSampInZeroU +
              PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[0]) +
             PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[0]) +
            PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[0]) +
           PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[0]) +
          PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[0]) +
         PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[0]) +
        PmsmDefault_Pmsm_PhasCurrCalc.Delay6_DSTATE[0]) >> 3);

    /* Update for Delay: '<S3>/Delay' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[0] = Pmsm_u16_AdcSampInZeroU;

    /* Update for Delay: '<S3>/Delay1' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[0] = rtb_Delay_idx_0;

    /* Update for Delay: '<S3>/Delay2' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[0] = rtb_Delay1_idx_0;

    /* Update for Delay: '<S3>/Delay3' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[0] = rtb_Delay2_idx_0;

    /* Update for Delay: '<S3>/Delay4' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[0] = rtb_Delay3_idx_0;

    /* Update for Delay: '<S3>/Delay5' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[0] = rtb_Delay4_idx_0;

    /* Update for Delay: '<S3>/Delay6' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay6_DSTATE[0] = rtb_Delay5_idx_0;

    /* Product: '<S3>/Divide' incorporates:
     *  Delay: '<S3>/Delay'
     *  Delay: '<S3>/Delay1'
     *  Delay: '<S3>/Delay2'
     *  Delay: '<S3>/Delay3'
     *  Delay: '<S3>/Delay4'
     *  Delay: '<S3>/Delay5'
     *  Delay: '<S3>/Delay6'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Sum: '<S3>/Add'
     */
    PmsmDefault_Pmsm_PhasCurrCalc.Divide[1] = (uint16_T)
      ((((((((Pmsm_u16_AdcSampInZeroV +
              PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[1]) +
             PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[1]) +
            PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[1]) +
           PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[1]) +
          PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[1]) +
         PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[1]) +
        PmsmDefault_Pmsm_PhasCurrCalc.Delay6_DSTATE[1]) >> 3);

    /* Update for Delay: '<S3>/Delay' incorporates:
     *  Inport: '<Root>/Zero_V_Adc'
     */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[1] = Pmsm_u16_AdcSampInZeroV;

    /* Update for Delay: '<S3>/Delay1' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[1] = rtb_Delay_idx_1;

    /* Update for Delay: '<S3>/Delay2' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[1] = rtb_Delay1_idx_1;

    /* Update for Delay: '<S3>/Delay3' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[1] = rtb_Delay2_idx_1;

    /* Update for Delay: '<S3>/Delay4' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[1] = rtb_Delay3_idx_1;

    /* Update for Delay: '<S3>/Delay5' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[1] = rtb_Delay4_idx_1;

    /* Update for Delay: '<S3>/Delay6' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay6_DSTATE[1] = rtb_Delay5_idx_1;

    /* Product: '<S3>/Divide' incorporates:
     *  Delay: '<S3>/Delay'
     *  Delay: '<S3>/Delay1'
     *  Delay: '<S3>/Delay2'
     *  Delay: '<S3>/Delay3'
     *  Delay: '<S3>/Delay4'
     *  Delay: '<S3>/Delay5'
     *  Delay: '<S3>/Delay6'
     *  Inport: '<Root>/Zero_W_Adc'
     *  Sum: '<S3>/Add'
     */
    PmsmDefault_Pmsm_PhasCurrCalc.Divide[2] = (uint16_T)
      ((((((((Pmsm_u16_AdcSampInZeroW +
              PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[2]) +
             PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[2]) +
            PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[2]) +
           PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[2]) +
          PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[2]) +
         PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[2]) +
        PmsmDefault_Pmsm_PhasCurrCalc.Delay6_DSTATE[2]) >> 3);

    /* Update for Delay: '<S3>/Delay' incorporates:
     *  Inport: '<Root>/Zero_W_Adc'
     */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay_DSTATE[2] = Pmsm_u16_AdcSampInZeroW;

    /* Update for Delay: '<S3>/Delay1' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay1_DSTATE[2] = rtb_Delay_idx_2;

    /* Update for Delay: '<S3>/Delay2' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay2_DSTATE[2] = rtb_Delay1_idx_2;

    /* Update for Delay: '<S3>/Delay3' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay3_DSTATE[2] = rtb_Delay2_idx_2;

    /* Update for Delay: '<S3>/Delay4' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay4_DSTATE[2] = rtb_Delay3_idx_2;

    /* Update for Delay: '<S3>/Delay5' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay5_DSTATE[2] = rtb_Delay4_idx_2;

    /* Update for Delay: '<S3>/Delay6' */
    PmsmDefault_Pmsm_PhasCurrCalc.Delay6_DSTATE[2] = rtb_Delay5_idx_2;

    /* SignalConversion generated from: '<S3>/Out2' */
    PmsmDefault_Pmsm_PhasCurrCalc.OutportBufferForOut2 =
      PmsmDefault_Pmsm_PhasCurrCalc.Divide[1];

    /* SignalConversion generated from: '<S3>/Out3' */
    PmsmDefault_Pmsm_PhasCurrCalc.OutportBufferForOut3 =
      PmsmDefault_Pmsm_PhasCurrCalc.Divide[2];
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem1' */

  /* SignalConversion: '<S1>/Signal Copy' */
  Pmsm_u16_FilterAdcZeroU = PmsmDefault_Pmsm_PhasCurrCalc.Divide[0];

  /* SignalConversion: '<S1>/Signal Copy1' */
  Pmsm_u16_FilterAdcZeroV = PmsmDefault_Pmsm_PhasCurrCalc.OutportBufferForOut2;

  /* SignalConversion: '<S1>/Signal Copy2' */
  Pmsm_u16_FilterAdcZeroW = PmsmDefault_Pmsm_PhasCurrCalc.OutportBufferForOut3;

  /* Switch: '<S1>/Switch' incorporates:
   *  Inport: '<Root>/Zero_I_Vld'
   *  Inport: '<Root>/Zero_U_Adc'
   *  Inport: '<Root>/Zero_V_Adc'
   *  Inport: '<Root>/Zero_W_Adc'
   */
  if (Pmsm_bl_ZeroIVld) {
    Pmsm_u16_ZeroAdcU = Pmsm_u16_AdcSampInZeroU;
    Pmsm_u16_ZeroAdcV = Pmsm_u16_AdcSampInZeroV;
    Pmsm_u16_ZeroAdcW = Pmsm_u16_AdcSampInZeroW;
  } else {
    Pmsm_u16_ZeroAdcU = Pmsm_u16_FilterAdcZeroU;
    Pmsm_u16_ZeroAdcV = Pmsm_u16_FilterAdcZeroV;
    Pmsm_u16_ZeroAdcW = Pmsm_u16_FilterAdcZeroW;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Inport: '<Root>/Phas_U_Adc'
   *  Sum: '<S1>/Subtract'
   */
  Pmsm_f32_PhasSampCurrU = (real32_T)(Pmsm_u16_ZeroAdcU -
    Pmsm_u16_AdcSampInPhasU) * Pmsm_f32_PhsCurrUGain;

  /* Product: '<S1>/Product2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/Phas_V_Adc'
   *  Sum: '<S1>/Subtract2'
   */
  Pmsm_f32_PhasSampCurrV = (real32_T)(Pmsm_u16_ZeroAdcV -
    Pmsm_u16_AdcSampInPhasV) * Pmsm_f32_PhsCurrVGain;

  /* Product: '<S1>/Product1' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Inport: '<Root>/Phas_W_Adc'
   *  Sum: '<S1>/Subtract1'
   */
  Pmsm_f32_PhasSampCurrW = (real32_T)(Pmsm_u16_ZeroAdcW -
    Pmsm_u16_AdcSampInPhasW) * Pmsm_f32_PhsCurrWGain;

  /* SignalConversion: '<S1>/Signal Copy9' incorporates:
   *  Inport: '<Root>/Phas_U_Adc'
   */
  Pmsm_u16_PhasAdcU = Pmsm_u16_AdcSampInPhasU;

  /* SignalConversion: '<S1>/Signal Copy11' incorporates:
   *  Inport: '<Root>/Phas_V_Adc'
   */
  Pmsm_u16_PhasAdcV = Pmsm_u16_AdcSampInPhasV;

  /* SignalConversion: '<S1>/Signal Copy10' incorporates:
   *  Inport: '<Root>/Phas_W_Adc'
   */
  Pmsm_u16_PhasAdcW = Pmsm_u16_AdcSampInPhasW;
}

#define PMSM_STOP_SEC_PSRAM_TEXT
#include "Pmsm_MemMap.h"

/* Model initialize function */

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

void Pmsm_PhasCurrCalc_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* custom signals */
  Pmsm_f32_PhasSampCurrU = 0.0F;
  Pmsm_f32_PhasSampCurrV = 0.0F;
  Pmsm_f32_PhasSampCurrW = 0.0F;
  Pmsm_u16_FilterAdcZeroU = 0U;
  Pmsm_u16_FilterAdcZeroV = 0U;
  Pmsm_u16_FilterAdcZeroW = 0U;
  Pmsm_u16_ZeroAdcU = 0U;
  Pmsm_u16_ZeroAdcV = 0U;
  Pmsm_u16_ZeroAdcW = 0U;
  Pmsm_u16_PhasAdcU = 0U;
  Pmsm_u16_PhasAdcV = 0U;
  Pmsm_u16_PhasAdcW = 0U;

  /* Initialize Storage class 'PmsmDefault' */
  (void) memset((void *)&PmsmDefault_Pmsm_PhasCurrCalc, 0,
                sizeof(Pmsm_PhasCurrCalc_PmsmDefault));

  /* external inputs */
  Pmsm_u16_AdcSampInZeroU = 0U;
  Pmsm_u16_AdcSampInZeroV = 0U;
  Pmsm_u16_AdcSampInZeroW = 0U;
  Pmsm_u16_AdcSampInPhasU = 0U;
  Pmsm_u16_AdcSampInPhasV = 0U;
  Pmsm_u16_AdcSampInPhasW = 0U;
  Pmsm_bl_ZeroIVld = false;

  /* SystemInitialize for Enabled SubSystem: '<S1>/Subsystem1' */
  /* InitializeConditions for Delay: '<S3>/Delay' */
  PmsmDefault_Pmsm_PhasCurrCalc.icLoad = true;

  /* InitializeConditions for Delay: '<S3>/Delay1' */
  PmsmDefault_Pmsm_PhasCurrCalc.icLoad_g = true;

  /* InitializeConditions for Delay: '<S3>/Delay2' */
  PmsmDefault_Pmsm_PhasCurrCalc.icLoad_j = true;

  /* InitializeConditions for Delay: '<S3>/Delay3' */
  PmsmDefault_Pmsm_PhasCurrCalc.icLoad_a = true;

  /* InitializeConditions for Delay: '<S3>/Delay4' */
  PmsmDefault_Pmsm_PhasCurrCalc.icLoad_f = true;

  /* InitializeConditions for Delay: '<S3>/Delay5' */
  PmsmDefault_Pmsm_PhasCurrCalc.icLoad_d = true;

  /* InitializeConditions for Delay: '<S3>/Delay6' */
  PmsmDefault_Pmsm_PhasCurrCalc.icLoad_h = true;

  /* End of SystemInitialize for SubSystem: '<S1>/Subsystem1' */
}

#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

/* Model terminate function */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

void Pmsm_PhasCurrCalc_terminate(void)
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
