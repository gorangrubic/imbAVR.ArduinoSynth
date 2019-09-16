#pragma once
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

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
	SignalMacroInstruction output;

	byte modeByte = 0;
	if (IsSignalON) bitSet(modeByte, 2);
	
#ifdef SMI_UNPACKED_FORM
	output.sid = SID;
	output.cid = cid_target;
	output.b2 = modeByte;
	output.b3 = highByte(frequency);
	output.b4 = lowByte(frequency);
	
#else
	byte b1 = SID;
	b1 = b1 << 4;
	b1 = b1 + cid_target;

	//byte b1 = (SID << 4) | cid_target;


	output.data = 0;
	output.data += b1;
	output.data = output.data << 8;
	output.data += modeByte;
	output.data = output.data << 16;
	output.data += frequency;



#endif //  UNPACKED_FORM

	

	//output.data = (b1 << 24) | modeByte << 16 | frequency;
	return output;
}

