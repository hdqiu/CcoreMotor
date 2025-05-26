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
 *   @file    Lin_Cfg.h
 *   @version 1.0.1
 *
 *   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
 *   @details Autosar layer of Lin MCAL driver.
 *
 *   @addtogroup Lin
 */

#ifndef LIN_CFG_H
#define LIN_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif
/*=======================================INCLUDE FILES=============================================*/
[!CODE!][!//
#include "EcuM_Cbk.h"
[!ENDCODE!][!//
#include "Mcal.h"

/*=============================SOURCE FILE VERSION INFORMATION======================================*/
#define LIN_VENDOR_ID_OUTPUT                    176
#define LIN_AR_REL_MJR_VERSION_PLUGIN           4
#define LIN_AR_REL_MNR_VERSION_PLUGIN           4
#define LIN_AR_REL_REV_VERSION_OUTPUT           0
#define LIN_SW_MAJOR_VERSION_OUTPUT             1
#define LIN_SW_MINOR_VERSION_OUTPUT             0
#define LIN_SW_PATCH_VERSION_OUTPUT             1
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_WRAPPER_C_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_WRAPPER_C_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_WRAPPER_C_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_WRAPPER_C_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_PLUGIN != LIN_WRAPPER_C_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_WRAPPER_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_WRAPPER_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_PLUGIN != LIN_WRAPPER_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_PLUGIN != LIN_WRAPPER_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_PLUGIN != LIN_WRAPPER_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_PLUGIN != LIN_WRAPPER_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_PATCH_VER "
#endif
/*=========================================CONSTANTS================================================*/

/*=====================================DEFINES AND MACROS===========================================*/
[!NOCODE!]
[!// check for duplicated channel id, or hw channel id
    [!VAR "tmp_ch_id" = "-1"!]
    [!VAR "tmp_hw_ch" = "-1"!]
    [!VAR "tmp_channel_index" = "0"!]
    [!VAR "max_channel_nr" = "count(LinChannel/*)"!]
    [!VAR "LinMasterNodeUsed"= "'false'"!]
    [!LOOP "LinChannel/*"!]
        [!VAR "i" = "0"!]
        [!VAR "tmp_channel_index" = "$tmp_channel_index + 1"!]
        [!VAR "tmp_ch_id" = "LinChannelId"!]
        [!VAR "tmp_hw_ch" = "substring-after(LinHwChannel,'_')"!]
        [!FOR "i" = "$tmp_channel_index + 1" TO "$max_channel_nr"!]
            [!IF "$tmp_ch_id = ../*[num:i($i)]/LinChannelId"!]
                [!ERROR!] Duplicate LinChannelId.[!ENDERROR!]
            [!ENDIF!]
            [!IF "$tmp_hw_ch = substring-after(../*[num:i($i)]/LinHwChannel,'_')"!]
                [!ERROR!] Duplicate LinHwChannel IDs.[!ENDERROR!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDLOOP!]
[!// end check for duplicated channel id, or hw channel id
[!ENDNOCODE!][!//

#define LIN_PRECOMPILE_SUPPORT [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime') and (variant:size() <= 1)"!] (STD_ON) [!ELSE!] (STD_OFF) [!ENDIF!]

#define LIN_HW_MAX_MODULES [!"num:i(count(LinGlobalConfig/LinChannel/*))"!]U

#define LIN_MAX_DATA_LENGTH 8U

#define LIN_HW_MAX_AVAILABLE_MODULES [!"num:i(ecu:get('Lin.LinGlobalConfig.LinChannel') + num:i(1))"!]U

[!NOCODE!]
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
    [!IF "contains(node:value(LinNodeType),'MASTER')"!]
        [!VAR "LinMasterNodeUsed"= "'true'"!]
    [!ENDIF!]
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
#define LIN_MASTER_NODE_USED [!IF "$LinMasterNodeUsed = 'true'"!] (STD_ON) [!ELSE!] (STD_OFF)[!ENDIF!]

#define LIN_TIMEOUT_LOOPS ((uint32)[!"LinGeneral/LinTimeoutDuration"!]U)

#define LIN_DEV_ERROR_DETECT [!IF "LinGeneral/LinDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF) [!ENDIF!]

#define LIN_VERSION_INFO_API [!IF "LinGeneral/LinVersionInfoApi"!](STD_ON) [!ELSE!](STD_OFF) [!ENDIF!]

#define LIN_DISABLE_FRAME_TIMEOUT [!IF "LinGeneral/LinDisableFrameTimeout"!](STD_ON) [!ELSE!](STD_OFF)[!ENDIF!]
[!NOCODE!]
[!FOR "index" = "0" TO "num:i(ecu:get('Lin.LinGlobalConfig.LinChannel'))-1"!][!//
    [!VAR "MaxHwChannels" = "string((ecu:list('Lin.LinGlobalConfig.LinChannel.LinHwChannel'))[$index+1])"!][!//
    [!VAR "ChannelFound" = "0"!][!//
    [!LOOP "LinGlobalConfig"!][!//
        [!LOOP "LinChannel/*"!][!//
            [!VAR "HardwareChannel" = "string(LinHwChannel)"!][!//
            [!IF "$MaxHwChannels = $HardwareChannel"!][!//
                [!IF "$ChannelFound = 0"!][!//
                    [!CODE!][!//

#define [!"$MaxHwChannels"!]    [!"substring-after(LinHwChannel,'_')"!]U[!//

                    [!ENDCODE!][!//
                    [!VAR "ChannelFound" = "1"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
#define LIN_DISABLE_DEM_REPORT_ERROR_STATUS [!IF "node:exists(LinDemEventParameterRefs)"!]    (STD_OFF)[!ELSE!](STD_ON) [!ENDIF!]

#define LIN_MULTICORE_SUPPORT [!IF "node:fallback(as:modconf('Lin')[1]/LinGeneral/LinMulticoreSupport, 'false') = 'false'"!](STD_OFF)[!ELSE!](STD_ON)[!ENDIF!]

#define LIN_UNALLOCATEDPAR_CORE_ID [!"num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]U

#define LIN_NONE_ECUM_WAKEUP_SOURCE_REF (uint32)0U

[!NOCODE!]
[!VAR "MaxCoreId"="0"!]
[!IF "node:value(LinGeneral/LinMulticoreSupport)='true'"!]
    [!LOOP "as:modconf('EcuC')[1]/EcucHardware/*[1]/EcucCoreDefinition/*"!][!//
            [!IF "$MaxCoreId < node:value(./EcucCoreId)"!]
                [!VAR "MaxCoreId"="node:value(./EcucCoreId)"!]
            [!ENDIF!]
    [!ENDLOOP!][!//
[!ENDIF!]
[!ENDNOCODE!]
#define LIN_MAX_PARTITIONS     ((uint32)[!"num:i($MaxCoreId+1)"!]U)

/*============================================ENUMS=================================================*/

/*===============================STRUCTURES AND OTHER TYPEDEFS======================================*/

/*===============================GLOBAL VARIABLE DECLARATIONS=======================================*/

/*===================================FUNCTION PROTOTYPES============================================*/

/*=================================EXTERNAL CONSTANTS===============================================*/

#define LIN_START_SEC_CONFIG_DATA
#include "Lin_MemMap.h"

#define LIN_STOP_SEC_CONFIG_DATA
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif

/** @} */
