#include "../../src/Domain/Grid/Grid.h"
#include "../../src/Domain/House/House.h"
#include "../../src/Domain/PV/PV.h"
#include "../../src/Domain/Storage/Controller/Controller.h"

#include <iostream>
#include <vector>
#include <cassert>

static const int Basic = 2;
static const int Standard = 3;
static const int Pro = 5;

void test_pvPowerGreaterThanHousePower_withoutBMSPower()
{
    Grid *grid = new Grid();
    PV *pv = new PV();
    House *house = new House();
    std::vector<BMS *> bms;
    for (int i = 0; i < Basic; i++)
    {
        bms.push_back(new BMS());
    }
    Inverter *inverter = new Inverter();
    Controller *controller = new Controller(inverter, bms);

    assert(pv->getPowerInWatts() == 0);
    assert(house->getPowerInWatts() == 0);

    pv->setPowerInWatts(700);
    house->setPowerInWatts(450);

    assert(pv->getPowerInWatts() == 700);
    assert(house->getPowerInWatts() == 450);
    assert(controller->getPowerInWatts() == 0);
    assert(controller->getMaxPowerInWatts() == 2000);

    controller->calculatePower(grid, house->getPowerInWatts(), pv->getPowerInWatts());

    assert(controller->getPowerInWatts() == 250);
    assert(controller->getActualBMSCapacity() == 1750);
    assert(grid->getPowerInWatts() == 0);

    std::cout << "Test -> PV power > House power without BMS Power - OK" << std::endl;
}

void test_pvPowerGreaterThanHousePower_withBMSPower()
{
    Grid *grid = new Grid();
    PV *pv = new PV();
    House *house = new House();
    std::vector<BMS *> bms;
    for (int i = 0; i < Basic; i++)
    {
        bms.push_back(new BMS(500, 1000, 0, 25));
    }
    Inverter *inverter = new Inverter();
    Controller *controller = new Controller(inverter, bms);

    assert(pv->getPowerInWatts() == 0);
    assert(house->getPowerInWatts() == 0);

    pv->setPowerInWatts(700);
    house->setPowerInWatts(450);

    assert(pv->getPowerInWatts() == 700);
    assert(house->getPowerInWatts() == 450);
    assert(controller->getPowerInWatts() == 1000);
    assert(controller->getMaxPowerInWatts() == 2000);

    controller->calculatePower(grid, house->getPowerInWatts(), pv->getPowerInWatts());

    assert(controller->getPowerInWatts() == 1250);
    assert(controller->getActualBMSCapacity() == 750);
    assert(grid->getPowerInWatts() == 0);

    std::cout << "Test -> PV power > House power with BMS Power    - OK" << std::endl;
}

void test_pvPowerLessThanHousePower_withoutBMSPower()
{
    Grid *grid = new Grid();
    PV *pv = new PV();
    House *house = new House();
    Inverter *inverter = new Inverter();
    std::vector<BMS *> bms;
    for (int i = 0; i < Basic; i++)
    {
        bms.push_back(new BMS());
    }
    Controller *controller = new Controller(inverter, bms);

    assert(pv->getPowerInWatts() == 0);
    assert(house->getPowerInWatts() == 0);

    pv->setPowerInWatts(400);
    house->setPowerInWatts(750);

    assert(pv->getPowerInWatts() == 400);
    assert(house->getPowerInWatts() == 750);
    assert(controller->getPowerInWatts() == 0);
    assert(controller->getMaxPowerInWatts() == 2000);

    controller->calculatePower(grid, house->getPowerInWatts(), pv->getPowerInWatts());

    assert(controller->getPowerInWatts() == 0);
    assert(controller->getActualBMSCapacity() == 2000);
    assert(grid->getPowerInWatts() == -350);

    std::cout << "Test -> PV power < House power without BMS Power - OK" << std::endl;
}

void test_pvPowerLessThanHousePower_withBMSPower()
{
    Grid *grid = new Grid();
    PV *pv = new PV();
    House *house = new House();
    Inverter *inverter = new Inverter();
    std::vector<BMS *> bms;
    for (int i = 0; i < Basic; i++)
    {
        bms.push_back(new BMS(500, 1000, 0, 25));
    }
    Controller *controller = new Controller(inverter, bms);

    assert(pv->getPowerInWatts() == 0);
    assert(house->getPowerInWatts() == 0);

    pv->setPowerInWatts(400);
    house->setPowerInWatts(750);

    assert(pv->getPowerInWatts() == 400);
    assert(house->getPowerInWatts() == 750);
    assert(controller->getPowerInWatts() == 1000);
    assert(controller->getMaxPowerInWatts() == 2000);

    controller->calculatePower(grid, house->getPowerInWatts(), pv->getPowerInWatts());

    assert(controller->getPowerInWatts() == 650);
    assert(controller->getActualBMSCapacity() == 1350);
    assert(grid->getPowerInWatts() == 0);

    std::cout << "Test -> PV power < House power with BMS Power    - OK" << std::endl;
}

void test_pvPowerEqualToHousePower_withoutBMSPower()
{
    Grid *grid = new Grid();
    PV *pv = new PV();
    House *house = new House();
    Inverter *inverter = new Inverter();
    std::vector<BMS *> bms;
    for (int i = 0; i < Basic; i++)
    {
        bms.push_back(new BMS());
    }
    Controller *controller = new Controller(inverter, bms);

    assert(pv->getPowerInWatts() == 0);
    assert(house->getPowerInWatts() == 0);

    pv->setPowerInWatts(700);
    house->setPowerInWatts(700);

    assert(pv->getPowerInWatts() == 700);
    assert(house->getPowerInWatts() == 700);
    assert(controller->getPowerInWatts() == 0);
    assert(controller->getMaxPowerInWatts() == 2000);

    controller->calculatePower(grid, house->getPowerInWatts(), pv->getPowerInWatts());

    assert(controller->getPowerInWatts() == 0);
    assert(controller->getActualBMSCapacity() == 2000);
    assert(grid->getPowerInWatts() == 0);

    std::cout << "Test -> PV power = House power without BMS Power - OK" << std::endl;
}

void test_pvPowerEqualToHousePower_withBMSPower()
{
    Grid *grid = new Grid();
    PV *pv = new PV();
    House *house = new House();
    Inverter *inverter = new Inverter();
    std::vector<BMS *> bms;
    for (int i = 0; i < Basic; i++)
    {
        bms.push_back(new BMS(500, 1000, 0, 25));
    }
    Controller *controller = new Controller(inverter, bms);

    pv->setPowerInWatts(700);
    house->setPowerInWatts(700);

    controller->calculatePower(grid, house->getPowerInWatts(), pv->getPowerInWatts());

    assert(controller->getPowerInWatts() == 1000);
    assert(controller->getActualBMSCapacity() == 1000);
    assert(grid->getPowerInWatts() == 0);

    std::cout << "Test -> PV power = House power with BMS Power    - OK" << std::endl;
}

int main()
{
    test_pvPowerGreaterThanHousePower_withoutBMSPower();
    test_pvPowerLessThanHousePower_withoutBMSPower();
    test_pvPowerEqualToHousePower_withoutBMSPower();

    test_pvPowerGreaterThanHousePower_withBMSPower();
    test_pvPowerLessThanHousePower_withBMSPower();
    test_pvPowerEqualToHousePower_withBMSPower();

    return 0;
}