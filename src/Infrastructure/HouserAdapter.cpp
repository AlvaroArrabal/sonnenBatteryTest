#include "../Domain/House/House.h"

double House::getPowerInWatts() const
{
    return powerHouseInWatts;
}

double House::getVoltageInVolts() const
{
    return houseVoltageInVolts;
}

double House::getCurrentInAmps() const
{
    return houseCurrentInAmps;
}

double House::getFrequencyInHz() const
{
    return houseFrequencyInHz;
}

void House::setPowerInWatts(double powerInWatts)
{
    powerHouseInWatts = powerInWatts;
}