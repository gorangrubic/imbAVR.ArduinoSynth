// 
// 
// 

#include "DigPotUnit.h"

void DigPotUnitClass::Write(byte value) {

	digitalWrite(ChipSelectPin, LOW);
	SPI.transfer(B00010001); // This tells the chip to set the pot
	SPI.transfer(value);     // This tells it the pot position
	digitalWrite(ChipSelectPin, HIGH);
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

