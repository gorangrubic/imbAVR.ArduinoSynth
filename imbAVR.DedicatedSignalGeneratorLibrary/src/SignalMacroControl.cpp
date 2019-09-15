#include "SignalMacroControl.h"


#define SUNIT_sid manager->SignalUnits[s_id]

void SignalMacroControl::Run(byte s_id, byte cc_id, byte b2, byte b3, byte b4, SignalControlManagerClass * manager)
{

	//SignalControlUnitClass * unit = 

	switch (cc_id) {

	case 1:

		// applying mode byte
		SUNIT_sid.pwmContinualMode = (bitRead(b2, 0) == 1);
		if (bitRead(b2, 1) == 1) {
			SUNIT_sid.sClockPrescalar = 2;
		}
		SUNIT_sid.isOn = (bitRead(b2, 2) == 1);

		SUNIT_sid.masterPitchRelationship = b2 >> 4;

		SUNIT_sid.freq = b3 | (b4 << 8);
		

		break;
	case 2:
		SUNIT_sid.PWMChange.SetBytes(b2, b3, b4);
		break;
	case 3:
		SUNIT_sid.PitchChange.SetBytes(b2, b3, b4);
		break;
	case 4:
		SUNIT_sid.PhaseChange.SetBytes(b2, b3, b4);
		break;

	}

	;
}

byte SignalMacroControl::MakeModeByte(bool IsPWMCycle, bool IsDoublePrescalar, bool IsSignalON, bool IsPitchSlave, bool IsPositiveRelation, bool IsRelativeDistance, bool IsPitchMidiNote)
{
	byte output = 0;

	if (IsPWMCycle) bitSet(output, 0);
	if (IsDoublePrescalar) bitSet(output, 1);
	if (IsSignalON) bitSet(output, 2);
	if (IsPitchSlave) bitSet(output, 3);
	if (IsPositiveRelation) bitSet(output, 4);
	if (IsRelativeDistance) bitSet(output, 5);
	if (IsPitchMidiNote) bitSet(output, 6);

	return output;
}


void SignalMacroControl::Run(SignalMacroInstruction instruction, SignalControlManagerClass * manager)
{

	byte b1 = instruction.data >> 24;
	byte b2 = instruction.data >> 16;
	byte b3 = instruction.data >> 8;
	byte b4 = instruction.data;

	byte s_id = b1 >> 4;
	byte cc_id = b1 & B00001111;



	


}
