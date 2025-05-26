/*
 * MotorControl_Types.h
 *
 *  Created on: 2024Äê3ÔÂ11ÈÕ
 *      Author: Administrator
 */

#ifndef MOTORCONTROL_TYPES_H_
#define MOTORCONTROL_TYPES_H_

#include "typedefs.h"

#define MOTORCONTROL_INST_P1 (0U)
#define MOTORCONTROL_INST_P3 (1U)
/*==================================================================================================
*                                           MACROS
==================================================================================================*/
#define PWM_OUT_ENABLE  (TRUE)
#define PWM_OUT_DISABLE (FALSE)

/**
 * @brief Value representation possible options
 */
typedef enum
{
    MOTOR_CONTROL_ELECTRIC_REPRES   = 0x00U, /**< @brief Angle and speed are represented in electric values */
    MOTOR_CONTROL_MECHANICAL_REPRES = 0x01U  /**< @brief Angle and speed are represented in mechanical values */
} MotorControl_Ipw_ValueRepresentationType;

/**
 * @brief Output value alignment possible options
 */
typedef enum
{
    MOTOR_CONTROL_LATEST_VALUE    = 0x00U, /**< @brief Angle and speed outputs are calculated */
    MOTOR_CONTROL_ONTRIGGER_VALUE = 0x01U  /**< @brief Angle and speed outputs are extrapolated based on trigger signal */
} MotorControl_Ipw_OutputAlignmentType;

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
#if (MOTOR_CONTROL_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief Motor control driver initialization options
 */
typedef enum
{
    MOTOR_CONTROL_STATE_UNINITIALIZED = 0x00U, /**< @brief Motor control driver is not initialized */
    MOTOR_CONTROL_STATE_INITIALIZED   = 0x01U  /**< @brief Motor control driver is initialized and running */
} MotorControl_InitStateType;
#endif /* MOTOR_CONTROL_DEV_ERROR_DETECT */

/**
 * @brief Motor control duty cycle reload options
 */
typedef enum
{
    /** @brief Duty cycle will be updated on frame and center position. */
    MOTOR_CONTROL_FRAME_AND_CENTER_RELOAD = 0x00U,

    /** @brief Duty cycle will be updated on frame position only. */
    MOTOR_CONTROL_FRAME_RELOAD            = 0x01U
} MotorControl_ReloadPositionType;

/**
 * @brief Motor control parameter interpretation options
 */
typedef enum
{
    /** @brief  Parameters will be interpreted in absolute values. */
    MOTOR_CONTROL_ABSOLUTE_INTERPRET = 0x00U,

    /** @brief  Parameters will be interpreted in relative values. */
    MOTOR_CONTROL_RELATIVE_INTERPRET = 0x01U
} MotorControl_ParamInterpretationType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief Motor Control instance ID type
 */
typedef unsigned char MotorControl_InstanceIdType;
/**
 * @brief Motor analog inputs structure.
 */
typedef struct
{
    /** @brief  Phase current A in range: relative <-1, 1>, absolute <-userSpecifiedMaximum, userSpecifiedMaximum> [Amps]. */
    float f32PhaseCurrentA;

    /** @brief  Phase current B in range: relative <-1, 1>, absolute <-userSpecifiedMaximum, userSpecifiedMaximum> [Amps]. */
    float f32PhaseCurrentB;

    /** @brief  Phase current C in range: relative <-1, 1>, absolute <-userSpecifiedMaximum, userSpecifiedMaximum> [Amps]. */
    float f32PhaseCurrentC;

    /** @brief  DC bus voltage in range: relative <0, 1>, absolute <0, userSpecifiedMaximum> [Volts]. */
    float f32DCBusVoltage;
} MotorControl_AnalogInputsType;

/**
 * @brief Angle and speed parameters structure
 */
typedef struct
{
    /** @brief Electric or mechanical representation of the angle and speed values. */
    MotorControl_Ipw_ValueRepresentationType eValueRepresentation;

    /** @brief Possible types of output value alignment. */
    MotorControl_Ipw_OutputAlignmentType eOutputAlignment;

    /** @brief The angular motor position in range: relative <-1, 1>, absolute <-pi, pi> [radians]. */
    float f32Angle;

    /** @brief The motor speed in range: relative <-1, 1>, absolute <-userSpecifiedMaximum, userSpecifiedMaxim> [RPM]. */
    float f32Speed;
} MotorControl_AngleSpeedParamsType;

/**
 * @brief  Motor phase duty cycles parameter structure in range: relative <0, 1>, absolute <0, 100> [%].
 */
typedef struct
{
    /** @brief  Duty cycle of phase A. */
    float f32DutyCycleA;

    /** @brief  Duty cycle of phase B. */
    float f32DutyCycleB;

    /** @brief  Duty cycle of phase C. */
    float f32DutyCycleC;
} MotorControl_PhaseDutyCyclesType;


void HAL_SetPwmOutput(MotorControl_InstanceIdType xInstanceId, boolean bOutputControl);


#endif /* MOTORCONTROL_TYPES_H_ */
