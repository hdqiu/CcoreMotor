

#include "Spi.h"
#include "CCFC3012PT.h"
#include "Spi_Test.h"
#include "Gpt_Stm_LLDriver.h"
#include "intc_lld.h"
#include "console.h"
#include "Shell.h"
#include "Spi_Irq.h"
#include "tester_gpt_multi.h"
#include <string.h>


#define SPI_START_SEC_VAR_SHARED_INIT
#include "Spi_MemMap.h"
static VAR(Spi_DataBufferType, SPI_VAR) recvData[20U] = {0};
#define SPI_STOP_SEC_VAR_SHARED_INIT
#include "SPi_MemMap.h"

/* Variables to store last DET error */
extern VAR(uint8, DET_VAR) Det_InstanceId;     /**< @brief DET instance ID*/
extern VAR(uint8, DET_VAR) Det_ApiId;          /**< @brief DET API ID*/
extern VAR(uint8, DET_VAR) Det_ErrorId;        /**< @brief DET Error ID*/

/* Variables to store last DET error */
extern VAR(uint16, DET_VAR) Det_ModuleId;       /**< @brief DET module ID*/

#define VERIFICATION_RESULT                  0
#define DSPI_HALT_VERIFICATION_RESULT          1



CONST(IntrPrior, SPI_CODE) dspi_Intc_Tcf_Priority[8U] = {DSPI0_TCF_INTPRI,DSPI1_TCF_INTPRI, \
                                                               DSPI2_TCF_INTPRI,DSPI3_TCF_INTPRI, \
                                                               DSPI4_TCF_INTPRI,DSPI5_TCF_INTPRI, \
                                                               DSPI6_TCF_INTPRI,DSPI12_TCF_INTPRI \
                                                              };

CONST(IntrId, SPI_CODE) dspi_Intc_Tcf_TntId[8U] = {DSPI0_TCF_IntID,DSPI1_TCF_IntID, \
                                                         DSPI2_TCF_IntID,DSPI3_TCF_IntID, \
                                                         DSPI4_TCF_IntID,DSPI5_TCF_IntID, \
                                                         DSPI6_TCF_IntID,DSPI12_TCF_IntID \
                                                        };

void (* const Tcf_Irq[8U])(void) = {dspi_0_Tcf_Irq,dspi_1_Tcf_Irq, \
                                          dspi_2_Tcf_Irq,dspi_3_Tcf_Irq, \
                                          dspi_4_Tcf_Irq,dspi_5_Tcf_Irq, \
                                          dspi_6_Tcf_Irq,dspi_12_Tcf_Irq \
                                         };

uint8 data[160];

static SpifuncMachine spi_funcs[] = {
    {"spi_0000", spi_0000},
    {"spi_0001", spi_0001},
	{"spi_0002", spi_0002},
	{"spi_0003", spi_0003},
	{"spi_0004", spi_0004},
	{"spi_0005", spi_0005},
};

FUNC(void, SPI_CODE) dspi_Int_Enable(VAR(uint8, SPI_VAR) Spi_u8HandleIdx)
{
    INTC_LLD_Set_IRQ_Handle(dspi_Intc_Tcf_TntId[Spi_u8HandleIdx], Tcf_Irq[Spi_u8HandleIdx]);
    INTC_LLD_Set_IRQ_Priority \
    ( \
        dspi_Intc_Tcf_TntId[Spi_u8HandleIdx], \
        dspi_Intc_Tcf_Priority[Spi_u8HandleIdx] \
    );
    INTC_LLD_Set_IRQ_Enable(dspi_Intc_Tcf_TntId[Spi_u8HandleIdx]);

}

void EnableSpiInterrupt(void)
{
    dspi_Int_Enable(0);
    dspi_Int_Enable(1);
    dspi_Int_Enable(2);
//    dspi_Int_Enable(3);
    dspi_Int_Enable(4);
//    dspi_Int_Enable(5);
//    dspi_Int_Enable(6);
//    dspi_Int_Enable(7);
}

extern void Spi_Dspi_IsrTCF_DSPI_0(void);

void spi_Env_Init()
{
    EnableSpiInterrupt();
}

void SPI_Init(void)
{
    spi_Env_Init();
    Spi_Init(&Spi_Configuration);
    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
}


void spi_0000(void)
{
    Std_ReturnType retVal1,retVal2,retVal3;
    uint8 tranbuffer[10] = {1,2,3,4,5,6,7,8,9,0};
    uint8 recbuffer[10] = {0};
    spi_Env_Init();
    Spi_Init(&Spi_Configuration);
    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    Spi_SetupEB(1,tranbuffer,recbuffer,10);
    retVal1 = Spi_AsyncTransmit(0);
    retVal2 = Spi_AsyncTransmit(1);
    retVal3 = Spi_AsyncTransmit(2);

    if(retVal1 == E_OK)
    {
        PSPRINTF("Transmit Seq0 is OK\n");
    }

    if(retVal2 == E_OK)
    {
        PSPRINTF("Transmit Seq1 is OK\n");
    }

    if(retVal3 == E_OK)
    {
        PSPRINTF("Transmit Seq2 is OK\n");
    }
}


void spi_0001(void)
{
    Std_ReturnType retVal1,retVal2;
    uint8 tranData[4] = {1,2,3,4};
    uint8 tranData1[4] = {5,6,7,8};
    uint8 tranData2[4] = {9,10,11,12};
    spi_Env_Init();
    Spi_Init(&Spi_Configuration);
    Spi_WriteIB(0,tranData);
    Spi_WriteIB(2,tranData1);
    Spi_WriteIB(3,tranData2);
    retVal1 = Spi_SyncTransmit(0);
    retVal2 = Spi_SyncTransmit(2);
    if(retVal1 == E_OK)
    {
        PSPRINTF("spi_0001 first transmit is OK\n");
    }
    else
    {
        PSPRINTF("spi_0001 first transmit is NG\n");
    }
    if(retVal2 == E_OK)
    {
        PSPRINTF("spi_0001 second transmit is OK\n");
    }
    else
    {
        PSPRINTF("spi_0001 second transmit is NG\n");
    }
}

void spi_0002(void)
{
    Std_ReturnType retVal;
    static uint8 tranData[20] = {0};
    static uint8 recvData1[20] = {0};
    uint8 i=0;

    spi_Env_Init();
	Spi_Init(&Spi_Configuration);

    for(i=0;i<20;i++)
    {
        tranData[i]=i;
    }

    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    Spi_SetupEB(14,&tranData[0],&recvData1[0],5);
    retVal = Spi_AsyncTransmit(8);
    if(retVal == E_OK)
    {
        PSPRINTF("spi_0002 is OK\n");
    }
    else
    {
        PSPRINTF("spi_0002 is NG\n");
    }
}

void spi_4911_A(void)
{
    Std_ReturnType retVal;
    static uint8 tranData[16] = {0};
    static uint8 recvData1[16] = {0};
    spi_Env_Init();
    Spi_Init(&Spi_Configuration);
    for(int i=0;i<16;i++)
    {
    	tranData[i]=i;
    }
    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    Spi_SetupEB(12,tranData,recvData1,2);

    retVal = Spi_AsyncTransmit(5);
    if(retVal == E_OK)
    {
        PSPRINTF("4911_A is OK\n");
    }
    else
    {
        PSPRINTF("4911_A is NG\n");
    }
}

void spi_4911_B(void)
{
    Std_ReturnType retVal;
    static uint8 tranData[16] = {0};
    static uint8 recvData1[16] = {0};
    spi_Env_Init();
    Spi_Init(&Spi_Configuration);
    for(int i=0;i<16;i++)
    {
    	tranData[i]=i;
    }
    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    Spi_SetupEB(24,tranData,recvData1,2);

    retVal = Spi_AsyncTransmit(13);
    if(retVal == E_OK)
    {
        PSPRINTF("spi_0003 is OK\n");
    }
    else
    {
        PSPRINTF("spi_0003 is NG\n");
    }
}

void spi_0003(void)
{
    Std_ReturnType retVal;
    static uint8 tranData[16] = {0};
    static uint8 recvData1[16] = {0};
    spi_Env_Init();
    Spi_Init(&Spi_Configuration);
    for(int i=0;i<16;i++)
    {
    	tranData[i]=i;
    }
    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    Spi_SetupEB(13,tranData,recvData1,4);

    retVal = Spi_AsyncTransmit(7);
    if(retVal == E_OK)
    {
        PSPRINTF("spi_0003 is OK\n");
    }
    else
    {
        PSPRINTF("spi_0003 is NG\n");
    }
}

extern FUNC(void, EDMA_CODE) EDMA_Ch1_IRQHandler(void);

void spi_0004(void)
{
    Std_ReturnType retVal;
    static uint8 tranData[20];
    static uint8 i=0;

    spi_Env_Init();
	(void) INTC_LLD_Set_IRQ_Handle(DMA0_CH1_IRQn, &EDMA_Ch1_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Priority(DMA0_CH1_IRQn, INTR_PRI_10);
	(void) INTC_LLD_Set_IRQ_Enable(DMA0_CH1_IRQn);

	Spi_Init(&Spi_Configuration);

    for(i=0;i<20;i++)
    {
        tranData[i]=i;
    }

    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    Spi_SetupEB(19,&tranData[0],&recvData[0],4);

    retVal = Spi_AsyncTransmit(7);
    if(retVal == E_OK)
    {
        PSPRINTF("spi_004 is OK\n");
    }
    else
    {
        PSPRINTF("spi_004 is NG\n");
    }
}

void spi_0005(void)
{
    Std_ReturnType retVal;
    static uint8 tranData[20];
    uint8 i=0;

    spi_Env_Init();
	(void) INTC_LLD_Set_IRQ_Handle(DMA0_CH1_IRQn, &EDMA_Ch1_IRQHandler);
	(void) INTC_LLD_Set_IRQ_Priority(DMA0_CH1_IRQn, INTR_PRI_10);
	(void) INTC_LLD_Set_IRQ_Enable(DMA0_CH1_IRQn);
	Spi_Init(&Spi_Configuration);

    for(i=0;i<20;i++)
    {
        tranData[i]=i;
    }

    Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    Spi_SetupEB(20,&tranData[0],&recvData[0],4);

    retVal = Spi_AsyncTransmit(8);
    if(retVal == E_OK)
    {
        PSPRINTF("spi_005 is OK\n");
    }
    else
    {
        PSPRINTF("spi_005 is NG\n");
    }
}


int spi_func(int argc, char *agrv[])
{
    if (argc!=2)
    {
        PSPRINTF("error: Parameter number error\n");
        return 0;
    }

    if(!strcmp(agrv[1], "help"))
    {
        PSPRINTF("Test valid ID: 0-5\n");
        PSPRINTF("Note: Modify configuration when switching between synchronous and asynchronous test cases\n");
        return 0;
    }

    uint32 id = (uint32)atoi(agrv[1]);

    if(id>(sizeof(spi_funcs)/sizeof(spi_funcs[0]))-1)
    {
        PSPRINTF("error: Parameter out of range\n");
        return 0;
    }

    if(spi_funcs[id].spifunc==NULL)
    {
        PSPRINTF("error: Test case is undefined\n");
        return 0;
    }

    spi_funcs[id].spifunc();

    return 0;
}

#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), spi_test, spi_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
