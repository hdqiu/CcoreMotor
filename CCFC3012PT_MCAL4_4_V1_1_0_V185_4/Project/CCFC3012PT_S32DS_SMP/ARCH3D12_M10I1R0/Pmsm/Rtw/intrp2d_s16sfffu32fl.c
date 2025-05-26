/*
 * File: intrp2d_s16sfffu32fl.c
 *
 * Code generated for Simulink model 'Pmsm_SpdLpFlxWkn'.
 *
 * Model version                  : 1.139
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr 17 21:22:28 2025
 */

#include "intrp2d_s16sfffu32fl.h"
#include "rtwtypes.h"

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

real32_T intrp2d_s16sfffu32fl(const uint32_T bpIndex[], const real32_T frac[],
  const int16_T table[], const uint32_T stride, const real32_T scaleFactor)
{
  real32_T yL_0d0;
  real32_T yL_0d1;
  uint32_T offset_1d;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
   */
  offset_1d = bpIndex[1U] * stride + bpIndex[0U];
  yL_0d0 = (real32_T)table[offset_1d] * scaleFactor;
  yL_0d0 += ((real32_T)table[offset_1d + 1U] * scaleFactor - yL_0d0) * frac[0U];
  offset_1d += stride;
  yL_0d1 = (real32_T)table[offset_1d] * scaleFactor;
  return ((((real32_T)table[offset_1d + 1U] * scaleFactor - yL_0d1) * frac[0U] +
           yL_0d1) - yL_0d0) * frac[1U] + yL_0d0;
}

#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
