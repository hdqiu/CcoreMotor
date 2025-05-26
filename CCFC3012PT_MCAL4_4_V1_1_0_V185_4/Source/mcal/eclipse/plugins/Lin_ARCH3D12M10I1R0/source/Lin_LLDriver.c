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
 *
 *   @file    Lin_LLDriver.c
 *   @version 1.0.1
 *
 *   @brief   AUTOSAR Lin - LLDrivers.
 *   @details File containing the low level driver of the LLDrivers IP.
 *
 *   @addtogroup MCAL
 *   @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*======================================INCLUDE FILES===============================================*/
#include "Lin.h"
#include "Lin_LLDriver.h"
#include "LinIf.h"
#include "Mcu_LLDriver.h"
#include "eDma.h"
#include "SchM_Lin.h"
#include "common.h"
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_LLD_C_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_LLD_C_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_LLD_C_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_LLD_C_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_LLD_C_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_LLD_C_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_LLD_C_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_LLD_C_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_LLD_C_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_LLD_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_LLD_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_C_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_LLD_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_LLD_C_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_LLD_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_C_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_LLD_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_C_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_LLD_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_LLD_C_SW_PATCH_VER "
#endif
/*=========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)===============================*/

/*======================================LOCAL MACROS================================================*/

/*======================================LOCAL CONSTANTS=============================================*/

/*======================================LOCAL VARIABLES=============================================*/
#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
extern volatile VAR(uint8, LIN_VAR) u8Lin_TransmitHeaderCmd[LIN_HW_MAX_AVAILABLE_MODULES];
static volatile VAR(uint8, LIN_VAR) g_u8Lin_LLD_StateOfBEF[LIN_HW_MAX_AVAILABLE_MODULES];
#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

/*======================================GLOBAL CONSTANTS============================================*/
#define LIN_START_SEC_VAR_INIT
#include "Lin_MemMap.h"



static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D0;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D1;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D2;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D3;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D4;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D5;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D6;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D7;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D8;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D9;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D10;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D11;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D12;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D14;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D15;
static VAR(Lin_flexDrivers, AUTOMATIC) s_sLinflex_D16;

extern volatile Lin_Configs g_sLin_HW_Config[LIN_HW_MAX_AVAILABLE_MODULES];

#define LIN_STOP_SEC_VAR_INIT
#include "Lin_MemMap.h"

#define LIN_START_SEC_VAR_SHARED_INIT
#include "Lin_MemMap.h"
VAR(uint32, AUTOMATIC) u32_txBuffdma[LIN_HW_MAX_AVAILABLE_MODULES][4] = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
#define LIN_STOP_SEC_VAR_SHARED_INIT
#include "Lin_MemMap.h"

/*======================================GLOBAL VARIABLES============================================*/

/*==================================LOCAL FUNCTION PROTOTYPES=======================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

LOCAL_INLINE FUNC(void, LIN_CODE) LINFlex_LLD_RXI_IRQHandler(VAR(uint8, AUTOMATIC) u8Lin_Channel);
LOCAL_INLINE FUNC(void, LIN_CODE) LINFlex_LLD_TXI_IRQHandler(VAR(uint8, AUTOMATIC) u8Lin_Channel);
LOCAL_INLINE FUNC(void, LIN_CODE) LINFlex_LLD_ERR_IRQHandler(VAR(uint8, AUTOMATIC) u8Lin_Channel);

LOCAL_INLINE FUNC(void, LIN_CODE) Lin_ConfigureDmaTransfer(uint8 channel, uint32 srcAddr, uint32 destAddr, uint32 len);
LOCAL_INLINE void Lin_Buf_Convert(uint8 *out_buf, uint8 const *in_buf, uint8 len);
LOCAL_INLINE uint8 Lin_LLD_GetChannel(uint8 channel);

LOCAL_INLINE uint8 Lin_LLD_GetChannel(uint8 channel)
{
    for(uint8 i = 0; i < 17U; i++)
    {
        if(channel == g_pLin_ChannelConfigPtr[i]->u8LinHwChannel)
        {
            return g_pLin_ChannelConfigPtr[i]->u8LinChannelID;
        }
    }
    return 0xFF;
}

LOCAL_INLINE void Lin_Buf_Convert(uint8 *out_buf, uint8 const *in_buf, uint8 len)
{
    uint8 gtFour = 0;
    uint16_t i, max_index = 3U;
    t_data tData;
    uint8 len_temp = len;
    uint8 const *ptemp = in_buf;
    while (len_temp > 0U)
    {
        for (i = 0; i < 4U; i++)
        {
            tData.b[i] = 0;
        }
        for (i = 0; ((i < len_temp) && (i < 4U)); i++)
        {
            tData.b[max_index - i] = *ptemp;
            ptemp++;
        }
        if (gtFour == 0U)
        {
            for (i = 0; i < 4U; i++)
            {
                out_buf[i] = tData.b[i];
            }
            gtFour = 1;
        }
        else
        {
            for (i = 0; i < 4U; i++)
            {
                out_buf[4U+i] = tData.b[i];
            }
        }
        if (len_temp < 4U)
        {
            len_temp = 0U;
        }
        else
        {
            len_temp = (uint8)(len_temp - 4U);
        }
    }
}

LOCAL_INLINE void Lin_ConfigureDmaTransfer(uint8 channel, uint32 srcAddr, uint32 destAddr, uint32 len)
{
    (void)EDMA_SetMultiTransferConfig(channel,
                                          EDMA_TRANSFER_TYPE_MEMTOMEM,
                                          srcAddr,
                                          destAddr,
                                          EDMA_TRANSFER_SIZE_4B,
                                          len,
                                          1u,
                                          TRUE);
    EDMA_SetInterruptConfig(channel, EDMA_CHN_ENABLE_MAJOR_LOOP_DONE_INT, FALSE);
    EDMA_SwRequestTriggerEn(channel);
    EDMA_WaitChnTransferDone(channel);
}

static FUNC(void, LIN_CODE) lld_txi(P2CONST(LinLldDrivers, AUTOMATIC, LIN_APPL_CONST) spLin_Ldp, \
        P2CONST(uint8, AUTOMATIC, LIN_APPL_CONST) u8pLin_Tx_Buf, VAR(uint8, AUTOMATIC) u8Lin_Len)
{
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD = spLin_Ldp->linflexD;
    VAR(t_data, AUTOMATIC) sLin_TData;
    VAR(uint8, AUTOMATIC) u8Lin_GtFour = 0;
    VAR(uint16, AUTOMATIC) u16Lin_I, u16Lin_Max_Index = 3U;
    VAR(uint16, AUTOMATIC) u16Lin_Len_Temp = u8Lin_Len;
    P2CONST(uint8, AUTOMATIC, LIN_APPL_CONST) u8pLin_Ptemp = u8pLin_Tx_Buf;

    while (u16Lin_Len_Temp > 0U)
    {
        /* Clean temporary buffer before transmit data. */
        for (u16Lin_I = 0; u16Lin_I < 4U; u16Lin_I++)
        {
            sLin_TData.b[u16Lin_I] = 0;
        }

        /* Fill temporary buffer with the characters to transmit (u8pLin_Tx_Buf). */
        for (u16Lin_I = 0; ((u16Lin_I < u16Lin_Len_Temp) && (u16Lin_I < 4U)); u16Lin_I++)
        {
            sLin_TData.b[u16Lin_Max_Index - u16Lin_I] = *u8pLin_Ptemp; /* PRQA S 2987 */
            u8pLin_Ptemp++;                         /* PRQA S 2987 */
        }

        /* Transfer temporary buffer to Buffer Data Register. */
        if (u8Lin_GtFour == 0U)
        {
            sLin_FlexD->BDRL.R = sLin_TData.w;
            u8Lin_GtFour = 1;
        }
        else
        {
            sLin_FlexD->BDRM.R = sLin_TData.w;
        }

        if (u16Lin_Len_Temp < 4U)
        {
            u16Lin_Len_Temp = 0U;
        }
        else
        {
            u16Lin_Len_Temp = (uint16)(u16Lin_Len_Temp - 4U);
        }
    }
}
static FUNC(void, LIN_CODE) lld_rxi(P2CONST(LinLldDrivers, AUTOMATIC, LIN_APPL_CONST) spLin_Ldp, \
        P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) u8pLin_SduPtr)
{
    volatile P2CONST(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_CONST) sLin_FlexD = spLin_Ldp->linflexD;
    VAR(t_data, AUTOMATIC) sLin_TData;
    VAR(uint8, AUTOMATIC) u8Lin_GtFour = 0;
    VAR(uint16, AUTOMATIC) u16Lin_I, u16Lin_Max_Index = 3U;
    VAR(uint16, AUTOMATIC) u16Lin_Len_Temp = (uint16)(sLin_FlexD->BIDR.B.DFL + 1U);
    VAR(uint16, AUTOMATIC) u8Lin_Len = u16Lin_Len_Temp;
    P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA)u8pLin_Ptemp = u8pLin_SduPtr;

    while (u16Lin_Len_Temp > 0U)
    {
        /* Clean temporary buffer before to receive data. */
        for (u16Lin_I = 0; u16Lin_I < 4U; u16Lin_I++)
        {
            sLin_TData.b[u16Lin_I] = 0;
        }

        /* Transfer Buffer Data Register to temporary data. */
        if (u8Lin_GtFour == 0U)
        {
            sLin_TData.w = sLin_FlexD->BDRL.R;
            u8Lin_GtFour = 1;
        }
        else
        {
            sLin_TData.w = sLin_FlexD->BDRM.R;
        }

        /* Fill RX buffer (rx_buf) from temporary data buffer with the character to receive. */
        for (u16Lin_I = 0; ((u16Lin_I < u8Lin_Len) && (u16Lin_I < 4U)); u16Lin_I++)
        {
            *u8pLin_Ptemp = sLin_TData.b[u16Lin_Max_Index - u16Lin_I];    /* Endianess to take in account */
            u8pLin_Ptemp++;
        }

        if (u16Lin_Len_Temp < 4U)
        {
            u16Lin_Len_Temp = 0U;
        }
        else
        {
            u16Lin_Len_Temp = (uint16)(u16Lin_Len_Temp - 4U);
        }
    }

}

LOCAL_INLINE FUNC(void, LIN_CODE) lin_lld_slave_transmit(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) spLin_PduInfoPtr)
{
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;

    if(spLin_PduInfoPtr->Drc == LIN_FRAMERESPONSE_TX)
    {
        sLin_FlexD->BIDR.B.CCS = (uint32)spLin_PduInfoPtr->Cs;
        sLin_FlexD->BIDR.B.DIR = (uint32)LIN_DIR_TRANSMIT;
        sLin_FlexD->BIDR.B.DFL = (uint32)spLin_PduInfoPtr->Dl - (uint32)1;
        sLin_FlexD->BIDR.B.ID = spLin_PduInfoPtr->Pid;
        
        sLin_FlexD->BDRL.R = 0;
        sLin_FlexD->BDRM.R = 0;
        if(g_sLin_HW_Config[u8Lin_Channel].DmaSupport == (uint8)STD_ON)
        {
            uint32 temp = 0;
            temp = (uint32)((uint32)spLin_PduInfoPtr->Dl - 1u);
            temp = ((temp) << 10u);
            uint32 css = (uint32)spLin_PduInfoPtr->Cs;
            temp = (css << 8) | temp;
            temp = (uint32)spLin_PduInfoPtr->Pid |temp;
            temp = (uint32)0x00000200|(uint32)temp;
            u32_txBuffdma[u8Lin_Channel][0] = 0x00000000;                  /** CR2 register **/
            u32_txBuffdma[u8Lin_Channel][1] = (uint32)temp;                /** BIDR register **/
            Lin_Buf_Convert((uint8 *)&u32_txBuffdma[u8Lin_Channel][2],spLin_PduInfoPtr->SduPtr, spLin_PduInfoPtr->Dl);

            Lin_ConfigureDmaTransfer(g_sLin_HW_Config[u8Lin_Channel].ldp->config->DmaTxChannel, \
                    (uint32)&u32_txBuffdma[u8Lin_Channel][2],                 \
                    (uint32)(&(sLin_FlexD->BDRL)),     \
                    8u                                 \
            );
        }
        else
        {
        	lld_txi(g_sLin_HW_Config[u8Lin_Channel].ldp, spLin_PduInfoPtr->SduPtr, spLin_PduInfoPtr->Dl);
        }
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
        /* Set timeout */
        sLin_FlexD->LINESR.R = LINFLEX_LINESR_OCF_MASK_U32;
        sLin_FlexD->LINIER.B.OCIE = 1;
#endif/* LIN_DISABLE_FRAME_TIMEOUT */
        sLin_FlexD->LINCR2.B.DTRQ = 1;
    }
    else if(spLin_PduInfoPtr->Drc == LIN_FRAMERESPONSE_RX)
    {
        sLin_FlexD->BIDR.B.CCS = (uint32)spLin_PduInfoPtr->Cs;
        sLin_FlexD->BIDR.B.DIR = (uint32)LIN_DIR_RECEIVE;
        sLin_FlexD->BIDR.B.DFL = (uint32)spLin_PduInfoPtr->Dl - (uint32)1;
        sLin_FlexD->BIDR.B.ID = spLin_PduInfoPtr->Pid;
    }
    else if(spLin_PduInfoPtr->Drc == LIN_FRAMERESPONSE_IGNORE)
    {
        sLin_FlexD->LINCR2.B.DDRQ = 1;
        sLin_FlexD->LINSR.R = LINFLEX_LINSR_DRBNE_MASK_U32;
    }
    else
    {
        /* nothing */
    }
}

/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX0_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D0.rxi_lincallback(0);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX0_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D0.txi_lincallback(0);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX0_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D0.err_lincallback(0);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX1_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D1.rxi_lincallback(1);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX1_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D1.txi_lincallback(1);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX1_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D1.err_lincallback(1);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX2_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D2.rxi_lincallback(2);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX2_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D2.txi_lincallback(2);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX2_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D2.err_lincallback(2);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX3_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D3.rxi_lincallback(3);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX3_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D3.txi_lincallback(3);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX3_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D3.err_lincallback(3);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX4_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D4.rxi_lincallback(4);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX4_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D4.txi_lincallback(4);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX4_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D4.err_lincallback(4);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX5_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D5.rxi_lincallback(5);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX5_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D5.txi_lincallback(5);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX5_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D5.err_lincallback(5);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX6_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D6.rxi_lincallback(6);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX6_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D6.txi_lincallback(6);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX6_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D6.err_lincallback(6);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX7_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D7.rxi_lincallback(7);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX7_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D7.txi_lincallback(7);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX7_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D7.err_lincallback(7);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX8_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D8.rxi_lincallback(8);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX8_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D8.txi_lincallback(8);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX8_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D8.err_lincallback(8);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX9_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D9.rxi_lincallback(9);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX9_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D9.txi_lincallback(9);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX9_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D9.err_lincallback(9);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX10_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D10.rxi_lincallback(10);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX10_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D10.txi_lincallback(10);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX10_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D10.err_lincallback(10);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX11_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D11.rxi_lincallback(11);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX11_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D11.txi_lincallback(11);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX11_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D11.err_lincallback(11);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX12_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D12.rxi_lincallback(12);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX12_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D12.txi_lincallback(12);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX12_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D12.err_lincallback(12);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX14_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D14.rxi_lincallback(14);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX14_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D14.txi_lincallback(14);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX14_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D14.err_lincallback(14);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX15_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D15.rxi_lincallback(15);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX15_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D15.txi_lincallback(15);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX15_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D15.err_lincallback(15);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX16_LLD_RXI_IRQ_HANDLER(void)
{
    s_sLinflex_D16.rxi_lincallback(16);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX16_LLD_TXI_IRQ_HANDLER(void)
{
    s_sLinflex_D16.txi_lincallback(16);
}
/* Specification of Lin Driver : [SWS_Lin_00155] */
FUNC(void, LIN_CODE) LINFLEX16_LLD_ERR_IRQ_HANDLER(void)
{
    s_sLinflex_D16.err_lincallback(16);
}



FUNC(void, LIN_CODE)Lin_LLD_Start(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
    VAR(uint32, AUTOMATIC) u32Temp1;
    VAR(uint32, AUTOMATIC) u32Temp2;
    VAR(uint32, AUTOMATIC) u32LINOCR_OC;
#endif /* LIN_DISABLE_FRAME_TIMEOUT */
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD \
            = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;

    
    SchM_Enter_LIN_EXCLUSIVE_AREA_00();
    sLin_FlexD->LINCR1.B.SLEEP = 0; /* exit sleep mode, Enters the configuration mode */
    sLin_FlexD->LINCR1.B.INIT = 1;  /* Enter in Initialization Mode  */
    SchM_Exit_LIN_EXCLUSIVE_AREA_00();

    while (0x1000U != (sLin_FlexD->LINSR.R & 0xF000U))
    {
        ;
    }

    SchM_Enter_LIN_EXCLUSIVE_AREA_01();
    sLin_FlexD->UARTCR.B.UART = 0;
    sLin_FlexD->LINCR1.B.MME = (uint8)g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode; /* Select Master/Slave mode */
    sLin_FlexD->LINCR1.B.MBL = (uint8)g_sLin_HW_Config[u8Lin_Channel].mbl;
    sLin_FlexD->LINCR1.B.LASE = 0; /* Auto synchronization disabled */
    sLin_FlexD->LINCR1.B.BF = 0;
    sLin_FlexD->LINCR1.B.AUTOWU = 1;

    sLin_FlexD->LINTOCR.B.RTO = (uint8)g_sLin_HW_Config[u8Lin_Channel].rto;

    if (g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
    {
        if (g_sLin_HW_Config[u8Lin_Channel].sbl == 10U)
        {
            sLin_FlexD->LINCR1.B.SSBL = 1;
        }
        else
        {
            sLin_FlexD->LINCR1.B.SSBL = 0;
        }
        sLin_FlexD->LINTOCR.B.HTO = (uint8)g_sLin_HW_Config[u8Lin_Channel].hto;
        sLin_FlexD->LINIER.B.HEIE = 1;
        sLin_FlexD->LINIER.B.HRIE = 1;
    }
    else
    {
        sLin_FlexD->LINIER.B.HEIE = 0;
        sLin_FlexD->LINIER.B.HRIE = 0;
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_01();

    SchM_Enter_LIN_EXCLUSIVE_AREA_02();
    sLin_FlexD->LINCR2.B.IOBE = 0;  /* Bit Error does not reset LIN state machine */

#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
    /*** LIN timeout config ***/

    /* the MODE bit can be read in any mode, written only in initialization mode.*/
    sLin_FlexD->LINTCSR.B.MODE = 1;        /* LIN output compare mode for 8 - bit counter */
    sLin_FlexD->LINTCSR.B.IOT  = 0;        /* !!!IMPORTANT!!!: do not reset LIN state to Idle on timeout */
    sLin_FlexD->LINTCSR.B.TOCE = 0;        /* Time - out counter enable - OCF flag is set if an output compare event occurs */

    if(g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_MASTER)
    {
        /* there is no meaning of header timeout in master mode, so it is disabled */
        u32Temp1 = sLin_FlexD->LINTOCR.B.HTO; /* Header timeout value */
        u32Temp2 = (sLin_FlexD->LINTOCR.B.RTO) * ((uint32)LIN_DATA_LEN+1U);/* OC2: T(response_time) */

        u32LINOCR_OC = sLin_FlexD->LINOCR.R;
        u32LINOCR_OC &= ~LINFlexD_LINOCR_OC2_MASK;   /*clear  bit */
        u32LINOCR_OC |= ((u32Temp2 << 8U) & 0xFF00U);
    }
    else /* Slave Mode */
    {
        u32Temp1 = sLin_FlexD->LINTCSR.B.CNT + 49U;/* Header_max = 49Tbit */
        u32Temp2 = (sLin_FlexD->LINTOCR.B.RTO) * ((uint32)LIN_DATA_LEN+1U);/* OC2: T(response_time) */

        u32LINOCR_OC = sLin_FlexD->LINOCR.R;
        u32LINOCR_OC &= (~LINFlexD_LINOCR_OC2_MASK); /*clear  bit */
        u32LINOCR_OC &= (~LINFlexD_LINOCR_OC1_MASK); /*clear  bit */
        u32LINOCR_OC |= (u32Temp1 & 0xFFU)|((u32Temp2 << 8U) & 0xFF00U);
    }
    /* LINOCR register is writable by software only in Output Compare Mode. */
    sLin_FlexD->LINOCR.R = u32LINOCR_OC;

    /* change MODE to LIN MODE */
    sLin_FlexD->LINTCSR.B.MODE = 0;

    /*** LIN timeout config end ***/
#else
    sLin_FlexD->LINTCSR.B.MODE = 0; /* LIN timeout mode for 8 - bit counter */
    sLin_FlexD->LINTCSR.B.IOT = 0;  /* LIN state machine does not reset to Idle on timeout */
    sLin_FlexD->LINTCSR.B.TOCE = 0; /* Time - out counter enable - OCF flag is set if an output compare event occurs */
#endif /* LIN_DISABLE_FRAME_TIMEOUT */

    sLin_FlexD->LINSR.R = 0xFFFF; /* Clearing LINSR register. */

    /* Specification of Lin Driver : [SWS_Lin_00011] */
    /* Set the LIN baud Rate */
    sLin_FlexD->LINFBRR.B.FBR = ((g_sLin_HW_Config[u8Lin_Channel].ldp->config->speed) \
            & LINFLEX_LINFBRR_DIV_F_MASK_U32);
    sLin_FlexD->LINIBRR.B.IBR = ((g_sLin_HW_Config[u8Lin_Channel].ldp->config->speed) \
            & LINFLEX_LINIBRR_DIV_M_MASK_U32) >> (uint8)8U;

    SchM_Exit_LIN_EXCLUSIVE_AREA_02();
    SchM_Enter_LIN_EXCLUSIVE_AREA_03();
    sLin_FlexD->LINIER.R = 0;     /* LIN Interrupts disabled.     */

    sLin_FlexD->LINIER.B.BEIE = 1;  /* Enable Bit Error Interrupt */
    sLin_FlexD->LINIER.B.CEIE = 1;  /* Enable Checksum Error Interrupt */
    sLin_FlexD->LINIER.B.FEIE = 1;  /* Enable Frame Error Interrupt */
    sLin_FlexD->LINIER.B.BOIE = 1;  /* Enable Buffer Overrun Error Interrupt */
    sLin_FlexD->LINIER.B.HEIE = 0;  /* Disable Header Error Interrupt */
    sLin_FlexD->LINIER.B.DTIE = 1;  /* Enable Data Transmitted Interrupt */
    sLin_FlexD->LINIER.B.SZIE = 0;  /* Disable Stuck at zero Interrupt*/


    /* Enable Header transmit interrupt */
    sLin_FlexD->LINIER.B.HRIE = 1;
    /** No code **/

    /* Enable receive interrupt */
    sLin_FlexD->LINIER.B.DRIE = 1;
    /** No code **/

    if (g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
    {
        sLin_FlexD->LINCR1.B.BF = 1;
    }
    else
    {
        /** No code **/
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_03();
    SchM_Enter_LIN_EXCLUSIVE_AREA_04();
    /* Leaves the configuration mode.*/
    sLin_FlexD->LINCR1.B.SLEEP = 1; /* Enter in normal mode */

    if (g_sLin_HW_Config[u8Lin_Channel].WakeupSupport == (uint8)STD_ON)
    {
        sLin_FlexD->LINSR.R = LINFLEX_LINSR_WUF_MASK_U32;
        sLin_FlexD->LINIER.B.WUIE = 1;
    }
    else
    {
        /** No code **/
    }
    sLin_FlexD->LINCR1.B.INIT = 0;
    SchM_Exit_LIN_EXCLUSIVE_AREA_04();
}

/*****************************************************************************
** Service Name      : Lin_LLD_InitChannel
**
**
**  Description      : This function initialize a LIN channel.
**
**  Parameters (in)  : Channel : LIN channel to be addressed.
**
**  Parameters (out) : None
**
**  Return value     : None
**
******************************************************************************/
FUNC(void, LIN_CODE)Lin_LLD_Init(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(LinLldConfig, AUTOMATIC, LIN_APPL_CONST) sLin_Config)
{
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_0;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_1;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_2;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_3;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_4;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_5;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_6;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_7;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_8;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_9;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_10;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_11;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_12;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_14;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_15;
    static VAR(LinLldDrivers, AUTOMATIC) g_sLin_16;
    switch (u8Lin_Channel)
    {
    case 0:
        g_sLin_0.linflexD = &CCFC3012PT_LINLLDFLEX0L;
        g_sLin_0.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D0.device = (uint32)&g_sLin_0;
        s_sLinflex_D0.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D0.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D0.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_0;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D0;
        break;
    case 1:
        g_sLin_1.linflexD = &CCFC3012PT_LINLLDFLEX1L;
        g_sLin_1.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D1.device = (uint32)&g_sLin_1;
        s_sLinflex_D1.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D1.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D1.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_1;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D1;
        break;
    case 2:
        g_sLin_2.linflexD = &CCFC3012PT_LINLLDFLEX2L;
        g_sLin_2.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D2.device = (uint32)&g_sLin_2;
        s_sLinflex_D2.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D2.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D2.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_2;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D2;
        break;
    case 3:
        g_sLin_3.linflexD = &CCFC3012PT_LINLLDFLEX3L;
        g_sLin_3.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D3.device = (uint32)&g_sLin_3;
        s_sLinflex_D3.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D3.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D3.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_3;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D3;
        break;
    case 4:
        g_sLin_4.linflexD = &CCFC3012PT_LINLLDFLEX4L;
        g_sLin_4.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D4.device = (uint32)&g_sLin_4;
        s_sLinflex_D4.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D4.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D4.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_4;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D4;
        break;
    case 5:
        g_sLin_5.linflexD = &CCFC3012PT_LINLLDFLEX5L;
        g_sLin_5.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D5.device = (uint32)&g_sLin_5;
        s_sLinflex_D5.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D5.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D5.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_5;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D5;
        break;
    case 6:
        g_sLin_6.linflexD = &CCFC3012PT_LINLLDFLEX6L;
        g_sLin_6.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D6.device = (uint32)&g_sLin_6;
        s_sLinflex_D6.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D6.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D6.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_6;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D6;
        break;
    case 7:
        g_sLin_7.linflexD = &CCFC3012PT_LINLLDFLEX7L;
        g_sLin_7.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D7.device = (uint32)&g_sLin_7;
        s_sLinflex_D7.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D7.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D7.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_7;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D7;
        break;
    case 8:
        g_sLin_8.linflexD = &CCFC3012PT_LINLLDFLEX8L;
        g_sLin_8.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D8.device = (uint32)&g_sLin_8;
        s_sLinflex_D8.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D8.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D8.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_8;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D8;
        break;
    case 9:
        g_sLin_9.linflexD = &CCFC3012PT_LINLLDFLEX9L;
        g_sLin_9.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D9.device = (uint32)&g_sLin_9;
        s_sLinflex_D9.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D9.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D9.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_9;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D9;
        break;
    case 10:
        g_sLin_10.linflexD = &CCFC3012PT_LINLLDFLEX10L;
        g_sLin_10.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D10.device = (uint32)&g_sLin_10;
        s_sLinflex_D10.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D10.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D10.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_10;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D10;
        break;
    case 11:
        g_sLin_11.linflexD = &CCFC3012PT_LINLLDFLEX11L;
        g_sLin_11.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D11.device = (uint32)&g_sLin_11;
        s_sLinflex_D11.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D11.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D11.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_11;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D11;
        break;
    case 12:
        g_sLin_12.linflexD = &CCFC3012PT_LINLLDFLEX12L;
        g_sLin_12.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D12.device = (uint32)&g_sLin_12;
        s_sLinflex_D12.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D12.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D12.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_12;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D12;
        break;
    case 14:
        g_sLin_14.linflexD = &CCFC3012PT_LINLLDFLEX14L;
        g_sLin_14.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D14.device = (uint32)&g_sLin_14;
        s_sLinflex_D14.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D14.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D14.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_14;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D14;
        break;
    case 15:
        g_sLin_15.linflexD = &CCFC3012PT_LINLLDFLEX15L;
        g_sLin_15.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D15.device = (uint32)&g_sLin_15;
        s_sLinflex_D15.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D15.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D15.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_15;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D15;
        break;
    case 16:
        g_sLin_16.linflexD = &CCFC3012PT_LINLLDFLEX16L;
        g_sLin_16.config = sLin_Config; /* PRQA S 2919 */
        s_sLinflex_D16.device = (uint32)&g_sLin_16;
        s_sLinflex_D16.rxi_lincallback = &LINFlex_LLD_RXI_IRQHandler;
        s_sLinflex_D16.txi_lincallback = &LINFlex_LLD_TXI_IRQHandler;
        s_sLinflex_D16.err_lincallback = &LINFlex_LLD_ERR_IRQHandler;
        g_sLin_HW_Config[u8Lin_Channel].ldp = &g_sLin_16;
        g_sLin_HW_Config[u8Lin_Channel].Linflex = s_sLinflex_D16;
        break;
    default:
        /* nothing */
        break;
    }
    g_u8Lin_LLD_StateOfBEF[u8Lin_Channel] = 0U;
}

FUNC(Std_ReturnType, LIN_CODE)Lin_LLD_Master_Transmit(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) spLin_PduInfoPtr)
{
    volatile VAR(uint32, AUTOMATIC) u32Lin_Counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_NOT_OK;
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD \
            = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;
    SchM_Enter_LIN_EXCLUSIVE_AREA_05();
    /* Abort transfer data */
    sLin_FlexD->LINCR2.B.ABRQ = 1;

    while (u32Lin_Counter <= LIN_TIMEOUT_LOOPS)
    {   
        u32Lin_Counter++;
        if (0U == (sLin_FlexD->LINCR2.R & LINFLEX_LINCR2_REQUEST_MASK_U32))
        {
            u8Lin_ReturnValue = (uint8)E_OK;
            break;
        }
    }

    if ((uint8)E_OK == u8Lin_ReturnValue)
    {
        u8Lin_ChFrameErrorStatus[u8Lin_Channel] = LIN_NO_ERROR;

        /* Set Header */
        sLin_FlexD->BIDR.R = 0;
        sLin_FlexD->BIDR.B.ID = (uint32)spLin_PduInfoPtr->Pid & 0x3FU;
        sLin_FlexD->BIDR.B.DFL = (uint32)spLin_PduInfoPtr->Dl - 1U; /* Configure DFL in BIDR */
        sLin_FlexD->BIDR.B.CCS = (uint32)spLin_PduInfoPtr->Cs;

        if (LIN_FRAMERESPONSE_TX == spLin_PduInfoPtr->Drc)
        {
            u8Lin_TransmitHeaderCmd[u8Lin_Channel] = LIN_TX_MASTER_RES_COMMAND_U8;
            u8Lin_ChFrameStatus[u8Lin_Channel] = LIN_CH_READY_STATE;

            sLin_FlexD->BIDR.B.DIR = (uint32)LIN_DIR_TRANSMIT;
            /* Save message parameters */
            g_sLin_HW_Config[u8Lin_Channel].ldp->tx_id_msg = spLin_PduInfoPtr->Pid;
            g_sLin_HW_Config[u8Lin_Channel].ldp->tx_buf = spLin_PduInfoPtr->SduPtr;
            g_sLin_HW_Config[u8Lin_Channel].ldp->tx_len = spLin_PduInfoPtr->Dl;

            if(g_sLin_HW_Config[u8Lin_Channel].DmaSupport == (uint8)STD_ON)
            {
                uint32 temp = 0;
                temp = (uint32)((uint32)spLin_PduInfoPtr->Dl - 1u);
                temp = ((temp) << 10u);
                uint32 css = (uint32)spLin_PduInfoPtr->Cs;
                temp = (css << 8) | temp;
                temp = (uint32)spLin_PduInfoPtr->Pid |temp;
                temp = (uint32)0x00000200|(uint32)temp;
                u32_txBuffdma[u8Lin_Channel][0] = 0x00000000;                  /** CR2 register **/
                u32_txBuffdma[u8Lin_Channel][1] = (uint32)temp;                /** BIDR register **/
                Lin_Buf_Convert((uint8 *)&u32_txBuffdma[u8Lin_Channel][2],spLin_PduInfoPtr->SduPtr, spLin_PduInfoPtr->Dl);
                Lin_ConfigureDmaTransfer(g_sLin_HW_Config[u8Lin_Channel].ldp->config->DmaTxChannel, \
                        (uint32)u32_txBuffdma[u8Lin_Channel],                 \
                        (uint32)(&(sLin_FlexD->LINCR2)),     \
                        16u                                    \
                );
            }
            else
            {
                lld_txi(g_sLin_HW_Config[u8Lin_Channel].ldp, spLin_PduInfoPtr->SduPtr, spLin_PduInfoPtr->Dl);
            }
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
            /* Set timeout */
            sLin_FlexD->LINESR.R = LINFLEX_LINESR_OCF_MASK_U32;
            sLin_FlexD->LINIER.B.OCIE = 1;
#endif /* LIN_DISABLE_FRAME_TIMEOUT */
            /* Enable transmit interrupt */

            /* Trigger Header transmission*/
            sLin_FlexD->LINCR2.B.HTRQ = 1;
        }
        else if (LIN_FRAMERESPONSE_RX == spLin_PduInfoPtr->Drc)
        {
            u8Lin_TransmitHeaderCmd[u8Lin_Channel] = LIN_TX_SLAVE_RES_COMMAND_U8;
            u8Lin_ChFrameStatus[u8Lin_Channel] = LIN_CH_RECEIVE_NOTHING_STATE;

            g_sLin_HW_Config[u8Lin_Channel].ldp->rx_len = spLin_PduInfoPtr->Dl;

            sLin_FlexD->LINSR.R = LINFLEX_LINSR_RMB_MASK_U32;
            sLin_FlexD->LINESR.R = LINFLEX_LINESR_NF_MASK_U32;

            sLin_FlexD->BIDR.B.DIR = (uint8)LIN_DIR_RECEIVE;

            sLin_FlexD->BDRL.R = 0;
            sLin_FlexD->BDRM.R = 0;
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
            /* Set timeout */
            sLin_FlexD->LINESR.R = LINFLEX_LINESR_OCF_MASK_U32;
            sLin_FlexD->LINIER.B.OCIE = 1;
#endif /* LIN_DISABLE_FRAME_TIMEOUT */
            /* Enable Data Receive interrupt */
            sLin_FlexD->LINIER.B.DRIE = 1;

            /* Trigger Header transmission*/
            sLin_FlexD->LINCR2.B.HTRQ = 1;
        }
        else
        {
            u8Lin_TransmitHeaderCmd[u8Lin_Channel] = LIN_TX_SLAVETOSLAVE_COMMAND_U8;
            u8Lin_ChFrameStatus[u8Lin_Channel] = LIN_CH_READY_STATE;
        }
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_05();

    return u8Lin_ReturnValue;
}

FUNC(Std_ReturnType, LIN_CODE)Lin_LLD_GoToSleep(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    volatile VAR(uint32, AUTOMATIC) u32Lin_Counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC)u8Lin_ReturnValue = (uint8)E_NOT_OK;
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD \
            = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;

    SchM_Enter_LIN_EXCLUSIVE_AREA_06();
    /* Stop any ongoing transmission */
    sLin_FlexD->LINCR2.B.ABRQ = 1;
    SchM_Exit_LIN_EXCLUSIVE_AREA_06();

    while (u32Lin_Counter <= LIN_TIMEOUT_LOOPS)
    {   
        u32Lin_Counter++;
        if (0U == (sLin_FlexD->LINCR2.R & LINFLEX_LINCR2_REQUEST_MASK_U32))
        {
            u8Lin_ReturnValue = (uint8)E_OK;
            break;
        }
    }
    SchM_Enter_LIN_EXCLUSIVE_AREA_07();
    if ((uint8)E_OK == u8Lin_ReturnValue)
    {
        sLin_FlexD->LINSR.R = LINFLEX_LINSR_RMB_MASK_U32;
        sLin_FlexD->BIDR.B.CCS = 1;
        sLin_FlexD->BIDR.B.DIR = 1;
        sLin_FlexD->BIDR.B.ID = 0x3C;
        sLin_FlexD->BIDR.B.DFL = 7;

        sLin_FlexD->BDRM.R = 0;
        sLin_FlexD->BDRL.B.DATA3 = 0xFF;
        sLin_FlexD->BDRL.B.DATA2 = 0xFF;
        sLin_FlexD->BDRL.B.DATA1 = 0xFF;
        sLin_FlexD->BDRL.B.DATA0 = 0;
        sLin_FlexD->BDRM.B.DATA7 = 0xFF;
        sLin_FlexD->BDRM.B.DATA6 = 0xFF;
        sLin_FlexD->BDRM.B.DATA5 = 0xFF;
        sLin_FlexD->BDRM.B.DATA4 = 0xFF;

        sLin_FlexD->LINCR2.B.HTRQ = 1;
        u8Lin_TransmitHeaderCmd[u8Lin_Channel] = LIN_TX_SLEEP_COMMAND_U8;
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_07();
    return u8Lin_ReturnValue;
}

FUNC(Std_ReturnType, LIN_CODE)Lin_LLD_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    VAR(uint32, AUTOMATIC)volatile u32Lin_Times = 0U;
    VAR(Std_ReturnType, AUTOMATIC)u8Lin_ReturnValue = E_NOT_OK;
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD \
           = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;

    SchM_Enter_LIN_EXCLUSIVE_AREA_08();
    /* Stop any ongoing transmission */
    sLin_FlexD->LINCR2.B.ABRQ = 1;

    while (u32Lin_Times <= LIN_TIMEOUT_LOOPS)
    {   
        u32Lin_Times++;
        if (0U == (sLin_FlexD->LINCR2.R & LINFLEX_LINCR2_REQUEST_MASK_U32))
        {
            u8Lin_ReturnValue = (uint8)E_OK;
            break;
        }
    }

    if ((uint8)E_OK == u8Lin_ReturnValue)
    {
        sLin_FlexD->LINSR.R = LINFLEX_LINSR_RMB_MASK_U32;
        sLin_FlexD->LINCR1.B.SLEEP = 1;

        if ((uint8)STD_ON == g_sLin_HW_Config[u8Lin_Channel].WakeupSupport)
        {
            sLin_FlexD->LINSR.R = LINFLEX_LINSR_WUF_MASK_U32;
            sLin_FlexD->LINIER.B.WUIE = 1;
        }
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_08();
    return u8Lin_ReturnValue;
}

FUNC(void, LIN_CODE)Lin_LLD_Wakeup(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD \
            = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;

    SchM_Enter_LIN_EXCLUSIVE_AREA_09();
    sLin_FlexD->LINCR1.B.SLEEP = 0;

    if ((uint8)STD_ON == g_sLin_HW_Config[u8Lin_Channel].WakeupSupport)
    {
        sLin_FlexD->LINSR.R = LINFLEX_LINSR_WUF_MASK_U32;
        sLin_FlexD->LINIER.B.WUIE = 0;
    }

    sLin_FlexD->BDRL.R = 0xF0;

    sLin_FlexD->LINCR2.B.WURQ = 1;
    SchM_Exit_LIN_EXCLUSIVE_AREA_09();
}

FUNC(void, LIN_CODE)Lin_LLD_WakeupInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD \
            = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;

    SchM_Enter_LIN_EXCLUSIVE_AREA_10();
    sLin_FlexD->LINCR1.B.SLEEP = 0;

    if (g_sLin_HW_Config[u8Lin_Channel].WakeupSupport == (uint8)STD_ON)
    {
        sLin_FlexD->LINSR.R = LINFLEX_LINSR_WUF_MASK_U32;
        sLin_FlexD->LINIER.B.WUIE = 0;
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_10();
}

FUNC(Std_ReturnType, LIN_CODE)Lin_LLD_CheckWakeup(CONST(uint8, AUTOMATIC) u8Lin_Channel)
{
    VAR(Std_ReturnType, AUTOMATIC)u8Lin_ReturnValue = E_FALSE;
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD \
            = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;

    SchM_Enter_LIN_EXCLUSIVE_AREA_11();
    if (sLin_FlexD->LINSR.B.WUF == (uint8)1)
    {
        sLin_FlexD->LINSR.R = LINFLEX_LINSR_WUF_MASK_U32;
        sLin_FlexD->LINCR1.B.SLEEP = 0;
        u8Lin_ReturnValue = E_TRUE;
    }
    else
    {
        u8Lin_ReturnValue = E_FALSE;
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_11();
    return u8Lin_ReturnValue;
}

FUNC(Lin_StatusType, LIN_CODE)Lin_LLD_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) u8pLin_SduPtr)
{
    VAR(Lin_StatusType, AUTOMATIC)eLin_ReturnValue = LIN_NOT_OK;
    VAR(LIN_LINSR_LINSTATE, AUTOMATIC) u8Lin_ReturnValue = LIN_STATE_SLEEP;
    VAR(uint32, AUTOMATIC) u8Lin_sLinValue = 0;
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD \
            = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;

    SchM_Enter_LIN_EXCLUSIVE_AREA_12();
    u8Lin_ReturnValue = (LIN_LINSR_LINSTATE)sLin_FlexD->LINSR.B.LINS;
    VAR(uint8, AUTOMATIC) u8Lin_ChannelValueA = u8Lin_TransmitHeaderCmd[u8Lin_Channel];
    VAR(uint8, AUTOMATIC) u8Lin_FrameErrorValueA = u8Lin_ChFrameErrorStatus[u8Lin_Channel];
    u8Lin_sLinValue = sLin_FlexD->BDRM.R;

    switch (u8Lin_ReturnValue)
    {
    case LIN_STATE_SLEEP:
    {
        eLin_ReturnValue = LIN_CH_SLEEP;
        break;
    }
    case LIN_STATE_INIT:
    {
        eLin_ReturnValue = LIN_NOT_OK;
        break;
    }
    case LIN_STATE_BREAK:
    case LIN_STATE_DEL:
    case LIN_STATE_FIELD:
    case LIN_STATE_IDENTIFIER:
    {
        eLin_ReturnValue = LIN_TX_BUSY;
        break;
    }
    case LIN_STATE_HEADER_RT:
    {
        if(u8Lin_ChFrameErrorStatus[u8Lin_Channel] == LIN_TIMEOUT_ERROR)
        {
            if(u8Lin_TransmitHeaderCmd[u8Lin_Channel] == LIN_TX_SLAVE_RES_COMMAND_U8)
            {
                if(sLin_FlexD->LINSR.B.DRBNE == (uint8)0)
                {
                    eLin_ReturnValue = LIN_RX_NO_RESPONSE;
                }
                else
                {
                    eLin_ReturnValue = LIN_RX_ERROR;
                }
            }
            else if ((LIN_TX_MASTER_RES_COMMAND_U8 == u8Lin_TransmitHeaderCmd[u8Lin_Channel]) \
                    || (LIN_TX_SLEEP_COMMAND_U8 == u8Lin_ChannelValueA))
            {
                eLin_ReturnValue = LIN_RX_ERROR;
            }
            else
            {
                eLin_ReturnValue = LIN_NOT_OK;
            }
        }
        else if(u8Lin_ChFrameErrorStatus[u8Lin_Channel] == LIN_BIT_ERROR)
        {
            if ((LIN_TX_MASTER_RES_COMMAND_U8 == u8Lin_TransmitHeaderCmd[u8Lin_Channel]) \
                    || (LIN_TX_SLEEP_COMMAND_U8 == u8Lin_ChannelValueA))
            {
                uint8 u8Temp = g_u8Lin_LLD_StateOfBEF[u8Lin_Channel];
                if (((uint8)LIN_STATE_BREAK != u8Temp) \
                        && ((uint8)LIN_STATE_DEL != u8Temp) \
                        && ((uint8)LIN_STATE_FIELD != u8Temp) \
                        && ((uint8)LIN_STATE_IDENTIFIER != u8Temp) \
                        && ((uint8)LIN_STATE_HEADER_RT != u8Temp))
                {
                    eLin_ReturnValue = LIN_TX_ERROR;
                }
                else
                {
                    eLin_ReturnValue = LIN_TX_HEADER_ERROR;
                }
            }
            else if(u8Lin_TransmitHeaderCmd[u8Lin_Channel] == LIN_TX_SLAVE_RES_COMMAND_U8)
            {
                eLin_ReturnValue = LIN_TX_HEADER_ERROR;
            }
            else
            {
                eLin_ReturnValue = LIN_TX_ERROR;
            }
        }
        else if(u8Lin_ChFrameErrorStatus[u8Lin_Channel] == LIN_NO_ERROR)
        {
            if(u8Lin_TransmitHeaderCmd[u8Lin_Channel] == LIN_TX_SLAVETOSLAVE_COMMAND_U8)
            {
                eLin_ReturnValue = LIN_TX_OK;
            }
            else
            {
                eLin_ReturnValue = LIN_TX_BUSY;
            }
        }
        else
        {
            /* nothing */
        }
        break;
    }
    case LIN_STATE_DATA_RT:
    case LIN_STATE_CCS:
    {
        if ((LIN_TX_MASTER_RES_COMMAND_U8 == u8Lin_TransmitHeaderCmd[u8Lin_Channel]) \
                || (LIN_TX_SLEEP_COMMAND_U8 == u8Lin_ChannelValueA))
        {
            eLin_ReturnValue = LIN_TX_BUSY;
        }
        else if (LIN_TX_SLAVE_RES_COMMAND_U8 == u8Lin_TransmitHeaderCmd[u8Lin_Channel])
        {
            eLin_ReturnValue = LIN_RX_BUSY;
        }
        else
        {
            eLin_ReturnValue = LIN_NOT_OK;
        }
        break;
    }
    case LIN_STATE_IDLE:
    {
        if ((u8Lin_ChFrameErrorStatus[u8Lin_Channel] == LIN_SYNCH_FIELD_ERROR) \
                || (u8Lin_FrameErrorValueA == LIN_BREAK_DELIMITER_ERROR) \
                || (u8Lin_FrameErrorValueA == LIN_IDENTIFIER_PARITY_ERROR))
        {
            eLin_ReturnValue = LIN_TX_HEADER_ERROR;
        }
        else if (u8Lin_ChFrameErrorStatus[u8Lin_Channel] == LIN_TIMEOUT_ERROR)
        {
            if ((LIN_TX_MASTER_RES_COMMAND_U8 == u8Lin_TransmitHeaderCmd[u8Lin_Channel]) \
                    || (LIN_TX_SLEEP_COMMAND_U8 == u8Lin_ChannelValueA))
            {
                if (sLin_FlexD->LINOCR.B.OC1 <= sLin_FlexD->LINOCR.B.OC2)
                {
                    eLin_ReturnValue = LIN_TX_HEADER_ERROR;
                }
                else
                {
                    eLin_ReturnValue = LIN_TX_ERROR;
                }
            }
            else
            {
                if ((sLin_FlexD->BDRL.R == (uint8)0) && (u8Lin_sLinValue == (uint32)0))
                {
                    eLin_ReturnValue = LIN_RX_NO_RESPONSE;
                }
                else
                {
                    eLin_ReturnValue = LIN_RX_ERROR;
                }
            }
        }
        else if (u8Lin_ChFrameErrorStatus[u8Lin_Channel] == LIN_BIT_ERROR)
        {
            if ((LIN_TX_MASTER_RES_COMMAND_U8 == u8Lin_TransmitHeaderCmd[u8Lin_Channel]) \
                    || (LIN_TX_SLEEP_COMMAND_U8 == u8Lin_ChannelValueA) \
                    || (LIN_TX_SLAVETOSLAVE_COMMAND_U8 == u8Lin_ChannelValueA))
            {
                switch (g_u8Lin_LLD_StateOfBEF[u8Lin_Channel])
                {
                case (uint8)LIN_STATE_SLEEP:
                case LIN_STATE_INIT:
                case LIN_STATE_IDLE:
                case LIN_STATE_CCS:
                {
                    eLin_ReturnValue = LIN_TX_ERROR;
                    break;
                }
                default:
                    eLin_ReturnValue = LIN_TX_HEADER_ERROR;
                    break;
                }
            }
            else if (LIN_TX_SLAVE_RES_COMMAND_U8 == u8Lin_TransmitHeaderCmd[u8Lin_Channel])
            {
                eLin_ReturnValue = LIN_TX_HEADER_ERROR;
            }
            else
            {
                eLin_ReturnValue = LIN_TX_ERROR;
            }
        }
        else if ((u8Lin_ChFrameErrorStatus[u8Lin_Channel] == LIN_NOISE_ERROR) \
                || (u8Lin_FrameErrorValueA == LIN_CHECKSUM_ERROR) \
                || (u8Lin_FrameErrorValueA == LIN_FRAMING_ERROR) \
                || (u8Lin_FrameErrorValueA == LIN_BUFFER_OVER_RUN_ERROR))
        {
            sLin_FlexD->LINSR.R = LINFLEX_LINSR_RMB_MASK_U32;
            eLin_ReturnValue = LIN_RX_ERROR;
        }
        else if (u8Lin_ChFrameErrorStatus[u8Lin_Channel] == LIN_NO_ERROR)
        {
            if (u8Lin_ChFrameStatus[u8Lin_Channel] == LIN_TX_COMPLETE_STATE)
            {
                eLin_ReturnValue = LIN_TX_OK;
            }
            else if (u8Lin_ChFrameStatus[u8Lin_Channel] == LIN_RX_COMPLETE_STATE)
            {
                if(g_sLin_HW_Config[u8Lin_Channel].DmaSupport == (uint8)STD_ON)
                {
                    Lin_ConfigureDmaTransfer(g_sLin_HW_Config[u8Lin_Channel].ldp->config->DmaRxChannel,     \
                            (uint32)(&(sLin_FlexD->BDRL)),                                                     \
                            (uint32)u8pLin_SduPtr,                                                            \
                            g_sLin_HW_Config[u8Lin_Channel].ldp->rx_len                                        \
                    );
                    Lin_Buf_Convert(u8pLin_SduPtr, u8pLin_SduPtr, (uint8)g_sLin_HW_Config[u8Lin_Channel].ldp->rx_len);
                }
                else
                {
                    lld_rxi(g_sLin_HW_Config[u8Lin_Channel].ldp, u8pLin_SduPtr);
                }
                eLin_ReturnValue = LIN_RX_OK;
            }
            else if (u8Lin_ChFrameStatus[u8Lin_Channel] == LIN_CH_RECEIVE_NOTHING_STATE)
            {
                eLin_ReturnValue = LIN_RX_NO_RESPONSE;
            }
            else if (u8Lin_ChFrameStatus[u8Lin_Channel] == LIN_CH_READY_STATE)
            {
                eLin_ReturnValue = LIN_OPERATIONAL;
            }
            else if (u8Lin_ChFrameStatus[u8Lin_Channel] == LIN_CH_NOT_READY_STATE)
            {
                eLin_ReturnValue = LIN_NOT_OK;
            }
            else
            {
                eLin_ReturnValue = LIN_NOT_OK;
            }
        }
        else
        {
            eLin_ReturnValue = LIN_NOT_OK;
        }
        break;
    }
    default:
    {
        eLin_ReturnValue = LIN_NOT_OK;
        break;
    }
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_12();
    return eLin_ReturnValue;
}

static FUNC(void, LIN_CODE) LINFlex_LLD_TXI_IRQHandler(VAR(uint8, AUTOMATIC) u8Lin_Channel)
{
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD \
            = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;

    VAR(uint8, AUTOMATIC) u8channel = Lin_LLD_GetChannel(u8Lin_Channel);

    if (sLin_FlexD->LINSR.B.HRF != 0U)
    {
        /* Slaver transmit mode with filter first tx interrupt */
        /* Call the related callback.
         * u8pLin_Tx_Buf will be filled by this callback
         */

        if(g_sLin_HW_Config[u8Lin_Channel].DmaSupport == (uint8)STD_ON)
        {
        	cc_memcpy((uint8_t*)&u32_txBuffdma[u8Lin_Channel][0], \
        			(uint8_t*)g_sLin_HW_Config[u8Lin_Channel].ldp->tx_buf, \
					(uint32)g_sLin_HW_Config[u8Lin_Channel].ldp->tx_len);

            Lin_ConfigureDmaTransfer(                                       \
                g_sLin_HW_Config[u8Lin_Channel].ldp->config->DmaTxChannel,  \
				(uint32)&u32_txBuffdma[u8Lin_Channel][0],                   \
                (uint32)(&(sLin_FlexD->BDRL)),                              \
                (uint8)g_sLin_HW_Config[u8Lin_Channel].ldp->tx_len          \
            );
        }
        else
        {
            lld_txi(g_sLin_HW_Config[u8Lin_Channel].ldp, g_sLin_HW_Config[u8Lin_Channel].ldp->tx_buf, \
                (uint8)g_sLin_HW_Config[u8Lin_Channel].ldp->tx_len);
        }

        /* Trigger Data transmissi on*/
        sLin_FlexD->LINCR2.B.DTRQ = 1;

        sLin_FlexD->LINSR.R = LINFLEX_LINSR_HRF_MASK_U32;
    }



    else if (sLin_FlexD->LINSR.B.DTF == (uint8)1)
    {
        /* Acknowledge transmit interrupt */
        sLin_FlexD->LINSR.R = LINFLEX_LINSR_DTF_MASK_U32;


        if (LIN_TX_SLEEP_COMMAND_U8 == u8Lin_TransmitHeaderCmd[u8Lin_Channel])
        {
            if ((uint8) STD_ON == g_sLin_HW_Config[u8Lin_Channel].WakeupSupport)
            {
                sLin_FlexD->LINSR.R = LINFLEX_LINSR_WUF_MASK_U32;
                sLin_FlexD->LINIER.B.WUIE = 1;
            }
            sLin_FlexD->LINCR1.B.SLEEP = 1;
            u8Lin_ChStatus[u8Lin_Channel] = LIN_CH_SLEEP_STATE;
            u8Lin_TransmitHeaderCmd[u8Lin_Channel] = LIN_TX_NO_COMMAND_U8;
        }
        else
        {
            if(g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
            {
                LinIf_TxConfirmation(u8channel);
            }
            else
            {
            u8Lin_ChFrameStatus[u8Lin_Channel] = LIN_TX_COMPLETE_STATE;
            }
        }
    }
    else
    {
        /* nothing */
    }
}

/*******************************************************************************
 * @brief      LINFlex_RXI_IRQHandler
 * @param[in]  uint32_t ildp
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static FUNC(void, LIN_CODE) LINFlex_LLD_RXI_IRQHandler(VAR(uint8, AUTOMATIC) u8Lin_Channel)
{
    static VAR(Lin_PduType, LIN_VAR) g_sLin_LLD_SlavePdu[LIN_HW_MAX_AVAILABLE_MODULES];
    VAR(Std_ReturnType, AUTOMATIC) u8Lin_ReturnValue = (uint8)E_NOT_OK;
    P2VAR(Lin_PduType, AUTOMATIC, LIN_APPL_DATA) spLin_PduInfoPtr = NULL_PTR;
    volatile P2VAR(struct LINFlexD_tag, AUTOMATIC, LIN_APPL_DATA) sLin_FlexD \
            = g_sLin_HW_Config[u8Lin_Channel].ldp->linflexD;

    VAR(uint16, AUTOMATIC) u16Lin_Len = 0U;
    VAR(uint8, AUTOMATIC) u8Lin_ChannelValue = 0U;
    u8Lin_ChannelValue = u8Lin_ChStatus[u8Lin_Channel];
    u16Lin_Len = (uint16)(sLin_FlexD->BIDR.B.DFL + 1U);

    VAR(lin_node_t, AUTOMATIC) u16Lin_Mode = g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode;
    VAR(uint32, AUTOMATIC) u16Lin_Mode_Flex =sLin_FlexD->LINSR.B.DRF;

    VAR(uint8, AUTOMATIC) u8channel = Lin_LLD_GetChannel(u8Lin_Channel);

    if ((sLin_FlexD->LINSR.B.HRF != 0U) \
            && (u16Lin_Mode == LIN_SLAVE))/* slave: header receive and data transmit */
    {
        spLin_PduInfoPtr = &g_sLin_LLD_SlavePdu[u8Lin_Channel];

        spLin_PduInfoPtr->Pid = (Lin_FramePidType)sLin_FlexD->BIDR.B.ID;

        /* Specification of Lin Driver : [SWS_Lin_00235] */
        u8Lin_ReturnValue = (uint8)LinIf_HeaderIndication(spLin_PduInfoPtr);
        if((uint8)E_OK == u8Lin_ReturnValue)
        {
            lin_lld_slave_transmit(u8Lin_Channel, spLin_PduInfoPtr);
        }
        else
        {
            sLin_FlexD->LINCR2.B.DDRQ = 1;
            sLin_FlexD->LINSR.R = LINFLEX_LINSR_DRBNE_MASK_U32;
        }
        sLin_FlexD->LINSR.R = LINFLEX_LINSR_HRF_MASK_U32;
    }
    else if (sLin_FlexD->LINSR.B.WUF != 0U)
    {
        sLin_FlexD->LINIER.B.WUIE = 0;
        if((LIN_CH_SLEEP_STATE == u8Lin_ChStatus[u8Lin_Channel]) \
                || (LIN_CH_SLEEP_PENDING == u8Lin_ChannelValue))
        {
            if ((uint8)STD_ON == g_sLin_HW_Config[u8Lin_Channel].WakeupSupport)
            {
                /* Specification of Lin Driver : [SWS_Lin_00176] */
                EcuM_CheckWakeup(g_sLin_HW_Config[u8Lin_Channel].WakeupSource);
            }
            u8Lin_ChStatus[u8Lin_Channel] = LIN_CH_OPERATIONAL;
            u8Lin_ChFrameStatus[u8Lin_Channel] = LIN_CH_READY_STATE;
        }
        sLin_FlexD->LINSR.R = LINFLEX_LINSR_WUF_MASK_U32;
    }
    else if ((g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_MASTER) \
            && (u16Lin_Mode_Flex == (uint32)1))/* master: data reception completed */
    {
        /* Master receive */
        /* Disable receive interrupt */
        sLin_FlexD->LINIER.B.DRIE = 0;

        /* Check the size of the data buffer */

        /* Set returned data length */
        u8Lin_ChFrameStatus[u8Lin_Channel] = LIN_RX_COMPLETE_STATE;

        sLin_FlexD->LINSR.R = LINFLEX_LINSR_DRF_MASK_U32;
    }
    else if ((g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE) \
            && (u16Lin_Mode_Flex == (uint32)1))/* slave: data reception completed */
    {
        spLin_PduInfoPtr = &g_sLin_LLD_SlavePdu[u8Lin_Channel];

        if(g_sLin_HW_Config[u8Lin_Channel].DmaSupport == (uint8)STD_ON)
        {
            Lin_ConfigureDmaTransfer(g_sLin_HW_Config[u8Lin_Channel].ldp->config->DmaRxChannel,     \
                    (uint32)(&(sLin_FlexD->BDRL)),                                                     \
					(uint32)&u32_txBuffdma[u8Lin_Channel][0],			\
                    (uint32)u16Lin_Len                                  \
            );
            Lin_Buf_Convert(spLin_PduInfoPtr->SduPtr,                 \
            		(uint8*)&u32_txBuffdma[u8Lin_Channel][0],		  \
                    (uint8)u16Lin_Len        \
            );
        }
        else
        {
            lld_rxi(g_sLin_HW_Config[u8Lin_Channel].ldp, spLin_PduInfoPtr->SduPtr);
        }


        sLin_FlexD->LINSR.R = LINFLEX_LINSR_RMB_MASK_U32;

        LinIf_RxIndication(u8channel, spLin_PduInfoPtr->SduPtr);

        sLin_FlexD->LINSR.R = LINFLEX_LINSR_DRF_MASK_U32;

        u8Lin_ChFrameStatus[u8Lin_Channel] = LIN_RX_COMPLETE_STATE;
    }
    else
    {
        /** No code **/
    }
}

/*******************************************************************************
 * @brief      LINFlex_ERR_IRQHandler
 * @param[in]  uint32_t ildp
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/

static FUNC(void, LIN_CODE) LINFlex_LLD_ERR_IRQHandler(VAR(uint8, AUTOMATIC) u8Lin_Channel)
{
    SchM_Enter_LIN_EXCLUSIVE_AREA_13();
    P2VAR(LinLldDrivers, AUTOMATIC, LIN_APPL_DATA) spLin_Ldp = g_sLin_HW_Config[u8Lin_Channel].ldp;
    VAR(lin_node_t, AUTOMATIC) u8Lin_ReturnMode = LIN_SLAVE;

    VAR(uint8, AUTOMATIC) u8channel = Lin_LLD_GetChannel(u8Lin_Channel);

    if (1u == spLin_Ldp->linflexD->LINESR.B.SZF)
    {
        spLin_Ldp->linflexD->LINESR.R = LINFLEX_LINESR_SZF_MASK_U32;
    }
    else
    {
    }

    if (1u == spLin_Ldp->linflexD->LINESR.B.OCF)
    {
        spLin_Ldp->linflexD->LINESR.R = LINFLEX_LINESR_OCF_MASK_U32;
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
        u8Lin_ChFrameErrorStatus[u8Lin_Channel] = LIN_TIMEOUT_ERROR;
        if(g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
        {
            if(spLin_Ldp->linflexD->LINSR.B.RXbusy == (uint8)1)
            {
                if(spLin_Ldp->linflexD->LINSR.B.DRBNE == (uint8)0)
                {
                    LinIf_LinErrorIndication(u8channel, LIN_ERR_NO_RESP);
                }
                else
                {
                    LinIf_LinErrorIndication(u8channel, LIN_ERR_INC_RESP);
                }
            }
            else
            {
                LinIf_LinErrorIndication(u8channel, LIN_ERR_HEADER);
            }

        }
        else
        {
            spLin_Ldp->linflexD->LINCR2.B.DDRQ = 1;
            spLin_Ldp->linflexD->LINSR.R = LINFLEX_LINSR_DRBNE_MASK_U32;
        }
#endif /* LIN_DISABLE_FRAME_TIMEOUT */
    }
    else
    {
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_13();

    SchM_Enter_LIN_EXCLUSIVE_AREA_14();
    if (1u == spLin_Ldp->linflexD->LINESR.B.BEF)
    {
        spLin_Ldp->linflexD->LINESR.R = LINFLEX_LINESR_BEF_MASK_U32;
        spLin_Ldp->linflexD->LINCR2.B.ABRQ = 1;
        u8Lin_ChFrameErrorStatus[u8Lin_Channel] = LIN_BIT_ERROR;
        g_u8Lin_LLD_StateOfBEF[u8Lin_Channel] = (uint8)spLin_Ldp->linflexD->LINSR.B.LINS;
        
        if(g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
        {
            LinIf_LinErrorIndication(u8channel, LIN_ERR_RESP_DATABIT);
        }
    }
    else
    {
    }

    if (1u == spLin_Ldp->linflexD->LINESR.B.CEF)
    {
        spLin_Ldp->linflexD->LINESR.R = LINFLEX_LINESR_CEF_MASK_U32;
        u8Lin_ChFrameErrorStatus[u8Lin_Channel] = LIN_CHECKSUM_ERROR;
        if(g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
        {
            LinIf_LinErrorIndication(u8channel, LIN_ERR_RESP_CHKSUM);
        }
    }
    else
    {
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_14();
    SchM_Enter_LIN_EXCLUSIVE_AREA_15();
    if (1u == spLin_Ldp->linflexD->LINESR.B.SFEF)
    {
        spLin_Ldp->linflexD->LINESR.R = LINFLEX_LINESR_SFEF_MASK_U32;
        u8Lin_ChFrameErrorStatus[u8Lin_Channel] = LIN_SYNCH_FIELD_ERROR;
        if(g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
        {
            LinIf_LinErrorIndication(u8channel, LIN_ERR_HEADER);
        }
    }
    else
    {
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_15();
    SchM_Enter_LIN_EXCLUSIVE_AREA_16();
    if (1u == spLin_Ldp->linflexD->LINESR.B.SDEF)
    {
        spLin_Ldp->linflexD->LINESR.R = LINFLEX_LINESR_SDEF_MASK_U32;
        u8Lin_ChFrameErrorStatus[u8Lin_Channel] = LIN_BREAK_DELIMITER_ERROR;
        if(g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
        {
            LinIf_LinErrorIndication(u8channel, LIN_ERR_HEADER);
        }
    }
    else
    {
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_16();
    SchM_Enter_LIN_EXCLUSIVE_AREA_17();
    if (1u == spLin_Ldp->linflexD->LINESR.B.IDPEF)
    {
        spLin_Ldp->linflexD->LINESR.R = LINFLEX_LINESR_IDPEF_MASK_U32;
        u8Lin_ChFrameErrorStatus[u8Lin_Channel] = LIN_IDENTIFIER_PARITY_ERROR;
        if(g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
        {
            LinIf_LinErrorIndication(u8channel, LIN_ERR_HEADER);
        }
    }
    else
    {
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_17();
    SchM_Enter_LIN_EXCLUSIVE_AREA_18();
    if (1u == spLin_Ldp->linflexD->LINESR.B.FEF)
    {
        spLin_Ldp->linflexD->LINESR.R = LINFLEX_LINESR_FEF_MASK_U32;
        spLin_Ldp->linflexD->LINCR2.B.DDRQ = 1;
        spLin_Ldp->linflexD->LINSR.R = LINFLEX_LINSR_DRBNE_MASK_U32;
        u8Lin_ChFrameErrorStatus[u8Lin_Channel] = LIN_FRAMING_ERROR;
        if(g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
        {
            LinIf_LinErrorIndication(u8channel, LIN_ERR_RESP_STOPBIT);
        }
    }
    else
    {
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_18();
    SchM_Enter_LIN_EXCLUSIVE_AREA_19();
    if (1u == spLin_Ldp->linflexD->LINESR.B.BOF)
    {
        spLin_Ldp->linflexD->LINESR.R = LINFLEX_LINESR_BOF_MASK_U32;
        spLin_Ldp->linflexD->LINCR2.B.DDRQ = 1;
        spLin_Ldp->linflexD->LINSR.R = LINFLEX_LINSR_DRBNE_MASK_U32;
        u8Lin_ChFrameErrorStatus[u8Lin_Channel] = LIN_BUFFER_OVER_RUN_ERROR;
        if(g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode == LIN_SLAVE)
        {
            LinIf_LinErrorIndication(u8channel, LIN_ERR_INC_RESP);
        }
    }
    else
    {
    }

    if (1u == spLin_Ldp->linflexD->LINESR.B.NF)
    {
        spLin_Ldp->linflexD->LINESR.R = LINFLEX_LINESR_NF_MASK_U32;
        u8Lin_ChFrameErrorStatus[u8Lin_Channel] = LIN_NOISE_ERROR;
    }
    else
    {
    }
    SchM_Exit_LIN_EXCLUSIVE_AREA_19();
    SchM_Enter_LIN_EXCLUSIVE_AREA_20();
    u8Lin_ReturnMode = g_sLin_HW_Config[u8Lin_Channel].ldp->config->mode;
    if ((LIN_TX_SLEEP_COMMAND_U8 == u8Lin_TransmitHeaderCmd[u8Lin_Channel]) \
            && (u8Lin_ReturnMode == LIN_MASTER))
    {
        if ((uint8) STD_ON == g_sLin_HW_Config[u8Lin_Channel].WakeupSupport)
        {
            spLin_Ldp->linflexD->LINSR.R = LINFLEX_LINSR_WUF_MASK_U32;
            spLin_Ldp->linflexD->LINIER.B.WUIE = 1;
        }
        spLin_Ldp->linflexD->LINCR1.B.SLEEP = 1;
        u8Lin_ChStatus[u8Lin_Channel] = LIN_CH_SLEEP_STATE;
        u8Lin_TransmitHeaderCmd[u8Lin_Channel] = LIN_TX_NO_COMMAND_U8;
        u8Lin_ChFrameStatus[u8Lin_Channel] = LIN_CH_NOT_READY_STATE;
    }
    spLin_Ldp->linflexD->LINESR.R = 0x0000FF81UL;

    SchM_Exit_LIN_EXCLUSIVE_AREA_20();
}


#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif
