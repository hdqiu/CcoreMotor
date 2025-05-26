/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC3012PT           
* DESCRIPTION : can demo code 
* HISTORY     : Initial version.
* @file     can_demo.h
* @version  4.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/


#ifndef CANFD_DEMO_H_
#define CANFD_DEMO_H_
/*PRQA S 0635 EOF*/
#include "Can_176_CanFD_LLDriver.h"
#include "Can_176_CanFD.h"
#include "common.h"

#ifdef RESOURCE_SUPPORT_CANFD_IP
#define CANFD_TEST_FUN 0
#define CANFD_TEST_LOCK 1
#define CANFD_PORT_TEST 0

typedef void (*Canfdfunc)(void);
typedef struct _CanfdfuncMachine
{
    char *name;
    Canfdfunc canfdfunc;
}CanfdfuncMachine;

union CanfdFrame {
    uint8 byte[8];
    uint32 word[2];
    struct {
        uint32 CFG_REQ:2;
        uint32 CFG_TX_IDE:1;
        uint32 CFG_TX_EID:18;
        uint32 CFG_TX_SID:11;
        //
        uint32 CFG_TX_Other_Data:8;
        uint32 CFG_TX_Data0:8;
        uint32 CFG_TX_FDF:1;
        uint32 CFG_TX_RTR_RRS:1;
        uint32 CFG_TX_BRS:1;
        uint32 CFG_TX_ESI_r0:1;
        uint32 CFG_TX_DLC:4;
        uint32 CFG_REQ_TEC_REC:2;
        uint32 CFG_IDX:6;
    } u64;
};

union CanfdFrameREQ_DATA {
    uint8 byte[4];
    struct {
        uint8 byte[3];
        uint8 Resv:5;
        uint8 REQ_DATA_BACK:1;
        uint8 REQ_TEC_REC:2;
    } B;
};

#ifdef Can_176_CanFd_LPduReceiveCalloutFunction
FUNC(Std_ReturnType, CAN_CODE) CanFdLPduReceiveCalloutFunction \
( \
    VAR(uint8, AUTOMATIC) u8Can_Hrh, \
    VAR(Can_IdType, AUTOMATIC) u32Can_CanId, \
    VAR(uint8, AUTOMATIC) u8Can_Dlc, \
    P2CONST(uint8, AUTOMATIC, CAN_APPL_CONST) u8Can_SduPtr \
);
#endif
void CANFD_Config_Init(void);
void CANFD_GPT_Callback_10ms_Function(void);
void CANFD_GPT_Callback_20ms_Function(void);
void CANFD_GPT_Callback_30ms_Function(void);
void Canfd_Test_Main(void);
FUNC(void,CAN_CODE) error_notify(VAR(uint8, AUTOMATIC) u8Can_ControllerId);
int canfd_func(int argc, char *agrv[]);
void CANFD_IRQ_Priority();

#endif /*RESOURCE_SUPPORT_CANFD_IP*/

#endif /* CAN_DEMO_H_ */
