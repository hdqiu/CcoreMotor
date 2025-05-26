/*
 * File: plook_u32ff_evenx.c
 *
 * Code generated for Simulink model 'MDCC'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Feb 10 10:58:46 2020
 */

#include "rtwtypes.h"
#include "plook_u32ff_evenx.h"

uint32_T plook_u32ff_evenx(real32_T u, real32_T bp0, real32_T bpSpace, uint32_T
  maxIndex, real32_T *fraction)
{
  uint32_T bpIndex;
  real32_T invSpc;
  real32_T fbpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0U;
    *fraction = (u - bp0) / bpSpace;
  } else {
    invSpc = 1.0F / bpSpace;
    fbpIndex = (u - bp0) * invSpc;
    if (fbpIndex < maxIndex) {
      bpIndex = (uint32_T)fbpIndex;
      *fraction = (u - ((real32_T)bpIndex * bpSpace + bp0)) * invSpc;
    } else {
      bpIndex = maxIndex - 1U;
      *fraction = (u - ((real32_T)(maxIndex - 1U) * bpSpace + bp0)) * invSpc;
    }
  }

  return bpIndex;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
