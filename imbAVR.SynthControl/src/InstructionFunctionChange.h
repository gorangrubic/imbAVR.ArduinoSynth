#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "MidiConfig.h"
#include "SynthState.h"
#include "SignalMacroInstruction.h"
#include "SignalChangeInstruction.h"


template<byte SID, byte cid_target, byte ccChange, byte ccRate, byte ccPeriod>
class InstructionFunctionChange //: InstructionFunction<SID, cid_target, ccChange, ccRate, ccPeriod>
{
public:

	byte mode = SIGNALCHANGE_MODE_OneShot;
	
	SignalMacroInstruction Update(CCValuesType * CCValues);

};

template<byte SID, byte cid_target, byte ccChange, byte ccRate, byte ccPeriod>
inline SignalMacroInstruction InstructionFunctionChange<SID, cid_target, ccChange, ccRate, ccPeriod>::Update(CCValuesType * CCValues)
{
	if (CCValues->IsChanged(ccChange, ccRate, ccPeriod)) {

		byte b1 = (SID << 4) | (cid_target);

		byte period = constrain(CCValues->Data[ccPeriod], 0, 64);
		byte options = mode << 6;
		options |= period;

		SignalMacroInstruction output;

		output.data += b1;
		output.data = output.data << 8;
		output.data += CCValues->Data[ccChange];
		output.data = output.data << 8;
		output.data += CCValues->Data[ccRate];
		output.data = output.data << 8;
		output.data += options;

		//output.data = (b1 << 24) | (CCValues->Data[ccChange] << 16) | (CCValues->Data[ccRate] << 8) | options;
		return output;

	}
	else {
		return SignalMacroInstruction();
	}
}
