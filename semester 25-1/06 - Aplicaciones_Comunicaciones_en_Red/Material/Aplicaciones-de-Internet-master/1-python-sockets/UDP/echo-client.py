import socket

HOST = "8.12.0.24"  # El hostname o IP del servidor
PORT = 54321  # El puerto usado por el servidor
msgFromClient = "Hola Servidor, Soy Alfredo Bautista"
bytesToSend = str.encode(msgFromClient)
serverAddressPort = ("8.12.0.24", 54321)
bufferSize = 1024

# Crea un socket UDP del lado del cliente

with socket.socket(socket.AF_INET,socket.SOCK_DGRAM) as UDPClientSocket:
    # Enviando mensaje al servidor usando el socket UDP
    UDPClientSocket.sendto(bytesToSend, serverAddressPort)
    msgFromServer = UDPClientSocket.recvfrom(bufferSize)
    print("Message from Server {}".format(msgFromServer[0]))