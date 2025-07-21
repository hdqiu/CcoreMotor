//------------------------------------------------------------------------------
#include <LowPassPt1.h>
//------------------------------------------------------------------------------

/** \brief Set the low pass filter configuration
 *
 * This function sets the low pass filter  configuration and reset the filter output.
 *
 * \param filter Specifies PT1 filter.
 * \param config Specifies the PT1 filter configuration.
 *
 * \return None
 */
void LowPassPt1_init (LowPassPt1 * filter, const LowPassPt1_Config * config)
{
    float32 tStar;
    float32 T = 1 / config->cutOffFrequency;
    tStar = 1 / (T / config->samplingTime + 1);

    filter->a = config->gain * tStar;
    filter->b = tStar;
    filter->out = 0;
}

/** \brief Execute the low pass filter
 * \param filter Specifies PT1 filter.
 * \param input Specifies the filter input.
 *
 * \return Returns the filter output
 */
float32 LowPassPt1_do (LowPassPt1 * filter, float32 input)
{
    filter->out = filter->out + filter->a * input - filter->b * filter->out;
    return filter->out;
}
