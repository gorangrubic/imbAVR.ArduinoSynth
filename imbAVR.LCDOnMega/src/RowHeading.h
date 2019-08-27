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

class RowHeading : public LCDField {

public:

	LCDLabel LeftLabel = LCDLabel();
	
	
	unsigned int Row = 0;


	uint16_t w = 0;
	uint16_t h = 0;

	void Deploy(GuiScreen screen, String heading);

	RowHeading(int row);

	void PrintLabels(ACEMegaHostTFTClass * Display);

};