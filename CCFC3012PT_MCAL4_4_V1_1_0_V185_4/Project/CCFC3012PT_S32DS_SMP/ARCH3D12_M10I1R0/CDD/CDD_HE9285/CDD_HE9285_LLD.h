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
#ifndef CDD_HE9285_LLD_H
#define CDD_HE9285_LLD_H

#include "StandardTypes.h"
#include "Platform_Types.h"
#include "Spi.h"
#include "Compiler.h"
#define SBC_UNINIT                              (0x00u)
#define SBC_INIT                                (0x01u)


#define HE9285_NUMBER_OF_DEVICES         1UL
#define HE9285_SPI_TRANSFER_LENGTH 1

// #define LOCAL_INLINE LOCAL_INLINE

typedef uint16 Sbc_IdType;
#define Sbc_SpiDataWidth uint16

typedef uint8 Spi_DataType;




FUNC(Std_ReturnType, HE9285_CODE) HE9285_Spi_RwRegister(
    Sbc_IdType dId, uint16 out, P2VAR(uint16, AUTOMATIC, SBC_30_HE9285_APPL_DATA) in);
FUNC(Std_ReturnType, HE9285_CODE) HE9285_SpiInit();

#endif /* CDD_HE9285_LLD_H */
