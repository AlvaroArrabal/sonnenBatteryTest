#include "CalculatePowerUseCase.h"

void CalculatePowerUseCase::calculate(
    Grid *grid,
    PV *pv,
    House *house,
    Controller *controller)
{
    controller->calculatePower(
        grid,
        house->getPowerInWatts(),
        pv->getPowerInWatts());
}