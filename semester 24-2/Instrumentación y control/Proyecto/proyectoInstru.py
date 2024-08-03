import tkinter as tk
from tkinter import ttk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import serial
import time



# Configuración de la comunicación serial
try:
    arduino = serial.Serial('COM3', 9600)  # Ajusta el puerto si es necesario
    time.sleep(2)  # Espera a que se establezca la conexión
except serial.SerialException as e:
    print(f"Error al abrir el puerto COM4: {e}")

# Funciones para mostrar mediciones
def mostrar_medicion():
    binario_str = entrada_binario.get()
    actualizar_grafico(binario_str)

def mostrar_medicion_arduino():
    try:
        if arduino.in_waiting > 0:
            binario_str = arduino.readline().decode().strip()
            estado_serial.config(text="Recibiendo datos...")
            # Invertir los bits del binario recibido
            binario_invertido = "".join('1' if bit == '0' else '0' for bit in binario_str)
            binario_recibido_label.config(text=f"Binario recibido: {binario_invertido}")
            actualizar_grafico(binario_invertido)  # Usar el binario invertido
        else:
            estado_serial.config(text="Esperando datos...")
    except serial.SerialException as e:
        estado_serial.config(text=f"Error de lectura: {e}")

    ventana.after(100, mostrar_medicion_arduino)  # Volver a llamar a la funciónion_arduino)  # Volver a llamar a la función

def actualizar_grafico(binario_str):
    try:
        # Convertir el binario a decimal y escalar a la distancia (0-7 cm)
        valor_decimal = int(binario_str, 2)  # Base 2 para binario
        distancia = valor_decimal * (7 / 255)  # Escalar de 0-255 a 0-7 cm

        resultado.config(text="")  # Limpiar el mensaje de error

        ax.clear()
        ax.set_xlim([-0.5, 7])
        ax.set_ylim([0, 1])
        ax.axvline(x=distancia, color='pink', linestyle='solid', linewidth=2)
        ax.set_yticks([])
        ax.set_xlabel("Distancia (cm)")
        ax.set_xticks(range(8))
        ax.set_xticklabels(range(8), fontsize=8)
        ax.xaxis.set_tick_params(pad=5)
        canvas.draw()
    except ValueError:
        resultado.config(text="Combinación binaria no válida")

# Ventana principal
ventana = tk.Tk()
ventana.title("Medición con ADC y Arduino")
ventana.configure(bg='white')

# Estilo para los botones
style = ttk.Style()
style.configure('TButton', background='lightblue', font=('Arial', 12))

# Botones "Manualmente" y "Arduino"
ttk.Button(ventana, text="Manualmente", style='TButton', command=mostrar_medicion).pack(fill=tk.X, padx=10, pady=10)
ttk.Button(ventana, text="Arduino", style='TButton', command=mostrar_medicion_arduino).pack(fill=tk.X, padx=10, pady=(0, 10))

# Etiqueta y entrada para el binario
ttk.Label(ventana, text="Combinación binaria:", background='white', font=('Arial', 12)).pack(pady=(0, 10))
entrada_binario = ttk.Entry(ventana, width=15, font=('Arial', 12))
entrada_binario.pack(pady=(0, 20))

# Etiquetas para mostrar el estado de la conexión y el binario recibido
estado_serial = ttk.Label(ventana, text="Esperando datos...", background='white', font=('Arial', 12))
estado_serial.pack(pady=(0, 10))
binario_recibido_label = ttk.Label(ventana, text="Binario recibido: ", background='white', font=('Arial', 12))
binario_recibido_label.pack(pady=(0, 10))

# Gráfico de la regla (inicialmente vacío)
fig, ax = plt.subplots(figsize=(8, 0.5))
canvas = FigureCanvasTkAgg(fig, master=ventana)
canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)

# Etiqueta para mostrar el resultado
resultado = ttk.Label(ventana, text="", background='white', font=('Arial', 12))
resultado.pack(pady=10)

# Iniciar el ciclo de actualización y el bucle principal de la interfaz
mostrar_medicion_arduino()
ventana.mainloop()
