## Uso Aplicacion
> **make help**: muestra por pantalla todas las opciones disponibles (opcion por defecto si se pone unicamente make)

Esta aplicacion tiene dos modos de uso y cada uno de ellos se ejcuta con los siguientes comandos:
> **make runTest**: con este modo se ejcutan los test que se especifican en el apartado de *Tests*. 
> **make run**: con este modo se ejecuta la aplicacion con un caso de uso. 

Con ambos comandos, se compilan y ejecutan las partes.

## Introduction
El proyecto está estructurado en cuatro componentes principales para separar las responsabilidades y facilitar la escalabilidad y el mantenimiento. Es un diseño relativamente genérico y esta distribución puede ser distinta a la estándar:
- **Dominio**
> Contiene las definiciones de las interfaces esenciales (Grid, House, PV, Storage). Estas abstracciones son clave para entender las operaciones que el sistema puede realizar, independientemente de su implementación, se va a mantener constante.
- **Infraestructura**
> InfraestructuraImplementa las interfaces definidas en el Dominio. Aquí, cambios en la lógica no requieren alteraciones en las definiciones de dominio.
- **Aplicacion**
> Aloja los casos de uso del sistema, en este caso, el cálculo de la potencia del sistema. 
- **Bootstrap**
> Es el punto de entrada del sistema donde se configura y se inicia la aplicación. Aquí se instancian y se conectan todos los componentes necesarios para el caso de uso específico.

## Suposiciones
En la arquitectura de nuestro sistema, hemos adoptado la suposición de que cada entidad de Storage es manejada por un único Controller. Esta decisión simplifica la estructura del código al evitar la creación de clases intermedias innecesarias, dado que la lógica de gestión energética reside directamente en el Controller. Aunque este enfoque favorece la simplicidad y la claridad actual, se mantiene flexible para futuras expansiones donde múltiples Controllers puedan requerir una clase Storage separada para gestionarlos colectivamente. 
Tomando dicha suposicion, cada Controller está formado por un Inverter y un vector con el número de baterías disponibles dependiendo del setup escogido (Basic, Standard, Pro).
Al hacer esta suposición, el controller es el que manejar el flujo de potencia de la batería, por ello, se han definido las funciones de charge y discharge en controller. Con el inverter se decide si es necesario cargar o descargar las baterías. La implementación de la lógica para determinar esto se ha hecho en la función de calculatePower de Controller, esta parte de la lógica que hace uso del inverter, se podría haber implementado en el propio inverter, ya que es quien decide que se hace.
De igual manera, se ha supuesto que las baterías se van llenando de una en una y no se empieza a llenar/vaciar una batería hasta que la anterior esté llena/vacía.

Otra suposición que se ha hecho es que la grid es infinita, y me va a poder suministrar siempre la potencia necesaria. Si esto no fuera así, el sistema que he desarrollado no estaría preparado para ello, si no hay potencia almacenada en las baterías. Entiendo que, en ese caso, se debería implementar una función/lógica para apagar el sistema, o elegir a que se le da potencia, etc…

## Tests
Los tests que se han realizado son sobre la logica del programa. Es decir, sobre el controller. Los diferentes casos que se han testeado son los siguientes:

IMAGEN? - tengo que pushear para poder meter el url de la imagen pero primero pregunto.

Destacar que harian falta mas tests, pero en este caso, como la logica del sistema esta en calcular la potencia y manejarla, se han testeado los posibles casos que pueden suceder. En estos tests, se han metido los tests de constructores, seters y geters. Sin embargo, seguramente lo apropiado seria realizar mas tests unitarios y no meter estos tests en el test de calcular la potencia.

