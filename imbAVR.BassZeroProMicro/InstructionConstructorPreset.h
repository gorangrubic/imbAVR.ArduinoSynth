#pragma once


#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SynthState.h"
#include "MathTool.h"
#include "SignalChangeInstruction.h"

template<byte SID>
class InstructionConstructorPreset
{
public:

	SignalMacroInstruction CreateChangeInstruction(byte cid, byte change, byte rate, byte period, byte mode);

	SignalMacroInstruction CreateModeInstruction(bool IsPWMCycle, bool IsDoublePrescalar, bool IsSignalON, bool IsPitchSlave, bool IsPositiveRelation, bool IsRelativeDistance, bool IsPitchMidiNote, unsigned int Pitch, byte sid_override=255);
};

template<byte SID>
inline SignalMacroInstruction InstructionConstructorPreset<SID>::CreateChangeInstruction(byte cid, byte change, byte rate, byte period, byte mode)
{
	SignalMacroInstruction output;

	byte b1 = (SID << 4) | (change);
	byte options = mode << 6;
	options |= period;

	output.data = (b1 << 24) | change << 16) | rate << 8 | options;
	return output;

}

template<byte SID>
inline SignalMacroInstruction InstructionConstructorPreset<SID>::CreateModeInstruction(bool IsPWMCycle, bool IsDoublePrescalar, bool IsSignalON, bool IsPitchSlave, bool IsPositiveRelation, bool IsRelativeDistance, bool IsPitchMidiNote, unsigned int Pitch, byte sid_override)
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
	
	output.data = (b1 << 24) | modeByte << 16) | Pitch;
	return output;

}
