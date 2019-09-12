#pragma once
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "MathTool.h"

template<byte ccTime, byte ccSpread>
class ControlFunctionChaos
{


protected:

	unsigned int ATime = 25;

	byte Spread = 0;

	byte BLevel = 255;
	byte ALevel = 127;

	unsigned int lastChange = 0;

public:

	
	byte Compute(unsigned int cT);

	void Update(MonitoredArray<16> * CCValues);
};

template<byte ccTime, byte ccSpread>
inline byte ControlFunctionChaos<ccTime, ccSpread>::Compute(unsigned int cT)
{
	if (lastChange == 0) {
		// initiation
		ALevel = 127;
		BLevel = random(0, Spread);
	}

	if ((cT - lastChange) > ATime) {
		lastChange = cT;
		BLevel = random(0, Spread);
	}

	return MathTool::Interpolation(ALevel, BLevel, cT - lastChange, ATime);
}

template<byte ccTime, byte ccSpread>
inline void ControlFunctionChaos<ccTime, ccSpread>::Update(MonitoredArray<16>* CCValues)
{
	if (CCValues->IsChanged(ccTime, ccSpread)) {
		ATime = CCValues[ccTime];
		Spread = CCValues[ccSpread];

	}

}