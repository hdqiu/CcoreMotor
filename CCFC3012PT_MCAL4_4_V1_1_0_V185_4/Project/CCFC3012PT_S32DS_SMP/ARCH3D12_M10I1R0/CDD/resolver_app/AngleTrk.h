/**
 * \file AngleTrk.h
 * \brief Angle-tracking observer for sin/cos analog position sensor
 * \ingroup mod_AngleTrk
 *
 *
 * \license
 * You can use this file under the terms of the IFX License.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * IFX License for more details (IFX_License.txt).
 *
 * This file may be used, copied, and distributed, with or without
 * modification, provided that all copyright notices are retained;
 * that all modifications to this file are prominently noted in the
 * modified file; and that aObsv paragraph is not modified.
 *
 * \copyright Copyright (C) 2011 Infineon Technologies AG
 * \author Dian Tresna Nugraha <Dian.Nugraha@Infineon.com>
 *
 * $Revision: 1559 $
 * $Date: 2013-06-24 14:20:02 +0200 (Mon, 24 Jun 2013) $
 *
 * \defgroup mod_AngleTrk Angle-Tracking Observer
 * This driver implements \ref library_srvsw_if_posif using 3rd order Angle-Tracking Observer algorithm.
 * \ingroup library_srvsw_if_posif
 *
 * FIXME this is not an interface, it should be moved to the SysSe library
 */

#ifndef ANGLETRK_H_
#define ANGLETRK_H_

//________________________________________________________________________________________
// INCLUDES
#include <LowPassPt1.h>
#include "Platform_Types.h"
#include "Std_Pos.h"

//________________________________________________________________________________________
// CONFIGURATION DEFINES

#ifndef ANGLETRK_RESOLUTION
#define ANGLETRK_RESOLUTION     (1UL << 12)    /** \brief 12-bit default resolution */
#endif

#ifndef ANGLETRK_TEST_MODE
#define ANGLETRK_TEST_MODE      (0)
#endif
#ifndef ANGLETRK_SPEED_FILTER
#define ANGLETRK_SPEED_FILTER   (1)
#endif

#define ANGLETRK_DIRECT_SPEED   (0)  /** \brief if not zero, speed calculated from angle reference is used, else speed from tracking observer is used */

#define POSIF_DATA_BITS         (12)
#define POSIF_ANGLE_RANGE       (1UL << POSIF_DATA_BITS)
#define PI                 (3.1415926535897932384626433832795F)

//________________________________________________________________________________________
// DATA STRUCTURES
typedef sint32 Pos_Raw;

/** \brief Angle Tracking Observer configuration */
typedef struct
{
    float32   Kp;                 /**< \brief Proportional gain */
    float32   Ki;                 /**< \brief Integrator gain */
    float32   Kd;                 /**< \brief Derivative gain */
    float32   speedLpfFc;         /**< \brief Cut-off frequency of speed low-pass filter. */
    float32   errorThreshold;     /**< \brief Threshold of error value in the tracking loop */
    sint32    sqrAmplMax;         /**< \brief Maximum value for square of signal amplitudes */
    sint32    sqrAmplMin;         /**< \brief Minimum value for square of signal amplitudes */
//    sint32    periodPerRotation;  /**< \brief Number of electrical periods per mechanical rotation */
    boolean   reversed;           /**< \brief TRUE: reversed direction, FALSE: straight direction */
    Pos_Raw   offset;             /**< \brief Offset in ticks. [0 .. (\ref ANGLETRK_RESOLUTION - 1)] */
    sint16*   sinIn;              /**< \brief Pointer to SIN input variable */
    sint16*   cosIn;              /**< \brief Pointer to COS input variable */
    sint32    sincos2;
    uint8     ResErr;
} AngleTrk_Config;

typedef struct
{
	Pos_Raw    position;           /**< \brief raw position in ticks. \note: the value already contains the offset */
//    float32     speed;              /**< \brief mechanical speed in rad/s */
//    sint32      turn;               /**< \brief number of mechanical turns */
    Std_Pos_Dir   direction;          /**< \brief rotation direction */
    Std_Pos_Status status;            /**< \brief error code (0 = no error) */
    //Std_Pos_Diag  diag;               /**< \brief diagnostic and statistic */
    /* configuration */
    Pos_Raw     offset;             /**< \brief raw position offset */
    boolean     reversed;           /**< \brief reverse direction */
    sint32      periodPerRotation;  /**< \brief 'electrical' periods per mechanical rotation */
    sint32      motorPolePairs;     /**< \brief Number of motor pole pairs */
    Pos_Raw     resolution;         /**< \brief resolution of this position sensor interface */
    float32     Ts;                 /**< \brief update period in seconds */
    float32     elAngleConst;       /**< \brief constant for calculating elAngle (in ticks) from raw position */
    float32     speedConst;         /**< \brief constant for calculating mechanical speed (in rad/s) from raw speed */

} PosIf;

/** \brief Angle Tracking Observer object */
typedef struct
{
    PosIf base;
    AngleTrk_Config cfg;
    float32 halfTs;
    float32 angleAtan;
    float32 angleRef;
    float32 angleEst;
    float32 speedEstA;
    float32 speedEstB;
    float32 accelEst;
    float32 angleErr;
#if ANGLETRK_SPEED_FILTER
    Ifx_LowPassPt1 speedLpf;
#endif
#if ANGLETRK_DIRECT_SPEED
    LowPass_PT1 speedLpf2;
    float32 angleHist;  /**< \brief previous value of angleRef */
    float32 speedEst2;  /**< \brief speed estimated from angleRef in (rad/s) */
    float32 speedConst2;/**< \brief equals 1 / (2 * Ts) */
#endif
#if ANGLETRK_TEST_MODE
    struct
    {
        float32 speed;
        AngleGen gen;
    } stimuli;
#endif
} AngleTrk;


//________________________________________________________________________________________
// PUBLIC FUNCTION PROTOTYPES

/** \name Initialisation functions
 * Example use:
 * \code
 * extern sint16    g_SinInput, g_CosInput;
 * AngleTrk_Config  driverConfig;
 * AngleTrk         driverData;
 * AngleTrk_initConfig(&driverConfig, &g_SinInput, g_CosInput);
 * driverConfig.errorThreshold    = 5.0 / 180 * PI; // 5 degree error
 * driverConfig.sqrAmplMax        = 1.01 * 1.01;
 * driverConfig.sqrAmplMin        = 0.99 * 0.99;
 * driverConfig.speedLpfFc        = 100;
 * driverConfig.periodPerRotation = 1;
 * driverConfig.reversed          = FALSE;
 * driverConfig.offset            = 0;
 * AngleTrk_init(&driverData, &driverConfig);
 * \endcode
 * Prototypes:
 * \{ */
extern void    AngleTrk_init        (AngleTrk* aObsv, const AngleTrk_Config* config, float32 Ts);
extern void    AngleTrk_initConfig  (AngleTrk_Config* config, sint16* sinIn, sint16* cosIn);
/** \} */

/** \name Interface implementations
 * It is recommended to use the \ref library_srvsw_if_posif functions, e.g.:
 * \code
 * newPosition = PosIf_update(&driverData.base);
 * \endcode
 * Prototypes:
 * \{ */
extern Pos_Raw  AngleTrk_update      (AngleTrk* aObsv);
extern void     AngleTrk_setupElAngleConst(AngleTrk* aObsv, sint32 motorPolePairs);
extern Pos_Raw  AngleTrk_getPosition (AngleTrk* aObsv);
extern float32  AngleTrk_getSpeed    (AngleTrk* aObsv, boolean update);
extern sint32   AngleTrk_resetOffset (AngleTrk* aObsv);
extern void     AngleTrk_setOffset   (AngleTrk* aObsv, Pos_Raw offset);
extern float32  AngleTrk_step        (AngleTrk* aObsv, sint32 sinIn, sint32 cosIn, float32 phase);
extern void     AngleTrk_updateStatus(AngleTrk* aObsv, sint32 sinIn, sint32 cosIn);
inline float32  AngleTrk_getLoopSpeed(AngleTrk* aObsv);
inline float32  AngleTrk_getLoopSpeed(AngleTrk* aObsv)
{
#if ANGLETRK_DIRECT_SPEED == 0
//    return aObsv->speedEstB;   // note: using speedEstB has better dynamic
    return aObsv->speedLpf.out;
#else
    return aObsv->speedLpf2.out;
#endif
}

#endif /* ANGLETRK_H_ */
