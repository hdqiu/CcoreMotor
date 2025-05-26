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

#define SPI_PRECOMPILE_SUPPORT              [!IF "IMPLEMENTATION_CONFIG_VARIANT != 'VariantPreCompile'"!]STD_OFF[!ELSE!]STD_ON[!ENDIF!]

#define SPI_DEV_ERROR_DETECT                [!IF "SpiGeneral/SpiDevErrorDetect = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/* Switches the development error detection and notification on or off. */
/* [SWS_Spi_00031] The API parameter Channel shall have a value within the defined channels in the initialization data structure,
 and the correct type of channel (IB or EB) has to be used with services. Related error value: SPI_E_PARAM_CHANNEL. Otherwise, 
 the service is not done and the return value shall be E_NOT_OK. (SRS_BSW_00323) */

#define SPI_VERSION_INFO_API                   [!IF "SpiGeneral/SpiVersionInfoApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#define SPI_HW_STATUS_API                      [!IF "SpiGeneral/SpiHwStatusApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#define SPI_CANCEL_API                         [!IF "SpiGeneral/SpiCancelApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#define SPI_CHANNEL_BUFFERS_ALLOWED            [!"num:i(SpiGeneral/SpiChannelBuffersAllowed)"!]U

#define SPI_LEVEL_DELIVERED                    [!IF "SpiGeneral/SpiLevelDelivered = '0'"!]SPI_LEVEL_0[!ELSEIF "SpiGeneral/SpiLevelDelivered = '1'"!]SPI_LEVEL_1[!ELSE!]SPI_LEVEL_2[!ENDIF!]

#define SPI_MAIN_FUNCTION_PERIOD               ([!"num:f(SpiGeneral/SpiMainFunctionPeriod)"!])

#define SPI_INTERRUPTIBLE_SEQ_ALLOWED          ([!IF "SpiGeneral/SpiInterruptibleSeqAllowed"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT   ([!IF "SpiGeneral/SpiSupportConcurrentSyncTransmit"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define SPI_DMA_USED                           ([!IF " SpiGeneral/SpiGlobalDmaEnable = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define SPI_EDGE_SELECT                        ([!"SpiGeneral/SpiShiftEdgeSelection"!])

#define SPI_TOTAL_CHANNEL                      [!"num:i(count(SpiDriver/SpiChannel/*))"!]U
#define SPI_TOTAL_JOB                          [!"num:i(count(SpiDriver/SpiJob/*))"!]U
#define SPI_TOTAL_SEQUENCE                     [!"num:i(count(SpiDriver/SpiSequence/*))"!]U
#define SPI_TOTAL_HWUNIT                       [!"num:i(count(SpiDriver/SpiExternalDevice/*))"!]U
#define SPI_TOTAL_HWDEVICE                     [!"num:i(count(SpiDriver/SpiHardWare/*))"!]U

[!LOOP "SpiDriver/SpiChannel/*"!]
#define [!"@name"!]   ((Spi_ChannelType)[!"num:i(@index)"!]U)
[!ENDLOOP!]
[!LOOP "SpiDriver/SpiJob/*"!]
#define [!"@name"!]   ((Spi_JobType)[!"num:i(@index)"!]U)
[!ENDLOOP!]
[!LOOP "SpiDriver/SpiSequence/*"!]
#define [!"@name"!]   ((Spi_SequenceType)[!"num:i(@index)"!]U)
[!ENDLOOP!]

[!NOCODE!]
[!LOOP "SpiDriver/SpiJob/*"!]
[!IF "SpiJobEndNotification != 'NULL_PTR'"!]
[!CODE!]extern FUNC(void, SPI_CODE)[!"SpiJobEndNotification"!](void);[!ENDCODE!]
[!ENDIF!]
[!ENDLOOP!]
[!LOOP "SpiDriver/SpiSequence/*"!]
[!IF "SpiSeqEndNotification != 'NULL_PTR'"!]
[!CODE!]extern FUNC(void, SPI_CODE)[!"SpiSeqEndNotification"!](void);[!ENDCODE!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]

#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"
extern CONST(uint32, SPI_CONST) Spi_HandleMap[22U];
#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif
