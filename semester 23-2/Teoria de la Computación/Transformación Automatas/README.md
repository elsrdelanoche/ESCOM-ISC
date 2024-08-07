
# Proyecto: Transformación de AFN a AFD y AFD desde archivo TXT

## Descripción
Este proyecto contiene dos partes principales:

1. **Transformación de AFN a AFD:** Implementación de un algoritmo para transformar un Autómata Finito No Determinista (AFN) a un Autómata Finito Determinista (AFD) utilizando estructuras de datos en C++. La salida se representa en un archivo Graphviz para visualización.

2. **Generación de AFD desde un archivo TXT:** Implementación para crear un AFD a partir de un archivo de texto que describe los estados y transiciones. Se genera un archivo Graphviz para la visualización del AFD y se permite evaluar cadenas de entrada.

## Requisitos
- Compilador compatible con C++
- Graphviz instalado para la generación de imágenes de grafos

## Instalación y Ejecución
1. **Compilar el proyecto:** Usa un compilador de C++ para compilar el código fuente.
   ```sh
   g++ -o TransformAFNtoAFD TransformAFNtoAFD.cpp -std=c++11
   g++ -o TxtToAFD TxtToAFD.cpp -std=c++11
   ```
2. **Ejecutar los programas:**
   - Para la transformación de AFN a AFD:
     ```sh
     ./TransformAFNtoAFD
     ```
   - Para la generación de AFD desde un archivo TXT:
     ```sh
     ./TxtToAFD
     ```

## Uso
- **Transformación de AFN a AFD:**
  - El programa lee un archivo `input.txt` con la definición del AFN y genera `graph.dot`, que se puede visualizar como una imagen utilizando Graphviz.
  - El programa también genera un archivo `graph.png` con la imagen del AFD.

- **Generación de AFD desde un archivo TXT:**
  - El programa lee `automata2.txt`, que contiene la definición del AFD.
  - Genera un archivo `automata.dot` y su correspondiente imagen `automata.png`.
  - Permite evaluar cadenas de entrada y verificar si son aceptadas por el AFD.

## Licencia
Este proyecto está bajo la licencia MIT. Puedes ver más detalles en el archivo `LICENSE`.
