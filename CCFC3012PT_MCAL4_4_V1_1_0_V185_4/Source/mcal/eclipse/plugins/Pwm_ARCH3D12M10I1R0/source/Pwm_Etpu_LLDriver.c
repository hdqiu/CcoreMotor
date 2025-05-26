
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC3007BC
* DESCRIPTION : CCFC3007BC etpu low level drivers h file
* HISTORY     : Initial version
* @file     Pwm_Etpu_LLDriver.c
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/

/*PRQA S 1503 EOF */
#include "status.h"

#include "Pwm_Etpu_LLDriver.h"

#define CHANNEL_NUM 32
#define ETPU_GROUP_NUM 3

#define PWM_ETPU_LLD_C_VENDOR_ID                      176
#define PWM_ETPU_LLD_C_AR_REL_MAJOR_VER               4
#define PWM_ETPU_LLD_C_AR_REL_MINOR_VER               4
#define PWM_ETPU_LLD_C_AR_REL_REV_VER                 0
#define PWM_ETPU_LLD_C_SW_MAJOR_VER                   1
#define PWM_ETPU_LLD_C_SW_MINOR_VER                   0
#define PWM_ETPU_LLD_C_SW_PATCH_VER                   1

#if (defined(CCFC3007PT) || defined(CCFC3008PT) || defined(CCFC3007BC))
#include "eTPU_LLDrivers.h"        /*PRQA S 0380 */

#if (PWM_ETPU_LLD_C_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_C_VENDOR_ID "
#endif
#if (PWM_ETPU_LLD_C_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_ETPU_LLD_C_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_C_AR_REL_MINOR_VER "
#endif
#if (PWM_ETPU_LLD_C_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_C_AR_REL_REV_VER "
#endif
#if (PWM_ETPU_LLD_C_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_C_SW_MAJOR_VER "
#endif
#if (PWM_ETPU_LLD_C_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_C_SW_MINOR_VER "
#endif
#if (PWM_ETPU_LLD_C_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_ETPU_LLD_C_SW_PATCH_VER "
#endif

#define PWM_START_SEC_VAR_SHARED_INIT
#include "Pwm_MemMap.h"
static P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) all_pba[ETPU_GROUP_NUM][CHANNEL_NUM]={{0},{0},{0}};
#define PWM_STOP_SEC_VAR_SHARED_INIT
#include "Pwm_MemMap.h"

static FUNC(uint32, PWM_CODE) ETPU_LLD_PWM_GetFrequency \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) timebaseFrequency \
);

LOCAL_INLINE FUNC(uint32*, PWM_CODE) get_pba_addr \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    VAR(uint8, AUTOMATIC) etpu_num = 0;
    VAR(uint8, AUTOMATIC) channel_num = 0;
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) ret = NULL;

    if((etpuGroup == 0U) && (channel > 63U))
    {
        etpu_num = 1;
        channel_num = (uint8)(channel - 64U);
    }
    else if(etpuGroup == 1U)
    {
        etpu_num = 2U;
        channel_num = channel;
    }else{
        etpu_num = etpuGroup;
        channel_num = channel;
    }
    if((etpu_num < 3U) && (channel_num < 32U))
    {
        if(all_pba[etpu_num][channel_num] != NULL)
        {
            ret = all_pba[etpu_num][channel_num];
        }
        else
        {
            ret = ETPU_LLD_Malloc_32(etpuGroup, ETPU_PWM_NUM_PARMS);
            all_pba[etpu_num][channel_num] = ret;
        }
    }
    return ret;
}

FUNC(status_t, PWM_CODE) ETPU_LLD_PWM_Init \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    P2CONST(etpu_pwm_param_t, AUTOMATIC, PWM_APPL_CONST) parameter \
)
{
    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pba;  /* parameter base address for channel */
    VAR(uint32, AUTOMATIC) period;

    /* QAC warning solution */
    all_pba[0][0] = (void *)0;

    /* Determine frequency of output waveform */
    period = parameter->period;

    if ((period == 0U) || (period > 0x007FFFFFU ))
    {
        ret = STATUS_ETPU_WRONG_PARAMETER;
    }

    /*Get channle parameter baseaddress */
    if (eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.B.CPBA == 0U)
    {
        /* get parameter RAM number of parameters passed from eTPU C code */
        pba = get_pba_addr(etpuGroup, channel);

        if (pba == NULL_PTR)
        {
            ret = STATUS_ETPU_WRONG_CODE_SIZE;
        }
    }
    else /*set pba to what is in the CR register*/
    {
        pba=ETPU_LLD_GetDataRam(etpuGroup, channel);
    }

    if (ret == STATUS_SUCCESS)
    {
        /* Disable channel to assign function safely */
        ETPU_LLD_ChannelDisable(etpuGroup, channel);

        /* write parameters to data memory */
        *(pba + ((ETPU_PWM_PERIOD_OFFSET - 1U) >> 2U)) = period;
        *(pba + ((ETPU_PWM_ACTIVE_OFFSET - 1U) >> 2U)) = parameter->dutyCycle;


        if(etpuGroup < 2U)
        {
            /* write channel configuration register */
            eTPUInstance[etpuGroup].eTPU->CHAN[channel].CR.R = ((uint32)parameter->priority << 28U) + \
                                                               ((uint32)ETPU_PWM_TABLE_SELECT << 24U) + \
                                                               ((uint32)((uint32)pba - eTPUInstance[etpuGroup].data_ram_start) >> 3U);
            /* write FM (function mode) bits */
            eTPUInstance[etpuGroup].eTPU->CHAN[channel].SCR.R = ((uint32)parameter->timebase << 1) + (uint32)parameter->polarity;

            /* write hsr to start channel running */
            eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_PWM_INIT;
        }


    }

    return ret;
}

/******************************************************************************
FUNCTION     : ETPU_LLD_PWM_SetDutyCycle
PURPOSE      : To immedately update a channel dutycycle using a 16 bit integer value.
                This function will update the dutycycle during the current period
                if possible. The ineteger value is the percentage *100, so 20% would
                be 2000.
INPUTS NOTES : This function has 2 parameters:
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
               dutyCycle - This is the dutyCycle cycle of the PWM. This is a
                        uint16 with a range of 0-0x8000. To represent 0-100%
                        with 0.01% resolution.
******************************************************************************/
FUNC(void, PWM_CODE) ETPU_LLD_PWM_SetDutyCycle \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint16, AUTOMATIC) dutyCycle \
)
{
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pba;
    VAR(uint32, AUTOMATIC) period;

    pba = ETPU_LLD_GetDataRam(etpuGroup, channel);

    period = *((pba + ETPU_PWM_PERIOD_OFFSET)-1U);

    pba += ((ETPU_PWM_ACTIVE_OFFSET-1U) >> 2U);
    period = period & 0xFFFFFFU;
    *pba = (uint32)((uint64)((uint64)period * (uint64)dutyCycle) >> 15);

    /* do immediate update of dutyCycle cycle is possible */
    eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_PWM_IMM_UPDATE;
}

/******************************************************************************
FUNCTION     : ETPU_LLD_PWM_SetFrequency
PURPOSE      : To update a PWM output's frequency
INPUTS NOTES : This function has 4 parameters:
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
               frequency - This is the frequency of the PWM. This is an unint32_t
                        but the value range is only 24 bits. The range of
                        this parameter is determine by the complete system but
                        normally would be between 1Hz-100kHz.
               timebaseFrequency - This is the frequency of the selected timebase.
                 The range of this is the same as the range of the timebase
                 frequency on the device. This parameter is a uint32_t.
RETURNS NOTES: Error code if frequency is out of range: ETPU_ERROR_FREQ
******************************************************************************/
FUNC(status_t, PWM_CODE) ETPU_LLD_PWM_SetFrequency \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) frequency, \
    VAR(uint32, AUTOMATIC) timebaseFrequency \
)
{
    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pba;
    VAR(uint32, AUTOMATIC) period;

    /* Determine frequency of output waveform */
    period = timebaseFrequency / frequency;

    if ((period == 0U) || (period > 0x007FFFFFU ))
    {
        ret = STATUS_ETPU_WRONG_PARAMETER;
    }

    if (ret == STATUS_SUCCESS)
    {
        pba = ETPU_LLD_GetDataRam(etpuGroup, channel);

        /* write parameters to data memory */
        *(pba + ((ETPU_PWM_PERIOD_OFFSET - 1U) >> 2U)) = period;

        eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_PWM_IMM_UPDATE;
    }

    return ret;
}

#ifdef __ghs__
#pragma ghs ZO
#endif

FUNC(status_t, PWM_CODE) ETPU_LLD_PWM_SetPeriodAndDuty \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) period, \
    VAR(uint32, AUTOMATIC) duty \
)
{
    VAR(status_t, AUTOMATIC) ret = STATUS_SUCCESS;
    P2VAR(uint32, AUTOMATIC, PWM_APPL_DATA) pba;

    /* Determine frequency of output waveform */

    if ((period == 0U) || (period > 0x007FFFFFU ))
    {
        ret = STATUS_ETPU_WRONG_PARAMETER;
    }

    if (ret == STATUS_SUCCESS)
    {
        pba = ETPU_LLD_GetDataRam(etpuGroup, channel);

        /* write parameters to data memory */

        *(pba + ((ETPU_PWM_CO_PERIOD_OFFSET - 1U) >> 2U)) = period;
        *(pba + ((ETPU_PWM_CO_ACTIVE_OFFSET - 1U) >> 2U))  = duty;

        eTPUInstance[etpuGroup].eTPU->CHAN[channel].HSRR.R = ETPU_PWM_CO_UPDATE;
    }

    return ret;
}
#ifdef __ghs__
#pragma ghs OS
#endif

/******************************************************************************
FUNCTION     : ETPU_LLD_PWM_GetDutyCycle
PURPOSE      : To determine the actual dutycycle by the PWM channel.
INPUTS NOTES : This function has 2 parameters:
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
               timebaseFrequency - This is the frequency of the selected timebase.
                 The range of this is the same as the range of the timebase
                 frequency on the device. This parameter is a uint32_t.
RETURNS NOTES: The actual frequency as an integer.
WARNING      :
******************************************************************************/
FUNC(uint32, PWM_CODE) ETPU_LLD_PWM_GetDutyCycle \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) timebaseFrequency \
)
{
    VAR(uint32, AUTOMATIC) dutyCycle;
    P2CONST(uint32, AUTOMATIC, PWM_APPL_CONST) pba;

    pba = ETPU_LLD_GetDataRam(etpuGroup, channel);

    dutyCycle = *(pba + ((ETPU_PWM_ACTIVE_OFFSET - 1U) >> 2U));
    dutyCycle = ((dutyCycle * 1000U) / ETPU_LLD_PWM_GetFrequency(etpuGroup, channel, timebaseFrequency));

    return dutyCycle;
}

/******************************************************************************
FUNCTION     : ETPU_LLD_PWM_GetFrequency
PURPOSE      : To determine the actual frequency by the PWM channel.
INPUTS NOTES : This function has 2 parameters:
               channel - This is the channel number.
                           0-31 for ETPU_A and 64-95 for ETPU_B.
               timebaseFrequency - This is the frequency of the selected timebase.
                 The range of this is the same as the range of the timebase
                 frequency on the device. This parameter is a uint32_t.
RETURNS NOTES: The actual frequency as an integer.
WARNING      :
******************************************************************************/
static FUNC(uint32, PWM_CODE) ETPU_LLD_PWM_GetFrequency   /*PRQA S 1505 */ \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel, \
    VAR(uint32, AUTOMATIC) timebaseFrequency \
)
{
    VAR(uint32, AUTOMATIC) period;
    P2CONST(uint32, AUTOMATIC, PWM_APPL_CONST) pba;

    pba = ETPU_LLD_GetDataRam(etpuGroup, channel);

    period = *(pba + ((ETPU_PWM_PERIOD_OFFSET - 1U) >> 2U));
    period = period & 0xFFFFFFU;

    return(timebaseFrequency / period);
}

FUNC(uint8, PWM_CODE) ETPU_LLD_PWM_GetOutputState \
( \
    VAR(uint8, AUTOMATIC) etpuGroup, \
    VAR(uint8, AUTOMATIC) channel \
)
{
    VAR(uint8, AUTOMATIC) state = 0;

    if(etpuGroup == 0U)
    {
        state = ETPU_LLD_GetChannelOutputStatus(ETPU_INSTANCE_A_B,ETPU_A_CHANNLE(channel));
    }else if(etpuGroup == 1U)
    {
        state = ETPU_LLD_GetChannelOutputStatus(ETPU_INSTANCE_A_B,ETPU_B_CHANNLE(channel));
    }else if(etpuGroup == 2U)
    {
        state = ETPU_LLD_GetChannelOutputStatus(ETPU_INSTANCE_C,ETPU_C_CHANNLE(channel));
    }else{
        /* nothing */
    }

    return state;
}
#endif
