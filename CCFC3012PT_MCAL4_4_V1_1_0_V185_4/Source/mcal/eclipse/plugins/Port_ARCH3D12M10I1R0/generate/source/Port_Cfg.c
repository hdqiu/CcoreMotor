[!CODE!][!//
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
* @file    Port_PBcfg.c
* @implements Port_PBcfg.c_Artifact
*
* @version 1.0.2
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver postbuild configuration.
*
* @addtogroup  Port
* @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Port.h"
#include "derivative.h"
[!INCLUDE "Port_VersionCheck_Src_PB.m"!][!//
    
[!NOCODE!][!//
[!/******************************************************************************/!][!//
[!/* Variable used to store Mode selected option                                */!][!//
[!/******************************************************************************/!][!//
[!/* Include package file in order to get valid Pins */!][!//
[!INCLUDE "Port_Operation.m"!][!//
[!INCLUDE "Matterhorn_Resource.m"!][!//
[!ENDNOCODE!][!//

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*
*/
#define PORT_C_VENDOR_ID_PBCFG                       176
/*
* @violates @ref PORT_PBCFG_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_C_AR_RELEASE_MAJOR_VERSION_PBCFG        4
/*
* @violates @ref PORT_PBCFG_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_C_AR_RELEASE_MINOR_VERSION_PBCFG        4

/** @violates @ref PORT_PBCFG_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*   ensure that 31 character significance and case sensitivity are supported for external
*   identifiers.
*/
#define PORT_C_AR_RELEASE_REVISION_VERSION_PBCFG     0
#define PORT_C_SW_MAJOR_VERSION_PBCFG                1
#define PORT_C_SW_MINOR_VERSION_PBCFG                0
#define PORT_C_SW_PATCH_VERSION_PBCFG                1

/*============================================FILE VERSION CHECKS===================================*/

/* Check if Port_PBcfg.c and Port.h are of the same vendor */
#if (PORT_C_VENDOR_ID_PBCFG != PORT_VENDOR_ID)
    #error "NON-MATCHED DATA : PORT_VENDOR_ID"
#endif
/* Check if Port_PBcfg.c and Port.h are of the same Autosar version */
#if (PORT_C_AR_RELEASE_MAJOR_VERSION_PBCFG    != PORT_AR_RELEASE_MAJOR_VERSION) 
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MAJOR_VERSION"
#endif

#if (PORT_C_AR_RELEASE_MINOR_VERSION_PBCFG    != PORT_AR_RELEASE_MINOR_VERSION) 
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MINOR_VERSION"
#endif

#if (PORT_C_AR_RELEASE_REVISION_VERSION_PBCFG != PORT_AR_RELEASE_REV_VERSION) 
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_REV_VERSION"
#endif

/* Check if Port_PBcfg.c and Port.h are of the same software version */
#if (PORT_C_SW_MAJOR_VERSION_PBCFG != PORT_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_MAJOR_VERSION"
#endif

#if (PORT_C_SW_MINOR_VERSION_PBCFG != PORT_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_MINOR_VERSION"
#endif

#if (PORT_C_SW_PATCH_VERSION_PBCFG != PORT_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_PATCH_VERSION"
#endif

/*=========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)===============================*/


/*======================================LOCAL MACROS================================================*/


/*======================================LOCAL CONSTANTS=============================================*/


/*======================================LOCAL VARIABLES=============================================*/


/*======================================GLOBAL CONSTANTS============================================*/
#define PORT_START_SEC_CONFIG_DATA

#include "Port_MemMap.h"
static CONST(Port_CoreMapItemType, PORT_CONST) Port_CoreMap[PORT_MAX_CONFIGURED_PADS_U16];
[!CALL "Port_UnUsedPadsArrayDefault", "Type"="'PB'"!][!//

#define PORT_STOP_SEC_CONFIG_DATA

#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA

#include "Port_MemMap.h"
[!AUTOSPACING!]
static CONST(uint8, PORT_CONST) u8Port_Etpu_Input_Select[6]={
[!VAR "etpu_mode_cnt" = "num:i(0)"!][!//
[!SELECT "PortConfigSet"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "text:match(./PortPinMode,'ETPU1_29') and (text:match(./PortPinDirection,'PORT_PIN_IN') or text:match(./PortPinMode,'_IN'))"!][!//
            [!VAR "etpu_mode_cnt" = "num:i($etpu_mode_cnt) + num:i(1)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!][!//
[!IF "$etpu_mode_cnt > num:i(0)"!][!//
    1,
[!ELSE!][!//
    0,
[!ENDIF!][!//
[!VAR "etpu_mode_cnt" = "num:i(0)"!][!//
[!SELECT "PortConfigSet"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "text:match(./PortPinMode,'ETPU1_28') and (text:match(./PortPinDirection,'PORT_PIN_IN') or text:match(./PortPinMode,'_IN'))"!][!//
            [!VAR "etpu_mode_cnt" = "num:i($etpu_mode_cnt) + num:i(1)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!][!//
[!IF "$etpu_mode_cnt > num:i(0)"!][!//
    1,
[!ELSE!][!//
    0,
[!ENDIF!][!//
[!VAR "etpu_mode_cnt" = "num:i(0)"!][!//
[!SELECT "PortConfigSet"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "text:match(./PortPinMode,'ETPU1_27') and (text:match(./PortPinDirection,'PORT_PIN_IN') or text:match(./PortPinMode,'_IN'))"!][!//
            [!VAR "etpu_mode_cnt" = "num:i($etpu_mode_cnt) + num:i(1)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!][!//
[!IF "$etpu_mode_cnt > num:i(0)"!][!//
    1,
[!ELSE!][!//
    0,
[!ENDIF!][!//
[!VAR "etpu_mode_cnt" = "num:i(0)"!][!//
[!SELECT "PortConfigSet"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "text:match(./PortPinMode,'ETPU1_26') and (text:match(./PortPinDirection,'PORT_PIN_IN') or text:match(./PortPinMode,'_IN'))"!][!//
            [!VAR "etpu_mode_cnt" = "num:i($etpu_mode_cnt) + num:i(1)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!][!//
[!IF "$etpu_mode_cnt > num:i(0)"!][!//
    1,
[!ELSE!][!//
    0,
[!ENDIF!][!//
[!VAR "etpu_mode_cnt" = "num:i(0)"!][!//
[!SELECT "PortConfigSet"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "text:match(./PortPinMode,'ETPU1_25') and (text:match(./PortPinDirection,'PORT_PIN_IN') or text:match(./PortPinMode,'_IN'))"!][!//
            [!VAR "etpu_mode_cnt" = "num:i($etpu_mode_cnt) + num:i(1)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!][!//
[!IF "$etpu_mode_cnt > num:i(0)"!][!//
    1,
[!ELSE!][!//
    0,
[!ENDIF!][!//
[!VAR "etpu_mode_cnt" = "num:i(0)"!][!//
[!SELECT "PortConfigSet"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "text:match(./PortPinMode,'ETPU1_24') and (text:match(./PortPinDirection,'PORT_PIN_IN') or text:match(./PortPinMode,'_IN'))"!][!//
            [!VAR "etpu_mode_cnt" = "num:i($etpu_mode_cnt) + num:i(1)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!][!//
[!IF "$etpu_mode_cnt > num:i(0)"!][!//
    1,
[!ELSE!][!//
    0,
[!ENDIF!][!//
};

[!CALL "Port_UnUsedPin", "Type"="'PB'"!][!//
[!CALL "Port_aPinConfigDefault", "Type"="'PB'"!][!//
[!CALL "Port_aPadSelConfigDefault", "Type"="'PB'"!][!//
[!CALL "Port_ConfigPinParameter", "Type"="'PB'"!][!//
[!CALL "Port_ParameterArrays", "Type"="'PB'"!][!//

#define PORT_STOP_SEC_CONFIG_DATA

#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA

#include "Port_MemMap.h"

[!CALL "Port_ParameterArrays_2", "Type"="'PB'"!][!//

#define PORT_STOP_SEC_CONFIG_DATA

#include "Port_MemMap.h"

/*======================================GLOBAL VARIABLES============================================*/


/*==================================LOCAL FUNCTION PROTOTYPES=======================================*/


/*======================================LOCAL FUNCTIONS=============================================*/


/*======================================GLOBAL FUNCTIONS============================================*/




/** @} */
[!MACRO "GetCoreID"!][!//
[!NOCODE!][!//
    [!VAR "CoreID" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!][!//
    [!VAR "EcucPartitionRef_cnt" = "num:i(count(PortPinEcucPartitionRef/*))"!][!//
    [!IF "$EcucPartitionRef_cnt = num:i(0)"!][!//
        [!VAR "CoreID" = "bit:shl(1,num:i(ecu:get('MCAL.DEFAULT.COREID')))"!][!// 
    [!ELSE!][!//
        [!FOR "i" = "0" TO "num:i($EcucPartitionRef_cnt)-1"!][!//
            [!VAR "ModuEcucPartitionRef" = "string(PortPinEcucPartitionRef/*[$i+1])"!][!//
            [!IF "not(node:refexists(PortPinEcucPartitionRef/*[$i+1]))"!][!//
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


[!SELECT "PortConfigSet"!]
static CONST(Port_CoreMapItemType, PORT_CONST) Port_CoreMap[PORT_MAX_CONFIGURED_PADS_U16]=
{
[!LOOP "(PortContainer/*/PortPin/*)"!]
    [!VAR "u8PortChannelID" = "num:i(./PortPinPcr)"!]
    {
        .u16Port_Pin = [!"$u8PortChannelID"!],
        .u8CoreId =  [!CALL "GetCoreID"!]
    },
[!ENDLOOP!]
};
[!ENDSELECT!]
/* End of File */

[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif
