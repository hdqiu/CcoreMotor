/**************************************************************************** 
* 

* Copyright (c) 2023  C*Core -   All Rights Reserved  
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
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    MemIf_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/

#ifndef MEMIF_TYPES_H
#define MEMIF_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcal.h"

#define MEMIF_VENDOR_ID_PLUGIN                      176
#define MEMIF_AR_REL_MAJOR_VER                      4
#define MEMIF_AR_REL_MINOR_VER                      4
#define MEMIF_AR_REL_REVISION_VER                   0
#define MEMIF_SW_MAJOR_VERSION_PLUGIN               1
#define MEMIF_SW_MINOR_VERSION_PLUGIN               0
#define MEMIF_SW_PATCH_VERSION_PLUGIN               1

#if (MCAL_VENDOR_ID != MEMIF_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : MEMIF_VENDOR_ID_PLUGIN "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : MEMIF_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != MEMIF_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : MEMIF_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != MEMIF_AR_REL_REVISION_VER)
    #error " NON-MATCHED DATA : MEMIF_AR_REL_REVISION_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != MEMIF_SW_MAJOR_VERSION_PLUGIN)
    #error " NON-MATCHED DATA : MEMIF_SW_MAJOR_VERSION_PLUGIN "
#endif
#if (MCAL_SW_MINOR_VERSION != MEMIF_SW_MINOR_VERSION_PLUGIN)
    #error " NON-MATCHED DATA : MEMIF_SW_MINOR_VERSION_PLUGIN "
#endif
#if (MCAL_SW_PATCH_VERSION != MEMIF_SW_PATCH_VERSION_PLUGIN)
    #error " NON-MATCHED DATA : MEMIF_SW_PATCH_VERSION_PLUGIN "
#endif

/* Specification of Flash Driver : [SWS_Fls_00308] */
/* Specification of Flash Driver : [SWS_Fls_00248] */
typedef enum
{
    MEMIF_UNINIT = 0,
    MEMIF_IDLE,
    MEMIF_BUSY,
    MEMIF_BUSY_INTERNAL
}MemIf_StatusType;

typedef enum
{
    MEMIF_JOB_OK = 0,
    MEMIF_JOB_FAILED,
    MEMIF_JOB_PENDING,
    MEMIF_JOB_CANCELED,
    MEMIF_BLOCK_INCONSISTENT,
    MEMIF_BLOCK_INVALID
}MemIf_JobResultType;

typedef enum
{
    MEMIF_MODE_SLOW = 0,
    MEMIF_MODE_FAST
}MemIf_ModeType;
/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

/*===========================================VARIABLE DECLARATIONS==================================*/

/*============================================FUNCTION PROTOTYPES===================================*/

#ifdef __cplusplus
}
#endif

#endif /* MEMIF_TYPES_H */

/** @} */

