Docente: Marco Antonio Castillo
# Lunes 2 de Septiembre 2024
## Evaluación
- Practicas y proyectos 40%
- Examen 30%
- Tareas (Apuntes, Ejercicios) 30%

Una entrega por cada parcial (P1,P2,P3), suficiente con que uno entregue
Examen practico, se califica al momento
Documento Tareas (Primero apuntes, después ejercicios) también una entrega por parcial
No copiar, o por lo menos hacerlo bien

## Formato de Practicas
-> Portada
	(Nombre integrantes)
-> Introducción
	(Tema a tratar)
-> Desarrollo
	-> Explicación de lo que se va a realizar
	-> Diagrama de flujo
	-> Código(s)
	-> _Capturas del funcionamiento_ (Más de una, con descripción)
-> Conclusión (No lleva juicios, ni opiniones, No debe ser la descripción de lo que se hizo)
	Busca que se agreguen aprendizajes a partir de los datos técnicos, estadísticas, comparativa de resultados numéricos, % de precisión, % tasas de error, posible comparar con practica pasadas
 *Toda practica debe ser revisada previo a desarrollar la practica*

-- -
# 4 de Septiembre 2024

Inteligencia: Capacidad para aprender, analizar y resolver problemas
Inteligencia Artificial: Dotar a una maquina con la capacidad de aprender, analizar y resolver.

## Areas:
- Machine Learning
	- Aprendizaje de patrones, Mejoramiento de procesos, clasificación de datos
	- Aprendizaje Clásico (Matemáticas) Metodos probabilisticos y estadísticos, Modelos Matematicos, Ecuaciones, Teorias, etc.
- Procesamiento
	- Dotar a las maquinas de generar y/o endender voz o texto
- Visión por computadora
	- Creación de algoritmos para que la maquina distinga profundidad


---
# 5 Septiembre 2024

## Agentes inteligentes
Son sistemas conformados por sensores, actuadores y sistemas de almacenamiento; para lograr un objetivo de forma autónoma.
Ejemplos: 
- Vehículos autónomos

Dichos sistemas suelen basar sus decisiones en la "Percepción" del entorno.
 
### Tipos de agentes inteligentes
- Reactivos: No almacena información del entorno
- Con conocimiento cognitivo: Se basa en la experiencia previa de otros sistemas.
- Basado en la teoría de utilidad: Se descarta lo que no le es útil o favorable al sistema
- Multi-agente: Combinación e interacción de varios agentes


## Sistemas expertos
Emula lo que el experto humano ha adquirido como conocimiento, emulado por un software o un sistema computacional para la toma de decisiones.
Ejemplo:
- Sistemas de descarte de CV's

No aprenden, dado que ya son expertos, no se adaptan a diferentes entornos


notas:
- Sensor: Dispositivo que transforma una variable física en una variable util (ejemplo: eléctrica) 
- Actuadores: Transforman una variable útil a una variable física.

---
# 9 de Septiembre del 2024
## Agente tipo Reflex y Basado en Objetivos

![[IA_2024-09-09 15.11.54.excalidraw]]

Este tipo de agentes son de heurística o Búsqueda de soluciones

Un problema se puede caracterizar por los siguientes 5 elementos
1. Estado inicial (De donde el agente iniciará)
2. Descripción de las posibles acciones que el agente puede tomar
3. Descripción de lo que cada acción provoca (modelo) de transiciones.
4. "Goal test" -> Si hay diferentes formas de cumplir un objetivo, ¿Cual es la forma más simple de llegar a la meta considerando Edo Inicial los estados?
5. Costo de trayectoria

---
#  11 de Septiembre 2024
## Criterios de selección de algoritmos de búsqueda
1) Completitud: Capacidad del algoritmo de ofrecer alguna solucion si existe alguna
2) Optimalidad: La solución encontrada es la mejor?
3) Tiempo de complejidad: Cuanto tiempo se requiere para encontrar una solución
4) Espacio de complejidad: Cantidad de memoria utilizada para hacer la busqueda
3 y 4: Comparaciones respecto a otros algoritmos o soluciones encontradas

En IA existen diversas<u> métricas para medir el rendimiento</u> de los algoritmos, sin embargo. No todos son usados en todo momento y hay que hacer uso adecuado de info.

-> Presión 
-> Exactitud
Son orientados a resultados