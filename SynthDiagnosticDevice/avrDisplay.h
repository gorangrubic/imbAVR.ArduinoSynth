// avrDisplay.h

#ifndef _AVRDISPLAY_h
#define _AVRDISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



class AvrDisplayClass
{
 protected:


 public:
	void init();
};

extern AvrDisplayClass AvrDisplay;

#endif

void BD_as_input();

void BD_as_output();

void Display_char(char znak);
