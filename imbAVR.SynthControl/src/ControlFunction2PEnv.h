#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "MonitoredArray.h"

template<byte ccATime, byte ccBTime, byte ccALevel, byte ccBLevel>
class ControlFunction2PEnv
{

	unsigned int ATime = 25;

	unsigned int BTime = 100;


	byte ALevel = 255;
	byte BLevel = 0;

public:

	byte ATimeFactor = 1;

	byte BTimeFactor = 4;

	byte Compute(unsigned int cT);

	void Update(CCValuesType * CCValues);
	
};

template<byte ccATime, byte ccBTime, byte ccALevel, byte ccBLevel>
inline byte ControlFunction2PEnv<ccATime, ccBTime, ccALevel, ccBLevel>::Compute(unsigned int cT)
{
	if (cT > ATime) {
		// decay phase
		return MathTool::Interpolation(ALevel, BLevel, cT - ATime, BTime);
	}
	else {
		// attack phase
		return MathTool::Interpolation(BLevel, ALevel, cT, ATime);
	}
}

template<byte ccATime, byte ccBTime, byte ccALevel, byte ccBLevel>
inline void ControlFunction2PEnv<ccATime, ccBTime, ccALevel, ccBLevel>::Update(CCValuesType* CCValues)
{

	
	ATime = CCValues[ccATime] * ATimeFactor;
	BTime = CCValues[ccBTime] * BTimeFactor;

	ALevel = CCValues[ccALevel];
	BLevel = CCValues[ccBLevel];



}
