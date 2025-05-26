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
*   @file    Fls_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

#include "Fls_Cfg.h"
[!AUTOSPACING!]

#define FLS_VENDOR_ID_PLUGIN_CFG_C          176
#define FLS_AR_REL_MAJOR_VER_CFG_C          4
#define FLS_AR_REL_MINOR_VER_CFG_C          4
#define FLS_AR_REL_REVISION_VER_CFG_C       0
#define FLS_SW_MAJOR_VERSION_CFG_C          1
#define FLS_SW_MINOR_VERSION_CFG_C          0
#define FLS_SW_PATCH_VERSION_CFG_C          1

#if (MCAL_VENDOR_ID != FLS_VENDOR_ID_PLUGIN_CFG_C)
    #error " NON-MATCHED DATA : FLS_VENDOR_ID_PLUGIN_CFG_C "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != FLS_AR_REL_MAJOR_VER_CFG_C)
    #error " NON-MATCHED DATA : FLS_AR_REL_MAJOR_VER_CFG_C "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != FLS_AR_REL_MINOR_VER_CFG_C)
    #error " NON-MATCHED DATA : FLS_AR_REL_MINOR_VER_CFG_C "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != FLS_AR_REL_REVISION_VER_CFG_C)
    #error " NON-MATCHED DATA : FLS_AR_REL_REVISION_VER_CFG_C "
#endif
#if (MCAL_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FLS_SW_MAJOR_VERSION_CFG_C "
#endif
#if (MCAL_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FLS_SW_MINOR_VERSION_CFG_C "
#endif
#if (MCAL_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FLS_SW_PATCH_VERSION_CFG_C "
#endif

extern FUNC( void, FLS_CODE ) Fee_JobEndNotification( void );

extern FUNC( void, FLS_CODE ) Fee_JobErrorNotification( void );

VAR(Fls_AddressType, FLS_VAR) gFls_JobAddrIt = 0UL;

VAR(Fls_AddressType, FLS_VAR) gFls_JobAddrEnd = 0UL;

VAR(volatile Fls_SectorIndex_Type, FLS_VAR) gFls_JobSectorIt = 0UL;

VAR(Fls_SectorIndex_Type, FLS_VAR) gFls_JobSectorEnd = 0UL;

VAR(uint8, FLS_VAR) gFls_JobStart = 0U;

VAR(uint32, FLS_VAR) gFls_MaxRead = 0UL;

VAR(uint32, FLS_VAR) gFls_MaxWrite = 0UL;

VAR(MemIf_StatusType, FLS_VAR) gFls_ModuleStatus = MEMIF_UNINIT;

VAR(MemIf_JobResultType, FLS_VAR) gFls_JobResult = MEMIF_JOB_OK;

VAR(Fls_Job_Type, FLS_VAR) gFls_Job = FLS_JOB_ERASE;

VAR(volatile MemIf_JobResultType, FLS_VAR) gFls_LLDJobResult = MEMIF_JOB_OK;

VAR(Fls_LLDJob_Type, FLS_VAR) gFls_LLDJob = FLASH_JOB_NONE;

static CONST(uint8, FLS_CONST) FlsConfig_FlsSectorFlags[[!"num:i(count(FlsConfigSet/*[1]/FlsSectorList/FlsSector/*))"!]] =
{
    [!VAR "FlsLoopIt" = "count(FlsConfigSet/*[1]/FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsConfigSet/*[1]/FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
    [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
    [!VAR "FlsFlag" = "0"!][!//
    [!IF "./FlsSectorEraseAsynch"!][!WS "4"!]FLS_SECTOR_ERASE_ASYNCH[!VAR "FlsFlag" = "1"!][!ENDIF!][!//
    [!IF "./FlsPageWriteAsynch"!][!IF "$FlsFlag = 1"!] | [!ELSE!][!WS "4"!][!VAR "FlsFlag" = "1"!][!ENDIF!]FLS_PAGE_WRITE_ASYNCH[!ENDIF!][!//
    [!IF "$FlsFlag = 0"!][!WS "4"!]0U[!ENDIF!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
};

static CONST(uint16, FLS_CONST) FlsConfig_FlsSectorUnlock[[!"num:i(count(FlsConfigSet/*[1]/FlsSectorList/FlsSector/*))"!]] =
{
    [!INDENT "4"!]
    [!LOOP "FlsConfigSet/*[1]/FlsSectorList/FlsSector/*"!][!//
        [!IF "./FlsPhysicalSectorUnlock = 'true'"!]1U, /* ([!"node:name(.)"!]) */
        [!ELSE!]0U, /* ([!"node:name(.)"!]) */
        [!ENDIF!] 
    [!ENDLOOP!][!//
    [!ENDINDENT!]
};

static CONST(Fls_AddressType, FLS_CONST) FlsConfig_FlsSectorEndAddr[[!"num:i(count(FlsConfigSet/*[1]/FlsSectorList/FlsSector/*))"!]] =
{
    [!LOOP "FlsConfigSet/*[1]/FlsSectorList/FlsSector/*"!][!//
    [!"num:inttohex(FlsSectorSize + FlsSectorStartaddress - 1)"!], /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
};

static CONST(Fls_AddressType, FLS_CONST) FlsConfig_FlsSectorStartAddr[[!"num:i(count(FlsConfigSet/*[1]/FlsSectorList/FlsSector/*))"!]] = 
{
    [!LOOP "FlsConfigSet/*[1]/FlsSectorList/FlsSector/*"!][!//
    [!"num:inttohex(FlsSectorStartaddress)"!], /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
};

static CONST(Fls_LengthType, FLS_CONST) FlsConfig_FlsPageSize[[!"num:i(count(FlsConfigSet/*[1]/FlsSectorList/FlsSector/*))"!]] =
{
    [!LOOP "FlsConfigSet/*[1]/FlsSectorList/FlsSector/*"!][!//
    [!"FlsPageSize"!]UL, /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
};

static CONST(Fls_PhysicalSector_Type, FLS_CONST) FlsConfig_FlsPhysicalSector[[!"num:i(count(FlsConfigSet/*[1]/FlsSectorList/FlsSector/*))"!]] =
{
    [!LOOP "FlsConfigSet/*[1]/FlsSectorList/FlsSector/*"!][!//
    [!VAR "temp_FlsPhysicalSector" = "FlsPhysicalSector"!]
    [!VAR "temp_index" = "num:i(@index)"!]
    [!LOOP "../../FlsSector/*"!]
        [!IF "$temp_index != num:i(@index)"!]
            [!IF "FlsPhysicalSector = $temp_FlsPhysicalSector"!]
                [!ERROR!] There are multiple sectors with FlsPhysicalSector set to[!"FlsPhysicalSector"!] [!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!"FlsPhysicalSector"!], /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
};


CONST(Fls_ConfigType, FLS_CONST) Fls_Config =
{
    (Fls_AcErasePtrType)[!"FlsConfigSet//FlsAcErase"!],/* FlsAcErase */
    (Fls_AcWritePtrType)[!"FlsConfigSet//FlsAcWrite"!],/* FlsAcWrite */
    [!"FlsConfigSet//FlsCallCycle"!],/* FlsCallCycle */
    [!"FlsConfigSet//FlsDefaultMode"!],/* FlsDefaultMode */
    [!"FlsConfigSet//FlsMaxReadFastMode"!]U,/* FlsMaxReadFastMode */
    [!"FlsConfigSet//FlsMaxReadNormalMode"!]U,/* FlsMaxReadNormalMode */
    [!"FlsConfigSet//FlsMaxWriteFastMode"!]U,/* FlsMaxWriteFastMode */
    [!"FlsConfigSet//FlsMaxWriteNormalMode"!]U,/* FlsMaxWriteNormalMode */
    [!WS "4"!][!IF "node:exists(FlsConfigSet//FlsJobEndNotification)"!]&[!"FlsConfigSet//FlsJobEndNotification"!][!ELSE!]NULL_PTR[!ENDIF!],/* FlsEndNotification */
    [!WS "4"!][!IF "node:exists(FlsConfigSet//FlsJobErrorNotification)"!]&[!"FlsConfigSet//FlsJobErrorNotification"!][!ELSE!]NULL_PTR[!ENDIF!],/* FlsErrorNotification */
    [!"num:i(count(FlsConfigSet/*[1]/FlsSectorList/FlsSector/*))"!]U,/* FlsSectorCount */
    &FlsConfig_FlsSectorStartAddr,/* FlsSectorStartAddr */
    &FlsConfig_FlsSectorEndAddr,/* FlsSectorEndAddr */
    &FlsConfig_FlsPhysicalSector,/* FlsPhysicalSector */
    &FlsConfig_FlsSectorFlags,/* FlsSectorFlags */
    &FlsConfig_FlsSectorUnlock,/* FlsSectorUnlock */
    &FlsConfig_FlsPageSize,/* FlsPageSize */
};



#ifdef __cplusplus
}
#endif