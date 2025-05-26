
#include "Std_Pos.h"

void Std_Pos_initConfig (Std_Pos_Config * config)
{
    config->offset = 0;
    config->reversed = FALSE;
    config->resolution = 0;
    config->periodPerRotation = 1;
    config->resolutionFactor = Std_Pos_ResolutionFactor_oneFold;
    config->updatePeriod = 0.001;
    config->speedModeThreshold = 0;
    config->minSpeed = 0;       // 0 rpm
    config->maxSpeed = 30000.0 / 60.0 * (2 * CC_PI);   // 20000 rpm
    config->speedFilterEnabled = FALSE;
    config->speedFilerCutOffFrequency = 0;
}
