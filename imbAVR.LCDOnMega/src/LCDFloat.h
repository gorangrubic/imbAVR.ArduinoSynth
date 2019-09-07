// LCDFloat.h

#ifndef _LCDFLOAT_h
#define _LCDFLOAT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "LCDField.h"

class LCDFloatField : public LCDField {

	float lastValue;

	float * value;

public:

	void SetValue(float * inValue);

	

	void printValue(float v, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width, unsigned int y, uint16_t Color);



	virtual void print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width);

};

#endif

