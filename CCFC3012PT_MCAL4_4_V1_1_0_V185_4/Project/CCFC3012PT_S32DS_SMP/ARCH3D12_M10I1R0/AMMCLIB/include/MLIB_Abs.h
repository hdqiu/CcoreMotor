/******************************************************************************
*
*   Copyright 2013-2015 Freescale Semiconductor
*   Copyright 2016-2024 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms.  By expressly accepting such
*   terms or by downloading, installing, activating and/or otherwise using the software, you are
*   agreeing that you have read, and that you agree to comply with and are bound by, such license
*   terms. If you do not agree to be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
******************************************************************************/
/**
*
* @file       MLIB_Abs.h
* 
* @brief      Header file for MLIB_Abs function
*
******************************************************************************/
#ifndef MLIB_ABS_H
#define MLIB_ABS_H
/**
@if MLIB_GROUP
    @addtogroup MLIB_GROUP
@else
    @defgroup MLIB_GROUP   MLIB
@endif
*/

#ifdef __cplusplus
extern "C" {
#endif


#include "SWLIBS_Defines.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_Abs(...)     macro_dispatcher(MLIB_Abs, __VA_ARGS__)(__VA_ARGS__)     /* This function returns absolute value of input parameter. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00006 */  
    #define MLIB_Abs_Dsptchr_1(In)     MLIB_Abs_Dsptchr_2(In,F32)     /* Function dispatcher for MLIB_Abs_Dsptchr_1, do not modify!!! */
  #endif 
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00006 */
    #define MLIB_Abs_Dsptchr_1(In)     MLIB_Abs_Dsptchr_2(In,F16)     /* Function dispatcher for MLIB_Abs_Dsptchr_1, do not modify!!! */
  #endif 
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DMLIB00006 */
    #define MLIB_Abs_Dsptchr_1(In)     MLIB_Abs_Dsptchr_2(In,FLT)     /* Function dispatcher for MLIB_Abs_Dsptchr_1, do not modify!!! */
  #endif 
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */

  #define MLIB_Abs_Dsptchr_2(In,Impl)    MLIB_Abs_Dsptchr_(In,Impl)     /* Function dispatcher for MLIB_Abs_Dsptchr_2, do not modify!!! */
  
  /* @remarks Implements DMLIB00008 */
  #define MLIB_Abs_Dsptchr_(In,Impl)     MLIB_Abs_##Impl(In)            /* Function dispatcher for MLIB_Abs_Dsptchr_, do not modify!!! */
#endif
 
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* Inline functions
****************************************************************************/
/* MLIB_Abs_F32 implementation variant - C */
/* C implementation */
SWLIBS_INLINE tFrac32 Abs_F32_C(register tFrac32 f32In)
{
  return((f32In < (tFrac32)0) ? (-f32In) : (f32In));
}
#ifdef MLIB_LSP
  #if (!(defined(__GNUC__) && defined(__PPC_EABI__)))
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
    /* Target-specific implementation */
    SWLIBS_INLINE tFrac32 Abs_F32_ITR_LSP(register tFrac32 f32In)
    {
      return((tFrac32)__zabsw((__lsp32_32__)f32In));
    }
  #endif /* (!(defined(__GNUC__) && defined(__PPC_EABI__))) */
  #if defined(__GNUC__) && defined(__PPC_EABI__)
    /* MLIB_Abs_F32 implementation variant - LSP assembly for S32DS for Power Architecture toolchain */
    SWLIBS_INLINE tFrac32 Abs_F32_S32DSPPC_LSP(register tFrac32 f32In)
    {
      register tFrac32 f32Return;
      SWLIBS_ASM(" zabsw %0,%1": "=r"(f32Return): "r"(f32In));
      return((tFrac32)f32Return);
    }
  #endif
#endif
/* MLIB_Abs_F16 implementation variant - C */
/* C implementation */
SWLIBS_INLINE tFrac16 Abs_F16_C(register tFrac16 f16In)
{
  return((f16In < (tFrac16)0) ? (-f16In) : (f16In));
}
#ifdef MLIB_LSP
  #if (!(defined(__GNUC__) && defined(__PPC_EABI__)))
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
    /* Target-specific implementation */
    SWLIBS_INLINE tFrac16 Abs_F16_ITR_LSP(register tFrac16 f16In)
    {
      /* Compiler_Warning: This is side effect of non static inline usage. */
      return((tFrac16)__lsp_extract_lower_hword(__zvabsh((__lsp32_16__)f16In)));
    }
  #endif /* (!(defined(__GNUC__) && defined(__PPC_EABI__))) */
  #if defined(__GNUC__) && defined(__PPC_EABI__)
    /* MLIB_Abs_F16 implementation variant - LSP assembly for S32DS for Power Architecture toolchain */
    SWLIBS_INLINE tFrac16 Abs_F16_S32DSPPC_LSP(register tFrac16 f16In)
    {
      register tFrac16 f16Return;
      SWLIBS_ASM(" zvabsh %0,%1": "=r"(f16Return): "r"(f16In));
      SWLIBS_ASM(" extsh %0,%1": "=r"(f16Return): "r"(f16Return));
      return((tFrac16)f16Return);
    }
  #endif
#endif
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/* MLIB_Abs_FLT implementation variant - C */
/* C implementation */
SWLIBS_INLINE tFloat Abs_FLT_C(register tFloat fltIn)
{
  return((fltIn<(tFloat)0) ? (-fltIn) : (fltIn));
}
#ifdef MLIB_EFPU2_ASM
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
/* Target-specific implementation */
SWLIBS_INLINE tFloat Abs_FLT_ASM_EFPU2(register tFloat fltIn)
{
  register tFloat fltReturn;
  #ifdef __ghs__
    #pragma ghs optasm
  #endif
  SWLIBS_ASM(" efsabs %0,%1": "=r"(fltReturn): "r"(fltIn));
  return((tFloat)fltReturn);
}
#endif /* MLIB_EFPU2_ASM */
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Abs

@param[in]    f32In      Input value.

@return       Absolute value of input parameter.

@details      The input value as well as output value is considered as 32-bit fractional data type.
              The output saturation is not implemented in this function, thus in case the absolute
              value of input parameter is outside the [-1, 1) interval, the output value will
              overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Abs_F32
              \image rtf absF32Eq1.math "MLIB_Abs_F32_Eq1"

*/
/**
@note         This function is implemented as inline assembly, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In;
tFrac32 f32Out;

void main(void)
{
    // input value = -0.25
    f32In = FRAC32(-0.25);

    // output should be FRAC32(0.25)
    f32Out = MLIB_Abs_F32(f32In);

    // output should be FRAC32(0.25)
    f32Out = MLIB_Abs(f32In, F32);

    // ##############################################################
    // Available only if 32-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be FRAC32(0.25)
    f32Out = MLIB_Abs(f32In);
}
\endcode
****************************************************************************/
/* @remarks Implements DMLIB00007, DMLIB00000, DMLIB00003, DMLIB00005 */
SWLIBS_INLINE tFrac32 MLIB_Abs_F32(register tFrac32 f32In)
{
  #ifdef MLIB_LSP
    #if defined(__GNUC__) && defined(__PPC_EABI__)
      /* @remarks Implements DMLIB00004 */
      return(Abs_F32_S32DSPPC_LSP(f32In));
    #else
      /* @remarks Implements DMLIB00004 */
      return(Abs_F32_ITR_LSP(f32In));
    #endif
  #else
    /* @remarks Implements DMLIB00004 */
    return(Abs_F32_C(f32In));
  #endif
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Abs

@param[in]    f16In      Input value.

@return       Absolute value of input parameter.

@details      The input value as well as output value is considered as 16-bit fractional data type.
              The output saturation is not implemented in this function, thus in case the absolute
              value of input parameter is outside the [-1, 1) interval, the output value will
              overflow.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Abs_F16
              \image rtf absF16Eq1.math "MLIB_Abs_F16_Eq1"

*/
/**
@note         This function is implemented as inline assembly, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In;
tFrac16 f16Out;

void main(void)
{
    // input value = -0.25
    f16In = FRAC16(-0.25);

    // output should be FRAC16(0.25)
    f16Out = MLIB_Abs_F16(f16In);

    // output should be FRAC16(0.25)
    f16Out = MLIB_Abs(f16In, F16);

    // ##############################################################
    // Available only if 16-bit fractional implementation selected
    // as default
    // ##############################################################

    // output should be FRAC16(0.25)
    f16Out = MLIB_Abs(f16In);
}
\endcode
****************************************************************************/
/* @remarks Implements DMLIB00007, DMLIB00000, DMLIB00002, DMLIB00005 */
SWLIBS_INLINE tFrac16 MLIB_Abs_F16(register tFrac16 f16In)
{
  #ifdef MLIB_LSP
    #if defined(__GNUC__) && defined(__PPC_EABI__)
      /* @remarks Implements DMLIB00004 */
      return(Abs_F16_S32DSPPC_LSP(f16In));
    #else
      /* @remarks Implements DMLIB00004 */
      return(Abs_F16_ITR_LSP(f16In));
    #endif
  #else
    /* @remarks Implements DMLIB00004 */
    return(Abs_F16_C(f16In));
  #endif
}





#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_Abs

@param[in]    fltIn      Input value.

@return       Absolute value of input parameter.

@details      The input value as well as output value is considered as single precision floating
              point data type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_Abs_FLT
              \image rtf absFLTEq1.math "MLIB_Abs_FLT_Eq1"

*/
/**
@note         The function may raise floating-point exceptions (floating-point overflow, underflow,
              inexact, invalid operation).
*/
/**
@note         The function may raise floating-point exceptions (floating-point
              inexact, invalid operation).

@note         This function is implemented as inline assembly, and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFloat fltIn;
tFloat fltOut;

void main(void)
{
    // input value = -0.25
    fltIn = (tFloat)-0.25;

    // output should be 0.25
    fltOut = MLIB_Abs_FLT(fltIn);

    // output should be 0.25
    fltOut = MLIB_Abs(fltIn, FLT);

    // ##############################################################
    // Available only if single precision floating point
    // implementation selected as default
    // ##############################################################

    // output should be 0.25
    fltOut = MLIB_Abs(fltIn);
}
\endcode
****************************************************************************/
/* @remarks Implements DMLIB00007, DMLIB00000, DMLIB00001, DMLIB00005 */
SWLIBS_INLINE tFloat MLIB_Abs_FLT(register tFloat fltIn)
{
  #ifdef __ghs__
    /* @remarks Implements DMLIB00004 */
    return(Abs_FLT_ASM_EFPU2(fltIn));
  #elif defined(__GNUC__) && defined(__PPC_EABI__)
    /* @remarks Implements DMLIB00004 */
    return(Abs_FLT_ASM_EFPU2(fltIn));
  #else
    /* @remarks Implements DMLIB00004 */
    return(Abs_FLT_C(fltIn));
  #endif
}


#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* MLIB_ABS_H */
