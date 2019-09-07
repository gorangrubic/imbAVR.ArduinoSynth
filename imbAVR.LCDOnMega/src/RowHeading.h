#pragma once
#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif


#include "GuiScreen.h"

#include "LCDLabel.h"
#include "LCDByteField.h"
#include "ACEMegaHostTFT.h"

#include <RowBase.h>


class RowHeading : public RowBase {

public:

	LCDLabel LeftLabel = LCDLabel();
	
	


	//void Deploy(GuiScreen screen, String heading);

	virtual byte Deploy(GuiScreen screen);

	RowHeading(String heading);

	RowHeading();

	virtual void PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	virtual void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

};

