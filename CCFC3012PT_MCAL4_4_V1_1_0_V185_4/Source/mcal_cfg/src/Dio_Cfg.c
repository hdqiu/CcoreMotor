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
 *   @file    Dio_Cfg.h
 *   @version 1.0.1
 *
 *   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
 *   @details Autosar layer of Dio MCAL driver.
 *
 *   @addtogroup Dio
 *   @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Dio_Cfg.h"
/*=============================SOURCE FILE VERSION INFORMATION==================================*/
#define DIO_CFG_C_VENDOR_ID 176
#define DIO_CFG_C_MAJOR_VERSION 4
#define DIO_CFG_C_MINOR_VERSION 4
#define DIO_CFG_C_patch_VERSION 0
#define DIO_CFG_C_SW_MAJOR_VERSION 1
#define DIO_CFG_C_SW_MINOR_VERSION 0
#define DIO_CFG_C_SW_PATCH_VERSION 1
/*====================================FILE VERSION CHECKS=======================================*/
#if (DIO_CFG_C_VENDOR_ID != DIO_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_CFG_C_VENDOR_ID "
#endif
#if (DIO_CFG_C_MAJOR_VERSION != DIO_CFG_H_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_MAJOR_VERSION "
#endif
#if (DIO_CFG_C_MINOR_VERSION != DIO_CFG_H_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_MINOR_VERSION "
#endif
#if (DIO_CFG_C_patch_VERSION != DIO_CFG_H_patch_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_patch_VERSION "
#endif
#if (DIO_CFG_C_SW_MAJOR_VERSION != DIO_CFG_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_SW_MAJOR_VERSION "
#endif
#if (DIO_CFG_C_SW_MINOR_VERSION != DIO_CFG_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_SW_MINOR_VERSION "
#endif
#if (DIO_CFG_C_SW_PATCH_VERSION != DIO_CFG_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_C_SW_PATCH_VERSION "
#endif
/*=========================================CONSTANTS============================================*/

CONST(Dio_ChannelGroupType, DIO_CONST) DioConf_aChannelGroupList[3] = 
{
    {(Dio_PortLevelType)0x0000e000UL , (uint8)0x0d, DioConf_DioPort_DioPort_A, DioConf_DioPort_Group_DioPort_A},
    {(Dio_PortLevelType)0x0000fc00UL , (uint8)0x0a, DioConf_DioPort_DioPort_C, DioConf_DioPort_Group_DioPort_C},
    {(Dio_PortLevelType)0x000003ffUL , (uint8)0x00, DioConf_DioPort_DioPort_C, DioConf_DioPort_Group_DioPort_C}
};


P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) u32ChannelGroupsListForEachPartition[6][3] =
{
    {
    &DioConf_aChannelGroupList[0],
    &DioConf_aChannelGroupList[1],
    &DioConf_aChannelGroupList[2]
    },
    {
    &DioConf_aChannelGroupList[0],
    &DioConf_aChannelGroupList[1],
    &DioConf_aChannelGroupList[2]
    },
    {
    &DioConf_aChannelGroupList[0],
    &DioConf_aChannelGroupList[1],
    &DioConf_aChannelGroupList[2]
    },
    {
    &DioConf_aChannelGroupList[0],
    &DioConf_aChannelGroupList[1],
    &DioConf_aChannelGroupList[2]
    },
    {
    &DioConf_aChannelGroupList[0],
    &DioConf_aChannelGroupList[1],
    &DioConf_aChannelGroupList[2]
    },
    {
    &DioConf_aChannelGroupList[0],
    &DioConf_aChannelGroupList[1],
    &DioConf_aChannelGroupList[2]
    }
};

CONST(Dio_PortLevelType, DIO_CONST) Dio_ReadAvailablePins[DIO_NUM_PORTS_U16] =
{
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xff80,
    (Dio_PortLevelType)0x0000,
    (Dio_PortLevelType)0x0000
};


CONST(Dio_PortLevelType, DIO_CONST) Dio_WriteAvailablePins[DIO_NUM_PORTS_U16] =
{
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0xc07f,
    (Dio_PortLevelType)0xffff,
    (Dio_PortLevelType)0x8000
};






static CONST(pu32Dio_PortToPartitionMap, DIO_CONST) u32PortToPartitionMap[DIO_NUM_PORTS_U16] =
{


    {
        .nDioPortId = 0,
        .coreid =  63

    },


    {
        .nDioPortId = 1,
        .coreid =  63

    },


    {
        .nDioPortId = 2,
        .coreid =  63

    },


    {
        .nDioPortId = 7,
        .coreid =  63

    },


    {
        .nDioPortId = 3,
        .coreid =  63

    },


    {
        .nDioPortId = 4,
        .coreid =  63

    },


    {
        .nDioPortId = 5,
        .coreid =  63

    },


    {
        .nDioPortId = 6,
        .coreid =  63

    },


    {
        .nDioPortId = 8,
        .coreid =  63

    },


    {
        .nDioPortId = 9,
        .coreid =  63

    },


    {
        .nDioPortId = 10,
        .coreid =  63

    },


    {
        .nDioPortId = 11,
        .coreid =  63

    },


    {
        .nDioPortId = 12,
        .coreid =  63

    },


    {
        .nDioPortId = 13,
        .coreid =  63

    },


    {
        .nDioPortId = 16,
        .coreid =  63

    },


    {
        .nDioPortId = 17,
        .coreid =  63

    },


    {
        .nDioPortId = 18,
        .coreid =  63

    },


    {
        .nDioPortId = 21,
        .coreid =  63

    },


};

static CONST(pu32Dio_ChannelToPartitionMap, DIO_CONST) u32ChannelToPartitionMap[DIO_NUM_CHANNELS_U16] =
{
                                            
        {
            .nDioChannelId = 0,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 1,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 2,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 25,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 32,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 33,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 34,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 35,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 36,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 37,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 38,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 39,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 40,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 41,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 42,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 43,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 44,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 45,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 46,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 47,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 112,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 114,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 115,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 116,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 118,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 119,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 120,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 121,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 122,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 123,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 126,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 127,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 48,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 64,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 81,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 96,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 136,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 137,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 144,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 145,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 175,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 176,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 192,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 208,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 257,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 258,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 283,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 289,
            .coreid =  1
        },                                                
        {
            .nDioChannelId = 336,
            .coreid =  1
        },                                        
        {
            .nDioChannelId = 337,
            .coreid =  1
        },    
};
CONST(Dio_ConfigType, DIO_CONST) Dio_ConfigPC=
{
    .u8NumChannelGroups = (uint8)0x3,
    .pChannelGroupList = &DioConf_aChannelGroupList[0],    
    .Dio_u32ChannelToPartitionMap = u32ChannelToPartitionMap,
    .Dio_u32PortToPartitionMap = u32PortToPartitionMap
};
#ifdef __cplusplus
}
#endif
