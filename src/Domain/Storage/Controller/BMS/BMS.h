#ifndef BMS_H
#define BMS_H

static const int DEFAULT_MAX_POWER = 1000.0;

class BMS
{
private:
    double powerBmsInWatts;      // BMS power in Watts
    double maxPowerInWatts;      // BMS max power in Watts
    double voltageInVolts;       // BMS voltage in Volts
    double temperatureInCelsius; // BMS temperature in Celsius

public:
    // Default constructor. Initializes the variables to 0.0 and temperature to 25 Celsius.
    BMS() : powerBmsInWatts(0.0), maxPowerInWatts(DEFAULT_MAX_POWER), voltageInVolts(0.0), temperatureInCelsius(25.0){};

    // Specific constructor, initialises the variables to a given value
    BMS(double initialPowerInWatts, double initialMaxPowerInWatts, double initialVoltageInVolts, double initialTemperatureInCelsius) : powerBmsInWatts(initialPowerInWatts), maxPowerInWatts(initialMaxPowerInWatts), voltageInVolts(initialVoltageInVolts), temperatureInCelsius(initialTemperatureInCelsius){};

    // Gets the actual power in Watts
    double getPowerInWatts() const;

    // Gets the max power in Watts
    double getMaxPowerInWatts() const;

    // Gets the actual voltage in Volts
    double getVoltageInVolts() const;

    // Gets the actual temperature in Celsius
    double getTemperatureInCelsius() const;

    // Set the power in Watts
    void setPowerInWatts(double powerInWatts);

    // Destructor
    virtual ~BMS() {}
};

#endif // BMS_H
