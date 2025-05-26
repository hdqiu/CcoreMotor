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
*   @file    Port_LLDrivers.h
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Port MCAL driver.
*
*   @addtogroup Port
*   @{
*/

#ifndef PORT_LLDRIVER_H
#define PORT_LLDRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ==============================================INCLUDE FILES======================================= */

#include "Port_Cfg.h"

#include "Port_Types.h"
#include "intc_lld.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define PORT_H_SIUL2_VENDOR_ID                     176
#define PORT_H_SIUL2_AR_REL_MAJOR_VER              4
#define PORT_H_SIUL2_AR_REL_MINOR_VER              4
#define PORT_H_SIUL2_AR_REL_REV_VER                0
#define PORT_H_SIUL2_SW_MAJOR_VERSION              1
#define PORT_H_SIUL2_SW_MINOR_VERSION              0
#define PORT_H_SIUL2_SW_PATCH_VERSION              1


/* ============================================FILE VERSION CHECKS=================================== */

#if (PORT_H_SIUL2_VENDOR_ID != PORT_H_VENDOR_ID_CFG)
    #error "NON-MATCHED DATA : PORT_H_VENDOR_ID_CFG"
#endif

#if (PORT_H_SIUL2_AR_REL_MAJOR_VER != PORT_H_AR_RELEASE_MAJOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_AR_RELEASE_MAJOR_VERSION_CFG"
#endif

#if (PORT_H_SIUL2_AR_REL_MINOR_VER != PORT_H_AR_RELEASE_MINOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_AR_RELEASE_MINOR_VERSION_CFG"
#endif

#if (PORT_H_SIUL2_SW_MAJOR_VERSION != PORT_H_SW_MAJOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_SW_MAJOR_VERSION_CFG"
#endif

#if (PORT_H_SIUL2_SW_MINOR_VERSION != PORT_H_SW_MINOR_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_SW_MINOR_VERSION_CFG"
#endif

#if (PORT_H_SIUL2_SW_PATCH_VERSION != PORT_H_SW_PATCH_VERSION_CFG)
    #error "NON-MATCHED DATA : PORT_H_SW_PATCH_VERSION_CFG"
#endif

#if (PORT_H_SIUL2_VENDOR_ID != PORT_H_SIUL2_VENDOR_ID_TYPES)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_VENDOR_ID_TYPES"
#endif

#if (PORT_H_SIUL2_AR_REL_MAJOR_VER != PORT_H_SIUL2_AR_REL_MAJ_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_AR_REL_MAJ_VER_TY"
#endif

#if (PORT_H_SIUL2_AR_REL_MINOR_VER != PORT_H_SIUL2_AR_REL_MIN_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_AR_REL_MIN_VER_TY"
#endif

#if (PORT_H_SIUL2_AR_REL_REV_VER != PORT_H_SIUL2_AR_REL_REV_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_AR_REL_REV_VER_TY"
#endif

#if (PORT_H_SIUL2_SW_MAJOR_VERSION != PORT_H_SIUL2_SW_MAJOR_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_SW_MAJOR_VER_TY"
#endif

#if (PORT_H_SIUL2_SW_MINOR_VERSION != PORT_H_SIUL2_SW_MINOR_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_SW_MINOR_VER_TY"
#endif

#if (PORT_H_SIUL2_SW_PATCH_VERSION != PORT_H_SIUL2_SW_PATCH_VER_TY)
    #error "NON-MATCHED DATA : PORT_H_SIUL2_SW_PATCH_VER_TY"
#endif

/* =============================================CONSTANTS============================================ */

#define PORT_LLD_INPUT_ACTIVE_U32             ((uint32)0xFFFFFFFFUL)
#define PORT_LLD_OUTPUT_ACTIVE_U32            ((uint32)0xFFFFFFFEUL)

#define PORT_LLD_INMUX_UNUSE_PATTEN_U32     ((uint32)0xFFFFFFFFUL)

/* =========================================DEFINES AND MACROS======================================= */


/* ==============================================ENUMS=============================================== */


/* =======================================STRUCTURES AND OTHER TYPEDEFS============================== */


/* ====================================GLOBAL VARIABLE DECLARATIONS================================== */


/* ========================================FUNCTION PROTOTYPES======================================= */


#define PORT_START_SEC_CODE
#define ENTER_PORT_EXCLUSIVE_AREA INTC_LLD_Set_Global_Disable()
#define EXIT_PORT_EXCLUSIVE_AREA INTC_LLD_Set_Global_Enable()

#include "Port_MemMap.h"

FUNC (void, PORT_CODE) Port_LLD_Init \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)

FUNC (Std_ReturnType, PORT_CODE) Port_LLD_SetPinDirection \
( \
    VAR    (Port_PinType,          AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) ePort_Direction, \
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#endif

#if (STD_ON == PORT_SET_PIN_MODE_API)

FUNC (void, PORT_CODE) Port_LLD_SetPinMode \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinCfgRegIndex, \
    VAR(Port_RegValueType,      AUTOMATIC) u32Port_PinCfgRegValue, \
    VAR(uint16,                 AUTOMATIC) u16Port_InMuxRegIndex, \
    VAR(Port_RegValueType,      AUTOMATIC) u32Port_InMuxRegValue \
);
#endif

#if (STD_ON == PORT_SET_PIN_MODE_API)

FUNC (void, PORT_CODE) Port_LLD_SetGpioDirChangeability \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PadID, \
    VAR(boolean,                AUTOMATIC) bPort_Status \
);

#if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)

FUNC (void, PORT_CODE) Port_LLD_SetGpioPadOutput \
( \
    VAR    (Port_PinType,    AUTOMATIC                 ) u32Port_PinIndex, \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);
#endif
#endif


FUNC (void, PORT_CODE) Port_LLD_RefreshPortDirection \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
);

#define PORT_STOP_SEC_CODE

#include "Port_MemMap.h"


#ifdef __cplusplus
}
#endif
/* PORT_LLDRIVER_H */
#endif
/** @} */
