#include <Wire.h> // Faz comunicação com I2C
#include <LiquidCrystal_I2C.h> //Inclui a biblioteca para o LCD
#include <OneWire.h> // biblioteca para o DS18B20
#include <DallasTemperature.h> //Inclui a biblioteca para o DS18B20

// Configuração do display LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pinos dos LEDs do bargraph
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int numLeds = 10;

// Pino do potenciômetro
const int potPin = A0;

// Configuração do sensor de temperatura DS18B20
const int oneWireBus = 12;         
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

// Pino do sensor LDR
const int ldrPin = A1; // Pino analógico conectado ao LDR

void setup() {
  lcd.init();                      // Inicializa o LCD
  lcd.backlight();                 // Liga a luz de fundo do LCD
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);   // Configura os pinos do bargraph como saída
  }
  sensors.begin();                 // Inicializa o sensor de temperatura
}

void loop() {
  int potValue = analogRead(potPin);              // Lê o valor do potenciômetro
  int mappedValue = map(potValue, 0, 1023, 0, 14); // Mapeia o valor para o intervalo de 0 a 14

  // Acende os LEDs do bargraph
  for (int i = 0; i < numLeds; i++) {
    if (i < mappedValue) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  // Obtém a temperatura do sensor DS18B20
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);

  // Lê o valor do sensor LDR e converte para porcentagem
  int ldrValue = analogRead(ldrPin); // Valor entre 0 e 1023
  int ldrPercentage = map(ldrValue, 0, 1023, 0, 100); // Converte para porcentagem

  // Exibe as informações no LCD, uma de cada vez
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PH: ");
  lcd.print(mappedValue);
  delay(2000); // Exibe por 2 segundos
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print((char)223); // Símbolo de grau
  lcd.print("C");
  delay(2000); // Exibe por 2 segundos
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Luz: ");
  lcd.print(ldrPercentage);
  lcd.print("%");
  delay(2000); // Exibe por 2 segundos
}
