#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif

#include "LCDField.h"


enum FieldValueRenderMode
{
	numeric_value,
	numeric_ratio,
	numeric_percentage,
	graphic_horizontal_bar,
	graphic_vertical_bar,
	graphic_horizontal_biased_bar,
	graphic_vertical_biased_bar,
	graphic_resized_box,
	graphic_resized_circle,
	graphic_bitBoxArray,
	graphic_bitBoxArrayLow4,
	graphic_bitBoxArrayHigh4,
	graphic_boolean_box,
	graphic_boolean_circle,


};

class LCDByteField : public LCDField {

	byte lastValue;

	byte * value;
	
	//void printValue(boolean lastValue, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width);

public:


	void SetValue(byte * inValue);

	void printValue(byte v, ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width, unsigned int y, uint16_t Color);



	virtual void print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width);

	

};