### 1. **socket()**
   - **Descripción**: Crea un nuevo objeto socket.
   - **Sintaxis**: `socket.socket(family, type)`
     - **family**: Define el tipo de red (AF_INET para IPv4, AF_INET6 para IPv6).
     - **type**: Define el tipo de socket (SOCK_STREAM para TCP, SOCK_DGRAM para UDP).

### 2. **bind()**
   - **Descripción**: Asocia un socket a una dirección y puerto en el servidor.
   - **Sintaxis**: `socket.bind(address)`
     - **address**: Es una tupla que contiene la dirección IP y el puerto.

### 3. **listen()**
   - **Descripción**: Coloca el socket en modo de escucha, esperando conexiones entrantes.
   - **Sintaxis**: `socket.listen(backlog)`
     - **backlog**: Especifica el número de conexiones que pueden estar en espera (por defecto suele ser 5).

### 4. **accept()**
   - **Descripción**: Acepta una conexión entrante.
   - **Sintaxis**: `socket.accept()`
     - **Devuelve**: Una nueva tupla con un socket para la conexión y la dirección del cliente.

### 5. **connect()**
   - **Descripción**: Establece una conexión con un servidor remoto.
   - **Sintaxis**: `socket.connect(address)`
     - **address**: Dirección IP y puerto del servidor al que deseas conectarte.

### 6. **send()**
   - **Descripción**: Envía datos a través del socket.
   - **Sintaxis**: `socket.send(data)`
     - **data**: Los datos que quieres enviar, deben estar en formato de bytes.

### 7. **sendall()**
   - **Descripción**: Envía todos los datos de forma confiable. Continúa enviando hasta que todos los datos han sido transmitidos.
   - **Sintaxis**: `socket.sendall(data)`
     - **data**: Los datos en formato de bytes.

### 8. **recv()**
   - **Descripción**: Recibe datos del socket.
   - **Sintaxis**: `socket.recv(bufsize)`
     - **bufsize**: La cantidad máxima de bytes que esperas recibir.

### 9. **close()**
   - **Descripción**: Cierra el socket.
   - **Sintaxis**: `socket.close()`

### 10. **setsockopt()**
   - **Descripción**: Establece opciones del socket.
   - **Sintaxis**: `socket.setsockopt(level, optname, value)`
     - **level**: Nivel de protocolo (generalmente SOL_SOCKET).
     - **optname**: Nombre de la opción (como SO_REUSEADDR).
     - **value**: Valor de la opción.

### 11. **gethostname()**
   - **Descripción**: Obtiene el nombre del host actual.
   - **Sintaxis**: `socket.gethostname()`

### 12. **gethostbyname()**
   - **Descripción**: Obtiene la dirección IP correspondiente a un nombre de host.
   - **Sintaxis**: `socket.gethostbyname(hostname)`
     - **hostname**: El nombre del host.

### 13. **getpeername()**
   - **Descripción**: Obtiene la dirección del otro extremo (peer) del socket conectado.
   - **Sintaxis**: `socket.getpeername()`

### 14. **shutdown()**
   - **Descripción**: Desactiva envíos y/o recepciones de datos en un socket.
   - **Sintaxis**: `socket.shutdown(how)`
     - **how**: Puede ser `SHUT_RD`, `SHUT_WR` o `SHUT_RDWR` para desactivar recepción, envío, o ambos.

### 15. **socketpair()**
   - **Descripción**: Crea un par de sockets conectados entre sí.
   - **Sintaxis**: `socket.socketpair()`
     - **Devuelve**: Dos objetos socket conectados.