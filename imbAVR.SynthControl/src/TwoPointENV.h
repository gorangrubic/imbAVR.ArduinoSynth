// TwoPointENV.h

#ifndef _TWOPOINTENV_h
#define _TWOPOINTENV_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif




class TwoPointENV {

public:

	byte ATimeFactor = 1;

	byte BTimeFactor = 4;

	unsigned int ATime = 25;

	unsigned int BTime = 100;


	byte ALevel=255;
	byte BLevel=0;


	byte Compute(unsigned int cT);

	void SetTimes(unsigned int At, unsigned int Bt);

	void SetLevels(byte aLevel, byte bLevel = 0);

};


#endif