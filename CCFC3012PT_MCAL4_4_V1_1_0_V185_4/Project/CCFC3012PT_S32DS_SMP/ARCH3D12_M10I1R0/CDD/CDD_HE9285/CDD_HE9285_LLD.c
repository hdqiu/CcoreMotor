/*
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, GELU Tech, 2024. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 ************************************************************************************************
 * Component : CDD_HE9285_Struct.h
 * Date      : Oct 16 2024
 * Author	 : David
 * Version   : 0.5
 * Description  : 	This module interfaces HE9285 function 
 ***********************************************************************************************
*/
#include "CDD_HE9285_LLD.H"

static VAR(Sbc_SpiDataWidth, HE9285_VAR_NOINIT) SpiOutBuffer[HE9285_NUMBER_OF_DEVICES];
static VAR(Sbc_SpiDataWidth, HE9285_VAR_NOINIT) SpiInBuffer[HE9285_NUMBER_OF_DEVICES];




FUNC(Std_ReturnType, HE9285_CODE) HE9285_SpiInit()
{
  Std_ReturnType result = E_NOT_OK;
  result = Spi_SetupEB(
    SpiChannel_1, /* SBSW_SBC_CALL_SPI_SETUPEB */
    (Spi_DataType*) &SpiOutBuffer[0],
    (Spi_DataType*) &SpiInBuffer[0],
    HE9285_SPI_TRANSFER_LENGTH*2);
  return result;
}

FUNC(Std_ReturnType, HE9285_CODE) HE9285_Spi_RwRegister(
    Sbc_IdType dId, uint16 out, P2VAR(uint16, AUTOMATIC, SBC_30_HE9285_APPL_DATA) in)
{

  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType result = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Write command to SPI out buffer */
  SpiOutBuffer[dId] = out; /* SBSW_SBC_VALID_DID */

//  Sbc_EnterCritical(SBC_EXCLUSIVE_AREA_3);
  /* >>> CRITICAL SECTION START >>> */

  /* #20 Transmit command synchronously via SPI */
  result = Spi_SyncTransmit(SpiSequence_1);

  /* #30 If parameter target is not a NULL_PTR, write read back value to pointer */
  if(in != NULL_PTR)
  {
    *in = SpiInBuffer[dId]; /* SBSW_SBC_VALID_INPTR */
  }

  /* <<< CRITICAL SECTION END <<< */
//  Sbc_LeaveCritical(SBC_EXCLUSIVE_AREA_3);

  return result;
}

