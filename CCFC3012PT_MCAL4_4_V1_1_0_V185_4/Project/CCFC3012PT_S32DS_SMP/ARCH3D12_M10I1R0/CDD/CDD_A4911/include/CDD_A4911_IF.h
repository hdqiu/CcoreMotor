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
 * Component : CDD_A4911_IF.h
 * Date      : Dec 30 2024
 * Author	 : W
 * Version   : 1.0
 * Description  : 	This module interfaces A4911 function and diagnostic
 ***********************************************************************************************
 */

#ifndef CDD_A4911_IF_H
#define CDD_A4911_IF_H

#include "CDD_A4911_Struct.h"
#include "CDD_A4911_LLD.h"
#include "CDD_A4911_Drv.h"

void CDD_A4911_Open_Sense_Amp(uint8_t target);
void CDD_A4911_Sense_Config(uint8_t target, uint8_t SAO, uint8_t SAG);



#endif /* CDD_A4911_IF_H */