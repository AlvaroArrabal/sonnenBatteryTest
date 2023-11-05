#include "iostream"
#include "Controller.h"

void Controller::calculatePower(Grid *grid, double powerHouse, double powerPV)
{
    _inverter->setValues(_bms);
    if (powerPV > powerHouse)
    {
        double surplus = powerPV - powerHouse;

        if (surplus > _inverter->getActualCapacity())
        {
            if (_inverter->getActualCapacity() == 0)
            {
                grid->setPowerInWatts(surplus);
            }
            else
            {
                grid->setPowerInWatts(surplus - _inverter->getActualCapacity());
                charge(_inverter->getActualCapacity());
            }
        }
        else
        {
            charge(surplus);
        }
    }
    else if (powerPV < powerHouse)
    {
        float powerMissing = powerHouse - powerPV;

        if (_inverter->getPowerInWatts() >= powerMissing)
        {
            discharge(-powerMissing);
        }
        else
        {
            double powerFromGrid = powerMissing - _inverter->getPowerInWatts();
            grid->setPowerInWatts(-powerFromGrid);
            discharge(-_inverter->getPowerInWatts());
        }
    }
    _inverter->setValues(_bms);
}

void Controller::charge(double power)
{
    for (long unsigned int i = 0; i < _bms.size(); i++)
    {
        if (_bms[i]->getPowerInWatts() < _bms[i]->getMaxPowerInWatts())
        {
            if (power > 0 && power > _bms[i]->getMaxPowerInWatts() - _bms[i]->getPowerInWatts())
            {
                power -= (_bms[i]->getMaxPowerInWatts() - _bms[i]->getPowerInWatts());
                _bms[i]->setPowerInWatts(_bms[i]->getMaxPowerInWatts() - _bms[i]->getPowerInWatts());
            }
            else if (power > 0)
            {
                _bms[i]->setPowerInWatts(power);
                power -= power;
            }
        }
    }
}

void Controller::discharge(double power)
{
    for (long unsigned int i = 0; i < _bms.size(); i++)
    {
        if (_bms[i]->getPowerInWatts() > 0)
        {

            if (power < 0 && abs(power) > _bms[i]->getPowerInWatts())
            {
                power += _bms[i]->getPowerInWatts();
                _bms[i]->setPowerInWatts(-_bms[i]->getPowerInWatts());
            }
            else if (power < 0)
            {
                _bms[i]->setPowerInWatts(power);
                power -= power;
            }
        }
    }
}

double Controller::getPowerInWatts() const
{
    return _inverter->getPowerInWatts();
}

double Controller::getActualBMSCapacity() const
{
    return _inverter->getActualCapacity();
}

double Controller::getMaxPowerInWatts() const
{
    return _inverter->getMaxPowerInWatts();
}

void Controller::displayBatteriesPower()
{
    std::cout << "Actual Power in each BMS:" << std::endl;
    for (long unsigned int i = 0; i < _bms.size(); i++)
    {
        std::cout << "- BMS (" << i + 1 << "): " << _bms[i]->getPowerInWatts() << std::endl;
    }
}