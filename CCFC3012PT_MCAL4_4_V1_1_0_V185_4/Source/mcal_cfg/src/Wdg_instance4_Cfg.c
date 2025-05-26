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
*   @file    Wdg_instance4_Cfg.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Wdg MCAL driver.
*
*   @addtogroup Wdg
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif
#define SWT_MAPCONFIG                         ((uint8)0xFFU)
#include "Wdg_Cfg.h"
#include "Wdg_176_ModId4.h"



#define WDG_INST4_CFG_C_VENDOR_ID                   176
#define WDG_INST4_CFG_C_VER_MAJOR                  4
#define WDG_INST4_CFG_C_VER_MINOR                  4
#define WDG_INST4_CFG_C_VER_REVISION               0
#define WDG_INST4_CFG_C_SW_VER_MAJOR               1
#define WDG_INST4_CFG_C_SW_VER_MINOR               0
#define WDG_INST4_CFG_C_SW_VER_PATCH               1
#if (WDG_INST4_CFG_C_VENDOR_ID != WDG_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_VENDOR_ID "
#endif
#if (WDG_INST4_CFG_C_VER_MAJOR != WDG_CFG_H_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_VER_MAJOR "
#endif
#if (WDG_INST4_CFG_C_VER_MINOR != WDG_CFG_H_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_VER_MINOR "
#endif
#if (WDG_INST4_CFG_C_VER_REVISION != WDG_CFG_H_VER_REVISION)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_VER_REVISION "
#endif
#if (WDG_INST4_CFG_C_SW_VER_MAJOR != WDG_CFG_H_SW_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_SW_VER_MAJOR "
#endif
#if (WDG_INST4_CFG_C_SW_VER_MINOR != WDG_CFG_H_SW_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_SW_VER_MINOR "
#endif
#if (WDG_INST4_CFG_C_SW_VER_PATCH != WDG_CFG_H_SW_VER_PATCH)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_SW_VER_PATCH "
#endif
#if (WDG_INST4_CFG_C_VENDOR_ID != WDG_176_MOD4_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_VENDOR_ID "
#endif
#if (WDG_INST4_CFG_C_VER_MAJOR != WDG_176_MOD4_H_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_VER_MAJOR "
#endif
#if (WDG_INST4_CFG_C_VER_MINOR != WDG_176_MOD4_H_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_VER_MINOR "
#endif
#if (WDG_INST4_CFG_C_VER_REVISION != WDG_176_MOD4_H_VER_REVISION)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_VER_REVISION "
#endif
#if (WDG_INST4_CFG_C_SW_VER_MAJOR != WDG_176_MOD4_H_SW_VER_MAJOR)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_SW_VER_MAJOR "
#endif
#if (WDG_INST4_CFG_C_SW_VER_MINOR != WDG_176_MOD4_H_SW_VER_MINOR)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_SW_VER_MINOR "
#endif
#if (WDG_INST4_CFG_C_SW_VER_PATCH != WDG_176_MOD4_H_SW_VER_PATCH)
    #error " NON-MATCHED DATA : WDG_INST4_CFG_C_SW_VER_PATCH "
#endif

#if (WDGINSTANCE4 == STD_ON)

static CONST(SWT_ModeConfig_Type, WDG_CONST) Wdg_Swt_OffModeSettings_Instance4=
{
    .SWT_MAPConfig=    (uint8)                  SWT_MAPCONFIG,
    .SWT_ServiceMode=    (SWT_ServiceMode_Type) Fixed_Serv_Seq,
    .SWT_ResetonInvalidAccess=(SWT_RIA_Type)    SWT_SystemReset,
    .SWT_WindowMode=    (SWT_Status_Type)         SWT_Disable,
    .SWT_InterruptMode= (SWT_InterMode)         SWT_RESET_FIRST,
    .SWT_StopMode=      (SWT_StopMode_Type)     SWT_CONTINUE,
    .SWT_DebugMode=    (SWT_DebugMode_Type)     SWT_FreezeOFF, 
    .SWT_Lock_Mode=    (SWT_Lock_Type)          SWT_Softlock,     
    .SWT_InitialSK=    (uint16)                 0x00000000,                 
    .SWT_Timeout=      (uint32)                 0x00000100   ,              
    .SWT_WindowValue=  (uint32)                 0x00000000  ,               
    .Wdg_InternalClock=(uint32)                 16000,
	.Wdg_TriggerAddr = (uint32)                0U 

} ;    
static CONST(SWT_ModeConfig_Type, WDG_CONST) Wdg_Swt_FastModeSettings_4=
{
    .SWT_MAPConfig=    (uint8)                   SWT_MAPCONFIG,
    .SWT_ServiceMode=  (SWT_ServiceMode_Type)    Fixed_Serv_Seq,
    .SWT_ResetonInvalidAccess=(SWT_RIA_Type)     SWT_SystemReset,
    .SWT_WindowMode=   (SWT_Status_Type)         SWT_Disable,
    .SWT_InterruptMode=(SWT_InterMode)           SWT_RESET_FIRST,
    .SWT_StopMode=     (SWT_StopMode_Type)       SWT_CONTINUE,
    .SWT_DebugMode=    (SWT_DebugMode_Type)      SWT_FreezeOFF,          
    .SWT_Lock_Mode=    (SWT_Lock_Type)           SWT_Softlock,
    .SWT_InitialSK=    (uint16)                  0,  
    .SWT_Timeout=      (uint32)                  0x01e84800,                 
    .SWT_WindowValue=  (uint32)                  0x00c35000,
    .Wdg_InternalClock=(uint32)                  16000,
	.Wdg_TriggerAddr = (uint32)                0U 

};
static CONST(SWT_ModeConfig_Type, WDG_CONST) Wdg_Swt_SlowModeSettings_4=
{
    .SWT_MAPConfig=   (uint8)                   SWT_MAPCONFIG,
    .SWT_ServiceMode= (SWT_ServiceMode_Type)    Fixed_Serv_Seq,
    .SWT_ResetonInvalidAccess=(SWT_RIA_Type)    SWT_SystemReset,
    .SWT_WindowMode=  (SWT_Status_Type)         SWT_Disable,
    .SWT_InterruptMode=(SWT_InterMode)          SWT_RESET_FIRST,
    .SWT_StopMode=    (SWT_StopMode_Type)       SWT_CONTINUE,
    .SWT_DebugMode=   (SWT_DebugMode_Type)      SWT_FreezeOFF,          
    .SWT_Lock_Mode=    (SWT_Lock_Type)          SWT_Softlock,
    .SWT_InitialSK=   (uint16)                  0,              
    .SWT_Timeout=     (uint32)                  0x01e84800,                 
    .SWT_WindowValue= (uint32)                  0x00c35000,
    .Wdg_InternalClock=(uint32)                 16000,
	.Wdg_TriggerAddr = (uint32)                0U 

};


static CONST(SWT_Module_Config_Type, WDG_CONST)WdgConfigSetType4 =
{
    .SWT_ModuleID = SWT4,
    .SWT_DefaultRunMode = WDGIF_FAST_MODE,
    .u8Wdg_GptTimerChannel = (Gpt_ChannelType)4U,
    .u32Wdg_TriggerSourceClock = (uint32)60000,
    .SWT_Config = { &Wdg_Swt_OffModeSettings_Instance4, &Wdg_Swt_SlowModeSettings_4, &Wdg_Swt_FastModeSettings_4},
    .SWT_Callback =NULL_PTR 
};


CONST(Wdg_ConfigType, WDG_CONST) WdgSettingsConfig_4 =
{
			&WdgConfigSetType4,
};


#endif


#ifdef __cplusplus
}
#endif
