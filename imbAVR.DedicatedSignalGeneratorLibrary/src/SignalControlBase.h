#pragma once
/// <summary>
/// SignalControlUnit base, containing "non-runtime" settings
/// </summary>
class SignalControlBase
{

public:

	bool isOn = true;

	byte sClockPrescalar = 1;

	// default PWM pattern is 50% square pulse waveform
	byte pwmByte = B11110000;


	unsigned int freq = 110;


	// relationship with master pitch
	byte masterPitchRelationship = 0;

	SignalChangeInstruction PWMChange;
	SignalChangeInstruction PhaseChange;
	SignalChangeInstruction PitchChange;
	SignalChangeInstruction ResetClock;
};

