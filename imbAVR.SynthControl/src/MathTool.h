#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif

#include "inttypes.h"

class MathTool
{


public:

	static float GetRatio(unsigned int part, unsigned int total, float whenPartIsZero, float whenTotalIsZero);
	static byte Interpolation(byte from, byte to, unsigned int index, unsigned int length);

	static byte GetPhaseShift(byte CCValue);

	static byte GetPWMWaveform(byte CCValue);
};