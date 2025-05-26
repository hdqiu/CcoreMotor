#ifdef __cplusplus
extern "C"{
#endif

#include "Spi.h"
#if(SPI_DMA_USED == STD_ON)
#include "eDma.h"
#endif

/*==================================================================================================
SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_CFG_C_VENDOR_ID                    176
#define SPI_CFG_C_AR_MAJOR_VER                 4
#define SPI_CFG_C_AR_MINOR_VER                 4
#define SPI_CFG_C_AR_PATCH_VER                 0
#define SPI_CFG_C_SW_MAJOR_VER                 1
#define SPI_CFG_C_SW_MINOR_VER                 0
#define SPI_CFG_C_SW_PATCH_VER                 1

/*==================================================================================================
FILE VERSION CHECKS
==================================================================================================*/
#if (SPI_CFG_C_VENDOR_ID != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : SPI_CFG_C_VENDOR_ID"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (SPI_CFG_C_AR_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_AR_MAJOR_VER"
#endif
#if (SPI_CFG_C_AR_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_AR_MINOR_VER"
#endif
#if (SPI_CFG_C_AR_PATCH_VER != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_AR_PATCH_VER"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (SPI_CFG_C_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_SW_MAJOR_VER"
#endif
#if (SPI_CFG_C_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_SW_MINOR_VER"
#endif
#if (SPI_CFG_C_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_C_SW_PATCH_VER"
#endif


#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_0[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_0[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_2[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_2[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_3[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_3[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_4[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_4[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_5[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_5[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_8[10U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_8[10U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_9[10U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_9[10U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_10[10U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_10[10U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_11[10U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_11[10U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_32[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_32[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_33[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_33[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_SpiChannel_34[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_SpiChannel_34[4U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
MEM_ALIGN(4) static VAR(Spi_DataBufferType, SPI_VAR) BufferEB_TX_SpiChannel_14[256U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT
#include "Spi_MemMap.h"

static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_1 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_6 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_7 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_12 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_13 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_14 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = BufferEB_TX_SpiChannel_14
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_15 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_16 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_17 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_18 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_19 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_20 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_21 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_22 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_23 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_24 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_25 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_26 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_27 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_28 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_29 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_30 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};
static VAR(Spi_EBDataType, SPI_VAR) EB_SpiChannel_31 = {
    .Length = 0,
    .ReadBuffer = NULL_PTR,
    .WriteBuffer = NULL_PTR,
    .WriteBufferReverse = NULL_PTR
};

#define SPI_STOP_SEC_VAR_INIT
#include "Spi_MemMap.h"


#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

static CONST(Spi_ChannelCfgType, SPI_CONST) SpiChannelConfiguration[SPI_TOTAL_CHANNEL] =
{
    {
        /* SpiChannel_0*/
        .ChannelId = 0,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 4U,
        .WriteBuffer = BufferIB_TX_SpiChannel_0,
        .ReadBuffer = BufferIB_RX_SpiChannel_0,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_1*/
        .ChannelId = 1,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_1,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_2*/
        .ChannelId = 2,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 4U,
        .WriteBuffer = BufferIB_TX_SpiChannel_2,
        .ReadBuffer = BufferIB_RX_SpiChannel_2,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_3*/
        .ChannelId = 3,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 4U,
        .WriteBuffer = BufferIB_TX_SpiChannel_3,
        .ReadBuffer = BufferIB_RX_SpiChannel_3,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_4*/
        .ChannelId = 4,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 4U,
        .WriteBuffer = BufferIB_TX_SpiChannel_4,
        .ReadBuffer = BufferIB_RX_SpiChannel_4,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_5*/
        .ChannelId = 5,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 4U,
        .WriteBuffer = BufferIB_TX_SpiChannel_5,
        .ReadBuffer = BufferIB_RX_SpiChannel_5,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_6*/
        .ChannelId = 6,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_6,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_7*/
        .ChannelId = 7,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_7,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_8*/
        .ChannelId = 8,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .WriteBuffer = BufferIB_TX_SpiChannel_8,
        .ReadBuffer = BufferIB_RX_SpiChannel_8,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_9*/
        .ChannelId = 9,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .WriteBuffer = BufferIB_TX_SpiChannel_9,
        .ReadBuffer = BufferIB_RX_SpiChannel_9,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_10*/
        .ChannelId = 10,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .WriteBuffer = BufferIB_TX_SpiChannel_10,
        .ReadBuffer = BufferIB_RX_SpiChannel_10,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_11*/
        .ChannelId = 11,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .WriteBuffer = BufferIB_TX_SpiChannel_11,
        .ReadBuffer = BufferIB_RX_SpiChannel_11,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_12*/
        .ChannelId = 12,
        .ChannelBufferType = EB,
        .DataWidth = 16U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_12,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_13*/
        .ChannelId = 13,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_13,
        .TransferType = LSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_14*/
        .ChannelId = 14,
        .ChannelBufferType = EB,
        .DataWidth = 32U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_14,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_15*/
        .ChannelId = 15,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_15,
        .TransferType = MSB,
        .DefaultValue = 255U,
    },
    {
        /* SpiChannel_16*/
        .ChannelId = 16,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_16,
        .TransferType = MSB,
        .DefaultValue = 255U,
    },
    {
        /* SpiChannel_17*/
        .ChannelId = 17,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_17,
        .TransferType = MSB,
        .DefaultValue = 255U,
    },
    {
        /* SpiChannel_18*/
        .ChannelId = 18,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_18,
        .TransferType = MSB,
        .DefaultValue = 255U,
    },
    {
        /* SpiChannel_19*/
        .ChannelId = 19,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_19,
        .TransferType = MSB,
        .DefaultValue = 255U,
    },
    {
        /* SpiChannel_20*/
        .ChannelId = 20,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_20,
        .TransferType = MSB,
        .DefaultValue = 255U,
    },
    {
        /* SpiChannel_21*/
        .ChannelId = 21,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_21,
        .TransferType = MSB,
        .DefaultValue = 255U,
    },
    {
        /* SpiChannel_22*/
        .ChannelId = 22,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 10U,
        .EB_Buffer = &EB_SpiChannel_22,
        .TransferType = MSB,
        .DefaultValue = 255U,
    },
    {
        /* SpiChannel_23*/
        .ChannelId = 23,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_23,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_24*/
        .ChannelId = 24,
        .ChannelBufferType = EB,
        .DataWidth = 16U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_24,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_25*/
        .ChannelId = 25,
        .ChannelBufferType = EB,
        .DataWidth = 16U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_25,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_26*/
        .ChannelId = 26,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_26,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_27*/
        .ChannelId = 27,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_27,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_28*/
        .ChannelId = 28,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_28,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_29*/
        .ChannelId = 29,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_29,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_30*/
        .ChannelId = 30,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_30,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_31*/
        .ChannelId = 31,
        .ChannelBufferType = EB,
        .DataWidth = 8U,
        .BufferSize = 64U,
        .EB_Buffer = &EB_SpiChannel_31,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_32*/
        .ChannelId = 32,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 4U,
        .WriteBuffer = BufferIB_TX_SpiChannel_32,
        .ReadBuffer = BufferIB_RX_SpiChannel_32,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_33*/
        .ChannelId = 33,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 4U,
        .WriteBuffer = BufferIB_TX_SpiChannel_33,
        .ReadBuffer = BufferIB_RX_SpiChannel_33,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
    {
        /* SpiChannel_34*/
        .ChannelId = 34,
        .ChannelBufferType = IB,
        .DataWidth = 8U,
        .BufferSize = 4U,
        .WriteBuffer = BufferIB_TX_SpiChannel_34,
        .ReadBuffer = BufferIB_RX_SpiChannel_34,
        .TransferType = MSB,
        .DefaultValue = 0U,
    },
};

static CONST(Spi_ChannelType, SPI_CONST) SpiJob_0_ChannelList[1] = 
{
    0U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_1_ChannelList[1] = 
{
    1U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_2_ChannelList[2] = 
{
    2U,
    3U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_3_ChannelList[2] = 
{
    4U,
    5U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_4_ChannelList[2] = 
{
    6U,
    7U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_5_ChannelList[2] = 
{
    8U,
    9U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_6_ChannelList[2] = 
{
    10U,
    11U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_7_ChannelList[1] = 
{
    12U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_8_ChannelList[1] = 
{
    13U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_9_ChannelList[1] = 
{
    13U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_10_ChannelList[1] = 
{
    14U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_11_ChannelList[2] = 
{
    15U,
    16U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_12_ChannelList[2] = 
{
    17U,
    18U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_13_ChannelList[2] = 
{
    19U,
    20U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_14_ChannelList[2] = 
{
    21U,
    22U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_15_ChannelList[1] = 
{
    23U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_16_ChannelList[1] = 
{
    24U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_17_ChannelList[1] = 
{
    25U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_18_ChannelList[1] = 
{
    26U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_19_ChannelList[1] = 
{
    26U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_20_ChannelList[1] = 
{
    26U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_21_ChannelList[1] = 
{
    26U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_22_ChannelList[1] = 
{
    27U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_23_ChannelList[1] = 
{
    27U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_24_ChannelList[1] = 
{
    27U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_25_ChannelList[1] = 
{
    27U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_26_ChannelList[1] = 
{
    28U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_27_ChannelList[1] = 
{
    29U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_28_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_29_ChannelList[1] = 
{
    31U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_30_ChannelList[1] = 
{
    32U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_31_ChannelList[1] = 
{
    33U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_32_ChannelList[1] = 
{
    34U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_33_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_34_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_35_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_36_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_37_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_38_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_39_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_40_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_41_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_42_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_43_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_44_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_45_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_46_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_47_ChannelList[1] = 
{
    30U,
};
static CONST(Spi_ChannelType, SPI_CONST) SpiJob_48_ChannelList[1] = 
{
    30U,
};





static CONST(Spi_JobCfgType, SPI_CONST) SpiJobConfiguration[SPI_TOTAL_JOB] = 
{
    {
        .JobId = 0U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_0_ChannelList,
    },
    {
        .JobId = 1U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_1_ChannelList,
    },
    {
        .JobId = 2U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 2U,
        .ChannelList = SpiJob_2_ChannelList,
    },
    {
        .JobId = 3U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 2U,
        .ChannelList = SpiJob_3_ChannelList,
    },
    {
        .JobId = 4U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 2U,
        .ChannelList = SpiJob_4_ChannelList,
    },
    {
        .JobId = 5U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 2U,
        .ChannelList = SpiJob_5_ChannelList,
    },
    {
        .JobId = 6U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 2U,
        .ChannelList = SpiJob_6_ChannelList,
    },
    {
        .JobId = 7U,
        .HwUnit = 1U, /* @index */
        .HwDeviceIdx = 6U,
        .HwDevice = DSPI1,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = HIGH,
        .ClockShift = TRAILING,
        .Ctar = (uint32)( /* Real Frequency 1041666 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (1U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_7_ChannelList,
    },
    {
        .JobId = 8U,
        .HwUnit = 5U, /* @index */
        .HwDeviceIdx = 4U,
        .HwDevice = DSPI5,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_8_ChannelList,
    },
    {
        .JobId = 9U,
        .HwUnit = 6U, /* @index */
        .HwDeviceIdx = 5U,
        .HwDevice = DSPI12,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = HIGH,
        .CSCountinue =0x8000U,
        .ClockPolarity = HIGH,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_9_ChannelList,
    },
    {
        .JobId = 10U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_10_ChannelList,
    },
    {
        .JobId = 11U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 2U,
        .ChannelList = SpiJob_11_ChannelList,
    },
    {
        .JobId = 12U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 2U,
        .ChannelList = SpiJob_12_ChannelList,
    },
    {
        .JobId = 13U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 1U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 2U,
        .ChannelList = SpiJob_13_ChannelList,
    },
    {
        .JobId = 14U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 1U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 2U,
        .ChannelList = SpiJob_14_ChannelList,
    },
    {
        .JobId = 15U,
        .HwUnit = 3U, /* @index */
        .HwDeviceIdx = 2U,
        .HwDevice = DSPI3,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 10000000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (0U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_15_ChannelList,
    },
    {
        .JobId = 16U,
        .HwUnit = 2U, /* @index */
        .HwDeviceIdx = 1U,
        .HwDevice = DSPI2,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = HIGH,
        .ClockShift = TRAILING,
        .Ctar = (uint32)( /* Real Frequency 1041666 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (1U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_16_ChannelList,
    },
    {
        .JobId = 17U,
        .HwUnit = 4U, /* @index */
        .HwDeviceIdx = 3U,
        .HwDevice = DSPI4,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = TRAILING,
        .Ctar = (uint32)( /* Real Frequency 1041666 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (1U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_17_ChannelList,
    },
    {
        .JobId = 18U,
        .HwUnit = 7U, /* @index */
        .HwDeviceIdx = 16U,
        .HwDevice = DSPI17,
        .CSPin = PCS1,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_18_ChannelList,
    },
    {
        .JobId = 19U,
        .HwUnit = 8U, /* @index */
        .HwDeviceIdx = 16U,
        .HwDevice = DSPI17,
        .CSPin = PCS2,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_19_ChannelList,
    },
    {
        .JobId = 20U,
        .HwUnit = 9U, /* @index */
        .HwDeviceIdx = 16U,
        .HwDevice = DSPI17,
        .CSPin = PCS3,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_20_ChannelList,
    },
    {
        .JobId = 21U,
        .HwUnit = 10U, /* @index */
        .HwDeviceIdx = 16U,
        .HwDevice = DSPI17,
        .CSPin = PCS4,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_21_ChannelList,
    },
    {
        .JobId = 22U,
        .HwUnit = 1U, /* @index */
        .HwDeviceIdx = 6U,
        .HwDevice = DSPI1,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = HIGH,
        .ClockShift = TRAILING,
        .Ctar = (uint32)( /* Real Frequency 1041666 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (1U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_22_ChannelList,
    },
    {
        .JobId = 23U,
        .HwUnit = 11U, /* @index */
        .HwDeviceIdx = 16U,
        .HwDevice = DSPI17,
        .CSPin = PCS5,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_23_ChannelList,
    },
    {
        .JobId = 24U,
        .HwUnit = 12U, /* @index */
        .HwDeviceIdx = 16U,
        .HwDevice = DSPI17,
        .CSPin = PCS6,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_24_ChannelList,
    },
    {
        .JobId = 25U,
        .HwUnit = 13U, /* @index */
        .HwDeviceIdx = 16U,
        .HwDevice = DSPI17,
        .CSPin = PCS7,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_25_ChannelList,
    },
    {
        .JobId = 26U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_26_ChannelList,
    },
    {
        .JobId = 27U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_27_ChannelList,
    },
    {
        .JobId = 28U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_28_ChannelList,
    },
    {
        .JobId = 29U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_29_ChannelList,
    },
    {
        .JobId = 30U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_30_ChannelList,
    },
    {
        .JobId = 31U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_31_ChannelList,
    },
    {
        .JobId = 32U,
        .HwUnit = 0U, /* @index */
        .HwDeviceIdx = 0U,
        .HwDevice = DSPI0,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 5000000 Hz */ /* CSC = 16 */ /* ASC = 2 */ /* DT = 2 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (1U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (3U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (0U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (0U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_32_ChannelList,
    },
    {
        .JobId = 33U,
        .HwUnit = 14U, /* @index */
        .HwDeviceIdx = 21U,
        .HwDevice = DSPI6,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_33_ChannelList,
    },
    {
        .JobId = 34U,
        .HwUnit = 15U, /* @index */
        .HwDeviceIdx = 7U,
        .HwDevice = DSPI7,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_34_ChannelList,
    },
    {
        .JobId = 35U,
        .HwUnit = 16U, /* @index */
        .HwDeviceIdx = 8U,
        .HwDevice = DSPI8,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_35_ChannelList,
    },
    {
        .JobId = 36U,
        .HwUnit = 17U, /* @index */
        .HwDeviceIdx = 9U,
        .HwDevice = DSPI9,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_36_ChannelList,
    },
    {
        .JobId = 37U,
        .HwUnit = 18U, /* @index */
        .HwDeviceIdx = 10U,
        .HwDevice = DSPI10,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_37_ChannelList,
    },
    {
        .JobId = 38U,
        .HwUnit = 19U, /* @index */
        .HwDeviceIdx = 11U,
        .HwDevice = DSPI11,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_38_ChannelList,
    },
    {
        .JobId = 39U,
        .HwUnit = 20U, /* @index */
        .HwDeviceIdx = 12U,
        .HwDevice = DSPI13,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_39_ChannelList,
    },
    {
        .JobId = 40U,
        .HwUnit = 21U, /* @index */
        .HwDeviceIdx = 13U,
        .HwDevice = DSPI14,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_40_ChannelList,
    },
    {
        .JobId = 41U,
        .HwUnit = 22U, /* @index */
        .HwDeviceIdx = 14U,
        .HwDevice = DSPI15,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_41_ChannelList,
    },
    {
        .JobId = 42U,
        .HwUnit = 23U, /* @index */
        .HwDeviceIdx = 15U,
        .HwDevice = DSPI16,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_42_ChannelList,
    },
    {
        .JobId = 43U,
        .HwUnit = 24U, /* @index */
        .HwDeviceIdx = 16U,
        .HwDevice = DSPI17,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_43_ChannelList,
    },
    {
        .JobId = 44U,
        .HwUnit = 25U, /* @index */
        .HwDeviceIdx = 17U,
        .HwDevice = DSPI18,
        .CSPin = PCS4,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_44_ChannelList,
    },
    {
        .JobId = 45U,
        .HwUnit = 26U, /* @index */
        .HwDeviceIdx = 18U,
        .HwDevice = DSPI19,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_45_ChannelList,
    },
    {
        .JobId = 46U,
        .HwUnit = 27U, /* @index */
        .HwDeviceIdx = 19U,
        .HwDevice = DSPI20,
        .CSPin = PCS2,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_46_ChannelList,
    },
    {
        .JobId = 47U,
        .HwUnit = 28U, /* @index */
        .HwDeviceIdx = 20U,
        .HwDevice = DSPI21,
        .CSPin = PCS4,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_47_ChannelList,
    },
    {
        .JobId = 48U,
        .HwUnit = 14U, /* @index */
        .HwDeviceIdx = 21U,
        .HwDevice = DSPI6,
        .CSPin = PCS0,
        .CSFunc = TRUE,
        .CSPolarity = LOW,
        .CSCountinue =0x8000U,
        .ClockPolarity = LOW,
        .ClockShift = LEADING,
        .Ctar = (uint32)( /* Real Frequency 625000 Hz */ /* CSC = 512 */ /* ASC = 512 */ /* DT = 512 */ 
            /* Prescaler */   (2U << 16U) 
            /* Scaler */    | (5U << 0U)
            /* PCSSCK */    | (0U << 22U)
            /* CSSCK */     | (8U << 12U)
            /* PASC */      | (0U << 20U)
            /* ASC */       | (8U << 8U)
            /* PDT */       | (0U << 18U)
            /* DT */        | (8U << 4U) ),
        .CtarSel = 0U,
        .SpiJobPriority = 0U,
        .JobEndNotification = NULL_PTR,
        .NoOfChannels = 1U,
        .ChannelList = SpiJob_48_ChannelList,
    },
};

static CONST(Spi_JobType, SPI_CONST) SpiSequence_0_JobList[1] = 
{
    0U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_1_JobList[1] = 
{
    1U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_2_JobList[1] = 
{
    2U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_3_JobList[2] = 
{
    3U,
    4U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_4_JobList[2] = 
{
    5U,
    6U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_5_JobList[1] = 
{
    7U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_6_JobList[1] = 
{
    8U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_7_JobList[1] = 
{
    9U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_8_JobList[1] = 
{
    10U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_9_JobList[2] = 
{
    11U,
    12U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_10_JobList[2] = 
{
    13U,
    14U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_11_JobList[1] = 
{
    15U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_12_JobList[1] = 
{
    15U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_13_JobList[1] = 
{
    16U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_14_JobList[1] = 
{
    17U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_15_JobList[1] = 
{
    18U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_16_JobList[1] = 
{
    19U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_17_JobList[1] = 
{
    20U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_18_JobList[1] = 
{
    21U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_19_JobList[1] = 
{
    22U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_20_JobList[3] = 
{
    23U,
    24U,
    25U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_21_JobList[1] = 
{
    26U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_22_JobList[1] = 
{
    27U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_23_JobList[1] = 
{
    28U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_24_JobList[1] = 
{
    29U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_25_JobList[1] = 
{
    30U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_26_JobList[1] = 
{
    31U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_27_JobList[1] = 
{
    32U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_28_JobList[1] = 
{
    33U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_29_JobList[1] = 
{
    34U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_30_JobList[1] = 
{
    35U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_31_JobList[1] = 
{
    36U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_32_JobList[1] = 
{
    37U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_33_JobList[1] = 
{
    38U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_34_JobList[1] = 
{
    39U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_35_JobList[1] = 
{
    40U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_36_JobList[1] = 
{
    41U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_37_JobList[1] = 
{
    42U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_38_JobList[1] = 
{
    43U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_39_JobList[1] = 
{
    44U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_40_JobList[1] = 
{
    45U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_41_JobList[1] = 
{
    46U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_42_JobList[1] = 
{
    47U,
};
static CONST(Spi_JobType, SPI_CONST) SpiSequence_43_JobList[1] = 
{
    48U,
};

static CONST(Spi_SequenceCfgType, SPI_CONST) SpiSequenceConfiguration[SPI_TOTAL_SEQUENCE] =
{
    {
        /* SpiSequence_0 */
        .SequenceId = 0U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_0_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_1 */
        .SequenceId = 1U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_1_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_2 */
        .SequenceId = 2U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_2_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_3 */
        .SequenceId = 3U,
        .NoOfJobs = 2U,
        .JobList = SpiSequence_3_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_4 */
        .SequenceId = 4U,
        .NoOfJobs = 2U,
        .JobList = SpiSequence_4_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_5 */
        .SequenceId = 5U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_5_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_6 */
        .SequenceId = 6U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_6_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_7 */
        .SequenceId = 7U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_7_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_8 */
        .SequenceId = 8U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_8_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_9 */
        .SequenceId = 9U,
        .InterruptableSequence = TRUE,
        .NoOfJobs = 2U,
        .JobList = SpiSequence_9_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_10 */
        .SequenceId = 10U,
        .InterruptableSequence = TRUE,
        .NoOfJobs = 2U,
        .JobList = SpiSequence_10_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_11 */
        .SequenceId = 11U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_11_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_12 */
        .SequenceId = 12U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_12_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_13 */
        .SequenceId = 13U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_13_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_14 */
        .SequenceId = 14U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_14_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_15 */
        .SequenceId = 15U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_15_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_16 */
        .SequenceId = 16U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_16_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_17 */
        .SequenceId = 17U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_17_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_18 */
        .SequenceId = 18U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_18_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_19 */
        .SequenceId = 19U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_19_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_20 */
        .SequenceId = 20U,
        .NoOfJobs = 3U,
        .JobList = SpiSequence_20_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_21 */
        .SequenceId = 21U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_21_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_22 */
        .SequenceId = 22U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_22_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_23 */
        .SequenceId = 23U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_23_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_24 */
        .SequenceId = 24U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_24_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_25 */
        .SequenceId = 25U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_25_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_26 */
        .SequenceId = 26U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_26_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_27 */
        .SequenceId = 27U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_27_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_28 */
        .SequenceId = 28U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_28_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_29 */
        .SequenceId = 29U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_29_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_30 */
        .SequenceId = 30U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_30_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_31 */
        .SequenceId = 31U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_31_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_32 */
        .SequenceId = 32U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_32_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_33 */
        .SequenceId = 33U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_33_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_34 */
        .SequenceId = 34U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_34_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_35 */
        .SequenceId = 35U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_35_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_36 */
        .SequenceId = 36U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_36_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_37 */
        .SequenceId = 37U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_37_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_38 */
        .SequenceId = 38U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_38_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_39 */
        .SequenceId = 39U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_39_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_40 */
        .SequenceId = 40U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_40_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_41 */
        .SequenceId = 41U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_41_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_42 */
        .SequenceId = 42U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_42_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
    {
        /* SpiSequence_43 */
        .SequenceId = 43U,
        .NoOfJobs = 1U,
        .JobList = SpiSequence_43_JobList,
        .SequenceEndNotification = NULL_PTR,
    },
};

static CONST(Spi_HwUnitCfgType, SPI_CONST) Spi_HwConfiguration[SPI_TOTAL_HWUNIT] = 
{
    {
        .HwDeviceIdx = 0,
        .HwDevice = DSPI0
    },
    {
        .HwDeviceIdx = 6,
        .HwDevice = DSPI1
    },
    {
        .HwDeviceIdx = 1,
        .HwDevice = DSPI2
    },
    {
        .HwDeviceIdx = 2,
        .HwDevice = DSPI3
    },
    {
        .HwDeviceIdx = 3,
        .HwDevice = DSPI4
    },
    {
        .HwDeviceIdx = 4,
        .HwDevice = DSPI5
    },
    {
        .HwDeviceIdx = 5,
        .HwDevice = DSPI12
    },
    {
        .HwDeviceIdx = 16,
        .HwDevice = DSPI17
    },
    {
        .HwDeviceIdx = 16,
        .HwDevice = DSPI17
    },
    {
        .HwDeviceIdx = 16,
        .HwDevice = DSPI17
    },
    {
        .HwDeviceIdx = 16,
        .HwDevice = DSPI17
    },
    {
        .HwDeviceIdx = 16,
        .HwDevice = DSPI17
    },
    {
        .HwDeviceIdx = 16,
        .HwDevice = DSPI17
    },
    {
        .HwDeviceIdx = 16,
        .HwDevice = DSPI17
    },
    {
        .HwDeviceIdx = 21,
        .HwDevice = DSPI6
    },
    {
        .HwDeviceIdx = 7,
        .HwDevice = DSPI7
    },
    {
        .HwDeviceIdx = 8,
        .HwDevice = DSPI8
    },
    {
        .HwDeviceIdx = 9,
        .HwDevice = DSPI9
    },
    {
        .HwDeviceIdx = 10,
        .HwDevice = DSPI10
    },
    {
        .HwDeviceIdx = 11,
        .HwDevice = DSPI11
    },
    {
        .HwDeviceIdx = 12,
        .HwDevice = DSPI13
    },
    {
        .HwDeviceIdx = 13,
        .HwDevice = DSPI14
    },
    {
        .HwDeviceIdx = 14,
        .HwDevice = DSPI15
    },
    {
        .HwDeviceIdx = 15,
        .HwDevice = DSPI16
    },
    {
        .HwDeviceIdx = 16,
        .HwDevice = DSPI17
    },
    {
        .HwDeviceIdx = 17,
        .HwDevice = DSPI18
    },
    {
        .HwDeviceIdx = 18,
        .HwDevice = DSPI19
    },
    {
        .HwDeviceIdx = 19,
        .HwDevice = DSPI20
    },
    {
        .HwDeviceIdx = 20,
        .HwDevice = DSPI21
    },
};


static CONST(Spi_HwDeviceCfgType, SPI_CONST) Spi_HwDeviceConfiguration[SPI_TOTAL_HWUNIT] = 
{
    {
        .HwIdx = 0,
        .HwDevice = DSPI0,
    },
    {
        .HwIdx = 1,
        .HwDevice = DSPI2,
    },
    {
        .HwIdx = 2,
        .HwDevice = DSPI3,
    },
    {
        .HwIdx = 3,
        .HwDevice = DSPI4,
    },
    {
        .HwIdx = 4,
        .HwDevice = DSPI5,
    },
    {
        .HwIdx = 5,
        .HwDevice = DSPI12,
    },
    {
        .HwIdx = 6,
        .HwDevice = DSPI1,
    },
    {
        .HwIdx = 7,
        .HwDevice = DSPI7,
    },
    {
        .HwIdx = 8,
        .HwDevice = DSPI8,
    },
    {
        .HwIdx = 9,
        .HwDevice = DSPI9,
    },
    {
        .HwIdx = 10,
        .HwDevice = DSPI10,
    },
    {
        .HwIdx = 11,
        .HwDevice = DSPI11,
    },
    {
        .HwIdx = 12,
        .HwDevice = DSPI13,
    },
    {
        .HwIdx = 13,
        .HwDevice = DSPI14,
    },
    {
        .HwIdx = 14,
        .HwDevice = DSPI15,
    },
    {
        .HwIdx = 15,
        .HwDevice = DSPI16,
    },
    {
        .HwIdx = 16,
        .HwDevice = DSPI17,
    },
    {
        .HwIdx = 17,
        .HwDevice = DSPI18,
    },
    {
        .HwIdx = 18,
        .HwDevice = DSPI19,
    },
    {
        .HwIdx = 19,
        .HwDevice = DSPI20,
    },
    {
        .HwIdx = 20,
        .HwDevice = DSPI21,
    },
    {
        .HwIdx = 21,
        .HwDevice = DSPI6,
    },
};




static CONST(uint8, SPI_CONST) Spi_DeviceMap[] =
{
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U),
    (uint8)(0U)
};

CONST(Spi_ConfigType, SPI_CONST) Spi_Configuration = 
{
    .SequenceNum = 35U,
    .JobNum = 49U,
    .ChannelNum = 44U,
    .HwUnitNum = 29U,
    .HwDeviceNum = 22U,
    .ChannelConfiguration = SpiChannelConfiguration,
    .JobConfiguration = SpiJobConfiguration,
    .SequenceConfiguration = SpiSequenceConfiguration,
    .HwConfiguration = Spi_HwConfiguration,
    .HwDeviceConfiguration = Spi_HwDeviceConfiguration,
    .DeviceMap = Spi_DeviceMap
};

CONST(uint32, SPI_CONST) Spi_HandleMap[22U] = 
{
    0U,
    6U,
    1U,
    2U,
    3U,
    4U,
    21U,
    7U,
    8U,
    9U,
    10U,
    11U,
    5U,
    12U,
    13U,
    14U,
    15U,
    16U,
    17U,
    18U,
    19U,
    20U,
};

#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"



#ifdef __cplusplus
}
#endif
