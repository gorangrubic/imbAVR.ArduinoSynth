#pragma once
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

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

		SignalMacroInstruction output;

#ifdef SMI_UNPACKED_FORM

		output.sid = SID;

		output.cid = cid_target;
		output.b2 = CSValues->Data[ccB2];
		output.b3 = CSValues->Data[ccB3];
		output.b4 = CSValues->Data[ccB4];

#else

		byte b1 = SID;
		b1 = b1 << 4;
		b1 = b1 + cid_target;

		output.data = b1;
		output.data = output.data << 8;
		output.data += CSValues->Data[ccB2];
		output.data = output.data << 8;
		output.data += CSValues->Data[ccB3];
		output.data = output.data << 8;
		output.data += CSValues->Data[ccB4];



#endif //  UNPACKED_FORM


		//byte b1 = (SID << 4) | (cid_target);

	//	output.data = (b1 << 24) | (CSValues->Data[ccB2] << 16) | (CSValues->Data[ccB3] << 8) | CSValues->Data[ccB4];
		return output;
	}
	else {
		return SignalMacroInstruction();
	}
}