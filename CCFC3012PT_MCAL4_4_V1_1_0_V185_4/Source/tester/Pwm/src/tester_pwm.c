#include "Pwm.h"
#include "console.h"
#include "shell.h"
#include "tester_pwm.h"
#include "common.h"
#include "intc_lld.h"
#include "Pwm_LLDriver.h"
//#include "GTM_TIM_LLDrivers.h"
#include <string.h>
#include "Gpt_Gtm_LLDriver.h"
#include "eMIOS_LLDriver.h"
#include "Pwm_Irq.h"
#include "Gpt_Stm_LLDriver.h"

#define PWM_TEST_ATOM_CH          0
#define PWM_TEST_TOM_CH           1
#define PWM_TEST_EMIOS_OPWFMB_CH  2
#define PWM_TEST_CASE_MAX sizeof(pwm_funcs) / sizeof(PwmfuncMachine)

#define PRINTF_FUNCNAME() PSPRINTF("\r\n    [%s]\r\n", __func__);

#define TSC_GTM_ATOM 1
#define TSC_GTM_TOM 0


#if (defined(CCFC3007PT) || defined (CCFC3008PT))
void TSC_Pwm_Clock(uint8_t type);
#endif

static PwmfuncMachine pwm_funcs[] = {
   {"1", TSC_Pwm_0001},
   {"2", TSC_Pwm_0002},
   {"3", TSC_Pwm_0003},
   {"4", TSC_Pwm_0004},
   {"5", TSC_Pwm_0005},
   {"6", TSC_Pwm_0006},
};

void Atom3_2_3_IRQ_Handle(void)
{
    Pwm_Atom_isr_handle(3,2,3);
}

void Tom0_0_1IRQ_Handle(void)
{
    Pwm_Tom_isr_handle(0,0,1);
}

void Emios0_5_IRQ_Handle(void)
{
    Pwm_Emios_isr_handle(0,5);
}
 
void Pwm_Notification_0(void)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();

    if(u32CoreIDn == 0)
    {
        SIUL.GPDO[0U].R ^= 1U;
    }
    else if(u32CoreIDn == 1)
    {
        SIUL.GPDO[1U].R ^= 1U;
    }
    else if(u32CoreIDn == 2)
    {
        SIUL.GPDO[2U].R ^= 1U;
    }
    else if(u32CoreIDn == 3)
    {
        SIUL.GPDO[3U].R ^= 1U;
    }
    else if(u32CoreIDn == 4)
    {
        SIUL.GPDO[4U].R ^= 1U;
    }
    else if(u32CoreIDn == 5)
    {
        SIUL.GPDO[5U].R ^= 1U;
    }
}

void Pwm_Notification_1(void)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();

    if(u32CoreIDn == 0)
    {
        SIUL.GPDO[0U].R ^= 1U;
    }
    else if(u32CoreIDn == 1)
    {
        SIUL.GPDO[1U].R ^= 1U;
    }
    else if(u32CoreIDn == 2)
    {
        SIUL.GPDO[2U].R ^= 1U;
    }
    else if(u32CoreIDn == 3)
    {
        SIUL.GPDO[3U].R ^= 1U;
    }
    else if(u32CoreIDn == 4)
    {
        SIUL.GPDO[4U].R ^= 1U;
    }
    else if(u32CoreIDn == 5)
    {
        SIUL.GPDO[5U].R ^= 1U;
    }
}

void Pwm_Notification_2(void)
{
    VAR(uint32, AUTOMATIC) u32CoreIDn = 0U;
    u32CoreIDn = GetCoreID();

    if(u32CoreIDn == 0)
    {
        SIUL.GPDO[0U].R ^= 1U;
    }
    else if(u32CoreIDn == 1)
    {
        SIUL.GPDO[1U].R ^= 1U;
    }
    else if(u32CoreIDn == 2)
    {
        SIUL.GPDO[2U].R ^= 1U;
    }
    else if(u32CoreIDn == 3)
    {
        SIUL.GPDO[3U].R ^= 1U;
    }
    else if(u32CoreIDn == 4)
    {
        SIUL.GPDO[4U].R ^= 1U;
    }
    else if(u32CoreIDn == 5)
    {
        SIUL.GPDO[5U].R ^= 1U;
    }
}

int Pwm_Channel = 0;

void TSC_Pwm_0001(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr)
{
    PRINTF_FUNCNAME();
    VAR(Pwm_OutputStateType, AUTOMATIC) retVal;

    //PWM_0094
    Pwm_Init(ConfigPtr);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0095
    Pwm_SetDutyCycle(PWM_TEST_ATOM_CH, 0x2000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0096
    Pwm_SetDutyCycle(PWM_TEST_ATOM_CH, 0);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0097
    Pwm_SetDutyCycle(PWM_TEST_ATOM_CH, 0x8000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0098
    Pwm_SetPeriodAndDuty(PWM_TEST_ATOM_CH,6000,0x6000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0099
    Pwm_SetPeriodAndDuty(PWM_TEST_ATOM_CH,6000,0);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0100
    Pwm_SetPeriodAndDuty(PWM_TEST_ATOM_CH,6000,0x8000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0101
    Pwm_SetOutputToIdle(PWM_TEST_ATOM_CH);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0102
    Pwm_SetPeriodAndDuty(PWM_TEST_ATOM_CH,6000,0x4000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0103
    Pwm_SetOutputToIdle(PWM_TEST_ATOM_CH);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0104
    Pwm_SetDutyCycle(PWM_TEST_ATOM_CH,0x2000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0105
    retVal = Pwm_GetOutputState(PWM_TEST_ATOM_CH);
    if (retVal == PWM_LOW)
    {
        PSPRINTF("retVal = PWM_LOW\r\n");
    }
    else
    {
        PSPRINTF("retVal = PWM_HIGH\r\n");
    }
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0106
    Pwm_DeInit();
}

//TOM
void TSC_Pwm_0002(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr)
{
    PRINTF_FUNCNAME();

    VAR(Pwm_OutputStateType, AUTOMATIC) retVal;

    //PWM_0120
    Pwm_Init(ConfigPtr);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0121
    Pwm_SetDutyCycle(PWM_TEST_TOM_CH, 0x2000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0122
    Pwm_SetDutyCycle(PWM_TEST_TOM_CH, 0);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0123
    Pwm_SetDutyCycle(PWM_TEST_TOM_CH, 0x8000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0124
    Pwm_SetPeriodAndDuty(PWM_TEST_TOM_CH,6000,0x6000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0125
    Pwm_SetPeriodAndDuty(PWM_TEST_TOM_CH,6000,0);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0126
    Pwm_SetPeriodAndDuty(PWM_TEST_TOM_CH,6000,0x8000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0127
    Pwm_SetOutputToIdle(PWM_TEST_TOM_CH);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0128
    Pwm_SetPeriodAndDuty(PWM_TEST_TOM_CH,6000,0x4000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0129
    Pwm_SetOutputToIdle(PWM_TEST_TOM_CH);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0130
    Pwm_SetDutyCycle(PWM_TEST_TOM_CH,0x2000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0131
    retVal = Pwm_GetOutputState(PWM_TEST_TOM_CH);
    if (retVal == PWM_LOW)
    {
        PSPRINTF("retVal = PWM_LOW\r\n");
    }
    else
    {
        PSPRINTF("retVal = PWM_HIGH\r\n");
    }
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0132
    Pwm_DeInit();
}

//OPWFMB
void TSC_Pwm_0003(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr)
{
    PRINTF_FUNCNAME();

    VAR(Pwm_OutputStateType, AUTOMATIC) retVal;

    //PWM_0300
    Pwm_Init(ConfigPtr);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0301
    Pwm_SetDutyCycle(PWM_TEST_EMIOS_OPWFMB_CH, 0x2000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0302
    Pwm_SetDutyCycle(PWM_TEST_EMIOS_OPWFMB_CH, 0);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0303
    Pwm_SetDutyCycle(PWM_TEST_EMIOS_OPWFMB_CH, 0x8000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0304
    Pwm_SetPeriodAndDuty(PWM_TEST_EMIOS_OPWFMB_CH,500,0x6000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0305
    Pwm_SetPeriodAndDuty(PWM_TEST_EMIOS_OPWFMB_CH,500,0);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0306
    Pwm_SetPeriodAndDuty(PWM_TEST_EMIOS_OPWFMB_CH,500,0x8000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0307
    Pwm_SetOutputToIdle(PWM_TEST_EMIOS_OPWFMB_CH);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0308
    Pwm_SetPeriodAndDuty(PWM_TEST_EMIOS_OPWFMB_CH,500,0x4000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0309
    Pwm_SetOutputToIdle(PWM_TEST_EMIOS_OPWFMB_CH);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0310
    Pwm_SetDutyCycle(PWM_TEST_EMIOS_OPWFMB_CH,0x2000);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);

    //PWM_0311
    retVal = Pwm_GetOutputState(PWM_TEST_EMIOS_OPWFMB_CH);
    if (retVal == PWM_LOW)
    {
        PSPRINTF("retVal = PWM_LOW\r\n");
    }
    else
    {
        PSPRINTF("retVal = PWM_HIGH\r\n");
    }

    //PWM_0312
    Gpt_Stm_LLD_DelayMs(STM1, 50U);
    Pwm_DeInit();
}

//ATOM Notification
void TSC_Pwm_0004(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr)
{
    SIUL.PCR[PA0].R = 0x0080u;  /* GPIO PA[0] output */
    SIUL.PCR[PA1].R = 0x0080u;  /* GPIO PA[1] output */
    SIUL.PCR[PA2].R = 0x0080u;  /* GPIO PA[2] output */
    SIUL.PCR[PA3].R = 0x0080u;  /* GPIO PA[3] output */
    SIUL.PCR[PA4].R = 0x0080u;  /* GPIO PA[4] output */
    SIUL.PCR[PA5].R = 0x0080u;  /* GPIO PA[5] output */
    (void)INTC_LLD_Set_IRQ_Handle((IntrId)850, &Atom3_2_3_IRQ_Handle);
    (void)INTC_LLD_Set_IRQ_Priority((IntrId)850, INTR_PRI_15);
    (void)INTC_LLD_Set_IRQ_Enable((IntrId)850);
    Pwm_Init(ConfigPtr);

    //PWM_0351
    Pwm_EnableNotification(PWM_TEST_ATOM_CH,PWM_BOTH_EDGES);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);
    //PWM_0352
    Pwm_DisableNotification(PWM_TEST_ATOM_CH);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);
    Pwm_DeInit();
}

//TOM Notification
void TSC_Pwm_0005(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr)
{
    SIUL.PCR[PA0].R = 0x0080u;  /* GPIO PA[0] output */
    SIUL.PCR[PA1].R = 0x0080u;  /* GPIO PA[1] output */
    SIUL.PCR[PA2].R = 0x0080u;  /* GPIO PA[2] output */
    SIUL.PCR[PA3].R = 0x0080u;  /* GPIO PA[3] output */
    SIUL.PCR[PA4].R = 0x0080u;  /* GPIO PA[4] output */
    SIUL.PCR[PA5].R = 0x0080u;  /* GPIO PA[5] output */
    (void)INTC_LLD_Set_IRQ_Handle((IntrId)813, &Tom0_0_1IRQ_Handle);
    (void)INTC_LLD_Set_IRQ_Priority((IntrId)813, INTR_PRI_15);
    (void)INTC_LLD_Set_IRQ_Enable((IntrId)813);
    Pwm_Init(ConfigPtr);

    //PWM_0353
    Pwm_EnableNotification(PWM_TEST_TOM_CH,PWM_BOTH_EDGES);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);
    //PWM_0354
    Pwm_DisableNotification(PWM_TEST_TOM_CH);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);
    Pwm_DeInit();
}

//EMIOS Notification
void TSC_Pwm_0006(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr)
{
    SIUL.PCR[PA0].R = 0x0080u;  /* GPIO PA[0] output */
    SIUL.PCR[PA1].R = 0x0080u;  /* GPIO PA[1] output */
    SIUL.PCR[PA2].R = 0x0080u;  /* GPIO PA[2] output */
    SIUL.PCR[PA3].R = 0x0080u;  /* GPIO PA[3] output */
    SIUL.PCR[PA4].R = 0x0080u;  /* GPIO PA[4] output */
    SIUL.PCR[PA5].R = 0x0080u;  /* GPIO PA[5] output */
    Pwm_Init(ConfigPtr);
    (void)INTC_LLD_Set_IRQ_Handle((IntrId)EMIOS0_CH5_IRQn, &Emios0_5_IRQ_Handle);
    (void)INTC_LLD_Set_IRQ_Priority((IntrId)EMIOS0_CH5_IRQn, INTR_PRI_15);
    (void)INTC_LLD_Set_IRQ_Enable((IntrId)EMIOS0_CH5_IRQn);

    //PWM_0355
    Pwm_EnableNotification(PWM_TEST_EMIOS_OPWFMB_CH,PWM_BOTH_EDGES);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);
    //PWM_0356
    Pwm_DisableNotification(PWM_TEST_EMIOS_OPWFMB_CH);
    Gpt_Stm_LLD_DelayMs(STM1, 50U);
    Pwm_DeInit();
}

#if (defined(CCFC3007PT) || defined (CCFC3008PT))
void TSC_Pwm_Clock(uint8_t type)
{
    if(type == TSC_GTM_ATOM && tom_clk_flag == 0)
    {
        (void)GPT_GTMINT_LLD_IsEnableModule(GPT_GTM_Enable);
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK0,GPT_GTM_Enable);
        tom_clk_flag=1;
    }
    else if(type == TSC_GTM_TOM && atom_clk_flag == 0)
    {
        (void)GPT_GTMINT_LLD_IsEnableModule(GPT_GTM_Enable);
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_FXCLK,GPT_GTM_Enable);
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK0,GPT_GTM_Enable);
        atom_clk_flag=1;
    }
}
#endif 

int tsc_pwm_func(int argc, char *agrv[])
{
    if ((argc > 3) || (argc < 2)) {
        PSPRINTF("error: The number of parameters exceeds 3 or is less than 2\n");
        return 1;
    }

    if (argc == 2)
       {
           if (!strcmp(agrv[1], "help"))
           {
               PSPRINTF("tom  ----- CMD -------  Enable TOM Clock\r\n");
               PSPRINTF("atom ----- CMD ------- Enable ATOM Clock\r\n");
               PSPRINTF("help ----- CMD ------- ID of the test case\r\n");

               for(uint8 i = 0; i < PWM_TEST_CASE_MAX; i++)
               {
                   PSPRINTF("%s\n", pwm_funcs[i].name);
               }
           }

#if (defined(CCFC3007PT) || defined (CCFC3008PT))
           else if (!strcmp(agrv[1], "tom"))
           {
               TSC_Pwm_Clock(TSC_GTM_TOM);
               PSPRINTF("Enable TOM Clock\r\n");
           }

           else if (!strcmp(agrv[1], "atom"))
           {
               TSC_Pwm_Clock(TSC_GTM_ATOM);
               PSPRINTF("Enable ATOM Clock\r\n");
           }
#endif
        else
        {
            for(uint8 i = 0; i < PWM_TEST_CASE_MAX; i++)
            {
                if(!strcmp(agrv[1], pwm_funcs[i].name))
                {
                    pwm_funcs[i].pwmfunc(&Pwm_Config);
                    return 0;
                }
            }
            PSPRINTF("error: Input invalid parameters[%s], please Use the 'Pwm_test help' command to see the supported test instructions\n", agrv[1]);
        }
    }
    return 0;
}

#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), pwm_test, tsc_pwm_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
