#include <Sdadc_Rdc.h>

extern inline void SineCalib_init(SineCalib *sc);

extern Sdadc_Rdc g_DdcDsadc_b;
extern Sdadc_Rdc g_DdcDsadc_a;

float32 Gtm_Tbu_getClockFrequency()
{
    float32 result = 200*1000*1000.0F;
    return result;
}


void Sdadc_Rdc_setupElAngleConst(Sdadc_Rdc *handle, sint32 motorPolePairs)
{
    AngleTrk_setupElAngleConst(&handle->angleTrk, motorPolePairs);
}

void Sdadc_Rdc_initHwTimestamp(Sdadc_Rdc_Hw *hwHandle, const Sdadc_Rdc_ConfigHw *config)
{
    {
    	GTM4.GLS[0].TBU.CHEN.B.ENDIS_CH0 = 0x1;
    	GTM4.GLS[0].TBU.CH0_CTRL.B.CH_CLK_SRC = 0;

		const Sdadc_GtmTimestamp *tsConfig = &config->gtmTimestamp;
		{
			// TIM channel, PWM triggered:
			GTM4.GLS[tsConfig->rdcTim].CCM.TIM_AUX_IN_SRC.R |= 1 << tsConfig->rdcTimChannel;
			GTM4.GLS[tsConfig->rdcTim].TIM.IN_SRC.R |= (0x6 << (tsConfig->rdcTimChannel*4));

			//rising GPR0 captureTBU0
			GTM4.GLS[tsConfig->rdcTim].TIM.CH[tsConfig->rdcTimChannel].CTRL.R = 0x00000005|(0 << 14)|(1 << 13);
			hwHandle->rdcTimCh = &GTM4.GLS[tsConfig->rdcTim].TIM.CH[tsConfig->rdcTimChannel];

		}
		{
			GTM4.GLS[tsConfig->pwmTim].CCM.TIM_AUX_IN_SRC.R |= 1 << tsConfig->pwmTimChannel;
			GTM4.GLS[tsConfig->pwmTim].TIM.IN_SRC.R |= (0x6 << (tsConfig->pwmTimChannel*4));

			//rising GPR0 captureTBU0
			GTM4.GLS[tsConfig->pwmTim].TIM.CH[tsConfig->pwmTimChannel].CTRL.R = 0x00000005|(0 << 14)|(1 << 13);
			hwHandle->pwmTimCh = &GTM4.GLS[tsConfig->pwmTim].TIM.CH[tsConfig->pwmTimChannel];

		}
        GTM4.GLS[0].TBU.CHEN.B.ENDIS_CH0 = 0x2;
    }
}

/** Return timestamp in seconds */
float32 Sdadc_Rdc_getTimeStamp(Sdadc_Rdc *handle)
{
    Sdadc_Rdc_Ts *timestamp = &handle->timestamp;
    Sdadc_Rdc_Hw *hwHandle = &handle->hardware;

    uint32 tsPwm = hwHandle->pwmTimCh->GPR0.B.GPR0;

//    uint32 clockTicks = (tsPwm + GTM_TBU0_MAX_VALUE - timestamp->rdc)%GTM_TBU0_MAX_VALUE; //% timestamp->maxTicks;
    sint32 clockTicks = (tsPwm - timestamp->rdc); //% timestamp->maxTicks;
    if(clockTicks < 0)
    {
    	clockTicks += GTM_TBU0_MAX_VALUE;
    }
    #if Sdadc_RDC_DEBUG
    timestamp->inTicks = clockTicks;
    timestamp->pwm = tsPwm;
    #endif
    timestamp->inSeconds = timestamp->clockPeriod * (float32)clockTicks;

    return timestamp->inSeconds;
}

/** Return the update period in [seconds], i.e. the period of new result (and interrupt)*/
float32 Sdadc_Rdc_getUpdatePeriod(Sdadc_Rdc_Hw *hwHandle)
{
	return 1.0F * 48.0F / 16000000 * 32;
}



boolean Sdadc_Rdc_initHwChannels(Sdadc_Rdc_Hw *hwHandle, const Sdadc_Rdc_ConfigHw *config)
{
	return 0;
}

/**
 * Initialise the DSADC RDC driver by initialising:
 * - Two DSADC hardware channel resources
 * - Carrier generation hardware resources
 * - Time-stamp hardware resources
 * - Driver's run-time data (RAM): tracking observer, fault-detection, interface layer etc.
 *
 * \param handle Driver's handle, i.e. pointer to \ref Sdadc_Rdc RAM location
 * \param config Pointer to the driver's configuration
 */
void Sdadc_Rdc_init(Sdadc_Rdc *handle, const Sdadc_Rdc_Config *config)
{
    /* Initialise the hardware channels */
//    Sdadc_Rdc_initHwChannels(&(handle->hardware), config->hardware);

    /* Initialise the hardware timestamp resources */
    Sdadc_Rdc_initHwTimestamp(&(handle->hardware), config->hardware);

    /* Initialise the software resources */
    handle->tSample  = Sdadc_Rdc_getUpdatePeriod(&(handle->hardware));
    handle->grpDelay = 0;
    handle->timestamp.enabled = TRUE;


    handle->angleTrk.base.periodPerRotation = config->periodPerRotation;
    handle->angleTrk.base.motorPolePairs = config->motorPolePairs;
    Sdadc_Rdc_setupElAngleConst(handle, config->motorPolePairs);


    handle->timestamp.clockPeriod = 1.0F / Gtm_Tbu_getClockFrequency();
    handle->timestamp.maxTicks    = handle->tSample / handle->timestamp.clockPeriod;

    {   /* Initialise angle-tracking observer */
        AngleTrk_Config atoConfig;
        atoConfig.sinIn             = &(handle->sinIn);
        atoConfig.cosIn             = &(handle->cosIn);

        atoConfig.offset            = config->offset;
        atoConfig.speedLpfFc        = config->speedLpfFc;
        atoConfig.reversed          = config->reversed;
        atoConfig.errorThreshold    = config->errorThreshold;
        atoConfig.sqrAmplMax        = config->sqrAmplMax;
        atoConfig.sqrAmplMin        = config->sqrAmplMin;

        atoConfig.Kp                = config->Kp;
        atoConfig.Ki                = config->Ki;
        atoConfig.Kd                = config->Kd;

#if Sdadc_RDC_PRE_OBSERVER_CORRECTION
        AngleTrk_init(&(handle->angleTrk), &atoConfig, config->userTs);
#else
        AngleTrk_init(&(handle->angleTrk), &atoConfig, handle->tSample);
#endif

        SineCalib_init(&handle->sinCal);
        SineCalib_init(&handle->cosCal);
    }
}


/** Function to be executed on DSADC channel interrupt.
 * \param handle Driver's handle, i.e. pointer to \ref Sdadc_Rdc RAM location
 */
void Sdadc_Rdc_updateStep1(Sdadc_Rdc *handle)
{
	volatile sint32 sin = 0;
	volatile sint32 cos = 0;
	volatile int32_t delta = 0;
	sint32 *sin_data = handle->sdadc_sin;
	sint32 *cos_data = handle->sdadc_cos;
	sint32 sin8 = sin_data[handle->Sample_point/4];
	sint32 cos8 = cos_data[handle->Sample_point/4];
	sint32 start_point = 0;
	sint32 end_point = handle->Sample_point/2;
	uint8 i = 0;

    if(sin8*sin8 > cos8*cos8)
    {
    	if(sin8 < 0)
    	{
    		for(i = handle->Sample_point/4; i < handle->Sample_point*3/4; i++)
    		{
    			if(sin_data[i] > 0)
    			{
    				start_point = i - handle->Sample_point/2;
    				end_point = start_point + handle->Sample_point/2;
    				break;
    			}
    		}
    	}
    	else
    	{
    		for(i = handle->Sample_point/4; i < handle->Sample_point*3/4; i++)
    		{
    			if(sin_data[i] < 0)
    			{
    				start_point = i - handle->Sample_point/2;
    				end_point = start_point + handle->Sample_point/2;
    				break;
    			}
    		}
    	}
    }
    else
    {
    	if(cos8 < 0)
    	{
    		for(i = handle->Sample_point/4; i < handle->Sample_point*3/4; i++)
    		{
    			if(cos_data[i] > 0)
    			{
    				start_point = i - handle->Sample_point/2;
    				end_point = start_point + handle->Sample_point/2;
    				break;
    			}
    		}
    	}
    	else
    	{
    		for(i = handle->Sample_point/4; i < handle->Sample_point*3/4; i++)
    		{
    			if(cos_data[i] < 0)
    			{
    				start_point = i - handle->Sample_point/2;
    				end_point = start_point + handle->Sample_point/2;
    				break;
    			}
    		}
    	}
    }

    handle->zero_offset = start_point;

    for(i = 0; i < 32; i++)
    {
    	if(i < start_point)
    	{
    		sin -= sin_data[i];
    		cos -= cos_data[i];
    	}
    	else if(i < end_point)
    	{
    		sin += sin_data[i];
    		cos += cos_data[i];
    	}
    	else
    	{
    		sin -= sin_data[i];
    		cos -= cos_data[i];
    	}
    }

    handle->timestamp.rdc = handle->hardware.rdcTimCh->GPR0.B.GPR0;

#if EMOTOR_SIMULATION == 0
	handle->sinIn = (sin >> 4);
	handle->cosIn = (cos >> 4);
#endif
#if Sdadc_RDC_PRE_OBSERVER_CORRECTION == 0
    {   // expand to 32-bit data
        sint32 sinIn = (handle->sinIn << 16) / (1 << 16);
        sint32 cosIn = (handle->cosIn << 16) / (1 << 16);
        // tracking observer (note: atan2 lookup function is available inside)
        AngleTrk_step(&(handle->angleTrk), sinIn, cosIn, 0);
        AngleTrk_updateStatus(&(handle->angleTrk), sinIn, cosIn);
    }
#endif
}


/** Function to be executed at user's application interrupt or task, e.g. motor control
 * task.
 * \param handle Driver's handle, i.e. pointer to \ref Sdadc_Rdc RAM location
 * */
Pos_Raw Sdadc_Rdc_updateStep2(Sdadc_Rdc *handle)
{
    PosIf  *base = &(handle->angleTrk).base;
    float32 groupDelayAngle;
    float32 timeStampAngle;
    float32 angleOut, speedEst, angleCorrection;

    speedEst = AngleTrk_getLoopSpeed(&(handle->angleTrk));

    // group delay angle
    groupDelayAngle = handle->grpDelay * speedEst;

    // time stamp angle
    if (handle->timestamp.enabled != FALSE)
    {
        timeStampAngle = Sdadc_Rdc_getTimeStamp(handle) * speedEst;
    }
    else
    {
        timeStampAngle = 0;
    }

    angleCorrection = groupDelayAngle + timeStampAngle;

#if Sdadc_RDC_PRE_OBSERVER_CORRECTION != 0
    {   // expand to 32-bit data
        sint32 sinIn = (handle->sinIn << 16) / (1 << 16);
        sint32 cosIn = (handle->cosIn << 16) / (1 << 16);
        //sint32 sinIn = SineCalib_update(&handle->sinCal, handle->sinIn);
        //sint32 cosIn = SineCalib_update(&handle->cosCal, handle->cosIn);
        // tracking observer (note: atan2 lookup function is available inside)
        AngleTrk_step(&(handle->angleTrk), sinIn, cosIn, angleCorrection);
        AngleTrk_updateStatus(&(handle->angleTrk), sinIn, cosIn);
    }
    angleOut = handle->angleTrk.angleEst;
#else
    angleOut = handle->angleTrk.angleEst + angleCorrection;
#endif

    {   // final output angle estimation
    	Pos_Raw  newPosition = (Pos_Raw)(angleOut * (ANGLETRK_RESOLUTION / 2) / PI);
        newPosition    = (newPosition + base->offset) & (ANGLETRK_RESOLUTION - 1);
        base->position = newPosition;
        return newPosition;
    }
}


/** Synchronously start of both DSADC H/W channels.
 * \param handle Driver's handle, i.e. pointer to \ref Sdadc_Rdc RAM location
 */
void Sdadc_Rdc_startConversion(Sdadc_Rdc *handle)
{

}
