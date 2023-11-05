## Application Usage
> **make help**: displays all available options on screen (default option if only make is set)

* This application has two modes of use and each of them is executed with the following commands:
  >     $ make runTests


  **make runTest**: This command, it runs the tests that are specified in the *Tests* section.

  >     $ make run

  **make run**: This command runs the application with a use case. 


* If you want to use Docker, follow the sequence of steps below:
  >     $ make up

  **make up**: brings up the container.
  >     $ make enter

  **make enter**: enters the container with the compiler.
  >     $ make run

  **make run**: inside the container, it will run the application.
  >     $ make runTests

  **make runTests**: nside the container, it will execute the tests.


With the "**run**" and "**runTest**" commands, the parts are compiled and executed. 

## Introduction
The project is structured into four main components to separate responsibilities and to facilitate scalability and maintenance. It is a relatively generic design, and this layout may differ from the standard one:
- **Domain**
> It contains the definitions of the essential interfaces (Grid, House, PV, Storage). These abstractions are key to understanding the operations that the system can perform and will remain constant regardless of their implementation.
- **Infrastructure**
> It implements the interfaces defined in the Domain. Here, changes in logic do not require alterations in the domain definitions.
- **Application**
> It encases the system's use cases, in this case, the calculation of the system's power. 
- **Bootstrap**
> It is the system's entry point where the application is configured and initiated. Here, all the necessary components are instantiated and connected for the specific use case.

## Assumptions
In our system architecture, we have adopted the assumption that each Storage entity is managed by a single Controller. This decision simplifies the code structure by avoiding the creation of unnecessary intermediate classes, since the energy management logic resides directly in the Controller. While this approach favors current simplicity and clarity, it remains flexible for future expansions where multiple Controllers may require a separate Storage class to manage them collectively.

Each Controller consists of an Inverter and a vector with the number of batteries available according to the selected setup (Basic, Standard, Pro).

With this assumption, the controller is responsible for managing the power flow from the battery, which is why the charge and discharge functions have been defined in the controller. It is the inverter that decides whether it is necessary to charge or discharge the batteries. The implementation of the logic to determine this has been done in the Controller's calculatePower function. This process, which utilizes the inverter, could have been implemented in the inverter itself, since it is the one that makes the decision.

Similarly, it has been assumed that the batteries are filled one by one, and a battery does not begin to be filled or emptied until the previous one is full or empty.

Another assumption made is that the grid has infinite capacity, and will always be able to supply the necessary power. If this were not the case, the developed system would not be prepared to handle such a scenario if there is no power stored in the batteries. It is understood that in such a scenario, a function or logic should be implemented to either shut down the system or to choose what to prioritize for power distribution, etc.

* It is understood that setters for the elements with which the controller interacts do not make sense in the context of the system's operations; they have been implemented for the purpose of using the program.

## Tests

A unit test has been carried out on Controller.calculatePower() where all use cases concerning that function are considered. The different cases that have been tested are the following:

  ![Tests](https://github.com/AlvaroArrabal/sonnenBatteryTest/blob/main/assets/tests.png)

Additionally, the opportunity is taken to indirectly test the setters and getters of the other entities; these asserts should be performed in separate unit tests. It should be noted that more tests would be necessary, but in this case, as the logic of the system is focused on calculating and managing power, the possible scenarios that could occur have been tested.

