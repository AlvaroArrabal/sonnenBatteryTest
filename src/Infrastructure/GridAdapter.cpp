#include "../Domain/Grid/Grid.h"

double Grid::getPowerInWatts() const
{
    return powerFromGridInWatts;
}

double Grid::getVoltageInVolts() const
{
    return gridVoltageInVolts;
}

double Grid::getFrequencyInH() const
{
    return gridFrequencyInHz;
}

void Grid::setPowerInWatts(double powerInWatts)
{
    powerFromGridInWatts += powerInWatts;
}