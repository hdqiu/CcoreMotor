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

[!SELECT "DioConfig"!][!//
[!//
[!VAR "numChannelGroupsInConfig" = "count(DioPort/*/DioChannelGroup/*)"!][!//
[!//
[!IF "$numChannelGroupsInConfig != 0"!][!//
[!//
CONST(Dio_ChannelGroupType, DIO_CONST) DioConf_aChannelGroupList[[!"num:dectoint($numChannelGroupsInConfig)"!]] = 
{
[!VAR "i" = "0"!][!//
[!LOOP "DioPort/*"!][!//
[!LOOP "DioChannelGroup/*"!][!//
[!VAR "mask"="DioPortMask"!][!//
[!VAR "offset"="DioPortOffset"!][!//
    {(Dio_PortLevelType)[!"num:inttohex($mask,8)"!]UL , (uint8)[!"num:inttohex($offset,2)"!], DioConf_DioPort_[!"node:name(./../..)"!], DioConf_DioPort_Group_[!"node:name(./../..)"!]}[!//
[!VAR "i"="$i+1"!][!//
[!IF "$i != $numChannelGroupsInConfig"!],[!ENDIF!]
[!ENDLOOP!][!//
[!ENDLOOP!][!//
};


[!NOCODE!][!//
[!VAR "maxCoreId" = "num:i(0)"!][!//
[!IF "node:value(../DioGeneral/DioMulticoreSupport)='true'"!]
    [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!][!//
        [!VAR "maxCoreId" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$maxCoreId = 0"!][!//
    [!VAR "maxCoreId" = "num:i(ecu:get('MCAL.DEFAULT.COREID')) + 1"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) u32ChannelGroupsListForEachPartition[[!"num:i($maxCoreId)"!]][[!"num:i($numChannelGroupsInConfig)"!]] =
{
[!INDENT "4"!][!//
[!VAR "EcucPartitionRef_cnt"="num:i(count(../DioGeneral/DioEcucPartitionRef/*))"!][!//
[!FOR "x" = "0" TO "num:i($maxCoreId)-1"!][!//
{
    [!VAR "GroupChannelCounter" = "0"!][!//
    [!LOOP "DioPort/*/DioChannelGroup/*"!][!//
        [!VAR "Counter" = "0"!][!//
        [!LOOP "DioChannelGroupEcucPartitionRef/*"!][!//
            [!VAR "DioCrtPart" = "node:value(.)"!][!//
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                [!IF "$DioCrtPart = node:value(./OsAppEcucPartitionRef/*[1])"!][!//
                    [!SELECT "node:ref(./OsApplicationCoreRef/*[1])"!][!//
                        [!IF "$x = node:value(./EcucCoreId)"!][!//
                            [!VAR "Counter" = "$Counter + 1"!][!//
                        [!ENDIF!][!//
                    [!ENDSELECT!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
        [!IF "$EcucPartitionRef_cnt = 2"!][!//
            &DioConf_aChannelGroupList[[!"num:i($GroupChannelCounter)"!]][!IF "$GroupChannelCounter < num:i($numChannelGroupsInConfig - 1)"!],[!ENDIF!]
        [!ELSE!][!//
            [!IF "$Counter = 0"!][!//
                NULL_PTR[!IF "$GroupChannelCounter < num:i($numChannelGroupsInConfig - 1)"!],[!ENDIF!]
            [!ELSE!][!//
                &DioConf_aChannelGroupList[[!"num:i($GroupChannelCounter)"!]][!IF "$GroupChannelCounter < num:i($numChannelGroupsInConfig - 1)"!],[!ENDIF!]
            [!ENDIF!][!//
        [!ENDIF!][!//
        [!VAR "GroupChannelCounter" = "$GroupChannelCounter + 1"!][!//
    [!ENDLOOP!][!//
    [!VAR "EcucPartitionRef_cnt"="num:i($EcucPartitionRef_cnt + 1)"!][!//
}[!IF "$x < ($maxCoreId -1)"!],[!ENDIF!]
[!ENDFOR!][!//
[!ENDINDENT!][!//
};
[!ENDIF!][!//
[!ENDSELECT!][!//

[!VAR "PortsNumber"="count(ecu:list('Dio.ReadAvailablePins'))"!][!//
CONST(Dio_PortLevelType, DIO_CONST) Dio_ReadAvailablePins[DIO_NUM_PORTS_U16] =
{
[!FOR "Loop" = "1" TO "$PortsNumber"!][!//
    (Dio_PortLevelType)[!"ecu:list('Dio.ReadAvailablePins')[num:dectoint($Loop)]"!][!//
[!IF "$Loop < $PortsNumber "!],[!ENDIF!]
[!ENDFOR!][!//
};


[!VAR "PortsNumber"="count(ecu:list('Dio.WriteAvailablePins'))"!][!//
CONST(Dio_PortLevelType, DIO_CONST) Dio_WriteAvailablePins[DIO_NUM_PORTS_U16] =
{
[!FOR "Loop" = "1" TO "$PortsNumber"!][!//
    (Dio_PortLevelType)[!"ecu:list('Dio.WriteAvailablePins')[num:dectoint($Loop)]"!][!//
[!IF "$Loop < $PortsNumber "!],[!ENDIF!]
[!ENDFOR!][!//
};


[!MACRO "GetCoreID"!][!//
[!NOCODE!][!//
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRef_cnt" = "num:i(count(DioPortEcucPartitionRef/*))"!][!//
    [!IF "$EcucPartitionRef_cnt = num:i(0)"!][!//
        [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!// 
    [!ELSE!][!//
        [!FOR "i" = "0" TO "num:i($EcucPartitionRef_cnt)-1"!][!//
            [!VAR "ModuEcucPartitionRef" = "string(DioPortEcucPartitionRef/*[$i+1])"!][!//
            [!IF "not(node:refexists(DioPortEcucPartitionRef/*[$i+1]))"!][!//
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




[!SELECT "DioConfig"!][!//
static CONST(pu32Dio_PortToPartitionMap, DIO_CONST) u32PortToPartitionMap[DIO_NUM_PORTS_U16] =
{
[!LOOP "(DioPort/*)"!]
[!VAR "u8PortChannelID" = "num:i(./DioPortId)"!]
    {
        .nDioPortId = [!"$u8PortChannelID"!],
        .coreid =  [!CALL "GetCoreID"!]
    },
[!ENDLOOP!]

};
[!ENDSELECT!][!//

[!MACRO "GetchannelCoreID"!][!//
[!NOCODE!][!//
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRef_cnt" = "num:i(count(DioChannelEcucPartitionRef/*))"!][!//
    [!IF "$EcucPartitionRef_cnt = num:i(0)"!][!//
        [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!// 
    [!ELSE!][!//
        [!FOR "i" = "0" TO "num:i($EcucPartitionRef_cnt)-1"!][!//
            [!VAR "ModuEcucPartitionRef" = "string(DioChannelEcucPartitionRef/*[$i+1])"!][!//
            [!IF "not(node:refexists(DioChannelEcucPartitionRef/*[$i+1]))"!][!//
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
[!SELECT "DioConfig"!][!//
static CONST(pu32Dio_ChannelToPartitionMap, DIO_CONST) u32ChannelToPartitionMap[DIO_NUM_CHANNELS_U16] =
{
[!LOOP "./DioPort/*"!][!//
    [!VAR "PortId" = "num:i(node:fallback(./DioPortId,0))"!][!//
    [!LOOP "./DioChannel/*"!][!//
        [!VAR "PortChannelId" = "DioChannelId"!][!//
        [!IF "$PortId >= 15 and $PortId < 20"!][!//
            [!VAR "ChannelId" = "num:i(16*$PortId + $PortChannelId + 1)"!][!//
        [!ELSEIF "$PortId = 20"!][!//
            [!IF "$PortChannelId = 1"!]
                [!VAR "ChannelId" = "num:i(16*$PortId + $PortChannelId + 1)"!][!//
            [!ENDIF!][!//
        [!ELSE!][!//
            [!VAR "ChannelId" = "num:i(16*$PortId + $PortChannelId)"!][!//
        [!ENDIF!]
        {
            .nDioChannelId = [!"$ChannelId"!],
            .coreid =  [!CALL "GetchannelCoreID"!][!//
        },[!//
    [!ENDLOOP!][!//
[!ENDLOOP!][!//

};
[!ENDSELECT!][!//
CONST(Dio_ConfigType, DIO_CONST) Dio_ConfigPC=
{
    .u8NumChannelGroups = (uint8)[!"num:inttohex($numChannelGroupsInConfig)"!],
    .pChannelGroupList = [!IF "$numChannelGroupsInConfig != 0"!][!/*
        */!]&DioConf_aChannelGroupList[0],[!//
    [!ELSE!][!/*
        */!]NULL_PTR,[!//
    [!ENDIF!]
    .Dio_u32ChannelToPartitionMap = u32ChannelToPartitionMap,
    .Dio_u32PortToPartitionMap = u32PortToPartitionMap
};
#ifdef __cplusplus
}
#endif
