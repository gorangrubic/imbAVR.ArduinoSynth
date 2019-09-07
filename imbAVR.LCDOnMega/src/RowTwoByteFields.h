#pragma once





#include "arduino.h"

#include "GuiScreen.h"

#include "LCDLabel.h"
#include "LCDByteField.h"
#include "ACEMegaHostTFT.h"

#include <RowBase.h>

class RowTwoByteFields : public RowBase {

public:

	LCDLabel LeftLabel = LCDLabel();
	LCDLabel RightLabel = LCDLabel();
	LCDByteField LeftField = LCDByteField();
	LCDByteField RightField = LCDByteField();

	//unsigned int Row = 0;

	virtual byte Deploy(GuiScreen screen);

	// void Deploy(GuiScreen screen, uint16_t fieldColor);

	virtual void PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	virtual void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	void Set(String leftLabel, String rightLabel, byte * leftValue, byte * rightValue);

	RowTwoByteFields(String leftLabel, String rightLabel, byte * leftValue, byte * rightValue);

	//void PrintLabels(ACEMegaHostTFTClass * Display);



	

	RowTwoByteFields(String leftLabel, String rightLabel, unsigned int row);

	RowTwoByteFields();

};