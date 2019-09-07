// RowWithUnit.h

#ifndef _ROWWITHUNIT_h
#define _ROWWITHUNIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GuiScreen.h"

#include "LCDLabel.h"
#include "LCDByteField.h"
#include "ACEMegaHostTFT.h"

#include <RowBase.h>

class RowWithUnit : public RowBase {

protected:

	void DeployBase(GuiScreen screen, LCDField * field);

public:

	LCDLabel LabelPrefix = LCDLabel();

	LCDLabel LabelUnit = LCDLabel();

	unsigned int FieldX = 0;

	virtual byte Deploy(GuiScreen screen) = 0;

	virtual void PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	virtual void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen) = 0;
};

#endif

