/**************************************************************************** 
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
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    eMIOS.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of eMIOS MCAL driver.
*
*   @addtogroup eMIOS
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "eMIOS.h"
#include "det.h"

#define EMIOS_C_VENDOR_ID                     176
#define EMIOS_C_AR_REL_MAJOR_VER              4
#define EMIOS_C_AR_REL_MINOR_VER              4
#define EMIOS_C_AR_REL_REV_VER                0
#define EMIOS_C_SW_MAJOR_VER                  1
#define EMIOS_C_SW_MINOR_VER                  0
#define EMIOS_C_SW_PATCH_VER                  1
#define EMIOS_MODULE_ID                       250

#if (EMIOS_VENDOR_ID != EMIOS_C_VENDOR_ID)
    #error " NON-MATCHED DATA : EMIOS_C_VENDOR_ID "
#endif
#if (EMIOS_AR_REL_MAJOR_VER != EMIOS_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_C_AR_REL_MAJOR_VER "
#endif
#if (EMIOS_AR_REL_MINOR_VER != EMIOS_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_C_AR_REL_MINOR_VER "
#endif
#if (EMIOS_AR_REL_REV_VER != EMIOS_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : EMIOS_C_AR_REL_REV_VER "
#endif
#if (EMIOS_SW_MAJOR_VER != EMIOS_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : EMIOS_C_SW_MAJOR_VER "
#endif
#if (EMIOS_SW_MINOR_VER != EMIOS_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : EMIOS_C_SW_MINOR_VER "
#endif
#if (EMIOS_SW_PATCH_VER != EMIOS_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : EMIOS_C_SW_PATCH_VER "
#endif


#if (EMIOS_INSTANCE_NUM != 0U)
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
static FUNC(void, EMIOS_CODE) EMIOS_ReportError \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_ApiId, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ErrorId \
);

static FUNC(void, EMIOS_CODE) EMIOS_ReportError \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_ApiId, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ErrorId \
)
{
    (void)Det_ReportError((uint16)EMIOS_MODULE_ID, (uint8)0U, u8eMIOS_ApiId, u8eMIOS_ErrorId);
}

static FUNC(Std_ReturnType, EMIOS_CODE) eMIOS_InitGlobalParamVerify \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    P2CONST(eMIOS_GlobalParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_GlobalParam \
);

static FUNC(Std_ReturnType, EMIOS_CODE) eMIOS_MC_InitVerify \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    P2CONST(eMIOS_MC_ParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_ParamPtr \
);

static FUNC(Std_ReturnType, EMIOS_CODE) eMIOS_InitGlobalParamVerify \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    P2CONST(eMIOS_GlobalParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_GlobalParam \
);

static FUNC(Std_ReturnType, EMIOS_CODE) eMIOS_InitGlobalParamVerify \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    P2CONST(eMIOS_GlobalParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_GlobalParam \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8eMIOS_InitGlobalParamRet = E_NOT_OK;
    if (u8eMIOS_Index > (uint8)EMIOS_INSTANCE_MAX)
    {
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
        EMIOS_ReportError(EMIOS_SID_INITGLOBALPARAM, EMIOS_E_PARAM_INSTANCE);  
#endif
    }
    else if (peMIOS_GlobalParam == NULL_PTR)
    {
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
        EMIOS_ReportError(EMIOS_SID_INITGLOBALPARAM, EMIOS_E_PARAM_POINTER);  
#endif
    }
    else
    {
        u8eMIOS_InitGlobalParamRet = (Std_ReturnType)E_OK;
    }
    return (Std_ReturnType)u8eMIOS_InitGlobalParamRet;
}

static FUNC(Std_ReturnType, EMIOS_CODE) eMIOS_MC_InitVerify \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    P2CONST(eMIOS_MC_ParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_ParamPtr \
)
{
    VAR(Std_ReturnType, AUTOMATIC) eMIOS_MC_InitRet = E_NOT_OK;
    if (u8eMIOS_Index > (uint8)EMIOS_INSTANCE_MAX)
    {
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
        EMIOS_ReportError(EMIOS_SID_MCINIT, EMIOS_E_PARAM_INSTANCE);  
#endif
    }
    else if (((u8eMIOS_ChanNum > 7U) && (u8eMIOS_ChanNum < 16U)) || (u8eMIOS_ChanNum > 23U))
    {
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
        EMIOS_ReportError(EMIOS_SID_MCINIT, EMIOS_E_PARAM_CHANNEL);  
#endif
    }
    else if (peMIOS_ParamPtr == NULL_PTR)
    {
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
        EMIOS_ReportError(EMIOS_SID_MCINIT, EMIOS_E_PARAM_POINTER);  
#endif
    }
    else
    {
        eMIOS_MC_InitRet = (Std_ReturnType)E_OK;
    }
    return (Std_ReturnType)eMIOS_MC_InitRet;
}

static FUNC(Std_ReturnType, EMIOS_CODE) eMIOS_SetEnDisGlobalVerify(VAR(uint8, AUTOMATIC) u8eMIOS_Index)
{
    VAR(Std_ReturnType, AUTOMATIC) u8eMIOS_SetEnDisGlobalRet = E_NOT_OK;
    if (u8eMIOS_Index > (uint8)EMIOS_INSTANCE_MAX)
    {
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
        EMIOS_ReportError(EMIOS_SID_INITGLOBALPARAM, EMIOS_E_PARAM_INSTANCE);  
#endif
    }
    else
    {
        u8eMIOS_SetEnDisGlobalRet = (Std_ReturnType)E_OK;
    }
    return (Std_ReturnType)u8eMIOS_SetEnDisGlobalRet;
}

static FUNC(Std_ReturnType, EMIOS_CODE) eMIOS_InitVerify \
( \
    P2CONST(eMIOS_ConfigType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_ConfigPtr \
) 
{
    VAR(Std_ReturnType, EMIOS_VAR) u8eMIOS_InitRet = (Std_ReturnType)E_NOT_OK;

#if (EMIOS_PRECOMPILE_SUPPORT == STD_ON)
    if (peMIOS_ConfigPtr != NULL_PTR)
#else
    if (peMIOS_ConfigPtr == NULL_PTR)
#endif
    {
    	EMIOS_ReportError(EMIOS_SID_INIT_ID, (uint8)EMIOS_E_PARAM_CONFIG);
    }

    else
    {
        u8eMIOS_InitRet = (Std_ReturnType)E_OK;
    }
    return u8eMIOS_InitRet;
}
#endif

static FUNC(void, EMIOS_CODE) eMIOS_InitGlobalParam \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    P2CONST(eMIOS_GlobalParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_GlobalParam \
)
{
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == eMIOS_InitGlobalParamVerify(u8eMIOS_Index, peMIOS_GlobalParam))
    {
#endif
        eMIOS_LLD_InitGlobalParam(u8eMIOS_Index, peMIOS_GlobalParam);
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

static FUNC(void, EMIOS_CODE) eMIOS_MC_Init \
( \
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(uint8, AUTOMATIC) u8eMIOS_ChanNum, \
    P2CONST(eMIOS_MC_ParamType, EMIOS_CONST, EMIOS_APPL_CONST) peMIOS_ParamPtr \
)
{
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == eMIOS_MC_InitVerify(u8eMIOS_Index, u8eMIOS_ChanNum, peMIOS_ParamPtr))
    {
#endif
        (void)eMIOS_LLD_MC_Init(u8eMIOS_Index, u8eMIOS_ChanNum, peMIOS_ParamPtr);
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

static FUNC(void, EMIOS_CODE) eMIOS_SetEnDisGlobal \
(\
    VAR(uint8, AUTOMATIC) u8eMIOS_Index, \
    VAR(boolean, AUTOMATIC) beMIOS_EnDisGlobal \
)
{
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == eMIOS_SetEnDisGlobalVerify(u8eMIOS_Index))
    {
#endif
        eMIOS_LLD_SetEnDisGlobal(u8eMIOS_Index, beMIOS_EnDisGlobal);
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif /* EMIOS_INSTANCE_NUM != 0U */

FUNC(void, EMIOS_CODE) eMIOS_Init(P2CONST(eMIOS_ConfigType, EMIOS_CONST, EMIOS_APPL_CONST) ConfigPtr)
{
#if (EMIOS_INSTANCE_NUM != 0U)
    static P2CONST(eMIOS_ConfigType, EMIOS_CONST, EMIOS_APPL_CONST) eMIOS_ConfigPtr = NULL_PTR;
#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == eMIOS_InitVerify(ConfigPtr))
    {
#endif /* EMIOS_DEV_ERROR_DETECT == STD_ON */
        VAR(uint8, AUTOMATIC) u8eMIOS_InstanceId = 0U;
        VAR(uint8, AUTOMATIC) u8eMIOS_ChannelNum = 0U;
        #if (EMIOS_PRECOMPILE_SUPPORT == STD_ON)
            eMIOS_ConfigPtr = &eMIOS_Config;
    	    (void)ConfigPtr;
        #else
            eMIOS_ConfigPtr = ConfigPtr;
        #endif

        for(u8eMIOS_InstanceId = 0U; u8eMIOS_InstanceId < EMIOS_INSTANCE_NUM; u8eMIOS_InstanceId++)
        {
            eMIOS_InitGlobalParam(eMIOS_ConfigPtr->eMIOS_InstanceConfig[u8eMIOS_InstanceId].eMIOSIntanceId, \
                &(eMIOS_ConfigPtr->eMIOS_InstanceConfig[u8eMIOS_InstanceId].eMIOS_GlobalParam));
            for(u8eMIOS_ChannelNum = 0U; u8eMIOS_ChannelNum < eMIOS_ConfigPtr->eMIOS_InstanceConfig[u8eMIOS_InstanceId].eMIOSChannelNum; u8eMIOS_ChannelNum++)
            {
                eMIOS_MC_Init \
                ( \
                    u8eMIOS_InstanceId, \
                    (uint8)eMIOS_ConfigPtr->eMIOS_InstanceConfig[u8eMIOS_InstanceId].eMIOS_Mc_CntChnConfig[u8eMIOS_ChannelNum].eMIOSChannelId, \
                    &(eMIOS_ConfigPtr->eMIOS_InstanceConfig[u8eMIOS_InstanceId].eMIOS_Mc_CntChnConfig[u8eMIOS_ChannelNum].eMIOS_MC_Param)
                );
            }
            eMIOS_SetEnDisGlobal(eMIOS_ConfigPtr->eMIOS_InstanceConfig[u8eMIOS_InstanceId].eMIOSIntanceId, TRUE);
        }

#if (EMIOS_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* EMIOS_DEV_ERROR_DETECT == STD_ON */
#else
    (void)ConfigPtr;
#endif /* EMIOS_INSTANCE_NUM != 0U */
}

#ifdef __cplusplus
}
#endif
