/*
    Gestire la frequenza di blink di un led tramite potenziometro, 
    andando da sempre acceso a sempre spento, i valori dovranno
    andare da blink minimi ad un massimo di 2 secondi.
*/
#include <Arduino.h>

#define LEDPIN 8
#define POTPIN A5
#define STEPFORMAPPING 2000

void setup(){
    Serial.begin(9600);
    pinMode(LEDPIN, OUTPUT);
}

void loop(){
    int val = map(analogRead(POTPIN), 0, 1023, 0, STEPFORMAPPING);
    Serial.println(val);

    if(val != 0){
        digitalWrite(LEDPIN, HIGH);
    }

    if(val != STEPFORMAPPING){
        delay(val);
        digitalWrite(LEDPIN, LOW);
        delay(val);
    }
}