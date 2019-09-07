// RowOneByteField.h

#ifndef _ROWONEBYTEFIELD_h
#define _ROWONEBYTEFIELD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "RowWithUnit.h"

class RowOneByteField : public RowWithUnit {

public:

	
	LCDByteField Field = LCDByteField();


	//void Deploy(GuiScreen screen, String heading);

	virtual byte Deploy(GuiScreen screen);

	RowOneByteField(String prefix, byte * value, String unit);

	

	//virtual void PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	virtual void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

};

#endif

