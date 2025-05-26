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
*   @file    EthSwt.h
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of EthSwt
*
*   @addtogroup EthSwt
*   @{
*/

#ifndef ETHSWT_H
#define ETHSWT_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/

/*Eth.h includes Eth_GeneralTypes.h*/
#include "Eth.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/** @implements EthSwt_Version_define */
#define ETHSWT_H_VENDOR_ID                    176
#define ETHSWT_H_AR_REL_MAJOR_VER             4
#define ETHSWT_H_AR_REL_MINOR_VER             4
#define ETHSWT_H_AR_REL_REV_VER               0
#define ETHSWT_H_SW_MAJOR_VER                 1
#define ETHSWT_H_SW_MINOR_VER                 0
#define ETHSWT_H_SW_PATCH_VER                 1
#define ETHSWT_MODULE_ID                      89

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (ETH_CFG_H_VENDOR_ID != ETHSWT_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETHSWT_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETHSWT_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETHSWT_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETHSWT_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETHSWT_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETHSWT_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETHSWT_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETHSWT_H_SW_PATCH_VER "
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
extern FUNC(Std_ReturnType, ETHSWT_CODE) EthSwt_EthRxProcessFrame( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                            VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, 
                                                            P2P2VAR(uint8, AUTOMATIC, ETHSWT_APPL_DATA) DataPtr, 
                                                            P2VAR(uint16, AUTOMATIC, ETHSWT_APPL_DATA) LengthPtr, 
                                                            P2VAR(boolean, AUTOMATIC, ETHSWT_APPL_DATA) IsMgmtFrameOnlyPtr
                                                          );

extern FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthRxFinishedIndication(VAR(uint8, AUTOMATIC) CtrlIdx, VAR(Eth_BufIdxType, AUTOMATIC) BufIdx);

extern FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthTxPrepareFrame( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                             VAR(Eth_BufIdxType, AUTOMATIC) BufIdx,
                                                             P2P2VAR(uint8, AUTOMATIC, ETHSWT_APPL_DATA) DataPtr, 
                                                             P2VAR(uint16, AUTOMATIC, ETHSWT_APPL_DATA) LengthPtr
                                                           );

extern FUNC( void, ETHSWT_CODE) EthSwt_EthTxAdaptBufferLength(P2VAR(uint16, AUTOMATIC, ETHSWT_APPL_DATA) LengthPtr);

extern FUNC(Std_ReturnType, ETHSWT_CODE) EthSwt_EthTxProcessFrame( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                             VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, 
                                                             P2P2VAR(uint8, AUTOMATIC, ETHSWT_APPL_DATA) DataPtr, 
                                                             P2VAR(uint16, AUTOMATIC, ETHSWT_APPL_DATA) LengthPtr
                                                           );

extern FUNC( Std_ReturnType, ETHSWT_CODE) EthSwt_EthTxFinishedIndication( VAR(uint8, AUTOMATIC) CtrlIdx, 
                                                                                                   VAR(Eth_BufIdxType, AUTOMATIC) BufIdx
                                                                                                 );




#endif /* ETHSWT_H */

/** @} */

