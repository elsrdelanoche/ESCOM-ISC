import tkinter as tk
from tkinter import ttk, messagebox
import random
import time
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

# Funciones para los algoritmos
def get_first_element(arr):
    return arr[0]

def binary_search(arr, target):
    arr.sort()  # Asegurar que el arreglo esté ordenado
    left, right = 0, len(arr) - 1
    operations = 0
    while left <= right:
        operations += 1
        mid = (left + right) // 2
        if arr[mid] == target:
            return operations
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return operations

def sum_array(arr):
    total = 0
    operations = 0
    for num in arr:
        total += num
        operations += 1
    return operations

def merge_sort(arr):
    operations = [0]
    def merge_sort_internal(arr):
        if len(arr) <= 1:
            return arr
        mid = len(arr) // 2
        left = merge_sort_internal(arr[:mid])
        right = merge_sort_internal(arr[mid:])
        return merge(left, right)
    
    def merge(left, right):
        result = []
        i = j = 0
        while i < len(left) and j < len(right):
            operations[0] += 1
            if left[i] < right[j]:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1
        result.extend(left[i:])
        result.extend(right[j:])
        return result
    
    merge_sort_internal(arr)
    return operations[0]

def bubble_sort(arr):
    n = len(arr)
    operations = 0
    for i in range(n):
        for j in range(0, n-i-1):
            operations += 1
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return operations

# Función para ejecutar el algoritmo seleccionado y actualizar la gráfica
def simulate_execution(algorithm, arr, interval=100):
    interval_operations = []
    interval_sizes = []
    
    if algorithm == 'First ELement':
        interval_operations.append(1)
        interval_sizes.append(len(arr))
        result = get_first_element(arr)
    else:
        if algorithm == 'Busqueda Binaria':
            for i in range(0, len(arr), interval):
                operations = binary_search(arr[:i+1], random.randint(0, 1000000))
                interval_operations.append(operations)
                interval_sizes.append(i + 1)
                time.sleep(0.001)
        elif algorithm == 'Suma de arreglo':
            for i in range(0, len(arr), interval):
                operations = sum_array(arr[:i+1])
                interval_operations.append(operations)
                interval_sizes.append(i + 1)
                time.sleep(0.001)
        elif algorithm == 'Merge sort':
            for i in range(0, len(arr), interval):
                operations = merge_sort(arr[:i+1])
                interval_operations.append(operations)
                interval_sizes.append(i + 1)
                time.sleep(0.001)
        elif algorithm == 'Bubble sort':
            for i in range(0, len(arr), interval):
                operations = bubble_sort(arr[:i+1])
                interval_operations.append(operations)
                interval_sizes.append(i + 1)
                time.sleep(0.001)
        else:
            raise ValueError

    update_plot(interval_sizes, interval_operations, algorithm)
    return result


# Función para calcular las curvas teóricas
def theoretical_curves(n):
    n = np.array(n)
    curves = {
        'O(1)': np.ones_like(n),
        'O(log n)': np.log2(n),
        'O(n)': n,
        'O(n log n)': n * np.log2(n),
        'O(n²)': n ** 2
    }
    return curves

# Función para encontrar la complejidad más cercana
def find_closest_complexity(sizes, operations):
    curves = theoretical_curves(sizes)
    min_error = float('inf')
    closest_complexity = None

    for name, curve in curves.items():
        if len(curve) == len(operations):
            # Normalizar operaciones para facilitar la comparación
            norm_operations = operations / np.max(operations)
            norm_curve = curve / np.max(curve)
            error = np.mean((norm_operations - norm_curve) ** 2)
            if error < min_error:
                min_error = error
                closest_complexity = name

    return closest_complexity, curves[closest_complexity]

# Función para ejecutar el algoritmo seleccionado y actualizar la gráfica
def execute_algorithm():
    try:
        size = int(size_entry.get())
        if size <= 0:
            raise ValueError

        arr = [random.randint(0, 1000000) for _ in range(size)]
        algorithm = algorithm_combobox.get()

        result = simulate_execution(algorithm, arr)

        messagebox.showinfo("Resultado", f"El algoritmo {algorithm} se ejecutó con éxito.")

    except ValueError:
        messagebox.showerror("Error", "Por favor, ingrese un tamaño válido y seleccione un algoritmo.")

# Función para actualizar la gráfica
def update_plot(sizes, operations, algorithm):
    ax.clear()
    if algorithm == 'First ELement':
        ax.plot([0, max(sizes)], [1, 1], linestyle='-', color='b', label='O(1)')  # Línea constante en y=1
        ax.set_ylim(0, 10)  # Ajustar el eje Y para visualizar correctamente O(1)
    else:
        ax.plot(sizes, operations, linestyle='-', color='b', label='Operaciones reales')  # Línea sin marcadores

    # Encontrar y trazar la complejidad más cercana
    closest_complexity, theoretical_curve = find_closest_complexity(sizes, operations)
    # Ajustar la curva teórica para que tenga el mismo rango de operaciones
    scale_factor = np.max(operations) / np.max(theoretical_curve)
    ax.plot(sizes, theoretical_curve * scale_factor, linestyle='--', color='r', label=f'{closest_complexity}')
    
    ax.set_title('Complejidad')
    ax.set_xlabel('Elementos')
    ax.set_ylabel('Operaciones')
    ax.set_xlim(left=0)  # Asegura que el eje X comience en 0
    ax.set_ylim(bottom=0)  # Asegura que el eje Y comience en 0
    ax.legend()
    canvas.draw()

# Función para limpiar la gráfica y los campos de entrada
def clear_all():
    size_entry.delete(0, tk.END)
    algorithm_combobox.set('O(1)')
    ax.clear()
    ax.set_title('Número de Operaciones vs Tamaño del arreglo')
    ax.set_xlabel('Tamaño del arreglo')
    ax.set_ylabel('Número de Operaciones')
    ax.set_xlim(left=0)
    ax.set_ylim(bottom=0)
    canvas.draw()

# Inicializar los datos para la gráfica
sizes = [0]
operations = [0]

# Configuración de la ventana principal
root = tk.Tk()
root.title("Analisis de Algortimos")

# Etiqueta y campo de entrada para el tamaño del arreglo
size_label = ttk.Label(root, text="Tamaño del arreglo a generar:")
size_label.grid(column=0, row=0, padx=5, pady=5)
size_entry = ttk.Entry(root)
size_entry.grid(column=1, row=0, padx=5, pady=5)

# Etiqueta y combobox para seleccionar el algoritmo
algorithm_label = ttk.Label(root, text="Selecciona el algoritmo:")
algorithm_label.grid(column=0, row=1, padx=5, pady=5)
algorithm_combobox = ttk.Combobox(root, values=['First Element', 'Busqueda Binaria', 'Suma de arreglo', 'Merge sort', 'Bubble sort'])
algorithm_combobox.grid(column=1, row=1, padx=5, pady=5)
algorithm_combobox.current(0)

# Botón para ejecutar el algoritmo
execute_button = ttk.Button(root, text="Ejecutar", command=execute_algorithm)
execute_button.grid(column=0, row=2, padx=5, pady=5)

# Botón para limpiar la gráfica y los campos de entrada
clear_button = ttk.Button(root, text="Limpiar", command=clear_all)
clear_button.grid(column=1, row=2, padx=5, pady=5)

# Configuración de la gráfica
fig, ax = plt.subplots()
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.get_tk_widget().grid(column=2, row=0, rowspan=3, padx=5, pady=5)

# Ejecutar la aplicación
root.mainloop()
