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
 * Component : CDD_A4911_LLD.h
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
#ifndef CDD_A4911_LLD_H
#define CDD_A4911_LLD_H
#include "CDD_A4911_Struct.h"

/*
 **********************************************************************************************************************
 * USER CONFIG
 **********************************************************************************************************************
 */
#define A4911_SPI_BUFFER_SIZE 2

void A4911_Fill_SPI_Tx_Buffer(A4911_Data_tag *SPIOut);
uint8_t cal_Parity(uint16_t data);
void A4911_Sync_Transmission(const uint8_t *txFrame, uint8_t *rxFrame, uint8_t size, uint8_t target);
void A4911_SPI_ExchangeData(A4911_Data_tag *SPIOut, uint8_t target);
#endif /* CDD_A4911_LLD_H */
