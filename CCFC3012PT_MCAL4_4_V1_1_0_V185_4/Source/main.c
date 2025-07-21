/**************************************************************************** 
*
* Copyright (c) 2023  C*Core -   All Rights Reserved  
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* @file     main.c
* @version  1.0
* @date     2023 - 04 - 17
* @brief    Initial version.
*
*****************************************************************************/
#include "main.h"
#include <Cfg_Pos.h>
#include "Mcu.h"
#include "mpu_lldriver.h"
#include "cmpu_cfg.h"
#include "intc_lld.h"
#include "console.h"
#include "shell_port.h"
#include "eDma.h"
#include "Gpt_Stm_LLDriver.h"
#include "Gpt.h"
#include "Port.h"
#include "eMIOS.h"
#include "tester_wdg.h"
#include "tester_canfd.h"
#include "tester_gpt.h"
#include "CarSigGen.h"
#include "tester_sdadc.h"
#include "tester_adc.h"
#include "motor_gtm4.h"
#include "tester_gpt_multi.h"
#include "Spi_Test.h"
#include "CDD_A4911_LLD.h"
#include "CDD_A4911_Drv.h"
#include "CDD_A4911_IF.h"
#include "Spi.h"
#include "CDD_HE9285_Drv.h"
#include "Sdadc_Rdc.h"
#include "SDAdc.h"

#include "gflib.h"

__attribute__ ((section (".cpu0_dtcm_data"))) signed int exe_data_buf_a[32]= {0};
__attribute__ ((section (".cpu0_dtcm_data"))) signed int sin_data_buf_a[32]= {0};
__attribute__ ((section (".cpu0_dtcm_data"))) signed int cos_data_buf_a[32]= {0};
__attribute__ ((section (".cpu0_dtcm_data"))) Sdadc_Rdc g_RdcSdadc_a;

__attribute__ ((section (".cpu1_dtcm_data"))) signed int exe_data_buf_b[32]= {0};
__attribute__ ((section (".cpu1_dtcm_data"))) signed int sin_data_buf_b[32]= {0};
__attribute__ ((section (".cpu1_dtcm_data"))) signed int cos_data_buf_b[32]= {0};
__attribute__ ((section (".cpu1_dtcm_data"))) Sdadc_Rdc g_RdcSdadc_b;


void Intc_Init(void)
{
    (void) INTC_LLD_Swtich_Mode(INTC_MODE_SOFTWARE_VECTOR);
    INTC_LLD_Set_Vector_Prefix((uint32_t)&VTABLE);/*PRQA S 0305*/
    INTC_LLD_Set_Vector_Table((uint32_t)&IntcIsrVectorTable[0U]);
    if(GetCoreID() == 0U)
    {
        INTC_LLD_Reset_IRQ_Status();
    }
    (void) INTC_LLD_Set_Global_Priority(INTR_PRI_0);
    INTC_LLD_Set_Global_Enable();
}

extern void CANFD_0001(void);

#if defined(MCORE_INIT)
void Mcore_Init(void)
{

}
#endif

void ChangeModeFailed(void);
void ChangeModeFailed(void)
{

}

BootFunc CoreFunc[6U] = {
    Core0Main,
    Core1Main,
    Core2Main,
    Core3Main,
    Core4Main,
    Core5Main };

int main(void)
{
#ifdef MPU_ENABLE
    (void)CMPU_LLD_Init(&cmpu_Cfg, cmpu_EntryArray, 1U);
#endif
    CoreFunc[GetCoreID()]();
    for(;;);
}

#define CORESYNC 1

void SDadc_ResultCallback_Ins0(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
{
    (void) parameter;
    (void) status;
    (void) mappedChannel;
}
void SDadc_ResultCallback_Ins1(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
{
    (void) parameter;
    (void) status;
    (void) mappedChannel;
}
//SDADC采样完成计算
void SDadc_ResultCallback_Ins2(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
{
    (void) parameter;
    (void) status;
    (void) mappedChannel;
    SIUL.GPDO[PC8].R = 1;
    SuspendAllInterrupts();
    Sdadc_Rdc_updateStep1(&g_RdcSdadc_a);
    ResumeAllInterrupts();
    SIUL.GPDO[PC8].R = 0;
}
void SDadc_ResultCallback_Ins3(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
{
    (void) parameter;
    (void) status;
    (void) mappedChannel;
}
void SDadc_ResultCallback_Ins4(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
{
    (void) parameter;
    (void) status;
    (void) mappedChannel;
}
void SDadc_ResultCallback_Ins5(const void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
{
    (void) parameter;
    (void) status;
    (void) mappedChannel;
    SIUL.GPDO[PQ7].R = 1;
    SuspendAllInterrupts();
    Sdadc_Rdc_updateStep1(&g_RdcSdadc_b);
    ResumeAllInterrupts();
    SIUL.GPDO[PQ7].R = 0;
}
extern uint32_t cnt1_ATOM4;
Adc_ValueGroupType result_main[ADC_CONFIG_GROUPS][10];
extern volatile uint8 flag_2ms;
extern volatile uint8 flag_2ms_2;
extern volatile uint8 ioTestFlag;

//#define SDADC_START_SEC_VAR_SHARED_INIT
//#include "Sdadc_MemMap.h"
//volatile uint8 ioTestFlag = 0;
//#define SDADC_STOP_SEC_VAR_SHARED_INIT
//#include "Sdadc_MemMap.h"

#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
volatile uint8 initOk = 0;
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"

volatile uint8 initOk2 = 0;

extern Adc_ValueGroupType resultForFOC2_0[ADC_CONFIG_GROUPS/2][10];
extern Adc_ValueGroupType resultForFOC2_1[ADC_CONFIG_GROUPS/2][10];
extern ADCSamp      ADCSampPare_0;
extern ADCSamp      ADCSampPare_1;
volatile uint8 canSendCounter = 0;

#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
volatile uint8 syncFlag = 0u;
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"

#pragma GCC push_options
//#pragma GCC optimize ("O0")
void Core0Main(void)
{
//    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
    uint16 i = 0U;
    uint16 j = 0U;

    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
    uint8 tranbuffer[2] = {2,7};
    uint8 recbuffer[2] = {0};

    Mcu_Init(&McuModuleConfiguration);
    Mcu_InitClock(0);
    Mcu_SetMode(0);
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
       /* wait until all enabled PLLs are locked */
    }
    Mcu_DistributePllClock();

    Intc_Init();
    /* 
    1. This macro "CORESYNC" defines whether the following programs enable the three core synchronizations or not.
    2. Single Z42 core debugging, can turn off the core synchronization function.
    3. After enabling core synchronization, the debugging process has to debug three cores and start the other two cores through Z42.
    4. The core synchronization process cannot be terminated until three cores have performed it.
     */
    #if CORESYNC
    Mcu_CoreSynchronise();
    #endif
    Port_Init(&PortContainer);
    Console_Init();

//    gpt_init_test();

    (void)Gpt_STM_LLD_DelayInit(STM1);

    EDMA_Init(&EDma_Config);

#if( GPT_ENABLE_GTMCMU == STD_ON )
    GPT_Gtm_Init(&Gpt_Gtm_Cmu_PBCfg);
#endif
	eMIOS_Init(&eMIOS_Config);
#if SWITCH_CORE_ENABLE
    shell_coreid = 0U; /* If switch core is enable, shell default core ID (range: 0-5)*/
#endif /* SWITCH_CORE_ENABLE */
    SIUL.PCR[0].R = 1<<7 | 7 <<2;
    SIUL.PCR[250].R = 1<<7 | 7 <<2;//PP10
    SIUL.PCR[PQ6].R = 1<<7 | 7 <<2;
    SIUL.PCR[PQ7].R = 1<<7 | 7 <<2;
    SIUL.PCR[PC7].R = 1<<7 | 7 <<2;
    SIUL.PCR[PC8].R = 1<<7 | 7 <<2;
    SIUL.PCR[PC11].R = 1<<7 | 7 <<2;
    SIUL.PCR[PT9].R = 1<<7 | 7 <<2;
    SIUL.PCR[PS6].R = 1<<7 | 7 <<2;
    SIUL.PCR[PI7].R = 1<<7 | 7 <<2;
    SIUL.GPDO[PT9].R = 1;

    //LED
    SIUL.PCR[PD2].R = 1<<7 | 7 <<2;
    SIUL.PCR[PD3].R = 1<<7 | 7 <<2;

    //SDADC2 DMA done
	INTC_LLD_Set_IRQ_Handle(DMA0_CH17_IRQn, &EDMA_Ch17_IRQHandler);
	INTC_LLD_Set_IRQ_Priority(DMA0_CH17_IRQn, INTR_PRI_63);
	INTC_LLD_Set_IRQ_Enable(DMA0_CH17_IRQn);

	//set GTM_SDADC_TRIG1
	SIUL.ISEL13.R = 0x0f0f100f;
	SIUL.ISEL14.R = 0x00001010;
    GTM_TrigSDADC((uint8_t)GTM_CLS0, GTM_SDADC_TRIG1, GTM_SDADC_TRIG_MEMBER0, GTM_SDADC_TRIG_OUTSEL_4); //ATOM2_4
    GTM_TrigSDADC((uint8_t)GTM_CLS0, GTM_SDADC_TRIG1, GTM_SDADC_TRIG_MEMBER1, GTM_SDADC_TRIG_OUTSEL_8); //ATOM3_4

	Sdadc_Init(&SdAdc_TotalConfig);

#if(MOTOR_LEFT_EN == MOTOR_ENABLE)
	Sdadc_SetupResultBuffer(0, &exe_data_buf_a[0], 32);
	Sdadc_SetupResultBuffer(3, &sin_data_buf_a[0], 32);
	Sdadc_SetupResultBuffer(2, &cos_data_buf_a[0], 32);
	Sdadc_StartModulation(2);
	Sdadc_StartModulation(3);
	Sdadc_StartModulation(0);
#endif	//(MOTOR_LEFT_EN == MOTOR_ENABLE)

	//init rdc
	Sdadc_Rdc_init(&g_RdcSdadc_a, &cfg_Pos_RdcDs_a);
	g_RdcSdadc_a.sdadc_sin = sin_data_buf_a;
	g_RdcSdadc_a.sdadc_cos = cos_data_buf_a;
	g_RdcSdadc_a.Sample_point = 32;

	Sdadc_Rdc_init(&g_RdcSdadc_b, &cfg_Pos_RdcDs_b);
	g_RdcSdadc_b.sdadc_sin = sin_data_buf_b;
	g_RdcSdadc_b.sdadc_cos = cos_data_buf_b;
	g_RdcSdadc_b.Sample_point = 32;

    ADC_demo_MultiGroup();
    syncFlag = 1u;
    for(i = 0U; i < ADC_CONFIG_GROUPS/2; i++)
    {
    	memset(&resultForFOC2_0[i][0], 0, 10U);
    	memset(&resultForFOC2_1[i][0], 0, 10U);
    }
    while(syncFlag == 1);

    SIUL.GPDO[PS6].R = 1;
    SIUL.GPDO[PI7].R = 1;

    SPI_Init();
//    CDD_A4911_Open_Sense_Amp(A4911_A);
#if(MOTOR_LEFT_EN == MOTOR_ENABLE)
    CDD_A4911_Sense_Config(A4911_A,0xF,0x3);
#endif	//(MOTOR_LEFT_EN == MOTOR_ENABLE)
#if(MOTOR_RIGHT_EN == MOTOR_ENABLE)
    CDD_A4911_Sense_Config(A4911_B,0xF,0x3);
#endif	//(MOTOR_RIGHT_EN == MOTOR_ENABLE)

    Spi_SetupEB(25,tranbuffer,recbuffer,1);//TJA1145
    Spi_AsyncTransmit(14);

    while (0 != Spi_GetSequenceResult(14))
    {
    }
    tranbuffer[0] = 3;

    Spi_SetupEB(25,tranbuffer,recbuffer,1);//TJA1145
    Spi_AsyncTransmit(14);
    while (0 != Spi_GetSequenceResult(14))
    {

    }
#if 1
//	Gpt_Pit_SetIRQ();
//	gpt_init_test();
//	Gpt_100us_task();
#endif

	CDD_HE9285_Drv_Init();

	Motor_Id_Init();

    CarSigGen_Init();

    GTM_ATOM_PWM_OUTPUT();

    initOk = 1;

    while(1)
    {

    }
}

extern Adc_ValueGroupType resultbuffer_1[100];
#pragma GCC pop_options
uint8 firstRun2;
#pragma GCC push_options
//#pragma GCC optimize ("O0")
void Core1Main(void)
{
//    Shell *shellPtr = &shell[GetCoreID()];
    
    Intc_Init();
	#if CORESYNC
	Mcu_CoreSynchronise();
	#endif

//	Gpt_Pit2_SetIRQ();
//	gpt_init_test();
//	Gpt2_100us_task();

    while(syncFlag == 0);

	Adc_Init(&Adc_Config);

	Adc_SetupResultBuffer(1, &resultbuffer_1[0]);
	Adc_SetupResultBuffer(3, &resultbuffer_1[20]);
	Adc_SetupResultBuffer(5, &resultbuffer_1[40]);
	Adc_SetupResultBuffer(7, &resultbuffer_1[60]);

	Adc_EnableHardwareTrigger(1);
	Adc_EnableHardwareTrigger(3);
	Adc_EnableHardwareTrigger(5);
	Adc_EnableHardwareTrigger(7);

	(void) INTC_LLD_Set_IRQ_Priority(DMA0_CH51_IRQn, INTR_PRI_62);
	(void) INTC_LLD_Set_IRQ_Handle(DMA0_CH51_IRQn, &EDMA_Ch51_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Enable(DMA0_CH51_IRQn);

	Sdadc_Init(&SdAdc_TotalConfig);

	Sdadc_SetupResultBuffer(1, &exe_data_buf_b[0], 32);
	Sdadc_SetupResultBuffer(4, &sin_data_buf_b[0], 32);
	Sdadc_SetupResultBuffer(5, &cos_data_buf_b[0], 32);
	Sdadc_StartModulation(4);
	Sdadc_StartModulation(5);
	Sdadc_StartModulation(1);

//	SDADC5 DMA done
	INTC_LLD_Set_IRQ_Handle(DMA0_CH37_IRQn, &EDMA_Ch37_IRQHandler);
	INTC_LLD_Set_IRQ_Priority(DMA0_CH37_IRQn, INTR_PRI_63);
	INTC_LLD_Set_IRQ_Enable(DMA0_CH37_IRQn);

	syncFlag = 0U;

	while(initOk==0){}

    while(1)
    {

    }
}
#pragma GCC pop_options

#pragma GCC push_options
void Core2Main(void)
{
    Intc_Init();

	#if CORESYNC
	Mcu_CoreSynchronise();
	#endif

	Gpt_Pit0Ch6_SetIRQ();
	gpt_init_test();
	Gpt6_100us_task();

#if (SWITCH_CORE_ENABLE == 0U)
    Console_Init();

    shell_init();
#endif /* SWITCH_CORE_ENABLE */

	while(initOk==0){}

#if(CAN_CORE == 2)
    CANFD_IRQ_Priority();
    CANFD_Config_Init();
    Can_176_CanFd_SetBaudrate(CanFd_1, 1);
    Can_176_CanFd_SetControllerMode(CanFd_1, CAN_CS_STARTED);
#endif	//(CAN_CORE == 2)

    initOk2 = 1;

    while(1)
    {

    }
}
#pragma GCC pop_options

void Core3Main(void)
{
    Shell *shellPtr = &shell[GetCoreID()];

    Intc_Init();

	#if CORESYNC
	Mcu_CoreSynchronise();
	#endif

    while(1)
    {

    }
}

void Core4Main(void)
{
    Shell *shellPtr = &shell[GetCoreID()];

    Intc_Init();

	#if CORESYNC
	Mcu_CoreSynchronise();
	#endif

    while(1)
    {

    }
}

void Core5Main(void)
{
    Shell *shellPtr = &shell[GetCoreID()];

    Intc_Init();

	#if CORESYNC
	Mcu_CoreSynchronise();
	#endif

    while(1)
    {

    }
}


