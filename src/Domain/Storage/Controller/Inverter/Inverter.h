#ifndef INVERTER_H
#define INVERTER_H

#include <iostream>
#include <vector>

#include "../BMS/BMS.h"

class Inverter
{
    double powerAvailableInWatts; // amount of power available in BMS modules in Watts
    double maxPowerInWatts;       // BMS modules max power in Watts
    double actualCapacity;        // BMS capacity in Watts

public:
    // Default constructor. Initializes the variables to 0.0
    Inverter() : powerAvailableInWatts(0.0), maxPowerInWatts(0.0), actualCapacity(0.0){};

    // Gets the actual power in Watts
    double getPowerInWatts() const;

    // Gets the actual max power in Watts
    double getMaxPowerInWatts() const;

    // Gets the actual power capacity in Watts
    double getActualCapacity() const;

    // Set the power in Watts
    void setPowerInWatts(std::vector<BMS *> bms);

    // Set the max power in Watts
    void setMaxPowerInWatts(std::vector<BMS *> bms);

    // Set the power capacity in Watts
    void setActualCapacity();

    // Set the values powerAvailableInWatts, maxPowerInWatts, actualCapacity in Watts
    void setValues(std::vector<BMS *> bms);

    // Destructor
    virtual ~Inverter() {}
};

#endif // INVERTER_H
