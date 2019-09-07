// SignalControlUnit.h

#ifndef _SIGNALCONTROLUNIT_h
#define _SIGNALCONTROLUNIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SignalInstruction.h"

#define PWMCycleSize 8

/// <summary>
/// 
/// </summary>
class SignalControlUnitClass
{
 protected:


 public:

	 byte pin = 3;
	 
	 unsigned int freq = 110;

	 // this controls the pitch
		byte sClockPerPWMStep = 18;

		byte sClockPerPWMStepB = 0;

	 byte sClockIndex;

	 byte pwmStepIndex;

	 // default PWM pattern is 50% square pulse waveform
	 byte pwmPatternByte = B11110000;
	 
	 bool pwmContinualMode = false;
	 byte pwmContinualSClockIndexChange = 0;
	 bool isOn = true;

	 byte sClockPrescalar = 1;





	 SignalChangeInstruction PWMChange;
	 SignalChangeInstruction PhaseChange;
	 SignalChangeInstruction PitchChange;
	 SignalChangeInstruction ResetClock;

};


#endif

