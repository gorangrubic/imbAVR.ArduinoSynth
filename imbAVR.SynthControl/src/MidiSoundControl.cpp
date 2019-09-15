
#include "MidiSoundControl.h"




void MidiSoundControlClass::AddInstructionToBuffer(SignalMacroInstruction instruction)
{
	if (instruction.data > 0) {
		linkBuffer.Add(instruction);
	}
}


void MidiSoundControlClass::setOperationMode(byte opm_id)
{

	switch (opm_id) {

	case OPM_BassLine:
		AddInstructionToBuffer(ICP_WFA.CreateModeInstruction(true, false, false, true, true, false, false, 0, SID_Master));
		break;
	case OPM_KickDrum:
		AddInstructionToBuffer(ICP_WFA.CreateModeInstruction(true, false, false, true, true, false, false, 0, SID_Master));
		break;
	case OPM_LeadSynth:
		AddInstructionToBuffer(ICP_WFA.CreateModeInstruction(true, false, false, true, true, false, false, 0, SID_Master));
		break;
	case OPM_ShortFX:
		AddInstructionToBuffer(ICP_WFA.CreateModeInstruction(true, false, false, true, true, false, false, 0, SID_Master));
		break;
	case OPM_LongFX:
		AddInstructionToBuffer(ICP_WFA.CreateModeInstruction(true, false, false, true, true, false, false, 0, SID_Master));
		break;
	case OPM_Keys:
		AddInstructionToBuffer(ICP_WFA.CreateModeInstruction(true, false, false, true, true, false, false, 0, SID_Master));
		break;
	case OPM_FatSynth:
		AddInstructionToBuffer(ICP_WFA.CreateModeInstruction(true, false, false, true, true, false, false, 0, SID_Master));
		break;
	case OPM_Uplifters:
		AddInstructionToBuffer(ICP_WFA.CreateModeInstruction(true, false, false, true, true, false, false, 0, SID_Master));
		AddInstructionToBuffer(ICP_PERKA.CreateModeInstruction(true, false, false, true, true, false, false, 1200));
		AddInstructionToBuffer(ICP_PERKB.CreateModeInstruction(true, false, false, true, true, false, false, 800));

		AddInstructionToBuffer(ICP_PERKA.CreateChangeInstruction(CID_Pitch, 255, 10, 64, SIGNALCHANGE_MODE_Continual));
		AddInstructionToBuffer(ICP_PERKB.CreateChangeInstruction(CID_Pitch, 160, 10, 64, SIGNALCHANGE_MODE_Continual));


		break;
	case OPM_Downlifters:
		AddInstructionToBuffer(ICP_WFA.CreateModeInstruction(true, false, false, true, true, false, false, 0, SID_Master));
		break;
	case OPM_ChaosFX:
		AddInstructionToBuffer(ICP_WFA.CreateModeInstruction(true, false, false, true, true, false, false, 0, SID_Master));
		break;
	}
}

void MidiSoundControlClass::setPreset(byte presetID, CCValuesType * CCValues)
{

	/* Setting time-based control functions */
	CCValues->SetValue(CC_AmpAttack, 5, CC_AmpDecayTime, 25, CC_AmpInitLevel, 0, CC_AmpRelease, 25, CC_AmpSustainLevel, 60);
	CCValues->SetValue(CC_FLTAttack, 5, CC_FLTDecayTime, 25, CC_FLTInitLevel, 0, CC_FLTRelease, 25, CC_FLTSustainLevel, 60);

	CCValues->SetValue(CC_LFOATime, 100, CC_LFOATimeFactor, 40, CC_LFOAValue, 127);
	CCValues->SetValue(CC_LFOBTime, 100, CC_LFOBTimeFactor, 20, CC_LFOBValue, 127);

	CCValues->SetValue(CC_ChaosTime, 200, CC_ChaosSpread, 50, CC_ChaosTimeFactor, 5);

	CCValues->SetValue(CC_ENVA_BLevel, 127, CC_ENVA_ATime, 50, CC_ENVA_ALevel, 0, CC_ENVA_BTime, 100);
	CCValues->SetValue(CC_ENVB_ALevel, 127, CC_ENVB_ATime, 50, CC_ENVB_BLevel, 0, CC_ENVB_BTime, 100);
	
	/* Setting direct controls*/
	//CCValues->SetValue(CC_WaveformA_PWM, 127, CC_WaveformB_PWM, 127, CC_WaveformA_Shaper, 64, CC_WaveformB_Shaper, 64, CC_WaveformMix, 64);
	CCValues->SetValue(CC_WAVEFORMA_PITCH, 63, CC_WAVEFORMB_PITCH, 63, CC_PERKA_PITCH, 127, CC_PERKB_PITCH, 127);

	//CCValues->SetValue(CC_PERKA_PWM, 63, CC_PERKB_PWM, 63, CC_PERKA_MonoStereo, 0, CC_PERKB_MonoStereo, 0);

	/* Setting modulated controls*/
	CCValues->SetValue(CC_PERKA_Amp_ModSrc, MODSOURCE2BYTE(MDF_ENV_A), CC_PERKA_Amp_ModAmt, 127, CC_PERKA_Amp_Val, 0);
	CCValues->SetValue(CC_PERKB_Amp_ModSrc, MODSOURCE2BYTE(MDF_ENV_B), CC_PERKB_Amp_ModAmt, 127, CC_PERKB_Amp_Val, 0);

	CCValues->SetValue(CC_PERKA_Pan_ModSrc, MODSOURCE2BYTE(MDF_LFO_A), CC_PERKA_Pan_ModAmt, 64, CC_PERKA_Pan_Val, 64);
	CCValues->SetValue(CC_PERKB_Pan_ModSrc, MODSOURCE2BYTE(MDF_LFO_B), CC_PERKB_Pan_ModAmt, 64, CC_PERKB_Pan_Val, 64);

	CCVALUESMDF(CC_FLT_CutOff, MODSOURCE2BYTE(MDF_ADSR_B), 64, 64);
	CCVALUESMDF(CC_FLT_Res, 0, 64, 64);

	CCVALUESMDF(CC_MASTER_Pan, 0, 64, 64);



}

void MidiSoundControlClass::noteOn(byte channel, byte pitch, byte velocity) {
	
	if (channel_id != CHANNEL_ID_ALL && channel != channel_id) return;

	//tone_pitch = midiPitchFrequency[pitch];

	//tone_on = true;

	tone_velocity = velocity;
	
	NoteOnTime = millis();
	
	AddInstructionToBuffer(IC_MASTER_NoteControl.CreateNote(true, midiPitchFrequency[pitch]));
	
	
}

void MidiSoundControlClass::noteOff(byte channel, byte pitch, byte velocity) {

	if (channel_id != CHANNEL_ID_ALL && channel != channel_id) return;
	
	//tone_on = false;

	NoteOffTime = millis();

	/*ADSR_Amp.NoteOff();
	ADSR_Filter.NoteOff();*/

}

void MidiSoundControlClass::controlChange(byte channel, byte control, byte value) {
	
	if (channel_id != CHANNEL_ID_ALL && channel != channel_id) return;

	State.CCValues.SetValue(control, value);

	//ApplyControls();
}

void MidiSoundControlClass::systemMessage(byte sysMsg, byte paramA, byte paramB)
{
}

void MidiSoundControlClass::ApplyControls() {

	


	//ADSR_Amp.SetLevels(State.CCValues[CC_AmpInitLevel], 127 , State.CCValues[CC_AmpSustainLevel]);

	//ADSR_Filter.SetLevels(State.CCValues[CC_FLTInitLevel], 127, State.CCValues[CC_FLTSustainLevel]);

	//ENV_PerkAmp.SetLevels(State.CCValues[CC_PERK_AmpALevel], State.CCValues[CC_PERK_AmpBLevel]);
	//
	//ENV_PerkPitch.SetLevels(State.CCValues[CC_PERK_PitchALevel], State.CCValues[CC_PERK_PitchBLevel]);


	////ENV_PerkPitch.SetTimes(State.CCValues[CC_PERK_PitchATime] * time_factor, State.CCValues[CC_PERK_PitchBTime] * time_factor);

	//ADSR_Amp.SetTimes(State.CCValues[CC_AmpAttack]*time_factor, State.CCValues[CC_AmpDecayTime] * time_factor, State.CCValues[CC_AmpRelease] * time_factor);

	//ADSR_Filter.SetTimes(State.CCValues[CC_FLTAttack] * time_factor, State.CCValues[CC_FLTDecayTime] * time_factor, State.CCValues[CC_FLTRelease] * time_factor);

	//ENV_PerkAmp.SetTimes(State.CCValues[CC_PERK_AmpATime] * time_factor, State.CCValues[CC_PERK_AmpBTime] * time_factor);

	//ENV_PerkPitch.SetTimes(State.CCValues[CC_PERK_PitchATime] * time_factor, State.CCValues[CC_PERK_PitchBTime] * time_factor);
	


}

String MidiSoundControlClass::DescribeState() {

	String output = "pitch: ";
	output += tone_pitch;
	output += " on: ";
	output += tone_on;

	return output;

}

/// <summary>
/// Performs all computations and stores results to synth control values
/// </summary>
/// <returns></returns>
unsigned int MidiSoundControlClass::DoTick() {

#pragma region Modulation_sources

	// Updating modulation sources' settings
	CF_ADSR_A.Update(&State.CCValues);
	CF_ADSR_B.Update(&State.CCValues);
	CF_Chaos.Update(&State.CCValues);
	CF_ENV_A.Update(&State.CCValues);
	CF_ENV_B.Update(&State.CCValues);
	CF_LFO_A.Update(&State.CCValues);
	CF_LFO_B.Update(&State.CCValues);

	// Computing time position of the current note
	bool IsReleaseStage = NoteOnTime < NoteOffTime;
	
	/* Current global time position, consumed by LFO's */
	unsigned int cTglobal = millis(); // <--- uint16 overflow can cause LFO values to jump every ~60 seconds, overflow compensation is included in Compute function

	/* Current time position since NoteOn or Note Off */
	unsigned int cT = 0;
	/* Current time position since NoteOn */
	unsigned int cTall = millis() - NoteOnTime;
	
	if (IsReleaseStage) {
		cT = millis() - NoteOffTime;
	}
	else {
		cT = cTall;
	}

	// Computing values of modulation sources
	State.MDFValues.SetValue(MDF_ADSR_A, CF_ADSR_A.Compute(cT, IsReleaseStage));
	State.MDFValues.SetValue(MDF_ADSR_B, CF_ADSR_B.Compute(cT, IsReleaseStage));
	State.MDFValues.SetValue(MDF_Chaos,	CF_Chaos.Compute(cTall));
	State.MDFValues.SetValue(MDF_ENV_A,	CF_ENV_A.Compute(cTall));
	State.MDFValues.SetValue(MDF_ENV_B, CF_ENV_B.Compute(cTall));
	State.MDFValues.SetValue(MDF_LFO_A, CF_LFO_A.Compute(cTglobal));
	State.MDFValues.SetValue(MDF_LFO_B, CF_LFO_B.Compute(cTglobal));

	State.MDFValues.SetValue(MDF_VEL, tone_velocity); // -- special case, not a function but direct assigment of velocety value received with note on MIDI message

#pragma endregion Modulation_sources


	// Updating settings of other control functions
	CF_FLT_CutOff.Update(&State.CCValues);
	CF_FLT_Dist.Update(&State.CCValues);
	CF_FLT_Res.Update(&State.CCValues);
	CF_FLT_Freq.Update(&State.CCValues);
	CF_WFA_Shaper.Update(&State.CCValues);
	CF_WFB_Shaper.Update(&State.CCValues);
	CF_PERKA_Amp.Update(&State.CCValues);
	CF_PERKB_Amp.Update(&State.CCValues);
	CF_MASTER_Pan.Update(&State.CCValues);
	CF_PERKA_Pan.Update(&State.CCValues);
	CF_PERKB_Pan.Update(&State.CCValues);
	

	CSF_Master_Pan.Update(&State.CSValues, CF_MASTER_Pan.Compute(State.MDFValues), State.MDFValues.Data[MDF_ADSR_A]);

	CSF_PERKA_Pan.Update(&State.CSValues, CF_PERKA_Pan.Compute(State.MDFValues), CF_PERKA_Amp.Compute(State.MDFValues));
	CSF_PERKB_Pan.Update(&State.CSValues, CF_PERKB_Pan.Compute(State.MDFValues), CF_PERKB_Amp.Compute(State.MDFValues));



	// Computing values of combined functions

	State.CSValues.SetValue(CS_DIST_Mix, CF_FLT_Dist.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_FLT_CutOff, CF_FLT_CutOff.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_FLT_Resonance, CF_FLT_Res.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_FLT_Freq, CF_FLT_Freq.Compute(State.MDFValues) * 2);

	State.CSValues.SetValue(CS_WAVEFORMA_MOD, CF_WFA_Shaper.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_WAVEFORMB_MOD, CF_WFB_Shaper.Compute(State.MDFValues) * 2);

	// Appling direct (non-modulated) values

	State.CSValues.SetValue(CS_WAVEFORMAB_MIX, State.CCValues.Data[CC_WaveformMix] * 2);
	State.CSValues.SetValue(CS_WAVEFORMA_PWM, State.CCValues.Data[CC_WaveformA_PWM] * 2);
	State.CSValues.SetValue(CS_WAVEFORMB_PWM, State.CCValues.Data[CC_WaveformB_PWM] * 2);
	State.CSValues.SetValue(CS_PERKA_PWM, State.CCValues.Data[CC_PERKA_PWM] * 2);
	State.CSValues.SetValue(CS_PERKB_PWM, State.CCValues.Data[CC_PERKB_PWM] * 2);

	State.CSValues.SetValue(CS_WAVEFORMA_MODBYTE, State.CCValues.Data[CC_WaveformA_SigGen_mod]);
	State.CSValues.SetValue(CS_WAVEFORMB_MODBYTE, State.CCValues.Data[CC_WaveformB_SigGen_mod]);

	State.CSValues.SetValue(CS_WAVEFORMA_PHASE, State.CCValues.Data[CC_WaveformA_Phase]);
	State.CSValues.SetValue(CS_WAVEFORMB_PHASE, State.CCValues.Data[CC_WaveformB_Phase]);
	

	// ------------ prepering PWM instructions
	AddInstructionToBuffer(IC_WFA_Live.Update(&State.CSValues));
	AddInstructionToBuffer(IC_WFB_Live.Update(&State.CSValues));

	AddInstructionToBuffer(IC_PERKA_Live.Update(&State.CSValues));
	AddInstructionToBuffer(IC_PERKB_Live.Update(&State.CSValues));
	
	return cT;
	
	
}