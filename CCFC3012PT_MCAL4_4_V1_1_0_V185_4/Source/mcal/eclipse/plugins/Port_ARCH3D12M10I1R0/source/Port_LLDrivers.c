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
*   @file    Port_LLDrivers.c
*   @version 
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Port MCAL driver.
*
*   @addtogroup Port
*   @{
*/
#ifdef __cplusplus
extern "C" {
#endif

/* ==============================================INCLUDE FILES======================================= */

#include "Port.h"
#include "Port_Register.h"
#include "Port_LLDriver.h"
#include "derivative.h"
#include "SchM_Port.h"

#define USER_MODE_REG_PROT_ENABLED (PORT_USER_MODE_SOFT_LOCKING)

#define PORT_MULTI_CORE_SUPPORT                      (0)

#define PORT_CORE_Z70_ID_MASK                        (0x01U)
#define PORT_CORE_Z71_ID_MASK                        (0x02U)
#define PORT_CORE_Z42_ID_MASK                        (0x04U)
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define PORT_C_SIUL2_VENDOR_ID                     176

#define PORT_C_SIUL2_AR_REL_MAJOR_VER              4

#define PORT_C_SIUL2_AR_REL_MINOR_VER              4

#define PORT_C_SIUL2_AR_REL_REV_VER                0
#define PORT_C_SIUL2_SW_MAJOR_VERSION              1
#define PORT_C_SIUL2_SW_MINOR_VERSION              0
#define PORT_C_SIUL2_SW_PATCH_VERSION              1

/* ============================================FILE VERSION CHECKS=================================== */


#if (PORT_C_SIUL2_VENDOR_ID != PORT_VENDOR_ID)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_PATCH_VERSION"
#endif

#if (PORT_C_SIUL2_AR_REL_MAJOR_VER != PORT_AR_RELEASE_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MAJOR_VERSION"
#endif

#if (PORT_C_SIUL2_AR_REL_MINOR_VER != PORT_AR_RELEASE_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_MINOR_VERSION"
#endif

#if (PORT_C_SIUL2_AR_REL_REV_VER != PORT_AR_RELEASE_REV_VERSION)
    #error "NON-MATCHED DATA : PORT_AR_RELEASE_REV_VERSION"
#endif

#if (PORT_C_SIUL2_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_MAJOR_VERSION"
#endif

#if (PORT_C_SIUL2_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_MINOR_VERSION"
#endif

#if (PORT_C_SIUL2_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : PORT_SW_PATCH_VERSION"
#endif

#if (PORT_C_SIUL2_VENDOR_ID != PORT_H_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : PORT_SIUL2_VENDOR_ID_H"
#endif

#if (PORT_C_SIUL2_AR_REL_MAJOR_VER != PORT_H_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_AR_REL_MINOR_VER != PORT_H_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : PORT_SIUL2_AR_RELEASE_MINOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_AR_REL_REV_VER != PORT_H_SIUL2_AR_REL_REV_VER)
    #error "NON-MATCHED DATA : PORT_SIUL2_AR_RELEASE_REVISION_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_MAJOR_VERSION != PORT_H_SIUL2_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_MAJOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_MINOR_VERSION != PORT_H_SIUL2_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_MINOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_PATCH_VERSION != PORT_H_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_PATCH_VERSION_H"
#endif

#if (PORT_C_SIUL2_VENDOR_ID != REGESYS_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_VENDOR_ID"
#endif

#if (PORT_C_SIUL2_AR_REL_MAJOR_VER != REGESYS_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MAJOR_VER"
#endif

#if (PORT_C_SIUL2_AR_REL_MINOR_VER != REGESYS_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_MINOR_VER"
#endif

#if (PORT_C_SIUL2_AR_REL_REV_VER != REGESYS_SIUL2_AR_REL_REV_VER)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_AR_REL_REV_VER"
#endif

#if (PORT_C_SIUL2_SW_PATCH_VERSION != REGESYS_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : REGESYS_SIUL2_SW_PATCH_VERSION"
#endif

#if (PORT_C_SIUL2_VENDOR_ID != PORT_H_SIUL2_VENDOR_ID)
    #error "NON-MATCHED DATA : PORT_SIUL2_VENDOR_ID_H"
#endif

#if (PORT_C_SIUL2_AR_REL_MAJOR_VER != PORT_H_SIUL2_AR_REL_MAJOR_VER)
    #error "NON-MATCHED DATA : PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_AR_REL_MINOR_VER != PORT_H_SIUL2_AR_REL_MINOR_VER)
    #error "NON-MATCHED DATA : PORT_SIUL2_AR_RELEASE_MINOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_MAJOR_VERSION != PORT_H_SIUL2_SW_MAJOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_MAJOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_MINOR_VERSION != PORT_H_SIUL2_SW_MINOR_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_MINOR_VERSION_H"
#endif

#if (PORT_C_SIUL2_SW_PATCH_VERSION != PORT_H_SIUL2_SW_PATCH_VERSION)
    #error "NON-MATCHED DATA : PORT_SIUL2_SW_PATCH_VERSION_H"
#endif

/* =========================LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)=============================== */


/* ======================================LOCAL MACROS================================================ */


/* ======================================LOCAL CONSTANTS============================================= */


/* ======================================LOCAL VARIABLES============================================= */


/* ======================================GLOBAL CONSTANTS============================================ */


/* ======================================GLOBAL VARIABLES============================================ */

#define PORT_START_SEC_VAR_NO_INIT

#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)

static VAR(uint16, PORT_VAR) s_u16Port_Siul2_au16GPIODirChangeability[PAD_16BLOCK_NO_U8];
#endif

#define PORT_STOP_SEC_VAR_NO_INIT

#include "Port_MemMap.h"

/* ==================================LOCAL FUNCTION PROTOTYPES======================================= */


/* ======================================LOCAL FUNCTIONS============================================= */
#define PORT_START_SEC_CODE

#include "Port_MemMap.h"

/* ======================================GLOBAL FUNCTIONS============================================ */


/*****************************************************************************
**  Service Name     : Port_LLD_Init
** 
**  Description      : The function Port_LLD_Init will initialize ALL ports and port pins with the
**                     configuration set pointed to by the parameter pConfigPtr.
**                                                                                                                       
**  Parameters (in)  : pConfigPtr: A pointer to the structure which contains initialization parameters
**                                                             
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/

FUNC(void, PORT_CODE) Port_LLD_Init \
( \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{
    
    // Initialize all variables
    VAR(uint16, AUTOMATIC) u16Port_PinIndex = 0;
    VAR(uint16, AUTOMATIC) u16Port_MuxIndex = 0;
    VAR(uint32, AUTOMATIC) u32Port_LocalVar = 0;
    VAR(uint16, AUTOMATIC) u16Port_PcrPin   = 0;
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinPad = 0;

    VAR(uint16, AUTOMATIC) u16Port_NumUnusedPins \
                                = (uint16)(pPort_ConfigPtr->Port_UnusedPin.u16Port_NumUnusedPins);
    VAR(uint16, AUTOMATIC) u16Port_NumPins \
                                = (uint16)(pPort_ConfigPtr->Port_UsedPin.u16Port_NumPins);
    VAR(uint16, AUTOMATIC) u16Port_NumMuxRegs    = PORT_NMBR_INMUX_REGS_U16;
    VAR(uint32, AUTOMATIC) u32Port_LocalMSCR \
                            = pPort_ConfigPtr->Port_UnusedPin.pPort_UnusedPadConfig->u32Port_MSCR;
    VAR(uint8,  AUTOMATIC) u8Port_LocalPDO \
                            = pPort_ConfigPtr->Port_UnusedPin.pPort_UnusedPadConfig->u8Port_PDO;

    // SIUL2.ISEL8.B.ETPU29 = pPort_ConfigPtr->Etpu_IS[0];
    // SIUL2.ISEL8.B.ETPU28 = pPort_ConfigPtr->Etpu_IS[1];
    // SIUL2.ISEL8.B.ETPU27 = pPort_ConfigPtr->Etpu_IS[2];
    // SIUL2.ISEL8.B.ETPU26 = pPort_ConfigPtr->Etpu_IS[3];
    // SIUL2.ISEL8.B.ETPU25 = pPort_ConfigPtr->Etpu_IS[4];
    // SIUL2.ISEL8.B.ETPU24 = pPort_ConfigPtr->Etpu_IS[5];

    // Initialize All UnUsed Port Pins
    u16Port_PinIndex = (uint16)0U;
    SchM_Enter_PORT_EXCLUSIVE_AREA_x(0);
    while( u16Port_PinIndex < u16Port_NumUnusedPins)
    {
        u16Port_PcrPin = pPort_ConfigPtr->Port_UnusedPin.au16Port_UnusedPads[u16Port_PinIndex];
        if((u16Port_PcrPin != PJ2) && (u16Port_PcrPin != PJ3))
        {
			SIUL.GPDO[u16Port_PcrPin].R = u8Port_LocalPDO;
			// Write MSCR configuration from Configuration tool
			SIUL.PCR[u16Port_PcrPin].R = u32Port_LocalMSCR;
        }
        u16Port_PinIndex++;
    }

#if(defined(PORT_MULTI_CORE_SUPPORT) && (PORT_MULTI_CORE_SUPPORT == 1))
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)(1<<GetCoreID());
#endif
    // Initialize All Configured Port Pins
    u16Port_PinIndex = (uint16)0U;
    while(u16Port_PinIndex < u16Port_NumPins)
    {
#if(defined(PORT_MULTI_CORE_SUPPORT) && (PORT_MULTI_CORE_SUPPORT == 1))
        if((u32CoreID & (pPort_ConfigPtr->coreMap[u16Port_PinIndex].u8CoreId)) != 0U)
#endif
        {
            u8Port_LocalPDO \
                = pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u8Port_GPDO;
            u16Port_PinPad = (uint16) \
                (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u16Port_SIUPin);
            if (PORT_PIN_LEVEL_LOW_U8 == u8Port_LocalPDO)
            {
                SIUL.GPDO[u16Port_PinPad].R = (uint8)STD_LOW;
            }
            else if (PORT_PIN_LEVEL_HIGH_U8 == u8Port_LocalPDO)
            {
                SIUL.GPDO[u16Port_PinPad].R = (uint8)STD_HIGH;
            }
            else
            {
                // do nothing
            }
        }
        
        SIUL.PCR[u16Port_PinPad].R = (uint32) \
        (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_PCR);
        SIUL.GPDO[u16Port_PinPad].R = (uint32) \
        (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u8Port_GPDO);
        u16Port_PinIndex++;
    }

    // Write Multiplexed Pad configuration registers from Configuration tool
    u16Port_MuxIndex = (uint16)0U;
    while(u16Port_MuxIndex < u16Port_NumMuxRegs)
    {
#if(defined(PORT_MULTI_CORE_SUPPORT) && (PORT_MULTI_CORE_SUPPORT == 1))
        if((u32CoreID & (pPort_ConfigPtr->coreMap[u16Port_PinIndex].u8CoreId)) != 0U)
#endif  
        {
            // Write MSCR configuration from Configuration tool
            u32Port_LocalVar \
                    = ((uint32)(pPort_ConfigPtr->Port_UsedPin.pPort_PadSelConfig[u16Port_MuxIndex]));

            if (PORT_LLD_INMUX_UNUSE_PATTEN_U32 != u32Port_LocalVar)
            {
                u32Port_LocalVar \
                    = ((uint32)(pPort_ConfigPtr->Port_UsedPin.pPort_PadSelConfig[u16Port_MuxIndex]) \
                                                                    <<SIUL2_IMCR_SSS_OFFSET_U32);
                // Set all reserved bits of the IMCR register to their reset value
                u32Port_LocalVar|= SIUL2_IMCR_RESET_MASK_U32;
                SIUL.PSMI[u16Port_MuxIndex].R = u32Port_LocalVar;
            }
        }
        u16Port_MuxIndex++;
    }
    SchM_Exit_PORT_EXCLUSIVE_AREA_x(0);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
    // u16Port_Siul2_au16GPIODirChangeability is only used by PORT_Siul_SetPinDirection and PORT_Siul_SetPinMode functions
    // Initialize the Array with Change Direction Flags for GPIO
    u16Port_PinIndex = (uint16)0U;
    while(u16Port_PinIndex < PAD_16BLOCK_NO_U8)
    {
        s_u16Port_Siul2_au16GPIODirChangeability[u16Port_PinIndex] = (uint16)0UL;
        u16Port_PinIndex++;
    }
#endif
}


#if (STD_ON == PORT_SET_PIN_MODE_API)

/*****************************************************************************
**  Service Name     : Port_LLD_SetPinDirection
** 
**  Description      : Sets the pin direction at runtime, changing it only if the pin is configurated as
**                     changeable.
**                                                                                                                       
**  Parameters (in)  : PinIndex: Pin ID number
**                     eDirection: Port Pin direction
**                     pConfigPtr: A pointer to the structure which contains initialization parameters
**                                                             
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Error code after execution                                                   
**                                                                            
******************************************************************************/

FUNC (Std_ReturnType, PORT_CODE) Port_LLD_SetPinDirection \
( \
    VAR    (Port_PinType,          AUTOMATIC                 ) u32Port_PinIndex, \
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) ePort_Direction, \
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{
    // Point to the Port Pin MSCR register address
    VAR(uint16, AUTOMATIC) u16Port_PinPad \
    = (uint16)pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u16Port_SIUPin;

    // Return value
    VAR(Std_ReturnType, AUTOMATIC) u8Port_PinDirError = (Std_ReturnType)E_OK;

    // Bit Offset and Table value for change direction flag word
    VAR(uint8,  AUTOMATIC) u8Port_PinDescBitOffset \
                            = (uint8)((uint8)u16Port_PinPad & SIUL2_BIT_OFFSET_MASK_U8);
    VAR(uint16, AUTOMATIC) u16Port_PinChangeDirFlagWord \
                        = s_u16Port_Siul2_au16GPIODirChangeability[(uint8)(u16Port_PinPad>>4)];
    if(u8Port_PinDescBitOffset <= 14U)
    {
        // Check the Direction changeability option
        if (((boolean)TRUE == \
            pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].bPort_DC) \
            || ((uint16)0 != (u16Port_PinChangeDirFlagWord & (uint16)(1UL<<u8Port_PinDescBitOffset))))
        {
            SchM_Enter_PORT_EXCLUSIVE_AREA_x(1);
            // Configures Port Pin as Output
            if (PORT_PIN_OUT == ePort_Direction)
            {
                SIUL.PCR[u16Port_PinPad].R &= (~SIUL_PCR_IBE_ON_U16);
                //Set MSCR.ODC bitfield to the value taken from configuration
                SIUL.PCR[u16Port_PinPad].R |= (SIUL.PCR[u16Port_PinPad].R \
                & (~SIUL_PCR_IBE_ON_U16));
            }
            // Configures Port Pin as Input
            else if (PORT_PIN_IN == ePort_Direction)
            {
               SIUL.PCR[u16Port_PinPad].R &= ~SIUL_PCR_ODE_U16;
               SIUL.PCR[u16Port_PinPad].R |= SIUL_PCR_IBE_ON_U16;
            }
            else
            {
                SIUL.PCR[u16Port_PinPad].R |= SIUL_PCR_IBE_ON_U16;
                //Set MSCR.ODC bitfield to the value taken from configuration
                SIUL.PCR[u16Port_PinPad].R = (SIUL.PCR[u16Port_PinPad].R \
                & (~SIUL_PCR_ODE_U16)) \
                | (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u32Port_PCR \
                & SIUL_PCR_ODE_U16);
            }
            SchM_Exit_PORT_EXCLUSIVE_AREA_x(1);
        }      
    }
    // Direction changeability is NOT supported
    else
    {
        u8Port_PinDirError = (Std_ReturnType)E_NOT_OK;
    }

    return u8Port_PinDirError;
}
#endif


#if (STD_ON == PORT_SET_PIN_MODE_API)

/*****************************************************************************
**  Service Name     : Port_LLD_SetPinMode
** 
**  Description      : The function will set the port pin mode of the referenced pin during runtime
**                                                                                                                       
**  Parameters (in)  : PinCfgRegIndex: Index of Register MSCR
**                     PinCfgRegValue: Value of Register MSCR
**                     u16InMuxRegIndex: Index of Register IMCR
**                     InMuxRegValue: Value of Register IMCR
**                                                             
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/

FUNC (void, PORT_CODE) Port_LLD_SetPinMode \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PinCfgRegIndex, \
    VAR(Port_RegValueType,      AUTOMATIC) u32Port_PinCfgRegValue, \
    VAR(uint16,                 AUTOMATIC) u16Port_InMuxRegIndex, \
    VAR(Port_RegValueType,      AUTOMATIC) u32Port_InMuxRegValue \
)
{
    // Variable used to clear and updated MSCR register
    VAR(uint16, AUTOMATIC) u32Port_LocalVar = (uint16)0U;
    SchM_Enter_PORT_EXCLUSIVE_AREA_x(2);

    // Read the entire value of the MSCR register
    //u32Port_LocalVar = SIUL2.MSCR_IO[u16Port_PinCfgRegIndex].R;
    u32Port_LocalVar = SIUL.PCR[u16Port_PinCfgRegIndex].R;

    if (PORT_LLD_INPUT_ACTIVE_U32 == u32Port_PinCfgRegValue)
    {
        // Clear MSCR.SSS bit field
        u32Port_LocalVar &= ~SIUL_PCR_SSS_U16;
        // Clear MSCR.OBE or MSCR.ODC bit field
        u32Port_LocalVar &= ~SIUL_PCR_ODE_U16;
        // Clear MSCR.APC bit field
#ifndef PORT_NO_ANALOG_MODE
        //u32Port_LocalVar &= ~SIUL2_MSCR_APC_U32;
#endif
        // Set the INPUT mode in MSCR
        u32Port_LocalVar |=  SIUL_PCR_IBE_U16;
    }
    else if (PORT_LLD_OUTPUT_ACTIVE_U32 == u32Port_PinCfgRegValue)
    {
        // Clear MSCR.IBE and MSCR.SSS bit fields
        u32Port_LocalVar &= ~(SIUL_PCR_IBE_U16 | SIUL_PCR_SSS_U16);
#ifndef PORT_NO_ANALOG_MODE
        // Clear MSCR.APC bit field, if platform supports it
        //u32Port_LocalVar &= ~SIUL2_MSCR_APC_U32;
#endif
        // Set the OUTPUT mode in MSCR
        // For platforms having ODC SIUL2 support, the Port_AutoSar_Wrapper_SetPinMode() function will send through
        // InMuxRegValue parameter the value of the MSCR.ODC in configuration structure.
        u32Port_LocalVar |= ((uint32)u32Port_InMuxRegValue);
    }
    else
    {
#ifndef PORT_NO_ANALOG_MODE
        if (PORT_ANALOG_INPUT_MODE == u32Port_PinCfgRegValue)
        {
            // Set the Analog Pad Control (APC) bit in MSCR
            //u32Port_LocalVar = SIUL2_MSCR_APC_U32;
        }
        else
#endif
        {
            // Clear the previous mode (MSCR.SSS)
            u32Port_LocalVar &= ~SIUL_PCR_SSS_U16;
#ifndef PORT_NO_ANALOG_MODE
            // Clear MSCR.APC bit, if platform supports it
            //u32Port_LocalVar &= ~SIUL2_MSCR_APC_U32;
#endif

            // For platforms having ODC support, for modes PORT_ALTx and PORT_INOUTx the MSCR.ODC bits should also be set.
            // InMuxRegValue is a logic OR between MSCR.ODC and IMCR.SSS so apply a mask in order to get only the information
            // related to MSCR.ODC
            u32Port_LocalVar |= (((uint32)u32Port_InMuxRegValue) & SIUL_PCR_ODE_U16);
            // Set the proper mode in MSCR.SSS
            u32Port_LocalVar |= ((uint32)u32Port_PinCfgRegValue<<SIUL2_MSCR_SSS_OFFSET_U32);
        }
    }
    SIUL.PCR[u16Port_PinCfgRegIndex].R = u32Port_LocalVar;

    if (NO_INPUTMUX_U16 != u16Port_InMuxRegIndex)
    {
        // Set the proper values in IMCR. For platforms having ODC support, InMuxRegValue is a logic OR between MSCR.ODC and IMCR.SSS
        // so apply a mask in order to get only the information related to IMCR.SSS
        SIUL.PCR[(u16Port_InMuxRegIndex % 512U)].R = \
                                                    ((u32Port_InMuxRegValue & SIUL_PCR_SSS_U16) \
                                                    | SIUL2_IMCR_RESET_MASK_U32);
        // Set the MSCR/IBE bit
        u32Port_LocalVar = SIUL.PCR[u16Port_PinCfgRegIndex].R;
        u32Port_LocalVar |= ((uint32)SIUL_PCR_IBE_U16);
        SIUL.PCR[u16Port_PinCfgRegIndex].R = u32Port_LocalVar;
    }
    SchM_Exit_PORT_EXCLUSIVE_AREA_x(2);
}
#endif

#if (STD_ON == PORT_SET_PIN_MODE_API)

/*****************************************************************************
**  Service Name     : Port_LLD_SetGpioDirChangeability
** 
**  Description      : The function will update the direction changeabilty for the pads whose mode is changed
**                                                                                                                       
**  Parameters (in)  : PadID: Pin ID number
**                     bStatus: The new value true or falsr for directuion changeability
**                                                             
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/

FUNC (void, PORT_CODE) Port_LLD_SetGpioDirChangeability \
( \
    VAR(Port_InternalPinIdType, AUTOMATIC) u16Port_PadID, \
    VAR(boolean,                AUTOMATIC) bPort_Status \
)
{
    // Pin description variables
    VAR(uint16, AUTOMATIC) u16Port_PinDirFlagWord = 0;
    VAR(uint8, AUTOMATIC) u8Port_PinBitOffset     = 0;

    SchM_Enter_PORT_EXCLUSIVE_AREA_x(3);

    // Bit offset of Pin index inside the pin description matrix
    u8Port_PinBitOffset    = (uint8)((uint8)u16Port_PadID & SIUL2_BIT_OFFSET_MASK_U8);
    u16Port_PinDirFlagWord = \
                    s_u16Port_Siul2_au16GPIODirChangeability[(uint8)((uint8)u16Port_PadID>>4)];
    if(u8Port_PinBitOffset <= 32U)
    {
        if ((boolean)TRUE == bPort_Status)
        {
            // Set the change direction flag
            u16Port_PinDirFlagWord |= (uint16)(1UL<<u8Port_PinBitOffset);
        }
        else
        {   // Reset the change direction flag
            u16Port_PinDirFlagWord &= (uint16)(~((uint16)(1UL<<u8Port_PinBitOffset)));
        }
    }
    
    s_u16Port_Siul2_au16GPIODirChangeability[(uint8)((uint8)u16Port_PadID>>4U)] = \
                                                                    u16Port_PinDirFlagWord;

    SchM_Exit_PORT_EXCLUSIVE_AREA_x(3);
}

#if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)

/*****************************************************************************
**  Service Name     : Port_LLD_SetGpioPadOutput
** 
**  Description      : The function will update the output for the pads whose mode is changed
**                                                                                                                       
**  Parameters (in)  : PinIndex: Pin ID number
**                     pConfigPtr: A pointer to the structure which contains initialization parameters
**                                                             
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/

FUNC (void, PORT_CODE) Port_LLD_SetGpioPadOutput \
( \
    VAR    (Port_PinType,    AUTOMATIC                 ) u32Port_PinIndex, \
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pPort_ConfigPtr \
)
{

    VAR(uint16, AUTOMATIC) u16Port_PinPad \
    = (uint16)(pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u16Port_SIUPin);
    VAR(uint8, AUTOMATIC) u8Port_LocalPDO \
            = pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u32Port_PinIndex].u8Port_GPDO;

    // Set pin to High value
    if (PORT_PIN_LEVEL_HIGH_U8 == u8Port_LocalPDO)
    {
        SchM_Enter_PORT_EXCLUSIVE_AREA_01();
        SIUL.GPDO[u16Port_PinPad].R = (uint8)STD_HIGH;
        SchM_Exit_PORT_EXCLUSIVE_AREA_01();
    }
    // Set pin to Low value
    else if (PORT_PIN_LEVEL_LOW_U8 == u8Port_LocalPDO)
    {
        SchM_Enter_PORT_EXCLUSIVE_AREA_02();
        SIUL.GPDO[u16Port_PinPad].R = (uint8)STD_LOW;
        SchM_Exit_PORT_EXCLUSIVE_AREA_02();
    }
    else
    {
        // No action to be done
    }
}
#endif
#endif

/*****************************************************************************
**  Service Name     : Port_LLD_RefreshPortDirection
** 
**  Description      : This service shall refresh the direction of all configured ports to the configured
**                     direction. The PORT driver shall exclude from refreshing those port pins that are
**                     configured as pin direction changeable during runtime.     
**         
**  Parameters (in)  : numPins: Number of pins to be refreshed
**                                                             
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/

FUNC (void, PORT_CODE) Port_LLD_RefreshPortDirection \
( \
    P2CONST(Port_ConfigType, AUTOMATIC,PORT_APPL_CONST) pPort_ConfigPtr \
)
{
     VAR(uint16, AUTOMATIC) u16Port_NumPins = pPort_ConfigPtr->Port_UsedPin.u16Port_NumPins;
     // Index of the port table
     VAR(uint16, AUTOMATIC) u16Port_PinIndex = 0;
     VAR(uint16, AUTOMATIC) u16Port_PinPad = 0;
    
     // Initialize All Configured Port Pins that aren't direction changable
     u16Port_PinIndex = (uint16)0U;
     while( u16Port_PinIndex < u16Port_NumPins)
     {
         if ((boolean)FALSE \
                 == pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].bPort_DC)
         {
             // Point to the Port Pin MSCR register address
             u16Port_PinPad = (uint16) \
                 pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u16Port_SIUPin;
        
            SchM_Enter_PORT_EXCLUSIVE_AREA_x(4);

             // Configures Port Pin as Output
             if ((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_PCR \
                                                                     & SIUL_PCR_ODE_U16) != 0U)
             {
                 // Set MSCR.ODC bitfield to the value taken from configuration
                 SchM_Enter_PORT_EXCLUSIVE_AREA_03();
                 SIUL.PCR[u16Port_PinPad].R = (SIUL.PCR[u16Port_PinPad].R \
                 & (~SIUL_PCR_ODE_U16)) \
                 | (pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_PCR \
                 & SIUL_PCR_ODE_U16);
                 SchM_Exit_PORT_EXCLUSIVE_AREA_03();
             }
             else
             {
                 SchM_Enter_PORT_EXCLUSIVE_AREA_04();
                 SIUL.PCR[u16Port_PinPad].R &= (~SIUL_PCR_ODE_U16);
                 SchM_Exit_PORT_EXCLUSIVE_AREA_04();
             }
             // Configures Port Pin as Input
             if ((pPort_ConfigPtr->Port_UsedPin.pPort_UsedPadConfig[u16Port_PinIndex].u32Port_PCR \
                                                                 & SIUL_PCR_IBE_U16) != 0U)
             {
                 SchM_Enter_PORT_EXCLUSIVE_AREA_05();
                 SIUL.PCR[u16Port_PinPad].R |= SIUL_PCR_IBE_U16;
                 SchM_Exit_PORT_EXCLUSIVE_AREA_05();
             }
             else
             {
                 SchM_Enter_PORT_EXCLUSIVE_AREA_06();
                 SIUL.PCR[u16Port_PinPad].R &= (~SIUL_PCR_IBE_U16);
                 SchM_Exit_PORT_EXCLUSIVE_AREA_06();
             }
            SchM_Exit_PORT_EXCLUSIVE_AREA_x(4);
         }
         u16Port_PinIndex++;
     }
}


#define PORT_STOP_SEC_CODE
/**
* file MemMap.h
*/
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
