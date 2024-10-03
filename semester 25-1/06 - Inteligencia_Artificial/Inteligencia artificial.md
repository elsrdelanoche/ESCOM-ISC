# Contenido

- 1.Introducción a la inteligencia artificial
	- 1.1 Inteligencia
		- 1.1.1 Tipos de inteligencia
	- 1.2 Historia de la inteligencia Artificial
	- 1.3 Problemas, áreas y aplicaciones de la inteligencia artificial
	- 1.4 Agentes inteligentes
		- 1.4.1 Estructura
		- 1.4.2 Medio ambiente de trabajo
		- 1.4.3 Clasificación
		- 1.4.4 Aplicaciones
- 2.Algoritmos de búsqueda
	- 2.1 Problemas y espacios de búsqueda
		- 2.1.1 Caracterización de problemas
		- 2.1.2 Espacios de búsqueda
	- 2.2 Algoritmos de búsqueda no informados
		- 2.2.1 Búsqueda en anchura 
		- 2.2.2 Búsqueda en profundidad
	- 2.3 Algoritmos de búsqueda informados 
		- 2.3.1 Heurística 
		- 2.3.2 Algoritmo de escalada simple y primero el mejor 
		- 2.3.3 Algoritmo A*
	- 2.4 Búsqueda adversaria 
		- 2.4.1 Algoritmo Min Max 
		- 2.4.2 Algoritmo Poda Alpha Beta
	- 2.5 Comparación de algoritmos búsqueda
- 3.Modelos de representación del conocimiento
	- 3.1 Conocimiento 
		- 3.1.1 Características y taxonomía 
		- 3.1.2 Modelos y sus características 
	- 3.2 Lógica de primer orden 
		- 3.2.1 Razonamiento en la lógica proposicional 
		- 3.2.2 Lenguaje de predicados 
	- 3.3 Razonamiento basado en reglas 
		- 3.3.1 Reglas de inferencia 
		- 3.3.2 Encadenamiento hacia adelante y hacia atrás 
		- 3.3.3 Ontologías 
	- 3.4. Modelos de llenado de ranuras 
		- 3.4.1 Redes semánticas y marcos 
		- 3.4.2 Dependencia conceptual y guiones 
	- 3.5 Modelos de conocimiento incierto e incompleto 
		- 3.5.1 Factores de certidumbre 
		- 3.5.2 Lógica difusa
- 4. Aprendizaje de máquina
	- 4.1 Aprendizaje 
		- 4.1.1 Aprendizaje supervisado 
		- 4.1.2 Aprendizaje no supervisado 
	- 4.2 Características de un conjunto de datos 
		- 4.2.1 Tipos de características 
		- 4.2.2 Problemas en los conjuntos de datos: tamaño de la muestra, desequilibrio de clases, complejidad, cambio del conjunto de datos, datos ruidosos, valores atípicos y costo 
		- 4.2.3 Selección de características: relevancia, redundancia y métodos de selección 
	- 4.3 Algoritmos de clasificación  
		- 4.3.1 Algoritmos basados en distancia: KNN y clasificador de mínima distancia 
		- 4.3.2 Arboles de decisión: id3 y C4.5 
		- 4.3.3 Algoritmos estadísticos: Naive Bayes 
	- 4.4. Algoritmos de agrupamiento 
		- 4.4.1 Algoritmos basados en distancia: K-Medias y Min-Max 
		- 4.4.2 Algoritmos basados en jerarquías 
	- 4.5 Métodos de validación 
		- 4.5.1 Métodos de validación de algoritmos de clasificación: Entrenamiento y prueba, validación cruzada y matriz de confusión 
		- 4.5.2 Métodos de validación de algoritmos de agrupamiento: Medidas de validación internas y externas
- 5 Algoritmos bioinspirados
	- 5.1 Algoritmos genéticos 
		- 5.1.1 Trasfondo biológico 
		- 5.1.2 Algoritmo genético con representación binaria 
		- 5.1.3 Operadores genéticos para representaciones reales y permutaciones 
		- 5.1.4 Aplicaciones 
	- 5.2 Redes neuronales 
		- 5.2.1 Modelo biológico y modelo artificial 
		- 5.2.2 Modelo de McCulloch-Pitts 
		- 5.2.3 Perceptrón simple y multicapa 
		- 5.2.4 Propagación hacia atrás 
		- 5.2.5 Aplicaciones

---
# **1.Introducción a la inteligencia artificial**
## **1.1 Inteligencia**
**Inteligencia** es la **capacidad** o facultad **para entender, razonar o relacionar ideas**, así como para resolver problemas, aprender de las experiencias o pensar de forma abstracta en distintos campos.
"La inteligencia es la capacidad del alma para pensar y razonar". **Aristóteles**. **Filósofo griego.** **S. IV a.C.**
### **1.1.1 Tipos de inteligencia**
Según Howard Gardner, existen varios tipos de inteligencias múltiples bien definidas, cada una de las cuales se distingue por habilidades y capacidades particulares. Entender cuáles son las inteligencias múltiples de esta teoría es fundamental para apreciar y desarrollar la diversidad de las capacidades humanas en el aprendizaje y en distintos aspectos de la vida. 
- **Inteligencia lingüística-verbal**. Es la capacidad para usar el lenguaje en todas sus expresiones y manifestaciones.
- **Inteligencia musical**. Es la capacidad de percibir y expresarse con formas musicales.
- **Inteligencia lógico-matemática**. Es la capacidad de resolver cálculos matemáticos y poner en práctica un razonamiento lógico.
- **Inteligencia corporal cinestésica**. Es la capacidad para expresar ideas, emociones y sentimientos con el cuerpo.
- **Inteligencia espacial**. Es la capacidad para percibir el entorno visual y espacial.
- **Inteligencia intrapersonal**. Es la capacidad para desarrollar un conocimiento profundo de uno mismo.
- **Inteligencia interpersonal**. Es la capacidad para relacionarse con los demás, tomando como base la empatía y la interacción social.
- **Inteligencia naturalista**. Es la capacidad de observar y estudiar los elementos que componen la naturaleza (objetos inanimados, animales y plantas).

## **1.2 Historia de la inteligencia Artificial**
La historia de la inteligencia artificial **comenzó en 1943** con la publicación del artículo «A Logical Calculus of Ideas Immanent in Nervous Activity» de Warren McCullough y Walter Pitts. En ese trabajo, los científicos presentaron el primer modelo matemático para la creación de una red neuronal.

- El **primer ordenador de red neuronal**, Snarc, fue creado en 1950 por dos alumnos de Harvard: Marvin Minsky y Dean Edmonds. Ese mismo año, Alan Turing publicó el Test de Turing, que todavía se utiliza hoy para valorar las IA.

- En 1952, Arthur Samuel creó un software capaz **de aprender a jugar al ajedrez** de forma autónoma. El término inteligencia artificial fue utilizado por primera vez en la conferencia «Dartmouth Summer Research Project on Artificial Intelligence» de John McCarthy en 1956.

- En ese acto, los investigadores presentaron los objetivos y la visión de la IA. Muchos consideran esta conferencia como **el verdadero nacimiento** de la inteligencia artificial, tal y como se conoce hoy en día.

- En 1959, Arthur Samuel acuñó **el término Machine Learning** mientras trabajaba en IBM. Por su parte, John McCfarthy y Marvin Minsky fundaron el MIT Artificial Intelligence Project. En 1963, John McCarthy también creó el «AI Lab» en la Universidad de Stanford.

- En los siguientes años, se cernieron dudas sobre el campo de la IA. En 1966, **el informe estadounidense ALPAC** puso de manifiesto la falta de avances en la investigación de la traducción automática destinada a traducir simultáneamente la lengua rusa en el contexto de la Guerra Fría. Muchos proyectos financiados por el gobierno estadounidense fueron cancelados.

- Del mismo modo, en 1973, el gobierno británico publicó su informe «Lighthill» en el que destacaba las decepciones de la investigación en IA. Una vez más, los proyectos de investigación fueron reducidos por los recortes presupuestarios. Este periodo de duda duró hasta 1980, y ahora se denomina el «**primer invierno de la IA**«.

- Ese invierno terminó con **la creación de R1 (XCON)** por parte de Digital Equipment Corporations. Este sistema comercial experto está diseñado para configurar los pedidos de nuevos sistemas informáticos, y provocó un auténtico auge de las inversiones que se prolongó durante más de una década.

- Japón y Estados Unidos hicieron grandes inversiones en la investigación de la IA. Las empresas se gastaron **más de mil millones de dólares al año** en sistemas expertos y el sector no paraba de crecer.

- Desgraciadamente, el mercado de las máquinas “Lisp” se desplomó en 1987 al surgir alternativas más baratas. Este fue **el «segundo invierno de la IA»**. Las empresas perdieron el interés por los sistemas expertos. Los gobiernos de Estados Unidos y Japón abandonaron sus proyectos de investigación y se gastaron miles de millones de dólares para nada.

- _Diez años después, en 1997, la historia de la IA estuvo marcada por un acontecimiento importante. La IA Deep Blue de IBM triunfó sobre el campeón mundial de ajedrez Gary Kasparov. Por primera vez, el hombre fue derrotado por la máquina._

- Diez años después, los avances tecnológicos permitieron **el resurgimiento de la inteligencia artificial**. En 2008, Google hizo grandes avances en el reconocimiento de voz y lanzó esa función en sus aplicaciones para smartphones.

- En 2012, Andrew Ng alimentó una red neuronal con **10 millones de vídeos de YouTube** como serie de datos de entrenamiento. Gracias al Deep Learning, esta red neuronal aprendió a reconocer un gato sin que se le enseñara lo que es un gato. Este fue el inicio de una nueva era para Deep Learning.

- En 2016 se produjo otra victoria de la IA sobre el ser humano, con **el triunfo del sistema AlphaGo** de Google DeepMind sobre Lee Sedol, el campeón de Go. La inteligencia artificial también conquistó el campo de los videojuegos, especialmente con DeepMind AlphaStar en Starcraft u OpenAI Five en Dota 2.

- Actualmente, empresas de todos los sectores utilizan el Deep Learning y el Machine Learning para infinidad de aplicaciones. La IA no deja de avanzar y sorprender con su rendimiento. El **sueño de la inteligencia artificial general** se acerca cada vez más a la realidad.

## 1.3 Problemas, áreas y aplicaciones de la inteligencia artificial
El impacto de la inteligencia artificial en la sociedad es profundo y abarca diversas áreas, entre ellas la empresarial. El uso de [**herramientas de inteligencia artificial**](https://www.apd.es/herramientas-ia-productividad-empresa/) ha demostrado ser una herramienta poderosa para impulsar la eficiencia en organizaciones. Los **campos de aplicación** de la [**inteligencia artificial en las empresas**](https://www.apd.es/el-gran-impacto-de-la-inteligencia-artificial-en-las-empresas/) son muchos, y algunos están orientados a satisfacer necesidades muy distintas.

### **1. Machine learning o aprendizaje automático**
El **Machine Learning es la rama de la ciencia que busca el desarrollo de técnicas de inteligencia artificial** que permitan a los ordenadores aprender por sí mismos. Para ello se crean programas que pueden **generalizar ciertas respuestas** a partir de información sin estructurar, que se suministra como ejemplos. Con ello, se induce al conocimiento por parte del ordenador.

### **2. Fuzzy logic o lógica difusa**
Conocida como **lógica heurística**. Esta técnica incide en lo relativo de un escenario observado como posición diferencial. Es un tipo de lógica que **toma dos valores al azar**, contextualizados y relacionados entre sí. Por ejemplo, considerar una persona de 2 metros como alta al haber tomado antes el valor de una persona de un metro como baja.

### **3. Vida artificial**
Consiste en el **estudio de la vida y de los entornos artificiales** que muestran cualidades propias de los seres vivos en entornos de simulación. Una de las técnicas de inteligencia artificial con más proyección de futuro en el ámbito de la investigación.

### **4. Sistemas expertos**
Hace referencia a un sistema de información que se basa en el conocimiento de un área de aplicación de gran **complejidad** y muy específica. Sirve como asistente consultor y experto para los usuarios de su interfaz.

> Se recurre a la IA cuando se considera útil incorporar a un sistema de ordenadores un conocimiento o comportamiento ante los eventos que serían más propios de un ser humano

Son entornos que **proporcionan respuestas sobre problemáticas muy específicas**, pudiendo realizar inferencias muy parecidas a las de un ser humano acerca de los conocimientos concretos consultados.

### **5. Data Mining o minería de datos**
Esta técnica consiste en la **extracción discriminada de información que se encuentra implícita en los datos manejados**. Dicha información, desconocida previamente, se destina a ser utilizada en algún otro proceso. La minería de datos **sondea, prepara y explora** los datos para poder extraer alguna información que se oculte en ellos.

### **6. Redes Bayesianas**
También conocidas como redes de creencia, estas redes son un **modelo probabilístico multivariado**, que relaciona un conjunto de variables de tipo aleatorio usando un grafo dirigido para indicar una influencia casual de manera explícita.
Con un motor de actualización de las probabilidades llamado el **Teorema de Bayes**, estas redes se convierten en una herramienta **muy útil a la hora de calcular probabilidades** en casos de nuevas evidencias. Es uno de los tipos de red que se denominan de tipo casual.

### **7. Ingeniería del conocimiento**
Consiste en **generar un nuevo conocimiento que no existía previamente**. Se hace a partir de la información que se contiene en bases de datos de documentos y mediante el cruce de contenido de los archivos.

Es una técnica que se basa en la **teoría de «actor-red»**, poniendo de manifiesto redes y creando nuevas. También implica el ejercicio de la teoría de la «traducción-traslación», acercando y poniendo en relación los actores, con el objetivo de producir una traducción en la que llevar los enunciados o modalidades hacia nuevos estadios evolutivos.

### **8. Redes neuronales artificiales**
Las **redes neuronales** son un paradigma del aprendizaje y los procesamientos automáticos, inspirado todo ello en el **modo en que funciona el sistema nervioso de los animales**. Consiste en un sistema de interconexión de neuronas en una red que colaboran entre ellas para crear una respuesta de salida.

### **9. Sistemas reactivos**
Estos son sistemas de **aplicación crítica**, y un fallo o error puede acarrear consecuencias graves. Al punto de poner en riesgo las vidas humanas o el resultado de importantes inversiones económicas.
Su comportamiento en estos entornos, de tiempo real, se determina tanto por la sucesión de acciones que se ejecutan como por el momento en que cada una de ellas se suceden y son procesadas.

### **10. Sistemas basados en reglas**
Consisten en **modelos de representación del conocimiento** que se usan de manera amplia. Son apropiados para escenarios en los que el conocimiento que se necesita representar surge de manera natural en una estructura de reglas.

### **11. Razonamiento basado en casos**
Es un **proceso para solucionar cuestiones basándose en soluciones de problemáticas anteriores**. El razonamiento que se basa en casos se sirve de analogías para los nuevos razonamientos.
Se considera que no solo es una poderosa herramienta de **cálculo para ordenadores**. Sino que los seres humanos usan el mismo principio para la solución de problemas cotidianos.

### **12. Técnicas de Representación de Conocimiento**
Es un sistema que sirve para **analizar el modo de pensar de manera formal**. Se usa un entorno de símbolos para la representación de un dominio de discurso, junto a las funciones que puedan inferir sobre los objetos procesados.

### **13. Redes semánticas**
Son **maneras de representación del conocimiento lingüístico** para las que los conceptos y las interrelaciones entre ellos se representan mediante grafos. Son utilizadas para la representación de **mapas conceptuales y mentales**, entre otras funciones.

### **14. Lingüística computacional**
Es un campo multidisciplinar de la lingüística aplicada en la informática. Se sirve de los sistemas informáticos para el **estudio y el tratamiento del lenguaje**. Para ello, se intenta modelar de manera lógica el lenguaje natural desde un punto de vista programable.

### **15. Procesamiento del lenguaje natural**
El **procesamiento del lenguaje natural (NLP) es una disciplina de la rama de la ingeniería para la lingüística computacional**. Se utiliza para la **formulación e investigación** de mecanismos de eficacia informática para servicios de comunicación entre las personas o entre ellas y las máquinas usando lenguajes naturales.

Los campos de desarrollo e investigación de la inteligencia artificial sirven para el desarrollo de mecanismos y aplicaciones que permitan diseñar nuevos métodos de trabajar y comunicar con las máquinas y los entornos informáticos. El **futuro de la inteligencia artificial** en las empresas promete una mayor integración y colaboración entre humanos y máquinas. Ya son muchas las [**empresas punteras que utilizan el big data y la inteligencia artificial**](https://www.apd.es/empresas-big-data-e-inteligencia-artificial/), convirtiendo en realidad lo que hasta hace muy poco formaba parte de la ficción.

Ante esta reciente, pero muy grande, difusión del uso de la **inteligencia artificial** en el trabajo y la intimidad, algunos **expertos en tecnología** han comentado su preocupación que tiene que ver con los siguientes puntos:
- Desinformación. Dado que los **avances de la inteligencia artificial** son cada vez mejores y que en poco tiempo se nota la calidad que han encontrado, es muy probable que dentro de poco sea casi imposible distinguir un producto fotográfico, un texto o un video real de uno falso. Esto representa una amenaza al momento de verificar datos y fomenta la **desinformación**, lo cual puede provocar importantes conflictos en la sociedad. De por sí, la [batalla contra las fake news](https://www.gq.com.mx/actualidad/articulos/fake-news-verdad-mit-estudio/10702) lleva tiempo sucediendo en **internet**, pero los pocos filtros que se han podido diseñar se quedarán cortos ante los alcances de la **IA**.
- Desempleo. Aunque esto parezca salido de una novela de ciencia ficción, entre mayor uso de **inteligencia artificial** tengamos en los empleos, menor será la necesidad de personal por parte de las empresas; una amenaza para muchas profesiones que podrían ser cada vez menos necesarias.
- Competencia sin límites. Debido a que compañías como Microsoft y Google están en constante competencia por tener los **últimos avances en inteligencia artificial,** la sensación de carrera podría provocar un crecimiento desmedido y sin suficiente contraparte ética por lo apresurado de su desarrollo. “Creo que hasta que hayan entendido si pueden controlarlo, no deben desarrollar más esto”, dijo **Geoffrey Hinton**.
## 1.4 Agentes inteligentes
Con la evolución de la IA se han integrado nuevas áreas de estudio. Entre las aplicaciones más conocidas se encuentran las redes neuronales, la robótica, el aprendizaje automático o el reconocimiento de patrones; sin embargo, desde hace algunos años han surgido otras que integran a la sociología y hasta la etología. Una de ellas es lo que se conoce como la “teoría de agentes inteligentes”.
Un agente inteligente basado en _software_ es una entidad que exhibe un comportamiento autónomo mientras está situado en un sistema de información que puede ser computacional.
### 1.4.1 Estructura
La arquitectura de un agente es la organización de los componentes del mismo; es decir, su estructura de información, las operaciones que puede hacer, el control que existe entre las acciones que estén programadas, etcétera. Así, encontramos que hasta el agente más sencillo requiere de un análisis y una abstracción detallada.

Dentro de las arquitecturas que actualmente se manejan en IA encontramos que un agente debe estar dotado de ciertas capacidades, entre las que encontramos la percepción —una función que permite que el agente conozca su ambiente— y una función de acción, que le permitirá decidir qué debe hacer.

Los robots y otros agentes situados en un mundo físico pueden emplear _hardware_ para realizar la función de percepción, ya sea a través de videocámaras, sensores de infrarrojos o sonares; mientras que un agente basado en un ambiente virtual, como puede ser un _software_, puede hacer uso de instrucciones y programas asociados al sistema operativo en el que interactúa.
### 1.4.2 Medio ambiente de trabajo
En su libro _Inteligencia artificial. Un enfoque moderno_, Russell y Norvig presentan la siguiente definición: “Un agente es un sistema computacional persistente, capaz de actuar autónomamente para encontrar sus objetivos o metas, cuando está situado en un ambiente”.

Bajo esta definición, un agente es visto como una serie de entradas del ambiente donde está situado, y produce acciones como salida en respuesta a su percepción. Estas acciones modifican el ambiente en una interacción que suele ser continua e indeterminada, lo que refleja la persistencia.

Un ambiente es el espacio donde un agente, o grupo de ellos, está situado. Ese ambiente no tiene que ser necesariamente físico; podría ser un sistema operativo o la World Wide Web. Lo realmente importante es la interacción del agente con su ambiente a través de la acción y la percepción. Algunas propiedades de los posibles ambientes están dadas en los términos de accesibilidad, determinismo, periodicidad, dinamismo y continuidad; estas propiedades caracterizan el ambiente de manera cualitativa; no son exclusivas y pueden existir combinaciones entre ellas.

Entre dichos ambientes, se encuentran el ajedrez, los sistemas de análisis de imágenes, los tutores, los brazos robóticos o los sistemas de diagnóstico.
### 1.4.3 Clasificación
Los agentes inteligentes se clasifican en 6 [tipos](https://www.ceupe.com/blog/tipos-de-tecnologias-de-la-informacion.html) diferentes, donde cada uno distingue su utilidad y características que lo definen:

1. **Agente de reactivo simple:** Cuando una percepción en concreto coincide con una regla programada, el agente responde según la forma en que fue predispuesto. Este accionar se conoce como _condición-acción_.

2. **Agente reactivo basado en modelo:** Este tipo de agente permite simular su acción de respuesta y sus diversas interacciones en un entorno preparado. De esta forma se estudia su comportamiento y sus efectos en el espacio de actuación.

3. **Agente basado en metas:** Combina características del agente reactivo simple y agente reactivo basado en modelo. En este caso, este tipo de agente tiene un objetivo en concreto, por lo tanto, está programado para buscar la vía más óptima y planificar un conjunto de acciones para cumplir dicho propósito.

4. **Agente basado en utilidad:** Este agente tiene varios propósitos como sistema inteligente, además, posee una herramienta para medir el valor de su comportamiento en el cumplimiento de sus metas establecidas. Sus estándares de conducta garantizan alta calidad en sus acciones.

5. **Agente que aprende:** Es un tipo de agente que busca aprender de sus acciones mientras se encuentra en funcionamiento. Es un sistema altamente complejo, ya que está programado para interactuar con el mundo real, además de tener preestablecidas varias metas a alcanzar. Posee en su interior un elemento que indica el éxito de la entidad, y tiene la capacidad de interactuar en entornos que no conoce.

6. **Agente de consulta:** Se dedica a responder consultas por parte de las personas que interactúan con este sistema. Tiene la peculiaridad de **crear varios agentes**, y dividir la pregunta del usuario en varias tareas para su respectiva solución. Además, en caso de que los agentes asignados no sean capaces de responder con exactitud la incógnita enviada, se crearán más agentes y se buscarán en más bases de datos para ofrecer una **resolución completa de la problemática**.
### 1.4.4 Aplicaciones
- Mantenimiento preventivo y correctivo de diferentes tipos de maquinaria.
- Aplicación en la gestión de riesgos.
- Para el cuidado de la reputación online.
- Ayuda en los procesos internos de la inteligencia territorial.
- Sistemas de análisis de la competencia laboral.
- Elaboración de agentes con la capacidad de mantener una comunicación fluida con usuarios.
# 2.Algoritmos de búsqueda
## 2.1 Problemas y espacios de búsqueda
Podemos pensar en una variedad de problemas que van desde cómo alcanzar una fuente de comida situada a cierta distancia y a la que no se puede ir directamente, hasta cómo resolver un pequeño juego como podría ser el famoso cubo de Rubik, o resolver el problema matemático de encontrar la solución a una ecuación numérica. 

Lo que consideremos o no solución dependerá del contexto concreto del problema, y puede ser, por ejemplo, el conjunto de acciones que nos llevan a cumplir cierta propiedad, conseguir cierto objetivo, o verificar ciertas restricciones.

Una de las aproximaciones más generales y sencillas de formalizar un problema y sus posibles mecanismos de solución es por medio de lo que se denomina **espacio de estados**. Antes de definir formalmente en qué consiste este espacio, observemos que en todo momento estamos tratando con métodos en los que la resolución de los problemas se dan de forma dinámica, es decir, se supone que se produce una evolución temporal, que pasa por etapas, que nos permite llegar de la situación inicial en la que el problema se presenta hasta una situación final en la que se ha encontrado la solución del mismo. Es precisamente esta dinámica, en la que aplicamos las acciones u operaciones de las que disponemos, la que permite ir modificando cada situación posible para llevarnos desde el inicio a la solución. Simplemente, denominaremos **estado** a la _representación de los elementos que describen el problema en un momento dado_, es decir, a la situación en que se encuentra o se podría encontrar el problema en cada instante de tiempo.
### 2.1.1 Caracterización de problemas
Una de las aproximaciones más generales y sencillas de formalizar un problema y sus posibles mecanismos de solución es por medio de lo que se denomina **espacio de estados**. Antes de definir formalmente en qué consiste este espacio, observemos que en todo momento estamos tratando con métodos en los que la resolución de los problemas se dan de forma dinámica, es decir, se supone que se produce una evolución temporal, que pasa por etapas, que nos permite llegar de la situación inicial en la que el problema se presenta hasta una situación final en la que se ha encontrado la solución del mismo. Es precisamente esta dinámica, en la que aplicamos las acciones u operaciones de las que disponemos, la que permite ir modificando cada situación posible para llevarnos desde el inicio a la solución. Simplemente, denominaremos **estado** a la _representación de los elementos que describen el problema en un momento dado_, es decir, a la situación en que se encuentra o se podría encontrar el problema en cada instante de tiempo.
![[IA_Caracteristicas.excalidraw]]
### 2.1.2 Espacios de búsqueda
Normalmente, los algoritmos que vamos a ver se basan en la suposición de que el espacio de búsqueda tiene la estructura de un grafo dirigido: cada **nodo** del grafo representa uno de los estados del espacio, y dos nodos están conectados si existe una forma de ir de uno al otro por medio de una acción.

Normalmente, cuando resolvemos el problema a partir de un estado particular, podemos construir un árbol que se construye partiendo del estado inicial y donde en cada nivel se añaden los estados que se pueden alcanzar desde los estados del nivel anterior (y que, en consecuencia, puede contener estados repetidos). En este caso, la **profundidad** (dd, de **depth**) del árbol es la longitud máxima de los caminos que se pueden construir desde cualquier nodo a la raíz; y el **factor de ramificación** (b, de **branch**) del árbol es el máximo número de sucesores que puede tener un nodo del árbol.

En un árbol, los sucesores inmediatos de un nodo (salvo las **hojas**, claro, que son los nodos terminales) se llaman **hijos**, el predecesor de un nodo (salvo la **raíz**, que no tiene predecesor), que es único, se llama **padre**, y los nodos que tienen el padre común se llaman **hermanos**.
![[IA_EspaciosBusqueda.excalidraw]]

## 2.2 Algoritmos de búsqueda no informados
La búsqueda no informada consiste en la selección e implementación de estrategias de búsqueda de un estado solución a partir de un estado inicial sin introducir al algoritmo de solución conocimiento sobre el impacto de las transiciones en la exploración del espacio de estados.
### 2.2.1 Búsqueda en anchura (BFS)
La búsqueda en anchura (BFS, breadth-first search) provee un algoritmo simple (basado en el recorrido de árboles por niveles) para encontrar un estado solución desde un estado inicial.

Al implementarse mediante el recorrido por niveles, se requiere una estructura cola (FIFO, first-in, first-out)
- En implementaciones multiagente, es posible que se requiera mantener la cola generada después de visitar (procesar) un nodo.


``` python
función BFS : nodo t;
	retorna ruta //solucion

	Q <- Cola() //Frontera
	Q.encolar(t)
	mientras ! Q.cola_vacia() do
		//retorna el primer elemento de la cola
		t <- Q.desencolar()
		//revisar si es estado solución
		si estado_objetivo(t)==verdadero
			return reconstruir_solución(t)
		t.hijos=expandir_nodo(t)
		para cada H en t.hijos(t)	
			Q.encolar(h)
		fin_para
	fin_mientras
	retornar FALLO //p.ej. NULL o none
```

Ejemplo: Búsqueda de anchura
![[IA_BFS.excalidraw]]
### 2.2.2 Búsqueda en profundidad
Una búsqueda en profundidad (DFS) es un algoritmo de búsqueda para lo cual recorre los nodos de un grafo. Su funcionamiento consiste en ir expandiendo cada uno de los nodos que va localizando, de forma recurrente (desde el nodo padre hacia el nodo hijo). Cuando ya no quedan más nodos que visitar en dicho camino, regresa al nodo predecesor, de modo que repite el mismo proceso con cada uno de los vecinos del nodo. Cabe resaltar que si se encuentra el nodo antes de recorrer todos los nodos, concluye la búsqueda.

- 2.3 Algoritmos de búsqueda informados 
- 2.3.1 Heurística 
- 2.3.2 Algoritmo de escalada simple y primero el mejor 
- 2.3.3 Algoritmo A*
	- 2.4 Búsqueda adversaria 
		- 2.4.1 Algoritmo Min Max 
		- 2.4.2 Algoritmo Poda Alpha Beta
	- 2.5 Comparación de algoritmos búsqueda
- 3.Modelos de representación del conocimiento
	- 3.1 Conocimiento 
		- 3.1.1 Características y taxonomía 
		- 3.1.2 Modelos y sus características 
	- 3.2 Lógica de primer orden 
		- 3.2.1 Razonamiento en la lógica proposicional 
		- 3.2.2 Lenguaje de predicados 
	- 3.3 Razonamiento basado en reglas 
		- 3.3.1 Reglas de inferencia 
		- 3.3.2 Encadenamiento hacia adelante y hacia atrás 
		- 3.3.3 Ontologías 
	- 3.4. Modelos de llenado de ranuras 
		- 3.4.1 Redes semánticas y marcos 
		- 3.4.2 Dependencia conceptual y guiones 
	- 3.5 Modelos de conocimiento incierto e incompleto 
		- 3.5.1 Factores de certidumbre 
		- 3.5.2 Lógica difusa
- 4. Aprendizaje de máquina
	- 4.1 Aprendizaje 
		- 4.1.1 Aprendizaje supervisado 
		- 4.1.2 Aprendizaje no supervisado 
	- 4.2 Características de un conjunto de datos 
		- 4.2.1 Tipos de características 
		- 4.2.2 Problemas en los conjuntos de datos: tamaño de la muestra, desequilibrio de clases, complejidad, cambio del conjunto de datos, datos ruidosos, valores atípicos y costo 
		- 4.2.3 Selección de características: relevancia, redundancia y métodos de selección 
	- 4.3 Algoritmos de clasificación  
		- 4.3.1 Algoritmos basados en distancia: KNN y clasificador de mínima distancia 
		- 4.3.2 Arboles de decisión: id3 y C4.5 
		- 4.3.3 Algoritmos estadísticos: Naive Bayes 
	- 4.4. Algoritmos de agrupamiento 
		- 4.4.1 Algoritmos basados en distancia: K-Medias y Min-Max 
		- 4.4.2 Algoritmos basados en jerarquías 
	- 4.5 Métodos de validación 
		- 4.5.1 Métodos de validación de algoritmos de clasificación: Entrenamiento y prueba, validación cruzada y matriz de confusión 
		- 4.5.2 Métodos de validación de algoritmos de agrupamiento: Medidas de validación internas y externas
- 5 Algoritmos bioinspirados
	- 5.1 Algoritmos genéticos 
		- 5.1.1 Trasfondo biológico 
		- 5.1.2 Algoritmo genético con representación binaria 
		- 5.1.3 Operadores genéticos para representaciones reales y permutaciones 
		- 5.1.4 Aplicaciones 
	- 5.2 Redes neuronales 
		- 5.2.1 Modelo biológico y modelo artificial 
		- 5.2.2 Modelo de McCulloch-Pitts 
		- 5.2.3 Perceptrón simple y multicapa 
		- 5.2.4 Propagación hacia atrás 
		- 5.2.5 Aplicaciones

# Referencias
 [https://www.significados.com/inteligencia/](https://www.significados.com/inteligencia/)  
[https://mexico.unir.net/noticias/educacion/howard-gardner-inteligencias-multiples-creatividad/](https://mexico.unir.net/noticias/educacion/howard-gardner-inteligencias-multiples-creatividad/)  
[https://datascientest.com/es/inteligencia-artificial-definicion](https://datascientest.com/es/inteligencia-artificial-definicion)  
[https://www.apd.es/tecnicas-de-la-inteligencia-artificial-cuales-son-y-para-que-se-utilizan/](https://www.apd.es/tecnicas-de-la-inteligencia-artificial-cuales-son-y-para-que-se-utilizan/)  
[https://www.gq.com.mx/articulo/peligros-de-la-inteligencia-artificial](https://www.gq.com.mx/articulo/peligros-de-la-inteligencia-artificial)  
[https://nuevosdialogos.unam.mx/comentarios/los-agentes-inteligentes-son-parte-de-la-ia/](https://nuevosdialogos.unam.mx/comentarios/los-agentes-inteligentes-son-parte-de-la-ia/)  
[https://www.ceupe.com/blog/agente-inteligente.html](https://www.ceupe.com/blog/agente-inteligente.html)  
[https://www.cs.us.es/~fsancho/Cursos/SVRAI/EspaciosEstados.md.html](https://www.cs.us.es/~fsancho/Cursos/SVRAI/EspaciosEstados.md.html)