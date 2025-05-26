/*
 * gelu_gtm.c
 *
 *  Created on: 2024Äê11ÔÂ20ÈÕ
 *      Author: 69405
 */
#include "CarSigGen.h"
#include "derivative.h"
#include "gtm4_cmu_lld.h"
#include "gtm4_lld.h"
#include "gtm4_atom_lld.h"
#include "gtm4_tim_lld.h"
//#include "mcu_lld.h"
#include "console.h"

#define FIFO_SIZE	64  /* 50 entries to generate cosine */
#define TI_EXCT_PERD	300 /* 1.5us@200MHz */

#if 0
const uint32_t EXC_CARDIG_Buffer[50] = {100,112,125,136,148,158,168,176,184,190,\
                                        194,197,199,199,197,194,190,184,176,168,\
                                        158,148,136,125,112,100, 88, 75, 64, 52,\
                                         42, 32, 24, 16, 10,  6,  3,  1,  1,  3,\
                                          6,   10,  16,  24,  32,  42,  52, 64,  75,  88};
#elif 0
const uint32_t EXC_CARDIG_Buffer[64] = {
										300, 299, 297, 294, 289, 282, 275, 266,\
										256, 245, 233, 221, 207, 194, 179, 165,\
										150, 135, 121, 106,  93,  79,  67,  55,\
										 44,  34,  25,  18,  11,   6,   3,   1,\
										  0,   1,   3,   6,  11,  18,  25,  34,\
										 44,  55,  67,  79,  93, 106, 121, 135,\
										 150, 165, 179, 194, 207, 221, 233, 245,\
										 256, 266, 275, 282, 289, 294, 297, 299};
#else

const uint32_t EXC_CARDIG_Buffer[FIFO_SIZE] = {
										269, 268, 265, 261, 256, 250, 243, 235,\
										226, 217, 207, 196, 185, 173, 162, 150,\
										138, 127, 115, 104,  93,  83,  74,  65,\
										 57,  50,  44,  39,  35,  32,  31,  30,\
										 31,  32,  35,  39,  44,  50,  57,  65,\
										 74,  83,  93, 104, 115, 127, 138, 150,\
										162, 173, 185, 196, 207, 217, 226, 235,\
										243, 250, 256, 261, 265, 268, 269, 270};
#endif


void CarSigGen_Init(void)
{
	uint32_t FIFO_Rolling ;
    //res_gtm_gensin_pinint start
	SIUL.PCR[PA12].R = 0x0A80;	//TOUT21	->	PA12
	SIUL.PCR[PP3].R = 0x0880;	//TOUT24	->	PP3
	GTM_LLD_SetToutSel_lld(21, 2);	//ATOM2_3	->	TOUT21
	GTM_LLD_SetToutSel_lld(24, 8);	//ATOM2_3_N	->	TOUT24


//    //TRIGER SDADC ATOM2_4
//	SIUL.PCR[PP1].R = 0x0880;	//TOUT2	->	PP1
//	GTM_LLD_SetToutSel_lld(22, 2);	//ATOM2_4	->	TOUT22
//
//    // SDADC TRIGER TimeSample ATOM2_5
//	SIUL.PCR[PP14].R = 0x0980;	//TOUT35	->	PP14
//	GTM_LLD_SetToutSel_lld(35, 2);	//ATOM2_5	->	TOUT35
//
//	// SARADC TRIGER TimeSample ATOM4_4
//	SIUL.PCR[PJ7].R = 0x0780;	//TOUT50	->	PJ7
//	GTM_LLD_SetToutSel_lld(50, 3);	//ATOM4_4	->	TOUT50


	SIUL.PCR[PP8].R = 0x0880;	//TOUT29	->	PP8
	SIUL.PCR[PA7].R = 0x0C80;	//TOUT16	->	PA7
	GTM_LLD_SetToutSel_lld(29, 3);	//ATOM3_3	->	TOUT29
	GTM_LLD_SetToutSel_lld(16, 10);	//ATOM3_3_N	->	TOUT16

    //res_gtm_gensin_pinint end
	//res_gtm_gensin_init start
	GTM4.GLS[0].PSM.FIFO.CH[0].START_ADDR.R = 0x0;
	GTM4.GLS[0].PSM.FIFO.CH[0].END_ADDR.R = FIFO_SIZE*4 - 1;
	GTM4.GLS[0].PSM.FIFO.CH[0].CTRL.R	= 0x9;	// PSM operates in Ring Buffer Mode

	GTM4.GLS[0].PSM.F2A.STR_CH[0].STR_CFG.R	= 0x50000;	// transfer FIFO data to ARU high word (duty cycle of PWM)

	for( FIFO_Rolling=0; FIFO_Rolling < FIFO_SIZE; FIFO_Rolling++)
	{
		GTM4.GLS[0].PSM.AFD.CH[0].BUF_ACC.R = EXC_CARDIG_Buffer[FIFO_Rolling] ;
	}

	GTM4.GLS[0].PSM.F2A.F2A_ENABLE.B.STR0_EN = 2 ;

	// Configure ATOM channel for PWM, compare values reloaded from FIFO by ARU
	GTM4.GLS[2].ATOM.CH[3].CTRL.R = 0x0000002A;		//CAu: up counter mode

	//CMU_CLK0, Duty cycle active high, Continuous running, SOMP, CN counts up then down, CMx are reloaded when CN0=0; ARU enabled
	GTM4.GLS[2].ATOM.CH[3].CN0.R = 0;
	GTM4.GLS[2].ATOM.CH[3].CM1.B.CM1 = 150; //PWM Duty (High Time)
	GTM4.GLS[2].ATOM.CH[3].CM0.B.CM0 = 300; //PWM Period


	/* Threshold Shadow Registers */
	GTM4.GLS[2].ATOM.CH[3].SR1.B.SR1 = 150; //PWM Duty (High Time)
	GTM4.GLS[2].ATOM.CH[3].SR0.B.SR0 = 300; //PWM Period

	// Select FIfo channel to read from via ARU
	GTM4.GLS[2].ATOM.CH[3].RDADDR.B.RDADDR0	= 0x001;		// get data from PSM channel0

	GTM4.GLS[2].CDTM.DTM[4].CH_CTRL2.B.DT0_3 = 1U;
	GTM4.GLS[2].CDTM.DTM[4].CH_CTRL2.B.DT1_3 = 1U;

	GTM4.GLS[1].PSM.FIFO.CH[1].START_ADDR.R = 0x0;
	GTM4.GLS[1].PSM.FIFO.CH[1].END_ADDR.R = FIFO_SIZE*4 - 1;
	GTM4.GLS[1].PSM.FIFO.CH[1].CTRL.R	= 0x9;	// PSM operates in Ring Buffer Mode

	GTM4.GLS[1].PSM.F2A.STR_CH[1].STR_CFG.R	= 0x50000;	// transfer FIFO data to ARU high word (duty cycle of PWM)

	for( FIFO_Rolling=0; FIFO_Rolling < FIFO_SIZE; FIFO_Rolling++)
	{
		GTM4.GLS[1].PSM.AFD.CH[1].BUF_ACC.R = EXC_CARDIG_Buffer[FIFO_Rolling] ;
	}

	GTM4.GLS[1].PSM.F2A.F2A_ENABLE.B.STR1_EN = 2 ;

	// Configure ATOM channel for PWM, compare values reloaded from FIFO by ARU
	GTM4.GLS[3].ATOM.CH[3].CTRL.R = 0x0000002A;		//CAu: up counter mode

	//CMU_CLK0, Duty cycle active high, Continuous running, SOMP, CN counts up then down, CMx are reloaded when CN0=0; ARU enabled
	GTM4.GLS[3].ATOM.CH[3].CN0.R = 0;
	GTM4.GLS[3].ATOM.CH[3].CM1.B.CM1 = 150; //PWM Duty (High Time)
	GTM4.GLS[3].ATOM.CH[3].CM0.B.CM0 = 300; //PWM Period

	/* Threshold Shadow Registers */
	GTM4.GLS[3].ATOM.CH[3].SR1.B.SR1 = 150; //PWM Duty (High Time)
	GTM4.GLS[3].ATOM.CH[3].SR0.B.SR0 = 300; //PWM Period

	// Select FIfo channel to read from via ARU
	GTM4.GLS[3].ATOM.CH[3].RDADDR.B.RDADDR0	= 0x00A;		// get data from PSM channel1

	GTM4.GLS[3].CDTM.DTM[4].CH_CTRL2.B.DT0_3 = 1U;
	GTM4.GLS[3].CDTM.DTM[4].CH_CTRL2.B.DT1_3 = 1U;
	//res_gtm_gensin_init end

	//TRIGER SDADC ATOM2_4
	GTM4.GLS[2].ATOM.CH[4].SOMP.B.MODE = 0x2;		//CAu: up counter mode
	GTM4.GLS[2].ATOM.CH[4].SOMP.B.SL = 1;
	GTM4.GLS[2].ATOM.CH[4].CTRL_SR.B.SL_SR = 1u;
	//CMU_CLK0, Duty cycle active high, Continuous running, SOMP, CN counts up then down, CMx are reloaded when CN0=0; ARU enabled
	GTM4.GLS[2].ATOM.CH[4].CN0.R = 0;
	GTM4.GLS[2].ATOM.CH[4].CM1.B.CM1 = 300; //PWM Duty (High Time)
	GTM4.GLS[2].ATOM.CH[4].CM0.B.CM0 = 19200; //PWM Period
	GTM4.GLS[2].ATOM.CH[4].SR1.B.SR1 = 300; //PWM Duty (High Time)
	GTM4.GLS[2].ATOM.CH[4].SR0.B.SR0 = 19200; //PWM Period

	//SDADC TRIGER TimeSample ATOM2_5
	GTM4.GLS[2].ATOM.CH[5].SOMP.B.MODE = 0x2;		//CAu: up counter mode
	GTM4.GLS[2].ATOM.CH[5].SOMP.B.SL = 1;
	GTM4.GLS[2].ATOM.CH[5].CTRL_SR.B.SL_SR = 1u;
	//CMU_CLK0, Duty cycle active high, Continuous running, SOMP, CN counts up then down, CMx are reloaded when CN0=0; ARU enabled
	GTM4.GLS[2].ATOM.CH[5].CN0.R = 0;
	GTM4.GLS[2].ATOM.CH[5].CM1.B.CM1 = 300; //PWM Duty (High Time)
	GTM4.GLS[2].ATOM.CH[5].CM0.B.CM0 = 19200; //PWM Period
	GTM4.GLS[2].ATOM.CH[5].SR1.B.SR1 = 300; //PWM Duty (High Time)
	GTM4.GLS[2].ATOM.CH[5].SR0.B.SR0 = 19200; //PWM Period

	GTM4.GLS[2].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL4 = 2;	// enabling update of CMx by SRx registers
	GTM4.GLS[2].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL4 = 2;	// enabling
	GTM4.GLS[2].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL4 = 2;

	GTM4.GLS[2].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL5 = 2;	// enabling update of CMx by SRx registers
	GTM4.GLS[2].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL5 = 2;	// enabling
	GTM4.GLS[2].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL5 = 2;

	//res_gtm_gensin_start start
	GTM4.GLS[2].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL3 = 2;	// enabling update of CMx by SRx registers
	GTM4.GLS[2].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL3 = 2;	// enabling
	GTM4.GLS[2].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL3 = 2;

	GTM4.GLS[2].ATOM.AGC.GLB_CTRL.B.HOST_TRIG = 1;

	GTM4.GLS[2].ATOM.CH[4].SR0.B.SR0 = 300; //PWM Period

	//TRIGER SDADC ATOM3_4
	GTM4.GLS[3].ATOM.CH[4].SOMP.B.MODE = 0x2;		//CAu: up counter mode
	GTM4.GLS[3].ATOM.CH[4].SOMP.B.SL = 1;
	GTM4.GLS[3].ATOM.CH[4].CTRL_SR.B.SL_SR = 1u;
	//CMU_CLK0, Duty cycle active high, Continuous running, SOMP, CN counts up then down, CMx are reloaded when CN0=0; ARU enabled
	GTM4.GLS[3].ATOM.CH[4].CN0.R = 0;
	GTM4.GLS[3].ATOM.CH[4].CM1.B.CM1 = 300; //PWM Duty (High Time)
	GTM4.GLS[3].ATOM.CH[4].CM0.B.CM0 = 19200; //PWM Period
	GTM4.GLS[3].ATOM.CH[4].SR1.B.SR1 = 300; //PWM Duty (High Time)
	GTM4.GLS[3].ATOM.CH[4].SR0.B.SR0 = 19200; //PWM Period

	//SDADC TRIGER TimeSample ATOM3_5
	GTM4.GLS[3].ATOM.CH[5].SOMP.B.MODE = 0x2;		//CAu: up counter mode
	GTM4.GLS[3].ATOM.CH[5].SOMP.B.SL = 1;
	GTM4.GLS[3].ATOM.CH[5].CTRL_SR.B.SL_SR = 1u;
	//CMU_CLK0, Duty cycle active high, Continuous running, SOMP, CN counts up then down, CMx are reloaded when CN0=0; ARU enabled
	GTM4.GLS[3].ATOM.CH[5].CN0.R = 0;
	GTM4.GLS[3].ATOM.CH[5].CM1.B.CM1 = 300; //PWM Duty (High Time)
	GTM4.GLS[3].ATOM.CH[5].CM0.B.CM0 = 19200; //PWM Period
	GTM4.GLS[3].ATOM.CH[5].SR1.B.SR1 = 300; //PWM Duty (High Time)
	GTM4.GLS[3].ATOM.CH[5].SR0.B.SR0 = 19200; //PWM Period

	GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL4 = 2;	// enabling update of CMx by SRx registers
	GTM4.GLS[3].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL4 = 2;	// enabling
	GTM4.GLS[3].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL4 = 2;

	GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL5 = 2;	// enabling update of CMx by SRx registers
	GTM4.GLS[3].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL5 = 2;	// enabling
	GTM4.GLS[3].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL5 = 2;


	GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL4 = 2;	// enabling update of CMx by SRx registers
	GTM4.GLS[3].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL4 = 2;	// enabling
	GTM4.GLS[3].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL4 = 2;

	GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL5 = 2;	// enabling update of CMx by SRx registers
	GTM4.GLS[3].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL5 = 2;	// enabling
	GTM4.GLS[3].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL5 = 2;

	//res_gtm_gensin_start start
	GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.UPEN_CTRL3 = 2;	// enabling update of CMx by SRx registers
	GTM4.GLS[3].ATOM.AGC.ENDIS_CTRL.B.ENDIS_CTRL3 = 2;	// enabling
	GTM4.GLS[3].ATOM.AGC.OUTEN_CTRL.B.OUTEN_CTRL3 = 2;

	GTM4.GLS[3].ATOM.AGC.GLB_CTRL.B.HOST_TRIG = 1;

	GTM4.GLS[3].ATOM.CH[4].SR0.B.SR0 = 300; //PWM Period
	//res_gtm_gensin_start end
}
