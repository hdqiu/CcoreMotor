#include "tester_adc.h"
#include "Adc_Cfg.h"
#include "intc_lld.h"
#include "Gpt_Stm_LLDriver.h"
#include "motor_gtm4.h"
#include "tester_gpt.h"
#include "Sdadc_Rdc.h"

__attribute__ ((section (".cpu0_dtcm_data"))) extern Sdadc_Rdc g_DdcDsadc_a;
__attribute__ ((section (".cpu1_dtcm_data"))) extern Sdadc_Rdc g_DdcDsadc_b;

extern CONST(Adc_ConfigType, ADC_CONST) Adc_Config;
extern VAR(Adc_RunningGroupType, ADC_VAR) sAdc_RunningGroup[ADC_CORE_NUM][ADC_CONFIG_GROUPS];
#define ADC_TEST_CASE_MAX sizeof(adc_funcs) / sizeof(AdcfuncMachine)


__attribute__ ((section (".cpu0_dtcm_data")))  Adc_ValueGroupType resultbuffer[500] = {0U};
__attribute__ ((section (".cpu1_dtcm_data")))  Adc_ValueGroupType resultbuffer_1[100] = {0U};

static const  AdcfuncMachine adc_funcs[] =
{
    {"demo", ADC_demo},                         /* config_C */
    {"demo_dma", ADC_demo_Dma},                 /* config_D */
    {"demo_int_dma", ADC_demo_Int_Dma},         /* config_E */
    {"demo_core0", ADC_0323},                   /* Adc_MultiCore, Core 0 */
    {"demo_core1", ADC_0324},                   /* Adc_MultiCore, Core 1 */
    {"demo_core2", ADC_0325},                   /* Adc_MultiCore, Core 2 */
    {"demo_core3", ADC_0326},                   /* Adc_MultiCore, Core 3 */
    {"demo_core4", ADC_0327},                   /* Adc_MultiCore, Core 4 */
    {"demo_core5", ADC_0328},                   /* Adc_MultiCore, Core 5 */
#if (ADC_HW_TRIGGER_API == STD_ON)
    {"demo_MultiGroup", ADC_demo_MultiGroup},   /* config_I */

#endif
    {"demo_PrioQueue", ADC_demo_PrioQueue},     /* config_G */
    {"demo_Queue", ADC_demo_Queue},             /* config_H */
};

extern boolean TesterDemoADC;

void AdcNotification_func(void)
{

}

#include "Gpt_Pit_LLDriver.h"
#include "Gpt_Cfg.h"
#include "Gpt.h"
#include "tester_pwm.h"
#include "Port.h"
#include "Pwm_Cfg.h"
GPT_CONFIG_DECLARATION

void ADC_demo(void)
{
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON || ADC_HW_TRIGGER_API == STD_ON)
    uint32 Adc_timeout = ADC_TIMEOUT;
#endif
#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
#endif
    Adc_Init(&Adc_Config);

    SIUL.PCR[PA14].B.OBE = 1;
    SIUL.GPDO[PA14].B.PDO = 0;
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    uint32 i = 0U;
    PSPRINTF("\n===============================================DEMO TEST===============================================\n");
    PSPRINTF("\nTest0:ADC0 SW ADC_CONV_MODE_ONESHOT CFIFO0 RFIFO1 channel:1(CH2) ADC_RESOLUTION_BIT12\n");
    INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_1_IRQn, ADC01_GRP1);
    INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_1_IRQn, INTR_PRI_8);
    INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_1_IRQn);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(0);
    Adc_ValueGroupType result_0[20];
    while((Adc_GetGroupStatus(0) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(0, result_0);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC0 test is OK, result is %d\n", result_0[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC0 test is timeout\n");
        }
        PSPRINTF("\nADC0 test is not OK\n");
    }
    //Adc_StopGroupConversion(0);
    INTC_LLD_Set_IRQ_Disable(EQADC01_FIFO_1_IRQn);

    PSPRINTF("\nTest1:ADC1 SW ADC_CONV_MODE_ONESHOT CFIFO1 RFIFO2 channel:1(CH0) ADC_RESOLUTION_BIT12\n");
    INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_2_IRQn, ADC01_GRP2);
    INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_2_IRQn, INTR_PRI_9);
    INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_2_IRQn);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(1);
    Adc_ValueGroupType result_1[20];
    while((Adc_GetGroupStatus(1) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(1, result_1);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC1 test is OK, result is %d\n", result_1[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC1 test is timeout\n");
        }
        PSPRINTF("\nADC1 test is not OK\n");
    }
    //Adc_StopGroupConversion(1);
    INTC_LLD_Set_IRQ_Disable(EQADC01_FIFO_2_IRQn);

    PSPRINTF("\nTest2:ADC2 SW ADC_CONV_MODE_CONTINUOUS CFIFO2 RFIFO2 channel:1(CH0) ADC_RESOLUTION_BIT12\n");
    INTC_LLD_Set_IRQ_Handle(EQADC23_FIFO_2_IRQn, ADC23_GRP2);
    INTC_LLD_Set_IRQ_Priority(EQADC23_FIFO_2_IRQn, INTR_PRI_9);
    INTC_LLD_Set_IRQ_Enable(EQADC23_FIFO_2_IRQn);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(2);
    for(uint32 i = 0U; i < 100000U; i++);
    Adc_ValueGroupType result_2[20];
    for(i = 0U; i < 10U; i++)
    {
    #if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(2, result_2);
    #endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\n conv: %d ,ADC2 test is OK, result is %d\n", i, result_2[0]);
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\nADC2 test is timeout\n");
            }
            PSPRINTF("\nADC2 test is not OK\n");
        }
    }

    Adc_StopGroupConversion(2);
    INTC_LLD_Set_IRQ_Disable(EQADC23_FIFO_2_IRQn);

    PSPRINTF("\nTest3:ADC3 SW ADC_CONV_MODE_CONTINUOUS CFIFO4 RFIFO5 channel:1(CH0) ADC_RESOLUTION_BIT12\n");
    INTC_LLD_Set_IRQ_Handle(EQADC23_FIFO_5_IRQn, ADC23_GRP5);
    INTC_LLD_Set_IRQ_Priority(EQADC23_FIFO_5_IRQn, INTR_PRI_12);
    INTC_LLD_Set_IRQ_Enable(EQADC23_FIFO_5_IRQn);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(3);
    for(uint32 i = 0U; i < 100000U; i++);
    Adc_ValueGroupType result_3[20];
    for(i = 0U; i < 10U; i++)
    {
    #if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(3, result_3);
    #endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\n conv: %d ,ADC3 test is OK, result is %d\n", i, result_3[0]);
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\nADC3 test is timeout\n");
            }
            PSPRINTF("\nADC3 test is not OK\n");
        }
    }
    Adc_StopGroupConversion(3);
    INTC_LLD_Set_IRQ_Disable(EQADC23_FIFO_5_IRQn);

    PSPRINTF("\nTest4:ADC4 SW ADC_CONV_MODE_ONESHOT CFIFO5 RFIFO0 channel:1(CH0) ADC_RESOLUTION_BIT10\n");
    INTC_LLD_Set_IRQ_Handle(EQADC45_FIFO_0_IRQn, ADC45_GRP0);
    INTC_LLD_Set_IRQ_Priority(EQADC45_FIFO_0_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC45_FIFO_0_IRQn);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(4);
    Adc_ValueGroupType result_4[20];
    while((Adc_GetGroupStatus(4) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(4, result_4);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC4 test is OK, result is %d\n", result_4[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC4 test is timeout\n");
        }
        PSPRINTF("\nADC4 test is not OK\n");
    }
    //Adc_StopGroupConversion(4);
    INTC_LLD_Set_IRQ_Disable(EQADC45_FIFO_0_IRQn);

    PSPRINTF("\nTest5:ADC5 SW ADC_CONV_MODE_ONESHOT CFIFO2 RFIFO0 channel:1(CH0) ADC_RESOLUTION_BIT8\n");
    INTC_LLD_Set_IRQ_Handle(EQADC45_FIFO_0_IRQn, ADC45_GRP0);
    INTC_LLD_Set_IRQ_Priority(EQADC45_FIFO_0_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC45_FIFO_0_IRQn);
    Adc_SetupResultBuffer(5, &resultbuffer[50]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(5);
    Adc_ValueGroupType result_5[20];
    while((Adc_GetGroupStatus(5) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(5, result_5);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC5 test is OK, result is %d\n", result_5[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC5 test is timeout\n");
        }
        PSPRINTF("\nADC5 test is not OK\n");
    }
    //Adc_StopGroupConversion(5);
    INTC_LLD_Set_IRQ_Disable(EQADC45_FIFO_0_IRQn);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#if (ADC_HW_TRIGGER_API == STD_ON)
    PSPRINTF("\nTest6:ADC6 HW ADC_CONV_MODE_ONESHOT CFIFO1 RFIFO0 channel:1(CH0) ADC_RESOLUTION_BIT12 EQADC_HW_TRIG_PIT0_CH0\n");
    INTC_LLD_Set_IRQ_Handle(EQADC67_FIFO_0_IRQn, ADC67_GRP0);
    INTC_LLD_Set_IRQ_Priority(EQADC67_FIFO_0_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC67_FIFO_0_IRQn);
    Adc_SetupResultBuffer(6, &resultbuffer[60]);
    Gpt_Init(&GptChannelConfigSet);
    Adc_timeout = ADC_TIMEOUT;
    Adc_EnableHardwareTrigger(6);
    Adc_ValueGroupType result_6[20];
    Gpt_StartTimer(5, 10000);
    while((Adc_GetGroupStatus(6) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(6, result_6);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC6 test is OK, result is %d\n", result_6[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC6 test is timeout\n");
        }
        PSPRINTF("\nADC6 test is not OK\n");
    }
    Adc_DisableHardwareTrigger(6);
    Gpt_StopTimer(5);
    INTC_LLD_Set_IRQ_Disable(EQADC67_FIFO_0_IRQn);
    Gpt_DeInit();

    PSPRINTF("\nTest7:ADC7 HW ADC_CONV_MODE_ONESHOT CFIFO2 RFIFO1 channel:1(CH0) ADC_RESOLUTION_BIT10 EQADC_HW_TRIG_EMIOS0_CH16\n");
    INTC_LLD_Set_IRQ_Handle(EQADC67_FIFO_1_IRQn, ADC67_GRP1);
    INTC_LLD_Set_IRQ_Priority(EQADC67_FIFO_1_IRQn, INTR_PRI_8);
    INTC_LLD_Set_IRQ_Enable(EQADC67_FIFO_1_IRQn);
    Adc_SetupResultBuffer(7, &resultbuffer[70]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_EnableHardwareTrigger(7);
    Adc_ValueGroupType result_7[20];

    Pwm_Init(&Pwm_Config);
    while((Adc_GetGroupStatus(7) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }

#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(7, result_7);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC7 test is OK, result is %d\n", result_7[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC7 test is timeout\n");
        }
        PSPRINTF("\nADC7 test is not OK\n");
    }
    Adc_DisableHardwareTrigger(7);
    Pwm_DeInit();
    INTC_LLD_Set_IRQ_Disable(EQADC67_FIFO_1_IRQn);

    PSPRINTF("\nTest8:ADC8 HW ADC_CONV_MODE_ONESHOT CFIFO3 RFIFO0 channel:1(CH1) ADC_RESOLUTION_BIT12 EQADC_HW_PAD15\n");
    SIUL.PCR[PA15].B.IBE = 1U;
    SIUL.PCR[PA15].B.PA = 0x4U;
    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_0_IRQn, ADC89_GRP0);
    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_0_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_0_IRQn);

    Adc_timeout = ADC_TIMEOUT;
    Adc_SetupResultBuffer(8, &resultbuffer[80]);
    Adc_EnableHardwareTrigger(8);
    SIUL.GPDO[PA14].B.PDO = 1;
    Adc_ValueGroupType result_8[20];
    while((Adc_GetGroupStatus(8) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(8, result_8);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC8 test is OK, result is %d\n", result_8[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC8 test is timeout\n");
        }
        PSPRINTF("\nADC8 test is not OK\n");
    }
    Adc_DisableHardwareTrigger(8);
    INTC_LLD_Set_IRQ_Disable(EQADC89_FIFO_0_IRQn);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    PSPRINTF("\nTest9:ADC9 SW ADC_CONV_MODE_ONESHOT CFIFO4 RFIFO3 channel:3(CH4 CH5 CH6) ADC_RESOLUTION_BIT12\n");
    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_3_IRQn, ADC89_GRP3);
    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_3_IRQn, INTR_PRI_10);
    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_3_IRQn);
    Adc_SetupResultBuffer(9, &resultbuffer[90]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(9);
    Adc_ValueGroupType result_9[20];
    while((Adc_GetGroupStatus(9) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(9, result_9);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC9 test is OK\n");
        for(i = 0; i < Adc_Config.Adc_GroupConfig[9].ChannelCount; i++)
        {
            PSPRINTF("result buffer[%d] is %d\n", i, result_9[i]);
        }
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC9 test is timeout\n");
        }
        PSPRINTF("\nADC9 test is not OK\n");
    }

    //Adc_StopGroupConversion(9);
    INTC_LLD_Set_IRQ_Disable(EQADC89_FIFO_3_IRQn);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
    PSPRINTF("\nTest10:ADC10 HW ADC_CONV_MODE_ONESHOT CFIFO2 RFIFO0 channel:1(CH0) ADC_RESOLUTION_BIT12 EQADC_HW_TRIG_GTM_TRIG0_MEMBER0\n");
    INTC_LLD_Set_IRQ_Handle(EQADC1011_FIFO_0_IRQn, ADC1011_GRP0);
    INTC_LLD_Set_IRQ_Priority(EQADC1011_FIFO_0_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC1011_FIFO_0_IRQn);
    Adc_SetupResultBuffer(10, &resultbuffer[100]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_EnableHardwareTrigger(10);

    Adc_ValueGroupType result_10[20];
    Pwm_Init(&Pwm_Config);
    while((Adc_GetGroupStatus(10) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)

    u8Adc_TempReturn = Adc_ReadGroup(10, result_10);

#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC10 test is OK, result is %d\n", result_10[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC10 test is timeout\n");
        }
        PSPRINTF("\nADC10 test is not OK\n");
    }
    Adc_DisableHardwareTrigger(10);
    Pwm_DeInit();
    INTC_LLD_Set_IRQ_Disable(EQADC1011_FIFO_0_IRQn);

#endif

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    PSPRINTF("\nTest11:ADC11 SW ADC_CONV_MODE_ONESHOT CFIFO3 RFIFO1 channel:1(CH0) ADC_RESOLUTION_BIT10\n");
    INTC_LLD_Set_IRQ_Handle(EQADC1011_FIFO_1_IRQn, ADC1011_GRP1);
    INTC_LLD_Set_IRQ_Priority(EQADC1011_FIFO_1_IRQn, INTR_PRI_6);
    INTC_LLD_Set_IRQ_Enable(EQADC1011_FIFO_1_IRQn);
    Adc_SetupResultBuffer(11, &resultbuffer[110]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(11);
    Adc_ValueGroupType result_11[20];
    while((Adc_GetGroupStatus(11) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(11, result_11);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC11 test is OK, result is %d\n", result_11[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC11 test is timeout\n");
        }
        PSPRINTF("\nADC11 test is not OK\n");
    }

    //Adc_StopGroupConversion(11);
    INTC_LLD_Set_IRQ_Disable(EQADC1011_FIFO_1_IRQn);

    PSPRINTF("\nTest12:ADC12 SW ADC_CONV_MODE_ONESHOT CFIFO4 RFIFO2 channel:4(CH0,EQADC_CH_VDD_HV_PMC,EQADC_CH_VDD_HV_FLA,EQADC_CH_VDD_LV) ADC_RESOLUTION_BIT12\n");
    EQADC_LLD_InternalFuncEn();
    (*(vuint32_t *)(0xFFF0C000UL)) = 0x00000001u;
    INTC_LLD_Set_IRQ_Handle(EQADC1213_FIFO_2_IRQn, ADC1213_GRP2);
    INTC_LLD_Set_IRQ_Priority(EQADC1213_FIFO_2_IRQn, INTR_PRI_10);
    INTC_LLD_Set_IRQ_Enable(EQADC1213_FIFO_2_IRQn);
    Adc_SetupResultBuffer(12, &resultbuffer[120]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(12);
    Adc_ValueGroupType result_12[20];
    while((Adc_GetGroupStatus(12) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(12, result_12);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC12 test is OK\n");
        for(i = 0; i < Adc_Config.Adc_GroupConfig[12].ChannelCount; i++)
        {
            PSPRINTF("result buffer[%d] is %d\n", i, result_12[i]);
        }
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC12 test is timeout\n");
        }
        PSPRINTF("\nADC12 test is not OK\n");
    }

    //Adc_StopGroupConversion(12);
    INTC_LLD_Set_IRQ_Disable(EQADC1213_FIFO_5_IRQn);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
    PSPRINTF("\n===============================================DEMO END================================================\n");
}

volatile uint8 eqadc_rsltCallback_counter_2;
volatile uint8 eqadc_rsltCallback_counter_3;

extern volatile uint8 resolver2msDoneCounter;
extern Adc_ValueGroupType resultForFOC2_0[ADC_CONFIG_GROUPS/2][10];
extern Adc_ValueGroupType resultForFOC2_1[ADC_CONFIG_GROUPS/2][10];
extern Adc_ValueGroupType resultForBusA[10];
extern Adc_ValueGroupType resultForBusB[10];



void Eqadc4_Adc8_RsltCallback(const  void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
{
    (void) parameter; /* PRQA S 3119 */
    (void) status; /* PRQA S 3119 */
    (void) mappedChannel;
    eqadc_rsltCallback_counter_2++;

//    if(eqadc_rsltCallback_counter_2 < 5)
//    {
// 	   return;
//    }

//	if( (eqadc_rsltCallback_counter_2 & 0x1) == 1)
	{
#if(MOTOR_LEFT_EN == MOTOR_ENABLE)

		SIUL.GPDO[PC7].R = 1;

		foc_do_0();

//		IPhDmaCbFunction_P1();

		SIUL.GPDO[PC7].R = 0;

#endif	//(MOTOR_LEFT_EN == MOTOR_ENABLE)
	}

}

void Eqadc4_Adc9_RsltCallback(const  void *parameter, eDMAChnStatusType status, uint8 mappedChannel)
{
    (void) parameter; /* PRQA S 3119 */
    (void) status; /* PRQA S 3119 */
    (void) mappedChannel;
    eqadc_rsltCallback_counter_3++;

//    if(eqadc_rsltCallback_counter_3<5)
//    {
// 	   return;
//    }

//	if( (eqadc_rsltCallback_counter_3 & 0x1) == 1)
	{
#if(MOTOR_RIGHT_EN == MOTOR_ENABLE)

		SIUL.GPDO[PQ6].R = 1;

		foc_do_1();

//		IPhDmaCbFunction_P3();

		SIUL.GPDO[PQ6].R = 0;
#endif	//(MOTOR_RIGHT_EN == MOTOR_ENABLE)
	}

}

#include "eDma.h"
EDMA_PB_CONFIG_DECLARATION
void ADC_demo_Dma(void)
{
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON || ADC_HW_TRIGGER_API == STD_ON)
    uint32 Adc_timeout = ADC_TIMEOUT;
#endif
#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
#endif
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    uint32 i = 0;
#endif
    Adc_Init(&Adc_Config);

    SIUL.PCR[PA14].B.OBE = 1;
    SIUL.GPDO[PA14].B.PDO = 0;
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    PSPRINTF("\n===========================================DMA DEMO TEST===============================================\n");
    PSPRINTF("\nTest0:ADC0 SW ADC_CONV_MODE_ONESHOT CFIFO0 RFIFO1 channel:1(CH2) ADC_RESOLUTION_BIT12 DMA:CH2 CH3\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH2_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH3_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH2_IRQn, &EDMA_Ch2_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH3_IRQn, &EDMA_Ch3_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH2_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH3_IRQn);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(0);
    Adc_ValueGroupType result_0[20];
    while((Adc_GetGroupStatus(0) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(0, result_0);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC0 test is OK, result is %d\n", result_0[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC0 test is timeout\n");
        }
        PSPRINTF("\nADC0 test is not OK\n");
    }
    //Adc_StopGroupConversion(0);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH2_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH3_IRQn);

    PSPRINTF("\nTest1:ADC1 SW ADC_CONV_MODE_ONESHOT CFIFO1 RFIFO2 channel:1(CH0) ADC_RESOLUTION_BIT10 DMA:CH4 CH5\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH4_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH5_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH4_IRQn, &EDMA_Ch4_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH5_IRQn, &EDMA_Ch5_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH4_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH5_IRQn);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(1);
    Adc_ValueGroupType result_1[20];
    while((Adc_GetGroupStatus(1) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(1, result_1);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC1 test is OK, result is %d\n", result_1[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC1 test is timeout\n");
        }
        PSPRINTF("\nADC1 test is not OK\n");
    }
    //Adc_StopGroupConversion(1);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH4_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH5_IRQn);

    PSPRINTF("\nTest2:ADC2 SW ADC_CONV_MODE_ONESHOT CFIFO2 RFIFO3 channel:1(CH0) ADC_RESOLUTION_BIT12 DMA:CH16 CH17\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH16_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH17_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH16_IRQn, &EDMA_Ch16_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH17_IRQn, &EDMA_Ch17_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH16_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH17_IRQn);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(2);
    Adc_ValueGroupType result_2[20];
    while((Adc_GetGroupStatus(2) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(2, result_2);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC2 test is OK, result is %d\n", result_2[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC2 test is timeout\n");
        }
        PSPRINTF("\nADC2 test is not OK\n");
    }
    //Adc_StopGroupConversion(2);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH16_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH17_IRQn);

    PSPRINTF("\nTest3:ADC3 SW ADC_CONV_MODE_ONESHOT CFIFO4 RFIFO5 channel:1(CH0) ADC_RESOLUTION_BIT10 DMA:CH18 CH19\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH18_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH19_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH18_IRQn, &EDMA_Ch18_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH19_IRQn, &EDMA_Ch19_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH18_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH19_IRQn);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(3);
    Adc_ValueGroupType result_3[20];
    while((Adc_GetGroupStatus(3) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(3, result_3);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC3 test is OK, result is %d\n", result_3[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC3 test is timeout\n");
        }
        PSPRINTF("\nADC3 test is not OK\n");
    }
    //Adc_StopGroupConversion(3);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH18_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH19_IRQn);

    PSPRINTF("\nTest4:ADC4 SW ADC_CONV_MODE_CONTINUOUS CFIFO0 RFIFO0 channel:1(CH0) ADC_RESOLUTION_BIT12 DMA:CH24 CH25\n");
//    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH24_IRQ77, INTR_PRI_7);
//  (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH25_IRQ78, INTR_PRI_8);
//  (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH24_IRQ77, &EDMA_Ch24_IRQHandler);
//  (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH25_IRQ78, &EDMA_Ch25_IRQHandler);
//  (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH24_IRQ77);
//  (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH25_IRQ78);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(4);
    for(uint32 i = 0U; i < 100000U; i++);
    Adc_ValueGroupType result_4[20];
    for(i = 0U; i < 10U; i++)
    {
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(4, result_4);
#endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\n conv: %d ,ADC4 test is OK, result is %d\n", i, result_4[0]);
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\nADC4 test is timeout\n");
            }
            PSPRINTF("\nADC4 test is not OK\n");
        }
    }
    Adc_StopGroupConversion(4);
//    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH24_IRQ77);
//  (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH25_IRQ78);

    PSPRINTF("\nTest5:ADC5 SW ADC_CONV_MODE_CONTINUOUS CFIFO2 RFIFO1 channel:1(CH0) ADC_RESOLUTION_BIT10 DMA:CH26 CH27\n");
//    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH26_IRQ79, INTR_PRI_7);
//  (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH27_IRQ80, INTR_PRI_8);
//  (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH26_IRQ79, &EDMA_Ch26_IRQHandler);
//  (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH27_IRQ80, &EDMA_Ch27_IRQHandler);
//  (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH26_IRQ79);
//  (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH27_IRQ80);
    Adc_SetupResultBuffer(5, &resultbuffer[50]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(5);
    for(uint32 i = 0U; i < 100000U; i++);
    Adc_ValueGroupType result_5[20];
    for(i = 0U; i < 10U; i++)
    {
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(5, result_5);
#endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\n conv: %d ,ADC5 test is OK, result is %d\n", i, result_5[0]);
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\nADC5 test is timeout\n");
            }
            PSPRINTF("\nADC5 test is not OK\n");
        }
    }
    Adc_StopGroupConversion(5);
//    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH26_IRQ79);
//  (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH27_IRQ80);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#if (ADC_HW_TRIGGER_API == STD_ON)
   PSPRINTF("\nTest6:ADC6 HW ADC_CONV_MODE_ONESHOT CFIFO1 RFIFO0 channel:1(CH0) ADC_RESOLUTION_BIT12 EQADC_HW_PAD15 DMA:CH32 CH33\n");
   SIUL.PCR[PA15].B.IBE = 1U;
   SIUL.PCR[PA15].B.PA = 0x4U;
   (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH32_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH33_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH32_IRQn, &EDMA_Ch32_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH33_IRQn, &EDMA_Ch33_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH32_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH33_IRQn);
   Adc_SetupResultBuffer(6, &resultbuffer[60]);
   Adc_timeout = ADC_TIMEOUT;
   Adc_EnableHardwareTrigger(6);
   SIUL.GPDO[PA14].B.PDO = 1;
   Adc_ValueGroupType result_6[20];
   while((Adc_GetGroupStatus(6) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
   u8Adc_TempReturn = Adc_ReadGroup(6, result_6);
#endif
   if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
   {
       PSPRINTF("\nADC6 test is OK, result is %d\n", result_6[0]);
   }
   else
   {
       if(Adc_timeout == 0)
       {
           PSPRINTF("\nADC6 test is timeout\n");
       }
       PSPRINTF("\nADC6 test is not OK\n");
   }
   Adc_DisableHardwareTrigger(6);
   (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH32_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH33_IRQn);

    PSPRINTF("\nTest7:ADC7 HW ADC_CONV_MODE_ONESHOT CFIFO2 RFIFO1 channel:1(CH0) ADC_RESOLUTION_BIT12 EQADC_HW_TRIG_EMIOS0_CH16 DMA:CH34 CH35\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH34_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH35_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH34_IRQn, &EDMA_Ch34_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH35_IRQn, &EDMA_Ch35_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH34_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH35_IRQn);
    Adc_SetupResultBuffer(7, &resultbuffer[70]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_EnableHardwareTrigger(7);
    Adc_ValueGroupType result_7[20];

   Pwm_Init(&Pwm_Config);

    while((Adc_GetGroupStatus(7) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }

#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(7, result_7);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC7 test is OK, result is %d\n", result_7[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC7 test is timeout\n");
        }
        PSPRINTF("\nADC7 test is not OK\n");
    }
    Adc_DisableHardwareTrigger(7);
    Pwm_DeInit();
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH34_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH35_IRQn);

   PSPRINTF("\nTest8:ADC8 HW ADC_CONV_MODE_ONESHOT CFIFO3 RFIFO0 channel:1(CH1) ADC_RESOLUTION_BIT12 EQADC_HW_TRIG_PIT0_CH0 DMA:CH48 CH49\n");
   (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH48_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH49_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH48_IRQn, &EDMA_Ch48_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH49_IRQn, &EDMA_Ch49_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH48_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH49_IRQn);
   Gpt_Init(&GptChannelConfigSet);
   Adc_timeout = ADC_TIMEOUT;
   Adc_SetupResultBuffer(8, &resultbuffer[80]);
   Adc_EnableHardwareTrigger(8);
   Adc_ValueGroupType result_8[20];
   Gpt_StartTimer(5, 10000);
   while((Adc_GetGroupStatus(8) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
   u8Adc_TempReturn = Adc_ReadGroup(8, result_8);
#endif
   if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
   {
       PSPRINTF("\nADC8 test is OK, result is %d\n", result_8[0]);
   }
   else
   {
       if(Adc_timeout == 0)
       {
           PSPRINTF("\nADC8 test is timeout\n");
       }
       PSPRINTF("\nADC8 test is not OK\n");
   }
   Adc_DisableHardwareTrigger(8);
   Gpt_StopTimer(5);
   (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH48_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH49_IRQn);
    Gpt_DeInit();
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    PSPRINTF("\nTest9:ADC9 SW ADC_CONV_MODE_ONESHOT CFIFO4 RFIFO3 channel:3(CH4 CH5 CH6) ADC_RESOLUTION_BIT12 DMA:CH50 CH51\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH50_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH51_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH50_IRQn, &EDMA_Ch50_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH51_IRQn, &EDMA_Ch51_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH50_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH51_IRQn);
    Adc_SetupResultBuffer(9, &resultbuffer[90]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(9);
    Adc_ValueGroupType result_9[20];
    while((Adc_GetGroupStatus(9) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(9, result_9);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC9 test is OK\n");
        for(i = 0; i < Adc_Config.Adc_GroupConfig[9].ChannelCount; i++)
        {
            PSPRINTF("result buffer[%d] is %d\n", i, result_9[i]);
        }
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC9 test is timeout\n");
        }
        PSPRINTF("\nADC9 test is not OK\n");
    }

    //Adc_StopGroupConversion(9);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH50_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH51_IRQn);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
PSPRINTF("\nTest10:ADC10 HW ADC_CONV_MODE_ONESHOT CFIFO2 RFIFO0 channel:1(CH0) ADC_RESOLUTION_BIT12 EQADC_HW_TRIG_GTM_TRIG0_MEMBER0 DMA:CH120 CH121\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH56_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH57_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH56_IRQn, &EDMA_Ch120_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH57_IRQn, &EDMA_Ch121_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH56_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH57_IRQn);

    Adc_timeout = ADC_TIMEOUT;
    Adc_SetupResultBuffer(10, &resultbuffer[100]);
    Adc_EnableHardwareTrigger(10);

    Adc_ValueGroupType result_10[20];
    Pwm_Init(&Pwm_Config);

    while((Adc_GetGroupStatus(10) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
     {
         Adc_timeout--;
     }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(10, result_10);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC10 test is OK, result is %d\n", result_10[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC10 test is timeout\n");
        }
        PSPRINTF("\nADC10 test is not OK\n");
    }
    Adc_DisableHardwareTrigger(10);
    (void) INTC_LLD_Set_IRQ_Disable(DMA1_CH56_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA1_CH57_IRQn);
    Pwm_DeInit();
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    PSPRINTF("\nTest11:ADC11 SW ADC_CONV_MODE_ONESHOT CFIFO3 RFIFO1 channel:1(CH0) ADC_RESOLUTION_BIT12 DMA:CH122 CH123\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH58_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH59_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH58_IRQn, &EDMA_Ch122_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH59_IRQn, &EDMA_Ch123_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH58_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH59_IRQn);
    Adc_SetupResultBuffer(11, &resultbuffer[110]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(11);
    Adc_ValueGroupType result_11[20];
    while((Adc_GetGroupStatus(11) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(11, result_11);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC11 test is OK, result is %d\n", result_11[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC11 test is timeout\n");
        }
        PSPRINTF("\nADC11 test is not OK\n");
    }
    //Adc_StopGroupConversion(11);
    (void) INTC_LLD_Set_IRQ_Disable(DMA1_CH58_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA1_CH59_IRQn);

    PSPRINTF("\nTest12:ADC12 SW ADC_CONV_MODE_ONESHOT CFIFO4 RFIFO2 channel:4(CH0,EQADC_CH_VDD_HV_PMC,EQADC_CH_VDD_HV_FLA,EQADC_CH_VDD_LV) ADC_RESOLUTION_BIT12 DMA:CH124 CH125\n");
    EQADC_LLD_InternalFuncEn();
    (*(vuint32_t *)(0xFFF0C000UL)) = 0x00000001u;
    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH60_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH61_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH60_IRQn, &EDMA_Ch124_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH61_IRQn, &EDMA_Ch125_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH60_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH61_IRQn);
    Adc_SetupResultBuffer(12, &resultbuffer[120]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(12);
    Adc_ValueGroupType result_12[20];
    while((Adc_GetGroupStatus(12) != ADC_STREAM_COMPLETED) && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(12, result_12);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC12 test is OK\n");
        for(i = 0; i < Adc_Config.Adc_GroupConfig[12].ChannelCount; i++)
        {
            PSPRINTF("result buffer[%d] is %d\n", i, result_12[i]);
        }
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC12 test is timeout\n");
        }
        PSPRINTF("\nADC12 test is not OK\n");
    }

    //Adc_StopGroupConversion(9);
    (void) INTC_LLD_Set_IRQ_Disable(DMA1_CH60_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA1_CH61_IRQn);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
    PSPRINTF("\n===============================================DEMO END================================================\n");
}

void ADC_demo_Int_Dma(void)
{
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON || ADC_HW_TRIGGER_API == STD_ON)
    uint32 Adc_timeout = ADC_TIMEOUT;
#endif
#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
#endif
    Adc_Init(&Adc_Config);

    SIUL.PCR[PA14].B.OBE = 1;
    SIUL.GPDO[PA14].B.PDO = 0;
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    uint32 i = 0U;
    PSPRINTF("\n==========================================INT DMA DEMO TEST=============================================\n");
    PSPRINTF("\nTest0:ADC0 SW ADC_CONV_MODE_ONESHOT CFIFO0 RFIFO1 channel:1(CH2) ADC_RESOLUTION_BIT12\n");
    INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_1_IRQn, ADC01_GRP1);
    INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_1_IRQn, INTR_PRI_8);
    INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_1_IRQn);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(0);
    Adc_ValueGroupType result_0[20];
    while((Adc_GetGroupStatus(0) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(0, result_0);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC0 test is OK, result is %d\n", result_0[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC0 test is timeout\n");
        }
        PSPRINTF("\nADC0 test is not OK\n");
    }
    //Adc_StopGroupConversion(0);
    INTC_LLD_Set_IRQ_Disable(EQADC01_FIFO_1_IRQn);

    PSPRINTF("\nTest1:ADC1 SW ADC_CONV_MODE_ONESHOT CFIFO1 RFIFO2 channel:1(CH0) ADC_RESOLUTION_BIT12 DMA:CH4 CH5\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH4_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH5_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH4_IRQn, &EDMA_Ch4_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH5_IRQn, &EDMA_Ch5_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH4_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH5_IRQn);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(1);
    Adc_ValueGroupType result_1[20];
    while((Adc_GetGroupStatus(1) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(1, result_1);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC1 test is OK, result is %d\n", result_1[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC1 test is timeout\n");
        }
        PSPRINTF("\nADC1 test is not OK\n");
    }
    //Adc_StopGroupConversion(1);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH4_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH5_IRQn);

    PSPRINTF("\nTest2:ADC2 SW ADC_CONV_MODE_ONESHOT CFIFO2 RFIFO3 channel:1(CH0) ADC_RESOLUTION_BIT12\n");
    INTC_LLD_Set_IRQ_Handle(EQADC23_FIFO_3_IRQn, ADC23_GRP3);
    INTC_LLD_Set_IRQ_Priority(EQADC23_FIFO_3_IRQn, INTR_PRI_10);
    INTC_LLD_Set_IRQ_Enable(EQADC23_FIFO_3_IRQn);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(2);
    Adc_ValueGroupType result_2[20];
    while((Adc_GetGroupStatus(2) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(2, result_2);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC2 test is OK, result is %d\n", result_2[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC2 test is timeout\n");
        }
        PSPRINTF("\nADC2 test is not OK\n");
    }
    //Adc_StopGroupConversion(2);
    INTC_LLD_Set_IRQ_Disable(EQADC23_FIFO_3_IRQn);

    PSPRINTF("\nTest3:ADC3 SW ADC_CONV_MODE_ONESHOT CFIFO4 RFIFO5 channel:1(CH0) ADC_RESOLUTION_BIT12 DMA:CH18 CH19\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH18_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH19_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH18_IRQn, &EDMA_Ch18_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH19_IRQn, &EDMA_Ch19_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH18_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH19_IRQn);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(3);
    Adc_ValueGroupType result_3[20];
    while((Adc_GetGroupStatus(3) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(3, result_3);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC3 test is OK, result is %d\n", result_3[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC3 test is timeout\n");
        }
        PSPRINTF("\nADC3 test is not OK\n");
    }
    //Adc_StopGroupConversion(3);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH18_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH19_IRQn);

    PSPRINTF("\nTest4:ADC4 SW ADC_CONV_MODE_CONTINUOUS CFIFO0 RFIFO0 channel:1(CH0) ADC_RESOLUTION_BIT12\n");
    INTC_LLD_Set_IRQ_Handle(EQADC45_FIFO_0_IRQn, ADC45_GRP0);
    INTC_LLD_Set_IRQ_Priority(EQADC45_FIFO_0_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC45_FIFO_0_IRQn);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(4);
    for(uint32 i = 0U; i < 100000U; i++);
    Adc_ValueGroupType result_4[20];
    for(i = 0U; i < 10U; i++)
    {
    #if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(4, result_4);
    #endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\n conv: %d ,ADC4 test is OK, result is %d\n", i, result_4[0]);
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\nADC4 test is timeout\n");
            }
            PSPRINTF("\nADC4 test is not OK\n");
        }
    }
    Adc_StopGroupConversion(4);
    INTC_LLD_Set_IRQ_Disable(EQADC45_FIFO_0_IRQn);

    PSPRINTF("\nTest5:ADC5 SW ADC_CONV_MODE_CONTINUOUS CFIFO2 RFIFO1 channel:1(CH0) ADC_RESOLUTION_BIT12 DMA:CH26 CH27\n");
//    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH26_IRQ79, INTR_PRI_7);
//  (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH27_IRQ80, INTR_PRI_8);
//  (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH26_IRQ79, &EDMA_Ch26_IRQHandler);
//  (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH27_IRQ80, &EDMA_Ch27_IRQHandler);
//  (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH26_IRQ79);
//  (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH27_IRQ80);
    Adc_SetupResultBuffer(5, &resultbuffer[50]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(5);
    for(uint32 i = 0U; i < 100000U; i++);
    Adc_ValueGroupType result_5[20];
    for(i = 0U; i < 10U; i++)
    {
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(5, result_5);
#endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\n conv: %d ,ADC5 test is OK, result is %d\n", i, result_5[0]);
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\nADC5 test is timeout\n");
            }
            PSPRINTF("\nADC5 test is not OK\n");
        }
    }
    Adc_StopGroupConversion(5);
//    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH26_IRQ79);
//  (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH27_IRQ80);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#if (ADC_HW_TRIGGER_API == STD_ON)
    PSPRINTF("\nTest6:ADC6 HW ADC_CONV_MODE_ONESHOT CFIFO1 RFIFO0 channel:1(CH0) ADC_RESOLUTION_BIT12 EQADC_HW_PAD15\n");
    SIUL.PCR[PA15].B.IBE = 1U;
    SIUL.PCR[PA15].B.PA = 0x4U;
    INTC_LLD_Set_IRQ_Handle(EQADC67_FIFO_0_IRQn, ADC67_GRP0);
    INTC_LLD_Set_IRQ_Priority(EQADC67_FIFO_0_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC67_FIFO_0_IRQn);
    Adc_SetupResultBuffer(6, &resultbuffer[60]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_EnableHardwareTrigger(6);
    Adc_ValueGroupType result_6[20];
    SIUL.GPDO[PA14].B.PDO = 1;
    while((Adc_GetGroupStatus(6) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(6, result_6);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC6 test is OK, result is %d\n", result_6[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC6 test is timeout\n");
        }
        PSPRINTF("\nADC6 test is not OK\n");
    }
    Adc_DisableHardwareTrigger(6);
    INTC_LLD_Set_IRQ_Disable(EQADC67_FIFO_0_IRQn);

    PSPRINTF("\nTest7:ADC7 HW ADC_CONV_MODE_ONESHOT CFIFO2 RFIFO1 channel:1(CH0) ADC_RESOLUTION_BIT12 EQADC_HW_TRIG_EMIOS0_CH16 DMA:CH34 CH35\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH34_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH35_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH34_IRQn, &EDMA_Ch34_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH35_IRQn, &EDMA_Ch35_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH34_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH35_IRQn);
    Adc_SetupResultBuffer(7, &resultbuffer[70]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_EnableHardwareTrigger(7);
    Adc_ValueGroupType result_7[20];

    Pwm_Init(&Pwm_Config);
    while((Adc_GetGroupStatus(7) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }

#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(7, result_7);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC7 test is OK, result is %d\n", result_7[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC7 test is timeout\n");
        }
        PSPRINTF("\nADC7 test is not OK\n");
    }
    Adc_DisableHardwareTrigger(7);
    Pwm_DeInit();
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH34_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH35_IRQn);

    PSPRINTF("\nTest8:ADC8 HW ADC_CONV_MODE_ONESHOT CFIFO3 RFIFO0 channel:1(CH1) ADC_RESOLUTION_BIT12 EQADC_HW_TRIG_PIT0_CH0\n");
    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_0_IRQn, ADC89_GRP0);
    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_0_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_0_IRQn);
    Gpt_Init(&GptChannelConfigSet);
    Adc_timeout = ADC_TIMEOUT;
    Adc_SetupResultBuffer(8, &resultbuffer[80]);
    Adc_EnableHardwareTrigger(8);
    Adc_ValueGroupType result_8[20];
    Gpt_StartTimer(5, 10000);
    while((Adc_GetGroupStatus(8) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(8, result_8);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC8 test is OK, result is %d\n", result_8[0]);
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC8 test is timeout\n");
        }
        PSPRINTF("\nADC8 test is not OK\n");
    }
    Adc_DisableHardwareTrigger(8);
    Gpt_StopTimer(5);
    INTC_LLD_Set_IRQ_Disable(EQADC89_FIFO_0_IRQn);
    Gpt_DeInit();
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    PSPRINTF("\nTest9:ADC9 SW ADC_CONV_MODE_ONESHOT CFIFO4 RFIFO3 channel:3(CH4 CH5 CH6) ADC_RESOLUTION_BIT12 DMA:CH50 CH51\n");
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH50_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH51_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH50_IRQn, &EDMA_Ch50_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH51_IRQn, &EDMA_Ch51_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH50_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH51_IRQn);
    Adc_SetupResultBuffer(9, &resultbuffer[90]);
    Adc_timeout = ADC_TIMEOUT;
    Adc_StartGroupConversion(9);
    Adc_ValueGroupType result_9[20];
    while((Adc_GetGroupStatus(9) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(9, result_9);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nADC9 test is OK\n");
        for(i = 0; i < Adc_Config.Adc_GroupConfig[9].ChannelCount; i++)
        {
            PSPRINTF("result buffer[%d] is %d\n", i, result_9[i]);
        }
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nADC9 test is timeout\n");
        }
        PSPRINTF("\nADC9 test is not OK\n");
    }

    //Adc_StopGroupConversion(9);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH50_IRQn);
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH51_IRQn);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

    PSPRINTF("\n===============================================DEMO END================================================\n");
}

void ADC_demo_ExternalMux(void)
{
    uint32 Adc_timeout = ADC_TIMEOUT;
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
    uint32 i = 0U;
    Adc_Init(&Adc_Config);
    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_0_IRQn, ADC89_GRP0);
    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_0_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_0_IRQn);
    Adc_SetupResultBuffer(1, &resultbuffer[0]);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StartGroupConversion(1);
#endif
    Adc_ValueGroupType result_0[20];
    while((Adc_GetGroupStatus(1) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(1, result_0);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nANW test is OK\n");
        for(i = 0; i < Adc_Config.Adc_GroupConfig[1].ChannelCount; i++)
        {
            PSPRINTF("result buffer[%d] is %d\n", i, result_0[i]);
        }
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nANW test is timeout\n");
        }
        PSPRINTF("\nANW test is not OK\n");
    }
    //Adc_StopGroupConversion(1);
    INTC_LLD_Set_IRQ_Disable(EQADC89_FIFO_0_IRQn);

    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_1_IRQn, ADC89_GRP1);
    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_1_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_1_IRQn);
    Adc_SetupResultBuffer(2, &resultbuffer[10]);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StartGroupConversion(2);
#endif
    Adc_ValueGroupType result_1[20];
    while((Adc_GetGroupStatus(2) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(2, result_1);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nANX test is OK\n");
        for(i = 0; i < Adc_Config.Adc_GroupConfig[2].ChannelCount; i++)
        {
            PSPRINTF("result buffer[%d] is %d\n", i, result_1[i]);
        }
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nANX test is timeout\n");
        }
        PSPRINTF("\nANX test is not OK\n");
    }
    //Adc_StopGroupConversion(2);
    INTC_LLD_Set_IRQ_Disable(EQADC89_FIFO_1_IRQn);

    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_2_IRQn, ADC89_GRP2);
    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_2_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_2_IRQn);
    Adc_SetupResultBuffer(3, &resultbuffer[20]);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StartGroupConversion(3);
#endif
    Adc_ValueGroupType result_2[20];
    while((Adc_GetGroupStatus(3) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
    {
        Adc_timeout--;
    }
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(3, result_2);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
    {
        PSPRINTF("\nANY test is OK\n");
        for(i = 0; i < Adc_Config.Adc_GroupConfig[3].ChannelCount; i++)
        {
            PSPRINTF("result buffer[%d] is %d\n", i, result_2[i]);
        }
    }
    else
    {
        if(Adc_timeout == 0)
        {
            PSPRINTF("\nANY test is timeout\n");
        }
        PSPRINTF("\nANY test is not OK\n");
    }
    //Adc_StopGroupConversion(3);
    INTC_LLD_Set_IRQ_Disable(EQADC89_FIFO_2_IRQn);

    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_4_IRQn, ADC89_GRP4);
    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_4_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_4_IRQn);
    Adc_SetupResultBuffer(4, &resultbuffer[30]);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StartGroupConversion(4);
#endif
    for(uint32 i = 0U; i < 100000U; i++);
    Adc_ValueGroupType result_3[20];
    uint32 j = 0U;
    for(i = 0U; i < 10U; i++)
    {
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(4, result_3);
#endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\nconv: %d,ANZ test is OK\n", i);
            for(j = 0; j < Adc_Config.Adc_GroupConfig[4].ChannelCount; j++)
            {
                PSPRINTF("result buffer[%d] is %d\n", j, result_3[j]);
            }
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\nANZ test is timeout\n");
            }
            PSPRINTF("\nANZ test is not OK\n");
        }
    }
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StopGroupConversion(4);
#endif
    INTC_LLD_Set_IRQ_Disable(EQADC89_FIFO_4_IRQn);
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

}

void Group0_Notification(void)
{
    Adc_ValueGroupType result_0[20];
#if (ADC_READ_GROUP_API == STD_ON)
    Adc_ReadGroup(0, result_0);
#endif
    PSPRINTF("group0 is OK, result is %d\n", result_0[0]);
    return;
}

void Group1_Notification(void)
{
    Adc_ValueGroupType result_1[20];
#if (ADC_READ_GROUP_API == STD_ON)
    Adc_ReadGroup(1, result_1);
#endif
    PSPRINTF("group1 is OK, result is %d\n", result_1[0]);
    return;
}

void Group2_Notification(void)
{
    Adc_ValueGroupType result_2[20];
#if (ADC_READ_GROUP_API == STD_ON)
    Adc_ReadGroup(2, result_2);
#endif
    PSPRINTF("group2 is OK, result is %d\n", result_2[0]);
    return;
}

void Group3_Notification(void)
{
    Adc_ValueGroupType result_3[20];
#if (ADC_READ_GROUP_API == STD_ON)
    Adc_ReadGroup(3, result_3);
#endif
    PSPRINTF("group3 is OK, result is %d\n", result_3[0]);
    return;
}

void Group4_Notification(void)
{
    Adc_ValueGroupType result_4[20];
#if (ADC_READ_GROUP_API == STD_ON)
    Adc_ReadGroup(4, result_4);
#endif
    PSPRINTF("group4 is OK, result is %d\n", result_4[0]);
    return;
}

void ADC_demo_PrioQueue(void)
{
    (void) INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_0_IRQn, ADC01_GRP0);
    (void) INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_0_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_0_IRQn);
    (void) INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_1_IRQn, ADC01_GRP1);
    (void) INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_1_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_1_IRQn);
    (void) INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_2_IRQn, ADC01_GRP2);
    (void) INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_2_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_2_IRQn);
    (void) INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_3_IRQn, ADC01_GRP3);
    (void) INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_3_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_3_IRQn);

    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH2_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH3_IRQn, INTR_PRI_8);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH2_IRQn, &EDMA_Ch2_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH3_IRQn, &EDMA_Ch3_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH2_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH3_IRQn);

    PSPRINTF("\nPriority:group0 is 0, group 1 is 1, group 2 is 2, group 3 is 2, group 4 is 3; QueueMaxDepth:10\n");
    PSPRINTF("\nCase 1: start 0 1 2 3 4\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(3);
    Adc_StartGroupConversion(4);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);

//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

    PSPRINTF("\nCase 2: start 2 0 4 1 3\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(4);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(3);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);
//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

    PSPRINTF("\nCase 3: start 2 0 4 1 3 stop 2\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(4);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(3);
    Adc_StopGroupConversion(2);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);
//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

    PSPRINTF("\nCase 4: start 2 0 4 1 3 stop 1\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(4);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(3);
    Adc_StopGroupConversion(1);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);
//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

    PSPRINTF("\nCase 5: start 2 0 4 1 3 stop 3\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(4);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(3);
    Adc_StopGroupConversion(3);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);
//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

    PSPRINTF("\nCase 6: start 2 0 4 1 3 stop 4\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif
#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(4);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(3);
    Adc_StopGroupConversion(4);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);
//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}

void ADC_demo_Queue(void)
{
    (void) INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_0_IRQn, ADC01_GRP0);
    (void) INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_0_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_0_IRQn);
    (void) INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_1_IRQn, ADC01_GRP1);
    (void) INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_1_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_1_IRQn);
    (void) INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_2_IRQn, ADC01_GRP2);
    (void) INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_2_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_2_IRQn);
    (void) INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_3_IRQn, ADC01_GRP3);
    (void) INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_3_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_3_IRQn);

    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH2_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH3_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH2_IRQn, &EDMA_Ch2_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH3_IRQn, &EDMA_Ch3_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH2_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH3_IRQn);

    PSPRINTF("\nQueueMaxDepth:10\n");
    PSPRINTF("\nCase 1: start 0 1 2 3 4\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(3);
    Adc_StartGroupConversion(4);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);

//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

    PSPRINTF("\nCase 2: start 2 0 4 1 3\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif
#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(4);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(3);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);
//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

    PSPRINTF("\nCase 3: start 2 0 4 1 3 stop 1\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(4);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(3);
    Adc_StopGroupConversion(1);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);
//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

    PSPRINTF("\nCase 4: start 2 0 4 1 3 stop 3\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(4);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(3);
    Adc_StopGroupConversion(3);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);
//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif

    PSPRINTF("\nCase 5: start 2 0 4 1 3 stop 4\n");
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(0, &resultbuffer[0]);
    Adc_SetupResultBuffer(1, &resultbuffer[10]);
    Adc_SetupResultBuffer(2, &resultbuffer[20]);
    Adc_SetupResultBuffer(3, &resultbuffer[30]);
    Adc_SetupResultBuffer(4, &resultbuffer[40]);

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
    Adc_EnableGroupNotification(0);
    Adc_EnableGroupNotification(1);
    Adc_EnableGroupNotification(2);
    Adc_EnableGroupNotification(3);
    Adc_EnableGroupNotification(4);
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
    Adc_StartGroupConversion(2);
    Adc_StartGroupConversion(0);
    Adc_StartGroupConversion(4);
    Adc_StartGroupConversion(1);
    Adc_StartGroupConversion(3);
    Adc_StopGroupConversion(4);

    Gpt_Stm_LLD_DelayMs(STM1, 1000U);
//    Adc_StopGroupConversion(0);
//    Adc_StopGroupConversion(1);
//    Adc_StopGroupConversion(2);
//    Adc_StopGroupConversion(3);
//    Adc_StopGroupConversion(4);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}
Adc_ValueGroupType resultForFOC_0[ADC_CONFIG_GROUPS/2][10];
Adc_ValueGroupType resultForFOC_1[ADC_CONFIG_GROUPS/2][10];
#if (ADC_HW_TRIGGER_API == STD_ON)
void ADC_demo_MultiGroup(void)
{
#if (ADC_READ_GROUP_API == STD_ON)
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
#endif
    uint16 i = 0U;
#if (ADC_READ_GROUP_API == STD_ON)
    uint32 j = 0U;
#endif

    SIUL.PCR[PA15].B.IBE = 1U;
    SIUL.PCR[PA15].B.PA = 0x4U;
    SIUL.PCR[PA14].B.OBE = 1;
    SIUL.GPDO[PA14].B.PDO = 0;

//    INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_0_IRQn, ADC01_GRP0);
//    INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_0_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_0_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_1_IRQn, ADC01_GRP1);
//    INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_1_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_1_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_2_IRQn, ADC01_GRP2);
//    INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_2_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_2_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_3_IRQn, ADC01_GRP3);
//    INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_3_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_3_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC01_FIFO_4_IRQn, ADC01_GRP4);
//    INTC_LLD_Set_IRQ_Priority(EQADC01_FIFO_4_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC01_FIFO_4_IRQn);
//
//    INTC_LLD_Set_IRQ_Handle(EQADC23_FIFO_0_IRQn, ADC23_GRP0);
//    INTC_LLD_Set_IRQ_Priority(EQADC23_FIFO_0_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC23_FIFO_0_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC23_FIFO_1_IRQn, ADC23_GRP1);
//    INTC_LLD_Set_IRQ_Priority(EQADC23_FIFO_1_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC23_FIFO_1_IRQn);

//    INTC_LLD_Set_IRQ_Handle(EQADC45_FIFO_0_IRQn, ADC45_GRP0);
//    INTC_LLD_Set_IRQ_Priority(EQADC45_FIFO_0_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC45_FIFO_0_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC45_FIFO_1_IRQn, ADC45_GRP1);
//    INTC_LLD_Set_IRQ_Priority(EQADC45_FIFO_1_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC45_FIFO_1_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC45_FIFO_2_IRQn, ADC45_GRP2);
//    INTC_LLD_Set_IRQ_Priority(EQADC45_FIFO_2_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC45_FIFO_2_IRQn);
//
//    INTC_LLD_Set_IRQ_Handle(EQADC67_FIFO_0_IRQn, ADC67_GRP0);
//    INTC_LLD_Set_IRQ_Priority(EQADC67_FIFO_0_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC67_FIFO_0_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC67_FIFO_2_IRQn, ADC67_GRP2);
//    INTC_LLD_Set_IRQ_Priority(EQADC67_FIFO_2_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC67_FIFO_2_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC67_FIFO_3_IRQn, ADC67_GRP3);
//    INTC_LLD_Set_IRQ_Priority(EQADC67_FIFO_3_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC67_FIFO_3_IRQn);
//
//    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_0_IRQn, ADC89_GRP0);
//    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_0_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_0_IRQn);
////    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_5_IRQn, ADC89_GRP5);
////    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_5_IRQn, INTR_PRI_10);
////    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_5_IRQn);
////    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_2_IRQn, ADC89_GRP2);
////    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_2_IRQn, INTR_PRI_10);
////    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_2_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_1_IRQn, ADC89_GRP1);
//    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_1_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_1_IRQn);

//    INTC_LLD_Set_IRQ_Handle(EQADC1011_FIFO_0_IRQn, ADC1011_GRP0);
//    INTC_LLD_Set_IRQ_Priority(EQADC1011_FIFO_0_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC1011_FIFO_0_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC1011_FIFO_1_IRQn, ADC1011_GRP1);
//    INTC_LLD_Set_IRQ_Priority(EQADC1011_FIFO_1_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC1011_FIFO_1_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC1011_FIFO_2_IRQn, ADC1011_GRP2);
//    INTC_LLD_Set_IRQ_Priority(EQADC1011_FIFO_2_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC1011_FIFO_2_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC1011_FIFO_3_IRQn, ADC1011_GRP3);
//    INTC_LLD_Set_IRQ_Priority(EQADC1011_FIFO_3_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC1011_FIFO_3_IRQn);

//    INTC_LLD_Set_IRQ_Handle(EQADC1213_FIFO_4_IRQn, ADC1213_GRP4);
//    INTC_LLD_Set_IRQ_Priority(EQADC1213_FIFO_4_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC1213_FIFO_4_IRQn);
//    INTC_LLD_Set_IRQ_Handle(EQADC1213_FIFO_5_IRQn, ADC1213_GRP5);
//    INTC_LLD_Set_IRQ_Priority(EQADC1213_FIFO_5_IRQn, INTR_PRI_10);
//    INTC_LLD_Set_IRQ_Enable(EQADC1213_FIFO_5_IRQn);


#if(MOTOR_LEFT_EN == MOTOR_ENABLE)

    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH49_IRQn, INTR_PRI_62);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH49_IRQn, &EDMA_Ch49_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH49_IRQn);

//    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH56_IRQn, INTR_PRI_15);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH56_IRQn, &EDMA_Ch120_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH56_IRQn);
//	(void) INTC_LLD_Set_IRQ_Priority(DMA1_CH57_IRQn, INTR_PRI_1);
//	(void) INTC_LLD_Set_IRQ_Handle(DMA1_CH57_IRQn, &EDMA_Ch121_IRQHandler);
//	(void) INTC_LLD_Set_IRQ_Enable(DMA1_CH57_IRQn);

#endif	//(MOTOR_LEFT_EN == MOTOR_ENABLE)

#if(MOTOR_RIGHT_EN == MOTOR_ENABLE)
//    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH20_IRQn, INTR_PRI_9);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH20_IRQn, &EDMA_Ch20_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH20_IRQn);
//    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH21_IRQn, INTR_PRI_6);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH21_IRQn, &EDMA_Ch21_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH21_IRQn);

//    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH50_IRQn, INTR_PRI_3);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH50_IRQn, &EDMA_Ch50_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH50_IRQn);
//	(void) INTC_LLD_Set_IRQ_Priority(DMA0_CH51_IRQn, INTR_PRI_4);
//	(void) INTC_LLD_Set_IRQ_Handle(DMA0_CH51_IRQn, &EDMA_Ch51_IRQHandler);
//	(void) INTC_LLD_Set_IRQ_Enable(DMA0_CH51_IRQn);

//    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH58_IRQn, INTR_PRI_17);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH58_IRQn, &EDMA_Ch122_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH58_IRQn);
//    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH59_IRQn, INTR_PRI_18);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH59_IRQn, &EDMA_Ch123_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH59_IRQn);
#endif	//(MOTOR_RIGHT_EN == MOTOR_ENABLE)


//    PSPRINTF("\n============================================MULTIGROUP TEST============================================\n");
//    Adc_ValueGroupType result[ADC_CONFIG_GROUPS][10];
    Adc_Init(&Adc_Config);
    for(i = 0U; i < ADC_CONFIG_GROUPS/2; i++)
    {
        Adc_SetupResultBuffer(i*2, &resultbuffer[i*20]);
//        Adc_SetupResultBuffer(i*2+1, &resultbuffer_1[i*20]);
    }
//#if(MOTOR_LEFT_EN == MOTOR_ENABLE)
//    Adc_SetupResultBuffer(0, &resultbuffer[0*10]);
//    Adc_SetupResultBuffer(2, &resultbuffer[1*10]);
//    Adc_SetupResultBuffer(4, &resultbuffer[2*10]);
//#endif	//(MOTOR_LEFT_EN == MOTOR_ENABLE)
//#if(MOTOR_RIGHT_EN == MOTOR_ENABLE)
//    Adc_SetupResultBuffer(1, &resultbuffer_1[0*10]);
//    Adc_SetupResultBuffer(3, &resultbuffer_1[1*10]);
//    Adc_SetupResultBuffer(5, &resultbuffer_1[2*10]);
//#endif	//(MOTOR_RIGHT_EN == MOTOR_ENABLE)
#if (ADC_HW_TRIGGER_API == STD_ON)
#if(MOTOR_LEFT_EN == MOTOR_ENABLE)
    Adc_EnableHardwareTrigger(0);
    Adc_EnableHardwareTrigger(2);
    Adc_EnableHardwareTrigger(4);
    Adc_EnableHardwareTrigger(6);
#endif	//(MOTOR_LEFT_EN == MOTOR_ENABLE)
#if(MOTOR_RIGHT_EN == MOTOR_ENABLE)
//    Adc_EnableHardwareTrigger(1);
//    Adc_EnableHardwareTrigger(3);
//    Adc_EnableHardwareTrigger(5);
#endif	//(MOTOR_RIGHT_EN == MOTOR_ENABLE)
//    Adc_EnableHardwareTrigger(8);
//    Adc_EnableHardwareTrigger(11);
////    Adc_EnableHardwareTrigger(14);
////    Adc_EnableHardwareTrigger(18);
//    Adc_EnableHardwareTrigger(20);
//    Adc_EnableHardwareTrigger(22);
    SIUL.GPDO[PA14].B.PDO = 1;
#endif
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
//    Adc_StartGroupConversion(0);
//    Adc_StartGroupConversion(1);
//    Adc_StartGroupConversion(2);
//    Adc_StartGroupConversion(3);
//    Adc_StartGroupConversion(4);
//    Adc_StartGroupConversion(5);
//    Adc_StartGroupConversion(6);
//    Adc_StartGroupConversion(7);
//    Adc_StartGroupConversion(9);
//    Adc_StartGroupConversion(10);
//    Adc_StartGroupConversion(12);
//    Adc_StartGroupConversion(13);
//    Adc_StartGroupConversion(15);
//    Adc_StartGroupConversion(16);
//    Adc_StartGroupConversion(17);
//    Adc_StartGroupConversion(19);
//    Adc_StartGroupConversion(21);
//
//    Adc_StartGroupConversion(14);
//    Adc_StartGroupConversion(18);
#endif
//    Pwm_Init(&Pwm_Config);

    for(i = 0U; i < 10000U; i++);

    for(i = 0U; i < ADC_CONFIG_GROUPS/2; i++)
    {
        memset(&resultForFOC_0[i][0], 0, 10U);
        memset(&resultForFOC_1[i][0], 0, 10U);
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(i, &resultForFOC_0[i][0]);
        u8Adc_TempReturn = Adc_ReadGroup(i, &resultForFOC_1[i][0]);
        if(u8Adc_TempReturn == E_OK)
        {
            for(j = 0; j < Adc_Config.Adc_GroupConfig[i].ChannelCount; j++)
            {
                if(resultForFOC_0[i][j] != 0)
                {
//                    PSPRINTF("\ngroup %d is ok\n", i);
//                    PSPRINTF("\nresult_adc[%d][%d] is %d\n", i, j, resultForFOC[i][j]);
                }
                else
                {
//                    PSPRINTF("\ngroup %d is not ok\n", i);
                }
            }
        }
#endif
    }

//    Adc_DisableHardwareTrigger(1);
//    Adc_DisableHardwareTrigger(3);
//    Adc_DisableHardwareTrigger(8);
//    Adc_DisableHardwareTrigger(11);
//    Adc_DisableHardwareTrigger(14);
//    Adc_DisableHardwareTrigger(18);
//    Adc_DisableHardwareTrigger(20);
//    Adc_DisableHardwareTrigger(22);
//
//    Pwm_DeInit();
//#if (ADC_DEINIT_API == STD_ON)
//    Adc_DeInit();
//#endif
//    PSPRINTF("\n===============================================DEMO END================================================\n");
}

void ADC_demo_MultiGroup_2(void)
{

#if(MOTOR_RIGHT_EN == MOTOR_ENABLE)

#if (ADC_READ_GROUP_API == STD_ON)
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
#endif
    uint16 i = 0U;
#if (ADC_READ_GROUP_API == STD_ON)
    uint32 j = 0U;
#endif

//    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH20_IRQn, INTR_PRI_9);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH20_IRQn, &EDMA_Ch20_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH20_IRQn);
//    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH21_IRQn, INTR_PRI_6);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH21_IRQn, &EDMA_Ch21_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH21_IRQn);

//    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH50_IRQn, INTR_PRI_3);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH50_IRQn, &EDMA_Ch50_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH50_IRQn);
	(void) INTC_LLD_Set_IRQ_Priority(DMA0_CH51_IRQn, INTR_PRI_4);
	(void) INTC_LLD_Set_IRQ_Handle(DMA0_CH51_IRQn, &EDMA_Ch51_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Enable(DMA0_CH51_IRQn);

//    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH58_IRQn, INTR_PRI_17);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH58_IRQn, &EDMA_Ch122_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH58_IRQn);
//    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH59_IRQn, INTR_PRI_18);
//    (void) INTC_LLD_Set_IRQ_Handle(DMA1_CH59_IRQn, &EDMA_Ch123_IRQHandler);
//    (void) INTC_LLD_Set_IRQ_Enable(DMA1_CH59_IRQn);

//    Adc_Init(&Adc_Config);

    for(i = 0U; i < ADC_CONFIG_GROUPS/2; i++)
    {
        Adc_SetupResultBuffer(i*2, &resultbuffer[i*10]);
        Adc_SetupResultBuffer(i*2+1, &resultbuffer_1[i*10]);
    }
//    Adc_SetupResultBuffer(1, &resultbuffer_1[0*10]);
//    Adc_SetupResultBuffer(3, &resultbuffer_1[1*10]);
//    Adc_SetupResultBuffer(5, &resultbuffer_1[2*10]);


    Adc_EnableHardwareTrigger(1);
    Adc_EnableHardwareTrigger(3);
    Adc_EnableHardwareTrigger(5);

    for(i = 0U; i < 10000U; i++);

    for(i = 0U; i < ADC_CONFIG_GROUPS/2; i++)
    {
        memset(&resultForFOC_0[i][0], 0, 10U);
        memset(&resultForFOC_1[i][0], 0, 10U);
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(i, &resultForFOC_0[i][0]);
        u8Adc_TempReturn = Adc_ReadGroup(i, &resultForFOC_1[i][0]);
        if(u8Adc_TempReturn == E_OK)
        {
            for(j = 0; j < Adc_Config.Adc_GroupConfig[i].ChannelCount; j++)
            {
                if(resultForFOC_0[i][j] != 0)
                {
//                    PSPRINTF("\ngroup %d is ok\n", i);
//                    PSPRINTF("\nresult_adc[%d][%d] is %d\n", i, j, resultForFOC[i][j]);
                }
                else
                {
//                    PSPRINTF("\ngroup %d is not ok\n", i);
                }
            }
        }
#endif
    }

#endif	//(MOTOR_RIGHT_EN == MOTOR_ENABLE)
}
#endif

void ADC_GPT_Callback_10ms_Function(void)
{
    static uint32 Adc_timeout_10ms[ADC_CORE_NUM] = {ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT};
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StartGroupConversion(0);
#endif
    Adc_ValueGroupType result_0[20];
    Gpt_Stm_LLD_DelayMs(STM1, 5U);
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(0, result_0);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout_10ms[0] > 0U))
    {
        PSPRINTF("\nADC0 result is %d\n", result_0[0]);
    }
    else
    {
        if(Adc_timeout_10ms[0] == 0)
        {
            PSPRINTF("\nADC0 is timeout\n");
        }
        PSPRINTF("\nADC0 is not OK\n");
    }
}

void ADC_GPT_Callback_20ms_Function(void)
{
    static uint32 Adc_timeout_20ms[ADC_CORE_NUM] = {ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT};
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StartGroupConversion(5);
#endif
    Adc_ValueGroupType result_5[20];
    Gpt_Stm_LLD_DelayMs(STM1, 1U);
#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(5, result_5);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout_20ms[0] > 0U))
    {
        PSPRINTF("\nADC5 result is %d\n", result_5[0]);
    }
    else
    {
        if(Adc_timeout_20ms[0] == 0)
        {
            PSPRINTF("\nADC5 is timeout\n");
        }
        PSPRINTF("\nADC5 is not OK\n");
    }
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StopGroupConversion(5);
#endif
}

void ADC_GPT_Callback_30ms_Function(void)
{
    static uint32 Adc_timeout_30ms[ADC_CORE_NUM] = {ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT, ADC_TIMEOUT};
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
    SIUL.PCR[PA15].B.IBE = 1U;
    SIUL.PCR[PA15].B.PA = 0x4U;
#if (STD_ON == ADC_HW_TRIGGER_API)
    Adc_EnableHardwareTrigger(6);
    SIUL.GPDO[PA14].B.PDO = 1;
#endif
    Adc_ValueGroupType result_6[20];
    Gpt_Stm_LLD_DelayMs(STM1, 1U);

#if (ADC_READ_GROUP_API == STD_ON)
    u8Adc_TempReturn = Adc_ReadGroup(6, result_6);
#endif
    if((u8Adc_TempReturn == E_OK) && (Adc_timeout_30ms[0] > 0U))
    {
        PSPRINTF("\nADC6 result is %d\n", result_6[0]);
    }
    else
    {
        if(Adc_timeout_30ms[0] == 0)
        {
            PSPRINTF("\nADC6 is timeout\n");
        }
        PSPRINTF("\nADC6 is not OK\n");
    }
#if (STD_ON == ADC_HW_TRIGGER_API)
    Adc_DisableHardwareTrigger(6);
#endif
}

void ADC_0323(void)
{
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    uint32 Adc_timeout = ADC_TIMEOUT;
#endif
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;

    Adc_Init(&Adc_Config);
    INTC_LLD_Set_IRQ_Handle(EQADC23_FIFO_3_IRQn, ADC23_GRP3);
    INTC_LLD_Set_IRQ_Priority(EQADC23_FIFO_3_IRQn, INTR_PRI_10);
    INTC_LLD_Set_IRQ_Enable(EQADC23_FIFO_3_IRQn);
    u8Adc_TempReturn = Adc_SetupResultBuffer(2, &resultbuffer[0]);
    if(u8Adc_TempReturn == E_OK)
    {
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
        Adc_timeout = ADC_TIMEOUT;
        Adc_StartGroupConversion(2);
        Adc_ValueGroupType result_2[20];
        while((Adc_GetGroupStatus(2) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
        {
            Adc_timeout--;
        }
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(2, result_2);
#endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\nZ7_0 group2 test is OK, result is %d\n", result_2[0]);
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\nZ7_0 group2 test is timeout\n");
            }
            PSPRINTF("\nZ7_0 group2 test is not OK\n");
        }
#endif
    }

    //Adc_StopGroupConversion(2);
    (void) INTC_LLD_Set_IRQ_Disable(EQADC23_FIFO_3_IRQn);
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}

void ADC_0324(void)
{
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    uint32 Adc_timeout = ADC_TIMEOUT;
    int i = 0U;
#endif
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
    Adc_Init(&Adc_Config);

    INTC_LLD_Set_IRQ_Handle(EQADC89_FIFO_3_IRQn, ADC89_GRP3);
    INTC_LLD_Set_IRQ_Priority(EQADC89_FIFO_3_IRQn, INTR_PRI_10);
    INTC_LLD_Set_IRQ_Enable(EQADC89_FIFO_3_IRQn);
    u8Adc_TempReturn = Adc_SetupResultBuffer(4, &resultbuffer[0]);
    if(u8Adc_TempReturn == E_OK)
    {
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
        Adc_timeout = ADC_TIMEOUT;
        Adc_StartGroupConversion(4);
        Adc_ValueGroupType result_4[20];
        while((Adc_GetGroupStatus(4) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
        {
            Adc_timeout--;
        }
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(4, result_4);
#endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\nZ7_1 group4 test is OK\n");
            for(i = 0; i < Adc_Config.Adc_GroupConfig[4].ChannelCount; i++)
            {
                PSPRINTF("result buffer[%d] is %d\n", i, result_4[i]);
            }
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\nZ7_1 group4 test is timeout\n");
            }
            PSPRINTF("\nZ7_1 group4 test is not OK\n");
        }
#endif
    }
    //Adc_StopGroupConversion(9);
    (void) INTC_LLD_Set_IRQ_Disable(EQADC89_FIFO_3_IRQn);
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}

void ADC_0325(void)
{
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    uint32 Adc_timeout = ADC_TIMEOUT;
    uint32 i = 0U;
#endif
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;
    Adc_Init(&Adc_Config);
    INTC_LLD_Set_IRQ_Handle(EQADC45_FIFO_0_IRQn, ADC45_GRP0);
    INTC_LLD_Set_IRQ_Priority(EQADC45_FIFO_0_IRQn, INTR_PRI_7);
    INTC_LLD_Set_IRQ_Enable(EQADC45_FIFO_0_IRQn);
    u8Adc_TempReturn = Adc_SetupResultBuffer(3, &resultbuffer[0]);
    if(u8Adc_TempReturn == E_OK)
    {
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
        Adc_timeout = ADC_TIMEOUT;
        Adc_StartGroupConversion(3);
        for(uint32 i = 0U; i < 100000U; i++);
        Adc_ValueGroupType result_3[20];
        for(i = 0U; i < 10U; i++)
        {
#if (ADC_READ_GROUP_API == STD_ON)
            u8Adc_TempReturn = Adc_ReadGroup(3, result_3);
#endif
            if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
            {
                PSPRINTF("\n conv: %d ,Z4_2 group3 test is OK, result is %d\n", i, result_3[0]);
            }
            else
            {
                if(Adc_timeout == 0)
                {
                    PSPRINTF("\nZ4_2 group3 test is timeout\n");
                }
                PSPRINTF("\nZ4_2 group3 test is not OK\n");
            }
        }
#endif
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
        Adc_StopGroupConversion(3);
#endif
    }
    INTC_LLD_Set_IRQ_Disable(EQADC45_FIFO_0_IRQn);
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}

void ADC_0326(void)
{
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    uint32 Adc_timeout = ADC_TIMEOUT;
#endif
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;

    Adc_Init(&Adc_Config);
    INTC_LLD_Set_IRQ_Handle(EQADC1011_FIFO_1_IRQn, ADC1011_GRP1);
    INTC_LLD_Set_IRQ_Priority(EQADC1011_FIFO_1_IRQn, INTR_PRI_10);
    INTC_LLD_Set_IRQ_Enable(EQADC1011_FIFO_1_IRQn);
    u8Adc_TempReturn = Adc_SetupResultBuffer(5, &resultbuffer[0]);
    if(u8Adc_TempReturn == E_OK)
    {
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
        Adc_timeout = ADC_TIMEOUT;
        Adc_StartGroupConversion(5);
        Adc_ValueGroupType result_5[20];
        while((Adc_GetGroupStatus(5) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
        {
            Adc_timeout--;
        }
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(5, result_5);
#endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\ncore 3 group5 test is OK, result is %d\n", result_5[0]);
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\ncore 3 group5 test is timeout\n");
            }
            PSPRINTF("\ncore 3 group5 test is not OK\n");
        }
#endif
    }

    //Adc_StopGroupConversion(2);
    (void) INTC_LLD_Set_IRQ_Disable(EQADC1011_FIFO_1_IRQn);
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}

void ADC_0327(void)
{
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    uint32 Adc_timeout = ADC_TIMEOUT;
#endif
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;

    Adc_Init(&Adc_Config);
    INTC_LLD_Set_IRQ_Handle(EQADC1011_FIFO_1_IRQn, ADC1011_GRP1);
    INTC_LLD_Set_IRQ_Priority(EQADC1011_FIFO_1_IRQn, INTR_PRI_10);
    INTC_LLD_Set_IRQ_Enable(EQADC1011_FIFO_1_IRQn);
    u8Adc_TempReturn = Adc_SetupResultBuffer(6, &resultbuffer[0]);
    if(u8Adc_TempReturn == E_OK)
    {
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
        Adc_timeout = ADC_TIMEOUT;
        Adc_StartGroupConversion(6);
        Adc_ValueGroupType result_6[20];
        while((Adc_GetGroupStatus(6) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
        {
            Adc_timeout--;
        }
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(6, result_6);
#endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\ncore 4 group6 test is OK, result is %d\n", result_6[0]);
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\ncore 4 group6 test is timeout\n");
            }
            PSPRINTF("\ncore 4 group6 test is not OK\n");
        }
#endif
    }

    //Adc_StopGroupConversion(2);
    (void) INTC_LLD_Set_IRQ_Disable(EQADC1011_FIFO_1_IRQn);
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}

void ADC_0328(void)
{
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    uint32 Adc_timeout = ADC_TIMEOUT;
#endif
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;

    Adc_Init(&Adc_Config);
    INTC_LLD_Set_IRQ_Handle(EQADC1213_FIFO_2_IRQn, ADC1213_GRP2);
    INTC_LLD_Set_IRQ_Priority(EQADC1213_FIFO_2_IRQn, INTR_PRI_10);
    INTC_LLD_Set_IRQ_Enable(EQADC1213_FIFO_2_IRQn);
    u8Adc_TempReturn = Adc_SetupResultBuffer(7, &resultbuffer[0]);
    if(u8Adc_TempReturn == E_OK)
    {
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
        Adc_timeout = ADC_TIMEOUT;
        Adc_StartGroupConversion(7);
        Adc_ValueGroupType result_7[20];
        while((Adc_GetGroupStatus(7) != ADC_STREAM_COMPLETED)  && (Adc_timeout > 0U))
        {
            Adc_timeout--;
        }
#if (ADC_READ_GROUP_API == STD_ON)
        u8Adc_TempReturn = Adc_ReadGroup(7, result_7);
#endif
        if((u8Adc_TempReturn == E_OK) && (Adc_timeout > 0U))
        {
            PSPRINTF("\ncore 5 group7 test is OK, result is %d\n", result_7[0]);
        }
        else
        {
            if(Adc_timeout == 0)
            {
                PSPRINTF("\ncore 5 group7 test is timeout\n");
            }
            PSPRINTF("\ncore 5 group7 test is not OK\n");
        }
#endif
    }

    //Adc_StopGroupConversion(2);
    (void) INTC_LLD_Set_IRQ_Disable(EQADC1213_FIFO_2_IRQn);
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
void ADC_0331(void)
{
    Adc_ValueGroupType result_12[20];
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;

    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(12, &resultbuffer[0]);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StartGroupConversion(12);
#endif
    for(uint16 j = 0U; j < 20U; j++)
    {
        Adc_MainFunction();
        if(Adc_GetGroupStatus(12) == ADC_STREAM_COMPLETED)
        {
#if (ADC_READ_GROUP_API == STD_ON)
            u8Adc_TempReturn = Adc_ReadGroup(12, result_12);
#endif
            if(u8Adc_TempReturn == E_OK)
            {
                PSPRINTF("\nOneShot without interrupt test is OK\n");
                for(uint16 i = 0; i < Adc_Config.Adc_GroupConfig[12].ChannelCount; i++)
                {
                    PSPRINTF("result buffer[%d] is %d\n", i, result_12[i]);
                }
            }
            else
            {
                PSPRINTF("\nOneShot without interrupt test is not OK\n");
            }
            break;
        }
    }
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}

void ADC_0332(void)
{
    Adc_ValueGroupType result_13[20];
    Std_ReturnType u8Adc_TempReturn = (Std_ReturnType)E_NOT_OK;

    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(13, &resultbuffer[0]);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StartGroupConversion(13);
#endif
    for(uint16 j = 0U; j < 30U; j++)
    {
        Adc_MainFunction();
        if(Adc_GetGroupStatus(13) == ADC_STREAM_COMPLETED)
        {
#if (ADC_READ_GROUP_API == STD_ON)
            u8Adc_TempReturn = Adc_ReadGroup(13, result_13);
#endif
            if(u8Adc_TempReturn == E_OK)
            {
                PSPRINTF("\nContinuous without interrupt test is OK\n");
                for(uint16 i = 0; i < Adc_Config.Adc_GroupConfig[13].ChannelCount; i++)
                {
                    PSPRINTF("result buffer[%d] is %d\n", i, result_13[i]);
                }
            }
            else
            {
                PSPRINTF("\nContinuous without interrupt test is not OK\n");
            }
        }
    }
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    Adc_StopGroupConversion(13);
#endif
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}
#endif

FUNC(void, ADC_CODE) Adc9_Result_Callback \
( \
    P2CONST(void, ADC_VAR, ADC_APPL_CONST) parameter, \
    VAR(eDMAChnStatusType, ADC_VAR) status, \
    VAR(uint8, ADC_VAR) mappedChannel \
)
{
    (void)parameter;
    (void)status;
    (void)mappedChannel;
    uint8 count = 0U;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();

    PSPRINTF("The sampling results are as follows:\n");
    for(uint8 i = 0U; i < 50U; i++)
    {
#if (ADC_CONFIG_GROUPS > 10U)
        if(sAdc_RunningGroup[u32Adc_ICoreId][10].GroupResultBufferPtr[i] != 0U)
        {
            PSPRINTF("%d: %d\n", i, sAdc_RunningGroup[u32Adc_ICoreId][10].GroupResultBufferPtr[i]>>2U);
            if(((count + 1U) % 3U == 0U) && (count != 0U))
            {
                PSPRINTF("\n");
            }
            count++;
        }
#endif
    }
    if(count == (Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[10].DmaSampleNum) * (Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[10].ChannelCount))
    {
        PSPRINTF("Number of channel:%d\nDma sampling times:%d\nThe number of valid data when a dma interrupt is generated:%d\n", \
            Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[10].ChannelCount, \
            Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[10].DmaSampleNum, count);
    }
#if (ADC_HW_TRIGGER_API == STD_ON)
    Adc_DisableHardwareTrigger(10);
#endif
    (void) INTC_LLD_Set_IRQ_Disable(DMA0_CH61_IRQn);
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
}
#if (ADC_HW_TRIGGER_API == STD_ON)
void ADC_0333(void)
{
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH61_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Handle(DMA0_CH61_IRQn, &EDMA_Ch61_IRQHandler);
    (void) INTC_LLD_Set_IRQ_Enable(DMA0_CH61_IRQn);
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(10, &resultbuffer[0]);
    Adc_EnableHardwareTrigger(10);
    Pwm_Init(&Pwm_Config);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);
    Pwm_DeInit();
}
#endif
FUNC(void, ADC_CODE) Overflow_callback(void)
{
    Pwm_DeInit();
#if (ADC_DEINIT_API == STD_ON)
    Adc_DeInit();
#endif
    PSPRINTF("Overflow_callback is OK\n");
}
extern VAR(uint16, ADC_VAR) Adc_gIrqMapping[ADC_CORE_NUM][42U];

void ADC_0334(void)
{
    (void) INTC_LLD_Set_IRQ_Priority(EQADC23_FIFO_OVERRUN_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Handle(EQADC23_FIFO_OVERRUN_IRQn, &ADC23_FISR_Overflow);
    (void) INTC_LLD_Set_IRQ_Enable(EQADC23_FIFO_OVERRUN_IRQn);
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    VAR(Eqadc_ConvCmdType, ADC_VAR) sAdc_ConvCmdTemp;
    Adc_Init(&Adc_Config);
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    Adc_EnableGroupNotification(11);
#endif
    Adc_gIrqMapping[u32Adc_ICoreId][(EQADC_INSTANCE_1 * EQADC_RFIFO_COUNT) + EQADC_FIFO_0] = 11U;
    sAdc_ConvCmdTemp = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[11].Eqadc_ConvCmd[0];
    EQADC_CFCRxSetMode((uint8)EQADC_INSTANCE_1, (uint8)(EQADC_FIFO_0), (uint32)(EQADC_CFIFO_MODE_SINGLE_SW_TRIG));
    EQADC_LLD_IntEnDis(EQADC_INSTANCE_1, EQADC_FIFO_0, EQADC_IRQ_EN_RFIFO_OVERFLOW, TRUE);
    for(uint8 i = 0U; i < 5U; i++)
    {
        EQADC_LLD_CfifoPushConvCmd(EQADC_INSTANCE_1, EQADC_FIFO_0, &sAdc_ConvCmdTemp);
        EQADC_LLD_SingleScanEn(EQADC_INSTANCE_1, EQADC_FIFO_0);
        Gpt_Stm_LLD_DelayMs(STM1, 50U);
    }
}

void ADC_0335(void)
{
    (void) INTC_LLD_Set_IRQ_Priority(EQADC23_FIFO_OVERRUN_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Handle(EQADC23_FIFO_OVERRUN_IRQn, &ADC23_FISR_Overflow);
    (void) INTC_LLD_Set_IRQ_Enable(EQADC23_FIFO_OVERRUN_IRQn);
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    VAR(Eqadc_ConvCmdType, ADC_VAR) sAdc_ConvCmdTemp;
    Adc_Init(&Adc_Config);
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    Adc_EnableGroupNotification(11);
#endif
    Adc_gIrqMapping[u32Adc_ICoreId][(EQADC_INSTANCE_1 * EQADC_RFIFO_COUNT) + EQADC_FIFO_0] = 11U;
    EQADC_LLD_IntEnDis(EQADC_INSTANCE_1, EQADC_FIFO_0, EQADC_IRQ_EN_TRIGGER_OVERRUN, TRUE);
    EQADC_CFCRxSetMode((uint8)EQADC_INSTANCE_1, (uint8)(EQADC_FIFO_0), (uint32)(EQADC_CFIFO_MODE_CONT_FALLING_EDGE_EXT_TRIG));
    EQADC_LLD_SingleScanEn(EQADC_INSTANCE_1, EQADC_FIFO_0);
    EQADC_LLD_SetCfifoHwTrigSource(EQADC_INSTANCE_1, EQADC_FIFO_0, EQADC_HW_TRIG_EMIOS0_CH16,0);
    sAdc_ConvCmdTemp = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[11].Eqadc_ConvCmd[0];
    EQADC_LLD_CfifoPushConvCmd(EQADC_INSTANCE_1, EQADC_FIFO_0, &sAdc_ConvCmdTemp);
    Pwm_Init(&Pwm_Config);
}
int adc_func(int argc, char *agrv[])
{
    if ((argc > 3) || (argc < 2)) {
        PSPRINTF("error: The number of parameters exceeds 3 or is less than 2\n");
    }
    else
    {
        if (argc == 2)
        {
            if (!strcmp(agrv[1], "deinit"))
            {
                #if (ADC_DEINIT_API == STD_ON)
                    Adc_DeInit();
                    PSPRINTF("Adc_DeInit end!\n");
                #else
                    PSPRINTF("ADC_DEINIT_API == STD_OFF\n");
                #endif

            }
            else if (!strcmp(agrv[1], "help"))
            {
                PSPRINTF("deinit ---------- CMD ------- Adc_DeInit()\n");
                PSPRINTF("id -------------- CMD ------- ID of the test case:\n");

                for(uint8 i = 0; i < ADC_TEST_CASE_MAX; i++)
                {
                    PSPRINTF("%s\n", adc_funcs[i].name);
                }
            }
            else
            {
                for(uint8 i = 0; i < ADC_TEST_CASE_MAX; i++)
                {
                    if(!strcmp(agrv[1], adc_funcs[i].name))
                    {
                        adc_funcs[i].adcfunc();
                        return 0;
                    }
                }
                PSPRINTF("error: Input invalid parameters[%s], please Use the 'adc_test help' command to see the supported test instructions\n", agrv[1]);
            }
        }
    }
    return 0;
}
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), adc_test, adc_func, deinit irq or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
