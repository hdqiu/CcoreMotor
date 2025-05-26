#include "tester_fee.h"
#include <string.h>
#include "Fls_Cfg.h"

#define FEE_TEST_CASE_MAX sizeof(fee_funcs) / sizeof(FeefuncMachine)

extern VAR(Fee_JobResult_Type, FEE_VAR) Fee_JobConfig;

static FeefuncMachine fee_funcs[] = {
    {"fee_001", test_fee_001},
    {"fee_002", test_fee_002},
    {"fee_003", test_fee_003},
};

void test_fee_001()
{
    VAR (uint8, AUTOMATIC) buff[32]={0x33,0x33,0x33,0x33,0x33,0x33,0x55,0xAA,
                                       0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
                                       0x00,0x00,0x00,0x00,0x00,0x23,0x00,0x23,
                                       0x55,0xAA,0x55,0xAA,0x55,0xAA,0x11,0xAA};
    uint8 b[32] = {0};
    uint8 c[32] = {0};
    uint8 i = 0;

    Fee_Init(&Fee_Config);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    Fee_EraseImmediateBlock(2);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    Fee_Write(2,buff);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    Fee_EraseImmediateBlock(2);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    Fee_Write(2,buff);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    Fee_Read(2,0,b,32);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    for(i = 0;i < 32; i++) {
        PSPRINTF("b:%x ",b[i]);
    }
    Fee_Read(2,0,c,32);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }

    for(i = 0;i < 32; i++) {
        PSPRINTF("c:%x ",c[i]);
    }
}

void test_fee_002()
{
    VAR (uint8, AUTOMATIC) buff[32]={0x33,0x33,0x33,0x33,0x33,0x33,0x55,0xAA,
                                       0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
                                       0x00,0x00,0x00,0x00,0x00,0x23,0x00,0x23,
                                       0x55,0xAA,0x55,0xAA,0x55,0xAA,0x11,0xAA};
    uint8 b[32] = {0};
    uint8 c[32] = {0};
    uint8 i = 0;

    Fee_Init(&Fee_Config);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    Fee_EraseImmediateBlock(2);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    Fee_Write(2,buff);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    Fee_EraseImmediateBlock(2);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    Fee_Write(2,buff);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    Fee_Read(2,0,b,32);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    for(i = 0;i < 32; i++) {
        PSPRINTF("b:%x ",b[i]);
    }
    Fee_Read(2,0,c,32);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }

    for(i = 0;i < 32; i++) {
        PSPRINTF("c:%x ",c[i]);
    }
}

void test_fee_003()
{
    Std_ReturnType ret;

    Fee_Init(&Fee_Config);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }

    ret = Fee_EraseImmediateBlock(2);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    PSPRINTF("Erase ret :%d\n",ret);

    ret = Fee_EraseImmediateBlock(2);
    while(Fee_GetStatus() != MEMIF_IDLE ||
    Fls_GetStatus() != MEMIF_IDLE)
    {
        Fls_MainFunction();
        Fee_MainFunction();
    }
    PSPRINTF("Erase ret :%d\n",ret);
}

int tsc_fee_func(int argc, char *agrv[])
{
    if ((argc > 3) || (argc < 2)) {
        PSPRINTF("error: The number of parameters exceeds 3 or is less than 2\n");
    }

   if (argc == 2)
   {
        if (!strcmp(agrv[1], "help"))
        {
            PSPRINTF("irq ---------- CMD ------- Register/enable FEE interrupt numbers\n \
                      stop --------- CMD ------- Migrate the module status to stop\n");
                    
            PSPRINTF("ID of the test case:\n");
            for(uint8 i = 0; i < FEE_TEST_CASE_MAX; i++)
            {
                PSPRINTF("%s\n", fee_funcs[i].name);
            }
        }
        else
        {
            for(uint8 i = 0; i < FEE_TEST_CASE_MAX; i++)
            {
                if(!strcmp(agrv[1], fee_funcs[i].name))
                {
                    Fls_Init(&Fls_Config);
                    fee_funcs[i].func();
                    return 0;
                }
            }
            PSPRINTF("error: Input invalid parameters[%s], please Use the 'fee_test help' command to see the supported test instructions\n", agrv[1]);
        }
   }

   return 0;
}
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), fee_test , tsc_fee_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
