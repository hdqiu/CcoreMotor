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
 * Component : CDD_HE9285_Drv.h
 * Date      : Oct 16 2024
 * Author	 : David
 * Version   : 0.5
 * Description  : 	This module interfaces HE9285 function and diagnostic
 * 					HE9285 -->KKChips-->Functional safety PMIC
 ***********************************************************************************************
*/

#ifndef CDD_HE9285_DRV_H
#define CDD_HE9285_DRV_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
//#include "Std_Types.h"
#include "StandardTypes.h"
#include "CDD_HE9285_Cfg.h"
#include "Gpt.h"
/*
 **********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************
 */
/* wakeup source type */
typedef enum
{
	SBC_WK_INVALID,
	SBC_WK_WAK, /* ENA signal wakeup flag */
	SBC_WK_ENA, /* WAK signal wakeup flag */
	SBC_WK_WKTIM, /* Wake timer wakeup flag */
	SBC_WK_RESET, /* Reset */
	SBC_WK_POR  /* First power on */
} HE9285_WK_SRC_Type;

typedef enum
{
	HE9285_WatchdogCycleTime_100us = 0,
	HE9285_WatchdogCycleTime_1ms = 1
}HE9285_WatchdogCycleTime;

typedef struct
{
    HE9285_WatchdogCycleTime watchdogCycleTime; /**< \brief  Watchdog cycle time */
	boolean errEnabled;  /**< \brief If TRUE, the ERR monitoring is enabled */
	Gpt_ChannelType TriggerTimer;	
    /** \brief Window watchdog */
    struct
    {
        boolean enabled; /**< \brief If TRUE, the watchdog is enabled */
    	float32 openWindowTime;  /**< \brief Watchdog open window time in s */
    	float32 closeWindowTime;  /**< \brief Watchdog close window time in s */
        boolean useWdiPin;		/**< \brief If TRUE, use the WDI pin to service the watchdog, else use the SPI */
    }windowWatchdog;
    struct
    {
        boolean enabled; /**< \brief If TRUE, the watchdog is enabled */
    	uint8 heartbeatTimerPeriod;  /**< \brief Watchdog heartbeat period of watchdof cycle */
    	uint32 servicePeriod;  /**< \brief Watchdog service period in us */
    }functionalWatchdog;
    
}HE9285_WDG_Config;

typedef enum SystemModeTypeTag
{
  SYS_MODE_INVALID = 0, /* For internal usage only */
  /* NORMAL mode of the system. */
  SYS_MODE_NORMAL,
  /* STANDBY mode of the system. */
  SYS_MODE_STANDBY,
  /* SLEEP mode of the system. */
  SYS_MODE_SLEEP
} SystemModeType;






    /** \brief Window watchdog */



/*
 **********************************************************************************************************************
 * External Call Functions
 **********************************************************************************************************************
 */
Std_ReturnType CDD_HE9284_ReadAndUnlockProtectedRegisters();
Std_ReturnType CDD_HE9284_WriteAndLockProtectedRegisters();
void HE9285_WatchConfigInit(HE9285_WDG_Config *config);
Std_ReturnType CDD_HE9285_WDG_Init(HE9285_WDG_Config *config);
Std_ReturnType CDD_HE9285_FWD_Trigger();
void CDD_HE9285_Drv_Init(void);
void CDD_HE9285_Drv_MainFunction(void);
extern Std_ReturnType CDD_HE9285_Drv_GetWuReason(HE9285_WK_SRC_Type* reason);
extern Std_ReturnType CDD_HE9285_Drv_SetWakeupTimer(uint32 Wakeup_timer_ms);
extern void CDD_HE9285_Drv_Shutdown(void);

// void CDD_HE9285_WDG_Init(HE9285_Config *config);
// boolean HE9285_setWatchdogCycleTime(HE9285_WatchdogCycleTime value);
//Std_ReturnType HE9285_CanSetMode();
//Std_ReturnType HE9285_SysSetMode();
//Std_ReturnType CDD_HE9285_SetMode(SystemModeType mode);

#endif /* CDD_HE9285_DRV_H */

/*
 **********************************************************************************************************************
 * End of the file
 **********************************************************************************************************************
 */
