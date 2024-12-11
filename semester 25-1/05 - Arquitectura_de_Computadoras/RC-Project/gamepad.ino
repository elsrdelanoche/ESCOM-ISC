#include "BluetoothSerial.h"
#include <stdlib.h> 

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

const int pinDireccion = 2;

String device_name = "ESP32-BMW"; // Name for your Bluetooth device
BluetoothSerial SerialBT;

void setup() {
  pinMode(pinDireccion, OUTPUT);
  Serial.begin(9600);  // Set the baud rate for serial communication
  SerialBT.begin(device_name);
  // Initialize any other necessary setup code here
  Serial.println("Bluetooth listo, conectar");
  if (SerialBT.available()) {
    Serial.println("Conectado, esperando...");
  }
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    Serial.println(command);
    executeCommand(command);
  }

}

void executeCommand(char command) {
  switch (command) {
    case FORWARD:
      // Perform action for moving forward
      Serial.println("Adelante");
      break;
    case BACKWARD:
      // Perform action for moving backward
      Serial.println("Atras");
      break;
    case LEFT:
      // Perform action for turning left
      Serial.println("Izquierda");

      break;
      
    case RIGHT:
      // Perform action for turning right
      Serial.println("Derecha");
      while(SerialBT.read()!='0'){
        digitalWrite(pinDireccion, HIGH);
      }
      digitalWrite(pinDireccion, LOW);
    break;    
    case CIRCLE:
      // Perform action for circle
      Serial.println("Circulo");
      break;
    case CROSS:
      // Perform action for immediate stop or crossing
      Serial.println("Equis");
      break;
    case TRIANGLE:
      // Perform action for toggling a state (e.g., LED on/off)
      Serial.println("Triangulo");
      break;
    case SQUARE:
      // Perform action for retrieving and sending status information
      Serial.println("Cuadrado");
      break;
    case START:
      // Perform action for starting a process or operation
      Serial.println("START");
      break;
    case PAUSE:
      // Perform action for pausing a process or operation
      Serial.println("PAUSE");
      break;
    default:
      // Invalid command received
      break;
    
  }
}
