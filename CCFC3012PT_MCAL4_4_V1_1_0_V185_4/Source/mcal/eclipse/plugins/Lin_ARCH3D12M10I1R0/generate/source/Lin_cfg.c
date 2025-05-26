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
*   @file    Lin_cfg.c
*   @implements Lin_cfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup Lin
*   @{
*/


#ifdef __cplusplus
extern "C"
{
#endif


/*======================================INCLUDE FILES===============================================*/
#include "StandardTypes.h"
#include "Lin_Cfg.h"
#include "Lin.h"
#include "eDma.h"
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_WRAPPER_C_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_WRAPPER_C_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_WRAPPER_C_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_WRAPPER_C_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_WRAPPER_C_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_WRAPPER_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_WRAPPER_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_WRAPPER_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_WRAPPER_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_WRAPPER_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_WRAPPER_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_PATCH_VER "
#endif
/*=========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)===============================*/

/*======================================LOCAL MACROS================================================*/

/*=====================================LOCAL CONSTANTS==============================================*/

/*=====================================LOCAL VARIABLES==============================================*/

/*=====================================GLOBAL CONSTANTS=============================================*/

#define LIN_START_SEC_CONFIG_DATA
#include "Lin_MemMap.h"

[!NOCODE!][!//
[!VAR "LFDIV"="0"!][!//
[!VAR "temp1" = "0"!][!//
[!VAR "temp2" = "0"!][!//
[!VAR "LINIBRR" = "0"!][!//
[!VAR "LINFBRR" = "0"!][!//
[!VAR "LINIBRR_LINFBRR" = "0"!][!//
[!VAR "ECUM_WAKE_UP_SOURCE" = "0"!][!//

[!VAR "DualClockEnabled"= "'false'"!][!//
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
[!IF "(node:exists(LinClockRef_Alternate))"!][!//
[!VAR "DualClockEnabled"= "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!VAR "LinDemErrorEnable" = "'false'"!]
[!IF "LinGeneral/ LinDisableDemReportErrorStatus ='false'"!][!//
    [!VAR "nconf" = "count(LinGlobalConfig/*)"!]
    [!VAR "iconf" = "0"!]
    [!FOR "iconf" = "1" TO "$nconf"!]
        [!IF "node:exists(LinGlobalConfig/LinDemEventParameterRefs)"!]
            [!VAR "LinDemErrorEnable" = "'true'"!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDIF!]
[!ENDNOCODE!][!//

[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
[!VAR "nodeName" = "name(.)"!]
static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_[!"node:name(.)"!]=
{
    (uint8)[!"LinChannelId"!]U,              /* Lin Channel ID */
    [!"LinHwChannel"!],              /* Lin Hardware channel*/
    [!IF "contains(node:value(LinNodeType), 'MASTER')"!]LIN_MASTER_NODE[!ELSE!]LIN_SLAVE_NODE[!ENDIF!],        /* Lin Node Type */
[!NOCODE!][!//
    [!VAR "linBaudrate" = "LinChannelBaudRate"!]
    [!SELECT "node:ref(LinClockRef)"!]
    [!INCLUDE "Lin_BaudRate_Comp.m"!][!//
    [!ENDSELECT!]
    [!CODE!]    [!"$LINIBRR_LINFBRR"!]U,            /* Baudrate [!"LinChannelBaudRate"!] ; Baudrate difference = [!"$temp2"!] */[!ENDCODE!]
[!ENDNOCODE!][!//
[!IF "LinChannelWakeupSupport"!]
    STD_ON,         /* Wakeup support enabled */
[!ELSE!]
    STD_OFF,        /* Wakeup support disabled */[!ENDIF!][!//
    [!IF "(node:exists(LinChannelEcuMWakeupSource) = 'true') and (node:value(LinChannelEcuMWakeupSource) != '')"!]
    (EcuM_WakeupSourceType)((uint32)1U<<(uint32)[!"as:ref(LinChannelEcuMWakeupSource)/EcuMWakeupSourceId"!]U), /* Wakeup Source transmitted to the Ecu State Manager (used only when Wakeup Support is true) */
    [!ELSE!]
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
    [!ENDIF!][!NOCODE!][!//
    [!VAR "IntegerBrkLength" = "substring-after(BreakLengthMaster,'_')"!]
    [!IF "$IntegerBrkLength = 36"!]
        [!VAR "VarBreakLength"="14"!]
    [!ELSEIF "$IntegerBrkLength = 50"!]
        [!VAR "VarBreakLength"="15"!]
    [!ELSE!]
        [!VAR "VarBreakLength"="$IntegerBrkLength - 10"!]
    [!ENDIF!]
    [!VAR "BrkLengthSlave" = "substring-after(BreakLengthSlave,'_')"!]
[!ENDNOCODE!][!//
    [!CODE!]
    [!"num:inttohex($VarBreakLength,2)"!]U, /* BreakLengthMaster = [!"BreakLengthMaster"!] bits */
    [!"$BrkLengthSlave"!]U, /* BreakLengthSlave = [!"BreakLengthSlave"!] bits */
    [!"num:i(LinResponseTimeout)"!]U, /* Response timeout value LINTOCR[RTO] */
    [!"num:i(LinHeaderTimeout)"!]U,  /* Header timeout value LINTOCR[HTO] */
    [!IF "GroupSelIntOrDma != 'DMA'"!]STD_OFF[!ELSE!]STD_ON[!ENDIF!],
    [!IF "GroupSelIntOrDma != 'DMA'"!]0[!ELSE!][!"node:ref(eDmaTXConfig)/eDmaChannelId"!][!ENDIF!],
    [!IF "GroupSelIntOrDma != 'DMA'"!]0[!ELSE!][!"node:ref(eDmaRXConfig)/eDmaChannelId"!][!ENDIF!],
    [!ENDCODE!][!//
};
[!ENDLOOP!][!//
[!MACRO "GetCoreID"!][!//
[!NOCODE!]
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!]
    [!VAR "ModuEcucPartitionRef" = "string(LinChannelEcucPartitionRef)"!]
    [!IF "not(node:refexists(LinChannelEcucPartitionRef))"!]
        [!VAR "CoreID" = "num:i(ecu:get('MCAL.DEFAULT.COREID'))"!][!//
    [!ELSE!]
        [!VAR "OsApplication_cnt" = "num:i(count(as:modconf('Os')[1]/OsApplication/*))"!]
        [!IF "$OsApplication_cnt = num:i(0)"!]
            [!ERROR!]ASPath:/Os/Os/OsApplication is not configured [!ENDERROR!]
        [!ELSE!]
            [!FOR "n" = "0" TO "num:i($OsApplication_cnt)-1"!]
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

[!SELECT "LinGlobalConfig"!]
static CONST(Lin_CoreMapItemType, GPT_CONST) Lin_CoreMap[LIN_HW_MAX_MODULES]=
{
[!LOOP "(LinChannel/*)"!]
    [!VAR "u8LinChannelID" = "num:i(./LinChannelId)"!]
    {
        .u16Lin_SIUPin = [!"$u8LinChannelID"!],[!//
        
        .u8CoreId =[!CALL "GetCoreID"!]
    },
[!ENDLOOP!] 
};
[!ENDSELECT!]

[!NOCODE!][!//
[!LOOP "./LinGlobalConfig"!][!//
    [!VAR "nodeName" = "name(.)"!][!//
[!ENDLOOP!][!//
[!CODE!]
/* Specification of Lin Driver : [SWS_Lin_00225] */
CONST(Lin_ConfigType,LIN_CONST)LinGlobalConfig =
{
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
[!ENDCODE!]
    [!IF "$LinDemErrorEnable"!]
        [!IF "node:exists(./LinDemEventParameterRefs/LIN_E_TIMEOUT)"!]
            [!IF "node:exists(node:ref(./LinDemEventParameterRefs/LIN_E_TIMEOUT))"!]
                [!CODE!]
    { (uint32)STD_ON, DemConf_DemEventParameter_[!"node:name(node:ref(./LinDemEventParameterRefs/LIN_E_TIMEOUT))"!]}, /* LIN_E_TIMEOUT parameters*/
                [!ENDCODE!]
            [!ELSE!]
                [!ERROR "Invalid reference for LIN_E_ERROR"!]
            [!ENDIF!]
        [!ELSE!]
            [!CODE!]
    {(uint32)STD_OFF, 0U}, /* LIN_E_TIMEOUT parameters*/
            [!ENDCODE!]
        [!ENDIF!]
    [!ELSE!]
        [!CODE!]
    {(uint32)STD_OFF, 0U}, /* LIN_E_TIMEOUT parameters*/
        [!ENDCODE!]
    [!ENDIF!]
[!CODE!]
#endif /* LIN_DISABLE_DEM_REPORT_ERROR_STATUS== STD_OFF */

    [!"num:i(count(LinGlobalConfig/LinChannel/*))"!]U,
    {
[!ENDCODE!]
[!VAR "LoopVar"="0"!]
[!VAR "count"="0"!]
[!VAR "MaxChannelNr" = "num:i(count(LinGlobalConfig/LinChannel/*))"!]
[!FOR "count" = "0" TO "$MaxChannelNr - 1"!]
        [!LOOP "LinGlobalConfig/LinChannel/*"!]
            [!IF "$LoopVar = num:i(LinChannelId)"!]
                [!IF "$LoopVar > $MaxChannelNr - 2"!]
                    [!CODE!]
        &Lin_[!"node:name(.)"!]
                    [!ENDCODE!]
                [!ELSE!]
                    [!CODE!]
        &Lin_[!"node:name(.)"!],
                    [!ENDCODE!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
[!VAR "LoopVar"="$LoopVar + 1"!]
[!ENDFOR!]
[!CODE!]
    },
    Lin_CoreMap,
};
[!ENDCODE!]
[!ENDNOCODE!]

#define LIN_STOP_SEC_CONFIG_DATA
#include "Lin_MemMap.h"
/*=====================================GLOBAL VARIABLES=============================================*/

/*==================================LOCAL FUNCTION PROTOTYPES=======================================*/

/*======================================LOCAL FUNCTIONS=============================================*/

/*======================================GLOBAL FUNCTIONS============================================*/



#ifdef __cplusplus
}
#endif

/** @} */
