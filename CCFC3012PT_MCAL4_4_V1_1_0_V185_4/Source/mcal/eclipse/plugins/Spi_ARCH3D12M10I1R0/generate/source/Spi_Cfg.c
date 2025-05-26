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

[!AUTOSPACING!]

[!INDENT "0"!]
    [!LOOP "SpiDriver/SpiChannel/*"!]
        [!IF "SpiChannelType = 'IB'"!]
            [!IF "SpiDataWidth < num:i(9)"!]
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
                static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_[!"@name"!][[!"num:i(SpiIbNBuffers)"!]U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
                static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_[!"@name"!][[!"num:i(SpiIbNBuffers)"!]U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
            [!ELSEIF "SpiDataWidth < num:i(17)"!]
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
                MEM_ALIGN(2) static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_[!"@name"!][[!"num:i(num:i(SpiIbNBuffers) * num:i(2))"!]U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
                MEM_ALIGN(2) static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_[!"@name"!][[!"num:i(num:i(SpiIbNBuffers) * num:i(2))"!]U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
            [!ELSE!]
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
                MEM_ALIGN(4) static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_TX_[!"@name"!][[!"num:i(num:i(SpiIbNBuffers) * num:i(4))"!]U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
               MEM_ALIGN(4)  static VAR(Spi_DataBufferType, SPI_VAR) BufferIB_RX_[!"@name"!][[!"num:i(num:i(SpiIbNBuffers) * num:i(4))"!]U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDINDENT!]

[!INDENT "0"!]
    [!LOOP "SpiDriver/SpiChannel/*"!]
        [!IF "SpiChannelType = 'EB'"!]
            [!IF "SpiDataWidth > num:i(16)"!]
#define SPI_START_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
                MEM_ALIGN(4) static VAR(Spi_DataBufferType, SPI_VAR) BufferEB_TX_[!"@name"!][[!"num:i(num:i(SpiEbMaxLength) * num:i(4))"!]U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_NO_INIT
#include "Spi_MemMap.h"
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDINDENT!]

#define SPI_START_SEC_VAR_INIT
#include "Spi_MemMap.h"

[!INDENT "0"!]
    [!LOOP "SpiDriver/SpiChannel/*"!]
        [!IF "SpiChannelType = 'EB'"!]
            static VAR(Spi_EBDataType, SPI_VAR) EB_[!"@name"!] = {
                [!INDENT "4"!]
                .Length = 0,
                .ReadBuffer = NULL_PTR,
                .WriteBuffer = NULL_PTR,
                [!IF "SpiDataWidth > num:i(16)"!]
                .WriteBufferReverse = BufferEB_TX_[!"@name"!]
                [!ELSE!]
                .WriteBufferReverse = NULL_PTR
                [!ENDIF!]
                [!ENDINDENT!]
            };
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDINDENT!]

#define SPI_STOP_SEC_VAR_INIT
#include "Spi_MemMap.h"


#define SPI_START_SEC_CONFIG_DATA
#include "Spi_MemMap.h"

[!INDENT "0"!]
static CONST(Spi_ChannelCfgType, SPI_CONST) SpiChannelConfiguration[SPI_TOTAL_CHANNEL] =
{
    [!LOOP "SpiDriver/SpiChannel/*"!]
        [!INDENT "4"!]
        {
            [!INDENT "8"!]
            /* [!"@name"!]*/
            .ChannelId = [!"num:i(SpiChannelId)"!],
            .ChannelBufferType = [!"SpiChannelType"!],
            .DataWidth = [!"num:i(SpiDataWidth)"!]U,
            [!IF "SpiChannelType = 'EB'"!]
                .BufferSize = [!"num:i(SpiEbMaxLength)"!]U,
                .EB_Buffer = &EB_[!"@name"!],
            [!ELSE!]
                .BufferSize = [!"num:i(SpiIbNBuffers)"!]U,
                .WriteBuffer = BufferIB_TX_[!"@name"!],
                .ReadBuffer = BufferIB_RX_[!"@name"!],
            [!ENDIF!]
            .TransferType = [!"SpiTransferStart"!],
            .DefaultValue = [!"num:i(SpiDefaultData)"!]U,
            [!ENDINDENT!]
        },
        [!ENDINDENT!]
    [!ENDLOOP!]
};
[!ENDINDENT!]

[!INDENT "0"!]
    [!LOOP "SpiDriver/SpiJob/*"!]
        static CONST(Spi_ChannelType, SPI_CONST) [!"@name"!]_ChannelList[[!"num:i(count(SpiChannelList/*))"!]] = 
        {
            [!INDENT "4"!]
            [!LOOP "SpiChannelList/*"!]
                [!VAR "temp_index" = "num:i(0)"!]
                [!VAR "temp_hasChannel" = "num:i(0)"!]
                [!VAR "temp_name" = "name(node:ref(SpiChannelAssignment))"!]
                [!LOOP "../../../../SpiChannel/*"!]
                    [!IF "$temp_name = @name"!]
                        [!VAR "temp_index" = "num:i(@index)"!]
                        [!VAR "temp_hasChannel" = "num:i(1)"!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!IF "$temp_hasChannel = num:i(0)"!]
                    [!ERROR!] There's no channel we're looking for [!ENDERROR!]
                [!ELSE!]
                    [!"$temp_index"!]U,
                [!ENDIF!]
            [!ENDLOOP!]
            [!ENDINDENT!]
        };
    [!ENDLOOP!]
[!ENDINDENT!]

[!MACRO "Spi_CalculatedBaudrate"!]
    [!VAR "SpiClock" = "num:i((node:ref(node:ref(SpiDeviceAssignment)/SpiCpuClockRef)/McuClockReferencePointFrequency))"!]
    [!VAR "OptimalBaudrate" = "$DesiredBaudrate"!]
    [!VAR "OptimalPrescaler" = "0"!]
    [!VAR "OptimalScaler" = "0"!]
    [!VAR "AbsoluteBaudrateMin" = "num:i($SpiClock)"!]
    [!FOR "Prescaler_Count" = "0" TO "3"!]
        [!IF "$Prescaler_Count = 0"!]
            [!VAR "Prescaler" = "2"!]
        [!ELSE!]
            [!VAR "Prescaler" = "$Prescaler_Count * 2 + 1"!]
        [!ENDIF!]
        [!FOR "Scaler_Count" = "0" TO "15"!]
            [!IF "$Scaler_Count < 4"!]
                [!VAR "Scaler" = "($Scaler_Count + 1) * 2"!]
            [!ELSE!]
                [!VAR "Scaler" = "$Scaler * 2"!]
            [!ENDIF!]
            [!VAR "CalculatedBaudrate" = "$SpiClock div ($Prescaler * $Scaler)"!]
            [!IF "$CalculatedBaudrate > $OptimalBaudrate"!]
                [!VAR "AbsoluteBaudrate" = "num:i($CalculatedBaudrate - $OptimalBaudrate)"!]
            [!ELSE!]
                [!VAR "AbsoluteBaudrate" = "num:i($OptimalBaudrate - $CalculatedBaudrate)"!]
            [!ENDIF!]
            [!IF "$AbsoluteBaudrate < $AbsoluteBaudrateMin"!]
                [!VAR "AbsoluteBaudrateMin" = "$AbsoluteBaudrate"!]
                [!VAR "OptimalPrescaler" = "$Prescaler_Count"!]
                [!VAR "OptimalScaler" = "$Scaler_Count"!]
                [!VAR "RealBaudRate" = "$CalculatedBaudrate"!]
            [!ENDIF!]

        [!ENDFOR!]
    [!ENDFOR!]
[!ENDMACRO!]

[!MACRO "Spi_CalculatedCSC"!]
    [!VAR "OptimalDesCSC" = "$DesiredCSC"!]
    [!VAR "OptimalPCSC" = "0"!]
    [!VAR "OptimalCSC" = "0"!]
    [!VAR "AbsoluteCSCMin" = "num:i($OptimalDesCSC)"!]
    [!FOR "PCSC_Count" = "0" TO "3"!]
        [!VAR "PCSC" = " ($PCSC_Count * 2 + 1)"!]
        [!FOR "CSC_Count" = "0" TO "15"!]
            [!IF "$CSC_Count < 1"!]
                [!VAR "CSC" = "num:i(2)"!]
            [!ELSE!]
                [!VAR "CSC" = "$CSC * num:i(2)"!]
            [!ENDIF!]
            [!VAR "CalculatedCSC" = "num:i($PCSC * $CSC)"!]
            [!IF "$CalculatedCSC > $OptimalDesCSC"!]
                [!VAR "AbsoluteCSC" = "num:i($CalculatedCSC - $OptimalDesCSC)"!]
            [!ELSE!]
                [!VAR "AbsoluteCSC" = "num:i($OptimalDesCSC - $CalculatedCSC)"!]
            [!ENDIF!]
            [!IF "$AbsoluteCSC < $AbsoluteCSCMin"!]
                [!VAR "AbsoluteCSCMin" = "$AbsoluteCSC"!]
                [!VAR "OptimalPCSC" = "$PCSC_Count"!]
                [!VAR "OptimalCSC" = "$CSC_Count"!]
                [!VAR "RealCSC" = "$CalculatedCSC"!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
[!ENDMACRO!]

[!MACRO "Spi_CalculatedASC"!]
    [!VAR "OptimalDesASC" = "$DesiredASC"!]
    [!VAR "OptimalPASC" = "0"!]
    [!VAR "OptimalASC" = "0"!]
    [!VAR "AbsoluteASCMin" = "num:i($OptimalDesASC)"!]
    [!FOR "PASC_Count" = "0" TO "3"!]
        [!VAR "PASC" = " ($PASC_Count * 2 + 1)"!]
        [!FOR "ASC_Count" = "0" TO "15"!]
            [!IF "$ASC_Count < 1"!]
                [!VAR "ASC" = "num:i(2)"!]
            [!ELSE!]
                [!VAR "ASC" = "$ASC * num:i(2)"!]
            [!ENDIF!]
            [!VAR "CalculatedASC" = "num:i($PASC * $ASC)"!]
            [!IF "$CalculatedASC > $OptimalDesASC"!]
                [!VAR "AbsoluteASC" = "num:i($CalculatedASC - $OptimalDesASC)"!]
            [!ELSE!]
                [!VAR "AbsoluteASC" = "num:i($OptimalDesASC - $CalculatedASC)"!]
            [!ENDIF!]
            [!IF "$AbsoluteASC < $AbsoluteASCMin"!]
                [!VAR "AbsoluteASCMin" = "$AbsoluteASC"!]
                [!VAR "OptimalPASC" = "$PASC_Count"!]
                [!VAR "OptimalASC" = "$ASC_Count"!]
                [!VAR "RealASC" = "$CalculatedASC"!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
[!ENDMACRO!]

[!MACRO "Spi_CalculatedDT"!]
    [!VAR "OptimalDesDT" = "$DesiredDT"!]
    [!VAR "OptimalPDT" = "0"!]
    [!VAR "OptimalDT" = "0"!]
    [!VAR "AbsoluteDTMin" = "num:i($OptimalDesDT)"!]
    [!FOR "PDT_Count" = "0" TO "3"!]
        [!VAR "PDT" = " ($PDT_Count * 2 + 1)"!]
        [!FOR "DT_Count" = "0" TO "15"!]
            [!IF "$DT_Count < 1"!]
                [!VAR "DT" = "num:i(2)"!]
            [!ELSE!]
                [!VAR "DT" = "$DT * num:i(2)"!]
            [!ENDIF!]
            [!VAR "CalculatedDT" = "num:i($PDT * $DT)"!]
            [!IF "$CalculatedDT > $OptimalDesDT"!]
                [!VAR "AbsoluteDT" = "num:i($CalculatedDT - $OptimalDesDT)"!]
            [!ELSE!]
                [!VAR "AbsoluteDT" = "num:i($OptimalDesDT - $CalculatedDT)"!]
            [!ENDIF!]
            [!IF "$AbsoluteDT < $AbsoluteDTMin"!]
                [!VAR "AbsoluteDTMin" = "$AbsoluteDT"!]
                [!VAR "OptimalPDT" = "$PDT_Count"!]
                [!VAR "OptimalDT" = "$DT_Count"!]
                [!VAR "RealDT" = "$CalculatedDT"!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
[!ENDMACRO!]

[!INDENT "0"!]
static CONST(Spi_JobCfgType, SPI_CONST) SpiJobConfiguration[SPI_TOTAL_JOB] = 
{
    [!INDENT "4"!]
    [!LOOP "SpiDriver/SpiJob/*"!]
    {   [!NOCODE!]
        [!VAR "DesiredBaudrate" = "num:i(node:ref(SpiDeviceAssignment)/SpiBaudrate)"!]
        [!CALL "Spi_CalculatedBaudrate"!] 
        [!VAR "DesiredCSC" = "num:i(node:ref(SpiDeviceAssignment)/CSC)"!]
        [!CALL "Spi_CalculatedCSC"!]
        [!VAR "DesiredASC" = "num:i(node:ref(SpiDeviceAssignment)/ASC)"!]
        [!CALL "Spi_CalculatedASC"!]
        [!VAR "DesiredDT" = "num:i(node:ref(SpiDeviceAssignment)/DT)"!]
        [!CALL "Spi_CalculatedDT"!]
        [!ENDNOCODE!]

        [!INDENT "8"!]
        .JobId = [!"num:i(SpiJobId)"!]U,
        .HwUnit = [!"node:ref(SpiDeviceAssignment)/SpiExtDeviceId"!]U, /* @index */
        .HwDeviceIdx = [!"node:ref(node:ref(SpiDeviceAssignment)/SpiHwUnit)/@index"!]U,
        .HwDevice = [!"text:toupper(node:ref(node:ref(SpiDeviceAssignment)/SpiHwUnit)/SpiHwUnit)"!],
        .CSPin = [!"text:toupper(node:ref(SpiDeviceAssignment)/SpiCsIdentifier)"!],
        .CSFunc = [!"text:toupper(node:ref(SpiDeviceAssignment)/SpiEnableCs)"!],
        .CSPolarity = [!"text:toupper(node:ref(SpiDeviceAssignment)/SpiCsPolarity)"!],
        .CSCountinue = [!IF "SpiCSCountinue = 'true'"!]0x8000U[!ELSE!]0U[!ENDIF!],
        .ClockPolarity = [!"text:toupper(node:ref(SpiDeviceAssignment)/SpiShiftClockIdleLevel)"!],
        .ClockShift = [!"text:toupper(node:ref(SpiDeviceAssignment)/SpiDataShiftEdge)"!],
        .Ctar = (uint32)( /* Real Frequency [!"num:i($RealBaudRate)"!] Hz */ /* CSC = [!"num:i($RealCSC)"!] */ /* ASC = [!"num:i($RealASC)"!] */ /* DT = [!"num:i($RealDT)"!] */ 
            [!INDENT "12"!]
            /* Prescaler */   ([!"num:i($OptimalPrescaler)"!]U << 16U) 
            /* Scaler */    | ([!"num:i($OptimalScaler)"!]U << 0U)
            /* PCSSCK */    | ([!"num:i($OptimalPCSC)"!]U << 22U)
            /* CSSCK */     | ([!"num:i($OptimalCSC)"!]U << 12U)
            /* PASC */      | ([!"num:i($OptimalPASC)"!]U << 20U)
            /* ASC */       | ([!"num:i($OptimalASC)"!]U << 8U)
            /* PDT */       | ([!"num:i($OptimalPDT)"!]U << 18U)
            /* DT */        | ([!"num:i($OptimalDT)"!]U << 4U) ),
            [!ENDINDENT!]
        .CtarSel = [!"text:toupper(node:ref(SpiDeviceAssignment)/SpiCtarSel)"!]U,
        .SpiJobPriority = [!"num:i(SpiJobPriority)"!]U,
        [!IF "(SpiJobEndNotification != '') and (SpiJobEndNotification != 'NULL_PTR') and (SpiJobEndNotification != 'NULL')"!]
            .JobEndNotification = &[!"SpiJobEndNotification"!],
        [!ELSE!]
            .JobEndNotification = NULL_PTR,
        [!ENDIF!]
        .NoOfChannels = [!"num:i(count(SpiChannelList/*))"!]U,
        .ChannelList = [!"@name"!]_ChannelList,
        [!IF "../../../SpiGeneral/SpiGlobalDmaEnable = 'true'"!]
        .JobDmaEn = [!IF "node:exists(node:ref(node:ref(SpiDeviceAssignment)/SpiHwUnit)/SpiTxDmaChannel) and node:exists(node:ref(node:ref(SpiDeviceAssignment)/SpiHwUnit)/SpiRxDmaChannel)"!]
                        [!IF "SpiJobDmaUse = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!]
                    [!ELSE!]
                    FALSE
                    [!ENDIF!],
        [!ENDIF!]
        [!ENDINDENT!]
    },
    [!ENDLOOP!]
    [!ENDINDENT!]
};
[!ENDINDENT!]

[!INDENT "0"!]
    [!LOOP "SpiDriver/SpiSequence/*"!]
        static CONST(Spi_JobType, SPI_CONST) [!"node:name(.)"!]_JobList[[!"num:i(count(./SpiJobAssignment/*))"!]] = 
        {
            [!INDENT "4"!]
            [!LOOP "SpiJobAssignment/*"!]
                [!VAR "temp_index" = "num:i(0)"!]
                [!VAR "temp_hasjob" = "num:i(0)"!]
                [!VAR "temp_name" = "name(node:ref(.))"!]
                [!LOOP "../../../../SpiJob/*"!]
                    [!IF "$temp_name = @name"!]
                        [!VAR "temp_index" = "num:i(@index)"!]
                        [!VAR "temp_hasjob" = "num:i(1)"!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!IF "$temp_hasjob = num:i(0)"!]
                    [!ERROR!] There's no Job we're looking for [!ENDERROR!]
                [!ELSE!]
                    [!"$temp_index"!]U,
                [!ENDIF!]
            [!ENDLOOP!]
            [!ENDINDENT!]
        };
    [!ENDLOOP!]
[!ENDINDENT!]

[!INDENT "0"!]
static CONST(Spi_SequenceCfgType, SPI_CONST) SpiSequenceConfiguration[SPI_TOTAL_SEQUENCE] =
{
    [!IF "num:i(SpiDriver/SpiMaxSequence) != num:i(count(SpiDriver/SpiSequence/*))"!]
        [!ERROR!] SpiMaxSequence count error, please correct [!ENDERROR!]
    [!ENDIF!]
    [!LOOP "SpiDriver/SpiSequence/*"!]
        [!INDENT "4"!]
        {
            [!INDENT "8"!]
            /* SpiSequence_[!"@index"!] */
            .SequenceId = [!"num:i(SpiSequenceId)"!]U,
            [!IF "../../../SpiGeneral/SpiInterruptibleSeqAllowed = 'true'"!]
                [!IF "SpiInterruptibleSequence = 'true'"!]
                    .InterruptableSequence = TRUE,
                [!ENDIF!]
            [!ELSE!]
                .InterruptableSequence = FALSE,
            [!ENDIF!]
            .NoOfJobs = [!"num:i(count(./SpiJobAssignment/*))"!]U,
            .JobList = [!"node:name(.)"!]_JobList,
            [!IF "node:exists(SpiSeqEndNotification)"!]
                [!IF "(SpiSeqEndNotification != '') and (SpiSeqEndNotification != 'NULL_PTR') and (SpiSeqEndNotification != 'NULL')"!]
                    .SequenceEndNotification = &[!"SpiSeqEndNotification"!],
                [!ELSE!]
                    .SequenceEndNotification = NULL_PTR,
                [!ENDIF!]
            [!ELSE!]
                .SequenceEndNotification = NULL_PTR,
            [!ENDIF!]
            [!ENDINDENT!]
        },
        [!ENDINDENT!]
    [!ENDLOOP!]
};
[!ENDINDENT!]

[!INDENT "0"!]
static CONST(Spi_HwUnitCfgType, SPI_CONST) Spi_HwConfiguration[SPI_TOTAL_HWUNIT] = 
{
    [!INDENT "4"!]
    [!LOOP "SpiDriver/SpiExternalDevice/*"!]
    {
        [!INDENT "8"!]
        .HwDeviceIdx = [!"num:i(node:ref(SpiHwUnit)/@index)"!],
        .HwDevice = [!"text:toupper(node:ref(SpiHwUnit)/SpiHwUnit)"!]
        [!ENDINDENT!]
    },
    [!ENDLOOP!]
    [!ENDINDENT!]
};
[!ENDINDENT!]


[!INDENT "0"!]
static CONST(Spi_HwDeviceCfgType, SPI_CONST) Spi_HwDeviceConfiguration[SPI_TOTAL_HWUNIT] = 
{
    [!INDENT "4"!]
    [!LOOP "SpiDriver/SpiHardWare/*"!]
    {
        [!INDENT "8"!]
        .HwIdx = [!"num:i(@index)"!],
        .HwDevice = [!"text:toupper(SpiHwUnit)"!],
        [!IF "../../../SpiGeneral/SpiGlobalDmaEnable = 'true'"!]
        [!IF "node:exists(node:refs(SpiTxDmaChannel))"!]
        .Spi_TxDmaChannelID = [!"node:fallback(node:refs(SpiTxDmaChannel)/eDmaChannelId, 'EDMA_CHN0_NUMBER')"!],
        [!ENDIF!]
        [!IF "node:exists(node:refs(SpiRxDmaChannel))"!]
        .Spi_RxDmaChannelID = [!"node:fallback(node:refs(SpiRxDmaChannel)/eDmaChannelId, 'EDMA_CHN0_NUMBER')"!],
        [!ENDIF!]
        [!ENDIF!]
        [!ENDINDENT!]
    },
    [!ENDLOOP!]
    [!ENDINDENT!]
};
[!ENDINDENT!]




static CONST(uint8, SPI_CONST) Spi_DeviceMap[] =
{
[!NOCODE!][!VAR "SpiDevCnt" = "num:i(count(SpiDriver/SpiExternalDevice/*))"!]
[!LOOP "SpiDriver/SpiExternalDevice/*"!]
[!CODE!]    (uint8)([!ENDCODE!][!IF "num:i(count(SpiDeviceEcucPartitionRef/*)) = num:i(0)"!]
    [!CODE!]2U[!ENDCODE!]
    [!ELSE!]
        [!LOOP "SpiDeviceEcucPartitionRef/*"!]
            [!VAR "PartitionVal" = "node:value(.)"!]
            [!IF "num:i(count(as:modconf('Os')[1]/OsApplication/*)) = num:i(0)"!]
                [!ERROR!]  ASPath:/Os/Os/OsApplication is not configured [!ENDERROR!]
            [!ELSE!]
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                    [!IF "node:value(./OsAppEcucPartitionRef/*[1]) = $PartitionVal"!]
                        [!CODE!][!"num:i(node:ref(./OsApplicationCoreRef/*[1])/EcucCoreId)"!]U[!ENDCODE!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!][!CODE!])[!ENDCODE!][!IF "@index != $SpiDevCnt - num:i(1)"!][!CODE!],[!ENDCODE!][!ENDIF!]
[!CODE!]

[!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]
};

CONST(Spi_ConfigType, SPI_CONST) Spi_Configuration = 
{
    .SequenceNum = [!"num:i(count(SpiDriver/SpiChannel/*))"!]U,
    .JobNum = [!"num:i(count(SpiDriver/SpiJob/*))"!]U,
    .ChannelNum = [!"num:i(count(SpiDriver/SpiSequence/*))"!]U,
    .HwUnitNum = [!"num:i(count(SpiDriver/SpiExternalDevice/*))"!]U,
    .HwDeviceNum = [!"num:i(count(SpiDriver/SpiHardWare/*))"!]U,
    .ChannelConfiguration = SpiChannelConfiguration,
    .JobConfiguration = SpiJobConfiguration,
    .SequenceConfiguration = SpiSequenceConfiguration,
    .HwConfiguration = Spi_HwConfiguration,
    .HwDeviceConfiguration = Spi_HwDeviceConfiguration,
    .DeviceMap = Spi_DeviceMap
};

CONST(uint32, SPI_CONST) Spi_HandleMap[22U] = 
{
[!INDENT "4"!]
[!FOR "ForIdx" = "0" TO "21"!]
    [!VAR "SpiHwCfgIdx" = "num:i(22)"!]
    [!LOOP "SpiDriver/SpiHardWare/*"!]
        [!VAR "TargetDevice" = "SpiHwUnit"!]
        [!VAR "TargetIdx" = "num:i(0)"!]
        [!VAR "LoopIdx" = "num:i(0)"!]
        [!LOOP "text:split('DSPI0,DSPI1,DSPI2,DSPI3,DSPI4,DSPI5,DSPI6,DSPI7,DSPI8,DSPI9,DSPI10,DSPI11,DSPI12,DSPI13,DSPI14,DSPI15,DSPI16,DSPI17,DSPI18,DSPI19,DSPI20,DSPI21', ',')"!]
            [!IF "$TargetDevice = node:current()"!]
                [!VAR "TargetIdx" = "num:i($LoopIdx)"!]
            [!ENDIF!]
            [!VAR "LoopIdx" = "num:i($LoopIdx) + num:i(1)"!]
        [!ENDLOOP!]
        [!IF "$ForIdx = $TargetIdx"!]
            [!VAR "SpiHwCfgIdx" = "num:i(@index)"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!"num:i($SpiHwCfgIdx)"!]U,
[!ENDFOR!]
[!ENDINDENT!]
};

#define SPI_STOP_SEC_CONFIG_DATA
#include "Spi_MemMap.h"



#ifdef __cplusplus
}
#endif
