/**
 * \brief	measure sonar Sensor 
 * measures the distance between sensor and object
 *
 * \author	Timo Steiner
 *
 * \date	16.12.2022
 *
 * \param	tP = trigger Pin
 * \param	eP = echo Pin
 * \param	mD = max distance
 *
 * \return	int --> distance
 */

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