#include "../Domain/Storage/Controller/BMS/BMS.h"

double BMS::getPowerInWatts() const
{
    return powerBmsInWatts;
}

double BMS::getMaxPowerInWatts() const
{
    return maxPowerInWatts;
}

double BMS::getVoltageInVolts() const
{
    return voltageInVolts;
}

double BMS::getTemperatureInCelsius() const
{
    return temperatureInCelsius;
}

void BMS::setPowerInWatts(double powerInWatts)
{
    powerBmsInWatts += powerInWatts;
}