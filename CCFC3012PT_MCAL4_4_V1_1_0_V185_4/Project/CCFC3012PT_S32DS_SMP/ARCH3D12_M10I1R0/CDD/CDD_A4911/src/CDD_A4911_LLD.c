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
 * Component : CDD_A4911_LLD.c
 * Date      : Dec 30 2024
 * Author	 : W
 * Version   : 1.0
 * Description  : 	This module interfaces A4911 function and diagnostic
 ***********************************************************************************************
 */

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "CDD_A4911_LLD.h"
#include "Gpt_Stm_LLDriver.h"
#include "Spi_Test.h"
#include "Spi.h"

/*
 **********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************
 */
uint8_t A4911_tx_Buffer[A4911_SPI_BUFFER_SIZE] = {0};
uint8_t A4911_rx_Buffer[A4911_SPI_BUFFER_SIZE] = {0};

A4911_Data_tag A4911_SPI_Buffer;

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
 */
void A4911_Fill_SPI_Tx_Buffer(A4911_Data_tag *SPIOut)
{
    A4911_tx_Buffer[0] = (uint8_t)((SPIOut->TxOut.R >> 8) & 0xFF);
    A4911_tx_Buffer[1] = (uint8_t)(SPIOut->TxOut.R & 0xFF);
}

/* parity check Functions */
uint8_t cal_Parity(uint16_t data)
{
    int parity_bit = 1;
    int i;

    // 閬嶅巻16浣嶆暟鎹�
    for ( i = 0; i < 15; i++)
    {
        if (data & (1 << i))
        {
            parity_bit ^= 1;
        }
    }

    return parity_bit;
}

void A4911_Sync_Transmission(const uint8_t *txFrame, uint8_t *rxFrame, uint8_t size, uint8_t target)
{
    switch (target)
    {
        case A4911_A:
            if (Spi_SetupEB(12, txFrame, rxFrame, size) == E_OK)
            {
                if (Spi_AsyncTransmit(5) == E_OK)
                {
                    /* Wait for transmission completed */
                    while (0 != Spi_GetSequenceResult(5))
                    {
                    }
                }
            }
            break;

        case A4911_B:
            if (Spi_SetupEB(24, txFrame, rxFrame, size) == E_OK)
            {
                if (Spi_AsyncTransmit(13) == E_OK)
                {
                    /* Wait for transmission completed */
                    while (0 != Spi_GetSequenceResult(13))
                    {
                    }
                }
            }
            break;
    }
}

void A4911_SPI_ExchangeData(A4911_Data_tag *SPIOut, uint8_t target)
{

    SPIOut->TxOut.B.crc = cal_Parity(SPIOut->TxOut.R);

    A4911_Fill_SPI_Tx_Buffer(SPIOut);

    A4911_Sync_Transmission((uint8_t *)A4911_tx_Buffer, (uint8_t *)A4911_rx_Buffer, 1, target);

    SPIOut->RxIn.R = (uint16_t)((A4911_rx_Buffer[0] << 8) | A4911_rx_Buffer[1]);
}
