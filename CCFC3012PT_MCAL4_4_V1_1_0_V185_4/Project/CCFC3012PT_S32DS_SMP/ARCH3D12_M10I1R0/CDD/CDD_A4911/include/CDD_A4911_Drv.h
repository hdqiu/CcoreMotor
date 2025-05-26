
#ifndef CDD_A4911_DRV_H
#define CDD_A4911_DRV_H

#include "CDD_A4911_Struct.h"
#include "CDD_A4911_LLD.h"

void A4911_Read_Config0(uint8_t target);
void A4911_Write_Config0(uint8_t target, uint8_t DBM, uint8_t DT);
void A4911_Read_Config1(uint8_t target);
void A4911_Write_Config1(uint8_t target, uint8_t OCQ, uint8_t OCT, uint8_t TOC);
void A4911_Read_Config2(uint8_t target);
void A4911_Write_Config2(uint8_t target, uint8_t VDQ, uint8_t TVD);
void A4911_Read_Config3(uint8_t target);
void A4911_Write_Config3(uint8_t target, uint8_t S3C, uint8_t S2C, uint8_t S1C, uint8_t VTL);
void A4911_Read_Config4(uint8_t target);
void A4911_Write_Config4(uint8_t target, uint8_t VTB, uint8_t VTH);
void A4911_Read_Config5(uint8_t target);
void A4911_Write_Config5(uint8_t target, uint8_t AOL, uint8_t OLI, uint8_t DOO, uint8_t OLT);
void A4911_Read_Config6(uint8_t target);
void A4911_Write_Config6(uint8_t target, uint8_t EWD, uint8_t VRG, uint8_t VPT);
void A4911_Read_Config7(uint8_t target);
void A4911_Write_Config7(uint8_t target, uint8_t SAO, uint8_t SAG);
void A4911_Read_Config8(uint8_t target);
void A4911_Write_Config8(uint8_t target, uint8_t THR, uint8_t THF);
void A4911_Read_Config9(uint8_t target);
void A4911_Write_Config9(uint8_t target, uint8_t IHR1, uint8_t IHF1);
void A4911_Read_Config10(uint8_t target);
void A4911_Write_Config10(uint8_t target, uint8_t IHR2, uint8_t IHF2);
void A4911_Read_Config11(uint8_t target);
void A4911_Write_Config11(uint8_t target, uint8_t TLR, uint8_t TLF);
void A4911_Read_Config12(uint8_t target);
void A4911_Write_Config12(uint8_t target, uint8_t ILR1, uint8_t ILF1);
void A4911_Read_Config13(uint8_t target);
void A4911_Write_Config13(uint8_t target, uint8_t ILR2, uint8_t ILF2);
void A4911_Read_VerifyCommand0(uint8_t target);
void A4911_Write_VerifyCommand0(uint8_t target, uint16_t command);
void A4911_Read_VerifyCommand1(uint8_t target);
void A4911_Write_VerifyCommand1(uint8_t target, uint16_t command);
void A4911_Read_VerifyCommand2(uint8_t target);
void A4911_Write_VerifyCommand2(uint8_t target, uint16_t command);
void A4911_Read_VerifyResult0(uint8_t target);
void A4911_Read_VerifyResult1(uint8_t target);
void A4911_Read_Mask0(uint8_t target);
void A4911_Write_Mask0(uint8_t target, uint16_t mask);
void A4911_Read_Mask1(uint8_t target);
void A4911_Write_Mask1(uint8_t target, uint16_t mask);
void A4911_Read_Mask2(uint8_t target);
void A4911_Write_Mask2(uint8_t target, uint16_t mask);
void A4911_Read_Diag0(uint8_t target);
void A4911_Read_Diag1(uint8_t target);
void A4911_Read_Diag2(uint8_t target);
void A4911_Read_Control(uint8_t target);
void A4911_Write_Control(uint8_t target, uint16_t control);




#endif /* CDD_A4911_DRV_H */