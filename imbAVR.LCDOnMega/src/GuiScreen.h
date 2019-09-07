#pragma once


#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif
//
#include "ACEMegaHostTFT.h"
//
//#include "LCDLabel.h"
//#include "LCDByteField.h"
//
//#include <GuiScreenView.h>
//#include <GuiScreenViewSet.h>

class GuiScreen {


public:

	//void FillBackground(RowBase * row, ACEMegaHostTFTClass * Display, uint16_t Color);

	byte generalMarginY = 1;
	byte generalMarginX = 1;

	void DeployField(LCDField * field, RowBase * row, boolean invert=false);

	void DeployLabel(LCDLabel * label, RowBase * row, boolean invert = false);

	void drawBitBoxes(unsigned int y, unsigned int x, unsigned int w, unsigned int h, byte bits, byte bitCount, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff);

	void drawValue(unsigned int y, unsigned int x, unsigned int width, unsigned int height, float r, FieldValueRenderMode mode, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff);

	void drawValue(unsigned int y, unsigned int x, unsigned int width, unsigned int height, int v, unsigned int total, FieldValueRenderMode mode, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff);

	void FillBackground(RowBase * row, ACEMegaHostTFTClass * Display, uint16_t Color, byte yMargin=0, byte xMargin=0, byte rowHeight = 1);

	void FillBackground(uint16_t xStart, uint16_t xEnd, RowBase * row, ACEMegaHostTFTClass * Display, uint16_t Color, byte yMargin=0, byte xMargin=0,byte rowHeight = 1);

	uint16_t LabelColor = GLCD_CL_LIGHT_GRAY;
	uint16_t FieldColor = GLCD_CL_YELLOW;

	uint16_t LabelBackColor = GLCD_CL_BLACK;
	uint16_t FieldBackColor = GLCD_CL_GRAY;

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











