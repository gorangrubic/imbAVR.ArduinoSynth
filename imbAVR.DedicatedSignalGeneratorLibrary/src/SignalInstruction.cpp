
#include "SignalInstruction.h"


unsigned int SignalInstruction::GetControlByte()
{
	return SignalID + Frequency + pwmPattern + Phase;
}

String SignalInstruction::GetString()
{

	String data = "";

	data += "[";
	data += SignalID;
	data += " ";
	data += Frequency;
	data += " ";
	data += Phase;
	data += " ";
	data += pwmPattern;
	data += " ]";


	return data;

	/*
	SoftSerial.print(instruction.SignalID);

	SoftSerial.print(STRPROTOCOL_SPLIT);

	SoftSerial.print(instruction.Frequency);

	SoftSerial.print(STRPROTOCOL_SPLIT);

	SoftSerial.print(instruction.Phase);

	SoftSerial.print(STRPROTOCOL_SPLIT);

	SoftSerial.print(instruction.pwmPattern);

	SoftSerial.print(STRPROTOCOL_END);
	*/
}

void SignalInstruction::Set(byte signalID, unsigned int frequency, byte waveform = WAVEFORM_HALFCYCLE, byte phase_shift = 0, bool resetPWMStep = true, bool resetSClock = true, bool setPWMStep = true, bool setSClock = false) {

	byte _Phase;
	phase_shift = constrain(phase_shift, 0, 16);

	_Phase = phase_shift << 4;
	if (resetPWMStep) _Phase = _Phase | PHASE_INSTRUCTION_RESETPWMSTEP;
	if (resetSClock) _Phase = _Phase | PHASE_INSTRUCTION_RESETSCLOCK;
	if (setPWMStep) _Phase = _Phase | PHASE_INSTRUCTION_SETPWMSTEP;
	if (setSClock) _Phase = _Phase | PHASE_INSTRUCTION_SETSCLOCK;

	while (frequency > 3440) {
		frequency = frequency / 2;
	}

	Frequency = frequency;
	pwmPattern = waveform;
	Phase = _Phase;
	SignalID = signalID;

	

}