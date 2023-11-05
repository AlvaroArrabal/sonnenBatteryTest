#include "../Domain/Storage/Controller/Controller.h"
#include "../Domain/Grid/Grid.h"
#include "../Domain/House/House.h"
#include "../Domain/PV/PV.h"

#ifndef CALCULATEPOWER_H
#define CALCULATEPOWER_H

class CalculatePowerUseCase
{
public:
    void calculate(
        Grid *grid,
        PV *pv,
        House *house,
        Controller *controller);
};

#endif // CALCULATEPOWER_H
