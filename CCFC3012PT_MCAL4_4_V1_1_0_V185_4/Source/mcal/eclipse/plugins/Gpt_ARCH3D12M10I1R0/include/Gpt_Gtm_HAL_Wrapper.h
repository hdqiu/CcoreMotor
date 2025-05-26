/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Gpt_Gtm_HAL_Wrapper.h
*   @version 1.0.1
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Gpt MCAL driver.
*
*   @addtogroup Gpt
*   @{
*/
#if ( defined(CCFC3012PT) ||defined(CCFC3007PT)||defined(CCFC3008PT))
#ifndef GPT_GTM_HAL_WRAPPER_H
#define GPT_GTM_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Gpt_Cfg.h"
#if ( defined(CCFC3012PT))
#include "Gpt_Gtm410_LLDriver.h"
#endif
#if (defined(CCFC3007PT)||defined(CCFC3008PT))
#include "Gpt_Gtm_LLDriver.h"
#endif
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define GPT_VENDOR_ID_H                     176
#define GPT_MODULE_ID_H                     100
#define GPT_AR_MAJOR_VER_H                  4
#define GPT_AR_MINOR_VER_H                  4
#define GPT_AR_PATCH_VER_H                  0
#define GPT_SW_MAJOR_VER_H                  1
#define GPT_SW_MINOR_VER_H                  0
#define GPT_SW_PATCH_VER_H                  1

/*============================================FILE VERSION CHECKS===================================*/

#if (GPT_VENDOR_ID_H != GPT_VENDOR_ID)
#error "NON-MATCHED DATA : GPT_CFG_VENDOR_ID"
#endif

#if (GPT_AR_MAJOR_VER_H != GPT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER"
#endif
#if (GPT_AR_MINOR_VER_H != GPT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER"
#endif
#if (GPT_AR_PATCH_VER_H != GPT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER"
#endif

#if (GPT_SW_MAJOR_VER_H != GPT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER"
#endif
#if (GPT_SW_MINOR_VER_H != GPT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER"
#endif
#if (GPT_SW_PATCH_VER_H != GPT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER"
#endif
/*=================================================Constants========================================*/

/*============================================DEFINES AND MACROS====================================*/

/*===================================================ENUMS==========================================*/

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

/*==============================================GLOBAL FUNCTIONS====================================*/
FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_Init
(
    VAR(uint8,      AUTOMATIC) u8Gtm_HwChannel,
    VAR(uint32,     AUTOMATIC) u32Gtm_ChannelRegCtrl1, 
#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    VAR(boolean,    AUTOMATIC) bGtm_SupportOutputEnable,
#endif	
    VAR(boolean,    AUTOMATIC) bGtm_FreezeEnable
);

FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_DeInit(VAR(uint8, AUTOMATIC) u8Gtm_HwChannel);

FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_Channel_StartTimer	\
( 														\
    VAR(uint8,      AUTOMATIC) u8Gtm_HwChannel, \
    VAR(uint32,     AUTOMATIC) u32Gtm_Value 	\
);

FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_StopTimer(VAR(uint8, AUTOMATIC) u8Gtm_HwChannel);

FUNC(uint32, GPT_CODE) Gpt_Gtm_Wrapper_GetTimeElapsed					\
( 																		\
    VAR(uint8,      AUTOMATIC) u8Gtm_HwChannel, 						\
    P2VAR(boolean,  AUTOMATIC, GPT_APPL_DATA) pbGtm_IsChannelRollover, 	\
    P2VAR(uint32,   AUTOMATIC, GPT_APPL_DATA) pu32Gtm_TargetValue 		\
);

FUNC(uint32, GPT_CODE) Gpt_Gtm_Wrapper_GetTimeRemaining	\
( 														\
    VAR(uint8, AUTOMATIC) u8Gtm_HwChannel 				\
);

FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_EnableInterrupt \
( 													 \
    VAR(uint8,      AUTOMATIC) u8Gtm_HwChannel 		 \
);

FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_DisableInterrupt	\
( 														\
    VAR(uint8,      AUTOMATIC) u8Gtm_HwChannel 			\
);
#if (defined(CCFC3012PT))
FUNC(void, GPT_CODE) Gpt_GtmCmu_Wrapper_Init    \
(                                               \
		P2CONST(GPT_GTM_CMU_LLD_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr \
);

FUNC(void, GPT_CODE) Gpt_GtmTbu_Wrapper_Init	\
(												\
	P2CONST(GPT_GTM_TBU_LLD_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr \
);
#endif

FUNC(void, GPT_CODE) Gpt_GtmCmu_Wrapper_Deinit(void);
FUNC(void, GPT_CODE) Gpt_GtmTbu_Wrapper_Deinit(void);

#ifdef __cplusplus
}
#endif

#endif // GPT_GTM_HAL_WRAPPER_H
#endif

