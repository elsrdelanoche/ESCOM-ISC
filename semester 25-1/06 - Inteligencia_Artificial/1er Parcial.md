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

### Ejercicio
El problema de las 8 reinas es un problema computacional muy conocido, se trata de colocar en un tablero de ajedrez 8 reinas sin que ninguna se ataque la una a la otra.

Una reina ataca a otra reina si hay dos reinas en la misma fila, columna o diagonal.
Opcional: https://omegaup.com/arena/problem/8Reinas/#:~:text=El%20problema%20de%20las%208,misma%20fila%2C%20columna%20o%20diagonal.

![[Pasted image 20240911175545.png]]

---
# 12 de Septiembre 2024
Grafos: Estructura matematica para modelar las relaciones que existen entre objetos
![[IA2024-09-12 16.44.37.excalidraw]]

Los grafos tienen diversas aplicaciones dentro de la IA, específicamente en algoritmos de búsqueda (heuristica),
se ocupan para obtener soluciones o conjuntos de estas, si las hay.

## Ejemplos de algoritmos de búsqueda
-> Búsqueda por profundidad
-> Búsqueda por anchura
-> A*

## Tipos de grafos:
### Grafos Dirigidos
Los vertices indican la direccion que puedan tomar los caminos entre nodos

### Grafos no dirigidos
Los vertices no tienen asociada ninguna dirección en la relación de los nodos y por lo tanto los caminos que se pueden trazar entre nodos puede ir en cualquier dirección.

![[Pasted image 20240912170723.png]]

Los algoritmos básicos y clásicos son búsqueda por profundidad y anchura
-> Éstos algoritmos se rigen por ir guardando los nodos en los que se ha estado.
### Grafos ponderados
El vértice tiene asociado un peso
Usados para encontrar rutas óptimas entre nodos, por ejemplo: Aplicaciones para encontrar el mejor camino entre 2 localidades.
Ejemplo: A*
![[Pasted image 20240912172043.png]]


## BFS: Búsqueda por anchura
Inicia en un nodo (por ejemplo el nodo raiz)y un recorriendo nodos de forma lateral (Nodos hermanos) y si encuentra la solución se pasa a los siguientes niveles.

![[Pasted image 20240912173648.png]]

-> Si hay solución, es garantía de que llegará a ella
-> No es optimo computacionalmente para gran cantidad de nodos


## DFS: Busqueda por profundidad
Inicia en un nodo (por ejemplo el nodo inicial) y va recorriendo Padre
![[Pasted image 20240912174613.png]]

---
# 03 Octubre 2024
Consideraciones para el algoritmo A*
1) Se suelen tener 3 tipos de listas (arreglos), lista cerrada la cual registra los nodos visitados, una lista abierta que registra los nodos con los que el nodo i-j esimo tiene que compararse y finalmente una lista de nodos bloqueados
2) Se debe definir desde un inicio "H" y "g"
3) Se recomienda empezar los análisis de vecinos en sentido horario o antihorario
4) Se debe ir guardando las relaciones padre-hijo
5) Se debe conocer el inicio y el final

g: Distancia Euclidiana
6) En la parte de las comparaciones se contempla la suma de las g del nodo i-j-esimo con el nodo a analizar en la lista abierta
Heuristica
h: Distancia manhattan (no considera diagonales)

---
# 7 de Octubre 2024
![[IA_2024-10-07 17.33.14.excalidraw]]


# Apuntes: Exenté apuntes en la dinámica de Asimov, saludos
---
# 4 de Septiembre 2024 - Tarea
## Lectura: La ultima pregunta, Isaac Asimov

La obra del autor Asimov me causa intriga sobre el que tan cercanos estamos a futuros como el que él imagina, sobre si personas como él (escritores de ciencia ficción) son escritores también de nuestro futuro, inspiran y hacen soñar a hombres de ciencia pues menciona computadoras capaces de resolver las mejores preguntas, tal y como lo hace la inteligencia artificial hoy en día.
La inteligencia de hoy tiene la capacidad de con lo aprendido dar respuestas a un usuario pero no puede imaginar, crear o pensar, no existe una creatividad como para retro-alimentar, actualizarse o repararse ella misma. Considero que puede ser posible pero son límites que el programador debe de poner para que esta misma no salga de su alcance y entendimiento.
En el cuento esta misma computadora logra resolver grandes dudas como Cómo detener el envejecimiento, la inmortalidad y otras, pero creo que indirectamente me da a entender que les dio poder a la raza humana, los dotó de características con las que una vez logrando las tendrían más problemas que puntos buenos, se comenzaron a expandir a territorios ajenos al suyos, comenzando un interminable consumo de recursos, o como lo comenta el libro, el desgaste del universo.
Veo a la raza humana como seres egoístas que con ciencia se ayudaron a ser los consumidores de todo, me atrevería a llamarlos una plaga muy inteligente, y creo que no es lejano a lo que somos actualmente, a mucho menor escala y con menos conocimiento, pero es lo que somos, seres que no sabemos por que estamos aquí y el tiempo que nos dure
tenemos que sobrevivir a como podamos para lograr disfrutarlo.
¿De qué nos sirve saber todas las respuestas? Saberlo todo, el que tengamos las respuestas en la mano, quita lo interesante que puede ser salir a buscarlas, le quita cierto sentido a la vida, lo tenemos todo y no tenemos nada.
Sin embargo, considero que la inteligencia artificial de hoy, con todo el conocimiento e información que nos proporciona,y las limitaciones que tiene, nos lleva a mejorar en la forma en la que hacemos preguntas, nos alimentamos de las respuestas y hacemos preguntas más grande, lo que creo nos hace mejores pensadores.
¿Es posible crear algo más allá de nuestro entendimos? Me gusta la teoría en la que vivimos en un ciclo sin fin, en el que somos nosotros mismos los que nos trajimos a el punto en el que estamos y no lo sabemos, que en el futuro estaremos en un fin inminente y después de un “Hágase la luz” podría estar cercano al presente en el que estamos
Somos nosotros el mismo ente creador, acompañado de una inteligencia que fue creciendo sin nosotros, buscando resolver acciones que no planeamos, avanzando a pasos inevitables.
Entropía: Desgaste del universo
# Avances de IA, simposio, congresos, revistas 2024 - Investigación
Los avances de la Inteligencia Artificial (IA) se presentan continuamente en revistas académicas, congresos, y simposios especializados en el campo. A continuación, te mencionaré algunos de los desarrollos más destacados en diversas áreas de la IA, basados en lo que ha sido mencionado en los últimos eventos y publicaciones científicas:

### 1. **Modelos de lenguaje avanzado**
   - **GPT-4 y LLMs (Large Language Models):** Modelos como GPT-4 y otros grandes modelos de lenguaje han revolucionado las aplicaciones de procesamiento de lenguaje natural (PLN), mejorando tareas como la traducción automática, la generación de texto, el resumen automático, y la comprensión de lenguaje. En congresos como **NeurIPS** y **ICLR**, se discuten mejoras en eficiencia, compresión, y capacidades multimodales, así como desafíos éticos.

### 2. **IA Multimodal**
   - **DALL-E, CLIP, Flamingo:** Estos modelos han avanzado la integración de texto, imágenes, y en algunos casos, sonido, para tareas de generación de contenido y análisis más complejas. En **CVPR** (Computer Vision and Pattern Recognition) y **ECCV** (European Conference on Computer Vision) se exploran nuevas técnicas que permiten combinar entradas de varios tipos de datos para mejorar la comprensión contextual y la generación creativa.

### 3. **Modelos Generativos (GANs y VAEs)**
   - Las **Generative Adversarial Networks (GANs)** y los **Variational Autoencoders (VAEs)** han seguido evolucionando. En conferencias como **ICML** (International Conference on Machine Learning) y **AAAI** (Association for the Advancement of Artificial Intelligence), se presentaron nuevas variantes que permiten una mejor generación de imágenes y videos, restauración de imágenes, y creación de entornos virtuales. Estos modelos también están mejorando en eficiencia y calidad con menos datos de entrenamiento.

### 4. **Aprendizaje Auto-supervisado y AutoML**
   - En eventos como **ICLR** y **NeurIPS**, el aprendizaje auto-supervisado ha ganado mucha atención. Este enfoque permite que los modelos aprendan sin necesidad de grandes cantidades de datos etiquetados, lo que reduce el costo y tiempo en la creación de modelos de IA. Además, **AutoML** sigue avanzando, automatizando el diseño, entrenamiento, y optimización de modelos.

### 5. **IA para la salud**
   - En congresos como **MICCAI** (Medical Image Computing and Computer-Assisted Intervention), se han mostrado grandes avances en el uso de IA para la detección temprana de enfermedades a partir de imágenes médicas, optimización de tratamientos personalizados, y el análisis de grandes conjuntos de datos de salud. La IA ha mejorado la precisión en diagnósticos como cáncer, enfermedades cardíacas, y trastornos neurológicos.

### 6. **Robótica avanzada e IA para automatización**
   - **Simposios como ICRA** (International Conference on Robotics and Automation) presentan avances en la integración de IA en robots para tareas complejas, desde la industria manufacturera hasta robots de asistencia para el hogar y la salud. La capacidad de los robots para aprender de forma autónoma, interactuar con entornos no estructurados, y colaborar con humanos sigue mejorando.

### 7. **IA Explicable (XAI)**
   - La **Inteligencia Artificial Explicable (XAI)** es un campo en crecimiento, y se ha abordado en conferencias como **IJCAI** (International Joint Conference on Artificial Intelligence). Los avances buscan hacer que los modelos de IA, especialmente los de aprendizaje profundo, sean más transparentes y comprensibles para los usuarios, particularmente en aplicaciones críticas como medicina, finanzas, y justicia.

### 8. **Mejoras en la eficiencia energética**
   - La reducción del consumo de energía en los modelos de IA es un tema recurrente en eventos como **CVPR** y **NeurIPS**. Investigadores están trabajando en métodos para hacer que los algoritmos sean más eficientes, tanto en entrenamiento como en inferencia, lo cual es crucial dado el costo computacional de modelos de gran tamaño como GPT.

### 9. **IA y Ética**
   - En simposios como el **AI for Good Global Summit**, los temas éticos, de privacidad, y de equidad en el uso de IA están tomando un papel central. Se discuten problemas relacionados con el sesgo en los algoritmos, la falta de transparencia en las decisiones tomadas por IA, y las implicaciones sociales y laborales del despliegue masivo de sistemas automatizados.

### 10. **IA Cuántica**
   - En eventos como **QIP** (Quantum Information Processing), el uso de computación cuántica para mejorar algoritmos de IA es un área emergente. Aunque los avances en esta intersección están en etapas iniciales, las investigaciones apuntan a resolver problemas que las computadoras clásicas no pueden abordar eficientemente.

Estos avances han sido destacados en las principales publicaciones y congresos como **NeurIPS, ICML, CVPR, ICLR, IJCAI** y **AAAI**, que son pilares en la investigación de IA a nivel mundial.

---
# Ejercicio Menu Cadenas

``` cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion;
    string cadena, cadena2;
    int inicio, fin, potencia;

    do {
        // Menú de opciones
        cout << "Menu de cadenas\n";
        cout << "1.- Concatenar cadenas\n";
        cout << "2.- Obtener prefijo\n";
        cout << "3.- Obtener sufijo\n";
        cout << "4.- Obtener subcadena\n";
        cout << "5.- Obtener subsecuencia\n";
        cout << "6.- Invertir cadena\n";
        cout << "7.- Potencia de cadena\n";
        cout << "8.- Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: // Concatenar cadenas
                cout << "Ingrese la primera cadena: ";
                cin >> cadena;
                cout << "Ingrese la segunda cadena: ";
                cin >> cadena2;
                cout << "La cadena concatenada es: ";
                for (char c : cadena) cout << c;
                for (char c : cadena2) cout << c;
                cout << endl<<endl;
                break;
            case 2: // Obtener prefijo
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "Ingrese el tamaño del prefijo: ";
                cin >> fin;
                for (int i = 0; i < fin; i++) {
                    cout << cadena[i];
                }
                cout << endl;
                break;
            case 3: // Obtener sufijo
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "Ingrese el tamaño del sufijo: ";
                cin >> inicio;
                for (int i = inicio; i < cadena.length(); i++) {
                    cout << cadena[i];
                }
                cout << endl;
                break;
            case 4: // Obtener subcadena
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "Ingrese el índice inicial: ";
                cin >> inicio;
                cout << "Ingrese el índice final: ";
                cin >> fin;
                for (int i = inicio; i <= fin; i++) {
                    cout << cadena[i];
                }
                cout << endl;
                break;

            case 5:{ // Obtener subsecuencia (considerando subcadena de longitud máxima)
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "Ingrese la subcadena a buscar: ";
                cin >> cadena2;
                bool encontrada = false;
                for (int i = 0; i <= cadena.length() - cadena2.length(); i++) {
                    int j;
                    for (j = 0; j < cadena2.length(); j++) {
                        if (cadena[i + j] != cadena2[j]) {
                            break;
                        }
                        
                    }
                    if (j == cadena2.length()) {
                        encontrada = true;
                        cout << "subsecuencia encontrada en el índice " << i << endl;
                        break;
                    }
                }
                if (!encontrada) {
                    cout << "subsecuencia no encontrada." << endl;
                }
                break;
            }
            case 6: // Invertir cadena
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "La cadena invertida es: ";
                for (int i = cadena.length() - 1; i >= 0; i--) {
                    cout << cadena[i];
                }
                cout << endl;
                break;
            case 7: // Potencia de cadena
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "Ingrese el exponente: ";
                cin >> potencia;
                cout << "La cadena elevada a la " << potencia << " es: ";
                for (int i = 0; i < potencia; i++) {
                    for (char c : cadena) cout << c;
                }
                cout << endl;
                break;
            case 8:
                cout << "Saliendo del programa..." << endl<<"Tenga buen día";
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 8);

    return 0;
}
```

## Pruebas de escritorio
![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXe9xOBf9u8aLa62vsvcp-bY9nE4ttcrJmNcJmI5zYUHjPo7j4BCP891zOsSMfkMI0JcFgPUnaUqtNpjhZLinG78kfijDZezaREoxnvV9BKNWnJcNk-a9gxKlOO50UlJ4Y6bcW463iF_uTKx8JHWRR9toG6Y?key=3ILisnqfMofe93DY5SL2IQ)![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXc1KGyrJwNh0jMG4yxuU-8nval7f5zClh6IzAAVkY8JQPvzct9cwPmyIjAB-2_X2eZv7Cq4g6Qa_fhfKzVORLJBQHes97EN_wcyUDzBJth-SC6NWkrf12_JCmgLT0iOJInUlgBoO9a2LXIYf_Ulu0Ud6Mzw?key=3ILisnqfMofe93DY5SL2IQ)![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdWGoAkBsO4qi3RWTBNlb9ssRTyi-8DgEqzxeXskXxr1In0XnjmLMuZav_uiIPMA-Ye-t6x2U44-QREmUeCN5OhIfofKKXMBX9Nf5cdSYSMvc4iJ6C3P3-DJjaZWxQAbP2Kfx8fgbVZaDUqL00sXZEXOBs?key=3ILisnqfMofe93DY5SL2IQ)![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdOvwLsl8rtf-Pn4wSbrxOZyPtabxMgOJRsWo11YQ9DjpNORAmXU5UEh8UgzrlxfspR1Qe59L94FTu40LTrLlEbB13pJFrOXS_AyDF1NzTouPndKoS4Eq8V7gphVU0ec89OIL7wyKs_14BrDe-3M3bZxEGu?key=3ILisnqfMofe93DY5SL2IQ)
