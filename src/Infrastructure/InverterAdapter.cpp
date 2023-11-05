#include "../Domain/Storage/Controller/Inverter/Inverter.h"

double Inverter::getPowerInWatts() const
{
    return powerAvailableInWatts;
}

double Inverter::getMaxPowerInWatts() const
{
    return maxPowerInWatts;
}

double Inverter::getActualCapacity() const
{
    return actualCapacity;
}

void Inverter::setPowerInWatts(std::vector<BMS *> bms)
{
    powerAvailableInWatts = 0; // reset

    for (BMS *bmsPtr : bms)
    {
        if (bmsPtr != nullptr)
        {
            powerAvailableInWatts += bmsPtr->getPowerInWatts();
        }
    }
}

void Inverter::setMaxPowerInWatts(std::vector<BMS *> bms)
{
    maxPowerInWatts = bms.size() * bms[0]->getMaxPowerInWatts();
}

void Inverter::setActualCapacity()
{
    actualCapacity = maxPowerInWatts - powerAvailableInWatts;
}

void Inverter::setValues(std::vector<BMS *> bms)
{
    setMaxPowerInWatts(bms);
    setPowerInWatts(bms);
    setActualCapacity();
}