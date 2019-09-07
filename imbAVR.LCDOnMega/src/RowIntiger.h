// RowIntiger.h

#ifndef _ROWINTIGER_h
#define _ROWINTIGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "RowWithUnit.h"

#include "LCDInt16.h"

class RowIntiger : public RowWithUnit {

public:


	LCDInt16Field Field = LCDInt16Field();


	//void Deploy(GuiScreen screen, String heading);

	virtual byte Deploy(GuiScreen screen);

	RowIntiger(String prefix, int * value, String unit);



	

	virtual void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

};


#endif

