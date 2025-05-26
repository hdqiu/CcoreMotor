#include "tester_fls.h"
#include "Gpt_Stm_LLDriver.h"
#include "shell.h"
#include <string.h>

#define FLS_TEST_CASE_MAX sizeof(fls_funcs) / sizeof(FlsfuncMachine)
 
extern VAR(MemIf_StatusType, FLS_VAR) gFls_ModuleStatus;
extern P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) gFls_ConfigPtr;


static FlsfuncMachine fls_funcs[] = {
    {"fls_0001",test_fls_0001},
    {"fls_0002",test_fls_0002},
};

uint32 Fls_Get_PhyStartAddress()
{
    VAR( uint32, AUTOMATIC) u32Fls_PhyStartAddr = 0U; 
    VAR( uint32, AUTOMATIC) u32Fls_PhyIndex = 0U;

    u32Fls_PhyIndex = (*(gFls_ConfigPtr->pSectorList))[gFls_JobSectorIt];
    u32Fls_PhyStartAddr = flashInfo[u32Fls_PhyIndex].addrStart;

    return u32Fls_PhyStartAddr;
}

void test_fls_0001(const Fls_ConfigType *Fls_Config)
{
    PSPRINTF("[%s]",__func__);
    Std_ReturnType type = E_NOT_OK;
    MemIf_JobResultType job_type = MEMIF_JOB_OK;
    uint8 array[16] = {1,2,3,4,5,6,7,8,5,5,5,5,5,5,5,5};
    uint8 array1[16] = {0};
#if (Fls_Compare_API == STD_ON)
    uint8 data1[16] = {1,2,3,4,5,6,7,8,5,5,5,5,5,5,5,5};
#endif
    uint8 i = 0;

    Fls_Init(Fls_Config);
    type = Fls_Erase(0x38000,65536);
    PSPRINTF("LogicAddr:0x%x PhyAddr:0x%x \n",gFls_JobAddrIt,Fls_Get_PhyStartAddress());
    job_type = Fls_GetJobResult();
    PSPRINTF("type:%d\n",type);/*E_OK*/
    PSPRINTF("job_type:%d\n",job_type);
    Fls_MainFunction();
    Gpt_Stm_LLD_DelayMs(STM1, 5U);
    job_type = Fls_GetJobResult();
    PSPRINTF("---After MainFunction Erase---\n");
    PSPRINTF("job_type:%d\n",job_type);
#if (FLS_BLANK_CHECK_API == STD_ON)
    Fls_BlankCheck(0x38000,65536);
    while(Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
    }
#endif
    type = Fls_Write(0x38000,array,16);
    while(Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
    }
    PSPRINTF("---After MainFunction Write---\n");
    job_type = Fls_GetJobResult();
    PSPRINTF("job_type:%d\n",job_type);
#if (Fls_Compare_API == STD_ON)
    Fls_Compare(0x38000,data1,16);
    while(Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
    }
#endif
    Fls_Cancel();
    type = Fls_Read(0x38000,array1,16);
    while(Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
    }
    PSPRINTF("---After MainFunction Read---\n");
    for(i = 0;i < 16;i++)
    {
        PSPRINTF("data1:%d\n",array1[i]);
    }
}

void test_fls_0002(const Fls_ConfigType *Fls_Config)
{
    PSPRINTF("[%s]",__func__);
    Std_ReturnType type = E_NOT_OK;
    MemIf_JobResultType job_type = MEMIF_JOB_OK;
    uint8 array[16] = {1,2,3,4,5,6,7,8,5,5,5,5,5,5,5,5};
    uint8 array1[16] = {0};
#if (Fls_Compare_API == STD_ON)
    uint8 data1[16] = {1,2,3,4,5,6,7,8,5,5,5,5,5,5,5,5};
#endif
    uint8 i = 0;

    Fls_Init(Fls_Config);
    type = Fls_Erase(0x3b8000,0x40000);
    PSPRINTF("LogicAddr:0x%x PhyAddr:0x%x \n",gFls_JobAddrIt,Fls_Get_PhyStartAddress());
    job_type = Fls_GetJobResult();
    PSPRINTF("type:%d\n",type);/*E_OK*/
    PSPRINTF("job_type:%d\n",job_type);
    Fls_MainFunction();
    Gpt_Stm_LLD_DelayMs(STM1, 5U);
    job_type = Fls_GetJobResult();
    PSPRINTF("---After MainFunction Erase---\n");
    PSPRINTF("job_type:%d\n",job_type);
#if (FLS_BLANK_CHECK_API == STD_ON)
    Fls_BlankCheck(0x3b8000,0x40000);
    while(Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
    }
#endif
    type = Fls_Write(0x3b8000,array,16);
    while(Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
    }
    PSPRINTF("---After MainFunction Write---\n");
    job_type = Fls_GetJobResult();
    PSPRINTF("job_type:%d\n",job_type);
#if (Fls_Compare_API == STD_ON)
    Fls_Compare(0x3b8000,data1,16);
    while(Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
    }
#endif
    Fls_Cancel();
    type = Fls_Read(0x3b8000,array1,16);
    while(Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
    }
    PSPRINTF("---After MainFunction Read---\n");
    for(i = 0;i < 16;i++)
    {
        PSPRINTF("data1:%d\n",array1[i]);
    }
}

int tsc_fls_func(int argc, char *agrv[])
{
    if ((argc > 3) || (argc < 2)) {
        PSPRINTF("error: The number of parameters exceeds 3 or is less than 2\n");
    }

   if (argc == 2)
   {
       if (!strcmp(agrv[1], "help"))
       {

            PSPRINTF("irq ---------- CMD ------- Register/enable FLS interrupt numbers\n \
                      stop --------- CMD ------- Migrate the module status to stop\n");
                    
            PSPRINTF("ID of the test case:\n");
            for(uint8 i = 0; i < FLS_TEST_CASE_MAX; i++)
            {
                PSPRINTF("%s\n", fls_funcs[i].name);
            }
        }
        else
        {
            for(uint8 i = 0; i < FLS_TEST_CASE_MAX; i++)
            {
                if(!strcmp(agrv[1], fls_funcs[i].name))
                {
                    fls_funcs[i].flsfunc(&Fls_Config);
                    return 0;
                }
            }
            PSPRINTF("error: Input invalid parameters[%s], please Use the 'fls_test help' command to see the supported test instructions\n", agrv[1]);
        }
   }

    return 0;
}
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), fls_test , tsc_fls_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif

