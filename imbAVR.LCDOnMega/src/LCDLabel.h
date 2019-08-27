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

class LCDLabel : public LCDField {

public:
	String label;
	void LCDLabel::print(ACEMegaHostTFTClass * Display);

	

};