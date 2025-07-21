
/* *INDENT-OFF* Note: this file was indented manually by the author. */

#ifndef IFX_RDC_DSADC_H_
#define IFX_RDC_DSADC_H_

//________________________________________________________________________________________
// INCLUDE FILES

#include "AngleTrk.h"
#include "SineCalib.h"
#include "derivative.h"
//________________________________________________________________________________________
// CONFIGURATION DEFINES

#ifndef Sdadc_RDC_PRE_OBSERVER_CORRECTION
#define Sdadc_RDC_PRE_OBSERVER_CORRECTION  (1)
#endif

#define Sdadc_RDC_DEBUG                    (0)

#define GTM_TBU0_MAX_VALUE  (0x1<<24) // 0 ~ 23bit

//________________________________________________________________________________________
// DATA STRUCTURES

/** DSADC timestamp helper using GTM */
typedef struct
{
	uint32                 rdcTim;
	uint32                 rdcTimChannel;      /**< \brief TIM channel triggered by DSADC channel */
    uint32                 pwmTim;             /**< \brief TIM channel triggered by PWM trigger */
	uint32                 pwmTimChannel;      /**< \brief TIM channel triggered by DSADC channel */            /**< \brief TIM channel triggered by PWM trigger */
} Sdadc_GtmTimestamp;

/** DSADC RDC hardware object structure */
typedef struct
{
//  Sdadc_Dsadc_Channel    inputSin;           /**< \brief Handle to SIN input channel */
//  Sdadc_Dsadc_Channel    inputCos;           /**< \brief Handle to COS input channel */
	GTM_TIM_CH*     pwmTimCh;           /**< \brief TIM channel for PWM timestamp */
	GTM_TIM_CH*     rdcTimCh;           /**< \brief TIM channel for DSADC timestamp */
} Sdadc_Rdc_Hw;

/** DSADC RDC hardware configuration */
typedef struct
{
//    Sdadc_ChannelId  inputSin;           /**< \brief Channel ID of DSADC used for SIN input. This will override value given in the inputConfig */
//    Sdadc_ChannelId  inputCos;           /**< \brief Channel ID of DSADC used for COS input. This will override value given in the inputConfig */
   Sdadc_GtmTimestamp gtmTimestamp;     /**< \brief Timestamp helper using GTM */
} Sdadc_Rdc_ConfigHw;

typedef struct
{
    boolean       enabled;
    float32       inSeconds;

    uint32        rdc;                /**< \brief Absolute time of DSADC result */
#if Sdadc_RDC_DEBUG
    uint32        pwm;                /**< \brief Absolute time of user's PWM trigger */
    sint32        inTicks;            /**< \brief Time-stamp of last result (in ticks) */
#endif
    uint32        maxTicks;           /**< \brief Maximum time-stamp value (in ticks of absolute time clock) */

    float32       clockPeriod;        /**< \brief Period of absolute time clock (in second) */
} Sdadc_Rdc_Ts;

/** DSADC RDC data structure */
typedef struct
{
    AngleTrk      angleTrk;
    sint32        *sdadc_sin;
    sint32        *sdadc_cos;
    uint8_t       Sample_point; //per Period
    sint8         zero_offset;
    sint32        sinIn;
    sint32        cosIn;
    float32       tSample;
    float32       grpDelay;
    Sdadc_Rdc_Hw  hardware;
    Sdadc_Rdc_Ts  timestamp;
    SineCalib     sinCal;
    SineCalib     cosCal;
} Sdadc_Rdc;

/** DSADC RDC configuration structure
 * Note: if ALL Kp, Ki, Kd are zero, then the init function will use default value. */
typedef struct
{
    float32       Kp;                 /**< \brief Observer proportional gain */
    float32       Ki;                 /**< \brief Observer integral gain */
    float32       Kd;                 /**< \brief Observer differential gain */
    float32       speedLpfFc;         /**< \brief Cut-off frequency of speed low-pass filter (in Hertz). */
    float32       errorThreshold;     /**< \brief Threshold of error value in the tracking loop (in radian) */
    float32       userTs;             /**< \brief Sampling period of the application */
    sint32        sqrAmplMax;         /**< \brief Maximum value for square of signal amplitudes */
    sint32        sqrAmplMin;         /**< \brief Minimum value for square of signal amplitudes */
    sint32        periodPerRotation;  /**< \brief Number of electrical periods per mechanical rotation */
    sint32        motorPolePairs;     /**< \brief Number of motor pole pairs */
    boolean       reversed;           /**< \brief TRUE: reversed direction, FALSE: straight direction */
    Pos_Raw       offset;             /**< \brief Offset in ticks. [0 .. (\ref ANGLETRK_RESOLUTION - 1)] */

    const Sdadc_Rdc_ConfigHw* hardware;     /**< \brief Pointer to hardware config. */
} Sdadc_Rdc_Config;

//________________________________________________________________________________________
// FUNCTION PROTOTYPES

/** \addtogroup IfxLld_Dsadc_rdc
 * \{ */
/** \name Main functions
 *
 * Initialisation shall be done by using Sdadc_Rdc_init().
 *
 * After successful initialisation, one DSADC channel may generate interrupt request to CPU.
 * Function Sdadc_Rdc_updateStep1() shall be called in the interrupt service routine.
 *
 * The function Sdadc_Rdc_updateStep2() shall be called in the user application's task
 * or interrupt context for updating the final outputs (position and speed),
 * (e.g. running inside motor PWM interrupt context)
 *
 * Prototypes:
 * \{ */
extern void      Sdadc_Rdc_init              (Sdadc_Rdc *handle, const Sdadc_Rdc_Config *config);
extern void      Sdadc_Rdc_startConversion   (Sdadc_Rdc *handle);
extern void      Sdadc_Rdc_updateStep1       (Sdadc_Rdc *handle);
extern Pos_Raw   Sdadc_Rdc_updateStep2       (Sdadc_Rdc *handle);
/** \} */
/**
 * \name Getting result functions
 *
 * Example usage
 * \code
 * {  // within context of user's application interrupt or task
 *     extern Sdadc_Rdc rdcHandle;
 *     extern uint32 motorPolePairs;
 *
 *     Sdadc_Rdc_updateStep2(&rdcHandle); // final update
 *
 *     PosIf_Raw position = Sdadc_Rdc_getPosition(&rdcHandle);
 *     StdReal speedRad_s = Sdadc_Rdc_getMechSpeed(&rdcHandle);
 *     StdReal elSpeedRad_s = speedRad_s * motorPolePairs / Sdadc_Rdc_getPeriodsPerRotation(&rdcHandle);
 * }
 * \endcode
 *
 * Alternatively, the application may use \ref library_srvsw_if_posif for accessing the actual results.
 *
 * \code
 * {   // within context of user's application interrupt or task
 *     extern Sdadc_Rdc rdcHandle;
 *     PosIf* posIf = (PosIf*)&rdcHandle; // cast is safe because it's located in the same address
 *
 *     PosIf_update(posIf); // final update, alias of Sdadc_Rdc_updateStep2()
 *
 *     elAngle = PosIf_getElAngle(posIf);
 *     elSpeed = PosIf_getElSpeed(posIf);
 *     faultOccurred = PosIf_isFault(posIf);
 * }
 * \endcode
 *
 * \note the Sdadc_Rdc_updateStep2() is implementing the PosIf_update(). Therefore,
 * only one of them shall be used.
 *
 * Prototypes:
 * \{ */
static inline Pos_Raw   Sdadc_Rdc_getPosition     (Sdadc_Rdc *handle);
static inline float32   Sdadc_Rdc_getMechSpeed    (Sdadc_Rdc *handle);
static inline boolean   Sdadc_Rdc_isErrorOccurred (Sdadc_Rdc *handle);
static inline Std_Pos_Status Sdadc_Rdc_getErrorStatus(Sdadc_Rdc *handle);
static inline sint32    Sdadc_Rdc_getPeriodsPerRotation(Sdadc_Rdc *handle);
static inline sint32    Sdadc_Rdc_getMotorPolePairs(Sdadc_Rdc *handle);
void Sdadc_Rdc_setupElAngleConst(Sdadc_Rdc *handle, sint32 motorPolePairs);


/** \} */
/** \name Auxiliary functions
 * These functions are used by the main functions above
 * \{ */
extern boolean   Sdadc_Rdc_initHwChannels  (Sdadc_Rdc_Hw *hwHandle, const Sdadc_Rdc_ConfigHw *config);
extern void      Sdadc_Rdc_initHwTimestamp (Sdadc_Rdc_Hw *hwHandle, const Sdadc_Rdc_ConfigHw *config);
extern float32   Sdadc_Rdc_getUpdatePeriod (Sdadc_Rdc_Hw *hwHandle);
extern float32   Sdadc_Rdc_getTimeStamp    (Sdadc_Rdc *handle);
/** \} */
/** \} */
//________________________________________________________________________________________
// static inline FUNCTION IMPLEMENTATIONS

/** Get the actual position.
 *
 * The periods per mechanical rotation is defined in the \ref Sdadc_Rdc_Config at
 * initialisation (call to Sdadc_Rdc_init()).
 *
 * \param handle Pointer to Sdadc_Rdc object (RAM location)
 * \return actual position. Range is within 0 .. (\ref ANGLETRK_RESOLUTION - 1)
 */
static inline Pos_Raw Sdadc_Rdc_getPosition(Sdadc_Rdc *handle)
{
    return AngleTrk_getPosition(&handle->angleTrk);
}

/** Get the number of periods per rotation as configured during initialisation */
static inline sint32 Sdadc_Rdc_getPeriodsPerRotation(Sdadc_Rdc *handle)
{
    return handle->angleTrk.base.periodPerRotation;
}

/** Get Number of motor pole pairs as configured during initialisation */
static inline sint32 Sdadc_Rdc_getMotorPolePairs(Sdadc_Rdc *handle)
{
    return handle->angleTrk.base.motorPolePairs;
}

/** Get the actual electrical speed.
 *
 * \param handle Pointer to Sdadc_Rdc object (RAM location)
 * \return actual electrical speed in rad/s
 */
static inline float32 Sdadc_Rdc_getElecSpeed(Sdadc_Rdc *handle)
{
    return AngleTrk_getLoopSpeed((AngleTrk *)&handle->angleTrk)*Sdadc_Rdc_getMotorPolePairs(handle)/Sdadc_Rdc_getPeriodsPerRotation(handle);
}

/** Get the actual mechanical speed.
 *
 * \param handle Pointer to Sdadc_Rdc object (RAM location)
 * \return actual  mechanical speed in rad/s
 */
static inline float32 Sdadc_Rdc_getMechSpeed(Sdadc_Rdc *handle)
{
    return Sdadc_Rdc_getElecSpeed(handle)/Sdadc_Rdc_getMotorPolePairs(handle);
}

/** Return TRUE if at least one error has occurred */
static inline boolean Sdadc_Rdc_isErrorOccurred(Sdadc_Rdc *handle)
{
    return (handle->angleTrk.base.status.status != 0);
}

/** Return fault state. \see PosIf_Status fields for more details */
static inline Std_Pos_Status Sdadc_Rdc_getErrorStatus(Sdadc_Rdc *handle)
{
    return handle->angleTrk.base.status;
}


#endif /* IFX_RDC_DSADC_H_ */

/* *INDENT-ON* Note: this file was indented manually by the author. */

//________________________________________________________________________________________
// DOCUMENTATION

/* *INDENT-OFF* */

/**
\page page_dsadc_rdc Resolver-to-digital Converter with DSADC

\tableofcontents

One of the popular rotor positioning sensor used by electric motor drive is resolver.
A resolver device modulates carrier signal R1-R2 by the SINE and COSINE function of actual
angle and feeds it back into the controller unit (S1-S3, S2-S6).

AURIX family provides support for resolver-to-digital converter (RDC) by providing the
following functionalities:
- Carrier generation (DSADC hardware)
- Signal acquisition and carrier cancellation (DSADC hardware)
- Timestamp acquisition (GTM TIM hardware)

Additionally, the following functionalities are provided by software:
- Angle tracking observer function
- Fault detection

This page contains concept documentation of the driver software (\ref IfxLld_Dsadc_rdc "DSADC RDC"),
especially implemented in files: Sdadc_Rdc.h and Sdadc_Rdc.c

\section sec_dsadc_rdc_cgen Carrier generation

DSADC hardware supports the generation of resolver excitation carrier by providing PWM
pin outputs which can be simply filtered by low-pass filter circuit to obtain a pair of
differential signal.

Common configuration of the positive and negative signals are:
- carrier signal frequency
- bit-reversed PWM (optional, but recommended)
- waveform mode: square, triangle, or sinusoidal

Those configuration are set by Sdadc_initCarrierGen() function which is called in the
context of Sdadc_Rdc_init() function. Therefore, user only needs to call
Sdadc_Rdc_init().

For each pin output (positive and negative), a low-pass filter and amplifier circuitry
is required to drive a resolver device. Example of such circuitry can be seen in the
figure below.

TODO: add picture

\section sec_dsadc_rdc_acq Signal acquisition and carrier cancellation

Two differential signals are generated from a resolver device (Sin+, Sin-, Cos+, Cos- or
some write also as S1-S3, S2-S6). These signals basically can be connected directly into
the two channels of DSADC, where each DSADC channel has P and N inputs.

Single DSADC channel and carrier cancelation configuration is done by function
Sdadc_initChannel() which is called in the context of Sdadc_Rdc_init() function.
Therefore, user only needs to call Sdadc_Rdc_init().

Common configuration items for each DSADC channel are:
- modulator frequency (default: 10MHz)
- CIC filter type (default: COMB3)
- CIC decimation factor (default: 32)
- FIR0 and FIR1 blocks (default: disabled)

Common configuration items of the carrier cancelation in each DSADC channel are:
- offset compensation block (default: enabled)
- integration count (default: 32)

With above default values (modulator frequency 10MHz, CIC decimation factor = 32, both FIRs
disabled and integration count = 32), the output sample rate is:
  10MHz / (32 * 32) = ~9.7kHz

In each acquired sample, interrupt service is requested by the first DSADC channel
initialised by Sdadc_Rdc_init(). User's application shall provide an interrupt service
routine (ISR) to handle this request. In the ISR, or an OS task which is synchronised to
the event, user shall call Sdadc_Rdc_updateStep1() function in order to update all
necessary driver data related to this event.

\section sec_dsadc_rdc_tstmp Timestamp acquisition

Typically, user's application run at different sampling rate than DSADC output sampling
rate. For example, motor control PWM interrupt occurs with 10 kHz sampling whereas the
DSADC interrupt runs with ~9.7 kHz. This condition creates situation where the sampled
resolver position is already aged with a few timer ticks, but can be significant to the
motor control algorithm.

Therefore, timestamp which indicates the elapsed time since last DSADC channel sampling
is required for compensating or computing the missing rotor position. In addition, this
timestamp is also used for compensating the group delay which is inherent property of
DSADC.

The implementation of timestamp acquisition uses following hardware resources:
- one timebase unit or global timer (free-running), i.e. GTM TBU
- first timer capture unit, to capture the time at the DSADC sample output event, i.e.
  using GTM TIM channel
- second timer capture unit, to capture the time at the application sample point (e.g.
  PWM event), i.e. using GTM TIM channel.

Those resources are initialised by Sdadc_Rdc_initHwTimestamp() function which is called
in the context of Sdadc_Rdc_init() function. Therefore, user **doesn't need** to call
Sdadc_Rdc_initHwTimestamp() separately.

The user shall call Sdadc_Rdc_updateStep2() function in order to execute:
- timestamp and group delay compensation
- angle tracking observer
- fault-detection

\section sec_dsadc_rdc_ato Angle tracking observer

Output samples acquired by DSADC channel and carrier cancelation are the envelope of SINE
and COSINE resolver signals. In principle, ATAN2 function can be used to calculate the
rotor position (angle), but in this driver a \ref mod_AngleTrk "AngleTrk" module is used.

When user's application calls function Sdadc_Rdc_updateStep2(), function AngleTrk_step()
is also called which contains implementation of:
- ATAN2,
- 3rd order angle tracking observer

The following figure shows the idea:

TODO: add picture

ATAN2 function computes the initial angle for the observer. Additional phase is computed
from the timestamp and group delay to compensate 'missing' rotor position (angle).
The combined initial angle and phase are used as reference for the first integrator for
estimating acceleration. The second integrator estimates speed. The final integrator
estimates the output angle.

The output angle is normally more 'smooth' in steady-state than the angle from ATAN2
function, albeit some settling time and overshoot which occur during transient. The dynamic
performance depends on the gain constants set in the integrators. By default, the constants
are calculated using formula from proceeding's paper
[Design of advanced resolver-to-digital converters](http://www.univ-nantes.fr/servlet/com.univ.collaboratif.utils.LectureFichiergw?CODE_FICHIER=1307605985775&ID_FICHE=1329),
by Auger, et.al, in Electrimacs 2011, CergyPontoise (France), 6-8 june 2011.

\subsection sec_dsadc_rdc_grpdelay Group delay estimation

It is shown in previous figure that group delay is required to estimate the actual position
based on the angular speed and measured position.

The group delay of itself is estimated to be the sum of group delay of components of the
DSADC channel used for acquisition such as CIC filter, FIR0, FIR1, and Integrator blocks.

The following formulas are used to estimate the group delays:

<table>
<tr><td>CIC group delay: \f$ \tau_{CIC} = \frac{N.k}{2.F_{mod}} \f$</td></tr>
<tr><td>FIR0 group delay: \f$ \tau_{FIR0} = \frac{7}{2.F_{FIR0_{in}}} \f$</td></tr>
<tr><td>FIR1 group delay: \f$ \tau_{FIR1} = \frac{27}{2.F_{FIR1_{in}}} \f$</td></tr>
<tr><td>Integrator group delay: \f$ \tau_{INT} = \frac{N_{INT}-1}{2.F_{INT_{in}}} \f$</td></tr>
</table>

The function Sdadc_getMainGroupDelay() implements those formulas, invoked by
Sdadc_Rdc_updateStep2().

\section sec_dsadc_rdc_fault Fault detection

When application calls function Sdadc_Rdc_updateStep2(), fault detection
implemented in \ref mod_AngleTrk "AngleTrk" module is also executed.
The fault-detection is based on simple trigonometry equation:

\f$ \sin^2(\phi) + \cos^2(\phi) = 1 \f$

With some tolerance, whenever the amplitude of one of SINE or COSINE signal is outside
the allowed band, then fault flag is set. "SignalLoss" flag is set when the amplitude is
below lower boundary. "SignalDegradation" flag is set when the amplitude is higher than
upper boundary.

In addition, the flag "TrackingLoss" is set when the internal error value of the angle
tracking observer is above a threshold.

Functions Sdadc_Rdc_isErrorOccurred() and Sdadc_Rdc_getErrorStatus() can be used to
check the error flags.

Configuration of the fault-detection (tolerance) boundary values and threshold are done
by user's call to Sdadc_Rdc_init().

*/
/* *INDENT-ON* */

//________________________________________________________________________________________
