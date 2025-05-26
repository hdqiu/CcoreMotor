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
 * Component : CDD_HE9285_Drv.c
 * Date      : Oct 16 2024
 * Author	 : David
 * Version   : 0.5
 * Description  : 	This module interfaces HE9285 function and diagnostic
 * 					HE9285 -->KKChips-->Functional safety PMIC
 ***********************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
//#include "CDD_HE9285_IF.h"
#include "StandardTypes.h"
// #include "Sbc_30_HE9285.h"
#include "CDD_HE9285_Drv.h"
#include "CDD_HE9285_Struct.h"
// #include "Sbc_30_HE9285.h"
#include "CDD_HE9285_LLD.H"
#if (STD_ON == HE9285_ECUM_SUPPORT)
#include "EcuM.h"
#endif

/*
 **********************************************************************************************************************
 * Private Macro Definitions
 **********************************************************************************************************************
 */
#define CODE_LOCAL										static
#define CODE_LOCAL_INLINE								static inline

#define HE9285_DEBUG_INFO
#define HE9285_P_FILL_CHECK							STD_ON /* STD_ON: fill the polarity bit of spi command */
#define HE9285_MakeWRCmd(addr, data)  				((uint16)((((((addr) & 0x3Fu) << 8) | ((uint16)(data) & 0xFFu)) << 1u) | 0x8000u))
#define HE9285_MakeRDCmd(addr)        				((uint16)(((addr) & 0x3Fu) << 9u))



/*
 **********************************************************************************************************************
 * Private Type Definitions
 **********************************************************************************************************************
 */
/* Drive status type of HE9285 */
typedef enum
{
	STATUS_UINIT,		/* state un-initialized */
	STATUS_INIT,		/* state initialized */
	STATUS_ERROR		/* state error */
} Sbc_DrvStatus_Type;

/*
 **********************************************************************************************************************
 * Private Function Declarations
 **********************************************************************************************************************
 */
CODE_LOCAL Std_ReturnType HE9285_WriteReg(HE9285_Reg_t reg, uint8 data);
CODE_LOCAL Std_ReturnType HE9285_ReadReg(HE9285_Reg_t reg,uint8* data);
CODE_LOCAL uint16 HE9285_CalcSpiParity(uint16 in);

/*
 **********************************************************************************************************************
 * Private Variable Definitions
 **********************************************************************************************************************
 */
/* For SPI communication */
static Sbc_SpiDataWidth HE9285_TxData;
static Sbc_SpiDataWidth HE9285_RxData;

/* For HE9285 driver */
static Sbc_DrvStatus_Type HE9285_DrvStatus = STATUS_UINIT;
static uint8 HE9285_Status; /* status[5:0] in SDO */
#ifdef HE9285_DEBUG_INFO
static HE9285_Reg_t HE9285_DebugRegToRead = HE9285_REG_NUM;
static uint8 HE9285_DebugRegValue;
// static Sbc_SystemStatusType HE9285_SysStatus;
static HE9285_WK_SRC_Type HE9285_WKReason;
#endif
#if (STD_ON == HE9285_REGACCESS)
static uint8 HE9285_RegValueLocal[HE9285_REG_NUM];
static uint8 HE9285_RegReadFlag[HE9285_REG_NUM];
static REG_INITERR_t Reg_INITERR_Init;
static REG_WKSF_t Reg_WKSF_Init;
#endif

/*! Buffer to read/write protected register values  */
static VAR(uint8, HE9285_VAR_NOINIT)
  HE9285_ProtectedRegisterValues[HE9285_NUMBER_OF_PROTECTED_REGISTERS];

static uint8 HE9285_FwdQuestion;

//static SystemModeType currentMode;

/* for WWD WDG */
#if (STD_ON == WWD_SUPPORT)
static uint16 WWD_Timeout_Counter; /* SWS_Wdg_00153 */
#endif

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/

/*******************************************************************************************
* Name              :   m_delay
* Description       :	delay about 1ms
* Parameters[in]    :	none
* Parameters[out]   :   none
* Limitations       :	only called from Drv
* ReturnType        :   void
*******************************************************************************************/
//#define TickMax 200000
//static void m_delay(void)
//{
// uint32 tick = TickMax;
// tick = TickMax;
// while(tick > 0)
// {
//  tick --;
// }
//}

/*******************************************************************************************
* Name              :   CDD_HE9285_Drv_Init
* Description       :	Initialization function for HE9285
* Parameters[in]    :	none
* Parameters[out]   :   none
* Limitations       :	only called from App
* ReturnType        :   void
*******************************************************************************************/
 
 typedef struct
{
  uint8 RESP3; /*!< Response byte 3 */
  uint8 RESP2; /*!< Response byte 2 */
  uint8 RESP1; /*!< Response byte 1 */
  uint8 RESP0; /*!< Response byte 0 */
} HE9285_FwdResponse_Type1;

HE9285_FwdResponse_Type1 HE9285_FwdResponseTbl[16] =  /* PRQA S 3218 */ /* MD_Sbc_3218 */
{
/* QUESTION */ /* RESP3, RESP2, RESP1, RESP0 */
/*     0    */  { 0xFFu, 0x0Fu, 0xF0u, 0x00u },
/*     1    */  { 0xB0u, 0x40u, 0xBFu, 0x4Fu },
/*     2    */  { 0xE9u, 0x19u, 0xE6u, 0x16u },
/*     3    */  { 0xA6u, 0x56u, 0xA9u, 0x59u },
/*     4    */  { 0x75u, 0x85u, 0x7Au, 0x8Au },
/*     5    */  { 0x3Au, 0xCAu, 0x35u, 0xC5u },
/*     6    */  { 0x63u, 0x93u, 0x6Cu, 0x9Cu },
/*     7    */  { 0x2Cu, 0xDCu, 0x23u, 0xD3u },
/*     8    */  { 0xD2u, 0x22u, 0xDDu, 0x2Du },
/*     9    */  { 0x9Du, 0x6Du, 0x92u, 0x62u },
/*     A    */  { 0xC4u, 0x34u, 0xCBu, 0x3Bu },
/*     B    */  { 0x8Bu, 0x7Bu, 0x84u, 0x74u },
/*     C    */  { 0x58u, 0xA8u, 0x57u, 0xA7u },
/*     D    */  { 0x17u, 0xE7u, 0x18u, 0xE8u },
/*     E    */  { 0x4Eu, 0xBEu, 0x41u, 0xB1u },
/*     F    */  { 0x01u, 0xF1u, 0x0Eu, 0xFEu }
 };
typedef enum
{
  SYSPCFG0 = 0, /*!< Index for buffered value of register SYSPCFG0. */
  SYSPCFG1 = 1, /*!< Index for buffered value of register SYSPCFG1. */
  WDCFG0 = 2,   /*!< Index for buffered value of register WDCFG0. */
  WDCFG1 = 3,   /*!< Index for buffered value of register WDCFG1. */
  FWDCFG = 4,   /*!< Index for buffered value of register FWDCFG. */
  WWDCFG0 = 5,  /*!< Index for buffered value of register WWDCFG0. */
  WWDCFG1 = 6   /*!< Index for buffered value of register WWDCFG1. */
} ProtectedRegisterValueIndex_Type;

Std_ReturnType CDD_HE9284_ReadAndUnlockProtectedRegisters()
{
	Std_ReturnType result = E_OK;
	uint8 regIdx = 0;


	
	/*unlock protected registers */
	result |= HE9285_WriteReg(HE9285_REG_PROTCFG,HE9285_REG_CMD_PROTCFG_UNLOCK_SEQ1);
	result |= HE9285_WriteReg(HE9285_REG_PROTCFG,HE9285_REG_CMD_PROTCFG_UNLOCK_SEQ2);
	result |= HE9285_WriteReg(HE9285_REG_PROTCFG,HE9285_REG_CMD_PROTCFG_UNLOCK_SEQ3);
	result |= HE9285_WriteReg(HE9285_REG_PROTCFG,HE9285_REG_CMD_PROTCFG_UNLOCK_SEQ4);

	/* Check if unlock procedure was successful */
	result |= HE9285_ReadReg(HE9285_REG_PROTSTAT,&HE9285_RegValueLocal[HE9285_REG_PROTSTAT]);
	if (((uint8)HE9285_RegValueLocal[HE9285_REG_PROTSTAT] & HE9285_REG_MASK_PROTSTAT_LOCK) != 0) 
 	{
    	result |= E_NOT_OK;
  	}
	else
	{	
		/*Read values of protected register to buffer */
		for (regIdx = 0; regIdx < HE9285_NUMBER_OF_PROTECTED_REGISTERS; regIdx++)
		{
			result |= HE9285_ReadReg(HE9285_REG_SYSPCFG0 + regIdx,&HE9285_RegValueLocal[HE9285_REG_RSYSPCFG0 + regIdx] );
			// edit Buffer
			HE9285_ProtectedRegisterValues[regIdx] = ~HE9285_RegValueLocal[HE9285_REG_RSYSPCFG0 + regIdx];
		}
		
	}
	return result;
}

Std_ReturnType CDD_HE9284_WriteAndLockProtectedRegisters()
{
    Std_ReturnType result = E_OK;
	uint8 regIdx = 0;
	uint8 checkSum = 0xFF;


	/* Write buffered values of protected registers */
	for (regIdx = 0; regIdx < HE9285_NUMBER_OF_PROTECTED_REGISTERS; regIdx++)
	{
		result |= HE9285_WriteReg(HE9285_REG_SYSPCFG0 + regIdx,HE9285_ProtectedRegisterValues[regIdx]);
	}
 	/*Lock protected registers */
	result |= HE9285_WriteReg(HE9285_REG_PROTCFG,HE9285_REG_CMD_PROTCFG_LOCK_SEQ1);
	result |= HE9285_WriteReg(HE9285_REG_PROTCFG,HE9285_REG_CMD_PROTCFG_LOCK_SEQ2);
	result |= HE9285_WriteReg(HE9285_REG_PROTCFG,HE9285_REG_CMD_PROTCFG_LOCK_SEQ3);
	result |= HE9285_WriteReg(HE9285_REG_PROTCFG,HE9285_REG_CMD_PROTCFG_LOCK_SEQ4);


	/* Check if lock procedure was successful */
	result |= HE9285_ReadReg(HE9285_REG_PROTSTAT,&HE9285_RegValueLocal[HE9285_REG_PROTSTAT]);
	if (((uint8)HE9285_RegValueLocal[HE9285_REG_PROTSTAT] & HE9285_REG_MASK_PROTSTAT_LOCK) != HE9285_REG_MASK_PROTSTAT_LOCK) /* COV_SBC_LL_EVENTS */
  	{
    	result |= E_NOT_OK;
  	}


	/* #20 Check if data was written successfully written to protected registers */
	 for (regIdx = 0; regIdx < HE9285_NUMBER_OF_PROTECTED_REGISTERS; regIdx++)
	{
		result |= HE9285_ReadReg(HE9285_REG_SYSPCFG0 + regIdx,&HE9285_RegValueLocal[HE9285_REG_SYSPCFG0 + regIdx] );
		checkSum &= (HE9285_ProtectedRegisterValues[regIdx] ^ (uint8)HE9285_RegValueLocal[HE9285_REG_SYSPCFG0 + regIdx]);
	}

	if(checkSum != 0xFF)
	{
		result |= E_NOT_OK;
	}
	return result;
}

void CDD_HE9285_Drv_Init(void)
{
	HE9285_SpiInit();

#if (STD_ON == HE9285_REGACCESS)
//	Std_ReturnType stdRet = E_OK;

#ifdef HE9285_DEBUG_INFO
	/* get information for debug */
//	uint8 i;
//	for(i = 0;i < HE9285_REG_NUM;i++)
//	{
//		HE9285_ReadReg(i,&HE9285_RegValueLocal[i]);
//	}
#endif

	CDD_HE9284_ReadAndUnlockProtectedRegisters();
	HE9285_ProtectedRegisterValues[SYSPCFG0] = 0x01;
	HE9285_ProtectedRegisterValues[SYSPCFG1] = 0x80;
	HE9285_ProtectedRegisterValues[WDCFG0] = 0x93;
	CDD_HE9284_WriteAndLockProtectedRegisters();

	/*go to normal*/
	HE9285_WriteReg(HE9285_REG_DEVCTRL , 0xEA);
	HE9285_WriteReg(HE9285_REG_DEVCTRLN ,0x15);
	

	// /* read wake-up reason */
	// stdRet |= HE9285_ReadReg(HE9285_REG_INITERR,&HE9285_RegValueLocal[HE9285_REG_INITERR]);
	// stdRet |= HE9285_ReadReg(HE9285_REG_WKSF,&HE9285_RegValueLocal[HE9285_REG_WKSF]);
	// /* clear flags */
	// if(E_OK == stdRet)
	// {
	// 	Reg_INITERR_Init.R = HE9285_RegValueLocal[HE9285_REG_INITERR];
	// 	Reg_WKSF_Init.R = HE9285_RegValueLocal[HE9285_REG_WKSF];
	// 	m_delay();
	// 	HE9285_WriteReg(HE9285_REG_INITERR,0xff);
	// 	m_delay();
	// 	HE9285_WriteReg(HE9285_REG_WKSF,0xff);

	// 	HE9285_DrvStatus = STATUS_INIT;
	// }
	// else
	// {
	// 	HE9285_DrvStatus = STATUS_ERROR;
	// }

	// HE9285_WriteReg(HE9285_REG_INITERR,0xff);
#else
	HE9285_DrvStatus = STATUS_INIT;
#endif
}




/*******************************************************************************************
* Name              :   CDD_HE9285_Drv_MainFunction
* Description       :	Main loop function for HE9285
* Parameters[in]    :	none
* Parameters[out]   :   none
* Limitations       :	only called from App
* ReturnType        :   void
*******************************************************************************************/
void CDD_HE9285_Drv_MainFunction(void)
{
	//FWD COUNT
	// HE9285_ReadReg(HE9285_REG_FWDSTAT0,&HE9285_RegValueLocal[HE9285_REG_FWDSTAT0]);

#ifdef HE9285_DEBUG_INFO /* get information for debug */
	if(HE9285_DebugRegToRead < HE9285_REG_NUM)
	{
		HE9285_ReadReg(HE9285_DebugRegToRead,&HE9285_DebugRegValue);
		HE9285_RegValueLocal[HE9285_DebugRegToRead] = HE9285_DebugRegValue;
	}

	HE9285_ReadReg(HE9285_REG_DEVSTAT,&HE9285_RegValueLocal[HE9285_REG_DEVSTAT]);
	HE9285_ReadReg(HE9285_REG_SYSSF,&HE9285_RegValueLocal[HE9285_REG_SYSSF]);
	HE9285_ReadReg(HE9285_REG_WKSF,&HE9285_RegValueLocal[HE9285_REG_WKSF]);

	HE9285_ReadReg(HE9285_REG_RWDCFG0,&HE9285_RegValueLocal[HE9285_REG_WDCFG0]);
	HE9285_ReadReg(HE9285_REG_RFWDCFG,&HE9285_RegValueLocal[HE9285_REG_FWDCFG]);
	HE9285_ReadReg(HE9285_REG_RWWDCFG0,&HE9285_RegValueLocal[HE9285_REG_WWDCFG0]);
	HE9285_ReadReg(HE9285_REG_RWWDCFG1,&HE9285_RegValueLocal[HE9285_REG_WWDCFG1]);
	HE9285_ReadReg(HE9285_REG_WWDSTAT,&HE9285_RegValueLocal[HE9285_REG_WWDSTAT]);
	HE9285_ReadReg(HE9285_REG_FWDSTAT1,&HE9285_RegValueLocal[HE9285_REG_FWDSTAT1]);

	// Sbc_GetStatus(0, &HE9285_SysStatus);

	CDD_HE9285_Drv_GetWuReason(&HE9285_WKReason);



#endif
}

void HE9285_WatchConfigInit(HE9285_WDG_Config *config)
{
    config->watchdogCycleTime = HE9285_WatchdogCycleTime_1ms;
	config->TriggerTimer = ((Gpt_ChannelType)1u);
    config->windowWatchdog.enabled = FALSE;
    config->windowWatchdog.openWindowTime = 0.0;
    config->windowWatchdog.closeWindowTime = 0.0;
	config->windowWatchdog.useWdiPin = FALSE;
    config->functionalWatchdog.enabled = TRUE;
    config->functionalWatchdog.heartbeatTimerPeriod = 250;
	config->functionalWatchdog.servicePeriod = 250000;
}

Std_ReturnType CDD_HE9285_WDG_Init(HE9285_WDG_Config *config)
{
	Std_ReturnType result = E_OK;
	HE9285_WatchConfigInit(config);

	Gpt_EnableNotification(config->TriggerTimer);

	result |= CDD_HE9284_ReadAndUnlockProtectedRegisters();

	
	if(config->functionalWatchdog.enabled == true)
	{
		/* set tick period and enable fwd,disable wwd */
		if (config->watchdogCycleTime == HE9285_WatchdogCycleTime_1ms)
		{	
			HE9285_ProtectedRegisterValues[WDCFG0] = 0X05;
		}
		else if(config->watchdogCycleTime == HE9285_WatchdogCycleTime_100us)
		{
			// HE9285_ProtectedRegisterValues[WDCFG0] = (HE9285_WDCFG0_DEFAULT_VAL) 
			// 	& ~(HE9285_REG_MASK_WDCFG0_WWDEN | HE9285_REG_MASK_WDCFG0_WDCYC);
			HE9285_ProtectedRegisterValues[WDCFG0] = 0X04;
		}
		/* set fwd heartbeat timer period*/
//		if(config->functionalWatchdog.heartbeatTimerPeriod <= 1550)
		{
			uint8 WDHBTP = config->functionalWatchdog.heartbeatTimerPeriod / 50;
			HE9285_ProtectedRegisterValues[FWDCFG] = WDHBTP;
		}

	}

	if(config->windowWatchdog.enabled == true)
	{
		//todo
	}
	result |= CDD_HE9284_WriteAndLockProtectedRegisters();

	if(result == E_OK)
	{
		Gpt_StartTimer(config->TriggerTimer,config->functionalWatchdog.servicePeriod);
		result |= HE9285_ReadReg(HE9285_REG_FWDSTAT0, &HE9285_RegValueLocal[HE9285_REG_FWDSTAT0]); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
		HE9285_FwdQuestion= ((uint8)HE9285_RegValueLocal[HE9285_REG_FWDSTAT0] & HE9285_REG_MASK_FWDSTAT_FWDQUEST); /* SBSW_SBC_VALID_DID */
	}

	return result;
}
 
Std_ReturnType CDD_HE9285_FWD_Trigger()
{
	uint16 quest = 0;
	Std_ReturnType result = E_OK;
	quest = HE9285_FwdQuestion;
	result |= HE9285_WriteReg(HE9285_REG_ADDR_FWDRSP, HE9285_FwdResponseTbl[quest].RESP3); /* SBSW_SBC_NULLPTR_PARAM */
	result |= HE9285_WriteReg(HE9285_REG_ADDR_FWDRSP, HE9285_FwdResponseTbl[quest].RESP2); /* SBSW_SBC_NULLPTR_PARAM */
	result |= HE9285_WriteReg(HE9285_REG_ADDR_FWDRSP, HE9285_FwdResponseTbl[quest].RESP1); /* SBSW_SBC_NULLPTR_PARAM */
	result |= HE9285_WriteReg(HE9285_REG_ADDR_FWDRSPSYNC, HE9285_FwdResponseTbl[quest].RESP0); /* SBSW_SBC_NULLPTR_PARAM */
	
	result |= HE9285_ReadReg(HE9285_REG_FWDSTAT0, &HE9285_RegValueLocal[HE9285_REG_FWDSTAT0]); /* SBSW_SBC_LOCALPTR_PARAM */ /* SBSW_SBC_ACCESS_LOCAL */
	HE9285_FwdQuestion= ((uint8)HE9285_RegValueLocal[HE9285_REG_FWDSTAT0] & HE9285_REG_MASK_FWDSTAT_FWDQUEST); /* SBSW_SBC_VALID_DID */

	return result;
}

//
//Std_ReturnType HE9285_CanSetMode(SystemModeType mode)
//{
//    Std_ReturnType result = E_NOT_OK;
//	if(mode = SYS_MODE_STANDBY)
//	{
//		result = E_OK;
//
//	}
//	else if (mode = SYS_MODE_SLEEP)
//	{
//		if(currentMode == SYS_MODE_STANDBY)
//		{
//			result = E_OK;
//		}
//	}
//	else
//	{
//		/* NORMAL Mode: only NORMAL, STANDBY and SLEEP Mode are valid: Invalid ones are blocked by core DET check */
//		result = E_OK;
//	}
//
//	return result;
//}
//
////Std_ReturnType HE9285_SysSetMode()
////{
////	Std_ReturnType result = E_OK;
////	reutrn result;
////}
//
//
//Std_ReturnType CDD_HE9285_SetMode(SystemModeType mode)
//{
//	Std_ReturnType result = E_OK;
//	if(HE9285_CanSetMode(mode) == E_OK)
//	{
//
//	}
//	return result;
//
//}



// void CDD_HE9285_WDG_Init(HE9285_Config *config)
// {

// 	Std_ReturnType result = E_OK;
// 	result |= HE9285_ReadReg(HE9285_REG_PROTSTAT , &HE9285_RegValueLocal[HE9285_REG_PROTSTAT]);
// 	m_delay();
// 	result |= HE9285_WriteReg(HE9285_REG_PROTCFG , 0xAB);
// 	m_delay();
// 	result |= HE9285_WriteReg(HE9285_REG_PROTCFG , 0xEF);
// 	m_delay();
// 	result |= HE9285_WriteReg(HE9285_REG_PROTCFG , 0x56);
// 	m_delay();
// 	result |= HE9285_WriteReg(HE9285_REG_PROTCFG , 0x12);		//unlock reg
// 	m_delay();
// 	result |= HE9285_ReadReg(HE9285_REG_PROTSTAT , &HE9285_RegValueLocal[HE9285_REG_PROTSTAT]);	
// 	if (result == E_OK)
// 	{
// 		HE9285_setWatchdogCycleTime(config->watchdogCycleTime);
// 	}
	
	
// }



// boolean HE9285_setWatchdogCycleTime(HE9285_WatchdogCycleTime value)
// {

// 	// HE9285_TxData = HE9285_CalcSpiParity(0X06,0X00);
// 	// status = Sbc_Ll_RwRegister(did,HE9285_TxData,&tmp);
// 	Std_ReturnType status;
// 	status = HE9285_ReadReg(HE9285_REG_WDCFG0,&HE9285_RegValueLocal[HE9285_REG_WDCFG0]);
// 	if (status)
// 	{
// 		// set wdconfg WDCYC value
// 		uint8 data = 0x93 | value;
// 		// status |= Sbc_Ll_WriteRegister(did, 0x06, data); 
// 		status = HE9285_WriteReg(HE9285_REG_WDCFG0,data);	
// 	}
// 	return status;
// }

/*******************************************************************************************
* Name              :   CDD_HE9285_Drv_GetWuReason
* Description       :	Get wake-up reason
* Parameters[in]    :	HE9285_WK_SRC_Type* reason: Wake-up reason
* Parameters[out]   :   none
* Limitations       :	only called from Drv
* ReturnType        :   Std_ReturnType
*******************************************************************************************/
Std_ReturnType CDD_HE9285_Drv_GetWuReason(HE9285_WK_SRC_Type* reason)
{
	Std_ReturnType stdRet = E_OK;

	if(STATUS_INIT == HE9285_DrvStatus)
	{
		if(Reg_WKSF_Init.B.WAK)
			*reason = SBC_WK_WAK;
		else if(Reg_WKSF_Init.B.ENA)
			*reason = SBC_WK_ENA;
		else if(Reg_WKSF_Init.B.WKTIM)
			*reason = SBC_WK_WKTIM;
		else if(Reg_INITERR_Init.B.WWDF || Reg_INITERR_Init.B.FWDF ||
				Reg_INITERR_Init.B.SOFTRES || Reg_INITERR_Init.B.HARDRES)
			*reason = SBC_WK_RESET;
		else
			*reason = SBC_WK_POR;
	}
	else
	{
		stdRet = E_NOT_OK;
	}

	return stdRet;
}

/*******************************************************************************************
* Name              :   CDD_HE9285_Drv_SetWakeupTimer
* Description       :	Set wake-up timer
* Parameters[in]    :	uint32 Wakeup_timer_ms:wake-up time in ms
* Parameters[out]   :   none
* Limitations       :	only called from Drv
* ReturnType        :   Std_ReturnType
*******************************************************************************************/
#if (STD_ON == HE9285_REGACCESS)
Std_ReturnType CDD_HE9285_Drv_SetWakeupTimer(uint32 Wakeup_timer_ms)
{
	Std_ReturnType stdRet = E_OK;

	Wakeup_timer_ms = Wakeup_timer_ms / 10; /* 1ms->10ms */

	if(0 == Wakeup_timer_ms) /* disabled */
	{
		stdRet |= HE9285_WriteReg(HE9285_REG_DEVCFG0,0x00 | HE9285_TRDEL);
	}
	else if(Wakeup_timer_ms <= 0x00ffffff) /* WKTIMCFG0..2 -> 24bits */
	{
		stdRet |= HE9285_WriteReg(HE9285_REG_WKTIMCFG0,Wakeup_timer_ms & 0xff); /* WKTIMCFG0 */
		stdRet |= HE9285_WriteReg(HE9285_REG_WKTIMCFG1,(Wakeup_timer_ms >> 8) & 0xff); /* WKTIMCFG1 */
		stdRet |= HE9285_WriteReg(HE9285_REG_WKTIMCFG2,(Wakeup_timer_ms >> 16) & 0xff);  /* WKTIMCFG2 */

		stdRet |= HE9285_WriteReg(HE9285_REG_DEVCFG0,0xc0 | HE9285_TRDEL);
	}
	else
	{
		stdRet = E_NOT_OK;
	}


	return stdRet;
}
#endif

/*******************************************************************************************
* Name              :   CDD_HE9285_Drv_Shutdown
* Description       :	EcuM call for shutdown of HE9285
* Parameters[in]    :	none
* Parameters[out]   :   none
* Limitations       :	only called from App
* ReturnType        :   void
*******************************************************************************************/
void CDD_HE9285_Drv_Shutdown(void)
{
	//CDD_HE9285_DrvSetWakeupTimer(10000);
	// Sbc_30_HE9285_SetMode(0,SBC_SYS_MODE_STANDBY); /* then enter standby mode */
	// Sbc_30_HE9285_SetMode(0,SBC_SYS_MODE_SLEEP); /* finally enter sleep to off mcu power supply */
}





/*
 **********************************************************************************************************************
 * Private Function Defination
 **********************************************************************************************************************
 */
/*******************************************************************************************
* Name              :   HE9285_CalcSpiParity
* Description       :	Calculate SPI Parity
* Parameters[in]    :	uint16 in:source
* Parameters[out]   :   none
* Limitations       :	only called from Drv
* ReturnType        :   uint16
*******************************************************************************************/
CODE_LOCAL uint16 HE9285_CalcSpiParity(uint16 in)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 i;
  uint16 res = 0;

  /* ----- Implementation ----------------------------------------------- */
  for(i = 1; i < 16; i++)
  {
      res = res ^ ((in >> i) & 0x01);
  }
  return (((in & 0xfffe) | res));
}

/*******************************************************************************************
* Name              :   HE9285_WriteReg
* Description       :	Write register of HE9285
* Parameters[in]    :	HE9285_Reg_t reg:which reg will be writen in
* Parameters[in]    :	uint8 data:what data will be writen
* Parameters[out]   :   none
* Limitations       :	only called from Drv
* ReturnType        :   Std_ReturnType
*******************************************************************************************/
#if (STD_ON == HE9285_REGACCESS)
CODE_LOCAL Std_ReturnType HE9285_WriteReg(HE9285_Reg_t reg, uint8 data)
{
	Std_ReturnType stdRet = E_OK;
	if(reg < HE9285_REG_NUM)
	{
		/* makeup tx cmd */
		HE9285_TxData = HE9285_MakeWRCmd(reg,data);
#if (STD_ON == HE9285_P_FILL_CHECK)
		HE9285_TxData = HE9285_CalcSpiParity(HE9285_TxData);
#endif
		/* transmit */
		// stdRet = Sbc_30_HE9285_AccessRegister(0,HE9285_TxData,&HE9285_RxData);
		stdRet = HE9285_Spi_RwRegister(0,HE9285_TxData,&HE9285_RxData);
	}
	else
	{
		stdRet = E_NOT_OK;
	}

	return stdRet;
}

/*******************************************************************************************
* Name              :   HE9285_ReadReg
* Description       :	Write register of HE9285
* Parameters[in]    :	HE9285_Reg_t reg:which reg will be read
* Parameters[out]   :   uint8* data:return data pointer
* Limitations       :	only called from Drv
* ReturnType        :   Std_ReturnType
*******************************************************************************************/
CODE_LOCAL Std_ReturnType HE9285_ReadReg(HE9285_Reg_t reg,uint8* data)
{
	Std_ReturnType stdRet = E_OK;

	if(reg < HE9285_REG_NUM)
	{
		/* makeup rx cmd */
		HE9285_TxData = HE9285_MakeRDCmd(reg);
#if (STD_ON == HE9285_P_FILL_CHECK)
		HE9285_TxData = HE9285_CalcSpiParity(HE9285_TxData);
#endif
		/* transmit */
		// stdRet = Sbc_30_HE9285_AccessRegister(0,HE9285_TxData,&HE9285_RxData);
		stdRet = HE9285_Spi_RwRegister(0,HE9285_TxData,&HE9285_RxData);

		if((E_OK == stdRet) && (NULL_PTR != data))
		{
			/* check P bit */
			if(HE9285_RxData == HE9285_CalcSpiParity(HE9285_RxData))
			{
				HE9285_Status = (HE9285_RxData >> 9) & 0x3f; /* status[5:0] */
				*data = (HE9285_RxData >> 1) & 0xff; /* rd_data[7:0] */
				HE9285_RegValueLocal[reg] = *data;
				HE9285_RegReadFlag[reg] = 1;
			}
			else
			{
				stdRet = E_NOT_OK;
			}
		}
		else
		{
			stdRet = E_NOT_OK;
		}
	}
	else
	{
		stdRet = E_NOT_OK;
	}

	return stdRet;
}
#endif

/*
 **********************************************************************************************************************
 * End of the file
 **********************************************************************************************************************
 */
