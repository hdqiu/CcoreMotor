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
*   @file    Sent_Cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Sent MCAL driver.
*
*   @addtogroup Sent
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Sent.h"
#include "Sent_Cfg.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SENT_VENDOR_ID                           176
#define SENT_CFG_AR_MAJOR_VER                    4
#define SENT_CFG_AR_MINOR_VER                    4
#define SENT_CFG_AR_PATCH_VER                    0
#define SENT_CFG_SW_MAJOR_VER                    1
#define SENT_CFG_SW_MINOR_VER                    0
#define SENT_CFG_SW_PATCH_VER                    1

/*============================================FILE VERSION CHECKS===================================*/
#if (MCAL_VENDOR_ID != SENT_VENDOR_ID)
    #error " NON-MATCHED DATA : SENT_VENDOR_ID "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != SENT_CFG_AR_MAJOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != SENT_CFG_AR_MINOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != SENT_CFG_AR_PATCH_VER)
    #error " NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER "
#endif
#if (MCAL_SW_MAJOR_VERSION != SENT_CFG_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER "
#endif
#if (MCAL_SW_MINOR_VERSION != SENT_CFG_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER "
#endif
#if (MCAL_SW_PATCH_VERSION != SENT_CFG_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER "
#endif

extern void Sensor_srxNotification(Sent_ChannelType channel, srx_callback_type_t type);

#if (SENT_ENABLE_MULTICORE == STD_ON)
static CONST(Sent_CoreMapItemType, SENT_CONST) Sent_CoreMap[25] =
{
    {
        .u8HwChannel = 0,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 1,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 2,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 3,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 4,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 5,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 6,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 7,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 8,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 9,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 10,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 11,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 12,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 13,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 14,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 15,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 16,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 17,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 18,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 19,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 20,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 21,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 22,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 23,
        .u8CoreId = 0
    },
    {
        .u8HwChannel = 24,
        .u8CoreId = 0
    },
};
#endif

static CONST(Sent_ChannelCfgtype, SENT_CONST) Sent_InitChannel[25] =
{
    {
        .u8ChannelId = (uint8)(SENT_0_CH_0),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_1),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_2),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_3),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_4),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_5),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_6),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_7),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_8),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_9),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_10),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_11),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_0_CH_12),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_0),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_1),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_2),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_3),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_4),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_5),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_6),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_7),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_8),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_9),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_10),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
    {
        .u8ChannelId = (uint8)(SENT_1_CH_11),
        .u8TickDuration = (uint8)(3),
        .inputFilter = SRX_INPUT_FILTER_NONE,
        .sSentDiagCfg =
        {
            .diagEvents = SRX_EV_NONE,
            .idleCount = SRX_BUS_IDLE_DISABLED,
            .calibVar = SRX_CALIB_VAR_25_PERCENT,
            .diagPulse = SRX_PULSE_CHECK_PAUSE,
            .pausePulse = SRX_PAUSE_PULSE_DISABLED,
            .succesiveCal = SRX_SUCC_CAL_CHK_PREFFERED
        },
        .sSentFastMsg =
        {
            .numberOfNibbles = (uint8)6u,
            .dmaEnable = FALSE,
            .crcIncludeStatus = SRX_FCRC_INCLUDE,
            .disableCrcCheck = SRX_FCRC_CHECK_ENABLE,
            .crcType = SRX_CRC_LEGACY
        },
        .sSentSlowMsg =
        {
            .dmaEnable = FALSE,
            .crcType = SRX_CRC_LEGACY,
        },
        .pfNotification = (Sent_NotificationFunc)(&Sensor_srxNotification)  /* Channel notification */
    },
};

CONST(Sent_ConfigType, SENT_CONST)SentChannelConfigSet =
{
    .u8MaxHwChannels = (uint8)25U,
    .u8TimestampPrescaler = (uint8)100U,
    .u32SentClkFreq = (uint32)100000000U,
#if (SENT_ENABLE_MULTICORE == STD_ON)
    .pCoreMap = Sent_CoreMap,
#endif
    .pChanCfgPtr = Sent_InitChannel,
};

#ifdef __cplusplus
}
#endif
