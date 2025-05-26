#include "Sent_Irq.h"
#include "Sent_LLDriver.h"

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


/*FUNCTION**********************************************************************
 *
 * Function Name : SRX_LLD_IRQ_Dispatch
 * Description   : Interrupt dispatcher
 *
 *END**************************************************************************/
LOCAL_INLINE FUNC(void, SENT_CODE) SRX_LLD_IRQ_Dispatch(CONST(uint8, AUTOMATIC) instance, CONST(uint8, AUTOMATIC) channel)
{
    /* Dispatch according to event type */
    if (SRX_LLD_GetFastRxStatus(instance, channel) == TRUE)
    {
        SRX_LLD_IRQ_FastHandler(instance, channel);
    }
    else if(SRX_LLD_GetSlowRxStatus(instance, channel) == TRUE)
    {
        SRX_LLD_IRQ_SlowHandler(instance, channel);
    }
    else
    {
        /* Fall through, error */
        SRX_LLD_IRQ_RxErrHandler(instance, channel);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX0_CH0_IRQHandler
 * Description   : Handler for SRX0_CH0_IRQn interrupt
 *
 *END**************************************************************************/
#ifdef FEATURE_SRX_HAS_COMBINED_IRQ
FUNC(void, SENT_CODE) SRX0_COMBINED_IRQHandler(void)
{
    uint8 i;
    for(i = 0u; i < 13u; i++)
    {
        SRX_LLD_IRQ_Dispatch(0u, i);
    }
}
#endif

FUNC(void, SENT_CODE) SRX0_CH0_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 0u);
}

#if (SRX_CHANNEL_COUNT > 1u)
/*FUNCTION**********************************************************************
 *
 * Function Name : SRX0_CH1_IRQHandler
 * Description   : Handler for SRX0_CH1_IRQn interrupt
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX0_CH1_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 1u);
}

FUNC(void, SENT_CODE) SRX0_CH2_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 2u);
}

FUNC(void, SENT_CODE) SRX0_CH3_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 3u);
}

FUNC(void, SENT_CODE) SRX0_CH4_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 4u);
}

FUNC(void, SENT_CODE) SRX0_CH5_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 5u);
}

FUNC(void, SENT_CODE) SRX0_CH6_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 6u);
}

FUNC(void, SENT_CODE) SRX0_CH7_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(0u, 7u);
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : SRX1_CH0_IRQHandler
 * Description   : Handler for SRX1_CH0_IRQn interrupt
 *
 *END**************************************************************************/
FUNC(void, SENT_CODE) SRX1_CH0_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 0u);
}

#if (SRX_CHANNEL_COUNT > 1u)
/*FUNCTION**********************************************************************
 *
 * Function Name : SRX1_CH1_IRQHandler
 * Description   : Handler for SRX1_CH1_IRQn interrupt
 *
 *END**************************************************************************/
#ifdef FEATURE_SRX_HAS_COMBINED_IRQ
FUNC(void, SENT_CODE) SRX1_COMBINED_IRQHandler(void)
{
    uint8 i;
    for(i = 0u; i < 12u; i++)
    {
        SRX_LLD_IRQ_Dispatch(1u, i);
    }
}
#endif

FUNC(void, SENT_CODE) SRX1_CH1_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 1u);
}

FUNC(void, SENT_CODE) SRX1_CH2_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 2u);
}

FUNC(void, SENT_CODE) SRX1_CH3_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 3u);
}

FUNC(void, SENT_CODE) SRX1_CH4_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 4u);
}

FUNC(void, SENT_CODE) SRX1_CH5_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 5u);
}

FUNC(void, SENT_CODE) SRX1_CH6_IRQHandler(void)
{
    SRX_LLD_IRQ_Dispatch(1u, 6u);
}
#endif 

/*******************************************************************************
* EOF
*******************************************************************************/
