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
* @file    Port_Cfg.h
* @implements Port_Cfg.h_Artifact
*
* @version 1.0.2
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver precompile configuration.
*
* @addtogroup Port
* @{
*/
/*=================================================================================================
=================================================================================================*/


#ifndef PORT_CFG_H
#define PORT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==============================================INCLUDE FILES=======================================*/

#include "Port_Types.h"
[!NOCODE!]
[!INCLUDE "Matterhorn_Resource.m"!][!//
[!ENDNOCODE!]
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*/
#define PORT_H_VENDOR_ID_CFG                       176
#define PORT_H_AR_RELEASE_MAJOR_VERSION_CFG        4
#define PORT_H_AR_RELEASE_MINOR_VERSION_CFG        4
#define PORT_H_AR_RELEASE_REVISION_VERSION_CFG     0
#define PORT_H_SW_MAJOR_VERSION_CFG                1
#define PORT_H_SW_MINOR_VERSION_CFG                0
#define PORT_H_SW_PATCH_VERSION_CFG                1

/*============================================FILE VERSION CHECKS===================================*/

#if (PORT_H_VENDOR_ID_CFG != REGESYS_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_VENDOR_ID"
#endif

#if (PORT_H_AR_RELEASE_MAJOR_VERSION_CFG != REGESYS_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MAJOR_VER"
#endif

#if (PORT_H_AR_RELEASE_MINOR_VERSION_CFG != REGESYS_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MINOR_VER"
#endif

#if (PORT_H_AR_RELEASE_REVISION_VERSION_CFG != REGESYS_SIUL2_AR_REL_REV_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_REV_VER"
#endif

#if (PORT_H_SW_MAJOR_VERSION_CFG != REGESYS_SIUL2_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_MAJOR_VERSION"
#endif

#if (PORT_H_SW_MINOR_VERSION_CFG != REGESYS_SIUL2_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_MINOR_VERSION"
#endif

#if (PORT_H_SW_PATCH_VERSION_CFG != REGESYS_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_PATCH_VERSION"
#endif
/*===============================================CONSTANTS======================================*/

/*===========================================DEFINES AND MACROS===================================*/
[!VAR "AlreadyParsedNotification"!][!ENDVAR!][!//
[!LOOP "PortConfigSet/PortContainer/*/PortPin/*"!][!//
[!IF "node:exists(PortInterruptSource)"!][!//
[!IF "(PortInterruptSource/eirq_callback != 'NULL_PTR') and (PortInterruptSource/eirq_callback != 'NULL')"!][!//
[!IF "contains($AlreadyParsedNotification, concat(PortInterruptSource/eirq_callback,'|')) = false()"!][!//
extern void [!"PortInterruptSource/eirq_callback"!](void);
[!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,.,'|')"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
/**
* @brief       Ensure better readability of the configuration
* @note 
*
* @violates @ref PORT_CFG_H_REF_3 Function-like macro defined.
*/
#define SHL_PAD_U16(x)                      ((uint16)(((uint16)1) << (x)))

/**
* @brief PSMI setting not available
* @note The current platform does not implement pad selection for multiplexed input for current pin.
*       Used for better readability of PSMI settings.
*
*/
#define NO_INPUTMUX_U16                     ((uint16)0xFFFFU)

/**
* @brief Show the Platform used.
* @note This define can be used by test phase.  
*
*/
#define PLATFORM_MATTERHORN
/**
* @brief Show the IPV used.
* @note This define can be used by test phase.
*
*/

#define ETPU_INPUT_SELECT_MASK             ((uint16)((uint16)1U << (uint16)15U))
#define ETPU1CH29_INPUT_SELECT_MASK        ((uint16)((uint16)1U << (uint16)8U))
#define ETPU1CH28_INPUT_SELECT_MASK        ((uint16)((uint16)1U << (uint16)9U))
#define ETPU1CH27_INPUT_SELECT_MASK        ((uint16)((uint16)1U << (uint16)10U))
#define ETPU1CH26_INPUT_SELECT_MASK        ((uint16)((uint16)1U << (uint16)11U))
#define ETPU1CH25_INPUT_SELECT_MASK        ((uint16)((uint16)1U << (uint16)12U))
#define ETPU1CH24_INPUT_SELECT_MASK        ((uint16)((uint16)1U << (uint16)13U))

/** @brief Port GPIO Mode */
#define PORT_GPIO_MODE                ((Port_PinModeType)0)
/** @brief Port Alternate 1 Mode */
#define PORT_ALT1_FUNC_MODE                ((Port_PinModeType)1)
/** @brief Port Alternate 2 Mode */
#define PORT_ALT2_FUNC_MODE                ((Port_PinModeType)2)
/** @brief Port Alternate 3 Mode */
#define PORT_ALT3_FUNC_MODE                ((Port_PinModeType)3)
/** @brief Port Alternate 4 Mode */
#define PORT_ALT4_FUNC_MODE                ((Port_PinModeType)4)
/** @brief Port Alternate 5 Mode */
#define PORT_ALT5_FUNC_MODE                ((Port_PinModeType)5)
/** @brief Port Alternate 6 Mode */
#define PORT_ALT6_FUNC_MODE                ((Port_PinModeType)6)
/** @brief Port Alternate 7 Mode */
#define PORT_ALT7_FUNC_MODE                ((Port_PinModeType)7)
/** @brief Port Alternate 8 Mode */
#define PORT_ALT8_FUNC_MODE                ((Port_PinModeType)8)
/** @brief Port Alternate 9 Mode */
#define PORT_ALT9_FUNC_MODE                ((Port_PinModeType)9)
/** @brief Port Alternate 10 Mode */
#define PORT_ALT10_FUNC_MODE                ((Port_PinModeType)10)
/** @brief Port Alternate 11 Mode */
#define PORT_ALT11_FUNC_MODE                ((Port_PinModeType)11)
/** @brief Port Alternate 12 Mode */
#define PORT_ALT12_FUNC_MODE                ((Port_PinModeType)12)
/** @brief Port Alternate 13 Mode */
#define PORT_ALT13_FUNC_MODE                ((Port_PinModeType)13)
/** @brief Port Alternate 14 Mode */
#define PORT_ALT14_FUNC_MODE                ((Port_PinModeType)14)
/** @brief Port Alternate 15 Mode */
#define PORT_ALT15_FUNC_MODE                ((Port_PinModeType)15)
/** @brief Port Onput Only Mode */
#define PORT_ONLY_OUTPUT_MODE                ((Port_PinModeType)16)
/** @brief Port Analog Input Mode */
#define PORT_ANALOG_INPUT_MODE                ((Port_PinModeType)17)
/** @brief Port Input Only Mode */
#define PORT_ONLY_INPUT_MODE                ((Port_PinModeType)18)
/** @brief Port Input 1 Mode */
#define PORT_INPUT1_MODE                ((Port_PinModeType)19)
/** @brief Port Input 2 Mode */
#define PORT_INPUT2_MODE                ((Port_PinModeType)20)
/** @brief Port Input 3 Mode */
#define PORT_INPUT3_MODE                ((Port_PinModeType)21)
/** @brief Port Input 4 Mode */
#define PORT_INPUT4_MODE                ((Port_PinModeType)22)
/** @brief Port Input 5 Mode */
#define PORT_INPUT5_MODE                ((Port_PinModeType)23)
/** @brief Port Input 6 Mode */
#define PORT_INPUT6_MODE                ((Port_PinModeType)24)
/** @brief Port Input 7 Mode */
#define PORT_INPUT7_MODE                ((Port_PinModeType)25)
/** @brief Port Input 8 Mode */
#define PORT_INPUT8_MODE                ((Port_PinModeType)26)
/** @brief Port Input 9 Mode */
#define PORT_INPUT9_MODE                ((Port_PinModeType)27)
/** @brief Port Input 10 Mode */
#define PORT_INPUT10_MODE                ((Port_PinModeType)28)
/** @brief Port Input 11 Mode */
#define PORT_INPUT11_MODE                ((Port_PinModeType)29)
/** @brief Port Input 12 Mode */
#define PORT_INPUT12_MODE                ((Port_PinModeType)30)
/** @brief Port Input 13 Mode */
#define PORT_INPUT13_MODE                ((Port_PinModeType)31)
/** @brief Port Input 14 Mode */
#define PORT_INPUT14_MODE                ((Port_PinModeType)32)
/** @brief Port Input 15 Mode */
#define PORT_INPUT15_MODE                ((Port_PinModeType)33)
/** @brief Port Input 16 Mode */
#define PORT_INPUT16_MODE                ((Port_PinModeType)34)
/** @brief Port Input 17 Mode */
#define PORT_INPUT17_MODE                ((Port_PinModeType)35)
/** @brief Port Input 18 Mode */
#define PORT_INPUT18_MODE                ((Port_PinModeType)36)
/** @brief Port Input 19 Mode */
#define PORT_INPUT19_MODE                ((Port_PinModeType)37)
/** @brief Port Input 20 Mode */
#define PORT_INPUT20_MODE                ((Port_PinModeType)38)
/** @brief Port Input 21 Mode */
#define PORT_INPUT21_MODE                ((Port_PinModeType)39)
/** @brief Port Input 22 Mode */
#define PORT_INPUT22_MODE                ((Port_PinModeType)40)
/** @brief Port Input 23 Mode */
#define PORT_INPUT23_MODE                ((Port_PinModeType)41)
/** @brief Port Input 24 Mode */
#define PORT_INPUT24_MODE                ((Port_PinModeType)42)
/** @brief Port Input 25 Mode */
#define PORT_INPUT25_MODE                ((Port_PinModeType)43)
/** @brief Port Input 26 Mode */
#define PORT_INPUT26_MODE                ((Port_PinModeType)44)
/** @brief Port Input 27 Mode */
#define PORT_INPUT27_MODE                ((Port_PinModeType)45)
/** @brief Port Input 28 Mode */
#define PORT_INPUT28_MODE                ((Port_PinModeType)46)
/** @brief Port Input 29 Mode */
#define PORT_INPUT29_MODE                ((Port_PinModeType)47)
/** @brief Port Input 30 Mode */
#define PORT_INPUT30_MODE                ((Port_PinModeType)48)
/** @brief Port Input 31 Mode */
#define PORT_INPUT31_MODE                ((Port_PinModeType)49)
/** @brief Port Input 32 Mode */
#define PORT_INPUT32_MODE                ((Port_PinModeType)50)
/** @brief Port Input 33 Mode */
#define PORT_INPUT33_MODE                ((Port_PinModeType)51)
/** @brief Port Input 34 Mode */
#define PORT_INPUT34_MODE                ((Port_PinModeType)52)
/** @brief Port Input 35 Mode */
#define PORT_INPUT35_MODE                ((Port_PinModeType)53)
/** @brief Port Input 36 Mode */
#define PORT_INPUT36_MODE                ((Port_PinModeType)54)
/** @brief Port Input 37 Mode */
#define PORT_INPUT37_MODE                ((Port_PinModeType)55)
/** @brief Port Input 38 Mode */
#define PORT_INPUT38_MODE                ((Port_PinModeType)56)
/** @brief Port Input 39 Mode */
#define PORT_INPUT39_MODE                ((Port_PinModeType)57)
/** @brief Port Input 40 Mode */
#define PORT_INPUT40_MODE                ((Port_PinModeType)58)
/** @brief Port Input 41 Mode */
#define PORT_INPUT41_MODE                ((Port_PinModeType)59)
/** @brief Port Input 42 Mode */
#define PORT_INPUT42_MODE                ((Port_PinModeType)60)
/** @brief Port Input 43 Mode */
#define PORT_INPUT43_MODE                ((Port_PinModeType)61)
/** @brief Port Input 44 Mode */
#define PORT_INPUT44_MODE                ((Port_PinModeType)62)
/** @brief Port Input 45 Mode */
#define PORT_INPUT45_MODE                ((Port_PinModeType)63)
/** @brief Port Input 46 Mode */
#define PORT_INPUT46_MODE                ((Port_PinModeType)64)
/** @brief Port Input 47 Mode */
#define PORT_INPUT47_MODE                ((Port_PinModeType)65)
/** @brief Port Input 48 Mode */
#define PORT_INPUT48_MODE                ((Port_PinModeType)66)
/** @brief Port Input 49 Mode */
#define PORT_INPUT49_MODE                ((Port_PinModeType)67)
/** @brief Port Input 50 Mode */
#define PORT_INPUT50_MODE                ((Port_PinModeType)68)
/** @brief Port Input 51 Mode */
#define PORT_INPUT51_MODE                ((Port_PinModeType)69)
/** @brief Port Input 52 Mode */
#define PORT_INPUT52_MODE                ((Port_PinModeType)70)
/** @brief Port Input 53 Mode */
#define PORT_INPUT53_MODE                ((Port_PinModeType)71)
/** @brief Port Input 54 Mode */
#define PORT_INPUT54_MODE                ((Port_PinModeType)72)
/** @brief Port Input 55 Mode */
#define PORT_INPUT55_MODE                ((Port_PinModeType)73)
/** @brief Port Input 56 Mode */
#define PORT_INPUT56_MODE                ((Port_PinModeType)74)
/** @brief Port Input 57 Mode */
#define PORT_INPUT57_MODE                ((Port_PinModeType)75)
/** @brief Port Input 58 Mode */
#define PORT_INPUT58_MODE                ((Port_PinModeType)76)
/** @brief Port Input 59 Mode */
#define PORT_INPUT59_MODE                ((Port_PinModeType)77)
/** @brief Port Input 60 Mode */
#define PORT_INPUT60_MODE                ((Port_PinModeType)78)
/** @brief Port Input 61 Mode */
#define PORT_INPUT61_MODE                ((Port_PinModeType)79)
/** @brief Port Input 62 Mode */
#define PORT_INPUT62_MODE                ((Port_PinModeType)80)
/** @brief Port Input 63 Mode */
#define PORT_INPUT63_MODE                ((Port_PinModeType)81)
/** @brief Port Input 64 Mode */
#define PORT_INPUT64_MODE                ((Port_PinModeType)82)
/** @brief Port Input 65 Mode */
#define PORT_INPUT65_MODE                ((Port_PinModeType)83)
/** @brief Port Input 66 Mode */
#define PORT_INPUT66_MODE                ((Port_PinModeType)84)
/** @brief Port Input 67 Mode */
#define PORT_INPUT67_MODE                ((Port_PinModeType)85)
/** @brief Port Input 68 Mode */
#define PORT_INPUT68_MODE                ((Port_PinModeType)86)
/** @brief Port Input 69 Mode */
#define PORT_INPUT69_MODE                ((Port_PinModeType)87)
/** @brief Port Input/Output 1 Mode */
#define PORT_INOUT1_MODE                ((Port_PinModeType)88)
/** @brief Port Input/Output 2 Mode */
#define PORT_INOUT2_MODE                ((Port_PinModeType)89)
/** @brief Port Input/Output 3 Mode */
#define PORT_INOUT3_MODE                ((Port_PinModeType)90)
/** @brief Port Input/Output 4 Mode */
#define PORT_INOUT4_MODE                ((Port_PinModeType)91)
/** @brief Port Input/Output 5 Mode */
#define PORT_INOUT5_MODE                ((Port_PinModeType)92)


/** @brief Port Abstraction Modes */
[!"$PinAbstractionModes_1"!]

/**
* @brief Enable/Disable Development Error Detection
*
* @implements   PORT_DEV_ERROR_DETECT_define
*/
#define PORT_DEV_ERROR_DETECT           [!IF "PortGeneral/PortDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
*
* @implements   PORT_SET_PIN_DIRECTION_API_define
*/
[!IF "node:exists(PortGeneral/PortSetPinDirectionApi)"!][!//
#define PORT_SET_PIN_DIRECTION_API      [!IF "PortGeneral/PortSetPinDirectionApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ELSE!]
#define PORT_SET_PIN_DIRECTION_API      (STD_OFF)
[!ENDIF!]

/**
* @brief Enable/Disable Port SetPinMode Does Not Touch GPIO Levels
*
* @implements   PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL_define
*/
[!IF "node:exists(PortGeneral/PortSetPinModeDoesNotTouchGpioLevel)"!][!//
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL      [!IF "PortGeneral/PortSetPinModeDoesNotTouchGpioLevel"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ELSE!]
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL      (STD_OFF)
[!ENDIF!]

/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
*
* @implements   PORT_SET_PIN_MODE_API_define
*/
[!IF "node:exists(PortGeneral/PortSetPinModeApi)"!][!//
#define PORT_SET_PIN_MODE_API           [!IF "PortGeneral/PortSetPinModeApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ELSE!]
#define PORT_SET_PIN_MODE_API           (STD_OFF)
[!ENDIF!]

/**
* @brief Use/remove Port_Siul2_SetExtRequest function from the compiled driver
*
* @implements   PORT_SET_SIUL2_API_define
*/
[!IF "node:exists(PortConfigSet/PortContainer/*/PortPin/*/PortInterruptSource)"!][!//
#define PORT_SET_SIUL2_API           (STD_ON)
[!ELSE!]
#define PORT_SET_SIUL2_API           (STD_OFF)
[!ENDIF!]

/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
*
* @implements   PORT_VERSION_INFO_API_define
*/
#define PORT_VERSION_INFO_API           [!IF "PortGeneral/PortVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!NOCODE!][!//
[!LOOP "PortConfigSet/*"!]
    [!VAR "OuterLoopCounter" = "0"!][!//
    [!VAR "InnerLoopCounter" = "0"!][!//
    [!LOOP "PortContainer/*"!][!//
        [!LOOP "PortPin/*"!][!//
            [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
            [!VAR "InnerLoopCounter" = "0"!]
            [!VAR "MatchCounter" = "0"!]
            [!VAR "Id" = "PortPinPcr"!]
            [!VAR "Name" = "node:name(.)"!]
            [!LOOP "../../../../PortContainer/*"!][!//
                [!LOOP "PortPin/*"!][!//
                    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
                    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                        [!IF "($Id = PortPinPcr)"!]
                            [!VAR "MatchCounter" = "$MatchCounter + 1"!]
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDLOOP!][!//
            [!IF "$MatchCounter = 1"!]
            [!ELSE!]
                [!ERROR "PortPinPcr is repeated for two or more ports."!]
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!LOOP "PortContainer/*"!][!//
        [!LOOP "PortPin/*"!][!//
            [!VAR "PortPinPcrVar" = "PortPinPcr"!][!//
            [!IF "($PortPinPcrVar>ecu:get('PortMaxPinNumber'))"!][!//
                [!ERROR!][!//
                [!"name(.)"!] [!"': PortPinPcr '"!] [!"string($PortPinPcrVar)"!] [!"concat('- Physical pin numbers greater then ',ecu:get('PortMaxPinNumber'),' are not available in this package')"!][!//
                [!ENDERROR!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*
*/
[!NOCODE!]
    [!VAR "OutConfigLoopCounter" = "0"!][!//
    [!VAR "ConfigSetIndex"="0"!]
    [!LOOP "PortConfigSet/*"!][!//
        [!VAR "ConfigSetName" = "node:name(.)"!][!//
        [!VAR "OutConfigLoopCounter" = "$OutConfigLoopCounter + 1"!][!//
        [!VAR "OutPinLoopCounter" = "0"!][!//
        [!LOOP "PortContainer/*"!][!//
            [!VAR "ContName" = "node:name(.)"!][!//
            [!LOOP "PortPin/*"!][!//
                [!VAR "OutPinLoopCounter" = "$OutPinLoopCounter + 1"!][!//
                [!VAR "Name" = "node:name(.)"!][!//
                [!VAR "MatchCounter" = "0"!][!//
                [!VAR "InConfigLoopCounter" = "0"!][!//
                [!VAR "MatchConfigSet" = "0"!][!//
                [!LOOP "../../../../../../PortConfigSet/*"!][!//
                    [!VAR "InConfigLoopCounter" = "$InConfigLoopCounter + 1"!][!//
                    [!VAR "InPinLoopCounter" = "0"!][!//
                    [!LOOP "PortContainer/*"!][!//
                        [!VAR "ContNameNew" = "node:name(.)"!][!//
                        [!LOOP "PortPin/*"!][!//
                            [!VAR "InPinLoopCounter" = "$InPinLoopCounter + 1"!][!//
                            [!IF "$InConfigLoopCounter < $OutConfigLoopCounter"!][!//
                                [!IF "($ContName = $ContNameNew)"!][!//
                                    [!IF "($Name = node:name(.))"!][!//
                                        [!IF "$InPinLoopCounter = $OutPinLoopCounter"!][!//
                                            [!IF "$MatchConfigSet = $ConfigSetIndex"!][!//
                                                [!VAR "MatchCounter" = "$MatchCounter + 1"!][!//
                                            [!ENDIF!][!//
                                        [!ELSE!][!//
                                            [!ERROR!][!//
                                                [!"concat('- The same Abstract Name ',($Name),' is used for different index values')"!][!//
                                            [!ENDERROR!][!//
                                        [!ENDIF!][!//
                                    [!ENDIF!][!//
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ENDLOOP!][!//
                    [!ENDLOOP!][!//
                    [!VAR "$MatchConfigSet" = "$MatchConfigSet+1"!][!//
                [!ENDLOOP!][!//
                [!IF "$MatchCounter = 0"!][!//
                    [!VAR "PortPinIdVar"="PortPinId"!][!//
[!CODE!][!//
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define [!"$ConfigSetName"!]_[!"$ContName"!]_[!"node:name(.)"!]  [!"num:i($PortPinIdVar - 1)"!]
[!ENDCODE!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!]

/**
* @brief Number of INMUX registers
* @details Platform constant
*/
#define PORT_NMBR_INMUX_REGS_U16    ((uint16)[!"ecu:get('PortMaxINMUXRegs')"!])
/**
* @brief Number of available pad modes options
* @details Platform constant
*/
#define PAD_MODE_OPTIONS_U8         ((uint8)[!"ecu:get('PortPadModeNumber')"!])
/**
* @brief Number of pad 16 blocks
* @details Platform constant
*/
#define PAD_16BLOCK_NO_U8           ((uint8)[!"ecu:get('PortPin16BlocksNo')"!])
/**
 * @brief The last supported pin number
 */
#define PORT_MAX_PIN_PACKAGE_U16    ((uint16)[!"ecu:get('PortMaxPinNumber')"!])

#define PORT_PRECOMPILE_SUPPORT[!WS "4"!][!//
[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!][!//
(STD_ON)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!]

/**
* @brief Number of UnUsed pin array
*/
[!NOCODE!]
    [!VAR "MaxNoOfUnusedPins" = "0"!][!//
    [!SELECT "PortConfigSet"!][!//
        [!VAR "MaxNoOfPins" = "num:i(ecu:get('PortMaxPinNumber')+1)"!][!//
        [!VAR "UnimplementedPadsNumber" = "num:i(count(ecu:list('PortUnimplementedPAD')))"!][!//
        [!VAR "UserPadsNumber" = "num:i(count(PortContainer/*/PortPin/*))"!][!//
        [!LOOP "PortContainer/*/PortPin/*"!][!//
            [!IF "contains(concat(',',string(ecu:get('PortUnimplementedPAD')),','),concat(',',PortPinPcr,','))"!][!//
                [!VAR "UnimplementedPadsNumber"= "$UnimplementedPadsNumber - 1"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!VAR "DefaultPinNumber" = "$UnimplementedPadsNumber + $UserPadsNumber"!][!//
        [!VAR "NoOfUnusedPins" = "num:i(($MaxNoOfPins - $DefaultPinNumber))"!][!//
[!NOCODE!][!//
#define PORT_MAX_UNUSED_PADS_[!"@index"!]_U16    ([!"num:i($NoOfUnusedPins)"!]U)
[!ENDNOCODE!][!//
        [!IF "num:i($NoOfUnusedPins) > $MaxNoOfUnusedPins"!][!//
            [!VAR "MaxNoOfUnusedPins" = "num:i($NoOfUnusedPins)"!]
        [!ENDIF!][!//
    [!ENDSELECT!][!//
[!ENDNOCODE!]
#define PORT_MAX_UNUSED_PADS_U16   ([!"num:i($MaxNoOfUnusedPins)"!]U)

/**
* @brief The maximum number of configured pins
*/
[!VAR "MaxNoOfConfiguredPins" = "0"!][!//
[!SELECT "PortConfigSet"!]
[!NOCODE!][!//
#define PORT_MAX_CONFIGURED_PADS_[!"@index"!]_U16   ((uint16)[!"num:i(count(PortContainer/*/PortPin/*))"!])
[!ENDNOCODE!][!//
[!IF "num:i(count(PortContainer/*/PortPin/*)) > $MaxNoOfConfiguredPins"!][!//
[!VAR "MaxNoOfConfiguredPins" = "num:i(count(PortContainer/*/PortPin/*))"!]
[!ENDIF!][!//
[!ENDSELECT!]
#define PORT_MAX_CONFIGURED_PADS_U16   ((uint16)[!"num:i($MaxNoOfConfiguredPins)"!])


#if (STD_ON == PORT_SET_PIN_MODE_API)
#define  PORT_INOUT_TABLE_NUM_ENTRIES_U16       ((uint16)[!"$SIZE_OF_INOUT_SETTINGS_1"!])
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

/*==============================================ENUMS===============================================*/


/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

typedef struct
{
    VAR(uint16, AUTOMATIC) u16Port_NumPins;                                                     /**< @brief Number of used pads (to be configured) */
    P2CONST(Port_Siul2_PinConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_UsedPadConfig;          /**< @brief Used pads data configuration */
    P2CONST(Port_Siul2_PadSelConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_PadSelConfig;        /**< @brief Used pads INMUX configuration */
}Port_UsedPinType;

typedef struct
{
    VAR(uint16, AUTOMATIC) u16Port_NumUnusedPins;                                               /**< @brief Number of unused pads */
    P2CONST(uint16, AUTOMATIC, PORT_APPL_CONST) au16Port_UnusedPads;                            /**< @brief Unused pad id's array */
    P2CONST(Port_Siul2_UnUsedPinConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_UnusedPadConfig;  /**< @brief Unused pad configuration */
}Port_UnusedPinType;

typedef struct{
    VAR(uint16, PORT_VAR) u16Port_Pin;
    VAR(uint8,  PORT_VAR) u8CoreId;
}Port_CoreMapItemType;[!//

[!VAR "pinnum"="num:i(0)"!][!//
[!LOOP "PortConfigSet/PortContainer/*/PortPin/*"!][!//
[!IF "node:exists(PortInterruptSource)"!][!//
[!VAR "pinnum" = "$pinnum+1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

#define PORT_SIUL2_NUM  [!"num:i($pinnum)"!]U

/*
 * @brief Typedef
 */
typedef uint16_t pin_index_t;
typedef void  (* callBackFunction)(void);

/*
 * @brief
 */
typedef enum {
    SIUL2_EVENT_DISABLED     = 0U,  /* request event disabled */
    SIUL2_EVENT_RISING_EDGE  = 1U,  /* rising edge event is enabled */
    SIUL2_EVENT_FALLING_EDGE = 2U,  /* falling edge event is enabled */
    SIUL2_EVENT_EITHER_EDGE  = 3U,  /* request on either edge */
} siul2_request_event_t;
/*
 * @brief Configures the siul2 external interrupt
 */
typedef struct { /* PRQA S 3630 */
    uint16                 eirq_index;
    siul2_request_event_t  event_edge_sel;
    callBackFunction       eirq_cb;
} Port_siul2_request_config;
/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements Port_ConfigType_struct
*
* @api
*/
typedef struct
{
	Port_UsedPinType Port_UsedPin;
	Port_UnusedPinType Port_UnusedPin;
    P2CONST(uint8,PORT_CONST,PORT_APPL_CONST)Etpu_IS;
	P2CONST(Port_CoreMapItemType, PORT_CONST, PORT_APPL_CONST) coreMap;
	P2CONST(Port_siul2_request_config, P2CONST, PORT_APPL_DATA) reqConfig;
} Port_ConfigType;

/**
* @brief Settings for a INMUX register
* @details The structure @p Port_InMuxSettingType manages ExtraFunctions PinMode.
* 
*
* @api
*/
typedef struct
{
    VAR(uint16,AUTOMATIC) u16Port_InMuxId;   /**< @brief The id of the INMUX register to be configured */
    VAR(uint8, AUTOMATIC) u8Port_InMuxCode;  /**< @brief The value of the INMUX reg for signal allocation */
} Port_InMuxSettingType;

/**
* @brief Settings for a INOUT functionality
* @details The structure @p Port_InoutSettingType manages Inout PinModes.
* 
* @api
*/
typedef struct
{
    VAR(uint16,AUTOMATIC) u16Port_MSCR;      /**< @brief The id of the MSCR register to be configured */
    VAR(uint8,AUTOMATIC)  u8Port_Mode;       /**< @brief The mode to be configured */
    VAR(uint16,AUTOMATIC) u16Port_InMuxId;   /**< @brief The id of the INMUX register to be configured */
    VAR(uint8, AUTOMATIC) u8Port_InMuxCode;  /**< @brief The value of the INMUX reg for signal allocation */
} Port_InoutSettingType;

/*====================================GLOBAL VARIABLE DECLARATIONS==================================*/

#define PORT_START_SEC_CONFIG_DATA
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"

[!LOOP "PortConfigSet/*"!]
/**
* @brief External declaration of the Port configuration structures for post-build mode
*/
extern CONST(Port_ConfigType, PORT_CONST) [!"node:name(.)"!];

[!ENDLOOP!]


#define PORT_STOP_SEC_CONFIG_DATA
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
#define PORT_START_SEC_CONFIG_DATA
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"
/**
* @brief External declaration of the Port pin description array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(uint16, PORT_CONST) Port_au16PinDescription[[!"ecu:get('PortPadModeNumber')"!]][[!"ecu:get('PortPin16BlocksNo')"!]];
#define PORT_STOP_SEC_CONFIG_DATA
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"



/**
* @brief External declaration of the Port inout functionality settings array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(Port_InoutSettingType,PORT_CONST) Port_aPadFunctInoutMuxSettings[PORT_INOUT_TABLE_NUM_ENTRIES_U16];

/**
* @brief External declaration of the Port pad inmux functionality settings array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(Port_InMuxSettingType,PORT_CONST) Port_aPadFunctInMuxSettings[];

/**
* @brief External declaration of the Port pad inmux functionality settings index array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(uint16,PORT_CONST) Port_au16PadFunctInMuxIndex[[!"ecu:get('PortModeSettingsLinesNo')"!]];
#endif


/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
/*========================================FUNCTION PROTOTYPES=======================================*/

#define PORT_START_SEC_CODE
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"

#define PORT_STOP_SEC_CODE
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"



[!SELECT "PortConfigSet/PortContainer/*/PortPin/*"!][!//
[!VAR "ChannelId" = "num:i(./PortPinId)"!][!//
#define [!"node:name(.)"!]                           ((uint16) [!"num:i($ChannelId - 1)"!]U)
[!VAR "ChannelId" = "num:i($ChannelId + 1)"!][!//
[!ENDSELECT!][!//

/* End of File */
[!NOCODE!][!//
[!ENDNOCODE!][!//
[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif

#endif /* PORT_CFG_H */

/** @} */





