#include "Alarm.h"
#include "Sonar.h"

bool motionDetection() {
	Sonar so;
	int currentDistanceSonar1 = so.measure(2, 3, 500);
	delay(50);
	int currentDistanceSonar2 = so.measure(4, 5, 500);
	if (currentDistanceSonar1!=500 || currentDistanceSonar2 != 500) {
		return true;
	}
	else {
		return false;
	}
}