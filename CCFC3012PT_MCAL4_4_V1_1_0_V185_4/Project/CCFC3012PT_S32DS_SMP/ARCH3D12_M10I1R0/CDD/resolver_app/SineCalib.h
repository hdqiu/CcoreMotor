/*
 * SineCalib.h
 *
 *  Created on: 9 May 2014
 *      Author: NugrahaD
 */

#ifndef SINECALIB_H_
#define SINECALIB_H_

#define SINECALIB_RESOLUTION (2048)

#include "Platform_Types.h"

typedef enum
{
    SineCalib_State_ready,
    SineCalib_State_init,
    SineCalib_State_marking
} SineCalib_State;

typedef struct
{
    float32 ampl;
    float32 offs;
    float32 hyst;
    sint32  maxv;
    sint32  minv;
    boolean trig;
    SineCalib_State state;
} SineCalib;


inline void SineCalib_init(SineCalib *sc)
{
    sc->ampl = 1.0;
    sc->offs = 0.0;
    sc->hyst = 20;
    sc->maxv = 0.0;
    sc->minv = -65535;
    sc->state = SineCalib_State_init;
    sc->trig = FALSE;
}


inline sint32 SineCalib_update(SineCalib *sc, sint32 input)
{
    if (sc->state == SineCalib_State_ready)
    {
        sc->maxv = __max(sc->maxv, input);
        sc->minv = __min(sc->minv, input);

        if (sc->trig && (input > sc->hyst))
        {
            sc->trig = FALSE;
            sc->ampl = SINECALIB_RESOLUTION * 2 / (float32)(sc->maxv - sc->minv);
            sc->offs = (float32)(sc->maxv + sc->minv) / 2;
            sc->minv = +65535;
            sc->maxv = -65535;
        }
        else if (input < -sc->hyst)
        {
            sc->trig = TRUE;
        }

        input = (sint32)(((float32)input * sc->ampl) - sc->offs);
    }
    else if (sc->state == SineCalib_State_marking)
    {
        sc->maxv = __maxX(sc->maxv, input);
        sc->minv = __minX(sc->minv, input);

        if (sc->trig && (input > sc->hyst))
        {
            sc->trig = FALSE;
            sc->state = SineCalib_State_ready;
        }
        else if (input < -sc->hyst)
        {
            sc->trig = TRUE;
        }
    }
    else if (sc->state == SineCalib_State_init)
    {
        if (input < -sc->hyst)
        {
            sc->trig = TRUE;
        }

        if (sc->trig && (input > sc->hyst))
        {
            sc->trig = FALSE;
            sc->minv = +65535;
            sc->maxv = -65535;
            sc->state = SineCalib_State_marking;
        }
    }

    return input;
}



#endif /* SINECALIB_H_ */
