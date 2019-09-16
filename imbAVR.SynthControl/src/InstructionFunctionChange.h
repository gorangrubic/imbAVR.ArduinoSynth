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

		//byte b1 = (SID << 4) | (cid_target);

		SignalMacroInstruction output;

#ifdef SMI_UNPACKED_FORM

		byte period = constrain(CCValues->Data[ccPeriod], 0, 64);
		byte options = mode << 6;
		options |= period;

		output.sid = SID;

		output.cid = cid_target;
		output.b2 = CCValues->Data[ccChange];
		output.b3 = CCValues->Data[ccRate];
		output.b4 = options;

#else
		byte b1 = SID;
		b1 = b1 << 4;
		b1 = b1 + cid_target;

		byte period = constrain(CCValues->Data[ccPeriod], 0, 64);
		byte options = mode << 6;
		options |= period;

		
		output.data = b1;
		output.data = output.data << 8;
		output.data += CCValues->Data[ccChange];
		output.data = output.data << 8;
		output.data += CCValues->Data[ccRate];
		output.data = output.data << 8;
		output.data += options;
#endif
		//output.data = (b1 << 24) | (CCValues->Data[ccChange] << 16) | (CCValues->Data[ccRate] << 8) | options;
		return output;

	}
	else {
		return SignalMacroInstruction();
	}
}
