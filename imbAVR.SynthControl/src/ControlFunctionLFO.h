#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

template<byte ccTime, byte ccTimeFactor, byte ccLevel>
class ControlFunctionLFO
{
	unsigned int ATime = 25;

	byte ALevel = 255;
	
	unsigned int lastChange = 0;

public:

	//byte ATimeFactor = 1;

	byte Compute(unsigned int cT);

	void Update(MonitoredArray<16> * CCValues);


};

template<byte ccTime, byte ccTimeFactor, byte ccLevel>
inline byte ControlFunctionLFO<ccTime, ccTimeFactor, ccLevel>::Compute(unsigned int cT)
{
	unsigned int since = cT - lastChange;

	if (since > ATime) {
		lastChange = cT;
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
inline void ControlFunctionLFO<ccTime, ccTimeFactor, ccLevel>::Update(MonitoredArray<16>* CCValues)
{
	if (CCValues->IsChanged(ccTime, ccTimeFactor, ccLevel)) {

		ATime = CCValues[ccTime] * (CCValues[ccTimeFactor] + 1);
		ALevel = CCValues[ccLevel];
	}
}
