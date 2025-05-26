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
* @file       MLIB_SubSat.h
*
* @brief      Header file for MLIB_SubSat function
*
******************************************************************************/
#ifndef MLIB_SUBSAT_H
#define MLIB_SUBSAT_H
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
  #include "MLIB_Sub.h"
#else
  /* Following include serves for NXP internal testing purposes only. 
  *  This header is not part of the release. */
  #include "CCOV_MLIB_Sub.h"
#endif

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define MLIB_SubSat(...)     macro_dispatcher(MLIB_SubSat, __VA_ARGS__)(__VA_ARGS__)     /* This function subtracts the second parameter from the first one and saturate if necessary. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DMLIB00078 */    
    #define MLIB_SubSat_Dsptchr_2(In1,In2)     MLIB_SubSat_Dsptchr_3(In1,In2,F32)     /* Function dispatcher for MLIB_SubSat_Dsptchr_2, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DMLIB00078 */
    #define MLIB_SubSat_Dsptchr_2(In1,In2)     MLIB_SubSat_Dsptchr_3(In1,In2,F16)     /* Function dispatcher for MLIB_SubSat_Dsptchr_2, do not modify!!! */
  #endif

  #define MLIB_SubSat_Dsptchr_3(In1,In2,Impl)    MLIB_SubSat_Dsptchr_(In1,In2,Impl)     /* Function dispatcher for MLIB_SubSat_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DMLIB00080 */
  #define MLIB_SubSat_Dsptchr_(In1,In2,Impl)     MLIB_SubSat_##Impl(In1,In2)            /* Function dispatcher for MLIB_SubSat_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/

/****************************************************************************
* Exported function prototypes
****************************************************************************/

/****************************************************************************
* Inline functions
****************************************************************************/
/* MLIB_SubSat_F32 implementation variant - C */
/* C implementation */
SWLIBS_INLINE tFrac32 SubSat_F32_C(register tFrac32 f32In1,register tFrac32 f32In2)
{
  register tS32 s32Temp;
  register tS32 s32satmin, s32satmax;

  s32Temp = F32TOINT32(MLIB_Sub_F32(f32In1, f32In2));

  s32satmax = (~F32TOINT32(f32In1) & F32TOINT32(f32In2)) & s32Temp;
  s32satmin = F32TOINT32(f32In1) & (~F32TOINT32(f32In2)) & (~s32Temp);

  s32Temp = (s32satmin < 0) ? SWLIBS_INT32_MIN : s32Temp;
  s32Temp = (s32satmax < 0) ? SWLIBS_INT32_MAX : s32Temp;
  return(INT32TOF32(s32Temp));
}
#ifdef MLIB_LSP
  #if (!(defined(__GNUC__) && defined(__PPC_EABI__)))
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
    /* Target-specific implementation */
    SWLIBS_INLINE tFrac32 SubSat_F32_ITR_LSP(register tFrac32 f32In1,register tFrac32 f32In2)
    {
      return((tFrac32)__zsubfwss((__lsp32_32__)f32In2, (__lsp32_32__)f32In1));
    }
  #endif /* (!(defined(__GNUC__) && defined(__PPC_EABI__))) */
  #if defined(__GNUC__) && defined(__PPC_EABI__)
    /* MLIB_SubSat_F32 implementation variant - LSP assembly for S32DS for Power Architecture toolchain */
    SWLIBS_INLINE tFrac32 SubSat_F32_S32DSPPC_LSP(register tFrac32 f32In1,register tFrac32 f32In2)
    {
      register tFrac32 f32Return;
      SWLIBS_ASM(" zsubfwss %0,%1,%2": "=r"(f32Return): "r"(f32In2), "r"(f32In1));
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
  SWLIBS_INLINE tFrac32 SubSat_F32_ASM_ISEL(register tFrac32 f32In1,register tFrac32 f32In2)
  {
    register tFrac32 f32Tmp1, f32Tmp2, f32Return, f32SatMin, f32SatMax;
    
    f32SatMin = SWLIBS_INT32_MIN;
    f32SatMax = SWLIBS_INT32_MAX;
    #ifdef __ghs__
      #pragma ghs optasm
    #endif
    SWLIBS_ASM(" mcrxr 0" ::: "cc");  /* clear XER summary overflow flag */
    #ifdef __ghs__
      #pragma ghs optasm
    #endif
    SWLIBS_ASM(" subfo. %0,%1,%2": "=r"(f32Tmp2): "r"(f32In2), "r"(f32In1): "cc");
    #ifdef __ghs__
      #pragma ghs optasm
    #endif
    SWLIBS_ASM(" isel %0,%1,%2,0": "=r"(f32Tmp1): "b"(f32SatMax), "b"(f32SatMin): "cc");
    #ifdef __ghs__
      #pragma ghs optasm
    #endif
    SWLIBS_ASM(" isel %0,%1,%2,3": "=r"(f32Return): "b"(f32Tmp1), "b"(f32Tmp2): "cc");
    return(f32Return);
  }
#endif /* ifdef MLIB_ISEL */
/* MLIB_SubSat_F16 implementation variant - C */
/* C implementation */
SWLIBS_INLINE tFrac16 SubSat_F16_C(register tFrac16 f16In1,register tFrac16 f16In2)
{
  register tS32 s32temp;

  s32temp = F32TOINT32(MLIB_Sub_F32((tFrac32)f16In1, (tFrac32)f16In2));

  s32temp = (s32temp > (tS32) SWLIBS_INT16_MAX) ? (tS32) SWLIBS_INT16_MAX : s32temp;
  s32temp = (s32temp < (tS32) SWLIBS_INT16_MIN) ? (tS32) SWLIBS_INT16_MIN : s32temp;
  return(INT32TOF16(s32temp));
}
#ifdef MLIB_LSP
  #if (!(defined(__GNUC__) && defined(__PPC_EABI__)))
  #ifdef __ghs__
    #pragma ghs static_call 0
    #pragma ghs extra_stack 0
  #endif
    /* Target-specific implementation */
    SWLIBS_INLINE tFrac16 SubSat_F16_ITR_LSP(register tFrac16 f16In1,register tFrac16 f16In2)
    {
      /* Compiler_Warning: This is side effect of non static inline usage. */
      return((tFrac16)__lsp_extract_lower_hword(__zvsubfhss((__lsp32_sf16__ )f16In2, (__lsp32_sf16__ )f16In1)));
    }
  #endif /* (!(defined(__GNUC__) && defined(__PPC_EABI__))) */
  #if defined(__GNUC__) && defined(__PPC_EABI__)
    /* MLIB_SubSat_F16 implementation variant - LSP assembly for S32DS for Power Architecture toolchain */
    SWLIBS_INLINE tFrac16 SubSat_F16_S32DSPPC_LSP(register tFrac16 f16In1,register tFrac16 f16In2)
    {
      register tFrac16 f16Return;
      SWLIBS_ASM(" zvsubfhss %0,%1,%2": "=r"(f16Return): "r"(f16In2), "r"(f16In1));
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

@functionality MLIB_SubSat

@param[in]    f32In1     Operand is a 32-bit number normalized between [-1,1).

@param[in]    f32In2     Operand is a 32-bit number normalized between [-1,1).

@return       The subtraction of the second argument from the first argument.

@details      The input values as well as output value are considered as 32-bit fractional data
              type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_SubSat_F32
              \image rtf subsatF32Eq1.math "MLIB_SubSat_F32_Eq1"

*/
/**
@note         This function is implemented as inline assembly and  thus is not ANSI-C compliant.
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
  // first input = 0.5
  f32In1 = FRAC32(0.5);

  // second input = 0.25
  f32In2 = FRAC32(0.25);

  // output should be 0x20000000
  f32Out = MLIB_SubSat_F32(f32In1,f32In2);

  // output should be 0x20000000
  f32Out = MLIB_SubSat(f32In1,f32In2,F32);

  // ##############################################################
  // Available only if 32-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x20000000
  f32Out = MLIB_SubSat(f32In1,f32In2);
}
\endcode
****************************************************************************/
/* @remarks Implements DMLIB00079, DMLIB00073, DMLIB00075, DMLIB00077, DMLIB00082 */
SWLIBS_INLINE tFrac32 MLIB_SubSat_F32(register tFrac32 f32In1, register tFrac32 f32In2)
{
  #ifdef MLIB_LSP
    #if defined(__GNUC__) && defined(__PPC_EABI__)
      /* @remarks Implements DMLIB00076 */
      return(SubSat_F32_S32DSPPC_LSP(f32In1,f32In2));
    #else
      /* @remarks Implements DMLIB00076 */
      return(SubSat_F32_ITR_LSP(f32In1,f32In2));
    #endif
  #else
    #ifdef MLIB_ISEL
      /* @remarks Implements DMLIB00076 */
      return(SubSat_F32_ASM_ISEL(f32In1,f32In2));
    #else
      /* @remarks Implements DMLIB00076 */
      return(SubSat_F32_C(f32In1,f32In2));
    #endif
  #endif
}





/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    MLIB_GROUP

@functionality MLIB_SubSat

@param[in]    f16In1     Operand is a 16-bit number normalized between [-1,1).

@param[in]    f16In2     Operand is a 16-bit number normalized between [-1,1).

@return       The subtraction of the second argument from the first argument.

@details      The input values as well as output value are considered as 16-bit fractional data
              type.

              \par

              The output of the function is defined by the following simple equation:
              \anchor eq1_SubSat_F16
              \image rtf subsatF16Eq1.math "MLIB_SubSat_F16_Eq1"

*/
/**
@note         This function is implemented as inline and thus is not ANSI-C compliant.
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
  // first input = 0.5
  f16In1 = FRAC16(0.5);

  // second input = 0.25
  f16In2 = FRAC16(0.25);

  // output should be 0x2000
  f16Out = MLIB_SubSat_F16(f16In1,f16In2);

  // output should be 0x2000
  f16Out = MLIB_SubSat(f16In1,f16In2,F16);

  // ##############################################################
  // Available only if 16-bit fractional implementation selected
  // as default
  // ##############################################################

  // output should be 0x2000
  f16Out = MLIB_SubSat(f16In1,f16In2);
}
\endcode
****************************************************************************/
/* @remarks Implements DMLIB00079, DMLIB00073, DMLIB00074, DMLIB00077, DMLIB00083 */
SWLIBS_INLINE tFrac16 MLIB_SubSat_F16(register tFrac16 f16In1,register tFrac16 f16In2)
{
  #ifdef MLIB_LSP
    #if defined(__GNUC__) && defined(__PPC_EABI__)
      /* @remarks Implements DMLIB00076 */
      return(SubSat_F16_S32DSPPC_LSP(f16In1,f16In2));
    #else
      /* @remarks Implements DMLIB00076 */
      return(SubSat_F16_ITR_LSP(f16In1,f16In2));
    #endif
  #else
    /* @remarks Implements DMLIB00076 */
    return(SubSat_F16_C(f16In1,f16In2));
  #endif
}

#ifdef __cplusplus
}
#endif

#endif /* MLIB_SUBSAT_H */
