#include "tester_can.h"
#include "Det.h"
#include "StandardTypes.h"
#include "Compiler.h"
#include "Can_GeneralTypes.h"
#include "console.h"
#include "CanIf.h"
#include "shell.h"
#include <string.h>
#include "Gpt_Stm_LLDriver.h"
#include "intc_lld.h"
#include "SchM_Can.h"

#define CAN_DLC       8u
#define CAN_FD_DLC    64
#define CAN_FD_DLC_48 48
#define CAN_FD_DLC_32 32
#define CAN_FD_DLC_24 24
#define CAN_FD_DLC_20 20
#define CAN_FD_DLC_16 16
#define CAN_FD_DLC_12 12
#define CAN_TEST_CASE_MAX 6

#define CAN_FUNC_UNITS(id)       CAN_000##id
#define CAN_FUNC_TENS(id)        CAN_00##id
#define CAN_FUNC_HUNDREDS(id)    CAN_0##id

static uint8 txBuffer_201[CAN_DLC];

#ifdef CanController_1
#ifdef CanHardwareObject_MCAN2_203
#if (CAN_MAINFUNCTION_WRITE_API == STD_ON)
#if (CAN_MAINFUNCTION_READ_API == STD_ON)
static uint8 txBuffer_203[CAN_DLC] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18};
static uint8 txBuffer_204[CAN_DLC];
#endif
#endif
#endif
#endif

#ifdef MCAN1_18ff3001
static uint8 txBuffer_18ff3001[CAN_FD_DLC];
#endif

static uint8 McanController[12U] = {
#ifdef CanController_0
    CanController_0,
#else
    0xFF,
#endif
#ifdef CanController_1
    CanController_1,
#else
    0xFF,
#endif
#ifdef CanController_2
    CanController_2,
#else
    0xFF,
#endif
#ifdef CanController_3
    CanController_3,
#else
    0xFF,
#endif
#ifdef CanController_4
    CanController_4,
#else
    0xFF,
#endif
#ifdef CanController_5
    CanController_5,
#else
    0xFF,
#endif
#ifdef CanController_6
    CanController_6,
#else
    0xFF,
#endif
#ifdef CanController_7
    CanController_7,
#else
    0xFF,
#endif
#ifdef CanController_8
    CanController_8,
#else
    0xFF,
#endif
#ifdef CanController_9
    CanController_9,
#else
    0xFF,
#endif
#ifdef CanController_10
    CanController_10,
#else
    0xFF,
#endif
#ifdef CanController_11
    CanController_11,
#else
    0xFF,
#endif
};

static CanfuncMachine can_funcs[] = {
    {"CAN_0001", CAN_0001},
    {"CAN_0002", CAN_0002},
    {"CAN_0003", CAN_0003},
    {"CAN_0004", CAN_0004},
    {"CAN_0005", CAN_0005},
    {"CAN_0006", CAN_0006},
};

extern boolean TesterDemoCAN;
#define FEATURE_MCAN_IRQS  {{MCAN1_0_IRQn, MCAN1_1_IRQn},   \
                            {MCAN2_0_IRQn, MCAN2_1_IRQn},   \
                            {MCAN3_0_IRQn, MCAN3_1_IRQn},   \
                            {MCAN4_0_IRQn, MCAN4_1_IRQn},   \
                            {MCAN5_0_IRQn, MCAN5_1_IRQn},   \
                            {MCAN6_0_IRQn, MCAN6_1_IRQn},   \
                            {MCAN7_0_IRQn, MCAN7_1_IRQn},   \
                            {MCAN8_0_IRQn, MCAN8_1_IRQn},  \
                            {MCAN9_0_IRQn, MCAN9_1_IRQn},   \
                            {MCAN10_0_IRQn, MCAN10_1_IRQn}, \
                            {MCAN11_0_IRQn, MCAN11_1_IRQn}, \
                            {MCAN12_0_IRQn, MCAN12_1_IRQn}  \
                            }

static const IntrId s_mcanInterruptMappings[MCAN_INSTANCE_COUNT][2U] = FEATURE_MCAN_IRQS;

LOCAL_INLINE FUNC(void, CAN_CODE) CAN_IRQ_Priority(CONST(uint32, AUTOMATIC) instance);

LOCAL_INLINE FUNC(void, CAN_CODE) CAN_IRQ_Priority(CONST(uint32, AUTOMATIC) instance)
{
    DEV_ASSERT(instance < MCAN_INSTANCE_COUNT);

    INTC_LLD_Set_IRQ_Priority(s_mcanInterruptMappings[instance][0], INTR_PRI_7);
    INTC_LLD_Set_IRQ_Priority(s_mcanInterruptMappings[instance][1], INTR_PRI_7);

    switch (instance)
    {
    case 0U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN1_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN1_1);
        break;
    case 1U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN2_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN2_1);
        break;
    case 2U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN3_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN3_1);
        break;
    case 3U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN4_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN4_1);
        break;
    case 4U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN5_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN5_1);
        break;
    case 5U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN6_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN6_1);
        break;
    case 6U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN7_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN7_1);
        break;
    case 7U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN8_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN8_1);
        break;
#ifdef CanController_8
    case 8U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN9_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN9_1);
        break;
    case 9U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN10_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN10_1);
        break;
    case 10U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN11_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN11_1);
        break;
    case 11U:
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][0], &ISR_M_CAN12_0);
        INTC_LLD_Set_IRQ_Handle(s_mcanInterruptMappings[instance][1], &ISR_M_CAN12_1);
        break;
#endif
    default:
        /* do nothing */
        break;
    }

    INTC_LLD_Set_IRQ_Enable(s_mcanInterruptMappings[instance][0]);
    INTC_LLD_Set_IRQ_Enable(s_mcanInterruptMappings[instance][1]);
}

#ifdef CanLPduReceiveCalloutFunction
FUNC(Std_ReturnType, CAN_CODE) Test_Function \
( \
    VAR(uint8, AUTOMATIC) u8Can_Hrh, \
    VAR(Can_IdType, AUTOMATIC) u32Can_CanId, \
    VAR(uint8, AUTOMATIC) u8Can_Dlc, \
    P2CONST(uint8, AUTOMATIC, CAN_APPL_CONST) u8Can_SduPtr \
)
{
    (void) u8Can_Hrh;
    (void) u32Can_CanId;
    (void) u8Can_Dlc;
    (void) u8Can_SduPtr;
    PSPRINTF("Test_Function is ok\n");
    return E_OK;
}
#endif

extern VAR(Can_DriverStateType, CAN_VAR) g_eCan_DriverState[CAN_CORE_NUM];
extern VAR(Can_ControllerStateType, CAN_VAR) g_eCan_ControllerState[CAN_CONTROLLER_COUNT];

void CAN_Config_Init(void);
void CAN_Config_Init(void)
{
    Can_Init(&Can_Config);
    VAR(uint32, AUTOMATIC) u32Can_CoreId = 0U;

    u32Can_CoreId = Can_GetCoreID();
    if (g_eCan_DriverState[u32Can_CoreId] == CAN_READY) {
        PSPRINTF("CAN_Config_Init is ok\n");
    } else {
        PSPRINTF("CAN_Config_Init is not ok g_eCan_DriverState[%d]\n", g_eCan_DriverState[u32Can_CoreId]);
    }
}

void CAN_0001(void)
{
    CAN_Config_Init();
#ifdef CanController_0
    Can_SetControllerMode(CanController_0, CAN_CS_STARTED);
#if (CAN_MAINFUNCTION_WRITE_API == STD_ON)
#ifdef CanHardwareObject_401
    static uint8 txBuffer_402[CAN_FD_DLC];
    static uint8 txBuffer_401[CAN_FD_DLC];
    for (uint8 i = 0; i < CAN_FD_DLC; i++) {
        txBuffer_401[i] = (uint8)(i + 1u);
    }
    memset(txBuffer_402, 0xFD, CAN_FD_DLC);
    Can_PduType pduInfo_401;
    // 8.2.3 Can_IdType
    pduInfo_401.id = 0x40000401;
    pduInfo_401.length = CAN_FD_DLC;
    pduInfo_401.sdu = txBuffer_401;
    pduInfo_401.swPduHandle = 0;

    Can_PduType pduInfo_402;
    pduInfo_402.id = 0x40000402;
    pduInfo_402.length = CAN_FD_DLC;
    pduInfo_402.sdu = txBuffer_402;
    pduInfo_402.swPduHandle = 1;
    PSPRINTF("CAN_0001 write start\n");
    uint32 count = 0;
    while (count < 10)
    {
        count++;
        Gpt_Stm_LLD_DelayMs(STM1, 50U);

        Can_MainFunction_Write();
        Std_ReturnType ret = Can_Write(CanHardwareObject_402, &pduInfo_402);
        PSPRINTF("CAN_0001 ret[%d]\n", ret);
        if ((count % 2) == 0) {
            Can_MainFunction_Write();
            Can_Write(CanHardwareObject_401, &pduInfo_401);
        }
        if (count >= 0xFFFFFFFF) {
            count = 1;
        }
    }
#endif
#endif
#endif
}


void CAN_0002(void)
{
	CAN_Config_Init();
#ifdef CanController_0
    Can_SetControllerMode(CanController_0, CAN_CS_STARTED);
#endif
}

void CAN_0003(void)
{
    CAN_Config_Init();
#ifdef CanController_0
    Can_SetControllerMode(CanController_0, CAN_CS_STARTED);
#if (CAN_MAINFUNCTION_READ_API == STD_ON)
    uint32 count = 0;
    while (count < 10)
    {
        count++;
        Gpt_Stm_LLD_DelayMs(STM1, 200U);
        Can_MainFunction_Read();
    }
#endif // CAN_MAINFUNCTION_READ_API
#endif
}


void CAN_0004(void)
{
    CAN_Config_Init();
#ifdef CanController_0
    Can_SetControllerMode(CanController_0, CAN_CS_STARTED);
#if (CAN_MAINFUNCTION_READ_API == STD_ON)
    uint32 count = 0;
    while (count < 10)
    {
        count++;
        Gpt_Stm_LLD_DelayMs(STM1, 200U);
        Can_MainFunction_Read();
    }
#endif // CAN_MAINFUNCTION_READ_API
#endif
}

void CAN_0005(void)
{
#ifdef CanController_0
#ifdef MCAN1_18ff3001
#if (CAN_MAINFUNCTION_WRITE_API == STD_ON)
    static uint8 num = 0U;

    Can_ControllerStateType state = CAN_CS_UNINIT;
    memset(txBuffer_18ff3001, 0x80, CAN_DLC);

    Can_PduType pduInfo_18ff3001;
    pduInfo_18ff3001.id = 0xD8ff3001;
    pduInfo_18ff3001.length = CAN_DLC;
    pduInfo_18ff3001.sdu = txBuffer_18ff3001;
    pduInfo_18ff3001.swPduHandle = 0;

    uint32 count = 0U;
    if (num == 0U)
    {
    	CAN_Config_Init();
        Can_SetControllerMode(CanController_0, CAN_CS_STARTED);
        while (count < 10U)
        {
            count++;
            Gpt_Stm_LLD_DelayMs(STM1, 100U);

            Can_MainFunction_Write();
            Can_Write(MCAN1_18ff3001, &pduInfo_18ff3001);
        }

        while (state != CAN_CS_STOPPED)
        {
            Can_GetControllerMode(CanController_0, &state);
        }

        num++;
    }
    else
    {
        num = 0U;
        Can_SetControllerMode(CanController_0, CAN_CS_STARTED);
        count = 0U;
        while (count < 10U)
        {
            count++;
            Gpt_Stm_LLD_DelayMs(STM1, 100U);

            Can_MainFunction_Write();
            Can_Write(MCAN1_18ff3001, &pduInfo_18ff3001);
        }
    }
#endif
#endif
#endif
}

void CAN_0006(void)
{
    memset(txBuffer_201, 0x80, CAN_DLC);
#ifdef CanController_0
#ifdef CanHardwareObject_201
#if (CAN_MAINFUNCTION_WRITE_API == STD_ON)
#if (CAN_MAINFUNCTION_BUSOFF_API == STD_ON)
    static uint8 num = 0U;

    Can_ControllerStateType state = CAN_CS_UNINIT;
    Can_PduType pduInfo_201;
    pduInfo_201.id = 0x201;
    pduInfo_201.length = CAN_DLC;
    pduInfo_201.sdu = txBuffer_201;
    pduInfo_201.swPduHandle = 0;

    uint32 count = 0;
    if (num == 0)
    {
    	CAN_Config_Init();
        Can_SetControllerMode(CanController_0, CAN_CS_STARTED);
        while (count < 10)
        {
            count++;
            Gpt_Stm_LLD_DelayMs(STM1, 100U);

            Can_MainFunction_Write();
            Can_Write(CanHardwareObject_201, &pduInfo_201);
            Can_MainFunction_BusOff();
        }
        while (state != CAN_CS_STOPPED)
        {
            Can_GetControllerMode(CanController_0, &state);
        }
        num++;
    }
    else
    {
        num = 0;
        Can_SetControllerMode(CanController_0, CAN_CS_STARTED);
        count = 0;
        while (count < 10)
        {
            count++;
            Gpt_Stm_LLD_DelayMs(STM1, 100U);
            Can_MainFunction_BusOff();
            Can_MainFunction_Write();
            Can_Write(CanHardwareObject_201, &pduInfo_201);
        }
    }
#endif
#endif
#endif
#endif
}

int can_func(int argc, char *agrv[])
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
                Can_DeInit();
                PSPRINTF("Can_DeInit end!\n");
            }
            else if (!strcmp(agrv[1], "irq"))
            {
                CAN_IRQ_Priority(CanController_0);
            }
            else if (!strcmp(agrv[1], "stop"))
            {
#ifdef CanController_8
                PSPRINTF("Please enter the number of the device you want to stop [1-12]!\n");
#else
                PSPRINTF("Please enter the number of the device you want to stop [1-8]!\n");
#endif
            }
            else if (!strcmp(agrv[1], "help"))
            {
                PSPRINTF("deinit ------- CMD ------- Can_DeInit()\n\
            irq ---------- CMD ------- Register/enable MCAN1 and MCAN2 interrupt numbers\n\
            stop --------- CMD ------- Migrate the module status to stop\n\
            [1 - %d] ----- CMD ------- ID of the test case\n", CAN_TEST_CASE_MAX);
            }
            else
            {
                uint32 id = (uint32)atoi(agrv[1]);
                PSPRINTF("%d\r\n", id);
                if ((id >= 1) && (id <= CAN_TEST_CASE_MAX))
                {
                    if (can_funcs[id - 1].canfunc != NULL_PTR)
                    {
                        can_funcs[id - 1].canfunc();
                    }
                    else
                    {
                        PSPRINTF("error: The ID entered does not correspond to the test code\n");
                    }
                }
                else
                {
                    PSPRINTF("error: Input invalid parameters[%d], please output [1 - %d] range parameters\n", id, CAN_TEST_CASE_MAX);
                }
            }
        }
        else
        {
            if (!strcmp(agrv[1], "stop"))
            {
                uint32 ControllerId = (uint32)atoi(agrv[2]);
                if ((ControllerId > CAN_CONTROLLER_COUNT) || (ControllerId < 1))
                {
#ifdef CanController_8
                    PSPRINTF("error: Invalid parameter[%d], please enter the value of [1-12]!\n", ControllerId);
#else
                    PSPRINTF("error: Invalid parameter[%d], please enter the value of [1-8]!\n", ControllerId);
#endif
                }
                else
                {
                    if (McanController[ControllerId - 1] != 0xFF)
                    {
                        Can_SetControllerMode(McanController[ControllerId - 1], CAN_CS_STOPPED);
                    }
                    else
                    {
                        PSPRINTF("error: The corresponding MCAN%d device is not used!\n", ControllerId);
                    }
                }
            }
        }
    }
    return 0;
}
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), can_test, can_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
