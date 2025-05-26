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
*   @file    LinIf.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Isolation level header file for LIN driver.
*   @details Header file for function definition on isolation level betwen high and low level driver.
*
*   @addtogroup LIN
*   @{
*/

#ifndef LIN_IF_H
#define LIN_IF_H

#ifdef __cplusplus
extern "C"
{
#endif


/*==============================================INCLUDE FILES=======================================*/

#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "Lin_Types.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LINIF_H_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LINIF_H_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LINIF_H_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LINIF_H_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LINIF_H_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LINIF_H_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LINIF_H_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LINIF_H_VENDOR_ID)
    #error " NON-MATCHED DATA : LINIF_H_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LINIF_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LINIF_H_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LINIF_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LINIF_H_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LINIF_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LINIF_H_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LINIF_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LINIF_H_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LINIF_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LINIF_H_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LINIF_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LINIF_H_SW_PATCH_VER "
#endif
/*=================================================CONSTANTS========================================*/

/*============================================DEFINES AND MACROS====================================*/
#define LINIF_WAKEUP_SUPPORT  (STD_ON)
/*===================================================ENUMS==========================================*/

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

/*====================================GLOBAL VARIABLE DECLARATIONS==================================*/

/*===============================================LOCAL FUNCTIONS====================================*/

/*==============================================GLOBAL FUNCTIONS====================================*/

FUNC(Std_ReturnType, LINIF_CODE) LinIf_CheckWakeup(VAR(EcuM_WakeupSourceType, LINIF_VAR) WakeupSource);

FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation(VAR(EcuM_WakeupSourceType, LINIF_VAR) WakeupSource);
FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication(P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr);
FUNC(void, LINIF_CODE) LinIf_RxIndication(VAR(NetworkHandleType, AUTOMATIC) Channel, P2CONST(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr);
FUNC(void, LINIF_CODE) LinIf_TxConfirmation(VAR(NetworkHandleType, AUTOMATIC) Channel);
FUNC(void, LINIF_CODE) LinIf_LinErrorIndication(VAR(NetworkHandleType, AUTOMATIC) Channel, VAR(Lin_SlaveErrorType, AUTOMATIC) ErrorStatus);
 

#ifdef __cplusplus
}
#endif

#endif /* LIN_IF_H */

/** @} */
