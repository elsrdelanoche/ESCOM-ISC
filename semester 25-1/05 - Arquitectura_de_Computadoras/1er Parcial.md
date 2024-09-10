# 26 de Agosto de 2024

Grupo en Facebook: ARQUI 5CV3 (1214) 25-1

## Evaluación

Prácticas = 7. Se realizan de 8 a 11 prácticas por semestre.
Examen = 3. Se realizan de 1 a 3 por semestre según lo requiera el grupo.

1. Se trabaja en EQUIPOS: Individual, en parejas o de 3 alumnos máximo.
2. Cada equipo creará una carpeta en algún medio remoto y me la compartirá ASIGNANDO PERMISOS DE LECTURA Y ESCRITURA para anotar observaciones y calificaciones según sea el caso.
3. Deberás subir a la carpeta anterior POR CADA PRÁCTICA, un informe en formato abierto de lo que se hizo. Puede ser un documento o el __video__ de funcionamiento de tu práctica. Incluye datos de los alumnos, objetivos, diagramas electrónicos, diagramas de flujo, y fotos del circuito como evidencia.
4. La evaluación de prácticas y examen es de forma oral. Si algún alumno no contesta lo que se le pregunta, implica la disminución de su calificación individual; es decir que no afecta la calificación de los demás integrantes del equipo.

Herramienta para el curso de MICROCONTROLADORES Y SISTEMAS EN CHIP:
Microcontrolador: POR DEFINIR
Programador: POR DEFINIR
IDE: POR DEFINIR
Lenguaje de programación que se estudiarán en el curso: POR DEFINIR.  

Herramienta para el curso de DISEÑO DIGITAL
GAL 22V10 o el FPGA de su preferencia

Lenguaje de descripción de Hardware válidos: VHDL y verilog
IDE: GALAXY, Eda Playground [https://www.edaplayground.com/loginpage](https://www.edaplayground.com/loginpage)

Herramienta para el curso de ARQUITECTURA DE COMPUTADORAS
IDE: MPLABX, ARDUINO
LENGUAJES: Ensamblador de 16 bits y C.
Simulador: Proteus, Wokwi

### Evaluación acordada


Lunes/LAB   Martes   Jueves
Se puede revisar la practica incluso martes o jueves, Lunes ya es otra practica



---
# [[27/08/2024]]

Arquitectura: composición de un microprocesador 
 
![[Arqui2024-08-27 16.50.18.excalidraw]]
# 02/09/2024

Practica para 9 de septiembre
Kit electronica RDA5807

- Describir el funcionamiento del receptor
- Que funcione

## Arquitectura de computadoras
Se refiere a los atributos de un sistema que son <u>visible</u> a un programador y a la estructura operacional fundamental de un sistema

- Conjunto de instrucciones
- Número de bit usados para representar los tipos de datos
- Mecanismos de E/S (Periféricos)
- Técnicas de direccionamiento de memoria 

### Organización
Se refiere a las unidades funcionales y a sis interconexiones que dan lugar a especificaciones arquitectónicas.
Entre los atributos de organización se incluyen aquellos detalles de <u>hardware</u> que son transparentes hacia el programador.
- Señales de control
- Interfaces entre la computadora y los periféricos
- La tecnología de memoria usada

Org Básica de un sistema de computo
- Unidad Aritmetico - Lógica 
	- Unidad de memoria
	- Unidad de control
	- Unidad de entrada y salida

### Microprocesador
Contiene toda la circuiteria lógica para llevar a cabo las funciones anteriores
- Su logica interna por lo general no es accesible de forma externa
- Se puede controlar lo que sucede en su interior mediante el programa de instrucciones que se puso en su memoria
- Cuando se requiere cambiar su operacio


El microcontrolador contiene al microprocesador

![[Arqui2024-09-02 18.48.07.excalidraw]]

El micro-controlador se dota de extremidades
### Selección de control y sincronización 
Busca y decodifica/Interpreta códigos de instrucciones de la memoria del programa y luego 
Genera señales de sincronización y control como R/W o clock

FETCH AND EXECUTING

### Sección de registro
Contiene varios registros dentro de la MPU que realizan una función especial. 
El más importante es el contador de programa PC

Registros importantes
IR Registro de instrucción a medida de que se codifican
A Acumulador: Retención de datos operados por la ALU
DPTR Apuntador de datos direcciones de datos que son buscados en la memoria
R0 a R7 Almacenamiento general y conteo


Scale of integratión


--- 
# 3 de Septiembre 2024

El micro-controlador se dota de extremidades

## Arquitectura Von Neumann
Tubos al vacio en los 40s
Latch Secuencial (niveles)
FlipFlop Combinacional (Flancos)

Eliminar rebote(Capacitor, pulldown, pasa bajas, 555 monoestable)

Delta: El limite cuando el tiempo tiende a 0

![[Arqui2024-09-03 16.57.58.excalidraw]]

### Memoria Caché
Areas de memoria reservadas usadas para acelerar ejecuciones
tambien llamada CPU Caché, en arque Von Neumann hace un puente entre el disco y el CPU

### Arquitecturas que dependen del tipo de instrucciones
CISC arqu que complementa una tarea en el menor numero de lineas de código ensamblador posible

Mapa de memoria de un microcontrolador DSPIC 30F

Ejemplo CISC multiplicacion
Mult(0x0BFE 0x0FFE )o en lenguaje de alto nivel A=A*B

## Arquitecura RISC
Instrucciones sencillas y ejecutan raído
Basadas en registros de proposito general

### Ejemplo RISC
MOV 0x0BFE W0
MOV 0x0FFE W1
MUL W0 W1
MOV W2 W0

W3:w2


MOV carga y al mismo tiempo ejecuta

----
# 10 Septiembre 2024
![[Pasted image 20240910172424.png]]
![[Pasted image 20240910172608.png]]

![[Pasted image 20240910172332.png]]

![[Pasted image 20240910173224.png]]

![[Pasted image 20240910173555.png]]
Operador directo -> toma la dirección
Operador inmediato -> toma el dato

![[Pasted image 20240910175129.png]]