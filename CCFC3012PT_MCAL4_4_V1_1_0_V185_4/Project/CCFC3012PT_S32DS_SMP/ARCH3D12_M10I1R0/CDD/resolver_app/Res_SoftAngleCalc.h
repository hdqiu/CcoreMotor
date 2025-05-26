#ifndef _Res_SoftAngleCalc_H
#define _Res_SoftAngleCalc_H

#include <Sdadc_Rdc.h>
#include "Platform_Types.h"
#include "Mcal.h"

#define Abs(A)    ((A>=0)?A:-A)

#define Motor_Poles         4
#define Resolver_Poles      4
#define Poles_Ratio_Coeff   1
#define GM_Low_Lass_A 		0.95
#define GM_Low_Lass_B       0.05
#define AD2SXB_12Bit        0XFFF

typedef struct {
	uint16      PM_angle;
	sint32      Ressin;
	sint32      Rescos;
	int16       Res_angle;
	float32     speedEst;
	int16       AD2S_Spd;
	uint16	    init_Angle;
	int16       AD2S_SpdRPM;
	int16       AD2S_SpdRPMH;
	uint16      Abs_SpdRPM;
	uint32      Res_sincos2;
	uint8       Res_Fault;
}ResXB;

#define  ResXB_DEFAULTS {0,0,0,0,0,0,0,0,0,0,0,0}       // 鍒濆鍖栧弬鏁�

extern ResXB      ResXBPare_a;
extern ResXB      ResXBPare_b;

void Res_PWMCalcInit(void);
void Res_SoftAngleCalc(void);
void Res_Dsadcupdate(Sdadc_Rdc *handle , sint32 * sin, sint32 * cos);
void Res_PWMupdateCalc(Sdadc_Rdc *handle, ResXB *ResXBPare);
#endif /* Res_SoftAngleCalc_H*/
//===========================================================================
// End of file.
//===========================================================================
