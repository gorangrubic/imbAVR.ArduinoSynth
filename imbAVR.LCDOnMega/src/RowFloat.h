// RowFloat.h

#ifndef _ROWFLOAT_h
#define _ROWFLOAT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "RowWithUnit.h"
#include "LCDFloat.h"

class RowFloat : public RowWithUnit {


public:

	LCDFloatField Field = LCDFloatField();

	virtual byte Deploy(GuiScreen screen);

	RowFloat(String prefix, float * value, String unit);



	virtual void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen);
};

#endif

