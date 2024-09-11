### UNIDAD TEMÁTICA I: Antecedentes del Cómputo en la Nube

### 1.1 Historia del Cómputo en la Nube

El **cómputo en la nube** ha transformado la forma en que las empresas y los usuarios finales acceden a los recursos tecnológicos. A lo largo de los años, su evolución ha pasado de la computación centralizada en mainframes a la virtualización y, finalmente, a la nube.

- **Origen**: La idea de compartir recursos informáticos se remonta a los años 60 con el concepto de **time-sharing**. Sin embargo, el cómputo en la nube, tal como lo conocemos hoy, comenzó a tomar forma con el desarrollo de la **virtualización** y el **internet de alta velocidad**.

- **Pioneros**: Empresas como Amazon, con el lanzamiento de **Amazon Web Services (AWS)** en 2006, y Google y Microsoft, han sido pioneras en el desarrollo de infraestructuras de nube pública.

#### 1.1.1 Características Esenciales de una Nube

Las principales características que definen una infraestructura de **cómputo en la nube** son:

- **Autoservicio bajo demanda**: Los usuarios pueden aprovisionar recursos de computación de manera automática, sin la intervención del proveedor del servicio.
- **Acceso ubicuo a la red**: Los servicios están disponibles a través de internet y pueden ser accedidos desde múltiples dispositivos.
- **Consolidación de recursos**: Los recursos físicos o virtuales se agrupan para servir a múltiples usuarios con un enfoque multiusuario.
- **Elasticidad rápida**: Los recursos pueden ser escalados hacia arriba o hacia abajo según la demanda, de forma rápida y automática.
- **Servicio medido**: El uso de los recursos está monitoreado y controlado, lo que permite transparencia en el consumo de recursos.

### 1.2 Modelos de Servicios

Los **modelos de servicios en la nube** se clasifican en tres categorías principales, cada una ofreciendo diferentes niveles de control, flexibilidad y administración.

#### 1.2.1 SaaS (Software as a Service)

En el modelo **SaaS**, las aplicaciones están alojadas y gestionadas en la nube, y los usuarios acceden a ellas a través de internet.

- **Ejemplos**: Gmail, Dropbox, Salesforce.
- **Ventajas**: No es necesario instalar o mantener software; todo se maneja por el proveedor. Es ideal para aplicaciones que necesitan un acceso rápido y sencillo.

#### 1.2.2 PaaS (Platform as a Service)

**PaaS** ofrece una plataforma sobre la cual los desarrolladores pueden construir, implementar y gestionar aplicaciones sin preocuparse por la infraestructura subyacente.

- **Ejemplos**: Google App Engine, Microsoft Azure.
- **Ventajas**: Facilita el desarrollo de aplicaciones y su despliegue al proporcionar un entorno preconfigurado con herramientas y middleware necesarios.

#### 1.2.3 IaaS (Infrastructure as a Service)

**IaaS** proporciona infraestructura virtualizada, como servidores, almacenamiento y redes, que los usuarios pueden aprovisionar y gestionar según sus necesidades.

- **Ejemplos**: Amazon EC2, Google Compute Engine.
- **Ventajas**: Ofrece máxima flexibilidad y control sobre los recursos, permitiendo que las organizaciones gestionen todo desde el sistema operativo hasta las aplicaciones.

### 1.3 Modelos de Despliegue

El despliegue de los servicios en la nube puede realizarse de diferentes formas, según las necesidades de la organización y los requisitos de seguridad y control.

#### 1.3.1 Nube Pública y Comunitaria

- **Nube Pública**: La infraestructura es gestionada por un proveedor externo y es accesible para el público general. Es rentable y permite el acceso fácil a recursos escalables, pero puede ser menos segura para datos sensibles.
  - **Ejemplo**: AWS, Microsoft Azure.

- **Nube Comunitaria**: Es compartida por varias organizaciones con intereses o requisitos comunes, y es gestionada por una o más de esas organizaciones o un proveedor externo.

#### 1.3.2 Nube Privada

- **Nube Privada**: La infraestructura está gestionada y utilizada exclusivamente por una organización. Proporciona mayor control y seguridad, pero a menudo requiere más recursos para su mantenimiento.
  - **Ejemplo**: Nube interna de grandes empresas como bancos o instituciones gubernamentales.

#### 1.3.3 Nube Híbrida

- **Nube Híbrida**: Combina infraestructuras de nube pública y privada, permitiendo que los datos y las aplicaciones se compartan entre ellas. Esto permite a las organizaciones aprovechar lo mejor de ambos mundos, utilizando la nube pública para tareas menos sensibles y la privada para datos críticos.
  - **Ejemplo**: Una empresa que utiliza AWS para su front-end y una nube privada para almacenar datos sensibles.

---

### UNIDAD TEMÁTICA II: Aspectos Básicos del Cómputo en la Nube

### 2.1 Principios del Cómputo en la Nube

El cómputo en la nube se basa en varios principios que garantizan su eficacia, sostenibilidad y rendimiento.

#### 2.1.1 Confiabilidad, Escalabilidad y Disponibilidad

- **Confiabilidad**: Se refiere a la capacidad del sistema de garantizar la correcta operación sin fallos durante un período determinado. Los servicios en la nube deben ofrecer redundancia, con respaldo de datos y recuperación ante desastres.
- **Escalabilidad**: La nube permite a las empresas aumentar o disminuir sus recursos (servidores, almacenamiento, etc.) según sea necesario, sin afectar el rendimiento.
- **Disponibilidad**: Los servicios en la nube deben estar disponibles casi en todo momento (24/7), con el menor tiempo de inactividad posible. Los proveedores suelen ofrecer altos niveles de disponibilidad a través de **acuerdos de nivel de servicio (SLA)** que especifican tiempos de actividad garantizados.

#### 2.1.2 Transparencia, Desempeño y Rendimiento

- **Transparencia**: Los usuarios finales deben experimentar un servicio sin interrupciones o fluctuaciones inesperadas, sin importar las acciones internas del proveedor en cuanto a administración y mantenimiento.
- **Desempeño y rendimiento**: La nube debe proporcionar un alto rendimiento, con baja latencia y respuesta rápida. Los recursos deben ser gestionados eficientemente para evitar la degradación del servicio, sobre todo cuando se experimenta alta demanda.

#### 2.1.3 Elasticidad

- **Elasticidad**: Se refiere a la capacidad de un sistema en la nube para ajustar sus recursos automáticamente en función de las necesidades. Por ejemplo, durante un pico de tráfico, los servidores en la nube pueden expandir su capacidad para gestionar la carga adicional sin intervención manual, y luego reducirse cuando la demanda disminuye.

### 2.2 Aspectos Legales del Cómputo en la Nube

El uso de servicios en la nube está regulado por acuerdos y marcos legales que protegen tanto a los proveedores como a los usuarios.

#### 2.2.1 Acuerdo de Nivel de Servicio para la Nube

- **Acuerdo de Nivel de Servicio (SLA)**: Es un contrato entre el proveedor y el cliente que define los niveles esperados de servicio, incluyendo tiempos de actividad, rendimiento, respuesta ante problemas y responsabilidades legales. El SLA es crucial para garantizar que las expectativas del servicio sean claras y estén respaldadas por compromisos contractuales.

#### 2.2.2 Ciclo de Vida de un Producto en la Nube

- El **ciclo de vida de un producto en la nube** incluye desde su desarrollo y despliegue hasta su eventual desmantelamiento. Durante este ciclo, es esencial garantizar la seguridad de los datos y la correcta administración de los recursos. Cada fase requiere gestión y coordinación para mantener la integridad del servicio y la satisfacción del cliente.

### 2.3 Proveedores de Servicios en la Nube

Existen numerosos proveedores de servicios en la nube, cada uno con sus propios enfoques y ofertas. La elección del proveedor depende de las necesidades específicas de cada empresa o proyecto.

#### 2.3.1 Casos de Estudio de Proveedores: Azure, AWS, Google, Oracle, entre otros

- **Azure (Microsoft)**: Es conocido por su fuerte integración con los servicios de Microsoft, como Windows Server y Active Directory, y por ser una opción popular entre grandes empresas.
- **Amazon Web Services (AWS)**: Es el proveedor más grande del mundo y ofrece una amplia gama de servicios que incluyen almacenamiento, computación, redes y bases de datos.
- **Google Cloud**: Se destaca por su eficiencia en la gestión de grandes volúmenes de datos y por sus herramientas de **machine learning** e **inteligencia artificial**.
- **Oracle Cloud**: Es muy utilizado por empresas que ya emplean las bases de datos de Oracle y otros servicios empresariales de alto nivel.

#### 2.3.2 Comparación de los Servicios Ofrecidos

Cada proveedor ofrece diferentes tipos de servicios, pero a grandes rasgos, estos son algunos puntos clave de comparación:

- **Capacidades de computación**: Todos los proveedores ofrecen capacidades de IaaS, pero la flexibilidad y escalabilidad de AWS suelen sobresalir.
- **Bases de datos**: AWS ofrece servicios como RDS, mientras que Oracle se especializa en grandes bases de datos empresariales.
- **Precios**: El costo de los servicios varía según el proveedor y las necesidades del cliente. AWS y Google Cloud ofrecen opciones más escalables, mientras que Azure es ideal para las empresas que buscan integración con Microsoft.

#### 2.3.3 Estrategias de Migración

Migrar una infraestructura o aplicación a la nube implica la evaluación de las aplicaciones actuales, la selección de los recursos de nube adecuados, y la implementación de estrategias para minimizar el tiempo de inactividad:

- **Rehost**: Mover una aplicación existente a la nube sin cambiar su estructura.
- **Refactor**: Adaptar las aplicaciones para aprovechar las características nativas de la nube, como la escalabilidad y la elasticidad.
- **Rebuild**: Crear aplicaciones nuevas que estén completamente optimizadas para la nube, maximizando la eficiencia y reduciendo costos a largo plazo.

---

### UNIDAD TEMÁTICA III: Servicios Distribuidos

### 3.1 Máquinas y Redes Virtuales

Las máquinas virtuales (VM) y las redes virtuales son componentes clave en la arquitectura de servicios distribuidos.

#### 3.1.1 Gestión de Máquinas Virtuales

La gestión de máquinas virtuales en la nube implica:

- **Creación y eliminación de VM**: Dependiendo de la demanda y las cargas de trabajo, las máquinas virtuales pueden crearse o destruirse automáticamente.
- **Asignación de recursos**: Las máquinas virtuales pueden aumentar o reducir sus recursos (CPU, memoria, etc.) según las necesidades del sistema.
- **Monitorización y mantenimiento**: Supervisar el rendimiento, aplicar actualizaciones y parches, y garantizar la seguridad son partes esenciales de la gestión de VM.

#### 3.1.2 Comunicación entre Máquinas Virtuales en la Nube

La **comunicación entre máquinas virtuales** en la nube utiliza redes virtuales que pueden configurarse para permitir el tráfico entre VM en una misma red o entre diferentes redes:

- **Redes privadas virtuales (VPN)**: Permiten la comunicación segura entre diferentes redes virtuales.
- **Subredes y gateways**: Las VM dentro de una red pueden comunicarse a través de subredes, mientras que los gateways gestionan el tráfico entre distintas redes.

#### 3.1.3 Respaldos en la Nube

El **respaldo en la nube** asegura que los datos y las configuraciones de las máquinas virtuales estén protegidos en caso de fallos:

- **Copia de seguridad automatizada**: Se programan respaldos periódicos.
- **Restauración rápida**: Los datos pueden restaurarse rápidamente en caso de pérdida o corrupción.

### 3.2 Arquitecturas de Almacenamiento

El almacenamiento en la nube ofrece flexibilidad y escalabilidad en la gestión de datos.

#### 3.2.1 Blob Storage

- **Blob Storage (Binary Large Object Storage)** es utilizado para almacenar grandes cantidades de datos no estructurados, como imágenes, vídeos y archivos de respaldo.

#### 3.2.2 Disk Storage

- **Disk Storage** está diseñado para replicar discos duros tradicionales en la nube, permitiendo que las máquinas virtuales tengan acceso a almacenamiento persistente.

#### 3.2.3 File Storage

- **File Storage** proporciona almacenamiento en la nube basado en sistemas de archivos, permitiendo que las VM y otros recursos compartan archivos en red de manera eficiente.

### 3.3 Bases de Datos en la Nube

Las bases de datos en la nube ofrecen soluciones escalables y gestionadas que permiten a las organizaciones almacenar y acceder a datos de manera eficiente.

#### 3.3.1 Implementación de Bases de Datos en la Nube

- Los proveedores de nube ofrecen bases de datos gestionadas (como **Amazon RDS**, **Azure SQL Database**, **Google Cloud SQL**) que permiten la implementación rápida de bases de datos relacionales y no relacionales.

#### 3.3.2 Gestión de Bases de Datos en la Nube

- **Escalabilidad automática**, **copias de seguridad automáticas** y **mantenimiento de actualizaciones** son características clave de la gestión de bases de datos en la nube.

#### 3.3.3 Estrategias de Partición de Datos

- **Partición horizontal**: Divide las filas de una tabla entre varios servidores.
- **Partición vertical**: Divide columnas entre servidores.

### 3.4 Elasticidad y Escalabilidad

La elasticidad y escalabilidad permiten que los servicios en la nube se adapten a las demandas cambiantes del sistema.

#### 3.4.1 Balanceo de Carga y su Administración

- El **balanceo de carga** distribuye el tráfico entre varios servidores para evitar la sobrecarga en uno solo. Los balanceadores de carga pueden configurarse para asegurar que el tráfico sea manejado de manera equitativa.

#### 3.4.2 Tolerancia a Fallas, Resiliencia y Confiabilidad

- **Tolerancia a fallas**: Los sistemas en la nube deben ser resilientes frente a fallos, asegurando que los servicios sigan disponibles.
- **Resiliencia**: La capacidad del sistema para recuperarse rápidamente de fallos.
- **Confiabilidad**: Mantener el sistema funcionando de manera consistente.

#### 3.4.3 Replicación

- La **replicación de datos** asegura la disponibilidad de los mismos en diferentes servidores, proporcionando redundancia y protección contra fallos.

### 3.5 Procesamiento Distribuido

El procesamiento distribuido permite ejecutar tareas complejas dividiendo el trabajo en varias máquinas.

#### 3.5.1 Técnicas MapReduce

- **MapReduce** es una técnica popular para el procesamiento distribuido de grandes conjuntos de datos, donde el trabajo se divide en **etapas de mapeo** (Map) y **etapas de reducción** (Reduce), permitiendo el procesamiento paralelo y eficiente.

---

### UNIDAD TEMÁTICA IV: Seguridad en la Nube


### 4.1 Importancia de la Seguridad

La **seguridad en la nube** es un aspecto crítico debido a la naturaleza distribuida y compartida de los servicios en la nube, donde se manejan grandes volúmenes de datos y se exponen múltiples puntos de entrada.

#### 4.1.1 Centros de Seguridad

- Los **centros de seguridad** en la nube son infraestructuras dedicadas a garantizar la seguridad física y lógica de los datos. Estos centros cuentan con controles avanzados de acceso, monitoreo 24/7 y planes de contingencia para evitar intrusiones o pérdidas de datos.

### 4.2 Aspectos de Seguridad de la Red

La seguridad en la red es fundamental para proteger el tráfico entre los recursos en la nube y los usuarios, así como entre los diferentes componentes de una aplicación distribuida.

#### 4.2.1 Grupos de Recursos

- Los **grupos de recursos** permiten organizar y gestionar los recursos en la nube bajo una misma política de seguridad. Cada grupo puede tener permisos, acceso y configuraciones de seguridad específicas para proteger los recursos asociados.

#### 4.2.2 Firewall

- El **firewall** en la nube actúa como una barrera protectora, filtrando el tráfico entrante y saliente para prevenir accesos no autorizados y ataques. Los firewalls en la nube pueden configurarse de manera dinámica y adaptarse según el tráfico.

### 4.3 Amenazas en la Nube

Las amenazas en la nube son variadas y requieren un enfoque preventivo para minimizar su impacto en los servicios y datos almacenados.

#### 4.3.1 Ataques de Negación de Servicio (DoS)

- Un **ataque de negación de servicio (DoS)** intenta saturar los recursos del servidor en la nube, dejándolo incapaz de procesar solicitudes legítimas. Los proveedores de servicios en la nube suelen implementar **mecanismos de mitigación de DoS** para evitar que estos ataques afecten a sus clientes.

#### 4.3.2 Brechas de Datos (Data Breaches) y Autenticación Débil

- Las **brechas de datos** ocurren cuando terceros no autorizados acceden a información sensible almacenada en la nube. 
- **Autenticación débil**: Se refiere a la falta de políticas robustas de autenticación, como contraseñas poco seguras o ausencia de autenticación multifactor (MFA), que facilita accesos no autorizados.

#### 4.3.3 Secuestro de Cuentas y Datos

- El **secuestro de cuentas** se produce cuando atacantes obtienen acceso a las credenciales de un usuario o administrador de la nube, permitiéndoles manipular recursos o extraer datos confidenciales. Los **sistemas de monitoreo y detección de actividad sospechosa** son esenciales para prevenir este tipo de ataques.

---
### UNIDAD TEMÁTICA V: Servicios Web y Microservicios

### 5.1 Aspectos Básicos de los Servicios Web

Los **servicios web** son aplicaciones que permiten la comunicación y el intercambio de datos entre diferentes sistemas a través de la red, utilizando estándares y protocolos web.

#### 5.1.1 Arquitecturas de un Servicio Web

- **Arquitectura monolítica**: Es la más tradicional, donde una sola aplicación contiene todas las funcionalidades. Si bien es más simple de desarrollar, la escalabilidad y mantenimiento a largo plazo se vuelven complicados.
- **Arquitectura de microservicios**: Los servicios web modernos suelen estar basados en microservicios, donde la aplicación se divide en pequeños servicios independientes que se comunican entre sí a través de interfaces bien definidas. Esta arquitectura ofrece mayor flexibilidad y escalabilidad.

#### 5.1.2 Estándares

- **SOAP (Simple Object Access Protocol)**: Un protocolo basado en XML para el intercambio estructurado de información en servicios web. Se usa principalmente en entornos donde la seguridad y la confiabilidad son esenciales.
- **REST (Representational State Transfer)**: Un estilo arquitectónico más ligero y flexible que SOAP, basado en HTTP, donde los recursos se acceden y manipulan a través de URLs. Es más usado debido a su simplicidad y compatibilidad con múltiples plataformas.
- **WSDL (Web Services Description Language)**: Especifica la interfaz que expone un servicio web, describiendo sus operaciones, mensajes y protocolos de transporte.
- **UDDI (Universal Description, Discovery, and Integration)**: Un estándar para el descubrimiento de servicios web.

### 5.2 Microservicios

Los **microservicios** son un enfoque de diseño arquitectónico en el cual una aplicación se descompone en servicios pequeños e independientes que pueden desarrollarse, desplegarse y escalarse de manera individual.

#### 5.2.1 Aplicación Monolítica vs Microservicios

- **Aplicación monolítica**: En una arquitectura monolítica, todas las funciones de la aplicación se integran en una sola base de código. Es fácil de implementar, pero difícil de escalar y mantener a medida que la aplicación crece.
- **Microservicios**: Permiten dividir una aplicación en servicios autónomos que se comunican entre sí mediante APIs. Cada servicio puede ser desarrollado por equipos diferentes y se puede actualizar sin afectar al resto de la aplicación.

#### 5.2.2 Características de los Microservicios

- **Independencia**: Cada microservicio funciona de manera autónoma y tiene su propia base de datos y lógica de negocio.
- **Escalabilidad**: Los microservicios permiten escalar solo aquellos componentes de la aplicación que lo necesiten, optimizando el uso de recursos.
- **Despliegue continuo**: Facilita el desarrollo ágil, permitiendo actualizaciones frecuentes sin afectar todo el sistema.
- **Tolerancia a fallos**: Si un microservicio falla, el resto de la aplicación puede seguir funcionando, mejorando la resiliencia del sistema.

#### 5.2.3 Contenedores y Kubernetes

- **Contenedores**: Una tecnología que permite empaquetar un microservicio con todas sus dependencias, asegurando que se ejecute de manera consistente en cualquier entorno. Docker es el contenedor más popular.
- **Kubernetes**: Una plataforma para la automatización del despliegue, escalado y operación de contenedores. Se utiliza comúnmente con microservicios para administrar de manera eficiente los contenedores en producción.

### 5.3 Tecnologías Emergentes

- **Serverless computing**: Permite a los desarrolladores ejecutar aplicaciones sin gestionar servidores. Los proveedores en la nube asignan recursos automáticamente cuando se ejecutan los servicios.
- **API Gateway**: Actúa como un intermediario entre el cliente y los microservicios, ayudando a gestionar la comunicación, la seguridad y la escalabilidad.
- **Event-Driven Architecture**: Una arquitectura que usa eventos (cambios en el estado del sistema) para desencadenar acciones, permitiendo que los servicios se comuniquen de manera más eficiente en entornos distribuidos.
