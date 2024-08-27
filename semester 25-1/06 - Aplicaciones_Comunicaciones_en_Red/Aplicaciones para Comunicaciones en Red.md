# Unidad I: 
## Sockets Bloqueantes

Esta unidad se centra en el uso de **sockets bloqueantes** en las aplicaciones de comunicación en red. Los sockets son un punto final de la comunicación entre dos máquinas y se utilizan para enviar y recibir datos a través de redes, como Internet. En esta unidad, aprenderemos sobre los conceptos fundamentales relacionados con los sockets y cómo se utilizan para crear aplicaciones cliente-servidor en red.


### 1.1 Servicios definidos en la capa de transporte

La **capa de transporte** es la cuarta capa en el modelo OSI y es responsable de proporcionar servicios de comunicación directa entre dispositivos. Los servicios principales de esta capa incluyen:
- **Segmentación y reensamblaje**: Divide los datos en segmentos y los reensambla en el destino.
- **Control de flujo**: Gestiona la cantidad de datos que se envían para evitar la congestión de la red.
- **Corrección de errores**: Detecta y corrige errores durante la transmisión de datos.
- **Establecimiento y terminación de la conexión**: Crea y cierra conexiones entre dispositivos.

Los protocolos más comunes en la capa de transporte son **TCP (Transmission Control Protocol)** y **UDP (User Datagram Protocol)**.


### 1.2 Modelo cliente-servidor

El **modelo cliente-servidor** es una arquitectura de red en la que un servidor proporciona recursos o servicios, y un cliente los consume. En esta configuración:
- **Servidor**: Es un programa que espera y responde a las solicitudes de los clientes. El servidor escucha en un puerto específico y se prepara para aceptar conexiones entrantes.
- **Cliente**: Es un programa que se conecta al servidor para solicitar servicios o recursos. El cliente inicia la comunicación enviando una solicitud al servidor.

**Ejemplo**: Un navegador web (cliente) solicita una página web a un servidor web. El servidor web procesa la solicitud y envía la página web de vuelta al navegador.


### 1.3 Conexiones en el dominio de internet

Las **conexiones en el dominio de internet** se refieren a las conexiones que se establecen utilizando protocolos de la capa de transporte como TCP y UDP, que son fundamentales para las comunicaciones en red.

#### 1.3.1 TCP (Transmission Control Protocol)

**TCP** es un protocolo orientado a la conexión que proporciona una comunicación confiable y ordenada entre dispositivos. Utiliza un proceso de tres vías para establecer una conexión antes de que comience la transmisión de datos:
1. **SYN**: El cliente envía un segmento SYN (Synchronize) al servidor para iniciar la conexión.
2. **SYN-ACK**: El servidor responde con un segmento SYN-ACK (Synchronize-Acknowledge) para aceptar la conexión.
3. **ACK**: El cliente envía un segmento ACK (Acknowledge) para confirmar la recepción del SYN-ACK y completar el establecimiento de la conexión.

TCP garantiza la entrega de datos en el orden correcto y detecta cualquier pérdida de datos, solicitando retransmisiones si es necesario.

**Aplicación**: TCP se utiliza en aplicaciones que requieren transmisión de datos confiable, como correos electrónicos, transferencia de archivos (FTP), y navegación web (HTTP).

#### 1.3.2 UDP (User Datagram Protocol)

**UDP** es un protocolo no orientado a la conexión que envía datos en forma de datagramas sin asegurarse de que lleguen en orden o sin errores. A diferencia de TCP, no hay un establecimiento de conexión formal, lo que lo hace más rápido pero menos confiable.

**Aplicación**: UDP es ideal para aplicaciones donde la velocidad es más importante que la fiabilidad, como en transmisiones de video en vivo, juegos en línea, y servicios de DNS.


### 1.4 Sockets orientados a conexión bloqueantes

Los **sockets orientados a conexión bloqueantes** son una forma de comunicación basada en TCP donde el socket bloquea el proceso hasta que una operación específica (como la recepción de datos) se completa. Esto significa que el programa se detendrá y esperará a que los datos sean enviados o recibidos antes de continuar.

**Ejemplo**: En una aplicación de chat, el socket del servidor esperará bloqueado hasta que reciba un mensaje de un cliente. Una vez recibido, el socket puede procesar el mensaje y responder.

**Ventajas**:
- Sencillo de implementar y comprender.
- Asegura que los datos se transmitan completamente antes de proceder.

**Desventajas**:
- Puede causar ineficiencias, ya que el programa se bloquea mientras espera, sin poder realizar otras tareas.


### 1.5 Serialización

**Serialización** es el proceso de convertir un objeto en un formato que puede ser fácilmente almacenado o transmitido a través de una red. La **deserialización** es el proceso inverso, que convierte los datos serializados de vuelta en un objeto.

**Aplicación**: En aplicaciones cliente-servidor, la serialización permite que los datos complejos (como estructuras de datos o objetos) se transmitan a través de la red en un formato estándar (como JSON, XML, o binario) y luego se reconstruyan en el extremo receptor.

**Ejemplo**: Un cliente envía un objeto de datos a un servidor en formato JSON. El servidor deserializa el JSON para obtener el objeto original y procesa la información.


### 1.6 Sockets no orientados a conexión bloqueantes

Los **sockets no orientados a conexión bloqueantes** se utilizan con UDP y permiten la comunicación sin la necesidad de establecer una conexión persistente. En un socket no bloqueante, las operaciones de envío o recepción se realizan inmediatamente, incluso si no pueden completarse en ese momento, permitiendo al programa continuar ejecutándose sin esperar.

**Ejemplo**: En una aplicación de streaming de video en vivo, un socket no orientado a conexión bloqueante puede enviar paquetes de video a medida que están disponibles, sin esperar a que se confirme la recepción de cada paquete.

**Ventajas**:
- Bajo retraso, ya que no espera confirmaciones o conexiones.
- Utiliza menos recursos, adecuado para aplicaciones en tiempo real.

**Desventajas**:
- No garantiza la entrega de datos o su orden correcto.
- No detecta errores o pérdidas de datos automáticamente.

---

# Unidad II: 
## Arquitectura Multihilos para Servidores

En esta unidad se exploran los conceptos y técnicas de programación multihilos, específicamente en el contexto de servidores. La programación multihilos permite que un programa ejecute múltiples tareas concurrentemente, mejorando así la eficiencia y la capacidad de respuesta de aplicaciones que requieren realizar varias operaciones al mismo tiempo, como los servidores web o de aplicaciones.


### 2.1 Sincronía de hilos

La **sincronía de hilos** es fundamental en la programación multihilos para asegurar que los recursos compartidos no sean accedidos simultáneamente por múltiples hilos de una manera que podría causar conflictos o resultados inesperados.

#### 2.1.1 Instrucciones atómicas

Las **instrucciones atómicas** son operaciones que se ejecutan completamente de una sola vez sin posibilidad de ser interrumpidas. Esto significa que cuando una instrucción atómica está en proceso, ningún otro hilo puede ver un estado intermedio, lo que ayuda a prevenir condiciones de carrera.

**Ejemplo**: En muchos sistemas, la operación `incrementar contador` puede no ser atómica. Si dos hilos intentan incrementar el mismo contador simultáneamente, podría resultar en un incremento incorrecto. Sin embargo, una instrucción atómica asegura que la operación completa (leer, incrementar y escribir) se realice como un solo paso no divisible.


#### 2.1.2 Sección crítica

Una **sección crítica** es una parte del código que accede a un recurso compartido que no puede ser ejecutado por más de un hilo al mismo tiempo. Para evitar conflictos, se necesita un mecanismo de sincronización que asegure que solo un hilo pueda ejecutar la sección crítica a la vez.

**Ejemplo**: Si varios hilos necesitan escribir en un archivo compartido, el código que realiza la escritura debe estar en una sección crítica para evitar que los hilos sobrescriban la información de los demás.


#### 2.1.3 Candados (Locks)

Los **candados** o **locks** son mecanismos de sincronización que permiten a los hilos obtener acceso exclusivo a un recurso compartido. Solo un hilo puede tener el candado a la vez, lo que garantiza que solo ese hilo puede ejecutar la sección crítica protegida por el candado.

**Aplicación**: En un servidor de base de datos multihilos, se pueden usar candados para controlar el acceso a los registros de datos, asegurando que solo un hilo pueda modificar un registro a la vez.


#### 2.1.4 Exclusión mutua (Mutex)

La **exclusión mutua** o **mutex** es un tipo de candado que asegura que solo un hilo pueda ejecutar una sección crítica o acceder a un recurso compartido a la vez. Los mutex son ampliamente utilizados para proteger secciones críticas y evitar condiciones de carrera.

**Ejemplo**: Un servidor de impresión multihilos puede usar mutexes para gestionar la cola de impresión, asegurando que solo un hilo pueda agregar o quitar trabajos de la cola al mismo tiempo.


#### 2.1.5 Semáforos

Los **semáforos** son variables que se utilizan para controlar el acceso a un recurso compartido. A diferencia de los mutexes, los semáforos pueden permitir que un número fijo de hilos accedan a la sección crítica al mismo tiempo, lo que es útil para limitar el número de recursos disponibles, como conexiones de base de datos o instancias de servicio.

**Aplicación**: En un servidor web multihilos, se pueden usar semáforos para limitar el número de conexiones simultáneas que el servidor puede manejar, evitando sobrecargas.


#### 2.1.6 Pools de hilos

Los **pools de hilos** son colecciones de hilos que están disponibles para ejecutar tareas. En lugar de crear y destruir un hilo para cada tarea, los pools de hilos permiten que los hilos se reutilicen, mejorando la eficiencia del servidor al reducir el coste de crear y destruir hilos frecuentemente.

**Aplicación**: En un servidor de aplicaciones, un pool de hilos puede ser utilizado para manejar solicitudes de clientes de manera eficiente, asignando hilos disponibles a las tareas entrantes sin necesidad de crear nuevos hilos para cada solicitud.


### 2.2 Multihilos

El **multihilos** es una técnica de programación en la que múltiples hilos de ejecución se ejecutan concurrentemente dentro de un programa. Los hilos permiten que diferentes partes de un programa se ejecuten simultáneamente, lo que es especialmente útil para mejorar el rendimiento en servidores que manejan múltiples solicitudes al mismo tiempo.

**Aplicación**: En un servidor HTTP multihilos, cada solicitud de cliente puede ser manejada por un hilo separado, permitiendo que múltiples solicitudes se procesen simultáneamente, mejorando la capacidad de respuesta del servidor.

**Ejemplo**: En un juego en línea, el servidor puede utilizar hilos para manejar las conexiones de los jugadores, la sincronización del estado del juego, y las interacciones en tiempo real, todo simultáneamente.


### 2.3 Formatos de intercambio de datos

Los **formatos de intercambio de datos** son estructuras o protocolos utilizados para enviar y recibir datos entre sistemas o aplicaciones de manera estándar. Estos formatos aseguran que los datos sean interpretados correctamente por diferentes sistemas, independientemente de su arquitectura o lenguaje de programación.

**Ejemplos de formatos**:
- **JSON (JavaScript Object Notation)**: Un formato de datos ligero y fácil de leer que es ampliamente utilizado para la comunicación entre servidores y aplicaciones web.
- **XML (eXtensible Markup Language)**: Un formato de datos flexible que es útil para representar estructuras de datos complejas y es común en servicios web SOAP.
- **Protobuf (Protocol Buffers)**: Un formato de serialización de datos eficiente desarrollado por Google que es utilizado para comunicación rápida y compacta entre servicios.

**Aplicación**: En un servidor RESTful multihilos, los datos entre el cliente y el servidor a menudo se intercambian en formato JSON, permitiendo que diferentes sistemas interactúen de manera eficiente y comprensible.

---

### Unidad III: Sockets No Bloqueantes

En esta unidad se exploran los conceptos y técnicas relacionados con los **sockets no bloqueantes** y su uso en aplicaciones de red. Los sockets no bloqueantes permiten que una aplicación continúe ejecutándose mientras espera a que se completen las operaciones de red, mejorando así la eficiencia y capacidad de respuesta de las aplicaciones que necesitan manejar múltiples conexiones o tareas simultáneamente.

---

### 3.1 Sockets orientados a conexión no bloqueantes

Los **sockets orientados a conexión no bloqueantes** se utilizan para conexiones que requieren un enlace persistente entre dos extremos, como en el caso del protocolo TCP. En el modo no bloqueante, las operaciones de entrada y salida en el socket, como enviar y recibir datos, no detienen la ejecución del programa mientras esperan que se completen, lo que permite manejar múltiples conexiones de manera eficiente.

**Aplicación**: Un servidor web de alta concurrencia puede utilizar sockets TCP no bloqueantes para manejar miles de conexiones de clientes simultáneamente. Esto es especialmente útil para aplicaciones en tiempo real, como los juegos en línea y los sistemas de chat, donde la capacidad de respuesta es crítica.

---

### 3.2 Sockets no orientados a conexión bloqueantes

Los **sockets no orientados a conexión bloqueantes**, típicamente utilizados con el protocolo UDP, permiten enviar y recibir datagramas sin establecer una conexión persistente. Aunque el término "bloqueantes" indica que las operaciones de red pueden bloquear el hilo de ejecución, en el contexto de esta unidad, se está contrastando con los sockets no bloqueantes orientados a conexión.

**Ejemplo**: Un servidor DNS utiliza sockets UDP para recibir y responder a consultas. Aunque las operaciones son bloqueantes, cada consulta es independiente, lo que permite al servidor manejar múltiples consultas de manera rápida y eficiente.

---

### 3.3 Multidifusión

La **multidifusión** es una técnica utilizada para enviar un único paquete de datos a múltiples destinos simultáneamente. Esto es especialmente útil en aplicaciones donde el mismo dato necesita ser enviado a varios receptores, como en conferencias de video, transmisiones de radio por internet o actualizaciones en tiempo real para juegos multijugador.

#### 3.3.1 Datagramas de multidifusión

Los **datagramas de multidifusión** permiten enviar un solo paquete de datos a múltiples destinatarios en una red que estén suscritos a un grupo de multidifusión específico. Esto es más eficiente que enviar paquetes separados a cada destinatario, reduciendo la carga de red y el procesamiento en el servidor.

**Aplicación**: En un sistema de transmisión de video en vivo, los datagramas de multidifusión se utilizan para enviar el flujo de video a múltiples espectadores al mismo tiempo, asegurando que todos reciban los mismos datos simultáneamente sin duplicar el tráfico en la red.

---

#### 3.3.2 Resolución de direcciones de multidifusión lógicas a físicas

La **resolución de direcciones de multidifusión lógicas a físicas** es el proceso mediante el cual las direcciones IP de multidifusión se convierten en direcciones MAC para ser transmitidas a través de una red Ethernet. Este proceso permite que los dispositivos de red, como los switches, manejen correctamente los paquetes de multidifusión y los dirijan a los destinos apropiados.

**Ejemplo**: Un router que soporta multidifusión traduce las direcciones IP de un flujo de video en vivo a direcciones MAC de multidifusión, lo que permite a los conmutadores de red reenviar los paquetes solo a los puertos que tienen dispositivos interesados en ese flujo.

---

#### 3.3.3 Protocolo IGMP (Internet Group Management Protocol)

El **Protocolo IGMP** es un protocolo de red utilizado para gestionar las membresías de los dispositivos en los grupos de multidifusión. IGMP permite a los routers y switches en una red conocer qué dispositivos desean recibir tráfico de multidifusión, optimizando así la transmisión de datos y evitando el envío innecesario de paquetes a dispositivos que no están interesados.

**Aplicación**: En un entorno de red corporativa, IGMP permite que los switches gestionen eficientemente el tráfico de multidifusión para aplicaciones de video conferencia, asegurando que solo los dispositivos que participan en la conferencia reciban el flujo de video.

---

### 3.4 Sockets de multidifusión

Los **sockets de multidifusión** son sockets utilizados para enviar y recibir datagramas de multidifusión. A diferencia de los sockets de unicast, que envían datos a un solo destinatario, los sockets de multidifusión permiten a una aplicación enviar datos a todos los miembros de un grupo de multidifusión o recibir datos de dicho grupo.

**Ejemplo**: En una red de noticias, un servidor puede utilizar sockets de multidifusión para transmitir actualizaciones de noticias a todos los dispositivos suscritos a un grupo de noticias específico, permitiendo una difusión eficiente y rápida de la información.

**Implementación**: Para configurar un socket de multidifusión, el desarrollador debe especificar la dirección del grupo de multidifusión y la interfaz de red adecuada. Los sockets también pueden ser configurados para utilizar IGMP y gestionar dinámicamente la membresía del grupo de multidifusión.

---

### Unidad IV: Protocolos de la Capa de Aplicación

En esta unidad se examinan los **protocolos de la capa de aplicación**, que son los encargados de proporcionar los servicios de red directamente a las aplicaciones del usuario. Estos protocolos definen cómo las aplicaciones en diferentes dispositivos se comunican a través de una red.


### 4.1 Aplicaciones No Orientadas a Conexión

Los **protocolos no orientados a conexión** operan sin establecer una conexión previa entre el emisor y el receptor. Estos protocolos envían datos de manera independiente y sin asegurarse de que lleguen a su destino de forma ordenada.

#### 4.1.1 Protocolo FTP (File Transfer Protocol)

El **Protocolo FTP** permite la transferencia de archivos entre sistemas de manera eficiente y segura. Aunque FTP puede operar en modo no orientado a conexión para ciertos comandos, principalmente funciona en modo orientado a conexión (ver 4.2.1), estableciendo una conexión persistente entre el cliente y el servidor.

**Aplicación**: FTP se utiliza comúnmente para cargar y descargar archivos en servidores web y servidores de archivos, permitiendo a los usuarios gestionar sus datos de forma remota.

#### 4.1.2 Protocolo DNS (Domain Name System)

El **Protocolo DNS** es esencial para la navegación en internet, ya que traduce los nombres de dominio legibles por humanos (como www.example.com) en direcciones IP que los dispositivos de red pueden utilizar para enrutar la información.

**Ejemplo**: Cuando un usuario ingresa una URL en su navegador, el DNS traduce esa URL en la dirección IP del servidor donde se aloja el sitio web, facilitando la conexión.

#### 4.1.3 Protocolo DHCP (Dynamic Host Configuration Protocol)

El **Protocolo DHCP** permite la asignación dinámica de direcciones IP a dispositivos en una red, simplificando la configuración de la red y asegurando que no haya conflictos de direcciones IP.

**Aplicación**: DHCP es utilizado por routers y servidores en redes domésticas y corporativas para asignar automáticamente direcciones IP a dispositivos como computadoras, teléfonos y tablets cuando se conectan a la red.

#### 4.1.4 Protocolo NFS (Network File System)

El **Protocolo NFS** permite a los sistemas de archivo acceder a archivos a través de una red como si estuvieran en su propio sistema local. Es especialmente útil en entornos UNIX y Linux.

**Ejemplo**: En una empresa, NFS se utiliza para permitir que múltiples usuarios accedan a los mismos archivos y directorios en un servidor central, facilitando la colaboración y el uso compartido de recursos.


### 4.2 Aplicaciones Orientadas a Conexión

Los **protocolos orientados a conexión** requieren establecer una conexión antes de que se transmita cualquier dato. Esta conexión asegura que los datos sean entregados en el orden correcto y proporciona mecanismos para la retransmisión de datos perdidos.

#### 4.2.1 Protocolo FTP (File Transfer Protocol)

En su modo principal, **FTP** es un protocolo orientado a conexión que utiliza TCP para garantizar la entrega confiable de archivos. Se establece una conexión controlada entre el cliente y el servidor para gestionar la transferencia de archivos y comandos.

**Aplicación**: FTP es ampliamente utilizado para transferencias de archivos entre servidores, ya que permite la autenticación de usuarios y la transferencia de archivos grandes con fiabilidad.

#### 4.2.2 Protocolo Telnet

**Telnet** es un protocolo que permite a los usuarios conectarse de forma remota a otro dispositivo en la red, proporcionando un terminal virtual para ejecutar comandos en ese dispositivo.

**Ejemplo**: Administradores de sistemas utilizan Telnet para acceder remotamente a servidores y dispositivos de red para realizar configuraciones y mantenimiento, aunque su uso ha disminuido debido a la falta de seguridad (es reemplazado por SSH).

#### 4.2.3 Protocolo HTTP (Hypertext Transfer Protocol)

El **Protocolo HTTP** es la base de la comunicación en la World Wide Web. Es un protocolo orientado a conexión que utiliza TCP para la transferencia de documentos HTML y otros recursos en la web.

**Aplicación**: HTTP es utilizado por navegadores web para cargar páginas web desde servidores. También es la base de muchas API web utilizadas en aplicaciones modernas.

#### 4.2.4 Protocolo SMTP (Simple Mail Transfer Protocol)

El **Protocolo SMTP** es utilizado para enviar correos electrónicos entre servidores. Es un protocolo orientado a conexión que asegura que los correos sean entregados correctamente.

**Ejemplo**: Los servidores de correo utilizan SMTP para enviar correos desde los clientes de correo (como Outlook o Gmail) a los servidores de destino. Es parte integral del sistema de correo electrónico global.

#### 4.2.5 Protocolo SNMP (Simple Network Management Protocol)

**SNMP** es un protocolo utilizado para la gestión de dispositivos en redes IP. Permite a los administradores de red monitorear y configurar dispositivos como routers, switches y servidores.

**Aplicación**: SNMP se utiliza en sistemas de monitorización de red para recopilar datos sobre el rendimiento de los dispositivos, detectar fallos y automatizar la gestión de red.

---

### Unidad V: Invocación a Métodos Remotos

La **invocación a métodos remotos (RMI)** es una técnica en programación que permite a un programa ejecutar métodos en un objeto ubicado en otro dispositivo o servidor a través de una red. Este mecanismo es esencial en el desarrollo de aplicaciones distribuidas, donde diferentes componentes de una aplicación pueden estar dispersos en diferentes ubicaciones geográficas pero necesitan trabajar juntos como si estuvieran en la misma máquina.


### 5.1 Java RMI (Remote Method Invocation)

**Java RMI** es una API que permite a los desarrolladores de Java realizar invocaciones a métodos en objetos remotos, es decir, ejecutar métodos en objetos que residen en diferentes máquinas dentro de una red. RMI facilita la comunicación y la interacción entre aplicaciones distribuidas.

- **Funcionalidad**: Java RMI permite a los objetos de un programa Java comunicarse con objetos en otro programa Java, incluso si se ejecutan en diferentes JVMs (Java Virtual Machines) en máquinas distintas. Esto es posible gracias a la serialización de objetos y al uso de interfaces remotas que definen los métodos que pueden invocarse remotamente.

- **Aplicación**: Java RMI se utiliza comúnmente en aplicaciones de red de cliente-servidor, como sistemas de comercio electrónico, aplicaciones de banca en línea, y sistemas de control remoto, donde el servidor puede estar en una ubicación diferente al cliente.

### 5.2 Implementación de Skeleton

El **skeleton** es un componente en RMI que actúa como un intermediario entre la llamada del cliente y el objeto remoto en el servidor. En versiones anteriores de Java (hasta Java 2 SDK, v1.2), el skeleton se generaba automáticamente al compilar las interfaces remotas y se encargaba de:

- **Deserializar los parámetros** enviados por el cliente.
- **Llamar al método apropiado** en el objeto remoto.
- **Serializar el resultado** y devolverlo al cliente.

En versiones más recientes de Java, el skeleton ya no es necesario explícitamente ya que la infraestructura de RMI se ha simplificado, utilizando más dinámicamente los proxies.

### 5.3 Implementación de Stub

El **stub** es el proxy en el lado del cliente para el objeto remoto. Es un objeto que representa el objeto remoto en el cliente y proporciona la misma interfaz que el objeto remoto, haciendo posible que el cliente invoque métodos en el objeto remoto como si estuviera local.

- **Funcionalidad**: Cuando un cliente invoca un método en el stub, el stub toma los parámetros de la llamada, los serializa, y los envía a través de la red al servidor. Luego, recibe la respuesta del servidor, la deserializa y devuelve el resultado al cliente.

- **Aplicación**: Los stubs permiten que las aplicaciones distribuidas sean más fáciles de desarrollar y mantener, ya que los desarrolladores pueden invocar métodos remotos de manera transparente, sin preocuparse por los detalles de la red.

### 5.4 RMIRegistry

El **RMIRegistry** es un servicio de registro que actúa como un directorio para objetos remotos en RMI. Proporciona un mecanismo mediante el cual los clientes pueden buscar y obtener referencias a objetos remotos.

- **Funcionalidad**: El RMIRegistry se ejecuta en el servidor y mantiene una lista de nombres de objetos y referencias a sus objetos remotos correspondientes. Cuando un cliente necesita acceder a un objeto remoto, primero se conecta al RMIRegistry, solicita el objeto por su nombre y luego usa la referencia devuelta para invocar métodos en el objeto remoto.

- **Ejemplo**: En una aplicación bancaria distribuida, el RMIRegistry puede contener referencias a diferentes servicios como "Cuenta", "Transacción", y "Cliente". Un cliente de banca en línea podría conectarse al RMIRegistry para obtener una referencia al objeto "Cuenta" y realizar operaciones como consultar saldo o transferir dinero.

---

### Unidad VI: Aplicaciones P2P

La **Unidad VI** explora las aplicaciones basadas en la arquitectura **P2P (Peer to Peer)**, un modelo de red donde cada nodo actúa tanto como cliente como servidor, permitiendo compartir recursos sin la necesidad de un servidor centralizado. Esta arquitectura es conocida por su flexibilidad, escalabilidad y robustez, lo que la hace ideal para varias aplicaciones en la red.


### 6.1 Arquitectura P2P (Peer to Peer)

La **arquitectura P2P** permite a los dispositivos en la red conectarse directamente entre sí, compartiendo recursos como archivos, ancho de banda y potencia de procesamiento. A diferencia de las arquitecturas cliente-servidor tradicionales, P2P elimina la necesidad de un servidor central, lo que permite a cada nodo (o "peer") actuar como cliente y servidor simultáneamente.

#### 6.1.1 Conectividad

**Conectividad** en P2P se refiere a la forma en que los nodos se conectan entre sí. En una red P2P, cada nodo puede establecer conexiones directas con otros nodos, creando una red descentralizada.

- **Tipos de Conexiones**: Pueden ser conexiones directas entre pares o a través de nodos intermedios en redes más complejas. La conectividad robusta es crucial para asegurar que la red sea resistente a fallos y permita la transferencia eficiente de datos.
  
- **Aplicación**: En aplicaciones como BitTorrent, los peers se conectan directamente para compartir fragmentos de archivos entre sí, aumentando la velocidad de descarga y reduciendo la carga en cualquier servidor central.

#### 6.1.2 Enrutamiento de Mensajes

El **enrutamiento de mensajes** es el proceso de determinar la ruta más eficiente para enviar datos de un nodo a otro en una red P2P. 

- **Métodos de Enrutamiento**: Incluyen el enrutamiento basado en la tabla hash distribuida (DHT) para buscar rápidamente nodos y recursos, o el enrutamiento basado en supernodos, donde ciertos nodos asumen más responsabilidades de enrutamiento debido a sus mayores capacidades.

- **Ejemplo**: En aplicaciones de intercambio de archivos como eMule o Gnutella, el enrutamiento de mensajes es crucial para localizar y acceder a los archivos compartidos en la red.

#### 6.1.3 Búsquedas

La **búsqueda** en redes P2P es el proceso de localizar recursos o nodos específicos sin un índice centralizado. Este proceso puede ser complejo debido a la naturaleza distribuida de la red.

- **Tipos de Búsquedas**: Pueden ser búsquedas de inundación, donde una solicitud se envía a todos los nodos hasta que se encuentra el recurso, o búsquedas basadas en DHT, donde la búsqueda se realiza utilizando un algoritmo eficiente que mapea recursos a nodos específicos.

- **Aplicación**: Protocolos como Kademlia y Chord utilizan tablas hash distribuidas para realizar búsquedas eficientes, permitiendo a los usuarios encontrar recursos rápidamente sin necesidad de servidores centralizados.

#### 6.1.4 Seguridad

La **seguridad** en redes P2P es un desafío debido a la falta de un punto de control centralizado. Los sistemas deben implementar medidas de seguridad para proteger la integridad de los datos, la privacidad de los usuarios y la autenticidad de las comunicaciones.

- **Mecanismos de Seguridad**: Incluyen la autenticación de nodos, cifrado de datos, y el uso de firmas digitales para verificar la autenticidad de los recursos compartidos.

- **Ejemplo**: BitTorrent utiliza cifrado para proteger las comunicaciones y prevenir la interferencia de terceros, mientras que las aplicaciones descentralizadas como las criptomonedas implementan técnicas avanzadas de criptografía para asegurar las transacciones.


### 6.2 Aplicaciones P2P

Las **aplicaciones P2P** aprovechan la arquitectura distribuida para ofrecer servicios eficientes y escalables sin depender de un servidor central. Estas aplicaciones son especialmente útiles en escenarios donde se requiere alta disponibilidad y resistencia a fallos.

#### 6.2.1 Intercambio y Búsqueda de Archivos

El **intercambio de archivos P2P** permite a los usuarios compartir y buscar archivos directamente entre sus dispositivos, eliminando la necesidad de un servidor central.

- **Ejemplo**: BitTorrent es una de las aplicaciones P2P más conocidas para el intercambio de archivos. Permite a los usuarios descargar y compartir archivos grandes de manera eficiente al dividirlos en fragmentos y descargar estos fragmentos desde múltiples nodos simultáneamente.

- **Aplicación**: Las aplicaciones P2P de intercambio de archivos se utilizan ampliamente para compartir contenido multimedia, software, y documentos, especialmente cuando se necesita distribuir grandes volúmenes de datos a muchos usuarios.

#### 6.2.2 Sistemas de Archivos Distribuidos

Los **sistemas de archivos distribuidos P2P** permiten a los usuarios almacenar y acceder a archivos en una red de nodos distribuidos, proporcionando redundancia y accesibilidad global.

- **Ejemplo**: InterPlanetary File System (IPFS) es un protocolo y red P2P para almacenar y compartir datos en un sistema de archivos distribuido. A diferencia de los sistemas de archivos tradicionales, IPFS utiliza direcciones basadas en el contenido, lo que permite un almacenamiento más eficiente y una entrega más rápida de datos.

- **Aplicación**: Estos sistemas son utilizados en aplicaciones que requieren almacenamiento seguro, distribuido y accesible globalmente, como plataformas de almacenamiento en la nube descentralizadas y redes de contenido distribuidas.


### 6.3 Sistema de Telefonía a Través de P2P

Los **sistemas de telefonía P2P** utilizan la arquitectura P2P para permitir la comunicación de voz y video directamente entre usuarios sin la necesidad de servidores centrales.

- **Ejemplo**: Skype fue uno de los primeros servicios en popularizar la telefonía P2P, permitiendo llamadas de voz y video a través de internet sin necesidad de infraestructura de telecomunicaciones tradicional.

- **Aplicación**: Estos sistemas son utilizados para proporcionar servicios de comunicación de bajo costo y alta disponibilidad, especialmente en áreas donde la infraestructura tradicional es limitada o costosa. Además, al evitar servidores centrales, se reduce el riesgo de puntos únicos de fallo y se mejora la privacidad.
