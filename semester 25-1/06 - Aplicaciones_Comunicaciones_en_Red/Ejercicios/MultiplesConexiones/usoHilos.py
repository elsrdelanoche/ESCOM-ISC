# Importación de módulos necesarios
import socket  # Para manejo de sockets TCP/IP
import sys  # Para leer argumentos de línea de comandos
import threading  # Para manejar múltiples clientes con hilos

# Función principal que mantiene el servidor escuchando por conexiones
def servirPorSiempre(socketTcp, listaconexiones):
    try:
        while True:  # Bucle infinito para aceptar conexiones entrantes
            client_conn, client_addr = socketTcp.accept()  # Acepta una nueva conexión
            print("Conectado a", client_addr)
            
            # Almacena la conexión en la lista de conexiones activas
            listaconexiones.append(client_conn)
            
            # Crea un hilo para manejar los datos del cliente
            thread_read = threading.Thread(target=recibir_datos, args=[client_conn, client_addr])
            thread_read.start()  # Inicia el hilo

            # Llama a la función que gestiona las conexiones activas (limpieza de recursos)
            gestion_conexiones(listaConexiones)
    
    except Exception as e:
        print(e)  # Imprime cualquier error que ocurra

# Gestiona la lista de conexiones para eliminar las que ya no están activas
def gestion_conexiones(listaconexiones):
    # Recorre las conexiones para verificar si alguna está cerrada
    for conn in listaconexiones:
        if conn.fileno() == -1:  # `fileno() == -1` indica que el socket está cerrado
            listaconexiones.remove(conn)  # Elimina la conexión cerrada de la lista

    # Información de depuración sobre el estado del servidor
    print("hilos activos:", threading.active_count())  # Muestra el número de hilos activos
    print("enum", threading.enumerate())  # Enumera los hilos en ejecución
    print("conexiones: ", len(listaconexiones))  # Muestra cuántas conexiones quedan activas
    print(listaconexiones)

# Función para recibir datos del cliente y enviar una respuesta
def recibir_datos(conn, addr):
    try:
        cur_thread = threading.current_thread()  # Obtiene el hilo actual
        print("Recibiendo datos del cliente {} en el {}".format(addr, cur_thread.name))
        
        while True:  # Bucle para recibir datos continuamente
            data = conn.recv(1024)  # Recibe hasta 1024 bytes del cliente
            
            # Si no hay más datos (el cliente cerró la conexión), rompe el bucle
            if not data:
                print("Fin.")  # Indica el final de la conexión
                break
            
            # Prepara y envía la respuesta al cliente
            response = bytes("{}: {}".format(cur_thread.name, data), 'ascii')
            conn.sendall(response)  # Envía toda la respuesta al cliente

    except Exception as e:
        print(e)  # Imprime cualquier error ocurrido durante la comunicación
    
    finally:
        # Cierra el socket al terminar, liberando el recurso de conexión
        conn.close()  # *** BAJA DE CONEXIÓN ***
        # Con esto, el socket se cierra correctamente y se libera el recurso

# Lista global para almacenar las conexiones activas
listaConexiones = []

# Lee los argumentos de línea de comandos: host, puerto y número máximo de conexiones
host, port, numConn = sys.argv[1:4]

if len(sys.argv) != 4:
    print("usage:", sys.argv[0], "<host> <port> <num_connections>")
    sys.exit(1)  # Sale si los argumentos son incorrectos

# Define la dirección del servidor (host y puerto)
serveraddr = (host, int(port))

# Crea y configura el socket del servidor TCP
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as TCPServerSocket:
    # Permite reutilizar la dirección del socket si el servidor se reinicia rápidamente
    TCPServerSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    # Asocia el socket a la dirección y puerto especificados
    TCPServerSocket.bind(serveraddr)

    # Establece el modo de escucha del servidor con el número máximo de conexiones permitidas
    TCPServerSocket.listen(int(numConn))
    print("El servidor TCP está disponible y en espera de solicitudes")

    # Inicia el bucle principal del servidor para aceptar conexiones
    servirPorSiempre(TCPServerSocket, listaConexiones)
