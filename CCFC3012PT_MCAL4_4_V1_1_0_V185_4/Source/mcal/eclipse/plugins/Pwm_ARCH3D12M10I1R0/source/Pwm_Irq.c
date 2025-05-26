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
*   @file    Pwm_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm.h"
#include "Mcal.h"
#include "Pwm_LLDriver.h"
#include "Pwm_HAL_Wrapper.h"
#include "intc_lld.h"
#if (defined(CCFC3007PT) || defined(CCFC3008PT) || defined(CCFC3007BC))
#include "eTPU_LLDrivers.h"
#endif
#include "SchM_Pwm.h"
#include "Pwm_Irq.h"

#define PWM_IRQ_C_VENDOR_ID                      176
#define PWM_IRQ_C_AR_REL_MAJOR_VER               4
#define PWM_IRQ_C_AR_REL_MINOR_VER               4
#define PWM_IRQ_C_AR_REL_REV_VER                 0
#define PWM_IRQ_C_SW_MAJOR_VER                   1
#define PWM_IRQ_C_SW_MINOR_VER                   0
#define PWM_IRQ_C_SW_PATCH_VER                   1

#if (PWM_IRQ_C_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_IRQ_C_VENDOR_ID "
#endif
#if (PWM_IRQ_C_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_IRQ_C_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_AR_REL_MINOR_VER "
#endif
#if (PWM_IRQ_C_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_AR_REL_REV_VER "
#endif
#if (PWM_IRQ_C_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_SW_MAJOR_VER "
#endif
#if (PWM_IRQ_C_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_SW_MINOR_VER "
#endif
#if (PWM_IRQ_C_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_SW_PATCH_VER "
#endif

#if (defined(CCFC3007PT) || defined (CCFC3008PT) || defined (CCFC3012PT))

FUNC(void, PWM_CODE)Pwm_Tom_isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch0_index, \
    VAR(uint8, AUTOMATIC) u8ch1_index \
)
{
    P2VAR(Pwm_ChConfigsType, PWM_VAR, PWM_APPL_VAR) Pwm_Configs = NULL_PTR;
    VAR(Pwm_NotifyType, PWM_VAR) Pwm_Notify = NULL_PTR;
    VAR(Pwm_ChannelType, AUTOMATIC) Pwm_ChannelId = 0U;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelNotificationStatus = NULL_PTR;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag0 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag1 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag2 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag3 = 0U;
    VAR(Pwm_DutycycleType, AUTOMATIC) u32Pwm_Dutycycle = 0U;
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)GetCoreID();    //get core id

    pChannelNotificationStatus = Pwm_Wrapper_Get_ChannelNotification();
    Pwm_Configs = Pwm_Pwm_Wrapper_Get_pChConfigs();

    u8Pwm_Flag0 = GTM_TOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
        (VAR(GTM_TOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU0TC \
    );
    u8Pwm_Flag1 = GTM_TOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
        (VAR(GTM_TOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU1TC \
    );

    u8Pwm_Flag2 = GTM_TOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
        (VAR(GTM_TOM_Interrupt_Type, AUTOMATIC))TOM_IRQ_CCU0TC \
    );
    u8Pwm_Flag3 = GTM_TOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
        (VAR(GTM_TOM_Interrupt_Type, AUTOMATIC))TOM_IRQ_CCU1TC \
    );

    if(u8Pwm_Flag0 == 1u)
    {
        (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
            TOM_IRQ_CCU0TC \
        );
    }

    if(u8Pwm_Flag1 == 1u)
    {
        (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
            TOM_IRQ_CCU1TC \
        );
    }

    if(u8Pwm_Flag2 == 1u)
    {
        (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
            TOM_IRQ_CCU0TC \
        );
    }

    if(u8Pwm_Flag3 == 1u)
    {
        (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
            TOM_IRQ_CCU1TC \
        );
    }

    if(Pwm_Configs != NULL_PTR)
    {
        Pwm_Notify = Pwm_Configs->pPwm_TomNotifyTable[(u8hw_index * PWM_TOM_CHANNEL_MAX) + u8ch0_index].pNotification;
        Pwm_ChannelId = Pwm_Configs->pPwm_TomNotifyTable[(u8hw_index * PWM_TOM_CHANNEL_MAX) + u8ch0_index].nPwmChannelId;
        if((Pwm_Notify != NULL_PTR) && ((u8Pwm_Flag0 == 1U) || (u8Pwm_Flag1 == 1U)))
        {
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if(u32CoreID < 6U)
            {
                if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))
                {
                	Pwm_Notify();
                }
            }
        }

        Pwm_Notify = Pwm_Configs->pPwm_TomNotifyTable[(u8hw_index * PWM_TOM_CHANNEL_MAX) + u8ch1_index].pNotification;
        Pwm_ChannelId = Pwm_Configs->pPwm_TomNotifyTable[(u8hw_index * PWM_TOM_CHANNEL_MAX) + u8ch1_index].nPwmChannelId;
        if((Pwm_Notify != NULL_PTR) && ((u8Pwm_Flag2 == 1U) || (u8Pwm_Flag3 == 1U)))
        {
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if((pChannelNotificationStatus[Pwm_ChannelId] == 1U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))
            {
            	Pwm_Notify();
            }
        }
    }

}

FUNC(void, PWM_CODE)Pwm_Atom_isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch0_index, \
    VAR(uint8, AUTOMATIC) u8ch1_index \
)
{
    P2VAR(Pwm_ChConfigsType, PWM_VAR, PWM_APPL_VAR) Pwm_Configs = NULL_PTR;
    VAR(Pwm_NotifyType, PWM_VAR) Pwm_Notify = NULL_PTR;
    VAR(Pwm_ChannelType, AUTOMATIC) Pwm_ChannelId = 0U;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelNotificationStatus = NULL_PTR;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag0 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag1 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag2 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag3 = 0U;
    VAR(Pwm_DutycycleType, AUTOMATIC) u32Pwm_Dutycycle = 0U;
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)GetCoreID();    //get core id

    pChannelNotificationStatus = Pwm_Wrapper_Get_ChannelNotification();
    Pwm_Configs = Pwm_Pwm_Wrapper_Get_pChConfigs();

    u8Pwm_Flag0 = GTM_ATOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
        (VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU0TC \
    );
    u8Pwm_Flag1 = GTM_ATOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
        (VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU1TC \
    );

    u8Pwm_Flag2 = GTM_ATOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
        (VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU0TC \
    );
    u8Pwm_Flag3 = GTM_ATOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
        (VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU1TC \
    );

    if(u8Pwm_Flag0 == 1u)
    {
        (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
            ATOM_IRQ_CCU0TC \
        );
    }

    if(u8Pwm_Flag1 == 1u)
    {
        (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
            ATOM_IRQ_CCU1TC \
        );
    }

    if(u8Pwm_Flag2 == 1u)
    {
        (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
            ATOM_IRQ_CCU0TC \
        );
    }

    if(u8Pwm_Flag3 == 1u)
    {
        (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
            ATOM_IRQ_CCU1TC \
        );
    }

    if(Pwm_Configs != NULL_PTR)
    {
        Pwm_Notify = Pwm_Configs->pPwm_AtomNotifyTable[(u8hw_index * PWM_ATOM_CHANNEL_MAX) + u8ch0_index].pNotification;
        Pwm_ChannelId = Pwm_Configs->pPwm_AtomNotifyTable[(u8hw_index * PWM_ATOM_CHANNEL_MAX) + u8ch0_index].nPwmChannelId;

        if((Pwm_Notify != NULL_PTR) && ((u8Pwm_Flag0 == 1U) || (u8Pwm_Flag1 == 1U)))
        {
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if(u32CoreID < 6U)
            {
                if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))
                {
                	Pwm_Notify();
                }
            }
        }

        Pwm_Notify = Pwm_Configs->pPwm_AtomNotifyTable[(u8hw_index * PWM_ATOM_CHANNEL_MAX) + u8ch1_index].pNotification;
        Pwm_ChannelId = Pwm_Configs->pPwm_AtomNotifyTable[(u8hw_index * PWM_ATOM_CHANNEL_MAX) + u8ch1_index].nPwmChannelId;
        if((Pwm_Notify != NULL_PTR) && ((u8Pwm_Flag2 == 1U) || (u8Pwm_Flag3 == 1U)))
        {
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if(u32CoreID < 6U)
            {
                if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))
                {
                	Pwm_Notify();
                }
            }
        }
    }
}

#endif

FUNC(void, PWM_CODE)Pwm_Emios_isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index \
)
{
    P2VAR(Pwm_ChConfigsType, PWM_VAR, PWM_APPL_VAR) Pwm_Configs = NULL_PTR;
    VAR(Pwm_NotifyType, PWM_VAR) Pwm_Notify = NULL_PTR;
    VAR(Pwm_ChannelType, AUTOMATIC) Pwm_ChannelId = 0;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelNotificationStatus = NULL_PTR;
    VAR(uint8, AUTOMATIC) channelState = 0;
    VAR(uint8*, AUTOMATIC) pChannelNotifiClass = NULL_PTR;
    VAR(Pwm_DutycycleType, AUTOMATIC) u32Pwm_Dutycycle = 0U;
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)GetCoreID();    //get core id

    Pwm_Configs = Pwm_Pwm_Wrapper_Get_pChConfigs();

    pChannelNotifiClass = Pwm_Wrapper_Get_ChannelNotifiClass();

    eMIOS_LLD_UC_ClearFlag(u8hw_index,u8ch_index);

    if(Pwm_Configs != NULL_PTR)
    {
        Pwm_Notify = Pwm_Configs->pPwm_EmiosNotifyTable[(u8hw_index * PWM_EMIOS_CHANNEL_MAX) + u8ch_index].pNotification;

        if(Pwm_Notify != NULL_PTR)
        {
            pChannelNotificationStatus = Pwm_Wrapper_Get_ChannelNotification();
            Pwm_ChannelId = Pwm_Configs->pPwm_EmiosNotifyTable[(u8hw_index * PWM_EMIOS_CHANNEL_MAX) + u8ch_index].nPwmChannelId;
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if((u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))
            {
                if(u32CoreID < 6U)
                {
                    if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U))
                    {
                        channelState = Pwm_Wrapper_GetEmiosOutputState(&(Pwm_Configs->sPwmChConfigs[Pwm_ChannelId]));
                        if(pChannelNotifiClass[Pwm_ChannelId] == (uint8)PWM_BOTH_EDGES)
                        {
                            Pwm_Notify();
                        }
                        else if((pChannelNotifiClass[Pwm_ChannelId] == (uint8)PWM_RISING_EDGE) && (channelState == 1U))
                        {
                            Pwm_Notify();
                        }
                        else if((pChannelNotifiClass[Pwm_ChannelId] == (uint8)PWM_FALLING_EDGE) && (channelState == 0U))
                        {
                            Pwm_Notify();
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                }
            }
        }
    }
}

#if (defined(CCFC3007PT) || defined(CCFC3008PT) || defined(CCFC3007BC))
FUNC(void, PWM_CODE)Pwm_Etpu_isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index \
)
{
    P2VAR(Pwm_ChConfigsType, PWM_VAR, PWM_APPL_VAR) Pwm_Configs = NULL_PTR;
    VAR(Pwm_NotifyType, PWM_VAR) Pwm_Notify = NULL_PTR;
    VAR(Pwm_ChannelType, AUTOMATIC) Pwm_ChannelId = 0;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelNotificationStatus = NULL_PTR;
    VAR(Pwm_DutycycleType, AUTOMATIC) u32Pwm_Dutycycle = 0U;
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)GetCoreID();    //get core id

    Pwm_Configs = Pwm_Pwm_Wrapper_Get_pChConfigs();

    if(u8hw_index == 0U)
    {
        (void)ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_A_B,ETPU_A_CHANNLE(u8ch_index));
    }
    else if(u8hw_index == 1U)
    {
        (void)ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_A_B,ETPU_B_CHANNLE(u8ch_index));
    }
    else if(u8hw_index == 2U)
    {
        (void)ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_C,ETPU_C_CHANNLE(u8ch_index));
    }
    else
    {
        /* Do nothing */
    }

    if(Pwm_Configs != NULL_PTR)
    {
        Pwm_Notify = Pwm_Configs->pPwm_EtpuNotifyTable[(u8hw_index * PWM_ETPU_CHANNEL_MAX) + u8ch_index].pNotification;

        if(Pwm_Notify != NULL_PTR)
        {
            pChannelNotificationStatus = Pwm_Wrapper_Get_ChannelNotification();
            Pwm_ChannelId = Pwm_Configs->pPwm_EtpuNotifyTable[(u8hw_index * PWM_ETPU_CHANNEL_MAX) + u8ch_index].nPwmChannelId;
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if(u32CoreID < 6U)
            {
                if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))
                {
                	Pwm_Notify();
                }
            }
        }
    }
}
#endif

static volatile VAR(eMIOS_PWM_DAOC_ISR_ParamType, PWM_VAR) Pwm_Emios_DAOC_Param[PWM_EMIOS_CHANNEL_MAX * PWM_EMIOS_MAX];

FUNC(void, PWM_CODE) Pwm_Set_Emios_DAOC_B \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index, \
    VAR(uint32, AUTOMATIC) value \
)
{
    if((((PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index) < (PWM_EMIOS_CHANNEL_MAX * PWM_EMIOS_MAX)) && (value < 0xFFFFFFU))
    {
        Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].duty = value;
    }
    else
    {
        if(((PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index) < (PWM_EMIOS_CHANNEL_MAX * PWM_EMIOS_MAX))
        {
            Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].duty = 0xFFFFFFU;
        }

    }
}

FUNC(void, PWM_CODE) Pwm_Set_Emios_DAOC_Active \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index, \
    VAR(uint32, AUTOMATIC) value \
)
{
    Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].active = (uint8)value;
}

FUNC(void, PWM_CODE) Pwm_Emios_DAOC_Isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index \
)
{
    VAR(uint8, AUTOMATIC) vla = 0;
    vla = eMIOS_UC_Sn_GetUCOUT(u8hw_index, u8ch_index);
    if(((PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index) < (PWM_EMIOS_CHANNEL_MAX * PWM_EMIOS_MAX))
    {
        if(vla != Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].active)
        {
            if(Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].duty < 0xFFFFFFU)
            {
                eMIOS_UC_Bn_SetValue \
                ( \
                        u8hw_index, \
                        u8ch_index, \
                        Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].duty \
                );
            }
            else
            {
                eMIOS_UC_Bn_SetValue \
                ( \
                        u8hw_index, \
                        u8ch_index, \
                        0xFFFFFFU \
                );
            }
            eMIOS_UC_An_SetValue(u8hw_index, u8ch_index,1U);
        }
    }
}

#ifdef __cplusplus
}
#endif
