#ifndef APP_H
#define APP_H

#include "../Application/CalculatePowerUseCase.h"

class App
{
private:
    CalculatePowerUseCase calculatePowerUseCase;

public:
    void run();
};

#endif // APP_H
