// LCDInt16.h

#ifndef _LCDINT16_h
#define _LCDINT16_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "LCDField.h"

class LCDInt16Field : public LCDField {

	int lastValue;

	int * value;

public:

	void SetValue(int * inValue);

	virtual void print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width);




	void printValue(int v, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width, unsigned int y, uint16_t Color);



	virtual void print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width);

};


#endif

