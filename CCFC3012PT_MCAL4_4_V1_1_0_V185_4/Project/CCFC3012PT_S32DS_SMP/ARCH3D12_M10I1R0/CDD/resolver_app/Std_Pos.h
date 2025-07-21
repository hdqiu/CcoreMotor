/**
 * \file Std_Pos.h
 * \brief Standard interface: Position interface
 *
 */
#ifndef Std_POSIF_H_
#define Std_POSIF_H_ 1

#include "Platform_Types.h"
/**
 * \name General configuration
 * \{
 * \addtogroup configuration_motor_general
 * \{
 */
#define EMOTOR_POLE_PAIR                    (3)                     /**< \brief Define the motor pole pair count. */

//------------------------------------------------------------------------------
/**
 * \name Inverter configuration
 * \see mod_inverter
 * \{
 * \addtogroup configuration_inverter
 * \{
 */
#define INVERTER_FREQUENCY                  (10000)                 /**< \brief Define the PWM frequency in Hz. */
#define INVERTER_DEAD_TIME                  (2.0e-6)                /**< \brief Define the dead time between the top and bottom PWM in s. */
#define INVERTER_MIN_PULSE                  (2.5e-6)                /**< \brief Define the smallest PWM pulse in s. */
#define INVERTER_CCX_ACTIVESTATE            (0)      /**< \brief Define the CCx outputs active state. Type is @ref ActiveState. */
#define INVERTER_COUTX_ACTIVESTATE          (0)      /**< \brief Define the COUTx outputs active state. Type is @ref ActiveState. */
#define INVERTER_TRIGGER_RISING_EDGE_AT_PERIOD        (0)           /**< \brief Define the Trigger rising edge. */

#define INVERTER_CCX_ACTIVESTATE_TOP            (1)
#define INVERTER_COUTX_ACTIVESTATE_BOT          (1)



#define CC_PI                  (3.1415926535897932384626433832795)
#define CC_TWO_OVER_PI         (2.0 / CC_PI)
#define CC_ONE_OVER_SQRT_THREE (0.57735026918962576450914878050196)
#define CC_SQRT_TWO            (1.4142135623730950488016887242097)

/** \brief Output event enable / disable */
typedef enum
{
    Std_Pos_MotionType_rotating,              /**< \brief Rotating sensor */
    Std_Pos_MotionType_linear                /**< \brief Linear sensor */
} Std_Pos_MotionType;

/** \brief Output event enable / disable */
typedef enum
{
    Std_Pos_ResolutionFactor_oneFold = 1,              /**< \brief Default, no multipluication factor */
    Std_Pos_ResolutionFactor_twoFold = 2,              /**< \brief 2-fold resolution. Valid for encoder */
    Std_Pos_ResolutionFactor_fourFold = 4              /**< \brief 4-fold resolution. Valid for encoder */
} Std_Pos_ResolutionFactor;

/** \brief Position sensor Types */
typedef enum
{
    Std_Pos_SensorType_encoder,
    Std_Pos_SensorType_hall,
    Std_Pos_SensorType_resolver,
    Std_Pos_SensorType_angletrk
} Std_Pos_SensorType;

/** \brief Position sensor direction definition */
typedef enum
{
    Std_Pos_Dir_forward,         /**< \brief Forward direction. For rotating position sensor, forward is clockwise rotation */
    Std_Pos_Dir_backward,        /**< \brief Backward direction. For rotating position sensor, fackward is counter-clockwise rotation */
    Std_Pos_Dir_unknown          /**< \brief Unknown direction */
} Std_Pos_Dir;

/** \brief Position sensor status definition */
typedef union
{
    uint32 status;						/**< \brief Global status access */
    struct
    {
        uint32 notSynchronised:1;		/**< \brief Sensor is not synchronized */
        uint32 signalLoss:1;			/**< \brief Loss of signal error */
        uint32 signalDegradation:1;		/**< \brief Signal degradation warning */
        uint32 trackingLoss:1;			/**< \brief Tracking loss error */
        uint32 commError:1;				/**< \brief Communication error*/
    } B;								/**< \brief Bitfielf status access */
} Std_Pos_Status;

/** \brief Forward declaration */
typedef struct Std_Pos_ Std_Pos;


/** \brief Position interface configuration */
typedef struct
{
    sint32 offset;                                  /**< \brief Position sensor offset */
    boolean reversed;                               /**< \brief If true, the sensor direction is reversed */
    sint32 resolution;                              /**< \brief Sensor resolution. For encoder with 1024 pulse per revolution, the value should be 1024 */
    uint16 periodPerRotation;                       /**< \brief Number of period per rotation. Is usually 1 for encoder */
    Std_Pos_ResolutionFactor resolutionFactor; /**< \brief Resolution multiplier for encoder interface, valid is 2, 4. */
    float32 updatePeriod;                           /**< \brief period in seconds, at which the application calls Std_Pos_update() */
    float32 speedModeThreshold;                     /**< \brief Speed threshold used for the speed calculation mode. For encoder, above the threshold the pulse count mode is used, below the threshold, the time delta is used */
    float32 minSpeed;                               /**< \brief Absolute minimal allowed speed. below speed is recognized as 0rad/s */
    float32 maxSpeed;                               /**< \brief Absolute maximal allowed speed. Above speed is recognized as error */
    boolean speedFilterEnabled;                      /**< \brief Enable / disable the speed low pass filter */
    float32 speedFilerCutOffFrequency;                     /**< \brief Speed low pass filter cut off frequency */
} Std_Pos_Config;

extern void Std_Pos_initConfig (Std_Pos_Config * config);

#endif /* Std_POSIF_H_ */
