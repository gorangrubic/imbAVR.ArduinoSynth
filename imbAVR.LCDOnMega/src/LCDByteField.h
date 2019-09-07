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

class LCDByteField : public LCDField {

	byte lastValue;

	byte * value;
	
public:

	void SetValue(byte * inValue);

	void print(ACEMegaHostTFTClass* Display);

};