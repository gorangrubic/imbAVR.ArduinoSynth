#include "SignalMacroControl.h"
#include "MidiConfig.h"

#include "MathTool.h"

#define SUNIT_sid manager->SignalUnits[s_id]

void SignalMacroControl::RunPitchRelation(byte s_id, unsigned int freq, SignalControlManagerClass * manager) {
	
	SUNIT_sid.ResetClocks(true, true, true);

	if (SUNIT_sid.IsPitchSlave) {

		// is slave relationship

		if (SUNIT_sid.IsRelativeDistanceMode) { // -- delta_freq is in semitones

			if (SUNIT_sid.IsPositiveRelation) {

				float semitone_freq = MathTool::GetRatio(freq, 12, 0, 1);
				manager->PerformPitch(freq + SUNIT_sid.delta_freq * semitone_freq, &SUNIT_sid);
			}
			else {

				byte octaves = SUNIT_sid.delta_freq / 12;
				byte semitones = SUNIT_sid.delta_freq % 12;

				float freq_main = freq;

				for (size_t i = 0; i < octaves; i++)
				{
					freq_main = freq_main / 2.0;
				}

				float freq_sub = freq_main / 2.0;
				float semitone_freq = (freq_main - freq_sub) / 12;

				freq_main -= semitone_freq * semitones;
				
				manager->PerformPitch(freq_main, &SUNIT_sid);

			}
			
		}
		else {

			if (SUNIT_sid.IsPositiveRelation) {
				manager->PerformPitch(freq + SUNIT_sid.delta_freq, &SUNIT_sid);
			}
			else {
				manager->PerformPitch(freq - SUNIT_sid.delta_freq, &SUNIT_sid);
			}
		}
	}
	else {
		
		manager->PerformPitch(freq, &SUNIT_sid);
	}

}

void SignalMacroControl::Run(byte s_id, byte cc_id, byte b2, byte b3, byte b4, SignalControlManagerClass * manager)
{

	//SignalControlUnitClass * unit = 

	switch (cc_id) {

	case 1:

		SUNIT_sid.ResetClocks(true, true, true);

		// applying mode byte
		SUNIT_sid.pwmContinualMode = (bitRead(b2, 0) == 1);
		if (bitRead(b2, 1) == 1) {
			SUNIT_sid.sClockPrescalar = 2;
		}
		else {
			SUNIT_sid.sClockPrescalar = 1;
		}
		SUNIT_sid.isOn = (bitRead(b2, 2) == 1);

		//SUNIT_sid.masterPitchRelationship = b2 >> 4;

		SUNIT_sid.IsPitchSlave = (bitRead(b2, 3) == 1);
		SUNIT_sid.IsPositiveRelation = (bitRead(b2, 4) == 1);
		SUNIT_sid.IsRelativeDistanceMode = (bitRead(b2, 5) == 1);
		SUNIT_sid.IsMidiNote = (bitRead(b2, 6) == 1);

		if (SUNIT_sid.IsPitchSlave) {
			SUNIT_sid.delta_freq = b3 | (b4 << 8);
		}
		else {
			SUNIT_sid.freq = b3 | (b4 << 8);
		}
		
		

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

	case 5:
		SUNIT_sid.modulationByte = b2;
		SUNIT_sid.pwmByte = b3;
		SUNIT_sid.sClockIndex += b4;
		break;
	}

	
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
#ifdef SMI_UNPACKED_FORM
	
	byte b2 = instruction.b2;
	byte b3 = instruction.b3;
	byte b4 = instruction.b4;

	byte s_id = instruction.sid;
	byte cc_id = instruction.cid;
#else
	byte b1 = instruction.data >> 24;
	byte b2 = instruction.data >> 16;
	byte b3 = instruction.data >> 8;
	byte b4 = instruction.data;

	byte s_id = b1 >> 4;
	byte cc_id = b1 & B00001111;
#endif


	if (s_id == SID_Master) {

		if (cc_id == CID_NoteControl) {
			unsigned int freq = b3 | (b4 << 8);
			for (size_t i = 0; i < manager->ActiveUnitCount; i++)
			{
				RunPitchRelation(i, freq, manager);
			}
		}
		else {
			for (size_t i = 0; i < manager->ActiveUnitCount; i++)
			{
				Run(i, cc_id, b2, b3, b4, manager);
			}
		}

	} else if (s_id == SID_Group1) {
		Run(0, cc_id, b2, b3, b4, manager);
		Run(1, cc_id, b2, b3, b4, manager);
	}
	else if (s_id == SID_Group2) {
		Run(2, cc_id, b2, b3, b4, manager);
		Run(3, cc_id, b2, b3, b4, manager);
	}
	else if (s_id == SID_Group3) {
		Run(4, cc_id, b2, b3, b4, manager);
		Run(5, cc_id, b2, b3, b4, manager);
	}
	else {
		Run(s_id, cc_id, b2, b3, b4, manager);
	}


}
