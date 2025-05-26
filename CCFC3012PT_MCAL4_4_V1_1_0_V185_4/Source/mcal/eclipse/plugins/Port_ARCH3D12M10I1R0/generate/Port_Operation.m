[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('PORT_OPERATION_M'))"!]
[!VAR "PORT_OPERATION_M"="'true'"!]
[!NOCODE!][!//

/**
*   @file    Port_Operation.m
*   @version 1.0.2
*
*   @brief   AUTOSAR Port - version check macro.
*   @details Version checks.
*
*   @addtogroup PORT
*   @{
*/

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
/*==================================================================================================
==================================================================================================*/

[!ENDNOCODE!][!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetAltConf                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Alternative Mode configuration for selected pin */!][!//
[!MACRO "GetAltConf"!][!//
[!NOCODE!][!//
[!/* Alternative Mode 0 is the GPIO */!][!//
[!IF "text:match(./PortPinMode,'PORT_PIN_MODE_GPIO')"!][!//
    [!VAR "OutPinAltConf"="0"!]
[!ELSE!][!//
    [!VAR "MacPinMode"="concat(./PortPinMode,'_PORT',number(./PortPinPcr))"!][!//
    [!VAR "OutPinAltConf"="number(substring-after(substring-before((substring-after($PinMap,$MacPinMode)),':'),';'))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetDirConf                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Alternative Mode configuration for selected pin */!][!//
[!MACRO "GetDirConf"!][!//
[!NOCODE!][!//
[!IF "(./PortPinMode = 'PORT_PIN_MODE_GPIO')"!][!//
    [!IF "./PortPinSchmittTrigger"!][!//
        [!VAR "MacDirection"= "string('(boolean)TRUE')"!][!//
    [!ELSE!][!//
        [!VAR "MacDirection"= "string('(boolean)FALSE')"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacDirection"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacDirection"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPCR                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Fill the MSCR register for the selected pin */!][!//
[!MACRO "GetPCR"!][!//
[!NOCODE!][!//
[!VAR "MacPinPCR"="num:i(0)"!][!//
[!/* Get the Alternative Mode configuration and fill the PCR */!][!//
[!CALL "GetAltConf"!][!//
[!/* Check if  Pull Up/Down is enabled */!][!//
[!IF "./PortPinPullEnable"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,1))"!][!//
[!ELSE!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,1))"!][!//
[!ENDIF!][!//
[!/* Select Pull Up or Pull Down */!][!//
[!IF "text:match(./PortPinPullSelect,'PULL_UP')"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,0))"!][!//
[!ELSE!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,0))"!][!//
[!ENDIF!][!//
[!/* Select Driving Strength */!][!//
[!IF "text:match(./PortPinDrivingStrength,'2mA')"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,2))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,3))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,4))"!][!//
[!ELSEIF "text:match(./PortPinDrivingStrength,'4mA')"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,2))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,3))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,4))"!][!//
[!ELSEIF "text:match(./PortPinDrivingStrength,'8mA')"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,2))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,3))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,4))"!][!//
[!ELSEIF "text:match(./PortPinDrivingStrength,'12mA')"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,2))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,3))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,4))"!][!//
[!ELSEIF "text:match(./PortPinDrivingStrength,'16mA')"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,2))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,3))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,4))"!][!//
[!ENDIF!][!//
[!IF "./PortPinOpenDrainOutput"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,5))"!][!//
[!ELSE!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,5))"!][!//
[!ENDIF!][!//
[!IF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,7))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,6))"!][!//
[!ELSE!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,6))"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,7))"!][!//
[!ENDIF!][!//
[!/* Pad Output Assignment */!][!//
[!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl($OutPinAltConf,8))"!][!//
[!IF "./PortPinSchmittTrigger"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,13))"!][!//
[!ELSE!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,13))"!][!//
[!ENDIF!][!//
[!IF "./PortPinSafeMode"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,14))"!][!//
[!ELSE!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,14))"!][!//
[!ENDIF!][!//
[!IF "./PortPinModeSelector"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,15))"!][!//
[!ELSE!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(0,15))"!][!//
[!ENDIF!][!//    
[!/* Check if read status is enabled */!][!//
[!IF "./PortPinWithReadBack"!][!//
    [!VAR "MacPinPCR"="bit:or($MacPinPCR,bit:shl(1,6))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($MacPinPCR,8)"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetUnusedMSCR                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Fill the MSCR register for the unused pins */!][!//
[!MACRO "GetUnusedMSCR"!][!//
[!NOCODE!][!//
[!VAR "MacConfigREG"="num:i(0)"!][!//
[!/* Get the Alternative Mode configuration and fill the Config Register */!][!//
[!CALL "GetAltConf"!][!//
[!/* Check if the pin is configured as an output */!][!//
[!IF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,25))"!][!//
[!ENDIF!][!//
[!/* Check if the pin is configured as an input */!][!//
[!IF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,19))"!][!//
[!ENDIF!][!//

[!/* Check if weak pull up is enabled */!][!//
[!IF "boolean(./PortPinWpue)"!][!//
    [!IF "./PortPinWpue"!][!//
        [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,16))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!/* Check whether weak pull-down is selected */!][!//
[!IF "./PortPinWpde"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,17))"!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//
[!"num:inttohex($MacConfigREG,8)"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPDO                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the output status for selected pin */!][!//
[!MACRO "GetPDO"!][!//
[!NOCODE!][!//
[!IF "not(contains(node:fallback(./PortPinMode,'SARADC'),'SARADC') and (not(contains(node:fallback(./PortPinMode,'INJECTION'),'INJECTION')) or not(contains(node:fallback(./PortPinMode,'NORMAL'),'NORMAL')) or not(contains(node:fallback(./PortPinMode,'EXT_CLKOUT'),'EXT_CLKOUT')) or not(contains(node:fallback(./PortPinMode,'EMUX_ADDR'),'EMUX_ADDR')) or not(contains(node:fallback(./PortPinMode,'ALTREF'),'ALTREF'))))"!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_LOW')"!][!//
        [!VAR "MacPinPDO"="num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_HIGH')"!][!//
        [!VAR "MacPinPDO"="num:i(1)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_NOTCHANGED')"!][!//
        [!VAR "MacPinPDO"="num:i(2)"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacPinPDO"="num:i(2)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacPinPDO"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetGPIOMODE                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Set the initial GPIO Mode for selected pin */!][!//
[!MACRO "GetGPIOMODE"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinDataOutput,'High')"!][!//
    [!VAR "MacGPIOMode"="num:i(1)"!][!//
[!ELSE!][!//
    [!VAR "MacGPIOMode"="num:i(0)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacGPIOMode"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!VAR "MaxcountDefaultPin"="ecu:get('PortMaxPinNumber')"!][!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_UnUsedPadsArrayDefault                */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "Port_UnUsedPadsArrayDefault", "Type"!][!//
[!VAR "maxConfig"="num:i('1')"!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/*
* @violates @ref PORT_[!IF "$Type = 'PB'"!]PB[!ENDIF!]CFG_REF_2 Violates MISRA 2004 Required Rules 10.1,Implicit conversion changes signedness.
*/
#if (PORT_MAX_UNUSED_PADS[!IF "$Type = 'PB'"!][!ENDIF!]_U16 != 0U)
/**
* @brief NoDefaultPadsArray is an array containing Unimplemented pads and User pads
* @violates @ref PORT_[!IF "$Type = 'PB'"!]PB[!ENDIF!]CFG_REF_4 The compiler/linker shall be checked to ensure that 31 character

*/
static CONST(uint16, PORT_CONST) Port_au16NoUnUsedPadsArrayDefault[!IF "$Type = 'PB'"!][!ENDIF!][PORT_MAX_UNUSED_PADS[!IF "$Type = 'PB'"!][!ENDIF!]_U16]=
{
[!NOCODE!]
[!FOR "x" = "0" TO "ecu:get('PortMaxPinNumber')"!][!//
    [!VAR "PinUsed"="0"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "$PinUsed=0"!][!//
            [!IF "num:i(./PortPinPcr)=$x"!][!//
                [!VAR "PinUsed"="$PinUsed + 1"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$PinUsed=0"!][!//
        [!IF "contains(concat(',',string(ecu:get('PortUnimplementedPAD')),','),concat(',',$x,','))"!][!//
            [!VAR "PinUsed"="$PinUsed + 1"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "$PinUsed=0"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
    (uint16)[!"$x"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    (uint16)[!"$x"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
};
#endif
[!ENDSELECT!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_UnUsedPin                             */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "Port_UnUsedPin", "Type"!][!//
[!VAR "maxConfig"="num:i('1')"!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
 * @brief Default Configuration for Pins not initialized
*/
static CONST(Port_Siul2_UnUsedPinConfigType, PORT_CONST) Port_UnUsedPin[!IF "$Type = 'PB'"!][!ENDIF!] =
{
   /**
   * @note: Configuration of Default pin
   */
   [!SELECT "NotUsedPortPin"!][!//
   (uint32)[!CALL "GetUnusedMSCR"!], (uint8)[!CALL "GetPDO"!], (uint8)0
   [!ENDSELECT!][!//
};
[!ENDSELECT!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPDDir                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetPDDir"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinMode,'ADC')"!][!//
    [!VAR "MacPinPDDir"="num:i(0)"!][!//
[!ELSE!][!//
    [!/* Test to 'PORT_PIN_INOUT' should be done first, as 'PORT_PIN_INOUT' string contains 'PORT_PIN_IN' string */!][!//
    [!IF "text:match(./PortPinDirection,'PORT_PIN_INOUT')"!][!//
        [!VAR "MacPinPDDir"="num:i(2)"!][!//
    [!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
        [!VAR "MacPinPDDir"="num:i(0)"!][!//
    [!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
        [!VAR "MacPinPDDir"="num:i(1)"!][!//
    [!ELSE!]
        [!/*don't anything*/!]
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacPinPDDir"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_aPinConfigDefault                     */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "Port_aPinConfigDefault", "Type"!][!//
[!VAR "maxConfig"="num:i('1')"!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "count"= "1"!][!//
[!VAR "Maxcount"= "num:i(count(PortContainer/*/PortPin/*))-1"!][!//
[!VAR "LoopVar"="1"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief Pin default configuration data [!IF "$Type = 'PB'"!]for configPB[!ENDIF!]

*/
static CONST(Port_Siul2_PinConfigType, PORT_CONST) Port_aPinConfigDefault[!IF "$Type = 'PB'"!]PB[!ENDIF!][PORT_MAX_CONFIGURED_PADS[!IF "$Type = 'PB'"!][!ENDIF!]_U16]=
{
[!NOCODE!]
[!FOR "x" = "0" TO "num:i(count(PortContainer/*/PortPin/*))"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!VAR "Loop"="num:i($LoopVar)"!][!//
        [!IF "PortPinId = $Loop"!][!//
            [!IF "$Maxcount>=$count"!][!//
[!CODE!][!//
    {(Port_InternalPinIdType)[!"./PortPinPcr"!], (uint32)[!CALL "GetPCR"!], (uint8)[!CALL "GetGPIOMODE"!], [!CALL "GetDirConf"!], (uint8)[!CALL "GetPDDir"!]},
[!ENDCODE!][!//
            [!ELSE!][!//
[!CODE!][!//
    {(Port_InternalPinIdType)[!"./PortPinPcr"!], (uint32)[!CALL "GetPCR"!], (uint8)[!CALL "GetGPIOMODE"!], [!CALL "GetDirConf"!], (uint8)[!CALL "GetPDDir"!]}
[!ENDCODE!][!//
            [!ENDIF!][!//
            [!VAR "count"= "$count+1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
};
[!ENDSELECT!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_aPadSelConfigDefault                     */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "Port_aPadSelConfigDefault", "Type"!][!//
[!VAR "maxConfig"="num:i('1')"!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief Pad selection default configuration [!IF "$Type = 'PB'"!]for configPB[!ENDIF!]

*/
static CONST(Port_Siul2_PadSelConfigType, PORT_CONST) Port_aPadSelConfigDefault[!IF "$Type = 'PB'"!]PB[!ENDIF!][PORT_NMBR_INMUX_REGS_U16]=
{
[!NOCODE!]
[!VAR "cINMUX0"="0"!][!//
[!VAR "cINMUX1"="0"!][!//
[!VAR "cINMUX2"="0"!][!//
[!VAR "cINMUX3"="0"!][!//
[!VAR "cINMUX4"="0"!][!//
[!VAR "cINMUX5"="0"!][!//
[!VAR "cINMUX6"="0"!][!//
[!VAR "cINMUX7"="0"!][!//
[!VAR "cINMUX8"="0"!][!//
[!VAR "cINMUX9"="0"!][!//
[!VAR "cINMUX10"="0"!][!//
[!VAR "cINMUX11"="0"!][!//
[!VAR "cINMUX12"="0"!][!//
[!VAR "cINMUX13"="0"!][!//
[!VAR "cINMUX14"="0"!][!//
[!VAR "cINMUX15"="0"!][!//
[!VAR "cINMUX16"="0"!][!//
[!VAR "cINMUX17"="0"!][!//
[!VAR "cINMUX18"="0"!][!//
[!VAR "cINMUX19"="0"!][!//
[!VAR "cINMUX20"="0"!][!//
[!VAR "cINMUX21"="0"!][!//
[!VAR "cINMUX22"="0"!][!//
[!VAR "cINMUX23"="0"!][!//
[!VAR "cINMUX24"="0"!][!//
[!VAR "cINMUX25"="0"!][!//
[!VAR "cINMUX26"="0"!][!//
[!VAR "cINMUX27"="0"!][!//
[!VAR "cINMUX28"="0"!][!//
[!VAR "cINMUX29"="0"!][!//
[!VAR "cINMUX30"="0"!][!//
[!VAR "cINMUX31"="0"!][!//
[!VAR "cINMUX32"="0"!][!//
[!VAR "cINMUX33"="0"!][!//
[!VAR "cINMUX34"="0"!][!//
[!VAR "cINMUX35"="0"!][!//
[!VAR "cINMUX36"="0"!][!//
[!VAR "cINMUX37"="0"!][!//
[!VAR "cINMUX38"="0"!][!//
[!VAR "cINMUX39"="0"!][!//
[!VAR "cINMUX40"="0"!][!//
[!VAR "cINMUX41"="0"!][!//
[!VAR "cINMUX42"="0"!][!//
[!VAR "cINMUX43"="0"!][!//
[!VAR "cINMUX44"="0"!][!//
[!VAR "cINMUX45"="0"!][!//
[!VAR "cINMUX46"="0"!][!//
[!VAR "cINMUX47"="0"!][!//
[!VAR "cINMUX48"="0"!][!//
[!VAR "cINMUX49"="0"!][!//
[!VAR "cINMUX50"="0"!][!//
[!VAR "cINMUX51"="0"!][!//
[!VAR "cINMUX52"="0"!][!//
[!VAR "cINMUX53"="0"!][!//
[!VAR "cINMUX54"="0"!][!//
[!VAR "cINMUX55"="0"!][!//
[!VAR "cINMUX56"="0"!][!//
[!VAR "cINMUX57"="0"!][!//
[!VAR "cINMUX58"="0"!][!//
[!VAR "cINMUX59"="0"!][!//
[!VAR "cINMUX60"="0"!][!//
[!VAR "cINMUX61"="0"!][!//
[!VAR "cINMUX62"="0"!][!//
[!VAR "cINMUX63"="0"!][!//
[!VAR "cINMUX64"="0"!][!//
[!VAR "cINMUX65"="0"!][!//
[!VAR "cINMUX66"="0"!][!//
[!VAR "cINMUX67"="0"!][!//
[!VAR "cINMUX68"="0"!][!//
[!VAR "cINMUX69"="0"!][!//
[!VAR "cINMUX70"="0"!][!//
[!VAR "cINMUX71"="0"!][!//
[!VAR "cINMUX72"="0"!][!//
[!VAR "cINMUX73"="0"!][!//
[!VAR "cINMUX74"="0"!][!//
[!VAR "cINMUX75"="0"!][!//
[!VAR "cINMUX76"="0"!][!//
[!VAR "cINMUX77"="0"!][!//
[!VAR "cINMUX78"="0"!][!//
[!VAR "cINMUX79"="0"!][!//
[!VAR "cINMUX80"="0"!][!//
[!VAR "cINMUX81"="0"!][!//
[!VAR "cINMUX82"="0"!][!//
[!VAR "cINMUX83"="0"!][!//
[!VAR "cINMUX84"="0"!][!//
[!VAR "cINMUX85"="0"!][!//
[!VAR "cINMUX86"="0"!][!//
[!VAR "cINMUX87"="0"!][!//
[!VAR "cINMUX88"="0"!][!//
[!VAR "cINMUX89"="0"!][!//
[!VAR "cINMUX90"="0"!][!//
[!VAR "cINMUX91"="0"!][!//
[!VAR "cINMUX92"="0"!][!//
[!VAR "cINMUX93"="0"!][!//
[!VAR "cINMUX94"="0"!][!//
[!VAR "cINMUX95"="0"!][!//
[!VAR "cINMUX96"="0"!][!//
[!VAR "cINMUX97"="0"!][!//
[!VAR "cINMUX98"="0"!][!//
[!VAR "cINMUX99"="0"!][!//
[!VAR "cINMUX100"="0"!][!//
[!VAR "cINMUX101"="0"!][!//
[!VAR "cINMUX102"="0"!][!//
[!VAR "cINMUX103"="0"!][!//
[!VAR "cINMUX104"="0"!][!//
[!VAR "cINMUX105"="0"!][!//
[!VAR "cINMUX106"="0"!][!//
[!VAR "cINMUX107"="0"!][!//
[!VAR "cINMUX108"="0"!][!//
[!VAR "cINMUX109"="0"!][!//
[!VAR "cINMUX110"="0"!][!//
[!VAR "cINMUX111"="0"!][!//
[!VAR "cINMUX112"="0"!][!//
[!VAR "cINMUX113"="0"!][!//
[!VAR "cINMUX114"="0"!][!//
[!VAR "cINMUX115"="0"!][!//
[!VAR "cINMUX116"="0"!][!//
[!VAR "cINMUX117"="0"!][!//
[!VAR "cINMUX118"="0"!][!//
[!VAR "cINMUX119"="0"!][!//
[!VAR "cINMUX120"="0"!][!//
[!VAR "cINMUX121"="0"!][!//
[!VAR "cINMUX122"="0"!][!//
[!VAR "cINMUX123"="0"!][!//
[!VAR "cINMUX124"="0"!][!//
[!VAR "cINMUX125"="0"!][!//
[!VAR "cINMUX126"="0"!][!//
[!VAR "cINMUX127"="0"!][!//
[!VAR "cINMUX128"="0"!][!//
[!VAR "cINMUX129"="0"!][!//
[!VAR "cINMUX130"="0"!][!//
[!VAR "cINMUX131"="0"!][!//
[!VAR "cINMUX132"="0"!][!//
[!VAR "cINMUX133"="0"!][!//
[!VAR "cINMUX134"="0"!][!//
[!VAR "cINMUX135"="0"!][!//
[!VAR "cINMUX136"="0"!][!//
[!VAR "cINMUX137"="0"!][!//
[!VAR "cINMUX138"="0"!][!//
[!VAR "cINMUX139"="0"!][!//
[!VAR "cINMUX140"="0"!][!//
[!VAR "cINMUX141"="0"!][!//
[!VAR "cINMUX142"="0"!][!//
[!VAR "cINMUX143"="0"!][!//
[!VAR "cINMUX144"="0"!][!//
[!VAR "cINMUX145"="0"!][!//
[!VAR "cINMUX146"="0"!][!//
[!VAR "cINMUX147"="0"!][!//
[!VAR "mode_pin"="0"!][!//
[!LOOP "PortContainer/*"!][!//
[!LOOP "PortPin/*"!][!//
[!VAR "mode_pin"="concat(./PortPinMode,'_PORT',number(./PortPinPcr),';')"!][!//  INMUX:LINFLEX0_LIN0_RX_PORT24    mode:LINFLEX3_LINFLEX3_RX
[!VAR "PortPinPcr"="./PortPinPcr"!][!//
[!/* INMUX 0*/!] 
[!IF "contains($INMUX0, $mode_pin)"!][!// 
  [!VAR "cINMUX0"="number(substring-after(substring-before((substring-after($INMUX0,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 1*/!] 
[!IF "contains($INMUX1, $mode_pin)"!][!// 
  [!VAR "cINMUX1"="number(substring-after(substring-before((substring-after($INMUX1,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 2*/!] 
[!IF "contains($INMUX2, $mode_pin)"!][!// 
  [!VAR "cINMUX2"="number(substring-after(substring-before((substring-after($INMUX2,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 3*/!] 
[!IF "contains($INMUX3, $mode_pin)"!][!// 
  [!VAR "cINMUX3"="number(substring-after(substring-before((substring-after($INMUX3,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 4*/!] 
[!IF "contains($INMUX4, $mode_pin)"!][!// 
  [!VAR "cINMUX4"="number(substring-after(substring-before((substring-after($INMUX4,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 5*/!] 
[!IF "contains($INMUX5, $mode_pin)"!][!// 
  [!VAR "cINMUX5"="number(substring-after(substring-before((substring-after($INMUX5,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 6*/!] 
[!IF "contains($INMUX6, $mode_pin)"!][!// 
  [!VAR "cINMUX6"="number(substring-after(substring-before((substring-after($INMUX6,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 7*/!] 
[!IF "contains($INMUX7, $mode_pin)"!][!// 
  [!VAR "cINMUX7"="number(substring-after(substring-before((substring-after($INMUX7,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 8*/!] 
[!IF "contains($INMUX8, $mode_pin)"!][!// 
  [!VAR "cINMUX8"="number(substring-after(substring-before((substring-after($INMUX8,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 9*/!] 
[!IF "contains($INMUX9, $mode_pin)"!][!// 
  [!VAR "cINMUX9"="number(substring-after(substring-before((substring-after($INMUX9,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 10*/!] 
[!IF "contains($INMUX10, $mode_pin)"!][!// 
  [!VAR "cINMUX10"="number(substring-after(substring-before((substring-after($INMUX10,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 11*/!] 
[!IF "contains($INMUX11, $mode_pin)"!][!// 
  [!VAR "cINMUX11"="number(substring-after(substring-before((substring-after($INMUX11,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 12*/!] 
[!IF "contains($INMUX12, $mode_pin)"!][!// 
  [!VAR "cINMUX12"="number(substring-after(substring-before((substring-after($INMUX12,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 13*/!] 
[!IF "contains($INMUX13, $mode_pin)"!][!// 
  [!VAR "cINMUX13"="number(substring-after(substring-before((substring-after($INMUX13,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 14*/!] 
[!IF "contains($INMUX14, $mode_pin)"!][!// 
  [!VAR "cINMUX14"="number(substring-after(substring-before((substring-after($INMUX14,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 15*/!] 
[!IF "contains($INMUX15, $mode_pin)"!][!// 
  [!VAR "cINMUX15"="number(substring-after(substring-before((substring-after($INMUX15,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 16*/!] 
[!IF "contains($INMUX16, $mode_pin)"!][!// 
  [!VAR "cINMUX16"="number(substring-after(substring-before((substring-after($INMUX16,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 17*/!] 
[!IF "contains($INMUX17, $mode_pin)"!][!// 
  [!VAR "cINMUX17"="number(substring-after(substring-before((substring-after($INMUX17,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 18*/!] 
[!IF "contains($INMUX18, $mode_pin)"!][!// 
  [!VAR "cINMUX18"="number(substring-after(substring-before((substring-after($INMUX18,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 19*/!] 
[!VAR "cINMUX19"="number(substring-after(substring-before((substring-after($INMUX19,$PortPinPcr)),':'),';'))"!][!// 
[!/* INMUX 20*/!] 
[!IF "contains($INMUX20, $mode_pin)"!][!// 
  [!VAR "cINMUX20"="number(substring-after(substring-before((substring-after($INMUX20,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 21*/!] 
[!IF "contains($INMUX21, $mode_pin)"!][!// 
  [!VAR "cINMUX21"="number(substring-after(substring-before((substring-after($INMUX21,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 22*/!] 
[!IF "contains($INMUX22, $mode_pin)"!][!// 
  [!VAR "cINMUX22"="number(substring-after(substring-before((substring-after($INMUX22,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 23*/!] 
[!IF "contains($INMUX23, $mode_pin)"!][!// 
  [!VAR "cINMUX23"="number(substring-after(substring-before((substring-after($INMUX23,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 24*/!] 
[!IF "contains($INMUX24, $mode_pin)"!][!// 
  [!VAR "cINMUX24"="number(substring-after(substring-before((substring-after($INMUX24,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 25*/!] 
[!IF "contains($INMUX25, $mode_pin)"!][!// 
  [!VAR "cINMUX25"="number(substring-after(substring-before((substring-after($INMUX25,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 26*/!] 
[!IF "contains($INMUX26, $mode_pin)"!][!// 
  [!VAR "cINMUX26"="number(substring-after(substring-before((substring-after($INMUX26,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 27*/!] 
[!IF "contains($INMUX27, $mode_pin)"!][!// 
  [!VAR "cINMUX27"="number(substring-after(substring-before((substring-after($INMUX27,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 28*/!] 
[!IF "contains($INMUX28, $mode_pin)"!][!// 
  [!VAR "cINMUX28"="number(substring-after(substring-before((substring-after($INMUX28,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 29*/!] 
[!IF "contains($INMUX29, $mode_pin)"!][!// 
  [!VAR "cINMUX29"="number(substring-after(substring-before((substring-after($INMUX29,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 30*/!] 
[!IF "contains($INMUX30, $mode_pin)"!][!// 
  [!VAR "cINMUX30"="number(substring-after(substring-before((substring-after($INMUX30,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 31*/!] 
[!IF "contains($INMUX31, $mode_pin)"!][!// 
  [!VAR "cINMUX31"="number(substring-after(substring-before((substring-after($INMUX31,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 32*/!] 
[!IF "contains($INMUX32, $mode_pin)"!][!// 
  [!VAR "cINMUX32"="number(substring-after(substring-before((substring-after($INMUX32,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 33*/!] 
[!IF "contains($INMUX33, $mode_pin)"!][!// 
  [!VAR "cINMUX33"="number(substring-after(substring-before((substring-after($INMUX33,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 34*/!] 
[!IF "contains($INMUX34, $mode_pin)"!][!// 
  [!VAR "cINMUX34"="number(substring-after(substring-before((substring-after($INMUX34,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 35*/!] 
[!IF "contains($INMUX35, $mode_pin)"!][!// 
  [!VAR "cINMUX35"="number(substring-after(substring-before((substring-after($INMUX35,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 36*/!] 
[!IF "contains($INMUX36, $mode_pin)"!][!// 
  [!VAR "cINMUX36"="number(substring-after(substring-before((substring-after($INMUX36,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 37*/!] 
[!IF "contains($INMUX37, $mode_pin)"!][!// 
  [!VAR "cINMUX37"="number(substring-after(substring-before((substring-after($INMUX37,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 38*/!] 
[!IF "contains($INMUX38, $mode_pin)"!][!// 
  [!VAR "cINMUX38"="number(substring-after(substring-before((substring-after($INMUX38,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 39*/!] 
[!IF "contains($INMUX39, $mode_pin)"!][!// 
  [!VAR "cINMUX39"="number(substring-after(substring-before((substring-after($INMUX39,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 40*/!] 
[!IF "contains($INMUX40, $mode_pin)"!][!// 
  [!VAR "cINMUX40"="number(substring-after(substring-before((substring-after($INMUX40,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 41*/!] 
[!IF "contains($INMUX41, $mode_pin)"!][!// 
  [!VAR "cINMUX41"="number(substring-after(substring-before((substring-after($INMUX41,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 42*/!] 
[!IF "contains($INMUX42, $mode_pin)"!][!// 
  [!VAR "cINMUX42"="number(substring-after(substring-before((substring-after($INMUX42,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 43*/!] 
[!IF "contains($INMUX43, $mode_pin)"!][!// 
  [!VAR "cINMUX43"="number(substring-after(substring-before((substring-after($INMUX43,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 44*/!] 
[!IF "contains($INMUX44, $mode_pin)"!][!// 
  [!VAR "cINMUX44"="number(substring-after(substring-before((substring-after($INMUX44,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 45*/!] 
[!IF "contains($INMUX45, $mode_pin)"!][!// 
  [!VAR "cINMUX45"="number(substring-after(substring-before((substring-after($INMUX45,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 46*/!] 
[!IF "contains($INMUX46, $mode_pin)"!][!// 
  [!VAR "cINMUX46"="number(substring-after(substring-before((substring-after($INMUX46,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 47*/!] 
[!IF "contains($INMUX47, $mode_pin)"!][!// 
  [!VAR "cINMUX47"="number(substring-after(substring-before((substring-after($INMUX47,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 48*/!] 
[!IF "contains($INMUX48, $mode_pin)"!][!// 
  [!VAR "cINMUX48"="number(substring-after(substring-before((substring-after($INMUX48,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 49*/!] 
[!IF "contains($INMUX49, $mode_pin)"!][!// 
  [!VAR "cINMUX49"="number(substring-after(substring-before((substring-after($INMUX49,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 50*/!] 
[!IF "contains($INMUX50, $mode_pin)"!][!// 
  [!VAR "cINMUX50"="number(substring-after(substring-before((substring-after($INMUX50,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 51*/!] 
[!IF "contains($INMUX51, $mode_pin)"!][!// 
  [!VAR "cINMUX51"="number(substring-after(substring-before((substring-after($INMUX51,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 52*/!] 
[!IF "contains($INMUX52, $mode_pin)"!][!// 
  [!VAR "cINMUX52"="number(substring-after(substring-before((substring-after($INMUX52,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 53*/!] 
[!IF "contains($INMUX53, $mode_pin)"!][!// 
  [!VAR "cINMUX53"="number(substring-after(substring-before((substring-after($INMUX53,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 54*/!] 
[!IF "contains($INMUX54, $mode_pin)"!][!// 
  [!VAR "cINMUX54"="number(substring-after(substring-before((substring-after($INMUX54,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 55*/!] 
[!IF "contains($INMUX55, $mode_pin)"!][!// 
  [!VAR "cINMUX55"="number(substring-after(substring-before((substring-after($INMUX55,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 56*/!] 
[!IF "contains($INMUX56, $mode_pin)"!][!// 
  [!VAR "cINMUX56"="number(substring-after(substring-before((substring-after($INMUX56,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 57*/!] 
[!IF "contains($INMUX57, $mode_pin)"!][!// 
  [!VAR "cINMUX57"="number(substring-after(substring-before((substring-after($INMUX57,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 58*/!] 
[!IF "contains($INMUX58, $mode_pin)"!][!// 
  [!VAR "cINMUX58"="number(substring-after(substring-before((substring-after($INMUX58,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 59*/!] 
[!IF "contains($INMUX59, $mode_pin)"!][!// 
  [!VAR "cINMUX59"="number(substring-after(substring-before((substring-after($INMUX59,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 60*/!] 
[!IF "contains($INMUX60, $mode_pin)"!][!// 
  [!VAR "cINMUX60"="number(substring-after(substring-before((substring-after($INMUX60,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 61*/!] 
[!IF "contains($INMUX61, $mode_pin)"!][!// 
  [!VAR "cINMUX61"="number(substring-after(substring-before((substring-after($INMUX61,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 62*/!] 
[!IF "contains($INMUX62, $mode_pin)"!][!// 
  [!VAR "cINMUX62"="number(substring-after(substring-before((substring-after($INMUX62,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 63*/!] 
[!IF "contains($INMUX63, $mode_pin)"!][!// 
  [!VAR "cINMUX63"="number(substring-after(substring-before((substring-after($INMUX63,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 64*/!] 
[!IF "contains($INMUX64, $mode_pin)"!][!// 
  [!VAR "cINMUX64"="number(substring-after(substring-before((substring-after($INMUX64,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 65*/!] 
[!IF "contains($INMUX65, $mode_pin)"!][!// 
  [!VAR "cINMUX65"="number(substring-after(substring-before((substring-after($INMUX65,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 66*/!] 
[!IF "contains($INMUX66, $mode_pin)"!][!// 
  [!VAR "cINMUX66"="number(substring-after(substring-before((substring-after($INMUX66,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 67*/!] 
[!IF "contains($INMUX67, $mode_pin)"!][!// 
  [!VAR "cINMUX67"="number(substring-after(substring-before((substring-after($INMUX67,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 68*/!] 
[!IF "contains($INMUX68, $mode_pin)"!][!// 
  [!VAR "cINMUX68"="number(substring-after(substring-before((substring-after($INMUX68,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 69*/!] 
[!IF "contains($INMUX69, $mode_pin)"!][!// 
  [!VAR "cINMUX69"="number(substring-after(substring-before((substring-after($INMUX69,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 70*/!] 
[!IF "contains($INMUX70, $mode_pin)"!][!// 
  [!VAR "cINMUX70"="number(substring-after(substring-before((substring-after($INMUX70,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 71*/!] 
[!IF "contains($INMUX71, $mode_pin)"!][!// 
  [!VAR "cINMUX71"="number(substring-after(substring-before((substring-after($INMUX71,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 72*/!] 
[!IF "contains($INMUX72, $mode_pin)"!][!// 
  [!VAR "cINMUX72"="number(substring-after(substring-before((substring-after($INMUX72,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 73*/!] 
[!IF "contains($INMUX73, $mode_pin)"!][!// 
  [!VAR "cINMUX73"="number(substring-after(substring-before((substring-after($INMUX73,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 74*/!] 
[!IF "contains($INMUX74, $mode_pin)"!][!// 
  [!VAR "cINMUX74"="number(substring-after(substring-before((substring-after($INMUX74,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 75*/!] 
[!IF "contains($INMUX75, $mode_pin)"!][!// 
  [!VAR "cINMUX75"="number(substring-after(substring-before((substring-after($INMUX75,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 76*/!] 
[!IF "contains($INMUX76, $mode_pin)"!][!// 
  [!VAR "cINMUX76"="number(substring-after(substring-before((substring-after($INMUX76,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 77*/!] 
[!IF "contains($INMUX77, $mode_pin)"!][!// 
  [!VAR "cINMUX77"="number(substring-after(substring-before((substring-after($INMUX77,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 78*/!] 
[!IF "contains($INMUX78, $mode_pin)"!][!// 
  [!VAR "cINMUX78"="number(substring-after(substring-before((substring-after($INMUX78,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 79*/!] 
[!IF "contains($INMUX79, $mode_pin)"!][!// 
  [!VAR "cINMUX79"="number(substring-after(substring-before((substring-after($INMUX79,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 80*/!] 
[!IF "contains($INMUX80, $mode_pin)"!][!// 
  [!VAR "cINMUX80"="number(substring-after(substring-before((substring-after($INMUX80,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 81*/!] 
[!IF "contains($INMUX81, $mode_pin)"!][!// 
  [!VAR "cINMUX81"="number(substring-after(substring-before((substring-after($INMUX81,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 82*/!] 
[!IF "contains($INMUX82, $mode_pin)"!][!// 
  [!VAR "cINMUX82"="number(substring-after(substring-before((substring-after($INMUX82,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 83*/!] 
[!IF "contains($INMUX83, $mode_pin)"!][!// 
  [!VAR "cINMUX83"="number(substring-after(substring-before((substring-after($INMUX83,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 84*/!] 
[!IF "contains($INMUX84, $mode_pin)"!][!// 
  [!VAR "cINMUX84"="number(substring-after(substring-before((substring-after($INMUX84,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 85*/!] 
[!IF "contains($INMUX85, $mode_pin)"!][!// 
  [!VAR "cINMUX85"="number(substring-after(substring-before((substring-after($INMUX85,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 86*/!] 
[!IF "contains($INMUX86, $mode_pin)"!][!// 
  [!VAR "cINMUX86"="number(substring-after(substring-before((substring-after($INMUX86,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 87*/!] 
[!IF "contains($INMUX87, $mode_pin)"!][!// 
  [!VAR "cINMUX87"="number(substring-after(substring-before((substring-after($INMUX87,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 88*/!] 
[!IF "contains($INMUX88, $mode_pin)"!][!// 
  [!VAR "cINMUX88"="number(substring-after(substring-before((substring-after($INMUX88,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 89*/!] 
[!IF "contains($INMUX89, $mode_pin)"!][!// 
  [!VAR "cINMUX89"="number(substring-after(substring-before((substring-after($INMUX89,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 90*/!] 
[!IF "contains($INMUX90, $mode_pin)"!][!// 
  [!VAR "cINMUX90"="number(substring-after(substring-before((substring-after($INMUX90,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 91*/!] 
[!IF "contains($INMUX91, $mode_pin)"!][!// 
  [!VAR "cINMUX91"="number(substring-after(substring-before((substring-after($INMUX91,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 92*/!] 
[!IF "contains($INMUX92, $mode_pin)"!][!// 
  [!VAR "cINMUX92"="number(substring-after(substring-before((substring-after($INMUX92,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 93*/!] 
[!IF "contains($INMUX93, $mode_pin)"!][!// 
  [!VAR "cINMUX93"="number(substring-after(substring-before((substring-after($INMUX93,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 94*/!] 
[!IF "contains($INMUX94, $mode_pin)"!][!// 
  [!VAR "cINMUX94"="number(substring-after(substring-before((substring-after($INMUX94,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 95*/!] 
[!IF "contains($INMUX95, $mode_pin)"!][!// 
  [!VAR "cINMUX95"="number(substring-after(substring-before((substring-after($INMUX95,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 96*/!] 
[!IF "contains($INMUX96, $mode_pin)"!][!// 
  [!VAR "cINMUX96"="number(substring-after(substring-before((substring-after($INMUX96,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 97*/!] 
[!IF "contains($INMUX97, $mode_pin)"!][!// 
  [!VAR "cINMUX97"="number(substring-after(substring-before((substring-after($INMUX97,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 98*/!] 
[!IF "contains($INMUX98, $mode_pin)"!][!// 
  [!VAR "cINMUX98"="number(substring-after(substring-before((substring-after($INMUX98,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 99*/!] 
[!IF "contains($INMUX99, $mode_pin)"!][!// 
  [!VAR "cINMUX99"="number(substring-after(substring-before((substring-after($INMUX99,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 100*/!] 
[!IF "contains($INMUX100, $mode_pin)"!][!// 
  [!VAR "cINMUX100"="number(substring-after(substring-before((substring-after($INMUX100,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 101*/!] 
[!IF "contains($INMUX101, $mode_pin)"!][!// 
  [!VAR "cINMUX101"="number(substring-after(substring-before((substring-after($INMUX101,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 102*/!] 
[!IF "contains($INMUX102, $mode_pin)"!][!// 
  [!VAR "cINMUX102"="number(substring-after(substring-before((substring-after($INMUX102,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 103*/!] 
[!IF "contains($INMUX103, $mode_pin)"!][!// 
  [!VAR "cINMUX103"="number(substring-after(substring-before((substring-after($INMUX103,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 104*/!] 
[!IF "contains($INMUX104, $mode_pin)"!][!// 
  [!VAR "cINMUX104"="number(substring-after(substring-before((substring-after($INMUX104,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 105*/!] 
[!IF "contains($INMUX105, $mode_pin)"!][!// 
  [!VAR "cINMUX105"="number(substring-after(substring-before((substring-after($INMUX105,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 106*/!] 
[!IF "contains($INMUX106, $mode_pin)"!][!// 
  [!VAR "cINMUX106"="number(substring-after(substring-before((substring-after($INMUX106,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 107*/!] 
[!IF "contains($INMUX107, $mode_pin)"!][!// 
  [!VAR "cINMUX107"="number(substring-after(substring-before((substring-after($INMUX107,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 108*/!] 
[!IF "contains($INMUX108, $mode_pin)"!][!// 
  [!VAR "cINMUX108"="number(substring-after(substring-before((substring-after($INMUX108,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 109*/!] 
[!IF "contains($INMUX109, $mode_pin)"!][!// 
  [!VAR "cINMUX109"="number(substring-after(substring-before((substring-after($INMUX109,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 110*/!] 
[!IF "contains($INMUX110, $mode_pin)"!][!// 
  [!VAR "cINMUX110"="number(substring-after(substring-before((substring-after($INMUX110,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 111*/!] 
[!IF "contains($INMUX111, $mode_pin)"!][!// 
  [!VAR "cINMUX111"="number(substring-after(substring-before((substring-after($INMUX111,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 112*/!] 
[!IF "contains($INMUX112, $mode_pin)"!][!// 
  [!VAR "cINMUX112"="number(substring-after(substring-before((substring-after($INMUX112,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 113*/!] 
[!IF "contains($INMUX113, $mode_pin)"!][!// 
  [!VAR "cINMUX113"="number(substring-after(substring-before((substring-after($INMUX113,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 114*/!] 
[!IF "contains($INMUX114, $mode_pin)"!][!// 
  [!VAR "cINMUX114"="number(substring-after(substring-before((substring-after($INMUX114,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 115*/!] 
[!IF "contains($INMUX115, $mode_pin)"!][!// 
  [!VAR "cINMUX115"="number(substring-after(substring-before((substring-after($INMUX115,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 116*/!] 
[!IF "contains($INMUX116, $mode_pin)"!][!// 
  [!VAR "cINMUX116"="number(substring-after(substring-before((substring-after($INMUX116,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 117*/!] 
[!IF "contains($INMUX117, $mode_pin)"!][!// 
  [!VAR "cINMUX117"="number(substring-after(substring-before((substring-after($INMUX117,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 118*/!] 
[!IF "contains($INMUX118, $mode_pin)"!][!// 
  [!VAR "cINMUX118"="number(substring-after(substring-before((substring-after($INMUX118,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 119*/!] 
[!IF "contains($INMUX119, $mode_pin)"!][!// 
  [!VAR "cINMUX119"="number(substring-after(substring-before((substring-after($INMUX119,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 120*/!] 
[!IF "contains($INMUX120, $mode_pin)"!][!// 
  [!VAR "cINMUX120"="number(substring-after(substring-before((substring-after($INMUX120,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 121*/!] 
[!IF "contains($INMUX121, $mode_pin)"!][!// 
  [!VAR "cINMUX121"="number(substring-after(substring-before((substring-after($INMUX121,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 122*/!] 
[!IF "contains($INMUX122, $mode_pin)"!][!// 
  [!VAR "cINMUX122"="number(substring-after(substring-before((substring-after($INMUX122,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 123*/!] 
[!IF "contains($INMUX123, $mode_pin)"!][!// 
  [!VAR "cINMUX123"="number(substring-after(substring-before((substring-after($INMUX123,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 124*/!] 
[!IF "contains($INMUX124, $mode_pin)"!][!// 
  [!VAR "cINMUX124"="number(substring-after(substring-before((substring-after($INMUX124,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 125*/!] 
[!IF "contains($INMUX125, $mode_pin)"!][!// 
  [!VAR "cINMUX125"="number(substring-after(substring-before((substring-after($INMUX125,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 126*/!] 
[!IF "contains($INMUX126, $mode_pin)"!][!// 
  [!VAR "cINMUX126"="number(substring-after(substring-before((substring-after($INMUX126,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 127*/!] 
[!IF "contains($INMUX127, $mode_pin)"!][!// 
  [!VAR "cINMUX127"="number(substring-after(substring-before((substring-after($INMUX127,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 128*/!] 
[!IF "contains($INMUX128, $mode_pin)"!][!// 
  [!VAR "cINMUX128"="number(substring-after(substring-before((substring-after($INMUX128,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 129*/!] 
[!IF "contains($INMUX129, $mode_pin)"!][!// 
  [!VAR "cINMUX129"="number(substring-after(substring-before((substring-after($INMUX129,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 130*/!] 
[!IF "contains($INMUX130, $mode_pin)"!][!// 
  [!VAR "cINMUX130"="number(substring-after(substring-before((substring-after($INMUX130,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 131*/!] 
[!IF "contains($INMUX131, $mode_pin)"!][!// 
  [!VAR "cINMUX131"="number(substring-after(substring-before((substring-after($INMUX131,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 132*/!] 
[!IF "contains($INMUX132, $mode_pin)"!][!// 
  [!VAR "cINMUX132"="number(substring-after(substring-before((substring-after($INMUX132,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 133*/!] 
[!IF "contains($INMUX133, $mode_pin)"!][!// 
  [!VAR "cINMUX133"="number(substring-after(substring-before((substring-after($INMUX133,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 134*/!] 
[!IF "contains($INMUX134, $mode_pin)"!][!// 
  [!VAR "cINMUX134"="number(substring-after(substring-before((substring-after($INMUX134,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 135*/!] 
[!IF "contains($INMUX135, $mode_pin)"!][!// 
  [!VAR "cINMUX135"="number(substring-after(substring-before((substring-after($INMUX135,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 136*/!] 
[!IF "contains($INMUX136, $mode_pin)"!][!// 
  [!VAR "cINMUX136"="number(substring-after(substring-before((substring-after($INMUX136,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 137*/!] 
[!IF "contains($INMUX137, $mode_pin)"!][!// 
  [!VAR "cINMUX137"="number(substring-after(substring-before((substring-after($INMUX137,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 138*/!] 
[!IF "contains($INMUX138, $mode_pin)"!][!// 
  [!VAR "cINMUX138"="number(substring-after(substring-before((substring-after($INMUX138,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 139*/!] 
[!IF "contains($INMUX139, $mode_pin)"!][!// 
  [!VAR "cINMUX139"="number(substring-after(substring-before((substring-after($INMUX139,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 140*/!] 
[!IF "contains($INMUX140, $mode_pin)"!][!// 
  [!VAR "cINMUX140"="number(substring-after(substring-before((substring-after($INMUX140,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 141*/!] 
[!IF "contains($INMUX141, $mode_pin)"!][!// 
  [!VAR "cINMUX141"="number(substring-after(substring-before((substring-after($INMUX141,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 142*/!] 
[!IF "contains($INMUX142, $mode_pin)"!][!// 
  [!VAR "cINMUX142"="number(substring-after(substring-before((substring-after($INMUX142,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 143*/!] 
[!IF "contains($INMUX143, $mode_pin)"!][!// 
  [!VAR "cINMUX143"="number(substring-after(substring-before((substring-after($INMUX143,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 144*/!] 
[!IF "contains($INMUX144, $mode_pin)"!][!// 
  [!VAR "cINMUX144"="number(substring-after(substring-before((substring-after($INMUX144,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 145*/!] 
[!IF "contains($INMUX145, $mode_pin)"!][!// 
  [!VAR "cINMUX145"="number(substring-after(substring-before((substring-after($INMUX145,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 146*/!] 
[!IF "contains($INMUX146, $mode_pin)"!][!// 
  [!VAR "cINMUX146"="number(substring-after(substring-before((substring-after($INMUX146,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!/* INMUX 147*/!] 
[!IF "contains($INMUX147, $mode_pin)"!][!// 
  [!VAR "cINMUX147"="number(substring-after(substring-before((substring-after($INMUX147,$PortPinPcr)),':'),';'))"!][!// 
[!ENDIF!][!// 
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
        (uint32)[!"num:inttohex($cINMUX0, 8)"!], /*"MSCR_MUX_0"*/ 
        (uint32)[!"num:inttohex($cINMUX1, 8)"!], /*"MSCR_MUX_1"*/ 
        (uint32)[!"num:inttohex($cINMUX2, 8)"!], /*"MSCR_MUX_2"*/ 
        (uint32)[!"num:inttohex($cINMUX3, 8)"!], /*"MSCR_MUX_3"*/ 
        (uint32)[!"num:inttohex($cINMUX4, 8)"!], /*"MSCR_MUX_4"*/ 
        (uint32)[!"num:inttohex($cINMUX5, 8)"!], /*"MSCR_MUX_5"*/ 
        (uint32)[!"num:inttohex($cINMUX6, 8)"!], /*"MSCR_MUX_6"*/ 
        (uint32)[!"num:inttohex($cINMUX7, 8)"!], /*"MSCR_MUX_7"*/ 
        (uint32)[!"num:inttohex($cINMUX8, 8)"!], /*"MSCR_MUX_8"*/ 
        (uint32)[!"num:inttohex($cINMUX9, 8)"!], /*"MSCR_MUX_9"*/ 
        (uint32)[!"num:inttohex($cINMUX10, 8)"!], /*"MSCR_MUX_10"*/ 
        (uint32)[!"num:inttohex($cINMUX11, 8)"!], /*"MSCR_MUX_11"*/ 
        (uint32)[!"num:inttohex($cINMUX12, 8)"!], /*"MSCR_MUX_12"*/ 
        (uint32)[!"num:inttohex($cINMUX13, 8)"!], /*"MSCR_MUX_13"*/ 
        (uint32)[!"num:inttohex($cINMUX14, 8)"!], /*"MSCR_MUX_14"*/ 
        (uint32)[!"num:inttohex($cINMUX15, 8)"!], /*"MSCR_MUX_15"*/ 
        (uint32)[!"num:inttohex($cINMUX16, 8)"!], /*"MSCR_MUX_16"*/ 
        (uint32)[!"num:inttohex($cINMUX17, 8)"!], /*"MSCR_MUX_17"*/ 
        (uint32)[!"num:inttohex($cINMUX18, 8)"!], /*"MSCR_MUX_18"*/ 
        (uint32)[!"num:inttohex($cINMUX19, 8)"!], /*"MSCR_MUX_19"*/ 
        (uint32)[!"num:inttohex($cINMUX20, 8)"!], /*"MSCR_MUX_20"*/ 
        (uint32)[!"num:inttohex($cINMUX21, 8)"!], /*"MSCR_MUX_21"*/ 
        (uint32)[!"num:inttohex($cINMUX22, 8)"!], /*"MSCR_MUX_22"*/ 
        (uint32)[!"num:inttohex($cINMUX23, 8)"!], /*"MSCR_MUX_23"*/ 
        (uint32)[!"num:inttohex($cINMUX24, 8)"!], /*"MSCR_MUX_24"*/ 
        (uint32)[!"num:inttohex($cINMUX25, 8)"!], /*"MSCR_MUX_25"*/ 
        (uint32)[!"num:inttohex($cINMUX26, 8)"!], /*"MSCR_MUX_26"*/ 
        (uint32)[!"num:inttohex($cINMUX27, 8)"!], /*"MSCR_MUX_27"*/ 
        (uint32)[!"num:inttohex($cINMUX28, 8)"!], /*"MSCR_MUX_28"*/ 
        (uint32)[!"num:inttohex($cINMUX29, 8)"!], /*"MSCR_MUX_29"*/ 
        (uint32)[!"num:inttohex($cINMUX30, 8)"!], /*"MSCR_MUX_30"*/ 
        (uint32)[!"num:inttohex($cINMUX31, 8)"!], /*"MSCR_MUX_31"*/ 
        (uint32)[!"num:inttohex($cINMUX32, 8)"!], /*"MSCR_MUX_32"*/ 
        (uint32)[!"num:inttohex($cINMUX33, 8)"!], /*"MSCR_MUX_33"*/ 
        (uint32)[!"num:inttohex($cINMUX34, 8)"!], /*"MSCR_MUX_34"*/ 
        (uint32)[!"num:inttohex($cINMUX35, 8)"!], /*"MSCR_MUX_35"*/ 
        (uint32)[!"num:inttohex($cINMUX36, 8)"!], /*"MSCR_MUX_36"*/ 
        (uint32)[!"num:inttohex($cINMUX37, 8)"!], /*"MSCR_MUX_37"*/ 
        (uint32)[!"num:inttohex($cINMUX38, 8)"!], /*"MSCR_MUX_38"*/ 
        (uint32)[!"num:inttohex($cINMUX39, 8)"!], /*"MSCR_MUX_39"*/ 
        (uint32)[!"num:inttohex($cINMUX40, 8)"!], /*"MSCR_MUX_40"*/ 
        (uint32)[!"num:inttohex($cINMUX41, 8)"!], /*"MSCR_MUX_41"*/ 
        (uint32)[!"num:inttohex($cINMUX42, 8)"!], /*"MSCR_MUX_42"*/ 
        (uint32)[!"num:inttohex($cINMUX43, 8)"!], /*"MSCR_MUX_43"*/ 
        (uint32)[!"num:inttohex($cINMUX44, 8)"!], /*"MSCR_MUX_44"*/ 
        (uint32)[!"num:inttohex($cINMUX45, 8)"!], /*"MSCR_MUX_45"*/ 
        (uint32)[!"num:inttohex($cINMUX46, 8)"!], /*"MSCR_MUX_46"*/ 
        (uint32)[!"num:inttohex($cINMUX47, 8)"!], /*"MSCR_MUX_47"*/ 
        (uint32)[!"num:inttohex($cINMUX48, 8)"!], /*"MSCR_MUX_48"*/ 
        (uint32)[!"num:inttohex($cINMUX49, 8)"!], /*"MSCR_MUX_49"*/ 
        (uint32)[!"num:inttohex($cINMUX50, 8)"!], /*"MSCR_MUX_50"*/ 
        (uint32)[!"num:inttohex($cINMUX51, 8)"!], /*"MSCR_MUX_51"*/ 
        (uint32)[!"num:inttohex($cINMUX52, 8)"!], /*"MSCR_MUX_52"*/ 
        (uint32)[!"num:inttohex($cINMUX53, 8)"!], /*"MSCR_MUX_53"*/ 
        (uint32)[!"num:inttohex($cINMUX54, 8)"!], /*"MSCR_MUX_54"*/ 
        (uint32)[!"num:inttohex($cINMUX55, 8)"!], /*"MSCR_MUX_55"*/ 
        (uint32)[!"num:inttohex($cINMUX56, 8)"!], /*"MSCR_MUX_56"*/ 
        (uint32)[!"num:inttohex($cINMUX57, 8)"!], /*"MSCR_MUX_57"*/ 
        (uint32)[!"num:inttohex($cINMUX58, 8)"!], /*"MSCR_MUX_58"*/ 
        (uint32)[!"num:inttohex($cINMUX59, 8)"!], /*"MSCR_MUX_59"*/ 
        (uint32)[!"num:inttohex($cINMUX60, 8)"!], /*"MSCR_MUX_60"*/ 
        (uint32)[!"num:inttohex($cINMUX61, 8)"!], /*"MSCR_MUX_61"*/ 
        (uint32)[!"num:inttohex($cINMUX62, 8)"!], /*"MSCR_MUX_62"*/ 
        (uint32)[!"num:inttohex($cINMUX63, 8)"!], /*"MSCR_MUX_63"*/ 
        (uint32)[!"num:inttohex($cINMUX64, 8)"!], /*"MSCR_MUX_64"*/ 
        (uint32)[!"num:inttohex($cINMUX65, 8)"!], /*"MSCR_MUX_65"*/ 
        (uint32)[!"num:inttohex($cINMUX66, 8)"!], /*"MSCR_MUX_66"*/ 
        (uint32)[!"num:inttohex($cINMUX67, 8)"!], /*"MSCR_MUX_67"*/ 
        (uint32)[!"num:inttohex($cINMUX68, 8)"!], /*"MSCR_MUX_68"*/ 
        (uint32)[!"num:inttohex($cINMUX69, 8)"!], /*"MSCR_MUX_69"*/ 
        (uint32)[!"num:inttohex($cINMUX70, 8)"!], /*"MSCR_MUX_70"*/ 
        (uint32)[!"num:inttohex($cINMUX71, 8)"!], /*"MSCR_MUX_71"*/ 
        (uint32)[!"num:inttohex($cINMUX72, 8)"!], /*"MSCR_MUX_72"*/ 
        (uint32)[!"num:inttohex($cINMUX73, 8)"!], /*"MSCR_MUX_73"*/ 
        (uint32)[!"num:inttohex($cINMUX74, 8)"!], /*"MSCR_MUX_74"*/ 
        (uint32)[!"num:inttohex($cINMUX75, 8)"!], /*"MSCR_MUX_75"*/ 
        (uint32)[!"num:inttohex($cINMUX76, 8)"!], /*"MSCR_MUX_76"*/ 
        (uint32)[!"num:inttohex($cINMUX77, 8)"!], /*"MSCR_MUX_77"*/ 
        (uint32)[!"num:inttohex($cINMUX78, 8)"!], /*"MSCR_MUX_78"*/ 
        (uint32)[!"num:inttohex($cINMUX79, 8)"!], /*"MSCR_MUX_79"*/ 
        (uint32)[!"num:inttohex($cINMUX80, 8)"!], /*"MSCR_MUX_80"*/ 
        (uint32)[!"num:inttohex($cINMUX81, 8)"!], /*"MSCR_MUX_81"*/ 
        (uint32)[!"num:inttohex($cINMUX82, 8)"!], /*"MSCR_MUX_82"*/ 
        (uint32)[!"num:inttohex($cINMUX83, 8)"!], /*"MSCR_MUX_83"*/ 
        (uint32)[!"num:inttohex($cINMUX84, 8)"!], /*"MSCR_MUX_84"*/ 
        (uint32)[!"num:inttohex($cINMUX85, 8)"!], /*"MSCR_MUX_85"*/ 
        (uint32)[!"num:inttohex($cINMUX86, 8)"!], /*"MSCR_MUX_86"*/ 
        (uint32)[!"num:inttohex($cINMUX87, 8)"!], /*"MSCR_MUX_87"*/ 
        (uint32)[!"num:inttohex($cINMUX88, 8)"!], /*"MSCR_MUX_88"*/ 
        (uint32)[!"num:inttohex($cINMUX89, 8)"!], /*"MSCR_MUX_89"*/ 
        (uint32)[!"num:inttohex($cINMUX90, 8)"!], /*"MSCR_MUX_90"*/ 
        (uint32)[!"num:inttohex($cINMUX91, 8)"!], /*"MSCR_MUX_91"*/ 
        (uint32)[!"num:inttohex($cINMUX92, 8)"!], /*"MSCR_MUX_92"*/ 
        (uint32)[!"num:inttohex($cINMUX93, 8)"!], /*"MSCR_MUX_93"*/ 
        (uint32)[!"num:inttohex($cINMUX94, 8)"!], /*"MSCR_MUX_94"*/ 
        (uint32)[!"num:inttohex($cINMUX95, 8)"!], /*"MSCR_MUX_95"*/ 
        (uint32)[!"num:inttohex($cINMUX96, 8)"!], /*"MSCR_MUX_96"*/ 
        (uint32)[!"num:inttohex($cINMUX97, 8)"!], /*"MSCR_MUX_97"*/ 
        (uint32)[!"num:inttohex($cINMUX98, 8)"!], /*"MSCR_MUX_98"*/ 
        (uint32)[!"num:inttohex($cINMUX99, 8)"!], /*"MSCR_MUX_99"*/ 
        (uint32)[!"num:inttohex($cINMUX100, 8)"!], /*"MSCR_MUX_100"*/ 
        (uint32)[!"num:inttohex($cINMUX101, 8)"!], /*"MSCR_MUX_101"*/ 
        (uint32)[!"num:inttohex($cINMUX102, 8)"!], /*"MSCR_MUX_102"*/ 
        (uint32)[!"num:inttohex($cINMUX103, 8)"!], /*"MSCR_MUX_103"*/ 
        (uint32)[!"num:inttohex($cINMUX104, 8)"!], /*"MSCR_MUX_104"*/ 
        (uint32)[!"num:inttohex($cINMUX105, 8)"!], /*"MSCR_MUX_105"*/ 
        (uint32)[!"num:inttohex($cINMUX106, 8)"!], /*"MSCR_MUX_106"*/ 
        (uint32)[!"num:inttohex($cINMUX107, 8)"!], /*"MSCR_MUX_107"*/ 
        (uint32)[!"num:inttohex($cINMUX108, 8)"!], /*"MSCR_MUX_108"*/ 
        (uint32)[!"num:inttohex($cINMUX109, 8)"!], /*"MSCR_MUX_109"*/ 
        (uint32)[!"num:inttohex($cINMUX110, 8)"!], /*"MSCR_MUX_110"*/ 
        (uint32)[!"num:inttohex($cINMUX111, 8)"!], /*"MSCR_MUX_111"*/ 
        (uint32)[!"num:inttohex($cINMUX112, 8)"!], /*"MSCR_MUX_112"*/ 
        (uint32)[!"num:inttohex($cINMUX113, 8)"!], /*"MSCR_MUX_113"*/ 
        (uint32)[!"num:inttohex($cINMUX114, 8)"!], /*"MSCR_MUX_114"*/ 
        (uint32)[!"num:inttohex($cINMUX115, 8)"!], /*"MSCR_MUX_115"*/ 
        (uint32)[!"num:inttohex($cINMUX116, 8)"!], /*"MSCR_MUX_116"*/ 
        (uint32)[!"num:inttohex($cINMUX117, 8)"!], /*"MSCR_MUX_117"*/ 
        (uint32)[!"num:inttohex($cINMUX118, 8)"!], /*"MSCR_MUX_118"*/ 
        (uint32)[!"num:inttohex($cINMUX119, 8)"!], /*"MSCR_MUX_119"*/ 
        (uint32)[!"num:inttohex($cINMUX120, 8)"!], /*"MSCR_MUX_120"*/ 
        (uint32)[!"num:inttohex($cINMUX121, 8)"!], /*"MSCR_MUX_121"*/ 
        (uint32)[!"num:inttohex($cINMUX122, 8)"!], /*"MSCR_MUX_122"*/ 
        (uint32)[!"num:inttohex($cINMUX123, 8)"!], /*"MSCR_MUX_123"*/ 
        (uint32)[!"num:inttohex($cINMUX124, 8)"!], /*"MSCR_MUX_124"*/ 
        (uint32)[!"num:inttohex($cINMUX125, 8)"!], /*"MSCR_MUX_125"*/ 
        (uint32)[!"num:inttohex($cINMUX126, 8)"!], /*"MSCR_MUX_126"*/ 
        (uint32)[!"num:inttohex($cINMUX127, 8)"!], /*"MSCR_MUX_127"*/ 
        (uint32)[!"num:inttohex($cINMUX128, 8)"!], /*"MSCR_MUX_128"*/ 
        (uint32)[!"num:inttohex($cINMUX129, 8)"!], /*"MSCR_MUX_129"*/ 
        (uint32)[!"num:inttohex($cINMUX130, 8)"!], /*"MSCR_MUX_130"*/ 
        (uint32)[!"num:inttohex($cINMUX131, 8)"!], /*"MSCR_MUX_131"*/ 
        (uint32)[!"num:inttohex($cINMUX132, 8)"!], /*"MSCR_MUX_132"*/ 
        (uint32)[!"num:inttohex($cINMUX133, 8)"!], /*"MSCR_MUX_133"*/ 
        (uint32)[!"num:inttohex($cINMUX134, 8)"!], /*"MSCR_MUX_134"*/ 
        (uint32)[!"num:inttohex($cINMUX135, 8)"!], /*"MSCR_MUX_135"*/ 
        (uint32)[!"num:inttohex($cINMUX136, 8)"!], /*"MSCR_MUX_136"*/ 
        (uint32)[!"num:inttohex($cINMUX137, 8)"!], /*"MSCR_MUX_137"*/ 
        (uint32)[!"num:inttohex($cINMUX138, 8)"!], /*"MSCR_MUX_138"*/ 
        (uint32)[!"num:inttohex($cINMUX139, 8)"!], /*"MSCR_MUX_139"*/ 
        (uint32)[!"num:inttohex($cINMUX140, 8)"!], /*"MSCR_MUX_140"*/ 
        (uint32)[!"num:inttohex($cINMUX141, 8)"!], /*"MSCR_MUX_141"*/ 
        (uint32)[!"num:inttohex($cINMUX142, 8)"!], /*"MSCR_MUX_142"*/ 
        (uint32)[!"num:inttohex($cINMUX143, 8)"!], /*"MSCR_MUX_143"*/ 
        (uint32)[!"num:inttohex($cINMUX144, 8)"!], /*"MSCR_MUX_144"*/ 
        (uint32)[!"num:inttohex($cINMUX145, 8)"!], /*"MSCR_MUX_145"*/ 
        (uint32)[!"num:inttohex($cINMUX146, 8)"!], /*"MSCR_MUX_146"*/
        (uint32)[!"num:inttohex($cINMUX147, 8)"!], /*"MSCR_MUX_147"*/

};
[!ENDSELECT!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_ConfigPinParameter                     */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "Port_ConfigPinParameter", "Type"!][!//
[!VAR "maxConfig"!][!IF "$Type = 'PC'"!][!"num:i('1')"!][!ELSE!][!"num:i(count(PortConfigSet/*))"!][!ENDIF!][!ENDVAR!]

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
[!VAR "pincount"="num:i(0)"!][!//
[!LOOP "PortConfigSet/PortContainer/*/PortPin/*"!][!//
[!IF "node:exists(PortInterruptSource)"!][!//
[!VAR "pincount" = "$pincount+1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
#if (PORT_SET_SIUL2_API == STD_ON)
static CONST(Port_siul2_request_config, PORT_CONST) Port_Siul2_config[[!"num:i($pincount)"!]] =
{
    [!INDENT "4"!][!LOOP "PortConfigSet/PortContainer/*/PortPin/*"!][!//
    [!IF "node:exists(PortInterruptSource)"!][!//
    {
        [!WS "4"!].eirq_index = ([!"PortInterruptSource/eirq_index"!]),/* eirq Interrupt number */
        [!WS "4"!].event_edge_sel = ([!"PortInterruptSource/event_edge_sel"!]),/* Select trigger source along events */
        [!WS "4"!].eirq_cb = ([!IF "node:exists(PortInterruptSource/eirq_callback)"!][!IF "(PortInterruptSource/eirq_callback != '')
         and (PortInterruptSource/eirq_callback != 'NULL_PTR') and (PortInterruptSource/eirq_callback != 'NULL')"!]&[!"PortInterruptSource/eirq_callback"!][!ELSE!]NULL_PTR[!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!]), /* callback notification */
    },
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!ENDINDENT!]
};
#endif
[!LOOP "PortConfigSet/*[@index < $maxConfig]"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the [!IF "$Type = 'PB'"!]post-build mode [!"@name"!][!ELSE!]pre-compiled mode[!ENDIF!]
[!IF "$Type = 'PB'"!]* @violates @ref PORT_PBCFG_REF_4 Violates MISRA 2004 Required Rule 8.10[!ENDIF!]
*/
CONST(Port_ConfigType, PORT_CONST) [!IF "$Type = 'PB'"!][!"@name"!][!ELSE!]Port_ConfigPC[!ENDIF!] =
{
      .Port_UsedPin={
            PORT_MAX_CONFIGURED_PADS[!IF "$Type = 'PB'"!][!ENDIF!]_U16,
            Port_aPinConfigDefault[!IF "$Type = 'PB'"!]PB[!ENDIF!],
            Port_aPadSelConfigDefault[!IF "$Type = 'PB'"!]PB[!ENDIF!]
        },
        .Port_UnusedPin={
            PORT_MAX_UNUSED_PADS[!IF "$Type = 'PB'"!][!ENDIF!]_U16,
    #if (PORT_MAX_UNUSED_PADS[!IF "$Type = 'PB'"!][!ENDIF!]_U16 != 0U)
      Port_au16NoUnUsedPadsArrayDefault[!IF "$Type = 'PB'"!][!ENDIF!],
    #else
      NULL_PTR,
    #endif
            &Port_UnUsedPin[!IF "$Type = 'PB'"!][!ENDIF!]
        },
        .Etpu_IS=u8Port_Etpu_Input_Select,
        .coreMap = Port_CoreMap,
#if (PORT_SET_SIUL2_API == STD_ON)
        .reqConfig = Port_Siul2_config
#endif
};
[!ENDLOOP!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_ParameterArrays                             */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "Port_ParameterArrays", "Type"!][!//
#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief Port INOUT settings data
*/
CONST(Port_InoutSettingType,PORT_CONST) Port_aPadFunctInoutMuxSettings[PORT_INOUT_TABLE_NUM_ENTRIES_U16] = 
{
[!"$INOUT_SETTINGS_1"!]
};

/**
* @brief Port INPUT INMUX settings data
*/
CONST(Port_InMuxSettingType,PORT_CONST) Port_aPadFunctInMuxSettings[]=
{
[!"$INPUT_INMUX_1"!]
};


/**
* @brief Port INOUT settings data
*/

/**
* @brief Port INPUT INMUX settings data
*/

#endif 

[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_ParameterArrays_2                             */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "Port_ParameterArrays_2", "Type"!][!//
#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief Port Pin description data
*/
CONST (uint16, PORT_CONST) Port_au16PinDescription[[!"ecu:get('PortPadModeNumber')"!]][[!"ecu:get('PortPin16BlocksNo')"!]] =
{
[!"$CHECK_1"!]
};

/**
* @brief Port index to address the INPUT INDEX data
*/  
CONST(uint16,PORT_CONST) Port_au16PadFunctInMuxIndex[[!"ecu:get('PortModeSettingsLinesNo')"!]]=
{
[!"$INPUT_INDEX_1"!]
};

/**
* @brief Port Pin description data
*/

/**
* @brief Port index to address the INPUT INDEX data
*/

#endif 
[!ENDMACRO!][!//

[!ENDIF!][!//
