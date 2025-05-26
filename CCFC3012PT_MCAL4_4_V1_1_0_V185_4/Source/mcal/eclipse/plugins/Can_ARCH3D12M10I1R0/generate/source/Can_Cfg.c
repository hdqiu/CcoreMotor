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

[!AUTOSPACING!]
[!SELECT "CanConfigSet"!]
[!NOCODE!]
[!VAR "HardwareObjectCnt" = "0"!]
[!LOOP "CanHardwareObject/*"!]
    [!VAR "HardwareObjectCnt" = "$HardwareObjectCnt + num:i(1)"!]
[!ENDLOOP!]
[!ENDNOCODE!]
[!ENDSELECT!]
[!VAR "MacOuterLoopCounter" = "0"!]
[!VAR "MacInnerLoopCounter" = "0"!]
[!LOOP "CanConfigSet/CanController/*"!]
    [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "MacMatchcounter" = "0"!]
    [!VAR "MacNotification" = "CanMRAFNotification"!]
    [!LOOP "../../CanController/*"!]
        [!IF "(normalize-space(CanMRAFNotification) != 'NULL_PTR')"!]
            [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
            [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                [!IF "($MacNotification = CanMRAFNotification)"!]
                    [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$MacMatchcounter = 1"!]
        [!CODE!]
extern FUNC(void,CAN_CODE) [!"normalize-space(CanMRAFNotification)"!](VAR(uint8, AUTOMATIC) u8Can_ControllerId);
        [!ENDCODE!]
    [!ENDIF!]
[!ENDLOOP!]
[!VAR "MacOuterLoopCounter" = "0"!]
[!VAR "MacInnerLoopCounter" = "0"!]
[!LOOP "CanConfigSet/CanController/*"!]
     [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "MacMatchcounter" = "0"!]
    [!IF "CanErrorControllerNotifEn = 'true'"!]
        [!VAR "MacNotification" = "CanErrorControllerNotification"!]
    [!ENDIF!] 
    [!LOOP "../../CanController/*"!]
         [!IF "CanErrorControllerNotifEn = 'true'"!]
            [!IF "(normalize-space(CanErrorControllerNotification) != 'NULL_PTR')"!]
                [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                    [!IF "($MacNotification = CanErrorControllerNotification)"!]
                        [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$MacMatchcounter = 1"!]
        [!IF "CanErrorControllerNotifEn = 'true'"!][!CODE!]
extern FUNC(void,CAN_CODE) [!"normalize-space(CanErrorControllerNotification)"!](VAR(uint8, AUTOMATIC) u8Can_ControllerId);
        [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!NOCODE!]
[!VAR "mcan1_mb_rx_index" = "0"!]
[!VAR "mcan1_mb_tx_index" = "0"!]
[!VAR "mcan2_mb_rx_index" = "0"!]
[!VAR "mcan2_mb_tx_index" = "0"!]
[!VAR "mcan3_mb_rx_index" = "0"!]
[!VAR "mcan3_mb_tx_index" = "0"!]
[!VAR "mcan4_mb_rx_index" = "0"!]
[!VAR "mcan4_mb_tx_index" = "0"!]
[!VAR "mcan5_mb_rx_index" = "0"!]
[!VAR "mcan5_mb_tx_index" = "0"!]
[!VAR "mcan6_mb_rx_index" = "0"!]
[!VAR "mcan6_mb_tx_index" = "0"!]
[!VAR "mcan7_mb_rx_index" = "0"!]
[!VAR "mcan7_mb_tx_index" = "0"!]
[!VAR "mcan8_mb_rx_index" = "0"!]
[!VAR "mcan8_mb_tx_index" = "0"!]
[!VAR "mcan9_mb_rx_index" = "0"!]
[!VAR "mcan9_mb_tx_index" = "0"!]
[!VAR "mcan10_mb_rx_index" = "0"!]
[!VAR "mcan10_mb_tx_index" = "0"!]
[!VAR "mcan11_mb_rx_index" = "0"!]
[!VAR "mcan11_mb_tx_index" = "0"!]
[!VAR "mcan12_mb_rx_index" = "0"!]
[!VAR "mcan12_mb_tx_index" = "0"!]
[!VAR "mb_rx_index" = "0"!]
[!VAR "mb_tx_index" = "0"!]
[!VAR "mcan1_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan2_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan3_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan4_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan5_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan6_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan7_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan8_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan9_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan10_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan11_buffer_transmission_ir_mask" = "num:i(0)"!]
[!VAR "mcan12_buffer_transmission_ir_mask" = "num:i(0)"!]
[!ENDNOCODE!]
[!INDENT "0"!]
[!SELECT "CanConfigSet"!]
static CONST(mcan_hwObject, CAN_CONST) Mcan_HardWareObjConfigs[CAN_MB_COUNT] = 
{
    [!LOOP "CanHardwareObject/*"!]
        [!IF "node:ref(CanControllerRef)/CanHwChannel = 'MCAN_1'"!]
            [!VAR "mb_rx_index" = "$mcan1_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan1_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_2'"!]
            [!VAR "mb_rx_index" = "$mcan2_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan2_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_3'"!]
            [!VAR "mb_rx_index" = "$mcan3_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan3_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_4'"!]
            [!VAR "mb_rx_index" = "$mcan4_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan4_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_5'"!]
            [!VAR "mb_rx_index" = "$mcan5_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan5_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_6'"!]
            [!VAR "mb_rx_index" = "$mcan6_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan6_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_7'"!]
            [!VAR "mb_rx_index" = "$mcan7_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan7_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_8'"!]
            [!VAR "mb_rx_index" = "$mcan8_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan8_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_9'"!]
            [!VAR "mb_rx_index" = "$mcan9_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan9_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_10'"!]
            [!VAR "mb_rx_index" = "$mcan10_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan10_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_11'"!]
            [!VAR "mb_rx_index" = "$mcan11_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan11_mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_12'"!]
            [!VAR "mb_rx_index" = "$mcan12_mb_rx_index"!]
            [!VAR "mb_tx_index" = "$mcan12_mb_tx_index"!]
        [!ENDIF!]
        [!IF "CanObjectType = 'TRANSMIT' and CanStoreMB != 'BUFFER'"!]
            [!ERROR!] CanObjectId = [!"num:i(CanObjectId)"!]. Please Set CanStoreMB to BUFFER when CanObjectType is TRANSMIT [!ENDERROR!]
        [!ENDIF!]
        [!IF "num:i(CanHwObjectCount) > num:i(1) and CanStoreMB != 'BUFFER'"!]
            [!ERROR!] CanObjectId = [!"num:i(CanObjectId)"!]. Please Set CanHwObjectCount to '1' when CanStoreMB is FIFO_0 or FIFO_1 [!ENDERROR!]
        [!ENDIF!]
        [!IF "CanStoreMB = 'FIFO_0' or CanStoreMB = 'FIFO_1'"!]
            [!IF "num:i(count(node:ref(CanControllerRef)/CanRxFifo/*)) = num:i(0)"!]
                [!ERROR!] CanObjectId = [!"num:i(CanObjectId)"!]. Please Set CanStoreMB to BUFFER when CanRxFifo is empty [!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "CanStoreMB = 'FIFO_0'"!]
            [!IF "node:ref(CanControllerRef)/CanRxFifo/*[1]/ReceiveFifo != 'FIFO_0' and node:ref(CanControllerRef)/CanRxFifo/*[1]/ReceiveFifo != 'FIFO_0_1'"!]
                [!ERROR!] CanObjectId = [!"num:i(CanObjectId)"!]. The current controller does not support FIFO 0 [!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "CanStoreMB = 'FIFO_1'"!]
            [!IF "node:ref(CanControllerRef)/CanRxFifo/*[1]/ReceiveFifo != 'FIFO_1' and node:ref(CanControllerRef)/CanRxFifo/*[1]/ReceiveFifo != 'FIFO_0_1'"!]
                [!ERROR!] CanObjectId = [!"num:i(CanObjectId)"!]. The current controller does not support FIFO 1 [!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
        [!FOR "i" = "0" TO "num:i(CanHwObjectCount) - 1"!]
        [!INDENT "4"!]
            {
            [!INDENT "8"!]
                .CanObjectId = [!"num:i(CanObjectId)"!]U,
            [!SELECT "node:ref(CanControllerRef)"!]
                .CanControllerId = (uint32)[!"num:i(CanControllerId)"!]U,
            [!ENDSELECT!]
            [!IF "CanIdType = 'STANDARD'"!]
                .CanIdType = STANDARD_ID,
            [!ELSEIF "CanIdType ='EXTENDED'"!]
                .CanIdType = EXTENDED_ID,
            [!ELSE!]
                .CanIdType = STD_AND_EXT_ID,
            [!ENDIF!]
            [!IF "CanStoreMB = 'FIFO_0'"!]
                .mbIdex = MCAN_STORE_RX_FIFO0,
            [!ELSEIF "CanStoreMB ='FIFO_1'"!]
                .mbIdex = MCAN_STORE_RX_FIFO1,
            [!ELSE!]
                [!IF "CanObjectType = 'TRANSMIT'"!]
                    .mbIdex = [!"num:i($mb_tx_index)"!]U,
                    [!IF "CanHardwareObjectUsesPolling = 'false'"!]
                        [!IF "node:ref(CanControllerRef)/CanHwChannel = 'MCAN_1'"!]
                            [!VAR "mcan1_buffer_transmission_ir_mask" = "num:i(bit:or($mcan1_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_2'"!]
                            [!VAR "mcan2_buffer_transmission_ir_mask" = "num:i(bit:or($mcan2_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_3'"!]
                            [!VAR "mcan3_buffer_transmission_ir_mask" = "num:i(bit:or($mcan3_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_4'"!]
                            [!VAR "mcan4_buffer_transmission_ir_mask" = "num:i(bit:or($mcan4_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_5'"!]
                            [!VAR "mcan5_buffer_transmission_ir_mask" = "num:i(bit:or($mcan5_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_6'"!]
                            [!VAR "mcan6_buffer_transmission_ir_mask" = "num:i(bit:or($mcan6_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_7'"!]
                            [!VAR "mcan7_buffer_transmission_ir_mask" = "num:i(bit:or($mcan7_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_8'"!]
                            [!VAR "mcan8_buffer_transmission_ir_mask" = "num:i(bit:or($mcan8_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_9'"!]
                            [!VAR "mcan9_buffer_transmission_ir_mask" = "num:i(bit:or($mcan9_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_10'"!]
                            [!VAR "mcan10_buffer_transmission_ir_mask" = "num:i(bit:or($mcan10_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_11'"!]
                            [!VAR "mcan11_buffer_transmission_ir_mask" = "num:i(bit:or($mcan11_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_12'"!]
                            [!VAR "mcan12_buffer_transmission_ir_mask" = "num:i(bit:or($mcan12_buffer_transmission_ir_mask,bit:shl(num:i(1),num:i($mb_tx_index))))"!]
                        [!ENDIF!]
                    [!ENDIF!]
                    [!VAR "mb_tx_index" = "$mb_tx_index + 1"!]
                [!ELSE!]
                    .mbIdex = [!"num:i($mb_rx_index)"!]U,
                    [!VAR "mb_rx_index" = "$mb_rx_index + 1"!]
                [!ENDIF!]
            [!ENDIF!]
                .mbPayloadLength = (uint32)[!"substring-before(substring-after(node:value(node:ref(./CanControllerRef)/CanPayloadLength),'_'),'_')"!]U,
            [!IF "CanHardwareObjectUsesPolling = 'true'"!]
                [!IF "CanObjectType = 'TRANSMIT'"!]
                    [!IF "node:ref(./CanControllerRef)/CanTxProcessing = 'INTERRUPT'"!]
                        [!ERROR!] CanObjectId = [!"num:i(CanObjectId)"!]. The current controller does not support polling sending [!ENDERROR!]
                    [!ENDIF!]
                    [!IF "node:ref(./CanControllerRef)/CanTxProcessing != 'INTERRUPT'"!]
                        .isPolling = 1U,
                    [!ELSE!]
                        .isPolling = 0U,
                    [!ENDIF!]
                [!ELSE!]
                    [!IF "node:ref(./CanControllerRef)/CanRxProcessing = 'INTERRUPT'"!]
                        [!ERROR!] CanObjectId = [!"num:i(CanObjectId)"!]. The current controller does not support cyclic receiving [!ENDERROR!]
                    [!ENDIF!]
                    [!IF "node:ref(./CanControllerRef)/CanRxProcessing != 'INTERRUPT'"!]
                        .isPolling = 1U,
                    [!ELSE!]
                        .isPolling = 0U,
                    [!ENDIF!]
                [!ENDIF!]
            [!ELSE!]
                .isPolling = 0U,
            [!ENDIF!]
            [!IF "CanObjectType = 'TRANSMIT'"!]
                .CanObjectType = TRANSMIT,
            [!ELSE!]
                .CanObjectType = RECEIVE,
            [!ENDIF!]
            .CanFdPaddingValue = [!"num:inttohex(CanFdPaddingValue,2)"!]U,
            [!IF "node:refexists(CanMainFunctionRWPeriodRef)"!]
                [!SELECT "node:ref(CanMainFunctionRWPeriodRef)"!]
                    .PeriodIndex = [!"num:i(@index)"!]U,
                [!ENDSELECT!]
            [!ELSE!]
                .PeriodIndex = 0U,
            [!ENDIF!]
            [!IF "num:i(count(CanHwFilter/*)) != num:i(0)"!]
                .filterType = [!"CanHwFilter/*[1]/CanFilterType"!],
                .filterCode = [!"num:inttohex(CanHwFilter/*[1]/CanHwFilterCode, 8)"!]U,
                .filterMask = [!"num:inttohex(CanHwFilter/*[1]/CanHwFilterMask, 8)"!]U,
            [!ELSE!]
                .filterType = FILTER_TYPE_CLASIC,
                .filterCode = 0x0U,
                .filterMask = 0x0U,
            [!ENDIF!]
            [!ENDINDENT!]
            },
        [!ENDINDENT!]
        [!IF "node:ref(CanControllerRef)/CanHwChannel = 'MCAN_1'"!]
            [!VAR "mcan1_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan1_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_2'"!]
            [!VAR "mcan2_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan2_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_3'"!]
            [!VAR "mcan3_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan3_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_4'"!]
            [!VAR "mcan4_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan4_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_5'"!]
            [!VAR "mcan5_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan5_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_6'"!]
            [!VAR "mcan6_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan6_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_7'"!]
            [!VAR "mcan7_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan7_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_8'"!]
            [!VAR "mcan8_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan8_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_9'"!]
            [!VAR "mcan9_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan9_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_10'"!]
            [!VAR "mcan10_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan10_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_11'"!]
            [!VAR "mcan11_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan11_mb_tx_index" = "$mb_tx_index"!]
        [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_12'"!]
            [!VAR "mcan12_mb_rx_index" = "$mb_rx_index"!]
            [!VAR "mcan12_mb_tx_index" = "$mb_tx_index"!]
        [!ENDIF!]
        [!ENDFOR!]
    [!ENDLOOP!]
    [!IF "$mcan1_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN1 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan1_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN1 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan2_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN2 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan2_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN2 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan3_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN3 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan3_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN3 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan4_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN4 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan4_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN4 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan5_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN5 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan5_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN5 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan6_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN6 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan6_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN6 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan7_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN7 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan7_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN7 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan8_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN8 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan8_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN8 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan9_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN9 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan9_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN9 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan10_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN10 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan10_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN10 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan11_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN11 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan11_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN11 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan12_mb_rx_index > num:i(ecu:get('MCan.rxMbMax'))"!]
        [!ERROR!] MCAN12 RX MB number is over [!"num:i(ecu:get('MCan.rxMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan12_mb_tx_index > num:i(ecu:get('MCan.txMbMax'))"!]
        [!ERROR!] MCAN12 TX MB number is over [!"num:i(ecu:get('MCan.txMbMax'))"!] [!ENDERROR!]
    [!ENDIF!]
};
[!ENDSELECT!]
[!ENDINDENT!]
[!NOCODE!]
[!VAR "mcan1_is_used" = "num:i(0)"!]
[!VAR "mcan2_is_used" = "num:i(0)"!]
[!VAR "mcan3_is_used" = "num:i(0)"!]
[!VAR "mcan4_is_used" = "num:i(0)"!]
[!VAR "mcan5_is_used" = "num:i(0)"!]
[!VAR "mcan6_is_used" = "num:i(0)"!]
[!VAR "mcan7_is_used" = "num:i(0)"!]
[!VAR "mcan8_is_used" = "num:i(0)"!]
[!VAR "mcan9_is_used" = "num:i(0)"!]
[!VAR "mcan10_is_used" = "num:i(0)"!]
[!VAR "mcan11_is_used" = "num:i(0)"!]
[!VAR "mcan12_is_used" = "num:i(0)"!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]
        [!IF "CanHwChannel = 'MCAN_1' and $mcan1_is_used = num:i(0)"!]
            [!VAR "mcan1_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_2' and $mcan2_is_used = num:i(0)"!]
            [!VAR "mcan2_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_3' and $mcan3_is_used = num:i(0)"!]
            [!VAR "mcan3_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_4' and $mcan4_is_used = num:i(0)"!]
            [!VAR "mcan4_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_5' and $mcan5_is_used = num:i(0)"!]
            [!VAR "mcan5_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_6' and $mcan6_is_used = num:i(0)"!]
            [!VAR "mcan6_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_7' and $mcan7_is_used = num:i(0)"!]
            [!VAR "mcan7_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_8' and $mcan8_is_used = num:i(0)"!]
            [!VAR "mcan8_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_9' and $mcan9_is_used = num:i(0)"!]
            [!VAR "mcan9_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_10' and $mcan10_is_used = num:i(0)"!]
            [!VAR "mcan10_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_11' and $mcan11_is_used = num:i(0)"!]
            [!VAR "mcan11_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_12' and $mcan12_is_used = num:i(0)"!]
            [!VAR "mcan12_is_used" = "num:i(1)"!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!]
[!NOCODE!]
[!VAR "mcan1_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan2_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan3_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan4_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan5_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan6_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan7_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan8_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan9_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan10_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan11_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan12_RamBase_U32" = "num:i(0)"!]
[!VAR "mcan1_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan2_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan3_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan4_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan5_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan6_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan7_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan8_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan9_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan10_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan11_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan12_RamSize_U32" = "num:i(0)"!]
[!VAR "mcan1_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan2_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan3_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan4_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan5_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan6_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan7_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan8_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan9_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan10_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan11_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan12_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan1_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan2_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan3_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan4_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan5_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan6_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan7_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan8_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan9_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan10_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan11_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan12_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "mcan1_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan2_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan3_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan4_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan5_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan6_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan7_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan8_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan9_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan10_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan11_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan12_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "mcan1_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan2_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan3_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan4_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan5_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan6_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan7_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan8_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan9_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan10_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan11_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan12_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "mcan1_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan2_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan3_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan4_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan5_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan6_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan7_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan8_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan9_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan10_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan11_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan12_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan1_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan2_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan3_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan4_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan5_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan6_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan7_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan8_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan9_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan10_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan11_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan12_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "RAMA_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "RAMA_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "RAMA_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "RAMA_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "RAMA_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "RAMA_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "RAMB_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "RAMB_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "RAMB_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "RAMB_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "RAMB_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "RAMB_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "RAMC_StandardMsg_Cnt" = "num:i(0)"!]
[!VAR "RAMC_ExtendedMsg_Cnt" = "num:i(0)"!]
[!VAR "RAMC_RxFifo0_Cnt" = "num:i(0)"!]
[!VAR "RAMC_RxFifo1_Cnt" = "num:i(0)"!]
[!VAR "RAMC_RxBuffer_Cnt" = "num:i(0)"!]
[!VAR "RAMC_TxBuffer_Cnt" = "num:i(0)"!]
[!VAR "mcan1_RAMA_Base" = "num:i(0)"!]
[!VAR "mcan2_RAMA_Base" = "num:i(0)"!]
[!VAR "mcan3_RAMA_Base" = "num:i(0)"!]
[!VAR "mcan4_RAMA_Base" = "num:i(0)"!]
[!VAR "mcan5_RAMB_Base" = "num:i(0)"!]
[!VAR "mcan6_RAMB_Base" = "num:i(0)"!]
[!VAR "mcan7_RAMB_Base" = "num:i(0)"!]
[!VAR "mcan8_RAMB_Base" = "num:i(0)"!]
[!VAR "mcan9_RAMC_Base" = "num:i(0)"!]
[!VAR "mcan10_RAMC_Base" = "num:i(0)"!]
[!VAR "mcan11_RAMC_Base" = "num:i(0)"!]
[!VAR "mcan12_RAMC_Base" = "num:i(0)"!]
[!VAR "mcan1_RAMA_Size" = "num:i(0)"!]
[!VAR "mcan2_RAMA_Size" = "num:i(0)"!]
[!VAR "mcan3_RAMA_Size" = "num:i(0)"!]
[!VAR "mcan4_RAMA_Size" = "num:i(0)"!]
[!VAR "mcan5_RAMB_Size" = "num:i(0)"!]
[!VAR "mcan6_RAMB_Size" = "num:i(0)"!]
[!VAR "mcan7_RAMB_Size" = "num:i(0)"!]
[!VAR "mcan8_RAMB_Size" = "num:i(0)"!]
[!VAR "mcan9_RAMC_Size" = "num:i(0)"!]
[!VAR "mcan10_RAMC_Size" = "num:i(0)"!]
[!VAR "mcan11_RAMC_Size" = "num:i(0)"!]
[!VAR "mcan12_RAMC_Size" = "num:i(0)"!]

[!VAR "mcan1_Payload_Size" = "num:i(0)"!]
[!VAR "mcan2_Payload_Size" = "num:i(0)"!]
[!VAR "mcan3_Payload_Size" = "num:i(0)"!]
[!VAR "mcan4_Payload_Size" = "num:i(0)"!]
[!VAR "mcan5_Payload_Size" = "num:i(0)"!]
[!VAR "mcan6_Payload_Size" = "num:i(0)"!]
[!VAR "mcan7_Payload_Size" = "num:i(0)"!]
[!VAR "mcan8_Payload_Size" = "num:i(0)"!]
[!VAR "mcan9_Payload_Size" = "num:i(0)"!]
[!VAR "mcan10_Payload_Size" = "num:i(0)"!]
[!VAR "mcan11_Payload_Size" = "num:i(0)"!]
[!VAR "mcan12_Payload_Size" = "num:i(0)"!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanHardwareObject/*"!]
        [!IF "CanObjectType = 'RECEIVE'"!]
            [!IF "node:ref(CanControllerRef)/CanHwChannel = 'MCAN_1'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan1_StandardMsg_Cnt" = "num:i($mcan1_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan1_ExtendedMsg_Cnt" = "num:i($mcan1_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan1_RxBuffer_Cnt" = "num:i($mcan1_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_2'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan2_StandardMsg_Cnt" = "num:i($mcan2_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan2_ExtendedMsg_Cnt" = "num:i($mcan2_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan2_RxBuffer_Cnt" = "num:i($mcan2_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_3'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan3_StandardMsg_Cnt" = "num:i($mcan3_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan3_ExtendedMsg_Cnt" = "num:i($mcan3_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan3_RxBuffer_Cnt" = "num:i($mcan3_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_4'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan4_StandardMsg_Cnt" = "num:i($mcan4_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan4_ExtendedMsg_Cnt" = "num:i($mcan4_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan4_RxBuffer_Cnt" = "num:i($mcan4_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_5'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan5_StandardMsg_Cnt" = "num:i($mcan5_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan5_ExtendedMsg_Cnt" = "num:i($mcan5_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan5_RxBuffer_Cnt" = "num:i($mcan5_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_6'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan6_StandardMsg_Cnt" = "num:i($mcan6_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan6_ExtendedMsg_Cnt" = "num:i($mcan6_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan6_RxBuffer_Cnt" = "num:i($mcan6_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_7'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan7_StandardMsg_Cnt" = "num:i($mcan7_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan7_ExtendedMsg_Cnt" = "num:i($mcan7_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan7_RxBuffer_Cnt" = "num:i($mcan7_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_8'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan8_StandardMsg_Cnt" = "num:i($mcan8_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan8_ExtendedMsg_Cnt" = "num:i($mcan8_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan8_RxBuffer_Cnt" = "num:i($mcan8_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_9'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan9_StandardMsg_Cnt" = "num:i($mcan9_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan9_ExtendedMsg_Cnt" = "num:i($mcan9_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan9_RxBuffer_Cnt" = "num:i($mcan9_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_10'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan10_StandardMsg_Cnt" = "num:i($mcan10_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan10_ExtendedMsg_Cnt" = "num:i($mcan10_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan10_RxBuffer_Cnt" = "num:i($mcan10_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_11'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan11_StandardMsg_Cnt" = "num:i($mcan11_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan11_ExtendedMsg_Cnt" = "num:i($mcan11_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan11_RxBuffer_Cnt" = "num:i($mcan11_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_12'"!]
                [!IF "CanIdType = 'STANDARD'"!]
                    [!VAR "mcan12_StandardMsg_Cnt" = "num:i($mcan12_StandardMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ELSE!]
                    [!VAR "mcan12_ExtendedMsg_Cnt" = "num:i($mcan12_ExtendedMsg_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
                [!IF "CanStoreMB = 'BUFFER'"!]
                    [!VAR "mcan12_RxBuffer_Cnt" = "num:i($mcan12_RxBuffer_Cnt + num:i(CanHwObjectCount))"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "CanObjectType = 'TRANSMIT'"!]
            [!IF "node:ref(CanControllerRef)/CanHwChannel = 'MCAN_1'"!]
                [!VAR "mcan1_TxBuffer_Cnt" = "num:i($mcan1_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_2'"!]
                [!VAR "mcan2_TxBuffer_Cnt" = "num:i($mcan2_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_3'"!]
                [!VAR "mcan3_TxBuffer_Cnt" = "num:i($mcan3_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_4'"!]
                [!VAR "mcan4_TxBuffer_Cnt" = "num:i($mcan4_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_5'"!]
                [!VAR "mcan5_TxBuffer_Cnt" = "num:i($mcan5_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_6'"!]
                [!VAR "mcan6_TxBuffer_Cnt" = "num:i($mcan6_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_7'"!]
                [!VAR "mcan7_TxBuffer_Cnt" = "num:i($mcan7_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_8'"!]
                [!VAR "mcan8_TxBuffer_Cnt" = "num:i($mcan8_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_9'"!]
                [!VAR "mcan9_TxBuffer_Cnt" = "num:i($mcan9_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_10'"!]
                [!VAR "mcan10_TxBuffer_Cnt" = "num:i($mcan10_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_11'"!]
                [!VAR "mcan11_TxBuffer_Cnt" = "num:i($mcan11_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ELSEIF "node:ref(CanControllerRef)/CanHwChannel ='MCAN_12'"!]
                [!VAR "mcan12_TxBuffer_Cnt" = "num:i($mcan12_TxBuffer_Cnt + num:i(CanHwObjectCount))"!]
            [!ENDIF!]
        [!ENDIF!]     
    [!ENDLOOP!]
[!ENDSELECT!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]
        [!IF "num:i(count(CanRxFifo/*)) != num:i(0)"!]
            [!IF "CanHwChannel = 'MCAN_1'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan1_RxFifo0_Cnt" = "num:i($mcan1_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan1_RxFifo1_Cnt" = "num:i($mcan1_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan1_RxFifo0_Cnt" = "num:i($mcan1_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan1_RxFifo1_Cnt" = "num:i($mcan1_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_2'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan2_RxFifo0_Cnt" = "num:i($mcan2_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan2_RxFifo1_Cnt" = "num:i($mcan2_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan2_RxFifo0_Cnt" = "num:i($mcan2_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan2_RxFifo1_Cnt" = "num:i($mcan2_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_3'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan3_RxFifo0_Cnt" = "num:i($mcan3_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan3_RxFifo1_Cnt" = "num:i($mcan3_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan3_RxFifo0_Cnt" = "num:i($mcan3_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan3_RxFifo1_Cnt" = "num:i($mcan3_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_4'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan4_RxFifo0_Cnt" = "num:i($mcan4_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan4_RxFifo1_Cnt" = "num:i($mcan4_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan4_RxFifo0_Cnt" = "num:i($mcan4_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan4_RxFifo1_Cnt" = "num:i($mcan4_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_5'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan5_RxFifo0_Cnt" = "num:i($mcan5_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan5_RxFifo1_Cnt" = "num:i($mcan5_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan5_RxFifo0_Cnt" = "num:i($mcan5_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan5_RxFifo1_Cnt" = "num:i($mcan5_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_6'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan6_RxFifo0_Cnt" = "num:i($mcan6_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan6_RxFifo1_Cnt" = "num:i($mcan6_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan6_RxFifo0_Cnt" = "num:i($mcan6_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan6_RxFifo1_Cnt" = "num:i($mcan6_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_7'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan7_RxFifo0_Cnt" = "num:i($mcan7_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan7_RxFifo1_Cnt" = "num:i($mcan7_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan7_RxFifo0_Cnt" = "num:i($mcan7_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan7_RxFifo1_Cnt" = "num:i($mcan7_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_8'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan8_RxFifo0_Cnt" = "num:i($mcan8_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan8_RxFifo1_Cnt" = "num:i($mcan8_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan8_RxFifo0_Cnt" = "num:i($mcan8_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan8_RxFifo1_Cnt" = "num:i($mcan8_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_9'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan9_RxFifo0_Cnt" = "num:i($mcan9_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan9_RxFifo1_Cnt" = "num:i($mcan9_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan9_RxFifo0_Cnt" = "num:i($mcan9_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan9_RxFifo1_Cnt" = "num:i($mcan9_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_10'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan10_RxFifo0_Cnt" = "num:i($mcan10_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan10_RxFifo1_Cnt" = "num:i($mcan10_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan10_RxFifo0_Cnt" = "num:i($mcan10_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan10_RxFifo1_Cnt" = "num:i($mcan10_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_11'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan11_RxFifo0_Cnt" = "num:i($mcan11_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan11_RxFifo1_Cnt" = "num:i($mcan11_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan11_RxFifo0_Cnt" = "num:i($mcan11_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan11_RxFifo1_Cnt" = "num:i($mcan11_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ELSEIF "CanHwChannel ='MCAN_12'"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    [!VAR "mcan12_RxFifo0_Cnt" = "num:i($mcan12_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    [!VAR "mcan12_RxFifo1_Cnt" = "num:i($mcan12_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ELSE!]
                    [!VAR "mcan12_RxFifo0_Cnt" = "num:i($mcan12_RxFifo0_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                    [!VAR "mcan12_RxFifo1_Cnt" = "num:i($mcan12_RxFifo1_Cnt + num:i(CanRxFifo/*[1]/CanFifoDepth))"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
        [!IF "CanHwChannel = 'MCAN_1'"!]
            [!VAR "mcan1_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_2'"!]
            [!VAR "mcan2_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_3'"!]
            [!VAR "mcan3_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_4'"!]
            [!VAR "mcan4_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_5'"!]
            [!VAR "mcan5_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_6'"!]
            [!VAR "mcan6_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_7'"!]
            [!VAR "mcan7_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_8'"!]
            [!VAR "mcan8_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_9'"!]
            [!VAR "mcan9_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_10'"!]
            [!VAR "mcan10_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_11'"!]
            [!VAR "mcan11_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ELSEIF "CanHwChannel ='MCAN_12'"!]
            [!VAR "mcan12_Payload_Size" = "num:i(substring-before(substring-after(node:value(./CanPayloadLength),'_'),'_'))"!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDSELECT!]
    [!VAR "RAMA_StandardMsg_Cnt" = "num:i($mcan1_StandardMsg_Cnt + $mcan2_StandardMsg_Cnt + $mcan3_StandardMsg_Cnt + $mcan4_StandardMsg_Cnt)"!]
    [!VAR "RAMA_ExtendedMsg_Cnt" = "num:i($mcan1_ExtendedMsg_Cnt + $mcan2_ExtendedMsg_Cnt + $mcan3_ExtendedMsg_Cnt + $mcan4_ExtendedMsg_Cnt)"!]
    [!VAR "RAMA_RxFifo0_Cnt" = "num:i($mcan1_RxFifo0_Cnt + $mcan2_RxFifo0_Cnt + $mcan3_RxFifo0_Cnt + $mcan4_RxFifo0_Cnt)"!]
    [!VAR "RAMA_RxFifo1_Cnt" = "num:i($mcan1_RxFifo1_Cnt + $mcan2_RxFifo1_Cnt + $mcan3_RxFifo1_Cnt + $mcan4_RxFifo1_Cnt)"!]
    [!VAR "RAMA_RxBuffer_Cnt" = "num:i($mcan1_RxBuffer_Cnt + $mcan2_RxBuffer_Cnt + $mcan3_RxBuffer_Cnt + $mcan4_RxBuffer_Cnt)"!]
    [!VAR "RAMA_TxBuffer_Cnt" = "num:i($mcan1_TxBuffer_Cnt + $mcan2_TxBuffer_Cnt + $mcan3_TxBuffer_Cnt + $mcan4_TxBuffer_Cnt)"!]
    [!VAR "RAMB_StandardMsg_Cnt" = "num:i($mcan5_StandardMsg_Cnt + $mcan6_StandardMsg_Cnt + $mcan7_StandardMsg_Cnt + $mcan8_StandardMsg_Cnt)"!]
    [!VAR "RAMB_ExtendedMsg_Cnt" = "num:i($mcan5_ExtendedMsg_Cnt + $mcan6_ExtendedMsg_Cnt + $mcan7_ExtendedMsg_Cnt + $mcan8_ExtendedMsg_Cnt)"!]
    [!VAR "RAMB_RxFifo0_Cnt" = "num:i($mcan5_RxFifo0_Cnt + $mcan6_RxFifo0_Cnt + $mcan7_RxFifo0_Cnt + $mcan8_RxFifo0_Cnt)"!]
    [!VAR "RAMB_RxFifo1_Cnt" = "num:i($mcan5_RxFifo1_Cnt + $mcan6_RxFifo1_Cnt + $mcan7_RxFifo1_Cnt + $mcan8_RxFifo1_Cnt)"!]
    [!VAR "RAMB_RxBuffer_Cnt" = "num:i($mcan5_RxBuffer_Cnt + $mcan6_RxBuffer_Cnt + $mcan7_RxBuffer_Cnt + $mcan8_RxBuffer_Cnt)"!]
    [!VAR "RAMB_TxBuffer_Cnt" = "num:i($mcan5_TxBuffer_Cnt + $mcan6_TxBuffer_Cnt + $mcan7_TxBuffer_Cnt + $mcan8_TxBuffer_Cnt)"!]
    [!VAR "RAMC_StandardMsg_Cnt" = "num:i($mcan9_StandardMsg_Cnt + $mcan10_StandardMsg_Cnt + $mcan11_StandardMsg_Cnt + $mcan12_StandardMsg_Cnt)"!]
    [!VAR "RAMC_ExtendedMsg_Cnt" = "num:i($mcan9_ExtendedMsg_Cnt + $mcan10_ExtendedMsg_Cnt + $mcan11_ExtendedMsg_Cnt + $mcan12_ExtendedMsg_Cnt)"!]
    [!VAR "RAMC_RxFifo0_Cnt" = "num:i($mcan9_RxFifo0_Cnt + $mcan10_RxFifo0_Cnt + $mcan11_RxFifo0_Cnt + $mcan12_RxFifo0_Cnt)"!]
    [!VAR "RAMC_RxFifo1_Cnt" = "num:i($mcan9_RxFifo1_Cnt + $mcan10_RxFifo1_Cnt + $mcan11_RxFifo1_Cnt + $mcan12_RxFifo1_Cnt)"!]
    [!VAR "RAMC_RxBuffer_Cnt" = "num:i($mcan9_RxBuffer_Cnt + $mcan10_RxBuffer_Cnt + $mcan11_RxBuffer_Cnt + $mcan12_RxBuffer_Cnt)"!]
    [!VAR "RAMC_TxBuffer_Cnt" = "num:i($mcan9_TxBuffer_Cnt + $mcan10_TxBuffer_Cnt + $mcan11_TxBuffer_Cnt + $mcan12_TxBuffer_Cnt)"!]
    [!IF "$mcan1_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN1 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan1_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN1 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan1_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN1 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan1_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN1 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan1_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN1 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan1_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN1 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan2_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN2 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan2_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN2 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan2_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN2 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan2_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN2 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan2_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN2 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan2_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN2 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan3_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN3 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan3_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN3 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan3_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN3 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan3_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN3 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan3_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN3 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan3_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN3 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan4_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN4 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan4_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN4 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan4_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN4 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan4_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN4 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan4_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN4 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan4_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN4 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan5_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN5 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan5_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN5 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan5_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN5 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan5_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN5 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan5_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN5 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan5_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN5 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan6_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN6 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan6_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN6 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan6_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN6 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan6_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN6 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan6_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN6 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan6_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN6 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan7_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN7 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan7_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN7 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan7_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN7 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan7_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN7 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan7_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN7 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan7_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN7 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan8_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN8 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan8_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN8 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan8_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN8 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan8_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN8 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan8_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN8 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan8_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN8 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan9_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN9 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan9_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN9 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan9_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN9 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan9_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN9 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan9_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN9 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan9_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN9 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan10_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN10 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan10_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN10 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan10_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN10 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan10_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN10 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan10_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN10 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan10_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN10 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan11_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN11 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan11_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN11 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan11_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN11 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan11_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN11 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan11_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN11 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan11_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN11 exceeds 32. [!ENDERROR!]
    [!ENDIF!]
    [!IF "$mcan12_StandardMsg_Cnt > num:i(128)"!]
        [!ERROR!] The number of MCAN12 standard frame filters exceeds 128. [!ENDERROR!]
    [!ELSEIF "$mcan12_ExtendedMsg_Cnt > num:i(64)"!]
        [!ERROR!] The number of MCAN12 extended frame filters exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan12_RxFifo0_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO0 depth of MCAN12 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan12_RxFifo1_Cnt > num:i(64)"!]
        [!ERROR!] The FIFO1 depth of MCAN12 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan12_RxBuffer_Cnt > num:i(64)"!]
        [!ERROR!] The RxBuffer depth of MCAN12 exceeds 64. [!ENDERROR!]
    [!ELSEIF "$mcan12_TxBuffer_Cnt > num:i(32)"!]
        [!ERROR!] The TxBuffer depth of MCAN12 exceeds 32. [!ENDERROR!]
    [!ENDIF!]

    [!VAR "mcan1_RAMA_Base" = "num:i(0)"!]
    [!VAR "mcan1_RAMA_Size" = "num:i(num:i(num:i($mcan1_StandardMsg_Cnt * 4) + num:i($mcan1_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan1_RxFifo0_Cnt + $mcan1_RxFifo1_Cnt + $mcan1_RxBuffer_Cnt + $mcan1_TxBuffer_Cnt) * num:i($mcan1_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan2_RAMA_Base" = "num:i($mcan1_RAMA_Base + $mcan1_RAMA_Size)"!]
    [!VAR "mcan2_RAMA_Size" = "num:i(num:i(num:i($mcan2_StandardMsg_Cnt * 4) + num:i($mcan2_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan2_RxFifo0_Cnt + $mcan2_RxFifo1_Cnt + $mcan2_RxBuffer_Cnt + $mcan2_TxBuffer_Cnt) * num:i($mcan2_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan3_RAMA_Base" = "num:i($mcan2_RAMA_Base + $mcan2_RAMA_Size)"!]
    [!VAR "mcan3_RAMA_Size" = "num:i(num:i(num:i($mcan3_StandardMsg_Cnt * 4) + num:i($mcan3_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan3_RxFifo0_Cnt + $mcan3_RxFifo1_Cnt + $mcan3_RxBuffer_Cnt + $mcan3_TxBuffer_Cnt) * num:i($mcan3_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan4_RAMA_Base" = "num:i($mcan3_RAMA_Base + $mcan3_RAMA_Size)"!]
    [!VAR "mcan4_RAMA_Size" = "num:i(num:i(num:i($mcan4_StandardMsg_Cnt * 4) + num:i($mcan4_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan4_RxFifo0_Cnt + $mcan4_RxFifo1_Cnt + $mcan4_RxBuffer_Cnt + $mcan4_TxBuffer_Cnt) * num:i($mcan4_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan5_RAMB_Base" = "num:i(0)"!]
    [!VAR "mcan5_RAMB_Size" = "num:i(num:i(num:i($mcan5_StandardMsg_Cnt * 4) + num:i($mcan5_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan5_RxFifo0_Cnt + $mcan5_RxFifo1_Cnt + $mcan5_RxBuffer_Cnt + $mcan5_TxBuffer_Cnt) * num:i($mcan5_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan6_RAMB_Base" = "num:i($mcan5_RAMB_Base + $mcan5_RAMB_Size)"!]
    [!VAR "mcan6_RAMB_Size" = "num:i(num:i(num:i($mcan6_StandardMsg_Cnt * 4) + num:i($mcan6_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan6_RxFifo0_Cnt + $mcan6_RxFifo1_Cnt + $mcan6_RxBuffer_Cnt + $mcan6_TxBuffer_Cnt) * num:i($mcan6_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan7_RAMB_Base" = "num:i($mcan6_RAMB_Base + $mcan6_RAMB_Size)"!]
    [!VAR "mcan7_RAMB_Size" = "num:i(num:i(num:i($mcan7_StandardMsg_Cnt * 4) + num:i($mcan7_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan7_RxFifo0_Cnt + $mcan7_RxFifo1_Cnt + $mcan7_RxBuffer_Cnt + $mcan7_TxBuffer_Cnt) * num:i($mcan7_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan8_RAMB_Base" = "num:i($mcan7_RAMB_Base + $mcan7_RAMB_Size)"!]
    [!VAR "mcan8_RAMB_Size" = "num:i(num:i(num:i($mcan8_StandardMsg_Cnt * 4) + num:i($mcan8_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan8_RxFifo0_Cnt + $mcan8_RxFifo1_Cnt + $mcan8_RxBuffer_Cnt + $mcan8_TxBuffer_Cnt) * num:i($mcan8_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan9_RAMC_Base" = "num:i(0)"!]
    [!VAR "mcan9_RAMC_Size" = "num:i(num:i(num:i($mcan9_StandardMsg_Cnt * 4) + num:i($mcan9_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan9_RxFifo0_Cnt + $mcan9_RxFifo1_Cnt + $mcan9_RxBuffer_Cnt + $mcan9_TxBuffer_Cnt) * num:i($mcan9_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan10_RAMC_Base" = "num:i($mcan9_RAMC_Base + $mcan9_RAMC_Size)"!]
    [!VAR "mcan10_RAMC_Size" = "num:i(num:i(num:i($mcan10_StandardMsg_Cnt * 4) + num:i($mcan10_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan10_RxFifo0_Cnt + $mcan10_RxFifo1_Cnt + $mcan10_RxBuffer_Cnt + $mcan10_TxBuffer_Cnt) * num:i($mcan10_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan11_RAMC_Base" = "num:i($mcan10_RAMC_Base + $mcan10_RAMC_Size)"!]
    [!VAR "mcan11_RAMC_Size" = "num:i(num:i(num:i($mcan11_StandardMsg_Cnt * 4) + num:i($mcan11_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan11_RxFifo0_Cnt + $mcan11_RxFifo1_Cnt + $mcan11_RxBuffer_Cnt + $mcan11_TxBuffer_Cnt) * num:i($mcan11_Payload_Size + 8)))) div 4)"!]
    [!VAR "mcan12_RAMC_Base" = "num:i($mcan11_RAMC_Base + $mcan11_RAMC_Size)"!]
    [!VAR "mcan12_RAMC_Size" = "num:i(num:i(num:i($mcan12_StandardMsg_Cnt * 4) + num:i($mcan12_ExtendedMsg_Cnt * 8) + (num:i(num:i($mcan12_RxFifo0_Cnt + $mcan12_RxFifo1_Cnt + $mcan12_RxBuffer_Cnt + $mcan12_TxBuffer_Cnt) * num:i($mcan12_Payload_Size + 8)))) div 4)"!]
    [!IF "num:i(($mcan1_RAMA_Size + $mcan2_RAMA_Size + $mcan3_RAMA_Size + $mcan4_RAMA_Size)) > num:i(ecu:get('MCan.RAMASIZE.Words'))"!]
        [!ERROR!] CAN1-CAN4 has more Ram than [!"num:i(ecu:get('MCan.RAMASIZE.Words'))"!] Words. [!ENDERROR!]
    [!ELSEIF "num:i(($mcan5_RAMB_Size + $mcan6_RAMB_Size + $mcan7_RAMB_Size + $mcan8_RAMB_Size)) > num:i(ecu:get('MCan.RAMBSIZE.Words'))"!]
        [!ERROR!] CAN5-CAN8 has more Ram than [!"num:i(ecu:get('MCan.RAMBSIZE.Words'))"!] Words. [!ENDERROR!]
    [!ELSEIF "num:i(($mcan9_RAMC_Size + $mcan10_RAMC_Size + $mcan11_RAMC_Size + $mcan12_RAMC_Size)) > num:i(ecu:get('MCan.RAMCSIZE.Words'))"!]
        [!ERROR!] CAN9-CAN12 has more Ram than [!"num:i(ecu:get('MCan.RAMCSIZE.Words'))"!] Words. [!ENDERROR!]
    [!ENDIF!]
[!ENDNOCODE!]

static CONST(McanControlInfor, CAN_CONST) MCAN_CTRL[[!"num:i(ecu:get('MCan.ControllerNumMax'))"!]U] =
{
    [!FOR "i" = "0" TO "num:i(ecu:get('MCan.ControllerNumMax')) - 1"!]
    {
        [!INDENT "8"!]
        .CanId = MCAN_MOD_ID_[!"num:i($i + 1)"!],
        [!IF "$i = 0 and $mcan1_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 1 and $mcan2_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 2 and $mcan3_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 3 and $mcan4_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 4 and $mcan5_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 5 and $mcan6_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 6 and $mcan7_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 7 and $mcan8_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 8 and $mcan9_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 9 and $mcan10_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 10 and $mcan11_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSEIF "$i = 11 and $mcan12_is_used = num:i(1)"!]
            .IsUsed = TRUE,
        [!ELSE!]
            .IsUsed = FALSE,
        [!ENDIF!]
        [!IF "$i = 0"!]
            .BaseWord = [!"num:i($mcan1_RAMA_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan1_RAMA_Size)"!]UL,
        [!ELSEIF "$i = 1"!]
            .BaseWord = [!"num:i($mcan2_RAMA_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan2_RAMA_Size)"!]UL,
        [!ELSEIF "$i = 2"!]
            .BaseWord = [!"num:i($mcan3_RAMA_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan3_RAMA_Size)"!]UL,
        [!ELSEIF "$i = 3"!]
            .BaseWord = [!"num:i($mcan4_RAMA_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan4_RAMA_Size)"!]UL,
        [!ELSEIF "$i = 4"!]
            .BaseWord = [!"num:i($mcan5_RAMB_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan5_RAMB_Size)"!]UL,
        [!ELSEIF "$i = 5"!]
            .BaseWord = [!"num:i($mcan6_RAMB_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan6_RAMB_Size)"!]UL,
        [!ELSEIF "$i = 6"!]
            .BaseWord = [!"num:i($mcan7_RAMB_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan7_RAMB_Size)"!]UL,
        [!ELSEIF "$i = 7"!]
            .BaseWord = [!"num:i($mcan8_RAMB_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan8_RAMB_Size)"!]UL,
        [!ELSEIF "$i = 8"!]
            .BaseWord = [!"num:i($mcan9_RAMC_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan9_RAMC_Size)"!]UL,
        [!ELSEIF "$i = 9"!]
            .BaseWord = [!"num:i($mcan10_RAMC_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan10_RAMC_Size)"!]UL,
        [!ELSEIF "$i = 10"!]
            .BaseWord = [!"num:i($mcan11_RAMC_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan11_RAMC_Size)"!]UL,
        [!ELSEIF "$i = 11"!]
            .BaseWord = [!"num:i($mcan12_RAMC_Base)"!]UL,
            .mram_size_words = [!"num:i($mcan12_RAMC_Size)"!]UL,
        [!ENDIF!]
        [!ENDINDENT!]
    },
    [!ENDFOR!]
};

static CONST(MCANPartitionConfig, CAN_CONST) MCAN_DATA =
{
    .McanCtrl = (McanControlInfor *)MCAN_CTRL,
};
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]

/* 
    The final value set to the register is as follows:
    Register NBTP.NBRP = brp - 1
    Register NBTP.NTSEG1 = (prop_seg + phase_seg1) - 1
    Register NBTP.NTSEG2 = phase_seg2 - 1
                             clockFrequency
    BitRate = ----------------------------------------------------
                brp * (1 + (prop_seg + phase_seg1) + phase_seg2)
*/
[!INDENT "0"!]
        static CONST(bt_config_canfd_struct, CAN_CONST) TIMCFG_[!"@index"!][[!"num:i(count(CanControllerBaudrateConfig/*))"!]U] =
        {
            [!LOOP "CanControllerBaudrateConfig/*"!]
            [!INDENT "4"!]
            {
                [!INDENT "8"!]
                .baudRateConfigId = [!"num:i(CanControllerBaudRateConfigID)"!]U,
                [!IF "(../../../../../CanGeneral/CanFdISO = 'false') and num:i(count(CanControllerFdBaudrateConfig/*)) != num:i(0)"!]
                    [!ERROR!] CanFdISO is not configured, but CanControllerFdBaudrateConfig is configured [!ENDERROR!]
                [!ENDIF!]
                [!IF "num:i(count(CanControllerFdBaudrateConfig/*)) != num:i(0) and (node:value(CanControllerFdBaudrateConfig/*[1]/CanControllerTxBitRateSwitch)) = 'true'"!]
                    .brs_ena = TRUE,
                [!ELSE!]
                    .brs_ena = FALSE,
                [!ENDIF!]
                [!IF "num:i(count(CanControllerFdBaudrateConfig/*)) != num:i(0)"!]
                    .fd_ena = TRUE,
                [!ELSE!]
                    .fd_ena = FALSE,
                [!ENDIF!]
                .is_noiso = FALSE,
                .nominal = 
                {
                [!INDENT "12"!]
                    .brp = [!"num:i(CanControllerPrescaller)"!]U,
                    .prop_seg = [!"num:i(CanControllerPropSeg)"!]U,
                    .phase_seg1 = [!"num:i(CanControllerSeg1)"!]U,
                    .phase_seg2 = [!"num:i(CanControllerSeg2)"!]U,
                    .sjw = [!"num:i(CanControllerSyncJumpWidth)"!]U,
                    .tdc = 0U
                [!ENDINDENT!]
                },
                [!IF "num:i(count(CanControllerFdBaudrateConfig/*)) != num:i(0)"!]
                    [!SELECT "CanControllerFdBaudrateConfig/*[1]"!]
                        .data =
                        {
                        [!INDENT "12"!]
                            .brp = [!"num:i(CanControllerPrescaller)"!]U,
                            .prop_seg = [!"num:i(CanControllerPropSeg)"!]U,
                            .phase_seg1 = [!"num:i(CanControllerSeg1)"!]U,
                            .phase_seg2 = [!"num:i(CanControllerSeg2)"!]U,
                            .sjw = [!"num:i(CanControllerSyncJumpWidth)"!]U,
                        [!IF "num:i(CanControllerSspOffset) != num:i(0)"!]
                            .tdc = 1U,
                            .tdc_offset = [!"num:i(CanControllerSspOffset)"!]U,
                        [!ELSE!]
                            .tdc = 0U,
                            .tdc_offset = 0U,
                        [!ENDIF!]
                        [!ENDINDENT!]
                        },
                    [!ENDSELECT!]
                [!ELSE!]
                    .data =
                    {
                    [!INDENT "12"!]
                        .brp = 0U,
                        .prop_seg = 0U,
                        .phase_seg1 = 0U,
                        .phase_seg2 = 0U,
                        .sjw = 0U,
                        .tdc = 0U,
                        .tdc_offset = 0U,
                    [!ENDINDENT!]
                    },
                [!ENDIF!]
                [!ENDINDENT!]
            },
            [!ENDINDENT!]
            [!ENDLOOP!]
        };
[!ENDINDENT!]
    [!ENDLOOP!]
[!ENDSELECT!]
[!INDENT "0"!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]
        [!VAR "mcan_controllerId" = "num:i(CanControllerId)"!]
        [!VAR "mcan_std_filters" = "num:i(0)"!]
        [!VAR "mcan_ext_filters" = "num:i(0)"!]
        [!VAR "mcan_mb_index" = "num:i(0)"!]
            [!LOOP "../../CanHardwareObject/*"!]
                [!IF "num:i(node:ref(CanControllerRef)/CanControllerId) = num:i($mcan_controllerId) and CanObjectType = 'RECEIVE' and num:i(count(CanHwFilter/*)) != num:i(0)"!]
                    [!IF "CanIdType = 'STANDARD'"!]
                        [!VAR "mcan_std_filters" = "num:i($mcan_std_filters + num:i(CanHwObjectCount))"!]
                    [!ELSE!]
                        [!VAR "mcan_ext_filters" = "num:i($mcan_ext_filters + num:i(CanHwObjectCount))"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!IF "num:i($mcan_std_filters + $mcan_ext_filters) != num:i(0)"!]

        static CONST(mcan_id_table_t, CAN_CONST) filter_ids_config_[!"@index"!][[!"num:i($mcan_std_filters + $mcan_ext_filters)"!]U] =
        {
            [!INDENT "4"!]
            [!LOOP "../../CanHardwareObject/*"!]
                [!IF "node:ref(CanControllerRef)/CanControllerId = $mcan_controllerId and CanObjectType = 'RECEIVE' and num:i(count(CanHwFilter/*)) != num:i(0)"!]
                    [!FOR "n" = "0" TO "num:i(CanHwObjectCount)-1"!]
                    {
                        [!INDENT "8"!]
                        [!IF "num:i(count(CanHwFilter/*)) != num:i(0)"!]
                            [!IF "CanStoreMB = 'BUFFER'"!]
                                .id1 = [!"num:inttohex(CanHwFilter/*[1]/CanHwFilterCode, 8)"!]U,
                                .id2 = [!"num:i($mcan_mb_index)"!]U,
                                [!VAR "mcan_mb_index" = "num:i($mcan_mb_index) + num:i(1)"!]
                            [!ELSE!]
                                .id1 = [!"num:inttohex(CanHwFilter/*[1]/CanHwFilterCode, 8)"!]U,
                                .id2 = [!"num:inttohex(CanHwFilter/*[1]/CanHwFilterMask, 8)"!]U,
                            [!ENDIF!]
                            .filterType = [!"CanHwFilter/*[1]/CanFilterType"!],
                        [!ELSE!]
                            .id1 = 0x0U,
                            .id2 = 0x0U,
                            .filterType = FILTER_TYPE_DISABLE,
                        [!ENDIF!]
                        [!IF "CanStoreMB = 'FIFO_0'"!]
                            .filterConfig = FILTER_CONF_RX_FIFO0,
                        [!ELSEIF "CanStoreMB = 'FIFO_1'"!]
                            .filterConfig = FILTER_CONF_RX_FIFO1,
                        [!ELSE!]
                            .filterConfig = FILTER_CONF_RX_BUFF,
                        [!ENDIF!]
                        .ssync = 0UL,
                        .esync = 0UL,
                        [!IF "CanIdType = 'STANDARD'"!]
                            .isExtendedFrame = FALSE,
                        [!ELSE!]
                            .isExtendedFrame = TRUE,
                        [!ENDIF!]
                        [!ENDINDENT!]
                    },
                    [!ENDFOR!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!ENDINDENT!]
        };

        static CONST(mcan_filter_config_t, CAN_CONST) RX_FILTER_CFG_[!"@index"!] =
        {
            [!INDENT "4"!]
            .filterconfigs = filter_ids_config_[!"@index"!],
            .std_filters = [!"$mcan_std_filters"!]U,
            .ext_filters = [!"$mcan_ext_filters"!]U,
            [!ENDINDENT!]
        };
        [!ELSE!]
            #define RX_FILTER_CFG_[!"@index"!] NULL_PTR
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDSELECT!]
[!ENDINDENT!]
[!INDENT "0"!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]

        static CONST(mcan_fifo_config_t, CAN_CONST) RX_FIFO_CFG_[!"@index"!] =
        {
            [!INDENT "4"!]
            [!IF "num:i(count(CanRxFifo/*)) = num:i(0)"!]
                .rx_fifo_needed = MCAN_RXFIFO_DISABLED,
                .modeFIFO = FIFO_MODE_OVERWRITE,
                .fifo_size_elems = 0U,
                .fifo_watermark = 0U,
                .payload = MCAN_PAYLOAD_SIZE_8,
            [!ELSEIF "num:i(count(CanRxFifo/*)) = num:i(1)"!]
                [!IF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_0'"!]
                    .rx_fifo_needed = MCAN_RXFIFO_0_ENABLE,
                [!ELSEIF "CanRxFifo/*[1]/ReceiveFifo = 'FIFO_1'"!]
                    .rx_fifo_needed = MCAN_RXFIFO_1_ENABLE,
                [!ELSE!]
                    .rx_fifo_needed = MCAN_RXFIFO_0_1_ENABLE,
                [!ENDIF!]
                .modeFIFO = FIFO_MODE_OVERWRITE,
                .fifo_size_elems = [!"num:i(CanRxFifo/*[1]/CanFifoDepth)"!]U,
                .fifo_watermark = [!"num:i(CanRxFifo/*[1]/CanFifoWatermark)"!]U,
                [!IF "CanPayloadLength = 'CAN_8_BYTES_PAYLOAD'"!]
                    .payload = MCAN_PAYLOAD_SIZE_8,
                [!ELSEIF "CanPayloadLength = 'CAN_12_BYTES_PAYLOAD'"!]
                    .payload = MCAN_PAYLOAD_SIZE_12,
                [!ELSEIF "CanPayloadLength = 'CAN_16_BYTES_PAYLOAD'"!]
                    .payload = MCAN_PAYLOAD_SIZE_16,
                [!ELSEIF "CanPayloadLength = 'CAN_20_BYTES_PAYLOAD'"!]
                    .payload = MCAN_PAYLOAD_SIZE_20,
                [!ELSEIF "CanPayloadLength = 'CAN_24_BYTES_PAYLOAD'"!]
                    .payload = MCAN_PAYLOAD_SIZE_24,
                [!ELSEIF "CanPayloadLength = 'CAN_32_BYTES_PAYLOAD'"!]
                    .payload = MCAN_PAYLOAD_SIZE_32,
                [!ELSEIF "CanPayloadLength = 'CAN_48_BYTES_PAYLOAD'"!]
                    .payload = MCAN_PAYLOAD_SIZE_48,
                [!ELSEIF "CanPayloadLength = 'CAN_64_BYTES_PAYLOAD'"!]
                    .payload = MCAN_PAYLOAD_SIZE_64,
                [!ENDIF!]
            [!ENDIF!]
            [!ENDINDENT!]
        };
    [!ENDLOOP!]
[!ENDSELECT!]
[!ENDINDENT!]
[!INDENT "0"!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]

        static CONST(mcan_global_filter_config_t, CAN_CONST) GLOBAL_FILTER_CFG_[!"@index"!] =
        {
            [!INDENT "4"!]
            .anfe = REJECT_NON_MATCHING_FRAMES,
            .anfs = REJECT_NON_MATCHING_FRAMES,
            .rrfe = TRUE,
            .rrfs = TRUE,
            [!ENDINDENT!]
        };
    [!ENDLOOP!]
[!ENDSELECT!]
[!ENDINDENT!]
[!INDENT "0"!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]

        static CONST(mcan_tx_buffer_config_t, CAN_CONST) TX_BUFFER_CFG_[!"@index"!] =
        {
            [!INDENT "4"!]
            .FIFO_true_QUEUE_false = TRUE,
            .fifo_queue_size = 0U,
            [!IF "CanHwChannel = 'MCAN_1'"!]
                .ded_buffers_number = [!"num:i($mcan1_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_2'"!]
                .ded_buffers_number = [!"num:i($mcan2_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_3'"!]
                .ded_buffers_number = [!"num:i($mcan3_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_4'"!]
                .ded_buffers_number = [!"num:i($mcan4_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_5'"!]
                .ded_buffers_number = [!"num:i($mcan5_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_6'"!]
                .ded_buffers_number = [!"num:i($mcan6_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_7'"!]
                .ded_buffers_number = [!"num:i($mcan7_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_8'"!]
                .ded_buffers_number = [!"num:i($mcan8_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_9'"!]
                .ded_buffers_number = [!"num:i($mcan9_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_10'"!]
                .ded_buffers_number = [!"num:i($mcan10_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_11'"!]
                .ded_buffers_number = [!"num:i($mcan11_mb_tx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_12'"!]
                .ded_buffers_number = [!"num:i($mcan12_mb_tx_index)"!]U,
            [!ENDIF!]
            [!IF "CanPayloadLength = 'CAN_8_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_8,
            [!ELSEIF "CanPayloadLength = 'CAN_12_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_12,
            [!ELSEIF "CanPayloadLength = 'CAN_16_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_16,
            [!ELSEIF "CanPayloadLength = 'CAN_20_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_20,
            [!ELSEIF "CanPayloadLength = 'CAN_24_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_24,
            [!ELSEIF "CanPayloadLength = 'CAN_32_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_32,
            [!ELSEIF "CanPayloadLength = 'CAN_48_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_48,
            [!ELSEIF "CanPayloadLength = 'CAN_64_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_64,
            [!ENDIF!]
            [!ENDINDENT!]
        };

        static CONST(mcan_dedicated_buffers_config_t, CAN_CONST) RX_BUFFER_CFG_[!"@index"!] =
        {
            [!INDENT "4"!]
            [!IF "CanHwChannel = 'MCAN_1'"!]
                .rx_buffer_size_elems = [!"num:i($mcan1_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_2'"!]
                .rx_buffer_size_elems = [!"num:i($mcan2_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_3'"!]
                .rx_buffer_size_elems = [!"num:i($mcan3_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_4'"!]
                .rx_buffer_size_elems = [!"num:i($mcan4_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_5'"!]
                .rx_buffer_size_elems = [!"num:i($mcan5_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_6'"!]
                .rx_buffer_size_elems = [!"num:i($mcan6_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_7'"!]
                .rx_buffer_size_elems = [!"num:i($mcan7_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_8'"!]
                .rx_buffer_size_elems = [!"num:i($mcan8_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_9'"!]
                .rx_buffer_size_elems = [!"num:i($mcan9_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_10'"!]
                .rx_buffer_size_elems = [!"num:i($mcan10_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_11'"!]
                .rx_buffer_size_elems = [!"num:i($mcan11_mb_rx_index)"!]U,
            [!ELSEIF "CanHwChannel = 'MCAN_12'"!]
                .rx_buffer_size_elems = [!"num:i($mcan12_mb_rx_index)"!]U,
            [!ENDIF!]
            [!IF "CanPayloadLength = 'CAN_8_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_8,
            [!ELSEIF "CanPayloadLength = 'CAN_12_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_12,
            [!ELSEIF "CanPayloadLength = 'CAN_16_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_16,
            [!ELSEIF "CanPayloadLength = 'CAN_20_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_20,
            [!ELSEIF "CanPayloadLength = 'CAN_24_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_24,
            [!ELSEIF "CanPayloadLength = 'CAN_32_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_32,
            [!ELSEIF "CanPayloadLength = 'CAN_48_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_48,
            [!ELSEIF "CanPayloadLength = 'CAN_64_BYTES_PAYLOAD'"!]
                .payload = MCAN_PAYLOAD_SIZE_64,
            [!ENDIF!]
            [!ENDINDENT!]
        };
    [!ENDLOOP!]
[!ENDSELECT!]
[!ENDINDENT!]
[!INDENT "0"!]
[!SELECT "CanConfigSet"!]
    [!LOOP "CanController/*"!]
        [!VAR "tx_ispol" = "0"!]
        [!VAR "rx_ispol" = "0"!]
        [!VAR "inter_en" = "0"!]
        [!VAR "inter_error_en" = "0"!]
        [!VAR "inter_mraf_en" = "0"!]
        [!VAR "inter_fifo0_en" = "0"!]
        [!VAR "inter_fifo1_en" = "0"!]
        [!VAR "inter_rxbuffer_en" = "0"!]
        [!VAR "inter_txbuffer_en" = "0"!]
        [!VAR "inter_busoff_en" = "0"!]
        [!VAR "tempControllerId" = "num:i(CanControllerId)"!]
        [!LOOP "../../CanHardwareObject/*"!]
            [!IF "num:i(node:ref(CanControllerRef)/CanControllerId) = $tempControllerId"!]
                [!IF "(((node:exists(CanHardwareObjectUsesPolling) and node:value(CanHardwareObjectUsesPolling) = 'true') and node:ref(CanControllerRef)/CanRxProcessing = 'POLLING') and node:value(CanObjectType) = 'RECEIVE')"!]
                    [!VAR "rx_ispol" = "1"!]
                [!ELSEIF "(((node:exists(CanHardwareObjectUsesPolling) and node:value(CanHardwareObjectUsesPolling) = 'true') and node:ref(CanControllerRef)/CanTxProcessing = 'POLLING') and node:value(CanObjectType) = 'TRANSMIT')"!]
                    [!VAR "tx_ispol" = "1"!]
                [!ELSE!]
                    [!VAR "inter_en" = "1"!]
                [!ENDIF!]
                [!IF "$inter_en = 1 and CanStoreMB = 'FIFO_0' and node:value(CanHardwareObjectUsesPolling) = 'false'"!]
                    [!VAR "inter_fifo0_en" = "1"!]
                [!ELSEIF "$inter_en = 1 and CanStoreMB = 'FIFO_1' and node:value(CanHardwareObjectUsesPolling) = 'false'"!]
                    [!VAR "inter_fifo1_en" = "1"!]
                [!ELSEIF "$inter_en = 1 and CanStoreMB = 'BUFFER' and node:value(CanHardwareObjectUsesPolling) = 'false' and node:value(CanObjectType) = 'RECEIVE'"!]
                    [!VAR "inter_rxbuffer_en" = "1"!]
                [!ELSEIF "$inter_en = 1 and CanStoreMB = 'BUFFER' and node:value(CanHardwareObjectUsesPolling) = 'false' and node:value(CanObjectType) = 'TRANSMIT'"!]
                    [!VAR "inter_txbuffer_en" = "1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "../../../../CanGeneral/CanSupportMRAFEvent = 'true' and CanSupportMRAFprocessing = 'INTERRUPT'"!]
            [!VAR "inter_mraf_en" = "1"!]
            [!VAR "inter_en" = "1"!]
        [!ENDIF!]
        [!IF "CanErrorControllerNotifEn = 'true'"!]
            [!VAR "inter_error_en" = "1"!]
            [!VAR "inter_en" = "1"!]
        [!ENDIF!]
        [!IF "CanBusoffProcessing = 'INTERRUPT'"!]
            [!VAR "inter_busoff_en" = "1"!]
            [!VAR "inter_en" = "1"!]
        [!ENDIF!]
        [!VAR "ir_line0_select_temp" = "num:i(0)"!]
        [!VAR "ir_line1_select_temp" = "num:i(0)"!]
        [!IF "$inter_error_en = 1"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(134217728)))"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(268435456)))"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(536870912)))"!]
        [!ENDIF!]
        [!IF "$inter_mraf_en = 1"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(131072)))"!]
        [!ENDIF!]
        [!IF "$inter_fifo0_en = 1"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(1)))"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(2)))"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(4)))"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(8)))"!]
        [!ENDIF!]
        [!IF "$inter_fifo1_en = 1"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(16)))"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(32)))"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(64)))"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(128)))"!]
        [!ENDIF!]
        [!IF "$inter_rxbuffer_en = 1"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(524288)))"!]
        [!ENDIF!]
        [!IF "$inter_txbuffer_en = 1"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(512)))"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(1024)))"!]
        [!ENDIF!]
        [!IF "$inter_busoff_en = 1"!]
            [!VAR "ir_line0_select_temp" = "num:i(bit:or(num:i($ir_line0_select_temp), num:i(33554432)))"!]
        [!ENDIF!]

        [!IF "$inter_en = 1"!]
        static CONST(mcan_inter_config_t, CAN_CONST) INTER_CFG_[!"@index"!] =
        {
            [!INDENT "4"!]
            .ir_line0_select = [!"num:inttohex(num:i($ir_line0_select_temp), 8)"!]UL,
            .ir_line1_select = [!"num:inttohex(num:i($ir_line1_select_temp), 8)"!]UL,
            [!IF "CanHwChannel = 'MCAN_1'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan1_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan1_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_2'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan2_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan2_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_3'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan3_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan3_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_4'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan4_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan4_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_5'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan5_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan5_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_6'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan6_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan6_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_7'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan7_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan7_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_8'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan8_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan8_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_9'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan9_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan9_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_10'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan10_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan10_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_11'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan11_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan11_buffer_transmission_ir_mask), 8)"!]UL,
            [!ELSEIF "CanHwChannel = 'MCAN_12'"!]
                .tx_buffer_tran_ir_enable = [!"num:inttohex(num:i($mcan12_buffer_transmission_ir_mask), 8)"!]UL,
                .tx_buffer_cancel_fin_ir_enable = [!"num:inttohex(num:i($mcan12_buffer_transmission_ir_mask), 8)"!]UL,
            [!ENDIF!]
            [!ENDINDENT!]
        };
        [!ELSE!]
        static CONST(mcan_inter_config_t, CAN_CONST) INTER_CFG_[!"@index"!] =
        {
            [!INDENT "4"!]
            .ir_line0_select = 0UL,
            .ir_line1_select = 0UL,
            .tx_buffer_tran_ir_enable = 0x0UL,
            .tx_buffer_cancel_fin_ir_enable = 0x0UL,
            [!ENDINDENT!]
        };
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDSELECT!]
[!ENDINDENT!]

[!NOCODE!]
[!VAR "mcan1_is_used" = "num:i(0)"!]
[!VAR "mcan2_is_used" = "num:i(0)"!]
[!VAR "mcan3_is_used" = "num:i(0)"!]
[!VAR "mcan4_is_used" = "num:i(0)"!]
[!VAR "mcan5_is_used" = "num:i(0)"!]
[!VAR "mcan6_is_used" = "num:i(0)"!]
[!VAR "mcan7_is_used" = "num:i(0)"!]
[!VAR "mcan8_is_used" = "num:i(0)"!]
[!VAR "mcan9_is_used" = "num:i(0)"!]
[!VAR "mcan10_is_used" = "num:i(0)"!]
[!VAR "mcan11_is_used" = "num:i(0)"!]
[!VAR "mcan12_is_used" = "num:i(0)"!]
[!ENDNOCODE!]
[!SELECT "CanConfigSet"!]
static CONST(CANConfig, CAN_CONST) Mcan_ControllerConfigs[CAN_CONTROLLER_COUNT] = 
{
    [!LOOP "CanController/*"!]
    [!VAR "RateConfigCount"="num:i(count(CanControllerBaudrateConfig/*))"!]
    {
        [!INDENT "8"!]
        [!IF "CanHwChannel = 'MCAN_1' and $mcan1_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_1,
            [!VAR "mcan1_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_2' and $mcan2_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_2,
            [!VAR "mcan2_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_3' and $mcan3_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_3,
            [!VAR "mcan3_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_4' and $mcan4_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_4,
            [!VAR "mcan4_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_5' and $mcan5_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_5,
            [!VAR "mcan5_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_6' and $mcan6_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_6,
            [!VAR "mcan6_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_7' and $mcan7_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_7,
            [!VAR "mcan7_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_8' and $mcan8_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_8,
            [!VAR "mcan8_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_9' and $mcan9_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_9,
            [!VAR "mcan9_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_10' and $mcan10_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_10,
            [!VAR "mcan10_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_11' and $mcan11_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_11,
            [!VAR "mcan11_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_12' and $mcan12_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_12,
            [!VAR "mcan12_is_used" = "num:i(1)"!]
        [!ELSE!]
            [!ERROR!]CanControllerId is [!"num:i(CanControllerId)"!] CanHwChannel is [!"CanHwChannel"!]. This canController is repeated [!ENDERROR!]
        [!ENDIF!]
        .defaultBaudRateId = (uint16)[!"node:ref(CanControllerDefaultBaudrate)/CanControllerBaudRateConfigID"!]U,
        .baudRateConfigCount = [!"$RateConfigCount"!]U,
        .data = &MCAN_DATA,
        .timingconfig = TIMCFG_[!"@index"!],
        .globalfilterconfig = &GLOBAL_FILTER_CFG_[!"@index"!],
        #ifdef RX_FILTER_CFG_[!"@index"!]
            .filterconfig = RX_FILTER_CFG_[!"@index"!],
        #else
            .filterconfig = &RX_FILTER_CFG_[!"@index"!],
        #endif
        .rxfifoconfig =  &RX_FIFO_CFG_[!"@index"!],
        .txeventconfig = NULL_PTR,
        .txbufferconfig = &TX_BUFFER_CFG_[!"@index"!],
        .rxbufferconfig = &RX_BUFFER_CFG_[!"@index"!],
        .interconfig = &INTER_CFG_[!"@index"!],
        .stampconfig = NULL_PTR,
        .mcanMode = MCAN_NORMAL_MODE,
        [!IF "normalize-space(CanMRAFNotification) != 'NULL_PTR'"!]
            .MRAFNotification = &[!"normalize-space(CanMRAFNotification)"!],
        [!ELSE!]
            .MRAFNotification = NULL_PTR,
        [!ENDIF!]
        [!IF "(CanErrorControllerNotifEn = 'true') and (normalize-space(CanErrorControllerNotification) != 'NULL_PTR')"!]
            .ErrorNotification = &[!"normalize-space(CanErrorControllerNotification)"!],
        [!ELSE!]
            .ErrorNotification = NULL_PTR,
        [!ENDIF!]
        [!ENDINDENT!]
    },
    [!ENDLOOP!]
};
[!ENDSELECT!]

[!IF "(CanGeneral/CanMulticoreSupport = 'true')"!]
    [!VAR "multcore_en" = "num:i(1)"!]
[!ELSE!]
    [!VAR "multcore_en" = "num:i(0)"!]
[!ENDIF!]
[!MACRO "GetCoreID"!]
[!NOCODE!]
    [!VAR "CoreID" = "num:i(0)"!]
    [!VAR "EcucPartitionRefMatch_cnt" = "num:i(0)"!]
    [!VAR "ModuEcucPartitionRef" = "string(CanControllerEcucPartitionRef)"!]
    [!IF "$multcore_en = num:i(1)"!]
        [!IF "not(node:refexists(CanControllerEcucPartitionRef))"!]
            [!VAR "CoreID" = "num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]
        [!ELSE!]
            [!VAR "OsApplication_cnt" = "num:i(count(as:modconf('Os')[1]/OsApplication/*))"!]
            [!IF "$OsApplication_cnt = num:i(0)"!]
                [!ERROR!]  ASPath:/Os/Os/OsApplication is not configured [!ENDERROR!]
            [!ELSE!]
                [!FOR "n" = "0" TO "num:i($OsApplication_cnt)-1"!]
                    [!VAR "OsEcucPartitionRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!]
                    [!IF "text:match($OsEcucPartitionRef,$ModuEcucPartitionRef)"!]
                        [!VAR "EcucPartitionRefMatch_cnt" = "num:i($EcucPartitionRefMatch_cnt)+num:i(1)"!]
                        [!IF "not(node:refexists(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1]))"!]
                            [!VAR "OsApplicationCoreRef" = "as:modconf('Os')[1]/OsApplication/*[$n+1]/OsAppEcucPartitionRef/*[1]"!]
                            [!ERROR!]  [!"string(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])"!] is not configured [!ENDERROR!]
                        [!ELSE!]
                            [!VAR "CoreID" = "node:ref(as:modconf('Os')[1]/OsApplication/*[$n+1]/OsApplicationCoreRef/*[1])/EcucCoreId"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDFOR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$EcucPartitionRefMatch_cnt = num:i(0)"!]
        [!VAR "CoreID" = "num:i(ecu:get('MCAL.DEFAULT.COREID'))"!]
    [!ENDIF!]
[!ENDNOCODE!]
[!"$CoreID"!]U
[!ENDMACRO!]
[!NOCODE!]
[!VAR "mcan1_is_used" = "num:i(0)"!]
[!VAR "mcan2_is_used" = "num:i(0)"!]
[!VAR "mcan3_is_used" = "num:i(0)"!]
[!VAR "mcan4_is_used" = "num:i(0)"!]
[!VAR "mcan5_is_used" = "num:i(0)"!]
[!VAR "mcan6_is_used" = "num:i(0)"!]
[!VAR "mcan7_is_used" = "num:i(0)"!]
[!VAR "mcan8_is_used" = "num:i(0)"!]
[!VAR "mcan9_is_used" = "num:i(0)"!]
[!VAR "mcan10_is_used" = "num:i(0)"!]
[!VAR "mcan11_is_used" = "num:i(0)"!]
[!VAR "mcan12_is_used" = "num:i(0)"!]
[!ENDNOCODE!]
#if (CAN_MULTICORE_ENABLED == STD_ON)
static CONST(mcan_core_map_t, CAN_CONST) Mcan_CoreMap[CAN_CONTROLLER_COUNT] =
{
    [!LOOP "(CanConfigSet/CanController/*)"!]
    [!VAR "CanControllerId" = "num:i(./CanControllerId)"!]
    {
        [!INDENT "8"!]
        [!IF "CanHwChannel = 'MCAN_1' and $mcan1_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_1,
            [!VAR "mcan1_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_2' and $mcan2_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_2,
            [!VAR "mcan2_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_3' and $mcan3_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_3,
            [!VAR "mcan3_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_4' and $mcan4_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_4,
            [!VAR "mcan4_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_5' and $mcan5_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_5,
            [!VAR "mcan5_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_6' and $mcan6_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_6,
            [!VAR "mcan6_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_7' and $mcan7_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_7,
            [!VAR "mcan7_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_8' and $mcan8_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_8,
            [!VAR "mcan8_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_9' and $mcan9_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_9,
            [!VAR "mcan9_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_10' and $mcan10_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_10,
            [!VAR "mcan10_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_11' and $mcan11_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_11,
            [!VAR "mcan11_is_used" = "num:i(1)"!]
        [!ELSEIF "CanHwChannel ='MCAN_12' and $mcan12_is_used = num:i(0)"!]
            .controllerId = MCAN_MOD_ID_12,
            [!VAR "mcan12_is_used" = "num:i(1)"!]
        [!ELSE!]
            [!ERROR!]CanControllerId is [!"num:i(CanControllerId)"!] CanHwChannel is [!"CanHwChannel"!]. This canController is repeated [!ENDERROR!]
        [!ENDIF!]
            .CoreId = [!WS "1"!][!CALL "GetCoreID"!]
        [!ENDINDENT!]
    },
    [!ENDLOOP!]
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
