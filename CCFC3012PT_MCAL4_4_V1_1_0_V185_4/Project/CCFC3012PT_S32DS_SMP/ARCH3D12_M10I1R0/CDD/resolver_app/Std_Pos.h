/**
 * \file Std_Pos.h
 * \brief Standard interface: Position interface
 * \ingroup Std
 *
 * \version iLLD_1_0_0_4_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 * \defgroup library_srvsw_stdif_posif Standard interface: Position interface
 * \ingroup library_srvsw_stdif
 *
 * The standard interface position interface (PosIf) abstract the hardware used for position interface feature like encoder, hall, resolver, ... It provide, after proper initialization an hardware
 * Independent way to interact with the position sensor like getting position, speed, direction, ...
 *
 * The figure below shows the standard position interface.
 *
 * \image html "stdif_PosIf.png" "Standard position interface"
 *
 * This interface defines the following features:
 * -
 *
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



#define IFX_PI                  (3.1415926535897932384626433832795)
#define IFX_TWO_OVER_PI         (2.0 / IFX_PI)
#define IFX_ONE_OVER_SQRT_THREE (0.57735026918962576450914878050196)
#define IFX_SQRT_TWO            (1.4142135623730950488016887242097)

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

///** \brief Return the position, inclusive turns
// *
// * Return the sensor position in rad for rotating sensor inclusive turns, or in m for linear sensors.
// * For linear sensor the effect is the same as Std_Pos_GetPosition.
// *
// * \param driver Pointer to the interface driver object
// * \return Return the position inclusive turns in rad
// */
//typedef float32 (*Std_Pos_GetAbsolutePosition) (Std_InterfaceDriver driver);
//
///** \brief Handles the zero interrupt
// * \param driver Pointer to the interface driver object
// * \return none
// */
//typedef void (*Std_Pos_OnZeroIrq) (Std_InterfaceDriver driver);
//
///** \brief Return the raw position sensor offset
// *
// * \param driver Pointer to the interface driver object
// * \return Return the raw position sensor offset sensor in ticks
// */
//typedef sint32 (*Std_Pos_GetOffset) (Std_InterfaceDriver driver);
//
///** \brief Return the position
// *
// * Return the sensor position in rad for rotating sensor or in m for linear sensors.
// * For rotating sensor, the position is always between 0 and 2*PI.
// *
// * \param driver Pointer to the interface driver object
// * \return Return the position in rad or m
// */
//typedef float32 (*Std_Pos_GetPosition) (Std_InterfaceDriver driver);
//
///** \brief Return the direction
// *
// * Return the sensor direction.
// *
// * \param driver Pointer to the interface driver object
// * \return Return the direction
// */
//typedef Std_Pos_Dir (*Std_Pos_GetDirection) (Std_InterfaceDriver driver);
//
///** \brief Return the raw position in ticks
// *
// * Return the sensor raw position in ticks.
// *
// * \param driver Pointer to the interface driver object
// * \return Return the raw position in ticks
// */
//typedef sint32 (*Std_Pos_GetRawPosition) (Std_InterfaceDriver driver);
//
///** \brief Get the update period
// * \param driver Pointer to the interface driver object
// * \return Return the update period in s
// */
//typedef float32 (*Std_Pos_GetRefreshPeriod) (Std_InterfaceDriver driver);
//
///** \brief Get the resolution
// * \param driver Pointer to the interface driver object
// * \return Return the resolution
// */
//typedef sint32 (*Std_Pos_GetResolution) (Std_InterfaceDriver driver);
//
///** \brief Get the sensor type
// * \param driver Pointer to the interface driver object
// * \return Return the sensor type
// */
//typedef Std_Pos_SensorType (*Std_Pos_GetSensorType) (Std_InterfaceDriver driver);
//
///** \brief Return the speed
// * \param driver Pointer to the interface driver object
// * \return Return the speed in rad/s or m/s
// */
//typedef float32 (*Std_Pos_GetSpeed) (Std_InterfaceDriver driver);
//
///** \brief Refresh the status
// *
// *  Update the driver state like speed, position, status, taking into account the updatePeriod
// *
// * \param driver Pointer to the interface driver object
// * \return None
// */
//typedef void (*Std_Pos_Update) (Std_InterfaceDriver driver);
//
///** \brief Reset the driver
// *
// *  Clear faults, reset speed and position to 0
// *
// * \param driver Pointer to the interface driver object
// * \return None
// */
//typedef void (*Std_Pos_Reset) (Std_InterfaceDriver driver);
//
///** \brief Reset the driver fault
// *
// *  Clear faults
// *
// * \param driver Pointer to the interface driver object
// * \return None
// */
//typedef void (*Std_Pos_ResetFaults) (Std_InterfaceDriver driver);
//
///** \brief Set the sensor offset
// * \param driver Pointer to the interface driver object
// * \param offset Offset in sensor ticks
// * \return None
// */
//typedef void (*Std_Pos_SetOffset) (Std_InterfaceDriver driver, sint32 offset);
//
///** \brief Set the update period
// * \param driver Pointer to the interface driver object
// * \param updatePeriod Refresh period in s
// * \return None
// */
//typedef void (*Std_Pos_SetRefreshPeriod) (Std_InterfaceDriver driver, float32 updatePeriod);
//
///** \brief Standard interface object
// */
//struct Std_Pos_
//{
//    Std_InterfaceDriver driver;                            /**< \brief Interface driver object                  */
//    Std_Pos_OnZeroIrq onZeroIrq;                           /**< \brief \see Std_Pos_OnZeroIrq           */
//    Std_Pos_GetAbsolutePosition getAbsolutePosition;       /**< \brief Return the absolute position     */
//    Std_Pos_GetOffset getOffset;                           /**< \brief \see Std_Pos_GetOffset           */
//    Std_Pos_GetPosition getPosition;                       /**< \brief \see Std_Pos_GetPosition           */
//    Std_Pos_GetDirection getDirection;                     /**< \brief \see Std_Pos_GetDirection           */
//    Std_Pos_GetRawPosition getRawPosition;                 /**< \brief \see Std_Pos_GetRawPosition           */
//    Std_Pos_GetRefreshPeriod getRefreshPeriod;             /**< \brief \see Std_Pos_GetRefreshPeriod           */
//    Std_Pos_GetResolution getResolution;                   /**< \brief \see Std_Pos_GetResolution           */
//    Std_Pos_GetSensorType getSensorType;                   /**< \brief \see Std_Pos_GetSensorType           */
//    Std_Pos_Reset reset;                                   /**< \brief \see Std_Pos_Reset           */
//    Std_Pos_ResetFaults resetFaults;                       /**< \brief \see Std_Pos_ResetFaults           */
//    Std_Pos_GetSpeed getSpeed;                             /**< \brief \see Std_Pos_GetSpeed             */
//    Std_Pos_Update update;                                 /**< \brief \see Std_Pos_Update           */
//    Std_Pos_SetOffset setOffset;                           /**< \brief \see Std_Pos_SetOffset           */
//    Std_Pos_SetRefreshPeriod setRefreshPeriod;             /**< \brief \see Std_Pos_SetRefreshPeriod           */
//};


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

/** \addtogroup library_srvsw_stdif_posif
 *  \{
 */

///** \copydoc Std_Pos_OnZeroIrq */
//inline void Std_Pos_onZeroIrq (Std_Pos * stdIf)
//{
//    stdIf->onZeroIrq (stdIf->driver);
//}
//
///** \copydoc Std_Pos_GetAbsolutePosition */
//inline float32 Std_Pos_getAbsolutePosition (Std_Pos * stdIf)
//{
//    return stdIf->getAbsolutePosition (stdIf->driver);
//}
//
///** \copydoc Std_Pos_GetOffset */
//inline sint32 Std_Pos_getOffset (Std_Pos * stdIf)
//{
//    return stdIf->getOffset (stdIf->driver);
//}
//
///** \copydoc Std_Pos_GetPosition */
//inline float32 Std_Pos_getPosition (Std_Pos * stdIf)
//{
//    return stdIf->getPosition (stdIf->driver);
//}
//
///** \copydoc Std_Pos_GetDirection */
//inline Std_Pos_Dir Std_Pos_getDirection (Std_Pos * stdIf)
//{
//    return stdIf->getDirection (stdIf->driver);
//}
//
///** \copydoc Std_Pos_GetRawPosition */
//inline sint32 Std_Pos_getRawPosition (Std_Pos * stdIf)
//{
//    return stdIf->getRawPosition (stdIf->driver);
//}
//
///** \copydoc Std_Pos_GetRefreshPeriod */
//inline float32 Std_Pos_getRefreshPeriod (Std_Pos * stdIf)
//{
//    return stdIf->getRefreshPeriod (stdIf->driver);
//}
//
///** \copydoc Std_Pos_GetResolution */
//inline sint32 Std_Pos_getResolution (Std_Pos * stdIf)
//{
//    return stdIf->getResolution (stdIf->driver);
//}
//
///** \copydoc Std_Pos_GetSensorType */
//inline Std_Pos_SensorType Std_Pos_getSensorType (Std_Pos * stdIf)
//{
//    return stdIf->getSensorType (stdIf->driver);
//}
//
///** \copydoc Std_Pos_GetSpeed */
//inline float32 Std_Pos_getSpeed (Std_Pos * stdIf)
//{
//    return stdIf->getSpeed (stdIf->driver);
//}
//
///** \copydoc Std_Pos_Update */
//inline void Std_Pos_update (Std_Pos * stdIf)
//{
//    stdIf->update (stdIf->driver);
//}
//
///** \copydoc Std_Pos_Reset */
//inline void Std_Pos_reset (Std_Pos * stdIf)
//{
//    stdIf->reset (stdIf->driver);
//}
//
///** \copydoc Std_Pos_ResetFaults */
//inline void Std_Pos_resetFaults (Std_Pos * stdIf)
//{
//    stdIf->resetFaults (stdIf->driver);
//}
//
///** \copydoc Std_Pos_SetOffset */
//inline void Std_Pos_setOffset (Std_Pos * stdIf, sint32 offset)
//{
//    stdIf->setOffset (stdIf->driver, offset);
//}
//
///** \copydoc Std_Pos_SetRefreshPeriod */
//inline void Std_Pos_setRefreshPeriod (Std_Pos * stdIf, float32 updatePeriod)
//{
//    stdIf->setRefreshPeriod (stdIf->driver, updatePeriod);
//}

/** \} */

/** Initialize the configuration structure to default
 *
 * \param config Position interface configuration. This parameter is initialized by the function
 *
 */
extern void Std_Pos_initConfig (Std_Pos_Config * config);

#endif /* Std_POSIF_H_ */
