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
*   @file    Fee_cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FEE MCAL driver.
*
*   @addtogroup FEE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Fee.h"
[!AUTOSPACING!]

#define FEE_VENDOR_ID_PLUGIN_CFG_C          176
#define FEE_AR_REL_MAJOR_VER_CFG_C          4
#define FEE_AR_REL_MINOR_VER_CFG_C          4
#define FEE_AR_REL_REVISION_VER_CFG_C       0
#define FEE_SW_MAJOR_VERSION_CFG_C          1
#define FEE_SW_MINOR_VERSION_CFG_C          0
#define FEE_SW_PATCH_VERSION_CFG_C          1

#if (MCAL_VENDOR_ID != FEE_VENDOR_ID_PLUGIN_CFG_C)
    #error " NON-MATCHED DATA : FEE_VENDOR_ID_PLUGIN_CFG_C "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != FEE_AR_REL_MAJOR_VER_CFG_C)
    #error " NON-MATCHED DATA : FEE_AR_REL_MAJOR_VER_CFG_C "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != FEE_AR_REL_MINOR_VER_CFG_C)
    #error " NON-MATCHED DATA : FEE_AR_REL_MINOR_VER_CFG_C "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != FEE_AR_REL_REVISION_VER_CFG_C)
    #error " NON-MATCHED DATA : FEE_AR_REL_REVISION_VER_CFG_C "
#endif
#if (MCAL_SW_MAJOR_VERSION != FEE_SW_MAJOR_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FEE_SW_MAJOR_VERSION_CFG_C "
#endif
#if (MCAL_SW_MINOR_VERSION != FEE_SW_MINOR_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FEE_SW_MINOR_VERSION_CFG_C "
#endif
#if (MCAL_SW_PATCH_VERSION != FEE_SW_PATCH_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FEE_SW_PATCH_VERSION_CFG_C "
#endif

[!VAR "FeeVPS" = "num:i(FeeGeneral/FeeVirtualPageSize)"!]
[!VAR "FeeVirtualPageSize" = "num:i(FeeGeneral/FeeVirtualPageSize)"!][!//
[!VAR "FeeBlockOverhead" = "num:i(ceiling(12 div $FeeVirtualPageSize + 2) * $FeeVirtualPageSize)"!][!//
[!VAR "FeeClsOverhead" = "num:i(ceiling(16 div $FeeVirtualPageSize + 2) * $FeeVirtualPageSize)"!][!//
[!LOOP "FeeClusterGroup/*"!][!//
static CONST(Fee_Cluster_Type, FEE_CONST) Fee_[!"node:name(.)"!][[!"num:i(count(FeeCluster/*))"!]] =
{
[!VAR "FeeSmallestClusterSize" = "2147483647"!][!//
[!VAR "FeeLoopIt" = "count(FeeCluster/*)"!][!//
[!LOOP "FeeCluster/*"!][!//
[!VAR "FeeLoopIt" = "$FeeLoopIt - 1"!][!//
[!VAR "FeeClusterSize" = "0"!][!//
[!LOOP "FeeSector/*"!][!//
[!VAR "FeeClusterSize" = "$FeeClusterSize + num:i(node:ref(./FeeSectorRef)/FlsSectorSize) * [!//
                                        num:i(node:ref(./FeeSectorRef)/FlsNumberOfSectors)"!][!//
[!ENDLOOP!][!//
    /* [!"node:name(.)"!] */
    {
        [!"num:i(node:ref(FeeSector/*[FeeSectorIndex = 0]/FeeSectorRef)/FlsSectorStartaddress)"!]U,
        [!"num:i($FeeClusterSize)"!]U
    }[!IF "$FeeLoopIt != 0"!],[!ENDIF!]
[!IF "$FeeClusterSize < $FeeSmallestClusterSize"!][!//
[!VAR "FeeSmallestClusterSize" = "$FeeClusterSize"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

};
[!VAR "FeeAvailClusterSize" = "$FeeSmallestClusterSize - $FeeClsOverhead - $FeeBlockOverhead"!][!//
[!VAR "FeePrefilledClusterSize" = "0"!][!//
[!LOOP "./FeeBlockConfiguration/*[node:name(node:ref(FeeClusterGroupRef)) = node:current()/@name]"!][!//
[!VAR "FeeBlockSize" = "num:i(ceiling(./FeeBlockSize div $FeeVirtualPageSize) * $FeeVirtualPageSize + $FeeBlockOverhead)"!][!//
[!VAR "FeeAvailClusterSize" = "$FeeAvailClusterSize - $FeeBlockSize"!][!//
[!IF "$FeeBlockSize > $FeePrefilledClusterSize"!][!//
[!VAR "FeePrefilledClusterSize" = "$FeeBlockSize"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//

static CONST(Fee_ClusterGroup_Type, FEE_CONST) Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS] =
{
[!VAR "FeeLoopIt" = "count(FeeClusterGroup/*)"!]
[!LOOP "FeeClusterGroup/*"!]
    [!VAR "FeeLoopIt" = "$FeeLoopIt - 1"!]
    [!// Compute the size of the reserved area (immediate block headers and aligned data)
    [!VAR "FeeReservedSize" = "0"!][!//
    [!LOOP "../../FeeBlockConfiguration/*[node:name(node:ref(FeeClusterGroupRef)) = node:current()/@name]"!]
        [!IF "./FeeImmediateData"!]
            [!VAR "FeeReservedSize" = "$FeeReservedSize + $FeeBlockOverhead + [!//
                             num:i( ceiling( ./FeeBlockSize div $FeeVPS ) * $FeeVPS )"!]
        [!ENDIF!]
    [!ENDLOOP!]     
    /* [!"node:name(.)"!] */
    {
        Fee_[!"node:name(.)"!], /* Cluster name set */
        [!"num:i(count(./FeeCluster/*))"!]U, /* Number of the clusters */
        [!"num:i( $FeeReservedSize )"!]U /* Size of the reserved area */        
    }[!IF "$FeeLoopIt != 0"!],[!ENDIF!][!//

[!ENDLOOP!]
};

static CONST(Fee_BlockConfig_Type, FEE_CONST) Fee_BlockConfig[FEE_NUMBER_OF_BLOCKS] =
{
[!VAR "FeeLoopIt" = "count(FeeBlockConfiguration/*)"!][!//
[!LOOP "node:order(FeeBlockConfiguration/*,'node:value(./FeeBlockNumber)')"!][!//
    /* [!"node:name(.)"!] */
    {
        FeeConf_FeeBlockConfiguration_[!"node:name(.)"!],
        [!"./FeeBlockSize"!]U,
        [!"node:ref(./FeeClusterGroupRef)/@index"!]U,
        (boolean) [!IF "./FeeImmediateData"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_[!"node:value(./FeeBlockAssignment)"!] /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    }[!VAR "FeeLoopIt" = "$FeeLoopIt - 1"!][!IF "$FeeLoopIt != 0"!],[!ENDIF!]
[!ENDLOOP!][!//

};

CONST(Fee_ConfigType, FEE_CONST) Fee_Config = 
{
    Fee_ClrGrps,
    Fee_BlockConfig
};


[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif
