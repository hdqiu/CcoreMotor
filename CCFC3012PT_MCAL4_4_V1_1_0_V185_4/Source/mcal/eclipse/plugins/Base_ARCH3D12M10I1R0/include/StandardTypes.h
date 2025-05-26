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
*   @file    StandardTypes.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of MCAL driver.
*
*   @addtogroup STANDARD
*   @{
*/

#ifndef StandardTypes_H
#define StandardTypes_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Platform_Types.h"
#include "Compiler.h"

#define STANDARD_VENDOR_ID                     176
#define STANDARD_AR_RELEASE_MAJOR_VERSION      4
#define STANDARD_AR_RELEASE_MINOR_VERSION      4
#define STANDARD_AR_RELEASE_REVISION_VERSION   0
#define STANDARD_SW_MAJOR_VERSION              1
#define STANDARD_SW_MINOR_VERSION              0
#define STANDARD_SW_PATCH_VERSION              1

#define STD_HIGH    0x01
#define STD_LOW     0x00
#define STD_ACTIVE  0x01
#define STD_IDLE    0x00
#define STD_ON      0x01
#define STD_OFF     0x00
#define E_NOT_OK    0x01
#define E_OK        0x00
#define E_DISABLE   0x00
#define E_ENABLE    0x01
#define E_TRUE      0x01
#define E_FALSE     0x00

typedef uint8 Std_ReturnType;
typedef struct
{
    VAR(uint16,AUTOMATIC)  vendorID;
    VAR(uint16,AUTOMATIC)  moduleID;
    VAR(uint8,AUTOMATIC)   sw_major_version;
    VAR(uint8,AUTOMATIC)   sw_minor_version;
    VAR(uint8,AUTOMATIC)   sw_patch_version;
} Std_VersionInfoType;

#ifdef __cplusplus
}
#endif
#endif 

