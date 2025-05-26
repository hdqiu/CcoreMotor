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
*   @file    Can_Cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Can MCAL driver.
*
*   @addtogroup Can
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Can.h"

#define CAN_CFG_C_VENDOR_ID                     176
#define CAN_CFG_C_AR_REL_MAJOR_VER              4
#define CAN_CFG_C_AR_REL_MINOR_VER              4
#define CAN_CFG_C_AR_REL_REV_VER                0
#define CAN_CFG_C_SW_MAJOR_VER                  1
#define CAN_CFG_C_SW_MINOR_VER                  0
#define CAN_CFG_C_SW_PATCH_VER                  1

#if (MCAL_VENDOR_ID != CAN_CFG_C_VENDOR_ID)
    #error " NON-MATCHED DATA : CAN_CFG_C_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != CAN_CFG_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_AR_REL_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != CAN_CFG_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_AR_REL_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != CAN_CFG_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_AR_REL_REV_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != CAN_CFG_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != CAN_CFG_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != CAN_CFG_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : CAN_CFG_C_SW_PATCH_VER "
#endif

static CONST(mcan_hwObject, CAN_CONST) Mcan_HardWareObjConfigs[CAN_MB_COUNT] = 
{
    {
        .CanObjectId = 0U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STANDARD_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 1U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000201U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 1U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STANDARD_ID,
        .mbIdex = 1U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 1U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000202U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 2U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STANDARD_ID,
        .mbIdex = 0U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 1U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000301U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 3U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STANDARD_ID,
        .mbIdex = 1U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 1U,
        .CanObjectType = RECEIVE,
        .CanFdPaddingValue = 0x00U,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000302U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 4U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STANDARD_ID,
        .mbIdex = 2U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 1U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x0fU,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000401U,
        .filterMask = 0x000007ffU,
    },
    {
        .CanObjectId = 5U,
        .CanControllerId = (uint32)0U,
        .CanIdType = STANDARD_ID,
        .mbIdex = 3U,
        .mbPayloadLength = (uint32)64U,
        .isPolling = 1U,
        .CanObjectType = TRANSMIT,
        .CanFdPaddingValue = 0x0fU,
        .PeriodIndex = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterCode = 0x00000402U,
        .filterMask = 0x000007ffU,
    },
};

static CONST(McanControlInfor, CAN_CONST) MCAN_CTRL[12U] =
{
    {
        .CanId = MCAN_MOD_ID_1,
        .IsUsed = TRUE,
        .BaseWord = 0UL,
        .mram_size_words = 1262UL,
    },
    {
        .CanId = MCAN_MOD_ID_2,
        .IsUsed = FALSE,
        .BaseWord = 1262UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_3,
        .IsUsed = FALSE,
        .BaseWord = 1262UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_4,
        .IsUsed = FALSE,
        .BaseWord = 1262UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_5,
        .IsUsed = FALSE,
        .BaseWord = 0UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_6,
        .IsUsed = FALSE,
        .BaseWord = 0UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_7,
        .IsUsed = FALSE,
        .BaseWord = 0UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_8,
        .IsUsed = FALSE,
        .BaseWord = 0UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_9,
        .IsUsed = FALSE,
        .BaseWord = 0UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_10,
        .IsUsed = FALSE,
        .BaseWord = 0UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_11,
        .IsUsed = FALSE,
        .BaseWord = 0UL,
        .mram_size_words = 0UL,
    },
    {
        .CanId = MCAN_MOD_ID_12,
        .IsUsed = FALSE,
        .BaseWord = 0UL,
        .mram_size_words = 0UL,
    },
};

static CONST(MCANPartitionConfig, CAN_CONST) MCAN_DATA =
{
    .McanCtrl = (McanControlInfor *)MCAN_CTRL,
};

/* 
    The final value set to the register is as follows:
    Register NBTP.NBRP = brp - 1
    Register NBTP.NTSEG1 = (prop_seg + phase_seg1) - 1
    Register NBTP.NTSEG2 = phase_seg2 - 1
                             clockFrequency
    BitRate = ----------------------------------------------------
                brp * (1 + (prop_seg + phase_seg1) + phase_seg2)
*/
static CONST(bt_config_canfd_struct, CAN_CONST) TIMCFG_0[2U] =
{
    {
        .baudRateConfigId = 0U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 47U,
            .phase_seg1 = 16U,
            .phase_seg2 = 16U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 0U,
            .phase_seg1 = 13U,
            .phase_seg2 = 6U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 14U,
        },
    },
    {
        .baudRateConfigId = 1U,
        .brs_ena = TRUE,
        .fd_ena = TRUE,
        .is_noiso = FALSE,
        .nominal = 
        {
            .brp = 1U,
            .prop_seg = 20U,
            .phase_seg1 = 10U,
            .phase_seg2 = 9U,
            .sjw = 16U,
            .tdc = 0U
        },
        .data =
        {
            .brp = 1U,
            .prop_seg = 0U,
            .phase_seg1 = 6U,
            .phase_seg2 = 3U,
            .sjw = 4U,
            .tdc = 1U,
            .tdc_offset = 14U,
        },
    },
};

static CONST(mcan_id_table_t, CAN_CONST) filter_ids_config_0[2U] =
{
    {
        .id1 = 0x00000301U,
        .id2 = 0U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_BUFF,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
    {
        .id1 = 0x00000302U,
        .id2 = 1U,
        .filterType = FILTER_TYPE_CLASIC,
        .filterConfig = FILTER_CONF_RX_BUFF,
        .ssync = 0UL,
        .esync = 0UL,
        .isExtendedFrame = FALSE,
    },
};

static CONST(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_0 =
{
    .filterconfigs = filter_ids_config_0,
    .std_filters = 2U,
    .ext_filters = 0U,
};

static CONST(mcan_fifo_config_t, CAN_CONST) RX_FIFO_CFG_0 =
{
    .rx_fifo_needed = MCAN_RXFIFO_0_1_ENABLE,
    .modeFIFO = FIFO_MODE_OVERWRITE,
    .fifo_size_elems = 32U,
    .fifo_watermark = 16U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};

static CONST(mcan_global_filter_config_t, CAN_CONST) GLOBAL_FILTER_CFG_0 =
{
    .anfe = REJECT_NON_MATCHING_FRAMES,
    .anfs = REJECT_NON_MATCHING_FRAMES,
    .rrfe = TRUE,
    .rrfs = TRUE,
};

static CONST(mcan_tx_buffer_config_t, CAN_CONST) TX_BUFFER_CFG_0 =
{
    .FIFO_true_QUEUE_false = TRUE,
    .fifo_queue_size = 0U,
    .ded_buffers_number = 4U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};

static CONST(mcan_dedicated_buffers_config_t, CAN_CONST) RX_BUFFER_CFG_0 =
{
    .rx_buffer_size_elems = 2U,
    .payload = MCAN_PAYLOAD_SIZE_64,
};

static CONST(mcan_inter_config_t, CAN_CONST) INTER_CFG_0 =
{
    .ir_line0_select = 0UL,
    .ir_line1_select = 0UL,
    .tx_buffer_tran_ir_enable = 0x0UL,
    .tx_buffer_cancel_fin_ir_enable = 0x0UL,
};

static CONST(CANConfig, CAN_CONST) Mcan_ControllerConfigs[CAN_CONTROLLER_COUNT] = 
{
    {
        .controllerId = MCAN_MOD_ID_1,
        .defaultBaudRateId = (uint16)0U,
        .baudRateConfigCount = 2U,
        .data = &MCAN_DATA,
        .timingconfig = TIMCFG_0,
        .globalfilterconfig = &GLOBAL_FILTER_CFG_0,
        #ifdef RX_FILTER_CFG_0
        .filterconfig = RX_FILTER_CFG_0,
        #else
        .filterconfig = &RX_FILTER_CFG_0,
        #endif
        .rxfifoconfig =  &RX_FIFO_CFG_0,
        .txeventconfig = NULL_PTR,
        .txbufferconfig = &TX_BUFFER_CFG_0,
        .rxbufferconfig = &RX_BUFFER_CFG_0,
        .interconfig = &INTER_CFG_0,
        .stampconfig = NULL_PTR,
        .mcanMode = MCAN_NORMAL_MODE,
        .MRAFNotification = NULL_PTR,
        .ErrorNotification = NULL_PTR,
    },
};

#if (CAN_MULTICORE_ENABLED == STD_ON)
static CONST(mcan_core_map_t, CAN_CONST) Mcan_CoreMap[CAN_CONTROLLER_COUNT] =
{
    {
        .controllerId = MCAN_MOD_ID_1,
        .CoreId = 0U
    },
};
#endif

CONST(Can_ConfigType, CAN_CONST) Can_Config =
{
    .controllerConfig = Mcan_ControllerConfigs,
    .hwObjectConfig = Mcan_HardWareObjConfigs,
    .HwObjCount = CAN_MB_COUNT,
#if (CAN_MULTICORE_ENABLED == STD_ON)
    .coreMap = Mcan_CoreMap
#endif
};

#ifdef __cplusplus
}
#endif
