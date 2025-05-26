/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC3012PT           
* DESCRIPTION : canfd demo code
* HISTORY     : Initial version.
* @file     canfd_demo.c
* @version  4.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/

/*PRQA S 1503, 1505 EOF*/
#include "tester_canfd.h"/*PRQA S 0380*/
#include "console.h"
#include "shell.h"
#include "Gpt_Stm_LLDriver.h"
#include "Det.h"
#include <string.h>
#include "intc_lld.h"
#include "SchM_Canfd.h"

#define CAN_DLC             8
#define CAN_FD_DLC          64
#define CANFD_TEST_CASE_MAX (ARRAY_SIZE(canfd_funcs))

void CANFD_0001(void);
static void CANFD_0002(void);
static void CANFD_0003(void);
static void CANFD_0004(void);
static void CANFD_0005(void);
static void CANFD_0006(void);

static uint8 CANFD_Controller[2U] = {
#ifdef CanFd_1
    CanFd_1,
#else
    0xFF,
#endif
#ifdef CanFd_9
    CanFd_9,
#else
    0xFF,
#endif
};

static CanfdfuncMachine canfd_funcs[] = {
    {"CANFD_0001", CANFD_0001},
    {"CANFD_0002", CANFD_0002},
    {"CANFD_0003", CANFD_0003},
    {"CANFD_0004", CANFD_0004},
    {"CANFD_0005", CANFD_0005},
    {"CANFD_0006", CANFD_0006},
};

extern boolean TesterDemoCANFD;

extern FUNC(void, CAN_CODE) ISR_CANFD1_0(void);
extern FUNC(void, CAN_CODE) ISR_CANFD9_0(void);

extern VAR(Can_176_CANFD_DriverStateType, CAN_VAR) g_eCanFd_DriverState[CANFD_CORE_NUM];
extern VAR(Can_ControllerStateType, CAN_VAR) g_eCanFd_ControllerState[CAN_176_CANFD_CONTROLLER_COUNT];


void CANFD_IRQ_Priority()
{
    INTC_LLD_Set_IRQ_Priority(CANFD1_IRQn, INTR_PRI_15);
    INTC_LLD_Set_IRQ_Handle(CANFD1_IRQn, &ISR_CANFD1_0);
    INTC_LLD_Set_IRQ_Enable(CANFD1_IRQn);
//    INTC_LLD_Set_IRQ_Priority(CANFD9_IRQn, INTR_PRI_7);
//    INTC_LLD_Set_IRQ_Handle(CANFD9_IRQn, &ISR_CANFD9_0);
//    INTC_LLD_Set_IRQ_Enable(CANFD9_IRQn);
}

uint8 Canfd_rxBuffer_101[64] = {0};
uint8 Canfd_rxBuffer_102[64] = {0};
uint8 Canfd_rxBuffer_103[64] = {0};
uint8 Canfd_rxBuffer_104[64] = {0};
uint8 Canfd_rxBuffer_105[64] = {0};
extern uint32 Can_Motor0_Ctrl_Alive_Counter;
extern uint32 Can_Motor1_Ctrl_Alive_Counter;
#ifdef Can_176_CanFd_LPduReceiveCalloutFunction
FUNC(Std_ReturnType, CAN_CODE) CanFdLPduReceiveCalloutFunction \
( \
    VAR(uint8, AUTOMATIC) u8Can_Hrh, \
    VAR(Can_IdType, AUTOMATIC) u32Can_CanId, \
    VAR(uint8, AUTOMATIC) u8Can_Dlc, \
    P2CONST(uint8, AUTOMATIC, CAN_APPL_CONST) u8Can_SduPtr \
)
{
    (void)u8Can_Hrh;
    (void)u32Can_CanId;
    (void)u8Can_Dlc;
    (void)u8Can_SduPtr;
    uint8 i;

    if(u32Can_CanId == 0x40000101)
    {
    	Can_Motor0_Ctrl_Alive_Counter = 30000;
    	for(i = 0; i < 64; i++)
    	{
            Canfd_rxBuffer_101[i] = u8Can_SduPtr[i];
    	}
    }
    else if(u32Can_CanId == 0x40000102)
    {
    	Can_Motor1_Ctrl_Alive_Counter = 30000;
    	for(i = 0; i < 64; i++)
    	{
            Canfd_rxBuffer_102[i] = u8Can_SduPtr[i];
    	}
    }
    else if(u32Can_CanId == 0x40000103)
    {
    	for(i = 0; i < 64; i++)
    	{
            Canfd_rxBuffer_103[i] = u8Can_SduPtr[i];
    	}
    }
    else if(u32Can_CanId == 0x40000104)
    {
    	for(i = 0; i < 64; i++)
    	{
            Canfd_rxBuffer_104[i] = u8Can_SduPtr[i];
    	}
    }
    else if(u32Can_CanId == 0x40000105)
    {
    	for(i = 0; i < 64; i++)
    	{
            Canfd_rxBuffer_105[i] = u8Can_SduPtr[i];
    	}
    }

//    PSPRINTF("Can_176_CanFd_LPduReceiveCalloutFunction\n");
    return E_OK;
}
#endif

FUNC(void,CAN_CODE) error_notify(VAR(uint8, AUTOMATIC) u8Can_ControllerId)
{
    (void)u8Can_ControllerId;
    PSPRINTF("Error Notification\n");
}
/*******************************************************************************
 * @brief      Init CANFD IO port
 * @param[in]  CANFDModId canfd_id
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void Canfd_LLD_Init_Port(CANFDModId canfd_id)
{
static const struct
    {
        uint16_t tx_pad;
        uint16_t tx_PCR;
        uint16_t rx_pad;
        uint16_t rx_PCR;
        uint8_t  rx_PSMI_idx;
        uint8_t  rx_PSMI_PADSEL;
    } pcr_cfg[2] = /* PRQA S 3408 */
    {
        /* CAN_MOD_ID_1: port PC0 as TX; port PC1 as RX */
        [CANFD_MOD_ID_1] = {PC0, 0x0E9C, PC1, 0x0640, 39U, 0x2U},
        /* CAN_MOD_ID_9: port PD6 as TX; port PD5 as RX */
        [CANFD_MOD_ID_9] = {PD6, 0x0E9CU, PD5, 0x0540U, 47U, 0x2U},
    };
    SIUL.PCR[pcr_cfg[canfd_id].tx_pad].R = pcr_cfg[canfd_id].tx_PCR;
    SIUL.PCR[pcr_cfg[canfd_id].rx_pad].R = pcr_cfg[canfd_id].rx_PCR;
    SIUL.PSMI[pcr_cfg[canfd_id].rx_PSMI_idx].R = (uint8_t)(pcr_cfg[canfd_id].rx_PSMI_PADSEL & SIUL_PSMI_U8_PADSEL_MASK);
}

void CANFD_Config_Init(void)
{
    Can_176_CanFd_Init(&Can_176_CanFd_Config);
    VAR(uint32, AUTOMATIC) u32CanFd_CoreId = 0U;

    u32CanFd_CoreId = CanFD_GetCoreID();

    if (g_eCanFd_DriverState[u32CanFd_CoreId] == CAN_176_CANFD_READY) {
        PSPRINTF("CANFD_Config_Init is ok\n");
    } else {
        PSPRINTF("CANFD_Config_Init is not ok g_eCanFd_DriverState[%d]\n", g_eCanFd_DriverState[u32CanFd_CoreId]);
    }
}


void CANFD_0001(void)
{
    CANFD_Config_Init();
#ifdef CanFd_1
#ifdef CANFD1_TX_SECONDARY
#if (CAN_176_CANFD_SET_BAUDRATE_API == STD_ON)
    Can_176_CanFd_SetBaudrate(CanFd_1, 1);
    Can_176_CanFd_SetControllerMode(CanFd_1, CAN_CS_STARTED);
    static uint8 Canfd_txBuffer_18FF1001[64] = {0};
    for (uint8 i = 0; i < 64u; i++) {
        Canfd_txBuffer_18FF1001[i] = (uint8)(i + 1u);
    }

    Can_PduType pduInfo_18FF1001;
    pduInfo_18FF1001.id = 0xD8ff1001;
    pduInfo_18FF1001.length = 64;
    pduInfo_18FF1001.sdu = Canfd_txBuffer_18FF1001;
    pduInfo_18FF1001.swPduHandle = 0;

    uint32 count = 0;
    
    while (count < 10)
    {
        count++;
        Gpt_Stm_LLD_DelayMs(STM1, 50U);
        Can_176_CanFd_Write(CANFD1_TX_SECONDARY, &pduInfo_18FF1001);
    }
#endif
#endif
#endif
}

static void CANFD_0002(void)
{
    CANFD_Config_Init();
#ifdef CanFd_1
#if (CAN_176_CANFD_SET_BAUDRATE_API == STD_ON)
    Can_176_CanFd_SetBaudrate(CanFd_1, 1);
    Can_176_CanFd_SetControllerMode(CanFd_1, CAN_CS_STARTED);
    Can_176_CanFd_DisableControllerInterrupts(CanFd_1);
    Can_176_CanFd_EnableControllerInterrupts(CanFd_1);
#endif
#endif
}



static void CANFD_0003(void)
{
    CANFD_Config_Init();
#ifdef CanFd_9
#ifdef CANFD9TX_SECONDARY
#if (CAN_176_CANFD_SET_BAUDRATE_API == STD_ON)
#if (CAN_176_CANFD_MAINFUNCTION_WRITE_API == STD_ON)
    Can_176_CanFd_SetBaudrate(CanFd_9, 1);
    Can_176_CanFd_SetControllerMode(CanFd_9, CAN_CS_STARTED);
    static uint8 Canfd_txBuffer_201[64] = {0};
    for (uint8 i = 0; i < 8u; i++) {
        Canfd_txBuffer_201[i] = (uint8)(i + 1u);
    }

    Can_PduType pduInfo_201;
    pduInfo_201.id = 0x40000201;
    pduInfo_201.length = 8;
    pduInfo_201.sdu = Canfd_txBuffer_201;
    pduInfo_201.swPduHandle = 0;

    uint32 count = 0;
    
    while (count < 10)
    {
        count++;
        Gpt_Stm_LLD_DelayMs(STM1, 50U);
        Can_176_CanFd_MainFunction_Write();
        Can_176_CanFd_Write(CANFD9TX_SECONDARY, &pduInfo_201);
    }
#endif
#endif
#endif
#endif
}

static void CANFD_0004(void)
{
    CANFD_Config_Init();
#ifdef CanFd_9
#if (CAN_176_CANFD_MAINFUNCTION_READ_API == STD_ON)
    Can_176_CanFd_SetControllerMode(CanFd_9, CAN_CS_STARTED);
    uint32 count = 0;
    
    while (count < 20)
    {
        count++;
        Can_176_CanFd_MainFunction_Read();
        Gpt_Stm_LLD_DelayMs(STM1, 100U);
    }
#endif
#endif
}


static void CANFD_0005(void)
{
#ifdef CanFd_1
#ifdef CANFD1_TX_SECONDARY
#if (CAN_176_CANFD_SET_BAUDRATE_API == STD_ON)
    static uint8 num = 0U;
    static uint8 Canfd_txBuffer_18FF1001[64] = {0};
    for (uint8 i = 0; i < 64u; i++) {
        Canfd_txBuffer_18FF1001[i] = (uint8)(i + 1u);
    }

    Can_PduType pduInfo_18FF1001;
    pduInfo_18FF1001.id = 0xD8ff1001;
    pduInfo_18FF1001.length = 64;
    pduInfo_18FF1001.sdu = Canfd_txBuffer_18FF1001;
    pduInfo_18FF1001.swPduHandle = 0;

    uint32 count = 0;

    if (num == 0U)
    {
    	CANFD_Config_Init();
        Can_176_CanFd_SetBaudrate(CanFd_1, 1);
        Can_176_CanFd_SetControllerMode(CanFd_1, CAN_CS_STARTED);
        while (count < 10)
        {
            count++;
            Gpt_Stm_LLD_DelayMs(STM1, 100U);
            Can_176_CanFd_Write(CANFD1_TX_SECONDARY, &pduInfo_18FF1001);
        }
        num++;
    }
    else
    {
        num = 0;
        count = 0;
        Can_176_CanFd_SetControllerMode(CanFd_1, CAN_CS_STARTED);
        while (count < 10)
        {
            count++;
            Gpt_Stm_LLD_DelayMs(STM1, 100U);
            Can_176_CanFd_Write(CANFD1_TX_SECONDARY, &pduInfo_18FF1001);
        }
    }
#endif
#endif
#endif
}

static void CANFD_0006(void)
{
#ifdef CanFd_9
#ifdef CANFD9TX_SECONDARY
#if (CAN_176_CANFD_SET_BAUDRATE_API == STD_ON)
#if (CAN_176_CANFD_MAINFUNCTION_BUSOFF_API == STD_ON)
#if (CAN_176_CANFD_MAINFUNCTION_WRITE_API == STD_ON)
    static uint8 num = 0U;

    static uint8 Canfd_txBuffer_201[64] = {0};
    for (uint8 i = 0; i < 8u; i++) {
        Canfd_txBuffer_201[i] = (uint8)(i + 1u);
    }

    Can_PduType pduInfo_201;
    pduInfo_201.id = 0x40000201;
    pduInfo_201.length = 8;
    pduInfo_201.sdu = Canfd_txBuffer_201;
    pduInfo_201.swPduHandle = 0;

    uint32 count = 0U;
    if (num == 0U)
    {
    	CANFD_Config_Init();
        Can_176_CanFd_SetBaudrate(CanFd_9, 1);
        Can_176_CanFd_SetControllerMode(CanFd_9, CAN_CS_STARTED);
        while (count < 10)
        {
            count++;
            Gpt_Stm_LLD_DelayMs(STM1, 100U);
            Can_176_CanFd_MainFunction_Write();
            Can_176_CanFd_Write(CANFD9TX_SECONDARY, &pduInfo_201);
            Can_176_CanFd_MainFunction_BusOff();
        }
        num++;
    }
    else
    {
        num = 0U;
        Can_176_CanFd_SetControllerMode(CanFd_9, CAN_CS_STARTED);
        count = 0U;
        while (count < 10)
        {
            count++;
            Gpt_Stm_LLD_DelayMs(STM1, 100U);
            Can_176_CanFd_MainFunction_Write();
            Can_176_CanFd_Write(CANFD9TX_SECONDARY, &pduInfo_201);
        }
    }
#endif
#endif
#endif
#endif
#endif
}


static uint8 isPortInited = 0U;
int canfd_func(int argc, char *agrv[])
{
    if ((argc > 3) || (argc < 2)) {
        PSPRINTF("error: The number of parameters exceeds 3 or is less than 2\r\n");
    }
    else
    {
        if (argc == 2)
        {
            if (!strcmp(agrv[1], "deinit"))
            {
                Can_176_CanFd_DeInit();
                PSPRINTF("Can_DeInit end!\r\n");
            }
            else if (!strcmp(agrv[1], "irq"))
            {
                CANFD_IRQ_Priority();
            }
            else if (!strcmp(agrv[1], "stop"))
            {
                PSPRINTF("Please enter the number of the device you want to stop [1-2]!\r\n");
            }
            else if (!strcmp(agrv[1], "help"))
            {
                PSPRINTF("deinit ------- CMD ------- Can_DeInit()\r\n\
            irq ---------- CMD ------- Register/enable CANFD1 and CANFD2 interrupt numbers\r\n\
            stop --------- CMD ------- Migrate the module status to stop\r\n\
            [1 - %d] ----- CMD ------- ID of the test case\r\n", CANFD_TEST_CASE_MAX);
            }
            else
            {
                uint32 id = (uint32)atoi(agrv[1]);
                if ((id >= 1) && (id <= CANFD_TEST_CASE_MAX))
                {
                    if (isPortInited == 0U)
                    {
                        Canfd_LLD_Init_Port(CANFD_MOD_ID_1);
                        Canfd_LLD_Init_Port(CANFD_MOD_ID_9);
                        isPortInited = 1U;
                    }
                    if (canfd_funcs[id - 1].canfdfunc != NULL_PTR)
                    {
                        canfd_funcs[id - 1].canfdfunc();
                    }
                    else
                    {
                        PSPRINTF("error: The ID entered does not correspond to the test code\r\n");
                    }
                }
                else
                {
                    PSPRINTF("error: Input invalid parameters[%d], please output [1 - %d] range parameters\r\n", id, CANFD_TEST_CASE_MAX);
                }
            }
        }
        else
        {
            if (!strcmp(agrv[1], "stop"))
            {
                uint32 ControllerId = (uint32)atoi(agrv[2]);
                if ((ControllerId > CAN_176_CANFD_CONTROLLER_COUNT) || (ControllerId < 1))
                {
                    PSPRINTF("error: Invalid parameter[%d], please enter the value of [1-2]!\r\n", ControllerId);
                }
                else
                {
                    if (CANFD_Controller[ControllerId - 1] != 0xFF)
                    {
                        Can_176_CanFd_SetControllerMode(CANFD_Controller[ControllerId - 1], CAN_CS_STOPPED);
                    }
                    else
                    {
                        PSPRINTF("error: The corresponding CANFD%d device is not used!\r\n", ControllerId);
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
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_MAIN), canfd_test, canfd_func, deint or number of test case);
#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif

