#include "Settings.h"

void Settings::setPasswort(Nextion* nx){
	if (nx->buttonValue[4]!=0 && nx->buttonValue[5] != 0 && nx->buttonValue[5] != 0) {
		if (nx->buttonValue[5]== nx->buttonValue[6]) {
			if (nx->buttonValue[4] == eepromReadInt(1)) {
				masterKey = nx->buttonValue[5];
				EEPROM.write(0, nx->buttonValue[5]);
				nx->buttonValue[4] = 0;
				nx->buttonValue[5] = 0;
				nx->buttonValue[6] = 0;
			}
		}
	}
}



void Settings::eepromWriteInt(int adr, int wert) {
	byte low, high;
	low = wert & 0xFF;
	high = (wert >> 8) & 0xFF;
	EEPROM.write(adr, low);
	EEPROM.commit();
	EEPROM.write(adr + 1, high);
	EEPROM.commit();
	return;
}

int Settings::eepromReadInt(int adr) {
	byte low, high;
	low = EEPROM.read(adr);
	high = EEPROM.read(adr + 1);
	return low+((high << 8) & 0xFF00);
}