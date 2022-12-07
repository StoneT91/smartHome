#include "Sonar.h"

int Sonar::measure(int tP, int eP, int mD) {
    trigPin = tP;
    echoPin = eP;
    maxDistance = mD;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int time = pulseIn(echoPin, HIGH, 5000);
    currentDistance = time * 0.1715;
    if (currentDistance == 0) {
        currentDistance = maxDistance;
    }
    return currentDistance;
}