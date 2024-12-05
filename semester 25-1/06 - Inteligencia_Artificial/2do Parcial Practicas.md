Tarea
Suponga un laberinto como el de la clase pasada, elabore SIN USAR INTERNET un diagrama y pseudocodigo para implementar el algoritmo BFS y DFS
![[diagrama DFS_BFS_2024-10-21 17.08.11.excalidraw]]

![[IA_DF_Aestrella2024-10-17 16.48.45.excalidraw]]


Practicas 2do Parcial
1) BFS aplicado al laberinto del profe
1.1) DFS '' '' 
2) Implementar A* y hacer las siguientes modificaciones (investigar si en el laberinto que queramos o el mismo de bfs y dfs
   a) Proponga una función de distancia "H", sustituya en el programa la heuristica por dicha función y determine si se logra encontrar un camino con una cantidad menor de bolitas rojas
   b) Proponga una función de distancia "G", sustituya en el programa los valores sueltos de 10 y 14 por dicha función y determine si se logra encontrar un camino con una cantidad menor de bolitas rojas
3) Implementar el algoritmo de dijkstra para el laberinto(?) , donde para validar la practica se tendrá que explicar cada paso del algoritmo basado en un diagrama de flujo o de pasos (incluso se puede apoyar de un ejemplo escrito)
4) Realizar un laberinto de ancho tenga 20 ptos y de largo 35 ptos, que tenga varios posibles caminos. 
   a) Cuando el programa se inicie deberá de pedirle al usuario la coordenada de fin y de inicio, y luego le pedirá elefir entre los 4 posibles algortimos. Una vez seleccionado, jugando con delays (pausas de tiempo) que se vaya dibujando el camino o trayectoria considerada y el final.
   b) Cuando el programa se i### Estructura de Apuntes y Ejercicios

---

#### **Práctica 3**

##### **a) Diagrama de flujo: Algoritmo A***
- Describa el propósito del algoritmo A*.
- Incluya un diagrama de flujo detallado que muestre los pasos:
  1. Inicializar el nodo inicial y final.
  2. Crear listas `abiertos` y `cerrados`.
  3. Calcular costos `f(n) = g(n) + h(n)`.
  4. Expandir nodo con menor `f(n)` en `abiertos`.
  5. Repetir hasta encontrar el nodo final o vaciar `abiertos`.

##### **b) Gráfica del laberinto con `imshow()` y `plot`**
- Código:
  ```python
  import numpy as np
  import matplotlib.pyplot as plt

  laberinto = np.array([
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1],
      [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0],
      [1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1],
      [1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1],
      [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0],
  ])

  plt.imshow(laberinto, cmap="binary")
  plt.show()
  ```

##### **c) Selección de coordenadas válidas**
- Investigar bibliotecas como `matplotlib` para agregar interactividad.
- Ejemplo:
  ```python
  def seleccionar_punto(x, y):
      if laberinto[x, y] == 0:
          plt.plot(y, x, 'o', color='red')
          plt.show()
      else:
          print("Coordenada inválida")
  ```

---

#### **Tarea: Algoritmos BFS y DFS**
1. **Diagrama de flujo:**
   - Mostrar las diferencias entre las estructuras (cola para BFS y pila para DFS).
   - Indicar exploración de vecinos, validación y finalización.

2. **Pseudocódigo BFS:**
   - Inicializar cola con el nodo inicial.
   - Mientras la cola no esté vacía:
     - Sacar el nodo actual.
     - Explorar vecinos y agregarlos a la cola si no están visitados.
   - Retornar el camino si se llega al objetivo.

---

#### **Prácticas del Segundo Parcial**
1. **BFS aplicado al laberinto**
   - Implementar el algoritmo para recorrer el laberinto.

2. **Modificaciones en A***
   - `H` personalizada: 
     - Ejemplo: Distancia Euclidiana.
     - Cambiar la función heurística por `h(n) = sqrt((x2-x1)^2 + (y2-y1)^2)`.
   - `G` personalizada:
     - Ejemplo: Penalización basada en costo del terreno.

3. **Dijkstra**
   - Implementar para laberintos.
   - Explicación detallada de cada paso con diagramas.

4. **Laberinto dinámico:**
   - Generar laberinto 20x35.
   - Implementar selección de inicio, fin y algoritmo.
   - Graficar ejecución con `matplotlib` y pausas.

---

### **Teoría**

#### **Lógica de primer orden (FOL)**
- Extensión de la lógica proposicional.
- Introduce:
  - **Cuantificadores:**
    - Universal (∀): *Para todo*.
    - Existencial (∃): *Existe al menos uno*.
  - **Predicados:** Relacionan objetos, e.g., `Padre(x, y)`.
  - **Dominios:** Conjunto de objetos sobre los cuales trabajan los predicados.

#### **Agentes inteligentes**
1. **Reactivos simples:**
   - Actúan basado en estímulos actuales (sin memoria).
   - Ejemplo: Termostato.
2. **Basados en modelos:**
   - Utilizan una representación del mundo.
   - Ejemplo: Robot que mapea una habitación.
3. **Basados en objetivos:**
   - Toman decisiones para alcanzar metas específicas.
   - Ejemplo: Planeador de rutas.
4. **Basados en utilidad:**
   - Optimizan la satisfacción de sus metas.
   - Ejemplo: Sistema de recomendaciones.

#### **Dijkstra**
- Algoritmo de búsqueda de caminos mínimos en grafos ponderados.
- Pasos:
  1. Inicializar todos los nodos con distancia infinita excepto el origen (cero).
  2. Expandir el nodo con menor costo acumulado.
  3. Actualizar costos a los vecinos.
  4. Repetir hasta que todos los nodos hayan sido explorados.

Si necesitas profundizar o ajustar algún apartado, ¡avísame!nicie deberá de pedirle al usuario la coordenada de fin y de inicio y despliegue 4 laberintos cada uno ejecutado con cada algoritmo y se ponga ARRIBA DE LA IMAGEN (DENTRO DE LA IMAGEN) DEL LABERINTO SU TIEMPO DE EJECUCION DE CADA UNO

![[IA2024-11-17 03.07.33.excalidraw]]

----


Practica 3
a) Realice un diagrama de flujo que ejemplifique el uso de A*
b) Sea la siguiente matriz (definirla como matriz)
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 1 1 1 1 0 0 1 1 1 1 1 1
0 0 0 0 0 0 0 1 1 1 0 0 0 0 0
1 0 1 0 1 1 1 1 0 0 0 1 1 1 1
1 0 0 0 0 0 0 1 1 1 1 1 1 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 0 1
1 1 1 0 1 0 1 0 1 1 1 1 1 0 1
0 0 0 0 0 0 1 0 0 0 1 1 1 0 0
-> Utilice el comando imshow() y plot para graficar el laberinto (si usa otro lenguaje) se debe ver graficamente el laberinto
c) Investigue una funcion, forma o manera para que el usuario elija una coordenada y en ese punto despliegue un punto de color si la coordenada es valida


```python
#Inicializar de punto inicial y final 
punto_inicial = (1, 1)
meta = (14, 14)
#Tipos de movimiento
movimientos = [(-1,0), (0,1), (1,0), (0,-1)]

def dfs(laberinto, punto_inicial, meta)
    #Lista para manejar los nodos por explorar (pila)
    pila = [(punto_inicial, [])]
    #Matriz de visitados
    filas = np.shape(laberinto)[0]
    columnas = np.shape(laberinto)[1]
    visitados = np.zeros((filas,columnas))
    #Marcamos el nodo inicial como visitados
    #Definir una lista que contenga a todos los nodos que he visitado
    considerados = []

    while len(pila) > 0:
        nodo_actual, camino = pila[-1]
        pila = pila[:1]

        #Guardar los nodos que se han ido visitando
        considerados += [considerados]

        if nodo_actual == meta
            return camino + [nodo_actual], considerados

        visitados[nodo_actual[0], nodo_actual[1]] = 1
        for direccion in movimientos:
            nueva_posicion = (nodo_actual[0] + direccion[0])
            #Ver que el vecino (nueva posición) este dentro del laberinto
            if ((0 <= nueva_posicion[0] < filas) and (0 <= nueva_posicion[1] < columnas));
                if (maze[nueva_posicion[0], nueva_posicion[1]]) == 0 and visitados[nueva_posicion[0], nueva_posicion[1]] == 0):
```

```python
import matplotlib.pyplot as plt
import numpy as np

#Laberinto de 15x15 con 1 representado por paredes y 0 por caminos
maze = np.array([
    [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
    [1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,1],
    [1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,0,1,1,1],
    [1,0,1,1,1,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1],
    [1,0,0,0,0,1,0,0,1,1,0,1,1,0,0,0,0,0,1,1],
    [1,0,0,0,1,1,0,0,1,1,0,0,1,0,1,1,1,0,1,1],
    [1,0,0,1,0,1,1,1,0,1,0,0,1,0,0,0,0,0,1,1],
    [1,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1],
    [1,0,0,0,0,1,1,0,1,1,0,1,1,1,1,0,0,1,0,1],
    [1,1,1,0,0,0,0,1,0,1,1,0,0,1,1,0,1,1,0,1],
    [1,0,0,1,0,0,1,0,1,0,1,1,0,0,1,0,1,1,0,1],
    [1,0,0,1,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1],
    [1,0,0,0,1,1,0,0,0,1,0,1,0,0,1,0,0,1,0,1],
    [1,0,0,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,0,1],
    [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
    ])

#Inicializar punto inicial y punto final
punto_inicial = (1,1)
meta = (13,15)

#Tipos de movimiento
movimientos = [(-1,0),(0,1),(1,0),(0,-1)]

def dfs(laberinto,punto_inicial,meta):
    #Lista para manejar los nodos por explorar (pila)
    pila = [(punto_inicial,[])]
    #Matriz de visitados
    filas = np.shape(laberinto)[0]
    columnas = np.shape(laberinto)[1]
    visitados = np.zeros((filas,columnas))
    #Marcamos el nodo inicial como visitado

    #Definir una lista que contenga todos los nodos que he visitado
    considerados = []

    while len(pila) > 0:
        nodo_actual,camino = pila[-1]
        pila = pila[:-1]

        #Guardar los nodos que se han ido visitando
        considerados += [nodo_actual]

        if nodo_actual == meta:
            return camino + [nodo_actual],considerados

        visitados[nodo_actual[0],nodo_actual[1]] = 1
        for direccion in movimientos:
            nueva_posicion = (nodo_actual[0] + direccion[0],nodo_actual[1] + direccion[1])
            #Ver que el vecino (nueva posición) esté dentro del laberinto
            if((0 <= nueva_posicion[0] < filas) and (0 <= nueva_posicion[1] < columnas)):
                #Ver si el nodo a evaluar (nueva_posicion) es un cambio accesible y además si ese nodo NO LO HE VISITADO
                if((maze[nueva_posicion[0],nueva_posicion[1]]) == 0 and visitados[nueva_posicion[0],nueva_posicion[1]] == 0):
                    pila += [(nueva_posicion,camino + [nodo_actual])]
    return None,considerados

def desplegar_laberinto(maze,camino = None,considerados = None):
    plt.imshow(maze,cmap = 'binary')
    if considerados:
        for i in considerados:
            plt.plot(i[1],i[0],'o',color = 'blue')
    if camino:
        for j in camino:
            plt.plot(j[1],j[0],'o',color = 'red')
    plt.show()

camino,considerados = dfs(maze,punto_inicial,meta)
desplegar_laberinto(maze,camino,considerados)

```



### **Lógica de Primer Orden (LPO)**

La **lógica de primer orden** (First-Order Logic, FOL) es una extensión de la lógica proposicional que permite representar y razonar sobre objetos individuales, sus propiedades, relaciones entre ellos y cuantificadores. Es fundamental en áreas como la Inteligencia Artificial para modelar problemas complejos.

**Componentes principales de la LPO:**

1. **Constantes:** Representan objetos específicos (e.g., a,ba, b).
2. **Variables:** Representan objetos no especificados (e.g., x,yx, y).
3. **Funciones:** Asocian objetos con otros objetos (e.g., f(x)f(x)).
4. **Predicados:** Representan propiedades de objetos o relaciones entre ellos (e.g., P(x)P(x), R(x,y)R(x, y)).
5. **Cuantificadores:**
    - **Universal (∀\forall):** "Para todo", indica que una propiedad es verdadera para todos los elementos.
    - **Existencial (∃\exists):** "Existe", indica que hay al menos un elemento que satisface una propiedad.
6. **Conectores lógicos:** Y (∧\land), O (∨\lor), No (¬\neg), Implies (→\rightarrow), Si y solo si (↔\leftrightarrow).

Ejemplo de expresión en LPO:

∀x(Humano(x)→Mortal(x))\forall x (Humano(x) \rightarrow Mortal(x))

Significa: "Todos los humanos son mortales".

### **Agentes Inteligentes**

Un **agente inteligente** es una entidad capaz de percibir su entorno mediante sensores, razonar sobre él y actuar para lograr objetivos específicos.

#### **Tipos de agentes:**

1. **Agentes Reactivos Simples:**
    
    - Actúan basándose únicamente en las percepciones actuales.
    - No tienen memoria ni modelan el entorno.
    - Ejemplo: Un termostato que enciende el aire acondicionado si la temperatura supera un umbral.
2. **Agentes Basados en Modelos:**
    
    - Mantienen un modelo interno del mundo que actualizan con las percepciones.
    - Usan este modelo para planificar acciones.
    - Ejemplo: Un robot que navega un entorno desconocido actualizando un mapa.
3. **Agentes Basados en Objetivos:**
    
    - Tienen metas específicas que intentan alcanzar.
    - Deciden acciones basándose en las percepciones y en cómo acercan al objetivo.
    - Ejemplo: Un GPS que calcula la ruta más corta hacia un destino.
4. **Agentes Basados en Utilidad:**
    
    - No solo buscan alcanzar objetivos, sino optimizar la calidad o utilidad de las soluciones.
    - Ejemplo: Un asistente virtual que selecciona el mejor restaurante según precio, distancia y preferencias.

### **Algoritmo de Dijkstra**

El **algoritmo de Dijkstra** es un método de búsqueda de caminos más cortos desde un nodo fuente a todos los demás nodos en un grafo ponderado dirigido o no dirigido, donde las aristas tienen pesos no negativos.

**Pasos principales:**

1. **Inicialización:**
    
    - Asigna a cada nodo una distancia infinita, excepto al nodo fuente, que tiene distancia 0.
    - Marca todos los nodos como no visitados.
    - Usa una cola de prioridad para elegir el nodo con la distancia más corta en cada iteración.
2. **Actualización de distancias:**
    
    - Desde el nodo actual, examina sus vecinos y calcula posibles distancias más cortas.
    - Si la distancia calculada a un vecino es menor que la conocida, actualiza su distancia.
3. **Repetición:**
    
    - Marca el nodo actual como visitado.
    - Selecciona el siguiente nodo no visitado con la distancia mínima y repite el proceso.
4. **Finalización:**
    
    - El algoritmo termina cuando todos los nodos han sido visitados o la distancia más corta a todos los nodos alcanzables ha sido calculada.

**Aplicaciones:**

- Redes de telecomunicaciones.
- Sistemas de navegación (e.g., GPS).
- Optimización de rutas en logística.
