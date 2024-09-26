import socket

HOST = "192.168.1.72"  # El hostname o IP del servidor
PORT = 54321  # El puerto que usa el servidor
bufferSize = 1024
termination_signal = ""  # La señal para terminar la conexión
server_closing_message = "Servidor cerrado."  # Mensaje de cierre

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as UDPServerSocket:
    UDPServerSocket.bind((HOST, PORT))

    print("Servidor UDP activo, esperando peticiones")

    while True:
        data, address = UDPServerSocket.recvfrom(bufferSize)
        message = data.decode()

        # Verificar si se ha recibido la señal de término
        if message == termination_signal:
            print("Señal de término recibida. Informando al cliente y cerrando servidor.")
            # Enviar mensaje de cierre al cliente
            UDPServerSocket.sendto(str.encode(server_closing_message), address)
            break

        print(f"Mensaje del cliente: {message} Ip del cliente: {address}")

        # Enviando una respuesta al cliente
        UDPServerSocket.sendto(data, address)

print("Servidor cerrado.")
