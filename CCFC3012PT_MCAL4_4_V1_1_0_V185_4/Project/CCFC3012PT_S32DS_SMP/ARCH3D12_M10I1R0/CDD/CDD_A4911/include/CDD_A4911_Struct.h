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
 * Component : CDD_A4911_Struct.h
 * Date      : Dec 30 2024
 * Author	 : W
 * Version   : 1.0
 * Description  : 	This module interfaces A4911 function and diagnostic
 * 					
 ***********************************************************************************************
 */
#ifndef CDD_A4911_STRUCT_H
#define CDD_A4911_STRUCT_H

#include "typedefs.h"

/*SPi data format of MCU read and receive from A4911*/
typedef struct A4911_Data {
    union {
        uint16_t R;
        struct
        {
            /* data */
            uint16_t address : 5;
            uint16_t WR : 1;
            uint16_t data : 9;
            uint16_t crc : 1;
        } B;
    } TxOut; /*MCU Send to A4911 through SPI bus*/
    union {
        uint16_t R;
        struct
        {
            /* data */
            uint16_t status : 6;
            uint16_t data : 9;
            uint16_t crc : 1;
        } B;
    } RxIn; /*MCU Read from A4911 through SPI bus*/
} A4911_Data_tag;

#define A4911_A 0x0
#define A4911_B 0x1

#define SPI_Config0_ADDR 0x00
#define SPI_Config1_ADDR 0x01
#define SPI_Config2_ADDR 0x02
#define SPI_Config3_ADDR 0x03
#define SPI_Config4_ADDR 0x04
#define SPI_Config5_ADDR 0x05
#define SPI_Config6_ADDR 0x06
#define SPI_Config7_ADDR 0x07
#define SPI_Config8_ADDR 0x08
#define SPI_Config9_ADDR 0x09
#define SPI_Config10_ADDR 0x0A
#define SPI_Config11_ADDR 0x0B
#define SPI_Config12_ADDR 0x0C
#define SPI_Config13_ADDR 0x0D

#define SPI_VerifyCommand0_ADDR 0x14
#define SPI_VerifyCommand1_ADDR 0x15
#define SPI_VerifyCommand2_ADDR 0x16

#define SPI_VerifyResult0_ADDR 0x17
#define SPI_VerifyResult1_ADDR 0x18

#define SPI_Mask0_ADDR 0x19
#define SPI_Mask1_ADDR 0x1A
#define SPI_Mask2_ADDR 0x1B

#define SPI_Diag0_ADDR 0x1C
#define SPI_Diag1_ADDR 0x1D
#define SPI_Diag2_ADDR 0x1E

#define SPI_Control_ADDR 0x1F

typedef struct CDD_A4911_Struct {
    /* data */
    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t DBM : 1;
            uint16_t : 2;
            uint16_t DT : 6;
        } B;
    } Config0;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t OCQ : 1;
            uint16_t OCT : 4;
            uint16_t TOC : 4;
        } B;
    } Config1;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t VDQ : 1;
            uint16_t : 2;
            uint16_t TVD : 6;
        } B;
    } Config2;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t S3C : 1;
            uint16_t S2C : 1;
            uint16_t S1C : 1;
            uint16_t VTL : 6;
        } B;
    } Config3;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t VTB : 2;
            uint16_t : 1;
            uint16_t VTH : 6;
        } B;
    } Config4;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t AOL : 1;
            uint16_t OLI : 1;
            uint16_t DOO : 1;
            uint16_t : 2;
            uint16_t OLT : 4;
        } B;
    } Config5;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t EWD : 1;
            uint16_t VRG : 1;
            uint16_t : 1;
            uint16_t VPT : 6;
        } B;
    } Config6;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 1;
            uint16_t SAO : 4;
            uint16_t : 1;
            uint16_t SAG : 3;
        } B;
    } Config7;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 1;
            uint16_t THR : 4;
            uint16_t THF : 4;
        } B;
    } Config8;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 1;
            uint16_t IHR1 : 4;
            uint16_t IHF1 : 4;
        } B;
    } Config9;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 1;
            uint16_t IHR2 : 4;
            uint16_t IHF2 : 4;
        } B;
    } Config10;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 1;
            uint16_t TLR : 4;
            uint16_t TLF : 4;
        } B;
    } Config11;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 1;
            uint16_t ILR1 : 4;
            uint16_t ILF1 : 4;
        } B;
    } Config12;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 1;
            uint16_t ILR2 : 4;
            uint16_t ILF2 : 4;
        } B;
    } Config13;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 1;
            uint16_t YDO : 1;
            uint16_t YRO : 1;
            uint16_t YRU : 1;
            uint16_t YBU : 1;
            uint16_t YLO : 1;
            uint16_t YSO : 1;
            uint16_t YSU : 1;
            uint16_t YGU : 1;
        } B;
    } VerifyCommand0;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t YPH : 1;
            uint16_t YPL : 1;
            uint16_t YOC : 1;
            uint16_t : 1;
            uint16_t YOL : 1;
            uint16_t YOP : 2;
            uint16_t YO1 : 1;
            uint16_t YO2 : 1;
        } B;
    } VerifyCommand1;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t YTW : 1;
            uint16_t YOT : 1;
            uint16_t : 7;
        } B;
    } VerifyCommand2;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 2;
            uint16_t PCD : 1;
            uint16_t PBD : 1;
            uint16_t PAD : 1;
            uint16_t VBR : 1;
            uint16_t LCD : 1;
            uint16_t LBD : 1;
            uint16_t LAD : 1;
        } B;
    } VerifyResult0;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 2;
            uint16_t GDO : 1;
            uint16_t SCS : 1;
            uint16_t SBS : 1;
            uint16_t SAS : 1;
            uint16_t S3D : 1;
            uint16_t S2D : 1;
            uint16_t S1D : 1;
        } B;
    } VerifyResult1;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 3;
            uint16_t CHU : 1;
            uint16_t CLU : 1;
            uint16_t BHU : 1;
            uint16_t BLU : 1;
            uint16_t AHU : 1;
            uint16_t ALU : 1;
        } B;
    } Mask0;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t VRO : 1;
            uint16_t VRU : 1;
            uint16_t : 1;
            uint16_t CHO : 1;
            uint16_t CLO : 1;
            uint16_t BHO : 1;
            uint16_t BLO : 1;
            uint16_t AHO : 1;
            uint16_t ALO : 1;
        } B;
    } Mask1;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t VS : 1;
            uint16_t VLO : 1;
            uint16_t BSU : 1;
            uint16_t TW : 1;
            uint16_t : 5;
        } B;
    } Mask2;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t : 3;
            uint16_t CHU : 1;
            uint16_t CLU : 1;
            uint16_t BHU : 1;
            uint16_t BLU : 1;
            uint16_t AHU : 1;
            uint16_t ALU : 1;
        } B;
    } Diag0;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t VRO : 1;
            uint16_t VRU : 1;
            uint16_t : 1;
            uint16_t CHO : 1;
            uint16_t CLO : 1;
            uint16_t BHO : 1;
            uint16_t BLO : 1;
            uint16_t AHO : 1;
            uint16_t ALO : 1;
        } B;
    } Diag1;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t VC : 1;
            uint16_t VB : 1;
            uint16_t VA : 1;
            uint16_t VSO : 1;
            uint16_t VSU : 1;
            uint16_t OC3 : 1;
            uint16_t OC2 : 1;
            uint16_t OC1 : 1;
            uint16_t OL : 1;
        } B;
    } Diag2;

    union {
        /* data */
        uint16_t R;
        struct
        {
            /* data */
            uint16_t : 7;
            uint16_t DG1 : 1;
            uint16_t DG0 : 1;
            uint16_t ESF : 1;
            uint16_t CH : 1;
            uint16_t CL : 1;
            uint16_t BH : 1;
            uint16_t BL : 1;
            uint16_t AH : 1;
            uint16_t AL : 1;
        } B;
    } Control;
} CDD_A4911_Struct_tag;

typedef struct CDD_A4911_Status {
    uint16_t R;
    struct
    {
        /* data */
        uint16_t FF : 1;
        uint16_t POR : 1;
        uint16_t SE : 1;
        uint16_t EE : 1;
        uint16_t OT : 1;
        uint16_t TW : 1;
        uint16_t VS : 1;
        uint16_t VLO : 1;
        uint16_t ETO : 1;
        uint16_t VR : 1;
        uint16_t : 1;
        uint16_t LDF : 1;
        uint16_t BSU : 1;
        uint16_t GSU : 1;
        uint16_t DSO : 1;
        uint16_t CRC : 1;
    } B;
} CDD_A4911_Status_tag;

#endif