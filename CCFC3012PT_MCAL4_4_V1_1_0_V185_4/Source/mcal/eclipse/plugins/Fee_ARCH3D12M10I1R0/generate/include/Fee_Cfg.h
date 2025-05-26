[!CODE!][!//
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
*   @file    Fee_cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FEE MCAL driver.
*
*   @addtogroup FEE
*   @{
*/

#ifndef FEE_CFG_H
#define FEE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Fee_Types.h"
[!AUTOSPACING!]

#define FEE_VENDOR_ID_OUTPUT                      176
#define FEE_MODULE_ID_OUTPUT                      92
#define FEE_AR_REL_MAJOR_VER_OUTPUT               4
#define FEE_AR_REL_MINOR_VER_OUTPUT               4
#define FEE_AR_REL_REVISION_VER_OUTPUT            0
#define FEE_SW_MAJOR_VERSION_OUTPUT               1
#define FEE_SW_MINOR_VERSION_OUTPUT               0
#define FEE_SW_PATCH_VERSION_OUTPUT               1

#if (MCAL_VENDOR_ID != FEE_VENDOR_ID_OUTPUT)
    #error " NON-MATCHED DATA : FEE_VENDOR_ID_OUTPUT "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != FEE_AR_REL_MAJOR_VER_OUTPUT)
    #error " NON-MATCHED DATA : FEE_AR_REL_MAJOR_VER_OUTPUT "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != FEE_AR_REL_MINOR_VER_OUTPUT)
    #error " NON-MATCHED DATA : FEE_AR_REL_MINOR_VER_OUTPUT "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != FEE_AR_REL_REVISION_VER_OUTPUT)
    #error " NON-MATCHED DATA : FEE_AR_REL_REVISION_VER_OUTPUT "
#endif
#if (MCAL_SW_MAJOR_VERSION != FEE_SW_MAJOR_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : FEE_SW_MAJOR_VERSION_OUTPUT "
#endif
#if (MCAL_SW_MINOR_VERSION != FEE_SW_MINOR_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : FEE_SW_MINOR_VERSION_OUTPUT "
#endif
#if (MCAL_SW_PATCH_VERSION != FEE_SW_PATCH_VERSION_OUTPUT)
    #error " NON-MATCHED DATA : FEE_SW_PATCH_VERSION_OUTPUT "
#endif

#define FEE_PRECOMPILE_SUPPORT  [!WS "4"!][!//          
[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]

#define FEE_DEV_ERROR_DETECT    [!WS "4"!][!//
[!IF "FeeGeneral/FeeDevErrorDetect = 'true'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]

#define FEE_SETMODE_API_SUPPORTED   [!WS "4"!][!//     
[!IF "FeeGeneral/FeeSetModeSupported = 'true'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]

#define FEE_VERSION_INFO_API    [!WS "4"!][!//     
[!IF "FeeGeneral/FeeVersionInfoApi = 'true'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]      

[!SELECT "as:modconf('Fls')"!][!//
#define FEE_CANCEL_API    [!WS "4"!][!//                        
[!IF "FlsGeneral/FlsCancelApi = 'true'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]
[!ENDSELECT!][!//

#define FEE_VIRTUAL_PAGE_SIZE    [!WS "4"!][!//                
([!"num:i(FeeGeneral/FeeVirtualPageSize)"!]U)

#define FEE_BLOCK_ALWAYS_AVAILABLE     [!WS "4"!][!//             
[!IF "FeeGeneral/FeeBlockAlwaysAvailable = 'true'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]

#define FEE_LEGACY_MODE     [!WS "4"!][!//             
[!IF "FeeGeneral/FeeLegacyMode = 'true'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]

#define FEE_LEGACY_IMM_ERASE_MODE     [!WS "4"!][!//             
[!IF "FeeGeneral/FeeLegacyEraseMode = 'true'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]          

#define FEE_SWAP_FOREIGN_BLOCKS_ENABLED     [!WS "4"!][!//             
[!IF "FeeGeneral/FeeSwapForeignBlocksEnabled = 'true'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]         

#define FEE_MARK_EMPTY_BLOCKS_INVALID     [!WS "4"!][!//             
[!IF "FeeGeneral/FeeMarkEmptyBlocksInvalid = 'true'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]    

#define FEE_BOOTLOADER_CONFIG     [!WS "4"!][!//             
[!IF "FeeGeneral/FeeConfigAssignment = 'BOOTLOADER'"!]
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!]

#define FEE_NVM_JOB_END_NOTIFICATION_DECL    [!WS "4"!][!// 
[!IF "node:exists(FeeGeneral/FeeNvmJobEndNotification)"!]extern void [!"normalize-space(FeeGeneral/FeeNvmJobEndNotification)"!](void);[!ENDIF!]

#define FEE_NVM_JOB_END_NOTIFICATION      [!WS "4"!][!//      
[!IF "node:exists(FeeGeneral/FeeNvmJobEndNotification)"!][!"normalize-space(FeeGeneral/FeeNvmJobEndNotification)"!]();[!ENDIF!]

#define FEE_NVM_JOB_ERROR_NOTIFICATION_DECL    [!WS "4"!][!//     
[!IF "node:exists(FeeGeneral/FeeNvmJobErrorNotification)"!]extern void [!"normalize-space(FeeGeneral/FeeNvmJobErrorNotification)"!](void);[!ENDIF!]

#define FEE_NVM_JOB_ERROR_NOTIFICATION     [!WS "4"!][!//    
[!IF "node:exists(FeeGeneral/FeeNvmJobErrorNotification)"!][!"normalize-space(FeeGeneral/FeeNvmJobErrorNotification)"!]();[!ENDIF!]

#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION_DECL       [!WS "4"!][!//    
[!IF "node:exists(FeeGeneral/FeeClusterFormatNotification)"!]extern void [!"normalize-space(FeeGeneral/FeeClusterFormatNotification)"!](void);[!ENDIF!]

#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION       [!WS "4"!][!//    
[!IF "node:exists(FeeGeneral/FeeClusterFormatNotification)"!][!"normalize-space(FeeGeneral/FeeClusterFormatNotification)"!]();[!ENDIF!]

#define FEE_NUMBER_OF_CLUSTER_GROUPS          [!"num:i(count(FeeClusterGroup/*))"!]U

#define FEE_NUMBER_OF_BLOCKS                  [!"num:i(count(FeeBlockConfiguration/*))"!]U

#define FEE_MAX_NR_OF_BLOCKS        [!//
[!IF "FeeGeneral/FeeSwapForeignBlocksEnabled"!]    [!"node:value(FeeGeneral/FeeMaximumNumberBlocks)"!]U[!ELSE!] (FEE_NUMBER_OF_BLOCKS)[!ENDIF!]

#define FEE_BLOCK_OVERHEAD                    ([!"num:i(ceiling(12 div num:i(FeeGeneral/FeeVirtualPageSize) + 2) * num:i(FeeGeneral/FeeVirtualPageSize))"!]U)

#define FEE_CLUSTER_OVERHEAD                  ([!"num:i(ceiling(16 div num:i(FeeGeneral/FeeVirtualPageSize) + 2) * num:i(FeeGeneral/FeeVirtualPageSize))"!]U)

#define FEE_DATA_BUFFER_SIZE                  ([!"num:i(FeeGeneral/FeeDataBufferSize)"!]U)

#define FEE_ERASED_VALUE                      ([!"num:inttohex(bit:and(as:modconf('Fls')[1]/FlsPublishedInformation/FlsErasedValue,255),2)"!]U)

#define FEE_VALIDATED_VALUE                   ([!"num:inttohex(bit:and(bit:xor(as:modconf('Fls')[1]/FlsPublishedInformation/FlsErasedValue,126),255),2)"!]U)

#define FEE_INVALIDATED_VALUE                 ([!"num:inttohex(bit:and(bit:xor(as:modconf('Fls')[1]/FlsPublishedInformation/FlsErasedValue,231),255),2)"!]U)

[!LOOP "node:order(FeeBlockConfiguration/*,'node:value(./FeeBlockNumber)')"!]
#define FeeConf_FeeBlockConfiguration_[!"node:name(.)"!]     [!"./FeeBlockNumber"!]U
[!ENDLOOP!]

[!LOOP "node:order(FeeBlockConfiguration/*,'node:value(./FeeBlockNumber)')"!][!//
#define FeeConf_[!"node:name(.)"!]       ([!"./FeeBlockNumber"!]U)
[!ENDLOOP!][!//

typedef struct 
{
    P2CONST( Fee_ClusterGroup_Type, FEE_CONST, FEE_APPL_CONST ) Fee_ClusterGroup;
    P2CONST( Fee_BlockConfig_Type, FEE_CONST, FEE_APPL_CONST ) Fee_BlockConfig;  
} Fee_ConfigType;

extern CONST(Fee_ConfigType, FEE_CONST) Fee_Config;

[!ENDCODE!][!//
#ifdef __cplusplus
}
#endif

#endif /* FEE_CFG_H */

