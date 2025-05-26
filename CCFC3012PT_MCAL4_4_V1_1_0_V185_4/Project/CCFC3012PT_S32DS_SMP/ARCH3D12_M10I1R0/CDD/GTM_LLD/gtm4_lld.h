
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC30xx
* DESCRIPTION : CCFC30xx GTM low level drivers h file
* HISTORY     : Initial version
* @file     gtm4_lld.h
* @version  1.0
* @date     2023 - 04 - 11
* @brief    Initial version.
*
*****************************************************************************/
#ifndef GTM4_LLD_H_
#define GTM4_LLD_H_
#include "derivative.h"
#ifdef RESORUCE_SUPPORT_GTM410

#include "status.h"
#include "Gpt_GTM410_LLDriver.h"


//typedef enum{
//    GTM_CLS0 = 0,
//    GTM_CLS1,
//    GTM_CLS2,
//    GTM_CLS3,
//    GTM_CLS4,
//    GTM_CLS5,
//    GTM_CLS6,
//    GTM_CLS7,
//}GTM_CLS_Type;

//typedef enum{
//    ClsDisable = 0,
//    ClsEnableWithoutDiv,
//    ClsEnableWithDiv2
//}GTM_ClsDivStatus_Type;

typedef enum{
	Disable = 0,
	Enable
}GTM_IsEnable_Type;

//typedef enum{
//	GTM_IRQ_MODE_Level = 0,
//	GTM_IRQ_MODE_Pulse,
//	GTM_IRQ_MODE_PulseNotify,
//	GTM_IRQ_MODE_SinglePulse
//}GTM_InterruptMode_Type;

//typedef enum{
//	GTM_TO_MODE_Observe = 0,
//	GTM_TO_MODE_Abort
//}GTM_AEITimeoutMode_Type;

void GTM_LLD_Reset_lld(void);

status_t GTM_LLD_SetAEITimeoutValue_lld(uint32_t GTM_LLD_SetAEITimeoutVal);

status_t GTM_LLD_SelectAEITimeoutMode_lld(GTM_AEITimeoutMode_Type AEITimeoutMode);

status_t GTM_LLD_IsEnableRSTFORCINTProtection_lld(GTM_IsEnable_Type IsEnable);

status_t GTM_LLD_IsEnableModule_lld(GTM_IsEnable_Type IsEnable);

status_t GTM_LLD_IsEnableClsDiv_lld(GTM_CLS_Type GTM_CLSn, GTM_ClsDivStatus_Type status);

status_t GTM_LLD_HresEn_lld(GTM_IsEnable_Type IsEnable);

status_t GTM_LLD_SetToutSel_lld(uint32_t TOUT_NUM,  uint32_t TOUT_SEL);
#endif /* RESORUCE_SUPPORT_GTM410 */
#endif /* GTM4_LLD_H_ */

