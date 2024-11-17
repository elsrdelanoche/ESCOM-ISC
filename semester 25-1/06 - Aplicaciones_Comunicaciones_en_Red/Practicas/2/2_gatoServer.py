import socket
import threading

def generar_tablero(tam):
    return ["□"] * (tam * tam)

def mostrar_tablero(tablero, tam):
    encabezado_columnas = "   " + " ".join(chr(65 + i) for i in range(tam))
    filas = [encabezado_columnas]
    for i in range(tam):
        fila = f"{i + 1} " + " ".join(tablero[i * tam:(i + 1) * tam])
        filas.append(fila)
    return "\n".join(filas)

def traducir_tirada(tirada, tam):
    columna = ord(tirada[0].upper()) - 65
    fila = int(tirada[1]) - 1
    return fila * tam + columna

def validar_ganador(tablero, tam, linea):
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

class ServidorGato:
    def __init__(self, num_jugadores):
        self.tam = 3  # Tamaño del tablero
        self.linea = 3  # Longitud de línea para ganar
        self.tablero = generar_tablero(self.tam)
        self.num_jugadores = num_jugadores
        self.jugadores = {}  # Guardar conexión y tipo de cada jugador
        self.conexiones = []
        self.lock = threading.Lock()
        self.jugador_actual = 0  # Lleva el control de turno

    def manejar_cliente(self, conn, addr, jugador_id):
        tipo_jugador = "X" if jugador_id % 2 == 0 else "O"
        self.jugadores[conn] = tipo_jugador
        conn.sendall(f"Bienvenido, eres el jugador {tipo_jugador}\n".encode())

        while True:
            if self.jugador_actual != jugador_id:
                continue  # Esperar el turno del jugador actual

            tablero_str = mostrar_tablero(self.tablero, self.tam)
            mensaje_turno = f"Es tu turno, jugador {tipo_jugador}. Ingresa tu movimiento (ej: A1):\n"
            conn.sendall((tablero_str + "\n" + mensaje_turno).encode())

            tirada = conn.recv(1024).decode().strip()
            indice = traducir_tirada(tirada, self.tam)

            with self.lock:
                if self.tablero[indice] == "□":
                    self.tablero[indice] = tipo_jugador
                    tablero_str = mostrar_tablero(self.tablero, self.tam)

                    if validar_ganador(self.tablero, self.tam, self.linea):
                        self.notificar_a_todos(f"{tablero_str}\n¡El jugador {tipo_jugador} ha ganado!\n")
                        break
                    elif "□" not in self.tablero:
                        self.notificar_a_todos(f"{tablero_str}\n¡Empate!\n")
                        break

                    self.notificar_a_todos(tablero_str)
                    self.jugador_actual = (self.jugador_actual + 1) % self.num_jugadores
                else:
                    conn.sendall("Movimiento inválido, casilla ocupada. Inténtalo de nuevo.\n".encode())

            if not self.conexiones:
                break

    def notificar_a_todos(self, mensaje):
        hilos = []
        for conn in self.conexiones:
            hilo = threading.Thread(target=self.enviar_mensaje, args=(conn, mensaje))
            hilos.append(hilo)
            hilo.start()
        for hilo in hilos:
            hilo.join()

    def enviar_mensaje(self, conn, mensaje):
        try:
            conn.sendall(mensaje.encode())
        except:
            conn.close()
            self.conexiones.remove(conn)

    def aceptar_conexiones(self, host="192.168.0.104", port=54321):
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as servidor:
            servidor.bind((host, port))
            servidor.listen()
            print("Servidor en espera de conexiones...")

            for jugador_id in range(self.num_jugadores):
                conn, addr = servidor.accept()
                print(f"Conectado con {addr}")
                self.conexiones.append(conn)
                hilo = threading.Thread(target=self.manejar_cliente, args=(conn, addr, jugador_id))
                hilo.start()

if __name__ == "__main__":
    num_jugadores = int(input("Ingrese el número de jugadores: "))
    servidor_gato = ServidorGato(num_jugadores)
    servidor_gato.aceptar_conexiones()
