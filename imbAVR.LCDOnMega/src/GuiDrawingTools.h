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

#include "FieldValueRenderMode.h"

class GuiDrawingTools
{

public:


	//static void DeployField(GuiScreen * Screen, LCDElement * field, RowBase * row, boolean invert = false);

	//static void DeployLabel(GuiScreen * Screen, LCDLabel * label, RowBase * row, boolean invert = false);

	//static void RenderRow(RowBase * row, ACEMegaHostTFTClass * Display, GuiScreen * Screen, byte yC, byte state);

	static void drawBitBoxes(unsigned int marginX, unsigned int marginY, unsigned int y, unsigned int x, unsigned int w, unsigned int h, byte bits, byte bitCount, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff);

	//static void print(LCDElement * Field, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width);

	//static void drawBitBoxes(GuiScreen * Screen, unsigned int y, unsigned int x, unsigned int w, unsigned int h, byte bits, byte bitCount, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff);

	
	 static void drawValue(unsigned int marginX, unsigned int marginY, unsigned int y, unsigned int x, unsigned int w, unsigned int h, float r, FieldValueRenderMode mode, ACEMegaHostTFTClass * Display, uint16_t ColorOn, uint16_t ColorOff);


	//static void FillBackground(GuiScreen * Screen, RowBase * row, ACEMegaHostTFTClass * Display, uint16_t Color, byte yMargin = 0, byte xMargin = 0, byte rowHeight = 1);

	//static void FillBackground(GuiScreen * Screen, uint16_t xStart, uint16_t xEnd, RowBase * row, ACEMegaHostTFTClass * Display, uint16_t Color, byte yMargin = 0, byte xMargin = 0, byte rowHeight = 1);


};

