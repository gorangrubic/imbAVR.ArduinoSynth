#pragma once

#include "SynthState.h"
#include "SignalMacroInstruction.h"

/* Universal macro instruction generator, based on CC inputs*/
template<byte SID, byte cid_target>
class InstructionConstructor
{
public:

	SignalMacroInstruction Create(byte b2, byte b3, byte b4);

	SignalMacroInstruction CreateNote(bool IsSignalON, unsigned int frequency);


};


template<byte SID, byte cid_target>
inline SignalMacroInstruction InstructionConstructor<SID, cid_target>::Create(byte b2, byte b3, byte b4)
{
	return SignalMacroInstruction();
}

template<byte SID, byte cid_target>
inline SignalMacroInstruction InstructionConstructor<SID, cid_target>::CreateNote(bool IsSignalON, unsigned int frequency)
{
	byte modeByte = 0;
	if (IsSignalON) bitSet(modeByte, 2);

	SignalMacroInstruction output;

	byte b1 = (SID << 4) | (cid_target);

	output.data = (b1 << 24) | modeByte << 16) | frequency
	return output;
}

