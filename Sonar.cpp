/**
 * \brief	measure BME280 Sensor (temperature, humitidy, pressure)
 * if the sensor is available, the function will read the current sensorvalues.
 * if the sensor is not available, the function will print an default value of "-99"
 *
 * \author	Timo Steiner
 *
 * \date	16.12.2022
 *     Diese Funktion gibt den übergebenen Parameter
 *     auf der Konsole aus.
 *
 * \param	cRT = current runtime of the system
 * \param	dly = break time between measures
 *
 * \return	void --> prints sensorresult directly in an Array in the class "BME280"
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