/*
 * motor_main.c
 *
 *  Created on: 2024年12月27日
 *      Author: Administrator
 */

#include <gdflib.h>
#include <gflib.h>
#include <gmclib.h>
#include <mlib.h>
#include "MotorControl_Types.h"
#include "motor_gtm4.h"


typedef struct
{
    tU32              svmSector;      /* Space Vector Modulation sector */
    tFloat            thRotEl;		 /* El. position entering to the control loop */
    tFloat            wRotEl;			/* El. speed entering to the control loop */
    SWLIBS_2Syst      thTransform;   /* Transformation angle - for Park transformation */
    SWLIBS_2Syst      uDQReq;         /* dq - axis required voltages given by current PIs */
    SWLIBS_2Syst      uAlBeReq;       /* Required dq currents transformed into the Alpha/Beta orth. system */
} pmsm_open_t;

__attribute__ ((section (".cpu0_dtcm_data"))) pmsm_open_t Motor_open = {0};

#define GTM_CLK  200*1000*1000
#define PWM_PERIOD 10000 //10K
#define PWM_CNT GTM_CLK/PWM_PERIOD

#define PI   (3.1415926535897932384626433832795F)

void MotorControl_SetDuty(SWLIBS_3Syst_FLT xDutyCycles, uint32_t period_cnt)
{
	uint32_t  input_a = 0;      /* A相PWM */
	uint32_t  input_b = 0;     /* B相PWM */
	uint32_t  input_c = 0;     /* C相PWM */

	input_a = (1 - xDutyCycles.fltArg1)*period_cnt/2;
	input_b = (1 - xDutyCycles.fltArg2)*period_cnt/2;
	input_c = (1 - xDutyCycles.fltArg3)*period_cnt/2;

	(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM4, GTM_ATOM_CH0, period_cnt + 1, input_a);
	(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM4, GTM_ATOM_CH1, period_cnt + 1, input_b);
	(void)GTM_ATOM_LLD_Channel_SetShadowRegister_lld(GTM_ATOM4, GTM_ATOM_CH2, period_cnt + 1, input_c);
}


// speed rad/s
void motor_loop(float Ud, float Uq, float Vbus, float speed)
{
	Motor_open.wRotEl = speed;

	 Motor_open.thRotEl += Motor_open.wRotEl/PWM_PERIOD;
	 if(Motor_open.thRotEl > PI)
	 {
		 Motor_open.thRotEl = Motor_open.thRotEl - 2*PI;
	 }

    /* Function performs Sin(angle) and Cos (angle) */
     GFLIB_SinCos(Motor_open.thRotEl , &Motor_open.thTransform);

     Motor_open.uDQReq.fltArg1 = Ud;
     Motor_open.uDQReq.fltArg2 = Uq;

     GMCLIB_ParkInv(&Motor_open.uAlBeReq, &Motor_open.thTransform, &Motor_open.uDQReq);

     SWLIBS_2Syst uAlBeAbsolute;
     uAlBeAbsolute.fltArg1 = Motor_open.uAlBeReq.fltArg1/(Vbus/sqrtf(3));  /* (Udc_max/sqrt3) * Ualpha */
     uAlBeAbsolute.fltArg2 = Motor_open.uAlBeReq.fltArg2/(Vbus/sqrtf(3));  /* (Udc_max/sqrt3) * Ubeta */

     SWLIBS_3Syst_FLT pPhAbcDuty = {0};
     Motor_open.svmSector = GMCLIB_SvmStd(&pPhAbcDuty, &uAlBeAbsolute);

     MotorControl_SetDuty(pPhAbcDuty, PWM_CNT);
}


//PWM 中断调用
void open_loop()
{
	motor_loop(2, 0, 12, 62.8);
}
