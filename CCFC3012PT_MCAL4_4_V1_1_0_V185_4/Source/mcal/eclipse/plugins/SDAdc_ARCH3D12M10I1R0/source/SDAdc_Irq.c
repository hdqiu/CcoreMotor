/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     SDAdc_Irq.c
* @version  1.0
* @date     2024 - 03 - 22
* @brief    Initial version.
*
*****************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

#include "SDAdc.h"
#include "SDAdc_Irq.h"
#include "SchM_Sdadc.h"

#ifdef RESOURCE_SUPPORT_SDADC_IP

#define SDADC_IRQ_C_VENDOR_ID                     176
#define SDADC_IRQ_C_AR_REL_MAJOR_VER              4
#define SDADC_IRQ_C_AR_REL_MINOR_VER              4
#define SDADC_IRQ_C_AR_REL_REV_VER                0
#define SDADC_IRQ_C_SW_MAJOR_VER                  1
#define SDADC_IRQ_C_SW_MINOR_VER                  0
#define SDADC_IRQ_C_SW_PATCH_VER                  1

#if (SDADC_CFG_H_VENDOR_ID               != SDADC_IRQ_C_VENDOR_ID)
    #error " NON-MATCHED DATA : SDADC_IRQ_C_VENDOR_ID "
#endif
#if (SDADC_CFG_H_AR_REL_MAJOR_VER    != SDADC_IRQ_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_C_AR_REL_MAJOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_MINOR_VER    != SDADC_IRQ_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_C_AR_REL_MINOR_VER "
#endif
#if (SDADC_CFG_H_AR_REL_REV_VER != SDADC_IRQ_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_C_AR_REL_REV_VER "
#endif
#if (SDADC_CFG_H_SW_MAJOR_VER        != SDADC_IRQ_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_C_SW_MAJOR_VER "
#endif
#if (SDADC_CFG_H_SW_MINOR_VER        != SDADC_IRQ_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_C_SW_MINOR_VER "
#endif
#if (SDADC_CFG_H_SW_PATCH_VER        != SDADC_IRQ_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : SDADC_IRQ_C_SW_PATCH_VER "
#endif

static FUNC(void, SDADC_CODE) Sdadc_Isr(CONST(Sdadc_InstanceType, SDADC_CONST) instance, CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId);

static FUNC(void, SDADC_CODE) Sdadc_Isr(CONST(Sdadc_InstanceType, SDADC_CONST) instance, CONST(Sdadc_ChannelType, SDADC_CONST) ChannelId)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    VAR(uint8, AUTOMATIC) CurrentCoreId = SDAdc_GetCoreID(); /*Get Core ID*/
    if(((CurrentCoreId) & (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_CoreMapItem[ChannelId].SdAdc_CoreId)) != 0U)
    {
#endif
        VAR(boolean, SDADC_VAR) rdata;
        VAR(boolean, SDADC_VAR) rdata1;
        VAR(boolean, SDADC_VAR) rdata2;
        VAR(uint32, SDADC_VAR) WaterMarkerValue = 0U;
        CONSTP2VAR(SDADC_TagType, SDADC_CONST, SDADC_APPL_CONST) BasePtr = Adc_SdadcBase0[instance];
        rdata = SDADC_LLD_GetWaterMarkerIntState(instance);
        rdata1 = SDADC_LLD_GetDataOverFlowIntState(instance);
        rdata2 = SDADC_LLD_GetFifoOverFlowIntState(instance);
        if(rdata == TRUE)
        {
            SchM_Enter_SDADC_CRITICAL_AREA_00();
            if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_ConvMethod == SDADC_USE_INTERRUPT)
            {
                WaterMarkerValue = BasePtr->FCFG.B.FIFOWM;
                for(uint32 i = 0U; i < WaterMarkerValue; i++)
                {
                    Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelResBuffer[Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes] = (SDADC_LLD_GetFifoData(instance) & 0xFFFFU);
                    Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes++;
                    if((Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NotifyStatus == TRUE) && (sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_NewResultNotify != NULL_PTR))
                    {
                        sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_NewResultNotify();
                    }
                }
                SDADC_LLD_ClearWaterMarkerIntState(instance);
                if((Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize - Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes) < (uint16)WaterMarkerValue)
                {
                	if((sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferMode != SDADC_STREAM_LINEAR_BUFFER)
                		&& (Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes >= Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize))
					{
						Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes = 0U;
						BasePtr->FCFG.B.FIFOWM = sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_Config->FifoCfg.FifoWaterMarker;
					}
                	else
                	{
                		BasePtr->FCFG.B.FIFOWM = (uint8)(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize - Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes);
                	}
                }
                Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelStatus = SDADC_RESULT_READY;
                if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NotifyStatus == TRUE)
                {
                    if(Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].NumofValidConRes >= Sdadc_ChannelData[ChannelId][u32Sdadc_ICoreId].ChannelBufferSize)
                    {
                        if(sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferFullNotifyPtr != NULL_PTR)
                        {
                            sdAdc_ConfigPtr[u32Sdadc_ICoreId]->SdAdc_InstanceConfig[ChannelId].Sdadc_BufferFullNotifyPtr();
                        }
                    }
                }
            }
            else
            {
                SDADC_LLD_ClearWaterMarkerIntState(instance);
            }
            SchM_Exit_SDADC_CRITICAL_AREA_00();
        }

        if(rdata1 == TRUE)
        {
            SDADC_LLD_ResetFifo(instance);
            SDADC_LLD_ModuleDisable(instance);
            SDADC_LLD_ClearDataOverFlowIntState(instance);
        }

        if(rdata2 == TRUE)
        {
            (void)SDADC_LLD_ResetFifo(instance);
            SDADC_LLD_ModuleDisable(instance);
            SDADC_LLD_ClearFifoOverFlowIntState(instance);
        }
#if (SDADC_ENABLE_MULTICORE == STD_ON)
    }
#endif
}

FUNC(void, SDADC_CODE) Sdadc0_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_0, SDAdc_gIrqMapping[SDADC_INSTANCE_0][u32Sdadc_ICoreId]);
}

FUNC(void, SDADC_CODE) Sdadc1_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_1, SDAdc_gIrqMapping[SDADC_INSTANCE_1][u32Sdadc_ICoreId]);
}

FUNC(void, SDADC_CODE) Sdadc2_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_2, SDAdc_gIrqMapping[SDADC_INSTANCE_2][u32Sdadc_ICoreId]);
}

FUNC(void, SDADC_CODE) Sdadc3_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_3, SDAdc_gIrqMapping[SDADC_INSTANCE_3][u32Sdadc_ICoreId]);
}

FUNC(void, SDADC_CODE) Sdadc4_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_4, SDAdc_gIrqMapping[SDADC_INSTANCE_4][u32Sdadc_ICoreId]);
}

#ifdef RESOURCE_SUPPORT_SDADC5
FUNC(void, SDADC_CODE) Sdadc5_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_5, SDAdc_gIrqMapping[SDADC_INSTANCE_5][u32Sdadc_ICoreId]);
}
#endif

FUNC(void, SDADC_CODE) Sdadc6_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_6, SDAdc_gIrqMapping[SDADC_INSTANCE_6][u32Sdadc_ICoreId]);
}

FUNC(void, SDADC_CODE) Sdadc7_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_7, SDAdc_gIrqMapping[SDADC_INSTANCE_7][u32Sdadc_ICoreId]);
}

FUNC(void, SDADC_CODE) Sdadc8_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_8, SDAdc_gIrqMapping[SDADC_INSTANCE_8][u32Sdadc_ICoreId]);
}

#ifdef RESOURCE_SUPPORT_SDADC9
FUNC(void, SDADC_CODE) Sdadc9_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_9, SDAdc_gIrqMapping[SDADC_INSTANCE_9][u32Sdadc_ICoreId]);
}
#endif

#ifdef RESOURCE_SUPPORT_SDADC10
FUNC(void, SDADC_CODE) Sdadc10_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_10, SDAdc_gIrqMapping[SDADC_INSTANCE_10][u32Sdadc_ICoreId]);
}
#endif

#ifdef RESOURCE_SUPPORT_SDADC11
FUNC(void, SDADC_CODE) Sdadc11_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_11, SDAdc_gIrqMapping[SDADC_INSTANCE_11][u32Sdadc_ICoreId]);
}
#endif

#ifdef RESOURCE_SUPPORT_SDADC12
FUNC(void, SDADC_CODE) Sdadc12_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_12, SDAdc_gIrqMapping[SDADC_INSTANCE_12][u32Sdadc_ICoreId]);
}
#endif

#ifdef RESOURCE_SUPPORT_SDADC13
FUNC(void, SDADC_CODE) Sdadc13_irq(void)
{
    VAR(uint32, AUTOMATIC) u32Sdadc_ICoreId = GetCoreID();
    Sdadc_Isr(SDADC_INSTANCE_13, SDAdc_gIrqMapping[SDADC_INSTANCE_13][u32Sdadc_ICoreId]);
}
#endif

#endif /*RESOURCE_SUPPORT_SDADC_IP*/

#ifdef __cplusplus
}
#endif


