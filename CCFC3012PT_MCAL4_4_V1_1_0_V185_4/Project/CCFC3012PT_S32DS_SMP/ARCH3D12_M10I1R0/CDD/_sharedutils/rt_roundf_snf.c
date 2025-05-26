/*
 * File: rt_roundf_snf.c
 *
 * Code generated for Simulink model 'Resolver'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Feb 10 12:22:26 2020
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_roundf_snf.h"

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabsf(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floorf(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceilf(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
