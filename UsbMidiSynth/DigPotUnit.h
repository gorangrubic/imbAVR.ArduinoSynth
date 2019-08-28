// DigPotUnit.h

#ifndef _DIGPOTUNIT_h
#define _DIGPOTUNIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SPI.h"

class DigPotUnitClass
{
 protected:


 public:
	 
	byte ChipSelectPin;
	byte lastValue;

	void Write(byte value);

	DigPotUnitClass(byte chipSelectPin);
		

	void init();
};

//extern DigPotUnitClass DigPotUnit;

#endif

