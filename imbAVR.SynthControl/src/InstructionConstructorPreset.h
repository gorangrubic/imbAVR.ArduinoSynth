#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SynthState.h"
#include "MathTool.h"
#include "SignalChangeInstruction.h"
#include "SignalMacroInstruction.h"
#include "MidiConfig.h"

template<byte SID>
class InstructionConstructorPreset
{
public:

	SignalMacroInstruction CreateChangeInstruction(byte cid, byte change, byte rate, byte period, byte mode, byte sid_override=255);

	SignalMacroInstruction CreateModeInstruction(bool IsPWMCycle, bool IsDoublePrescalar, bool IsSignalON, bool IsPitchSlave, bool IsPositiveRelation, bool IsRelativeDistance, bool IsPitchMidiNote, unsigned int Pitch, byte sid_override=255);
};

template<byte SID>
SignalMacroInstruction InstructionConstructorPreset<SID>::CreateChangeInstruction(byte cid, byte change, byte rate, byte period, byte mode, byte sid_override)
{
	SignalMacroInstruction output;

	//byte b1 = (SID << 4) | (change);

	byte b1 = 0;

	if (sid_override != 255) {
		b1 = (sid_override << 4) | (cid);
	}
	else {
		b1 = (SID << 4) | (cid);
	}

	byte options = mode << 6;
	options |= period;
	output.data = 0;
	output.data += b1;
	output.data = output.data << 8;
	output.data += change;
	output.data = output.data << 8;
	output.data += rate;
	output.data = output.data << 8;
	output.data += options;

//	output.data = b12 << 16 | b34; //(b1 << 24) | change << 16 | rate << 8 | options;
	return output;

}

template<byte SID>
SignalMacroInstruction InstructionConstructorPreset<SID>::CreateModeInstruction(bool IsPWMCycle, bool IsDoublePrescalar, bool IsSignalON, bool IsPitchSlave, bool IsPositiveRelation, bool IsRelativeDistance, bool IsPitchMidiNote, unsigned int Pitch, byte sid_override)
{
	byte modeByte = 0;

	if (IsPWMCycle) bitSet(modeByte, 0);
	if (IsDoublePrescalar) bitSet(modeByte, 1);
	if (IsSignalON) bitSet(modeByte, 2);
	if (IsPitchSlave) bitSet(modeByte, 3);
	if (IsPositiveRelation) bitSet(modeByte, 4);
	if (IsRelativeDistance) bitSet(modeByte, 5);
	if (IsPitchMidiNote) bitSet(modeByte, 6);


	SignalMacroInstruction output;

	byte b1 = 0;
	
	if (sid_override != 255) {
		b1 = (sid_override << 4) | (CID_NoteControl);
	}
	else {
		b1 = (SID << 4) | (CID_NoteControl);
	}
	output.data = 0;
	output.data += b1;
	output.data = output.data << 8;
	output.data += modeByte;
	output.data = output.data << 8;
	output.data += Pitch;

	//output.data = (b1 << 24) | modeByte << 16 | Pitch;
	return output;

}
