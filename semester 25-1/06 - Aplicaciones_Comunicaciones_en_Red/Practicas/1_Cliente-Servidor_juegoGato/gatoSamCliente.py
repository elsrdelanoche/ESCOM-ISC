import socket
import os

# para "limpiar" la pantalla
def limpiar_pantalla():
    os.system('cls' if os.name == 'nt' else 'clear')

# para imprimir el tablero
def imprimir_tablero(tablero_str):
    print("tablero:")
    print(tablero_str)

# configuracion que va ingresar el cliente
host = input("IP del servidor al que vas a conectarte (ej: 127.0.0.1): ").strip()
port = 54321
buffer_size = 4096 

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as tcp_client_socket:
    # para conectar al servidor
    tcp_client_socket.connect((host, port))

    while True:
        # dificultad
        dificultad = input("escribe la dificultad (principiante/avanzado): ").strip()
        tcp_client_socket.sendall(dificultad.encode())
        print(f"dificultad enviada: {dificultad}")

        # para recibir confirmacion o un msj de error por parte del server
        data = tcp_client_socket.recv(buffer_size).decode()
        if data == "FIN":
            print("dificultad no reconocida, apagando cliente")
            break
        elif data == "OK":
            print("comenzando el juego...")
        else:
            print("respuesta desconocida del servidor, apagando cliente.")
            break

        # juego (while)
        while True:
            # mensaje del server (tablero y msj)
            data = tcp_client_socket.recv(buffer_size).decode()

            # separar el tablero y el mensaje
            tablero_str, _, mensaje = data.partition('\n###\n')

            limpiar_pantalla()
            # imprimir el tablero
            imprimir_tablero(tablero_str)

            # manejar fin del juego
            if mensaje:
                print(mensaje)
                if "ganaste" in mensaje or "perdiste" in mensaje or "Empate" in mensaje:
                    # enviar confirmación al servidor antes de cerrar
                    tcp_client_socket.sendall("OK".encode('utf-8'))
                    print("ein del juego.")
                    break

            # enviar jugada (si el juego no ha terminad)
            jugada = input("escribe la casilla (ej: A1): ").strip()
            tcp_client_socket.sendall(jugada.encode())

        # tablero final, y mensaje de nueva partida
        data = tcp_client_socket.recv(buffer_size).decode()
        tablero_str, _, mensaje = data.partition('\n###\n')
        imprimir_tablero(tablero_str)
        print(mensaje)
        respuesta = input().strip().lower()
        tcp_client_socket.sendall(respuesta.encode())

        if respuesta != "si":
            print("cerrando conexion.")
            break
