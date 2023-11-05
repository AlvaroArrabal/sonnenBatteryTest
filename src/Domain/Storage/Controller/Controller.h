#include "BMS/BMS.h"
#include "Inverter/Inverter.h"
#include "../../Grid/Grid.h"
#include <vector>

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
private:
    Inverter *_inverter;
    std::vector<BMS *> _bms;

    void discharge(double power);
    void charge(double power);

public:
    // Constructor
    Controller(Inverter *inverter, std::vector<BMS *> bms) : _inverter(inverter), _bms(bms)
    {
        _inverter->setValues(_bms);
    };

    // Gets the actual power in Watts
    double getPowerInWatts() const;

    // Gets the actual power capacity in Watts
    double getActualBMSCapacity() const;

    // Get the maximum amount of power that can be stored by the BMS array
    double getMaxPowerInWatts() const;

    // Shows the current load of each BMS in watts on the display
    void displayBatteriesPower();

    // Indicates the amount of power the house needs and calls the inverter to determine where to get that power from
    void calculatePower(Grid *grid, double powerHouse, double powerPV);

    // Destructor
    ~Controller() {}
};

#endif // CONTROLLER_H
