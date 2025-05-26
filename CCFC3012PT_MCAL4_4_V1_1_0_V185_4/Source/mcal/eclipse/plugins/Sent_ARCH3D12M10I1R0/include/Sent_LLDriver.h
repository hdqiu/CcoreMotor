/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     srx_lld.h
* @version  1.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/

#ifndef LLD_INC_SRX_LLD_H_
#define LLD_INC_SRX_LLD_H_

#include "derivative.h"
#include "Sent_Cfg.h"
#include "typedefs.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define SENT_VENDOR_ID_H                     176
#define SENT_MODULE_ID_H                     100
#define SENT_AR_MAJOR_VER_H                  4
#define SENT_AR_MINOR_VER_H                  4
#define SENT_AR_PATCH_VER_H                  0
#define SENT_SW_MAJOR_VER_H                  1
#define SENT_SW_MINOR_VER_H                  0
#define SENT_SW_PATCH_VER_H                  1

/*============================================FILE VERSION CHECKS===================================*/

#if (SENT_VENDOR_ID_H != SENT_VENDOR_ID)
#error "NON-MATCHED DATA : SENT_CFG_VENDOR_ID"
#endif

#if (SENT_AR_MAJOR_VER_H != SENT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER"
#endif
#if (SENT_AR_MINOR_VER_H != SENT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER"
#endif
#if (SENT_AR_PATCH_VER_H != SENT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER"
#endif

#if (SENT_SW_MAJOR_VER_H != SENT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER"
#endif
#if (SENT_SW_MINOR_VER_H != SENT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER"
#endif
#if (SENT_SW_PATCH_VER_H != SENT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER"
#endif


#define SENT_DET_ERR(x)                         DEV_ASSERT(x)

typedef  struct SRX_tag                         SRX_Type;

/* IRCOSC - Peripheral instance base addresses */
/** Peripheral SRX0 base address */
#define SRX_0_BASE                              (0xFFE5C000u)
/** Peripheral SRX0  base pointer */
#define SRX0_StPtr                              ((SRX_Type *)SRX_0_BASE)
/** Peripheral SRX1 base address */
#define SRX_1_BASE                              (0xFBE5C000u)
/** Peripheral SRX1 base pointer */
#define SRX1_StPtr                              ((SRX_Type *)SRX_1_BASE)
/** Array initializer of IRCOSC peripheral base addresses */
#define SRX_BASE_ADDRS                          { SRX_0_BASE,SRX_1_BASE }
/** Array initializer of IRCOSC peripheral base pointers */
#define SRX_BASE_PTRS                           { SRX0_StPtr, SRX1_StPtr}

#define SRX_INSTANCE_COUNT                      2u
#define SRX_CLK_CTRL_PRSC_WIDTH                 14u

#define SRX_CH_COUNT                            2u
#define SRX0_CHANNEL_COUNT                      13u
#define SRX1_CHANNEL_COUNT                      12u
#define SRX_CHANNEL_COUNT                       GET_MAX((SRX0_CHANNEL_COUNT),(SRX1_CHANNEL_COUNT))

/**
 * Used for bringing the register to a default reset state
 */
#define SRX_GBL_CTRL_RESET_VALUE                (0x00010010u)
#define SRX_CHNL_EN_RESET_VALUE                 (0x00000000u)
#define SRX_DATA_CTRL1_RESET_VALUE              (0x11000000u)
#define SRX_FDMA_CTRL_RESET_VALUE               (0x00000000u)
#define SRX_SDMA_CTRL_RESET_VALUE               (0x00000000u)
#define SRX_FRDY_IE_RESET_VALUE                 (0x00000000u)
#define SRX_SRDY_IE_RESET_VALUE                 (0x00000000u)
#define SRX_CHn_CLK_CTRL_RESET_VALUE            (0x00008000u)
#define SRX_CHn_CONFIG_RESET_VALUE              (0x00000104u)


#define SRX_DATA_CTRL1_NIBBCH0_MASK              0x70000000u
#define SRX_DATA_CTRL1_NIBBCH0_SHIFT             28u
#define SRX_DATA_CTRL1_NIBBCH0_WIDTH             3u


#define SRX_DATA_CTRL2_NIBBCH0_MASK              0x70000000u
#define SRX_DATA_CTRL2_NIBBCH0_SHIFT             28u
#define SRX_DATA_CTRL2_NIBBCH0_WIDTH             3u
#define SRX_DATA_CTRL2_NIBBCH0(x)                (((uint32_t)(((uint32_t)(x))<<SRX_DATA_CTRL1_NIBBCH0_SHIFT))&SRX_DATA_CTRL1_NIBBCH0_MASK)
/*
 * Masks for various events
 * These can be combined such as: events |= (EV_1 | EV_2);
 * Also used inside the configuration structure for enabling/disabling certain events
 */
#define SRX_EV_BUS_IDLE                          ((uint32)((uint32)(1u) << (uint32)(31 - 0)))  /* Channel has been idle for more than the allowed value */
#define SRX_EV_CAL_RESYNC                        ((uint32)((uint32)(1u) << (uint32)(31 - 4)))  /* Successive Calibration Check has failed three times */
#define SRX_EV_CAL_20_25                         ((uint32)((uint32)(1u) << (uint32)(31 - 5)))  /* Calibration pulse received on this channel has variation in between 20% to 25% from 56 ticks */
#define SRX_EV_SMSG_OFLW                         ((uint32)((uint32)(1u) << (uint32)(31 - 6)))  /* Slow message overflow */
#define SRX_EV_FMSG_OFLW                         ((uint32)((uint32)(1u) << (uint32)(31 - 7)))  /* Fast message overflow */
#define SRX_EV_PP_DIAG_ERR                       ((uint32)((uint32)(1u) << (uint32)(31 - 9)))  /* The ratio of calibration pulse length to overall message length (with pause pulse) is more than 1.5625% between two messages */
#define SRX_EV_CAL_LEN_ERR                       ((uint32)((uint32)(1u) << (uint32)(31 - 10))) /* Calibration pulse is more than 56 ticks 25% */
#define SRX_EV_CAL_DIAG_ERR                      ((uint32)((uint32)(1u) << (uint32)(31 - 11))) /* Successive Calibration pulses differ by 1.56% */
#define SRX_EV_NIB_VAL_ERR                       ((uint32)((uint32)(1u) << (uint32)(31 - 12))) /* Any nibble data value <0 or >15 */
#define SRX_EV_SMSG_CRC_ERR                      ((uint32)((uint32)(1u) << (uint32)(31 - 13))) /* Checksum error in Slow Serial Message */
#define SRX_EV_FMSG_CRC_ERR                      ((uint32)((uint32)(1u) << (uint32)(31 - 14))) /* Checksum error in Fast Serial Message */
#define SRX_EV_NUM_EDGES_ERR                     ((uint32)((uint32)(1u) << (uint32)(31 - 15))) /*  Not the expected number of negative edges between calibration pulse */
#define SRX_EV_FDMA_UNDERFLOW                    ((uint32)((uint32)(1u) << (uint32)(31 - 8)))  /* Underflow in Fast message DMA registers */
#define SRX_EV_SDMA_UNDERFLOW                    ((uint32)((uint32)(1u) << (uint32)(31 - 9)))  /* Underflow in Slow message DMA registers */
#define SRX_EV_ALL                               ((uint32)(SRX_EV_BUS_IDLE | SRX_EV_CAL_RESYNC | SRX_EV_CAL_20_25 | SRX_EV_SMSG_OFLW \
                                                | SRX_EV_FMSG_OFLW | SRX_EV_PP_DIAG_ERR | SRX_EV_CAL_LEN_ERR | SRX_EV_CAL_DIAG_ERR \
                                                | SRX_EV_NIB_VAL_ERR  | SRX_EV_SMSG_CRC_ERR | SRX_EV_FMSG_CRC_ERR | SRX_EV_NUM_EDGES_ERR)) /* All flags */
#define SRX_EV_NONE                              ((uint32)(~(SRX_EV_ALL))) /* No events */

/* FMSG_DATA Bit Fields */
#define SRX_FMSG_DATA_DNIB6_MASK                 0xFu
#define SRX_FMSG_DATA_DNIB6_SHIFT                0u
#define SRX_FMSG_DATA_DNIB6_WIDTH                4u
#define SRX_FMSG_DATA_DNIB5_MASK                 0xF0u
#define SRX_FMSG_DATA_DNIB5_SHIFT                4u
#define SRX_FMSG_DATA_DNIB5_WIDTH                4u
#define SRX_FMSG_DATA_DNIB4_MASK                 0xF00u
#define SRX_FMSG_DATA_DNIB4_SHIFT                8u
#define SRX_FMSG_DATA_DNIB4_WIDTH                4u
#define SRX_FMSG_DATA_DNIB3_MASK                 0xF000u
#define SRX_FMSG_DATA_DNIB3_SHIFT                12u
#define SRX_FMSG_DATA_DNIB3_WIDTH                4u
#define SRX_FMSG_DATA_DNIB2_MASK                 0xF0000u
#define SRX_FMSG_DATA_DNIB2_SHIFT                16u
#define SRX_FMSG_DATA_DNIB2_WIDTH                4u
#define SRX_FMSG_DATA_DNIB1_MASK                 0xF00000u
#define SRX_FMSG_DATA_DNIB1_SHIFT                20u
#define SRX_FMSG_DATA_DNIB1_WIDTH                4u
#define SRX_FMSG_DATA_SCNIB_MASK                 0xF000000u
#define SRX_FMSG_DATA_SCNIB_SHIFT                24u
#define SRX_FMSG_DATA_SCNIB_WIDTH                4u
#define SRX_FMSG_DATA_CHNUM_MASK                 0xF0000000u
#define SRX_FMSG_DATA_CHNUM_SHIFT                28u
#define SRX_FMSG_DATA_CHNUM_WIDTH                4u
/* FMSG_CRC Bit Fields */
#define SRX_FMSG_CRC_CRC4b_MASK                  0xF0000u
#define SRX_FMSG_CRC_CRC4b_SHIFT                 16u
#define SRX_FMSG_CRC_CRC4b_WIDTH                 4u
/* FMSG_TS Bit Fields */
#define SRX_FMSG_TS_TS_MASK                      0xFFFFFFFFu
#define SRX_FMSG_TS_TS_SHIFT                     0u
#define SRX_FMSG_TS_TS_WIDTH                     32u
/* SMSG_BIT3 Bit Fields */
#define SRX_SMSG_BIT3_ID3_0_DATA15_12_MASK       0x1Eu
#define SRX_SMSG_BIT3_ID3_0_DATA15_12_SHIFT      1u
#define SRX_SMSG_BIT3_ID3_0_DATA15_12_WIDTH      4u
#define SRX_SMSG_BIT3_ID7_4_ID3_0_MASK           0x3C0u
#define SRX_SMSG_BIT3_ID7_4_ID3_0_SHIFT          6u
#define SRX_SMSG_BIT3_ID7_4_ID3_0_WIDTH          4u
#define SRX_SMSG_BIT3_CFG_MASK                   0x400u
#define SRX_SMSG_BIT3_CFG_SHIFT                  10u
#define SRX_SMSG_BIT3_CFG_WIDTH                  1u
#define SRX_SMSG_BIT3_TYPE_MASK                  0x8000000u
#define SRX_SMSG_BIT3_TYPE_SHIFT                 27u
#define SRX_SMSG_BIT3_TYPE_WIDTH                 1u
#define SRX_SMSG_BIT3_CHNUM_MASK                 0xF0000000u
#define SRX_SMSG_BIT3_CHNUM_SHIFT                28u
#define SRX_SMSG_BIT3_CHNUM_WIDTH                4u
/* SMSG_BIT2 Bit Fields */
#define SRX_SMSG_BIT2_DATA_MASK                  0xFFFu
#define SRX_SMSG_BIT2_DATA_SHIFT                 0u
#define SRX_SMSG_BIT2_DATA_WIDTH                 12u
#define SRX_SMSG_BIT2_SMCRC_MASK                 0x3F0000u
#define SRX_SMSG_BIT2_SMCRC_SHIFT                16u
#define SRX_SMSG_BIT2_SMCRC_WIDTH                6u
/* SMSG_TS Bit Fields */
#define SRX_SMSG_TS_TS_MASK                      0xFFFFFFFFu
#define SRX_SMSG_TS_TS_SHIFT                     0u
#define SRX_SMSG_TS_TS_WIDTH                     32u

/**
 * @brief Idle check configuration
 *
 * Contains the possible values use in setting
 * up the IDLE pulse diagnostics.
 *
 * Implements : srx_idle_cnt_cfg_t_Class
 */
typedef enum
{
    SRX_BUS_IDLE_DISABLED,
    SRX_BUS_IDLE_245_CLK_TICKS,
    SRX_BUS_IDLE_508_CLK_TICKS,
    SRX_BUS_IDLE_1016_CLK_TICKS,
    SRX_BUS_IDLE_2032_CLK_TICKS
} srx_idle_cnt_cfg_t;

/**
 * @brief Calibration configuration
 *
 * Contains the allowed values for configuring
 * the variance in the calibration pulse.
 *
 * Implements : srx_calib_pulse_var_cfg_t_Class
 */
typedef enum
{
    SRX_CALIB_VAR_20_PERCENT,
    SRX_CALIB_VAR_25_PERCENT
} srx_calib_pulse_var_cfg_t;

/**
 * @brief Diagnostics pulse configuration
 *
 * Contains the possible value for configuring
 * the diagnostics pulse checks.
 *
 * Implements : srx_pulse_cfg_t_Class
 */
typedef enum
{
    SRX_PULSE_CHECK_BOTH,
    SRX_PULSE_CHECK_PAUSE
} srx_pulse_cfg_t;

/**
 * @brief Pause pulse configuration
 *
 * Contains the possible value of the PAUSE pulse
 * configuration.
 *
 * Implements : srx_pause_pulse_cfg_t_Class
 */
typedef enum
{
    SRX_PAUSE_PULSE_DISABLED,
    SRX_PAUSE_PULSE_ENABLED
} srx_pause_pulse_cfg_t;

/**
 * @brief Successive calibration check method
 *
 * This contains the values use in the configuration
 * for the successive calibration pulse check field.
 *
 * Implements : srx_succ_cal_check_cfg_t_Class
 */
typedef enum
{
    SRX_SUCC_CAL_CHK_LOW_LATENCY,
    SRX_SUCC_CAL_CHK_PREFFERED
} srx_succ_cal_check_cfg_t;

/**
 * @brief Fast/Slow CRC type
 *
 * Contains the possible values for the configuration
 * of the CRC type.
 *
 * Implements : srx_msg_crc_t_Class
 */
typedef enum
{
    SRX_CRC_RECOMMENDED, /* Additional 0 data nibble XORed with the rest of the nibbles */
    SRX_CRC_LEGACY /* No additional 0 data nibble is XORed */
} srx_msg_crc_t;

/**
 * @brief Pause pulse configuration
 *
 * Contains the possible value of the PAUSE pulse
 * configuration.
 *
 * Implements :srx_fcrc_sc_cfg_t_Class
 */
typedef enum
{
    SRX_FCRC_NOT_INCLUDE,
    SRX_FCRC_INCLUDE
} srx_fcrc_sc_cfg_t;

/**
 * @brief Pause pulse configuration
 *
 * Contains the possible value of the PAUSE pulse
 * configuration.
 *
 * Implements : srx_fcrc_check_cfg_t_Class
 */
typedef enum
{
    SRX_FCRC_CHECK_ENABLE,
    SRX_FCRC_CHECK_DISABLE
} srx_fcrc_check_cfg_t;

/**
 * @brief Raw message data type
 *
 * Raw message type. It is the actual format transferred by the
 * DMA peripheral and contained inside the Rx channel registers.
 *
 * Implements : srx_raw_msg_t_Class
 */
typedef struct
{
    uint32 dataField0; /*!< Raw data field [0] */
    uint32 dataField1; /*!< Raw data field [1] */
    uint32 dataField2; /*!< Raw data field [2] */
} srx_raw_msg_t;

/**
 * @brief Actual format for a Fast message
 *
 * Contains the actual fields of a complete FAST message.
 *
 * Implements : srx_fast_msg_t_Class
 */
typedef struct
{
    uint32 data; /*!< Data field formed from all possible nibbles */
    uint32 timeStamp; /*!< Message timestamp */
    uint8 channelNumber; /*!< Channel number, 4 bits */
    uint8 statusField; /*!< Status field for the message, 2 bits */
    uint8 crc; /*!< CRC for the fast message, 4 bits */
} srx_fast_msg_t;

/**
 * @brief Slow message type
 *
 * This is determined by the peripheral, at reception.
 *
 * Implements : srx_slow_msg_type_t_Class
 */
typedef enum
{
    SRX_SLOW_TYPE_SHORT, /*!< Standard 4 bit ID, 8 bit Data */
    SRX_SLOW_TYPE_ENHANCED_4_BIT, /*!< Enhanced 4 bit ID, 16 bit Data */
    SRX_SLOW_TYPE_ENHANCED_8_BIT /*!< Enhanced 8 bit ID, 12 bit Data */
} srx_slow_msg_type_t;

/**
 * @brief Actual format for a Slow message
 *
 * Contains the actual fields of a complete SLOW message
 * Lengths for the actual fields depend on the actual message type
 * Please see the SAE J2716 specification.
 *
 * Implements : srx_slow_msg_t_Class
 */
typedef struct
{
    uint32 timeStamp; /*!< Message timestamp */
    uint16 data; /*!< Data field */
    srx_slow_msg_type_t type; /*!< Message type */
    uint8 id; /*!< Message ID */
    uint8 channelNumber; /*!< Channel number, 4 bits */
    uint8 crc; /*!< CRC for the slow message, max 6 bits */
} srx_slow_msg_t;

/**
 * @brief Input filter settings
 *
 * Contains all the possible values for configuring
 * the channel hardware input filter (glitch filter).
 * It is expressed in a number of protocol clocks
 * during which the signal should maintain it's value
 * to be considered stable.
 *
 * Implements : srx_channel_input_filter_t_Class
 */
typedef enum
{
    SRX_INPUT_FILTER_NONE, /*!< No filtering */
    SRX_INPUT_FILTER_1,
    SRX_INPUT_FILTER_2,
    SRX_INPUT_FILTER_4,
    SRX_INPUT_FILTER_8,
    SRX_INPUT_FILTER_16,
    SRX_INPUT_FILTER_32,
    SRX_INPUT_FILTER_64,
    SRX_INPUT_FILTER_128
} srx_channel_input_filter_t;

/**
 * @brief Type of issued callback
 *
 * Implements : srx_callback_type_t_Class
 */
typedef enum
{
    SRX_CALLBACK_SLOW_DMA_RX_COMPLETE,
    SRX_CALLBACK_FAST_DMA_RX_COMPLETE,
    SRX_CALLBACK_SLOW_RX_COMPLETE,
    SRX_CALLBACK_FAST_RX_COMPLETE,
    SRX_CALLBACK_RX_ERROR
} srx_callback_type_t;

/**
 * @brief Type of callback function
 *
 * Implements : srx_callback_func_t_Class
 */
typedef void(* srx_callback_func_t)(uint32 instance, uint32 channel, srx_callback_type_t type, void * param);

/**
 * @brief Type of callback structure
 *
 * Implements : srx_callback_t_Class
 */
typedef struct
{
    srx_callback_func_t function; /*!< Callback function */
    void * param; /*!< User parameter */
} srx_callback_t;

/**
 * @brief Fast messages configuration
 *
 * Contains all the necessary fields used in the
 * configuration of the fast message channel.
 *
 * Implements : srx_fast_msg_config_t_Class
 */
typedef struct
{
    /* Message length */
    uint8 numberOfNibbles; /*!< Number of nibbles for the message. Valid values 1 >= x <= 6 */

    /* DMA enabler for the specific channel */
    boolean dmaEnable; /*!< Enable DMA transfers */

    /* CRC related */
    srx_fcrc_sc_cfg_t crcIncludeStatus; /*!< Include the STATUS nibble in the CRC calculation */
    srx_fcrc_check_cfg_t disableCrcCheck; /*!< Disable CRC checks for the channel */
    srx_msg_crc_t crcType; /*!< CRC type */
} srx_fast_msg_config_t;

/**
 * @brief Slow messages configuration
 *
 * Contains all the necessary fields used in the
 * configuration of the slow message channel.
 *
 * Implements : srx_slow_msg_config_t_Class
 */
typedef struct
{
    /* DMA enabler for the specific channel */
    boolean dmaEnable; /*!< Enable DMA transfers */

    /* CRC related */
    srx_msg_crc_t crcType; /*!< CRC type */
} srx_slow_msg_config_t;

/**
 * @brief Diagnostics configuration
 *
 * Contains all the fields used in the configuration of the
 * diagnostics side of the driver. For a better understanding
 * of these settings, the SAE J2716 specification and
 * the user manual for the current part should be read.
 *
 * Implements : srx_diag_config_t_Class
 */
typedef struct
{
    uint32 diagEvents; /*!< Flags for active diagnostics events */
    srx_idle_cnt_cfg_t idleCount; /*!< Maximum allowed IDLE time */
    srx_calib_pulse_var_cfg_t calibVar; /*!< Valid calibration pulse range */
    srx_pulse_cfg_t diagPulse; /*!< Selection for which diagnostics to run for pulses*/
    srx_pause_pulse_cfg_t pausePulse; /*!< Selection of PAUSE pulse*/
    srx_succ_cal_check_cfg_t succesiveCal; /*!< Successive calibration check method */
} srx_diag_config_t;

/**
 * @brief Channel configuration structure
 *
 * Contains all the required fields for the configuration
 * of a single channel inside the peripheral.
 *
 * Implements : srx_channel_config_t_Class
 */
typedef struct
{
    uint8 channelId; /*!< Designated channel */
    uint8 tickDuration; /*!< Tick duration in microseconds */
    srx_channel_input_filter_t inputFilter; /*!< Channel input filter configuration */
    srx_diag_config_t diagConfig; /*!< Diagnostics configuration structure*/
    srx_fast_msg_config_t fastMsgConfig; /*!< Fast messages configuration structure */
    srx_slow_msg_config_t slowMsgConfig; /*!< Slow messages configuration structure */
} srx_channel_config_t;

/**
 * @brief State structure
 *
 * Contains internal driver state data.
 *
 * Implements : srx_state_t_Class
 */
typedef struct
{
/*! @cond DRIVER_INTERNAL_USE_ONLY */
    /* Configuration data */
    srx_raw_msg_t * fastMsgDmaPtr; /*!< DMA transfer target pointer for fast messages */
    srx_raw_msg_t * slowMsgDmaPtr; /*!< DMA transfer target pointer for slow messages */
    uint8 fastDmaChannel; /*!< DMA channel on which fast message transfers are performed */
    uint8 slowDmaChannel; /*!< DMA channel on which slow message transfers are performed */
    srx_callback_t callbackFunc; /*!< Callback function */
    uint32 channelEvents[SRX_CHANNEL_COUNT]; /*!< Event configuration for each channel */
    boolean activeChannels[SRX_CHANNEL_COUNT]; /*!< Activation state for the specific channel */
    boolean fastDmaEnabled[SRX_CHANNEL_COUNT]; /*!< Holds the state for the Fast DMA channel */
    boolean slowDmaEnabled[SRX_CHANNEL_COUNT]; /*!< Holds the state for the Slow DMA channel */
    uint8 instanceId; /*!< Instance Id number */
/*! @endcond */
} srx_state_t;

/**
 * IRQ IDs
 */
typedef enum {
    SRX_IRQ_FAST = 0,
    SRX_IRQ_SLOW = 1,
    SRX_IRQ_ERROR = 2
} srx_interrupt_id_t;

/**
 * @brief Configuration structure
 *
 * Contains all the fields necessary for a complete
 * configuration of the peripheral
 *
 * Implements : srx_driver_user_config_t_Class
 */
typedef struct
{
    /* Dma related transfers are common to all channels */
    srx_raw_msg_t * fastMsgDmaPtr; /*!< Initial DMA target buffer */
    srx_raw_msg_t * slowMsgDmaPtr; /*!< Initial DMA target buffer */
    srx_callback_t callbackFunc; /*!< Callback function */
    uint8 slowDmaChannel; /*!< Assigned DMA channel for slow messages */
    uint8 fastDmaChannel; /*!< Assigned DMA channel for fast messages */
    boolean fastDmaFIFOEnable; /*!< Enable FIFO for Fast DMA transfers */
    uint8 fastDmaFIFOSize; /*!< Minimum FIFO size to trigger a Fast DMA transfer */

    /* Unique instances for each channel */
    const srx_channel_config_t * channelConfig; /*!< Pointer to a channel configuration list */
    uint8 numOfConfigs; /*!< Number of configurations in the channel configuration list */
} srx_driver_user_config_t;


FUNC(void, SENT_CODE) SRX_LLD_SetTimestampPrescaler(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) value);
FUNC(void, SENT_CODE) SRX_LLD_SetChannelPrescaler(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(uint16 , AUTOMATIC) prescaler);
FUNC(void, SENT_CODE) SRX_LLD_SetChannelCompensation(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) state);
FUNC(void, SENT_CODE) SRX_LLD_SetChannelStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint16 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable);
FUNC(void, SENT_CODE) SRX_LLD_SetPeripheralStatus(CONST(uint8, AUTOMATIC) instance, CONST(boolean, AUTOMATIC) enable);
FUNC(void, SENT_CODE) SRX_LLD_SetFastRxInterrupt(CONST(uint8, AUTOMATIC) instance, CONST(uint16 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable);
FUNC(boolean, SENT_CODE) SRX_HW_GetSlowRxStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
FUNC(void, SENT_CODE) SRX_LLD_SetSlowRxInterrupt(CONST(uint8, AUTOMATIC) instance, CONST(uint16 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable);
FUNC(void, SENT_CODE) SRX_LLD_GetFastRawMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2VAR(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg);
FUNC(void, SENT_CODE) SRX_LLD_InitDiag(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2CONST(srx_diag_config_t, AUTOMATIC, SENT_APPL_DATA) config);
FUNC(void, SENT_CODE) SRX_LLD_InitSlowMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2CONST(srx_slow_msg_config_t, AUTOMATIC, SENT_APPL_DATA) config);
FUNC(void, SENT_CODE) SRX_LLD_InitFastMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2CONST(srx_fast_msg_config_t, AUTOMATIC, SENT_APPL_DATA) config);
FUNC(uint8, SENT_CODE) SRX_LLD_CompTimestampPrescaler(CONST(uint32, AUTOMATIC) u32clock);
FUNC(uint32, SENT_CODE) SRX_LLD_ComputeChannelPrescaler(CONST(uint8, AUTOMATIC) reqTick, CONST(uint32, AUTOMATIC) u32clock);
FUNC(void, SENT_CODE) SRX_LLD_IRQ_FastHandler(CONST(uint8 , AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
FUNC(void, SENT_CODE) SRX_LLD_GetEvents(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, P2VAR(uint32, AUTOMATIC, SENT_APPL_DATA) events);
FUNC(void, SENT_CODE) SRX_LLD_GetFastMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, P2VAR(srx_fast_msg_t, AUTOMATIC, SENT_APPL_DATA) message);
FUNC(void, SENT_CODE) SRX_LLD_GetSlowMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, P2VAR(srx_slow_msg_t, AUTOMATIC, SENT_APPL_DATA) message);
FUNC(void, SENT_CODE) SRX_LLD_GetFastMsgFromRaw(P2VAR(srx_fast_msg_t, AUTOMATIC, SENT_APPL_DATA) msg, P2CONST(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg);
FUNC(void, SENT_CODE) SRX_LLD_GetSlowMsgFromRaw(P2VAR(srx_slow_msg_t, AUTOMATIC, SENT_APPL_DATA) msg, P2CONST(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg);
FUNC(boolean, SENT_CODE) SRX_LLD_GetSlowRxStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
FUNC(boolean, SENT_CODE) SRX_LLD_GetFastRxStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
FUNC(void, SENT_CODE) SRX_LLD_Deinit(CONST(uint8, AUTOMATIC) instance);
FUNC(void, SENT_CODE) SRX_LLD_IRQ_SlowHandler(CONST(uint8 , AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);
FUNC(void, SENT_CODE) SRX_LLD_IRQ_RxErrHandler(CONST(uint8 , AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel);

#endif /* LLD_INC_SRX_LLD_H_ */
