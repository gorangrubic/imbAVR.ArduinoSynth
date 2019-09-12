#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif

#include "ACEMegaHostTFT.h"


struct GuiScreenPallete {

	uint16_t CriticalColor = GLCD_CL_RED;

	uint16_t LabelColor = GLCD_CL_LIGHT_GRAY;
	uint16_t FieldColor = GLCD_CL_YELLOW;

	uint16_t LabelBackColor = GLCD_CL_BLACK;
	uint16_t FieldBackColor = GLCD_CL_GRAY;

	
};

class GuiScreen {


public:

	//void FillBackground(RowBase * row, ACEMegaHostTFTClass * Display, uint16_t Color);

	GuiScreen();

	byte generalMarginY = 1;
	byte generalMarginX = 1;

	GuiScreenPallete PalleteA;
	GuiScreenPallete PalleteB;

	uint16_t BackColor = GLCD_CL_BLACK;

	unsigned int ScreenWidth = 320;
	unsigned int ScreenHeight = 200;

	int TextSize = 2;

	int GetWidth(byte characters);
	int GetHeight(byte characters);

	int GetCharScreenWidth();
	int GetCharScreenHeight();

	int GetYPosition(unsigned int row);
	int GetXPosition(unsigned int character);


};
