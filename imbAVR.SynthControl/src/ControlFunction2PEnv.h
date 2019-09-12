#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
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

	byte ComputeR(unsigned int cT);

	void Update(MonitoredArray<16> * CCValues);
	
};

