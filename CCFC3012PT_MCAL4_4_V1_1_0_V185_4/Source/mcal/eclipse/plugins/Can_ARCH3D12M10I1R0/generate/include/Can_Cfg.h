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
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Can_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/

#ifndef CAN_CFG_H_
#define CAN_CFG_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "StandardTypes.h"
#include "Mcal.h"

#define CAN_CFG_H_VENDOR_ID                     176
#define CAN_CFG_H_AR_REL_MAJOR_VER              4
#define CAN_CFG_H_AR_REL_MINOR_VER              4
#define CAN_CFG_H_AR_REL_REV_VER                0
#define CAN_CFG_H_SW_MAJOR_VER                  1
#define CAN_CFG_H_SW_MINOR_VER                  0
#define CAN_CFG_H_SW_PATCH_VER                  1

#if (MCAL_VENDOR_ID != CAN_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_CFG_H_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CAN_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CAN_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CAN_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CAN_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CAN_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CAN_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_CFG_H_SW_PATCH_VER "
#endif

[!AUTOSPACING!]

#define CAN_PRECOMPILE_SUPPORT[!WS "4"!][!//
[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!][!//
(STD_ON)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!]

#define CAN_MULTICORE_ENABLED[!WS "4"!][!IF "(CanGeneral/CanMulticoreSupport = 'true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

[!VAR "check_wakeup_en" = "num:i(0)"!]
[!LOOP "CanConfigSet/CanController/*"!]
    [!IF "(CanWakeupFunctionalityAPI = 'true')"!]
        [!VAR "check_wakeup_en" = "num:i(1)"!]
    [!ENDIF!]
[!ENDLOOP!]
#define CAN_CHECK_WAKEUP_API [!WS "4"!][!IF "($check_wakeup_en = num:i(1))"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

#define CAN_FD_MODE_ENABLE[!WS "4"!][!//
[!IF "node:exists(CanConfigSet/CanController/*/CanControllerBaudrateConfig/*/CanControllerFdBaudrateConfig/*)"!]
(STD_ON)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!]

[!SELECT "CanGeneral"!][!//
#define CAN_DEV_ERROR_DETECT[!WS "4"!][!//
[!IF "CanDevErrorDetect = 'true'"!]
(STD_ON)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!]

#define CAN_VERSION_INFO_API[!WS "4"!][!//
[!IF "CanVersionInfoApi = 'true'"!]
(STD_ON)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!]

#define CAN_INSTANCE[!WS "4"!]([!"num:i(CanIndex)"!]U)

[!IF "node:exists(CanMainFunctionBusoffPeriod)"!][!//
#define CAN_MAINFUNCTION_BUSOFF_PERIOD[!WS "4"!]([!"num:i(CanMainFunctionBusoffPeriod)"!]U)
[!ENDIF!][!//

[!IF "node:exists(CanMainFunctionModePeriod)"!][!//
#define CAN_MAINFUNCTION_MODE_PERIOD[!WS "4"!]([!"num:i(CanMainFunctionModePeriod)"!]U)
[!ENDIF!][!//

[!IF "node:exists(CanMainFunctionWakeupPeriod)"!][!//
#define CAN_MAINFUNCTION_WAKEUP_PERIOD[!WS "4"!]([!"num:i(CanMainFunctionWakeupPeriod)"!]U)
[!ENDIF!][!//

#define CAN_MULTIPLEXED_TRANSMISSION[!WS "4"!][!//
[!IF "CanMultiplexedTransmission = 'true'"!]
(STD_ON)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!]

#define CAN_SET_BAUDRATE_API [!WS "4"!][!IF "(CanSetBaudrateApi = 'true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

[!NOCODE!]
[!VAR "busoff_pol_en" = "0"!]
[!VAR "wakeup_pol_en" = "0"!]
[!VAR "wakeup_en" = "0"!]
[!LOOP "../CanConfigSet/CanController/*"!]
    [!IF "CanBusoffProcessing = 'POLLING'"!]
        [!VAR "busoff_pol_en" = "1"!]
    [!ENDIF!]
    [!IF "CanWakeupProcessing = 'POLLING' and CanWakeupSupport = 'true'"!]
        [!VAR "wakeup_pol_en" = "1"!]
    [!ENDIF!]
    [!IF "CanWakeupSupport = 'true'"!]
        [!VAR "wakeup_en" = "1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
#define CAN_MAINFUNCTION_BUSOFF_API [!WS "4"!][!IF "$busoff_pol_en = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define CAN_MAINFUNCTION_WAKEUP_API [!WS "4"!][!IF "$wakeup_pol_en = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define CAN_WAKEUP_SUPPORT [!WS "4"!][!IF "$wakeup_en = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
/* The unit is us. */
[!IF "node:exists(CanOsCounterRef)"!]
#define CAN_TIMEOUT_DURATION [!WS "4"!][!"num:i(CanTimeoutDuration * 1000000)"!]U[!CR!]
[!ELSE!]
    [!SELECT "node:ref(CanOsCounterRef)"!]
#define CAN_TIMEOUT_COUNTER_NAME    [!"@name"!]
#define CAN_TIMEOUT_USE_OS [!WS "4"!](STD_ON)
#define CAN_TIMEOUT_COUNTER_TICK2NS()    OS_TICKS2NS_[!"@name"!](1U)
    [!ENDSELECT!]
/* The unit is ns. */
#define CAN_TIMEOUT_DURATION [!WS "4"!][!"CanTimeoutDuration * 1000000000"!]F[!CR!]
[!ENDIF!]

[!IF "num:i(count(CanMainFunctionRWPeriods/*)) = 1"!][!//
#define CAN_MAINFUNCTION_PERIOD         ([!"CanMainFunctionRWPeriods/*[1]/CanMainFunctionPeriod"!]F)
#define CAN_MAINFUNCTION_PERIOD_READ    ([!"CanMainFunctionRWPeriods/*[1]/CanMainFunctionPeriod"!]F)
#define CAN_MULTIPLE_READ_PERIOD        (STD_OFF)
#define CAN_MAINFUNCTION_PERIOD_WRITE   ([!"CanMainFunctionRWPeriods/*[1]/CanMainFunctionPeriod"!]F)
#define CAN_MULTIPLE_WRITE_PERIOD       (STD_OFF)
[!ELSE!][!//
#define CAN_MULTIPLE_READ_PERIOD   (STD_ON)
#define CAN_MULTIPLE_WRITE_PERIOD  (STD_ON)
[!LOOP "CanMainFunctionRWPeriods/*"!][!//
#define CAN_MAINFUNCTION_RW_PERIOD_[!"@index"!]            ([!"CanMainFunctionPeriod"!]F)
#define CAN_MAINFUNCTION_PERIOD_READ_[!"@index"!]       ([!"CanMainFunctionPeriod"!]F)
#define CAN_MAINFUNCTION_PERIOD_WRITE_[!"@index"!]      ([!"CanMainFunctionPeriod"!]F)
[!ENDLOOP!][!//
[!ENDIF!][!//
[!//
[!ENDSELECT!][!// SELECT "CanGeneral"
[!NOCODE!][!//
[!VAR "tx_pol_en" = "0"!]
[!VAR "rx_pol_en" = "0"!]
[!VAR "int_en" = "0"!]
[!VAR "CanTriggerTransmitEnable_en" = "0"!]
[!ENDNOCODE!][!//
[!SELECT "CanConfigSet"!][!//
#define CAN_CONTROLLER_COUNT    [!"num:i(count(CanController/*))"!]U
[!NOCODE!][!//
[!LOOP "CanHardwareObject/*"!][!//
    [!IF "node:value(CanTriggerTransmitEnable) = 'true'"!]
        [!VAR "CanTriggerTransmitEnable_en" = "1"!]
    [!ENDIF!]
    [!IF "(((node:exists(CanHardwareObjectUsesPolling) and node:value(CanHardwareObjectUsesPolling) = 'true') or node:ref(CanControllerRef)/CanRxProcessing != 'INTERRUPT') and node:value(CanObjectType) = 'RECEIVE')"!]
        [!VAR "rx_pol_en" = "1"!]
    [!ELSEIF "(((node:exists(CanHardwareObjectUsesPolling) and node:value(CanHardwareObjectUsesPolling) = 'true') or node:ref(CanControllerRef)/CanTxProcessing != 'INTERRUPT') and node:value(CanObjectType) = 'TRANSMIT')"!]
        [!VAR "tx_pol_en" = "1"!]
    [!ELSE!]
        [!VAR "int_en" = "1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!][!//
#define CAN_MAINFUNCTION_WRITE_API [!WS "4"!][!IF "$tx_pol_en = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define CAN_MAINFUNCTION_READ_API [!WS "4"!][!IF "$rx_pol_en = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]
#define CAN_TRIGGER_TRANSMIT_EN [!WS "4"!][!IF "$CanTriggerTransmitEnable_en = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!]

[!VAR "HardwareObjectCnt1" = "0"!]
[!VAR "HardwareObjectCnt0" = "0"!]
[!LOOP "CanHardwareObject/*"!]
    [!VAR "HardwareObjectCnt1" = "$HardwareObjectCnt1 + num:i(CanHwObjectCount)"!]
    [!VAR "HardwareObjectCnt0" = "$HardwareObjectCnt0 + num:i(1)"!]
[!ENDLOOP!]
#define CAN_MB_COUNT       [!"num:i($HardwareObjectCnt1)"!]U
#define CAN_HOH_CNT_MAX    [!"num:i($HardwareObjectCnt0)"!]U
#define CAN_DEFAULT_COREID [!"num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]U
[!ENDSELECT!]

[!LOOP "node:order(CanConfigSet/CanHardwareObject/*, 'CanObjectId')"!]
    [!CODE!]#define [!"@name"!][!WS "4"!][!"num:i(CanObjectId)"!]U  /* [!"CanObjectType"!] object of Controller Id [!"node:ref(CanControllerRef)/CanControllerId"!] */[!ENDCODE!][!CR!]
[!ENDLOOP!]

[!LOOP "node:order(CanConfigSet/CanController/*, 'CanControllerId')"!]
    [!CODE!]#define [!"@name"!][!WS "4"!][!"num:i(CanControllerId)"!]U  /* [!"CanHwChannel"!] */[!ENDCODE!][!CR!]
[!ENDLOOP!]

[!SELECT "CanGeneral"!]
    [!IF "node:exists(CanLPduReceiveCalloutFunction)"!]
        [!IF "(normalize-space(CanLPduReceiveCalloutFunction) != 'NULL_PTR')"!]
#define CanLPduReceiveCalloutFunction     ([!"normalize-space(CanLPduReceiveCalloutFunction)"!])

        [!ENDIF!]
    [!ENDIF!]
[!ENDSELECT!]
#define CAN_PB_CONFIG_DECLARATION   extern CONST(Can_ConfigType, CAN_VAR) Can_Config;

#ifdef __cplusplus
}
#endif

#endif /* CAN_CFG_H_ */
