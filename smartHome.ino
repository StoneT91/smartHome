#include "Alarm.h"
#include "Sonar.h"

Sonar so;
bool alarmOn = false;
int buzzer = 8;
int pinButton = 7;
int panicButton = 8;

// The setup() function runs once each time the micro-controller starts
void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(pinButton, INPUT_PULLUP);
    Serial.begin(9600);
}

// Add the main program code into the continuous loop() function
void loop() { 
    if (motionDetection() == true) {
        alarmOn = true;
        while (alarmOn) {
            digitalWrite(buzzer, HIGH); 
            delay(1);
            digitalWrite(buzzer, LOW);
            delay(1);

            if(digitalRead(pinButton)==HIGH){
                alarmOn = false;
            }
        }
    }
    
    delay(50);
}