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
*   @file    Pwm_Cfg.c
*   @version
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm_Cfg.h"

#define PWM_CFG_C_VENDOR_ID                      176
#define PWM_CFG_C_AR_REL_MAJOR_VER               4
#define PWM_CFG_C_AR_REL_MINOR_VER               4
#define PWM_CFG_C_AR_REL_REV_VER                 0
#define PWM_CFG_C_SW_MAJOR_VER                   1
#define PWM_CFG_C_SW_MINOR_VER                   0
#define PWM_CFG_C_SW_PATCH_VER                   1

#if (PWM_CFG_C_VENDOR_ID != MCAL_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_CFG_C_VENDOR_ID "
#endif
#if (PWM_CFG_C_AR_REL_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_CFG_C_AR_REL_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_AR_REL_MINOR_VER "
#endif
#if (PWM_CFG_C_AR_REL_REV_VER != MCAL_AR_RELEASE_REVISION_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_AR_REL_REV_VER "
#endif
#if (PWM_CFG_C_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_SW_MAJOR_VER "
#endif
#if (PWM_CFG_C_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_SW_MINOR_VER "
#endif
#if (PWM_CFG_C_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : PWM_CFG_C_SW_PATCH_VER "
#endif

static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_TomNotifyTable[PWM_TOM_MAX * PWM_TOM_CHANNEL_MAX];
static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_AtomNotifyTable[PWM_ATOM_MAX * PWM_ATOM_CHANNEL_MAX];
static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_EmiosNotifyTable[PWM_EMIOS_MAX * PWM_EMIOS_CHANNEL_MAX];
static CONST(Pwm_CoreMapItemType, PWM_CONST)     Pwm_CoreMap[PWM_CHANNEL_NUM];
[!//
[!MACRO "GetCoreID"!][!//
[!NOCODE!][!//
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRef_cnt" = "num:i(count(PwmChannelEcucPartitionRef/*))"!][!//
    [!IF "$EcucPartitionRef_cnt = num:i(0)"!][!//
        [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!//
    [!ELSE!][!//
        [!FOR "i" = "0" TO "num:i($EcucPartitionRef_cnt)-1"!][!//
            [!VAR "ModuEcucPartitionRef" = "string(PwmChannelEcucPartitionRef/*[$i+1])"!][!//
            [!IF "not(node:refexists(PwmChannelEcucPartitionRef/*[$i+1]))"!][!//
                [!ERROR!]  Node [!"$ModuEcucPartitionRef"!] not found [!ENDERROR!]
            [!ELSE!][!//
                [!VAR "OsApplication_cnt" = "num:i(count(as:modconf('Os')[1]/OsApplication/*))"!][!//
                [!IF "$OsApplication_cnt = num:i(0)"!][!//
                    [!ERROR!]  ASPath:/Os/Os/OsApplication is not configured [!ENDERROR!]
                [!ELSE!][!//
                    [!FOR "n" = "0" TO "num:i($OsApplication_cnt)-1"!][!//
                        [!VAR "OsEcucPartitionRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!][!//
                        [!IF "text:match($OsEcucPartitionRef,$ModuEcucPartitionRef)"!][!//
                            [!VAR "EcucPartitionRefMatch_cnt" = "num:i($EcucPartitionRefMatch_cnt)+num:i(1)"!][!//
                            [!IF "not(node:refexists(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1]))"!][!//
                                [!VAR "OsApplicationCoreRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!][!//
                                [!ERROR!]  [!"string(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])"!] is not configured [!ENDERROR!]
                            [!ELSE!][!//
                                [!VAR "CoreID_temp" = "node:ref(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])/EcucCoreId"!][!//
                                [!VAR "CoreID" = "bit:or($CoreID,bit:shl(1,$CoreID_temp))"!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDFOR!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDFOR!][!//
        [!IF "$EcucPartitionRefMatch_cnt = num:i(0)"!][!//
            [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$CoreID"!]
[!ENDMACRO!][!//
[!//
[!LOOP "(PwmChannelConfigSet/PwmChannel/*)"!][!//
    [!IF "text:match(./PwmNotification,'NULL')"!][!//
    [!ELSEIF "text:match(./PwmNotification,'null')"!][!//
    [!ELSE!][!//
extern void [!"./PwmNotification"!](void);
    [!ENDIF!][!//
[!ENDLOOP!][!//

[!AUTOSPACING!]
CONST(Pwm_ConfigType, PWM_CONST) Pwm_Config=
{
    [!INDENT "4"!]
    .nNum=PWM_CHANNEL_NUM,
    .pPwm_TomNotifyTable=Pwm_TomNotifyTable,
    .pPwm_AtomNotifyTable=Pwm_AtomNotifyTable,
    .pPwm_EmiosNotifyTable=Pwm_EmiosNotifyTable,
    .pPwm_CoreMap=Pwm_CoreMap,
    .sPwmChConfigs={
    [!ENDINDENT!]
[!FOR "x" = "0" TO "num:i(count(PwmChannelConfigSet/PwmChannel/*))"!][!//
[!SELECT "PwmChannelConfigSet/PwmChannel/*/PwmChannelId[.=$x]/.."!][!//
    [!VAR "nPwmChannelId" = "num:i(./PwmChannelId)"!]
    [!IF "text:match(./PwmHwIP,'GTM_ATOM')"!]
        [!VAR "ePwmHwIP"="'PWM_ATOM'"!]
        [!VAR "nPwmHwIndex"="num:i(substring-after(node:ref(./AtomChannelRef)/../../PwmAtomModule,'ATOM'))"!]
        [!VAR "nPwmChIndex"="num:i(substring-after(node:ref(./AtomChannelRef)/PwmAtomChannel,'Channel_'))"!]
        [!VAR "CMUClock"="node:ref(node:ref(./AtomChannelRef)/CmuClckRef)/CMUClockId"!]
        [!VAR "nGtm4Tout"="node:ref(./AtomChannelRef)/Gtm4Tout"!]
        [!VAR "nToutNum"="node:ref(./AtomChannelRef)/ToutNum"!]
    [!ELSEIF "text:match(./PwmHwIP,'GTM_TOM')"!]
        [!VAR "ePwmHwIP"="'PWM_TOM'"!]
        [!VAR "nPwmHwIndex"="num:i(substring-after(node:ref(./TomChannelRef)/../../PwmTomModule,'TOM'))"!]
        [!VAR "nPwmChIndex"="num:i(substring-after(node:ref(./TomChannelRef)/PwmTomChannel,'Channel_'))"!]
        [!VAR "CmuFXClk"="node:ref(./TomChannelRef)/CmuFXClk"!]
        [!VAR "nGtm4Tout"="node:ref(./TomChannelRef)/Gtm4Tout"!]
        [!VAR "nToutNum"="node:ref(./TomChannelRef)/ToutNum"!]
    [!ELSEIF "text:match(./PwmHwIP,'EMIOS')"!]
        [!VAR "ePwmHwIP"="'PWM_EMIOS'"!]
        [!VAR "nPwmHwIndex"="num:i(substring-after(node:ref(./EmiosChannelRef)/../../PwmEmiosModule,'eMios_'))"!]
        [!IF "$nPwmHwIndex = '0'"!]
        [!VAR "nPwmChIndex"="num:i(substring-after(node:ref(./EmiosChannelRef)/PwmEmiosChannel,'Channel_'))"!]
        [!ELSE!]
        [!VAR "nPwmChIndex"="num:i(substring-after(node:ref(./EmiosChannelRef)/PwmEmiosChannel,'Channel_') - 8)"!]
        [!ENDIF!]
        [!VAR "nPwmeMiosPrescaler"="node:ref(./EmiosChannelRef)/PwmPrescaler"!]
        [!VAR "nPwmeMiosMode"="node:ref(./EmiosChannelRef)/PwmModeSelect"!]
        [!VAR "nPwmeMiosBus"="node:ref(./EmiosChannelRef)/EmiosUnifiedChannelBusSelect"!]
        [!VAR "nIdealDutyCycle"="node:ref(./EmiosChannelRef)/IdealDutyCycle"!]
        [!VAR "nDeadtime"="node:ref(./EmiosChannelRef)/PwmDeadtime"!]
        [!VAR "nOffset"="node:ref(./EmiosChannelRef)/PwmOffset"!]
        [!VAR "nPwmeMiosDmaSwitch"="node:ref(./EmiosChannelRef)/EmiosDmaSwitch"!]
         [!VAR "ntrigTime"="node:ref(./EmiosChannelRef)/PwmtrigTime"!]
    [!ENDIF!]
    [!VAR "nPwmDutycycleDefault" = "num:i(./PwmDutycycleDefault)"!]
    [!VAR "nPwmMaxDutycycle" = "num:i(32768)"!]
    [!IF "text:match(node:value(./PwmHwIP),'EMIOS')"!]
        [!IF "text:match(node:value(node:ref(./EmiosChannelRef)/PwmModeSelect),'EMIOS_UC_MODE_PWM_OPWFMB')"!]
            [!VAR "nPwmPeriodDefault" = "num:i(./PwmPeriodDefault)"!]
            [!IF "$nPwmPeriodDefault > num:i(16777214)"!]
                [!ERROR!]  The period of channel [!"node:ref(./EmiosChannelRef)/PwmEmiosChannel"!] of module [!"node:ref(./EmiosChannelRef)/../../PwmEmiosModule"!] is out of range. The maximum value is 16777214 [!ENDERROR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "$nPwmHwIndex = 0"!]
                [!IF "text:match(node:ref(node:ref(./EmiosChannelRef)/EMIOS0BUSRef)/eMIOSChannelMode,'MCB_UPDOWN')"!]
                    [!VAR "nPwmPeriodOffset" = "num:i(1)"!]
                [!ELSE!]
                    [!VAR "nPwmPeriodOffset" = "num:i(0)"!]
                [!ENDIF!]
                [!IF "text:match(node:value(node:ref(./EmiosChannelRef)/PwmModeSelect),'EMIOS_UC_MODE_PWM_OPWMCB')"!]
                    [!VAR "nPwmPeriodDefault" = "num:i(node:ref(node:ref(./EmiosChannelRef)/EMIOS0BUSRef)/eMIOSChannelperiod)"!]
                    [!IF "num:i($nPwmPeriodDefault div num:i(2) + $nPwmPeriodOffset) > num:i(16777213)"!]
                        [!ERROR!]  The value of the external COUNTER BUS of channel [!"node:ref(./EmiosChannelRef)/PwmEmiosChannel"!] of module [!"node:ref(./EmiosChannelRef)/../../PwmEmiosModule"!] is too large. [!ENDERROR!]
                    [!ENDIF!]
                [!ELSE!]
                    [!VAR "nPwmPeriodDefault" = "num:i(node:ref(node:ref(./EmiosChannelRef)/EMIOS0BUSRef)/eMIOSChannelperiod)"!]
                    [!IF "$nPwmPeriodDefault > num:i(16777213)"!]
                        [!ERROR!]  The value of the external COUNTER BUS of channel [!"node:ref(./EmiosChannelRef)/PwmEmiosChannel"!] of module [!"node:ref(./EmiosChannelRef)/../../PwmEmiosModule"!] is too large. [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ELSEIF "$nPwmHwIndex = 1"!]
                [!IF "text:match(node:ref(node:ref(./EmiosChannelRef)/EMIOS1BUSRef)/eMIOSChannelMode,'MCB_UPDOWN')"!]
                    [!VAR "nPwmPeriodOffset" = "num:i(1)"!]
                [!ELSE!]
                    [!VAR "nPwmPeriodOffset" = "num:i(0)"!]
                [!ENDIF!]
                [!IF "text:match(node:value(node:ref(./EmiosChannelRef)/PwmModeSelect),'EMIOS_UC_MODE_PWM_OPWMCB')"!]
                    [!VAR "nPwmPeriodDefault" = "num:i(node:ref(node:ref(./EmiosChannelRef)/EMIOS1BUSRef)/eMIOSChannelperiod)"!]
                    [!IF "num:i($nPwmPeriodDefault div num:i(2) + $nPwmPeriodOffset) > num:i(16777213)"!]
                        [!ERROR!]  The value of the external COUNTER BUS of channel [!"node:ref(./EmiosChannelRef)/PwmEmiosChannel"!] of module [!"node:ref(./EmiosChannelRef)/../../PwmEmiosModule"!] is too large. [!ENDERROR!]
                    [!ENDIF!]
                [!ELSE!]
                    [!VAR "nPwmPeriodDefault" = "num:i(node:ref(node:ref(./EmiosChannelRef)/EMIOS1BUSRef)/eMIOSChannelperiod)"!]
                    [!IF "$nPwmPeriodDefault > num:i(16777213)"!]
                        [!ERROR!]  The value of the external COUNTER BUS of channel [!"node:ref(./EmiosChannelRef)/PwmEmiosChannel"!] of module [!"node:ref(./EmiosChannelRef)/../../PwmEmiosModule"!] is too large. [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "text:match(node:value(node:ref(./EmiosChannelRef)/PwmModeSelect),'EMIOS_UC_MODE_PWM_OPWMB') and $nOffset > 0"!]
            [!VAR "temp" = "num:i(num:i($nPwmDutycycleDefault * $nPwmPeriodDefault div num:i(32768)) + $nOffset)"!]
            [!IF "$temp >= $nPwmPeriodDefault"!]
                [!ERROR!]  The offset value of [!"node:ref(./EmiosChannelRef)/PwmEmiosChannel"!] of module [!"node:ref(./EmiosChannelRef)/../../PwmEmiosModule"!] is too large. [!ENDERROR!]
            [!ENDIF!]
            [!VAR "nPwmMaxDutycycle" = "num:i((($nPwmPeriodDefault - $nOffset -1) * num:i(32768)) div $nPwmPeriodDefault)"!]
        [!ENDIF!]
    [!ELSEIF "text:match(./PwmHwIP,'GTM_TOM')"!]
        [!VAR "nPwmPeriodDefault" = "num:i(./PwmPeriodDefault)"!]
        [!IF "$nPwmPeriodDefault > num:i(65535)"!]
            [!ERROR!]  The period of channel [!"node:ref(./TomChannelRef)/PwmTomChannel"!] of module [!"node:ref(./TomChannelRef)/../../PwmTomModule"!] is out of range. The maximum value is 65535 [!ENDERROR!]
        [!ENDIF!]
    [!ELSEIF "text:match(./PwmHwIP,'GTM_ATOM')"!]
        [!VAR "nPwmPeriodDefault" = "num:i(./PwmPeriodDefault)"!]
        [!IF "$nPwmPeriodDefault > num:i(16777215)"!]
            [!ERROR!]  The period of channel [!"node:ref(./AtomChannelRef)/PwmAtomChannel"!] of module [!"node:ref(./AtomChannelRef)/../../PwmAtomModule"!] is out of range. The maximum value is 16777215 [!ENDERROR!]
        [!ENDIF!]
    [!ENDIF!]
    [!VAR "ePwmPolarity" = "./PwmPolarity"!]
    [!VAR "ePwmIdleState" = "./PwmIdleState"!]
    [!IF "text:match(node:value(./PwmHwIP),'EMIOS')"!]
        [!IF "text:match(node:value(node:ref(./EmiosChannelRef)/PwmModeSelect),'EMIOS_UC_MODE_PWM_OPWFMB')"!]
            [!VAR "ePwmChannelClass" = "./PwmChannelClass"!]
        [!ELSE!]
            [!VAR "ePwmChannelClass" = "'PWM_FIXED_PERIOD'"!]
        [!ENDIF!]
    [!ELSE!]
        [!VAR "ePwmChannelClass" = "./PwmChannelClass"!]
    [!ENDIF!]
    [!IF "text:match(./PwmNotification,'NULL')"!]
        [!VAR "pfPwmChannelNotification" = "'NULL_PTR'"!]
    [!ELSEIF "text:match(./PwmNotification,'null')"!]
        [!VAR "pfPwmChannelNotification" = "'NULL_PTR'"!]
    [!ELSE!]
        [!VAR "pfPwmChannelNotification" = "concat('&',./PwmNotification)"!]
    [!ENDIF!]
    [!INDENT "8"!]
    {
        [!INDENT "12"!]
        .nPwmChannelId=[!"$nPwmChannelId"!],
        .ePwmHwIP=[!"$ePwmHwIP"!],
        .sHwConfig={
            [!INDENT "16"!]
            .nPwmHwIndex=[!"$nPwmHwIndex"!],
            .nPwmChIndex=[!"$nPwmChIndex"!]
            [!ENDINDENT!]
        },
        .nPwmPeriodDefault=[!"$nPwmPeriodDefault"!],
        .nPwmDutycycleDefault=[!"$nPwmDutycycleDefault"!],
        .ePwmChannelClass=[!"$ePwmChannelClass"!],
        .ePwmPolarity=[!"$ePwmPolarity"!],
        .ePwmIdleState=[!"$ePwmIdleState"!],
        .pfPwmChannelNotification=[!"$pfPwmChannelNotification"!],
        [!IF "$ePwmHwIP = 'PWM_ATOM'"!]
            .nGtm4Tout=[!"$nGtm4Tout"!],
            .nToutNum=[!"$nToutNum"!],
            .sCmuClk={
                [!INDENT "16"!]
                .ATOM_ClkSrc={
                    [!INDENT "20"!]
                    .ClkSrc=[!"$CMUClock"!],
                    [!ENDINDENT!]
                }
                [!ENDINDENT!]
            },
        [!ENDIF!]
        [!IF "$ePwmHwIP = 'PWM_TOM'"!]
            .nGtm4Tout=[!"$nGtm4Tout"!],
            .nToutNum=[!"$nToutNum"!],
            .sCmuClk={
                [!INDENT "16"!]
                .TOM_ClkSrc={
                    [!INDENT "20"!]
                    .ClkSrc=[!"$CmuFXClk"!],
                    [!ENDINDENT!]
                }
                [!ENDINDENT!]
            },
        [!ENDIF!]
        [!IF "$ePwmHwIP = 'PWM_EMIOS'"!]
            .sEmiosChannelConfig={
                [!INDENT "16"!]
                .nPwmeMiosPrescaler=[!"$nPwmeMiosPrescaler"!],
                .nPwmeMiosMode=[!"$nPwmeMiosMode"!],
                .nPwmeMiosBus=[!"$nPwmeMiosBus"!],
                .nIdealDutyCycle=[!"$nIdealDutyCycle"!],
                .nDeadtime=[!"$nDeadtime"!],
                .nOffset=[!"$nOffset"!],
                .ntrigTime=[!"$ntrigTime"!],
                [!IF "$pfPwmChannelNotification != 'NULL_PTR'"!]
                .nPwmeMiosDmaSwitch=FALSE,
                [!ELSE!]
                .nPwmeMiosDmaSwitch=[!IF "$nPwmeMiosDmaSwitch"!]TRUE[!ELSE!]FALSE[!ENDIF!],
                [!ENDIF!]
                [!ENDINDENT!]
            },
        [!ENDIF!]
            .nPwmMaxDutycycle=[!"$nPwmMaxDutycycle"!],
        [!ENDINDENT!]
    },
    [!ENDINDENT!]
[!ENDSELECT!][!//
[!ENDFOR!][!//
    }
};
[!VAR "PwmHwIPClass" = "'GTM_TOM'"!]
[!VAR "PwmHWIndex" = "num:i(0)"!]
[!VAR "PwmCHIndex" = "num:i(0)"!]
[!MACRO "GetNotification"!][!//
[!NOCODE!][!//
    [!VAR "flag" = "num:i(0)"!]
    [!VAR "Pwm_Notification" = "'NULL_PTR'"!]
    [!VAR "Pwm_ChannelId" = "num:i(0)"!]
    [!LOOP "(PwmChannelConfigSet/PwmChannel/*)"!]
        [!IF "$flag = 0"!]
            [!IF "text:match(./PwmHwIP,'GTM_ATOM')"!]
                [!VAR "nPwmHwIndex_temp"="num:i(substring-after(node:ref(./AtomChannelRef)/../../PwmAtomModule,'ATOM'))"!]
                [!VAR "nPwmChIndex_temp"="num:i(substring-after(node:ref(./AtomChannelRef)/PwmAtomChannel,'Channel_'))"!]
            [!ELSEIF "text:match(./PwmHwIP,'GTM_TOM')"!]
                [!VAR "nPwmHwIndex_temp"="num:i(substring-after(node:ref(./TomChannelRef)/../../PwmTomModule,'TOM'))"!]
                [!VAR "nPwmChIndex_temp"="num:i(substring-after(node:ref(./TomChannelRef)/PwmTomChannel,'Channel_'))"!]
            [!ELSEIF "text:match(./PwmHwIP,'EMIOS')"!]
                [!VAR "nPwmHwIndex_temp"="num:i(substring-after(node:ref(./EmiosChannelRef)/../../PwmEmiosModule,'eMios_'))"!]
                [!VAR "nPwmChIndex_temp"="num:i(substring-after(node:ref(./EmiosChannelRef)/PwmEmiosChannel,'Channel_'))"!]
            [!ENDIF!]
            [!IF "$PwmHwIPClass = ./PwmHwIP and $nPwmHwIndex_temp = $PwmHWIndex and $nPwmChIndex_temp = $PwmCHIndex"!]
                [!VAR "Pwm_Notification"="./PwmNotification"!]
                [!VAR "Pwm_ChannelId"="./PwmChannelId"!]
                [!VAR "flag" = "num:i(1)"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!][!//
[!IF "$Pwm_Notification = 'NULL'"!]
    [!VAR "Pwm_Notification" = "'NULL_PTR'"!]
[!ELSEIF "$Pwm_Notification != 'NULL_PTR'"!]
    [!VAR "Pwm_Notification" = "concat('&',$Pwm_Notification)"!]
[!ENDIF!]
[!INDENT "4"!]
{.pNotification=[!"$Pwm_Notification"!],.nPwmChannelId=[!"$Pwm_ChannelId"!]},
[!ENDINDENT!]
[!ENDMACRO!][!//

static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_TomNotifyTable[PWM_TOM_MAX * PWM_TOM_CHANNEL_MAX]=
{
    [!VAR "PwmHwIPClass" = "'GTM_TOM'"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(8)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(9)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(10)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(11)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(12)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(13)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(14)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(15)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(8)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(9)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(10)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(11)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(12)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(13)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(14)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(15)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(8)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(9)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(10)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(11)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(12)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(13)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(14)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(15)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(8)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(9)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(10)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(11)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(12)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(13)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(14)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(15)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(8)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(9)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(10)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(11)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(12)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(13)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(14)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(15)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(8)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(9)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(10)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(11)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(12)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(13)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(14)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(15)"!]
    [!CALL "GetNotification"!]
};

static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_AtomNotifyTable[PWM_ATOM_MAX * PWM_ATOM_CHANNEL_MAX]=
{
    [!VAR "PwmHwIPClass" = "'GTM_ATOM'"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(1)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(2)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(3)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(4)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(5)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(6)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(6)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(6)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(6)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(6)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(6)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(6)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(6)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(7)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(7)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(7)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(7)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(7)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(7)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(7)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(7)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
};

static CONST(Pwm_NotifyTableItemType, PWM_CONST) Pwm_EmiosNotifyTable[PWM_EMIOS_MAX * PWM_EMIOS_CHANNEL_MAX]=
{
    [!VAR "PwmHwIPClass" = "'EMIOS'"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(0)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(1)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(2)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(3)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(4)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(5)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(6)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(7)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(8)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(9)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(10)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(11)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(12)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(13)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(14)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(15)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(16)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(17)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(18)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(19)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(20)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(21)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(22)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(23)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(24)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(25)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(26)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(27)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(28)"!]
    [!CALL "GetNotification"!]  
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(29)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(30)"!]
    [!CALL "GetNotification"!]
    [!VAR "PwmHWIndex" = "num:i(0)"!]
    [!VAR "PwmCHIndex" = "num:i(31)"!]
    [!CALL "GetNotification"!] 
};

static CONST(Pwm_CoreMapItemType, PWM_CONST) Pwm_CoreMap[PWM_CHANNEL_NUM]=
{
[!FOR "x" = "0" TO "num:i(count(PwmChannelConfigSet/PwmChannel/*))"!][!//
[!SELECT "PwmChannelConfigSet/PwmChannel/*/PwmChannelId[.=$x]/.."!][!//
    [!VAR "nPwmChannelId" = "num:i(./PwmChannelId)"!]
    {
        .nPwmChannelId=[!"$nPwmChannelId"!],
        .nCoreId=[!CALL "GetCoreID"!]
    },
[!ENDSELECT!][!//
[!ENDFOR!][!//
};

#ifdef __cplusplus
}
#endif
