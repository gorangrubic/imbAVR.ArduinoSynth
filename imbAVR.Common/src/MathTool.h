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

#define PANROOFZONE 7

class MathTool
{


public:

	static float GetRatio(unsigned int part, unsigned int total, float whenPartIsZero, float whenTotalIsZero);
	static byte Interpolation(byte from, byte to, unsigned int index, unsigned int length);

	static byte GetPhaseShift(byte CCValue);

	static byte GetPWMWaveform(byte CCValue);
	static byte GetCCValueForWaveform(byte pwmPattern);

	/// <summary>
	/// Computes volume byte for a channel, from ccPAN. 
	/// </summary>
	/// <param name="ccPAN">Control value for stereo panning</param>
	/// <param name="IsRightChannel">if set to <c>true</c> the result is for R channel, if false for L</param>
	/// <param name="maxVolume">Specifies what value represents 100% volume</param>
	/// <returns>byte to be sent to digpot or electronic volume control chip</returns>
	static byte GetChannelVolumeForPan(byte ccPAN, bool IsRightChannel, byte maxVolume = 100);


	/// <summary>
	/// Scales the ccValue 
	/// </summary>
	/// <param name="ccValue">The cc value.</param>
	/// <param name="ccMaxValue">Max value for the ccValue, e.g. 127 for MIDI CC value</param>
	/// <param name="maxValue">Max value for output</param>
	/// <returns></returns>
	static byte ScaleByte(byte ccValue, byte ccMaxValue, byte maxValue);

};