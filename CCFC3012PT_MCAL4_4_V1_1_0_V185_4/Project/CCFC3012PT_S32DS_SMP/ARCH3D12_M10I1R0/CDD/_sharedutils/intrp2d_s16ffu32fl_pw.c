/*
 * File: intrp2d_s16ffu32fl_pw.c
 *
 * Code generated for Simulink model 'MDCC'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Feb 10 10:58:46 2020
 */

#include "rtwtypes.h"
#include "intrp2d_s16ffu32fl_pw.h"

real32_T intrp2d_s16ffu32fl_pw(const uint32_T bpIndex[], const real32_T frac[],
  const int16_T table[], uint32_T stride)
{
  real32_T yL_1d;
  uint32_T offset_1d;

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  offset_1d = bpIndex[1U] * stride + bpIndex[0U];
  yL_1d = ((real32_T)table[offset_1d + 1U] - (real32_T)table[offset_1d]) * frac
    [0U] + (real32_T)table[offset_1d];
  offset_1d += stride;
  return ((((real32_T)table[offset_1d + 1U] - (real32_T)table[offset_1d]) *
           frac[0U] + (real32_T)table[offset_1d]) - yL_1d) * frac[1U] + yL_1d;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
