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
*   @file    Wdg_instance0_Cfg.c
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
#include "Wdg_Module.h"
#include "Wdg_Cfg.h"
#define WDG_CFGEXT_C_VENDOR_ID                   176
#define WDG_CFGEXT_C_VER_MAJOR                  4
#define WDG_CFGEXT_C_VER_MINOR                  4
#define WDG_CFGEXT_C_VER_REVISION               0
#define WDG_CFGEXT_C_SW_VER_MAJOR               1
#define WDG_CFGEXT_C_SW_VER_MINOR               0
#define WDG_CFGEXT_C_SW_VER_PATCH               1
#if (WDG_CFGEXT_C_VENDOR_ID != WDG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_VENDOR_ID "
#endif
#if (WDG_CFGEXT_C_VER_MAJOR != WDG_H_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_VER_MAJOR "
#endif
#if (WDG_CFGEXT_C_VER_MINOR != WDG_H_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_VER_MINOR "
#endif
#if (WDG_CFGEXT_C_VER_REVISION != WDG_H_REVISION_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_VER_REVISION "
#endif
#if (WDG_CFGEXT_C_SW_VER_MAJOR != WDG_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_SW_VER_MAJOR "
#endif
#if (WDG_CFGEXT_C_SW_VER_MINOR != WDG_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_SW_VER_MINOR "
#endif
#if (WDG_CFGEXT_C_SW_VER_PATCH != WDG_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : WDG_CFGEXT_C_SW_VER_PATCH "
#endif
CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Disable_Rejected = 
{
    (uint32)STD_ON,


    (uint16)1U

};


CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Mode_Failed = 
{

    (uint32)STD_ON,


    (uint16)2U

};

#ifdef __cplusplus
}
#endif

