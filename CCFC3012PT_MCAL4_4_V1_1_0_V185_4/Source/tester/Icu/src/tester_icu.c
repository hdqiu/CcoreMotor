
#include "Icu.h"
#include "console.h"
#include "Icu_Cfg.h"
#include "Gpt_Stm_LLDriver.h"
#include "intc_lld.h"
#include "shell.h"
#include "tester_icu.h"
#include <string.h>
#include "Icu_Gtm_LLDrivers.h"
#include "Icu_eMIOS_LLDrivers.h"
#include "Gtm_HAL_Irq.h"
#include "eDma_LLDriver.h"
#ifdef RESOURCE_SUPPORT_ETPU
#include "eTPU_LLDrivers.h"
#include "eTPU_HAL_Irq.h"
#endif
#include "eMIOS_HAL_Irq.h"
#include "Mcu.h"
#include "Gpt.h"
#include "Wkpu_HAL_Irq.h"
#include "Gpt_cfg.h"
#include "tester_gpt.h"

#include "compiler_api.h"
#define ICU_TEST_CASE_MAX   sizeof(icu_funcs) / sizeof(IcufuncMachine)
#define GPT_RTC_CON_INSTANCE		13
extern VAR(Icu_ModeType, ICU_VAR) eIcu_CurrentMode[ICU_CORE_NUM];
extern CONST(Icu_ConfigType, ICU_CONST) Icu_Cfg;
extern boolean TesterDemoICU;
extern CONST(Gpt_ConfigType, GPT_CONST) GptChannelConfigSet;

#if ( defined(CCFC3007PT) || defined(CCFC3008PT)|| defined(CCFC3012PT))
extern ISR(GTM_TIM_0_CH_0_ISR);
extern ISR(GTM_TIM_0_CH_1_ISR);
extern ISR(GTM_TIM_0_CH_2_ISR);
extern ISR(GTM_TIM_0_CH_3_ISR);
extern ISR(GTM_TIM_0_CH_4_ISR);
extern ISR(GTM_TIM_0_CH_5_ISR);
extern ISR(GTM_TIM_0_CH_6_ISR);
extern ISR(GTM_TIM_0_CH_7_ISR);
extern ISR(GTM_TIM_1_CH_0_ISR);
extern ISR(GTM_TIM_1_CH_1_ISR);
extern ISR(GTM_TIM_1_CH_2_ISR);
extern ISR(GTM_TIM_1_CH_3_ISR);
extern ISR(GTM_TIM_1_CH_4_ISR);
extern ISR(GTM_TIM_1_CH_5_ISR);
extern ISR(GTM_TIM_1_CH_6_ISR);
extern ISR(GTM_TIM_1_CH_7_ISR);
extern ISR(GTM_TIM_2_CH_0_ISR);
extern ISR(GTM_TIM_2_CH_1_ISR);
extern ISR(GTM_TIM_2_CH_2_ISR);
extern ISR(GTM_TIM_2_CH_3_ISR);
extern ISR(GTM_TIM_2_CH_4_ISR);
extern ISR(GTM_TIM_2_CH_5_ISR);
extern ISR(GTM_TIM_2_CH_6_ISR);
extern ISR(GTM_TIM_2_CH_7_ISR);
extern ISR(GTM_TIM_3_CH_0_ISR);
extern ISR(GTM_TIM_3_CH_1_ISR);
extern ISR(GTM_TIM_3_CH_2_ISR);
extern ISR(GTM_TIM_3_CH_3_ISR);
extern ISR(GTM_TIM_3_CH_4_ISR);
extern ISR(GTM_TIM_3_CH_5_ISR);
extern ISR(GTM_TIM_3_CH_6_ISR);
extern ISR(GTM_TIM_3_CH_7_ISR);
extern ISR(GTM_TIM_4_CH_0_ISR);
extern ISR(GTM_TIM_4_CH_1_ISR);
extern ISR(GTM_TIM_4_CH_2_ISR);
extern ISR(GTM_TIM_4_CH_3_ISR);
extern ISR(GTM_TIM_4_CH_4_ISR);
extern ISR(GTM_TIM_4_CH_5_ISR);
extern ISR(GTM_TIM_4_CH_6_ISR);
extern ISR(GTM_TIM_4_CH_7_ISR);
extern ISR(GTM_TIM_5_CH_0_ISR);
extern ISR(GTM_TIM_5_CH_1_ISR);
extern ISR(GTM_TIM_5_CH_2_ISR);
extern ISR(GTM_TIM_5_CH_3_ISR);
extern ISR(GTM_TIM_5_CH_4_ISR);
extern ISR(GTM_TIM_5_CH_5_ISR);
extern ISR(GTM_TIM_5_CH_6_ISR);
extern ISR(GTM_TIM_5_CH_7_ISR);
extern ISR(GTM_TIM_6_CH_0_ISR);
extern ISR(GTM_TIM_6_CH_1_ISR);
extern ISR(GTM_TIM_6_CH_2_ISR);
extern ISR(GTM_TIM_6_CH_3_ISR);
extern ISR(GTM_TIM_6_CH_4_ISR);
extern ISR(GTM_TIM_6_CH_5_ISR);
extern ISR(GTM_TIM_6_CH_6_ISR);
extern ISR(GTM_TIM_6_CH_7_ISR);
extern ISR(GTM_TIM_7_CH_0_ISR);
extern ISR(GTM_TIM_7_CH_1_ISR);
extern ISR(GTM_TIM_7_CH_2_ISR);
extern ISR(GTM_TIM_7_CH_3_ISR);
extern ISR(GTM_TIM_7_CH_4_ISR);
extern ISR(GTM_TIM_7_CH_5_ISR);
extern ISR(GTM_TIM_7_CH_6_ISR);
extern ISR(GTM_TIM_7_CH_7_ISR);
#endif

#if (defined(CCFC3007PT) || defined(CCFC3007BC)|| defined(CCFC3012PT))
extern void WKPU_IRQ0_Handler(void);
extern void WKPU_IRQ1_Handler(void);
extern void WKPU_IRQ2_Handler(void);
extern void WKPU_IRQ3_Handler(void);
extern void WKPU_IRQ4_Handler(void);
extern void WKPU_IRQ5_Handler(void);
extern void WKPU_IRQ6_Handler(void);
extern void WKPU_IRQ7_Handler(void);
#endif
//extern ISR(SIUL2_EIRQ_0_IRQHandler);
//extern ISR(SIUL2_EIRQ_1_IRQHandler);


#if (defined(RESOURCE_SUPPORT_EMIOS0) && defined(RESOURCE_SUPPORT_EMIOS1))
static CONST(IntrId, ICU_CONST) EMIOS_IRQ_NUM[EMIOS_INSTANCE_MAX][EMIOS_MODULE_CHANNEL_MAX] = {   \
    {   \
	    EMIOS0_CH0_IRQn,     EMIOS0_CH1_IRQn,     EMIOS0_CH2_IRQn,     EMIOS0_CH3_IRQn,      \
        EMIOS0_CH4_IRQn,     EMIOS0_CH5_IRQn,     EMIOS0_CH6_IRQn,     EMIOS0_CH7_IRQn,      \
        EMIOS0_CH8_IRQn,     EMIOS0_CH9_IRQn,     EMIOS0_CH10_IRQn,    EMIOS0_CH11_IRQn,    \
        EMIOS0_CH12_IRQn,    EMIOS0_CH13_IRQn,    EMIOS0_CH14_IRQn,    EMIOS0_CH15_IRQn,    \
        EMIOS0_CH16_IRQn,    EMIOS0_CH17_IRQn,    EMIOS0_CH18_IRQn,    EMIOS0_CH19_IRQn,    \
        EMIOS0_CH20_IRQn,    EMIOS0_CH21_IRQn,    EMIOS0_CH22_IRQn,    EMIOS0_CH23_IRQn,    \
        EMIOS0_CH24_IRQn,    EMIOS0_CH25_IRQn,    EMIOS0_CH26_IRQn,    EMIOS0_CH27_IRQn,    \
        EMIOS0_CH28_IRQn,    EMIOS0_CH29_IRQn,    EMIOS0_CH30_IRQn,    EMIOS0_CH31_IRQn     \
    },  \
    {   \
	    EMIOS1_CH0_IRQn,     EMIOS1_CH1_IRQn,     EMIOS1_CH2_IRQn,     EMIOS1_CH3_IRQn,      \
        EMIOS1_CH4_IRQn,     EMIOS1_CH5_IRQn,     EMIOS1_CH6_IRQn,     EMIOS1_CH7_IRQn,      \
        EMIOS1_CH8_IRQn,     EMIOS1_CH9_IRQn,     EMIOS1_CH10_IRQn,    EMIOS1_CH11_IRQn,    \
        EMIOS1_CH12_IRQn,    EMIOS1_CH13_IRQn,    EMIOS1_CH14_IRQn,    EMIOS1_CH15_IRQn,    \
        EMIOS1_CH16_IRQn,    EMIOS1_CH17_IRQn,    EMIOS1_CH18_IRQn,    EMIOS1_CH19_IRQn,    \
        EMIOS1_CH20_IRQn,    EMIOS1_CH21_IRQn,    EMIOS1_CH22_IRQn,    EMIOS1_CH23_IRQn,    \
        EMIOS1_CH24_IRQn,    EMIOS1_CH25_IRQn,    EMIOS1_CH26_IRQn,    EMIOS1_CH27_IRQn,    \
        EMIOS1_CH28_IRQn,    EMIOS1_CH29_IRQn,    EMIOS1_CH30_IRQn,    EMIOS1_CH31_IRQn     \
    }   \
};

static CONST(IntrHandle, ICU_CONST) EMIOS_IRQ_Callback[EMIOS_INSTANCE_MAX][EMIOS_MODULE_CHANNEL_MAX] = { \
    {   \
        eMIOS0_CH0_Handler,     eMIOS0_CH1_Handler,     eMIOS0_CH2_Handler,     eMIOS0_CH3_Handler,     \
        eMIOS0_CH4_Handler,     eMIOS0_CH5_Handler,     eMIOS0_CH6_Handler,     eMIOS0_CH7_Handler,     \
        eMIOS0_CH8_Handler,     eMIOS0_CH9_Handler,     eMIOS0_CH10_Handler,    eMIOS0_CH11_Handler,    \
        eMIOS0_CH12_Handler,    eMIOS0_CH13_Handler,    eMIOS0_CH14_Handler,    eMIOS0_CH15_Handler,    \
        eMIOS0_CH16_Handler,    eMIOS0_CH17_Handler,    eMIOS0_CH18_Handler,    eMIOS0_CH19_Handler,    \
        eMIOS0_CH20_Handler,    eMIOS0_CH21_Handler,    eMIOS0_CH22_Handler,    eMIOS0_CH23_Handler,    \
        eMIOS0_CH24_Handler,    eMIOS0_CH25_Handler,    eMIOS0_CH26_Handler,    eMIOS0_CH27_Handler,    \
        eMIOS0_CH28_Handler,    eMIOS0_CH29_Handler,    eMIOS0_CH30_Handler,    eMIOS0_CH31_Handler     \
    },  \
    {   \
        eMIOS1_CH0_Handler,     eMIOS1_CH1_Handler,     eMIOS1_CH2_Handler,     eMIOS1_CH3_Handler,     \
        eMIOS1_CH4_Handler,     eMIOS1_CH5_Handler,     eMIOS1_CH6_Handler,     eMIOS1_CH7_Handler,     \
        eMIOS1_CH8_Handler,     eMIOS1_CH9_Handler,     eMIOS1_CH10_Handler,    eMIOS1_CH11_Handler,    \
        eMIOS1_CH12_Handler,    eMIOS1_CH13_Handler,    eMIOS1_CH14_Handler,    eMIOS1_CH15_Handler,    \
        eMIOS1_CH16_Handler,    eMIOS1_CH17_Handler,    eMIOS1_CH18_Handler,    eMIOS1_CH19_Handler,    \
        eMIOS1_CH20_Handler,    eMIOS1_CH21_Handler,    eMIOS1_CH22_Handler,    eMIOS1_CH23_Handler,    \
        eMIOS1_CH24_Handler,    eMIOS1_CH25_Handler,    eMIOS1_CH26_Handler,    eMIOS1_CH27_Handler,    \
        eMIOS1_CH28_Handler,    eMIOS1_CH29_Handler,    eMIOS1_CH30_Handler,    eMIOS1_CH31_Handler     \
    }   \
};
#else
static CONST(IntrId, ICU_CONST) EMIOS_IRQ_NUM[EMIOS_INSTANCE_MAX][EMIOS_MODULE_CHANNEL_MAX] = {   \
    {   \
	    EMIOS0_CH0_IRQn,     EMIOS0_CH1_IRQn,     EMIOS0_CH2_IRQn,     EMIOS0_CH3_IRQn,     \
        EMIOS0_CH4_IRQn,     EMIOS0_CH5_IRQn,     EMIOS0_CH6_IRQn,     EMIOS0_CH7_IRQn,     \
        EMIOS0_CH8_IRQn,     EMIOS0_CH9_IRQn,     EMIOS0_CH10_IRQn,    EMIOS0_CH11_IRQn,    \
        EMIOS0_CH12_IRQn,    EMIOS0_CH13_IRQn,    EMIOS0_CH14_IRQn,    EMIOS0_CH15_IRQn,    \
        EMIOS0_CH16_IRQn,    EMIOS0_CH17_IRQn,    EMIOS0_CH18_IRQn,    EMIOS0_CH19_IRQn,    \
        EMIOS0_CH20_IRQn,    EMIOS0_CH21_IRQn,    EMIOS0_CH22_IRQn,    EMIOS0_CH23_IRQn,    \
        EMIOS0_CH24_IRQn,    EMIOS0_CH25_IRQn,    EMIOS0_CH26_IRQn,    EMIOS0_CH27_IRQn,    \
        EMIOS0_CH28_IRQn,    EMIOS0_CH29_IRQn,    EMIOS0_CH30_IRQn,    EMIOS0_CH31_IRQn     \
    }
};

static CONST(IntrHandle, ICU_CONST) EMIOS_IRQ_Callback[EMIOS_INSTANCE_MAX][EMIOS_MODULE_CHANNEL_MAX] = { \
    {   \
        eMIOS0_CH0_Handler,     eMIOS0_CH1_Handler,     eMIOS0_CH2_Handler,     eMIOS0_CH3_Handler,     \
        eMIOS0_CH4_Handler,     eMIOS0_CH5_Handler,     eMIOS0_CH6_Handler,     eMIOS0_CH7_Handler,     \
        eMIOS0_CH8_Handler,     eMIOS0_CH9_Handler,     eMIOS0_CH10_Handler,    eMIOS0_CH11_Handler,    \
        eMIOS0_CH12_Handler,    eMIOS0_CH13_Handler,    eMIOS0_CH14_Handler,    eMIOS0_CH15_Handler,    \
        eMIOS0_CH16_Handler,    eMIOS0_CH17_Handler,    eMIOS0_CH18_Handler,    eMIOS0_CH19_Handler,    \
        eMIOS0_CH20_Handler,    eMIOS0_CH21_Handler,    eMIOS0_CH22_Handler,    eMIOS0_CH23_Handler,    \
        eMIOS0_CH24_Handler,    eMIOS0_CH25_Handler,    eMIOS0_CH26_Handler,    eMIOS0_CH27_Handler,    \
        eMIOS0_CH28_Handler,    eMIOS0_CH29_Handler,    eMIOS0_CH30_Handler,    eMIOS0_CH31_Handler     \
    }
};
#endif

#ifdef RESOURCE_SUPPORT_ETPU
static CONST(IntrId, ICU_CONST) ETPU_IRQ_NUM[ETPU_IRQ_INSTANCE_MAX][ETPU_MODULE_CHANNEL_MAX] = {   \
    {   \
        ETPU1_CH0_IRQn,             ETPU1_CH1_IRQn,             ETPU1_CH2_IRQn,             ETPU1_CH3_IRQn,      \
        ETPU1_CH4_IRQn,             ETPU1_CH5_IRQn,             ETPU1_CH6_IRQn,             ETPU1_CH7_IRQn,      \
        ETPU1_CH8_IRQn,             ETPU1_CH9_IRQn,             ETPU1_CH10_IRQn,            ETPU1_CH11_IRQn,    \
        ETPU1_CH12_IRQn,            ETPU1_CH13_IRQn,            ETPU1_CH14_IRQn,            ETPU1_CH15_IRQn,    \
        ETPU1_CH16_IRQn,            ETPU1_CH17_IRQn,            ETPU1_CH18_IRQn,            ETPU1_CH19_IRQn,      \
		ETPU1_CH20_IRQn,            ETPU1_CH21_IRQn,            ETPU1_CH22_IRQn,            ETPU1_CH23_IRQn,      \
		ETPU1_CH24_IRQn,            ETPU1_CH25_IRQn,            ETPU1_CH26_IRQn,            ETPU1_CH27_IRQn,    \
		ETPU1_CH28_IRQn,            ETPU1_CH29_IRQn,            ETPU1_CH30_IRQn,            ETPU1_CH31_IRQn,    \
    },  \
    {   \
    	ETPU2_CH0_IRQn,             ETPU2_CH1_IRQn,             ETPU2_CH2_IRQn,             ETPU2_CH3_IRQn,            \
		ETPU2_CH4_IRQn,             ETPU2_CH5_IRQn,             ETPU2_CH6_IRQn,             ETPU2_CH7_IRQn,            \
		ETPU2_CH8_IRQn,             ETPU2_CH9_IRQn,             ETPU2_CH10_IRQn,            ETPU2_CH11_IRQn,            \
		ETPU2_CH12_IRQn,            ETPU2_CH13_IRQn,            ETPU2_CH14_IRQn,            ETPU2_CH15_IRQn,            \
		ETPU2_CH16_IRQn,            ETPU2_CH17_IRQn,            ETPU2_CH18_IRQn,            ETPU2_CH19_IRQn,            \
		ETPU2_CH20_IRQn,            ETPU2_CH21_IRQn,            ETPU2_CH22_IRQn,            ETPU2_CH23_IRQn,            \
		ETPU2_CH24_IRQn,            ETPU2_CH25_IRQn,            ETPU2_CH26_IRQn,            ETPU2_CH27_IRQn,            \
		ETPU2_CH28_IRQn,            ETPU2_CH29_IRQn,            ETPU2_CH30_IRQn,            ETPU2_CH31_IRQn             \
    },   \
    {   \
    	ETPU3_CH0_IRQn,             ETPU3_CH1_IRQn,             ETPU3_CH2_IRQn,             ETPU3_CH3_IRQn,            \
		ETPU3_CH4_IRQn,             ETPU3_CH5_IRQn,             ETPU3_CH6_IRQn,             ETPU3_CH7_IRQn,            \
		ETPU3_CH8_IRQn,             ETPU3_CH9_IRQn,             ETPU3_CH10_IRQn,            ETPU3_CH11_IRQn,            \
		ETPU3_CH12_IRQn,            ETPU3_CH13_IRQn,            ETPU3_CH14_IRQn,            ETPU3_CH15_IRQn,            \
		ETPU3_CH16_IRQn,            ETPU3_CH17_IRQn,            ETPU3_CH18_IRQn,            ETPU3_CH19_IRQn,            \
		ETPU3_CH20_IRQn,            ETPU3_CH21_IRQn,            ETPU3_CH22_IRQn,            ETPU3_CH23_IRQn,            \
		ETPU3_CH24_IRQn,            ETPU3_CH25_IRQn,            ETPU3_CH26_IRQn,            ETPU3_CH27_IRQn,            \
		ETPU3_CH28_IRQn,            ETPU3_CH29_IRQn,            ETPU3_CH30_IRQn,            ETPU3_CH31_IRQn             \
    }   \
};

static CONST(IntrHandle, ICU_CONST) ETPU_IRQ_Callback[ETPU_IRQ_INSTANCE_MAX][ETPU_MODULE_CHANNEL_MAX] = { \
    {   \
        eTPUA_CH0_Handler,     eTPUA_CH1_Handler,     eTPUA_CH2_Handler,     eTPUA_CH3_Handler,     \
        eTPUA_CH4_Handler,     eTPUA_CH5_Handler,     eTPUA_CH6_Handler,     eTPUA_CH7_Handler,     \
        eTPUA_CH8_Handler,     eTPUA_CH9_Handler,     eTPUA_CH10_Handler,    eTPUA_CH11_Handler,    \
        eTPUA_CH12_Handler,    eTPUA_CH13_Handler,    eTPUA_CH14_Handler,    eTPUA_CH15_Handler,    \
        eTPUA_CH16_Handler,    eTPUA_CH17_Handler,    eTPUA_CH18_Handler,    eTPUA_CH19_Handler,    \
        eTPUA_CH20_Handler,    eTPUA_CH21_Handler,    eTPUA_CH22_Handler,    eTPUA_CH23_Handler,    \
        eTPUA_CH24_Handler,    eTPUA_CH25_Handler,    eTPUA_CH26_Handler,    eTPUA_CH27_Handler,    \
        eTPUA_CH28_Handler,    eTPUA_CH29_Handler,    eTPUA_CH30_Handler,    eTPUA_CH31_Handler     \
    },  \
    {   \
        eTPUB_CH0_Handler,     eTPUB_CH1_Handler,     eTPUB_CH2_Handler,     eTPUB_CH3_Handler,     \
        eTPUB_CH4_Handler,     eTPUB_CH5_Handler,     eTPUB_CH6_Handler,     eTPUB_CH7_Handler,     \
        eTPUB_CH8_Handler,     eTPUB_CH9_Handler,     eTPUB_CH10_Handler,    eTPUB_CH11_Handler,    \
        eTPUB_CH12_Handler,    eTPUB_CH13_Handler,    eTPUB_CH14_Handler,    eTPUB_CH15_Handler,    \
        eTPUB_CH16_Handler,    eTPUB_CH17_Handler,    eTPUB_CH18_Handler,    eTPUB_CH19_Handler,    \
        eTPUB_CH20_Handler,    eTPUB_CH21_Handler,    eTPUB_CH22_Handler,    eTPUB_CH23_Handler,    \
        eTPUB_CH24_Handler,    eTPUB_CH25_Handler,    eTPUB_CH26_Handler,    eTPUB_CH27_Handler,    \
        eTPUB_CH28_Handler,    eTPUB_CH29_Handler,    eTPUB_CH30_Handler,    eTPUB_CH31_Handler     \
    },  \
    {   \
        eTPUC_CH0_Handler,     eTPUC_CH1_Handler,     eTPUC_CH2_Handler,     eTPUC_CH3_Handler,     \
        eTPUC_CH4_Handler,     eTPUC_CH5_Handler,     eTPUC_CH6_Handler,     eTPUC_CH7_Handler,     \
        eTPUC_CH8_Handler,     eTPUC_CH9_Handler,     eTPUC_CH10_Handler,    eTPUC_CH11_Handler,    \
        eTPUC_CH12_Handler,    eTPUC_CH13_Handler,    eTPUC_CH14_Handler,    eTPUC_CH15_Handler,    \
        eTPUC_CH16_Handler,    eTPUC_CH17_Handler,    eTPUC_CH18_Handler,    eTPUC_CH19_Handler,    \
        eTPUC_CH20_Handler,    eTPUC_CH21_Handler,    eTPUC_CH22_Handler,    eTPUC_CH23_Handler,    \
        eTPUC_CH24_Handler,    eTPUC_CH25_Handler,    eTPUC_CH26_Handler,    eTPUC_CH27_Handler,    \
        eTPUC_CH28_Handler,    eTPUC_CH29_Handler,    eTPUC_CH30_Handler,    eTPUC_CH31_Handler     \
    }   \
};
#endif /*#RESOURCE_SUPPORT_ETPU*/

static IcufuncMachine icu_funcs[] = {
    {"icu_deinit",icu_de_init},
    {"icuinit", icuinit},
    {"icu_01", icu_01},
    {"icu_02", icu_02},
    //{"icu_03", icu_03},
	{"icu_04", icu_04},
};

void icu_de_init()
{
    Icu_DeInit();
}

void IcuSignalNotification_0(void)
{
	PSPRINTF("notification_0 is ok \n");
}

void IcuSignalNotification_1(void)
{
	PSPRINTF("notification_1 is ok \n");
}
void IcuSignalNotification_2(void)
{
	PSPRINTF("notification_2 is ok \n");
}

void IcuSignalNotification_3(void)
{
	PSPRINTF("notification_3 is ok \n");
}
void IcuSignalNotification_4(void)
{
	PSPRINTF("notification_4 is ok \n");
}
void IcuSignalNotification_5(void)
{
	PSPRINTF("notification_5 is ok \n");
}
void IcuSignalNotification_6(void)
{
	PSPRINTF("notification_6 is ok \n");
}
void IcuSignalNotification_7(void)
{
	PSPRINTF("notification_7 is ok \n");
}
void IcuSignalNotification_8(void)
{
	PSPRINTF("notification_8 is ok \n");
}
void IcuSignalNotification_9(void)
{
	PSPRINTF("notification_9 is ok \n");
}
void IcuSignalNotification_10(void)
{
	PSPRINTF("notification_10 is ok \n");
}
void IcuSignalNotification_11(void)
{
	PSPRINTF("notification_11 is ok \n");
}
void IcuSignalNotification_12(void)
{
	PSPRINTF("notification_12 is ok \n");
}
void IcuSignalNotification_13(void)
{
	PSPRINTF("notification_13 is ok \n");
}
void IcuSignalNotification_14(void)
{
	PSPRINTF("notification_14 is ok \n");
}
void IcuSignalNotification_15(void)
{
	PSPRINTF("notification_15 is ok \n");
}
void IcuSignalNotification_16(void)
{
	PSPRINTF("notification_16 is ok \n");
}
void IcuSignalNotification_17(void)
{
	PSPRINTF("notification_17 is ok \n");
}
void IcuSignalNotification_18(void)
{
	PSPRINTF("notification_18 is ok \n");
}
void IcuSignalNotification_19(void)
{
	PSPRINTF("notification_19 is ok \n");
}
void IcuSignalNotification_20(void)
{
	PSPRINTF("notification_20 is ok \n");
}
void IcuSignalNotification_21(void)
{
	PSPRINTF("notification_21 is ok \n");
}
void IcuSignalNotification_22(void)
{
	PSPRINTF("notification_22 is ok \n");
}
void IcuSignalNotification_23(void)
{
	PSPRINTF("notification_23 is ok \n");
}
void IcuSignalNotification_24(void)
{
	PSPRINTF("notification_24 is ok \n");
}
void IcuSignalNotification_25(void)
{
	PSPRINTF("notification_25 is ok \n");
}
void IcuSignalNotification_26(void)
{
	PSPRINTF("notification_26 is ok \n");
}
void IcuSignalNotification_27(void)
{
	PSPRINTF("notification_27 is ok \n");
}
void IcuSignalNotification_28(void)
{
	PSPRINTF("notification_28 is ok \n");
}
void IcuSignalNotification_29(void)
{
	PSPRINTF("notification_29 is ok \n");
}
void IcuSignalNotification_30(void)
{
	PSPRINTF("notification_30 is ok \n");
}
void IcuSignalNotification_31(void)
{
	PSPRINTF("notification_31 is ok \n");
}
void IcuSignalNotification_32(void)
{
	PSPRINTF("notification_32 is ok \n");
}
void IcuSignalNotification_33(void)
{
	PSPRINTF("notification_33 is ok \n");
}
void IcuSignalNotification_34(void)
{
	PSPRINTF("notification_34 is ok \n");
}
void IcuSignalNotification_35(void)
{
	PSPRINTF("notification_35 is ok \n");
}
void IcuSignalNotification_36(void)
{
	PSPRINTF("notification_36 is ok \n");
}
void IcuSignalNotification_37(void)
{
	PSPRINTF("notification_37 is ok \n");
}
void IcuSignalNotification_38(void)
{
	PSPRINTF("notification_38 is ok \n");
}
void IcuSignalNotification_39(void)
{
	PSPRINTF("notification_39 is ok \n");
}
void IcuSignalNotification_40(void)
{
	PSPRINTF("notification_40 is ok \n");
}
void IcuSignalNotification_41(void)
{
	PSPRINTF("notification_41 is ok \n");
}
void IcuSignalNotification_42(void)
{
	PSPRINTF("notification_42 is ok \n");
}
void IcuSignalNotification_43(void)
{
	PSPRINTF("notification_43 is ok \n");
}
void IcuSignalNotification_44(void)
{
	PSPRINTF("notification_44 is ok \n");
}
void IcuSignalNotification_45(void)
{
	PSPRINTF("notification_45 is ok \n");
}
void IcuSignalNotification_46(void)
{
	PSPRINTF("notification_46 is ok \n");
}
void IcuSignalNotification_47(void)
{
	PSPRINTF("notification_47 is ok \n");
}
void IcuSignalNotification_48(void)
{
	PSPRINTF("notification_48 is ok \n");
}
void IcuSignalNotification_49(void)
{
	PSPRINTF("notification_49 is ok \n");
}
void IcuSignalNotification_50(void)
{
	PSPRINTF("notification_50 is ok \n");
}
void IcuSignalNotification_51(void)
{
	PSPRINTF("notification_51 is ok \n");
}
void IcuSignalNotification_52(void)
{
	PSPRINTF("notification_52 is ok \n");
}
void IcuSignalNotification_53(void)
{
	PSPRINTF("notification_53 is ok \n");
}
void IcuSignalNotification_54(void)
{
	PSPRINTF("notification_54 is ok \n");
}
void IcuSignalNotification_55(void)
{
	PSPRINTF("notification_55 is ok \n");
}
void IcuSignalNotification_56(void)
{
	PSPRINTF("notification_56 is ok \n");
}
void IcuSignalNotification_57(void)
{
	PSPRINTF("notification_57 is ok \n");
}
void IcuSignalNotification_58(void)
{
	PSPRINTF("notification_58 is ok \n");
}
void IcuSignalNotification_59(void)
{
	PSPRINTF("notification_59 is ok \n");
}
void IcuSignalNotification_60(void)
{
	PSPRINTF("notification_60 is ok \n");
}
void IcuSignalNotification_61(void)
{
	PSPRINTF("notification_61 is ok \n");
}
void IcuSignalNotification_62(void)
{
	PSPRINTF("notification_62 is ok \n");
}
void IcuSignalNotification_63(void)
{
	PSPRINTF("notification_63 is ok \n");
}
void IcuSignalNotification_64(void)
{
	PSPRINTF("notification_64 is ok \n");
}
void IcuSignalNotification_65(void)
{}
void IcuSignalNotification_66(void)
{}
void IcuSignalNotification_67(void)
{}
void IcuSignalNotification_68(void)
{}
void IcuSignalNotification_69(void)
{}
void IcuSignalNotification_70(void)
{}
void IcuSignalNotification_71(void)
{}
void IcuSignalNotification_72(void)
{}
void IcuSignalNotification_73(void)
{}
void IcuSignalNotification_74(void)
{}
void IcuSignalNotification_75(void)
{}
void IcuSignalNotification_76(void)
{}
void IcuSignalNotification_77(void)
{}
void IcuSignalNotification_78(void)
{}
void IcuSignalNotification_79(void)
{}
void IcuSignalNotification_80(void)
{}
void IcuSignalNotification_81(void)
{}
void IcuSignalNotification_82(void)
{}
void IcuSignalNotification_83(void)
{}
void IcuSignalNotification_84(void)
{}
void IcuSignalNotification_85(void)
{}
void IcuSignalNotification_86(void)
{}
void IcuSignalNotification_87(void)
{}
void IcuSignalNotification_88(void)
{}
void IcuSignalNotification_89(void)
{}
void IcuSignalNotification_90(void)
{}
void IcuSignalNotification_91(void)
{}
void IcuSignalNotification_92(void)
{}
void IcuSignalNotification_93(void)
{}
void IcuSignalNotification_94(void)
{}
void IcuSignalNotification_95(void)
{}

void icuinit()
{
    Icu_Test_Demo();
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH8_IRQn, INTR_PRI_7);
	(void) INTC_LLD_Set_IRQ_Handle(DMA0_CH8_IRQn, &EDMA_Ch8_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Enable(DMA0_CH8_IRQn);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH12_IRQn, INTR_PRI_7);
	(void) INTC_LLD_Set_IRQ_Handle(DMA0_CH12_IRQn, &EDMA_Ch12_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Enable(DMA0_CH12_IRQn);
    (void) INTC_LLD_Set_IRQ_Priority(DMA1_CH59_IRQn, INTR_PRI_7);
	(void) INTC_LLD_Set_IRQ_Handle(DMA1_CH59_IRQn, &EDMA_Ch123_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Enable(DMA1_CH59_IRQn);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH1_IRQn, INTR_PRI_7);
	(void) INTC_LLD_Set_IRQ_Handle(DMA0_CH1_IRQn, &EDMA_Ch1_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Enable(DMA0_CH1_IRQn);
    (void) INTC_LLD_Set_IRQ_Priority(DMA0_CH0_IRQn, INTR_PRI_7);
	(void) INTC_LLD_Set_IRQ_Handle(DMA0_CH0_IRQn, &EDMA_Ch0_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Enable(DMA0_CH0_IRQn);
	(void) INTC_LLD_Set_IRQ_Priority(DMA1_CH50_IRQn, INTR_PRI_7);
	(void) INTC_LLD_Set_IRQ_Handle(DMA1_CH50_IRQn, &EDMA_Ch114_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Enable(DMA1_CH50_IRQn);
	(void) INTC_LLD_Set_IRQ_Priority(DMA1_CH56_IRQn, INTR_PRI_7);
	(void) INTC_LLD_Set_IRQ_Handle(DMA1_CH56_IRQn, &EDMA_Ch120_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Enable(DMA1_CH56_IRQn);
	/*wake up*/
#if ( defined(CCFC3007PT) || defined(CCFC3007BC)||defined(CCFC3012PT))
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR0_0_7_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR0_8_15_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR0_16_23_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR0_24_31_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR1_0_7_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR1_8_15_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR1_16_23_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR1_24_31_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR0_0_7_IRQn, &WKPU_IRQ0_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR0_8_15_IRQn, &WKPU_IRQ1_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR0_16_23_IRQn, &WKPU_IRQ2_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR0_24_31_IRQn, &WKPU_IRQ3_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR1_0_7_IRQn, &WKPU_IRQ4_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR1_8_15_IRQn, &WKPU_IRQ5_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR1_16_23_IRQn, &WKPU_IRQ6_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR1_24_31_IRQn, &WKPU_IRQ7_Handler);

    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR0_0_7_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR0_8_15_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR0_16_23_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR0_24_31_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR1_0_7_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR1_8_15_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR1_16_23_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR1_24_31_IRQn);
#endif
    /* emios module init */
#if (defined(RESOURCE_SUPPORT_EMIOS0) && defined(RESOURCE_SUPPORT_EMIOS1))
    eMios_Module_Init(0, 10);/* prameter 2: 3008:8, 3007:10*/
    eMios_Module_Init(1, 10);/* prameter 2: 3008:8, 3007:10*/
#else
    eMios_Module_Init(0, 10);/* prameter 2: 3008:8, 3007:10*/
#endif
    /* etpu init */
#ifdef RESOURCE_SUPPORT_ETPU
    ETPU_IC_Init();
#endif
}

void IcuTimestampNotification_0(void)
{

}

void IcuTimestampNotification_1(void)
{

}

void IcuTimestampNotification_2(void)
{}

void IcuTimestampNotification_3(void)
{}

void IcuTimestampNotification_4(void)
{}

void IcuTimestampNotification_5(void)
{}
void Icu_Test_Demo(void)
{
#if ( defined(CCFC3007PT) || defined(CCFC3008PT)||defined(CCFC3012PT))
    INTC_LLD_Set_IRQ_Handle(GTM_TIM0_0_IRQn,GTM_TIM_0_CH_0_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM0_0_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM0_0_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM0_1_IRQn,GTM_TIM_0_CH_1_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM0_1_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM0_1_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM0_2_IRQn,GTM_TIM_0_CH_2_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM0_2_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM0_2_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM0_3_IRQn,GTM_TIM_0_CH_3_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM0_3_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM0_3_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM0_4_IRQn,GTM_TIM_0_CH_4_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM0_4_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM0_4_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM0_5_IRQn,GTM_TIM_0_CH_5_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM0_5_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM0_5_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM0_6_IRQn,GTM_TIM_0_CH_6_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM0_6_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM0_6_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM0_7_IRQn,GTM_TIM_0_CH_7_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM0_7_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM0_7_IRQn);


    INTC_LLD_Set_IRQ_Handle(GTM_TIM1_0_IRQn,GTM_TIM_1_CH_0_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM1_0_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM1_0_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM1_1_IRQn,GTM_TIM_1_CH_1_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM1_1_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM1_1_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM1_2_IRQn,GTM_TIM_1_CH_2_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM1_2_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM1_2_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM1_3_IRQn,GTM_TIM_1_CH_3_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM1_3_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM1_3_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM1_4_IRQn,GTM_TIM_1_CH_4_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM1_4_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM1_4_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM1_5_IRQn,GTM_TIM_1_CH_5_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM1_5_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM1_5_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM1_6_IRQn,GTM_TIM_1_CH_6_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM1_6_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM1_6_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM1_7_IRQn,GTM_TIM_1_CH_7_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM1_7_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM1_7_IRQn);


    INTC_LLD_Set_IRQ_Handle(GTM_TIM2_0_IRQn,GTM_TIM_2_CH_0_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM2_0_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM2_0_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM2_1_IRQn,GTM_TIM_2_CH_1_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM2_1_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM2_1_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM2_2_IRQn,GTM_TIM_2_CH_2_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM2_2_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM2_2_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM2_3_IRQn,GTM_TIM_2_CH_3_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM2_3_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM2_3_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM2_4_IRQn,GTM_TIM_2_CH_4_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM2_4_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM2_4_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM2_5_IRQn,GTM_TIM_2_CH_5_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM2_5_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM2_5_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM2_6_IRQn,GTM_TIM_2_CH_6_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM2_6_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM2_6_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM2_7_IRQn,GTM_TIM_2_CH_7_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM2_7_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM2_7_IRQn);


    INTC_LLD_Set_IRQ_Handle(GTM_TIM3_0_IRQn,GTM_TIM_3_CH_0_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM3_0_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM3_0_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM3_1_IRQn,GTM_TIM_3_CH_1_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM3_1_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM3_1_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM3_2_IRQn,GTM_TIM_3_CH_2_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM3_2_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM3_2_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM3_3_IRQn,GTM_TIM_3_CH_3_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM3_3_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM3_3_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM3_4_IRQn,GTM_TIM_3_CH_4_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM3_4_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM3_4_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM3_5_IRQn,GTM_TIM_3_CH_5_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM3_5_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM3_5_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM3_6_IRQn,GTM_TIM_3_CH_6_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM3_6_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM3_6_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM3_7_IRQn,GTM_TIM_3_CH_7_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM3_7_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM3_7_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM4_0_IRQn,GTM_TIM_4_CH_0_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM4_0_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM4_0_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM4_1_IRQn,GTM_TIM_4_CH_1_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM4_1_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM4_1_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM4_2_IRQn,GTM_TIM_4_CH_2_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM4_2_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM4_2_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM4_3_IRQn,GTM_TIM_4_CH_3_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM4_3_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM4_3_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM4_4_IRQn,GTM_TIM_4_CH_4_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM4_4_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM4_4_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM4_5_IRQn,GTM_TIM_4_CH_5_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM4_5_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM4_5_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM4_6_IRQn,GTM_TIM_4_CH_6_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM4_6_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM4_6_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM4_7_IRQn,GTM_TIM_4_CH_7_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM4_7_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM4_7_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM5_0_IRQn,GTM_TIM_5_CH_0_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM5_0_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM5_0_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM5_1_IRQn,GTM_TIM_5_CH_1_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM5_1_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM5_1_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM5_2_IRQn,GTM_TIM_5_CH_2_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM5_2_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM5_2_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM5_3_IRQn,GTM_TIM_5_CH_3_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM5_3_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM5_3_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM5_4_IRQn,GTM_TIM_5_CH_4_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM5_4_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM5_4_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM5_5_IRQn,GTM_TIM_5_CH_5_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM5_5_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM5_5_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM5_6_IRQn,GTM_TIM_5_CH_6_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM5_6_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM5_6_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM5_7_IRQn,GTM_TIM_5_CH_7_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM5_7_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM5_7_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM6_0_IRQn,GTM_TIM_6_CH_0_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM6_0_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM6_0_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM6_1_IRQn,GTM_TIM_6_CH_1_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM6_1_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM6_1_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM6_2_IRQn,GTM_TIM_6_CH_2_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM6_2_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM6_2_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM6_3_IRQn,GTM_TIM_6_CH_3_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM6_3_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM6_3_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM6_4_IRQn,GTM_TIM_6_CH_4_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM6_4_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM6_4_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM6_5_IRQn,GTM_TIM_6_CH_5_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM6_5_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM6_5_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM6_6_IRQn,GTM_TIM_6_CH_6_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM6_6_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM6_6_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM6_7_IRQn,GTM_TIM_6_CH_7_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM6_7_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM6_7_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM7_0_IRQn,GTM_TIM_7_CH_0_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM7_0_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM7_0_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM7_1_IRQn,GTM_TIM_7_CH_1_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM7_1_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM7_1_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM7_2_IRQn,GTM_TIM_7_CH_2_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM7_2_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM7_2_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM7_3_IRQn,GTM_TIM_7_CH_3_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM7_3_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM7_3_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM7_4_IRQn,GTM_TIM_7_CH_4_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM7_4_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM7_4_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM7_5_IRQn,GTM_TIM_7_CH_5_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM7_5_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM7_5_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM7_6_IRQn,GTM_TIM_7_CH_6_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM7_6_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM7_6_IRQn);

    INTC_LLD_Set_IRQ_Handle(GTM_TIM7_7_IRQn,GTM_TIM_7_CH_7_ISR);
    INTC_LLD_Set_IRQ_Priority(GTM_TIM7_7_IRQn, INTR_PRI_50);
    INTC_LLD_Set_IRQ_Enable(GTM_TIM7_7_IRQn);
#endif
#if (defined(RESOURCE_SUPPORT_EMIOS0) && defined(RESOURCE_SUPPORT_EMIOS1))
    for(uint8_t i = 0;i < 2;i++)
#else
    for(uint8_t i = 0;i < 1;i++)
#endif
    {
        for(uint8_t j = 0;j < 32; j++)
        {
            eMIOS_LLD_SetIRQ(i,j);
        }
    }

#ifdef RESOURCE_SUPPORT_ETPU
    for(uint8_t i = 0;i < 3; i++)
    {
        for(uint8_t j = 0;j < 32; j++)
        {
            eTPU_LLD_SetIRQ(i,j);
        }
    }
#endif
//      GTMINT.GTMMCR.B.MDIS = 0;
//      GTM_CMU.GCLK_NUM.R = 6;
//      GTM_CMU.GCLK_DEN.R = 1;
//      GTM_CMU.CLK_EN.B.EN_CLK0 = 0b10;


}
FUNC(status_t, ICU_CODE) eMIOS_LLD_SetIRQ
(
    VAR(uint8_t, AUTOMATIC) emiosIndex, \
    VAR(uint8_t, AUTOMATIC) ChanNum \
)
{
    VAR(status_t, AUTOMATIC) ret = STATUS_ERROR;
    VAR(IntrId,   AUTOMATIC) irq_num;

    /*Check Module ID*/
    DEV_ASSERT((uint8)emiosIndex < (uint8)EMIOS_INSTANCE_MAX);

    if ((emiosIndex < (uint8)EMIOS_INSTANCE_MAX) && (ChanNum < (uint8)EMIOS_MODULE_CHANNEL_MAX))
    {
        ret = STATUS_SUCCESS;
    }

    if (ret == STATUS_SUCCESS)
    {
        irq_num = EMIOS_IRQ_NUM[emiosIndex][ChanNum];
        (void)INTC_LLD_Set_IRQ_Handle((IntrId)irq_num, \
            (IntrHandle)EMIOS_IRQ_Callback[emiosIndex][ChanNum]);
        (void)INTC_LLD_Set_IRQ_Enable((IntrId)irq_num);
        (void)INTC_LLD_Set_IRQ_Priority((IntrId)irq_num, INTR_PRI_51);
    }

    return ret;
}
#ifdef RESOURCE_SUPPORT_ETPU
FUNC(status_t, ICU_CODE) eTPU_LLD_SetIRQ
(
    VAR(uint8_t, AUTOMATIC) etpuIndex, \
    VAR(uint8_t, AUTOMATIC) ChanNum \
)
{
    VAR(status_t, AUTOMATIC) ret = STATUS_ERROR;
    VAR(IntrId,   AUTOMATIC) irq_num;

    /*Check Module ID*/
    DEV_ASSERT((uint8)etpuIndex < (uint8)ETPU_IRQ_INSTANCE_MAX);

    if ((etpuIndex < (uint8)ETPU_IRQ_INSTANCE_MAX) && (ChanNum < (uint8)ETPU_MODULE_CHANNEL_MAX))
    {
        ret = STATUS_SUCCESS;
    }

    if (ret == STATUS_SUCCESS)
    {
        irq_num = ETPU_IRQ_NUM[etpuIndex][ChanNum];
        (void)INTC_LLD_Set_IRQ_Handle((IntrId)irq_num, \
            (IntrHandle)ETPU_IRQ_Callback[etpuIndex][ChanNum]);
        (void)INTC_LLD_Set_IRQ_Enable((IntrId)irq_num);
        (void)INTC_LLD_Set_IRQ_Priority((IntrId)irq_num, INTR_PRI_51);
    }

    return ret;
}
#endif /*#RESOURCE_SUPPORT_ETPU*/
void icu_01(void)
{
    Icu_EdgeNumberType EdgeNumber = 0;
    Icu_Init(&Icu_Cfg);
    Icu_SetMode((Icu_ModeType)0);
    Icu_ResetEdgeCount(23);
    Icu_EnableEdgeCount(23);
    Gpt_Stm_LLD_DelayMs(STM1,100U);
    Icu_DisableEdgeCount(23);
    EdgeNumber = Icu_GetEdgeNumbers(23);
    PSPRINTF("%d\n",EdgeNumber);
}

void icu_02(void)
{
    Icu_DutyCycleType DutyCycle = {0};
    Icu_Init(&Icu_Cfg);
    Icu_StartSignalMeasurement(3);
    Gpt_Stm_LLD_DelayMs(STM1,100U);
    Icu_GetDutyCycleValues(3,&DutyCycle);
    Icu_StopSignalMeasurement(3);
    PSPRINTF("%d %d\n",DutyCycle.ActiveTime,DutyCycle.PeriodTime);
}

void wakeup_intc()
{
#if defined(CCFC3007BC)
	/*wake up*/
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR0_0_7_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR0_8_15_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR0_16_23_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR0_24_31_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR1_0_7_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR1_8_15_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR1_16_23_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Priority(WKPU_WISR1_24_31_IRQn, INTR_PRI_7);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR0_0_7_IRQn, &WKPU_IRQ0_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR0_8_15_IRQn, &WKPU_IRQ1_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR0_16_23_IRQn, &WKPU_IRQ2_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR0_24_31_IRQn, &WKPU_IRQ3_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR1_0_7_IRQn, &WKPU_IRQ4_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR1_8_15_IRQn, &WKPU_IRQ5_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR1_16_23_IRQn, &WKPU_IRQ6_Handler);
    (void) INTC_LLD_Set_IRQ_Handle(WKPU_WISR1_24_31_IRQn, &WKPU_IRQ7_Handler);

    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR0_0_7_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR0_8_15_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR0_16_23_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR0_24_31_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR1_0_7_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR1_8_15_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR1_16_23_IRQn);
    (void) INTC_LLD_Set_IRQ_Enable(WKPU_WISR1_24_31_IRQn);
#endif
}

void icu_04(void)
{
	wakeup_intc();
	Icu_Init(&Icu_Cfg);
	Icu_EnableNotification(15);
    Icu_EnableWakeup(15);
//    for(volatile int i=0;i<100000000;i++);
    Icu_EnableEdgeDetection(15);

    Mcu_SetMode(3);
}
int icu_func(int argc, char *agrv[])
{

    if ((argc > 3) || (argc < 2)) {
        PSPRINTF("error: The number of parameters exceeds 3 or is less than 2\n");
        return 1;
    }

    if (argc == 2)
    {
        if (!strcmp(agrv[1], "help"))
        {
            PSPRINTF("help ----- CMD ------- ID of the test case\r\n");
                    
            for(uint16 i = 0; i < ICU_TEST_CASE_MAX; i++)
            {
                PSPRINTF("%s\n", icu_funcs[i].name);
            }
        }
        else
        {
            for(uint16 i = 0; i < ICU_TEST_CASE_MAX; i++)
            {
                if(!strcmp(agrv[1], icu_funcs[i].name))
                {
                    icu_funcs[i].icufunc();
                    return 0;
                }
            }
            PSPRINTF("error: Input invalid parameters[%s], please Use the 'Icu_test help' command to see the supported test instructions\n", agrv[1]);
        }
    }
    return 0;

}

#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), icu_test, icu_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
