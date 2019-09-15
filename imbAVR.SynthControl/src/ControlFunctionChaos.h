#pragma once
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "MathTool.h"
#include "MonitoredArray.h"
#include "SynthState.h"

template<byte ccTime, byte ccSpread, byte ccTimeFactor>
class ControlFunctionChaos
{


protected:

	byte TimeFactor = 1;
	unsigned int ATime = 25;

	byte Spread = 0;

	byte BLevel = 255;
	byte ALevel = 127;

	unsigned int lastChange = 0;

public:

	
	byte Compute(unsigned int cT);

	void Update(CCValuesType * CCValues);
};

template<byte ccTime, byte ccSpread, byte ccTimeFactor>
inline byte ControlFunctionChaos<ccTime, ccSpread, ccTimeFactor>::Compute(unsigned int cT)
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

template<byte ccTime, byte ccSpread, byte ccTimeFactor>
inline void ControlFunctionChaos<ccTime, ccSpread, ccTimeFactor>::Update(CCValuesType* CCValues)
{
	if (CCValues->IsChanged(ccTime, ccSpread, ccTimeFactor)) {

		TimeFactor = CCValues->Data[ccTimeFactor];
		ATime = CCValues->Data[ccTime] * TimeFactor;
		Spread = CCValues->Data[ccSpread];

	}

}