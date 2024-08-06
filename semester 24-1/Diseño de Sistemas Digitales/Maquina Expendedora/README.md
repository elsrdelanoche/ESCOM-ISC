## Máquina Expendedora VHDL

### Descripción
Este proyecto implementa una máquina expendedora utilizando VHDL. El diseño se basa en una máquina de estados finitos (FSM) que controla el proceso de inserción de monedas, selección de producto y dispensación del producto.

### Estructura del Código
El código se divide en dos partes principales:

1. **Entidad:** Define los puertos de entrada y salida del módulo.
2. **Arquitectura:** Contiene la lógica interna de la máquina expendedora, incluyendo la definición de estados, memoria de productos y el proceso secuencial.

### Puertos
* **direccion:** Entrada de 2 bits para seleccionar el producto.
* **precio_prod:** Salida de 4 bits que indica el precio del producto seleccionado.
* **cambio:** Salida de 8 bits que representa el cambio devuelto al usuario.
* **in_005, in_010, in_020, in_050, in_100:** Entradas para indicar la inserción de monedas de diferentes denominaciones.
* **clock:** Reloj de sistema.
* **reset:** Señal de reinicio.
* **dulce:** Salida que indica si se debe dispensar el producto.

### Funcionamiento
La máquina expendedora opera de la siguiente manera:

1. **Inicialización:** Se inicializa la memoria de productos con los precios correspondientes.
2. **Inserción de monedas:** El usuario inserta monedas de diferentes denominaciones. El sistema acumula el valor total de las monedas insertadas.
3. **Selección de producto:** El usuario selecciona un producto mediante la señal `direccion`.
4. **Verificación de crédito:** Se compara el valor acumulado de las monedas con el precio del producto seleccionado.
5. **Dispensación:** Si el crédito es suficiente, se dispensa el producto y se calcula el cambio.
6. **Devolución de cambio:** Se devuelve el cambio al usuario utilizando la salida `cambio`.

### Referencias
* IEEE Standard Logic 1164
* IEEE Standard Logic Arithmetic
