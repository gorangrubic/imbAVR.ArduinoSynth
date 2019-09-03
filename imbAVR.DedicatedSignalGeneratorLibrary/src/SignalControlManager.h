// SignalControlManager.h

#ifndef _SIGNALCONTROLMANAGER_h
#define _SIGNALCONTROLMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SignalControlUnit.h"
#include "SignalInstruction.h"

#include "HardwareSerial.h"

#define SIGNAL_UNITS_COUNT 12




class SignalControlManagerClass
{
 protected:


 public:

	 float CycleCompensation = 490.0;

	 byte ActiveUnitCount = 0;
	 
	 unsigned int CycleIndex = 0;

	 SignalControlUnitClass SignalUnits[SIGNAL_UNITS_COUNT];

	 byte AddSignalUnit(byte pin);


	 static byte RollPattern(byte pattern, int bits);

	 static byte DoublePitchInPattern(byte pattern);

	 String Describe(SignalInstruction instruction, unsigned int index);

	 

	// static void Describe(HardwareSerial * serialOut, SignalInstruction instruction);

	 void DescribeAll(HardwareSerial * serialOut);

	 void Perform(SignalInstruction instruction);

	 void loop();

};



#endif

