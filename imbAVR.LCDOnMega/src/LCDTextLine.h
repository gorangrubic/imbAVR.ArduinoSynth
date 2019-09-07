// LCDTextLine.h

#ifndef _LCDTEXTLINE_h
#define _LCDTEXTLINE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "LCDField.h"

class LCDTextField : public LCDField {

	String lastValue;

	String * value;

public:

	void SetValue(String * inValue);

	virtual void print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width);

};

#endif

