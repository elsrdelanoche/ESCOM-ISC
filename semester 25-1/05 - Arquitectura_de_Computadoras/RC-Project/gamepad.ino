/*
Equipo 8 : Carrito a control remoto versión 2.2
Funciones principales:
 * Control de movimiento via Bluetooth
 * Encendido de luz inferior en condiciones de poca luz
 * Frenado de emergencia en caso de choque inminente
 * Claxon al presionar cuadrado
 * Circulo para encendido de luces traseras */

//Librerias
#include "BluetoothSerial.h"
#include <stdlib.h>
#include <Arduino.h>

//Definiciones
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

//Definicion de variables globales

int LDR = 35;    //Definimos el pin para el sensor de luz
int trig = 19;   // Definimos el pin para el transmisor
int eco = 21;    //Definimos el pin para el eco
int faros = 22;  //Definimos el pin para las luces
int faros2 = 32;
int claxon = 23; 
int flow = 15;
int luz;       //Variable para guardar el valor de iluminacion
int duracion;  //Variable para guardar duracion de pulso de sonido
int distancia; //Variable para guardar la distancia medida
int d = 1;   //Variable para delay's en el codigo
//Pines para movimiento
int diri = 25; //Pin para direccion izquierda
int dird = 14;
int movf = 4;
int movb = 5;
int hab1 = 33;
int hab2 = 2;


String device_name = "BMW"; // Nombre de la conexion Bluetooth
BluetoothSerial SerialBT;


void setup() {
    pinMode(diri, OUTPUT);
    pinMode(dird, OUTPUT);
    pinMode(movf, OUTPUT);
    pinMode(movb, OUTPUT);
    pinMode(trig, OUTPUT);   //Pin trig es salida
    pinMode(faros, OUTPUT);  //Pin de faros es salida
    pinMode(faros2, OUTPUT);
    pinMode(claxon, OUTPUT);  //Pin de claxon es salida
    pinMode(hab1, OUTPUT);
    pinMode(hab2, OUTPUT);
    pinMode(LDR, INPUT);     //Pin LDR es entrada
    pinMode(eco, INPUT);     //Pin eco es entrada
    pinMode(flow, OUTPUT);

    Serial.begin(9600);    //Iniciamos comunicacion serial en 115200
    SerialBT.begin(device_name);

    Serial.println("Bluetooth listo, conectar");
    if (SerialBT.available()) {
        Serial.println("Conectado, esperando...");
    }

    //Condicion Inicial del auto
    digitalWrite(diri, LOW);
    digitalWrite(dird, LOW);
    digitalWrite(movf, LOW);
    digitalWrite(movb, LOW);
    digitalWrite(hab1, LOW);
    digitalWrite(hab2, LOW);
    digitalWrite(faros, LOW);
    digitalWrite(faros2, LOW);
    digitalWrite(claxon, LOW);
    digitalWrite(flow, LOW);
}

void loop(){
    //Leer valores de distancia
    digitalWrite(trig, LOW);
    delay(2);
    digitalWrite(trig, HIGH);
    delay(10);
    digitalWrite(trig, LOW);
    
    //Calculo de distancia frontal
    duracion = pulseIn(eco, HIGH);
    distancia = duracion / 58.2;
    Serial.print(distancia);
    //Serial.println(" cm");
    delay(d);

    //Si hay entrada en puerto serial Bt
    if (SerialBT.available()) {
        char command = SerialBT.read();
        //Serial.println(command);
        executeCommand(command);
    }
  //Leer valor del ldr para saber condiciones de luz
      luz=analogRead(LDR);
      Serial.println(luz);
      delay(d);
      if(luz > 200){
        digitalWrite(flow, HIGH);
      } else{
        digitalWrite(flow, LOW);
      }
}

void executeCommand(char command) {
  switch (command) {
    case FORWARD:
        if(distancia < 10){
            // Detener el movimiento
            digitalWrite(diri, LOW);
            digitalWrite(dird, LOW);
            digitalWrite(movf, LOW);
            digitalWrite(movb, LOW);
            Serial.println("Obstáculo detectado, deteniendo el movimiento.");
            return;
        }else {
        digitalWrite(diri, LOW);
        digitalWrite(hab1, HIGH);
        digitalWrite(hab2, HIGH);
        digitalWrite(dird, LOW);
        digitalWrite(movf, HIGH);
        digitalWrite(movb, LOW);
        Serial.println("Adelante");
        }
      break;
    case BACKWARD:
        digitalWrite(diri, LOW);
        digitalWrite(hab1, HIGH);
        digitalWrite(hab2, HIGH);
        digitalWrite(dird, LOW);
        digitalWrite(movf, LOW);
        digitalWrite(movb, HIGH);
        Serial.println("Atras");
      break;
    case LEFT:
        digitalWrite(diri, HIGH);
        digitalWrite(hab1, HIGH);
        digitalWrite(hab2, HIGH);
        digitalWrite(dird, LOW);
        digitalWrite(movf, HIGH);
        digitalWrite(movb, LOW);
        Serial.println("Izquierda");
      break;
    case RIGHT:
        digitalWrite(diri, LOW);
        digitalWrite(hab1, HIGH);
        digitalWrite(hab2, HIGH);
        digitalWrite(dird, HIGH);
        digitalWrite(movf, HIGH);
        digitalWrite(movb, LOW);
        Serial.println("Derecha");
      break;
    case CIRCLE:
        digitalWrite(faros, HIGH);
        digitalWrite(faros2, HIGH);
        Serial.println("Faros");
      break;
    case CROSS:
        digitalWrite(claxon, HIGH);
        Serial.println("Claxon");
      break;
    case TRIANGLE:
      Serial.println("Triangulo");
      break;
    case SQUARE:
      Serial.println("Cuadrado");
      break;
    case START:
      Serial.println("START");
      break;
    case PAUSE:
      Serial.println("PAUSE");
      break;
    default:
        digitalWrite(diri, LOW);
        digitalWrite(dird, LOW);
        digitalWrite(movf, LOW);
        digitalWrite(movb, LOW);
        digitalWrite(faros, LOW);
        digitalWrite(faros2, LOW);
        digitalWrite(claxon, LOW);
        digitalWrite(hab1, LOW);
        digitalWrite(hab2, LOW);
      break;
  }
}