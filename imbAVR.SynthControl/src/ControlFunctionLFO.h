#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "MonitoredArray.h"
#include "SynthState.h"

template<byte ccTime, byte ccTimeFactor, byte ccLevel>
class ControlFunctionLFO
{
	unsigned int ATime = 25;

	byte ALevel = 255;
	
	unsigned int lastChange = 0;

	// internal time position
	unsigned int int_cT;

public:

	//byte ATimeFactor = 1;

	byte Compute(unsigned int cT);

	void Update(CCValuesType * CCValues);


};

template<byte ccTime, byte ccTimeFactor, byte ccLevel>
inline byte ControlFunctionLFO<ccTime, ccTimeFactor, ccLevel>::Compute(unsigned int cT)
{
	unsigned int cTc = 0;

	if (cT < int_cT) {
		// global time overflow occured
		cTc = (65535 - int_cT) + cT; // compensates overflow
	}
	else {
		cTc = cT;
	}

	// stores global time, to detect overflow
	int_cT = cT;



	unsigned int since = cTc - lastChange;

	if (since > ATime) {
		lastChange = cTc;
		since = 0;
	}

	
	if (since > (ATime / 2)) {
		return MathTool::Interpolation(ALevel, 0, since- (ATime / 2), ATime/2);
	}
	else {
		return MathTool::Interpolation(0, ALevel, since, ATime / 2);
	}

	
}

template<byte ccTime, byte ccTimeFactor, byte ccLevel>
inline void ControlFunctionLFO<ccTime, ccTimeFactor, ccLevel>::Update(CCValuesType* CCValues)
{
	if (CCValues->IsChanged(ccTime, ccTimeFactor, ccLevel)) {

		ATime = CCValues[ccTime] * (CCValues[ccTimeFactor] + 1);
		ALevel = CCValues[ccLevel];
	}
}
