#ifndef PV_H
#define PV_H

class PV
{
private:
    double powerPvInWatts;   // Photovoltaic panel power in Watts
    double pvVoltageInVolts; // Photovoltaic panel voltage in Volts
    double pvCurrentInAmps;  // Photovoltaic panel current in Amps

public:
    // Default constructor. Initializes the variables to 0.0
    PV() : powerPvInWatts(0.0), pvVoltageInVolts(0.0), pvCurrentInAmps(0.0){};

    // Specific constructor, initialises the variables to a given value
    PV(double powerInWatts, double voltageInVolts, double currentInAmps) : powerPvInWatts(powerInWatts), pvVoltageInVolts(voltageInVolts), pvCurrentInAmps(currentInAmps){};

    // Gets the actual power in Watts
    double getPowerInWatts() const;

    // Gets the actual voltage in Volts
    double getVoltageInVolts() const;

    // Gets the actual current in Amps
    double getCurrentInAmps() const;

    // Set the power in Watts
    void setPowerInWatts(double powerInWatts);

    // Destructor
    virtual ~PV() {}
};

#endif // PV_H
