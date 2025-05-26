/*
 * File: Pmsm_PhasCurrCalc_MotB.c
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

#include "rtwtypes.h"
#include "Pmsm_PhasCurrCalc_MotB.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

Pmsm_PhasCurrCalc_MotB_PmsmDefault PmsmDefault_Pmsm_PhasCurrCalc_MotB;/* '<S3>/Delay' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Exported data definition */

/* pmsm trusted bss 16bits */
/* Definition for custom storage class: TRUSTED_BSS_16BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInPhasU_B;    /* '<Root>/Phas_U_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInPhasV_B;    /* '<Root>/Phas_V_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInPhasW_B;    /* '<Root>/Phas_W_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInZeroU_B;    /* '<Root>/Zero_U_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInZeroV_B;    /* '<Root>/Zero_V_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_AdcSampInZeroW_B;    /* '<Root>/Zero_W_Adc' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_FilterAdcZeroU_B;    /* '<S1>/Signal Copy' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_FilterAdcZeroV_B;    /* '<S1>/Signal Copy1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_FilterAdcZeroW_B;    /* '<S1>/Signal Copy2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_PhasAdcU_B;          /* '<S1>/Signal Copy9' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_PhasAdcV_B;          /* '<S1>/Signal Copy11' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_PhasAdcW_B;          /* '<S1>/Signal Copy10' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_ZeroAdcU_B;          /* '<S1>/Signal Copy3' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_ZeroAdcV_B;          /* '<S1>/Signal Copy5' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

uint16_T Pmsm_u16_ZeroAdcW_B;          /* '<S1>/Signal Copy4' */

#define PMSM_STOP_SEC_TRUSTED_BSS_16BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 32bits */
/* Definition for custom storage class: TRUSTED_BSS_32BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_PhasSampCurrU_B;     /* '<S1>/Product' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_PhasSampCurrV_B;     /* '<S1>/Product2' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_PhasSampCurrW_B;     /* '<S1>/Product1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 8bits */
/* Definition for custom storage class: TRUSTED_BSS_8BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

boolean_T Pmsm_bl_ZeroIVld_B;          /* '<Root>/Zero_I_Vld' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Definition for custom storage class: TRUSTED_DATA_32BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_PhsCurrUGain_B = 0.122070312F;/* Referenced by: '<S1>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_PhsCurrVGain_B = 0.122070312F;/* Referenced by: '<S1>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_PhsCurrWGain_B = 0.122070312F;/* Referenced by: '<S1>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* Model step function */

/* Code 2 RAM */
#define PMSM_START_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_PhasCurrCalc_MotB_step(void)
{
  /* Outputs for Enabled SubSystem: '<S1>/Subsystem1' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* Inport: '<Root>/Zero_I_Vld' */
  if (Pmsm_bl_ZeroIVld_B) {
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
    if (PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad) {
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[0] =
        Pmsm_u16_AdcSampInZeroU_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[1] =
        Pmsm_u16_AdcSampInZeroV_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[2] =
        Pmsm_u16_AdcSampInZeroW_B;
    }

    rtb_Delay_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[0];
    rtb_Delay_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[1];
    rtb_Delay_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[2];

    /* Delay: '<S3>/Delay1' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_g) {
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[0] =
        Pmsm_u16_AdcSampInZeroU_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[1] =
        Pmsm_u16_AdcSampInZeroV_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[2] =
        Pmsm_u16_AdcSampInZeroW_B;
    }

    rtb_Delay1_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[0];
    rtb_Delay1_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[1];
    rtb_Delay1_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[2];

    /* Delay: '<S3>/Delay2' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_j) {
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[0] =
        Pmsm_u16_AdcSampInZeroU_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[1] =
        Pmsm_u16_AdcSampInZeroV_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[2] =
        Pmsm_u16_AdcSampInZeroW_B;
    }

    rtb_Delay2_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[0];
    rtb_Delay2_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[1];
    rtb_Delay2_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[2];

    /* Delay: '<S3>/Delay3' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_a) {
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[0] =
        Pmsm_u16_AdcSampInZeroU_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[1] =
        Pmsm_u16_AdcSampInZeroV_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[2] =
        Pmsm_u16_AdcSampInZeroW_B;
    }

    rtb_Delay3_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[0];
    rtb_Delay3_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[1];
    rtb_Delay3_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[2];

    /* Delay: '<S3>/Delay4' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_f) {
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[0] =
        Pmsm_u16_AdcSampInZeroU_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[1] =
        Pmsm_u16_AdcSampInZeroV_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[2] =
        Pmsm_u16_AdcSampInZeroW_B;
    }

    rtb_Delay4_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[0];
    rtb_Delay4_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[1];
    rtb_Delay4_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[2];

    /* Delay: '<S3>/Delay5' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_d) {
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[0] =
        Pmsm_u16_AdcSampInZeroU_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[1] =
        Pmsm_u16_AdcSampInZeroV_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[2] =
        Pmsm_u16_AdcSampInZeroW_B;
    }

    rtb_Delay5_idx_0 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[0];
    rtb_Delay5_idx_1 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[1];
    rtb_Delay5_idx_2 = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[2];

    /* Delay: '<S3>/Delay6' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     *  Inport: '<Root>/Zero_V_Adc'
     *  Inport: '<Root>/Zero_W_Adc'
     */
    if (PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_h) {
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay6_DSTATE[0] =
        Pmsm_u16_AdcSampInZeroU_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay6_DSTATE[1] =
        Pmsm_u16_AdcSampInZeroV_B;
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay6_DSTATE[2] =
        Pmsm_u16_AdcSampInZeroW_B;
    }

    /* Update for Delay: '<S3>/Delay' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad = false;

    /* Update for Delay: '<S3>/Delay1' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_g = false;

    /* Update for Delay: '<S3>/Delay2' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_j = false;

    /* Update for Delay: '<S3>/Delay3' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_a = false;

    /* Update for Delay: '<S3>/Delay4' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_f = false;

    /* Update for Delay: '<S3>/Delay5' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_d = false;

    /* Update for Delay: '<S3>/Delay6' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_h = false;

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
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Divide[0] = (uint16_T)
      ((((((((Pmsm_u16_AdcSampInZeroU_B +
              PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[0]) +
             PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[0]) +
            PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[0]) +
           PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[0]) +
          PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[0]) +
         PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[0]) +
        PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay6_DSTATE[0]) >> 3);

    /* Update for Delay: '<S3>/Delay' incorporates:
     *  Inport: '<Root>/Zero_U_Adc'
     */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[0] =
      Pmsm_u16_AdcSampInZeroU_B;

    /* Update for Delay: '<S3>/Delay1' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[0] = rtb_Delay_idx_0;

    /* Update for Delay: '<S3>/Delay2' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[0] = rtb_Delay1_idx_0;

    /* Update for Delay: '<S3>/Delay3' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[0] = rtb_Delay2_idx_0;

    /* Update for Delay: '<S3>/Delay4' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[0] = rtb_Delay3_idx_0;

    /* Update for Delay: '<S3>/Delay5' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[0] = rtb_Delay4_idx_0;

    /* Update for Delay: '<S3>/Delay6' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay6_DSTATE[0] = rtb_Delay5_idx_0;

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
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Divide[1] = (uint16_T)
      ((((((((Pmsm_u16_AdcSampInZeroV_B +
              PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[1]) +
             PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[1]) +
            PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[1]) +
           PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[1]) +
          PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[1]) +
         PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[1]) +
        PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay6_DSTATE[1]) >> 3);

    /* Update for Delay: '<S3>/Delay' incorporates:
     *  Inport: '<Root>/Zero_V_Adc'
     */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[1] =
      Pmsm_u16_AdcSampInZeroV_B;

    /* Update for Delay: '<S3>/Delay1' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[1] = rtb_Delay_idx_1;

    /* Update for Delay: '<S3>/Delay2' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[1] = rtb_Delay1_idx_1;

    /* Update for Delay: '<S3>/Delay3' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[1] = rtb_Delay2_idx_1;

    /* Update for Delay: '<S3>/Delay4' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[1] = rtb_Delay3_idx_1;

    /* Update for Delay: '<S3>/Delay5' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[1] = rtb_Delay4_idx_1;

    /* Update for Delay: '<S3>/Delay6' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay6_DSTATE[1] = rtb_Delay5_idx_1;

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
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Divide[2] = (uint16_T)
      ((((((((Pmsm_u16_AdcSampInZeroW_B +
              PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[2]) +
             PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[2]) +
            PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[2]) +
           PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[2]) +
          PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[2]) +
         PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[2]) +
        PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay6_DSTATE[2]) >> 3);

    /* Update for Delay: '<S3>/Delay' incorporates:
     *  Inport: '<Root>/Zero_W_Adc'
     */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay_DSTATE[2] =
      Pmsm_u16_AdcSampInZeroW_B;

    /* Update for Delay: '<S3>/Delay1' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay1_DSTATE[2] = rtb_Delay_idx_2;

    /* Update for Delay: '<S3>/Delay2' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay2_DSTATE[2] = rtb_Delay1_idx_2;

    /* Update for Delay: '<S3>/Delay3' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay3_DSTATE[2] = rtb_Delay2_idx_2;

    /* Update for Delay: '<S3>/Delay4' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay4_DSTATE[2] = rtb_Delay3_idx_2;

    /* Update for Delay: '<S3>/Delay5' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay5_DSTATE[2] = rtb_Delay4_idx_2;

    /* Update for Delay: '<S3>/Delay6' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.Delay6_DSTATE[2] = rtb_Delay5_idx_2;

    /* SignalConversion generated from: '<S3>/Out2' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.OutportBufferForOut2 =
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Divide[1];

    /* SignalConversion generated from: '<S3>/Out3' */
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.OutportBufferForOut3 =
      PmsmDefault_Pmsm_PhasCurrCalc_MotB.Divide[2];
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem1' */

  /* SignalConversion: '<S1>/Signal Copy' */
  Pmsm_u16_FilterAdcZeroU_B = PmsmDefault_Pmsm_PhasCurrCalc_MotB.Divide[0];

  /* SignalConversion: '<S1>/Signal Copy1' */
  Pmsm_u16_FilterAdcZeroV_B =
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.OutportBufferForOut2;

  /* SignalConversion: '<S1>/Signal Copy2' */
  Pmsm_u16_FilterAdcZeroW_B =
    PmsmDefault_Pmsm_PhasCurrCalc_MotB.OutportBufferForOut3;

  /* Switch: '<S1>/Switch' incorporates:
   *  Inport: '<Root>/Zero_I_Vld'
   *  Inport: '<Root>/Zero_U_Adc'
   *  Inport: '<Root>/Zero_V_Adc'
   *  Inport: '<Root>/Zero_W_Adc'
   */
  if (Pmsm_bl_ZeroIVld_B) {
    Pmsm_u16_ZeroAdcU_B = Pmsm_u16_AdcSampInZeroU_B;
    Pmsm_u16_ZeroAdcV_B = Pmsm_u16_AdcSampInZeroV_B;
    Pmsm_u16_ZeroAdcW_B = Pmsm_u16_AdcSampInZeroW_B;
  } else {
    Pmsm_u16_ZeroAdcU_B = Pmsm_u16_FilterAdcZeroU_B;
    Pmsm_u16_ZeroAdcV_B = Pmsm_u16_FilterAdcZeroV_B;
    Pmsm_u16_ZeroAdcW_B = Pmsm_u16_FilterAdcZeroW_B;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Product: '<S1>/Product' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Inport: '<Root>/Phas_U_Adc'
   *  Sum: '<S1>/Subtract'
   */
  Pmsm_f32_PhasSampCurrU_B = (real32_T)(Pmsm_u16_ZeroAdcU_B -
    Pmsm_u16_AdcSampInPhasU_B) * Pmsm_f32_PhsCurrUGain_B;

  /* Product: '<S1>/Product2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/Phas_V_Adc'
   *  Sum: '<S1>/Subtract2'
   */
  Pmsm_f32_PhasSampCurrV_B = (real32_T)(Pmsm_u16_ZeroAdcV_B -
    Pmsm_u16_AdcSampInPhasV_B) * Pmsm_f32_PhsCurrVGain_B;

  /* Product: '<S1>/Product1' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Inport: '<Root>/Phas_W_Adc'
   *  Sum: '<S1>/Subtract1'
   */
  Pmsm_f32_PhasSampCurrW_B = (real32_T)(Pmsm_u16_ZeroAdcW_B -
    Pmsm_u16_AdcSampInPhasW_B) * Pmsm_f32_PhsCurrWGain_B;

  /* SignalConversion: '<S1>/Signal Copy9' incorporates:
   *  Inport: '<Root>/Phas_U_Adc'
   */
  Pmsm_u16_PhasAdcU_B = Pmsm_u16_AdcSampInPhasU_B;

  /* SignalConversion: '<S1>/Signal Copy11' incorporates:
   *  Inport: '<Root>/Phas_V_Adc'
   */
  Pmsm_u16_PhasAdcV_B = Pmsm_u16_AdcSampInPhasV_B;

  /* SignalConversion: '<S1>/Signal Copy10' incorporates:
   *  Inport: '<Root>/Phas_W_Adc'
   */
  Pmsm_u16_PhasAdcW_B = Pmsm_u16_AdcSampInPhasW_B;
}

#define PMSM_STOP_SEC_PSRAM_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Model initialize function */

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_PhasCurrCalc_MotB_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* custom signals */
  Pmsm_f32_PhasSampCurrU_B = 0.0F;
  Pmsm_f32_PhasSampCurrV_B = 0.0F;
  Pmsm_f32_PhasSampCurrW_B = 0.0F;
  Pmsm_u16_FilterAdcZeroU_B = 0U;
  Pmsm_u16_FilterAdcZeroV_B = 0U;
  Pmsm_u16_FilterAdcZeroW_B = 0U;
  Pmsm_u16_ZeroAdcU_B = 0U;
  Pmsm_u16_ZeroAdcV_B = 0U;
  Pmsm_u16_ZeroAdcW_B = 0U;
  Pmsm_u16_PhasAdcU_B = 0U;
  Pmsm_u16_PhasAdcV_B = 0U;
  Pmsm_u16_PhasAdcW_B = 0U;

  /* Initialize Storage class 'PmsmDefault' */
  (void) memset((void *)&PmsmDefault_Pmsm_PhasCurrCalc_MotB, 0,
                sizeof(Pmsm_PhasCurrCalc_MotB_PmsmDefault));

  /* external inputs */
  Pmsm_u16_AdcSampInZeroU_B = 0U;
  Pmsm_u16_AdcSampInZeroV_B = 0U;
  Pmsm_u16_AdcSampInZeroW_B = 0U;
  Pmsm_u16_AdcSampInPhasU_B = 0U;
  Pmsm_u16_AdcSampInPhasV_B = 0U;
  Pmsm_u16_AdcSampInPhasW_B = 0U;
  Pmsm_bl_ZeroIVld_B = false;

  /* SystemInitialize for Enabled SubSystem: '<S1>/Subsystem1' */
  /* InitializeConditions for Delay: '<S3>/Delay' */
  PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad = true;

  /* InitializeConditions for Delay: '<S3>/Delay1' */
  PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_g = true;

  /* InitializeConditions for Delay: '<S3>/Delay2' */
  PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_j = true;

  /* InitializeConditions for Delay: '<S3>/Delay3' */
  PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_a = true;

  /* InitializeConditions for Delay: '<S3>/Delay4' */
  PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_f = true;

  /* InitializeConditions for Delay: '<S3>/Delay5' */
  PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_d = true;

  /* InitializeConditions for Delay: '<S3>/Delay6' */
  PmsmDefault_Pmsm_PhasCurrCalc_MotB.icLoad_h = true;

  /* End of SystemInitialize for SubSystem: '<S1>/Subsystem1' */
}

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Model terminate function */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_PhasCurrCalc_MotB_terminate(void)
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
