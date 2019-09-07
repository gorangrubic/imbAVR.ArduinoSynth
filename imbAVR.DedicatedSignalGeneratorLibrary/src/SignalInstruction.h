#ifndef _SIGNALINSTRUCTION_h
#define _SIGNALINSTRUCTION_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define PHASE_INSTRUCTION_RESETPWMSTEP	B00000001
#define PHASE_INSTRUCTION_RESETSCLOCK	B00000010
#define PHASE_INSTRUCTION_SETPWMSTEP	B00000100
#define PHASE_INSTRUCTION_SETSCLOCK		B00001000


#define WAVEFORM_HALFCYCLE	B11110000
#define WAVEFORM_1_4_CYCLE	B11000000
#define WAVEFORM_3_4_CYCLE	B11111100
#define WAVEFORM_1_8_CYCLE	B10000000
#define WAVEFORM_7_8_CYCLE	B11111110

#define SIGNALINSTRUCTION_DATASIZE 5
#define SIGNALINSTRUCTION_PREFIXSIZE 5
#define SIGNALINSTRUCTION_SIZE 20

#define SIGNAL_STARTBYTE B00000000

#define SIGNAL_ENDBYTE B11111111


class SignalChangeInstruction {
	
public:
	byte Rate = 256;
	byte RateIndex = 0;
	// change = 1 => -126, change = 255 = +126
	byte Change = 0;


};


//enum SignalAspect {
//	pwm,
//	pitch,
//
//};

//class SignalInstructionByte {
//
//
//	void Set(byte cc_id, byte s_id, byte value);
//
//	
//
//	byte GetCCID();
//
//	byte GetSID();
//
//	//byte cc_id;
//
//	//byte s_id;
//
//
//	byte cc_s_id;
//	byte value;
//
//};

class SignalInstruction {

public:
	// 00xx xxxx Signal id: 0-7
	byte SignalID;

	unsigned int Frequency;

	// xxxx 0000  Phase shift: 0-7

	// 0000 xxxx  Phase instruction

	// 0 ---- 0000 No instruction
	// 1 ---- 0001 Reset oscilator
	// 2 ---- 0010 
	// 3 ---- 0011 
	// 4 ---- 0110 
	// 5 ---- 0111 
	// 6 ---- 1110 
	// 7 ---- 1111 Reset all oscilators

	byte Phase = 0;

	byte pwmPattern = B11110000;
	
	unsigned int lastControlByte = 0;
	unsigned int GetControlByte();

	static byte GetCCID(byte cc_id);

	static byte GetSID(byte cc_id);


	byte Mode = B00000100;
	
	// bytes sent last time
	byte lastSent[16];
	byte TempByte = 0;

	SignalChangeInstruction PWMChange;
	SignalChangeInstruction PhaseChange;
	SignalChangeInstruction PitchChange;
	SignalChangeInstruction ResetClock;

	String GetString();

	void clearCache();
	
	void Set(byte signalID, unsigned int frequency, byte waveform, byte phase_shift, bool resetPWMStep, bool resetSClock, bool setPWMStep, bool setSClock);

};

#endif