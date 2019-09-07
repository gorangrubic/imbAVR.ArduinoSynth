// RowFourByteFields.h

#ifndef _ROWFOURBYTEFIELDS_h
#define _ROWFOURBYTEFIELDS_h

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


class RowThreeByteFields : public RowBase {

public:

	LCDLabel Labels[3];
	LCDByteField Fields[3];

	virtual byte Deploy(GuiScreen screen);

	virtual void PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	virtual void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	RowThreeByteFields(String labelA, byte * valueA, String labelB, byte * valueB, String labelC, byte * valueC);

	RowThreeByteFields();

};

class RowFourByteFields : public RowBase {

public:

	LCDLabel Labels[4];
	LCDByteField Fields[4];

	virtual byte Deploy(GuiScreen screen);

	virtual void PrintLabels(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	virtual void UpdateFields(ACEMegaHostTFTClass * Display, GuiScreen * Screen);

	RowFourByteFields(String labelA, byte * valueA, String labelB, byte * valueB, String labelC, byte * valueC, String labelD, byte * valueD);

	RowFourByteFields();

};


#endif

