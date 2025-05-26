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
*   @file    Lin_LLDriver.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Low level driver header file.
*   @details This file includes the function prototypes defined in the LIN low level driver for LinFlex.
*
*   @addtogroup MCAL
*   @{
*/


#ifndef LINFLEX_H
#define LINFLEX_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ==============================================INCLUDE FILES=======================================*/
#include "Lin_Types.h"
#include "Lin.h"
#include "intc_lld.h"
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_LLD_H_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_LLD_H_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_LLD_H_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_LLD_H_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_LLD_H_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_LLD_H_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_LLD_H_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_LLD_H_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_LLD_H_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_LLD_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_LLD_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_LLD_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_LLD_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_LLD_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_LLD_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_LLD_H_SW_PATCH_VER "
#endif
/*=================================================CONSTANTS========================================*/

/*============================================DEFINES AND MACROS====================================*/                                           
#define LINFLEX_BIDR_DFL_EXT_MASK_U32  ((uint32)0x0000FC00UL)
#define LINFLEX_BIDR_DFL_MASK_U32      ((uint32)0x00000007UL)
#define LINFLEX_LINCR2_HTRQ_MASK_U32   ((uint32)0x00000100UL)
#define LINFLEX_LINCR2_ABRQ_MASK_U32   ((uint32)0x00000200UL)
#define LINFLEX_LINCR2_DTRQ_MASK_U32   ((uint32)0x00000400UL)
#define LINFLEX_LINCR2_REQUEST_MASK_U32    ((uint32)(LINFLEX_LINCR2_DTRQ_MASK_U32 | LINFLEX_LINCR2_ABRQ_MASK_U32 | LINFLEX_LINCR2_HTRQ_MASK_U32))
#define LINFLEX_LINFBRR_FBR_MASK_U32   ((uint32)0x0000000FUL)
#define LINFLEX_LINFBRR_DIV_F_MASK_U32 ((uint32)0x000000FFUL)
#define LINFLEX_LINIBRR_DIV_M_MASK_U32 ((uint32)0xFFFFFF00UL)
#define LIN_NUM_FILTER                                  16U   /** LIN driver number of filters **/

/**
* @brief    LINFLEX Registers bits.
* @details  LINSR register bit masks.
*/
#define LINFLEX_LINSR_HRF_MASK_U32     ((uint32)0x00000001UL)
#define LINFLEX_LINSR_DTF_MASK_U32     ((uint32)0x00000002UL)
#define LINFLEX_LINSR_DRF_MASK_U32     ((uint32)0x00000004UL)
#define LINFLEX_LINSR_WUF_MASK_U32     ((uint32)0x00000020UL)
#define LINFLEX_LINSR_DRBNE_MASK_U32   ((uint32)0x00000100UL)
#define LINFLEX_LINSR_RXBUSY_MASK_U32  ((uint32)0x00000080UL)
#define LINFLEX_LINSR_RMB_MASK_U32     ((uint32)0x00000200UL)
#define LINFLEX_LINSR_LINS_MASK_U32    ((uint32)0x0000F000UL)
#define LINFLEX_LINSR_FLAGS_MASK_U32   ((uint32)0x0000033FUL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINESR register bit masks.
*/
#define LINFLEX_LINESR_NF_MASK_U32     ((uint32)0x00000001UL)
#define LINFLEX_LINESR_BOF_MASK_U32    ((uint32)0x00000080UL)
#define LINFLEX_LINESR_FEF_MASK_U32    ((uint32)0x00000100UL)
#define LINFLEX_LINESR_IDPEF_MASK_U32  ((uint32)0x00000200UL)
#define LINFLEX_LINESR_SDEF_MASK_U32   ((uint32)0x00000400UL)
#define LINFLEX_LINESR_SFEF_MASK_U32   ((uint32)0x00000800UL)
#define LINFLEX_LINESR_CEF_MASK_U32    ((uint32)0x00001000UL)
#define LINFLEX_LINESR_BEF_MASK_U32    ((uint32)0x00002000UL)
#define LINFLEX_LINESR_OCF_MASK_U32    ((uint32)0x00004000UL)
#define LINFLEX_LINESR_SZF_MASK_U32    ((uint32)0x00008000UL)
#define LINFLEX_LINESR_FLAGS_MASK_U32  ((uint32)0x0000FF81UL)

#define LINSR_LINS_IDLE_MASK                     (0x2U) /* PRQA S 1534 */
#define LINFlexD_LINTCSR_MODE_MASK               0x400u
#define LINFlexD_LINTCSR_MODE_SHIFT              10u
#define LINFlexD_LINTCSR_MODE(x)                 (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINTCSR_MODE_SHIFT))&LINFlexD_LINTCSR_MODE_MASK)
#define LINFlexD_LINCR1_INIT_SHIFT               0u
#define LINFlexD_LINCR1_INIT_MASK                0x1u
#define LINFlexD_LINCR1_INIT(x)                  (((uint32_t)(((uint32_t)(x))<<LINFlexD_LINCR1_INIT_SHIFT))&LINFlexD_LINCR1_INIT_MASK)
#define LINFlexD_LINCR1_SLEEP_MASK               0x2u
#define LINFlexD_LINOCR_OC2_MASK                 0xFF00u
#define LINFlexD_LINOCR_OC1_MASK                 0xFFu
#define LIN_DATA_LEN                             8U   /** LIN driver data length **/ /* PRQA S 1534 */
#define LINFLEX_BIDR_ID_MASK                     0x3FU

#define LIN_API_MODE_SYNCHRONOUS               0U   /** < @brief Synchronous API.  */
#define LIN_API_MODE_ASYNCHRONOUS              1U   /** < @brief Asynchronous API. */ /* PRQA S 1534 */
#define LIN_API_MODE_BUFFERED_IO               2U   /** < @brief Buffered IO API (only for Serial). */

#define CCFC3012PT_LINLLDFLEX0L        (LINFlexD_0)
#define CCFC3012PT_LINLLDFLEX1L        (LINFlexD_1)
#define CCFC3012PT_LINLLDFLEX2L        (LINFlexD_2)
#define CCFC3012PT_LINLLDFLEX3L        (LINFlexD_3)
#define CCFC3012PT_LINLLDFLEX4L        (LINFlexD_4)
#define CCFC3012PT_LINLLDFLEX5L        (LINFlexD_5)
#define CCFC3012PT_LINLLDFLEX6L        (LINFlexD_6)
#define CCFC3012PT_LINLLDFLEX7L        (LINFlexD_7)
#define CCFC3012PT_LINLLDFLEX8L        (LINFlexD_8)
#define CCFC3012PT_LINLLDFLEX9L        (LINFlexD_9)
#define CCFC3012PT_LINLLDFLEX10L       (LINFlexD_10)
#define CCFC3012PT_LINLLDFLEX11L       (LINFlexD_11)
#define CCFC3012PT_LINLLDFLEX12L       (LINFlexD_12)
#define CCFC3012PT_LINLLDFLEX14L	   (LINFlexD_14)
#define CCFC3012PT_LINLLDFLEX15L       (LINFlexD_15)
#define CCFC3012PT_LINLLDFLEX16L       (LINFlexD_16)


/*===================================================ENUMS==========================================*/
typedef enum
{
    LIN_SLAVE,                                      /**  LINFlex is in slave mode.        */
    LIN_MASTER                                      /**  LINFlex is in master mode.       */
}lin_node_t;

typedef enum
{
    LIN_ENHANCED_CCS,                               /**  Enhanced Checksum covering Identifier and Data fields. */
    LIN_CLASSIC_CCS                                 /**  Classic Checksum covering Data field only.             */
}lin_ccs_t;

typedef enum
{
    LIN_DIR_RECEIVE,                               /**  LINFlexD receives the data and copies them in the BDRs. */
    LIN_DIR_TRANSMIT                               /**  LINFlexD transmits the data from the BDRs.              */
}lin_message_dir_t;

typedef enum
{
    LIN_LIST,                                       /**  FIlter is configured in list mode. */
    LIN_MASK                                        /**  Filter is configured in mask mode. */
}lin_filter_t;

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

typedef struct LinLldDriver LinLldDrivers;  /** Type of a structure representing a LIN driver. **/
typedef void (*lin_callback_t)(uint8  device);
typedef struct Lin_flexDriver Lin_flexDrivers;
typedef uint32 (*linlldclbk_t)(const LinLldDrivers *ldp, uint8 idMessage, uint8 *buf, uint16 len);

typedef union tmpdata /* PRQA S 1536 */
{
    uint32    w;
    uint8  b[4];
}t_data;


typedef struct /* PRQA S 3630 */
{
    uint8                                  value;    /** Value. Filter value, it is in the range[0, 63] **/
    uint8                               datasize;    /** Message data size. It is in the range[1, 8]. **/
    lin_message_dir_t                  direction;    /** Message direction (Transmit, Receive). **/
    lin_ccs_t                                ccs;    /** Message Checksum Data Type **/
    lin_filter_t                            mode;    /** Mask or List **/
    uint8                             mask_value;    /** Mask Value. Mask Filter value, it is in the range[0, 63] **/
}LinLldFilter;

typedef struct /* PRQA S 3630 */
{
    uint8                                  value;    /** Value. Filter value, it is in the range[0, 63] **/
    uint8                               datasize;    /** Message data size. It is in the range[1, 8]. **/
    lin_message_dir_t                  direction;    /** Message direction (Transmit, Receive). **/
    lin_ccs_t                                ccs;    /** Message Checksum Data Type. **/
}No_LinLldFilter;

typedef struct /* PRQA S 3630 */
{
    uint32                                 speed;    /** Bit rate. **/
    lin_node_t                              mode;    /** Lin Driver Mode flags. **/
    uint8                               api_mode;    /** API Mode flags. **/
    uint8                           DmaTxChannel;
    uint8                           DmaRxChannel;
} LinLldConfig;

struct LinLldDriver
{
    const LinLldConfig                   *config;    /** Current configuration data. **/
    uint8                                *rx_buf;    /** Input Buffer. **/
    uint8                                *tx_buf;    /** Output Buffer. **/
    uint8                        *filter_buf[16];    /** Private buffer of each filter **/
    uint16                                rx_len;    /** Number of bytes to receive. **/
    uint16                                tx_len;    /** Number of bytes to transmit. **/
    uint8                              rx_id_msg;    /** Id of the received message. **/
    uint8                              tx_id_msg;    /** Id of the transmitted message. **/
    uint8                                    ccs;    /** Checksum mode. **/


    volatile struct LINFlexD_tag       *linflexD;
    uint32                                 clock;    /** Clock value for this unit. **/
};


struct Lin_flexDriver{
    uint32                   device;                     /* must be private */
    lin_callback_t rxi_lincallback;                     /* linflex Rx interrupt call back */
    lin_callback_t txi_lincallback;                     /* linflex Tx interrupt call back */
    lin_callback_t err_lincallback;                     /* linflex Err interrupt call back */
};


typedef struct Lin_Config
{
    LinLldDrivers *ldp;
    struct Lin_flexDriver Linflex;
    uint8 mbl; /* Master break length */
    uint8 sbl; /* Slave break length */
    uint8 rto; /* Response TimeOut*/
    uint8 hto; /* Header TimeOut*/
    uint8 DmaSupport;
    uint8 WakeupSupport;
    uint32 WakeupSource;
}Lin_Configs;

/*==============================================GLOBAL FUNCTIONS====================================*/

#define LIN_START_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"

extern volatile VAR(uint8,LIN_VAR)u8Lin_ChStatus[LIN_HW_MAX_AVAILABLE_MODULES];

extern volatile VAR(uint8,LIN_VAR)u8Lin_ChFrameStatus[LIN_HW_MAX_AVAILABLE_MODULES];

extern volatile VAR(uint8,LIN_VAR)u8Lin_ChFrameErrorStatus[LIN_HW_MAX_AVAILABLE_MODULES];

extern VAR(sint8,LIN_VAR)s8Lin_ChannelHardwareMap[LIN_HW_MAX_AVAILABLE_MODULES];

#define LIN_STOP_SEC_VAR_NO_INIT
#include "Lin_MemMap.h"
#define LIN_START_SEC_VAR_INIT
#include "Lin_MemMap.h"
 
extern P2CONST(Lin_ConfigType,LIN_VAR,LIN_APPL_CONST) g_pLin_GenerateConfigPBPtr;
#define LIN_STOP_SEC_VAR_INIT
#include "Lin_MemMap.h"

 
/* Specification of Lin Driver : [SWS_Lin_00013] */
extern P2CONST(Lin_ChannelConfigType,LIN_VAR,LIN_APPL_CONST)g_pLin_ChannelConfigPtr[LIN_HW_MAX_AVAILABLE_MODULES];
 
/*===================================FUNCTION PROTOTYPES============================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

extern FUNC(void, LIN_CODE) LINFLEX0_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX0_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX0_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX1_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX1_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX1_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX2_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX2_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX2_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX3_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX3_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX3_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX4_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX4_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX4_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX5_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX5_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX5_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX6_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX6_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX6_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX7_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX7_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX7_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX8_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX8_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX8_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX9_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX9_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX9_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX10_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX10_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX10_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX11_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX11_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX11_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX12_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX12_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX12_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX14_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX14_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX14_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX15_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX15_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX15_LLD_ERR_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX16_LLD_RXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX16_LLD_TXI_IRQ_HANDLER(void);
extern FUNC(void, LIN_CODE) LINFLEX16_LLD_ERR_IRQ_HANDLER(void);

FUNC(void, LIN_CODE) Lin_LLD_Init(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(LinLldConfig, AUTOMATIC, LIN_APPL_CONST) sLin_Config);

FUNC(void, LIN_CODE) Lin_LLD_Start(CONST(uint8, AUTOMATIC) u8Lin_Channel);

FUNC(Std_ReturnType, LIN_CODE) Lin_LLD_Master_Transmit(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) spLin_PduInfoPtr);

FUNC(Std_ReturnType, LIN_CODE) Lin_LLD_GoToSleep(CONST(uint8, AUTOMATIC) u8Lin_Channel);

FUNC(Std_ReturnType, LIN_CODE) Lin_LLD_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel);

FUNC(void, LIN_CODE) Lin_LLD_WakeupInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel);

FUNC(Std_ReturnType, LIN_CODE) Lin_LLD_CheckWakeup(CONST(uint8, AUTOMATIC) u8Lin_Channel);

FUNC(void, LIN_CODE) Lin_LLD_Wakeup(CONST(uint8, AUTOMATIC) u8Lin_Channel);

FUNC(Lin_StatusType, LIN_CODE) Lin_LLD_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) u8pLin_SduPtr);

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif

#endif /* LINFLEX_H */

/** @} */
