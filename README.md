# Tarea_1 | Sistema de Gestión de Tickets

Este programa en lenguaje C simula una aplicación para la gestión de tickets de soporte técnico dentro de una empresa. Permite a los usuarios registrar tickets, asignarles prioridades (Alta, Media o Baja), visualizar los pendientes, procesarlos en orden de urgencia y buscarlos por su ID.

Está diseñado para ser una herramienta útil en entornos donde la atención organizada y priorizada es fundamental, como en áreas de soporte técnico, atención al cliente, servicios administrativos o gestión de incidencias internas.

## Cómo compilar y ejecutar

Este sistema ha sido desarrollado en lenguaje C y puede ejecutarse fácilmente utilizando **Visual Studio Code** junto con una extensión para C/C++, como **C/C++ Extension Pack** de Microsoft. Para comenzar a trabajar con el sistema en tu equipo local, sigue estos pasos:

### Requisitos previos:

- Tener instalado [Visual Studio Code](https://code.visualstudio.com/).
- Instalar la extensión **C/C++** (Microsoft).
- Tener instalado un compilador de C (como **gcc**). Si estás en Windows, se recomienda instalar [MinGW](https://www.mingw-w64.org/) o utilizar el entorno [WSL](https://learn.microsoft.com/en-us/windows/wsl/).

### Pasos para compilar y ejecutar:

1. **Descarga y descomprime** el archivo `.zip` del proyecto en una carpeta de tu elección.
2. **Abre el proyecto en Visual Studio Code**
    - Inicia Visual Studio Code.
    - Selecciona `Archivo > Abrir carpeta...` y elige la carpeta del proyecto.
3. **Compila el código**
Asegúrate de que los siguientes archivos estén en la misma carpeta:
    - `main.c`: Contiene la lógica principal de la aplicación.
    - `queue.h`: Contiene la implementación de las estructuras de datos.
    - Abre la terminal integrada (`Terminal > Nueva terminal`).
    - En la terminal, compila el programa con el siguiente comando:
    
        ```bash
        gcc main.c queue.c -o sistema_tickets
        ```

4. **Ejecuta el programa**
    - Una vez compilado correctamente, ejecuta el programa con:

        ```bash
        ./sistema_tickets
        ```

    - En Windows, puedes ejecutar con:

        ```bash
        sistema_tickets.exe
        ```

## Menú de Opciones
MENU OPCIONES - SELECCIONE UNA OPCIÓN:
1. Ingresar ticket.
2. Asignar prioridad.
3. Mostrar lista de tickets pendientes.
4. Procesar ticket.
5. Buscar ticket.
0. Salir. 

### Funcionando correctamente:

- **Registrar tickets** con una descripción e ID únicos.
- **Asignar prioridades** a los tickets registrados.
- **Ver la lista de tickets pendientes**, ordenada por prioridad y hora de registro.
- **Procesar el siguiente ticket**, seleccionando siempre el más prioritario y antiguo.
- **Buscar un ticket** por ID para consultar su información.

## Ejemplo de uso

**Paso 1: Registrar un nuevo ticket**
Opción seleccionada: 1. Ingresar ticket 
- Inserte ID del ticket: TCK-001
- Ingrese descripción: El sistema no arranca.
El ticket se guarda con prioridad baja por defecto y se registra su hora de creación.

**Paso 2: Asignar prioridad al ticket**
Opción seleccionada: 2. Asignar prioridad 
- Inserte ID del ticket: TCK-001
- Ingrese prioridad (Alta, Media o Baja): Alta
La prioridad del ticket TCK-001 se actualiza correctamente a "Alta".

**Paso 3: Procesar ticket**
Opción seleccionada: 3. Mostrar lista de tickets pendientes
Se muestra el listado de tickets pendientes (Prioridad, ID, Descripción, Hora de registro).

**Paso 4: Procesar ticket**
Opción seleccionada: 4. Procesar ticket 
- Ticket encontrado: ID: TCK-001
- Descripción: El sistema no arranca
- Prioridad: ALTA
- Hora de creación: 2025-04-13 19:32:21
El sistema toma el ticket con mayor prioridad y más antiguo, lo procesa y lo elimina de la cola.

**Paso 4: Buscar ticket**
Opción seleccionada: 5. Buscar ticket 
- Ingrese ID del ticket: TCK-002
- No se encontró ningún ticket con la ID proporcionada.
El sistema busca en todas las colas y notifica si no encuentra coincidencias.

**Paso 5: Salida**
Opción seleccionada: 0. Salida
Muestra mensaje de salida y cierra la aplicación.


