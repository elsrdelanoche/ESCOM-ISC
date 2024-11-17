import selectors
import socket

HOST = '192.168.1.72'
PORT = 12345

sel = selectors.DefaultSelector()

def accept(sock, mask):
    conn, addr = sock.accept()  # Aceptar una nueva conexión
    print(f'Conexión aceptada desde {addr}')
    conn.setblocking(False)
    sel.register(conn, selectors.EVENT_READ, read)

def read(conn, mask):
    data = conn.recv(1024)  # Leer hasta 1024 bytes
    if data:
        print(f'Recibido: {data} de {conn.getpeername()}')
        # Enviar el eco de vuelta al cliente
        conn.sendall(b'Eco: ' + data)
    else:
        print('Cerrando la conexión con', conn.getpeername())
        sel.unregister(conn)
        conn.close()

# Configurar el socket del servidor
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind((HOST, PORT))
sock.listen(100)
sock.setblocking(False)
sel.register(sock, selectors.EVENT_READ, accept)

print(f'Servidor iniciado en {HOST}:{PORT}')

# Bucle principal del servidor
while True:
    events = sel.select()
    for key, mask in events:
        callback = key.data
        callback(key.fileobj, mask)
