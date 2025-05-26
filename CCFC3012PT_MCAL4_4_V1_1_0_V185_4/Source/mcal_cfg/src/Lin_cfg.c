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
*   @file    Lin_cfg.c
*   @implements Lin_cfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup Lin
*   @{
*/


#ifdef __cplusplus
extern "C"
{
#endif


/*======================================INCLUDE FILES===============================================*/
#include "StandardTypes.h"
#include "Lin_Cfg.h"
#include "Lin.h"
#include "eDma.h"
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_WRAPPER_C_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_WRAPPER_C_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_WRAPPER_C_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_WRAPPER_C_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_WRAPPER_C_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_WRAPPER_C_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_WRAPPER_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_WRAPPER_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_WRAPPER_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_WRAPPER_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_WRAPPER_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_WRAPPER_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_WRAPPER_C_SW_PATCH_VER "
#endif
/*=========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)===============================*/

/*======================================LOCAL MACROS================================================*/

/*=====================================LOCAL CONSTANTS==============================================*/

/*=====================================LOCAL VARIABLES==============================================*/

/*=====================================GLOBAL CONSTANTS=============================================*/

#define LIN_START_SEC_CONFIG_DATA
#include "Lin_MemMap.h"



static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_0=
{
    (uint8)0U,              /* Lin Channel ID */
    LinHWCh_0,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00028b01U,            /* Baudrate 9600 ; Baudrate difference = 0.04166666666662877 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x03U, /* BreakLengthMaster = BL_13 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_1=
{
    (uint8)1U,              /* Lin Channel ID */
    LinHWCh_1,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00014508U,            /* Baudrate 19200 ; Baudrate difference = 0.5208333333333144 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x03U, /* BreakLengthMaster = BL_13 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_2=
{
    (uint8)2U,              /* Lin Channel ID */
    LinHWCh_14,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00145805U,            /* Baudrate 1200 ; Baudrate difference = 0.33333333333303017 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0aU, /* BreakLengthMaster = BL_20 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_3=
{
    (uint8)3U,              /* Lin Channel ID */
    LinHWCh_16,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x000a2c03U,            /* Baudrate 2400 ; Baudrate difference = 0.16666666666651508 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0bU, /* BreakLengthMaster = BL_21 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_4=
{
    (uint8)4U,              /* Lin Channel ID */
    LinHWCh_2,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00051601U,            /* Baudrate 4800 ; Baudrate difference = 0.08333333333325754 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0cU, /* BreakLengthMaster = BL_22 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_5=
{
    (uint8)5U,              /* Lin Channel ID */
    LinHWCh_3,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00051601U,            /* Baudrate 4800 ; Baudrate difference = 0.08333333333325754 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0dU, /* BreakLengthMaster = BL_23 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_6=
{
    (uint8)6U,              /* Lin Channel ID */
    LinHWCh_4,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x0001b200U,            /* Baudrate 14400 ; Baudrate difference = 0.027777777777771462 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0dU, /* BreakLengthMaster = BL_23 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_7=
{
    (uint8)7U,              /* Lin Channel ID */
    LinHWCh_15,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x0001b200U,            /* Baudrate 14400 ; Baudrate difference = 0.027777777777771462 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0dU, /* BreakLengthMaster = BL_23 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_8=
{
    (uint8)8U,              /* Lin Channel ID */
    LinHWCh_6,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00014508U,            /* Baudrate 19200 ; Baudrate difference = 0.5208333333333144 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0bU, /* BreakLengthMaster = BL_21 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_9=
{
    (uint8)9U,              /* Lin Channel ID */
    LinHWCh_7,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00014508U,            /* Baudrate 19200 ; Baudrate difference = 0.5208333333333144 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0bU, /* BreakLengthMaster = BL_21 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_10=
{
    (uint8)10U,              /* Lin Channel ID */
    LinHWCh_8,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00014508U,            /* Baudrate 19200 ; Baudrate difference = 0.5208333333333144 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0bU, /* BreakLengthMaster = BL_21 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_11=
{
    (uint8)11U,              /* Lin Channel ID */
    LinHWCh_9,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00028b01U,            /* Baudrate 9600 ; Baudrate difference = 0.04166666666662877 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0cU, /* BreakLengthMaster = BL_22 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_12=
{
    (uint8)12U,              /* Lin Channel ID */
    LinHWCh_10,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00028b01U,            /* Baudrate 9600 ; Baudrate difference = 0.04166666666662877 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0cU, /* BreakLengthMaster = BL_22 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_13=
{
    (uint8)13U,              /* Lin Channel ID */
    LinHWCh_11,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00028b01U,            /* Baudrate 9600 ; Baudrate difference = 0.04166666666662877 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0cU, /* BreakLengthMaster = BL_22 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };

static CONST(Lin_ChannelConfigType,LIN_CONST) Lin_LinChannel_14=
{
    (uint8)14U,              /* Lin Channel ID */
    LinHWCh_12,              /* Lin Hardware channel*/
    LIN_MASTER_NODE,        /* Lin Node Type */
    0x00028b01U,            /* Baudrate 9600 ; Baudrate difference = 0.04166666666662877 */
    STD_ON,         /* Wakeup support enabled */
    
    (EcuM_WakeupSourceType)LIN_NONE_ECUM_WAKEUP_SOURCE_REF, /* None Wakeup Source was referred */   
        
    0x0cU, /* BreakLengthMaster = BL_22 bits */
    10U, /* BreakLengthSlave = BL_10 bits */
    14U, /* Response timeout value LINTOCR[RTO] */
    44U,  /* Header timeout value LINTOCR[HTO] */
    STD_OFF,
    0,
    0,
    };



static CONST(Lin_CoreMapItemType, GPT_CONST) Lin_CoreMap[LIN_HW_MAX_MODULES]=
{

    
    {
        .u16Lin_SIUPin = 0,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 1,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 2,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 3,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 4,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 5,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 6,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 7,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 8,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 9,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 10,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 11,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 12,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 13,        
        .u8CoreId = 0

    },

    
    {
        .u16Lin_SIUPin = 14,        
        .u8CoreId = 0

    },
 
};



/* Specification of Lin Driver : [SWS_Lin_00225] */
CONST(Lin_ConfigType,LIN_CONST)LinGlobalConfig =
{
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)

    {(uint32)STD_OFF, 0U}, /* LIN_E_TIMEOUT parameters*/
        
#endif /* LIN_DISABLE_DEM_REPORT_ERROR_STATUS== STD_OFF */

    15U,
    {

        &Lin_LinChannel_0,
                    
        &Lin_LinChannel_1,
                    
        &Lin_LinChannel_2,
                    
        &Lin_LinChannel_3,
                    
        &Lin_LinChannel_4,
                    
        &Lin_LinChannel_5,
                    
        &Lin_LinChannel_6,
                    
        &Lin_LinChannel_7,
                    
        &Lin_LinChannel_8,
                    
        &Lin_LinChannel_9,
                    
        &Lin_LinChannel_10,
                    
        &Lin_LinChannel_11,
                    
        &Lin_LinChannel_12,
                    
        &Lin_LinChannel_13,
                    
        &Lin_LinChannel_14
                    
    },
    Lin_CoreMap,
};


#define LIN_STOP_SEC_CONFIG_DATA
#include "Lin_MemMap.h"
/*=====================================GLOBAL VARIABLES=============================================*/

/*==================================LOCAL FUNCTION PROTOTYPES=======================================*/

/*======================================LOCAL FUNCTIONS=============================================*/

/*======================================GLOBAL FUNCTIONS============================================*/



#ifdef __cplusplus
}
#endif

/** @} */
