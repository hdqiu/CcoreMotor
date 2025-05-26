/*
 * File: Pmsm_SpdLpFlxWkn_MotB.c
 *
 * Code generated for Simulink model 'Pmsm_SpdLpFlxWkn_MotB'.
 *
 * Model version                  : 1.141
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr 17 21:18:51 2025
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
#include "Pmsm_SpdLpFlxWkn_MotB_private.h"
#include "plook_u32ff_binx.h"
#include "intrp1d_s16sfffu32fl.h"
#include "intrp2d_s16sfffu32fl.h"
#include "Pmsm_SpdLpFlxWkn_MotB.h"

/* Storage class 'PmsmDefault' */

/* default varibles */
#define PMSM_START_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

Pmsm_SpdLpFlxWkn_MotB_PmsmDefault PmsmDefault_Pmsm_SpdLpFlxWkn_MotB;/* '<S2>/Merge' */

#define PMSM_STOP_SEC_TRUSTED_BSS_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Exported data definition */

/* pmsm trusted bss 32bits */
/* Definition for custom storage class: TRUSTED_BSS_32BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_DbgTorqCmd_B;        /* '<Root>/Dbg_TorqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_FlxWknIdRefOut_B;    /* '<S1>/Gain' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_FlxWknIqRefOut_B;    /* '<S1>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_FlxWknMotSpd_B;      /* '<Root>/MotSpd' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_FlxWknTorqRef_B;     /* '<S9>/Gain1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_FlxWknVBus_B;        /* '<Root>/VBus' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_FlxWkn_IsRef_B;      /* '<S11>/Sqrt' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_MotSpdFdb_B;         /* '<S4>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_SpdCtrlSpdFdb_B;     /* '<S3>/Add' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_SpdRef_B;            /* '<Root>/SpdRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

real32_T Pmsm_f32_TorqCmd_B;           /* '<Root>/TorqRef' */

#define PMSM_STOP_SEC_TRUSTED_BSS_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted bss 8bits */
/* Definition for custom storage class: TRUSTED_BSS_8BITS_B */
#define PMSM_START_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

boolean_T Pmsm_bl_FlxWknCmdFlg_B;      /* '<S5>/Logical Operator1' */

#define PMSM_STOP_SEC_TRUSTED_BSS_8BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Definition for custom storage class: TRUSTED_DATA_32BITS */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_FlxWkn_LkupTabVoltage_B = 12.0F;/* Referenced by: '<S23>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_FlxWkn_SpdShiftPerVolt_B = 100.0F;/* Referenced by: '<S23>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_invKt_B = 29.4117641F;/* Referenced by: '<S12>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 32bits */
/* Definition for custom storage class: TRUSTED_DATA_32BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_DdgTorqStepper_B = 0.01F;/* Referenced by: '<S7>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_FlxWkb_VbusFiltCoeff_B = 0.2F;/* Referenced by: '<S25>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_SpdLpDeadband_B = 2.0F;/* Referenced by: '<S17>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_SpdLpFdbLpfCoeff_C_B = 1.0F;/* Referenced by: '<S3>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_SpdLpRefMax_B = 5000.0F;/* Referenced by: '<S6>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_SpdLp_Ki_B = 0.001F;/* Referenced by: '<S17>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_SpdLp_Kp_B = 0.01F;/* Referenced by: '<S17>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_SpdLp_OutMax_B = 0.34F;/* Referenced by: '<S17>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_SpdLpfCoeff_C_B = 0.05F;/* Referenced by: '<S4>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

volatile real32_T Pmsm_f32_SpdRefStepper_B = 1.0F;/* Referenced by: '<S18>/Constant2' */

#define PMSM_STOP_SEC_TRUSTED_DATA_32BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted data 8bits */
/* Definition for custom storage class: TRUSTED_DATA_8BITS_B */
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

volatile boolean_T Pmsm_bl_DbgTorqStepEnable_B = true;/* Referenced by: '<S7>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

volatile boolean_T Pmsm_bl_FlxWknEnable_B = true;/* Referenced by:
                                                  * '<S2>/Constant'
                                                  * '<S9>/Constant1'
                                                  */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

volatile boolean_T Pmsm_bl_FlxWkn_VoltShiftEnable_B = false;/* Referenced by: '<S10>/Constant3' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

volatile boolean_T Pmsm_bl_SpdRefStepEnable_B = true;/* Referenced by: '<S18>/Constant1' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"
#define PMSM_START_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

volatile boolean_T Pmsm_bl_TorqLookupEnable_B = true;/* Referenced by: '<S9>/Constant' */

#define PMSM_STOP_SEC_TRUSTED_DATA_8BITS_MOTB
#include "Pmsm_MemMap.h"

/* pmsm trusted const unspecified */
#define PMSM_START_TRUSTED_CONST_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Definition for custom storage class: TRUSTED_CONST_UNSPECIFIED_B */
const real32_T Pmsm_f32_FlxWknAxis_SpeedRef_B[21] = { 0.0F, 200.0F, 400.0F,
  600.0F, 800.0F, 1000.0F, 1200.0F, 1400.0F, 1600.0F, 1800.0F, 2000.0F, 2200.0F,
  2400.0F, 2600.0F, 2800.0F, 3000.0F, 3200.0F, 3400.0F, 3600.0F, 3800.0F,
  4000.0F } ;                          /* Referenced by:
                                        * '<S9>/Prelookup_speed'
                                        * '<S11>/Prelookup_speed'
                                        */

const real32_T Pmsm_f32_FlxWknAxis_TorqRef_B[20] = { 0.0F, 0.0178947374F,
  0.0357894748F, 0.0536842123F, 0.0715789497F, 0.0894736871F, 0.107368425F,
  0.125263155F, 0.143157899F, 0.161052629F, 0.178947374F, 0.196842104F,
  0.214736849F, 0.232631579F, 0.250526309F, 0.268421054F, 0.286315799F,
  0.304210514F, 0.322105259F, 0.34F } ;
                                   /* Referenced by: '<S11>/Prelookup_torque' */

const int16_T Pmsm_s16p10_FlxWknTab_TeMax_B[21] = { 348, 348, 348, 348, 348, 348,
  348, 348, 348, 312, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147 } ;
                       /* Referenced by: '<S9>/Interpolation Using Prelookup' */

const int16_T Pmsm_s16p7_FlxWknTab_IdRef_B[420] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  -858, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, -883, -1126, -1126, -1126, -1126, -1126, -1126,
  -1126, -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -909, -1126, -1126,
  -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, -947, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126,
  -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -986, -1126, -1126, -1126, -1126, -1126,
  -1126, -1126, -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, -26, -1011,
  -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, 0, 0, 0,
  0, 0, 0, 0, 0, 0, -64, -1050, -1126, -1126, -1126, -1126, -1126, -1126, -1126,
  -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, -90, -1088, -1126, -1126,
  -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0,
  0, -128, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126,
  -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, -166, -1126, -1126, -1126, -1126, -1126,
  -1126, -1126, -1126, -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, -205,
  -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, 0,
  0, 0, 0, 0, 0, 0, 0, 0, -243, -1126, -1126, -1126, -1126, -1126, -1126, -1126,
  -1126, -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, -282, -1126, -1126,
  -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, 0, 0, 0, 0, 0,
  0, 0, 0, 0, -320, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126,
  -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, -358, -1126, -1126, -1126,
  -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0,
  0, -397, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126,
  -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, -435, -1126, -1126, -1126, -1126, -1126,
  -1126, -1126, -1126, -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, -486,
  -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, 0,
  0, 0, 0, 0, 0, 0, 0, 0, -486, -1126, -1126, -1126, -1126, -1126, -1126, -1126,
  -1126, -1126, -1126, -1126, 0, 0, 0, 0, 0, 0, 0, 0, 0, -486, -1126, -1126,
  -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126, -1126 } ;
                      /* Referenced by: '<S11>/Interpolation Using Prelookup' */

const int16_T Pmsm_s16p7_FlxWknTab_IqRef_B[420] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67,
  67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 135, 135, 135, 135, 135, 135, 135, 135,
  135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 202, 202, 202,
  202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202,
  202, 202, 269, 269, 269, 269, 269, 269, 269, 269, 269, 269, 269, 269, 269, 269,
  269, 269, 269, 269, 269, 269, 269, 337, 337, 337, 337, 337, 337, 337, 337, 337,
  337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 337, 404, 404, 404, 404,
  404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404, 404,
  404, 472, 472, 472, 472, 472, 472, 472, 472, 472, 472, 472, 472, 472, 472, 472,
  472, 472, 472, 472, 472, 472, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539,
  539, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539, 606, 606, 606, 606, 606,
  606, 606, 606, 606, 606, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539,
  674, 674, 674, 674, 674, 674, 674, 674, 674, 674, 539, 539, 539, 539, 539, 539,
  539, 539, 539, 539, 539, 741, 741, 741, 741, 741, 741, 741, 741, 741, 741, 539,
  539, 539, 539, 539, 539, 539, 539, 539, 539, 539, 808, 808, 808, 808, 808, 808,
  808, 808, 808, 808, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539, 876,
  876, 876, 876, 876, 876, 876, 876, 876, 876, 539, 539, 539, 539, 539, 539, 539,
  539, 539, 539, 539, 943, 943, 943, 943, 943, 943, 943, 943, 943, 943, 539, 539,
  539, 539, 539, 539, 539, 539, 539, 539, 539, 1011, 1011, 1011, 1011, 1011,
  1011, 1011, 1011, 1011, 1011, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539,
  539, 1078, 1078, 1078, 1078, 1078, 1078, 1078, 1078, 1078, 1078, 539, 539, 539,
  539, 539, 539, 539, 539, 539, 539, 539, 1145, 1145, 1145, 1145, 1145, 1145,
  1145, 1145, 1145, 1145, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539,
  1213, 1213, 1213, 1213, 1213, 1213, 1213, 1213, 1213, 1145, 539, 539, 539, 539,
  539, 539, 539, 539, 539, 539, 539, 1280, 1280, 1280, 1280, 1280, 1280, 1280,
  1280, 1280, 1145, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539, 539 } ;
                     /* Referenced by: '<S11>/Interpolation Using Prelookup1' */

#define PMSM_STOP_TRUSTED_CONST_UNSPECIFIED_MOTB
#include "Pmsm_MemMap.h"

/* Model step function */

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_SpdLpFlxWkn_MotB_step(void)
{
  real32_T frac[2];
  real32_T frac_0[2];
  real32_T rtb_Abs;
  real32_T rtb_Abs1;
  real32_T rtb_Switch2_j;
  real32_T rtb_Switch5;
  uint32_T bpIndex[2];
  uint32_T bpIndex_0[2];
  boolean_T rtb_Compare_b;
  boolean_T rtb_Compare_i;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S5>/Constant5'
   */
  rtb_Compare_i = (Pmsm_u8_MotCmdSel_B == 0);

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S5>/Constant5'
   */
  rtb_Compare_b = (Pmsm_u8_MotCmdSel_B == 5);

  /* Logic: '<S5>/Logical Operator1' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S5>/Constant5'
   *  RelationalOperator: '<S15>/Compare'
   */
  Pmsm_bl_FlxWknCmdFlg_B = (rtb_Compare_i || (Pmsm_u8_MotCmdSel_B == 1) ||
    rtb_Compare_b);

  /* Abs: '<S10>/Abs' incorporates:
   *  Inport: '<Root>/MotSpd'
   */
  rtb_Abs = fabsf(Pmsm_f32_FlxWknMotSpd_B);

  /* Outputs for Enabled SubSystem: '<S10>/Volt_Shift_Func' incorporates:
   *  EnablePort: '<S23>/Enable'
   */
  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  if (Pmsm_bl_FlxWkn_VoltShiftEnable_B) {
    if (!PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Volt_Shift_Func_MODE) {
      /* InitializeConditions for Delay: '<S25>/Delay1' */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.icLoad = true;
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Volt_Shift_Func_MODE = true;
    }

    /* Delay: '<S25>/Delay1' */
    if (PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.icLoad) {
      /* Sum: '<S25>/Add' incorporates:
       *  Constant: '<S25>/Constant2'
       */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_g = 14.0F;
    }

    /* Sum: '<S25>/Add' incorporates:
     *  Constant: '<S25>/Constant'
     *  Constant: '<S25>/Constant1'
     *  Delay: '<S25>/Delay1'
     *  Inport: '<Root>/VBus'
     *  Product: '<S25>/Product'
     *  Product: '<S25>/Product1'
     *  Sum: '<S25>/Subtract1'
     */
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_g = (1.0F -
      Pmsm_f32_FlxWkb_VbusFiltCoeff_B) *
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_g + Pmsm_f32_FlxWknVBus_B *
      Pmsm_f32_FlxWkb_VbusFiltCoeff_B;

    /* Sum: '<S23>/Subtract1' incorporates:
     *  Constant: '<S23>/Constant'
     *  Constant: '<S23>/Constant1'
     *  Product: '<S23>/Product'
     *  Sum: '<S23>/Subtract'
     */
    rtb_Abs1 = rtb_Abs - (PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_g -
                          Pmsm_f32_FlxWkn_LkupTabVoltage_B) *
      Pmsm_f32_FlxWkn_SpdShiftPerVolt_B;

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S24>/Constant'
     *  RelationalOperator: '<S24>/Compare'
     */
    if (rtb_Abs1 >= 0.0F) {
      /* Switch: '<S23>/Switch' */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Switch = rtb_Abs1;
    } else {
      /* Switch: '<S23>/Switch' incorporates:
       *  Constant: '<S23>/Constant2'
       */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Switch = 0.0F;
    }

    /* End of Switch: '<S23>/Switch' */

    /* Update for Delay: '<S25>/Delay1' */
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.icLoad = false;
    rtb_Abs = PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Switch;
  } else {
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Volt_Shift_Func_MODE = false;
  }

  /* End of Switch: '<S10>/Switch1' */
  /* End of Outputs for SubSystem: '<S10>/Volt_Shift_Func' */

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Inport: '<Root>/MotSpd'
   *  Product: '<S3>/Product'
   *  Product: '<S3>/Product1'
   *  Sum: '<S3>/Subtract1'
   */
  Pmsm_f32_SpdCtrlSpdFdb_B = (1.0F - Pmsm_f32_SpdLpFdbLpfCoeff_C_B) *
    Pmsm_f32_SpdCtrlSpdFdb_B + Pmsm_f32_FlxWknMotSpd_B *
    Pmsm_f32_SpdLpFdbLpfCoeff_C_B;

  /* Outputs for Enabled SubSystem: '<S1>/SpeedLoop' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtb_Compare_b) {
    if (!PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.SpeedLoop_MODE) {
      /* InitializeConditions for Delay: '<S18>/Delay' */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE_g = 0.0F;

      /* InitializeConditions for Delay: '<S17>/Delay' */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.icLoad_f = true;

      /* InitializeConditions for Sum: '<S17>/Add' incorporates:
       *  Delay: '<S17>/Delay1'
       */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_e = 0.0F;
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.SpeedLoop_MODE = true;
    }

    /* Switch: '<S16>/Switch2' incorporates:
     *  Constant: '<S6>/Constant2'
     *  Gain: '<S6>/Gain'
     *  Inport: '<Root>/SpdRef'
     *  RelationalOperator: '<S16>/LowerRelop1'
     *  RelationalOperator: '<S16>/UpperRelop'
     *  Switch: '<S16>/Switch'
     */
    if (Pmsm_f32_SpdRef_B > Pmsm_f32_SpdLpRefMax_B) {
      rtb_Switch2_j = Pmsm_f32_SpdLpRefMax_B;
    } else if (Pmsm_f32_SpdRef_B < -Pmsm_f32_SpdLpRefMax_B) {
      /* Switch: '<S16>/Switch' incorporates:
       *  Gain: '<S6>/Gain'
       */
      rtb_Switch2_j = -Pmsm_f32_SpdLpRefMax_B;
    } else {
      rtb_Switch2_j = Pmsm_f32_SpdRef_B;
    }

    /* End of Switch: '<S16>/Switch2' */

    /* Sum: '<S18>/Sum' incorporates:
     *  Delay: '<S18>/Delay'
     */
    rtb_Abs1 = rtb_Switch2_j - PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE_g;

    /* Switch: '<S18>/Switch1' incorporates:
     *  Constant: '<S18>/Constant2'
     *  Delay: '<S18>/Delay'
     *  Gain: '<S18>/Gain'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  RelationalOperator: '<S18>/Relational Operator1'
     *  Sum: '<S18>/Add1'
     *  Switch: '<S18>/Switch'
     */
    if (rtb_Abs1 > Pmsm_f32_SpdRefStepper_B) {
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE_g +=
        Pmsm_f32_SpdRefStepper_B;
    } else if (rtb_Abs1 < -Pmsm_f32_SpdRefStepper_B) {
      /* Switch: '<S18>/Switch' incorporates:
       *  Delay: '<S18>/Delay'
       *  Gain: '<S18>/Gain'
       *  Sum: '<S18>/Add2'
       */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE_g +=
        -Pmsm_f32_SpdRefStepper_B;
    } else {
      /* Delay: '<S18>/Delay' incorporates:
       *  Switch: '<S18>/Switch'
       */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE_g = rtb_Switch2_j;
    }

    /* End of Switch: '<S18>/Switch1' */

    /* Switch: '<S18>/Switch2' incorporates:
     *  Constant: '<S18>/Constant1'
     *  Delay: '<S18>/Delay'
     *  RelationalOperator: '<S21>/Compare'
     */
    if (Pmsm_bl_SpdRefStepEnable_B) {
      rtb_Switch2_j = PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE_g;
    }

    /* End of Switch: '<S18>/Switch2' */

    /* Sum: '<S17>/Sum' */
    rtb_Switch2_j -= Pmsm_f32_SpdCtrlSpdFdb_B;

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S17>/Constant3'
     *  RelationalOperator: '<S19>/Relational Operator'
     *  RelationalOperator: '<S19>/Relational Operator1'
     *  Sum: '<S19>/Subtract'
     *  Switch: '<S19>/Switch1'
     *  UnaryMinus: '<S19>/Unary Minus'
     */
    if (rtb_Switch2_j > Pmsm_f32_SpdLpDeadband_B) {
      rtb_Switch2_j -= Pmsm_f32_SpdLpDeadband_B;
    } else if (rtb_Switch2_j < -Pmsm_f32_SpdLpDeadband_B) {
      /* Switch: '<S19>/Switch1' incorporates:
       *  Sum: '<S19>/Add'
       */
      rtb_Switch2_j += Pmsm_f32_SpdLpDeadband_B;
    } else {
      /* Switch: '<S19>/Switch1' incorporates:
       *  Constant: '<S19>/Constant1'
       */
      rtb_Switch2_j = 0.0F;
    }

    /* End of Switch: '<S19>/Switch' */

    /* Delay: '<S17>/Delay' */
    if (PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.icLoad_f) {
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE_p = rtb_Switch2_j;
    }

    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant1'
     *  Delay: '<S17>/Delay'
     *  Delay: '<S17>/Delay1'
     *  Product: '<S17>/Product'
     *  Product: '<S17>/Product1'
     *  Sum: '<S17>/Subtract'
     */
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_e += (rtb_Switch2_j -
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE_p) * Pmsm_f32_SpdLp_Kp_B +
      rtb_Switch2_j * Pmsm_f32_SpdLp_Ki_B;

    /* Switch: '<S20>/Switch2' incorporates:
     *  Constant: '<S17>/Constant2'
     *  Gain: '<S17>/Gain'
     *  RelationalOperator: '<S20>/LowerRelop1'
     *  RelationalOperator: '<S20>/UpperRelop'
     *  Switch: '<S20>/Switch'
     */
    if (PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_e >
        Pmsm_f32_SpdLp_OutMax_B) {
      /* Sum: '<S17>/Add' */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_e =
        Pmsm_f32_SpdLp_OutMax_B;
    } else if (PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_e <
               -Pmsm_f32_SpdLp_OutMax_B) {
      /* Sum: '<S17>/Add' incorporates:
       *  Gain: '<S17>/Gain'
       *  Switch: '<S20>/Switch'
       */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_e =
        -Pmsm_f32_SpdLp_OutMax_B;
    }

    /* End of Switch: '<S20>/Switch2' */

    /* Update for Delay: '<S17>/Delay' */
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.icLoad_f = false;
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE_p = rtb_Switch2_j;
  } else {
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.SpeedLoop_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S1>/SpeedLoop' */

  /* Sum: '<S7>/Sum' incorporates:
   *  Delay: '<S7>/Delay'
   *  Inport: '<Root>/Dbg_TorqRef'
   */
  rtb_Switch2_j = Pmsm_f32_DbgTorqCmd_B -
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE;

  /* Switch: '<S7>/Switch1' incorporates:
   *  Constant: '<S7>/Constant2'
   *  Delay: '<S7>/Delay'
   *  Gain: '<S7>/Gain'
   *  RelationalOperator: '<S7>/Relational Operator'
   *  RelationalOperator: '<S7>/Relational Operator1'
   *  Sum: '<S7>/Add1'
   *  Switch: '<S7>/Switch'
   */
  if (rtb_Switch2_j > Pmsm_f32_DdgTorqStepper_B) {
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE += Pmsm_f32_DdgTorqStepper_B;
  } else if (rtb_Switch2_j < -Pmsm_f32_DdgTorqStepper_B) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Delay: '<S7>/Delay'
     *  Gain: '<S7>/Gain'
     *  Sum: '<S7>/Add2'
     */
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE += -Pmsm_f32_DdgTorqStepper_B;
  } else {
    /* Delay: '<S7>/Delay' incorporates:
     *  Inport: '<Root>/Dbg_TorqRef'
     *  Switch: '<S7>/Switch'
     */
    PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE = Pmsm_f32_DbgTorqCmd_B;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* Switch: '<S8>/Switch5' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Inport: '<Root>/Dbg_TorqRef'
   *  Logic: '<S8>/Logical Operator1'
   *  RelationalOperator: '<S22>/Compare'
   *  Switch: '<S7>/Switch2'
   */
  if (rtb_Compare_b || rtb_Compare_i) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Delay: '<S17>/Delay1'
     *  Inport: '<Root>/TorqRef'
     */
    if (rtb_Compare_b) {
      rtb_Switch5 = PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_e;
    } else {
      rtb_Switch5 = Pmsm_f32_TorqCmd_B;
    }

    /* End of Switch: '<S8>/Switch1' */
  } else if (Pmsm_bl_DbgTorqStepEnable_B) {
    /* Switch: '<S7>/Switch2' incorporates:
     *  Delay: '<S7>/Delay'
     */
    rtb_Switch5 = PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE;
  } else {
    rtb_Switch5 = Pmsm_f32_DbgTorqCmd_B;
  }

  /* End of Switch: '<S8>/Switch5' */

  /* Outputs for Enabled SubSystem: '<S1>/TorqLookup' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (Pmsm_bl_FlxWknCmdFlg_B) {
    uint32_T rtb_Prelookup_speed_o1;

    /* Abs: '<S9>/Abs1' */
    rtb_Abs1 = fabsf(rtb_Switch5);

    /* PreLookup: '<S9>/Prelookup_speed' */
    rtb_Prelookup_speed_o1 = plook_u32ff_binx(rtb_Abs,
      &Pmsm_f32_FlxWknAxis_SpeedRef_B[0], 20U, &rtb_Switch2_j);

    /* Interpolation_n-D: '<S9>/Interpolation Using Prelookup' */
    if (rtb_Switch2_j < 0.0F) {
      rtb_Switch2_j = 0.0F;
    } else if (rtb_Switch2_j > 1.0F) {
      rtb_Switch2_j = 1.0F;
    }

    rtb_Switch2_j = intrp1d_s16sfffu32fl(rtb_Prelookup_speed_o1, rtb_Switch2_j,
      &Pmsm_s16p10_FlxWknTab_TeMax_B[0], 0.0009765625F);

    /* End of Interpolation_n-D: '<S9>/Interpolation Using Prelookup' */

    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant1'
     *  Logic: '<S9>/Logical Operator'
     */
    if (Pmsm_bl_TorqLookupEnable_B && Pmsm_bl_FlxWknEnable_B) {
      /* Switch: '<S9>/Switch' incorporates:
       *  Gain: '<S9>/Gain'
       *  RelationalOperator: '<S9>/Relational Operator'
       *  Switch: '<S9>/Switch2'
       */
      if (rtb_Switch5 > 0.0F) {
        /* Switch: '<S9>/Switch2' incorporates:
         *  RelationalOperator: '<S9>/Relational Operator'
         */
        if (rtb_Abs1 < rtb_Switch2_j) {
          rtb_Switch2_j = rtb_Abs1;
        }
      } else if (rtb_Abs1 < rtb_Switch2_j) {
        /* Switch: '<S9>/Switch2' incorporates:
         *  Gain: '<S9>/Gain'
         */
        rtb_Switch2_j = -rtb_Abs1;
      } else {
        rtb_Switch2_j = -rtb_Switch2_j;
      }

      /* End of Switch: '<S9>/Switch' */
    } else {
      rtb_Switch2_j = rtb_Switch5;
    }

    /* End of Switch: '<S9>/Switch1' */

    /* Gain: '<S9>/Gain1' */
    Pmsm_f32_FlxWknTorqRef_B = rtb_Switch2_j;

    /* Outputs for Enabled SubSystem: '<S1>/FlxWknLookup' incorporates:
     *  EnablePort: '<S2>/Enable'
     */
    /* If: '<S2>/If' incorporates:
     *  Constant: '<S2>/Constant'
     */
    if (Pmsm_bl_FlxWknEnable_B) {
      uint32_T rtb_Prelookup_speed_o1_a;

      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* Abs: '<S11>/Abs1' */
      rtb_Abs1 = fabsf(Pmsm_f32_FlxWknTorqRef_B);

      /* PreLookup: '<S11>/Prelookup_torque' */
      rtb_Prelookup_speed_o1 = plook_u32ff_binx(rtb_Abs1,
        &Pmsm_f32_FlxWknAxis_TorqRef_B[0], 19U, &rtb_Abs1);

      /* PreLookup: '<S11>/Prelookup_speed' */
      rtb_Prelookup_speed_o1_a = plook_u32ff_binx(rtb_Abs,
        &Pmsm_f32_FlxWknAxis_SpeedRef_B[0], 20U, &rtb_Switch2_j);

      /* Interpolation_n-D: '<S11>/Interpolation Using Prelookup' */
      frac[0] = rtb_Switch2_j;
      if (rtb_Switch2_j < 0.0F) {
        frac[0] = 0.0F;
      } else if (rtb_Switch2_j > 1.0F) {
        frac[0] = 1.0F;
      }

      frac[1] = rtb_Abs1;
      if (rtb_Abs1 < 0.0F) {
        frac[1] = 0.0F;
      } else if (rtb_Abs1 > 1.0F) {
        frac[1] = 1.0F;
      }

      bpIndex[0] = rtb_Prelookup_speed_o1_a;
      bpIndex[1] = rtb_Prelookup_speed_o1;
      rtb_Abs = intrp2d_s16sfffu32fl(bpIndex, frac,
        &Pmsm_s16p7_FlxWknTab_IdRef_B[0], 21U, 0.0078125F);

      /* End of Interpolation_n-D: '<S11>/Interpolation Using Prelookup' */

      /* Interpolation_n-D: '<S11>/Interpolation Using Prelookup1' */
      frac_0[0] = rtb_Switch2_j;
      if (rtb_Switch2_j < 0.0F) {
        frac_0[0] = 0.0F;
      } else if (rtb_Switch2_j > 1.0F) {
        frac_0[0] = 1.0F;
      }

      frac_0[1] = rtb_Abs1;
      if (rtb_Abs1 < 0.0F) {
        frac_0[1] = 0.0F;
      } else if (rtb_Abs1 > 1.0F) {
        frac_0[1] = 1.0F;
      }

      bpIndex_0[0] = rtb_Prelookup_speed_o1_a;
      bpIndex_0[1] = rtb_Prelookup_speed_o1;

      /* Switch: '<S11>/Switch' incorporates:
       *  Gain: '<S11>/Gain'
       *  Interpolation_n-D: '<S11>/Interpolation Using Prelookup1'
       */
      if (Pmsm_f32_FlxWknTorqRef_B > 0.0F) {
        rtb_Switch2_j = intrp2d_s16sfffu32fl(bpIndex_0, frac_0,
          &Pmsm_s16p7_FlxWknTab_IqRef_B[0], 21U, 0.0078125F);
      } else {
        rtb_Switch2_j = -intrp2d_s16sfffu32fl(bpIndex_0, frac_0,
          &Pmsm_s16p7_FlxWknTab_IqRef_B[0], 21U, 0.0078125F);
      }

      /* End of Switch: '<S11>/Switch' */

      /* Sqrt: '<S11>/Sqrt' incorporates:
       *  Product: '<S11>/Product'
       *  Product: '<S11>/Product1'
       *  Sum: '<S11>/Add'
       */
      Pmsm_f32_FlxWkn_IsRef_B = sqrtf(rtb_Abs * rtb_Abs + rtb_Switch2_j *
        rtb_Switch2_j);

      /* Merge: '<S2>/Merge' incorporates:
       *  SignalConversion generated from: '<S11>/FlxWkn_IdIqRef'
       */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Merge[0] = rtb_Abs;
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Merge[1] = rtb_Switch2_j;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      /* Merge: '<S2>/Merge' incorporates:
       *  Constant: '<S12>/Constant'
       *  Constant: '<S12>/Constant1'
       *  Product: '<S12>/Product'
       *  SignalConversion generated from: '<S12>/FlxWkn_IdIqRef'
       */
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Merge[0] = 0.0F;
      PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Merge[1] = Pmsm_f32_FlxWknTorqRef_B *
        Pmsm_f32_invKt_B;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
    }

    /* End of If: '<S2>/If' */
    /* End of Outputs for SubSystem: '<S1>/FlxWknLookup' */
  }

  /* End of Outputs for SubSystem: '<S1>/TorqLookup' */

  /* Gain: '<S1>/Gain' */
  Pmsm_f32_FlxWknIdRefOut_B = PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Merge[0];

  /* Gain: '<S1>/Gain1' */
  Pmsm_f32_FlxWknIqRefOut_B = PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Merge[1];

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/MotSpd'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Sum: '<S4>/Subtract1'
   */
  Pmsm_f32_MotSpdFdb_B = (1.0F - Pmsm_f32_SpdLpfCoeff_C_B) *
    Pmsm_f32_MotSpdFdb_B + Pmsm_f32_FlxWknMotSpd_B * Pmsm_f32_SpdLpfCoeff_C_B;
}

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Model initialize function */

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_SpdLpFlxWkn_MotB_initialize(void)
{
  /* Registration code */

  /* block I/O */

  /* custom signals */
  Pmsm_f32_SpdCtrlSpdFdb_B = 0.0F;
  Pmsm_f32_FlxWknIdRefOut_B = 0.0F;
  Pmsm_f32_FlxWknIqRefOut_B = 0.0F;
  Pmsm_f32_MotSpdFdb_B = 0.0F;
  Pmsm_f32_FlxWknTorqRef_B = 0.0F;
  Pmsm_f32_FlxWkn_IsRef_B = 0.0F;
  Pmsm_bl_FlxWknCmdFlg_B = false;

  /* Initialize Storage class 'PmsmDefault' */
  (void) memset((void *)&PmsmDefault_Pmsm_SpdLpFlxWkn_MotB, 0,
                sizeof(Pmsm_SpdLpFlxWkn_MotB_PmsmDefault));

  /* external inputs */
  Pmsm_f32_SpdRef_B = 0.0F;
  Pmsm_f32_TorqCmd_B = 0.0F;
  Pmsm_f32_DbgTorqCmd_B = 0.0F;
  Pmsm_f32_FlxWknMotSpd_B = 0.0F;
  Pmsm_f32_FlxWknVBus_B = 0.0F;

  /* SystemInitialize for Enabled SubSystem: '<S10>/Volt_Shift_Func' */
  /* InitializeConditions for Delay: '<S25>/Delay1' */
  PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.icLoad = true;

  /* End of SystemInitialize for SubSystem: '<S10>/Volt_Shift_Func' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/SpeedLoop' */
  /* InitializeConditions for Delay: '<S18>/Delay' */
  PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay_DSTATE_g = 0.0F;

  /* InitializeConditions for Delay: '<S17>/Delay' */
  PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.icLoad_f = true;

  /* InitializeConditions for Sum: '<S17>/Add' incorporates:
   *  Delay: '<S17>/Delay1'
   */
  PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Delay1_DSTATE_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S1>/SpeedLoop' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/FlxWknLookup' */
  /* SystemInitialize for Merge: '<S2>/Merge' */
  PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Merge[0] = 0.0F;
  PmsmDefault_Pmsm_SpdLpFlxWkn_MotB.Merge[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S1>/FlxWknLookup' */
}

#define PMSM_STOP_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

/* Model terminate function */
/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT_MOTB
#include "Pmsm_MemMap.h"

void Pmsm_SpdLpFlxWkn_MotB_terminate(void)
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
