Por medio de bluetooth terminal enviare un 1 o 0 a mi dispositivo, conecta el codigo de como debe funcionar el dispositivo con lo necesario para comunicarme por bluetooth
#include <Arduino.h>

const int pinPotenciometro = 2;
const int pinSalida19 = 19;
const int pinSalida21 = 21;
int valorPotenciometro;
int terminalBT;

void setup() {
  pinMode(pinPotenciometro, INPUT);
  pinMode(pinSalida19, OUTPUT);
  pinMode(pinSalida21, OUTPUT);
  Serial.begin(9600); 
}

void loop() {

    //Si el valor recibido por terminal bluetooth es 0, ejecuta parabrisas
  if(terminalBT==0){
    valorPotenciometro = analogRead(pinPotenciometro);
    // Lógica para controlar los pines de salida
    if (valorPotenciometro >= 3400 && valorPotenciometro <= 4000) {
      digitalWrite(pinSalida19, HIGH);  // 1 en pin 19
      digitalWrite(pinSalida21, LOW);   // 0 en pin 21
    } else if (valorPotenciometro >= 2000 && valorPotenciometro <= 2500) {
      digitalWrite(pinSalida19, LOW);   // 0 en pin 19
      digitalWrite(pinSalida21, HIGH);  // 1 en pin 21
    } else {
      // Estado por defecto (opcional)
      digitalWrite(pinSalida19, LOW); 
      digitalWrite(pinSalida21, LOW);  
    }

    Serial.println(valorPotenciometro);
  } 

  //Si el valor recibido por terminal bluetooth es 1, ejecuta martillo
  if(terminalBT==1){
    valorPotenciometro = analogRead(pinPotenciometro);
    // Lógica para controlar los pines de salida
    if (valorPotenciometro >= 3400 && valorPotenciometro <= 4095) {
      digitalWrite(pinSalida19, HIGH);  // 1 en pin 19
      digitalWrite(pinSalida21, LOW);   // 0 en pin 21
    } else if (valorPotenciometro >= 1600 && valorPotenciometro <= 2500) {
      digitalWrite(pinSalida19, LOW);   // 0 en pin 19
      digitalWrite(pinSalida21, HIGH);  // 1 en pin 21
    } else {
      // Estado por defecto (opcional)
      digitalWrite(pinSalida19, LOW); 
      digitalWrite(pinSalida21, LOW);  
    }

    Serial.println(valorPotenciometro); 
  }
}

Codigo bluetooth
// This example code is in the Public Domain (or CC0 licensed, at your option.)
// By Evandro Copercini - 2018
//
// This example creates a bridge between Serial and Classical Bluetooth (SPP)
// and also demonstrate that SerialBT have the same functionalities of a normal Serial
// Note: Pairing is authenticated automatically by this device

#include "BluetoothSerial.h"

String device_name = "ESP32-BT-Slave";

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  SerialBT.begin(device_name);  //Bluetooth device name
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}

