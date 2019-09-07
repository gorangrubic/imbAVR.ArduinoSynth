// RowTextLineWithPrefix.h

#ifndef _ROWTEXTLINEWITHPREFIX_h
#define _ROWTEXTLINEWITHPREFIX_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "RowWithUnit.h"
#include "LCDTextLine.h"

class RowTextLineWithPrefix : public RowWithUnit{

public:


	LCDTextField Field = LCDTextField();


	//void Deploy(GuiScreen screen, String heading);

	virtual byte Deploy(GuiScreen screen);

	RowTextLineWithPrefix(String prefix, String * value, String unit);



	//virtual void PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	virtual void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

};


#endif

