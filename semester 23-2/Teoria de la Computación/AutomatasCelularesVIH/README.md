# Proyecto: Simulación del Juego de la Vida de Conway

## Descripción
Este proyecto es una implementación del Juego de la Vida de Conway utilizando la biblioteca gráfica SFML en C++. El Juego de la Vida es un autómata celular donde células en una cuadrícula viven, mueren o nacen según ciertas reglas. La simulación se visualiza en una ventana gráfica que muestra la evolución de las células a lo largo del tiempo.

## Características
- **Interfaz gráfica:** Utiliza SFML para representar gráficamente el estado de la cuadrícula.
- **Dinámica del juego:** Las reglas de evolución de las células están implementadas según las reglas originales de Conway.
- **Inicialización aleatoria:** La cuadrícula inicial se llena aleatoriamente con células vivas y muertas.

## Requisitos
- SFML (Simple and Fast Multimedia Library)
- Un compilador compatible con C++

## Instalación y Ejecución
1. **Instalar SFML:** Asegúrate de tener SFML instalado en tu sistema.
2. **Compilar el proyecto:** Usa un compilador de C++ para compilar el código fuente. Por ejemplo:
   ```sh
   g++ -o GameOfLife main.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```
3. **Ejecutar la simulación:** Una vez compilado, ejecuta el binario generado:
   ```sh
   ./GameOfLife
   ```

## Uso
- Al ejecutar el programa, se abrirá una ventana de SFML mostrando la cuadrícula. Las células verdes representan células vivas y las negras representan células muertas.
- La simulación se actualiza en cada iteración según las reglas de Conway.

## Reglas del Juego de la Vida
1. **Supervivencia:** Una célula viva con 2 o 3 vecinos vivos sigue viva.
2. **Muerte:** Una célula viva con menos de 2 o más de 3 vecinos vivos muere.
3. **Nacimiento:** Una célula muerta con exactamente 3 vecinos vivos se convierte en una célula viva.

#### Licencia
Este proyecto está bajo la licencia MIT. Puedes ver más detalles en el archivo `LICENSE`.
