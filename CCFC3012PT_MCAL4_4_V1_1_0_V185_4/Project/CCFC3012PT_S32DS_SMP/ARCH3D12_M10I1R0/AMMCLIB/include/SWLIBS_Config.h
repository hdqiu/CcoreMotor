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
* @file     SWLIBS_Config.h
*
* @brief    AMMCLIB configuration header file.
*
******************************************************************************/


#ifndef SWLIBS_CONFIG_H
#define SWLIBS_CONFIG_H

/******************************************************************************
* Library version definition (format <major number>.<minor number>.<build number>)
******************************************************************************/
#define SWLIBS_VERSION {(unsigned char)1U,(unsigned char)1U,(unsigned char)38U}

/******************************************************************************
* Global definitions
******************************************************************************/
#define SWLIBS_STD_ON    (1U)
#define SWLIBS_STD_OFF   (0U)

#define F32 F32
#define F16 F16
#define FLT FLT

#define SWLIBS_DEFAULT_IMPLEMENTATION_F32   (1U) 
#define SWLIBS_DEFAULT_IMPLEMENTATION_F16   (2U)
#define SWLIBS_DEFAULT_IMPLEMENTATION_FLT   (3U)

/******************************************************************************
* Implementation supported
******************************************************************************/
#define SWLIBS_SUPPORT_F32    SWLIBS_STD_ON   /**< Enables/disables support of 32-bit fractional implementation. */
#define SWLIBS_SUPPORT_F16    SWLIBS_STD_ON   /**< Enables/disables support of 16-bit fractional implementation. */
#if defined(__ghs__)
  #if defined(__EFP_APU__)
    #define SWLIBS_SUPPORT_FLT    SWLIBS_STD_ON   /**< Enables/disables support of single precision floating point implementation. */
  #else
    #define SWLIBS_SUPPORT_FLT    SWLIBS_STD_OFF   /**< Enables/disables support of single precision floating point implementation. */
  #endif
#elif defined(__DCC__)
  #if defined(__nofp)
    #define SWLIBS_SUPPORT_FLT    SWLIBS_STD_OFF   /**< Enables/disables support of single precision floating point implementation. */
  #else
    #define SWLIBS_SUPPORT_FLT    SWLIBS_STD_ON   /**< Enables/disables support of single precision floating point implementation. */
  #endif
#elif ((defined(__GNUC__)) && (defined(__PPC_EABI__)))
  #if defined(_SOFT_FLOAT)
    #define SWLIBS_SUPPORT_FLT    SWLIBS_STD_OFF   /**< Enables/disables support of single precision floating point implementation. */
  #else
    #define SWLIBS_SUPPORT_FLT    SWLIBS_STD_ON   /**< Enables/disables support of single precision floating point implementation. */
  #endif
#else
  #define SWLIBS_SUPPORT_FLT    SWLIBS_STD_ON   /**< Enables/disables support of single precision floating point implementation. */
#endif

#define SWLIBS_SUPPORTED_IMPLEMENTATION {SWLIBS_SUPPORT_F32,SWLIBS_SUPPORT_F16,SWLIBS_SUPPORT_FLT,0,0,0,0,0,0} /**< Array of supported implementations. */

/******************************************************************************
* Selection of default implementation
******************************************************************************/
#ifndef SWLIBS_DEFAULT_IMPLEMENTATION
  #define SWLIBS_DEFAULT_IMPLEMENTATION SWLIBS_DEFAULT_IMPLEMENTATION_FLT    /**< Selection of default implementation - single precision floating-point. */
  #ifndef SWLIBS_DEFAULT_IMPLEMENTATION
    #error "Please select the default implementation in the file SWLIBS_Config.h."
  #else
    #if((SWLIBS_DEFAULT_IMPLEMENTATION != SWLIBS_DEFAULT_IMPLEMENTATION_F32)&&(SWLIBS_DEFAULT_IMPLEMENTATION != SWLIBS_DEFAULT_IMPLEMENTATION_F16)&&(SWLIBS_DEFAULT_IMPLEMENTATION != SWLIBS_DEFAULT_IMPLEMENTATION_FLT))
      #error "Please select the default implementation in the file SWLIBS_Config.h."
    #endif
  #endif /* SWLIBS_DEFAULT_IMPLEMENTATION */
#endif /* SWLIBS_DEFAULT_IMPLEMENTATION */


#endif /* SWLIBS_CONFIG_H */
