#include "../Domain/PV/PV.h"

double PV::getPowerInWatts() const
{
    return powerPvInWatts;
}

double PV::getVoltageInVolts() const
{
    return pvVoltageInVolts;
}

double PV::getCurrentInAmps() const
{
    return pvCurrentInAmps;
}

void PV::setPowerInWatts(double powerInWatts)
{
    powerPvInWatts = powerInWatts;
}