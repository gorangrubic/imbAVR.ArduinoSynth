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




class LCDField {

public:

	virtual void print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width) = 0;

	void setPosition(ACEMegaHostTFTClass* Display);

	uint16_t TextColor = GLCD_CL_BLUE;
	uint16_t BackColor = GLCD_CL_BLACK;

	uint16_t x = 0;
	//uint16_t y = 0;

	FieldValueRenderMode renderMode = FieldValueRenderMode::numeric_value;

	//void printValue(byte v, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width, unsigned int y, uint16_t Color);



	//virtual void print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width) = 0;

	//uint16_t w = 0;
	//uint16_t h = 0;


};