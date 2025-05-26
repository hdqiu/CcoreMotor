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
*   @file    Fls_HAL_Wrapper.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/

#ifndef FLS_HAL_WRAPPER_H
#define FLS_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "status.h"
#include "Fls.h"

#define FLS_HAL_WRA_H_VENDOR_ID                     176
#define FLS_HAL_WRA_H_AR_REL_MAJOR_VER              4
#define FLS_HAL_WRA_H_AR_REL_MINOR_VER              4
#define FLS_HAL_WRA_H_AR_REL_REV_VER                0
#define FLS_HAL_WRA_H_SW_MAJOR_VER                  1
#define FLS_HAL_WRA_H_SW_MINOR_VER                  0
#define FLS_HAL_WRA_H_SW_PATCH_VER                  1

#if (FLS_VENDOR_ID_OUTPUT != FLS_HAL_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_H_VENDOR_ID "
#endif
#if (FLS_AR_REL_MAJOR_VER_OUTPUT != FLS_HAL_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (FLS_AR_REL_MINOR_VER_OUTPUT != FLS_HAL_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_H_AR_REL_MINOR_VER "
#endif
#if (FLS_AR_REL_REVISION_VER_OUTPUT != FLS_HAL_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_H_AR_REL_REV_VER "
#endif
#if (FLS_SW_MAJOR_VERSION_OUTPUT != FLS_HAL_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_H_SW_MAJOR_VER "
#endif
#if (FLS_SW_MINOR_VERSION_OUTPUT != FLS_HAL_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_H_SW_MINOR_VER "
#endif
#if (FLS_SW_PATCH_VERSION_OUTPUT != FLS_HAL_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FLS_HAL_WRA_H_SW_PATCH_VER "
#endif

extern FUNC( Fls_AddressType, FLS_CODE ) Fls_GetSectorStartAddr \
( \
    CONST(Fls_SectorIndex_Type, AUTOMATIC) u32Fls_SectorIndex \
);

extern P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) gFls_ConfigPtr;

extern P2CONST( uint8, FLS_VAR, FLS_APPL_CONST ) gFls_JobDataSrcPtr;

extern P2VAR( uint8, FLS_VAR, FLS_APPL_DATA ) gFls_JobDataDestPtr;

FUNC(status_t, FLS_CODE) Fls_Wrapper_InitController(void);

FUNC(MemIf_JobResultType, FLS_CODE) Fls_Wrapper_EraseController(void);

FUNC(MemIf_JobResultType, FLS_CODE) Fls_Wrapper_WriteController(void);

FUNC(MemIf_JobResultType, FLS_CODE) Fls_Wrapper_ReadController(void);

FUNC(MemIf_JobResultType, FLS_CODE) Fls_Wrapper_CompareController(void);

FUNC(MemIf_JobResultType, FLS_CODE) Fls_Wrapper_BlankCheckController(void);

FUNC(void, FLS_CODE) Fls_Wrapper_CancelController(void);

#ifdef __cplusplus
}
#endif
#endif /* FLS_HAL_WRAPPER_H */
