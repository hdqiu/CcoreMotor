#include <Sdadc_Rdc.h>

/** Hardware configuration for DSADC resolver interface */
const Sdadc_Rdc_ConfigHw cfg_Pos_RdcDs_Hardware =
{
    .gtmTimestamp = {
         .rdcTim            = 2,
         .rdcTimChannel     = 5,
         .pwmTim            = 4,
		 .pwmTimChannel     = 4
    },
};


/* 1638400  Configuration for DSADC resolver interface */
const Sdadc_Rdc_Config cfg_Pos_RdcDs_a =
{
    .speedLpfFc             = 100,
    .errorThreshold         = 20.0/180*PI,
    .sqrAmplMax             = 20000*20000,
    .sqrAmplMin             = 16000*16000,
    .periodPerRotation      = 4,
	.motorPolePairs         = 4,
    .reversed               = FALSE, //TRUE,
    .offset                 = 0,
    .hardware               = &cfg_Pos_RdcDs_Hardware,
    .userTs                 = 1.0F / INVERTER_FREQUENCY,

    /* set ALL gain to zero for using default values */
    .Kp                     = 0,
    .Ki                     = 0,
    .Kd                     = 0,
};

/** Hardware configuration for DSADC resolver interface */
const Sdadc_Rdc_ConfigHw cfg_Pos_RdcDs_Hardware1 =
{
    .gtmTimestamp = {
         .rdcTim            = 3,
         .rdcTimChannel     = 5,
         .pwmTim            = 5,
		 .pwmTimChannel     = 4
    },
};


/* 1638400  Configuration for DSADC resolver interface */
const Sdadc_Rdc_Config cfg_Pos_RdcDs_b =
{
    .speedLpfFc             = 100,
    .errorThreshold         = 20.0/180*PI,
    .sqrAmplMax             = 20000*20000,
    .sqrAmplMin             = 16000*16000,
    .periodPerRotation      = 4,
	.motorPolePairs         = 4,
    .reversed               = FALSE, //TRUE,
    .offset                 = 0,
    .hardware               = &cfg_Pos_RdcDs_Hardware1,
    .userTs                 = 1.0F / INVERTER_FREQUENCY,

    /* set ALL gain to zero for using default values */
    .Kp                     = 0,
    .Ki                     = 0,
    .Kd                     = 0,
};
/** \} */
