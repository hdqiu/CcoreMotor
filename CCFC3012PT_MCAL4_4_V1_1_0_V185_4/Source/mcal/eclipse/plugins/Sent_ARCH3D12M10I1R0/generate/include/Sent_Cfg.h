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

[!AUTOSPACING!]

#define SENT_PRECOMPILE_SUPPORT                  ([!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime') and (variant:size() <= 1)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define SENT_DEV_ERROR_DETECT                    ([!IF "SentGeneral/SentDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define SENT_VERSION_INFO_API                    ([!IF "SentGeneral/SentVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define SENT_ENABLE_MULTICORE                    ([!IF "SentGeneral/SentMulticoreSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!NOCODE!][!//
[!VAR "maxPartition" = "num:i(0)"!][!//
[!IF "node:value(SentGeneral/SentMulticoreSupport) = 'true'"!][!//
[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!][!//
    [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!// 
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$maxPartition = 0"!][!VAR "maxPartition" = "num:i(1)"!][!ENDIF!][!//
[!ENDNOCODE!][!//
[!CODE!][!//
/* Number of maximum partitions. */
#define SENT_MAX_PARTITIONS                      ([!"num:i($maxPartition)"!]U)
#define SENT_DEFAULT_COREID                      ([!"num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]U)
[!ENDCODE!][!//

[!NOCODE!][!//
    [!VAR "channelsNum"="num:i(count(ecu:list('Sent.SentChannelConfigSet.SentChannelConfiguration.SentHwChannel')))"!][!//
    [!FOR "MacModuleId" = "0" TO "$channelsNum"!]
        [!VAR "channelName"="(ecu:list('Sent.SentChannelConfigSet.SentChannelConfiguration.SentHwChannel'))[num:i($MacModuleId)]"!]
        [!IF "contains(substring-before($channelName, '_CH'),'SENT')"!]
            [!VAR "module" = "num:i(substring($channelName,6,1))"!]
            [!VAR "channel"="num:i(substring-after($channelName, '_CH_'))"!]
            [!VAR "handle"="num:inttohex(num:add(num:mul($module, 32),$channel))"!]
[!CODE!]
[!IF "$channel >= 10"!]
#define SENT_[!"$module"!]_CH_[!"$channel"!]                [!"$handle"!]
[!ELSE!]#define SENT_[!"$module"!]_CH_[!"$channel"!]                 [!"$handle"!]
[!ENDIF!]
[!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDNOCODE!]

[!INDENT "0"!]
[!NOCODE!]
    [!VAR "OuterLoopCounter" = "0"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!LOOP "SentChannelConfigSet/SentChannelConfiguration/*"!]
        [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!VAR "Matchcounter" = "0"!]
        [!VAR "Name" = "node:name(.)"!]
        [!LOOP "../../../*/SentChannelConfiguration/*"!]
            [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
            [!IF "($Name = node:name(.))"!]
                    [!VAR "Matchcounter" = "$Matchcounter + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$Matchcounter = 1"!]
                [!CODE!]
[!IF " @index>= 10"!]
#define [!"node:name(.)"!]                            (SentConf_SentChannel_[!"node:name(.)"!])[!CR!]
#define SentConf_SentChannel_[!"node:name(.)"!]       ((Sent_ChannelType)[!"@index"!]U)[!CR!]
[!ELSE!]#define [!"node:name(.)"!]                             (SentConf_SentChannel_[!"node:name(.)"!])[!CR!]
#define SentConf_SentChannel_[!"node:name(.)"!]        ((Sent_ChannelType)[!"@index"!]U)[!CR!]
[!ENDIF!]
                [!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDINDENT!][!//

#endif /* Sent_CFG_H_ */
