import socket
import threading
import os
import sys

def limpiar_pantalla():
    # Limpia la terminal
    os.system('cls' if os.name == 'nt' else 'clear')

def escuchar_servidor(conn, continuar_jugando):
    while continuar_jugando[0]:
        try:
            mensaje = conn.recv(1024).decode()
            if mensaje:
                limpiar_pantalla()
                print("\n" + mensaje)

                # Verificar si el mensaje indica el fin del juego
                if "ganaste" in mensaje.lower() or "perdiste" in mensaje.lower() or "empate" in mensaje.lower():
                    continuar_jugando[0] = False  # Finaliza el bucle de entrada en main
                    conn.close()
                    sys.exit()  # Cerrar el programa inmediatamente
            else:
                break
        except:
            print("Se perdió la conexión con el servidor.")
            break

def main():
    host = input("Ingrese la IP del servidor: ")
    port = int(input("Ingrese el puerto del servidor: "))

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as conn:
        conn.connect((host, port))
        print("Conectado al servidor.")

        # Flag para controlar el ciclo de entrada
        continuar_jugando = [True]

        # Iniciar hilo de escucha para recibir mensajes del servidor
        hilo_escucha = threading.Thread(target=escuchar_servidor, args=(conn,continuar_jugando))
        hilo_escucha.daemon = True
        hilo_escucha.start()

        while continuar_jugando[0]:
            jugada = input("Ingrese su jugada (ej: A1): ")
            if jugada.lower() == 'salir':
                print("Desconectándose...")
                break
            conn.sendall(jugada.encode())

if __name__ == "__main__":
    main()
