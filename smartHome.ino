// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       smartHome.ino
    Created:	06.12.2022 08:55:19
    Author:     DESKTOP-H28UBFF\tisto
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//
#include "Alarm.h"
#include "Sonar.h"

//Sonar so;
bool alarmOn = false;
int buzzer = 7;
int index = 0;
int pinButton = 13;
int demandPin[4] = {};

// The setup() function runs once each time the micro-controller starts
void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(pinButton, OUTPUT);
    Serial.begin(9600);
}

// Add the main program code into the continuous loop() function
void loop() {   
    if (motionDetection() == true) {
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
