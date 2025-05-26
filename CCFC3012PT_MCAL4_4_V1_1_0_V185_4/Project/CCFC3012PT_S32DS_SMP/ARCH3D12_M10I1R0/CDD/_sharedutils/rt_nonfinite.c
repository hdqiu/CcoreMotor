/*
 * File: rt_nonfinite.c
 *
 * Code generated for Simulink model 'MDTM'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Feb 10 12:16:51 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/*
 * Abstract:
 *      Function to initialize non-finites,
 *      (Inf, NaN and -Inf).
 */
#include "derivative.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#include "Platform_Types.h"

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

extern volatile uint8 ioTestFlag;
/* Test if value is infinite */
#pragma GCC push_options
#pragma GCC diagnostic ignored "-Wfloat-equal"
boolean_T rtIsInf(real_T value)
{
	boolean_T result;
//  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
	result = (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
	return result;
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
	boolean_T result;
//  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
	result = (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
	return result;
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
	boolean_T result;
//  return (boolean_T)((value!=value) ? 1U : 0U);
	result = (boolean_T)((value!=value) ? 1U : 0U);
	return result;
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
	boolean_T result;
//  return (boolean_T)(((value!=value) ? 1U : 0U));
	result = (boolean_T)(((value!=value) ? 1U : 0U));
	return result;
}
#pragma GCC pop_options

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
