#include "SignalInstruction.h"


unsigned int SignalInstruction::GetControlByte()
{
	return SignalID + Frequency + pwmPattern + Phase;
}

byte SignalInstruction::GetCCID(byte cc_id)
{
	return (cc_id & B11110000) >> 4;
}

byte SignalInstruction::GetSID(byte cc_id)
{
	return (cc_id & B00001111);
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

void SignalInstruction::clearCache()
{
	for (size_t i = 0; i < 16; i++)
	{
		lastSent[i] = 0;

	}
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

void SignalChangeInstruction::SetBytes(byte b2, byte b3, byte options)
{
	Change = b2;
	Rate = b3;
	SetOptions(options);

}

void SignalChangeInstruction::SetOptions(byte options)
{
	mode = options >> 6;
	period = options & B00111111;

}

byte SignalChangeInstruction::GetOptions()
{
	byte options = mode << 66;
	options |= period;

	return options;
}

void SignalChangeInstruction::PerformPeriod()
{

	PeriodIndex++;

	if (PeriodIndex > period) {
		if (mode == 1) Change = 0;
		else if (mode == 2) PeriodIndex = 0;
		else if (mode == 3) {
			Change -= Change; 
			PeriodIndex = 0;
		}
	}
}


