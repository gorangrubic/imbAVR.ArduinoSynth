// GuiScreenView.h

#ifndef _GUISCREENVIEW_h
#define _GUISCREENVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <RowBase.h>

class GuiScreenView {

public:

	byte uid = 0;

	RowBase * Rows[14];

	byte ActiveRows = 0;

	//byte AddRow(RowBase row);

	GuiScreen * Screen;

	//byte AddRow(RowBase row);

	byte AddRow(RowBase * row);

	GuiScreenView(byte id, GuiScreen * screen);

	GuiScreenView();

	void PrintLabels(ACEMegaHostTFTClass * Display);

	void UpdateFields(ACEMegaHostTFTClass * Display);


};

#endif

