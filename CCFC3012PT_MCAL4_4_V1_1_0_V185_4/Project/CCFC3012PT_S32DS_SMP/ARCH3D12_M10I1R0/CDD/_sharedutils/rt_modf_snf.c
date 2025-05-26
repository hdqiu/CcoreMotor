/*
 * File: rt_modf_snf.c
 *
 * Code generated for Simulink model 'Resolver'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Feb 10 12:22:26 2020
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <float.h>
#include <math.h>
#include "rt_roundf_snf.h"
#include "rt_modf_snf.h"

#pragma GCC push_options
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T tmp;
  if (u1 == 0.0F) {
    y = u0;
  } else if (!((!rtIsNaNF(u0)) && (!rtIsInfF(u0)) && ((!rtIsNaNF(u1)) &&
               (!rtIsInfF(u1))))) {
    y = (rtNaNF);
  } else {
    tmp = u0 / u1;
    if (u1 <= (real32_T)floorf(u1)) {
      y = u0 - (real32_T)floorf(tmp) * u1;
    } else if ((real32_T)fabsf(tmp - rt_roundf_snf(tmp)) <= FLT_EPSILON *
               (real32_T)fabsf(tmp)) {
      y = 0.0F;
    } else {
      y = (tmp - (real32_T)floorf(tmp)) * u1;
    }
  }

  return y;
}
#pragma GCC pop_options

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
