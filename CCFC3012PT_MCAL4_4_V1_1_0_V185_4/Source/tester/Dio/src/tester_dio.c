#include "tester_dio.h"
//#include <stdbool.h>

#include "Det.h"
#include "shell.h"
#include <string.h>
#define NULL_PTR ((void *)0)
#define DIO_TEST_CASE_MAX sizeof(dio_funcs) / sizeof(DiofuncMachine)

#define Dio_error_port 23
#define Dio_error_channel2 500

#define DioConf_DioChannelGroup_DioChannelGroup_99    (&DioConf_aChannelGroupListerror1[1])
CONST(Dio_ChannelGroupType, DIO_CONST) DioConf_aChannelGroupListerror1[1] =
{
	{(Dio_PortLevelType)0x00000200UL , (uint8)5, 17, 0},
};
#define DioConf_DioChannelGroup_DioChannelGroup_100    (&DioConf_aChannelGroupListerror[1])
CONST(Dio_ChannelGroupType, DIO_CONST) DioConf_aChannelGroupListerror[1] =
{
	{(Dio_PortLevelType)0x00000c00UL , (uint8)50, 50, 0},
};
static DiofuncMachine dio_funcs[] = {

    {"testdio0001", testdio0001},
    {"testdio0002", testdio0002},
    {"testdio0003", testdio0003},
    {"testdio0004", testdio0004},

};


extern boolean TesterDemoDIO ;
void DIO_GPT_Callback_10ms_Function(void)
{
#ifdef DioConf_DioChannel_DioChannel_H11
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_H11,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_H12
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_H12,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_H13
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_H13,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_H14
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_H14,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_H15
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_H15,STD_HIGH);
#endif
}
void DIO_GPT_Callback_20ms_Function(void)
{
#ifdef DioConf_DioChannel_DioChannel_Q1
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_Q1,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_S1
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_S1,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_S0
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_S0,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_V0
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_V0,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_V1
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_V1,STD_HIGH);
#endif
}
void DIO_GPT_Callback_30ms_Function(void)
{
#ifdef DioConf_DioChannel_DioChannel_J1
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_J1,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_K14
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_K14,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_K15
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_K15,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_L0
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_L0,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_L1
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_L1,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_M0
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_M0,STD_HIGH);
#endif
#ifdef DioConf_DioChannel_DioChannel_M1
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_M1,STD_HIGH);
#endif
}



void testdio0001()
{
#ifdef DioConf_DioChannel_DioChannel_A1
	Dio_WriteChannel(DioConf_DioChannel_DioChannel_A1,STD_HIGH);
#else
	PSPRINTF("testdio0001 is NULL\n");
#endif
}
void testdio0002()
{
#ifdef DioConf_DioChannel_DioChannel_A1
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_A1,STD_LOW);
#else
	PSPRINTF("testdio0002 is NULL\n");
#endif
}

void testdio0003()
{
#ifdef DioConf_DioChannel_DioChannel_A0
    int level=Dio_ReadChannel(DioConf_DioChannel_DioChannel_A0);
    if(level==1)
    {
        PSPRINTF("testdio0003 read high\n");
    }
    else if(level==0)
    {
        PSPRINTF("testdio0003 read low\n");
    }else{
        PSPRINTF("error\n");
    }
#else
	PSPRINTF("testdio0003 is NULL\n");
#endif
}
void testdio0004()
{
#ifdef DioConf_DioChannel_DioChannel_A0
    int level =Dio_ReadChannel(DioConf_DioChannel_DioChannel_A0);
    if(level==1)
    {
        PSPRINTF("testdio0004 read high\n");
    }
    else if(level==0)
    {
        PSPRINTF("testdio0004 read  low\n");
    }else{
        PSPRINTF("error\n");
    }
#else
	PSPRINTF("testdio0004 is NULL\n");
#endif
}


int dio_func(int argc, char *agrv[])
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
                    
            for(uint8 i = 0; i < DIO_TEST_CASE_MAX; i++)
            {
                PSPRINTF("%s\n", dio_funcs[i].name);
            }
        }
        else
        {
                uint32 id = (uint32)atoi(agrv[1]);
                PSPRINTF("%d\r\n", id);
                if((id >= 1) && (id <=DIO_TEST_CASE_MAX))
                {
                    if (dio_funcs[id - 1].diofunc != NULL_PTR)
                    {
                        dio_funcs[id - 1].diofunc();
                    }
                    else if(dio_funcs[id].diofunc==NULL)
                    {
                        PSPRINTF("error: Test case is undefined\n");
                        return 0;
                    }
                    else
                    {
                        PSPRINTF("error: The ID entered does not correspond to the test code\n");
                    }
                }
                 else
                {
                    PSPRINTF("error: Input invalid parameters[%d], please output [1 - %d] range parameters\n", id, DIO_TEST_CASE_MAX);
                }}
    }
    return 0;
}
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), dio_test, dio_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif

