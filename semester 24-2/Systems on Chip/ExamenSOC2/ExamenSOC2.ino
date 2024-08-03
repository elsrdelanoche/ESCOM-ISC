#include "BluetoothSerial.h"  // Include the Bluetooth library

const int pinPotenciometro = 2;
const int pinSalida19 = 19;
const int pinSalida21 = 21;
int valorPotenciometro;

String device_name = "ESP32-BT-Slave"; // Name for your Bluetooth device
BluetoothSerial SerialBT;

void setup() {
    pinMode(pinPotenciometro, INPUT);
    pinMode(pinSalida19, OUTPUT);
    pinMode(pinSalida21, OUTPUT);
    Serial.begin(9600);
    SerialBT.begin(device_name);

    Serial.println("Bluetooth listo, conectar");
}

void loop() {

    if (SerialBT.available()) {
        String command = SerialBT.readString();

        if (command == "0") { 
            controlParabrisas();
        }
        else if (command == "1") { 
            controlMartillo();
        } else {
            Serial.println("Comando invalido, solo '0' or '1'.");
        }
    }
}

void controlParabrisas() {
  String command2 = SerialBT.readString();
  command2="0";
  while(command2 == "0"){
    valorPotenciometro = analogRead(pinPotenciometro);
    if (valorPotenciometro >= 3400 && valorPotenciometro <= 4000) {
        digitalWrite(pinSalida19, HIGH);  
        digitalWrite(pinSalida21, LOW);  
    } else if (valorPotenciometro >= 2000 && valorPotenciometro <= 2500) {
        digitalWrite(pinSalida19, LOW); 
        digitalWrite(pinSalida21, HIGH);
    } else {
        // Estado por defecto
        digitalWrite(pinSalida19, LOW); 
        digitalWrite(pinSalida21, LOW);  
    }
    Serial.println("Modo Parabrisas: " + String(valorPotenciometro));
  }
  if(command2=="1"){
    controlMartillo();  
  }
  
}

void controlMartillo() {
  String command2 = SerialBT.readString();
  command2="1";
  while (command2 == "1"){
    valorPotenciometro = analogRead(pinPotenciometro);
    
    if (valorPotenciometro >= 3400 && valorPotenciometro <= 4095) {
      digitalWrite(pinSalida19, HIGH);  // 1 en pin 19
      digitalWrite(pinSalida21, LOW);   // 0 en pin 21
    } else if (valorPotenciometro >= 1600 && valorPotenciometro <= 2500) {
      digitalWrite(pinSalida19, LOW);   // 0 en pin 19
      digitalWrite(pinSalida21, HIGH);  // 1 en pin 21
    } else {
      // Estado por defecto 
      digitalWrite(pinSalida19, LOW); 
      digitalWrite(pinSalida21, LOW);  
    }

    Serial.println("Modo Martillo: " + String(valorPotenciometro));
  }
  if(command2=="0"){
    controlParabrisas();  
  }
}
