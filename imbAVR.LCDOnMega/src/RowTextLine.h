// RowTextLine.h

#ifndef _ROWTEXTLINE_h
#define _ROWTEXTLINE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "LCDTextLine.h"

class RowTextLine : public RowBase {

	LCDTextField Field = LCDTextField();

	RowTextLine(String * text);

	virtual byte Deploy(GuiScreen screen);

	// void Deploy(GuiScreen screen, uint16_t fieldColor);

	virtual void PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	virtual void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen);
};


#endif

