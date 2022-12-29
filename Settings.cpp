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



void Settings::eepromWriteInt(int address, int number) {
	EEPROM.write(address, (number >> 24) & 0xFF);
	EEPROM.commit();
	EEPROM.write(address + 1, (number >> 16) & 0xFF);
	EEPROM.commit();
	EEPROM.write(address + 2, (number >> 8) & 0xFF);
	EEPROM.commit();
	EEPROM.write(address + 3, number & 0xFF);
	EEPROM.commit();
}

long Settings::eepromReadInt(int address) {
		return ((long)EEPROM.read(address) << 24) +
			((long)EEPROM.read(address + 1) << 16) +
			((long)EEPROM.read(address + 2) << 8) +
			(long)EEPROM.read(address + 3);
}