
#ifdef __cplusplus
extern "C"{
#endif

#include "Icu.h"
#include "Icu_Irq.h"
#include "Icu_Wkpu_LLDrivers.h"
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

CONSTP2VAR(WKPU_Type, ICU_CONST, ICU_APPL_CONST)Wkpu_Base[] = {((WKPU_Type *)0xFFF98000UL)};
#if defined(CCFC3012PT)
static VAR(uint16, ICU_VAR)Wkpu_ChMap[1U][64U] = {{0U}};
#endif

/*====================================================================================================
                                        FILE VERSION CHECKS
====================================================================================================*/
#define ICU_WKPU_LLDRIVERS_VENDOR_ID_C                   176

#define ICU_WKPU_LLDRIVERS_MAJOR_VER_C                   4
#define ICU_WKPU_LLDRIVERS_MINOR_VER_C                   4
#define ICU_WKPU_LLDRIVERS_REVISION_VER_C                0

#define ICU_WKPU_LLDRIVERS_SW_MAJOR_VER_C                1
#define ICU_WKPU_LLDRIVERS_SW_MINOR_VER_C                0
#define ICU_WKPU_LLDRIVERS_SW_PATCH_VER_C                1

#if (ICU_WKPU_LLDRIVERS_VENDOR_ID_C != ICU_WKPU_LLDRIVERS_VENDOR_ID_H)
#error "NON-MATCHED DATA : ICU_VENDOR_ID_CFG"
#endif

/* Check if current file and ICU header file are of the same Autosar version */
#if (ICU_WKPU_LLDRIVERS_MAJOR_VER_C != ICU_WKPU_LLDRIVERS_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_MAJOR_VER_H"
#endif
#if (ICU_WKPU_LLDRIVERS_MINOR_VER_C != ICU_WKPU_LLDRIVERS_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_MINOR_VER_H"
#endif
#if (ICU_WKPU_LLDRIVERS_REVISION_VER_C != ICU_WKPU_LLDRIVERS_REVISION_VER_H)
#error "NON-MATCHED DATA : ICU_REVISION_VER_H"
#endif

/* Check if current file and ICU header file are of the same Software version */
#if (ICU_WKPU_LLDRIVERS_SW_MAJOR_VER_C != ICU_WKPU_LLDRIVERS_SW_MAJOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MAJOR_VER_H"
#endif
#if (ICU_WKPU_LLDRIVERS_SW_MINOR_VER_C != ICU_WKPU_LLDRIVERS_SW_MINOR_VER_H)
#error "NON-MATCHED DATA : ICU_SW_MINOR_VER_H"
#endif
#if (ICU_WKPU_LLDRIVERS_SW_PATCH_VER_C != ICU_WKPU_LLDRIVERS_SW_PATCH_VER_H)
#error "NON-MATCHED DATA : ICU_SW_PATCH_VER_H"
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#if defined(CCFC3012PT)
static FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EdgeRisingSet
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)((uint32)1U << hwChannel);
        base->WIREER0.R |= Val;
        base->WIFEER0.R &= ~Val;
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)((uint32)1U << (hwChannel - 32U));
        base->WIREER1.R |= Val;
        base->WIFEER1.R &= ~Val;
    }
    else
    {
        // Do nothing
    }
}

static FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EdgeFallingSet
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)((uint32)1U << hwChannel);
        base->WIREER0.R &= ~Val;
        base->WIFEER0.R |= Val;
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)((uint32)1U << (hwChannel - 32U));
        base->WIREER1.R &= ~Val;
        base->WIFEER1.R |= Val;
    }
    else
    {
        // Do nothing
    }
}

static FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EdgeBothSet
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)((uint32)1U << hwChannel);
        base->WIREER0.R |= Val;
        base->WIFEER0.R |= Val;
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)((uint32)1U << (hwChannel - 32U));
        base->WIREER1.R |= Val;
        base->WIFEER1.R |= Val;
    }
    else
    {
        // Do nothing
    }
}


static FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EdgeNoneSet
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)((uint32)1U << hwChannel);
        base->WIREER0.R &= ~Val;
        base->WIFEER0.R &= ~Val;
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)((uint32)1U << (hwChannel - 32U));
        base->WIREER1.R &= ~Val;
        base->WIFEER1.R &= ~Val;
    }
    else
    {
        // Do nothing
    }
}

FUNC(void, ICU_CODE)Icu_Wkpu_LLD_Init
(
    P2CONST(ICU_Wkpu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)Wkpu_ConfigPtr
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[Wkpu_ConfigPtr->IcuConfig_ModuleId];
    VAR(uint32, ICU_VAR) Val = 0U;

    Wkpu_ChMap[Wkpu_ConfigPtr->IcuConfig_ModuleId][Wkpu_ConfigPtr->IcuConfig_ChannelId] = Wkpu_ConfigPtr->IcuConfig_Instance;

    if(Wkpu_ConfigPtr->IcuConfig_ChannelId < 32U)
    {
        Val = (uint32)((uint32)1U << Wkpu_ConfigPtr->IcuConfig_ChannelId);
        if(Wkpu_ConfigPtr->IcuChannel_Filter == TRUE)
        {
            base->WIFER0.R |= Val;
        }
        else
        {
            base->WIFER0.R &= ~Val;
        }
    }
    else if(Wkpu_ConfigPtr->IcuConfig_ChannelId < 64U)
    {
        Val = (uint32)((uint32)1U << (Wkpu_ConfigPtr->IcuConfig_ChannelId - 32U));
        if(Wkpu_ConfigPtr->IcuChannel_Filter == TRUE)
        {
            base->WIFER1.R |= Val;
        }
        else
        {
            base->WIFER1.R &= ~Val;
        }
    }
    else
    {
        // Do Nothing
    }
    switch(Wkpu_ConfigPtr->IcuChannel_DefaultStartEdge)
    {
        case ICU_RISING_EDGE:
        {
            Icu_Wkpu_LLD_EdgeRisingSet(Wkpu_ConfigPtr->IcuConfig_ModuleId,(uint8)Wkpu_ConfigPtr->IcuConfig_ChannelId);
        }break;
        case ICU_FALLING_EDGE:
        {
            Icu_Wkpu_LLD_EdgeFallingSet(Wkpu_ConfigPtr->IcuConfig_ModuleId,(uint8)Wkpu_ConfigPtr->IcuConfig_ChannelId);
        }break;
        case ICU_BOTH_EDGES:
        {
            Icu_Wkpu_LLD_EdgeBothSet(Wkpu_ConfigPtr->IcuConfig_ModuleId,(uint8)Wkpu_ConfigPtr->IcuConfig_ChannelId);
        }break;
        default:
        {
            Icu_Wkpu_LLD_EdgeNoneSet(Wkpu_ConfigPtr->IcuConfig_ModuleId,(uint8)Wkpu_ConfigPtr->IcuConfig_ChannelId);
        }break;
    }
}


FUNC(void, ICU_CODE)Icu_Wkpu_LLD_DeInit
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;

    Wkpu_ChMap[instance][hwChannel] = 0U;

    if(hwChannel < 32U)
    {
        Val = (uint32)((uint32)1U << hwChannel);
        base->WIFER0.R &= ~Val;
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)((uint32)1U << (hwChannel - 32U));
        base->WIFER1.R &= ~Val;
    }
    else
    {
        // Do Nothing
    }
    Icu_Wkpu_LLD_EdgeNoneSet(instance, hwChannel);
}
#endif

FUNC(void, ICU_CODE)Icu_WkpuNMI_LLD_Init(
    P2CONST(ICU_Wkpu_NMIConfigType, AUTOMATIC, ICU_APPL_CONST) pWkpuNMIConfig
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
    P2CONST(Wkpu_NmiCfgType, ICU_VAR, ICU_APPL_CONST) ConfigNMI = &pWkpuNMIConfig->WkpuNMIConfig[0];
    VAR(uint8, ICU_VAR)coreNumber = 0U;
    VAR(uint32, ICU_VAR)coreShift = 0U;

#if (defined(CCFC3007BC)||defined(CCFC3007PT))

    #if (NMI_WAKEUP_PIN == WKP_PS0) 

    if ((WKPU.NCR.R & 0x00000008U) != 0x00000000U)
    { 
        WKPU.NCR.R &= ~0x00000008U;
    } 

    #elif (NMI_WAKEUP_PIN == WKP_PA4)

    if ((WKPU.NCR.R & 0x00000008U) != 0x00000008U)
    { 
        WKPU.NCR.R |= 0x00000008U;
    } 

    #endif

#endif

#if defined(CCFC3008PT)

    #if (NMI_WAKEUP_PIN == WKP_PS0) 

    if ((SIUL2.SCR0.R & 0x40000000U) != 0x00000000U)
    { 
        SIUL2.SCR0.R &= ~0x40000000U;
    } 

    #elif (NMI_WAKEUP_PIN == WKP_PA4)

    if ((SIUL2.SCR0.R & 0x40000000U) != 0x40000000U)
    { 
        SIUL2.SCR0.R |= 0x40000000U;
    } 

    #endif

#endif

    for (uint8 i = 0U; i<pWkpuNMIConfig->NMICount; i++)
    {
        coreNumber = (uint8)ConfigNMI[i].core;
        if(coreNumber < 3U)
        {
            coreShift = (coreNumber * WKPU_NMI_CORE_BIT_OFFSET);
            /* Configure destination source */
            base->NCR.R &= ~(WKPU_NCR_NDSS0_MASK >> coreShift);
            base->NCR.R |= WKPU_NCR_NDSS0((uint8)ConfigNMI[i].destination) >> coreShift;

            /* Configure wake-up request */
            base->NCR.R &= ~(WKPU_NCR_NWRE0_MASK >> coreShift);
            base->NCR.R |= WKPU_NCR_NWRE0(ConfigNMI[i].wkpReqEn ? 1UL : 0UL) >> coreShift;

            /* Only set filter for Core 0 */
            if ( 0UL == coreNumber)
            {
                /* Configure glitch filter */
                base->NCR.R &= ~(WKPU_NCR_NFE0_MASK >> coreShift);
                base->NCR.R |= WKPU_NCR_NFE0(ConfigNMI[i].filterEn ? 1UL : 0UL) >> coreShift;
            }

            /* Configure edge events */
            if (WKPU_RISING_EDGE == ConfigNMI[i].edgeEvent)
            {
                base->NCR.R |= WKPU_NCR_NREE0_MASK >> coreShift;
                base->NCR.R &= ~(WKPU_NCR_NFEE0_MASK >> coreShift);
            }
            else if (WKPU_FALLING_EDGE == ConfigNMI[i].edgeEvent)
            {
                base->NCR.R &= ~(WKPU_NCR_NREE0_MASK >> coreShift);
                base->NCR.R |= WKPU_NCR_NFEE0_MASK >> coreShift;
            }
            else
            {
                base->NCR.R |= WKPU_NCR_NFEE0_MASK >> coreShift;
                base->NCR.R |= WKPU_NCR_NREE0_MASK >> coreShift;
            }
            /* Configure lock */
            base->NCR.R |= WKPU_NCR_NLOCK0(ConfigNMI[i].lockEn ? 1UL : 0UL) >> coreShift;
        }
        else if (coreNumber < 6u)
        {
            coreShift = ((coreNumber % 3U) * WKPU_NMI_CORE_BIT_OFFSET);
            /* Configure destination source */
            base->NCR1.R &= ~(WKPU_NCR1_NDSS3_MASK >> coreShift);
            base->NCR1.R |= WKPU_NCR1_NDSS3((uint8)ConfigNMI[i].destination) >> coreShift;

            /* Configure wake-up request */
            base->NCR1.R &= ~(WKPU_NCR1_NWRE3_MASK >> coreShift);
            base->NCR1.R |= WKPU_NCR1_NWRE3(ConfigNMI[i].wkpReqEn ? 1UL : 0UL) >> coreShift;

            /* Configure edge events */
            if (WKPU_RISING_EDGE == ConfigNMI[i].edgeEvent)
            {
                base->NCR1.R |= WKPU_NCR1_NREE3_MASK >> coreShift;
                base->NCR1.R &= ~(WKPU_NCR1_NFEE3_MASK >> coreShift); 
            }
            else if (WKPU_FALLING_EDGE == ConfigNMI[i].edgeEvent)
            {
                base->NCR1.R &= ~(WKPU_NCR1_NREE3_MASK >> coreShift);
                base->NCR1.R |= WKPU_NCR1_NFEE3_MASK >> coreShift;
            }
            else
            {
                base->NCR1.R |= WKPU_NCR1_NFEE3_MASK >> coreShift;
                base->NCR1.R |= WKPU_NCR1_NREE3_MASK >> coreShift;
            }
            /* Configure lock */
            base->NCR1.R |= WKPU_NCR1_NLOCK3(ConfigNMI[i].lockEn ? 1UL : 0UL) >> coreShift;
        }
        else
        {
            /* nothing */
        }
    }
}


FUNC(void, ICU_CODE)Icu_WkpuNMI_LLD_DeInit( void )
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[0U];
	VAR(uint32, ICU_VAR)coreShift = 0U;

    for (uint32 CoreIdx = 0U; CoreIdx < WKPU_NMI_CORE_MAX; CoreIdx++)
	{
		
        if(CoreIdx < 3)
        {
            coreShift = (uint32)CoreIdx * WKPU_NMI_CORE_BIT_OFFSET;
            if((base->NCR.R & WKPU_NCR_NLOCK0(coreShift) )!= 0U)
            {
                // Do nothing
            }
            else
            {
                /* Clear status flag and overrun status flag */
                base->NSR.R = ((WKPU_NSR_NIF0_MASK | WKPU_NSR_NOVF0_MASK) >> coreShift);
                /* Clear edge events */
                base->NCR.R &= ~(WKPU_NCR_NREE0_MASK >> coreShift);
                base->NCR.R &= ~(WKPU_NCR_NFEE0_MASK >> coreShift);

                /* Only set filter for Core 0 */
                if ((uint32)WKPU_CORE0 == (uint32) CoreIdx)
                {
                    /* Disable glitch filter */
                    base->NCR.R &= ~(WKPU_NCR_NFE0_MASK >> coreShift);
                }
                /* Disable wake-up request */
                base->NCR.R &= ~(WKPU_NCR_NWRE0_MASK >> coreShift);
                /* Configure destination source */
                base->NCR.R &= ~(WKPU_NCR_NDSS0_MASK >> coreShift);
                base->NCR.R |= WKPU_NCR_NDSS0((uint8)WKPU_NMI_NONE) >> coreShift;
            }

        }
        else if(CoreIdx < 6)
        {
            coreShift = ((uint32)CoreIdx % 3U) * WKPU_NMI_CORE_BIT_OFFSET;
            if((base->NCR1.R & WKPU_NCR1_NLOCK3(coreShift) )!= 0U)
            {
                // Do nothing
            }
            else
            {
                /* Clear status flag and overrun status flag */
                base->NSR1.R = ((WKPU_NSR1_NIF3_MASK | WKPU_NSR1_NOVF3_MASK) >> coreShift);
                /* Clear edge events */
                base->NCR1.R &= ~(WKPU_NCR1_NREE3_MASK >> coreShift);
                base->NCR1.R &= ~(WKPU_NCR1_NFEE3_MASK >> coreShift);

                /* Disable wake-up request */
                base->NCR1.R &= ~(WKPU_NCR1_NWRE3_MASK >> coreShift);
                /* Configure destination source */
                base->NCR1.R &= ~(WKPU_NCR1_NDSS3_MASK >> coreShift);
                base->NCR1.R |= WKPU_NCR1_NDSS3((uint8)WKPU_NMI_NONE) >> coreShift;
            }
        }
        else
        {
            // Do nothing
        }
	}
}

#if defined(CCFC3012PT)
FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EnableInterrupt
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint8, AUTOMATIC) hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;
    if(hwChannel < 32U)
    {
        Val = (uint32)((uint32)1U << hwChannel);
        base->WISR0.R = Val;
        base->IRER0.R |= Val;
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)((uint32)1U << (hwChannel - 32U));
        base->WISR1.R = Val;
        base->IRER1.R |= Val;
    }
    else
    {
        // Do nothing
    }
}

FUNC(void, ICU_CODE)Icu_Wkpu_LLD_DisableInterrupt
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint8, AUTOMATIC) hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;
    if(hwChannel < 32U)
    {
        Val = (uint32)((uint32)1U << hwChannel);
        base->WISR0.R = Val;
        base->IRER0.R &= ~Val;
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)((uint32)1U << (hwChannel - 32U));
        base->WISR1.R = Val;
        base->IRER1.R &= ~Val;
    }
    else
    {
        // Do nothing
    }
}

FUNC(void, ICU_CODE)Icu_Wkpu_LLD_EnableWakeup
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint8, AUTOMATIC) hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;
    if(hwChannel < 32U)
    {
        Val = (uint32)((uint32)1U << hwChannel);
        base->WISR0.R = Val;
        base->WRER0.R |= Val;
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)((uint32)1U << (hwChannel - 32U));
        base->WISR1.R = Val;
        base->WRER1.R |= Val;
    }
    else
    {
        // Do nothing
    }
}


FUNC(void, ICU_CODE)Icu_Wkpu_LLD_DisableWakeup
(
    VAR(uint8, AUTOMATIC) instance,
    VAR(uint8, AUTOMATIC) hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;
    if(hwChannel < 32U)
    {
        Val = (uint32)((uint32)1U << hwChannel);
        base->WISR0.R = Val;
        base->WRER0.R &= ~Val;
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)((uint32)1U << (hwChannel - 32U));
        base->WISR1.R = Val;
        base->WRER1.R &= ~Val;
    }
    else
    {
        // Do nothing
    }
}

FUNC(void, ICU_CODE)Icu_Wkpu_LLD_SetActivationCondition
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel,
    VAR(Icu_Wkpu_EdgeType, ICU_VAR)edge
)
{

    switch(edge)
    {
        case WKPU_NONE_EDGE:
        {
            Icu_Wkpu_LLD_EdgeNoneSet(instance,hwChannel);
        }break;
        case WKPU_RISING_EDGE:
        {
            Icu_Wkpu_LLD_EdgeRisingSet(instance,hwChannel);
        }break;
        case WKPU_FALLING_EDGE:
        {
            Icu_Wkpu_LLD_EdgeFallingSet(instance,hwChannel);
        }break;
        case WKPU_BOTH_EDGES:
        {
            Icu_Wkpu_LLD_EdgeBothSet(instance,hwChannel);
        }break;
        default :
        {
        	/*do nothing*/
        }break;
    }
}


FUNC(boolean, ICU_CODE)Icu_Wkpu_LLD_GetInputState
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    CONSTP2VAR(WKPU_Type, ICU_VAR, ICU_APPL_CONST) base = Wkpu_Base[instance];
    VAR(uint32, ICU_VAR) Val = 0U;
    VAR(boolean, ICU_VAR) status = false;

    if(hwChannel < 32U)
    {
        Val = (uint32)((uint32)1U << hwChannel);
        if((Val & base->WISR0.R)!=0U)
        {
            status = true;
        }
        else
        {
            status = false;
        }
    }
    else if(hwChannel < 64U)
    {
        Val = (uint32)((uint32)1U << (hwChannel - 32U));
        if((Val & base->WISR1.R)!=0U)
        {
            status = true;
        }
        else
        {
            status = false;
        }
    }
    else
    {
        // Do nothing
    }
    return status;
}



FUNC(void, ICU_CODE)Icu_Wkpu_LLD_IrqCallbcak
(
    VAR(uint8, ICU_VAR)instance,
    VAR(uint8, ICU_VAR)hwChannel
)
{
    ICU_AutoSAR_Wapper_ReportEvents(Wkpu_ChMap[instance][hwChannel], FALSE);
}

#endif
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"



#ifdef __cplusplus
}
#endif

/** @} */

