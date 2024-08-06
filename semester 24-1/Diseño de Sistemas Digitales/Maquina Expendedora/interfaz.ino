#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C del LCD 20x4
#define I2C_ADDR    0x27

// Inicializar el LCD
LiquidCrystal_I2C lcd(I2C_ADDR, 20, 4);

// Pin para el LED
const int ledPin = 13;

void setup() {
  // Inicializar el LCD
  lcd.begin(20, 4);
  
  // Inicializar el LED como salida
  pinMode(ledPin, OUTPUT);

  // Mostrar el mensaje de bienvenida en el LCD
  lcd.setCursor(0, 0);
  lcd.print("Hola Bienvenido");
  lcd.setCursor(0, 1);
  lcd.print("00 Cremino $4");
  lcd.setCursor(0, 2);
  lcd.print("01 Mazapan $5");
  lcd.setCursor(0, 3);
  lcd.print("10 Lucas $6");

  // Encender el LED para indicar que el programa está en funcionamiento
  digitalWrite(ledPin, HIGH);
}

void loop() {
  
}