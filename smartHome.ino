#include "Alarm.h"
#include "Sonar.h"

//Sonar so;
bool alarmOn = false;
int buzzer = 25;
int pinButton = 26;
int panicButton = 21;

// The setup() function runs once each time the micro-controller starts
void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(pinButton, OUTPUT);
    Serial.begin(9600);
}

// Add the main program code into the continuous loop() function
void loop() {
    if (motionDetection() == true || digitalRead(panicButton)) {
        alarmOn = true;
        while (alarmOn) {
            digitalWrite(buzzer, HIGH); // send high signal to buzzer 
            delay(1); // delay 1ms
            digitalWrite(buzzer, LOW); // send low signal to buzzer
            delay(1);
            if (digitalRead(pinButton))
            {
                alarmOn = false;
            }
        }
    }
    delay(500);
}