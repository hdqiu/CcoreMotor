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

static CONST(Fee_Cluster_Type, FEE_CONST) Fee_FeeClusterGroup_0[2] =
{
    /* FeeCluster_0 */
    {
        229376U,
        65536U
    },    /* FeeCluster_1 */
    {
        294912U,
        65536U
    }
};
static CONST(Fee_Cluster_Type, FEE_CONST) Fee_FeeClusterGroup_1[2] =
{
    /* FeeCluster_0 */
    {
        360448U,
        65536U
    },    /* FeeCluster_1 */
    {
        425984U,
        65536U
    }
};

static CONST(Fee_ClusterGroup_Type, FEE_CONST) Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS] =
{
    
                /* FeeClusterGroup_0 */
    {
        Fee_FeeClusterGroup_0, /* Cluster name set */
        2U, /* Number of the clusters */
        128U /* Size of the reserved area */        
    },
    
                /* FeeClusterGroup_1 */
    {
        Fee_FeeClusterGroup_1, /* Cluster name set */
        2U, /* Number of the clusters */
        128U /* Size of the reserved area */        
    }
};

static CONST(Fee_BlockConfig_Type, FEE_CONST) Fee_BlockConfig[FEE_NUMBER_OF_BLOCKS] =
{
    /* FeeBlockConfiguration_0 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_0,
        32U,
        0U,
        (boolean)TRUE,
        #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },    /* FeeBlockConfiguration_1 */
    {
        FeeConf_FeeBlockConfiguration_FeeBlockConfiguration_1,
        32U,
        1U,
        (boolean)TRUE,
        #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    }
};

CONST(Fee_ConfigType, FEE_CONST) Fee_Config = 
{
    Fee_ClrGrps,
    Fee_BlockConfig
};



#ifdef __cplusplus
}
#endif
