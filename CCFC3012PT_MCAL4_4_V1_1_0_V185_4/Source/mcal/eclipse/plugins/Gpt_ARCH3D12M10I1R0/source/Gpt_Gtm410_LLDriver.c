
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3008PT
* DESCRIPTION : CCFC3008PT GTM TOM low level drivers code
* HISTORY     : Initial version
* @file     Gpt_Gtm_LLDriver.c
* @version  1.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0380,1296,1503,1317,1338,1881,2016,2023,2024,4442 EOF*/
#if ( defined(CCFC3012PT))
#ifdef __cplusplus
extern "C"{
#endif

#include "Gpt_Gtm_LLDriver.h"
#include "Gpt_Irq.h"
#include "Gpt_AutoSar_Wrapper.h"
#include "Gpt_Cfg.h"
#include "SchM_Gpt.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define GPT_VENDOR_ID_C                 176
#define GPT_AR_MAJOR_VER_C              4
#define GPT_AR_MINOR_VER_C              4
#define GPT_AR_PATCH_VER_C              0
#define GPT_SW_MAJOR_VER_C              1
#define GPT_SW_MINOR_VER_C              0
#define GPT_SW_PATCH_VER_C              1

/*============================================FILE VERSION CHECKS===================================*/

/* Check if current file and GPT header file are of the same vendor */
#if (GPT_VENDOR_ID_C != GPT_VENDOR_ID)
#error "NON-MATCHED DATA : GPT_VENDOR_ID"
#endif

/* Check if current file and GPT header file are of the same Autosar version */
#if (GPT_AR_MAJOR_VER_C != GPT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER"
#endif
#if (GPT_AR_MINOR_VER_C != GPT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER"
#endif
#if (GPT_AR_PATCH_VER_C != GPT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER"
#endif

/* Check if current file and GPT header file are of the same Software version */
#if (GPT_SW_MAJOR_VER_C != GPT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER"
#endif
#if (GPT_SW_MINOR_VER_C != GPT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER"
#endif
#if (GPT_SW_PATCH_VER_C != GPT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER"
#endif




extern P2CONST(Gpt_ConfigType, GPT_VAR,  GPT_APPL_CONST)  sGpt_pConfig[GPT_MAX_PARTITION];

FUNC(GPT_GTM_TOM_Type, GPT_CODE) Gpt_GTM_LLD_ConvertModuleId
(
		VAR(uint8, AUTOMATIC)u8Module
)
{
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) eModuleId;
    switch(u8Module)
    {
        case 0u:
            eModuleId = GPT_GTM_TOM0;
        break;
        case 1u:
            eModuleId = GPT_GTM_TOM1;
        break;
        case 2u:
            eModuleId = GPT_GTM_TOM2;
        break;
        case 3u:
            eModuleId = GPT_GTM_TOM3;
        break;
        case 4u:
            eModuleId = GPT_GTM_TOM4;
        break;
        case 5u:
            eModuleId = GPT_GTM_TOM5;
        break;
        default:
            eModuleId = GPT_GTM_TOM0;
        break;
    }
    return eModuleId;
}

FUNC(GPT_GTM_TOM_Channel_Type, GPT_CODE) Gpt_Gtm_LLD_ConvertChannelId(VAR(uint8, AUTOMATIC)u8Channel)
{
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) eChannelId;
    switch(u8Channel)
    {
        case 0u:
            eChannelId = GPT_GTM_TOM_CH0;
        break;
        case 1u:
            eChannelId = GPT_GTM_TOM_CH1;
        break;
        case 2u:
            eChannelId = GPT_GTM_TOM_CH2;
        break;
        case 3u:
            eChannelId = GPT_GTM_TOM_CH3;
        break;
        case 4u:
            eChannelId = GPT_GTM_TOM_CH4;
        break;
        case 5u:
            eChannelId = GPT_GTM_TOM_CH5;
        break;
        case 6u:
            eChannelId = GPT_GTM_TOM_CH6;
        break;
        case 7u:
            eChannelId = GPT_GTM_TOM_CH7;
        break;
        case 8u:
            eChannelId = GPT_GTM_TOM_CH8;
        break;
        case 9u:
            eChannelId = GPT_GTM_TOM_CH9;
        break;
        case 10u:
            eChannelId = GPT_GTM_TOM_CH10;
        break;
        case 11u:
            eChannelId = GPT_GTM_TOM_CH11;
        break;
        case 12u:
            eChannelId = GPT_GTM_TOM_CH12;
        break;
        case 13u:
            eChannelId = GPT_GTM_TOM_CH13;
        break;
        case 14u:
            eChannelId = GPT_GTM_TOM_CH14;
        break;
        case 15u:
            eChannelId = GPT_GTM_TOM_CH15;
        break;
        default:
            eChannelId = GPT_GTM_TOM_CH0;
        break;
    }
    return eChannelId;
}


FUNC(Std_ReturnType, GPT_CODE) Gpt_GTM_TOM_LLD_IsEnableOneShotMode  \
( 																    \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 					    \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 					\
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;


    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.OSM = (uint8)IsEnable;
    if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.OSM != (uint8)IsEnable)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }

    return Ret;
}
FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_LLD_IsEnableClsDiv
(
		VAR(GTM_CLS_Type, AUTOMATIC) GTM_CLSn, \
		VAR(GTM_ClsDivStatus_Type, AUTOMATIC_Type) status
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    GTM4.GLS[0].ARCH.CTRL.B.RF_PROT = 0;
	GTM4.GLS[0].ARCH.CLS_CLK_CFG.R &= ~(uint32_t)(0x3u << 2u * (uint32_t)GTM_CLSn);
	GTM4.GLS[0].ARCH.CLS_CLK_CFG.R |= (uint32_t)((uint32_t)status << 2u * (uint32_t)GTM_CLSn);
	GTM4.GLS[0].ARCH.CTRL.B.RF_PROT = 1;
	return Ret;

}

VAR(uint16, AUTOMATIC) Gpt_GTM_TOM_LLD_Channel_GetCompareRegister   \
(                                                                   \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn,                      \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn                    \
)
{
    VAR(uint16, AUTOMATIC) u16Gpt_ReturnValue = 0;
    u16Gpt_ReturnValue = GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CM0.B.CM0;

    return u16Gpt_ReturnValue;
}

FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SelectClockSource 	\
( 																	\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 						\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(GPT_GTM_TOM_ClockSource_Type, AUTOMATIC) ClockSource 		\
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL_SR.B.CLK_SRC_SR = (uint8)ClockSource;
    if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL_SR.B.CLK_SRC_SR != (uint8)ClockSource)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }

    return Ret;
}


FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SelectCCU0ResetSource  \
(                                                                     \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn,                        \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn,                     \
    VAR(GPT_GTM_TOM_CCU0ResetSource_Type, AUTOMATIC) CCU0ResetSource  \
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;


    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.RST_CCU0 = (uint8)CCU0ResetSource;
    if(GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CTRL.B.RST_CCU0 != (uint8)CCU0ResetSource)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    
	return Ret;
}

FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SetShadowRegister \
( 																 \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 					 \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 				 \
    uint16 SR0, 												 \
    uint16 SR1 													 \
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;


    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].SR0.B.SR0 = SR0;
    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].SR1.B.SR1 = SR1;
    if((GTM4.GLS[GTM_TOMn].TOM.CH[CHn].SR0.B.SR0 != SR0) || (GTM4.GLS[GTM_TOMn].TOM.CH[CHn].SR1.B.SR1 != SR1))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    return Ret;
}

FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SetCompareRegister \
( 													\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 		\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 	\
    uint16 CM0, 									\
    uint16 CM1 										\
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;


    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CM0.B.CM0 = CM0;
    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CM1.B.CM1 = CM1;

    return Ret;
}

FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_SetCounter \
( 												  \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 	  \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, \
    VAR(uint16, AUTOMATIC) CN0                    \
)
{

	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;

    GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CN0.B.CN0 = CN0;

    return Ret;
}

FUNC(uint8, GPT_CODE) GPT_GTM_TOM_LLD_GetInterruptFlag 	 \
( 														 \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 			 \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 		 \
    VAR(GPT_GTM_TOM_Interrupt_Type, AUTOMATIC) Interrupt \
)
{
	VAR(uint8, AUTOMATIC) Ret = 0;


    if(Interrupt == GPT_GTM_TOM_IRQ_CCU0TC)
    {
        Ret =(uint8)GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_NOTIFY.B.CCU0TC;
    }
    else if(Interrupt == GPT_GTM_TOM_IRQ_CCU1TC)
    {
        Ret =(uint8) GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_NOTIFY.B.CCU1TC;
    }else
    {
        Ret =(uint8) 0U;
    }
   
    return Ret;
}


FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_ClearInterruptFlag \
( 																  \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 					  \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 				  \
    VAR(GPT_GTM_TOM_Interrupt_Type, AUTOMATIC) Interrupt 		  \
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;


    if(Interrupt == GPT_GTM_TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_NOTIFY.B.CCU0TC = 1U;

    }
    else if(Interrupt == GPT_GTM_TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_NOTIFY.B.CCU1TC = 1U;

    }else
    {
       Ret = (Std_ReturnType)E_NOT_OK;
    }

    return Ret;
}



FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableInterrupt 	\
( 																	\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 						\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 					\
    VAR(GPT_GTM_TOM_Interrupt_Type, AUTOMATIC) Interrupt, 			\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 					\
)
{

	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;


    if(Interrupt == GPT_GTM_TOM_IRQ_CCU0TC)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_EN.B.CCU0TC_IRQ_EN = (uint8)IsEnable;

    }
    else if(Interrupt == GPT_GTM_TOM_IRQ_CCU1TC)
    {
        GTM4.GLS[GTM_TOMn].TOM.CH[CHn].IRQ_EN.B.CCU1TC_IRQ_EN = (uint8)IsEnable;

    }else
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }

    return Ret;
}

FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableUpdate \
( 															  \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 				  \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 			  \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 			  \
)
{

	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;

    VAR(uint8, AUTOMATIC) IsEnable_l = (uint8)IsEnable;

    if((uint8)IsEnable_l  == 1u)
    {
    	IsEnable_l = (uint8)2u;
    }
    else
    {
    	IsEnable_l = (uint8)1u;
    }

    uint8  shift = (((uint8)CHn % 8U) * 2U) + (uint8)GTM4_TOM_TGC_GLB_CTRL_UPEN_CTRL0_OFF;

    if((uint8)CHn < 8U)
    {

    	GTM4.GLS[GTM_TOMn].TOM.TGC0_GLB_CTRL.R  = (uint32)(IsEnable_l << shift);

        
    }else
    {

        GTM4.GLS[GTM_TOMn].TOM.TGC1_GLB_CTRL.R = (uint32)(IsEnable_l << shift);

    }

    return Ret;
}

FUNC(uint16, GPT_CODE) GPT_GTM_TOM_LLD_GetCounter \
(                                                 \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn,    \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn  \
)
{
	
    return GTM4.GLS[GTM_TOMn].TOM.CH[CHn].CN0.B.CN0;
}
    



FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableChannel 	\
( 																\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn, 					\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, 				\
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable 				\
)
{

	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
    VAR(uint8, AUTOMATIC) IsEnable_l = 0;


    if((uint8)IsEnable  == 1U)
    {
        IsEnable_l = 2;
    }
    else
    {
        IsEnable_l = 1;
    }
    uint8  shift = (((uint8)CHn % 8U) * 2U) + (uint8)GTM4_TOM_TGC_ENDIS_STAT_ENDIS_STAT0_OFF;

    if((uint8)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_ENDIS_STAT.R = (uint32)(IsEnable_l << shift);

    }else
    {

        GTM4.GLS[GTM_TOMn].TOM.TGC1_ENDIS_STAT.R = (uint32)(IsEnable_l << shift);

    }
    return Ret;
}

FUNC(Std_ReturnType, GPT_CODE) GPT_GTM_TOM_LLD_IsEnableOut \
(                                                 \
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) GTM_TOMn,    \
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) CHn, \
    VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable  \
)
{
	VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
	VAR(uint8, AUTOMATIC) Status = 0;


    if((uint8)IsEnable  == 1U)
    {
    	Status = 2;
    }
    else
    {
    	Status = 1;
    }

    uint8  shift = (((uint8)CHn % 8U) * 2U) + (uint8)GTM4_TOM_TGC_OUTEN_STAT_OUTEN_STAT0_OFF;

    if((uint8)CHn < 8U)
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC0_OUTEN_STAT.R = (uint32)(Status << shift);
       
    }else
    {
        GTM4.GLS[GTM_TOMn].TOM.TGC1_OUTEN_STAT.R = (uint32)(Status << shift);
        
    }

    return Ret;
}


Std_ReturnType GTM_LLD_HresEn(void)
{
    GTM4.GLS[0].GLSDLLCTRL[0].R = (0x33030000 | (uint32_t)1);
    GTM4.GLS[0].GLSDLLCTRL[1].R = (0x33030000 | (uint32_t)1);

    return (Std_ReturnType)E_OK;
}


FUNC(Std_ReturnType, GPT_CODE) GPT_GTMINT_LLD_IsEnableModule
(
		VAR(GPT_GTM_Status_Type, AUTOMATIC) IsEnable
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;
	VAR(uint8, AUTOMATIC) Status = 0;
	if((uint8)IsEnable != 0u)	 /*PRQA S 1881 */
	{
		Status = 0u;
	}
	else
	{
		Status = 1u;
	}

    GTM4.GLS[0].GTMINT.GTMMCR.B.MDIS = (uint32)Status;

	if(GTM4.GLS[0].GTMINT.GTMMCR.B.MDIS != (uint32)Status)
	{
		Ret = (Std_ReturnType)E_NOT_OK;
	}
	return Ret;
}

///////////  GTM ////////////////

FUNC(void, GPT_CODE) GPT_GTM_LLD_Reset(void)
{
    GTM4.GLS[0].ARCH.RST.B.RST = 1u;
}

FUNC(void, GPT_CODE) GPT_TOM_LLD_IRQHandler 				\
( 															\
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) TOM_ModuleID, 			\
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) TOM_ChannelID 	\
)
{
    #if 1
	VAR(uint8, AUTOMATIC) u8Channel = 0;
    VAR(uint32, AUTOMATIC) CoreIndex = Gpt_GetCoreID();

   // uint32* pIrqNotify;
    uint32* pChStat;


    VAR(Gpt_ChannelType, AUTOMATIC) u8Gpt_Instance = (TOM_ModuleID * GPT_GTM_CHANNEL_MAX) + TOM_ChannelID + GPT_GTM_MODULE_INDEX;
    u8Channel = sGpt_pConfig[CoreIndex]->Gpt_aHw2LogicChannelMap[u8Gpt_Instance];
    

#if (GPT_ENABLE_MULTICORE == STD_ON)
    P2VAR(Gpt_Wrapper_ChannelInfo, AUTOMATIC, GPT_APPL_DATA) pChannelInfo = NULL_PTR;

    VAR(uint32, AUTOMATIC) CurrentCoreId = 1 << Gpt_GetCoreID();

    pChannelInfo = Gpt_AutoSar_Wrapper_GetChannelInfo(u8Channel);

    VAR(uint8, AUTOMATCI) Temp = CurrentCoreId & pChannelInfo->pGpt_CoreId[u8Channel];

    if(Temp != (uint8)0u)
#endif
    {

    	GTM4.GLS[TOM_ModuleID].TOM.CH[TOM_ChannelID].IRQ_NOTIFY.R = 3;

		if (GPT_CH_MODE_ONESHOT == (*(sGpt_pConfig[CoreIndex]->pChannelConfig))[u8Channel].eChannelMode)
		{
			SchM_Enter_GPT_EXCLUSIVE_AREA_16();

			if(TOM_ChannelID < 8)
			{
				pChStat = (uint32*)&GTM4.GLS[TOM_ModuleID].TOM.TGC0_ENDIS_STAT.R;
				*pChStat = 1 << ((uint8)TOM_ChannelID * 2);
			}
			else
			{
				pChStat = (uint32*)&GTM4.GLS[TOM_ModuleID].TOM.TGC1_ENDIS_STAT.R;
				*pChStat = 1 << (((uint8)TOM_ChannelID - 8) * 2);
			}

			SchM_Exit_GPT_EXCLUSIVE_AREA_16();
		}

		Gpt_ProcessCommonIrq(u8Channel);
    }
#else
     VAR (uint8, AUTOMATIC) u32Gpt_CCU0NotifyStatus;
    VAR (uint8, AUTOMATIC) u32Gpt_CCU1NotifyStatus;
    VAR (uint8, AUTOMATIC) u32Gpt_CCU0IrqFlags;
    VAR (uint8, AUTOMATIC) u32Gpt_CCU1IrqFlags;

   // st_Gpt_GTM_TOM_tag* GPT_GPT_GTM_TOM_n = g_GPT_GTM_TOM_Base[TOM_ModuleID];

    VAR(Gpt_ChannelType, AUTOMATIC) u8Gpt_Instance = Gpt_GetInstance(GPT_MODULE_GTM, (TOM_ModuleID * GPT_GTM_CHANNEL_MAX) + TOM_ChannelID);
    
#if (GPT_ENABLE_MULTICORE == STD_ON)
    P2VAR(Gpt_Wrapper_ChannelInfo, AUTOMATIC, GPT_APPL_DATA) pChannelInfo = NULL_PTR;

    VAR(uint32, AUTOMATIC) CurrentCoreId = 1 << Gpt_GetCoreID();

    pChannelInfo = Gpt_AutoSar_Wrapper_GetChannelInfo(u8Gpt_Instance);

    VAR(uint8, AUTOMATCI) Temp = CurrentCoreId & pChannelInfo->pGpt_CoreId[u8Gpt_Instance];

    if(Temp != (uint8)0u)
#endif
    {
        {      
            u32Gpt_CCU0NotifyStatus = GTM4.GLS[TOM_ModuleID].TOM.CH[TOM_ChannelID].IRQ_NOTIFY.B.CCU0TC ;

            u32Gpt_CCU1NotifyStatus = GTM4.GLS[TOM_ModuleID].TOM.CH[TOM_ChannelID].IRQ_NOTIFY.B.CCU1TC ;
            
            u32Gpt_CCU0IrqFlags = GTM4.GLS[TOM_ModuleID].TOM.CH[TOM_ChannelID].IRQ_EN.B.CCU0TC_IRQ_EN ;
            
            u32Gpt_CCU1IrqFlags = GTM4.GLS[TOM_ModuleID].TOM.CH[TOM_ChannelID].IRQ_EN.B.CCU1TC_IRQ_EN ;
            
            GTM4.GLS[TOM_ModuleID].TOM.CH[TOM_ChannelID].IRQ_NOTIFY.R = 3;
        }

        if(((u32Gpt_CCU0NotifyStatus == (uint8)1) && (u32Gpt_CCU0IrqFlags == (uint8)1)) || \
            ((u32Gpt_CCU1NotifyStatus == (uint8)1) && (u32Gpt_CCU1IrqFlags == (uint8)1)))
        {
            Gpt_Gtm_Callback_From_IRQ(u8Gpt_Instance);
        }

		
    }
#endif
}



#ifdef __cplusplus
}
#endif
#endif

