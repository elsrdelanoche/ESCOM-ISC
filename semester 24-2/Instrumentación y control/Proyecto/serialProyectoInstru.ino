void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial a 9600 baudios

  // Configura los pines como entradas
  for (int pin = 9; pin >= 2; pin--) {
    pinMode(pin, INPUT);
  }
}

void loop() {
  // Lee los estados de los pines y muestra cada dígito en el monitor serie
  for (int pin = 9; pin >= 2; pin--) {
    Serial.print(digitalRead(pin));  // Imprime el estado del pin (0 o 1)
  }
  Serial.println();  // Salto de línea para mostrar la siguiente lectura en una nueva línea

  delay(100);  // Pequeño retraso para evitar enviar datos demasiado rápido
}