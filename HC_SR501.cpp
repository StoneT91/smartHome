// 
// 
// 

#include "HC_SR501.h"

bool getMovementDetection(int mP) {
    pinMode(mP, INPUT);
	if (digitalRead(mP)) {
		return true;
	}
	else {
		return false;
	}
}