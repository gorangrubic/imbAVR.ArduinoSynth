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


#include "MathTool.h"

#define SIGNAL_UNITS_COUNT 12



#define CCID_PWMBYTE 0
#define CCID_PHASEBYTE 1
#define CCID_PITCHBYTELOW 2
#define CCID_PITCHBYTEHIGH 3
#define CCID_MODEBYTE 4

#define CCID_CHANGE_PWM 9
#define CCID_CHANGE_RATE_PWM 10

#define CCID_CHANGE_PHASE 11
#define CCID_CHANGE_RATE_PHASE 12

#define CCID_CHANGE_PITCH 13
#define CCID_CHANGE_RATE_PITCH 14


#define CCID_CHANGE_RESET 15
#define CCID_CHANGE_RATE_RESET 16


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

	 //static String Describe(SignalInstruction instruction, unsigned int index);

	 void Receive(byte receivedByte);

	 //void SetCC(byte cc, byte value, SignalControlUnitClass * signal);

	// static void Describe(HardwareSerial * serialOut, SignalInstruction instruction);

	 //void Set(byte cc_sid, byte value);

	 void DescribeAll(HardwareSerial * serialOut);

	 void PerformPhaseByte(byte Phase, SignalControlUnitClass * signal);

	 void PerformModeByte(byte Phase, SignalControlUnitClass * signal);

	 void PerformPitch(unsigned int Pitch, SignalControlUnitClass * signal);

	// void Perform(SignalInstruction instruction);

	 void loop();

};



#endif

