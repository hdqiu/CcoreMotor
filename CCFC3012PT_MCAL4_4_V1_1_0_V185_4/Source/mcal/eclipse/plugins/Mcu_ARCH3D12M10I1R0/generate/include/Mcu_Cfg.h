/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
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
*   @file    Mcu_Cfg.c
*   @version 1.0.1
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==============================================INCLUDE FILES=======================================*/

#include "Mcal.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define MCU_CFG_VENDOR_ID                    176
#define MCU_CFG_AR_MAJOR_VER                 4
#define MCU_CFG_AR_MINOR_VER                 4
#define MCU_CFG_AR_PATCH_VER                 0
#define MCU_CFG_SW_MAJOR_VER                 1
#define MCU_CFG_SW_MINOR_VER                 0
#define MCU_CFG_SW_PATCH_VER                 1

#define MCU_MODULE_ID                        101

/*============================================FILE VERSION CHECKS===================================*/

#if (MCU_CFG_VENDOR_ID != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : MCAL_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_CFG_AR_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MAJOR_VER"
#endif
#if (MCU_CFG_AR_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_MINOR_VER"
#endif
#if (MCU_CFG_AR_PATCH_VER != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : MCAL_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_CFG_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MAJOR_VER"
#endif
#if (MCU_CFG_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_MINOR_VER"
#endif
#if (MCU_CFG_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : MCAL_SW_PATCH_VER"
#endif


/*==================================================================================================
DEFINES
==================================================================================================*/
[!NOCODE!]
[!CODE!]#define MCU_HARDVER                         [!ENDCODE!]
[!IF "McuGeneralConfiguration/Mcu_HardwareVersion = 'CCFC3007PT'"!]
[!CODE!]2[!ENDCODE!]
[!ELSEIF "McuGeneralConfiguration/Mcu_HardwareVersion = 'CCFC3008PT'"!]
[!CODE!]3[!ENDCODE!]
[!ELSEIF "McuGeneralConfiguration/Mcu_HardwareVersion = 'CCFC3007BC'"!]
[!CODE!]4[!ENDCODE!]
[!ELSEIF "McuGeneralConfiguration/Mcu_HardwareVersion = 'CCFC3012PT'"!]
[!CODE!]5[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#define MCU_CONFIG_TYPE_PB                          [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#define MCU_DEV_ERROR_DETECT                        [!IF "McuGeneralConfiguration/McuDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define MCU_DISABLE_DEM_REPORT_ERROR_STATUS         [!IF "(num:i(count(McuModuleConfiguration/McuDemEventParameterRefs/*)) = num:i(0))"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#define MCU_INIT_CLOCK                              [!IF "McuGeneralConfiguration/McuInitClock = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define MCU_NO_PLL                                  [!IF "McuGeneralConfiguration/McuNoPll = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define MCU_PERFORM_RESET_API                       [!IF "McuGeneralConfiguration/McuPerformResetApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define MCU_GET_RAM_STATE_API                       [!IF "McuGeneralConfiguration/McuGetRamStateApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define MCU_VERSION_INFO_API                        [!IF "McuGeneralConfiguration/McuVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#define MC_ME_RUN_CONFIG_COUNT                      [!"num:i(count(McuModuleConfiguration/McuRunConfig/*))"!]
#define MC_ME_LOWPOWER_CONFIG_COUNT                 [!"num:i(count(McuModuleConfiguration/McuLowPowerConfig/*))"!]
#define MC_ME_PERIPH_CONFIG_COUNT                   [!"num:i(count(McuModuleConfiguration/McuPeripheralConfig/*))"!]
#define MC_ME_PERIPH_INSTANCE_COUNT                 [!"num:i(count(ecu:list('MCU.PerSource.List')))"!]

#define MCU_PERIRESET_COUNT                         [!"num:i(count(McuModuleConfiguration/McuResetSetting/*))"!]

#define CMU_INSTANCE_COUNT                          13U

#define MCU_CLOCKS_FAILURE_EN                       [!IF "McuModuleConfiguration/McuClockSrcFailureNotification = 'ENABLED'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#define MCU_FCCU_ENABLE                             [!IF "num:i(count(McuModuleConfiguration/FccuConfigSet/Fault/*)) != num:i(0)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#define MCU_TIMEOUT_LOOPS                           ((uint32)[!"num:i(McuGeneralConfiguration/McuTimeout)"!]U)

#define MCU_XOSC_FREQ                               ((uint32)[!"num:i(McuModuleConfiguration/McuCrystalFrequencyHz)"!]U)

/* FCCU Operation Timeout definition */
#define FCCU_OP_TIMEOUT_CONFIG                       0xFFFFFFFFU

#define FCCU_MAX_FAULTS_NO                           128U

#define FCCU_RF_MAX_GROUP                            4U

/* Control register key macros */                 
#define FCCU_RECOVERABLE_FAULT_KEY                   0xAB3498FEU
#define FCCU_UNLOCK_OP1_KEY                          0x913756AFU
#define FCCU_UNLOCK_OP2_KEY                          0x825A132BU

/* Transition Unlocking Key value */                 
#define FCCU_TRANSKEY_UNLOCK_VAL                     0xBCU
#define FCCU_TRANSKEY_LOCK_VAL                       0xFFU

/* Transition Locking Key value */                 
#define FCCU_PERMENTKEY_LOCK_VAL                     0xFFU


[!SELECT "McuModuleConfiguration"!]
/**
*             Create defines with the IDs assigned to Mcu Clock configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitClock() API.
*/
[!LOOP "McuClockSettingConfig/*"!]

#define [!"name(.)"!]   ((Mcu_ClockType)[!"num:i(McuClockSettingId)"!]U)

#define McuConf_McuClockSettingConfig_[!"name(.)"!]   ((Mcu_ClockType)[!"num:i(McuClockSettingId)"!]U) 
[!ENDLOOP!]

/**
*             Create defines with the IDs assigned to Mcu Mode configurations.
*                   These IDs will be transmitted as input parameters for Mcu_SetMode() API.
*/[!LOOP "McuModeSettingConf/*"!]

#define [!"name(.)"!]   ((Mcu_ModeType)[!"num:i(McuModeId)"!]U)

#define McuConf_McuModeSettingConf_[!"name(.)"!]   ((Mcu_ModeType)[!"num:i(McuModeId)"!]U)
[!ENDLOOP!]

/**
*             Create defines with the IDs assigned to Mcu RAM Section configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitRamSection() API.
*/
[!LOOP "McuRamSectorSettingConf/*"!]

#define [!"name(.)"!]   ((Mcu_RamSectionType)[!"num:i(McuRamSectorId)"!]U)

#define McuConf_McuRamSectorSettingConf_[!"name(.)"!]   ((Mcu_RamSectionType)[!"num:i(McuRamSectorId)"!]U)
[!ENDLOOP!]

[!ENDSELECT!]

#include "Mcu.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

#define MCU_PB_CONFIG_DECLARATION   extern CONST(Mcu_ConfigType, MCU_CONST) McuModuleConfiguration;

#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif