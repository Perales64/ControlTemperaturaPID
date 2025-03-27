#include <Arduino.h>

// Definiciones componentes de la tarjeta
#define sensor1 5  //TMP36
#define heater1 3   //TIP31C
#define LED    2   //Led
//Variables Globales
float T1,aux;       //Temperatura del Heater 1

void setup() {
  pinMode(LED,OUTPUT);  //Led "Caliente" como salida
  digitalWrite(LED,LOW);
}
void loop() {
  int i;
  //Filtro de promedio movil en la lectura ADC
  aux=0;
  for(i=0;i<10;i++){
    aux = aux + (float(analogRead(sensor1))*3.3/4095.0-0.5)/0.01; //TMP36
  }
  T1 = aux/10.0;
 analogWrite(heater1,255*0.4);
 //Usar el Serial Plotter
    Serial.println("Temperatura_1");
    Serial.print(T1);
    delay(1000);
}