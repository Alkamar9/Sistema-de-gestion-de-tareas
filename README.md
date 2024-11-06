# Sistema-de-gestion-de-tareas
Manual de Usuario
Sistema de Gestion de Tareas 

Manual de Usuario: Sistema de Gestión de Tareas

Introducción

Este programa en C++ es un sistema de gestión de tareas que permite a los usuarios agregar, mostrar y eliminar tareas con prioridades. Cada tarea tiene un nombre, una prioridad, y una fecha de vencimiento.

Requisitos Previos

- El programa debe compilarse en un entorno compatible con C++, como g++.

Funcionalidades

Menú Principal

Al ejecutar el programa, se despliega un menú con opciones que permiten interactuar con el sistema de gestión de tareas. Las opciones disponibles son:

1. Agregar Tarea
2. Mostrar Tareas por Prioridad
3. Eliminar Tarea
4. Mostrar Todas las Tareas
5. Salir

Para seleccionar una opción, ingrese el número correspondiente en el menú y presione Enter.

Opciones del Menú

1. Agregar Tarea
   - Seleccione la opción 1 en el menú.
   - Introduzca el nombre de la tarea.
   - Introduzca el nivel de prioridad de la tarea:
     - 1 = Alta prioridad
     - 3 = Baja prioridad
   - La fecha de vencimiento se establece automáticamente en función de la prioridad (ejemplo: 1 día después para alta prioridad).
   - La tarea se agregará a la lista y se mostrará un mensaje de confirmación.

2. Mostrar Tareas por Prioridad
   - Seleccione la opción 2 en el menú.
   - El sistema mostrará las tareas ordenadas de mayor a menor prioridad.
   - Cada tarea incluirá el nombre, la prioridad, y la fecha de vencimiento.

3. Eliminar Tarea
   - Seleccione la opción 3 en el menú.
   - Ingrese el nombre de la tarea que desea eliminar.
   - Si la tarea se encuentra en la lista, se eliminará y mostrará un mensaje de confirmación.
   - Si no se encuentra, el sistema le notificará que la tarea no existe.

4. Mostrar Todas las Tareas
   - Seleccione la opción 4 en el menú.
   - El sistema mostrará todas las tareas, incluyendo nombre, prioridad y fecha de vencimiento.

5. Salir
   - Seleccione la opción 0 en el menú para salir del programa.

Ejemplo de Ejecución

1. Ejecute el programa compilado desde la terminal.
2. Ingrese una opción del menú, por ejemplo, 1 para agregar una tarea.
3. Siga las instrucciones para ingresar los detalles de la tarea.
4. Use la opción 2 para ver las tareas ordenadas por prioridad, o la opción 4 para ver todas las tareas.
5. Seleccione la opción 3 para eliminar una tarea si es necesario.
6. Use la opción 0 para salir.


Consideraciones

- El sistema utiliza fechas relativas basadas en la prioridad para facilitar la simulación.
- Es importante introducir el nombre de la tarea con exactitud en la opción de eliminación, ya que el nombre se utiliza para identificar las tareas.
