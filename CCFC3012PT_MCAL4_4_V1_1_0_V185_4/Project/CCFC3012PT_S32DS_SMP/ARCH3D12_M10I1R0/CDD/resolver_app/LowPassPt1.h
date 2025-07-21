/**
 * \file LowPassPt1.h
 * \brief Low pass filter PT1
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup library_srvsw_sysse_math_lowPassPt1 Low-pass Filter: Type PT1
 * This module implements a PT1 low pass filter.
 *
 * Formula: \n
 * \f$ y_k = y_{k-1} + a * x_k - b * y_{k-1} \f$ \n
 * with \f$(T^* = \frac{T_s}{T+T_s})\f$, \f$(a = K*T^*)\f$, \f$(b = T^*)\f$
 * with \f$(T_s: Sample time)\f$, \f$(K: Gain)\f$, \f$(T = \frac{1}{\omega_0})\f$
 *
 * \ingroup library_srvsw_sysse_math
 *
 */

#if !defined(LOW_PASS_PT1)
#define LOW_PASS_PT1
//------------------------------------------------------------------------------
#include "Platform_Types.h"
//------------------------------------------------------------------------------

/** \brief PT1 object definition.
 */
typedef struct
{
    float32 a;              /**< \brief a parameter */
    float32 b;              /**< \brief b parameter */
    float32 out;            /**< \brief last output */
} LowPassPt1;


/** \brief PT1 configuration */
typedef struct
{
    float32 cutOffFrequency;/**< \brief Cut off frequency */
    float32 gain;           /**< \brief Gain */
    float32 samplingTime;   /**< \brief Sampling time */
} LowPassPt1_Config;

//------------------------------------------------------------------------------

/** \addtogroup  library_srvsw_sysse_math_lowPassPt1
 * \{ */
extern void LowPassPt1_init (LowPassPt1 * filter, const LowPassPt1_Config * config);
static inline void LowPassPt1_reset (LowPassPt1 * filter);
extern float32 LowPassPt1_do (LowPassPt1 * filter, float32 input);
/** \} */

//------------------------------------------------------------------------------

/** \brief Reset the internal filter variable
 * \param filter Specifies PT1 filter.
 */
static inline void LowPassPt1_reset (LowPassPt1 * filter)
{
    filter->out = 0.0;
}

//------------------------------------------------------------------------------
#endif
