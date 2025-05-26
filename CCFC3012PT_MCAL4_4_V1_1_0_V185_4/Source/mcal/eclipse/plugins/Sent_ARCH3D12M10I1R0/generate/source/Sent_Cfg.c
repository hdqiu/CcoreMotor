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
*   @file    Sent_Cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Sent MCAL driver.
*
*   @addtogroup Sent
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Sent.h"
#include "Sent_Cfg.h"

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

[!VAR "AlreadyParsedNotification"!][!ENDVAR!][!//
[!LOOP "SentChannelConfigSet/SentChannelConfiguration/*/SentNotification"!][!//
[!IF "(. != 'NULL_PTR') and (. != 'NULL')"!][!//
[!IF "contains($AlreadyParsedNotification, concat(.,'|')) = false()"!][!//
extern void [!"."!](Sent_ChannelType channel, srx_callback_type_t type);
[!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,.,'|')"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!MACRO "GetCoreID"!][!//
[!NOCODE!][!//
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!][!//
    [!VAR "ModuEcucPartitionRef" = "string(SentChannelEcucPartitionRef)"!][!//
    [!IF "not(node:refexists(SentChannelEcucPartitionRef))"!][!//
        [!VAR "CoreID" = "num:i(ecu:get('MCAL.DEFAULT.COREID'))"!][!//
    [!ELSE!][!//
        [!VAR "OsApplication_cnt" = "num:i(count(as:modconf('Os')[1]/OsApplication/*))"!][!//
        [!IF "$OsApplication_cnt = num:i(0)"!][!//
            [!ERROR!]ASPath:/Os/Os/OsApplication is not configured [!ENDERROR!][!//
        [!ELSE!][!//
            [!FOR "n" = "0" TO "num:i($OsApplication_cnt)-1"!][!//
                [!VAR "OsEcucPartitionRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!]
                [!IF "text:match($OsEcucPartitionRef,$ModuEcucPartitionRef)"!]
                    [!VAR "EcucPartitionRefMatch_cnt" = "num:i($EcucPartitionRefMatch_cnt)+num:i(1)"!]
                    [!IF "not(node:refexists(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1]))"!]
                        [!VAR "OsApplicationCoreRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!]
                        [!ERROR!]  [!"string(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])"!] is not configured [!ENDERROR!]
                    [!ELSE!]
                        [!VAR "CoreID" = "node:ref(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])/EcucCoreId"!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDFOR!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "$EcucPartitionRefMatch_cnt = num:i(0)"!][!//
        [!VAR "CoreID" = "num:i(ecu:get('MCAL.DEFAULT.COREID'))"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
 [!"$CoreID"!]
[!ENDMACRO!]
[!VAR "MaxChannelNums" = "num:i(count(SentChannelConfigSet/SentChannelConfiguration/*))"!][!//
#if (SENT_ENABLE_MULTICORE == STD_ON)
static CONST(Sent_CoreMapItemType, SENT_CONST) Sent_CoreMap[[!"$MaxChannelNums"!]] =
{
[!FOR "x" = "0" TO "num:i(count(SentChannelConfigSet/SentChannelConfiguration/*))"!][!//
[!SELECT "SentChannelConfigSet/SentChannelConfiguration/*/SentChannelId[.=$x]/.."!][!//
[!VAR "u8ChannelID" = "num:i(./SentChannelId)"!][!//
    {
        .u8HwChannel = [!"$u8ChannelID"!],
        .u8CoreId =[!CALL "GetCoreID"!]    },
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
#endif

static CONST(Sent_ChannelCfgtype, SENT_CONST) Sent_InitChannel[[!"$MaxChannelNums"!]] =
{
[!FOR "x" = "0" TO "num:i(count(SentChannelConfigSet/SentChannelConfiguration/*))"!][!//
[!SELECT "SentChannelConfigSet/SentChannelConfiguration/*/SentChannelId[.=$x]/.."!][!//
    {
        .u8ChannelId = (uint8)([!"SentHwChannel"!]),
        .u8TickDuration = (uint8)([!"SentTickDuration"!]),
        .inputFilter = SRX_[!"SentChanFilterDepth"!],
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_[!"SentDiagConfiguration/SentIdleCount"!],
            .calibVar = SRX_[!"SentDiagConfiguration/SentValidPulseRange"!],
            .diagPulse = SRX_[!"SentDiagConfiguration/SentDiagPulseCheck"!],
            .pausePulse = [!IF "SentDiagConfiguration/SentPausePulseEnable"!]SRX_PAUSE_PULSE_ENABLED[!ELSE!]SRX_PAUSE_PULSE_DISABLED[!ENDIF!],
            .succesiveCal = SRX_SUCC_[!"SentDiagConfiguration/SentSuccesiveCal"!]
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)[!"SentDataLength"!]u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_F[!"SentCRCInclude"!],
            .disableCrcCheck = SRX_F[!"SentCRCCheck"!],
            .crcType = SRX_[!"SentFCRCMode"!]
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_[!"SentSCRCMode"!],
        },
        .pfNotification = (Sent_NotificationFunc)([!IF "node:exists(SentNotification)"!][!IF "(SentNotification != '') and (SentNotification != 'NULL_PTR') and (SentNotification != 'NULL')"!]&[!"SentNotification"!][!ELSE!]NULL_PTR[!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!])  /* Channel notification */
    },
[!ENDSELECT!][!//
[!ENDFOR!][!//
};

[!CODE!][!//
CONST(Sent_ConfigType, SENT_CONST)SentChannelConfigSet =
{
    .u8MaxHwChannels = (uint8)[!"$MaxChannelNums"!]U,
    .u8TimestampPrescaler = (uint8)[!"SentGeneral/SentTimestampPrescaler"!]U,
    .u32SentClkFreq = (uint32)[!"(num:i(node:value(node:ref(SentGeneral/SentClockReference)/McuClockReferencePointFrequency)))"!]U,
#if (SENT_ENABLE_MULTICORE == STD_ON)
    .pCoreMap = Sent_CoreMap,
#endif
    .pChanCfgPtr = Sent_InitChannel,
};
[!ENDCODE!]
#ifdef __cplusplus
}
#endif
