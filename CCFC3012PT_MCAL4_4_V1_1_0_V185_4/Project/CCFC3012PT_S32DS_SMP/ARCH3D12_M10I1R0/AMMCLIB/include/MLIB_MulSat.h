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
* @file       MLIB_MulSat.h
*
* @brief      Header file for MLIB_MulSat function
*
******************************************************************************/
#ifndef MLIB_MULSAT_H
#define MLIB_MULSAT_H
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
#ifndef AMMCLIB_TESTING_ENV
  #include "MLIB_Mul.h"
  #include "MLIB_ConvertPU.h"
#else
  /* Following include serves for NXP internal testing purposes only. 
  *  This header is not part of the release. */
  #include "CCOV_MLIB_Mul.h"
  #include "CCOV_MLIB_ConvertPU.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_MulSat(...)     macro_dispatcher(MLIB_MulSat, __VA_ARGS__)(__VA_ARGS__)     /* This function multiply two input parameters and saturate if necessary. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00101 */
    #define MLIB_MulSat_Dsptchr_2(In1,In2)     MLIB_MulSat_Dsptchr_3(In1,In2,F32)     /* Function dispatcher for MLIB_MulSat_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00101 */
    #define MLIB_MulSat_Dsptchr_2(In1,In2)     MLIB_MulSat_Dsptchr_3(In1,In2,F16)     /* Function dispatcher for MLIB_MulSat_Dsptchr_2, do not modify!!! */
  #endif

  #define MLIB_MulSat_Dsptchr_3(In1,In2,Impl)    MLIB_MulSat_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for MLIB_MulSat_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00103 */
  #define MLIB_MulSat_Dsptchr_(In1,In2,Impl)     MLIB_MulSat_##Impl(In1,In2)            /* Function dispatcher for MLIB_MulSat_Dsptchr_, do not modify!!! */
#endif
/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* inline functions
****************************************************************************/
/* C implementation */
SWLIBS_INLINE tFrac32 MulSat_F32_C(register tFrac32 f32In1,register tFrac32 f32In2)
{
  register tS32 s32Temp;

  s32Temp = F32TOINT32(MLIB_Mul_F32(f32In1, f32In2));
    s32Temp = (s32Temp == SWLIBS_INT32_MIN) ? SWLIBS_INT32_MAX : s32Temp;
  return(INT32TOF32(s32Temp));
}
/* C implementation */
SWLIBS_INLINE tFrac32 MulSat_F32F16F16_C(register tFrac16 f16In1,register tFrac16 f16In2)
{
  register tS32 s32Temp;

  s32Temp = F32TOINT32(MLIB_Mul_F32F16F16(f16In1, f16In2));
  s32Temp = (s32Temp == SWLIBS_INT32_MIN) ? SWLIBS_INT32_MAX : s32Temp;
  return(INT32TOF32(s32Temp));
}
#ifdef MLIB_LSP
  #if (!(defined(__GNUC__) && defined(__PPC_EABI__)))
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
    /* Target-specific implementation */
    SWLIBS_INLINE tFrac32 MulSat_F32_ITR_LSP(register tFrac32 f32In1,register tFrac32 f32In2)
    {
      return((tFrac32)__zmwsf((__lsp32_32__)f32In1, (__lsp32_32__)f32In2));
    }
  #endif /* (!(defined(__GNUC__) && defined(__PPC_EABI__))) */
  #if (!(defined(__GNUC__) && defined(__PPC_EABI__)))
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
    /* Target-specific implementation */
    SWLIBS_INLINE tFrac32 MulSat_F32F16F16_ITR_LSP(register tFrac16 f16In1,register tFrac16 f16In2)
    {
      return((tFrac32)__zmhosf((__lsp32_16__)f16In1, (__lsp32_16__)f16In2));
    }
  #endif /* (!(defined(__GNUC__) && defined(__PPC_EABI__))) */
  #if defined(__GNUC__) && defined(__PPC_EABI__)
    /* MLIB_MulSat_F32 implementation variant - LSP assembly for S32DS for Power Architecture toolchain */
    SWLIBS_INLINE tFrac32 MulSat_F32_S32DSPPC_LSP(register tFrac32 f32In1,register tFrac32 f32In2)
    {
      tFrac32 f32Return;
      SWLIBS_ASM(" zmwsf %0,%1,%2": "=r"(f32Return): "r"(f32In1), "r"(f32In2));
      return((tFrac32)f32Return);
    } 
    /* MLIB_MulSat_F32F16F16 implementation variant - LSP assembly for S32DS for Power Architecture toolchain */
    SWLIBS_INLINE tFrac32 MulSat_F32F16F16_S32DSPPC_LSP(register tFrac16 f16In1,register tFrac16 f16In2)
    {
      register tFrac32 f32Return;
      SWLIBS_ASM(" zmhosf %0,%1,%2": "=r"(f32Return): "r"(f16In1), "r"(f16In2));
      return((tFrac32)f32Return);
    }
  #endif
#endif
#ifdef MLIB_ISEL
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
  /* Target-specific implementation */
  SWLIBS_INLINE tFrac32 MulSat_F32_ASM_ISEL(register tFrac32 f32In1,register tFrac32 f32In2)
  {
    register tFrac32 f32Return, f32Tmp1, f32SatMax;

    f32SatMax = SWLIBS_INT32_MAX;
    #ifdef __ghs__
      #pragma ghs optasm
    #endif
    SWLIBS_ASM(" mullw %0,%1,%2": "=r"(f32Tmp1): "r"(f32In1), "r"(f32In2));
    #ifdef __ghs__
      #pragma ghs optasm
    #endif
    SWLIBS_ASM(" mulhw %0,%1,%2": "=r"(f32Return): "r"(f32In1), "r"(f32In2));
    #ifdef __ghs__
      #pragma ghs optasm
    #endif
    SWLIBS_ASM(" mcrxr 0" ::: "cc");  /* clear XER summary overflow flag */
    #ifdef __ghs__
      #pragma ghs optasm
    #endif
    SWLIBS_ASM(" addc %0,%0,%0": "+r"(f32Tmp1) :: "cc");    
    #ifdef __ghs__
      #pragma ghs optasm
    #endif
    SWLIBS_ASM(" addeo. %0,%0,%0": "+r"(f32Return) :: "cc");
    #ifdef __ghs__
      #pragma ghs optasm
    #endif
    SWLIBS_ASM(" isel %0,%1,%0,3": "+r"(f32Return): "b"(f32SatMax): "cc");
    return(f32Return);
  }
#endif /* ifdef MLIB_ISEL */
/* C implementation */
SWLIBS_INLINE tFrac16 MulSat_F16_C(register tFrac16 f16In1,register tFrac16 f16In2)
{
  register tS16 s16Temp;

  s16Temp = F16TOINT16(MLIB_Mul_F16(f16In1, f16In2));
  s16Temp = (s16Temp == SWLIBS_INT16_MIN) ? SWLIBS_INT16_MAX : s16Temp;
  return(INT16TOF16(s16Temp));
}
#ifdef MLIB_LSP
  #if (!(defined(__GNUC__) && defined(__PPC_EABI__)))
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
    /* Target-specific implementation */
    SWLIBS_INLINE tFrac16 MulSat_F16_ITR_LSP(register tFrac16 f16In1,register tFrac16 f16In2)
    {
      /* Compiler_Warning: This is side effect of non static inline usage. */
      return((tFrac16)__lsp_extract_lower_hword(__zvmhsfh((__lsp32_16__)f16In1, (__lsp32_16__)f16In2)));
    }
  #endif /* (!(defined(__GNUC__) && defined(__PPC_EABI__))) */
  #if defined(__GNUC__) && defined(__PPC_EABI__)
    /* MLIB_MulSat_F16 implementation variant - LSP assembly for S32DS for Power Architecture toolchain */
    SWLIBS_INLINE tFrac16 MulSat_F16_S32DSPPC_LSP(register tFrac16 f16In1,register tFrac16 f16In2)
    {
      tFrac16 f16Return;
      SWLIBS_ASM(" zvmhsfh %0,%1,%2": "=r"(f16Return): "r"(f16In1), "r"(f16In2));
      SWLIBS_ASM(" extsh %0,%1": "=r"(f16Return): "r"(f16Return));
      return(f16Return);
    }
  #endif
#endif





/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_MulSat

@param[in]    f32In1     Operand is a 32-bit number normalized between [-1,1).

@param[in]    f32In2     Operand is a 32-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values as well as output value are considered as 32-bit fractional data
              type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_MulSat_F32
              \image rtf mulsatF32Eq1.math "MLIB_MulSat_F32_Eq1"

*/
/**
@note         This function is implemented as inline assembly and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac32 f32In1;
tFrac32 f32In2;
tFrac32 f32Out;

void main(void)
{
  // first input = 0.8
  f32In1 = FRAC32(0.8);

  // second input = 0.75
  f32In2 = FRAC32(0.75);

  // output should be 0x4ccccccc = FRAC32(0.6)
  f32Out = MLIB_MulSat_F32(f32In1,f32In2);

  // output should be 0x4ccccccc = FRAC32(0.6)
  f32Out = MLIB_MulSat(f32In1,f32In2,F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x4ccccccc = FRAC32(0.6)
  f32Out = MLIB_MulSat(f32In1,f32In2);
}
\endcode
****************************************************************************/
/* @remarks Implements DMLIB00102, DMLIB00095, DMLIB00097, DMLIB00100, DMLIB00105 */
SWLIBS_INLINE tFrac32 MLIB_MulSat_F32(register tFrac32 f32In1,register tFrac32 f32In2)
{
  #ifdef MLIB_LSP
    #if defined(__GNUC__) && defined(__PPC_EABI__)
      /* @remarks Implements DMLIB00098 */
      return(MulSat_F32_S32DSPPC_LSP(f32In1,f32In2));
    #else
      /* @remarks Implements DMLIB00098 */
      return(MulSat_F32_ITR_LSP(f32In1,f32In2));
    #endif
  #else
    #ifdef MLIB_ISEL
      /* @remarks Implements DMLIB00098 */
      return(MulSat_F32_ASM_ISEL(f32In1,f32In2));
    #else
      /* @remarks Implements DMLIB00098 */
      return(MulSat_F32_C(f32In1,f32In2));
    #endif
  #endif
}





/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_MulSat

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values are considered as 16-bit fractional data type and the output value is
              considered as 32-bit fractional data type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_MulSat_F32F16F16
              \image rtf mulsatF32F16F16Eq1.math "MLIB_MulSat_F32F16F16_Eq1"

*/
/**
@note         This function is implemented as inline assembly and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac32 f32Out;

void main(void)
{
  // first input = 0.8
  f16In1 = FRAC16(0.8);

  // second input = 0.75
  f16In2 = FRAC16(0.75);

  // output should be 0x4ccccccc = FRAC32(0.6)
  f32Out = MLIB_MulSat_F32F16F16(f16In1,f16In2);

  // output should be 0x4ccccccc = FRAC32(0.6)
  f32Out = MLIB_MulSat(f32In1,f32In2,F32F16f16);
}
\endcode
****************************************************************************/
/* @remarks Implements DMLIB00102, DMLIB00095, DMLIB00099, DMLIB00100, DMLIB00105 */
SWLIBS_INLINE tFrac32 MLIB_MulSat_F32F16F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  #ifdef MLIB_LSP
    #if defined(__GNUC__) && defined(__PPC_EABI__)
      /* @remarks Implements DMLIB00098 */
      return(MulSat_F32F16F16_S32DSPPC_LSP(f16In1,f16In2));
    #else
      /* @remarks Implements DMLIB00098 */
      return(MulSat_F32F16F16_ITR_LSP(f16In1,f16In2));
    #endif
  #else
    /* @remarks Implements DMLIB00098 */
    return(MulSat_F32F16F16_C(f16In1,f16In2));
  #endif
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_MulSat

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       Fractional multiplication of the input arguments.

@details      The input values as well as output value are considered as 16-bit fractional data
              type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_MulSat_F16
              \image rtf mulsatF16Eq1.math "MLIB_MulSat_F16_Eq1"

*/
/**
@note         This function is implemented as inline assembly and thus is not ANSI-C compliant.
*/
/**

@par Code Example
\code
#include "mlib.h"

tFrac16 f16In1;
tFrac16 f16In2;
tFrac16 f16Out;

void main(void)
{
  // first input = 0.8
  f16In1 = FRAC16(0.8);

  // second input = 0.75
  f16In2 = FRAC16(0.75);

  // output should be 0x4ccc = FRAC16(0.6)
  f16Out = MLIB_MulSat_F16(f16In1,f16In2);

  // output should be 0x4ccc = FRAC16(0.6)
  f16Out = MLIB_MulSat(f16In1,f16In2,F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x4ccc = FRAC32(0.6)
  f16Out = MLIB_MulSat(f16In1,f16In2);
}
\endcode
****************************************************************************/
/* @remarks Implements DMLIB00102, DMLIB00095, DMLIB00096, DMLIB00100, DMLIB00106 */
SWLIBS_INLINE tFrac16 MLIB_MulSat_F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  #ifdef MLIB_LSP
    #if defined(__GNUC__) && defined(__PPC_EABI__)
      /* @remarks Implements DMLIB00098 */
      return(MulSat_F16_S32DSPPC_LSP(f16In1,f16In2));
    #else
      /* @remarks Implements DMLIB00098 */
      return(MulSat_F16_ITR_LSP(f16In1,f16In2));
    #endif
  #else
    /* @remarks Implements DMLIB00098 */
    return(MulSat_F16_C(f16In1,f16In2));
  #endif
}


#ifdef __cplusplus
}
#endif

#endif /* MLIB_MULSAT_H */
