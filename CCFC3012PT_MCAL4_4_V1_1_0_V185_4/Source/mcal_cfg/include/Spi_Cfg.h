#ifndef SPI_CFG_H
#define SPI_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
INCLUDE
==================================================================================================*/
#include "Mcal.h"

/*==================================================================================================
SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_CFG_VENDOR_ID                    176
#define SPI_CFG_AR_MAJOR_VER                 4
#define SPI_CFG_AR_MINOR_VER                 4
#define SPI_CFG_AR_PATCH_VER                 0
#define SPI_CFG_SW_MAJOR_VER                 1
#define SPI_CFG_SW_MINOR_VER                 0
#define SPI_CFG_SW_PATCH_VER                 1

/*==================================================================================================
FILE VERSION CHECKS
==================================================================================================*/
#if (SPI_CFG_VENDOR_ID != MCAL_VENDOR_ID)
#error "NON-MATCHED DATA : SPI_CFG_VENDOR_ID"
#endif

/* Check if current file and SPI header file are of the same Autosar version */
#if (SPI_CFG_AR_MAJOR_VER != MCAL_AR_RELEASE_MAJOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_AR_MAJOR_VER"
#endif
#if (SPI_CFG_AR_MINOR_VER != MCAL_AR_RELEASE_MINOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_AR_MINOR_VER"
#endif
#if (SPI_CFG_AR_PATCH_VER != MCAL_AR_RELEASE_REVISION_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_AR_PATCH_VER"
#endif

/* Check if current file and SPI header file are of the same Software version */
#if (SPI_CFG_SW_MAJOR_VER != MCAL_SW_MAJOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_SW_MAJOR_VER"
#endif
#if (SPI_CFG_SW_MINOR_VER != MCAL_SW_MINOR_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_SW_MINOR_VER"
#endif
#if (SPI_CFG_SW_PATCH_VER != MCAL_SW_PATCH_VERSION)
#error "NON-MATCHED DATA : SPI_CFG_SW_PATCH_VER"
#endif

/*==================================================================================================
DEFINES
==================================================================================================*/

#define SPI_PRECOMPILE_SUPPORT              STD_OFF

#define SPI_DEV_ERROR_DETECT                STD_ON

/* Switches the development error detection and notification on or off. */
/* [SWS_Spi_00031] The API parameter Channel shall have a value within the defined channels in the initialization data structure,
 and the correct type of channel (IB or EB) has to be used with services. Related error value: SPI_E_PARAM_CHANNEL. Otherwise, 
 the service is not done and the return value shall be E_NOT_OK. (SRS_BSW_00323) */

#define SPI_VERSION_INFO_API                   STD_ON

#define SPI_HW_STATUS_API                      STD_ON

#define SPI_CANCEL_API                         STD_ON

#define SPI_CHANNEL_BUFFERS_ALLOWED            2U

#define SPI_LEVEL_DELIVERED                    SPI_LEVEL_2

#define SPI_MAIN_FUNCTION_PERIOD               (0.01)

#define SPI_INTERRUPTIBLE_SEQ_ALLOWED          (STD_ON)

#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT   (STD_OFF)

#define SPI_DMA_USED                           (STD_OFF)

#define SPI_EDGE_SELECT                        (SAMPLE)

#define SPI_TOTAL_CHANNEL                      35U
#define SPI_TOTAL_JOB                          49U
#define SPI_TOTAL_SEQUENCE                     44U
#define SPI_TOTAL_HWUNIT                       29U
#define SPI_TOTAL_HWDEVICE                     22U


#define SpiChannel_0   ((Spi_ChannelType)0U)

#define SpiChannel_1   ((Spi_ChannelType)1U)

#define SpiChannel_2   ((Spi_ChannelType)2U)

#define SpiChannel_3   ((Spi_ChannelType)3U)

#define SpiChannel_4   ((Spi_ChannelType)4U)

#define SpiChannel_5   ((Spi_ChannelType)5U)

#define SpiChannel_6   ((Spi_ChannelType)6U)

#define SpiChannel_7   ((Spi_ChannelType)7U)

#define SpiChannel_8   ((Spi_ChannelType)8U)

#define SpiChannel_9   ((Spi_ChannelType)9U)

#define SpiChannel_10   ((Spi_ChannelType)10U)

#define SpiChannel_11   ((Spi_ChannelType)11U)

#define SpiChannel_12   ((Spi_ChannelType)12U)

#define SpiChannel_13   ((Spi_ChannelType)13U)

#define SpiChannel_14   ((Spi_ChannelType)14U)

#define SpiChannel_15   ((Spi_ChannelType)15U)

#define SpiChannel_16   ((Spi_ChannelType)16U)

#define SpiChannel_17   ((Spi_ChannelType)17U)

#define SpiChannel_18   ((Spi_ChannelType)18U)

#define SpiChannel_19   ((Spi_ChannelType)19U)

#define SpiChannel_20   ((Spi_ChannelType)20U)

#define SpiChannel_21   ((Spi_ChannelType)21U)

#define SpiChannel_22   ((Spi_ChannelType)22U)

#define SpiChannel_23   ((Spi_ChannelType)23U)

#define SpiChannel_24   ((Spi_ChannelType)24U)

#define SpiChannel_25   ((Spi_ChannelType)25U)

#define SpiChannel_26   ((Spi_ChannelType)26U)

#define SpiChannel_27   ((Spi_ChannelType)27U)

#define SpiChannel_28   ((Spi_ChannelType)28U)

#define SpiChannel_29   ((Spi_ChannelType)29U)

#define SpiChannel_30   ((Spi_ChannelType)30U)

#define SpiChannel_31   ((Spi_ChannelType)31U)

#define SpiChannel_32   ((Spi_ChannelType)32U)

#define SpiChannel_33   ((Spi_ChannelType)33U)

#define SpiChannel_34   ((Spi_ChannelType)34U)


#define SpiJob_0   ((Spi_JobType)0U)

#define SpiJob_1   ((Spi_JobType)1U)

#define SpiJob_2   ((Spi_JobType)2U)

#define SpiJob_3   ((Spi_JobType)3U)

#define SpiJob_4   ((Spi_JobType)4U)

#define SpiJob_5   ((Spi_JobType)5U)

#define SpiJob_6   ((Spi_JobType)6U)

#define SpiJob_7   ((Spi_JobType)7U)

#define SpiJob_8   ((Spi_JobType)8U)

#define SpiJob_9   ((Spi_JobType)9U)

#define SpiJob_10   ((Spi_JobType)10U)

#define SpiJob_11   ((Spi_JobType)11U)

#define SpiJob_12   ((Spi_JobType)12U)

#define SpiJob_13   ((Spi_JobType)13U)

#define SpiJob_14   ((Spi_JobType)14U)

#define SpiJob_15   ((Spi_JobType)15U)

#define SpiJob_16   ((Spi_JobType)16U)

#define SpiJob_17   ((Spi_JobType)17U)

#define SpiJob_18   ((Spi_JobType)18U)

#define SpiJob_19   ((Spi_JobType)19U)

#define SpiJob_20   ((Spi_JobType)20U)

#define SpiJob_21   ((Spi_JobType)21U)

#define SpiJob_22   ((Spi_JobType)22U)

#define SpiJob_23   ((Spi_JobType)23U)

#define SpiJob_24   ((Spi_JobType)24U)

#define SpiJob_25   ((Spi_JobType)25U)

#define SpiJob_26   ((Spi_JobType)26U)

#define SpiJob_27   ((Spi_JobType)27U)

#define SpiJob_28   ((Spi_JobType)28U)

#define SpiJob_29   ((Spi_JobType)29U)

#define SpiJob_30   ((Spi_JobType)30U)

#define SpiJob_31   ((Spi_JobType)31U)

#define SpiJob_32   ((Spi_JobType)32U)

#define SpiJob_33   ((Spi_JobType)33U)

#define SpiJob_34   ((Spi_JobType)34U)

#define SpiJob_35   ((Spi_JobType)35U)

#define SpiJob_36   ((Spi_JobType)36U)

#define SpiJob_37   ((Spi_JobType)37U)

#define SpiJob_38   ((Spi_JobType)38U)

#define SpiJob_39   ((Spi_JobType)39U)

#define SpiJob_40   ((Spi_JobType)40U)

#define SpiJob_41   ((Spi_JobType)41U)

#define SpiJob_42   ((Spi_JobType)42U)

#define SpiJob_43   ((Spi_JobType)43U)

#define SpiJob_44   ((Spi_JobType)44U)

#define SpiJob_45   ((Spi_JobType)45U)

#define SpiJob_46   ((Spi_JobType)46U)

#define SpiJob_47   ((Spi_JobType)47U)

#define SpiJob_48   ((Spi_JobType)48U)


#define SpiSequence_0   ((Spi_SequenceType)0U)

#define SpiSequence_1   ((Spi_SequenceType)1U)

#define SpiSequence_2   ((Spi_SequenceType)2U)

#define SpiSequence_3   ((Spi_SequenceType)3U)

#define SpiSequence_4   ((Spi_SequenceType)4U)

#define SpiSequence_5   ((Spi_SequenceType)5U)

#define SpiSequence_6   ((Spi_SequenceType)6U)

#define SpiSequence_7   ((Spi_SequenceType)7U)

#define SpiSequence_8   ((Spi_SequenceType)8U)

#define SpiSequence_9   ((Spi_SequenceType)9U)

#define SpiSequence_10   ((Spi_SequenceType)10U)

#define SpiSequence_11   ((Spi_SequenceType)11U)

#define SpiSequence_12   ((Spi_SequenceType)12U)

#define SpiSequence_13   ((Spi_SequenceType)13U)

#define SpiSequence_14   ((Spi_SequenceType)14U)

#define SpiSequence_15   ((Spi_SequenceType)15U)

#define SpiSequence_16   ((Spi_SequenceType)16U)

#define SpiSequence_17   ((Spi_SequenceType)17U)

#define SpiSequence_18   ((Spi_SequenceType)18U)

#define SpiSequence_19   ((Spi_SequenceType)19U)

#define SpiSequence_20   ((Spi_SequenceType)20U)

#define SpiSequence_21   ((Spi_SequenceType)21U)

#define SpiSequence_22   ((Spi_SequenceType)22U)

#define SpiSequence_23   ((Spi_SequenceType)23U)

#define SpiSequence_24   ((Spi_SequenceType)24U)

#define SpiSequence_25   ((Spi_SequenceType)25U)

#define SpiSequence_26   ((Spi_SequenceType)26U)

#define SpiSequence_27   ((Spi_SequenceType)27U)

#define SpiSequence_28   ((Spi_SequenceType)28U)

#define SpiSequence_29   ((Spi_SequenceType)29U)

#define SpiSequence_30   ((Spi_SequenceType)30U)

#define SpiSequence_31   ((Spi_SequenceType)31U)

#define SpiSequence_32   ((Spi_SequenceType)32U)

#define SpiSequence_33   ((Spi_SequenceType)33U)

#define SpiSequence_34   ((Spi_SequenceType)34U)

#define SpiSequence_35   ((Spi_SequenceType)35U)

#define SpiSequence_36   ((Spi_SequenceType)36U)

#define SpiSequence_37   ((Spi_SequenceType)37U)

#define SpiSequence_38   ((Spi_SequenceType)38U)

#define SpiSequence_39   ((Spi_SequenceType)39U)

#define SpiSequence_40   ((Spi_SequenceType)40U)

#define SpiSequence_41   ((Spi_SequenceType)41U)

#define SpiSequence_42   ((Spi_SequenceType)42U)

#define SpiSequence_43   ((Spi_SequenceType)43U)




#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
extern CONST(uint32, SPI_CONST) Spi_HandleMap[22U];
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif
