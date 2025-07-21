/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM low level drivers code
* HISTORY     : Initial version
* @file     gtm_lld.c
* @version  1.0
* @date     2023 - 05 - 11
* @brief    Initial version.
*
*****************************************************************************/
 /*PRQA S 0380,0686,1503,1338,1297 EOF*/

#include "gtm4_lld.h"
#ifdef RESORUCE_SUPPORT_GTM410


/*
 * @brief GTM Reset.
 *
 * @param[in] None.
 *
 * @return None
 */
void GTM_LLD_Reset_lld(void)
{
	GTM4.GLS[0].ARCH.RST.B.RST = 1u;
}

/*
 * @brief AEI Timeout value.
 *
 * @param[in] GTM_LLD_SetAEITimeoutValue AEI Timeout value.
 *
 * @return Operation status
 */
status_t GTM_LLD_SetAEITimeoutValue_lld(uint32_t GTM_LLD_SetAEITimeoutVal)
{
    GTM4.GLS[0].ARCH.CTRL.B.TO_VAL = GTM_LLD_SetAEITimeoutVal;
	if(GTM4.GLS[0].ARCH.CTRL.B.TO_VAL != GTM_LLD_SetAEITimeoutVal)
	{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

/*
 * @brief Timeout mode.
 *
 * @param[in] AEITimeoutMode Timeout mode.
 *
 * @return Operation status
 */
status_t GTM_LLD_SelectAEITimeoutMode_lld(GTM_AEITimeoutMode_Type AEITimeoutMode)
{
    GTM4.GLS[0].ARCH.CTRL.B.TO_MODE = (uint8_t)AEITimeoutMode;
	if(GTM4.GLS[0].ARCH.CTRL.B.TO_MODE != (uint8_t)AEITimeoutMode)
	{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

/*
 * @brief RST and FORCINT protection
 *
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status
 */
status_t GTM_LLD_IsEnableRSTFORCINTProtection_lld(GTM_IsEnable_Type IsEnable)
{
    GTM4.GLS[0].ARCH.CTRL.B.RF_PROT = (uint8_t)IsEnable;
	if(GTM4.GLS[0].ARCH.CTRL.B.RF_PROT != (uint8_t)IsEnable)
	{
		return STATUS_ERROR;
	}
	return STATUS_SUCCESS;
}

/*
 * @brief GTM Module enable
 *
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status
 */
status_t GTM_LLD_IsEnableModule_lld(GTM_IsEnable_Type IsEnable)
{
	if(IsEnable != 0u)	 /*PRQA S 1881 */
	{
		IsEnable = 0u;
	}
	else
	{
		IsEnable = 1u;
	}
	GTM4.GLS[0].GTMINT.GTMMCR.B.MDIS = (uint8_t)IsEnable;
	if(GTM4.GLS[0].GTMINT.GTMMCR.B.MDIS != (uint8_t)IsEnable)
	{
		return STATUS_ERROR;
	}
//	GTM4.GLS[5].GTMINT.GTMMCR.B.MDIS = (uint8_t)IsEnable;
//	if(GTM4.GLS[5].GTMINT.GTMMCR.B.MDIS != (uint8_t)IsEnable)
//	{
//		return STATUS_ERROR;
//	}
//	GTM4.GLS[4].GTMINT.GTMMCR.B.MDIS = (uint8_t)IsEnable;
//	if(GTM4.GLS[4].GTMINT.GTMMCR.B.MDIS != (uint8_t)IsEnable)
//	{
//		return STATUS_ERROR;
//	}
	return STATUS_SUCCESS;
}

/*
 * @brief GTM CLS clk div enable
 *
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status
 */
status_t GTM_LLD_IsEnableClsDiv_lld(GTM_CLS_Type GTM_CLSn, GTM_ClsDivStatus_Type status)
{
    GTM4.GLS[0].ARCH.CTRL.B.RF_PROT = 0;
    GTM4.GLS[0].ARCH.CLS_CLK_CFG.R &= ~(uint32_t)(0x3u << 2u * (uint32_t)GTM_CLSn);
    GTM4.GLS[0].ARCH.CLS_CLK_CFG.R |= (uint32_t)((uint32_t)status << 2u * (uint32_t)GTM_CLSn);
    GTM4.GLS[0].ARCH.CTRL.B.RF_PROT = 1;

    return STATUS_SUCCESS;
}

/*
 * @brief GTM HRES enable
 *
 * @param[in] IsEnable Enable status.
 *
 * @return Operation status
 */
status_t GTM_LLD_HresEn_lld(GTM_IsEnable_Type IsEnable)
{
    GTM4.GLS[0].GLSDLLCTRL[0].R = (0x33030000 | (uint32_t)IsEnable);
    GTM4.GLS[0].GLSDLLCTRL[1].R = (0x33030000 | (uint32_t)IsEnable);
    while(GTM4.GLS[0].GLSDLLCTRL[0].B.LOCK_STA == 0);
    while(GTM4.GLS[0].GLSDLLCTRL[1].B.LOCK_STA == 0);

//    GTM4.GLS[4].GLSDLLCTRL[0].R = (0x33030000 | (uint32_t)IsEnable);
//    GTM4.GLS[4].GLSDLLCTRL[1].R = (0x33030000 | (uint32_t)IsEnable);
//    while(GTM4.GLS[4].GLSDLLCTRL[0].B.LOCK_STA == 0);
//    while(GTM4.GLS[4].GLSDLLCTRL[1].B.LOCK_STA == 0);

    return STATUS_SUCCESS;
}

status_t GTM_LLD_SetToutSel_lld(uint32_t TOUT_NUM,  uint32_t TOUT_SEL)
{
    GTM4.GLS[0].TOUTSEL[TOUT_NUM / 8].R |= (TOUT_SEL << (0x4 * (TOUT_NUM % 8)));

    return STATUS_SUCCESS;
}

#endif /* RESORUCE_SUPPORT_GTM410 */

