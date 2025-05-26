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

*   *****************************************************************************/
/**
*   @file    Wdg_Swt_Isr.c
*   @version 1.0.1
*
*   @addtogroup Wdg
*   @{
*/
#ifdef __cplusplus
extern "C"{
#endif
#include "Wdg_AutoSar_Wrapper.h"
#include "Gpt.h"
#include "intc_lld.h"
#include "SchM_Wdg.h"
/*=======================================INCLUDE FILES============================================*/


/*======================================SOURCE FILE VERSION INFORMATION==========================*/
#define WDG_ATS_WRA_C_VENDOR_ID                      176
#define WDG_ATS_WRA_C_VERSION_MAJOR                  4
#define WDG_ATS_WRA_C_VERSION_MINOR                  4
#define WDG_ATS_WRA_C_VERSION_REVISION               0
#define WDG_ATS_WRA_C_SW_VERSION_MAJOR               1
#define WDG_ATS_WRA_C_SW_VERSION_MINOR               0
#define WDG_ATS_WRA_C_SW_VERSION_PATCH               1
/*==================================== FILE VERSION CHECKS========================================*/
#if (WDG_ATS_WRA_C_VENDOR_ID != WDG_ATS_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_ATS_WRA_C_VENDOR_ID "
#endif
#if (WDG_ATS_WRA_C_VERSION_MAJOR != WDG_ATS_WRA_H_VERSION_MAJOR)
    #error " NON-MATCHED DATA : WDG_ATS_WRA_C_VERSION_MAJOR "
#endif
#if (WDG_ATS_WRA_C_VERSION_MINOR != WDG_ATS_WRA_H_VERSION_MINOR)
    #error " NON-MATCHED DATA : WDG_ATS_WRA_C_VERSION_MINOR "
#endif
#if (WDG_ATS_WRA_C_VERSION_REVISION != WDG_ATS_WRA_H_VERSION_REVISION)
    #error " NON-MATCHED DATA : WDG_ATS_WRA_C_VERSION_REVISION "
#endif
#if (WDG_ATS_WRA_C_SW_VERSION_MAJOR != WDG_ATS_WRA_H_SW_VERSION_MAJOR)
    #error " NON-MATCHED DATA : WDG_ATS_WRA_C_SW_VERSION_MAJOR "
#endif
#if (WDG_ATS_WRA_C_SW_VERSION_MINOR != WDG_ATS_WRA_H_SW_VERSION_MINOR)
    #error " NON-MATCHED DATA : WDG_ATS_WRA_C_SW_VERSION_MINOR "
#endif
#if (WDG_ATS_WRA_C_SW_VERSION_PATCH != WDG_ATS_WRA_H_SW_VERSION_PATCH)
    #error " NON-MATCHED DATA : WDG_ATS_WRA_C_SW_VERSION_PATCH "
#endif

/*===============================================LOCAL FUNCTIONS====================================*/

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif

#include "Wdg_MemMap.h"

FUNC(void, WDG_CODE) Wdg_Autosar_Wrapper_Init \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
)
{
    VAR(uint32, AUTOMATIC) u8Wdg_Ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint64 , AUTOMATIC) u64Wdg_TimerValue = 0;


    Gpt_StopTimer(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u8Wdg_GptTimerChannel);
    u8Wdg_Ret = (uint32)Wdg_HAL_WRA_Init(pWdg_ConfigPtr[SWT_ModuleID]);
    if(u8Wdg_Ret == (Std_ReturnType)E_OK)
    {
        eWdg_DriverStatus[SWT_ModuleID] = WDG_IDLE;
    }
    else{
        eWdg_DriverStatus[SWT_ModuleID] = WDG_UNINIT;
    }

    VAR(uint32 , AUTOMATIC) u32Wdg_TimerTimeoutValue \
        = (pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type \
            ->SWT_Config[pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->SWT_DefaultRunMode]->SWT_Timeout);


    VAR(uint32 , AUTOMATIC) u32wdg_TimerWindowValue \
        =(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type-> \
            SWT_Config[pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->SWT_DefaultRunMode]->SWT_WindowValue>>1);

    u64Wdg_TimerValue =u32Wdg_TimerTimeoutValue - u32wdg_TimerWindowValue;

    u64Wdg_TimerValue = u64Wdg_TimerValue * 1000U;

    u64Wdg_TimerValue = (uint64)u64Wdg_TimerValue \
        /(uint64)(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type-> \
            SWT_Config[pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->SWT_DefaultRunMode]->Wdg_InternalClock);

    Wdg_u32GptPeriod[SWT_ModuleID] = u64Wdg_TimerValue;
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API==STD_ON)
    Gpt_EnableNotification(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u8Wdg_GptTimerChannel);
#endif
    if (WDGIF_OFF_MODE != pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->SWT_DefaultRunMode)
    {
        Gpt_StartTimer (pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u8Wdg_GptTimerChannel, \
            (uint32)(u64Wdg_TimerValue));
    }
    SchM_Enter_WDG_EXCLUSIVE_AREA_01();
    Wdg_u32Timeout[SWT_ModuleID] = WDG_INITIAL_TIMEOUT_U32;
    SchM_Exit_WDG_EXCLUSIVE_AREA_01();
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif

#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE) Wdg_Autosar_Wrapper_SetMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID,VAR(WdgIf_ModeType, WDG_VAR) Mode \
)
{
    VAR(uint32, AUTOMATIC) u8Wdg_Ret = (Std_ReturnType)E_NOT_OK;
    VAR(uint64 , AUTOMATIC) u64Wdg_TimerValue=0;
    VAR(Gpt_ValueType, AUTOMATIC) u32Wdg_GetGptpasstime=0;
    VAR(uint32, AUTOMATIC) u32Wdg_ValueTemp=0;

    u8Wdg_Ret = (uint32)Wdg_HAL_WRA_SetMode(SWT_ModuleID,Mode);
    if(u8Wdg_Ret == (Std_ReturnType)E_OK)
    {
        eWdg_DriverStatus[SWT_ModuleID] = WDG_BUSY;
    }

    u64Wdg_TimerValue = pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->SWT_Config[Mode]->SWT_Timeout \
        - (pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->SWT_Config[Mode]->SWT_WindowValue>>1);

    Gpt_StopTimer(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u8Wdg_GptTimerChannel);
#if (GPT_TIME_ELAPSED_API==STD_ON)
    u32Wdg_GetGptpasstime =  (Gpt_GetTimeElapsed(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u8Wdg_GptTimerChannel) \
        / (pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u32Wdg_TriggerSourceClock / 1000U));
#endif
    u64Wdg_TimerValue = (u64Wdg_TimerValue * 1000U);

    u64Wdg_TimerValue = (uint64)u64Wdg_TimerValue/(uint64)(pWdg_ConfigPtr[SWT_ModuleID]-> \
        SWT_Config_Type->SWT_Config[Mode]->Wdg_InternalClock);

    Wdg_u32GptPeriod[SWT_ModuleID] = (uint32)u64Wdg_TimerValue;
    
    SchM_Enter_WDG_EXCLUSIVE_AREA_02();

    u32Wdg_ValueTemp = Wdg_u32Timeout[SWT_ModuleID] - u32Wdg_GetGptpasstime;
    Wdg_u32Timeout[SWT_ModuleID] =  u32Wdg_ValueTemp;
    SchM_Exit_WDG_EXCLUSIVE_AREA_02();

    if (WDGIF_OFF_MODE != Mode)
    {
        Gpt_StartTimer(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u8Wdg_GptTimerChannel, \
            (uint32)(u64Wdg_TimerValue));
    }
    gWdg_DriverMode = Mode;
    SchM_Enter_WDG_EXCLUSIVE_AREA_03();
    if(eWdg_DriverStatus[SWT_ModuleID] == WDG_BUSY)
    {
    	eWdg_DriverStatus[SWT_ModuleID]  = WDG_IDLE;
    }
    SchM_Exit_WDG_EXCLUSIVE_AREA_03();
    return u8Wdg_Ret;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif

#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) Wdg_Autosar_wrapper_Trigger(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{

    eWdg_DriverStatus[SWT_ModuleID]  = WDG_BUSY;
    SchM_Enter_WDG_EXCLUSIVE_AREA_00();

    if( Wdg_u32Timeout[SWT_ModuleID] < Wdg_u32GptPeriod[SWT_ModuleID])
    {
        SchM_Exit_WDG_EXCLUSIVE_AREA_00();
        Gpt_StopTimer(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u8Wdg_GptTimerChannel);
    }
    else
    {
        VAR(uint32, AUTOMATIC) u32TempTimeout = Wdg_u32Timeout[SWT_ModuleID] - Wdg_u32GptPeriod[SWT_ModuleID];
        Wdg_u32Timeout[SWT_ModuleID]= u32TempTimeout;
        SchM_Exit_WDG_EXCLUSIVE_AREA_00();
        Wdg_HAL_WRA_Trigger(SWT_ModuleID);
    }
    eWdg_DriverStatus[SWT_ModuleID]  = WDG_IDLE;
}

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"


/*====================================== GLOBAL FUNCTIONS========================================*/


#ifdef __cplusplus
}
#endif

/** @} */
