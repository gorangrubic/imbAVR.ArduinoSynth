#pragma once





#include "arduino.h"

#include "GuiScreen.h"

#include "LCDLabel.h"
#include "LCDByteField.h"
#include "ACEMegaHostTFT.h"

class RowTwoByteFields {

public:

	LCDLabel LeftLabel = LCDLabel();
	LCDLabel RightLabel = LCDLabel();
	LCDByteField LeftField = LCDByteField();
	LCDByteField RightField = LCDByteField();

	unsigned int Row = 0;

	void Deploy(GuiScreen screen);

	void Deploy(GuiScreen screen, uint16_t fieldColor);

	void PrintLabels(ACEMegaHostTFTClass * Display);

	void UpdateFields(ACEMegaHostTFTClass * Display);

	void Set(String leftLabel, String rightLabel, byte leftValue, byte rightValue);

	RowTwoByteFields(String leftLabel, String rightLabel, unsigned int row);

	RowTwoByteFields(unsigned int row);

};