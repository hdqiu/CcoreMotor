#include "StandardTypes.h"
#include "tester_gpt.h"
#include "Gpt_cfg.h"
#include "shell.h"
#include "Gpt_Stm_LLDriver.h"
#include "Gpt_Rtc_LLDriver.h"
#include "Gpt_Irq.h"
#include "Gpt_AutoSar_Wrapper.h"
#include "console.h"
#include "SchM_Gpt.h"
#include <string.h>
#include "tester_canfd.h"
#include "motor_gtm4.h"
#include "tester_adc.h"
#include "Adc_Cfg.h"
#include "Pmsm_If.h"
#include "Sdadc_Rdc.h"
#include "Pmsm_PhasCurrCalc_MotB.h"

extern Sdadc_Rdc g_RdcSdadc_a;
extern Sdadc_Rdc g_RdcSdadc_b;

volatile uint32 pit0ch6_total_cnt;

#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
volatile uint8 ioTestFlag = 0;
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"

#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
uint8 u8InputValue0[4];
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
real32_T f32InputValue0[15];
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"

#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
uint8 u8OutputValue0[4];
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
real32_T f32OutputValue0[15];
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"

#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
uint8 u8InputValue1[4];
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
real32_T f32InputValue1[15];
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"

#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
uint8 u8OutputValue1[4];
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
real32_T f32OutputValue1[15];
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"

#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
uint32 Can_Motor0_Ctrl_Alive_Counter;
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
#define SDADC_START_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"
uint32 Can_Motor1_Ctrl_Alive_Counter;
#define SDADC_STOP_SEC_VAR_SHARED_INIT
#include "Sdadc_MemMap.h"

Can_PduType pduInfo_18FF1001;
Can_PduType pduInfo_Tx2;
Can_PduType pduInfo_Tx3;
Can_PduType pduInfo_Tx4;
Can_PduType pduInfo_Tx5;
uint8 Canfd_txBuffer_18FF1001[64] = {0};
uint8 Canfd_txBuffer_Tx2[64] = {0};
uint8 Canfd_txBuffer_Tx3[64] = {0};
uint8 Canfd_txBuffer_Tx4[64] = {0};
uint8 Canfd_txBuffer_Tx5[64] = {0};
extern uint8 Canfd_rxBuffer_101[];
extern uint8 Canfd_rxBuffer_102[];
extern uint8 Canfd_rxBuffer_103[];
extern uint8 Canfd_rxBuffer_104[];
extern uint8 Canfd_rxBuffer_105[];
extern volatile uint16 VuRes_MotorEAngle_NULL_a;
extern volatile float VfRes_MotorMSpd_rads_a;
extern volatile uint8 initOk;

#pragma GCC push_options
//#pragma GCC optimize ("O0")
#pragma GCC diagnostic ignored "-Wmissing-declarations"

extern Adc_ValueGroupType resultbuffer[500];
extern Adc_ValueGroupType resultbuffer_1[100];

__attribute__ ((section (".cpu0_dtcm_data"))) Adc_ValueGroupType resultForFOC2_0[ADC_CONFIG_GROUPS/2][10];
__attribute__ ((section (".cpu1_dtcm_data"))) Adc_ValueGroupType resultForFOC2_1[ADC_CONFIG_GROUPS/2][10];
__attribute__ ((section (".cpu0_dtcm_data"))) Adc_ValueGroupType resultForBusA[10];//18V:16384;0V:0
__attribute__ ((section (".cpu1_dtcm_data"))) Adc_ValueGroupType resultForBusB[10];

__attribute__ ((section (".cpu0_dtcm_data"))) uint8 timer_1ms_cnts = 0u;
__attribute__ ((section (".cpu0_dtcm_data"))) uint16 duty_u_cnt = 5000u;
__attribute__ ((section (".cpu0_dtcm_data"))) uint16 duty_v_cnt = 5000u;
__attribute__ ((section (".cpu0_dtcm_data"))) uint16 duty_w_cnt = 5000u;
__attribute__ ((section (".cpu0_dtcm_data"))) volatile uint32 foc_do_0_cnt0 = 0ul;
__attribute__ ((section (".cpu0_dtcm_data"))) volatile float32 foc_vbus = 12.0F;

void motor0_can_rec()
{
	/*******************CAN*********************/
	if(Can_Motor0_Ctrl_Alive_Counter>0)
	{
		Can_Motor0_Ctrl_Alive_Counter--;
	}
	if(u8InputValue0[1] != 0xFF)
	{
		Pmsm_u8_MotCmdSelIn = u8InputValue0[0];
		Pmsm_f32_SpdRef = 0.0F;
		Pmsm_f32_TorqCmd = 0.0F;
		Pmsm_f32_DbgIdRef = 0.0F;
		Pmsm_f32_DbgIqRef = 0.0F;
		Pmsm_f32_DbgDutyU = 0.0F;
		Pmsm_f32_DbgDutyV = 0.0F;
		Pmsm_f32_DbgDutyW = 0.0F;
		Pmsm_f32_ManuVdRef_Volt = 0.0F;
		Pmsm_f32_ManuVqRef_Volt = 0.0F;
		Pmsm_f32_DbgTheta_Rad = 0.0F;
//		Pmsm_f32_RdcThetaOffset_Rad = 0.0F;
		Pmsm_f32_VfSpeed_C = 0.0F;
	}
	else
	{
		if(Can_Motor0_Ctrl_Alive_Counter == 20000)
		{
	//		Pmsm_u8_MotCmdSelIn = 6;
			Pmsm_f32_SpdRef = 0.0F;
			Pmsm_f32_TorqCmd = 0.0F;
			Pmsm_f32_DbgIdRef = 0.0F;
			Pmsm_f32_DbgIqRef = 0.0F;
			Pmsm_f32_DbgDutyU = 0.0F;
			Pmsm_f32_DbgDutyV = 0.0F;
			Pmsm_f32_DbgDutyW = 0.0F;
			Pmsm_f32_ManuVdRef_Volt = 0.0F;
			Pmsm_f32_ManuVqRef_Volt = 0.0F;
			Pmsm_f32_DbgTheta_Rad = 0.0F;
	//		Pmsm_f32_RdcThetaOffset_Rad = 0.0F;
			Pmsm_f32_VfSpeed_C = 0.0F;
		}
		else if(Can_Motor0_Ctrl_Alive_Counter == 1)
		{
			Pmsm_u8_MotCmdSelIn = 6;
		}
		else if(Can_Motor0_Ctrl_Alive_Counter == 0)
		{
			//do nothing
		}
		else if(Can_Motor0_Ctrl_Alive_Counter > 20000)
		{
			Pmsm_u8_MotCmdSelIn = u8InputValue0[0];
			if(Pmsm_u8_MotCmdSelIn == 5)
			{
				Pmsm_f32_SpdRef = f32InputValue0[0];
			}
			else
			{
				Pmsm_f32_SpdRef = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn == 0)
			{
				Pmsm_f32_TorqCmd = f32InputValue0[1];
			}
			else
			{
				Pmsm_f32_TorqCmd = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn == 2)
			{
				Pmsm_f32_DbgIdRef = f32InputValue0[2];
				Pmsm_f32_DbgIqRef = f32InputValue0[3];
			}
			else
			{
				Pmsm_f32_DbgIdRef = 0.0F;
				Pmsm_f32_DbgIqRef = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn == 4)
			{
				Pmsm_f32_DbgDutyU = f32InputValue0[4];
				Pmsm_f32_DbgDutyV = f32InputValue0[5];
				Pmsm_f32_DbgDutyW = f32InputValue0[6];
			}
			else
			{
				Pmsm_f32_DbgDutyU = 0.0F;
				Pmsm_f32_DbgDutyV = 0.0F;
				Pmsm_f32_DbgDutyW = 0.0F;
			}
			if( (Pmsm_u8_MotCmdSelIn == 3) || (Pmsm_u8_MotCmdSelIn == 6) || (Pmsm_u8_MotCmdSelIn == 7) )
			{
				Pmsm_f32_ManuVdRef_Volt = f32InputValue0[7];
				Pmsm_f32_ManuVqRef_Volt = f32InputValue0[8];
			}
			else
			{
				Pmsm_f32_ManuVdRef_Volt = 0.0F;
				Pmsm_f32_ManuVqRef_Volt = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn == 6)
			{
				Pmsm_f32_DbgTheta_Rad = f32InputValue0[9];
			}
			else
			{
				Pmsm_f32_DbgTheta_Rad = 0.0F;
			}
	//		Pmsm_f32_RdcThetaOffset_Rad = f32InputValue0[10];//todo
			if(Pmsm_u8_MotCmdSelIn == 7)
			{
				Pmsm_f32_VfSpeed_C = f32InputValue0[11];
			}
			else
			{
				Pmsm_f32_VfSpeed_C = 0.0F;
			}

			//range check
	//		if(Pmsm_f32_SpdRef > 3000.0F)
	//		{
	//			Pmsm_f32_SpdRef = 3000.0F;
	//		}
	//		else if(Pmsm_f32_SpdRef < -3000.0F)
	//		{
	//			Pmsm_f32_SpdRef = -3000.0F;
	//		}
			if(Pmsm_f32_DbgIdRef < -10.0F)
			{
				Pmsm_f32_DbgIdRef = -10.0F;
			}
			else if(Pmsm_f32_DbgIdRef > 0.0F)
			{
				Pmsm_f32_DbgIdRef = 0.0F;
			}
			if(Pmsm_f32_DbgIqRef > 5.0F)
			{
				Pmsm_f32_DbgIqRef = 5.0F;
			}
			else if(Pmsm_f32_DbgIqRef < 0.0F)
			{
				Pmsm_f32_DbgIqRef = 0.0F;
			}
			if(Pmsm_f32_DbgDutyU > 1.0F)
			{
				Pmsm_f32_DbgDutyU = 1.0F;
			}
			else if(Pmsm_f32_DbgDutyU < 0.0F)
			{
				Pmsm_f32_DbgDutyU = 0.0F;
			}
			if(Pmsm_f32_DbgDutyV > 1.0F)
			{
				Pmsm_f32_DbgDutyV = 1.0F;
			}
			else if(Pmsm_f32_DbgDutyV < 0.0F)
			{
				Pmsm_f32_DbgDutyV = 0.0F;
			}
			if(Pmsm_f32_DbgDutyW > 1.0F)
			{
				Pmsm_f32_DbgDutyW = 1.0F;
			}
			else if(Pmsm_f32_DbgDutyW < 0.0F)
			{
				Pmsm_f32_DbgDutyW = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn == 3)
			{
				Pmsm_f32_ManuVdRef_Volt = 0.0F;
				Pmsm_f32_ManuVqRef_Volt = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn == 6)
			{
				if(Pmsm_f32_ManuVdRef_Volt > 1.0F)
				{
					Pmsm_f32_ManuVdRef_Volt = 1.0F;
				}
				else if(Pmsm_f32_ManuVdRef_Volt < 0.0F)
				{
					Pmsm_f32_ManuVdRef_Volt = 0.0F;
				}
				Pmsm_f32_ManuVqRef_Volt = 0.0F;
				Pmsm_f32_DbgTheta_Rad = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn == 7)
			{
				Pmsm_f32_ManuVdRef_Volt = 0.0F;
				Pmsm_f32_ManuVqRef_Volt = 0.0F;
				Pmsm_f32_VfSpeed_C = 0.0F;
			}
		}
	}
	/*******************CAN*********************/
}

void motor0_can_send()
{
	/*******************CAN*********************/
	u8OutputValue0[0] = Pmsm_u8_MotCmdSel;
	f32OutputValue0[0] = Pmsm_f32_PhyVs;
	f32OutputValue0[1] = Pmsm_f32_PhyVd;
	f32OutputValue0[2] = Pmsm_f32_PhyVq;
	f32OutputValue0[3] = Pmsm_f32_IdRef;
	f32OutputValue0[4] = Pmsm_f32_IqRef;
	f32OutputValue0[5] = Pmsm_f32_Id;
	f32OutputValue0[6] = Pmsm_f32_Iq;
	f32OutputValue0[7] = Pmsm_f32_MotSpdFdb;
	f32OutputValue0[8] = Pmsm_f32_RdceTheta_Rad;
	f32OutputValue0[9] = Pmsm_f32_RdceThetaOffset_Rad;
	/*******************CAN*********************/
}

#if 0
__attribute__ ((section (".cpu0_dtcm_data"))) uint16 A_Cur = 1948;
__attribute__ ((section (".cpu0_dtcm_data"))) uint16 B_Cur = 2048;
__attribute__ ((section (".cpu0_dtcm_data"))) uint16 C_Cur = 2148;
__attribute__ ((section (".cpu0_dtcm_data"))) uint16 Angle = 0;
__attribute__ ((section (".cpu0_dtcm_data"))) float32 Speed = 0;
Pmsm_100us_Task(A_Cur, B_Cur,\
				C_Cur, \
				Angle, \
				Speed, \
				12.0f, &duty_u_cnt, &duty_v_cnt, &duty_w_cnt);

#endif

void foc_do_0(void)
{
	foc_do_0_cnt0++;

	motor0_can_rec();

	SIUL.GPDO[PC7].R = 0;

	//计算旋变角度
	SuspendAllInterrupts();
	Sdadc_Rdc_updateStep2(&g_RdcSdadc_a);
    ResumeAllInterrupts();

	SIUL.GPDO[PC7].R = 1;

    //获取电流
	resultForFOC2_0[0][0] = resultbuffer[0]>>2;
	resultForFOC2_0[1][0] = resultbuffer[20]>>2;
	resultForFOC2_0[2][0] = resultbuffer[40]>>2;
	resultForBusA[0]      = resultbuffer[60]>>2;

	SIUL.GPDO[PC7].R = 0;

	foc_vbus = (float32)resultForBusA[0] * 0.010986328125F; // resultForBusA[0]/4/4096*18*10
	Pmsm_100us_Task(resultForFOC2_0[0][0], resultForFOC2_0[1][0],\
			        resultForFOC2_0[2][0], \
				    g_RdcSdadc_a.angleTrk.base.position, \
				    g_RdcSdadc_a.angleTrk.speedLpf.out, \
					12.0f, &duty_u_cnt, &duty_v_cnt, &duty_w_cnt);


	(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM4,GTM_ATOM_CH0,PWM_PERIOD+1,duty_u_cnt);
	(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM4,GTM_ATOM_CH1,PWM_PERIOD+1,duty_v_cnt);
	(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM4,GTM_ATOM_CH2,PWM_PERIOD+1,duty_w_cnt);

	timer_1ms_cnts++;
	if (timer_1ms_cnts >= 10u)
	{
		timer_1ms_cnts = 0;
		Pmsm_1ms_Task();
	}

	motor0_can_send();
}


__attribute__ ((section (".cpu1_dtcm_data"))) uint8 timer_1ms_cnts_b = 0u;
__attribute__ ((section (".cpu1_dtcm_data"))) uint16 duty_u_cnt_b = 5000u;
__attribute__ ((section (".cpu1_dtcm_data"))) uint16 duty_v_cnt_b = 5000u;
__attribute__ ((section (".cpu1_dtcm_data"))) uint16 duty_w_cnt_b = 5000u;
__attribute__ ((section (".cpu1_dtcm_data"))) volatile uint32 foc_do_1_cnt1 = 0ul;
__attribute__ ((section (".cpu1_dtcm_data"))) volatile float32 foc_vbus_b = 12.0F;

void motor1_can_rec()
{
	/*******************CAN*********************/
	if(Can_Motor1_Ctrl_Alive_Counter>0)
	{
		Can_Motor1_Ctrl_Alive_Counter--;
	}
	if(u8InputValue1[1] != 0xFF)
	{
		Pmsm_u8_MotCmdSelIn_B = u8InputValue1[0];
		Pmsm_f32_SpdRef_B = 0.0F;
		Pmsm_f32_TorqCmd_B = 0.0F;
		Pmsm_f32_DbgIdRef_B = 0.0F;
		Pmsm_f32_DbgIqRef_B = 0.0F;
		Pmsm_f32_DbgDutyU_B = 0.0F;
		Pmsm_f32_DbgDutyV_B = 0.0F;
		Pmsm_f32_DbgDutyW_B = 0.0F;
		Pmsm_f32_ManuVdRef_Volt_B = 0.0F;
		Pmsm_f32_ManuVqRef_Volt_B = 0.0F;
		Pmsm_f32_DbgTheta_Rad_B = 0.0F;
//		Pmsm_f32_RdcThetaOffset_Rad_B = 0.0F;
		Pmsm_f32_VfSpeed_C_B = 0.0F;
	}
	else
	{
		if(Can_Motor1_Ctrl_Alive_Counter == 20000)
		{
	//		Pmsm_u8_MotCmdSelIn_B = 6;
			Pmsm_f32_SpdRef_B = 0.0F;
			Pmsm_f32_TorqCmd_B = 0.0F;
			Pmsm_f32_DbgIdRef_B = 0.0F;
			Pmsm_f32_DbgIqRef_B = 0.0F;
			Pmsm_f32_DbgDutyU_B = 0.0F;
			Pmsm_f32_DbgDutyV_B = 0.0F;
			Pmsm_f32_DbgDutyW_B = 0.0F;
			Pmsm_f32_ManuVdRef_Volt_B = 0.0F;
			Pmsm_f32_ManuVqRef_Volt_B = 0.0F;
			Pmsm_f32_DbgTheta_Rad_B = 0.0F;
	//		Pmsm_f32_RdcThetaOffset_Rad_B = 0.0F;
			Pmsm_f32_VfSpeed_C_B = 0.0F;
		}
		else if(Can_Motor1_Ctrl_Alive_Counter == 1)
		{
			Pmsm_u8_MotCmdSelIn_B = 6;
		}
		else if(Can_Motor1_Ctrl_Alive_Counter == 0)
		{
			//do nothing
		}
		else if(Can_Motor1_Ctrl_Alive_Counter > 20000)
		{
			Pmsm_u8_MotCmdSelIn_B = u8InputValue1[0];
			if(Pmsm_u8_MotCmdSelIn_B == 5)
			{
				Pmsm_f32_SpdRef_B = f32InputValue1[0];
			}
			else
			{
				Pmsm_f32_SpdRef_B = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn_B == 0)
			{
				Pmsm_f32_TorqCmd_B = f32InputValue1[1];
			}
			else
			{
				Pmsm_f32_TorqCmd_B = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn_B == 2)
			{
				Pmsm_f32_DbgIdRef_B = f32InputValue1[2];
				Pmsm_f32_DbgIqRef_B = f32InputValue1[3];
			}
			else
			{
				Pmsm_f32_DbgIdRef_B = 0.0F;
				Pmsm_f32_DbgIqRef_B = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn_B == 4)
			{
				Pmsm_f32_DbgDutyU_B = f32InputValue1[4];
				Pmsm_f32_DbgDutyV_B = f32InputValue1[5];
				Pmsm_f32_DbgDutyW_B = f32InputValue1[6];
			}
			else
			{
				Pmsm_f32_DbgDutyU_B = 0.0F;
				Pmsm_f32_DbgDutyV_B = 0.0F;
				Pmsm_f32_DbgDutyW_B = 0.0F;
			}
			if( (Pmsm_u8_MotCmdSelIn_B == 3) || (Pmsm_u8_MotCmdSelIn_B == 6) || (Pmsm_u8_MotCmdSelIn_B == 7) )
			{
				Pmsm_f32_ManuVdRef_Volt_B = f32InputValue1[7];
				Pmsm_f32_ManuVqRef_Volt_B = f32InputValue1[8];
			}
			else
			{
				Pmsm_f32_ManuVdRef_Volt_B = 0.0F;
				Pmsm_f32_ManuVqRef_Volt_B = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn_B == 6)
			{
				Pmsm_f32_DbgTheta_Rad_B = f32InputValue1[9];
			}
			else
			{
				Pmsm_f32_DbgTheta_Rad_B = 0.0F;
			}
	//		Pmsm_f32_RdcThetaOffset_Rad_B = f32InputValue1[10];//todo
			if(Pmsm_u8_MotCmdSelIn_B == 7)
			{
				Pmsm_f32_VfSpeed_C_B = f32InputValue1[11];
			}
			else
			{
				Pmsm_f32_VfSpeed_C_B = 0.0F;
			}

			//range check
	//		if(Pmsm_f32_SpdRef_B > 3000.0F)
	//		{
	//			Pmsm_f32_SpdRef_B = 3000.0F;
	//		}
	//		else if(Pmsm_f32_SpdRef_B < -3000.0F)
	//		{
	//			Pmsm_f32_SpdRef_B = -3000.0F;
	//		}
			if(Pmsm_f32_DbgIdRef_B < -10.0F)
			{
				Pmsm_f32_DbgIdRef_B = -10.0F;
			}
			else if(Pmsm_f32_DbgIdRef_B > 0.0F)
			{
				Pmsm_f32_DbgIdRef_B = 0.0F;
			}
			if(Pmsm_f32_DbgIqRef_B > 5.0F)
			{
				Pmsm_f32_DbgIqRef_B = 5.0F;
			}
			else if(Pmsm_f32_DbgIqRef_B < 0.0F)
			{
				Pmsm_f32_DbgIqRef_B = 0.0F;
			}
			if(Pmsm_f32_DbgDutyU_B > 1.0F)
			{
				Pmsm_f32_DbgDutyU_B = 1.0F;
			}
			else if(Pmsm_f32_DbgDutyU_B < 0.0F)
			{
				Pmsm_f32_DbgDutyU_B = 0.0F;
			}
			if(Pmsm_f32_DbgDutyV_B > 1.0F)
			{
				Pmsm_f32_DbgDutyV_B = 1.0F;
			}
			else if(Pmsm_f32_DbgDutyV_B < 0.0F)
			{
				Pmsm_f32_DbgDutyV_B = 0.0F;
			}
			if(Pmsm_f32_DbgDutyW_B > 1.0F)
			{
				Pmsm_f32_DbgDutyW_B = 1.0F;
			}
			else if(Pmsm_f32_DbgDutyW_B < 0.0F)
			{
				Pmsm_f32_DbgDutyW_B = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn_B == 3)
			{
				Pmsm_f32_ManuVdRef_Volt_B = 0.0F;
				Pmsm_f32_ManuVqRef_Volt_B = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn_B == 6)
			{
				if(Pmsm_f32_ManuVdRef_Volt_B > 1.0F)
				{
					Pmsm_f32_ManuVdRef_Volt_B = 1.0F;
				}
				else if(Pmsm_f32_ManuVdRef_Volt_B < 0.0F)
				{
					Pmsm_f32_ManuVdRef_Volt_B = 0.0F;
				}
				Pmsm_f32_ManuVqRef_Volt_B = 0.0F;
				Pmsm_f32_DbgTheta_Rad_B = 0.0F;
			}
			if(Pmsm_u8_MotCmdSelIn_B == 7)
			{
				Pmsm_f32_ManuVdRef_Volt_B = 0.0F;
				Pmsm_f32_ManuVqRef_Volt_B = 0.0F;
				Pmsm_f32_VfSpeed_C_B = 0.0F;
			}
		}
	}
	/*******************CAN*********************/
}

void motor1_can_send()
{
	/*******************CAN*********************/
	u8OutputValue1[0] = Pmsm_u8_MotCmdSel_B;
	f32OutputValue1[0] = Pmsm_f32_PhyVs_B;
	f32OutputValue1[1] = Pmsm_f32_PhyVd_B;
	f32OutputValue1[2] = Pmsm_f32_PhyVq_B;
	f32OutputValue1[3] = Pmsm_f32_IdRef_B;
	f32OutputValue1[4] = Pmsm_f32_IqRef_B;
	f32OutputValue1[5] = Pmsm_f32_Id_B;
	f32OutputValue1[6] = Pmsm_f32_Iq_B;
	f32OutputValue1[7] = Pmsm_f32_MotSpdFdb_B;
	f32OutputValue1[8] = Pmsm_f32_RdceTheta_Rad_B;
	f32OutputValue1[9] = Pmsm_f32_RdceThetaOffset_Rad_B;
	/*******************CAN*********************/
}

__attribute__ ((section (".cpu1_dtcm_data"))) float g_angleB_test = 0.0f;
__attribute__ ((section (".cpu1_dtcm_data"))) float g_speedB_test = 0.0f;
__attribute__ ((section (".cpu1_dtcm_data"))) float g_speedB_testh = 0.0f;
__attribute__ ((section (".cpu1_dtcm_data"))) float time_stamp_test = 0.0f;
__attribute__ ((section (".cpu1_dtcm_data"))) float g_angleB[5000] = {0.0f};
__attribute__ ((section (".cpu1_dtcm_data"))) float g_speedB[5000] = {0.0f};
__attribute__ ((section (".cpu1_dtcm_data"))) float g_time_stamp[5000] = {0.0f};
__attribute__ ((section (".cpu1_dtcm_data"))) uint32_t g_cnt = 0;
__attribute__ ((section (".cpu1_dtcm_data"))) float g_PhasU[5000] = {0.0f};
__attribute__ ((section (".cpu1_dtcm_data"))) float g_PhasV[5000] = {0.0f};
__attribute__ ((section (".cpu1_dtcm_data"))) float g_PhasW[5000] = {0.0f};


void foc_do_1(void)
{
	foc_do_1_cnt1++;
	motor1_can_rec();
//	SIUL.GPDO[PQ6].R = 0;

	//计算旋变角度
	SuspendAllInterrupts();
	Sdadc_Rdc_updateStep2(&g_RdcSdadc_b);
    //for test
#if 1
    time_stamp_test = g_RdcSdadc_b.timestamp.inSeconds*1000000;
    g_speedB_test = Sdadc_Rdc_getMechSpeed(&g_RdcSdadc_b)*60.0F/(2*3.1415926F);
    g_speedB_testh =  g_speedB_testh*0.95 +  g_speedB_test * 0.05;

    g_angleB_test = g_RdcSdadc_b.angleTrk.angleEst/PI*180.0f;
    if(g_angleB_test < 0)
    {
    	g_angleB_test += 360.0f;
    }
    if(g_cnt < 5000)
    {
        g_angleB[g_cnt] = g_angleB_test;
        g_speedB[g_cnt] = g_speedB_testh;
        g_time_stamp[g_cnt] = time_stamp_test;
//        g_cnt++;
    }
#endif
    ResumeAllInterrupts();

//	SIUL.GPDO[PQ6].R = 1;

	resultForFOC2_1[2][0] = resultbuffer_1[0]>>2;
	resultForFOC2_1[1][0] = resultbuffer_1[20]>>2;
	resultForFOC2_1[0][0] = resultbuffer_1[40]>>2;
	resultForBusB[0]      = resultbuffer_1[60]>>2;

//	SIUL.GPDO[PQ6].R = 0;

	foc_vbus_b = (float32)resultForBusB[0] * 0.010986328125F; // resultForBusB[0]/4/4096*18*10
	Pmsm_100us_Task_MotB(resultForFOC2_1[0][0], resultForFOC2_1[1][0],
						 resultForFOC2_1[2][0],
						 g_RdcSdadc_b.angleTrk.base.position, \
						 g_RdcSdadc_b.angleTrk.speedLpf.out, \
						 12.0f, &duty_u_cnt_b, &duty_v_cnt_b, &duty_w_cnt_b);
	(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM5,GTM_ATOM_CH0,PWM_PERIOD+1,duty_u_cnt_b);
	(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM5,GTM_ATOM_CH1,PWM_PERIOD+1,duty_v_cnt_b);
	(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM5,GTM_ATOM_CH2,PWM_PERIOD+1,duty_w_cnt_b);
	timer_1ms_cnts_b++;
	
	if (timer_1ms_cnts_b >= 10u) {
		timer_1ms_cnts_b = 0;
		Pmsm_1ms_Task_MOTB();
	}

//	SIUL.GPDO[PQ6].R = 1;

	motor1_can_send();
}


extern volatile uint8 initOk2;
real32_T TestBBB = 1000.0;
uint8 *pp;
uint8 *p;

void Gpt_Pit0Ch6_Cbk_Notification(void)
{
	uint8 i;
	pit0ch6_total_cnt++;

	if((pit0ch6_total_cnt%100) == 0)
	{
		SIUL.GPDO[PD2].R ^= 1;
	}

   if(initOk2 == 0)
   {
	   return;
   }

#if(CAN_CORE == 2)

	u8InputValue0[0] = Canfd_rxBuffer_101[0];
	u8InputValue0[1] = Canfd_rxBuffer_101[1];
	for(i = 0; i<12;i++)
	{
		pp = (uint8*)&f32InputValue0[i];
		pp[0] = Canfd_rxBuffer_101[4 + i * 4];
		pp[1] = Canfd_rxBuffer_101[5 + i * 4];
		pp[2] = Canfd_rxBuffer_101[6 + i * 4];
		pp[3] = Canfd_rxBuffer_101[7 + i * 4];
	}

	u8InputValue1[0] = Canfd_rxBuffer_102[0];
	u8InputValue1[1] = Canfd_rxBuffer_102[1];
	for(i = 0; i<12;i++)
	{
		pp = (uint8*)&f32InputValue1[i];
		pp[0] = Canfd_rxBuffer_102[4 + i * 4];
		pp[1] = Canfd_rxBuffer_102[5 + i * 4];
		pp[2] = Canfd_rxBuffer_102[6 + i * 4];
		pp[3] = Canfd_rxBuffer_102[7 + i * 4];
	}

#endif	//(CAN_CORE == 2)

#if(CAN_CORE == 2)

//	if(canSendAllow)//if(0/*canSendAllow*/)//
	{
		Canfd_txBuffer_18FF1001[0] = u8OutputValue0[0];
		for(i = 0; i<10;i++)
		{
			p = (uint8*)&f32OutputValue0[i];
			Canfd_txBuffer_18FF1001[4 + i * 4] = *p;//(uint8) ((TestBBB) >> 24);
			p = (uint8*)&f32OutputValue0[i] + 1;
			Canfd_txBuffer_18FF1001[5 + i * 4] = *p;//(uint8) ((TestBBB) >> 16);
			p = (uint8*)&f32OutputValue0[i] + 2;
			Canfd_txBuffer_18FF1001[6 + i * 4] = *p;//(uint8) ((TestBBB) >> 8);
			p = (uint8*)&f32OutputValue0[i] + 3;
			Canfd_txBuffer_18FF1001[7 + i * 4] = *p;//(uint8) ((TestBBB) & 0xFF);
		}

		Canfd_txBuffer_Tx2[0] = u8OutputValue1[0];
		for(i = 0; i<10;i++)
		{
			p = (uint8*)&f32OutputValue1[i];
			Canfd_txBuffer_Tx2[4 + i * 4] = *p;//(uint8) ((TestBBB) >> 24);
			p = (uint8*)&f32OutputValue1[i] + 1;
			Canfd_txBuffer_Tx2[5 + i * 4] = *p;//(uint8) ((TestBBB) >> 16);
			p = (uint8*)&f32OutputValue1[i] + 2;
			Canfd_txBuffer_Tx2[6 + i * 4] = *p;//(uint8) ((TestBBB) >> 8);
			p = (uint8*)&f32OutputValue1[i] + 3;
			Canfd_txBuffer_Tx2[7 + i * 4] = *p;//(uint8) ((TestBBB) & 0xFF);
		}

		p = (uint8*)&TestBBB;
		Canfd_txBuffer_Tx3[4] = *p;//(uint8) ((TestBBB) >> 24);
		p = (uint8*)&TestBBB + 1;
		Canfd_txBuffer_Tx3[5] = *p;//(uint8) ((TestBBB) >> 16);
		p = (uint8*)&TestBBB + 2;
		Canfd_txBuffer_Tx3[6] = *p;//(uint8) ((TestBBB) >> 8);
		p = (uint8*)&TestBBB + 3;
		Canfd_txBuffer_Tx3[7] = *p;//(uint8) ((TestBBB) & 0xFF);

	    pduInfo_18FF1001.id = 0x400003F4;// 0xD8ff1001;
	    pduInfo_18FF1001.length = 64;
	    pduInfo_18FF1001.sdu = Canfd_txBuffer_18FF1001;
	    pduInfo_18FF1001.swPduHandle = 0;

		Canfd_txBuffer_Tx2[0]=2;
		pduInfo_Tx2.id = 0x400003F5;// 0xD8ff1001;
		pduInfo_Tx2.length = 64;
		pduInfo_Tx2.sdu = Canfd_txBuffer_Tx2;
		pduInfo_Tx2.swPduHandle = 0;

		Canfd_txBuffer_Tx3[0]=3;
		pduInfo_Tx3.id = 0x400003F6;// 0xD8ff1001;
		pduInfo_Tx3.length = 64;
		pduInfo_Tx3.sdu = Canfd_txBuffer_Tx3;
		pduInfo_Tx3.swPduHandle = 0;

		Canfd_txBuffer_Tx4[0]=4;
		pduInfo_Tx4.id = 0x400003F7;// 0xD8ff1001;
		pduInfo_Tx4.length = 64;
		pduInfo_Tx4.sdu = Canfd_txBuffer_Tx4;
		pduInfo_Tx4.swPduHandle = 0;

		Canfd_txBuffer_Tx5[0]=5;
		pduInfo_Tx5.id = 0x400003F8;// 0xD8ff1001;
		pduInfo_Tx5.length = 64;
		pduInfo_Tx5.sdu = Canfd_txBuffer_Tx5;
		pduInfo_Tx5.swPduHandle = 0;

		Can_176_CanFd_Write(CANFD1_TX_SECONDARY, &pduInfo_18FF1001);

		Can_176_CanFd_Write(CANFD1_TX_SECONDARY2, &pduInfo_Tx2);
		Can_176_CanFd_Write(CANFD1_TX_SECONDARY3, &pduInfo_Tx3);
		Can_176_CanFd_Write(CANFD1_TX_SECONDARY4, &pduInfo_Tx4);
		Can_176_CanFd_Write(CANFD1_TX_SECONDARY5, &pduInfo_Tx5);
	}
#endif	//(CAN_CORE == 2)
}

#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#if defined(__GNUC__) || defined(__HIGHTEC__)
#pragma GCC diagnostic pop
#endif
