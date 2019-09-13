#pragma once
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "MonitoredArray.h"

#define MODSOURCES 8

#define BYTE2MODSOURCE(byteValue) byteValue / (127 / MODSOURCES)
#define MODSOURCE2BYTE(source) source * (127 / MODSOURCES)

template<byte ccModSource, byte ccModAmount, byte ccValue>
class ControlFunctionCombine
{

public:

	byte ModSourceID;

	byte ModAmount;

	byte Value;

	byte Compute(MDFValuesType CFValues);

	void Update(CCValuesType * CCValues);

};

template<byte ccModSource, byte ccModAmount, byte ccValue>
inline byte ControlFunctionCombine<ccModSource, ccModAmount, ccValue>::Compute(MDFValuesType MDFValues)
{
	floar r = MathTool::GetRatio(ModAmount, 127, 0, 0);

	byte modValue = MDFValues.Data[ModSourceID];

	return ((1 - r) * Value) + (r * modValue);

}

template<byte ccModSource, byte ccModAmount, byte ccValue>
inline void ControlFunctionCombine<ccModSource, ccModAmount, ccValue>::Update(CCValuesType* CCValues)
{
	ModSourceID = BYTE2MODSOURCE(CCValues->Data[ccModSource]); // / (127 / MODSOURCES);
	ModAmount = CCValues->Data[ccModAmount];
	Value = CCValues->Data[ccValue];

}
