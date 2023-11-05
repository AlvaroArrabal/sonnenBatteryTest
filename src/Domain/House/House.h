#ifndef HOUSE_H
#define HOUSE_H

class House
{
    double powerHouseInWatts;   // House power in Watts
    double houseVoltageInVolts; // House voltage in Volts
    double houseCurrentInAmps;  // House current in Amps
    double houseFrequencyInHz;  // House frequency in Herzts

public:
    // Default constructor. Initializes the variables to 0.0
    House() : powerHouseInWatts(0.0), houseVoltageInVolts(0.0), houseCurrentInAmps(0.0), houseFrequencyInHz(0.0){};

    // Specific constructor, initialises the variables to a given value
    House(double powerInWatts, double voltageInVolts, double currentInAmps, double frequencyInHz) : powerHouseInWatts(powerInWatts), houseVoltageInVolts(voltageInVolts), houseCurrentInAmps(currentInAmps), houseFrequencyInHz(frequencyInHz){};
    // Set the power in Watts
    void setPowerInWatts(double powerInWatts);

    // Gets the actual voltage in Volts
    double getVoltageInVolts() const;

    // Gets the actual current in Amps
    double getCurrentInAmps() const;

    // Gets the actual frequency in Hertzs
    double getFrequencyInHz() const;

    // Gets the actual power in Watts
    double getPowerInWatts() const;

    // Destructor
    virtual ~House() {}
};

#endif // HOUSE_H
