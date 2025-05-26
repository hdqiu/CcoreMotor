
#include "tester_mcu.h"
#include "intc_lld.h"
#include "console.h"
#include "Mcu.h"
#include "Mcu_Irq.h"

extern VAR(uint8, DET_VAR) Det_InstanceId;     /**< @brief DET instance ID*/
extern VAR(uint8, DET_VAR) Det_ApiId;          /**< @brief DET API ID*/
extern VAR(uint8, DET_VAR) Det_ErrorId;        /**< @brief DET Error ID*/
extern VAR(uint16, DET_VAR) Det_ModuleId;      /**< @brief DET module ID*/


void Mcu_001(void)
{
    int retVal = 0;
    Mcu_Init(&McuModuleConfiguration);
    if(Det_ModuleId == MCU_MODULE_ID && Det_ErrorId != 0)
    {
        if(Det_InstanceId != MCU_INSTANCE_ID || Det_ApiId != MCU_INIT_ID || Det_ErrorId != 0)
        {
            retVal++;
        }
    }
    Mcu_InitClock(0);
    if(Det_ModuleId == MCU_MODULE_ID && Det_ErrorId != 0)
    {
        if(Det_InstanceId != MCU_INSTANCE_ID || Det_ApiId != MCU_INITCLOCK_ID || Det_ErrorId != 0)
        {
            retVal++;
        }
    }
    Mcu_SetMode(0);
    if(Det_ModuleId == MCU_MODULE_ID && Det_ErrorId != 0)
    {
        if(Det_InstanceId != MCU_INSTANCE_ID || Det_ApiId != MCU_INITCLOCK_ID || Det_ErrorId != 0)
        {
            retVal++;
        }
    }
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
       /* wait until all enabled PLLs are locked */
    }
    if(Det_ModuleId == MCU_MODULE_ID && Det_ErrorId != 0)
    {
        if(Det_InstanceId != MCU_INSTANCE_ID || Det_ApiId != MCU_GETPLLSTATUS_ID || Det_ErrorId != 0)
        {
            retVal++;
        }
    }
    Mcu_DistributePllClock();
    if(Det_ModuleId == MCU_MODULE_ID && Det_ErrorId != 0)
    {
        if(Det_InstanceId != MCU_INSTANCE_ID || Det_ApiId != MCU_DISTRIBUTEPLLCLOCK_ID || Det_ErrorId != 0)
        {
            retVal++;
        }
    }

    Console_Init();
    if(retVal == 0)
    {
        PSPRINTF("Mcu_001 is OK\n");
    }
    else
    {
        PSPRINTF("Mcu_001 is NOT OK\n");
    }
}


void Mcu_002(void)
{
    int retVal = 0;
    Mcu_PllStatusType PllStatus;
    Mcu_Init(&McuModuleConfiguration);
    PllStatus = Mcu_GetPllStatus();
    if(PllStatus != MCU_PLL_UNLOCKED)
    {
        retVal++;
    }
    Mcu_InitClock(0);
    Mcu_SetMode(0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
       /* wait until all enabled PLLs are locked */
    }
    PllStatus = Mcu_GetPllStatus();
    if(PllStatus != MCU_PLL_LOCKED)
    {
        retVal++;
    }
    Mcu_DistributePllClock();
    PllStatus = Mcu_GetPllStatus();
    if(PllStatus != MCU_PLL_LOCKED)
    {
        retVal++;
    }

    Console_Init();
    if(retVal == 0)
    {
        PSPRINTF("Mcu_002 is OK\n");
    }
    else
    {
        PSPRINTF("Mcu_002 is NOT OK\n");
    }
}


void Mcu_003(void)
{
    int retVal = 0;
    const Mcu_ClockConfigType *ClockConfig = (const Mcu_ClockConfigType*)&McuModuleConfiguration.Mcu_ClockConfigPtr[0];
    Mcu_Init(&McuModuleConfiguration);
    if(CGM_SYSTEM_CLOCK_SRC_IRCOSC != MC_ME.GS.B.S_SYSCLK)
    {
        retVal++;
    }
    Mcu_InitClock(0);
    Mcu_SetMode(0);
    if(CGM_SYSTEM_CLOCK_SRC_IRCOSC != MC_ME.GS.B.S_SYSCLK)
    {
        retVal++;
    }
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
       /* wait until all enabled PLLs are locked */
    }
    if(CGM_SYSTEM_CLOCK_SRC_IRCOSC != MC_ME.GS.B.S_SYSCLK)
    {
        retVal++;
    }
    Mcu_DistributePllClock();
    if(ClockConfig->mode_configuration.sysclk != MC_ME.GS.B.S_SYSCLK)
    {
        retVal++;
    }

    Console_Init();
    if(retVal == 0)
    {
        PSPRINTF("Mcu_003 is OK\n");
    }
    else
    {
        PSPRINTF("Mcu_003 is NOT OK\n");
    }
}


void Mcu_004(void)
{
    int retVal = 0;
    const Mcu_ModeConfigType *ModeConfig = (const Mcu_ModeConfigType*)&McuModuleConfiguration.Mcu_ModeConfigPtr[2];
    Mcu_Init(&McuModuleConfiguration);
    Mcu_InitClock(0);
    Mcu_SetMode(0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
       /* wait until all enabled PLLs are locked */
    }
    Mcu_DistributePllClock();

    Console_Init();
    Mcu_SetMode(2);
    if(ModeConfig->Mcu_ChipMode != MC_ME.GS.B.S_CURRENT_MODE)
    {
        retVal++;
    }
    if(ModeConfig->Mcu_IRC_En != MC_ME.GS.B.S_IRC)
    {
        retVal++;
    }
    if(ModeConfig->Mcu_XOSC_En != MC_ME.GS.B.S_XOSC)
    {
        retVal++;
    }
    if(ModeConfig->Mcu_PLL0_En != MC_ME.GS.B.S_PLL0)
    {
        retVal++;
    }
    if(ModeConfig->Mcu_PLL1_En != MC_ME.GS.B.S_PLL1)
    {
        retVal++;
    }
    if(ModeConfig->Mcu_TargetClock != MC_ME.GS.B.S_SYSCLK)
    {
        retVal++;
    }

    if(retVal == 0)
    {
        PSPRINTF("Mcu_004 is OK\n");
    }
    else
    {
        PSPRINTF("Mcu_004 is NOT OK\n");
    }
}


void Mcu_005(void)
{
    Mcu_ResetType Reset;
    int i;
    Mcu_Init(&McuModuleConfiguration);
    Reset = Mcu_GetResetReason();
    Mcu_InitClock(0);
    Mcu_SetMode(0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
       /* wait until all enabled PLLs are locked */
    }
    Mcu_DistributePllClock();

    Console_Init();
    if(Reset == MCU_SOFT_FUNC_RESET)
    {
        PSPRINTF("Mcu_005 is OK\n");
    }
    else
    {
        PSPRINTF("Mcu_005 is NOT OK\n");
    }
    for(i=0;i<8000000;i++);
    PSPRINTF("Mcu_PerformReset() Output once per second\n");
    Mcu_PerformReset();
}

FUNC(void, MCU_CODE)Mcu_ClockFailureCallback(void)
{
    return;
}
FUNC(void, MCU_CODE)Mcu_XoscCallback(void)
{
    return;
}
FUNC(void, MCU_CODE)Mcu_InvalidConfigCoreCallback(void)
{
    return;
}
FUNC(void, MCU_CODE)Mcu_InvalidConfigClockCallback(void)
{
    return;
}
FUNC(void, MCU_CODE)Mcu_InvalidConfigCallback(void)
{
    return;
}
FUNC(void, MCU_CODE)Mcu_InvalidModeCallback(void)
{
    return;
}
FUNC(void, MCU_CODE)Mcu_SafeModeCallback(void)
{
    return;
}
FUNC(void, MCU_CODE)Mcu_ModeCompleteCallback(void)
{
    return;
}
FUNC(void, MCU_CODE)Mcu_PmcVoltageErrorCallback(void)
{
    return;
}
FUNC(void, MCU_CODE)Mcu_PmcTempErrorCallback(void)
{
    return;
}

FUNC(void, MCU_CODE)FccuAlarmCallback(void)
{
    return;
}

FUNC(void, MCU_CODE)FccuTimeoutCallback(void)
{
    return;
}

