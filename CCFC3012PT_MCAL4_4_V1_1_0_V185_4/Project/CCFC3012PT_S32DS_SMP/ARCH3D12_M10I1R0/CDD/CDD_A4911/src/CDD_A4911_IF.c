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
 *  * Component : CDD_A4911_IF.c
 *  * Date      : Dec 30 2024
 *  * Author	: w
 *  * Version   : 1.0
 *  * Description  :    This module interfaces A4911 function and diagnostic
 *  *
 *  *******************************************************************************************************************
 */
#include "CDD_A4911_IF.h"


void CDD_A4911_Open_Sense_Amp(uint8_t target)
{
    A4911_Write_Config3(target, 0x1, 0x1, 0x1, 0x18);
    A4911_Read_Config3(target);
}

void CDD_A4911_Sense_Config(uint8_t target, uint8_t SAO, uint8_t SAG)
{
    A4911_Write_Config7(target, SAO, SAG);
    A4911_Read_Config7(target);
}
