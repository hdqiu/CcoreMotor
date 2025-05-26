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
*   @file    Mcu_PBcfg.c
*   @version 1.0.1
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================INCLUDE FILES=======================================*/

#include "Mcu_Cfg.h"
#include "Mcu.h"
#include "Mcu_LLDriver.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define MCU_PB_VENDOR_ID_C                 176
#define MCU_PB_AR_MAJOR_VER_C              4
#define MCU_PB_AR_MINOR_VER_C              4
#define MCU_PB_AR_PATCH_VER_C              0
#define MCU_PB_SW_MAJOR_VER_C              1
#define MCU_PB_SW_MINOR_VER_C              0
#define MCU_PB_SW_PATCH_VER_C              1

/*============================================FILE VERSION CHECKS===================================*/

#if (MCU_PB_VENDOR_ID_C != MCU_CFG_VENDOR_ID)
#error "NON-MATCHED DATA : MCU_CFG_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_PB_AR_MAJOR_VER_C != MCU_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_MAJOR_VER"
#endif
#if (MCU_PB_AR_MINOR_VER_C != MCU_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_MINOR_VER"
#endif
#if (MCU_PB_AR_PATCH_VER_C != MCU_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : MCU_CFG_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_PB_SW_MAJOR_VER_C != MCU_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_MAJOR_VER"
#endif
#if (MCU_PB_SW_MINOR_VER_C != MCU_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_MINOR_VER"
#endif
#if (MCU_PB_SW_PATCH_VER_C != MCU_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : MCU_CFG_SW_PATCH_VER"
#endif
[!AUTOSPACING!]

[!IF "McuGeneralConfiguration/Mcu_HardwareVersion = 'CCFC3007PT'"!]
[!VAR "MCU_HARDVAR" = "num:i(2)"!]
[!ELSEIF "McuGeneralConfiguration/Mcu_HardwareVersion = 'CCFC3008PT'"!]
[!VAR "MCU_HARDVAR" = "num:i(3)"!]
[!ELSEIF "McuGeneralConfiguration/Mcu_HardwareVersion = 'CCFC3007BC'"!]
[!VAR "MCU_HARDVAR" = "num:i(4)"!]
[!ELSEIF "McuGeneralConfiguration/Mcu_HardwareVersion = 'CCFC3012PT'"!]
[!VAR "MCU_HARDVAR" = "num:i(5)"!]
[!ELSE!]
[!VAR "MCU_HARDVAR" = "num:i(0)"!]
[!ENDIF!]

/* MCU_HARDVAR [!"num:i($MCU_HARDVAR)"!] */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

[!SELECT "McuModuleConfiguration"!]

    [!IF "McuClockSrcFailureNotification = 'true'"!]
    [!IF "McuClockFailureNotification != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuClockFailureNotification"!](void);
    [!ENDIF!]
    [!ENDIF!]

    [!IF "McuXoscInterruptEn = 'true'"!]
    [!IF "McuXoscStartupNotification != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuXoscStartupNotification"!](void);
    [!ENDIF!]
    [!ENDIF!]

    [!IF "McuFailOfChangeModeNotification != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuFailOfChangeModeNotification"!](void);
    [!ENDIF!]

    [!SELECT "McuMcmeInterrupt"!]
    [!IF "McuInvalidConfigurationIntEn_Core = 'true'"!]
    [!IF "McuInvalidConfigurationNotification_Core != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuInvalidConfigurationNotification_Core"!](void);
    [!ENDIF!]
    [!ENDIF!]
    [!IF "McuInvalidConfigurationIntEn = 'true'"!]
    [!IF "McuInvalidConfigurationNotification_Clock != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuInvalidConfigurationNotification_Clock"!](void);
    [!ENDIF!]
    [!ENDIF!]
    [!IF "McuInvalidConfigurationIntEn_Clock = 'true'"!]
    [!IF "McuInvalidConfigurationNotification != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuInvalidConfigurationNotification"!](void);
    [!ENDIF!]
    [!ENDIF!]
    [!IF "McuInvalidModeIntEn = 'true'"!]
    [!IF "McuInvalidModeNotification != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuInvalidModeNotification"!](void);
    [!ENDIF!]
    [!ENDIF!]
    [!IF "McuSafeModeIntEn = 'true'"!]
    [!IF "McuSafeModeNotification != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuSafeModeNotification"!](void);
    [!ENDIF!]
    [!ENDIF!]
    [!IF "McuModeCompleteIntEn = 'true'"!]
    [!IF "McuModeCompleteNotification != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuModeCompleteNotification"!](void);
    [!ENDIF!]
    [!ENDIF!]
    [!ENDSELECT!]

    [!IF "McuPowerControl/McuPMC_IntConfig/McuVoltageErrorNotification != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuPowerControl/McuPMC_IntConfig/McuVoltageErrorNotification"!](void);
    [!ENDIF!]

    [!IF "McuPowerControl/McuPMC_IntConfig/McuTemperatureErrorNotification != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"McuPowerControl/McuPMC_IntConfig/McuTemperatureErrorNotification"!](void);
    [!ENDIF!]

    [!IF "num:i(count(FccuConfigSet/Fault/*)) != num:i(0)"!]
    [!IF "FccuConfigSet/AlarmNotificationApi != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"FccuConfigSet/AlarmNotificationApi"!](void);
    [!ENDIF!]
    [!IF "FccuConfigSet/FccuConfigTimeOutNotificationAPI != 'NULL_PTR'"!]
    extern FUNC(void, MCU_CODE)[!"FccuConfigSet/FccuConfigTimeOutNotificationAPI"!](void);
    [!ENDIF!]
    [!ENDIF!]

[!ENDSELECT!]
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
static CONST(Mcu_CoreConfigType, MCU_CONST) Mcu_CoreConfiguration = 
{
    [!SELECT "McuModuleConfiguration/McuCoreConfiguration"!]
    .Mcme_Caddr0_Config = (uint32)( [!IF "McuCore0Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!] | ([!"num:inttohex(McuCore0Configuration/McuBootAddress,8)"!]U & MC_ME_CADDR_ADDR_MASK32) ),
    .Mcme_Caddr1_Config = (uint32)( [!IF "McuCore0Configuration/CheckerCoreEn='true'"!][!IF "McuCore0Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!][!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!]),
    .Mcme_Caddr2_Config = (uint32)( [!IF "McuCore1Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!] | ([!"num:inttohex(McuCore1Configuration/McuBootAddress,8)"!]U & MC_ME_CADDR_ADDR_MASK32) ),
    .Mcme_Caddr3_Config = (uint32)( [!IF "McuCore1Configuration/CheckerCoreEn='true'"!][!IF "McuCore1Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!][!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!]),
    .Mcme_Caddr4_Config = (uint32)( [!IF "McuHSMConfiguration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!] | ([!"num:inttohex(McuHSMConfiguration/McuBootAddress,8)"!]U & MC_ME_CADDR_ADDR_MASK32) ),
    .Mcme_Caddr6_Config = (uint32)( [!IF "McuCore2Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!] | ([!"num:inttohex(McuCore2Configuration/McuBootAddress,8)"!]U & MC_ME_CADDR_ADDR_MASK32) ),
    .Mcme_Caddr7_Config = (uint32)( [!IF "McuCore2Configuration/CheckerCoreEn='true'"!][!IF "McuCore2Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!][!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!]),
    .Mcme_Caddr8_Config = (uint32)( [!IF "McuCore3Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!] | ([!"num:inttohex(McuCore3Configuration/McuBootAddress,8)"!]U & MC_ME_CADDR_ADDR_MASK32) ),
    .Mcme_Caddr9_Config = (uint32)( [!IF "McuCore3Configuration/CheckerCoreEn='true'"!][!IF "McuCore3Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!][!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!]),
    .Mcme_Caddr10_Config = (uint32)( [!IF "McuCore4Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!] | ([!"num:inttohex(McuCore4Configuration/McuBootAddress,8)"!]U & MC_ME_CADDR_ADDR_MASK32) ),
    .Mcme_Caddr11_Config = (uint32)( [!IF "McuCore5Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE[!ELSE!]MC_ME_CADDR_RESET_DISABLE[!ENDIF!] | ([!"num:inttohex(McuCore5Configuration/McuBootAddress,8)"!]U & MC_ME_CADDR_ADDR_MASK32) ),
    .Mcme_Cctrl0_Config = (uint16)(
        [!SELECT "McuCore0Configuration"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!]) [!ENDSELECT!]
    ),
    .Mcme_Cctrl1_Config = (uint16)(
        [!SELECT "McuCore0Configuration"!]
        [!IF "CheckerCoreEn = 'true'"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!])
        [!ELSE!]
        (0U)
        [!ENDIF!] [!ENDSELECT!]
    ),
    .Mcme_Cctrl2_Config = (uint16)(
        [!SELECT "McuCore1Configuration"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!]) [!ENDSELECT!]
    ),
    .Mcme_Cctrl3_Config = (uint16)(
        [!SELECT "McuCore1Configuration"!]
        [!IF "CheckerCoreEn = 'true'"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!])
        [!ELSE!]
        (0U)
        [!ENDIF!] [!ENDSELECT!]
    ),
    .Mcme_Cctrl4_Config = (uint16)(
        [!SELECT "McuHSMConfiguration"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!]) [!ENDSELECT!]
    ),
    .Mcme_Cctrl6_Config = (uint16)(
        [!SELECT "McuCore2Configuration"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!]) [!ENDSELECT!]
    ),
    .Mcme_Cctrl7_Config = (uint16)(
        [!SELECT "McuCore2Configuration"!]
        [!IF "CheckerCoreEn = 'true'"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!])
        [!ELSE!]
        (0U)
        [!ENDIF!] [!ENDSELECT!]
    ),
    .Mcme_Cctrl8_Config = (uint16)(
        [!SELECT "McuCore3Configuration"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!]) [!ENDSELECT!]
    ),
    .Mcme_Cctrl9_Config = (uint16)(
        [!SELECT "McuCore3Configuration"!]
        [!IF "CheckerCoreEn = 'true'"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!])
        [!ELSE!]
        (0U)
        [!ENDIF!] [!ENDSELECT!]
    ),
    .Mcme_Cctrl10_Config = (uint16)(
        [!SELECT "McuCore4Configuration"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!]) [!ENDSELECT!]
    ),
    .Mcme_Cctrl11_Config = (uint16)(
        [!SELECT "McuCore5Configuration"!]
        ([!IF "RunInRun3='true'"!]MC_ME_CCTL_RUN3_ON[!ELSE!]MC_ME_CCTL_RUN3_OFF[!ENDIF!]) |
        ([!IF "RunInRun2='true'"!]MC_ME_CCTL_RUN2_ON[!ELSE!]MC_ME_CCTL_RUN2_OFF[!ENDIF!]) |
        ([!IF "RunInRun1='true'"!]MC_ME_CCTL_RUN1_ON[!ELSE!]MC_ME_CCTL_RUN1_OFF[!ENDIF!]) |
        ([!IF "RunInRun0='true'"!]MC_ME_CCTL_RUN0_ON[!ELSE!]MC_ME_CCTL_RUN0_OFF[!ENDIF!]) |
        ([!IF "RunInDrun='true'"!]MC_ME_CCTL_DRUN_ON[!ELSE!]MC_ME_CCTL_DRUN_OFF[!ENDIF!]) |
        ([!IF "RunInSafe='true'"!]MC_ME_CCTL_SAFE_ON[!ELSE!]MC_ME_CCTL_SAFE_OFF[!ENDIF!]) [!ENDSELECT!]
    )
    [!ENDSELECT!]
};

[!LOOP "McuModuleConfiguration/McuPeripheralConfig/*"!]
static CONST(Mcu_PeriConfigType, MCU_CONST) [!"@name"!][]= 
{
    [!LOOP "McuPeripheral/*"!]
    {
        .McMePeriNameConfig = (Mcu_McMePeriNameType)[!"McuPerName"!],
        [!VAR "Idx" = "0"!]
        [!VAR "CurrentRunConfigName" = "name(node:ref(McuPerRunConfig))"!]
        [!LOOP "../../../../McuRunConfig/*"!]
            [!VAR "LoopName"="@name"!]
            [!IF "contains($CurrentRunConfigName,$LoopName)"!] 
                [!VAR "Idx" = "@index"!]
            [!ENDIF!]
        [!ENDLOOP!]
        .McMeRunConfig = (Mcu_McMePeriConfigType)[!"concat('MC_ME_PERIPH_CONFIG_',num:i($Idx))"!],
        [!VAR "CurrentLpConfigName" = "name(node:ref(McuPerLowPwrConfig))"!]
        [!LOOP "../../../../McuLowPowerConfig/*"!]
            [!VAR "LoopName"="@name"!]
            [!IF "contains($CurrentLpConfigName,$LoopName)"!]
                [!VAR "Idx" = "@index"!]
            [!ENDIF!]
        [!ENDLOOP!]
        .McMeLowPowerConfig = (Mcu_McMePeriConfigType)[!"concat('MC_ME_PERIPH_CONFIG_',num:i($Idx))"!] },
    [!ENDLOOP!]
};
[!ENDLOOP!]

static CONST(Mcu_McMeConfigType, MCU_CONST) Mcu_McMeConfiguration = 
{
    [!SELECT "McuModuleConfiguration"!]
    .McMeMe = (uint32)(
        /* McuModeRun1 */  (uint32) ([!IF "McuEnableMode/McuModeRun1"!]MCU_MCME_RUN1[!ELSE!]0U[!ENDIF!])
        /* McuModeRun2 */ |(uint32) ([!IF "McuEnableMode/McuModeRun2"!]MCU_MCME_RUN2[!ELSE!]0U[!ENDIF!])
        /* McuModeRun3 */ |(uint32) ([!IF "McuEnableMode/McuModeRun3"!]MCU_MCME_RUN3[!ELSE!]0U[!ENDIF!])
        /* McuModeHalt */ |(uint32) ([!IF "McuEnableMode/McuModeHalt0"!]MCU_MCME_HALT[!ELSE!]0U[!ENDIF!])
        /* McuModeStop */ |(uint32) ([!IF "McuEnableMode/McuModeStop0"!]MCU_MCME_STOP[!ELSE!]0U[!ENDIF!])
        [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4)) or ($MCU_HARDVAR = num:i(5))"!]
        /* McuModeStandby */ |(uint32) ([!IF "McuEnableMode/McuModeStandby"!]MCU_MCME_STANDBY[!ELSE!]0U[!ENDIF!])
        [!ENDIF!]
    ),

    .McMeRunConfig = {
        [!LOOP "McuRunConfig/*"!]
        (uint32) ( /* McuRunConfig [!"@index"!] */
                /* McuModeSafe */  (uint32) ([!IF "McuModeSafe"!]MCU_MCME_SAFE[!ELSE!]0U[!ENDIF!])
                /* McuModeDrun */ |(uint32) ([!IF "McuModeDRun"!]MCU_MCME_DRUN[!ELSE!]0U[!ENDIF!])
                /* McuModeRun0 */ |(uint32) ([!IF "McuModeRun0"!]MCU_MCME_RUN0[!ELSE!]0U[!ENDIF!])
                /* McuModeRun1 */ |(uint32) ([!IF "McuModeRun1"!]MCU_MCME_RUN1[!ELSE!]0U[!ENDIF!])
                /* McuModeRun2 */ |(uint32) ([!IF "McuModeRun2"!]MCU_MCME_RUN2[!ELSE!]0U[!ENDIF!])
                /* McuModeRun3 */ |(uint32) ([!IF "McuModeRun3"!]MCU_MCME_RUN3[!ELSE!]0U[!ENDIF!]) ),
        [!ENDLOOP!]
    },

    .McMeLowPowerConfig = {
        [!LOOP "McuLowPowerConfig/*"!]
        (uint32)( /* McuLowPowerConfig [!"@index"!] */
            /* McuModeHalt */     (uint32) ([!IF "McuHalt0"!]MCU_MCME_HALT[!ELSE!]0U[!ENDIF!])
            /* McuModeStop */    |(uint32) ([!IF "McuStop0"!]MCU_MCME_STOP[!ELSE!]0U[!ENDIF!])
            [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4)) or ($MCU_HARDVAR = num:i(5))"!]
            /* McuModeStandby */ |(uint32) ([!IF "McuStandby"!]MCU_MCME_STANDBY[!ELSE!]0U[!ENDIF!]) [!ENDIF!]),
        [!ENDLOOP!]
    },

    .McMePeripheralConfig = {
        [!LOOP "McuPeripheralConfig/*"!]
        /* McuPeripheralConfig [!"@index"!] */&[!"@name"!][0U],
        [!ENDLOOP!]
    },

    .Mcu_McMeIrqCfg = (uint32_t)(
        (uint32_t)([!IF "McuMcmeInterrupt/McuInvalidConfigurationIntEn_Core = 'true'"!]0x20U[!ELSE!]0U[!ENDIF!])
        |(uint32_t)([!IF "McuMcmeInterrupt/McuInvalidConfigurationIntEn_Clock = 'true'"!]0x10U[!ELSE!]0U[!ENDIF!])
        |(uint32_t)([!IF "McuMcmeInterrupt/McuInvalidConfigurationIntEn = 'true'"!]0x8U[!ELSE!]0U[!ENDIF!])
        |(uint32_t)([!IF "McuMcmeInterrupt/McuInvalidModeIntEn = 'true'"!]0x4U[!ELSE!]0U[!ENDIF!])
        |(uint32_t)([!IF "McuMcmeInterrupt/McuSafeModeIntEn = 'true'"!]0x2U[!ELSE!]0U[!ENDIF!])
        |(uint32_t)([!IF "McuMcmeInterrupt/McuModeCompleteIntEn = 'true'"!]0x1U[!ELSE!]0U[!ENDIF!])
    ),
    [!ENDSELECT!]
};


[!SELECT "McuModuleConfiguration"!]
[!IF "num:i(count(McuResetSetting/*)) != num:i(0)"!]
[!LOOP "McuResetSetting/*"!]
static CONST(Mcu_PeripheralResetType, MCU_CONST) [!"@name"!] = 
{
    .RgmGroup0 = (uint32)( 0U
        [!LOOP "McuResetModuleGroup0/*"!]
            [!IF "Mcu_ResetEnable = 'true'"!]
                | [!"McuRgmModuleName"!]
            [!ENDIF!]
        [!ENDLOOP!] 
        ),

    .RgmGroup1 = (uint32)( 0U
        [!LOOP "McuResetModuleGroup1/*"!]
            [!IF "Mcu_ResetEnable = 'true'"!]
                | [!"McuRgmModuleName"!]
            [!ENDIF!]
        [!ENDLOOP!] 
        ),

    .RgmGroup2 = (uint32)( 0U
        [!LOOP "McuResetModuleGroup2/*"!]
            [!IF "Mcu_ResetEnable = 'true'"!]
                | [!"McuRgmModuleName"!]
            [!ENDIF!]
        [!ENDLOOP!] 
        ),

    .RgmGroup3 = (uint32)( 0U
        [!LOOP "McuResetModuleGroup3/*"!]
            [!IF "Mcu_ResetEnable = 'true'"!]
                | [!"McuRgmModuleName"!]
            [!ENDIF!]
        [!ENDLOOP!] 
        ),
    
    .RgmGroup4 = (uint32)( 0U
        [!LOOP "McuResetModuleGroup4/*"!]
            [!IF "Mcu_ResetEnable = 'true'"!]
                | [!"McuRgmModuleName"!]
            [!ENDIF!]
        [!ENDLOOP!] 
        ),

    .RgmGroup5 = (uint32)( 0U
        [!LOOP "McuResetModuleGroup5/*"!]
            [!IF "Mcu_ResetEnable = 'true'"!]
                | [!"McuRgmModuleName"!]
            [!ENDIF!]
        [!ENDLOOP!] 
        ),

    .RgmGroup6 = (uint32)( 0U
        [!LOOP "McuResetModuleGroup6/*"!]
            [!IF "Mcu_ResetEnable = 'true'"!]
                | [!"McuRgmModuleName"!]
            [!ENDIF!]
        [!ENDLOOP!] 
        ),

    .RgmGroup7 = (uint32)( 0U
        [!LOOP "McuResetModuleGroup7/*"!]
            [!IF "Mcu_ResetEnable = 'true'"!]
                | [!"McuRgmModuleName"!]
            [!ENDIF!]
        [!ENDLOOP!] 
        ),
};
[!ENDLOOP!]
[!ENDIF!]
[!ENDSELECT!]


[!SELECT "McuModuleConfiguration"!]
static CONST(Mcu_RgmConfigType, MCU_CONST)  Mcu_RgmConfiguration = 
{
    #if (MCU_PERFORM_RESET_API == STD_ON)
    .Mcu_RgmResetType = [!IF "McuResetConfig/McuResetType = 'FunctionalReset'"!]MCU_FUNC_RESET[!ELSE!]MCU_DEST_RESET[!ENDIF!],
    #endif /* (MCU_PERFORM_RESET_API == STD_ON) */
    /* RGM_FRET Register Configuration. */
    .Mcrgm_FuncThresholdReset = (uint8)([!"num:i(McuResetConfig/McuFuncResetEscThreshold)"!]U),
    /* RGM_DRET Register Configuration. */
    .Mcrgm_DesThresholdReset = (uint8)([!"num:i(McuResetConfig/McuDestResetEscThreshold)"!]U),
    .Mcrgm_DestResetOpt = (uint32)([!IF "McuResetConfig/McuPORST_ResetSource/McuDisableReset='false'"!]RGM_PORST_RESET[!ELSE!]RGM_PORST_SAFE_INT[!ENDIF!]),
    .Mcrgm_DestSafeIsrOpt = (uint32)([!IF "McuResetConfig/McuPORST_ResetSource/McuEnableInterruptSafe='false'"!]RGM_PORST_ALT_EVENT_SAFE[!ELSE!]RGM_PORST_ALT_EVENT_ISR[!ENDIF!]),
    .Mcrgm_DestExtPinReset = (uint32)(0x00000000U),
    .Mcrgm_FuncResetOpt = (uint32)(
        [!INDENT "8"!]
        ([!IF "McuResetConfig/McuVOR_FUNC_ResetSource/McuDisableReset='false'"!]RGM_VOR_FUNC_EVENT_RESET[!ELSE!]RGM_VOR_FUNC_EVENT_SAFE_INT[!ENDIF!]) |
        ([!IF "McuResetConfig/McuTSR_FUNC_ResetSource/McuDisableReset='false'"!]RGM_TSR_FUNC_EVENT_RESET[!ELSE!]RGM_TSR_FUNC_EVENT_SAFE_INT[!ENDIF!]) |
        ([!IF "McuResetConfig/McuESR1_ResetSource/McuDisableReset='false'"!]RGM_ESR1_EVENT_RESET[!ELSE!]RGM_ESR1_EVENT_SAFE_INT[!ENDIF!])
        [!ENDINDENT!]
    ),
    .Mcrgm_FuncSafeIsrOpt = (uint32)(
        [!INDENT "8"!]
        ([!IF "McuResetConfig/McuVOR_FUNC_ResetSource/McuEnableInterruptSafe='false'"!]RGM_VOR_FUNC_EVENT_SAFE[!ELSE!]RGM_VOR_FUNC_EVENT_ISR[!ENDIF!]) |
        ([!IF "McuResetConfig/McuTSR_FUNC_ResetSource/McuEnableInterruptSafe='false'"!]RGM_TSR_FUNC_EVENT_SAFE[!ELSE!]RGM_TSR_FUNC_EVENT_ISR[!ENDIF!]) |
        ([!IF "McuResetConfig/McuESR1_ResetSource/McuEnableInterruptSafe='false'"!]RGM_ESR1_EVENT_SAFE[!ELSE!]RGM_ESR1_EVENT_ISR[!ENDIF!])
        [!ENDINDENT!]
    ),
    .Mcrgm_FuncExtPinReset = (uint32)(
        [!INDENT "8"!]
        ([!IF "McuResetConfig/McuVOR_FUNC_ResetSource/McuResetPin='false'"!]RGM_VOR_FUNC_EXT_RESET_B_EN[!ELSE!]RGM_VOR_FUNC_EXT_RESET_B_DIS[!ENDIF!]) |
        ([!IF "McuResetConfig/McuTSR_FUNC_ResetSource/McuResetPin='false'"!]RGM_TSR_FUNC_EXT_RESET_B_EN[!ELSE!]RGM_TSR_FUNC_EXT_RESET_B_DIS[!ENDIF!]) |
        ([!IF "McuResetConfig/McuHSM_FUNC_ResetSource/McuResetPin='false'"!]RGM_HSM_FUNC_ASSERT_ESR0_EN[!ELSE!]RGM_HSM_FUNC_ASSERT_ESR0_DIS[!ENDIF!]) |
        ([!IF "McuResetConfig/McuFCCU_SOFT_ResetSource/McuResetPin='false'"!]RGM_FCCU_SOFT_EXT_RESET_B_EN[!ELSE!]RGM_FCCU_SOFT_EXT_RESET_B_DIS[!ENDIF!]) |
        ([!IF "McuResetConfig/McuFCCU_HARD_ResetSource/McuResetPin='false'"!]RGM_FCCU_HARD_EXT_RESET_B_EN[!ELSE!]RGM_FCCU_HARD_EXT_RESET_B_DIS[!ENDIF!]) |
        ([!IF "McuResetConfig/McuSOFT_FUNC_ResetSource/McuResetPin='false'"!]RGM_SOFT_FUNC_EXT_RESET_B_EN[!ELSE!]RGM_SOFT_FUNC_EXT_RESET_B_DIS[!ENDIF!]) |
        ([!IF "McuResetConfig/McuESR1_ResetSource/McuResetPin='false'"!]RGM_ESR1_ASSERT_ESR0_EN[!ELSE!]RGM_ESR1_ASSERT_ESR0_DIS[!ENDIF!])
        [!ENDINDENT!]
    ),
    .Mcrgm_FuncPhase1or3Opt = (uint32)(
        [!INDENT "8"!]
        ([!IF "McuResetConfig/McuVOR_FUNC_ResetSource/McuResetPhase='PHASE_1'"!]RGM_VOR_FUNC_RESET_PHASE1[!ELSE!]RGM_VOR_FUNC_RESET_PHASE3[!ENDIF!]) |
        ([!IF "McuResetConfig/McuTSR_FUNC_ResetSource/McuResetPhase='PHASE_1'"!]RGM_TSR_FUNC_RESET_PHASE1[!ELSE!]RGM_TSR_FUNC_RESET_PHASE3[!ENDIF!]) |
        ([!IF "McuResetConfig/McuJTAG_FUNC_ResetSource/McuResetPhase='PHASE_1'"!]RGM_JTAG_FUNC_RESET_PHASE1[!ELSE!]RGM_JTAG_FUNC_RESET_PHASE3[!ENDIF!]) |
        ([!IF "McuResetConfig/McuSOFT_FUNC_ResetSource/McuResetPhase='PHASE_1'"!]RGM_SOFT_FUNC_RESET_PHASE1[!ELSE!]RGM_SOFT_FUNC_RESET_PHASE3[!ENDIF!]) |
        ([!IF "McuResetConfig/McuESR1_ResetSource/McuResetPhase='PHASE_1'"!]RGM_ESR1_RESET_PHASE1[!ELSE!]RGM_ESR1_RESET_PHASE3[!ENDIF!]) |
        ([!IF "McuResetConfig/McuESR0_ResetSource/McuResetPhase='PHASE_1'"!]RGM_ESR0_RESET_PHASE1[!ELSE!]RGM_ESR0_RESET_PHASE3[!ENDIF!])
        [!ENDINDENT!]
    ),
    [!IF "num:i(count(McuResetSetting/*)) != num:i(0)"!]
    .PeriResetConfig = {
        [!LOOP "McuResetSetting/*"!]
            &[!"@name"!],
        [!ENDLOOP!]
    }
    [!ENDIF!]
};
[!ENDSELECT!]




[!SELECT "McuModuleConfiguration"!]
static CONST(Mcu_PmcConfigType, MCU_CONST)  Mcu_PmcConfiguration = 
{
    .Pmc_IerConfig = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD15IE_A='true'"!]PMC_IER_VD15IE_A_ENA[!ELSE!]PMC_IER_VD15IE_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD15IE_C='true'"!]PMC_IER_VD15IE_C_ENA[!ELSE!]PMC_IER_VD15IE_C_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD14IE_A='true'"!]PMC_IER_VD14IE_A_ENA[!ELSE!]PMC_IER_VD14IE_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD14IE_IM='true'"!]PMC_IER_VD14IE_IM_ENA[!ELSE!]PMC_IER_VD14IE_IM_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD13IE_IM='true'"!]PMC_IER_VD13IE_IM_ENA[!ELSE!]PMC_IER_VD13IE_IM_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD12IE_F='true'"!]PMC_IER_VD12IE_F_ENA[!ELSE!]PMC_IER_VD12IE_F_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD10IE_A='true'"!]PMC_IER_VD10IE_A_ENA[!ELSE!]PMC_IER_VD10IE_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD10IE_F='true'"!]PMC_IER_VD10IE_F_ENA[!ELSE!]PMC_IER_VD10IE_F_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD9IE_O='true'"!]PMC_IER_VD9IE_O_ENA[!ELSE!]PMC_IER_VD9IE_O_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD9IE_O_H='true'"!]PMC_IER_VD9IE_O_H_ENA[!ELSE!]PMC_IER_VD9IE_O_H_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD9IE_IO_5V_H='true'"!]PMC_IER_VD9IE_IO_5V_H_ENA[!ELSE!]PMC_IER_VD9IE_IO_5V_H_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD9IE_IO_5V='true'"!]PMC_IER_VD9IE_IO_5V_ENA[!ELSE!]PMC_IER_VD9IE_IO_5V_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD9IE_PMC_H='true'"!]PMC_IER_VD9IE_PMC_H_ENA[!ELSE!]PMC_IER_VD9IE_PMC_H_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD9IE_PMC='true'"!]PMC_IER_VD9IE_PMC_ENA[!ELSE!]PMC_IER_VD9IE_PMC_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD8IE_C='true'"!]PMC_IER_VD8IE_C_ENA[!ELSE!]PMC_IER_VD8IE_C_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD8IE_F='true'"!]PMC_IER_VD8IE_F_ENA[!ELSE!]PMC_IER_VD8IE_F_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD7IE_C='true'"!]PMC_IER_VD7IE_C_ENA[!ELSE!]PMC_IER_VD7IE_C_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD4IE_C='true'"!]PMC_IER_VD4IE_C_ENA[!ELSE!]PMC_IER_VD4IE_C_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD3IE_P='true'"!]PMC_IER_VD3IE_P_ENA[!ELSE!]PMC_IER_VD3IE_P_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_IntConfig/McuVD3IE_F='true'"!]PMC_IER_VD3IE_F_ENA[!ELSE!]PMC_IER_VD3IE_F_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD3ResetEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD3/McuHVD3_P='true'"!]PMC_REE_VD3_HVD3_P_ENA[!ELSE!]PMC_REE_VD3_HVD3_P_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD3/McuLVD3_F='true'"!]PMC_REE_VD3_LVD3_F_ENA[!ELSE!]PMC_REE_VD3_LVD3_F_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD3/McuLVD3_C='true'"!]PMC_REE_VD3_LVD3_C_ENA[!ELSE!]PMC_REE_VD3_LVD3_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD4ResetEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD4/McuLVD4_C='true'"!]PMC_REE_VD4_LVD4_C_ENA[!ELSE!]PMC_REE_VD4_LVD4_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD7ResetEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD7/McuHVD7_C='true'"!]PMC_REE_VD7_HVD7_C_ENA[!ELSE!]PMC_REE_VD7_HVD7_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD8ResetEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD8/McuLVD8_F='true'"!]PMC_REE_VD8_LVD8_F_ENA[!ELSE!]PMC_REE_VD8_LVD8_F_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD8/McuHVD8_C='true'"!]PMC_REE_VD8_HVD8_C_ENA[!ELSE!]PMC_REE_VD8_HVD8_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD9ResetEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD9/McuHVD9_O='true'"!]PMC_REE_VD9_HVD9_O_ENA[!ELSE!]PMC_REE_VD9_HVD9_O_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD9/McuHVD9_IO_5V='true'"!]PMC_REE_VD9_HVD9_IO_5V_ENA[!ELSE!]PMC_REE_VD9_HVD9_IO_5V_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD9/McuHVD9_PMC='true'"!]PMC_REE_VD9_HVD9_PMC_ENA[!ELSE!]PMC_REE_VD9_HVD9_PMC_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD9/McuLVD9_O='true'"!]PMC_REE_VD9_LVD9_O_ENA[!ELSE!]PMC_REE_VD9_LVD9_O_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD9/McuLVD9_IO_5V='true'"!]PMC_REE_VD9_LVD9_IO_5V_ENA[!ELSE!]PMC_REE_VD9_LVD9_IO_5V_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD9/McuLVD9_PMC='true'"!]PMC_REE_VD9_LVD9_PMC_ENA[!ELSE!]PMC_REE_VD9_LVD9_PMC_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD10ResetEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD10/McuLVD10_A='true'"!]PMC_REE_VD10_LVD10_A_ENA[!ELSE!]PMC_REE_VD10_LVD10_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD10/McuLVD10_F='true'"!]PMC_REE_VD10_LVD10_F_ENA[!ELSE!]PMC_REE_VD10_LVD10_F_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD12ResetEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD12/McuHVD12_F='true'"!]PMC_REE_VD12_HVD12_F_ENA[!ELSE!]PMC_REE_VD12_HVD12_F_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD13ResetEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD13/McuLVD13_IM='true'"!]PMC_REE_VD13_LVD13_IM_ENA[!ELSE!]PMC_REE_VD13_LVD13_IM_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD14ResetEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD14/McuLVD14_A='true'"!]PMC_REE_VD14_LVD14_A_ENA[!ELSE!]PMC_REE_VD14_LVD14_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD14/McuHVD14_IM='true'"!]PMC_REE_VD14_HVD14_IM_ENA[!ELSE!]PMC_REE_VD14_HVD14_IM_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD15ResetEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD15/McuHVD15_A='true'"!]PMC_REE_VD15_HVD15_A_ENA[!ELSE!]PMC_REE_VD15_HVD15_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventEnConfig/McuREE_VD15/McuHVD15_C='true'"!]PMC_REE_VD15_HVD15_C_ENA[!ELSE!]PMC_REE_VD15_HVD15_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD3ResetEventSel = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD3/McuHVD3_P='true'"!]PMC_RES_VD3_HVD3_P_ENA[!ELSE!]PMC_RES_VD3_HVD3_P_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD3/McuLVD3_F='true'"!]PMC_RES_VD3_LVD3_F_ENA[!ELSE!]PMC_RES_VD3_LVD3_F_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD3/McuLVD3_C='true'"!]PMC_RES_VD3_LVD3_C_ENA[!ELSE!]PMC_RES_VD3_LVD3_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD4ResetEventSel = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD4/McuLVD4_C='true'"!]PMC_RES_VD4_LVD4_C_ENA[!ELSE!]PMC_RES_VD4_LVD4_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD7ResetEventSel = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD7/McuHVD7_C='true'"!]PMC_RES_VD7_HVD7_C_ENA[!ELSE!]PMC_RES_VD7_HVD7_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD8ResetEventSel = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD8/McuLVD8_F='true'"!]PMC_RES_VD8_LVD8_F_ENA[!ELSE!]PMC_RES_VD8_LVD8_F_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD8/McuHVD8_C='true'"!]PMC_RES_VD8_HVD8_C_ENA[!ELSE!]PMC_RES_VD8_HVD8_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD9ResetEventSel = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD9/McuHVD9_O='true'"!]PMC_RES_VD9_HVD9_O_ENA[!ELSE!]PMC_RES_VD9_HVD9_O_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD9/McuHVD9_IO_5V='true'"!]PMC_RES_VD9_HVD9_IO_5V_ENA[!ELSE!]PMC_RES_VD9_HVD9_IO_5V_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD9/McuHVD9_PMC='true'"!]PMC_RES_VD9_HVD9_PMC_ENA[!ELSE!]PMC_RES_VD9_HVD9_PMC_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD12ResetEventSel = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD12/McuHVD12_F='true'"!]PMC_RES_VD12_HVD12_F_ENA[!ELSE!]PMC_RES_VD12_HVD12_F_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD13ResetEventSel = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD13/McuLVD13_IM='true'"!]PMC_RES_VD13_LVD13_IM_ENA[!ELSE!]PMC_RES_VD13_LVD13_IM_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD14ResetEventSel = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD14/McuLVD14_A='true'"!]PMC_RES_VD14_LVD14_A_ENA[!ELSE!]PMC_RES_VD14_LVD14_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD14/McuHVD14_IM='true'"!]PMC_RES_VD14_HVD14_IM_ENA[!ELSE!]PMC_RES_VD14_HVD14_IM_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD15ResetEventSel = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD15/McuHVD15_A='true'"!]PMC_RES_VD15_HVD15_A_ENA[!ELSE!]PMC_RES_VD15_HVD15_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_ResetEventSelConfig/McuRES_VD15/McuHVD15_C='true'"!]PMC_RES_VD15_HVD15_C_ENA[!ELSE!]PMC_RES_VD15_HVD15_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD3FccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD3/McuFEE3_P='true'"!]PMC_FEE_VD3_FEE3_P_ENA[!ELSE!]PMC_FEE_VD3_FEE3_P_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD3/McuFEE3_F='true'"!]PMC_FEE_VD3_FEE3_F_ENA[!ELSE!]PMC_FEE_VD3_FEE3_F_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD3/McuFEE3_C='true'"!]PMC_FEE_VD3_FEE3_C_ENA[!ELSE!]PMC_FEE_VD3_FEE3_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD4FccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD4/McuFEE4_C='true'"!]PMC_FEE_VD4_FEE4_C_ENA[!ELSE!]PMC_FEE_VD4_FEE4_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD7FccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD7/McuFEE7_C='true'"!]PMC_FEE_VD7_FEE7_C_ENA[!ELSE!]PMC_FEE_VD7_FEE7_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD8FccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD8/McuFEE8_F='true'"!]PMC_FEE_VD8_FEE8_F_ENA[!ELSE!]PMC_FEE_VD8_FEE8_F_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD8/McuFEE8_C='true'"!]PMC_FEE_VD8_FEE8_C_ENA[!ELSE!]PMC_FEE_VD8_FEE8_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD9FccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD9/McuFEE9_O='true'"!]PMC_FEE_VD9_FEE9_O_ENA[!ELSE!]PMC_FEE_VD9_FEE9_O_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD9/McuFEE9_IO_5V='true'"!]PMC_FEE_VD9_FEE9_IO_5V_ENA[!ELSE!]PMC_FEE_VD9_FEE9_IO_5V_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD9/McuFEE9_PMC='true'"!]PMC_FEE_VD9_FEE9_PMC_ENA[!ELSE!]PMC_FEE_VD9_FEE9_PMC_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD9/McuFEE9_O_H='true'"!]PMC_FEE_VD9_FEE9_O_H_ENA[!ELSE!]PMC_FEE_VD9_FEE9_O_H_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD9/McuFEE9_IO_5V_H='true'"!]PMC_FEE_VD9_FEE9_IO_5V_H_ENA[!ELSE!]PMC_FEE_VD9_FEE9_IO_5V_H_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD9/McuFEE9_PMC='true'"!]PMC_FEE_VD9_FEE9_PMC_ENA[!ELSE!]PMC_FEE_VD9_FEE9_PMC_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD10FccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD10/McuFEE10_A='true'"!]PMC_FEE_VD10_FEE10_A_ENA[!ELSE!]PMC_FEE_VD10_FEE10_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD10/McuFEE10_F='true'"!]PMC_FEE_VD10_FEE10_F_ENA[!ELSE!]PMC_FEE_VD10_FEE10_F_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD12FccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD12/McuFEE12_F='true'"!]PMC_FEE_VD12_FEE12_F_ENA[!ELSE!]PMC_FEE_VD12_FEE12_F_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD13FccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD13/McuFEE13_IM='true'"!]PMC_FEE_VD13_FEE13_IM_ENA[!ELSE!]PMC_FEE_VD13_FEE13_IM_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD14FccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD14/McuFEE14_A='true'"!]PMC_FEE_VD14_FEE14_A_ENA[!ELSE!]PMC_FEE_VD14_FEE14_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD14/McuFEE14_IM='true'"!]PMC_FEE_VD14_FEE14_IM_ENA[!ELSE!]PMC_FEE_VD14_FEE14_IM_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VD15FccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD15/McuFEE15_A='true'"!]PMC_FEE_VD15_FEE15_A_ENA[!ELSE!]PMC_FEE_VD15_FEE15_A_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_FCCUEventEnConfig/McuFEE_VD15/McuFEE15_C='true'"!]PMC_FEE_VD15_FEE15_C_ENA[!ELSE!]PMC_FEE_VD15_FEE15_C_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_VoltageSupply = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_VoltageSupplyConfig/McuVSIO_IF2='true'"!]PMC_VSIO_VSIO_IF2_ENA[!ELSE!]PMC_VSIO_VSIO_IF2_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_VoltageSupplyConfig/McuVSIO_IF='true'"!]PMC_VSIO_VSIO_IF_ENA[!ELSE!]PMC_VSIO_VSIO_IF_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_VoltageSupplyConfig/McuVSIO_IJ='true'"!]PMC_VSIO_VSIO_IJ_ENA[!ELSE!]PMC_VSIO_VSIO_IJ_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_VoltageSupplyConfig/McuVSIO_IM='true'"!]PMC_VSIO_VSIO_IM_ENA[!ELSE!]PMC_VSIO_VSIO_IM_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_TempResEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_TempResetEventEnConfig/McuTEMP_3='true'"!]PMC_REE_TD_TEMP_3_ENA[!ELSE!]PMC_REE_TD_TEMP_3_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_TempResetEventEnConfig/McuTEMP_2='true'"!]PMC_REE_TD_TEMP_2_ENA[!ELSE!]PMC_REE_TD_TEMP_2_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_TempResetEventEnConfig/McuTEMP_0='true'"!]PMC_REE_TD_TEMP_0_ENA[!ELSE!]PMC_REE_TD_TEMP_0_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_TempResEventSel = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_TempResetEventSelConfig/McuTEMP_3='true'"!]PMC_RES_TD_TEMP_3_ENA[!ELSE!]PMC_RES_TD_TEMP_3_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_TempResetEventSelConfig/McuTEMP_2='true'"!]PMC_RES_TD_TEMP_2_ENA[!ELSE!]PMC_RES_TD_TEMP_2_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_TempResetEventSelConfig/McuTEMP_0='true'"!]PMC_RES_TD_TEMP_0_ENA[!ELSE!]PMC_RES_TD_TEMP_0_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_TempDetConfig = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_TempDetectorConfig/McuTS3IE='true'"!]PMC_CTL_TD_TS3IE_ENA[!ELSE!]PMC_CTL_TD_TS3IE_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_TempDetectorConfig/McuTS2IE='true'"!]PMC_CTL_TD_TS2IE_ENA[!ELSE!]PMC_CTL_TD_TS2IE_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_TempDetectorConfig/McuTS0IE='true'"!]PMC_CTL_TD_TS0IE_ENA[!ELSE!]PMC_CTL_TD_TS0IE_DIS[!ENDIF!] |
        ((uint32)( (uint32)(([!"num:i(McuPowerControl/McuPMC_TempDetectorConfig/McuTRIM_ADJ_OVER)"!]U) << (uint32)8U) & PMC_CTL_TD_TRIM_ADJ_OVER )) |
        ((uint32)( (uint32)(([!"num:i(McuPowerControl/McuPMC_TempDetectorConfig/McuTRIM_ADJ_UNDER)"!]U) << (uint32)2U) & PMC_CTL_TD_TRIM_ADJ_UNDER )) |
        [!IF "McuPowerControl/McuPMC_TempDetectorConfig/McuDOUT_EN='true'"!]PMC_CTL_TD_DOUT_ENA[!ELSE!]PMC_CTL_TD_DOUT_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_TempDetectorConfig/McuAOUT_EN='true'"!]PMC_CTL_TD_AOUT_ENA[!ELSE!]PMC_CTL_TD_AOUT_DIS[!ENDIF!] ),
        [!ENDINDENT!]
    .Pmc_TempFccuEventEn = (uint32)(
        [!INDENT "8"!]
        [!IF "McuPowerControl/McuPMC_TempResetEventSelConfig/McuFEE_TS3='true'"!]PMC_FEE_TD_FEE_TS3_ENA[!ELSE!]PMC_FEE_TD_FEE_TS3_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_TempResetEventSelConfig/McuFEE_TS2='true'"!]PMC_FEE_TD_FEE_TS2_ENA[!ELSE!]PMC_FEE_TD_FEE_TS2_DIS[!ENDIF!] |
        [!IF "McuPowerControl/McuPMC_TempResetEventSelConfig/McuFEE_TS0='true'"!]PMC_FEE_TD_FEE_TS0_ENA[!ELSE!]PMC_FEE_TD_FEE_TS0_DIS[!ENDIF!] )
        [!ENDINDENT!]
};
[!ENDSELECT!]

[!IF "McuGeneralConfiguration/McuInitClock = 'true'"!]
[!IF "num:i(count(McuModuleConfiguration/McuClockSettingConfig/*)) > 0"!]
static CONST(Mcu_ClockConfigType, MCU_CONST) Mcu_ClockConfiguration[] = 
{
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
    {
    .cgmConfig = {
        .sc_dc0 = (Mcu_CgmClkDivType)([!"num:i(McuSystemClockDivider/McuSystemClockDivider0/McuSystemClockDivider - num:i(1))"!]U << 16U),
        .sc_dc1 = (Mcu_CgmClkDivType)([!"num:i(McuSystemClockDivider/McuSystemClockDivider1/McuSystemClockDivider - num:i(1))"!]U << 16U),
        .sc_dc2 = (Mcu_CgmClkDivType)([!"num:i(McuSystemClockDivider/McuSystemClockDivider2/McuSystemClockDivider - num:i(1))"!]U << 16U),
        .sc_dc3 = (Mcu_CgmClkDivType)([!"num:i(McuSystemClockDivider/McuSystemClockDivider3/McuSystemClockDivider - num:i(1))"!]U << 16U),
        .sc_dc4 = (Mcu_CgmClkDivType)([!"num:i(McuSystemClockDivider/McuSystemClockDivider4/McuSystemClockDivider - num:i(1))"!]U << 16U),
        .ac0_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock0/McuAuxClk0_Source = 'IRC'"!]CGM_SYSTEM_CLOCK_SRC_IRCOSC[!ELSEIF "McuAuxClock0/McuAuxClk0_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuAuxClock0/McuAuxClk0_Source = 'PLL0_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0[!ENDIF!] << 24U),
        .ac0_dc0 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock0/McuAuxiliaryClock0Divider0/McuAuxClk0Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock0/McuAuxiliaryClock0Divider0/McuAuxClk0Div0_Divisor - num:i(1))"!]U << 16U) ),
        .ac0_dc1 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock0/McuAuxiliaryClock0Divider1/McuAuxClk0Div1_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock0/McuAuxiliaryClock0Divider1/McuAuxClk0Div1_Divisor - num:i(1))"!]U << 16U)
        [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4))"!]
                                        | ([!"num:i(McuAuxClock0/McuAuxiliaryClock0Divider3/McuAuxClk0Div1_DivFmt)"!]U)
        [!ENDIF!]
                                        ),
        .ac0_dc2 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock0/McuAuxiliaryClock0Divider2/McuAuxClk0Div2_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock0/McuAuxiliaryClock0Divider2/McuAuxClk0Div2_Divisor - num:i(1))"!]U << 16U)
        [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4))"!]
                                        | ([!"num:i(McuAuxClock0/McuAuxiliaryClock0Divider3/McuAuxClk0Div2_DivFmt)"!]U)
        [!ENDIF!]
                                        ),
        .ac0_dc3 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock0/McuAuxiliaryClock0Divider3/McuAuxClk0Div3_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock0/McuAuxiliaryClock0Divider3/McuAuxClk0Div3_Divisor - num:i(1))"!]U << 16U) |
                                        ([!"num:i(McuAuxClock0/McuAuxiliaryClock0Divider3/McuAuxClk0Div3_DivFmt)"!]U) ),
        .ac0_dc4 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock0/McuAuxiliaryClock0Divider4/McuAuxClk0Div4_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock0/McuAuxiliaryClock0Divider4/McuAuxClk0Div4_Divisor - num:i(1))"!]U << 16U) ),
        .ac1_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock1/McuAuxClk1_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuAuxClock1/McuAuxClk1_Source = 'PLL0_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0[!ENDIF!] << 24U),
        .ac1_dc0 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock1/McuAuxiliaryClock1Divider0/McuAuxClk1Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock1/McuAuxiliaryClock1Divider0/McuAuxClk1Div0_Divisor - num:i(1))"!]U << 16U) ),
        .ac2_dc0 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock2/McuAuxiliaryClock2Divider0/McuAuxClk2Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock2/McuAuxiliaryClock2Divider0/McuAuxClk2Div0_Divisor - num:i(1))"!]U << 16U) ),
        .ac2_dc1 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock2/McuAuxiliaryClock2Divider1/McuAuxClk2Div1_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock2/McuAuxiliaryClock2Divider1/McuAuxClk2Div1_Divisor - num:i(1))"!]U << 16U) ),
        [!IF "($MCU_HARDVAR = num:i(5))"!]
        .ac2_dc2 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock2/McuAuxiliaryClock2Divider2/McuAuxClk2Div2_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock2/McuAuxiliaryClock2Divider2/McuAuxClk2Div2_Divisor - num:i(1))"!]U << 16U) ),
        [!ENDIF!]
        .ac3_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock3/McuAuxClk3_Source = 'IRC'"!]CGM_SYSTEM_CLOCK_SRC_IRCOSC[!ELSEIF "McuAuxClock3/McuAuxClk3_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ENDIF!] << 24U),
        .ac4_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock4/McuAuxClk4_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuAuxClock4/McuAuxClk4_Source = 'PLL0_PHI1'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI1[!ENDIF!] << 24U),
        .ac5_dc0 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock5/McuAuxiliaryClock5Divider0/McuAuxClk5Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock5/McuAuxiliaryClock5Divider0/McuAuxClk5Div0_Divisor - num:i(1))"!]U << 16U) |
                                        ([!"num:i(McuAuxClock5/McuAuxiliaryClock5Divider0/McuAuxClk5Div0_DivFmt)"!]U)),
        .ac5_dc1 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock5/McuAuxiliaryClock5Divider1/McuAuxClk5Div1_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock5/McuAuxiliaryClock5Divider1/McuAuxClk5Div1_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_dc2 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock5/McuAuxiliaryClock5Divider2/McuAuxClk5Div2_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock5/McuAuxiliaryClock5Divider2/McuAuxClk5Div2_Divisor - num:i(1))"!]U << 16U) ),
        [!SELECT "McuAuxClock5/McuAuxiliaryClock5Divider2/McuAuxClk5CasDiv"!]
        .ac5_cdc0 = (Mcu_CgmClkDivType) ( ([!IF "McuAuxClk5CasDiv0/McuAuxClk5CasDiv0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv0/McuAuxClk5CasDiv0_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_cdc1 = (Mcu_CgmClkDivType) ( ([!IF "McuAuxClk5CasDiv1/McuAuxClk5CasDiv1_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv1/McuAuxClk5CasDiv1_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_cdc2 = (Mcu_CgmClkDivType) ( ([!IF "McuAuxClk5CasDiv2/McuAuxClk5CasDiv2_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv2/McuAuxClk5CasDiv2_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_cdc10 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClk5CasDiv1/McuAuxClk5CasDiv1x/McuAuxClk5CasDiv10/McuAuxClk5CasDiv10_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv1/McuAuxClk5CasDiv1x/McuAuxClk5CasDiv10/McuAuxClk5CasDiv10_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_cdc11 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClk5CasDiv1/McuAuxClk5CasDiv1x/McuAuxClk5CasDiv11/McuAuxClk5CasDiv11_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv1/McuAuxClk5CasDiv1x/McuAuxClk5CasDiv11/McuAuxClk5CasDiv11_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_cdc12 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClk5CasDiv1/McuAuxClk5CasDiv1x/McuAuxClk5CasDiv12/McuAuxClk5CasDiv12_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv1/McuAuxClk5CasDiv1x/McuAuxClk5CasDiv12/McuAuxClk5CasDiv12_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_cdc13 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClk5CasDiv1/McuAuxClk5CasDiv1x/McuAuxClk5CasDiv13/McuAuxClk5CasDiv13_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv1/McuAuxClk5CasDiv1x/McuAuxClk5CasDiv13/McuAuxClk5CasDiv13_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_cdc20 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClk5CasDiv2/McuAuxClk5CasDiv2x/McuAuxClk5CasDiv20/McuAuxClk5CasDiv20_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv2/McuAuxClk5CasDiv2x/McuAuxClk5CasDiv20/McuAuxClk5CasDiv20_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_cdc21 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClk5CasDiv2/McuAuxClk5CasDiv2x/McuAuxClk5CasDiv21/McuAuxClk5CasDiv21_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv2/McuAuxClk5CasDiv2x/McuAuxClk5CasDiv21/McuAuxClk5CasDiv21_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_cdc22 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClk5CasDiv2/McuAuxClk5CasDiv2x/McuAuxClk5CasDiv22/McuAuxClk5CasDiv22_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv2/McuAuxClk5CasDiv2x/McuAuxClk5CasDiv22/McuAuxClk5CasDiv22_Divisor - num:i(1))"!]U << 16U) ),
        .ac5_cdc23 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClk5CasDiv2/McuAuxClk5CasDiv2x/McuAuxClk5CasDiv23/McuAuxClk5CasDiv23_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                          ([!"num:i(McuAuxClk5CasDiv2/McuAuxClk5CasDiv2x/McuAuxClk5CasDiv23/McuAuxClk5CasDiv23_Divisor - num:i(1))"!]U << 16U) ),
        [!ENDSELECT!]
        .ac6_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock6/McuAuxClk6_Source = 'IRC'"!]CGM_SYSTEM_CLOCK_SRC_IRCOSC[!ELSEIF "McuAuxClock6/McuAuxClk6_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuAuxClock6/McuAuxClk6_Source = 'PLL0_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0[!ELSEIF "McuAuxClock6/McuAuxClk6_Source = 'PLL1_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL1_PHI0[!ENDIF!] << 24U),
        .ac6_dc0 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock6/McuAuxiliaryClock6Divider0/McuAuxClk6Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock6/McuAuxiliaryClock6Divider0/McuAuxClk6Div0_Divisor - num:i(1))"!]U << 16U) ),
        .ac7_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock7/McuAuxClk7_Source = 'IRC'"!]CGM_SYSTEM_CLOCK_SRC_IRCOSC[!ELSEIF "McuAuxClock7/McuAuxClk7_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuAuxClock7/McuAuxClk7_Source = 'PLL0_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0[!ELSEIF "McuAuxClock7/McuAuxClk7_Source = 'PLL1_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL1_PHI0[!ENDIF!] << 24U),
        .ac7_dc0 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock7/McuAuxiliaryClock7Divider0/McuAuxClk7Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock7/McuAuxiliaryClock7Divider0/McuAuxClk7Div0_Divisor - num:i(1))"!]U << 16U) ),
        .ac8_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock8/McuAuxClk8_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuAuxClock8/McuAuxClk8_Source = 'PLL0_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0[!ENDIF!] << 24U),
        .ac8_dc0 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock8/McuAuxiliaryClock8Divider0/McuAuxClk8Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock8/McuAuxiliaryClock8Divider0/McuAuxClk8Div0_Divisor - num:i(1))"!]U << 16U) ),
        .ac9_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock9/McuAuxClk9_Source = 'IRC'"!]CGM_SYSTEM_CLOCK_SRC_IRCOSC[!ELSEIF "McuAuxClock9/McuAuxClk9_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ENDIF!] << 24U),
        .ac9_dc0 = (Mcu_CgmClkDivType)( ([!IF "McuAuxClock9/McuAuxiliaryClock9Divider0/McuAuxClk9Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock9/McuAuxiliaryClock9Divider0/McuAuxClk9Div0_Divisor - num:i(1))"!]U << 16U) ),
        .ac10_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock10/McuAuxClk10_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuAuxClock10/McuAuxClk10_Source = 'PLL0_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0[!ENDIF!] << 24U),
        .ac10_dc0 = (Mcu_CgmClkDivType)(([!IF "McuAuxClock10/McuAuxiliaryClock10Divider0/McuAuxClk10Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock10/McuAuxiliaryClock10Divider0/McuAuxClk10Div0_Divisor - num:i(1))"!]U << 16U) ),
        [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4)) or ($MCU_HARDVAR = num:i(5))"!]
        .ac11_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock11/McuAuxClk11_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuAuxClock11/McuAuxClk11_Source = 'PLL0_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0[!ENDIF!] << 24U),
        .ac11_dc0 = (Mcu_CgmClkDivType)(([!IF "McuAuxClock11/McuAuxiliaryClock11Divider0/McuAuxClk11Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock11/McuAuxiliaryClock11Divider0/McuAuxClk11Div0_Divisor - num:i(1))"!]U << 16U) ),
        [!ENDIF!]
        [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4)) or ($MCU_HARDVAR = num:i(5))"!]
        .ac12_sc = (Mcu_CgmClkSelType)([!IF "McuAuxClock12/McuAuxClk12_Source = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuAuxClock12/McuAuxClk12_Source = 'PLL0_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0[!ENDIF!] << 24U),
        [!ENDIF!]
        [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4))"!]
        .ac12_dc0 = (Mcu_CgmClkDivType)(([!IF "McuAuxClock12/McuAuxiliaryClock12Divider0/McuAuxClk12Div0_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock12/McuAuxiliaryClock12Divider0/McuAuxClk12Div0_Divisor - num:i(1))"!]U << 16U) |
                                        ([!"num:i(McuAuxClock12/McuAuxiliaryClock12Divider0/McuAuxClk12Div0_DivFmt)"!]) ),
        [!ENDIF!]
        [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4)) or ($MCU_HARDVAR = num:i(5))"!]
        .ac12_dc1 = (Mcu_CgmClkDivType)(([!IF "McuAuxClock12/McuAuxiliaryClock12Divider1/McuAuxClk12Div1_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock12/McuAuxiliaryClock12Divider1/McuAuxClk12Div1_Divisor - num:i(1))"!]U << 16U) |
                                        ([!"num:i(McuAuxClock12/McuAuxiliaryClock12Divider1/McuAuxClk12Div1_DivFmt)"!]) ),
        [!ENDIF!]
        [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4))"!]
        .ac12_dc2 = (Mcu_CgmClkDivType)(([!IF "McuAuxClock12/McuAuxiliaryClock12Divider2/McuAuxClk12Div2_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 31U) |
                                        ([!"num:i(McuAuxClock12/McuAuxiliaryClock12Divider2/McuAuxClk12Div2_Divisor - num:i(1))"!]U << 16U) |
                                        ([!"num:i(McuAuxClock12/McuAuxiliaryClock12Divider2/McuAuxClk12Div2_DivFmt)"!]) ),
        [!ENDIF!]
        },
    .cgmcsConfig = {
        .ircConfig = {
            .Mcu_FircCfg = (uint32)(
                (uint32)([!"num:i(McuIRC/McuFIRC_Trim)"!]U << 16U)  /* FIRC Trim */
                [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4)) or ($MCU_HARDVAR = num:i(5))"!]
               |(uint32)([!IF "McuIRC/McuFIRC_OffInStandby = 'true'"!]1U[!ELSE!]0U[!ENDIF!] << 23U) /* FIRCOFF_STDBY */
                [!ENDIF!]
               |(uint32)([!"num:i(McuIRC/McuFIRC_Div)"!]U << 8U) /* FIRC DIV */
            ),
            [!IF "($MCU_HARDVAR = num:i(2)) or ($MCU_HARDVAR = num:i(4)) or ($MCU_HARDVAR = num:i(5))"!]
            .Mcu_SircCfg = (uint32)(
                (uint32)([!IF "McuIRC/McuSIRC_En = 'true'"!]1U[!ELSE!]0U[!ENDIF!]) /* SIRC Enable */
               |(uint32)([!"num:i(McuIRC/McuSIRC_Div)"!]U << 8U) /* SIRC DIV */
            )
            [!ENDIF!]
        },
        .xosc0Config = {
            .freq = (uint32) [!"num:i(../../McuCrystalFrequencyHz)"!],
            .startupDelay = (uint16) [!"num:i(McuXOSC/McuXoscCounter)"!],
            .bypassOption = (Mcu_XoscBypassType) [!IF "McuXOSC/McuXoscByPass = 'true'"!]XOSC_USE_EXTAL[!ELSE!]XOSC_USE_CRYSTAL[!ENDIF!],
            .Mcu_xoscInterruptEn = [!IF "../../McuXoscInterruptEn = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            },
        .pll0Config = {
            .predivider = (Mcu_PlldigClkPredivType) [!"num:i(McuPll_0/McuPll0_Parameter/McuInputClkPreDivider)"!],
            .mulFactorDiv = (uint8) [!"num:i(McuPll_0/McuPll0_Parameter/McuLoopMultiplicationClkDivider)"!],
            .phi0Divider = (Mcu_PlldigClkoutDivType) [!"num:i(McuPll_0/McuPll0_Parameter/McuPHI_ReducedFreqDivider)"!],
            .phi1Divider = (Mcu_PlldigClkoutDivType) [!"num:i(McuPll_0/McuPll0_Parameter/McuPHI1_ReducedFreqDivider)"!]
            },
        .pll1Config = { 
            .mulFactorDiv = (uint8) [!"num:i(McuPll_1/McuPll1_Parameter/McuLoopMultiplicationClkDivider)"!],
            .phi0Divider = (Mcu_PlldigClkPredivType) [!"num:i(McuPll_1/McuPll1_Parameter/McuPHI_ReducedFreqDivider)"!],
            .modulation = (uint8) [!IF "McuPll_1/McuPll1_Parameter/McuModulationEnable = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .modulationType = (Mcu_PlldigModType) [!IF "McuPll_1/McuFmPll1_Parameter/McuSpreadSelection = 'Down_Spread'"!]DOWN_SPREAD_MODULATION[!ELSE!]CENTRE_SPREAD_MODULATION[!ENDIF!],
            .modulationPeriod = (uint16) [!"num:i(McuPll_1/McuFmPll1_Parameter/McuModulationPeriod)"!],
            .incrementStep = (uint16) [!"num:i(McuPll_1/McuFmPll1_Parameter/McuModulationIncrementStep)"!],
            .fracDivider = (uint8) [!IF "McuPll_1/McuPll1_Parameter/McuFracDivEnable = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .fracDividerValue = (uint16) [!"num:i(McuPll_1/McuFdPll1_Parameter/McuFractionalDivider)"!]
            }
        },
    .Mcu_SRamWSConfig = (uint32)(
        ((uint32)(((uint32)[!"num:i(McuRam/McuRam_PRI)"!]U<< (uint32)8U) & PRAMC_PRCR1_PRI_MASK32)) |
        ([!IF "McuRam/McuRam_P1_BO_DIS = 'true'"!]PRAMC_PRCR1_P1_BO_DIS[!ELSE!]PRAMC_PRCR1_P1_BO_ENA[!ENDIF!]) |
        ([!IF "McuRam/McuRam_P0_BO_DIS = 'true'"!]PRAMC_PRCR1_P0_BO_DIS[!ELSE!]PRAMC_PRCR1_P0_BO_ENA[!ENDIF!]) |
        ([!IF "McuRam/McuRam_P1_RB_DIS = 'true'"!]PRAMC_PRCR1_P1_RB_DIS[!ELSE!]PRAMC_PRCR1_P1_RB_ENA[!ENDIF!]) |
        ([!IF "McuRam/McuRam_P0_RB_DIS = 'true'"!]PRAMC_PRCR1_P0_RB_DIS[!ELSE!]PRAMC_PRCR1_P0_RB_ENA[!ENDIF!]) |
        ([!IF "McuRam/McuRam_FT_DIS = 'true'"!]PRAMC_PRCR1_FT_DIS[!ELSE!]PRAMC_PRCR1_FT_ENA[!ENDIF!])),
    [!IF "node:exists(McuFlash)"!]
    .Mcu_FlashWSConfig = (uint32)(
        ((uint32)((uint32)([!"num:i(McuFlash/McuFlashAddrPipelineControl)"!]) << (uint32)13U) & FLASHC_PFCR1_APC_MASK32) |
        ((uint32)((uint32)([!"num:i(McuFlash/McuFlashReadWaitStateControl)"!]) << (uint32)8U) & FLASHC_PFCR1_RWSC_MASK32)),
    [!ENDIF!]
    .mode_configuration = {
        .clocksEnabled = {
            .irc0 = (uint8)[!IF "McuClkSetIRC_En"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .xosc0 = (uint8)[!IF "McuClkSetXOSC_En"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .pll0 = (uint8)[!IF "McuClkSetPLL0_En"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .pll1 = (uint8)[!IF "McuClkSetPLL1_En"!]TRUE[!ELSE!]FALSE[!ENDIF!]
            },
        .sysclk = (Mcu_CgmSysClkSrcType)[!IF "McuSystemClockSwitch = 'IRC'"!]CGM_SYSTEM_CLOCK_SRC_IRCOSC[!ELSEIF "McuSystemClockSwitch = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuSystemClockSwitch = 'PLL0_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0[!ELSEIF "McuSystemClockSwitch = 'PLL1_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL1_PHI0[!ENDIF!],
        },
    .PeriConfigPtr = &[!"name(node:ref(PeripheralConfig))"!][0U],
    },
    [!ENDLOOP!]
};
[!ENDIF!]
[!ENDIF!]

[!IF "num:i(count(McuModuleConfiguration/McuModeSettingConf/*)) > 0"!]
static CONST(Mcu_ModeConfigType, MCU_CONST) Mcu_ModeConfiguration[] = 
{
    [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
    {
        .Mcu_ModeConfigId = [!"@index"!],
        .Mcu_ChipMode = [!IF "McuPowerMode = 'RUN0'"!]me_mc_run0_mode[!ELSEIF "McuPowerMode = 'RUN1'"!]me_mc_run1_mode[!ELSEIF "McuPowerMode = 'RUN2'"!]me_mc_run2_mode[!ELSEIF "McuPowerMode = 'RUN3'"!]me_mc_run3_mode[!ELSEIF "McuPowerMode = 'DRUN'"!]me_mc_drun_mode[!ELSEIF "McuPowerMode = 'HALT0'"!]me_mc_halt0_mode[!ELSEIF "McuPowerMode = 'STOP0'"!]me_mc_stop0_mode[!ELSEIF "McuPowerMode = 'STANDBY'"!]me_mc_standby_mode[!ENDIF!],
        .Mcu_TargetClock = [!IF "McuSystemClockSwitch = 'IRC'"!]CGM_SYSTEM_CLOCK_SRC_IRCOSC[!ELSEIF "McuSystemClockSwitch = 'XOSC'"!]CGM_SYSTEM_CLOCK_SRC_XOSC[!ELSEIF "McuSystemClockSwitch = 'PLL0_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL0_PHI0[!ELSEIF "McuSystemClockSwitch = 'PLL1_PHI'"!]CGM_SYSTEM_CLOCK_SRC_PLL1_PHI0[!ENDIF!],
        .Mcu_IRC_En = [!IF "McuIRCOscControl = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .Mcu_XOSC_En = [!IF "McuXOSCControl = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .Mcu_PLL0_En = [!IF "McuSystemFMPLLControl = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .Mcu_PLL1_En = [!IF "McuSecondaryFMPLLControl = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .PeriConfigPtr = &[!"name(node:ref(PeripheralConfig))"!][0U]
    },
    [!ENDLOOP!]
};
[!ENDIF!]

[!IF "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*)) > 0"!]
static CONST(Mcu_RamConfigType, MCU_CONST) Mcu_RamConfiguration[] = 
{
    [!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
    [!VAR "PCindex" = "@index"!]
    {
        [!INDENT "8"!]
        /* The ID for Ram Sector configuration. */
        (Mcu_RamSectionType)[!"num:i(McuRamSectorId)"!]U,
        /* RAM section base address: Start of Mcu_RamConfig[[!"@index"!]]. */
        (uint8 *)[!"num:inttohex(McuRamSectionBaseAddress,8)"!]U,
        /* RAM section size: Section base address (must be aligned to 4 bytes). */
        (Mcu_RamSizeType)[!"num:inttohex(McuRamSectionSize,8)"!]U,
        [!VAR "FirstByte" = "1"!]
        (uint64) ( 
            [!INDENT "12"!]
        [!FOR "i" = "0" TO "node:fallback(McuRamSectionWriteSize, 8) - 1"!][!//
            [!IF "num:i($FirstByte)=0"!] | [!ENDIF!][!VAR "FirstByte"="0"!]((uint64)[!"num:inttohex(McuRamDefaultValue, 2)"!]U << [!"num:i($i * 8)"!]U)
        [!ENDFOR!]
            [!ENDINDENT!]
         ),
        /* RAM section write size (maximum allowed: 8). */
        (Mcu_RamWriteSizeType)[!"num:i(McuRamSectionWriteSize)"!]U
        [!ENDINDENT!]
    },
    [!ENDLOOP!]
};
[!ENDIF!]

[!IF "num:i(count(McuModuleConfiguration/FccuConfigSet/Fault/*)) != num:i(0)"!]
static CONST(Mcu_FccuRfConfigType, MCU_CONST)  Mcu_FccuRfConfiguration[] = {
    [!LOOP "McuModuleConfiguration/FccuConfigSet/Fault/*"!]
    {
        .Mcu_FccuChannel           = (uint8)[!"SignalDesc"!],
        .Mcu_FccuRecoveryConfig    = (Mcu_FccuRecoveryType)[!IF "RecoveryType = 'SwRecoverableFault'"!]FCCU_RF_SW_RECOVERABLE_FAULT[!ELSE!]FCCU_RF_HW_RECOVERABLE_FAULT[!ENDIF!],
        .Mcu_FccuReactionConfig    = (Mcu_FccuReactionType)[!IF "ReactionType = 'ShortResetReaction'"!]FCCU_RFS_SHORT_RESET[!ELSEIF "ReactionType = 'LongResetReaction'"!]FCCU_RFS_LONG_RESET[!ELSE!]FCCU_RFS_NO_RESET[!ENDIF!],
        .Mcu_FccuToAlarmEn         = (uint8)[!IF "RecoveryTimeOutEnabled = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .Mcu_FccuRfReactionEnCfg   = {
            .irq_alarm_en = (uint8)[!IF "AlarmIrqEnabled = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .nmi_en       = (uint8)[!IF "FaultNmiEnabled = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .eout_sig_en  = (uint8)[!IF "ActivateOutputPins = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!]
        },
    },
    [!ENDLOOP!]
};
[!ENDIF!]
[!SELECT "McuModuleConfiguration/FccuConfigSet"!]
[!IF "num:i(count(Fault/*)) != num:i(0)"!]
static CONST(Mcu_FccuConfigType, MCU_CONST) Mcu_FccuConfiguration = /* PRQA S 3218 */
{
    .Mcu_FccuFilterBypassEn = (uint8)[!IF "FccuGlitchFilterBypass = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .Mcu_FccuFilterWidth = [!IF "FccuGlitchFilterWidth = 'Up_To_50_us'"!]0U[!ELSEIF "FccuGlitchFilterWidth = 'Up_To_75_us'"!]1U[!ELSE!]2U[!ENDIF!],
    .Mcu_FccuEoutConfig = {
        .set_after_reset  = (uint8)[!IF "EOUT_AfterReset = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .control = [!"FCCU_SET_CLEAR"!],
        .output = [!"OD"!],
        .fop = [!"FOP"!],
        .switch_mode = [!IF "EOUT_SwitchingMode = 'true'"!]FCCU_EOUT_PROTOCOL_FAST_SM[!ELSE!]FCCU_EOUT_PROTOCOL_SLOW_SM[!ENDIF!],
        .polarity_sel = [!IF "EOUT_PolaritySelection = 'true'"!]FCCU_EOUT_0_HIGH_0_LOW[!ELSE!]FCCU_EOUT_0_LOW_1_HIGH[!ENDIF!],
        .mode = [!IF "EOUT_FaultOutputMode = 'EOUT_DualRail'"!]FCCU_FOM_DUAL_RAIL[!ELSEIF "EOUT_FaultOutputMode = 'EOUT_TimeSwitching'"!]FCCU_FOM_TIME_SWITCHING[!ELSEIF "EOUT_FaultOutputMode = 'EOUT_BiStable'"!]FCCU_FOM_BI_STABLE[!ELSE!][!"EOUT_FaultOutputMode"!][!ENDIF!],
        .eof = [!"EOF"!],
        .delta_t_value = [!"num:i(DeltaT)"!],
    },
    .Mcu_FccuLockTypeConfig = [!"FccuLockedConfiguration"!],
    .Mcu_FccuCfgTimeout = [!"ConfigTimeout"!]U,
    .Mcu_FccuIrqTypeConfig = (Mcu_FccuIrqType)[!IF "CfgToIrqEnabled = 'true'"!]FCCU_IRQ_CFG_TO_IEN[!ELSE!]FCCU_IRQ_NONE[!ENDIF!],
    .Mcu_FccuRfCfgNumber = (uint8)[!"num:i(count(Fault/*))"!],
    .Mcu_FccuRfConfigPtr = &Mcu_FccuRfConfiguration[0U],
};
[!ENDIF!]
[!ENDSELECT!]

[!IF "(num:i(count(McuModuleConfiguration/McuDemEventParameterRefs/*)) != num:i(0))"!]
static CONST(Mcu_DemConfigType, MCU_CONST) Mcu_Dem_Config =
{
    .Mcu_E_ClockFailureCfg.state = STD_ON,
    .Mcu_E_ClockFailureCfg.id = [!"McuModuleConfiguration/McuDemEventParameterRefs/*/MCU_E_CLOCK_FAILURE/*/DemEventId"!]
};
[!ENDIF!]

static CONST(Mcu_CtrlConfigType, MCU_CONST) Mcu_CtrlConfiguration = 
{
    .Mcu_BootCore = [!"McuModuleConfiguration/Mcu_BootCore"!],
    .Mcu_InitCore = [!"McuModuleConfiguration/Mcu_InitCore"!]
};


CONST( Mcu_NotifyConfigType, MCU_CONST) Mcu_NotifyConfiguration = {
[!SELECT "McuModuleConfiguration"!]
    [!IF "McuClockSrcFailureNotification = 'true'"!]
    .Mcu_ClockFailureNotification = [!"/McuClockFailureNotification"!],
    [!ENDIF!]
    .Mcu_XoscStartupNotification = [!IF "McuXoscInterruptEn = 'true'"!][!"McuXoscStartupNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
    .McuFailOfChangeModeNotification = [!"McuFailOfChangeModeNotification"!],
    [!SELECT "McuMcmeInterrupt"!]
    .Mcu_InvalidConfigNotification_Core = [!IF "McuInvalidConfigurationIntEn_Core = 'true'"!][!"McuInvalidConfigurationNotification_Core"!][!ELSE!]NULL_PTR[!ENDIF!],
    .Mcu_InvalidConfigNotification_Clock = [!IF "McuInvalidConfigurationIntEn_Clock = 'true'"!][!"McuInvalidConfigurationNotification_Clock"!][!ELSE!]NULL_PTR[!ENDIF!],
    .Mcu_InvalidConfigNotification = [!IF "McuInvalidConfigurationIntEn = 'true'"!][!"McuInvalidConfigurationNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
    .Mcu_InvalidModeNotification = [!IF "McuInvalidModeIntEn = 'true'"!][!"McuInvalidModeNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
    .Mcu_SafeModeNotification = [!IF "McuSafeModeIntEn = 'true'"!][!"McuSafeModeNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
    .Mcu_ModeCompleteNotification = [!IF "McuModeCompleteIntEn = 'true'"!][!"McuModeCompleteNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
    [!ENDSELECT!]
    [!SELECT "McuPowerControl"!]
    .McuVoltageErrorNotification = [!IF "node:exists(McuVoltageErrorNotification)"!][!"McuVoltageErrorNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
    .McuTemperatureErrorNotification = [!IF "node:exists(McuTemperatureErrorNotification)"!][!"McuTemperatureErrorNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
    [!ENDSELECT!]
    [!IF "num:i(count(McuModuleConfiguration/FccuConfigSet/Fault/*)) != num:i(0)"!]
    .Mcu_FccuAlarmNotification = [!"FccuConfigSet/AlarmNotificationApi"!],
    .Mcu_FccuCfgToNotification = [!"FccuConfigSet/FccuConfigTimeOutNotificationAPI"!],
    [!ENDIF!]
[!ENDSELECT!]
};


CONST(Mcu_ConfigType, MCU_CONST) McuModuleConfiguration = 
{
    [!IF "(num:i(count(McuModuleConfiguration/McuDemEventParameterRefs/*)) != num:i(0))"!]
    .Mcu_DemConfigPtr = &Mcu_Dem_Config,
    [!ENDIF!]
    .Mcu_NotifyConfigPtr = &Mcu_NotifyConfiguration,
    .Mcu_CtrlConfigPtr = &Mcu_CtrlConfiguration,
    .Mcu_CoreConfigPtr = &Mcu_CoreConfiguration,
    .Mcu_McMeConfigPtr = &Mcu_McMeConfiguration,
    .Mcu_RgmConfigPtr = &Mcu_RgmConfiguration,
    .Mcu_PmcConfigPtr = &Mcu_PmcConfiguration,
    [!IF "num:i(count(McuModuleConfiguration/FccuConfigSet/Fault/*)) != num:i(0)"!]
    .Mcu_FccuConfigPtr = &Mcu_FccuConfiguration,
    [!ENDIF!]
    [!IF "McuGeneralConfiguration/McuInitClock = 'true'"!]
    .NoClockConfig = [!"num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))"!]U,
    .Mcu_ClockConfigPtr = [!IF "num:i(count(McuModuleConfiguration/McuClockSettingConfig/*)) > 0"!] &Mcu_ClockConfiguration[0U][!ELSE!]NULL_PTR[!ENDIF!],
    [!ENDIF!]
    .NoModeConfig = [!"num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]U,
    .Mcu_ModeConfigPtr = [!IF "num:i(count(McuModuleConfiguration/McuModeSettingConf/*)) > 0"!] &Mcu_ModeConfiguration[0U][!ELSE!]NULL_PTR[!ENDIF!],
    .NoRamSectionConfig = [!"num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))"!]U,
    .Mcu_RamConfigPtr = [!IF "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*)) > 0"!] &Mcu_RamConfiguration[0U][!ELSE!]NULL_PTR[!ENDIF!]
};


#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif


