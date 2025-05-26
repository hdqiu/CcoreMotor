/*
 * File: plook_u32ff_binx.c
 *
 * Code generated for Simulink model 'Pmsm_SpdLpFlxWkn'.
 *
 * Model version                  : 1.139
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr 17 21:22:28 2025
 */

#include "plook_u32ff_binx.h"
#include "binsearch_u32f.h"
#include "rtwtypes.h"

/* Trusted Text */
#define PMSM_START_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

uint32_T plook_u32ff_binx(real32_T u, const real32_T bp[], uint32_T maxIndex,
  real32_T *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  return bpIndex;
}

#define PMSM_STOP_TRUSTED_SEC_TEXT
#include "Pmsm_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
