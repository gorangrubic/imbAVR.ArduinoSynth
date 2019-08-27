#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#include "arduino.h"
#include "inttypes.h"

#endif

class ADSRFunction
{

public:

	unsigned int AttackTime = 0;

	unsigned int DecayTime = 0;

	unsigned int ReleaseTime = 0;


	byte InitLevel;
	byte PeakLevel;
	byte SustainLevel;

	byte ComputeADS(unsigned int cT);
	byte ComputeR(unsigned int cT);

	void SetTimes(unsigned int At, unsigned int Dt, unsigned int Rt);

	void SetLevels(byte iL, byte pL, byte sL);

	ADSRFunction();
	~ADSRFunction();
};
