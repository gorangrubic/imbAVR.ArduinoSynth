#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


#include "SignalChangeInstruction.h"

/// <summary>
/// SignalControlUnit base, containing "non-runtime" settings
/// </summary>
class SignalControlBase
{

public:

	bool isDisabled = false;
	bool isOn = true;

	byte sClockPrescalar = 1;

	// default PWM pattern is 50% square pulse waveform
	byte pwmByte = 0b11110000;


	unsigned int freq = 110;
	unsigned int delta_freq = 0;


	bool IsPitchSlave = false;
	bool IsPositiveRelation = false;
	bool IsRelativeDistanceMode = false;

	bool IsMidiNote = false;

	// relationship with master pitch
	byte masterPitchRelationship = 0;

	byte modulationByte = 0;

	SignalChangeInstruction PWMChange;
	SignalChangeInstruction PhaseChange;
	SignalChangeInstruction PitchChange;
	SignalChangeInstruction ResetClock;
};

