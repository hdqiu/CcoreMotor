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


#define CAN_PRECOMPILE_SUPPORT    (STD_OFF)

#define CAN_MULTICORE_ENABLED    (STD_ON)

#define CAN_CHECK_WAKEUP_API    (STD_ON)

#define CAN_FD_MODE_ENABLE    (STD_ON)

#define CAN_DEV_ERROR_DETECT    (STD_ON)

#define CAN_VERSION_INFO_API    (STD_ON)

#define CAN_INSTANCE    (0U)

#define CAN_MAINFUNCTION_BUSOFF_PERIOD    (1U)

#define CAN_MAINFUNCTION_MODE_PERIOD    (1U)

#define CAN_MAINFUNCTION_WAKEUP_PERIOD    (1U)

#define CAN_MULTIPLEXED_TRANSMISSION    (STD_OFF)

#define CAN_SET_BAUDRATE_API    (STD_ON)

#define CAN_MAINFUNCTION_BUSOFF_API    (STD_ON)
#define CAN_MAINFUNCTION_WAKEUP_API    (STD_ON)
#define CAN_WAKEUP_SUPPORT    (STD_ON)
/* The unit is us. */
#define CAN_TIMEOUT_DURATION    1000000U

#define CAN_MAINFUNCTION_PERIOD         (1.0F)
#define CAN_MAINFUNCTION_PERIOD_READ    (1.0F)
#define CAN_MULTIPLE_READ_PERIOD        (STD_OFF)
#define CAN_MAINFUNCTION_PERIOD_WRITE   (1.0F)  
#define CAN_MULTIPLE_WRITE_PERIOD       (STD_OFF)
#define CAN_CONTROLLER_COUNT    1U
#define CAN_MAINFUNCTION_WRITE_API    (STD_ON)
#define CAN_MAINFUNCTION_READ_API    (STD_ON)
#define CAN_TRIGGER_TRANSMIT_EN    (STD_OFF)

#define CAN_MB_COUNT       6U
#define CAN_HOH_CNT_MAX    6U
#define CAN_DEFAULT_COREID 0U

#define CanHardwareObject_201    0U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_202    1U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_301    2U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_302    3U  /* RECEIVE object of Controller Id 0 */
#define CanHardwareObject_401    4U  /* TRANSMIT object of Controller Id 0 */
#define CanHardwareObject_402    5U  /* TRANSMIT object of Controller Id 0 */

#define CanController_0    0U  /* MCAN_1 */

#define CAN_PB_CONFIG_DECLARATION   extern CONST(Can_ConfigType, CAN_VAR) Can_Config;

#ifdef __cplusplus
}
#endif

#endif /* CAN_CFG_H_ */
