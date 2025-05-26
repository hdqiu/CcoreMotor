/*
 *  *******************************************************************************************************************
 *  *
 *  * COPYRIGHT RESERVED, GELU Tech, 2024. All rights reserved.
 *  * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 *  * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 *  * All rights reserved in the event of the grant of a patent, utility model or design.
 *  *
 *  *******************************************************************************************************************
 *  *******************************************************************************************************************
 *  *
 *  * Component : CDD_A4911_Drv.c
 *  * Date      : Dec 30 2024
 *  * Author	: w
 *  * Version   : 1.0
 *  * Description  :    This module interfaces A4911 function and diagnostic
 *  *
 *  *******************************************************************************************************************
 */
#include "CDD_A4911_Drv.h"

volatile CDD_A4911_Struct_tag A4911_Tx_Register;
volatile CDD_A4911_Struct_tag A4911_Rx_Register;

volatile CDD_A4911_Status_tag A4911_status;

extern A4911_Data_tag A4911_SPI_Buffer;

void A4911_Read_Config0(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config0_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config0.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config0(uint8_t target, uint8_t DBM, uint8_t DT)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config0_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config0.B.DBM = DBM & 0x1;
    A4911_Tx_Register.Config0.B.DT = DT & 0x3F;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config0.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config1(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config1_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config1.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config1(uint8_t target, uint8_t OCQ, uint8_t OCT, uint8_t TOC)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config1_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config1.B.OCQ = OCQ & 0x1;
    A4911_Tx_Register.Config1.B.OCT = OCT & 0xF;
    A4911_Tx_Register.Config1.B.TOC = TOC & 0xF;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config1.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config2(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config2_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config2.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config2(uint8_t target, uint8_t VDQ, uint8_t TVD)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config2_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config2.B.VDQ = VDQ & 0x1;
    A4911_Tx_Register.Config2.B.TVD = TVD & 0x3F;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config2.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config3(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config3_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config3.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config3(uint8_t target, uint8_t S3C, uint8_t S2C, uint8_t S1C, uint8_t VTL)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config3_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config3.B.S3C = S3C & 0x1;
    A4911_Tx_Register.Config3.B.S2C = S2C & 0x1;
    A4911_Tx_Register.Config3.B.S1C = S1C & 0x1;
    A4911_Tx_Register.Config3.B.VTL = VTL & 0x3F;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config3.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config4(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config4_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config4.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config4(uint8_t target, uint8_t VTB, uint8_t VTH)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config4_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config4.B.VTB = VTB & 0x3;
    A4911_Tx_Register.Config4.B.VTH = VTH & 0x3F;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config4.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config5(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config5_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config5.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config5(uint8_t target, uint8_t AOL, uint8_t OLI, uint8_t DOO, uint8_t OLT)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config5_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config5.B.AOL = AOL & 0x1;
    A4911_Tx_Register.Config5.B.OLI = OLI & 0x1;
    A4911_Tx_Register.Config5.B.DOO = DOO & 0x1;
    A4911_Tx_Register.Config5.B.OLT = OLT & 0xF;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config5.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config6(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config6_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config6.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config6(uint8_t target, uint8_t EWD, uint8_t VRG, uint8_t VPT)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config6_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config6.B.EWD = EWD & 0x1;
    A4911_Tx_Register.Config6.B.VRG = VRG & 0x1;
    A4911_Tx_Register.Config6.B.VPT = VPT & 0x3F;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config6.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config7(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config7_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config7.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config7(uint8_t target, uint8_t SAO, uint8_t SAG)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config7_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config7.R = 0;
    A4911_Tx_Register.Config7.B.SAO = SAO & 0xF;
    A4911_Tx_Register.Config7.B.SAG = SAG & 0x7;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config7.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config8(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config8_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config8.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config8(uint8_t target, uint8_t THR, uint8_t THF)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config8_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config8.B.THR = THR & 0xF;
    A4911_Tx_Register.Config8.B.THF = THF & 0xF;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config8.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config9(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config9_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config9.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config9(uint8_t target, uint8_t IHR1, uint8_t IHF1)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config9_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config9.B.IHR1 = IHR1 & 0xF;
    A4911_Tx_Register.Config9.B.IHF1 = IHF1 & 0xF;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config9.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config10(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config10_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config10.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config10(uint8_t target, uint8_t IHR2, uint8_t IHF2)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config10_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config10.B.IHR2 = IHR2 & 0xF;
    A4911_Tx_Register.Config10.B.IHF2 = IHF2 & 0xF;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config10.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config11(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config11_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config11.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config11(uint8_t target, uint8_t TLR, uint8_t TLF)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config11_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config11.B.TLR = TLR & 0xF;
    A4911_Tx_Register.Config11.B.TLF = TLF & 0xF;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config11.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config12(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config12_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config12.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config12(uint8_t target, uint8_t ILR1, uint8_t ILF1)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config12_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config12.B.ILR1 = ILR1 & 0xF;
    A4911_Tx_Register.Config12.B.ILF1 = ILF1 & 0xF;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config12.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Config13(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config13_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Config13.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Config13(uint8_t target, uint8_t ILR2, uint8_t ILF2)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Config13_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Config13.B.ILR2 = ILR2 & 0xF;
    A4911_Tx_Register.Config13.B.ILF2 = ILF2 & 0xF;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Config13.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_VerifyCommand0(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_VerifyCommand0_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.VerifyCommand0.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_VerifyCommand0(uint8_t target, uint16_t command)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_VerifyCommand0_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.VerifyCommand0.B.YDO = (command >> 7) & 0x1;
    A4911_Tx_Register.VerifyCommand0.B.YRO = (command >> 6) & 0x1;
    A4911_Tx_Register.VerifyCommand0.B.YRU = (command >> 5) & 0x1;
    A4911_Tx_Register.VerifyCommand0.B.YBU = (command >> 4) & 0x1;
    A4911_Tx_Register.VerifyCommand0.B.YLO = (command >> 3) & 0x1;
    A4911_Tx_Register.VerifyCommand0.B.YSO = (command >> 2) & 0x1;
    A4911_Tx_Register.VerifyCommand0.B.YSU = (command >> 1) & 0x1;
    A4911_Tx_Register.VerifyCommand0.B.YGU = command & 0x01;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.VerifyCommand0.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_VerifyCommand1(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_VerifyCommand1_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.VerifyCommand1.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_VerifyCommand1(uint8_t target, uint16_t command)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_VerifyCommand1_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.VerifyCommand1.B.YPH = (command >> 8) & 0x1;
    A4911_Tx_Register.VerifyCommand1.B.YPL = (command >> 7) & 0x1;
    A4911_Tx_Register.VerifyCommand1.B.YOC = (command >> 6) & 0x1;
    A4911_Tx_Register.VerifyCommand1.B.YOL = (command >> 5) & 0x1;
    A4911_Tx_Register.VerifyCommand1.B.YOP = (command >> 2) & 0x3;
    A4911_Tx_Register.VerifyCommand1.B.YO1 = (command >> 1) & 0x1;
    A4911_Tx_Register.VerifyCommand1.B.YO2 = command & 0x01;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.VerifyCommand1.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_VerifyCommand2(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_VerifyCommand2_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.VerifyCommand2.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_VerifyCommand2(uint8_t target, uint16_t command)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_VerifyCommand2_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.VerifyCommand2.B.YTW = (command >> 8) & 0x1;
    A4911_Tx_Register.VerifyCommand2.B.YOT = (command >> 7) & 0x1;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.VerifyCommand2.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_VerifyResult0(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_VerifyResult0_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.VerifyResult0.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Read_VerifyResult1(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_VerifyResult1_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.VerifyResult1.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Read_Mask0(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Mask0_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Mask0.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Mask0(uint8_t target, uint16_t mask)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Mask0_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Mask0.B.CHU = (mask >> 5) & 0x1;
    A4911_Tx_Register.Mask0.B.CLU = (mask >> 4) & 0x1;
    A4911_Tx_Register.Mask0.B.BHU = (mask >> 3) & 0x1;
    A4911_Tx_Register.Mask0.B.BLU = (mask >> 2) & 0x1;
    A4911_Tx_Register.Mask0.B.AHU = (mask >> 1) & 0x1;
    A4911_Tx_Register.Mask0.B.ALU = mask & 0x1;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Mask0.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Mask1(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Mask1_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Mask1.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Mask1(uint8_t target, uint16_t mask)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Mask1_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Mask1.B.VRO = (mask >> 8) & 0x1;
    A4911_Tx_Register.Mask1.B.VRU = (mask >> 7) & 0x1;
    A4911_Tx_Register.Mask1.B.CHO = (mask >> 5) & 0x1;
    A4911_Tx_Register.Mask1.B.CLO = (mask >> 4) & 0x1;
    A4911_Tx_Register.Mask1.B.BHO = (mask >> 3) & 0x1;
    A4911_Tx_Register.Mask1.B.BLO = (mask >> 2) & 0x1;
    A4911_Tx_Register.Mask1.B.AHO = (mask >> 1) & 0x1;
    A4911_Tx_Register.Mask1.B.ALO = mask & 0x1;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Mask1.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Mask2(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Mask2_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Mask2.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Mask2(uint8_t target, uint16_t mask)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Mask2_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Mask2.B.VS = (mask >> 8) & 0x1;
    A4911_Tx_Register.Mask2.B.VLO = (mask >> 7) & 0x1;
    A4911_Tx_Register.Mask2.B.BSU = (mask >> 6) & 0x1;
    A4911_Tx_Register.Mask2.B.TW = (mask >> 5) & 0x1;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Mask2.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}

void A4911_Read_Diag0(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Diag0_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Diag0.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Read_Diag1(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Diag1_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Diag1.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Read_Diag2(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Diag2_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Diag2.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Read_Control(uint8_t target)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Control_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 0;
    A4911_SPI_Buffer.TxOut.B.data = 0x0;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_Rx_Register.Control.R = A4911_SPI_Buffer.RxIn.B.data;
}

void A4911_Write_Control(uint8_t target, uint16_t control)
{
    A4911_SPI_Buffer.TxOut.B.address = SPI_Control_ADDR;
    A4911_SPI_Buffer.TxOut.B.WR = 1;
    A4911_Tx_Register.Control.B.DG1 = (control >> 8) & 0x1;
    A4911_Tx_Register.Control.B.DG0 = (control >> 7) & 0x1;
    A4911_Tx_Register.Control.B.ESF = (control >> 6) & 0x1;
    A4911_Tx_Register.Control.B.CH = (control >> 5) & 0x1;
    A4911_Tx_Register.Control.B.CL = (control >> 4) & 0x1;
    A4911_Tx_Register.Control.B.BH = (control >> 3) & 0x1;
    A4911_Tx_Register.Control.B.BL = (control >> 2) & 0x1;
    A4911_Tx_Register.Control.B.AH = (control >> 1) & 0x1;
    A4911_Tx_Register.Control.B.AL = control & 0x1;
    A4911_SPI_Buffer.TxOut.B.data = A4911_Tx_Register.Control.R & 0x1FF;
    A4911_SPI_ExchangeData(&A4911_SPI_Buffer, target);
    A4911_status.R = A4911_SPI_Buffer.RxIn.R;
}
