#!/usr/bin/python3

import socket

HOST = "187.190.146.19"  # Dirección IP del servidor
PORT = 54321  # Puerto del servidor
buffer_size = 1024

def imprimir_tablero(tablero, tamaño):
    letras = "ABCDE"[:tamaño]
    print("   " + " ".join([str(i+1) for i in range(tamaño)]))
    for idx, fila in enumerate([tablero[i:i+tamaño] for i in range(0, len(tablero), tamaño)]):
        print(f"{letras[idx]}  " + " ".join(fila))

def jugar():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as TCPClientSocket:
        TCPClientSocket.connect((HOST, PORT))
        
        # Elige dificultad
        dificultad = input("Elige dificultad: 1. Principiante (3x3), 2. Avanzado (5x5): ")
        TCPClientSocket.sendall(dificultad.encode())
        
        # Recibe y muestra el tablero inicial
        tablero = TCPClientSocket.recv(buffer_size).decode()
        tamaño = 3 if dificultad == '1' else 5
        imprimir_tablero(tablero, tamaño)
        
        while True:
            # Enviar jugada
            jugada = input("Ingresa tu jugada (e.g., A1): ")
            TCPClientSocket.sendall(jugada.encode())
            
            # Recibe la respuesta del servidor (actualización del tablero)
            tablero = TCPClientSocket.recv(buffer_size).decode()
            imprimir_tablero(tablero, tamaño)
            
            # Verifica si el juego ha terminado
            resultado = TCPClientSocket.recv(buffer_size).decode()
            if resultado:
                print(resultado)
                break

if __name__ == "__main__":
    jugar()
