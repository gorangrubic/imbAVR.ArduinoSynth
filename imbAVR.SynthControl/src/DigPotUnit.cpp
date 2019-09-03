// 
// 
// 

#include "DigPotUnit.h"
#define OPTIMIZATION

void DigPotUnitClass::Write(byte value) {

#ifdef OPTIMIZATION
	if (value == lastValue) {
		return;
	}
#endif
	digitalWrite(ChipSelectPin, LOW);
	
	SPI.transfer(B00010001); // This tells the chip to set the pot
	SPI.transfer(value);     // This tells it the pot position
	digitalWrite(ChipSelectPin, HIGH);
	lastValue = value;
}

DigPotUnitClass::DigPotUnitClass(byte chipSelectPin) {

	ChipSelectPin = chipSelectPin;
	pinMode(ChipSelectPin, OUTPUT);
	//Write(127);
}

void DigPotUnitClass::init()
{


}


//DigPotUnitClass DigPotUnit;

