/**************************************************************************** 
* 
* Copyright (c) 2022  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Platform_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of MCAL driver.
*
*   @addtogroup PLATFORM
*   @{
*/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

#define PLATFORM_VENDOR_ID                      176
#define PLATFORM_AR_RELEASE_MAJOR_VERSION       4
#define PLATFORM_AR_RELEASE_MINOR_VERSION       4
#define PLATFORM_AR_RELEASE_REVISION_VERSION    0
#define PLATFORM_SW_MAJOR_VERSION               1
#define PLATFORM_SW_MINOR_VERSION               0
#define PLATFORM_SW_PATCH_VERSION               1

#ifndef TRUE
#define TRUE (1u)
#endif
#ifndef FALSE
#define FALSE (0u)
#endif

typedef unsigned char       boolean;
typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef short               int16;
typedef unsigned long       uint32;
typedef unsigned long long  uint64;
typedef signed char         sint8;
typedef signed short        sint16;
typedef signed long         sint32;
typedef signed long long    sint64;
typedef unsigned long       uint8_least;
typedef unsigned long       uint16_least;
typedef unsigned long       uint32_least;
typedef signed long         sint8_least;
typedef signed long         sint16_least;
typedef signed long         sint32_least;
typedef float               float32;
typedef double              float64;

#ifdef __cplusplus
}
#endif
#endif 
