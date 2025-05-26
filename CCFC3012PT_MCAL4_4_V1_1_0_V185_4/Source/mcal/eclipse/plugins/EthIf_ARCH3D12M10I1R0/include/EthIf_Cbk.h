/**************************************************************************** 
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
*   @file    EthIf_Cbk.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EthIf.
*
*   @addtogroup EthIf
*   @{
*/
#ifndef ETHIF_CBK_H
  #define ETHIF_CBK_H
#ifdef __cplusplus
extern "C"{
#endif


#include "derivative.h"
#include "Eth_GeneralTypes.h"
#include "Eth_Cfg.h"
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
  /* Common types for all communication modules*/
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETHIF_CBK_H_VENDOR_ID                    176
#define ETHIF_CBK_H_AR_REL_MAJOR_VER             4
#define ETHIF_CBK_H_AR_REL_MINOR_VER             4
#define ETHIF_CBK_H_AR_REL_REV_VER               0
#define ETHIF_CBK_H_SW_MAJOR_VER                 1
#define ETHIF_CBK_H_SW_MINOR_VER                 0
#define ETHIF_CBK_H_SW_PATCH_VER                 1
#define ETHIF_CBK_MODULE_ID                      65


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (ETH_CFG_H_VENDOR_ID != ETHIF_CBK_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETHIF_CBK_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETHIF_CBK_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETHIF_CBK_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETHIF_CBK_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETHIF_CBK_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETHIF_CBK_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETHIF_CBK_H_SW_PATCH_VER "
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
    
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
FUNC(void, ETH_CODE) EthIf_RxIndication \
(\
    VAR(uint8, AUTOMATIC) CtrlIdx,\
    VAR(Eth_FrameType, AUTOMATIC) FrameType, \
    VAR(boolean, AUTOMATIC) IsBroadcast, \
    P2CONST(uint8, AUTOMATIC, ETHIF_APPL_CONST) PhysAddrPtr, \
    P2CONST(Eth_DataType, AUTOMATIC, ETHIF_APPL_CONST) DataPtr,\
    VAR(uint16, AUTOMATIC) LenByte \
);

FUNC(void, ETH_CODE) EthIf_TxConfirmation \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) BufIdx, \
    VAR(Std_ReturnType, AUTOMATIC) Result \
);
FUNC(void, ETH_CODE) EthIf_CtrlModeIndication \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(Eth_ModeType, AUTOMATIC) CtrlMode \
);

                                              
#ifdef __cplusplus
}
#endif                                              

#endif /* ETHIF_CBK_H */
/** @} */
