/**************************************************************************** 
*
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* @file     srx_lld.c
* @version  1.0
* @date     2023 - 01 - 01
* @brief    Initial version.
*
*****************************************************************************/
/*PRQA S 3218,0654,3469,4404,3119,3205,0316,4603,3673,1505,1503,2841 EOF*/
#include "Mcu_LLDriver.h"/*PRQA S 0380*/
#include "eDma_LLDriver.h"/*PRQA S 0380*/
#include "intc_lld.h"
#include "Sent_LLDriver.h"
#include "Sent.h"
#include "SchM_Sent.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define SENT_VENDOR_ID_C                 176
#define SENT_AR_MAJOR_VER_C              4
#define SENT_AR_MINOR_VER_C              4
#define SENT_AR_PATCH_VER_C              0
#define SENT_SW_MAJOR_VER_C              1
#define SENT_SW_MINOR_VER_C              0
#define SENT_SW_PATCH_VER_C              1

/*============================================FILE VERSION CHECKS===================================*/

/* Check if current file and SENT header file are of the same vendor */
#if (SENT_VENDOR_ID_C != SENT_VENDOR_ID)
#error "NON-MATCHED DATA : SENT_VENDOR_ID"
#endif

/* Check if current file and SENT header file are of the same Autosar version */
#if (SENT_AR_MAJOR_VER_C != SENT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MAJOR_VER"
#endif
#if (SENT_AR_MINOR_VER_C != SENT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_MINOR_VER"
#endif
#if (SENT_AR_PATCH_VER_C != SENT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_AR_PATCH_VER"
#endif

/* Check if current file and SENT header file are of the same Software version */
#if (SENT_SW_MAJOR_VER_C != SENT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MAJOR_VER"
#endif
#if (SENT_SW_MINOR_VER_C != SENT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_MINOR_VER"
#endif
#if (SENT_SW_PATCH_VER_C != SENT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : SENT_CFG_SW_PATCH_VER"
#endif


/**
 * Defines 1s/x = SRX_ONE_MICROSECOND_CYCLES
 */
#define SRX_ONE_MICROSECOND_CYCLES (1000000u)

static SRX_Type * const s_srxBase[SRX_INSTANCE_COUNT] = SRX_BASE_PTRS;

/*******************************************************************************
 * Private data
 ******************************************************************************/




/*******************************************************************************
 * Private functions
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetTimestampPrescaler
 * Description   : This function sets the timestamp prescaler value
 *
 *END**************************************************************************/

FUNC(void, SENT_CODE) SRX_LLD_SetTimestampPrescaler(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) value)
{
    if(instance < (uint8)SRX_INSTANCE_COUNT)
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_00();
        /* Ensure clearing before modification */
        s_srxBase[instance]->GBL_CTRL.B.TSPRSC = value;
        SchM_Exit_SENT_EXCLUSIVE_AREA_00();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetChannelPrescaler
 * Description   : Sets the channel prescaler.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_SetChannelPrescaler(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(uint16 , AUTOMATIC) prescaler)
{
    uint16 lPre;
    uint16 maxVal;

    /* Prescaler limited to maximum range of SRX_CLK_CTRL_PRSC_WIDTH bits */
    maxVal = (uint16)((uint16)((uint16)1u << SRX_CLK_CTRL_PRSC_WIDTH) - 1u);
    lPre = (prescaler > maxVal) ? maxVal : prescaler;

    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_01();
        s_srxBase[instance]->CH[channel].CLK_CTRL.B.PRSC = lPre;
        SchM_Exit_SENT_EXCLUSIVE_AREA_01();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetChannelCompensation
 * Description   : Sets the channel compensation state (enable / disable).
 * This enables automatic compesation for deviations in the receve u32clock.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_SetChannelCompensation(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) state)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_02();
        if(state == TRUE)
        {
            s_srxBase[instance]->CH[channel].CLK_CTRL.B.COMP_EN= 1u;
        }
        else
        {
            s_srxBase[instance]->CH[channel].CLK_CTRL.B.COMP_EN = 0u;
        }
        SchM_Exit_SENT_EXCLUSIVE_AREA_02();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetBusIdleCnt
 * Description   : Sets the value for the Bus Idle Count paramter.
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_SetBusIdleCnt(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(srx_idle_cnt_cfg_t , AUTOMATIC) count)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_03();
        /* Clear first */
        switch(count)
        {
        case SRX_BUS_IDLE_DISABLED:
            s_srxBase[instance]->CH[channel].CONFIG.B.BUS_IDLE_CNT = 0u;
            break;

        case SRX_BUS_IDLE_245_CLK_TICKS:
            s_srxBase[instance]->CH[channel].CONFIG.B.BUS_IDLE_CNT = 1u;
            break;

        case SRX_BUS_IDLE_508_CLK_TICKS:
            s_srxBase[instance]->CH[channel].CONFIG.B.BUS_IDLE_CNT = 2u;
            break;

        case SRX_BUS_IDLE_1016_CLK_TICKS:
            s_srxBase[instance]->CH[channel].CONFIG.B.BUS_IDLE_CNT = 4u;
            break;

        case SRX_BUS_IDLE_2032_CLK_TICKS:
            s_srxBase[instance]->CH[channel].CONFIG.B.BUS_IDLE_CNT = 8u;
            break;

        default: /* Disabled since there was a clear first */
            break;
        }
        SchM_Exit_SENT_EXCLUSIVE_AREA_03();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetCalRng
 * Description   : Sets the value for the Calibration Range paramter.
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_SetCalRng(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(srx_calib_pulse_var_cfg_t , AUTOMATIC) range)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_04();
        s_srxBase[instance]->CH[channel].CONFIG.B.CAL_RNG = (uint8)range;
        SchM_Exit_SENT_EXCLUSIVE_AREA_04();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetPpChkSel
 * Description   : Sets the value for the Pause Pulse Check paramter.
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_SetPpChkSel(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(srx_pulse_cfg_t , AUTOMATIC) check)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_05();
        s_srxBase[instance]->CH[channel].CONFIG.B.PP_CHKSEL = (uint8)check;
        SchM_Exit_SENT_EXCLUSIVE_AREA_05();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetPausePulseEnable
 * Description   : Enables / disables the detection of pause pulses.
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_SetPausePulseEnable(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(srx_pause_pulse_cfg_t , AUTOMATIC) stat)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_06();
        s_srxBase[instance]->CH[channel].CONFIG.B.PAUSE_EN= (uint8)stat;
        SchM_Exit_SENT_EXCLUSIVE_AREA_06();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetSuccCalChk
 * Description   : Sets the value of the Successive Calibration Check parameter
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_SetSuccCalChk(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(srx_succ_cal_check_cfg_t , AUTOMATIC) type)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_07();
        s_srxBase[instance]->CH[channel].CONFIG.B.SUCC_CAL_CHK = (uint8)type;
        SchM_Exit_SENT_EXCLUSIVE_AREA_07();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetSlowCrcType
 * Description   : Sets the value of the Slow Message CRC Type parameter
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_SetSlowCrcType(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(srx_msg_crc_t , AUTOMATIC) type)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_08();
        s_srxBase[instance]->CH[channel].CONFIG.B.SCRC_TYPE = (uint8)type;
        SchM_Exit_SENT_EXCLUSIVE_AREA_08();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetFastCrcType
 * Description   : Sets the value of the Fast Message CRC Type parameter
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_SetFastCrcType(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(srx_msg_crc_t , AUTOMATIC) type)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_09();
        s_srxBase[instance]->CH[channel].CONFIG.B.FCRC_TYPE = (uint8)type;
        SchM_Exit_SENT_EXCLUSIVE_AREA_09();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetFastCrcIncStatus
 * Description   : Sets the Include Status Nibble in CRC calculation parameter.
 * This is valid only for Fast messages.
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_SetFastCrcIncStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(srx_fcrc_sc_cfg_t , AUTOMATIC) stat)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_10();
        s_srxBase[instance]->CH[channel].CONFIG.B.FCRC_SC_EN = (uint8)stat;
        SchM_Exit_SENT_EXCLUSIVE_AREA_10();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetFastDisableCrc
 * Description   : Sets the enabling / disabling of CRC verification for Fast
 * messages
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_SetFastDisableCrc(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(srx_fcrc_check_cfg_t , AUTOMATIC) stat)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_11();
        s_srxBase[instance]->CH[channel].CONFIG.B.FCRC_CHK_OFF = (uint8)stat;
        SchM_Exit_SENT_EXCLUSIVE_AREA_11();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetFastNumNibbles
 * Description   : Configures the number of nibbles for the Fast channel.
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_SetFastNumNibbles(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(uint8 , AUTOMATIC) num)
{
    uint32 locVal = (num < (uint8)1u) ? (uint32)1u : ((num > (uint8)6u) ? (uint32)6u : (uint32)num);

    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_12();
        if(channel < 8)
        {
            /* Clear the current value */
            s_srxBase[instance]->DATA_CTRL1.R &= ~(SRX_DATA_CTRL1_NIBBCH0_MASK >> (4u * channel));

            /* Write it back */
            s_srxBase[instance]->DATA_CTRL1.R |= (locVal << (28u - (4u * channel))); /* Register layout */
        }
        else
        {
            /* Clear the current value */
            s_srxBase[instance]->DATA_CTRL2.R &= ~(SRX_DATA_CTRL2_NIBBCH0_MASK >> (4u * (channel - 8)));

            /* Write it back */
            s_srxBase[instance]->DATA_CTRL2.R |= (locVal << (28u - (4u * (channel - 8)))); /* Register layout */
        }
        SchM_Exit_SENT_EXCLUSIVE_AREA_12();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetChannelStatus
 * Description   : Enables / disables reception for the given channels.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_SetChannelStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint16 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_13();
        if(enable == TRUE)
        {
            s_srxBase[instance]->CHNL_EN.R |= (uint32)((uint32)1u << channel);
        }
        else
        {
            s_srxBase[instance]->CHNL_EN.R &= (uint32)(~((uint32)1u << channel));
        }
        SchM_Exit_SENT_EXCLUSIVE_AREA_13();
    }

}


/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetPeripheralStatus
 * Description   : Enables / disables the peripheral
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_SetPeripheralStatus(CONST(uint8, AUTOMATIC) instance, CONST(boolean, AUTOMATIC) enable)
{
    if(instance < (uint8)SRX_INSTANCE_COUNT)
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_14();
        if(enable == TRUE)
        {
            s_srxBase[instance]->GBL_CTRL.B.SENT_EN = 1u;
        }
        else
        {
            s_srxBase[instance]->GBL_CTRL.B.SENT_EN= 0u;
        }
        SchM_Exit_SENT_EXCLUSIVE_AREA_14();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetActiveEvents
 * Description   : Returns current active diagnostics events
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(uint32, SENT_CODE) SRX_LLD_GetActiveEvents(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel)
{
    uint32 evTemp = 0u;
    uint32 regState = 0u;
    uint32 regGlobal = 0u;

    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        regState = s_srxBase[instance]->CH[channel].STATUS.R;
        regGlobal = s_srxBase[instance]->GBL_STATUS.R;

        /* Put events in temp var */
        if((regState & (uint32)SRX_EV_BUS_IDLE) != 0u)
        {
            evTemp |= SRX_EV_BUS_IDLE;/*PRQA S 2984*/
        }

        if((regState & (uint32)SRX_EV_CAL_RESYNC) != 0u)
        {
            evTemp |= SRX_EV_CAL_RESYNC;
        }

        if((regState & (uint32)SRX_EV_CAL_20_25) != 0u)
        {
            evTemp |= SRX_EV_CAL_20_25;
        }

        if((regState & (uint32)SRX_EV_SMSG_OFLW) != 0u)
        {
            evTemp |= SRX_EV_SMSG_OFLW;
        }

        if((regState & (uint32)SRX_EV_FMSG_OFLW) != 0u)
        {
            evTemp |= SRX_EV_FMSG_OFLW;
        }

        if((regState & (uint32)SRX_EV_PP_DIAG_ERR) != 0u)
        {
            evTemp |= SRX_EV_PP_DIAG_ERR;
        }

        if((regState & (uint32)SRX_EV_CAL_LEN_ERR) != 0u)
        {
            evTemp |= SRX_EV_CAL_LEN_ERR;
        }

        if((regState & (uint32)SRX_EV_CAL_DIAG_ERR) != 0u)
        {
            evTemp |= SRX_EV_CAL_DIAG_ERR;
        }

        if((regState & (uint32)SRX_EV_NIB_VAL_ERR) != 0u)
        {
            evTemp |= SRX_EV_NIB_VAL_ERR;
        }

        if((regState & (uint32)SRX_EV_SMSG_CRC_ERR) != 0u)
        {
            evTemp |= SRX_EV_SMSG_CRC_ERR;
        }

        if((regState & (uint32)SRX_EV_FMSG_CRC_ERR) != 0u)
        {
            evTemp |= SRX_EV_FMSG_CRC_ERR;
        }

        if((regState & (uint32)SRX_EV_NUM_EDGES_ERR) != 0u)
        {
            evTemp |= SRX_EV_NUM_EDGES_ERR;
        }

    #ifdef FEATURE_SRX_DMA_HAS_FIFO
        if((regGlobal & (uint32)SRX_GBL_STATUS_FMFO_MASK) != 0u)
        {
            evTemp |= SRX_EV_FIFO_OVERFLOW;
        }
    #endif

        if((regGlobal & (uint32)SRX_EV_FDMA_UNDERFLOW) != 0u)
        {
            evTemp |= SRX_EV_FDMA_UNDERFLOW;
        }

        if((regGlobal & (uint32)SRX_EV_SDMA_UNDERFLOW) != 0u)
        {
            evTemp |= SRX_EV_SDMA_UNDERFLOW;
        }
    }

    return evTemp;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_ClearActiveEvents
 * Description   : Clears the flags for the events in the given mask.
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_ClearActiveEvents(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, CONST(uint32 , AUTOMATIC) events)
{
    uint32 clrMask = 0u;
    uint32 gClrMask = 0u; /* For global events */

    /* Put events in temp var */
    if((events & SRX_EV_BUS_IDLE) != 0u)
    {
        clrMask |= SRX_EV_BUS_IDLE;/*PRQA S 2984*/
    }

    if((events & SRX_EV_CAL_RESYNC) != 0u)
    {
        clrMask |= SRX_EV_CAL_RESYNC;
    }

    if((events & SRX_EV_CAL_20_25) != 0u)
    {
        clrMask |= SRX_EV_CAL_20_25;
    }

    if((events & SRX_EV_SMSG_OFLW) != 0u)
    {
        clrMask |= SRX_EV_SMSG_OFLW;
    }

    if((events & SRX_EV_FMSG_OFLW) != 0u)
    {
        clrMask |= SRX_EV_FMSG_OFLW;
    }

    if((events & SRX_EV_PP_DIAG_ERR) != 0u)
    {
        clrMask |= SRX_EV_PP_DIAG_ERR;
    }

    if((events & SRX_EV_CAL_LEN_ERR) != 0u)
    {
        clrMask |= SRX_EV_CAL_LEN_ERR;
    }

    if((events & SRX_EV_CAL_DIAG_ERR) != 0u)
    {
        clrMask |= SRX_EV_CAL_DIAG_ERR;
    }

    if((events & SRX_EV_NIB_VAL_ERR) != 0u)
    {
        clrMask |= SRX_EV_NIB_VAL_ERR;
    }

    if((events & SRX_EV_SMSG_CRC_ERR) != 0u)
    {
        clrMask |= SRX_EV_SMSG_CRC_ERR;
    }

    if((events & SRX_EV_FMSG_CRC_ERR) != 0u)
    {
        clrMask |= SRX_EV_FMSG_CRC_ERR;
    }

    if((events & SRX_EV_NUM_EDGES_ERR) != 0u)
    {
        clrMask |= SRX_EV_NUM_EDGES_ERR;
    }

    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        SchM_Enter_SENT_EXCLUSIVE_AREA_15();
        /* RMW the channel status register */
        s_srxBase[instance]->CH[channel].STATUS.R = clrMask;
        SchM_Exit_SENT_EXCLUSIVE_AREA_15();

    #ifdef FEATURE_SRX_DMA_HAS_FIFO
        if((events & SRX_EV_FIFO_OVERFLOW) != 0u)
        {
            gClrMask |= SRX_EV_FIFO_OVERFLOW;
        }
    #endif /* FEATURE_SRX_DMA_HAS_FIFO */

        if((events & SRX_EV_FDMA_UNDERFLOW) != 0u)
        {
            gClrMask |= SRX_EV_FDMA_UNDERFLOW;/*PRQA S 2984*/
        }

        if((events & SRX_EV_SDMA_UNDERFLOW) != 0u)
        {
            gClrMask |= SRX_EV_SDMA_UNDERFLOW;
        }

        SchM_Enter_SENT_EXCLUSIVE_AREA_16();
        /* Global RMW */
        s_srxBase[instance]->GBL_STATUS.R = gClrMask;
        SchM_Exit_SENT_EXCLUSIVE_AREA_16();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetFastRxInterrupt
 * Description   : Enables / disables Interrupts for the Rx
 * event on the Slow channel.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_SetFastRxInterrupt(CONST(uint8, AUTOMATIC) instance, CONST(uint16 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable)
{
    SchM_Enter_SENT_EXCLUSIVE_AREA_17();
    /* Just mask the bit */
    /* Predefined masks not usable */
    if((enable == TRUE) && (channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        s_srxBase[instance]->FRDY_IE.B.FRDY_IE |= (uint16)((uint16)1U << channel);
    }
    else
    {
        s_srxBase[instance]->FRDY_IE.B.FRDY_IE &= ~(uint16)((uint16)1U << channel);
    }
    SchM_Exit_SENT_EXCLUSIVE_AREA_17();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_SetSlowRxInterrupt
 * Description   : Enables / disables Interrupts for the Rx
 * event on the Slow channel.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_SetSlowRxInterrupt(CONST(uint8, AUTOMATIC) instance, CONST(uint16 , AUTOMATIC) channel, CONST(boolean , AUTOMATIC) enable)
{
    SchM_Enter_SENT_EXCLUSIVE_AREA_18();
    /* Just mask the bit */
    /* Predefined masks not usable */
    if((enable == TRUE) && (channel <= (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        s_srxBase[instance]->SRDY_IE.B.SRDY_IE |= (uint8)((uint8)1u << channel);
    }
    else
    {
        s_srxBase[instance]->SRDY_IE.B.SRDY_IE &= ~(uint8)((uint8)1u << channel);
    }
    SchM_Exit_SENT_EXCLUSIVE_AREA_18();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetFastRxStatus
 * Description   : Returns current Rx status for the Fast channel.
 * This will return true if there
 * is a new message present in the buffer.
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(boolean, SENT_CODE)SRX_HW_GetFastRxStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    /* Just pass the status */
    boolean flag = FALSE;

    if(channel <= (uint8)SRX_CHANNEL_COUNT && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        flag = (((uint32)(s_srxBase[instance]->FMSG_RDY.B.F_RDY & ((uint32)1u << channel)) != 0u) ? TRUE : FALSE);
    }

    return flag;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetSlowRxStatus
 * Description   : Returns current Rx status for the Slow channel.
 * This will return true if there
 * is a new message present in the buffer.
 *
 *END**************************************************************************/
FUNC(boolean, SENT_CODE) SRX_HW_GetSlowRxStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    /* Just pass the status */
    boolean flag = FALSE;

    if(channel < (uint8)SRX_CHANNEL_COUNT && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        flag = (((uint32)(s_srxBase[instance]->SMSG_RDY.B.S_RDY & ((uint32)1u << channel)) != 0u) ? TRUE : FALSE);
    }

    return flag;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetFastRawMsg
 * Description   : Returns current Fast message in the raw format (unformatted).
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_GetFastRawMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2VAR(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        /* Populate according to registers */
        rawMsg->dataField0 = s_srxBase[instance]->CHANNEL[channel].FMSG_DATA.R;
        rawMsg->dataField1 = s_srxBase[instance]->CHANNEL[channel].FMSG_CRC.R;
        rawMsg->dataField2 = s_srxBase[instance]->CHANNEL[channel].FMSG_TS.R;
        /* Clear the RDY channels */
        SchM_Enter_SENT_EXCLUSIVE_AREA_19();
        s_srxBase[instance]->FMSG_RDY.B.F_RDY |= (uint8)((uint8)1u << channel);
        SchM_Exit_SENT_EXCLUSIVE_AREA_19();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetSlowRawMsg
 * Description   : Returns current Slow message in the raw format (unformatted).
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_GetSlowRawMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2VAR(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg)
{
    if((channel < (uint8)SRX_CHANNEL_COUNT) && (instance < (uint8)SRX_INSTANCE_COUNT))
    {
        /* Populate according to registers */
        rawMsg->dataField0 = s_srxBase[instance]->CHANNEL[channel].SMSG_BIT3.R;
        rawMsg->dataField1 = s_srxBase[instance]->CHANNEL[channel].SMSG_BIT2.R;
        rawMsg->dataField2 = s_srxBase[instance]->CHANNEL[channel].SMSG_TS.R;

        /* Clear the RDY channels */
        SchM_Enter_SENT_EXCLUSIVE_AREA_20();
        s_srxBase[instance]->SMSG_RDY.B.S_RDY |= (uint8)((uint8)1u << channel);
        SchM_Exit_SENT_EXCLUSIVE_AREA_20();
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_ConvertFastRaw
 * Description   : Converts an unformatted (raw) Fast message
 * into a formatted one.
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_ConvertFastRaw(P2VAR(srx_fast_msg_t, AUTOMATIC, SENT_APPL_DATA) msg, P2CONST(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg)
{
    /* FMSG_DATA register */
    msg->channelNumber = (uint8)((uint32)(rawMsg->dataField0 & SRX_FMSG_DATA_CHNUM_MASK) >> SRX_FMSG_DATA_CHNUM_SHIFT);
    msg->statusField = (uint8)((uint32)(rawMsg->dataField0 & SRX_FMSG_DATA_SCNIB_MASK) >> SRX_FMSG_DATA_SCNIB_SHIFT);

    /* Get full data and then shift depending on configured number of nibbles */
    msg->data = rawMsg->dataField0 & (SRX_FMSG_DATA_DNIB1_MASK
                                        | SRX_FMSG_DATA_DNIB2_MASK
                                        | SRX_FMSG_DATA_DNIB3_MASK
                                        | SRX_FMSG_DATA_DNIB4_MASK
                                        | SRX_FMSG_DATA_DNIB5_MASK
                                        | SRX_FMSG_DATA_DNIB6_MASK);

    /* FMSG_CRC register */
    msg->crc = (uint8)((uint32)(rawMsg->dataField1 & SRX_FMSG_CRC_CRC4b_MASK) >> SRX_FMSG_CRC_CRC4b_SHIFT);

    /* FMSG TS register */
    msg->timeStamp = rawMsg->dataField2;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_ConvertSlowRaw
 * Description   : Converts an unformatted (raw) Slow message
 * into a formatted one.
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_ConvertSlowRaw(P2VAR(srx_slow_msg_t, AUTOMATIC, SENT_APPL_DATA) msg, P2CONST(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg)
{
    srx_slow_msg_type_t locType;

    /* Channel number */
    msg->channelNumber = (uint8)((uint32)(rawMsg->dataField0 & SRX_SMSG_BIT3_CHNUM_MASK) >> SRX_SMSG_BIT3_CHNUM_SHIFT);

    /* CRC */
    msg->crc = (uint8)((uint32)(rawMsg->dataField1 & SRX_SMSG_BIT2_SMCRC_MASK) >> SRX_SMSG_BIT2_SMCRC_SHIFT);

    /* Timestamp */
    msg->timeStamp = rawMsg->dataField2;

    /* Lower 12 bits of data */
    msg->data = (uint16)(rawMsg->dataField1 & SRX_SMSG_BIT2_DATA_MASK);

    /* This is more complicated due to message type */
    if((rawMsg->dataField0 & (uint32)SRX_SMSG_BIT3_TYPE_MASK) != 0u)
    {
        /* Enhanced */
        if((rawMsg->dataField0 & (uint32)SRX_SMSG_BIT3_CFG_MASK) != 0u)
        {
            /* 4 bit ID, C = 1 */
            locType = SRX_SLOW_TYPE_ENHANCED_4_BIT;
            msg->data |= (uint16)((uint32)((uint32)(rawMsg->dataField0 & SRX_SMSG_BIT3_ID3_0_DATA15_12_MASK)
                            >> SRX_SMSG_BIT3_ID3_0_DATA15_12_SHIFT) << 12u);
            msg->id = (uint8)((uint32)(rawMsg->dataField0 & SRX_SMSG_BIT3_ID7_4_ID3_0_MASK)
                            >> SRX_SMSG_BIT3_ID7_4_ID3_0_SHIFT);
        }
        else
        {
            /* 8 bit ID, C = 0 */
            locType = SRX_SLOW_TYPE_ENHANCED_8_BIT;
            msg->id = (uint8)((uint32)(rawMsg->dataField0 & SRX_SMSG_BIT3_ID3_0_DATA15_12_MASK)
                            >> SRX_SMSG_BIT3_ID3_0_DATA15_12_SHIFT);
            msg->id |= (uint8)((uint32)((uint32)(rawMsg->dataField0 & SRX_SMSG_BIT3_ID7_4_ID3_0_MASK)
                            >> SRX_SMSG_BIT3_ID7_4_ID3_0_SHIFT) << 4u);
        }
    }
    else
    {
        /* Standard */
        locType = SRX_SLOW_TYPE_SHORT;
        msg->id = (uint8)((uint32)(rawMsg->dataField0 & SRX_SMSG_BIT3_ID7_4_ID3_0_MASK)
                            >> SRX_SMSG_BIT3_ID7_4_ID3_0_SHIFT);
    }

    /* Message type */
    msg->type = locType;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_ResetPeripheral
 * Description   : Disables the peripheral and brings it's
 * register into a default state
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_ResetPeripheral(CONST(uint8, AUTOMATIC) instance)
{
    uint8 chInd;
    if(instance < (uint8)SRX_INSTANCE_COUNT)
    {
        /* Peripheral wide */
        s_srxBase[instance]->GBL_CTRL.R = SRX_GBL_CTRL_RESET_VALUE;
        s_srxBase[instance]->CHNL_EN.R = SRX_CHNL_EN_RESET_VALUE;
        s_srxBase[instance]->DATA_CTRL1.R = SRX_DATA_CTRL1_RESET_VALUE;
        s_srxBase[instance]->FDMA_CTRL.R = SRX_FDMA_CTRL_RESET_VALUE;
        s_srxBase[instance]->SDMA_CTRL.R = SRX_SDMA_CTRL_RESET_VALUE;
        s_srxBase[instance]->FRDY_IE.R = SRX_FRDY_IE_RESET_VALUE;
        s_srxBase[instance]->SRDY_IE.R = SRX_SRDY_IE_RESET_VALUE;

        /* For each channel */
        for(chInd = 0u; chInd < (uint8)SRX_CHANNEL_COUNT; chInd++)
        {
            s_srxBase[instance]->CH[chInd].CLK_CTRL.R = SRX_CHn_CLK_CTRL_RESET_VALUE;
            s_srxBase[instance]->CH[chInd].CONFIG.R = SRX_CHn_CONFIG_RESET_VALUE;
        }
    }
}

/*******************************************************************************
 * API implementation
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_InitDiag
 * Description   : Initializes the diagnostics side of the driver.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_InitDiag(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2CONST(srx_diag_config_t, AUTOMATIC, SENT_APPL_DATA) config)
{
    /* Set bus IDLE count */
    SRX_LLD_SetBusIdleCnt(instance, channel, config->idleCount);

    /* Set calibration range */
    SRX_LLD_SetCalRng(instance, channel, config->calibVar);

    /* Set pause pulse diag check */
    SRX_LLD_SetPpChkSel(instance, channel, config->diagPulse);

    /* Set pause pulse enable status */
    SRX_LLD_SetPausePulseEnable(instance, channel, config->pausePulse);

    /* Successive calibration check */
    SRX_LLD_SetSuccCalChk(instance, channel, config->succesiveCal);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_InitSlowMes
 * Description   : Initializes the Slow message reception side of the driver.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_InitSlowMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2CONST(srx_slow_msg_config_t, AUTOMATIC, SENT_APPL_DATA) config)
{
    /* CRC related */
    SRX_LLD_SetSlowCrcType(instance, channel, config->crcType);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_InitFastMes
 * Description   : Initializes the Fast message reception side of the driver.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_InitFastMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8 , AUTOMATIC) channel, P2CONST(srx_fast_msg_config_t, AUTOMATIC, SENT_APPL_DATA) config)
{
    /* Number of nibbles */
    SRX_LLD_SetFastNumNibbles(instance, channel, config->numberOfNibbles);

    /* CRC related */
    SRX_LLD_SetFastCrcType(instance, channel, config->crcType);
    SRX_LLD_SetFastCrcIncStatus(instance, channel, (srx_fcrc_sc_cfg_t)config->crcIncludeStatus);
    SRX_LLD_SetFastDisableCrc(instance, channel, (srx_fcrc_check_cfg_t)config->disableCrcCheck);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_CompTimestampPrescaler
 * Description   : Computes the message timestamp base prescaler.
 *
 *END**************************************************************************/
FUNC(uint8, SENT_CODE) SRX_LLD_CompTimestampPrescaler(CONST(uint32, AUTOMATIC) u32clock)
{
    uint32 tsPre;

    /* 0 in worst case */
    tsPre = (uint32)(u32clock / SRX_ONE_MICROSECOND_CYCLES) - 1u;
    /* Saturate at upper interval */
    tsPre = (tsPre > 255u) ? 255u : tsPre;

    return (uint8)tsPre;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_ComputeChannelPrescaler
 * Description   : Computes the channel reception u32clock prescaler.
 *
 *END**************************************************************************/
FUNC(uint32, SENT_CODE) SRX_LLD_ComputeChannelPrescaler(CONST(uint8, AUTOMATIC) reqTick, CONST(uint32, AUTOMATIC) u32clock)
{
    uint32 chPre;

    /* Compute and set the channel prescaler */
    chPre = u32clock / 1000u; /* Keep info on fractional frequencies */

    chPre = (reqTick * chPre) / 1000u;

    return chPre;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetEvents
 * Description   : Returns a list containing masks for the current active events.
 * Also clears the active events in the process.
 *
 * Implements    : SRX_LLD_GetEvents_Activity
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_GetEvents(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, P2VAR(uint32, AUTOMATIC, SENT_APPL_DATA) events)
{
    uint32 locEv;

    /* Invalid instance or channel */
    SENT_DET_ERR(instance < SRX_INSTANCE_COUNT);
    SENT_DET_ERR(channel < SRX_CHANNEL_COUNT);

    /* Get, clear and return */
    locEv = SRX_LLD_GetActiveEvents(instance, (uint8)channel);
    SRX_LLD_ClearActiveEvents(instance, (uint8)channel, locEv);
    *events = locEv;

}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetFastMsg
 * Description   : Returns last received fast message and clears the
 * Rx complete flag.
 *
 * Implements    : SRX_LLD_GetFastMsg_Activity
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_GetFastMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, P2VAR(srx_fast_msg_t, AUTOMATIC, SENT_APPL_DATA) message)
{
    srx_raw_msg_t locMsg = 
    {
        .dataField0 = 0U,
        .dataField1 = 0U,
        .dataField2 = 0U
    };

    /* Invalid instance or channel */
    SENT_DET_ERR(instance < SRX_INSTANCE_COUNT);
    SENT_DET_ERR(channel < SRX_CHANNEL_COUNT);

    SRX_LLD_GetFastRawMsg(instance, (uint8)channel, &locMsg);
    SRX_LLD_ConvertFastRaw(message, &locMsg);

}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetSlowMsg
 * Description   : Returns last received slow message and clears the
 * Rx complete flag.
 *
 * Implements    : SRX_DRV_GetSlowMsg_Activity
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_GetSlowMsg(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel, P2VAR(srx_slow_msg_t, AUTOMATIC, SENT_APPL_DATA) message)
{
    srx_raw_msg_t locMsg = 
    {
        .dataField0 = 0U,
        .dataField1 = 0U,
        .dataField2 = 0U
    };

    /* Invalid instance or channel */
    SENT_DET_ERR(instance < SRX_INSTANCE_COUNT);
    SENT_DET_ERR(channel < SRX_CHANNEL_COUNT);

    SRX_LLD_GetSlowRawMsg(instance, channel, &locMsg);
    SRX_LLD_ConvertSlowRaw(message, &locMsg);
    
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetFastMsgFromRaw
 * Description   : Transforms a RAW fast message into a normal fast message.
 *
 * Implements    : SRX_LLD_GetFastMsgFromRaw_Activity
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_GetFastMsgFromRaw(P2VAR(srx_fast_msg_t, AUTOMATIC, SENT_APPL_DATA) msg, P2CONST(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg)
{
    /* Just call the conversion function */
    SRX_LLD_ConvertFastRaw(msg, rawMsg);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetSlowMsgFromRaw
 * Description   : Transforms a RAW slow message into a normal slow message.
 *
 * Implements    : SRX_LLD_GetSlowMsgFromRaw_Activity
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_GetSlowMsgFromRaw(P2VAR(srx_slow_msg_t, AUTOMATIC, SENT_APPL_DATA) msg, P2CONST(srx_raw_msg_t, AUTOMATIC, SENT_APPL_DATA) rawMsg)
{
    /* Just call the conversion function */
    SRX_LLD_ConvertSlowRaw(msg, rawMsg);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetSlowRxStatus
 * Description   : Returns the buffer status for any incoming SLOW message.
 *
 * Implements    : SRX_LLD_GetSlowRxStatus_Activity
 *END**************************************************************************/
FUNC(boolean, SENT_CODE) SRX_LLD_GetSlowRxStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    boolean retVal;

    /* Invalid instance or channel */
    SENT_DET_ERR(instance < SRX_INSTANCE_COUNT);
    SENT_DET_ERR(channel < SRX_CHANNEL_COUNT);

    retVal = SRX_HW_GetSlowRxStatus(instance, (uint8)channel);

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_GetFastRxStatus
 * Description   : Returns the buffer status for any incoming FAST message.
 *
 * Implements    : SRX_LLD_GetFastRxStatus_Activity
 *END**************************************************************************/
FUNC(boolean, SENT_CODE) SRX_LLD_GetFastRxStatus(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    boolean retVal;

    /* Invalid instance or channel */
    SENT_DET_ERR(instance < SRX_INSTANCE_COUNT);
    SENT_DET_ERR(channel < SRX_CHANNEL_COUNT);

    retVal = SRX_HW_GetFastRxStatus(instance, (uint8)channel);

    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_DeInit
 * Description   : De-Initializes the peripheral and brings it's registers into a reset state.
 *
 * Implements    : SRX_LLD_DeInit_Activity
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_Deinit(CONST(uint8, AUTOMATIC) instance)
{
    /* Invalid instance or channel */
    SENT_DET_ERR(instance < SRX_INSTANCE_COUNT);

    /* Reset peripheral*/
    SRX_LLD_ResetPeripheral(instance);

}


/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_IRQ_FastHandler
 * Description   : Gets called from the low level handler
 * with instance and channel as parameter.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_IRQ_FastHandler(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    DEV_ASSERT(instance < SRX_INSTANCE_COUNT);
    DEV_ASSERT(channel < SRX_CHANNEL_COUNT);

    uint8 ChannelId = Sent_GetInstance(instance, channel);

    Sent_ProcessCommonIrq(ChannelId, SRX_CALLBACK_FAST_RX_COMPLETE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_IRQ_SlowHandler
 * Description   : Gets called from the low level handler
 * with instance and channel as parameter.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_IRQ_SlowHandler(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    DEV_ASSERT(instance < SRX_INSTANCE_COUNT);
    DEV_ASSERT(channel < SRX_CHANNEL_COUNT);

    uint8 ChannelId = Sent_GetInstance(instance, channel);

    Sent_ProcessCommonIrq(ChannelId, SRX_CALLBACK_SLOW_RX_COMPLETE);

}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_IRQ_RxErrHandler
 * Description   : Gets called from the low level handler
 * with instance and channel as parameter.
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX_LLD_IRQ_RxErrHandler(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    DEV_ASSERT(instance < SRX_INSTANCE_COUNT);
    DEV_ASSERT(channel < SRX_CHANNEL_COUNT);
    
    uint8 ChannelId = Sent_GetInstance(instance, channel);

    Sent_ProcessCommonIrq(ChannelId, SRX_CALLBACK_RX_ERROR);
}

/*! @endcond */


/*******************************************************************************
* EOF
*******************************************************************************/


