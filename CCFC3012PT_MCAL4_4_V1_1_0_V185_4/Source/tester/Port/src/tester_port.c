#include "Port.h"
#include "Port_Cfg.h"
#include "Det.h"
#include "Mcu.h"
#include "Mcu_Cfg.h"
#include "tester_port.h"
#include "shell.h"
#include "intc_lld.h"
#include "status.h"

#if (PORT_SET_SIUL2_API == STD_ON)
void eirq0_callBack(void);
void eirq1_callBack(void);
void eirq2_callBack(void);
void eirq3_callBack(void);
void eirq4_callBack(void);
void eirq5_callBack(void);
void eirq6_callBack(void);
void eirq7_callBack(void);
void eirq8_callBack(void);
void eirq9_callBack(void);
void eirq10_callBack(void);
void eirq11_callBack(void);
void eirq12_callBack(void);
void eirq13_callBack(void);
void eirq14_callBack(void);
void eirq15_callBack(void);
#endif

int port_func(int argc, char *agrv[]);
Std_VersionInfoType versioninfo;
static PortfuncMachine port_test_funcs[] = {
        {"port_test_0000", port_test_0000},
        {"port_test_0001", port_test_0001},
        {"port_test_0002", port_test_0002},
        {"port_test_0003", port_test_0003},
        {"port_test_0004", port_test_0004},
        {"port_test_0005", port_test_0005},
        {"port_test_0006", port_test_0006},
        {"port_test_0007", port_test_0007},
        {"port_test_0008", port_test_0008},
		{"port_test_0009", port_test_0009},
#if (PORT_SET_SIUL2_API == STD_ON)
		{"port_test_0010", port_test_0010}
#endif
};
extern boolean TesterDemoPORT;
void port_test_0000(void)
{
    Det_ModuleId=0;
    Port_Init(NULL);                      //Port_Init
    if ((Det_ModuleId == PORT_MODULE_ID && Det_ErrorId==PORT_E_INIT_FAILED)){
        PSPRINTF("PORT_0000 is ok\n");
        PSPRINTF("Det_ErrorId: PORT_E_INIT_FAILED\n\n");
    } else {
        PSPRINTF("PORT_0000 is not ok\n\n");
    }
}

void port_test_0001(void)
{
    Det_ModuleId=0;
    Port_Init(&PortContainer);                      //Port_Init
    if ((Det_ModuleId != PORT_MODULE_ID)){
        PSPRINTF("PORT_0001 is ok\n\n");
    } else {
        PSPRINTF("PORT_0001 is not ok\n\n");
    }
}

void port_test_0002(void)
{
    Det_ModuleId=0;
    Port_SetPinDirection(0xFFFFFFFF,PORT_PIN_OUT);  //Pin
    if ((Det_ModuleId == PORT_MODULE_ID && Det_ErrorId==PORT_E_PARAM_PIN)){
        PSPRINTF("PORT_0002 is ok\n");
        PSPRINTF("Det_ErrorId: PORT_E_PARAM_PIN\n\n");
    } else {
        PSPRINTF("PORT_0002 is not ok\n\n");
    }
}

void port_test_0003(void)
{
    Det_ModuleId=0;
    Port_SetPinDirection(10,PORT_PIN_OUT);          //Port_SetPinDirection
    if ((Det_ModuleId != PORT_MODULE_ID)){
        PSPRINTF("PORT_0003 is ok\n\n");
    } else {
        PSPRINTF("PORT_0003 is not ok\n\n");
    }
}

void port_test_0004(void)
{
    Det_ModuleId=0;
    Port_RefreshPortDirection();                    //Port_RefreshPortDirection
    if ((Det_ModuleId != PORT_MODULE_ID)){
        PSPRINTF("PORT_0004 is ok\n\n");
    } else {
        PSPRINTF("PORT_0004 is not ok\n\n");
    }
}

void port_test_0005(void)
{
    Det_ModuleId=0;
    Port_GetVersionInfo(NULL);                      //Port_GetVersionInfo
    if ((Det_ModuleId == PORT_MODULE_ID && Det_ErrorId==PORT_E_PARAM_POINTER)){
        PSPRINTF("PORT_0005 is ok\n");
        PSPRINTF("Det_ErrorId: PORT_E_PARAM_POINTER\n\n");
    } else {
        PSPRINTF("PORT_0005 is not ok\n\n");
    }
}

void port_test_0006(void)
{
    Det_ModuleId=0;
    Port_GetVersionInfo(&versioninfo);              //Port_GetVersionInfo
    if ((Det_ModuleId != PORT_MODULE_ID)){
        PSPRINTF("PORT_0006 is ok\n\n");
    } else {
        PSPRINTF("PORT_0006 is not ok\n\n");
    }
}

void port_test_0007(void)
{
    Det_ModuleId=0;
    Port_SetPinMode(0xFFFF,PORT_GPIO_MODE);  //Pin
    if ((Det_ModuleId == PORT_MODULE_ID && Det_ErrorId==PORT_E_PARAM_PIN)){
        PSPRINTF("PORT_0007 is ok\n");
        PSPRINTF("Det_ErrorId: PORT_E_PARAM_PIN\n\n");
    } else {
        PSPRINTF("PORT_0007 is not ok\n\n");
    }
}

void port_test_0008(void)
{
    Det_ModuleId=0;
    Port_SetPinMode(34,PORT_GPIO_MODE);          //Port_SetPinMode
    if ((Det_ModuleId != PORT_MODULE_ID)){
        PSPRINTF("PORT_0008 is ok\n\n");
    } else {
        PSPRINTF("PORT_0008 is not ok\n\n");
    }
}

void port_test_0009(void)
{
	uint8_t coreMapArray = GetCoreID();
    PSPRINTF("[Port_Core] : %d\r\n",coreMapArray);
    Port_Init(&PortContainer);
    if(coreMapArray == 0)
    {
    	Det_ModuleId=0;
		Port_SetPinMode(34,PORT_GPIO_MODE);
		uint8 pin_index1 = PORT_GPIO_MODE;
		if ((Det_ModuleId != PORT_MODULE_ID)){
			PSPRINTF("PORT_0009 core 0 is ok,PORT50_SIUL2_GPIO is %d\n\n",pin_index1);
		} else {
			PSPRINTF("PORT_0009 core 0 is not ok\n\n");
		}
    }
    else if(coreMapArray == 1)
    {
    	Det_ModuleId=0;
		Port_SetPinMode(34,PORT_GPIO_MODE);
		uint8 pin_index2 = PORT_GPIO_MODE;
		if ((Det_ModuleId != PORT_MODULE_ID)){
			PSPRINTF("PORT_0009 core 1 is ok,PORT63_SIUL2_GPIO is %d\n\n",pin_index2);
		} else {
			PSPRINTF("PORT_0009 core 2 is not ok\n\n");
		}
    }
    else if(coreMapArray == 2)
    {
    	Det_ModuleId=0;
		Port_SetPinMode(34,PORT_GPIO_MODE);
		uint8 pin_index3 = PORT_GPIO_MODE;
		if ((Det_ModuleId != PORT_MODULE_ID)){
			PSPRINTF("PORT_0009 core 2 is ok,PORT56_SIUL2_GPIO is %d\n\n",pin_index3);
		} else {
			PSPRINTF("PORT_0009 core 2 is not ok\n\n");
		}
    }
}

#if (PORT_SET_SIUL2_API == STD_ON)
extern callBackFunction eirq_cb[EIRQ_MAX_NUM];
/*
 * @brief Global Interrupt SIUL2 external interrupt 0 Handler
 *
 * In case of interrupt checks the triggered source for
 * EIRQ0 | EIRQ1 | EIRQ2 | EIRQ3 |
 * EIRQ4 | EIRQ5 | EIRQ6 | EIRQ7
 */
void SIUL2_EIRQ_0_IRQHandler(void)
{
   uint32 eirq_n, tmp_disr0;

   tmp_disr0 = SIUL.ISR.R;

   for (eirq_n = EIRQ0; eirq_n <= EIRQ7; eirq_n++)
   {
       if ((tmp_disr0 & (1UL << eirq_n)) != 0UL)
       {
    	   SIUL.ISR.R = (1UL << eirq_n);
           if (eirq_cb[eirq_n] != NULL_PTR)
           {
               eirq_cb[eirq_n]();
           }
       }
   }
}

/*
 * @brief Global Interrupt SIUL2 external interrupt 1 Handler
 *
 * In case of interrupt checks the triggered source for
 * EIRQ8  | EIRQ9  | EIRQ10 | EIRQ11 |
 * EIRQ12 | EIRQ13 | EIRQ14 | EIRQ15
 */
void SIUL2_EIRQ_1_IRQHandler(void)
{
   uint32 eirq_n, tmp_disr0;

   tmp_disr0 = SIUL.ISR.R;

   for (eirq_n = EIRQ8; eirq_n <= EIRQ15; eirq_n++)
   {
       if ((tmp_disr0 & (1UL << eirq_n)) != 0UL)
       {
    	   SIUL.ISR.R = (1UL << eirq_n);
           if (eirq_cb[eirq_n] != NULL_PTR)
           {
               eirq_cb[eirq_n]();
           }
       }
   }
}
/*
 * @brief Global Interrupt SIUL2 external interrupt 1 Handler
 *
 * In case of interrupt checks the triggered source for
 * EIRQ16 | EIRQ17 | EIRQ18 | EIRQ19 |
 * EIRQ20 | EIRQ21 | EIRQ22 | EIRQ23
 */
void SIUL2_EIRQ_2_IRQHandler(void)
{
   uint32 eirq_n, tmp_disr0;

   tmp_disr0 = SIUL.ISR.R;

   for (eirq_n = EIRQ16; eirq_n <= EIRQ23; eirq_n++)
   {
       if ((tmp_disr0 & (1UL << eirq_n)) != 0UL)
       {
    	   SIUL.ISR.R = (1UL << eirq_n);
           if (eirq_cb[eirq_n] != NULL_PTR)
           {
               eirq_cb[eirq_n]();
           }
       }
   }
}

void port_test_0010(void)
{
	status_t ret = STATUS_SUCCESS;
	/* set interrupt processor */
	ret = INTC_LLD_Set_IRQ_Priority(SIUL_EPORT0_IRQn, INTR_PRI_1);
	if (ret != STATUS_SUCCESS)
	{
		return;
	}
	ret = INTC_LLD_Set_IRQ_Handle(SIUL_EPORT0_IRQn, &SIUL2_EIRQ_0_IRQHandler);
	if (ret != STATUS_SUCCESS)
	{
		return;
	}
	ret = INTC_LLD_Set_IRQ_Enable(SIUL_EPORT0_IRQn);
	if (ret != STATUS_SUCCESS)
	{
		return;
	}
	ret = INTC_LLD_Set_IRQ_Priority(SIUL_EPORT1_IRQn, INTR_PRI_1);
	if (ret != STATUS_SUCCESS)
	{
		return;
	}
	ret = INTC_LLD_Set_IRQ_Handle(SIUL_EPORT1_IRQn, &SIUL2_EIRQ_1_IRQHandler);
	if (ret != STATUS_SUCCESS)
	{
		return;
	}
	ret = INTC_LLD_Set_IRQ_Enable(SIUL_EPORT1_IRQn);
	if (ret != STATUS_SUCCESS)
	{
		return;
	}
	ret = INTC_LLD_Set_IRQ_Priority(SIUL_EPORT2_IRQn, INTR_PRI_1);
	if (ret != STATUS_SUCCESS)
	{
		return;
	}
	ret = INTC_LLD_Set_IRQ_Handle(SIUL_EPORT2_IRQn, &SIUL2_EIRQ_2_IRQHandler);
	if (ret != STATUS_SUCCESS)
	{
		return;
	}
	ret = INTC_LLD_Set_IRQ_Enable(SIUL_EPORT2_IRQn);
	if (ret != STATUS_SUCCESS)
	{
		return;
	}
}
#endif

#if (PORT_SET_SIUL2_API == STD_ON)
void eirq0_callBack(void) /* PRQA S 1505,3673 */
{
PSPRINTF("enter eirq0 callback\n\n");
}
/*
 * @brief EIRQ_4 CallBack function
 */
void eirq1_callBack(void)
{
PSPRINTF("enter eirq1 callback\n\n");
}
/*
 * @brief EIRQ_2 CallBack function
 */
void eirq2_callBack(void)
{
PSPRINTF("enter eirq2 callback\n\n");
}
/*
 * @brief EIRQ_3 CallBack function
 */
void eirq3_callBack(void)
{
PSPRINTF("enter eirq3 callback\n\n");
}
/*
 * @brief EIRQ_4 CallBack function
 */
void eirq4_callBack(void)
{
PSPRINTF("enter eirq4 callback\n\n");
}
/*
 * @brief EIRQ_5 CallBack function
 */
void eirq5_callBack(void) /* PRQA S 1505,3673 */
{
PSPRINTF("enter eirq5 callback\n\n");
}
/*
 * @brief EIRQ_6 CallBack function
 */
void eirq6_callBack(void) /* PRQA S 1505,3673 */
{
PSPRINTF("enter eirq6 callback\n\n");
}
/*
 * @brief EIRQ_7 CallBack function
 */
void eirq7_callBack(void) /* PRQA S 1505,3673 */
{
PSPRINTF("enter eirq7 callback\n\n");
}
/*
 * @brief EIRQ_8 CallBack function
 */
void eirq8_callBack(void)
{
PSPRINTF("enter eirq8 callback\n\n");
}
/*
 * @brief EIRQ_9 CallBack function
 */
void eirq9_callBack(void)
{
PSPRINTF("enter eirq9 callback\n\n");
}
/*
 * @brief EIRQ_10 CallBack function
 */
void eirq10_callBack(void) /* PRQA S 1505,3673 */
{
PSPRINTF("enter eirq10 callback\n\n");
}
/*
 * @brief EIRQ_11 CallBack function
 */
void eirq11_callBack(void)
{
PSPRINTF("enter eirq11 callback\n\n");
}
/*
 * @brief EIRQ_12 CallBack function
 */
void eirq12_callBack(void) /* PRQA S 1505,3673 */
{
PSPRINTF("enter eirq12 callback\n\n");
}
/*
 * @brief EIRQ_13 CallBack function
 */
void eirq13_callBack(void) /* PRQA S 1505,3673 */
{
PSPRINTF("enter eirq13 callback\n\n");
}
/*
 * @brief EIRQ_14 CallBack function
 */
void eirq14_callBack(void) /* PRQA S 1505,3673 */
{
PSPRINTF("enter eirq14 callback\n\n");
}
/*
 * @brief EIRQ_15 CallBack function
 */
void eirq15_callBack(void) /* PRQA S 1505,3673 */
{
PSPRINTF("enter eirq15 callback\n\n");
}


#endif

int port_func(int argc, char *agrv[])
{
    if (argc!=2)
    {
        PSPRINTF("error: Parameter number error\n");
        return 0;
    }

    uint32 id = (uint32)atoi(agrv[1]);

    if(id>(sizeof(port_test_funcs)/sizeof(port_test_funcs[0]))-1)
    {
        PSPRINTF("error: Parameter out of range\n");
        return 0;
    }

    if(port_test_funcs[id].portfunc==NULL)
    {
        PSPRINTF("error: Test case is undefined\n");
        return 0;
    }

    port_test_funcs[id].portfunc();

    return 0;
}
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), port_test, port_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
