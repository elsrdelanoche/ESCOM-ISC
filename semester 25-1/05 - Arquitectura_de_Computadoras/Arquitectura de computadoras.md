# Unidad temática 1: 
## Organización y arquitectura de computadoras
### 1.1 Fundamentos de arquitectura de computadoras

#### 1.1.1 Arquitectura y organización de computadoras
Este tema se enfoca en la estructura y el diseño de los sistemas informáticos. La **arquitectura** se refiere al diseño conceptual y a las especificaciones funcionales de los componentes de un sistema informático, mientras que la **organización** se refiere a la forma en que estos componentes están interconectados y funcionan juntos. 

**Dato interesante**: La arquitectura x86 es una de las más populares en computadoras personales y servidores, mientras que ARM es dominante en dispositivos móviles debido a su eficiencia energética.

**Aplicación**: La arquitectura y la organización son fundamentales para diseñar computadoras eficientes y adecuadas para tareas específicas, desde supercomputadoras hasta sistemas embebidos en dispositivos móviles.

#### 1.1.2 Memoria de programa
Se refiere al almacenamiento de instrucciones que la computadora ejecutará. Este tipo de memoria es crucial para el funcionamiento de la CPU, ya que mantiene las instrucciones necesarias para que el procesador realice sus operaciones.

**Ejemplo**: La memoria caché de instrucciones en una CPU moderna almacena temporalmente instrucciones para reducir el tiempo de acceso a la memoria principal.

#### 1.1.3 Memoria de datos
La memoria de datos almacena información temporalmente mientras se ejecutan los programas. Incluye tanto la memoria RAM como las memorias caché.

**Aplicación**: Es fundamental para el rendimiento del sistema, ya que la velocidad de acceso a los datos afecta directamente la velocidad de procesamiento.

#### 1.1.4 Unidad aritmética lógica (ALU)
La ALU es el componente del procesador encargado de realizar todas las operaciones aritméticas y lógicas. Es un bloque básico de la CPU que permite realizar cálculos matemáticos y evaluaciones lógicas.

**Ejemplo**: Cuando una calculadora realiza una operación matemática, está utilizando una ALU para calcular el resultado.

#### 1.1.5 Registros
Los registros son pequeñas unidades de almacenamiento dentro de la CPU que mantienen datos temporales para operaciones rápidas. 

**Dato interesante**: Los registros son los tipos de memoria más rápidos, ya que están directamente dentro del procesador.

#### 1.1.6 Unidad de control
La unidad de control dirige el flujo de datos dentro del procesador, gestionando cómo se ejecutan las instrucciones. Esencialmente, coordina la operación de la CPU y regula el uso de la ALU, los registros y la memoria.

**Aplicación**: Sin la unidad de control, no habría un flujo ordenado de instrucciones y operaciones dentro del procesador.

### 1.2 Arquitecturas clásicas

#### 1.2.1 Arquitectura Von Neumann
La arquitectura Von Neumann es un diseño de computadora que usa una sola memoria para almacenar tanto los datos como las instrucciones del programa.

**Ejemplo**: La mayoría de las computadoras modernas utilizan una arquitectura Von Neumann.

**Dato interesante**: Este diseño es propenso al problema del "cuello de botella" de Von Neumann, donde la CPU y la memoria compiten por el mismo bus.

#### 1.2.2 Arquitectura RISC y CISC
- **RISC (Reduced Instruction Set Computer)**: Utiliza un conjunto reducido de instrucciones para ejecutar operaciones más simples y rápidas. 
- **CISC (Complex Instruction Set Computer)**: Utiliza un conjunto complejo de instrucciones que pueden realizar operaciones más complejas en una sola instrucción.

**Ejemplo**: Los procesadores ARM utilizan RISC y son comunes en dispositivos móviles, mientras que los procesadores Intel x86 son ejemplos de CISC.

#### 1.2.3 Arquitectura Harvard
La arquitectura Harvard separa la memoria de instrucciones de la memoria de datos, permitiendo acceso simultáneo a ambas.

**Aplicación**: Es común en sistemas embebidos y microcontroladores debido a su eficiencia en el manejo de datos e instrucciones por separado.

### 1.3 Arquitecturas especializadas

#### 1.3.1 Arquitectura Superscalar
Este tipo de arquitectura permite ejecutar más de una instrucción por ciclo de reloj al tener múltiples unidades de ejecución en paralelo.

**Ejemplo**: Los procesadores modernos de Intel y AMD son ejemplos de arquitecturas superscalar.

#### 1.3.2 Arquitectura vectorial
Se enfoca en el procesamiento de datos en bloques grandes, optimizando operaciones matemáticas en matrices y vectores.

**Aplicación**: Es común en supercomputadoras y aplicaciones científicas donde se requieren grandes cantidades de cálculos matemáticos.

Estos temas proporcionan una base sólida para entender cómo las computadoras están diseñadas y cómo funcionan internamente, permitiendo optimizaciones en diferentes áreas de aplicación, desde el uso cotidiano hasta aplicaciones científicas y de alta tecnología.

---

# Unidad Temática 2: 
## Arquitectura del conjunto de instrucciones de RISC

La arquitectura RISC (Reduced Instruction Set Computer) se centra en un conjunto reducido y optimizado de instrucciones, lo cual permite que las operaciones sean más rápidas y eficientes. Esta unidad se enfoca en los formatos y tipos de instrucciones en la arquitectura RISC, así como en su implementación práctica mediante programación.
### 2.1 Formato de las instrucciones

Los formatos de instrucciones en una arquitectura RISC son esquemas que definen cómo se organizan los bits dentro de una instrucción para indicar a la CPU qué operación realizar y sobre qué operandos. A continuación, se describen los principales tipos de formatos de instrucciones en RISC.

#### 2.1.1 Formato tipo R

El **formato tipo R** se utiliza para instrucciones que operan completamente en registros, como las operaciones aritméticas y lógicas. En general, incluye campos para el código de operación, registros fuente, registros destino, y, a veces, un campo de función para especificar variaciones de la operación.

**Ejemplo**: En una instrucción RISC típica, como `ADD R1, R2, R3`, el registro `R1` se utilizará para almacenar el resultado de la suma de los registros `R2` y `R3`.

#### 2.1.2 Formato tipo I

El **formato tipo I** se utiliza para instrucciones que incluyen un valor inmediato o una dirección de memoria. Este formato incluye campos para el código de operación, un registro fuente o destino, un registro base, y un valor inmediato o desplazamiento.

**Aplicación**: Es común en instrucciones de carga y almacenamiento donde es necesario acceder a la memoria, como `LW R1, 4(R2)`, que carga un valor desde la dirección calculada como la suma del contenido de `R2` y 4 en el registro `R1`.

#### 2.1.3 Formato tipo J

El **formato tipo J** se utiliza para instrucciones de salto (brinco), permitiendo que el programa salte a una nueva ubicación en el código. Este formato tiene un campo de código de operación y un campo de destino que especifica la dirección del salto.

**Ejemplo**: Una instrucción de salto como `J 1024` indicaría al procesador que continúe la ejecución en la dirección de memoria 1024.

#### 2.1.4 Otros formatos

**Otros formatos** pueden incluir formatos especializados para operaciones como multiplicación, división, o manejo de excepciones, dependiendo de la implementación específica del procesador RISC. Estos formatos varían en su estructura dependiendo de los requerimientos de la operación.

### 2.2 Tipos de instrucción

Los tipos de instrucciones definen las operaciones específicas que el procesador puede realizar. En una arquitectura RISC, las instrucciones suelen ser sencillas y de tamaño fijo para maximizar la eficiencia.

#### 2.2.1 Instrucciones de carga y almacenamiento

Estas instrucciones mueven datos entre los registros y la memoria principal. En RISC, las operaciones aritméticas solo se realizan entre registros, por lo que cargar y almacenar datos es fundamental.

**Ejemplo**: `LW R1, 0(R2)` carga un valor de la memoria al registro `R1`, y `SW R1, 0(R2)` almacena el valor del registro `R1` en la memoria.

#### 2.2.2 Instrucciones aritméticas y lógicas

Estas instrucciones realizan operaciones matemáticas y lógicas en registros. Ejemplos comunes incluyen adición (`ADD`), sustracción (`SUB`), y operaciones lógicas (`AND`, `OR`).

**Dato interesante**: En procesadores RISC, estas instrucciones tienden a ser ejecutadas en un solo ciclo de reloj.

#### 2.2.3 Instrucciones de corrimiento

Las instrucciones de corrimiento (`shift`) mueven los bits en un registro hacia la izquierda o la derecha. Son útiles para operaciones rápidas de multiplicación y división por potencias de dos.

**Ejemplo**: `SLL R1, R2, 2` realiza un corrimiento lógico a la izquierda del registro `R2` por dos posiciones y guarda el resultado en `R1`.

#### 2.2.4 Instrucciones de brinco condicional e incondicional

Estas instrucciones cambian el flujo del programa. Las instrucciones de brinco incondicional (`J`) siempre se ejecutan, mientras que las condicionales (`BEQ`, `BNE`) dependen de una comparación.

**Ejemplo**: `BEQ R1, R2, etiqueta` salta a `etiqueta` si los registros `R1` y `R2` son iguales.

#### 2.2.5 Instrucciones de manejo de subrutinas

Estas instrucciones permiten llamar y retornar de subrutinas, gestionando el flujo de control del programa. Usualmente implican guardar la dirección de retorno en un registro o en la pila.

**Ejemplo**: `JAL etiqueta` salta a `etiqueta` y guarda la dirección de retorno en un registro, facilitando el regreso a la instrucción siguiente después de ejecutar la subrutina.

#### 2.2.6 Otras instrucciones

Dependiendo del diseño específico del conjunto de instrucciones, pueden existir otras instrucciones como las de manejo de interrupciones o acceso a registros especiales.

### 2.3 Programación

La programación en arquitecturas RISC implica el uso eficiente de instrucciones simples y optimizadas. La comprensión de cómo utilizar cada tipo de instrucción es crucial para maximizar el rendimiento.

#### 2.3.1 Instrucciones de carga y almacenamiento

La programación con estas instrucciones se centra en mover datos hacia y desde registros de manera eficiente para que estén disponibles para operaciones aritméticas y lógicas.

**Ejemplo**: Mover datos necesarios en un cálculo a registros para minimizar el acceso a la memoria, que es más lento.

#### 2.3.2 Instrucciones aritméticas y lógicas

Estas instrucciones se utilizan para manipular datos directamente en los registros. La eficiencia proviene de la capacidad de realizar cálculos con un número mínimo de instrucciones.

**Aplicación**: Usar la instrucción `ADD` para sumar dos números almacenados en registros en lugar de tener que cargar desde la memoria cada vez.

#### 2.3.3 Instrucciones de corrimiento

Las instrucciones de corrimiento se utilizan en operaciones que requieren manipulaciones bit a bit, como encriptación o gráficos.

**Ejemplo**: Usar `SLL` y `SRL` para manipular datos de píxeles en gráficos.

#### 2.3.4 Instrucciones de brinco condicional e incondicional

Se utilizan para crear bucles y condicionales en el código, controlando el flujo de ejecución basado en comparaciones y condiciones.

**Aplicación**: Crear un bucle `for` utilizando instrucciones de comparación y salto condicional para iterar sobre un conjunto de datos.

#### 2.3.5 Instrucciones de manejo de subrutinas

Estas son esenciales para la programación modular, permitiendo que el código se organice en funciones y procedimientos que se pueden llamar repetidamente.

**Ejemplo**: Llamar a una subrutina que realiza una operación matemática compleja para evitar repetir el mismo código varias veces.

#### 2.3.6 Implementación usando simuladores

El uso de simuladores permite probar y depurar código de bajo nivel sin necesidad de hardware físico. Estos simuladores replican el comportamiento de procesadores RISC, facilitando el aprendizaje y desarrollo.

**Aplicación**: Utilizar un simulador RISC-V para probar un algoritmo de encriptación y asegurarse de que funcione correctamente antes de implementarlo en hardware.

---

# Unidad Temática III: 
## Diseño e implementación de un procesador monociclo de arquitectura RISC

En esta unidad, se estudia el diseño y la implementación de un procesador RISC monociclo, lo que implica que cada instrucción se ejecuta en un solo ciclo de reloj. El procesador monociclo es un modelo conceptual simple que sirve para entender los principios básicos de diseño de procesadores y su implementación.

### 3.1 Unidad aritmética y lógica (ALU)

La Unidad Aritmética y Lógica (ALU) es responsable de realizar operaciones aritméticas (como suma y resta) y lógicas (como AND, OR, NOT) en los datos. En un procesador RISC monociclo, la ALU es un componente crucial para la ejecución de instrucciones.

#### 3.1.1 Análisis usando sumador con acarreo en cascada

El **sumador con acarreo en cascada** (ripple carry adder) es un tipo de sumador donde el acarreo generado en cada bit se propaga a la siguiente posición. Es fácil de implementar, pero su rendimiento se degrada a medida que aumenta el número de bits debido al tiempo necesario para que el acarreo "ripple" a través de todos los bits.

**Ejemplo**: Un sumador de 4 bits utilizando acarreo en cascada tendría un tiempo de retraso directamente proporcional al número de bits, ya que cada bit espera el resultado del anterior para calcular su propio acarreo.

#### 3.1.2 Análisis usando sumador con acarreo anticipado

El **sumador con acarreo anticipado** (carry-lookahead adder) mejora el rendimiento calculando el acarreo en varias posiciones simultáneamente, en lugar de depender de la propagación secuencial del acarreo. Esto permite una ejecución más rápida en comparación con el sumador con acarreo en cascada.

**Aplicación**: En procesadores de alta velocidad, donde la latencia debe minimizarse, se prefiere el sumador con acarreo anticipado debido a su menor tiempo de cálculo.

#### 3.1.3 Análisis usando otras arquitecturas

Esta sección implica explorar otras arquitecturas de ALU, como sumadores con acarreo selectivo (carry-select adders) o sumadores con acarreo variable (carry-skip adders), que ofrecen diferentes compromisos entre complejidad y velocidad.

#### 3.1.4 Implementación usando HDL en lógica reconfigurable

**HDL (Hardware Description Language)** como VHDL o Verilog se utiliza para describir y simular el comportamiento de la ALU en lógica reconfigurable, como FPGAs (Field Programmable Gate Arrays). Esto permite prototipar y evaluar diseños antes de su implementación en hardware físico.

### 3.2 Memoria de programa, datos y pila

En un procesador RISC monociclo, la memoria se utiliza para almacenar tanto las instrucciones del programa como los datos que esas instrucciones manipulan. La pila es una estructura de datos que se utiliza para gestionar el flujo de control, como llamadas a subrutinas y almacenamiento temporal de registros.

#### 3.2.1 Análisis con ROM y RAM multipuerto

La **ROM** (Read-Only Memory) y la **RAM** (Random Access Memory) multipuerto permiten múltiples accesos simultáneos a la memoria, lo que es útil en un procesador para mejorar la eficiencia de acceso a instrucciones y datos.

**Ejemplo**: En un procesador con RAM multipuerto, un puerto puede estar leyendo datos mientras otro puerto escribe, aumentando la eficiencia del sistema.

#### 3.2.2 Implementación de pila en software y hardware

La pila puede ser implementada tanto en software como en hardware. La implementación en software utiliza instrucciones para manipular el puntero de la pila y almacenar datos, mientras que la implementación en hardware puede incluir registros dedicados o estructuras de memoria para manejar la pila automáticamente.

**Aplicación**: La implementación de la pila en hardware puede ser más rápida y eficiente, pero es menos flexible que una pila gestionada por software.

#### 3.2.3 Implementación usando HDL en lógica reconfigurable

Usando HDL, es posible diseñar y simular memorias y pilas en lógica reconfigurable. Esto permite probar diferentes configuraciones de memoria y optimizaciones antes de implementar un diseño final.


### 3.3 Archivos de registros

Los archivos de registros son conjuntos de registros que almacenan datos temporales para operaciones rápidas. En un procesador RISC monociclo, el acceso rápido a los registros es fundamental para la ejecución eficiente de las instrucciones.

#### 3.3.1 Análisis con RAM multipuerto

Un archivo de registros utilizando **RAM multipuerto** permite múltiples lecturas y escrituras simultáneas, lo cual es crítico en un procesador donde múltiples instrucciones pueden necesitar acceso a los registros al mismo tiempo.

**Ejemplo**: Un archivo de registros con dos puertos de lectura y uno de escritura permite leer dos operandos y escribir un resultado en un solo ciclo de reloj.

#### 3.3.2 Análisis usando otras arquitecturas

Esto implica explorar otras configuraciones de archivos de registros, como arquitecturas con diferentes números de puertos de acceso o con optimizaciones específicas para ciertas aplicaciones.

#### 3.3.3 Implementación usando HDL en lógica reconfigurable

La implementación de archivos de registros usando HDL en FPGAs permite diseñar y probar diferentes configuraciones y optimizaciones, permitiendo la personalización del procesador para tareas específicas.


### 3.4 Unidad de control

La unidad de control es responsable de dirigir el flujo de datos y las operaciones dentro del procesador, decodificando instrucciones y enviando señales a otros componentes para ejecutar las operaciones requeridas.

#### 3.4.1 Ruta de datos del procesador

La **ruta de datos** es el camino que siguen los datos dentro del procesador, desde los registros a través de la ALU y la memoria, y de vuelta. Diseñar una ruta de datos eficiente es clave para la ejecución rápida de instrucciones.

#### 3.4.2 Microinstrucciones

Las **microinstrucciones** son instrucciones a nivel de hardware que controlan las operaciones básicas dentro del procesador. Una secuencia de microinstrucciones puede implementar una instrucción más compleja a nivel de ensamblador.

#### 3.4.3 Memorias de microcódigo

Las **memorias de microcódigo** almacenan microinstrucciones que implementan instrucciones de máquina. Permiten flexibilidad en el diseño del procesador, ya que se puede cambiar la microprogramación para modificar el conjunto de instrucciones.

#### 3.4.4 Decodificador de instrucción

El **decodificador de instrucción** traduce las instrucciones del programa en señales de control para otros componentes del procesador, asegurando que se ejecuten las operaciones correctas.

#### 3.4.5 Registro de estado

El **registro de estado** almacena banderas y otros indicadores que reflejan el estado actual del procesador, como resultados de operaciones (cero, negativo, desbordamiento, etc.).

#### 3.4.6 Análisis de banderas para determinar condiciones

El análisis de **banderas** implica usar los valores en el registro de estado para tomar decisiones sobre el flujo de control, como saltos condicionales.

#### 3.4.7 Autómata de control

El **autómata de control** es un diagrama o máquina de estados que representa las diferentes etapas de operación del procesador y las transiciones entre ellas.

#### 3.4.8 Implementación usando HDL en lógica reconfigurable

El uso de HDL para diseñar la unidad de control permite una implementación flexible y modificable en lógica reconfigurable, como FPGAs.


### 3.5 Implementación de procesador RISC monociclo

Esta sección cubre la implementación práctica de un procesador RISC monociclo utilizando herramientas y técnicas modernas.

#### 3.5.1 Implementación usando HDL en lógica reconfigurable

Desarrollar un procesador RISC monociclo usando HDL permite crear prototipos de procesadores en FPGAs, probando y ajustando el diseño antes de una implementación física.

#### 3.5.2 Ejecución de programas en los procesadores

Después de la implementación, es crucial ejecutar programas en el procesador para validar su funcionamiento y rendimiento. Esto puede incluir pruebas de programas básicos y complejos para asegurar que todas las instrucciones funcionen correctamente.

#### 3.5.3 Implementación de analizadores lógicos en FPGA para la depuración de programas en ejecución

Los **analizadores lógicos** permiten observar señales dentro del FPGA durante la ejecución de programas, facilitando la depuración y optimización del procesador. Esto es especialmente útil para identificar y corregir errores en la implementación.

---

# Unidad Temática IV: 
## Segmentación de la Ruta de Datos de un Procesador RISC

La segmentación es una técnica utilizada en el diseño de procesadores RISC para mejorar el rendimiento al dividir la ejecución de las instrucciones en varias etapas, permitiendo que múltiples instrucciones se procesen simultáneamente en diferentes etapas del ciclo de reloj. Esto aumenta la eficiencia y el rendimiento del procesador, pero también introduce ciertos desafíos conocidos como "riesgos" o "hazards" que deben ser manejados cuidadosamente.


### 4.1 Segmentación

La segmentación divide la ejecución de instrucciones en varias etapas, permitiendo la ejecución simultánea de diferentes partes de múltiples instrucciones.

#### 4.1.1 Etapas de segmentación

En un procesador RISC típico, las etapas de segmentación suelen incluir:

- **Fetch (IF)**: Se obtiene la instrucción de la memoria.
- **Decode (ID)**: Se decodifica la instrucción y se leen los registros fuente.
- **Execute (EX)**: Se ejecuta la instrucción, ya sea una operación aritmética o lógica.
- **Memory Access (MEM)**: Si la instrucción requiere acceso a la memoria, se realiza en esta etapa.
- **Write Back (WB)**: El resultado se escribe de vuelta en un registro.

Cada etapa se lleva a cabo en un ciclo de reloj separado, permitiendo que varias instrucciones estén en diferentes etapas de ejecución al mismo tiempo, incrementando así el throughput del procesador.

#### 4.1.2 Registros inter etapa

Los **registros inter etapa** son registros especiales que se utilizan para almacenar datos temporales entre las etapas de segmentación. Estos registros permiten que cada etapa opere independientemente de las demás, reteniendo los datos necesarios para la siguiente etapa de la instrucción.

**Ejemplo**: Un registro inter etapa puede almacenar el valor leído de un registro en la etapa de decodificación (ID) hasta que se necesite en la etapa de ejecución (EX).

#### 4.1.3 Implementación usando HDL en lógica reconfigurable

La segmentación puede ser implementada en lógica reconfigurable usando HDL (Hardware Description Language). En este proceso, se describen las diferentes etapas de segmentación y los registros inter etapa para simular y verificar el comportamiento de la segmentación antes de implementarlo en un FPGA (Field Programmable Gate Array).


### 4.2 Riesgos (Hazards)

Los riesgos son situaciones que pueden causar problemas en un procesador segmentado, resultando en una ejecución incorrecta o ineficiente de instrucciones. Existen tres tipos principales de riesgos: estructurales, de datos y de control.

#### 4.2.1 Riesgo estructural

Un **riesgo estructural** ocurre cuando dos o más instrucciones necesitan acceder al mismo recurso de hardware simultáneamente, y el recurso no está disponible para ambas. Por ejemplo, si dos instrucciones necesitan acceder a la memoria en la misma etapa del ciclo de reloj, esto puede causar un conflicto.

**Ejemplo**: Si un procesador tiene una sola unidad de acceso a memoria, y dos instrucciones requieren acceder a memoria simultáneamente, se genera un riesgo estructural.

#### 4.2.2 Riesgos de datos

Los **riesgos de datos** ocurren cuando las instrucciones dependen de los resultados de las instrucciones anteriores que aún no se han completado. Existen diferentes tipos de riesgos de datos, como los riesgos de dependencia de lectura después de escritura (RAW, por sus siglas en inglés), donde una instrucción necesita leer un registro que aún no ha sido actualizado por una instrucción anterior.

**Ejemplo**: Si una instrucción suma necesita el resultado de una instrucción de carga anterior que aún no se ha completado, se crea un riesgo de datos.

#### 4.2.3 Método de bypassing

El **bypassing** es una técnica para resolver riesgos de datos al redirigir temporalmente los resultados de una instrucción a otra sin esperar a que los datos se escriban y lean de vuelta desde el registro. Esto ayuda a evitar retrasos innecesarios.

**Aplicación**: Si una instrucción suma necesita el resultado de una operación inmediatamente anterior, el resultado puede ser pasado directamente de la ALU a la siguiente instrucción, evitando la espera de una escritura y lectura.

#### 4.2.4 Método de forwarding

El **forwarding** es una forma más específica de bypassing, donde el hardware detecta automáticamente cuando los resultados de una instrucción pueden ser utilizados por una instrucción posterior y los redirige. Esto es manejado por la unidad de control del procesador.

**Ejemplo**: En un procesador segmentado, si una instrucción de suma sigue inmediatamente a una instrucción de carga, el forwarding permite que el resultado de la carga se pase directamente a la ALU sin pasar primero por el banco de registros.

#### 4.2.5 Implementación usando HDL en lógica reconfigurable

El manejo de riesgos, incluyendo bypassing y forwarding, puede ser implementado en lógica reconfigurable utilizando HDL. Este proceso incluye diseñar circuitos de control y lógica que detectan y resuelven riesgos automáticamente.


### 4.3 Riesgo de Control

Los **riesgos de control** ocurren principalmente debido a instrucciones de salto y bifurcación, donde el flujo de ejecución del programa cambia y la siguiente instrucción a ejecutar puede depender de un resultado que aún no se ha calculado.

#### 4.3.1 Predictores de salto

Los **predictores de salto** son componentes de hardware que intentan adivinar el resultado de una instrucción de salto antes de que se conozca, permitiendo que la segmentación continúe sin esperar. 

**Ejemplo**: Un predictor de salto puede "adivinar" que una instrucción de salto condicional será tomada o no, basándose en el comportamiento pasado de saltos similares.

#### 4.3.2 Predicción estática

La **predicción estática** es una forma simple de predicción de saltos que no cambia durante la ejecución del programa. Un método común es asumir siempre que los saltos hacia atrás (looping) se tomarán y que los saltos hacia adelante no se tomarán.

**Ejemplo**: En un bucle, un predictor estático puede asumir que el salto hacia atrás (a la instrucción inicial del bucle) siempre se tomará hasta que se cumpla una condición de salida.

#### 4.3.3 Predicción dinámica

La **predicción dinámica** utiliza información en tiempo real sobre el comportamiento de los saltos para tomar decisiones. Los procesadores modernos a menudo tienen predictores dinámicos que monitorean los resultados de saltos anteriores y ajustan sus predicciones en consecuencia.

**Aplicación**: Un predictor dinámico puede utilizar una tabla de historial de saltos (Branch History Table, BHT) para rastrear si un salto fue tomado o no en ejecuciones anteriores, ajustando su predicción basada en patrones detectados.

#### 4.3.4 Implementación usando HDL en lógica reconfigurable

La implementación de predictores de salto y técnicas para manejar riesgos de control usando HDL en FPGAs permite explorar diferentes estrategias y optimizaciones para minimizar los impactos de los riesgos de control.

---

# Unidad Temática V: 
## Organización del Sistema de Memoria

La organización del sistema de memoria es fundamental en el diseño de computadoras modernas. La eficiencia de la memoria puede afectar significativamente el rendimiento general del sistema. La Unidad Temática V aborda la jerarquía de memoria, los diferentes tipos de memoria y las técnicas de gestión de memoria que se utilizan en la arquitectura RISC.


### 5.1 Jerarquía de la memoria

La **jerarquía de la memoria** es una estructura de niveles de diferentes tipos de memoria en un sistema informático, ordenados según su velocidad y costo. El objetivo es equilibrar el rendimiento del sistema y el costo de la memoria, asegurando que los datos más utilizados estén disponibles en los niveles más rápidos.

#### 5.1.1 Memoria principal

La **memoria principal**, o RAM (Random Access Memory), es donde se almacenan temporalmente los datos y programas que está utilizando el procesador. La RAM es volátil, lo que significa que pierde su contenido cuando se apaga el sistema. Es más rápida que el almacenamiento secundario, pero más lenta y más costosa por bit que la memoria caché.

#### 5.1.2 Memoria caché

La **memoria caché** es una memoria más rápida y pequeña que la RAM, utilizada para almacenar copias de datos que se usan con frecuencia, reduciendo así el tiempo de acceso del procesador a la memoria principal. La caché está más cerca del CPU y opera a velocidades similares, lo que permite un acceso rápido a datos repetidamente necesarios.

**Ejemplo**: En un procesador moderno, los niveles de caché incluyen L1 (más rápida, menor tamaño), L2, y a veces L3, cada uno con mayor capacidad pero menos velocidad.

#### 5.1.3 Memoria virtual

La **memoria virtual** es una técnica que permite a los sistemas operativos utilizar más memoria de la que físicamente tienen, utilizando parte del almacenamiento secundario (disco duro o SSD) como si fuera memoria RAM adicional. Esto permite ejecutar programas más grandes o más programas simultáneamente, pero a un costo de rendimiento debido a la velocidad más lenta del almacenamiento secundario.

#### 5.1.4 Tecnologías de memorias

Las **tecnologías de memoria** se refieren a los tipos de memoria utilizados, como SRAM (Static RAM) para caché, DRAM (Dynamic RAM) para RAM principal, y NAND flash para almacenamiento secundario. Cada tecnología tiene sus propias características de velocidad, costo y durabilidad.


### 5.2 Memoria caché

La **memoria caché** juega un papel crucial en la mejora del rendimiento del procesador al reducir el tiempo necesario para acceder a datos y instrucciones repetidamente utilizados.

#### 5.2.1 Cache hit y miss

- **Cache hit**: Ocurre cuando los datos solicitados por el procesador están presentes en la caché, lo que permite un acceso rápido sin necesidad de ir a la memoria principal.
- **Cache miss**: Ocurre cuando los datos solicitados no están en la caché y deben ser recuperados de la memoria principal, lo que resulta en un tiempo de acceso más largo.

**Ejemplo**: Si el procesador necesita datos de un cálculo anterior y estos están en la caché, se obtiene un cache hit, lo que permite un acceso casi instantáneo.

#### 5.2.2 Estrategia Write Through y Write Back

- **Write Through**: Cada vez que se escribe un dato en la caché, también se escribe inmediatamente en la memoria principal. Esto garantiza la coherencia entre la caché y la memoria principal, pero puede ser lento debido a la escritura simultánea.
- **Write Back**: Los datos modificados en la caché no se escriben en la memoria principal hasta que se expulsan de la caché. Esto mejora el rendimiento porque reduce las escrituras a la memoria principal, pero introduce complejidad para garantizar la coherencia.

#### 5.2.3 Caché con mapeo directo

La **caché con mapeo directo** asigna cada bloque de memoria a una ubicación específica en la caché. Esto simplifica la implementación, pero puede llevar a colisiones frecuentes cuando varios bloques compiten por la misma línea de caché.

#### 5.2.4 Caché asociativa por conjuntos

La **caché asociativa por conjuntos** divide la caché en varios conjuntos, y cada conjunto puede almacenar varios bloques de datos. Cada bloque de memoria puede ser mapeado a cualquier lugar dentro de un conjunto, lo que reduce las colisiones en comparación con el mapeo directo.

#### 5.2.5 Caché completamente asociativa

En una **caché completamente asociativa**, cualquier bloque de memoria puede ser almacenado en cualquier línea de la caché. Esto minimiza las colisiones, pero requiere un hardware más complejo para decidir en qué línea almacenar un nuevo bloque.

#### 5.2.6 Algoritmos de sustitución

Los **algoritmos de sustitución** determinan qué bloque de caché se reemplaza cuando se produce un cache miss. Los algoritmos comunes incluyen:
- **LRU (Least Recently Used)**: Reemplaza el bloque que no ha sido utilizado en el mayor tiempo.
- **FIFO (First In, First Out)**: Reemplaza el bloque que ha estado más tiempo en la caché.
- **Random**: Selecciona un bloque al azar para reemplazar.

#### 5.2.7 Implementación usando HDL en lógica reconfigurable

El diseño de la caché y sus algoritmos de manejo pueden implementarse usando HDL en lógica reconfigurable, permitiendo simulaciones precisas y la personalización del diseño para aplicaciones específicas.


### 5.3 Memoria virtual

La **memoria virtual** permite a los sistemas operativos gestionar la memoria de manera más eficiente y proporcionar a los programas la ilusión de tener más memoria disponible de la que realmente existe.

#### 5.3.1 Paginación

La **paginación** es una técnica que divide la memoria virtual en bloques de tamaño fijo llamados **páginas** y la memoria física en bloques de tamaño correspondiente llamados **marcos de página**. La paginación permite que las páginas de un proceso se mapeen a marcos de página no contiguos en la memoria física, facilitando el uso eficiente del espacio de memoria y evitando problemas de fragmentación.

#### 5.3.2 Unidad de Administración de Memoria (MMU)

La **Unidad de Administración de Memoria (MMU)** es un componente de hardware que traduce direcciones virtuales a direcciones físicas y gestiona la protección de la memoria. La MMU utiliza tablas de páginas para realizar esta traducción.

#### 5.3.3 Tablas de páginas

Las **tablas de páginas** son estructuras de datos que mantienen el mapeo entre las páginas virtuales y los marcos de página físicos. Cada entrada de la tabla de páginas contiene la dirección del marco de página físico correspondiente y otros bits de control, como los permisos de acceso.

#### 5.3.4 Arquitecturas de TLB

La **TLB (Translation Lookaside Buffer)** es una caché especial dentro de la MMU que almacena mapeos recientes de direcciones virtuales a direcciones físicas, acelerando las traducciones de direcciones al reducir la necesidad de buscar en la tabla de páginas cada vez.

#### 5.3.5 Algoritmos de reemplazo de páginas

Los **algoritmos de reemplazo de páginas** determinan qué página en la memoria física se reemplaza cuando se necesita cargar una nueva página desde el almacenamiento secundario. Los algoritmos comunes incluyen:
- **FIFO**: Reemplaza la página que ha estado más tiempo en la memoria.
- **LRU**: Reemplaza la página que no ha sido utilizada en el mayor tiempo.
- **Algoritmo de reloj**: Similar a LRU pero más eficiente en términos de hardware.
