/*
 * MotorControl.c
 *
 *  Created on: 2024年3月11日
 *      Author: Administrator
 */

#include "MotorControl_Types.h"
#include "motor_gtm4.h"
#include "Adc.h"

uint16_t dcOfsIPhA_P3;
uint16_t dcOfsIPhB_P3;
uint16_t dcOfsIPhC_P3;

uint16_t dcOfsIPhA_P1;
uint16_t dcOfsIPhB_P1;
uint16_t dcOfsIPhC_P1;

Adc_ValueGroupType resultForFOC2_0[ADC_CONFIG_GROUPS/2][10];
Adc_ValueGroupType resultForFOC2_1[ADC_CONFIG_GROUPS/2][10];
Adc_ValueGroupType resultForBusA[10];//18V:16384;0V:0
Adc_ValueGroupType resultForBusB[10];//18V:16384;0V:0

//extern uint16_t Motor_Eqadc0_ResultFifo0Buf_Demo_01[3];
//extern uint16_t Motor_Eqadc0_ResultFifo1Buf_Demo_01[3]; /* Result buffer */
/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/** @brief The maximum value of 24 bit signed fractional data type number */
#define MOTOR_CONTROL_IPW_SFRACT24_MAX          0x7FFFFF

/** @brief The minimum value of 24 bit signed fractional data type number */
#define MOTOR_CONTROL_IPW_SFRACT24_MIN          0x800000

/** @brief The maximum value of 24 bit unsigned fractional data type number */
#define MOTOR_CONTROL_IPW_UFRACT24_MAX          0xFFFFFF

#define ATOFRE                          20000       /* ATO frequency */

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/


/** @brief The minimum inverted value of 24 bit signed fractional data type number */
static const float f32SFract24MinInv = (1 / (float)MOTOR_CONTROL_IPW_SFRACT24_MIN);

/** @brief The maximum inverted value of 24 bit unsigned fractional data type number */
static const float f32UFract24MaxInv = (1 / (float)MOTOR_CONTROL_IPW_UFRACT24_MAX);

/** @brief Constant represents the ration between PI and minimum of 24 bit signed fractional data type number */
static const float f32PiToMinSFractRatio = ((3.14159265359F) / MOTOR_CONTROL_IPW_SFRACT24_MIN);

/** @brief Constant represents the ration between maximum of 24 bit signed fractional data type number and PI */
static const float f32MaxSFractToPiRatio = (MOTOR_CONTROL_IPW_SFRACT24_MAX / (3.14159265359F));


void Iph_CalcOffsets(MotorControl_InstanceIdType xInstanceId)
{
	static uint16_t tempDcOfsPhA_P3 = 8196;
	static uint16_t tempDcOfsPhB_P3 = 8196;
	static uint16_t tempDcOfsPhC_P3 = 8196;

	static uint16_t tempDcOfsPhA_P1 = 8196;
	static uint16_t tempDcOfsPhB_P1 = 8196;
	static uint16_t tempDcOfsPhC_P1 = 8196;

	if(xInstanceId == MOTORCONTROL_INST_P3)
	{
		Adc_ReadGroup(1, &resultForFOC2_1[2][0]);
		Adc_ReadGroup(3, &resultForFOC2_1[1][0]);
		Adc_ReadGroup(5, &resultForFOC2_1[0][0]);

	    dcOfsIPhA_P3 = resultForFOC2_1[0][0] * 0.05 + tempDcOfsPhA_P3*0.95;
	    dcOfsIPhB_P3 = resultForFOC2_1[1][0] * 0.05 + tempDcOfsPhB_P3*0.95;
	    dcOfsIPhC_P3 = resultForFOC2_1[2][0] * 0.05 + tempDcOfsPhC_P3*0.95;

	    tempDcOfsPhA_P3 = dcOfsIPhA_P3;
	    tempDcOfsPhB_P3 = dcOfsIPhB_P3;
	    tempDcOfsPhC_P3 = dcOfsIPhC_P3;
	}
	else
	{
		Adc_ReadGroup(0, &resultForFOC2_0[0][0]);
		Adc_ReadGroup(2, &resultForFOC2_0[1][0]);
		Adc_ReadGroup(4, &resultForFOC2_0[2][0]);

	    dcOfsIPhA_P1 = resultForFOC2_0[0][0]*0.05 + tempDcOfsPhA_P1*0.95;
	    dcOfsIPhB_P1 = resultForFOC2_0[1][0]*0.05 + tempDcOfsPhB_P1*0.95;
	    dcOfsIPhC_P1 = resultForFOC2_0[2][0]*0.05 + tempDcOfsPhC_P1*0.95;

	    tempDcOfsPhA_P1 = dcOfsIPhA_P1;
	    tempDcOfsPhB_P1 = dcOfsIPhB_P1;
	    tempDcOfsPhC_P1 = dcOfsIPhC_P1;
	}

}

void  MotorControl_GetAnalogInputs(MotorControl_InstanceIdType xInstanceId,
                                            MotorControl_ParamInterpretationType eParamInterpret,
                                            MotorControl_AnalogInputsType *pAnalogInputs)
{
	static uint16_t cntCalDcOfs=0;
	if(cntCalDcOfs < 500)
	{
		Iph_CalcOffsets(xInstanceId);
		cntCalDcOfs++;
	}

	if(xInstanceId == MOTORCONTROL_INST_P1)
	{
		Adc_ReadGroup(0, &resultForFOC2_0[0][0]);
		Adc_ReadGroup(2, &resultForFOC2_0[1][0]);
		Adc_ReadGroup(4, &resultForFOC2_0[2][0]);
		Adc_ReadGroup(6, &resultForBusA[0]);

		//pAnalogInputs->f32DCBusVoltage = (float32)resultForBusA[0] * 0.010986328125F;
		pAnalogInputs->f32DCBusVoltage = 60.0F;

		pAnalogInputs->f32PhaseCurrentA = (float)(dcOfsIPhA_P1 - resultForFOC2_0[0][0]) * 0.009765625F; //W;
		pAnalogInputs->f32PhaseCurrentB = (float)(dcOfsIPhB_P1 - resultForFOC2_0[1][0]) * 0.009765625F; //V;
		pAnalogInputs->f32PhaseCurrentC = (float)(dcOfsIPhC_P1 - resultForFOC2_0[2][0]) * 0.009765625F; //U;
	}
	else
	{
		Adc_ReadGroup(1, &resultForFOC2_1[2][0]);
		Adc_ReadGroup(3, &resultForFOC2_1[1][0]);
		Adc_ReadGroup(5, &resultForFOC2_1[0][0]);
		Adc_ReadGroup(7, &resultForBusB[0]);

		//pAnalogInputs->f32DCBusVoltage = (float32)resultForBusB[0] * 0.010986328125F;
		pAnalogInputs->f32DCBusVoltage = 60.0F;

		pAnalogInputs->f32PhaseCurrentA = (float)(dcOfsIPhA_P3 - resultForFOC2_1[0][0]) * 0.009765625F; //W;
		pAnalogInputs->f32PhaseCurrentB = (float)(dcOfsIPhB_P3 - resultForFOC2_1[1][0]) * 0.009765625F; //V;
		pAnalogInputs->f32PhaseCurrentC = (float)(dcOfsIPhC_P3 - resultForFOC2_1[2][0]) * 0.009765625F; //U;
	}

}

void MotorControl_GetAngleAndSpeed(MotorControl_InstanceIdType xInstanceId,
                                             MotorControl_ParamInterpretationType eParamInterpret,
                                             MotorControl_AngleSpeedParamsType *pAngleSpeedParams)
{
//	pAngleSpeedParams->f32Angle = ResXBPare.PM_angle;
//	pAngleSpeedParams->f32Speed = ResXBPare.AD2S_SpdRPMH;
}

void  MotorControl_SetDutyCycles(MotorControl_InstanceIdType xInstanceId,
                                          MotorControl_ParamInterpretationType eParamInterpret,
                                          MotorControl_PhaseDutyCyclesType xDutyCycles)
{
	uint32_t  input_a = 0;      /* A相PWM */
	uint32_t  input_b = 0;     /* B相PWM */
	uint32_t  input_c = 0;     /* C相PWM */
	if(xInstanceId == MOTORCONTROL_INST_P1)
	{
		input_a = (1 - xDutyCycles.f32DutyCycleA)*PWM_PERIOD_CNT/2;
		input_b = (1 - xDutyCycles.f32DutyCycleB)*PWM_PERIOD_CNT/2;
		input_c = (1 - xDutyCycles.f32DutyCycleC)*PWM_PERIOD_CNT/2;

		(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM4, GTM_ATOM_CH0, PWM_PERIOD+1, input_a);
		(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM4, GTM_ATOM_CH1, PWM_PERIOD+1, input_b);
		(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM4, GTM_ATOM_CH2, PWM_PERIOD+1, input_c);
	}
	else
	{
		input_a = (1 - xDutyCycles.f32DutyCycleA)*PWM_PERIOD_CNT/2;
		input_b = (1 - xDutyCycles.f32DutyCycleB)*PWM_PERIOD_CNT/2;
		input_c = (1 - xDutyCycles.f32DutyCycleC)*PWM_PERIOD_CNT/2;

		(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM5, GTM_ATOM_CH0, PWM_PERIOD+1, input_a);
		(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM5, GTM_ATOM_CH1, PWM_PERIOD+1, input_b);
		(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM5, GTM_ATOM_CH2, PWM_PERIOD+1, input_c);
	}
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void HAL_SetPwmOutput(MotorControl_InstanceIdType xInstanceId, boolean bOutputControl)
{
    if (bOutputControl == PWM_OUT_ENABLE)
    {
		// 2. enable pwm
    	if(xInstanceId == MOTORCONTROL_INST_P1)
    	{
//    		SIUL2.GPDO[192U].B.PDO = 1;
//    		fs_etpu_pwmm_enable(&pwmm_instance);
    	}
    	else
    	{
//    		SIUL2.GPDO[62U].B.PDO = 1;
//    		fs_etpu_c_pwmm_enable(&pwmm_instance_c);
    	}
    }
    else if (bOutputControl == PWM_OUT_DISABLE)
    {
    	if(xInstanceId == MOTORCONTROL_INST_P1)
    	{
//    		fs_etpu_pwmm_disable(&pwmm_instance);
//    		SIUL2.GPDO[192U].B.PDO = 0;
    	}
    	else
    	{
//    		fs_etpu_c_pwmm_disable(&pwmm_instance_c);
//    		SIUL2.GPDO[62U].B.PDO = 0;
    	}
        // Reset duty cycle values to default
        MotorControl_PhaseDutyCyclesType xDutyCycles = {0.5F, 0.5F, 0.5F};
        MotorControl_SetDutyCycles(xInstanceId, MOTOR_CONTROL_RELATIVE_INTERPRET, xDutyCycles);
    }
}
