#pragma once

#include "SynthState.h"
#include "SignalMacroInstruction.h"

/* Universal macro instruction generator, based on CC inputs*/
template<byte SID, byte cid_target, byte ccB2, byte ccB3, byte ccB4>
class InstructionFunction
{
public:

	SignalMacroInstruction Update(CSValuesType * CSValues);


};

template<byte SID, byte cid_target, byte ccB2, byte ccB3, byte ccB4>
inline SignalMacroInstruction InstructionFunction<SID, cid_target, ccB2, ccB3, ccB4>::Update(CSValuesType * CSValues)
{
	if (CSValues->IsChanged(ccB2, ccB3, ccB4)) {

		byte b1 = (SID << 4) | (cid_target);
		SignalMacroInstruction output;

		output.data = (b1 << 24) | (CSValues->Data[ccB2] << 16) | (CSValues->Data[ccB3] << 8) | CSValues->Data[ccB4];
		return output;
	}
	else {
		return SignalMacroInstruction();
	}
}