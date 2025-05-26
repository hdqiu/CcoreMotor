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
* @file       GFLIB_VMin.h
*
* @brief      Header file for GFLIB_VMin function
*
******************************************************************************/
#ifndef GFLIB_VMIN_H
#define GFLIB_VMIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE)))
  #define GFLIB_VMin(...)     macro_dispatcher(GFLIB_VMin, __VA_ARGS__)(__VA_ARGS__)     /* This function finds the vector minimum. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /* @remarks Implements DGFLIB00368 */
    #define GFLIB_VMin_Dsptchr_2(pIn,N)     GFLIB_VMin_Dsptchr_3(pIn,N,F32)     /* Function dispatcher for GFLIB_VMin_Dsptchr_2, do not modify!!! */
  #endif 
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /* @remarks Implements DGFLIB00368 */
    #define GFLIB_VMin_Dsptchr_2(pIn,N)     GFLIB_VMin_Dsptchr_3(pIn,N,F16)     /* Function dispatcher for GFLIB_VMin_Dsptchr_2, do not modify!!! */
  #endif 
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_FLT)
    /* @remarks Implements DGFLIB00368 */
    #define GFLIB_VMin_Dsptchr_2(pIn,N)     GFLIB_VMin_Dsptchr_3(pIn,N,FLT)     /* Function dispatcher for GFLIB_VMin_Dsptchr_2, do not modify!!! */
  #endif 

  #define GFLIB_VMin_Dsptchr_3(pIn,N,Impl)    GFLIB_VMin_Dsptchr_(pIn,N,Impl)   /* Function dispatcher for GFLIB_VMin_Dsptchr_3, do not modify!!! */
  
  /* @remarks Implements DGFLIB00370 */
  #define GFLIB_VMin_Dsptchr_(pIn,N,Impl)     GFLIB_VMin_##Impl(pIn,N)          /* Function dispatcher for GFLIB_VMin_Dsptchr_, do not modify!!! */
#endif /* if (!(defined(__MINGW32__) || defined(__MINGW64__) || defined(_MSC_VER) || defined(_MATLAB_BAM_CREATE))) */

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  /****************************************************************************
  * Exported function prototypes
  ****************************************************************************/
  extern tU32 GFLIB_VMin_F32(const tFrac32 *pIn, tU32 u32N);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */


/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  /****************************************************************************
  * Exported function prototypes
  ****************************************************************************/
  extern tU16 GFLIB_VMin_F16(const tFrac16 *pIn, tU16 u16N);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */


/****************************************************************************
* Implementation variant: Single precision floating point
****************************************************************************/
#if (SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON)
  /****************************************************************************
  * Exported function prototypes
  ****************************************************************************/ 
  extern tU32 GFLIB_VMin_FLT(const tFloat *pIn, tU32 u32N);
#endif /* SWLIBS_SUPPORT_FLT == SWLIBS_STD_ON */




/****************************************************************************
* Inline functions
****************************************************************************/

#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
#ifndef RTWTYPES_H /* disable fixed-length implementations for Matlab */
/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 4 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 4-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[4] = {6, 3, 1, 4};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin4_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00352 */
SWLIBS_INLINE tU16 GFLIB_VMin4_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;
  

  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 5 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 5-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. There must be two consecutive readable bytes in the memory following
              the last element of the input array. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[5] = {6, 3, 1, 4, 5};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin5_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#if defined(__CWCC__) || defined(__MWERKS__)
/* Compiler_Warning: Inlining is required to meet real-time performance demands of target applications. */
#pragma always_SWLIBS_INLINE on
#endif
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00353 */
SWLIBS_INLINE tU16 GFLIB_VMin5_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;

  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 6 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 6-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[6] = {6, 3, 1, 4, 5, 6};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin6_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#if defined(__CWCC__) || defined(__MWERKS__)
/* Compiler_Warning: Inlining is required to meet real-time performance demands of target applications. */
#pragma always_SWLIBS_INLINE on
#endif
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00354 */
SWLIBS_INLINE tU16 GFLIB_VMin6_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;

  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 7 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 7-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[7] = {6, 3, 1, 4, 5, 6, 7};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin7_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#if defined(__CWCC__) || defined(__MWERKS__)
/* Compiler_Warning: Inlining is required to meet real-time performance demands of target applications. */
#pragma always_SWLIBS_INLINE on
#endif
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00355 */
SWLIBS_INLINE tU16 GFLIB_VMin7_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;
  
  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  if(pIn[6] <= pIn[u16Idx])
  {
    u16Idx = 6u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 8 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 8-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[8] = {6, 3, 1, 4, 5, 6, 7, 8};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin8_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00356 */
SWLIBS_INLINE tU16 GFLIB_VMin8_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;


  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  if(pIn[6] <= pIn[u16Idx])
  {
    u16Idx = 6u;
  }
  if(pIn[7] <= pIn[u16Idx])
  {
    u16Idx = 7u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 9 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 9-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. There must be two consecutive readable bytes in the memory following
              the last element of the input array. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[9] = {6, 3, 1, 4, 5, 6, 7, 8, 9};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin9_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00357 */
SWLIBS_INLINE tU16 GFLIB_VMin9_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;

  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  if(pIn[6] <= pIn[u16Idx])
  {
    u16Idx = 6u;
  }
  if(pIn[7] <= pIn[u16Idx])
  {
    u16Idx = 7u;
  }
  if(pIn[8] <= pIn[u16Idx])
  {
    u16Idx = 8u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 10 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 10-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[10] = {6, 3, 1, 4, 5, 6, 7, 8, 9, 10};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin10_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00358 */
SWLIBS_INLINE tU16 GFLIB_VMin10_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;

  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  if(pIn[6] <= pIn[u16Idx])
  {
    u16Idx = 6u;
  }
  if(pIn[7] <= pIn[u16Idx])
  {
    u16Idx = 7u;
  }
  if(pIn[8] <= pIn[u16Idx])
  {
    u16Idx = 8u;
  }
  if(pIn[9] <= pIn[u16Idx])
  {
    u16Idx = 9u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 11 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 11-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. There must be two consecutive readable bytes in the memory following
              the last element of the input array. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[11] = {6, 3, 1, 4, 5, 6, 7, 8, 9, 10, 11};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin11_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00359 */
SWLIBS_INLINE tU16 GFLIB_VMin11_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;
  
  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  if(pIn[6] <= pIn[u16Idx])
  {
    u16Idx = 6u;
  }
  if(pIn[7] <= pIn[u16Idx])
  {
    u16Idx = 7u;
  }
  if(pIn[8] <= pIn[u16Idx])
  {
    u16Idx = 8u;
  }
  if(pIn[9] <= pIn[u16Idx])
  {
    u16Idx = 9u;
  }
  if(pIn[10] <= pIn[u16Idx])
  {
    u16Idx = 10u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 12 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 12-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[12] = {6, 3, 1, 4, 5, 6, 7, 8, 9,
      10, 11, 12};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin12_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00360 */
SWLIBS_INLINE tU16 GFLIB_VMin12_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;
  
  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  if(pIn[6] <= pIn[u16Idx])
  {
    u16Idx = 6u;
  }
  if(pIn[7] <= pIn[u16Idx])
  {
    u16Idx = 7u;
  }
  if(pIn[8] <= pIn[u16Idx])
  {
    u16Idx = 8u;
  }
  if(pIn[9] <= pIn[u16Idx])
  {
    u16Idx = 9u;
  }
  if(pIn[10] <= pIn[u16Idx])
  {
    u16Idx = 10u;
  }
  if(pIn[11] <= pIn[u16Idx])
  {
    u16Idx = 11u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 13 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 13-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. There must be two consecutive readable bytes in the memory following
              the last element of the input array. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[13] = {6, 3, 1, 4, 5, 6, 7, 8, 9,
      10, 11, 12, 13};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin13_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00361 */
SWLIBS_INLINE tU16 GFLIB_VMin13_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;
  
  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  if(pIn[6] <= pIn[u16Idx])
  {
    u16Idx = 6u;
  }
  if(pIn[7] <= pIn[u16Idx])
  {
    u16Idx = 7u;
  }
  if(pIn[8] <= pIn[u16Idx])
  {
    u16Idx = 8u;
  }
  if(pIn[9] <= pIn[u16Idx])
  {
    u16Idx = 9u;
  }
  if(pIn[10] <= pIn[u16Idx])
  {
    u16Idx = 10u;
  }
  if(pIn[11] <= pIn[u16Idx])
  {
    u16Idx = 11u;
  }
  if(pIn[12] <= pIn[u16Idx])
  {
    u16Idx = 12u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 14 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 14-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[14] = {6, 3, 1, 4, 5, 6, 7, 8, 9,
      10, 11, 12, 13, 14};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin14_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00362 */
SWLIBS_INLINE tU16 GFLIB_VMin14_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;
  
  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  if(pIn[6] <= pIn[u16Idx])
  {
    u16Idx = 6u;
  }
  if(pIn[7] <= pIn[u16Idx])
  {
    u16Idx = 7u;
  }
  if(pIn[8] <= pIn[u16Idx])
  {
    u16Idx = 8u;
  }
  if(pIn[9] <= pIn[u16Idx])
  {
    u16Idx = 9u;
  }
  if(pIn[10] <= pIn[u16Idx])
  {
    u16Idx = 10u;
  }
  if(pIn[11] <= pIn[u16Idx])
  {
    u16Idx = 11u;
  }
  if(pIn[12] <= pIn[u16Idx])
  {
    u16Idx = 12u;
  }
  if(pIn[13] <= pIn[u16Idx])
  {
    u16Idx = 13u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 15 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 15-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. There must be two consecutive readable bytes in the memory following
              the last element of the input array. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[15] = {6, 3, 1, 4, 5, 6, 7, 8, 9,
      10, 11, 12, 13, 14, 15};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin15_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00363 */
SWLIBS_INLINE tU16 GFLIB_VMin15_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;
  
  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  if(pIn[6] <= pIn[u16Idx])
  {
    u16Idx = 6u;
  }
  if(pIn[7] <= pIn[u16Idx])
  {
    u16Idx = 7u;
  }
  if(pIn[8] <= pIn[u16Idx])
  {
    u16Idx = 8u;
  }
  if(pIn[9] <= pIn[u16Idx])
  {
    u16Idx = 9u;
  }
  if(pIn[10] <= pIn[u16Idx])
  {
    u16Idx = 10u;
  }
  if(pIn[11] <= pIn[u16Idx])
  {
    u16Idx = 11u;
  }
  if(pIn[12] <= pIn[u16Idx])
  {
    u16Idx = 12u;
  }
  if(pIn[13] <= pIn[u16Idx])
  {
    u16Idx = 13u;
  }
  if(pIn[14] <= pIn[u16Idx])
  {
    u16Idx = 14u;
  }
  return(u16Idx);
}


/***************************************************************************/
/**
@ingroup    GFLIB_GROUP

@functionality GFLIB_VMin

@param[in]    pIn   Pointer to an array of 16-bit fixed-point signed input values. The length
                    of the array must be 16 elements.

@return       The function returns the index of the smallest element of the input array.

@details      The function finds the minimum in a 16-element vector of values and returns the index
              of that value. If there are several equal minimums, the index of an arbitrary one of
              them is returned. This function is faster than #GFLIB_VMin_F16.

@par Code Example
\code
#include "gflib.h"

void main(void)
{
    tFrac16 pInputArray[16] = {6, 3, 1, 4, 5, 6, 7, 8, 9,
      10, 11, 12, 13, 14, 15, 16};
    tFrac16 f16MinValue;
    
    f16MinValue = pInputArray[GFLIB_VMin16_F16(pInputArray)];
}
\endcode
****************************************************************************/  
#ifdef __ghs__
  #pragma ghs static_call 0
  #pragma ghs extra_stack 0
#endif
/* @remarks Implements DGFLIB00364 */
SWLIBS_INLINE tU16 GFLIB_VMin16_F16(const tFrac16 *pIn)
{
  tU16 u16Idx;
  
  u16Idx = 0u;
  if(pIn[1] <= pIn[u16Idx])
  {
    u16Idx = 1u;
  }
  if(pIn[2] <= pIn[u16Idx])
  {
    u16Idx = 2u;
  }
  if(pIn[3] <= pIn[u16Idx])
  {
    u16Idx = 3u;
  }
  if(pIn[4] <= pIn[u16Idx])
  {
    u16Idx = 4u;
  }
  if(pIn[5] <= pIn[u16Idx])
  {
    u16Idx = 5u;
  }
  if(pIn[6] <= pIn[u16Idx])
  {
    u16Idx = 6u;
  }
  if(pIn[7] <= pIn[u16Idx])
  {
    u16Idx = 7u;
  }
  if(pIn[8] <= pIn[u16Idx])
  {
    u16Idx = 8u;
  }
  if(pIn[9] <= pIn[u16Idx])
  {
    u16Idx = 9u;
  }
  if(pIn[10] <= pIn[u16Idx])
  {
    u16Idx = 10u;
  }
  if(pIn[11] <= pIn[u16Idx])
  {
    u16Idx = 11u;
  }
  if(pIn[12] <= pIn[u16Idx])
  {
    u16Idx = 12u;
  }
  if(pIn[13] <= pIn[u16Idx])
  {
    u16Idx = 13u;
  }
  if(pIn[14] <= pIn[u16Idx])
  {
    u16Idx = 14u;
  }
  if(pIn[15] <= pIn[u16Idx])
  {
    u16Idx = 15u;
  }
  return(u16Idx);
}
#endif /* ifndef RTWTYPES_H */
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */



#ifdef __cplusplus
}
#endif

#endif /* GFLIB_VMIN_H */
