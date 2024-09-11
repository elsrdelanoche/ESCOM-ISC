# 27/08/2024

- Se va a usar el cómputo en la nube (para maquinas virtuales, servidores)
- Se verá la nube de Azure
- Se programará en Java, HTML-Javascript, C#
- Se usaran IAs
- Se jugara Kahoots

## Evaluació Parcial
- Tareas 70%
- Examen 20% (Opción multiple)
- Participación en clase 10%
- Puntos extra
Asistencias

---
## 28/08/2024
![[SistDist2024-08-28 18.39.48.excalidraw]]

---
# 3 de Septiembre 2024

Lectura clase del día
![[SistDist2024-09-03 18.41.41.excalidraw]]

---
# 4 de Septiembre 2024
![[SistDist2024-09-04 18.41.07.excalidraw]]

---
# Falta

---

# 10 de Septiembre 2024

## ¿Qué es un servidor HTTP?
Recibe peticiones HTTP a través de una conexión TCP, donde cada hilo se encarga de recibir la petición y enviar la respuesta al cliente
Puertos (80,8080)
Métodos más comunes( GET, POST, PUT, DELETE, HEAD)
- Get: Solicita un recurso al servidor HTTP, 200(ok), tipo de recurso(tipo mime), longitud del recurso y contenido, si no existe 404(NotFound)
Servidor web -> Servidor de archivos
Servidor de aplicaciones -> Ejecuta código

CR-> Carriage return
LF-> Line feed

Se tomará el servidor multi thread para crear el servidor

No se usara DataInputStream() y DataOutputStream(), sino las instancias BufferedReader y PrintWriteer creadas

Ahora vamos a recibir petición mediante el metodo readLine()

http://localhost/hola ->get_/hola_HTTP/1.1CRLF


404
if, else
## Encabezado LastModified
Cache en el navegador, guarda contenidos que nos se modifican con frecuencia
El encabezado le dice al navegador la fecha de ultima modificación

El servidor obtiene esos datos mediante el metadata de los archivos

Compara la nueva fecha y la anterior, al ser iguales regresa un 304 NotModified


## Encabezado Cache control
- Public: Cualquier usuario puede tener acceso
- Private: Solo el usuario tiene acceso al contenido
- no-store: El contenido no debe almacenarse
- no-cache:default, solo se guarda el contenido con el encabezado LastModified
- max-age=tiempo, indica el tiempo en segundo que guardara el contenido
- inmutable: indica que el contenido no será modificado nunca por el servidor

## Content Disposition
No muestra el archivo, sino lo descarga

## ¿Cómo obtener la IP del cliente?
getRemoteSocketAddress()
Se usa para llevar una bitacora


*Ejecución programa servidorHTTP*

