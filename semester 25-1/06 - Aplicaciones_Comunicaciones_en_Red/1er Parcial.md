# 27/08/2024

Bloc de notas de la clase en el teams

## Evaluación
100% Examen
requisitos para exentar:
1. 100% asistencia
2. Practica en tiempo y forma
3. No plagio

Tecnologías
Python 3.8 o +
Pycharm 2024.2 (community ed)
Github
VirtualBox 7.0

3 Sept Practica 1, pa exentar

---
# 3 de Septiembre 2024
Clase exposición de la investigación por equipos

# 5 de Septiembre
## Aplicacion de red: 
coleccion de conjuntos y servicios en la instalación, convocados por el usuario, usando como intermediario una aplicación para consumir un servicio o una instalación de red.
Estas aplicaciones ofrecen un servicio especifico, al ofrecer un servicio lo convierte en nodo Servidor

## Aplicaciones en red y programación en red

Un programador que comprende los mecanismos y tecnologias de red subyacentes puede escribir aplicaciones de red confiables

## Modelo cliente servidor

| Server APP | Client app!

## Programación de red y la API de sockets
La interfaz que utiliza una aplicación para especificar la comunicación
Para ello usaremos la API de Sockets Ouyeah

## Funciones en la API
#Tabla funciones
#DiagramaSecuencia


# 10 de Septiembre 2024

Apuntes Freddy

## Servicios de transporte disponibles para las aplicaciones

1. **Fiabilidad en la transferencia de datos:** Importancia en garantizar la entrega correcta de los datos
2. **Tasa de transferencia:** Garantías de tasa de transferencia para aplicaciones sensibles al ancho de banda.
3. **Temporización:** Garantías de tiempos de entrega de datos en aplicaciones en tiempo real

Aqui va el ejercicio que hice en el telefono
---
# 17 de septiembre 2024
## Diapositivas
## Paradigmas de comunicación de internet

Paradigma orientado a Stream
El cliente y el servidor tendran una comunicación bidireccional con cada cliente, usando la conexión TCP

Paradigma orientado a mensajes
El cliente solo envia datos, no existe canal, el servidor usando protocolo IP del mismo paquete, envia una respuesta

![[Redes2_2024-09-17 15.25.17.excalidraw]]

Se agregara un socket a cada cliente 

## Función Socket

el modulo socket en python 3.x



## Objeto Socket
metodos:
- Socket.bind(address) // Asociar a formato de dirección IP
- socket.accept() // Acepta solicitud de conexión


![[Redes2_2024-09-17 15.38.36.excalidraw]]

Cerrar sockets, liberar ram, puede petar!!! usar CLOSE()

## Socket no orientado a conexión

## Funciones de UDP
Diagrama

## Objeto socket
ya no usaremos sen o rec a secas
siempre que enviamos datos hay que especificar el destinatario


Próxima clase: demostración