#ifndef _CUSTOMMESSAGE_h
#define _CUSTOMMESSAGE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


typedef struct customMessage {
	unsigned int parameterA;
	unsigned int parameterB;
	byte parameterC;
	byte parameterD;
};

#endif

