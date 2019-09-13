#ifndef _SIGNALCONTROLUNIT_h
#define _SIGNALCONTROLUNIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SignalChangeInstruction.h"
#include "SignalControlBase.h"

#define PWMCycleSize 8

/// <summary>
/// Instance of SignalControlUnit, containing clock indexes and other "runtime" information
/// </summary>
class SignalControlUnitClass : public SignalControlBase
{
 protected:


 public:

	 byte pin = 3;


	 // this controls the pitch
	 byte sClockPerPWMStep = 18;

	 byte sClockPerPWMStepB = 0;

	 byte sClockIndex;

	 byte pwmStepIndex;


	 
	 bool pwmContinualMode = false;
	 byte pwmContinualSClockIndexChange = 0;



};


#endif

