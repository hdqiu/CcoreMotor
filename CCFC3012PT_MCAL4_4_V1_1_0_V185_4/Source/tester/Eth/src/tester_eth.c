#include "tester_eth.h"
#include "Eth_Irq.h"
#include "Dem.h"
#include "Det.h"
#include "StandardTypes.h"
#include "Compiler.h"
#include "console.h"
#include "shell.h"
#include <string.h>
#include "Port.h"
#include "Gpt_Stm_LLDriver.h"
#include "common.h"

#define ETH_TEST_CASE_MAX 12

uint32 Eth_TestFlag = 0;

static const uint8 g_arp_pkt[] = {/* PRQA S 3218 */
                                    0x00, 0x01, 0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x12, 0x34, 0x56, 0x78, 0x90, 0xab,
                                    0xa9, 0xfe, 0xa9, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa9, 0xfe, 0xa9, 0x05}; /* pkt - data */
FUNC(status_t, ETH_CODE) Gmac_LLD_Transceiver_Init_DP83848 \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg \
);
FUNC(status_t, ETH_CODE) Gmac_LLD_Transceiver_Init_DP83848 \
( \
    VAR(GmacId, AUTOMATIC) gmac_id, \
    P2CONST(GmacCfg, AUTOMATIC, ETH_APPL_CONST) gmac_cfg \
)
{
    VAR(uint8, AUTOMATIC) phy_addr;
    VAR(uint16, AUTOMATIC) reg_val;
    Gpt_Stm_LLD_DelayMs(STM1, 500U); /* Cold start requires a delay to allow the DP83848 to initialize */
    for (phy_addr = 0U; phy_addr < 32U; phy_addr++)
    {
        (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x02U, &reg_val);
        if ((reg_val != 0U) && (reg_val != 0xffffU))
        {
            break;
        }
    }
    if (phy_addr == 32U) {
        return STATUS_GMAC_TRANSCEIVER_INIT;
    }

    /* Enable RMII mode */
    if (gmac_cfg->phy_cfg.transfer_mode == GMAC_TRANS_RMII_MODE)
    {
        (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x17U, &reg_val);
        (void)Gmac_LLD_Mii_Write_Reg(gmac_id, phy_addr, 0x17U, (uint16) (reg_val | 0x0020U));
    }

    /* Set transfer speed */
    if (gmac_cfg->phy_cfg.transfer_speed == GMAC_TRANS_SPEED_100M)
    {
        (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x00U, &reg_val);
        (void)Gmac_LLD_Mii_Write_Reg(gmac_id, phy_addr, 0x00U, (reg_val | (0x2000U)) & 0xEFFFU);
    }
    else if (gmac_cfg->phy_cfg.transfer_speed == GMAC_TRANS_SPEED_10M)
    {
        (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x00U, &reg_val);
        (void)Gmac_LLD_Mii_Write_Reg(gmac_id, phy_addr, 0x00U, (reg_val & ~(0x3000U)));
    }
    else{
        return STATUS_ERROR;
    }

    /* Set transfer duplex */
    if (gmac_cfg->phy_cfg.transfer_duplex == GMAC_TRANS_FULL_DUPLEX)
    {
        (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x00U, &reg_val);
        (void)Gmac_LLD_Mii_Write_Reg(gmac_id, phy_addr, 0x00U, (reg_val | (0x0100U)) & 0xEFFFU);
    }
    else if(gmac_cfg->phy_cfg.transfer_duplex == GMAC_TRANS_HALF_DUPLEX)
    {
        (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x00U, &reg_val);
        (void)Gmac_LLD_Mii_Write_Reg(gmac_id, phy_addr, 0x00U, (reg_val & ~(0x1100U)));
    }
    else
    {
        return STATUS_ERROR;
    }
    do
    {
        Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x10U, &reg_val);
    } while ((reg_val & 0x0001U) != 0x0001U);
    Gpt_Stm_LLD_DelayMs(STM1, 500U);
    return STATUS_SUCCESS;
}

static status_t Gmac_LLD_RTL8211_Set_Page(VAR(GmacId, AUTOMATIC) gmac_id, const uint32 phy_addr, const uint32 page_val)
{
    (void)Gmac_LLD_Mii_Write_Reg(gmac_id, phy_addr, 0x001FU, page_val);
    return STATUS_SUCCESS;
}

static status_t Gmac_LLD_Transceiver_Init_RTL8211(VAR(GmacId, AUTOMATIC) gmac_id, const GmacCfg *gmac_cfg)
{
    (void)gmac_cfg;
    uint32 phy_addr;
    uint16 reg_val;
    uint32 cnt = 0U;
    Gpt_Stm_LLD_DelayMs(STM1, 500U); /* Cold start requires a delay to allow the RTL8211 to initialize */
    for (phy_addr = 0U; phy_addr < 32U; phy_addr++) {
        (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 2U, &reg_val);
        if ((reg_val != 0U) && (reg_val != 0xffffU)) {
            break;
        }
    }
    if (phy_addr == 32U) {
        return STATUS_GMAC_TRANSCEIVER_INIT;
    }

    /* BMCR, BMSR Page: 0x000 */
    (void)Gmac_LLD_RTL8211_Set_Page(gmac_id, phy_addr, 0x000U);

    /* 0x0000: BMCR, PHY Software Reset */
    (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x0000U, &reg_val);
    (void)Gmac_LLD_Mii_Write_Reg(gmac_id, phy_addr, 0x0000U, (uint16)(reg_val | 0x8000U));
    do {
        (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x0000U, &reg_val);
    } while (reg_val & 0x8000U);
    /* 0x0000: BMCR, Auto-Negotiation Enable */
    (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x0000U, &reg_val);
    (void)Gmac_LLD_Mii_Write_Reg(gmac_id, phy_addr, 0x0000U, (uint16)(reg_val | 0x1000U));

    /* 0x0000: BMCR, Restart Auto-Negotiation */
    (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x0000U, &reg_val);
    (void)Gmac_LLD_Mii_Write_Reg(gmac_id, phy_addr, 0x0000U, (uint16)(reg_val | 0x0200U));

    Gpt_Stm_LLD_DelayMs(STM1, 500U); /* Waiting for successful self-negotiation */
    /* 0x0001: BMSR, Wait for Auto - Neg complete */
    do {
        (void)Gmac_LLD_Mii_Read_Reg(gmac_id, phy_addr, 0x0001U, &reg_val);
        Gpt_Stm_LLD_DelayMs(STM1, 1U);
        cnt++;
    } while (((reg_val & 0x0020U) != 0x0020U) & (cnt < 20000U));

    return STATUS_SUCCESS;
}

status_t Gmac_LLD_Transceiver_Cfg(VAR(GmacId, AUTOMATIC) gmac_id, const GmacCfg *gmac_cfg)
{
    if (gmac_cfg->func_cfg.inner_loop_back_en == true) { /* PRQA S 1881 */
        return STATUS_SUCCESS;
    }
    if(Eth_Config.pController[0].phy_cfg.transfer_mode == GMAC_TRANS_RGMII_MODE)
    {
        return Gmac_LLD_Transceiver_Init_RTL8211(gmac_id, gmac_cfg);
    }
    else
    {
        return Gmac_LLD_Transceiver_Init_DP83848(gmac_id, gmac_cfg);
    }

}


FUNC(void, ETH_CODE) Eth_IRQ_Priority(void)
{
    (void)INTC_LLD_Set_IRQ_Handle(FEC_SBD_INTR_IRQn, &ISR_GMAC_0); /* PRQA S 4342 */
    (void)INTC_LLD_Set_IRQ_Priority(FEC_SBD_INTR_IRQn, GMAC_0_INTC_PRIOR_DMA); /* PRQA S 4342 */
    (void)INTC_LLD_Set_IRQ_Enable(FEC_SBD_INTR_IRQn); /* PRQA S 4342 */
}

static EthfuncMachine eth_funcs[] = {
    {"ETH_0001", ETH_0001},
    {"ETH_0002", ETH_0002},
    {"ETH_0003", ETH_0003},
    {"ETH_0004", ETH_0004},
    {"ETH_0005", ETH_0005},
    {"ETH_0006", ETH_0006},
    {"ETH_0007", ETH_0007},
    {"ETH_0008", ETH_0008},
    {"ETH_0009", ETH_0009},
    {"ETH_0010", ETH_0010},
    {"ETH_0011", ETH_0011},
    {"ETH_0012", ETH_0012},
};

void ETH_0001()
{
    uint8 des_addr[GMAC_MAC_ADDR_SIZE] = {0x22, 0x34, 0x56, 0xFF, 0xFF, 0xFF};
    uint16 frame_type = 0x0806;

    Eth_BufIdxType BufIdx = 0;
    uint8 *pBufPtr = NULL;
    uint16 pBufLength = 50;
    BufReq_ReturnType buf_ret = BUFREQ_E_NOT_OK;
    uint32 i = 0;
    boolean RxIntTmp = 0;
    boolean TxIntTmp = 0;
    RxIntTmp = Eth_Config.pController[0].EnableRxInterrupt;
    TxIntTmp = Eth_Config.pController[0].EnableTxInterrupt;
    Eth_Config.pController[0].EnableRxInterrupt = TRUE;
    Eth_Config.pController[0].EnableTxInterrupt = TRUE;
    Eth_Init(&Eth_Config);
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Gpt_Stm_LLD_DelayMs(STM1, 100U);

    for (i = 0; i < 100000; i++)
    {
        buf_ret = Eth_ProvideTxBuffer(Eth_Config.pController[0].gmac_id, 0, &BufIdx, &pBufPtr, &pBufLength);
        while (buf_ret != BUFREQ_OK)
        {
            (void)buf_ret;
        }

        cc_memcpy((uint8 *)pBufPtr, (const uint8 *)g_arp_pkt, pBufLength);
        pBufPtr[(sizeof(g_arp_pkt)+1)] = (i & 0x00FF0000) >>16;
        pBufPtr[(sizeof(g_arp_pkt)+2)] = (i & 0x0000FF00) >>8;
        pBufPtr[(sizeof(g_arp_pkt)+3)] = (i & 0x000000FF) ;
        Eth_Transmit(Eth_Config.pController[0].gmac_id, BufIdx, frame_type, FALSE, pBufLength, &des_addr[0]
#if STD_ON == ETH_BRIDGE_SUPPORT
                    , NULL_PTR
#endif /* ETH_BRIDGE_SUPPORT  */
                    );
        if (Eth_InternalCfgPtr->pController[Eth_Config.pController[0].gmac_id].EnableTxInterrupt)
        {
            Gpt_Stm_LLD_DelayMs(STM1, 1U);
        } else {
            Gpt_Stm_LLD_DelayMs(STM1, 1U);
            Eth_TxConfirmation(Eth_Config.pController[0].gmac_id);
        }
    }
    Eth_Config.pController[0].EnableRxInterrupt = RxIntTmp;
    Eth_Config.pController[0].EnableTxInterrupt = TxIntTmp;
}

void ETH_0002()
{
    Eth_TestFlag = 1U;
    uint8 des_addr[GMAC_MAC_ADDR_SIZE] = {0x22, 0x34, 0x56, 0xFF, 0xFF, 0xFF};
    uint16 frame_type = 0x0806;

    Eth_BufIdxType BufIdx = 0;
    uint8 *pBufPtr = NULL;
    uint16 pBufLength = 64;
    BufReq_ReturnType buf_ret = BUFREQ_E_NOT_OK;
    uint32 i = 0;
    boolean RxIntTmp = 0;
    boolean TxIntTmp = 0;
    RxIntTmp = Eth_Config.pController[0].EnableRxInterrupt;
    TxIntTmp = Eth_Config.pController[0].EnableTxInterrupt;
    Eth_Config.pController[0].EnableRxInterrupt = FALSE;
    Eth_Config.pController[0].EnableTxInterrupt = FALSE;
    Eth_Init(&Eth_Config);
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Gpt_Stm_LLD_DelayMs(STM1, 100U);

    for (i = 0; i < 100000; i++)
    {
        buf_ret = Eth_ProvideTxBuffer(Eth_Config.pController[0].gmac_id, 0, &BufIdx, &pBufPtr, &pBufLength);
        while (buf_ret != BUFREQ_OK)
        {
            ;
        }

        cc_memcpy((uint8 *)pBufPtr, (const uint8 *)g_arp_pkt, pBufLength);
        pBufPtr[(sizeof(g_arp_pkt)+1)] = (i & 0x00FF0000) >>16;
        pBufPtr[(sizeof(g_arp_pkt)+2)] = (i & 0x0000FF00) >>8;
        pBufPtr[(sizeof(g_arp_pkt)+3)] = (i & 0x000000FF) ;
        Eth_Transmit(Eth_Config.pController[0].gmac_id, BufIdx, frame_type, TRUE, pBufLength, &des_addr[0]
#if STD_ON == ETH_BRIDGE_SUPPORT
                    , NULL_PTR
#endif /* ETH_BRIDGE_SUPPORT  */
                    );
        if (Eth_InternalCfgPtr->pController[Eth_Config.pController[0].gmac_id].EnableTxInterrupt)
        {
            Gpt_Stm_LLD_DelayMs(STM1, 1U);
        } else {
            Gpt_Stm_LLD_DelayMs(STM1, 1U);
            Eth_TxConfirmation(Eth_Config.pController[0].gmac_id);
        }
    }
    Eth_TestFlag = 0U;
    Eth_Config.pController[0].EnableRxInterrupt = RxIntTmp;
    Eth_Config.pController[0].EnableTxInterrupt = TxIntTmp;
}

void ETH_0003()
{
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    Eth_TestFlag = 1U;
    uint8 addr2[6] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xab};
    Eth_RxStatusType rec_ret = ETH_NOT_RECEIVED;
    Eth_Config.pController[0].EnableRxInterrupt = TRUE;
    Eth_Config.pController[0].EnableTxInterrupt = TRUE;
    Eth_Init(&Eth_Config);
    PSPRINTF("Eth_Init is ok\n");
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Eth_UpdatePhysAddrFilter(GMAC_ID_0, (uint8*)&addr2, ETH_ADD_TO_FILTER);
    while (1)
    {
        if (Eth_InternalCfgPtr->pController[Eth_Config.pController[0].gmac_id].EnableRxInterrupt)
        {

        } else {
            Eth_Receive(GMAC_ID_0, 0, &rec_ret);
            Gpt_Stm_LLD_DelayMs(STM1, 1U);
        }
    }
#endif
}

void ETH_0004()
{
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    Eth_TestFlag = 1U;
    uint8 addr2[6] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xab};
    Eth_RxStatusType rec_ret = ETH_NOT_RECEIVED;
    Eth_Config.pController[0].EnableRxInterrupt = FALSE;
    Eth_Config.pController[0].EnableTxInterrupt = FALSE;

    Eth_Init(&Eth_Config);
    PSPRINTF("Eth_Init is ok\n");
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Eth_UpdatePhysAddrFilter(GMAC_ID_0, (uint8*)&addr2, ETH_ADD_TO_FILTER);
    while (1)
    {
        if (Eth_InternalCfgPtr->pController[Eth_Config.pController[0].gmac_id].EnableRxInterrupt)
        {

        } else {
            Eth_Receive(GMAC_ID_0, 0, &rec_ret);
            Gpt_Stm_LLD_DelayMs(STM1, 1U);
        }
    }
#endif
}

void ETH_0005()
{
    uint8 des_addr[GMAC_MAC_ADDR_SIZE] = {0x22, 0x34, 0x56, 0xFF, 0xFF, 0xFF};
    uint16 frame_type = 0x0806;

    Eth_BufIdxType BufIdx = 0;
    uint8 *pBufPtr = NULL;
    uint16 pBufLength = 0;
    BufReq_ReturnType buf_ret = BUFREQ_E_NOT_OK;
    uint32 i = 0;
    boolean RxIntTmp = 0;
    boolean TxIntTmp = 0;
    RxIntTmp = Eth_Config.pController[0].EnableRxInterrupt;
    TxIntTmp = Eth_Config.pController[0].EnableTxInterrupt;
    Eth_Config.pController[0].EnableRxInterrupt = TRUE;
    Eth_Config.pController[0].EnableTxInterrupt = TRUE;
    Eth_Init(&Eth_Config);
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Gpt_Stm_LLD_DelayMs(STM1, 100U);

    for (i = 0; i < 10; i++)
    {
        buf_ret = Eth_ProvideTxBuffer(Eth_Config.pController[0].gmac_id, 0, &BufIdx, &pBufPtr, &pBufLength);
        while (buf_ret != BUFREQ_OK)
        {
            ;
        }

        cc_memcpy((uint8 *)pBufPtr, (const uint8 *)g_arp_pkt, pBufLength);
        Eth_Transmit(Eth_Config.pController[0].gmac_id, BufIdx, frame_type, TRUE, pBufLength, &des_addr[0]
#if STD_ON == ETH_BRIDGE_SUPPORT
                    , NULL_PTR
#endif /* ETH_BRIDGE_SUPPORT  */
                    );
        Gpt_Stm_LLD_DelayMs(STM1, 1U);
        Eth_TxConfirmation(Eth_Config.pController[0].gmac_id);
    }
    Eth_Config.pController[0].EnableRxInterrupt = RxIntTmp;
    Eth_Config.pController[0].EnableTxInterrupt = TxIntTmp;
}

void ETH_0006()
{
    uint8 des_addr[GMAC_MAC_ADDR_SIZE] = {0x22, 0x34, 0x56, 0xFF, 0xFF, 0xFF};
    uint16 frame_type = 0x0806;

    Eth_BufIdxType BufIdx = 0;
    uint8 *pBufPtr = NULL;
    uint16 pBufLength = 0;
    BufReq_ReturnType buf_ret = BUFREQ_E_NOT_OK;
    uint32 i = 0;
    boolean RxIntTmp = 0;
    boolean TxIntTmp = 0;
    RxIntTmp = Eth_Config.pController[0].EnableRxInterrupt;
    TxIntTmp = Eth_Config.pController[0].EnableTxInterrupt;
    Eth_Config.pController[0].EnableRxInterrupt = FALSE;
    Eth_Config.pController[0].EnableTxInterrupt = FALSE;
    Eth_Init(&Eth_Config);
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Gpt_Stm_LLD_DelayMs(STM1, 100U);

    for (i = 0; i < 10; i++)
    {
        buf_ret = Eth_ProvideTxBuffer(Eth_Config.pController[0].gmac_id, 0, &BufIdx, &pBufPtr, &pBufLength);
        while (buf_ret != BUFREQ_OK)
        {
            ;
        }

        cc_memcpy((uint8 *)pBufPtr, (const uint8 *)g_arp_pkt, pBufLength);
        Eth_Transmit(Eth_Config.pController[0].gmac_id, BufIdx, frame_type, TRUE, pBufLength, &des_addr[0]
#if STD_ON == ETH_BRIDGE_SUPPORT
                    , NULL_PTR
#endif /* ETH_BRIDGE_SUPPORT  */
                    );
        Gpt_Stm_LLD_DelayMs(STM1, 1U);
        Eth_TxConfirmation(Eth_Config.pController[0].gmac_id);
    }
    Eth_Config.pController[0].EnableRxInterrupt = RxIntTmp;
    Eth_Config.pController[0].EnableTxInterrupt = TxIntTmp;
}

void ETH_0007()
{
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    uint8 addr2[6] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xab};
    Eth_RxStatusType rec_ret = ETH_NOT_RECEIVED;

    Eth_Config.pController[0].EnableRxInterrupt = TRUE;
    Eth_Config.pController[0].EnableTxInterrupt = TRUE;
    Eth_Init(&Eth_Config);
    PSPRINTF("Eth_Init is ok\n");
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Eth_UpdatePhysAddrFilter(GMAC_ID_0, (uint8*)&addr2, ETH_ADD_TO_FILTER);
    while (1)
    {
        if (Eth_InternalCfgPtr->pController[Eth_Config.pController[0].gmac_id].EnableRxInterrupt)
        {

        } else {
            Eth_Receive(GMAC_ID_0, 0, &rec_ret);
            Gpt_Stm_LLD_DelayMs(STM1, 1U);
        }
    }
#endif
}

void ETH_0008()
{
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    uint8 addr2[6] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xab};
    Eth_RxStatusType rec_ret = ETH_NOT_RECEIVED;

    Eth_Config.pController[0].EnableRxInterrupt = FALSE;
    Eth_Config.pController[0].EnableTxInterrupt = FALSE;
    Eth_Init(&Eth_Config);
    PSPRINTF("Eth_Init is ok\n");
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Eth_UpdatePhysAddrFilter(GMAC_ID_0, (uint8*)&addr2, ETH_ADD_TO_FILTER);
    while (1)
    {
        if (Eth_InternalCfgPtr->pController[Eth_Config.pController[0].gmac_id].EnableRxInterrupt)
        {

        } else {
            Eth_Receive(GMAC_ID_0, 0, &rec_ret);
            Gpt_Stm_LLD_DelayMs(STM1, 1U);
        }
    }
#endif
}

void ETH_0009()
{
    uint8 des_addr[GMAC_MAC_ADDR_SIZE] = {0x22, 0x34, 0x56, 0xFF, 0xFF, 0xFF};
    uint16 frame_type = 0x0806;

    Eth_BufIdxType BufIdx = 0;
    uint8 *pBufPtr = NULL;
    uint16 pBufLength = 0;
    BufReq_ReturnType buf_ret = BUFREQ_E_NOT_OK;
    uint32 i = 0;
    boolean RxIntTmp = 0;
    boolean TxIntTmp = 0;
    RxIntTmp = Eth_Config.pController[0].EnableRxInterrupt;
    TxIntTmp = Eth_Config.pController[0].EnableTxInterrupt;
    Eth_Config.pController[0].EnableRxInterrupt = TRUE;
    Eth_Config.pController[0].EnableTxInterrupt = TRUE;
    Eth_Init(&Eth_Config);
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Gpt_Stm_LLD_DelayMs(STM1, 100U);

    for (i = 0; i < 10; i++)
    {
        buf_ret = Eth_ProvideTxBuffer(Eth_Config.pController[0].gmac_id, 0, &BufIdx, &pBufPtr, &pBufLength);
        while (buf_ret != BUFREQ_OK)
        {
            ;
        }

        cc_memcpy((uint8 *)pBufPtr, (const uint8 *)g_arp_pkt, pBufLength);
        Eth_Transmit(Eth_Config.pController[0].gmac_id, BufIdx, frame_type, TRUE, pBufLength, &des_addr[0]
#if STD_ON == ETH_BRIDGE_SUPPORT
                    , NULL_PTR
#endif /* ETH_BRIDGE_SUPPORT  */
                    );
        Gpt_Stm_LLD_DelayMs(STM1, 1U);
        Eth_TxConfirmation(Eth_Config.pController[0].gmac_id);
    }
    Eth_Config.pController[0].EnableRxInterrupt = RxIntTmp;
    Eth_Config.pController[0].EnableTxInterrupt = TxIntTmp;
}

void ETH_0010()
{
    uint8 des_addr[GMAC_MAC_ADDR_SIZE] = {0x22, 0x34, 0x56, 0xFF, 0xFF, 0xFF};
    uint16 frame_type = 0x0806;

    Eth_BufIdxType BufIdx = 0;
    uint8 *pBufPtr = NULL;
    uint16 pBufLength = 0;
    BufReq_ReturnType buf_ret = BUFREQ_E_NOT_OK;
    uint32 i = 0;
    boolean RxIntTmp = 0;
    boolean TxIntTmp = 0;
    RxIntTmp = Eth_Config.pController[0].EnableRxInterrupt;
    TxIntTmp = Eth_Config.pController[0].EnableTxInterrupt;
    Eth_Config.pController[0].EnableRxInterrupt = FALSE;
    Eth_Config.pController[0].EnableTxInterrupt = FALSE;
    Eth_Init(&Eth_Config);
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Gpt_Stm_LLD_DelayMs(STM1, 100U);

    for (i = 0; i < 10; i++)
    {
        buf_ret = Eth_ProvideTxBuffer(Eth_Config.pController[0].gmac_id, 0, &BufIdx, &pBufPtr, &pBufLength);
        while (buf_ret != BUFREQ_OK)
        {
            ;
        }

        cc_memcpy((uint8 *)pBufPtr, (const uint8 *)g_arp_pkt, pBufLength);
        Eth_Transmit(Eth_Config.pController[0].gmac_id, BufIdx, frame_type, TRUE, pBufLength, &des_addr[0]
#if STD_ON == ETH_BRIDGE_SUPPORT
                    , NULL_PTR
#endif /* ETH_BRIDGE_SUPPORT  */
                    );
        Gpt_Stm_LLD_DelayMs(STM1, 1U);
        Eth_TxConfirmation(Eth_Config.pController[0].gmac_id);
    }
    Eth_Config.pController[0].EnableRxInterrupt = RxIntTmp;
    Eth_Config.pController[0].EnableTxInterrupt = TxIntTmp;
}

void ETH_0011()
{
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    uint8 addr2[6] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xab};
    Eth_RxStatusType rec_ret = ETH_NOT_RECEIVED;

    Eth_Config.pController[0].EnableRxInterrupt = TRUE;
    Eth_Config.pController[0].EnableTxInterrupt = TRUE;
    Eth_Init(&Eth_Config);
    PSPRINTF("Eth_Init is ok\n");
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Eth_UpdatePhysAddrFilter(GMAC_ID_0, (uint8*)&addr2, ETH_ADD_TO_FILTER);
    while (1)
    {
        if (Eth_InternalCfgPtr->pController[Eth_Config.pController[0].gmac_id].EnableRxInterrupt)
        {

        } else {
            Eth_Receive(GMAC_ID_0, 0, &rec_ret);
            Gpt_Stm_LLD_DelayMs(STM1, 1U);
        }
    }
#endif
}

void ETH_0012()
{
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    uint8 addr2[6] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xab};
    Eth_RxStatusType rec_ret = ETH_NOT_RECEIVED;

    Eth_Config.pController[0].EnableRxInterrupt = FALSE;
    Eth_Config.pController[0].EnableTxInterrupt = FALSE;
    Eth_Init(&Eth_Config);
    PSPRINTF("Eth_Init is ok\n");
    Eth_SetControllerMode(Eth_Config.pController[0].gmac_id, ETH_MODE_ACTIVE);
    Eth_UpdatePhysAddrFilter(GMAC_ID_0, (uint8*)&addr2, ETH_ADD_TO_FILTER);
    while (1)
    {
        if (Eth_InternalCfgPtr->pController[Eth_Config.pController[0].gmac_id].EnableRxInterrupt)
        {

        } else {
            Eth_Receive(GMAC_ID_0, 0, &rec_ret);
            Gpt_Stm_LLD_DelayMs(STM1, 1U);
        }
    }
#endif
}

int eth_func(int argc, char *agrv[])
{
    if ((argc > 4) || (argc < 2))
    {
        PSPRINTF("error: The number of parameters exceeds 3 or is less than 2\n");
    }
    else
    {
        if (argc == 2)
        {
            if (!strcmp(agrv[1], "help"))
            {
                PSPRINTF("set ------- CMD ------- eth set mode speed eg: eth_test set rmii 100\n\
                          get ------- CMD ------- eth get mode speed eg: eth_test get  \n\
                          [1 - %d] ---CMD ------- ID of the test case\n",
                         ETH_TEST_CASE_MAX);
            }
            else if (!strcmp(agrv[1], "get"))
            {
                PSPRINTF(" tranfer mode  %d  ---- 0=RGMII 1=MII 2=RMII,\n\
                           tranfer speed %d  ---- 0=1000M 1=100M 2=10M !\n",
                Eth_Config.pController[0].phy_cfg.transfer_mode, Eth_Config.pController[0].phy_cfg.transfer_speed);
            }
            else
            {
                Eth_IRQ_Priority();
                Gmac_LLD_Transceiver_Cfg(Eth_Config.pController[0].gmac_id, &Eth_Config.pController[0]);

                uint32 id = (uint32)atoi(agrv[1]);

                PSPRINTF("%d\r\n", id);
                if ((id >= 1) && (id <= ETH_TEST_CASE_MAX))
                {
                    if (eth_funcs[id - 1].ethfunc != NULL_PTR)
                    {
                        eth_funcs[id - 1].ethfunc();
                    }
                    else
                    {
                        PSPRINTF("error: The ID entered does not correspond to the test code\n");
                    }
                }
                else
                {
                    PSPRINTF("error: Input invalid parameters[%d], please output [1 - %d] range parameters\n", id, ETH_TEST_CASE_MAX);
                }
            }
        }
        else
        {
            if (!strcmp(agrv[1], "set"))
            {
                if (!strcmp(agrv[2], "rgmii"))
                {
                    Eth_Config.pController[0].phy_cfg.transfer_mode = GMAC_TRANS_RGMII_MODE;
                }
                else if (!strcmp(agrv[2], "rmii"))
                {
                    Eth_Config.pController[0].phy_cfg.transfer_mode = GMAC_TRANS_RMII_MODE;
                }
                else if (!strcmp(agrv[2], "mii"))
                {
                    Eth_Config.pController[0].phy_cfg.transfer_mode = GMAC_TRANS_MII_MODE;
                }
                else
                {
                    PSPRINTF("error: tranfer mode %s device is not used!\n", agrv[2]);
                }

                if (!strcmp(agrv[3], "1000"))
                {
                    Eth_Config.pController[0].phy_cfg.transfer_speed = GMAC_TRANS_SPEED_1000M;
                }
                else if (!strcmp(agrv[3], "100"))
                {
                    Eth_Config.pController[0].phy_cfg.transfer_speed = GMAC_TRANS_SPEED_100M;
                }
                else if (!strcmp(agrv[3], "10"))
                {
                    Eth_Config.pController[0].phy_cfg.transfer_speed = GMAC_TRANS_SPEED_10M;
                }
                else
                {
                    PSPRINTF("error: tranfer speed %sM device is not used!\n", agrv[3]);
                }

                PSPRINTF("set tranfer mode %s, tranfer speed %sM !\n", agrv[2], agrv[3]);
            }
        }
    }
    return 0;
}
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0) | SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), eth_test, eth_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
