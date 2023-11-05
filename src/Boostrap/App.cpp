#include "App.h"
#include "iostream"
#include "../Domain/Grid/Grid.h"
#include "../Domain/House/House.h"
#include "../Domain/PV/PV.h"
#include "../Domain/Storage/Controller/Controller.h"
#include "../Domain/Storage/Controller/BMS/BMS.h"
#include "../Domain/Storage/Controller/Inverter/Inverter.h"

#include <vector>

static const int Basic = 2;
static const int Standard = 3;
static const int Pro = 5;

void App::run()
{
    Grid *grid = nullptr;
    PV *pv = nullptr;
    House *house = nullptr;
    Inverter *inverter = nullptr;
    std::vector<BMS *> bms;
    Controller *controller = nullptr;
    int type;
    bool correctSetup = false;

    while (!correctSetup)
    {
        std::cout << "Choose the setup:\n 1. Basic (2 batteries)\n 2. Standard (3 batteries)\n 3. Pro (5 batteries)\n->System type: ";
        std::cin >> type;
        switch (type)
        {
        case 1:
            correctSetup = true;
            grid = new Grid();
            pv = new PV();
            house = new House();
            inverter = new Inverter();
            for (int i = 0; i < Basic; i++)
            {
                bms.push_back(new BMS());
            }
            controller = new Controller(inverter, bms);
            break;
        case 2:
            correctSetup = true;
            grid = new Grid();
            pv = new PV();
            house = new House();
            inverter = new Inverter();
            for (int i = 0; i < Standard; i++)
            {
                bms.push_back(new BMS());
            }
            controller = new Controller(inverter, bms);
            break;
        case 3:
            correctSetup = true;
            grid = new Grid();
            pv = new PV();
            house = new House();
            inverter = new Inverter();
            for (int i = 0; i < Pro; i++)
            {
                bms.push_back(new BMS());
            }
            controller = new Controller(inverter, bms);
            break;
        default:
            std::cout << "Invalid Setup. Please select one of the available configurations." << std::endl;
            break;
        }
    }

    bool exit = false;
    while (!exit)
    {
        int command;
        std::cout << "----------------------------\nChoose an option: \n 1. PV > House\n 2. PV < House\n 0. Exit" << std::endl;
        std::cout << "->which command: ";
        std::cin >> command;
        std::cout << std::endl;

        switch (command)
        {
        case 1:
            pv->setPowerInWatts(700);
            house->setPowerInWatts(400);
            std::cout << "Power produced by the Photovoltaic Panel: " << pv->getPowerInWatts() << " W" << std::endl;
            std::cout << "Power required by the house: " << house->getPowerInWatts() << " W" << std::endl;
            std::cout << std::endl;
            this->calculatePowerUseCase.calculate(grid, pv, house, controller);
            controller->displayBatteriesPower();
            std::cout << "Total BMS capacity: " << controller->getActualBMSCapacity() << " W" << std::endl;
            std::cout << "Total power storage BMS: " << controller->getPowerInWatts() << " W" << std::endl;
            std::cout << "Sold (+) or bought (-): " << grid->getPowerInWatts() << " W" << std::endl;
            break;
        case 2:
            pv->setPowerInWatts(200);
            house->setPowerInWatts(550);
            std::cout << "Power produced by the Photovoltaic Panel: " << pv->getPowerInWatts() << " W" << std::endl;
            std::cout << "Power required by the house: " << house->getPowerInWatts() << " W" << std::endl;
            std::cout << std::endl;
            this->calculatePowerUseCase.calculate(grid, pv, house, controller);
            controller->displayBatteriesPower();
            std::cout << "Total BMS capacity: " << controller->getActualBMSCapacity() << " W" << std::endl;
            std::cout << "Total power storage BMS: " << controller->getPowerInWatts() << " W" << std::endl;
            std::cout << "Sold (+) or bought (-): " << grid->getPowerInWatts() << " W" << std::endl;
            break;
        default:
            std::cout << "Invalid Option. " << std::endl;
            break;
        case 0:
            delete controller;
            delete grid;
            delete house;
            delete pv;
            exit = true;
            break;
        }
    }
}