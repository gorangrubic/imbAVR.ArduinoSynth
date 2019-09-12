#pragma once

#ifndef _GUISCREENVIEW_h
#define _GUISCREENVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <RowBase.h>
#include <GuiScreen.h>
#include <ACEMegaHostTFT.h>

class GuiScreenView {

public:

	//byte uid = 0;

	RowBase * Rows[14];

	byte ActiveRows = 0;

	//byte AddRow(RowBase row);

	// GuiScreen * Screen;

	//byte AddRow(RowBase row);

	byte AddRow(RowBase * row, GuiScreen * Screen);

//	GuiScreenView(byte id, GuiScreen * screen);

	GuiScreenView();

	void RenderElement(LCDElement * element, unsigned int chw, unsigned int y, unsigned int h, GuiScreen * Screen, ACEMegaHostTFTClass * Display, byte state);

	void Render(GuiScreen * screen, ACEMegaHostTFTClass * Display, byte state);

};

#endif