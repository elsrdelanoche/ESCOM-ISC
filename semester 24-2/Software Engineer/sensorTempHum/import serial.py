import serial
import csv
import datetime
from pathlib import Path

# Configuración del puerto serial
ser = serial.Serial('COM4', 9600)  # Reemplaza 'COM3' con el puerto correcto

# Ruta de la carpeta donde se guardarán los archivos CSV
folder_path = Path("datos_invernadero")

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        data = line.split(',')

        # Obtiene la fecha y hora actual
        now = datetime.datetime.now()
        fecha = now.strftime("%Y-%m-%d")
        hora = now.strftime("%H")

        # Nombre del archivo CSV para la hora actual
        filename = folder_path / f"{fecha}_{hora}.csv"

        # Crea la carpeta si no existe
        folder_path.mkdir(parents=True, exist_ok=True)

        # Escribe los datos en el archivo CSV
        with open(filename, 'a', newline='') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow([now.strftime("%Y-%m-%d %H:%M:%S"), data[0], data[1]])  # Fecha, humedad, temperatura
