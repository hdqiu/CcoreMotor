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
    .sqrAmplMax             = 10000*10000,
    .sqrAmplMin             = 8000*8000,
    .periodPerRotation      = 3,
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
    .sqrAmplMax             = 10000*10000,
    .sqrAmplMin             = 8000*8000,
    .periodPerRotation      = 3,
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
