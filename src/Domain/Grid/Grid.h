#ifndef GRID_H
#define GRID_H

class Grid
{
private:
    double powerFromGridInWatts; // Total power sold/purchased from the grid
    double gridVoltageInVolts;   // Grid voltage in Volts
    double gridFrequencyInHz;    // Grid frequency in Herzts

public:
    // Default constructor. Initializes the variables to 0.0
    Grid() : powerFromGridInWatts(0.0), gridVoltageInVolts(0.0), gridFrequencyInHz(0.0){};

    // Specific constructor, initialises the variables to a given value
    Grid(double powerInWatts, double voltageInVolts, double frequencyInHz) : powerFromGridInWatts(powerInWatts), gridVoltageInVolts(voltageInVolts), gridFrequencyInHz(frequencyInHz){};

    // Set the power in Watss
    void setPowerInWatts(double powerInWatts);

    // Gets the actual power in Watts
    double getPowerInWatts() const;

    // Gets the actual voltage in Volts
    double getVoltageInVolts() const;

    // Gets the actual frequency in Hertzs
    double getFrequencyInH() const;

    // Destructor
    virtual ~Grid() {}
};

#endif // GRID_H
