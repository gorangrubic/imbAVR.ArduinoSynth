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
	 unsigned int sClockPerPWMStep = 18;

	 byte sClockPerPWMStepB = 0;

	 unsigned int sClockIndex = 0;

	 byte pwmStepIndex;


	 
	 bool pwmContinualMode = false;

	 float pwmContinualChange = 0.5F;

	 unsigned int pwmContinualSClockIndexChange = 0;

	 void ResetClocks(bool reset_pwmIndex, bool reset_sClock, bool reset_changes);

};


#endif

