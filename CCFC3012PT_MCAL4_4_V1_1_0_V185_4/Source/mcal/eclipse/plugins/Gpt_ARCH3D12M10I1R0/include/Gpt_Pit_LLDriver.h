/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     Gpt_Pit_LLDriver.h
* @version  1.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/

#ifndef GPT_PIT_LLDRIVER_H
#define GPT_PIT_LLDRIVER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
/*PRQA S 1534,1535,3472 EOF*/
#include "derivative.h"
#include "StandardTypes.h"
#include "Gpt_Cfg.h"
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
#define PIT_0_BASE_ADDR                         ((uint32)&PIT_0)
#define PIT_1_BASE_ADDR                         ((uint32)&PIT_1)
#define PIT_0_BASE                              ((PIT_tag_Type *)PIT_0_BASE_ADDR)
#define PIT_1_BASE                              ((PIT_tag_Type *)PIT_1_BASE_ADDR)
#define PIT_BASE_ARRAY                          {PIT_0_BASE, PIT_1_BASE}

#define PIT_INSTANCE_NUM                        (2U)

#define PIT0_CH_NUM                             (9U)
#define PIT1_CH_NUM                             (2U)

#define GPT_PIT_MODULE_MAX                      (2U)
#define GPT_PIT_MODULE_CHANNEL_MAX              (9U)

#define PIT_CHANNEL_DISABLE 	0u
#define PIT_CHANNEL_ENABLE		1u

#define PIT_MODLE_DISABLE		0u
#define PIT_MODLE_ENABLE		1u


#define PIT_MOD_SHIFT               ((uint8)4U)
#define PIT_CH_MASK_U8              ((uint8)0x0FU)

#define PIT_MODULE_INDEX_U32(ch)    (((ch) >> PIT_MOD_SHIFT) & 0xFU)
#define PIT_CHANNEL_INDEX_U32(ch)   ((ch) & PIT_CH_MASK_U8)

/*===================================================ENUMS==========================================*/
typedef enum
{
    PIT0 = 0U,
    PIT1
}PIT_Module_t;

typedef enum
{
    PIT_Channel0 = 0U,
    PIT_Channel1,
    PIT_Channel2,
    PIT_Channel3,
    PIT_Channel4,
    PIT_Channel5,
    PIT_Channel6,
    PIT_Channel7,
    PIT_RTI
}PIT_Channel_t;
typedef enum
{
    FREEZEOFF = 0U,
    FREEZEON
}PIT_DebugMode_Type;

typedef enum
{
    PIT_Status_Disable = 0U,
    PIT_Status_Enable
}PIT_Status_Type;

typedef enum
{
    RTI_Status_Disable = 0U,
    RTI_Status_Enable
}RTI_Status_Type;

typedef enum
{
    PIT_Period_Count = 0U,
    PIT_Period_US,
    PIT_Period_MS
}PIT_Value_Type;

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

typedef struct PIT_tag PIT_tag_Type;

typedef struct {
    VAR(uint32, GPT_VAR) u32PerClkFreq;
    VAR(uint32, GPT_VAR) u32RtiClkFreq;
}PIT_ClkFreq;
/*==============================================GLOBAL FUNCTIONS====================================*/
FUNC(PIT_Channel_t, GPT_CODE) Gpt_Pit_LLD_ConvertChannelId(VAR(uint8, AUTOMATIC) Channel);
FUNC(PIT_Module_t, GPT_CODE) Gpt_Pit_LLD_ConvertModuleId(VAR(uint8, AUTOMATIC) Module);

FUNC(void, GPT_CODE) Gpt_Pit_IRQHandler(                \
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,     \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID    \
);

FUNC(void, GPT_CODE) Gpt_Pit_LLD_ModuleEnable(VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID);

FUNC(Std_ReturnType, GPT_CODE) Gpt_Rti_LLD_ModuleEnable(VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID);

FUNC(void, GPT_CODE) Gpt_Pit_LLD_Deinit 		    \
( 													\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID 	\
);

FUNC(void, GPT_CODE) Gpt_Pit_LLD_SetDebugFreeze     \
(                                                   \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
   VAR(PIT_DebugMode_Type, AUTOMATIC) PIT_DebugMode \
);

FUNC(void, GPT_CODE) Gpt_Pit_LLD_ChannelEnable 		 \
( 													 \
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
);

FUNC(void, GPT_CODE) Gpt_Pit_LLD_ChannelDisable 	 \
( 													 \
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
);

FUNC(Std_ReturnType, GPT_CODE) Gpt_Pit_LLD_SetLoadValue \
(                                                  \
   VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,      \
   VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,    \
   VAR(uint32, AUTOMATIC) u32Pit_Value,            \
   VAR(PIT_Value_Type, AUTOMATIC) PIT_Value        \
);

FUNC(uint32, GPT_CODE) Gpt_Pit_LLD_GetLoadValue \
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID, 	\
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,\
    VAR(PIT_Value_Type, AUTOMATIC) PIT_Value 	\
);



FUNC(uint8, GPT_CODE) Gpt_Pit_LLD_GetDebugFreeze \
( 												 \
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID 	 \
);

FUNC(void, GPT_CODE) Gpt_Pit_LLD_ClearIntFlag   \
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
);

FUNC(uint32, GPT_CODE) Gpt_Pit_LLD_GetIntFlag 	\
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
);

FUNC(void, GPT_CODE) Gpt_Pit_LLD_SetChIntState 	\
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID, 	\
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,\
    VAR(PIT_Status_Type, AUTOMATIC) eGpt_Pit_InterruptState \
);


FUNC(void, GPT_CODE) Gpt_Pit_LLD_SetChChainMode \
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID,  \
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID,\
    VAR(PIT_Status_Type, AUTOMATIC) eGpt_Stm_Chainmode \
);

FUNC(uint32, GPT_CODE) Gpt_Pit_LLD_GetCurrentValue \
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID, 	\
    VAR(PIT_Channel_t, AUTOMATIC) PIT_ChannelID \
);

FUNC(Std_ReturnType, GPT_CODE) Gpt_Rti_LLD_ModuleDisable \
( 												\
    VAR(PIT_Module_t, AUTOMATIC) PIT_ModuleID 	\
);

#ifdef __cplusplus
}
#endif

#endif /* PIT_H_ */
