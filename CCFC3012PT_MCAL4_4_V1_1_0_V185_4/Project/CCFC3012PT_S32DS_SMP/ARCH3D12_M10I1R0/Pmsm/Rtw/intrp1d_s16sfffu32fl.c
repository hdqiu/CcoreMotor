/*
 * File: intrp1d_s16sfffu32fl.c
 *
 * Code generated for Simulink model 'Pmsm_SpdLpFlxWkn'.
 *
 * Model version                  : 1.139
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr 17 21:22:28 2025
 */

#include "intrp1d_s16sfffu32fl.h"
#include "rtwtypes.h"

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

real32_T intrp1d_s16sfffu32fl(uint32_T bpIndex, real32_T frac, const int16_T
  table[], const real32_T scaleFactor)
{
  real32_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  yL_0d0 = (real32_T)table[bpIndex] * scaleFactor;
  return ((real32_T)table[bpIndex + 1U] * scaleFactor - yL_0d0) * frac + yL_0d0;
}

#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
