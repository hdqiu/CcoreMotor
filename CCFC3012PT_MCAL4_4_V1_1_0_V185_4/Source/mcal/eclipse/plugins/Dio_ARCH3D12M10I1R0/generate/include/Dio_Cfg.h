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
#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Dio_Types.h"
/*=============================SOURCE FILE VERSION INFORMATION==================================*/
#define DIO_CFG_H_VENDOR_ID                     176
#define DIO_CFG_H_MAJOR_VERSION                 4
#define DIO_CFG_H_MINOR_VERSION                 4
#define DIO_CFG_H_patch_VERSION                 0
#define DIO_CFG_H_SW_MAJOR_VERSION              1
#define DIO_CFG_H_SW_MINOR_VERSION              0
#define DIO_CFG_H_SW_PATCH_VERSION              1
/*====================================FILE VERSION CHECKS=======================================*/
#if (DIO_CFG_H_VENDOR_ID != DIO_TYPES_VENDOR_ID)
    #error " NON-MATCHED DATA : DIO_CFG_H_VENDOR_ID "
#endif
#if (DIO_CFG_H_MAJOR_VERSION != DIO_TYPES_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_MAJOR_VERSION "
#endif
#if (DIO_CFG_H_MINOR_VERSION != DIO_TYPES_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_MINOR_VERSION "
#endif
#if (DIO_CFG_H_patch_VERSION != DIO_TYPES_patch_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_patch_VERSION "
#endif
#if (DIO_CFG_H_SW_MAJOR_VERSION != DIO_TYPES_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_SW_MAJOR_VERSION "
#endif
#if (DIO_CFG_H_SW_MINOR_VERSION != DIO_TYPES_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_SW_MINOR_VERSION "
#endif
#if (DIO_CFG_H_SW_PATCH_VERSION != DIO_TYPES_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : DIO_CFG_H_SW_PATCH_VERSION "
#endif

/*=========================================CONSTANTS============================================*/


#define DIO_DEV_ERROR_DETECT    ([!IF "DioGeneral/DioDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define DIO_VERSION_INFO_API    ([!IF "DioGeneral/DioVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define DIO_FLIP_CHANNEL_API    ([!IF "DioGeneral/DioFlipChannelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define DIO_MASKEDWRITEPORT_API ([!IF "DioGeneral/DioMaskedWritePortApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define DIO_READZERO_UNDEFINEDPORTS ([!IF "DioGeneral/DioReadZeroForUndefinedPortPins"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define DIO_MULTICORE_SUPPORT ([!IF "DioGeneral/DioMulticoreSupport  "!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
 
#define DIO_NUM_PORTS_U16 (uint16)([!"num:i(count(ecu:list('Dio.WriteAvailablePins')))"!])

#define DIO_NUM_CHANNELS_RIDE_PORT_U16 (uint16)0x10U

#define DIO_ZERO_U16 ((Dio_PortLevelType)0x0U)

#define DIO_NUM_CHANNELS_U16     ((uint16)DIO_NUM_PORTS_U16 * DIO_NUM_CHANNELS_RIDE_PORT_U16)

#define DIO_PRECOMPILE_SUPPORT



#define ncoreid  [!"num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]

#define DIO_OFFSET_MAX_VALID_U8 ((uint8)0x1FU)
extern CONST(Dio_PortLevelType, DIO_CONST) Dio_ReadAvailablePins[DIO_NUM_PORTS_U16];
extern CONST(Dio_PortLevelType, DIO_CONST) Dio_WriteAvailablePins[DIO_NUM_PORTS_U16];
extern CONST(Dio_ConfigType, DIO_CONST) Dio_ConfigPC;
[!AUTOSPACING!]
[!SELECT "DioConfig"!]
[!VAR "ChannelGroupdIdx"="0"!]
[!LOOP "DioPort/*"!]
[!VAR "PortId" = "DioPortId"!]


/**
* @brief          Symbolic name for the port [!"node:name(.)"!].
*
*/
#define DioConf_DioPort_[!"node:name(.)"!]  ((uint8)[!"num:inttohex($PortId,2)"!]U/2)
#define DioConf_DioPort_Group_[!"node:name(.)"!]  ((uint8)[!"num:inttohex($PortId,2)"!]U)

[!LOOP "DioChannel/*"!]
[!VAR "portChannelId" = "DioChannelId"!]
[!VAR "ChannelId" = "16*$PortId + $portChannelId"!]

[!IF "$ChannelId = 322"!]
[!VAR "ChannelId" = "240"!]
[!ELSEIF "$ChannelId >= 240 and $ChannelId <= 321"!]
[!VAR "ChannelId" = "$ChannelId + 1"!]
[!ENDIF!]
/**
* @brief          Symbolic name for the port [!"node:name(.)"!].
*/
#define DioConf_DioChannel_[!"node:name(.)"!] ((uint16)[!"num:i($ChannelId)"!]U)

[!ENDLOOP!]

[!LOOP "DioChannelGroup/*"!]
/**
* @brief          Symbolic name for the port [!"node:name(.)"!].
*/
#define DioConf_DioChannelGroup_[!"node:value(./DioChannelGroupIdentification)"!]    \
                    (&DioConf_aChannelGroupList[[!"num:dectoint($ChannelGroupdIdx)"!]])

[!VAR "ChannelGroupdIdx" = "$ChannelGroupdIdx + 1"!]
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDSELECT!]

[!SELECT "DioConfig"!]

[!VAR "numChannelGroupsInConfig" = "count(DioPort/*/DioChannelGroup/*)"!]
[!//
[!IF "$numChannelGroupsInConfig != 0"!]
[!//
#define DIO_CHANNEL_GROUPS_AVAILABLE
[!VAR "CoreId" = "num:i(0)"!][!//
[!IF "node:value(../DioGeneral/DioMulticoreSupport)='true'"!]
    [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!][!//
        [!VAR "CoreId" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$CoreId = 0"!][!//
    [!VAR "CoreId" = "num:i(ecu:get('MCAL.DEFAULT.COREID'))+1"!][!//
[!ENDIF!][!//




extern CONST(Dio_ChannelGroupType, DIO_CONST) DioConf_aChannelGroupList[[!"num:dectoint($numChannelGroupsInConfig)"!]];
extern P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) u32ChannelGroupsListForEachPartition[[!"num:i($CoreId)"!]][[!"num:dectoint($numChannelGroupsInConfig)"!]];
[!ENDIF!][!//
[!ENDSELECT!][!//

[!LOOP "DioConfig/DioPort/*/DioChannelGroup/*"!]
   [!VAR "i"="0"!]
   [!VAR "group_names"="node:name(.)"!]
   [!LOOP "../../../../DioPort/*/DioChannelGroup/*"!]
      [!IF "$group_names=node:name(.)"!]
         [!VAR "i"="$i+1"!]
      [!ENDIF!]
   [!ENDLOOP!]
   [!IF "$i > 1"!]
      [!ERROR "ChannelGroup name duplicated. Channel group names must be unique even across ports and configurations"!]
   [!ENDIF!]
[!ENDLOOP!]

[!LOOP "DioConfig/DioPort/*/DioChannelGroup/*"!]
   [!VAR "i"="0"!]
   [!VAR "groupmacro_names"="node:value(./DioChannelGroupIdentification)"!]
   [!LOOP "../../../../DioPort/*/DioChannelGroup/*"!]
      [!IF "$groupmacro_names=node:value(./DioChannelGroupIdentification)"!]
         [!VAR "i"="$i+1"!]
      [!ENDIF!]
   [!ENDLOOP!]
   [!IF "$i > 1"!]
      [!ERROR "ChannelGroup name duplicated. Channel group names must be unique even across ports and configurations"!]
   [!ENDIF!]
[!ENDLOOP!]

[!LOOP "DioConfig/DioPort/*/DioChannel/*"!]
   [!VAR "i"="0"!]
   [!VAR "channel_names"="node:name(.)"!]
   [!LOOP "../../../../DioPort/*/DioChannel/*"!]
      [!IF "$channel_names=node:name(.)"!]
         [!VAR "i"="$i+1"!]
      [!ENDIF!]
   [!ENDLOOP!]
   [!IF "$i > 1"!]
      [!ERROR "Channel name duplicated. Channel names must be unique even across ports and configurations"!]
   [!ENDIF!]
[!ENDLOOP!]


#endif  /* DIO_CFG_H */
