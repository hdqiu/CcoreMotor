#include <string.h>
#include "tester_lin.h"
#include "common.h"
#include "console.h"
#include "intc_lld.h"
#include "shell.h"
#include "Lin_Cfg.h"
#include "Lin_LLDriver.h"
#if (LIN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
int tsc_lin_func(int argc, char *agrv[]);
#define LIN_TEST_CASE_MAX sizeof(lin_funcs) / sizeof(LinfuncMachine)

#define LIN_GETSTATUS_TIMEOUT 500U
#define LIN_SEND_DATA_LEN  0x8u

#define PRINTF_FUNCNAME() PSPRINTF("\r\n[%s]\r\n", __func__);

/* Specification of Lin Driver : [SWS_Lin_00156] */
FUNC(void, LIN_CODE) Lin_LLD_Init_IrqIsrEnable(void)
{
#if UART_MULTI_CORE_CONFIG
        if (GetCoreID()==0)
		{
	        (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD0_RX_IRQn, INTR_PRI_40);
	        (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD0_RX_IRQn, &LINFLEX0_LLD_RXI_IRQ_HANDLER);
	        (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD0_RX_IRQn);
	        (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD0_TX_IRQn, INTR_PRI_40);
	        (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD0_TX_IRQn, &LINFLEX0_LLD_TXI_IRQ_HANDLER);
	        (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD0_TX_IRQn);
	        (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD0_ERR_IRQn, INTR_PRI_40);
	        (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD0_ERR_IRQn, &LINFLEX0_LLD_ERR_IRQ_HANDLER);
	        (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD0_ERR_IRQn);
		}
		else if (GetCoreID()==1)
        {
            (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD1_RX_IRQn, INTR_PRI_40);
            (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD1_RX_IRQn, &LINFLEX1_LLD_RXI_IRQ_HANDLER);
            (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD1_RX_IRQn);
            (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD1_TX_IRQn, INTR_PRI_40);
            (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD1_TX_IRQn, &LINFLEX1_LLD_TXI_IRQ_HANDLER);
            (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD1_TX_IRQn);
            (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD1_ERR_IRQn, INTR_PRI_40);
            (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD1_ERR_IRQn, &LINFLEX1_LLD_ERR_IRQ_HANDLER);
            (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD1_ERR_IRQn);
        }
		else if (GetCoreID()==2)
        {
            (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD14_RX_IRQn, INTR_PRI_40);
            (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD14_RX_IRQn, &LINFLEX14_LLD_RXI_IRQ_HANDLER);
            (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD14_RX_IRQn);
            (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD14_TX_IRQn, INTR_PRI_40);
            (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD14_TX_IRQn, &LINFLEX14_LLD_TXI_IRQ_HANDLER);
            (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD14_TX_IRQn);
            (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD14_ERR_IRQn, INTR_PRI_40);
            (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD14_ERR_IRQn, &LINFLEX14_LLD_ERR_IRQ_HANDLER);
            (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD14_ERR_IRQn);
        }
#else
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD0_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD0_RX_IRQn, &LINFLEX0_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD0_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD0_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD0_TX_IRQn, &LINFLEX0_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD0_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD0_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD0_ERR_IRQn, &LINFLEX0_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD0_ERR_IRQn);

			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD1_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD1_RX_IRQn, &LINFLEX1_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD1_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD1_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD1_TX_IRQn, &LINFLEX1_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD1_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD1_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD1_ERR_IRQn, &LINFLEX1_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD1_ERR_IRQn);

			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD14_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD14_RX_IRQn, &LINFLEX14_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD14_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD14_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD14_TX_IRQn, &LINFLEX14_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD14_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD14_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD14_ERR_IRQn, &LINFLEX14_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD14_ERR_IRQn);

			 (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD2_RX_IRQn, INTR_PRI_40);
			 (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD2_RX_IRQn, &LINFLEX2_LLD_RXI_IRQ_HANDLER);
			 (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD2_RX_IRQn);
			 (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD2_TX_IRQn, INTR_PRI_40);
			 (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD2_TX_IRQn, &LINFLEX2_LLD_TXI_IRQ_HANDLER);
			 (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD2_TX_IRQn);
			 (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD2_ERR_IRQn, INTR_PRI_40);
			 (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD2_ERR_IRQn, &LINFLEX2_LLD_ERR_IRQ_HANDLER);
			 (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD2_ERR_IRQn);

			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD3_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD3_RX_IRQn, &LINFLEX3_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD3_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD3_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD3_TX_IRQn, &LINFLEX3_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD3_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD3_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD3_ERR_IRQn, &LINFLEX3_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD3_ERR_IRQn);

			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD4_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD4_RX_IRQn, &LINFLEX4_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD4_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD4_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD4_TX_IRQn, &LINFLEX4_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD4_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD4_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD4_ERR_IRQn, &LINFLEX4_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD4_ERR_IRQn);

#if 0       /* LIN_5 is used for UART */
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD5_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD5_RX_IRQn, &LINFLEX5_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD5_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD5_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD5_TX_IRQn, &LINFLEX5_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD5_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD5_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD5_ERR_IRQn, &LINFLEX5_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD5_ERR_IRQn);
#endif
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD6_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD6_RX_IRQn, &LINFLEX6_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD6_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD6_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD6_TX_IRQn, &LINFLEX6_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD6_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD6_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD6_ERR_IRQn, &LINFLEX6_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD6_ERR_IRQn);

			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD7_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD7_RX_IRQn, &LINFLEX7_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD7_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD7_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD7_TX_IRQn, &LINFLEX7_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD7_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD7_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD7_ERR_IRQn, &LINFLEX7_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD7_ERR_IRQn);

			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD8_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD8_RX_IRQn, &LINFLEX8_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD8_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD8_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD8_TX_IRQn, &LINFLEX8_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD8_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD8_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD8_ERR_IRQn, &LINFLEX8_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD8_ERR_IRQn);

			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD9_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD9_RX_IRQn, &LINFLEX9_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD9_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD9_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD9_TX_IRQn, &LINFLEX9_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD9_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD9_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD9_ERR_IRQn, &LINFLEX9_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD9_ERR_IRQn);

			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD10_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD10_RX_IRQn, &LINFLEX10_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD10_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD10_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD10_TX_IRQn, &LINFLEX10_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD10_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD10_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD10_ERR_IRQn, &LINFLEX10_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD10_ERR_IRQn);

			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD11_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD11_RX_IRQn, &LINFLEX11_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD11_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD11_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD11_TX_IRQn, &LINFLEX11_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD11_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD11_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD11_ERR_IRQn, &LINFLEX11_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD11_ERR_IRQn);

			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD12_RX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD12_RX_IRQn, &LINFLEX12_LLD_RXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD12_RX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD12_TX_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD12_TX_IRQn, &LINFLEX12_LLD_TXI_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD12_TX_IRQn);
			(void)INTC_LLD_Set_IRQ_Priority(LINFLEXD12_ERR_IRQn, INTR_PRI_40);
			(void)INTC_LLD_Set_IRQ_Handle(LINFLEXD12_ERR_IRQn, &LINFLEX12_LLD_ERR_IRQ_HANDLER);
			(void)INTC_LLD_Set_IRQ_Enable(LINFLEXD12_ERR_IRQn);

	        (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD15_RX_IRQn, INTR_PRI_40);
	        (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD15_RX_IRQn, &LINFLEX15_LLD_RXI_IRQ_HANDLER);
	        (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD15_RX_IRQn);
	        (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD15_TX_IRQn, INTR_PRI_40);
	        (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD15_TX_IRQn, &LINFLEX15_LLD_TXI_IRQ_HANDLER);
	        (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD15_TX_IRQn);
	        (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD15_ERR_IRQn, INTR_PRI_40);
	        (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD15_ERR_IRQn, &LINFLEX15_LLD_ERR_IRQ_HANDLER);
	        (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD15_ERR_IRQn);

			 (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD16_RX_IRQn, INTR_PRI_40);
			 (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD16_RX_IRQn, &LINFLEX16_LLD_RXI_IRQ_HANDLER);
			 (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD16_RX_IRQn);
			 (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD16_TX_IRQn, INTR_PRI_40);
			 (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD16_TX_IRQn, &LINFLEX16_LLD_TXI_IRQ_HANDLER);
			 (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD16_TX_IRQn);
			 (void)INTC_LLD_Set_IRQ_Priority(LINFLEXD16_ERR_IRQn, INTR_PRI_40);
			 (void)INTC_LLD_Set_IRQ_Handle(LINFLEXD16_ERR_IRQn, &LINFLEX16_LLD_ERR_IRQ_HANDLER);
			 (void)INTC_LLD_Set_IRQ_Enable(LINFLEXD16_ERR_IRQn);

#endif
}


VAR(uint8,AUTOMATIC) linSdu[8] = {0};
uint32 ulGetStatusTimeout = LIN_GETSTATUS_TIMEOUT;


static uint8 lindata[][LIN_SEND_DATA_LEN] = {
    {0x00u, 0x50u, 0x90u, 0xD0u, 0x10u, 0xa1u, 0x42u, 0x85u},
    {0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u},
    {0x02u, 0x08u, 0x36u, 0xD0u, 0x10u, 0xa1u, 0x42u, 0x86u},
    {0x45u, 0x39u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u}
};

const Lin_PduType linPduInfo[]={
    {
        .Pid= 0x17u,
        .Cs = LIN_CLASSIC_CS,
        .Drc= LIN_FRAMERESPONSE_TX,
        .Dl = LIN_SEND_DATA_LEN,
        .SduPtr = lindata[0],
    },

    {
        .Pid= 0x18u,
        .Cs = LIN_CLASSIC_CS,
        .Drc= LIN_FRAMERESPONSE_RX,
        .Dl = LIN_SEND_DATA_LEN,
        .SduPtr =  lindata[1],
    },
    {
        .Pid= 0x19u,
        .Cs = LIN_ENHANCED_CS,
        .Drc= LIN_FRAMERESPONSE_TX,
        .Dl = LIN_SEND_DATA_LEN,
        .SduPtr = lindata[2],
    },

    {
        .Pid= 0x1Au,
        .Cs = LIN_ENHANCED_CS,
        .Drc= LIN_FRAMERESPONSE_RX,
        .Dl = LIN_SEND_DATA_LEN,
        .SduPtr =  lindata[3],
    },
};


static LinfuncMachine lin_funcs[] = {
#if (LIN_MASTER_NODE_USED == STD_ON)
   {"LIN_0001", TSC_Lin_0001},
#endif
   {"LIN_0002", TSC_Lin_0002},
   {"LIN_0003", TSC_Lin_0003},
};


extern VAR(Lin_DriveState_Type,LIN_VAR) eLin_DrvStatus[LIN_MAX_CORES];
extern volatile VAR(uint8, LIN_VAR) u8Lin_ChStatus[LIN_HW_MAX_AVAILABLE_MODULES];




/***************************Transmit-Receive************************************/
/*
LinChannelId: 0
BaudRate: 9600
BreakLength: 13
LinHwChannel: 0
LinNodeType: Master
*/
#if (LIN_MASTER_NODE_USED == STD_ON)
void TSC_Lin_0001(const Lin_ConfigType *LinDriverConfig)
{
    VAR(uint8, AUTOMATIC) *pu8linSduPtr[1];
    Std_ReturnType u8Lin_ReturnValue;PRINTF_FUNCNAME();
    pu8linSduPtr[0] = linSdu;

    Lin_Init(LinDriverConfig);

    u8Lin_ReturnValue = Lin_GetStatus(LinDriverConfig->pLin_Channel[0]->u8LinChannelID, pu8linSduPtr);
    if (u8Lin_ReturnValue != LIN_CH_SLEEP)
    {
        PSPRINTF("[Lin_0001] u8Lin_ReturnValue != LIN_CH_SLEEP\r\n");
        return;
    }
    else
    {
        PSPRINTF("[Lin_0001] Lin_GetStatus u8Lin_ReturnValue = %d\r\n", u8Lin_ReturnValue);
    }

    u8Lin_ReturnValue = Lin_Wakeup(LinDriverConfig->pLin_Channel[0]->u8LinChannelID);
    if (u8Lin_ReturnValue != E_OK)
    {
        PSPRINTF("[Lin_0001]LIN Error %d returned by Lin_WakeUp(LIN_LOGICAL_CHANNEL)\n", u8Lin_ReturnValue);
        return;
    }
    else
    {
        PSPRINTF("[Lin_0001] Lin_Wakeup u8Lin_ReturnValue = %d\r\n", u8Lin_ReturnValue);
    }

    u8Lin_ReturnValue = Lin_SendFrame(LinDriverConfig->pLin_Channel[0]->u8LinChannelID, &linPduInfo[2]);
    if (u8Lin_ReturnValue != E_OK)
    {
        PSPRINTF("[Lin_0001]LIN Error %d returned by Lin_SendFrame\n", u8Lin_ReturnValue);
        return;
    }else
    {
        PSPRINTF("[Lin_0001] Lin_SendFrame u8Lin_ReturnValue = %d\r\n", u8Lin_ReturnValue);
    }

    ulGetStatusTimeout = LIN_GETSTATUS_TIMEOUT;
    do
    {
        u8Lin_ReturnValue = Lin_GetStatus(LinDriverConfig->pLin_Channel[0]->u8LinChannelID, pu8linSduPtr);
        if (u8Lin_ReturnValue == LIN_TX_OK || u8Lin_ReturnValue == LIN_OPERATIONAL) // send success
        {
            PSPRINTF("[Lin_0001] Lin_GetStatus u8Lin_ReturnValue = %d\r\n", u8Lin_ReturnValue);
            break;
        }
        else
        {
            if (ulGetStatusTimeout > 0)
            {
                (void)delay_ms(1);
                ulGetStatusTimeout--;
            }
            else
            {
                PSPRINTF("[Lin_0001]LIN Error - transmission timeout : %d\n", u8Lin_ReturnValue);
                return;
            }
        }
    } while (1);

    (void)delay_ms(500);

    u8Lin_ReturnValue = Lin_SendFrame(LinDriverConfig->pLin_Channel[0]->u8LinChannelID, &linPduInfo[3]);
    if (u8Lin_ReturnValue != E_OK)
    {
        PSPRINTF("[Lin_0001]LIN Error %d returned by Lin_SendFrame\n", u8Lin_ReturnValue);
        return;
    }
    else
    {
        PSPRINTF("[Lin_0001] Lin_SendFrame u8Lin_ReturnValue = %d\r\n", u8Lin_ReturnValue);
    }

    ulGetStatusTimeout = LIN_GETSTATUS_TIMEOUT;
    do
    {
        u8Lin_ReturnValue = Lin_GetStatus(LinDriverConfig->pLin_Channel[0]->u8LinChannelID, pu8linSduPtr);
        if (u8Lin_ReturnValue == LIN_RX_OK || u8Lin_ReturnValue == LIN_OPERATIONAL) // recvive success
        {
            PSPRINTF("[Lin_0001] recv response: ");
            for(int i = 0; i < 8; i++)
            {
                PSPRINTF("%x ", (pu8linSduPtr[0][i]));
            }
            PSPRINTF("\r\n");
            break;
        }
        else
        {
            if (ulGetStatusTimeout > 0)
            {
                ulGetStatusTimeout--;
                (void)delay_ms(10);
            }
            else
            {
                PSPRINTF("[Lin_0001]LIN Error - transmission timeout : %d\n", u8Lin_ReturnValue);
                return;
            }
        }
    } while (1);
}
#endif
/*
LinChannelId: 0
BaudRate: 9600
BreakLength: 13
LinHwChannel: 0
LinNodeType: SLAVE
*/
void TSC_Lin_0002(const Lin_ConfigType *LinDriverConfig)
{
    Std_ReturnType u8Lin_ReturnValue;PRINTF_FUNCNAME();

    Lin_Init(LinDriverConfig);

    u8Lin_ReturnValue = Lin_Wakeup(LinDriverConfig->pLin_Channel[0]->u8LinChannelID);

    if (u8Lin_ReturnValue != E_OK)
    {
        PSPRINTF("[Lin_0002]LIN Error %d returned by Lin_WakeUp(LIN_LOGICAL_CHANNEL)\n", u8Lin_ReturnValue);
        return;
    }else
    {
        PSPRINTF("[Lin_0002] Lin_Wakeup u8Lin_ReturnValue = %d\r\n", u8Lin_ReturnValue);
        PSPRINTF("[Lin_0002] Lin Channel%d state: %d\r\n", LinDriverConfig->pLin_Channel[0]->u8LinChannelID, \
                u8Lin_ChStatus[LinDriverConfig->pLin_Channel[0]->u8LinHwChannel]);
    }
}

/*
LinChannelId: 0
BaudRate: 9600
BreakLength: 13
LinHwChannel: 0
LinNodeType: SLAVE
*/

void TSC_Lin_0003(const Lin_ConfigType *LinDriverConfig)
{
    Std_ReturnType u8Lin_ReturnValue;
    PRINTF_FUNCNAME();

    Lin_Init(LinDriverConfig);

    u8Lin_ReturnValue = Lin_Wakeup(LinDriverConfig->pLin_Channel[0]->u8LinChannelID);

    if (u8Lin_ReturnValue != E_OK)
    {
        PSPRINTF("[Lin_0003]LIN Error %d returned by Lin_WakeUp(LIN_LOGICAL_CHANNEL)\n", u8Lin_ReturnValue);
        return;
    }else
    {
        PSPRINTF("[Lin_0003] Lin_Wakeup u8Lin_ReturnValue = %d\r\n", u8Lin_ReturnValue);
        PSPRINTF("[Lin_0003] Lin Channel%d state: %d\r\n", LinDriverConfig->pLin_Channel[0]->u8LinChannelID, \
                u8Lin_ChStatus[LinDriverConfig->pLin_Channel[0]->u8LinHwChannel]);
    }
    if (u8Lin_ReturnValue != E_OK)
    {
        PSPRINTF("[Lin_0003]LIN Error %d returned by Lin_WakeUp(LIN_LOGICAL_CHANNEL)\n", u8Lin_ReturnValue);
        return;
    }else
    {
        PSPRINTF("[Lin_0003] Lin_Wakeup u8Lin_ReturnValue = %d\r\n", u8Lin_ReturnValue);
        PSPRINTF("[Lin_0003] Lin Channel%d state: %d\r\n", LinDriverConfig->pLin_Channel[1]->u8LinChannelID, \
                u8Lin_ChStatus[LinDriverConfig->pLin_Channel[1]->u8LinHwChannel]);
    }
}


int tsc_lin_func(int argc, char *agrv[])
{
    if ((argc > 3) || (argc < 2)) {
        PSPRINTF("error: The number of parameters exceeds 3 or is less than 2\n");
        return 1;
    }
    static uint8 init_flag[LIN_MAX_CORES] = {0};

    VAR(uint32, AUTOMATIC) u32Lin_CoreId = 0U;
    u32Lin_CoreId = Lin_GetCoreID();

    if (init_flag[u32Lin_CoreId] == 0)
    {
    	Lin_LLD_Init_IrqIsrEnable();
    	init_flag[u32Lin_CoreId] = 1;
    }

    if (argc == 2)
    {
        if (!strcmp(agrv[1], "help"))
        {
            PSPRINTF("irq ---------- CMD ------- Register/enable LIN interrupt numbers\n"\
                      "help ----- CMD ------- ID of the test case\r\n");
                    
            for(uint8 i = 0; i < LIN_TEST_CASE_MAX; i++)
            {
                PSPRINTF("%s\n", lin_funcs[i].name);
            }
        }
        else
        {
            for(uint8 i = 0; i < LIN_TEST_CASE_MAX; i++)
            {
                if(!strcmp(agrv[1], lin_funcs[i].name))
                {
                    lin_funcs[i].linfunc(&LinGlobalConfig);
                    return 0;
                }
            }
            PSPRINTF("error: Input invalid parameters[%s], please Use the 'lin_test help' command to see the supported test instructions\n", agrv[1]);
        }
    }
    return 0;
}

#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), lin_test , tsc_lin_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
