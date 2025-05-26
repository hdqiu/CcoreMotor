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
*   @file    Eth_AutoSar_Wrapper.h
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Eth MCAL driver.
*
*   @addtogroup Eth
*   @{
*/

#ifndef ETH_AUTOSAR_WRAPPER_H
#define ETH_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "StandardTypes.h"
#include "Eth_GeneralTypes.h"
#include "Eth_Cfg.h"
#include "Eth.h"

#define ETH_ATS_WRA_H_VENDOR_ID                     176
#define ETH_ATS_WRA_H_AR_REL_MAJOR_VER              4
#define ETH_ATS_WRA_H_AR_REL_MINOR_VER              4
#define ETH_ATS_WRA_H_AR_REL_REV_VER                0
#define ETH_ATS_WRA_H_SW_MAJOR_VER                  1
#define ETH_ATS_WRA_H_SW_MINOR_VER                  0
#define ETH_ATS_WRA_H_SW_PATCH_VER                  1

#if (ETH_CFG_H_VENDOR_ID != ETH_ATS_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_H_VENDOR_ID "
#endif
#if (ETH_CFG_H_AR_REL_MAJOR_VER != ETH_ATS_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_MINOR_VER != ETH_ATS_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_H_AR_REL_MINOR_VER "
#endif
#if (ETH_CFG_H_AR_REL_REV_VER != ETH_ATS_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_H_AR_REL_REV_VER "
#endif
#if (ETH_CFG_H_SW_MAJOR_VER != ETH_ATS_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_H_SW_MAJOR_VER "
#endif
#if (ETH_CFG_H_SW_MINOR_VER != ETH_ATS_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_H_SW_MINOR_VER "
#endif
#if (ETH_CFG_H_SW_PATCH_VER != ETH_ATS_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ETH_ATS_WRA_H_SW_PATCH_VER "
#endif

#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_InitController \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx \
);
FUNC(Std_ReturnType, ETH_CODE) Eth_AutoSar_Wrapper_SetControllerMode \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(Eth_ModeType, AUTOMATIC) CtrlMode \
);
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetControllerMode \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_ModeType, AUTOMATIC, ETH_APPL_DATA) CtrlModePtr \
);
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetPhysAddr \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr \
);
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_SetPhysAddr \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr \
);
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_UpdatePhysAddrFilter \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr, \
    VAR(Eth_FilterActionType, AUTOMATIC) Action \
);
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
#if STD_ON == ETH_CTRLENABLE_MII
FUNC(boolean, ETH_CODE) Eth_AutoSar_Wrapper_WriteMii \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx, \
    VAR(uint16, AUTOMATIC) RegVal \
);
FUNC(boolean, ETH_CODE) Eth_AutoSar_Wrapper_ReadMii \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) TrcvIdx, \
    VAR(uint8, AUTOMATIC) RegIdx, \
    P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) RegValPtr \
);
#endif /* ETH_CTRLENABLE_MII */
#if STD_ON == ETH_GET_COUNTVAL_API
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetCounterValues \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_CounterType, AUTOMATIC, ETH_APPL_DATA) CounterPtr \
);
#endif
#if STD_ON == ETH_GET_RXSTATS_API
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetRxStats \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_RxStatsType, AUTOMATIC, ETH_APPL_DATA) RxStats \
);
#endif
#if STD_ON == ETH_GET_TXSTATS_API
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetTxStats \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_TxStatsType, AUTOMATIC, ETH_APPL_DATA) TxStats \
);
#endif
#if STD_ON == ETH_GET_TXERRORCOUNT_API
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_GetTxErrorCounterValues \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    P2VAR(Eth_TxErrorCounterValuesType, AUTOMATIC, ETH_APPL_DATA) TxErrorCounterValues \
);
#endif
FUNC(BufReq_ReturnType, ETH_CODE) Eth_AutoSar_Wrapper_ProvideTxBuffer \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) Priority, \
    P2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_DATA) BufIdxPtr, \
    P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) BufPtr, \
    P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) LenBytePtr \
);
FUNC(Eth_ModeType, ETH_CODE) Eth_AutoSar_Wrapper_Check_Ctrl_Is_Active \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx \
);
FUNC(Std_ReturnType, ETH_CODE) Eth_AutoSar_Wrapper_Transmit \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(Eth_BufIdxType, AUTOMATIC) BufIdx, \
    VAR(Eth_FrameType, AUTOMATIC) FrameType, \
    VAR(boolean, AUTOMATIC) TxConfirmation, \
    VAR(uint16, AUTOMATIC) LenByte, \
    P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr
#if STD_ON == ETH_BRIDGE_SUPPORT
    , P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) PhysSourceAddrPtr
#endif /* ETH_BRIDGE_SUPPORT  */
);
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_Receive \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) FifoIdx, \
    P2VAR(Eth_RxStatusType, AUTOMATIC, ETH_APPL_DATA) RxStatusPtr \
);
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_TxConfirmation \
( \
    VAR(uint8, AUTOMATIC) CtrlIdx, \
    VAR(uint8, AUTOMATIC) u8Eth_FifoIdx \
);
FUNC(void, ETH_CODE) Eth_AutoSar_Wrapper_MainFunction(void);

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif
