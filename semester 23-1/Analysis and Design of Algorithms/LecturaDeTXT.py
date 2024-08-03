# Abrimos el archivo en modo lectura
with open("HUFFMAN.txt", "r") as f:
    for linea in f:
        # Si la línea comienza con "Caracter:"
        if linea.startswith("Caracter:"):
            # Extraemos el valor de caracter y eliminamos las comas
            caracter = linea.split(":")[1].replace(",", "").strip()
        # Si la línea comienza con "Frecuencia:"
        elif linea.startswith("Frecuencia:"):
            # Extraemos el valor de frecuencia y eliminamos las comas
            frecuencia = linea.split(":")[1].replace(",", "").strip()
        # Si la línea comienza con "Mensaje:"
        elif linea.startswith("Mensaje:"):
            # Extraemos el valor de mensaje
            mensaje = linea.split(":")[1].strip()
print("Caracter:", caracter)
print("Frecuencia:", frecuencia)
print("Mensaje:", mensaje)
