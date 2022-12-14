#include "Detection.h"
#include "Sonar.h"


bool motionDetection() {
	
	int currentDistanceSonar1 = 2;// so.measure(12, 14, 500);
	delay(10);
	//int currentDistanceSonar2 = so.measure(4, 5, 500);
	if (currentDistanceSonar1!=500){ //|| currentDistanceSonar2 != 500) {
		return true;
	}
	else {
		return false;
	}
}
