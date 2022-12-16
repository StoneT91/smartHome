// 
// 
// 

#include "gasSensorEns160.h"



void gasSensorEns160::measureEns160(int cRT, int dly) {
	if ((cRT - updateTimeEns160) > dly) {

		/**
* Set power mode
* mode Configurable power mode:
*   ENS160_SLEEP_MODE: DEEP SLEEP mode (low power standby)
*   ENS160_IDLE_MODE: IDLE mode (low-power)
*   ENS160_STANDARD_MODE: STANDARD Gas Sensing Modes
*/
		


		updateTimeEns160 = millis();
	}
}
