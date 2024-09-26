import socket
import time

HOST = "172.100.72.237"  # El hostname o IP del servidor
PORT = 54322  # El puerto usado por el servidor
bufferSize = 1024
serverAddressPort = (HOST, PORT)

# Crea un socket UDP del lado del cliente
with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as UDPClientSocket:
    # Enviar 100 mensajes numerados del 1 al 100
    for i in range(1, 6):
        msgFromClient = str(i)
        bytesToSend = str.encode(msgFromClient)

        UDPClientSocket.sendto(bytesToSend, serverAddressPort)
        msgFromServer = UDPClientSocket.recvfrom(bufferSize)

        print(f"Mensaje {i} desde el servidor: {msgFromServer[0].decode()}")

        # Pausa breve entre envíos
        time.sleep(0.1) 

    # Enviar la señal de término
    termination_signal = ""
    UDPClientSocket.sendto(str.encode(termination_signal), serverAddressPort)

print("Transferencia completada.")
