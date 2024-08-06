# Analizador de Complejidad de Algoritmos

Este programa es una herramienta educativa diseñada para ilustrar las diferencias en la complejidad computacional de varios algoritmos. La interfaz gráfica permite al usuario seleccionar un algoritmo, definir el tamaño del arreglo y observar la cantidad de operaciones realizadas a medida que el tamaño del arreglo aumenta. Además, se muestran curvas teóricas para comparar con la ejecución real.

## Requisitos

- Python 3.x
- Bibliotecas:
  - `tkinter`: Para la interfaz gráfica.
  - `numpy`: Para cálculos numéricos.
  - `matplotlib`: Para la visualización de datos.

## Instalación

1. Clona el repositorio o descarga los archivos.
2. Asegúrate de tener las bibliotecas necesarias instaladas. Puedes instalarlas usando pip:

   ```sh
   pip install numpy matplotlib
   ```

## Uso

1. Ejecuta el script `main.py`.
2. En la ventana de la aplicación:
   - Ingresa el tamaño del arreglo que se generará.
   - Selecciona el algoritmo que deseas analizar:
     - **First Element**: O(1)
     - **Búsqueda Binaria**: O(log n)
     - **Suma de arreglo**: O(n)
     - **Merge sort**: O(n log n)
     - **Bubble sort**: O(n²)
   - Haz clic en "Ejecutar" para ver la cantidad de operaciones realizadas.
   - Haz clic en "Limpiar" para reiniciar la aplicación.

3. La gráfica mostrará el número de operaciones realizadas por el algoritmo y comparará estas operaciones con la curva teórica esperada.

## Licencia

Este proyecto está licenciado bajo los términos de la licencia MIT. Consulta el archivo LICENSE para más detalles.
lizadas con curvas teóricas. Incluye selección de algoritmos como `O(1)`, `O(n)`, `O(n log n)`, `O(n²)`.
