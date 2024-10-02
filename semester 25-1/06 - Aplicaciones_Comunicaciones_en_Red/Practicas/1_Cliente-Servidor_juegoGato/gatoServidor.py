#!/usr/bin/python3

import socket
import random
import time

def generar_tablero(tam):
    return ["□"] * (tam * tam)

def mostrar_tablero(tablero, tam):
    for i in range(tam):
        print(tablero[i * tam:(i + 1) * tam])

def traducir_tirada(tirada, tam):
    columna = ord(tirada[0]) - 65  # Convierte la letra a un índice (A -> 0, B -> 1, ...)
    fila = int(tirada[1]) - 1  # Convierte el número a un índice (1 -> 0, 2 -> 1, ...)
    return fila * tam + columna

def validar_ganador(tablero, tam, linea):
    # Revisar filas, columnas y diagonales
    for i in range(tam):
        if tablero[i*tam:(i+1)*tam].count(tablero[i*tam]) == linea and tablero[i*tam] != "□":
            return True
        if tablero[i::tam].count(tablero[i]) == linea and tablero[i] != "□":
            return True
    
    if [tablero[i*tam+i] for i in range(tam)].count(tablero[0]) == linea and tablero[0] != "□":
        return True
    if [tablero[i*tam+(tam-1-i)] for i in range(tam)].count(tablero[tam-1]) == linea and tablero[tam-1] != "□":
        return True
    return False

def servidor():
    HOST = "192.168.1.72"
    PORT = 54321
    buffer_size = 1024

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as TCPServerSocket:
        TCPServerSocket.bind((HOST, PORT))
        TCPServerSocket.listen()
        print("El servidor está disponible y en espera de solicitudes...")

        Client_conn, Client_addr = TCPServerSocket.accept()
        with Client_conn:
            print("Conectado a", Client_addr)

            # Recibir el modo de juego
            modo = Client_conn.recv(buffer_size).decode('utf-8')
            tam = int(modo[0])  # Tamaño del tablero (3 o 5)
            linea = tam  # Línea para ganar (3 o 5)
            
            # Generar tablero
            tablero = generar_tablero(tam)
            Client_conn.sendall("".join(tablero).encode('utf-8'))

            inicio = time.time()  # Marcar el inicio de la partida

            while True:
                # Recibir tirada del cliente
                tirada = Client_conn.recv(buffer_size).decode('utf-8')
                indice = traducir_tirada(tirada, tam)

                # Validar la tirada
                if tablero[indice] == "□":
                    tablero[indice] = "x"  # Marcar la tirada del cliente

                    # Verificar si el cliente ganó
                    if validar_ganador(tablero, tam, linea):
                        Client_conn.sendall("GANO el jugador!".encode('utf-8'))
                        break

                    # Tirada del servidor
                    while True:
                        tirada_servidor = random.randint(0, tam*tam - 1)
                        if tablero[tirada_servidor] == "□":
                            tablero[tirada_servidor] = "o"
                            break

                    # Verificar si el servidor ganó
                    if validar_ganador(tablero, tam, linea):
                        Client_conn.sendall("GANO el servidor!".encode('utf-8'))
                        break

                    # Enviar tablero actualizado al cliente
                    Client_conn.sendall("".join(tablero).encode('utf-8'))

                    # Verificar si hay empate
                    if "□" not in tablero:
                        Client_conn.sendall("EMPATE!".encode('utf-8'))
                        break
                else:
                    Client_conn.sendall("Movimiento inválido, casilla ocupada.".encode('utf-8'))

            fin = time.time()  # Marcar el fin de la partida
            duracion = fin - inicio
            print(f"Duración del juego: {duracion:.2f} segundos")

if __name__ == "__main__":
    servidor()
