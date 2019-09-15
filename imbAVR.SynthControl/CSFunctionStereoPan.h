#pragma once
#include "SynthState.h"
#include "MathTool.h"

template<byte csLChannel, byte csRChannel, byte maxVolume>
class CSFunctionStereoPan
{
public:
	void Update(CSValuesType * csValues, byte pan);

	void Update(CSValuesType * csValues, byte pan, byte vol);
};

template<byte csLChannel, byte csRChannel, byte maxVolume>
inline void CSFunctionStereoPan<csLChannel, csRChannel, maxVolume>::Update(CSValuesType * csValues, byte pan)
{
	csValues.SetValue(csLChannel, MathTool::GetChannelVolumeForPan(pan, false, maxVolume));
	csValues.SetValue(csRChannel, MathTool::GetChannelVolumeForPan(pan, true, maxVolume));

}

template<byte csLChannel, byte csRChannel, byte maxVolume>
inline void CSFunctionStereoPan<csLChannel, csRChannel, maxVolume>::Update(CSValuesType * csValues, byte pan, byte vol)
{
	vol = MathTool::ScaleByte(vol, 127, maxVolume);

	csValues.SetValue(csLChannel, MathTool::GetChannelVolumeForPan(pan, false, vol));
	csValues.SetValue(csRChannel, MathTool::GetChannelVolumeForPan(pan, true, vol));

}