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
*   @file    Sent_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Sent MCAL driver.
*
*   @addtogroup Sent
*   @{
*/


#ifndef Sent_CFG_H_
#define Sent_CFG_H_

#include "Compiler.h"
#include "StandardTypes.h"
#include "Mcal.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SENT_VENDOR_ID                           176
#define SENT_CFG_AR_MAJOR_VER                    4
#define SENT_CFG_AR_MINOR_VER                    4
#define SENT_CFG_AR_PATCH_VER                    0
#define SENT_CFG_SW_MAJOR_VER                    1
#define SENT_CFG_SW_MINOR_VER                    0
#define SENT_CFG_SW_PATCH_VER                    1

/*============================================FILE VERSION CHECKS===================================*/
#if (MCAL_VENDOR_ID != SENT_VENDOR_ID)
    #error " NON-MATCHED DATA : SENT_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != SENT_CFG_AR_MAJOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != SENT_CFG_AR_MINOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != SENT_CFG_AR_PATCH_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != SENT_CFG_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != SENT_CFG_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != SENT_CFG_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER "
#endif


#define SENT_PRECOMPILE_SUPPORT                  (STD_OFF)
#define SENT_DEV_ERROR_DETECT                    (STD_ON)
#define SENT_VERSION_INFO_API                    (STD_ON)
#define SENT_ENABLE_MULTICORE                    (STD_ON)

/* Number of maximum partitions. */
#define SENT_MAX_PARTITIONS                      (6U)
#define SENT_DEFAULT_COREID                      (0U)

#define SENT_0_CH_0                 0x0
#define SENT_0_CH_1                 0x1
#define SENT_0_CH_2                 0x2
#define SENT_0_CH_3                 0x3
#define SENT_0_CH_4                 0x4
#define SENT_0_CH_5                 0x5
#define SENT_0_CH_6                 0x6
#define SENT_0_CH_7                 0x7
#define SENT_0_CH_8                 0x8
#define SENT_0_CH_9                 0x9
#define SENT_0_CH_10                0xa
#define SENT_0_CH_11                0xb
#define SENT_0_CH_12                0xc
#define SENT_1_CH_0                 0x20
#define SENT_1_CH_1                 0x21
#define SENT_1_CH_2                 0x22
#define SENT_1_CH_3                 0x23
#define SENT_1_CH_4                 0x24
#define SENT_1_CH_5                 0x25
#define SENT_1_CH_6                 0x26
#define SENT_1_CH_7                 0x27
#define SENT_1_CH_8                 0x28
#define SENT_1_CH_9                 0x29
#define SENT_1_CH_10                0x2a
#define SENT_1_CH_11                0x2b

#define SentChannelConfiguration_0                             (SentConf_SentChannel_SentChannelConfiguration_0)
#define SentConf_SentChannel_SentChannelConfiguration_0        ((Sent_ChannelType)0U)
#define SentChannelConfiguration_1                             (SentConf_SentChannel_SentChannelConfiguration_1)
#define SentConf_SentChannel_SentChannelConfiguration_1        ((Sent_ChannelType)1U)
#define SentChannelConfiguration_2                             (SentConf_SentChannel_SentChannelConfiguration_2)
#define SentConf_SentChannel_SentChannelConfiguration_2        ((Sent_ChannelType)2U)
#define SentChannelConfiguration_3                             (SentConf_SentChannel_SentChannelConfiguration_3)
#define SentConf_SentChannel_SentChannelConfiguration_3        ((Sent_ChannelType)3U)
#define SentChannelConfiguration_4                             (SentConf_SentChannel_SentChannelConfiguration_4)
#define SentConf_SentChannel_SentChannelConfiguration_4        ((Sent_ChannelType)4U)
#define SentChannelConfiguration_5                             (SentConf_SentChannel_SentChannelConfiguration_5)
#define SentConf_SentChannel_SentChannelConfiguration_5        ((Sent_ChannelType)5U)
#define SentChannelConfiguration_6                             (SentConf_SentChannel_SentChannelConfiguration_6)
#define SentConf_SentChannel_SentChannelConfiguration_6        ((Sent_ChannelType)6U)
#define SentChannelConfiguration_7                             (SentConf_SentChannel_SentChannelConfiguration_7)
#define SentConf_SentChannel_SentChannelConfiguration_7        ((Sent_ChannelType)7U)
#define SentChannelConfiguration_8                             (SentConf_SentChannel_SentChannelConfiguration_8)
#define SentConf_SentChannel_SentChannelConfiguration_8        ((Sent_ChannelType)8U)
#define SentChannelConfiguration_9                             (SentConf_SentChannel_SentChannelConfiguration_9)
#define SentConf_SentChannel_SentChannelConfiguration_9        ((Sent_ChannelType)9U)
#define SentChannelConfiguration_10                            (SentConf_SentChannel_SentChannelConfiguration_10)
#define SentConf_SentChannel_SentChannelConfiguration_10       ((Sent_ChannelType)10U)
#define SentChannelConfiguration_11                            (SentConf_SentChannel_SentChannelConfiguration_11)
#define SentConf_SentChannel_SentChannelConfiguration_11       ((Sent_ChannelType)11U)
#define SentChannelConfiguration_12                            (SentConf_SentChannel_SentChannelConfiguration_12)
#define SentConf_SentChannel_SentChannelConfiguration_12       ((Sent_ChannelType)12U)
#define SentChannelConfiguration_13                            (SentConf_SentChannel_SentChannelConfiguration_13)
#define SentConf_SentChannel_SentChannelConfiguration_13       ((Sent_ChannelType)13U)
#define SentChannelConfiguration_14                            (SentConf_SentChannel_SentChannelConfiguration_14)
#define SentConf_SentChannel_SentChannelConfiguration_14       ((Sent_ChannelType)14U)
#define SentChannelConfiguration_15                            (SentConf_SentChannel_SentChannelConfiguration_15)
#define SentConf_SentChannel_SentChannelConfiguration_15       ((Sent_ChannelType)15U)
#define SentChannelConfiguration_16                            (SentConf_SentChannel_SentChannelConfiguration_16)
#define SentConf_SentChannel_SentChannelConfiguration_16       ((Sent_ChannelType)16U)
#define SentChannelConfiguration_17                            (SentConf_SentChannel_SentChannelConfiguration_17)
#define SentConf_SentChannel_SentChannelConfiguration_17       ((Sent_ChannelType)17U)
#define SentChannelConfiguration_18                            (SentConf_SentChannel_SentChannelConfiguration_18)
#define SentConf_SentChannel_SentChannelConfiguration_18       ((Sent_ChannelType)18U)
#define SentChannelConfiguration_19                            (SentConf_SentChannel_SentChannelConfiguration_19)
#define SentConf_SentChannel_SentChannelConfiguration_19       ((Sent_ChannelType)19U)
#define SentChannelConfiguration_20                            (SentConf_SentChannel_SentChannelConfiguration_20)
#define SentConf_SentChannel_SentChannelConfiguration_20       ((Sent_ChannelType)20U)
#define SentChannelConfiguration_21                            (SentConf_SentChannel_SentChannelConfiguration_21)
#define SentConf_SentChannel_SentChannelConfiguration_21       ((Sent_ChannelType)21U)
#define SentChannelConfiguration_22                            (SentConf_SentChannel_SentChannelConfiguration_22)
#define SentConf_SentChannel_SentChannelConfiguration_22       ((Sent_ChannelType)22U)
#define SentChannelConfiguration_23                            (SentConf_SentChannel_SentChannelConfiguration_23)
#define SentConf_SentChannel_SentChannelConfiguration_23       ((Sent_ChannelType)23U)
#define SentChannelConfiguration_24                            (SentConf_SentChannel_SentChannelConfiguration_24)
#define SentConf_SentChannel_SentChannelConfiguration_24       ((Sent_ChannelType)24U)

#endif /* Sent_CFG_H_ */
