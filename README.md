# Gestor de Eventos

Este es un proyecto de gestión de eventos desarrollado en C++. Permite a los usuarios crear, administrar y registrar eventos, así como también gestionar la asistencia de los participantes.

## Funcionalidades

- Crear eventos de diferentes tipos, como talleres, conferencias, fiestas, etc.
- Registrar asistentes, incluyendo profesores, alumnos y otros participantes.
- Mostrar detalles de los eventos, como la lista de asistentes.
- Generar informes con estadísticas sobre los eventos y los asistentes.

## Descripción de los Objetos Principales

Durante el inicio del programa, se crean varios objetos que son fundamentales para el funcionamiento de la aplicación. A continuación, se detallan estos objetos:

### 1. Gestor de Eventos (`GestorEvento`)

El `GestorEvento` es una clase principal que gestiona todas las operaciones relacionadas con la creación, gestión y presentación de eventos. Algunas de las funciones clave del `GestorEvento` incluyen:

- Creación y almacenamiento de eventos.
- Registro de asistentes a eventos.
- Generación de informes sobre eventos y asistentes.

### 2. Evento (`Evento`)

La clase `Evento` representa un evento individual que se organiza como parte del programa. 
Cada objeto `Evento` tiene atributos como nombre, tipo, fecha, lugar, duración, costo, capacidad máxima y una lista de asistentes.
Entre las funciones importantes de la clase `Evento` se incluyen:

- Mostrar detalles del evento.
- Agregar asistentes al evento.
- Guardar los detalles del evento en un archivo de texto.

### 3. Asistente (`Asistente`)

La clase `Asistente` representa a una persona que asiste a un evento.
Cada objeto `Asistente` tiene atributos como nombre, edad, dinero disponible, universidad (si es alumno), y si es alumno o profesor. 
Algunas funciones importantes de la clase `Asistente` incluyen:

- Mostrar detalles del asistente.
- Guardar los detalles del asistente en un archivo de texto.


## Requisitos del Sistema

- Se requiere un compilador de C++ compatible, como g++.
- El proyecto utiliza archivos de texto para almacenar datos, por lo que se necesitan permisos de lectura y escritura para los archivos de eventos y asistentes.

## Instrucciones

1. **Compilación del Código:**
   Utiliza el siguiente comando para compilar el código fuente:
   g++ Evento.cpp Asistente.cpp GestorEvento.cpp Main.cpp -o main

   Esto creará un ejecutable llamado `main`.

2. **Ejecución del Programa:**
   Después de compilar el código, ejecuta el programa con el siguiente comando:
   ./main
   Esto iniciará la aplicación y mostrará el menú principal en la consola.

3. **Uso del Programa:**
   El menú principal te permite seleccionar varias opciones, como crear eventos, registrar asistentes, generar informes, etc.
   Sigue las instrucciones en pantalla para interactuar con la aplicación y realizar las tareas deseadas.

4. **Formato de los Archivos de Texto:**
   El programa utiliza dos archivos de texto (`asistentes.txt` y `eventos.txt`) para almacenar datos.
   Asegúrate de que los archivos de texto sigan el formato especificado en el README para evitar errores al cargar los datos.

5. **Comprensión del Código Fuente:**
   Si deseas explorar el código fuente, puedes encontrar los archivos relevantes en el repositorio.
   Lee los comentarios en el código para comprender cómo está estructurada la aplicación y cómo funciona cada parte.

## Archivos de Texto

El proyecto utiliza dos archivos de texto para almacenar datos:

### `asistentes.txt`

Este archivo contiene información sobre los asistentes registrados para los eventos. Cada línea representa un asistente y tiene los siguientes campos separados por comas:
- Nombre del evento
- Nombre del asistente
- Edad
- Dinero disponible
- Universidad
- Es alumno (1 para sí, 0 para no)
- Es profesor (1 para sí, 0 para no)

Ejemplo:
Taller de programacion,juan,14,100,Universidad X,1,0
Taller de baile,Pedro,25,9999,Universidad Y,1,0
Conferencia de tecnologia,josejuan,21,9999,,0,0
Taller de programacion,Maxi,1000,1,Universidad Z,1,0

### `eventos.txt`

Este archivo contiene información sobre los eventos programados. Cada línea representa un evento y tiene los siguientes campos separados por comas:
- Nombre del evento
- Tipo
- Fecha (en formato YYYY-MM-DD)
- Lugar
- Duración
- Costo
- Capacidad máxima

Ejemplo:
Conferencia de tecnologia,Tecnologia,2024-05-10,Centro de convenciones,2 horas,50,200
Taller de programacion,Capacitacion,2024-07-20,Universidad X,4 horas,0,50
Taller de baile,Taller,2024-06-03,Universidad Y,3 horas,30,25

## Autores

- Nombre: Inti Bautista Santibáñez Walker, rut: 21.275.258-4, correor: inti.santibanez@alumnos.ucn.cl
- Nombre: Carlos Andres Tapia Paredes, rut: 21.458.544-8, correo: carlos.tapia03@alumnos.ucn.cl

