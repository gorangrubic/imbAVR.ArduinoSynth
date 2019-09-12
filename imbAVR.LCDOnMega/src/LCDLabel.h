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

#include "LCDElement.h"

class LCDLabel : public LCDElement
{

public:

	String label = "";
	//void LCDLabel::print(ACEMegaHostTFTClass * Display);

	//virtual 
		//void print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width=0);

	//virtual void print(ACEMegaHostTFTClass * Display, GuiScreen * Screen, RowBase * row, unsigned int width);

		LCDLabel(String label);
		LCDLabel();

		virtual void Render(ACEMegaHostTFTClass * Display, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int char_w, unsigned int Forecolor, unsigned int Backcolor, byte state) override;
};