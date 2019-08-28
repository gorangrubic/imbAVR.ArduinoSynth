#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif

#include <SPI.h>

#include "inttypes.h"

class digPotCluster {


	//Pin connected to ST_CP of 74HC595
	byte latchPin = 8;
	//Pin connected to SH_CP of 74HC595
	byte clockPin = 12;
	////Pin connected to DS of 74HC595
	byte dataPin = 11;

public:

	void init(byte latch_pin, byte clock_pin, byte data_pin);

	byte lastValues[8];

	void Write(byte dp1, byte dp2, byte dp3, byte dp4, byte dp5, byte dp6, byte dp7, byte dp8);

	void CheckAndWrite(int whichPin, byte dp_value);

	void Debug();

	void SetOut(byte myDataOut);

	void Write(int whichPin, byte dp_value);

};