
#include "MidiSoundControl.h"




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
	CCValues->SetValue(CC_WaveformA_PWM, 127, CC_WaveformB_PWM, 127, CC_WaveformA_Shaper, 64, CC_WaveformB_Shaper, 64, CC_WaveformMix, 64);
	CCValues->SetValue(CC_WAVEFORMA_PITCH, 63, CC_WAVEFORMB_PITCH, 63, CC_PERKA_PITCH, 127, CC_PERKB_PITCH, 127);

	CCValues->SetValue(CC_PERKA_PWM, 63, CC_PERKB_PWM, 63, CC_PERKA_MonoStereo, 0, CC_PERKB_MonoStereo, 0);

	/* Setting modulated controls*/
	CCValues->SetValue(CC_PERKA_Amp_ModSrc, MODSOURCE2BYTE(MDF_ENV_A), CC_PERKA_Amp_ModAmt, 127, CC_PERKA_Amp_Val, 0);
	CCValues->SetValue(CC_PERKB_Amp_ModSrc, MODSOURCE2BYTE(MDF_ENV_B), CC_PERKB_Amp_ModAmt, 127, CC_PERKB_Amp_Val, 0);

	CCValues->SetValue(CC_PERKA_Pan_ModSrc, MODSOURCE2BYTE(MDF_LFO_A), CC_PERKA_Pan_ModAmt, 64, CC_PERKA_Pan_Val, 64);
	CCValues->SetValue(CC_PERKB_Pan_ModSrc, MODSOURCE2BYTE(MDF_LFO_B), CC_PERKB_Pan_ModAmt, 64, CC_PERKB_Pan_Val, 64);

	CCVALUESMDF(CC_FLT_CutOff, MODSOURCE2BYTE(MDF_ADSR_B), 64, 64);
	CCVALUESMDF(CC_FLT_Res, 0, 64, 64);

	CCVALUESMDF(CC_MAINCOMPONENT_Pan, 0, 64, 64);



}

void MidiSoundControlClass::noteOn(byte channel, byte pitch, byte velocity) {
	
	if (channel_id != CHANNEL_ID_ALL && channel != channel_id) return;

	tone_pitch = midiPitchFrequency[pitch];

	tone_on = true;

	tone_velocity = velocity;
	
	NoteOnTime = millis();
	

	
	//ADSR_Amp.Restart();
	//ADSR_Filter.Restart();

	
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
	CF_PERKA_Amp.Update(&State.CCValues);
	CF_PERKA_Pan.Update(&State.CCValues);
	CF_PERKB_Amp.Update(&State.CCValues);
	CF_PERKB_Pan.Update(&State.CCValues);
	CF_MAINCOMPONENT_Pan.Update(&State.CCValues);

	
	// Main component AMP is allways controled by CF_ADSR_A function
	State.CSValues.SetValue(CS_MAINCOMPONENT_AMP, State.MDFValues.Data[MDF_ADSR_A] * 2); // -- modification source ignored

	// Computing values of combined functions
	State.CSValues.SetValue(CS_MAINCOMPONENT_PAN, CF_MAINCOMPONENT_Pan.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_DIST_Mix, CF_FLT_Dist.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_FLT_CutOff, CF_FLT_CutOff.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_FLT_Resonance, CF_FLT_Res.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_FLT_Freq, CF_FLT_Freq.Compute(State.MDFValues) * 2);

	State.CSValues.SetValue(CS_PERKA_AMP, CF_PERKA_Amp.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_PERKB_AMP, CF_PERKB_Amp.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_PERKA_PAN, CF_PERKA_Pan.Compute(State.MDFValues) * 2);
	State.CSValues.SetValue(CS_PERKB_PAN, CF_PERKA_Pan.Compute(State.MDFValues) * 2);

	// Appling direct (non-modulated) values
	State.CSValues.SetValue(CS_WAVEFORMA_MOD, State.CCValues.Data[CC_WaveformA_Shaper] * 2);
	State.CSValues.SetValue(CS_WAVEFORMB_MOD, State.CCValues.Data[CC_WaveformB_Shaper] * 2);
	State.CSValues.SetValue(CS_WAVEFORMAB_MIX, State.CCValues.Data[CC_WaveformMix] * 2);

	State.CSValues.SetValue(CS_WAVEFORMA_PWM, State.CCValues.Data[CC_WaveformA_PWM] * 2);
	State.CSValues.SetValue(CS_WAVEFORMB_PWM, State.CCValues.Data[CC_WaveformB_PWM] * 2);
	State.CSValues.SetValue(CS_PERKA_PWM, State.CCValues.Data[CC_PERKA_PWM] * 2);
	State.CSValues.SetValue(CS_PERKB_PWM, State.CCValues.Data[CC_PERKB_PWM] * 2);
	


	
	//if (IsReleaseStage) {

	//	if (cT > ADSR_Amp.ReleaseTime) {
	//		//State.out_amp_value = 0;
	//		//State.out_flt_value = 0;
	//		//tone_on = false;
	//	} else {

	//		State.out_amp_value = ADSR_Amp.ComputeR(cT);
	//		State.out_flt_value = ADSR_Filter.ComputeR(cT) ;
	//	}
	//}
	//else {
	//	
	//	State.out_amp_value = ADSR_Amp.ComputeADS(cT);
	//	State.out_flt_value = ADSR_Filter.ComputeADS(cT);
	//}

	//float flt_adsr_mix_factor = MathTool::GetRatio((unsigned int)State.CCValues[CC_FLT_ADSR_Mix], 127,1,0);

	//State.out_amp_value = State.out_amp_value;
	//State.out_flt_value = ( ((float)State.out_flt_value * flt_adsr_mix_factor) + (127 * (1- flt_adsr_mix_factor)))  * MathTool::GetRatio((unsigned int)State.CCValues[CC_Cutoff], 127, 1, 0);


	//State.out_perkA_amp = ENV_PerkAmp.Compute(cTall);
	//State.out_perkB_amp = State.out_perkA_amp; //ENV_PerkAmp.Compute(cTall);


	//signalA_instruction.Frequency = tone_pitch;
	//if (State.CCValues[CC_WaveformA_OctaveUp] == 127) signalA_instruction.Frequency = signalA_instruction.Frequency * 2;

	//signalB_instruction.Frequency = tone_pitch;
	//if (State.CCValues[CC_WaveformB_OctaveUp] == 127) signalB_instruction.Frequency = signalB_instruction.Frequency * 2;

	//perkA_instruction.Frequency = tone_pitch;
	//if (State.CCValues[CC_PerkA_OctaveUp] == 127) perkA_instruction.Frequency = perkA_instruction.Frequency * 2;

	//perkB_instruction.Frequency = tone_pitch;
	//if (State.CCValues[CC_PerkB_OctaveUp] == 127) perkB_instruction.Frequency = perkB_instruction.Frequency * 2;

	//signalFLT_instruction.Frequency = State.CCValues[CC_FLTPitch];
	//signalFLT_instruction.Set(signalFLT_SID, signalFLT_instruction.Frequency, B11110000,0, false, false, false, false);

	//signalA_instruction.pwmPattern = MathTool::GetPWMWaveform(State.CCValues[CC_WaveformA_PWM]);
	//signalB_instruction.pwmPattern = MathTool::GetPWMWaveform(State.CCValues[CC_WaveformB_PWM]);

	//signalA_instruction.Set(signalA_SID, signalA_instruction.Frequency, signalA_instruction.pwmPattern, 0, true, true, true, true);
	//signalB_instruction.Set(signalB_SID, signalB_instruction.Frequency, signalB_instruction.pwmPattern, 0, true, true, true, true);

	//perkA_instruction.pwmPattern = MathTool::GetPWMWaveform(State.CCValues[CC_PERK_PWM]);
	//perkB_instruction.pwmPattern = MathTool::GetPWMWaveform(127-State.CCValues[CC_PERK_PWM]);

	//perkA_instruction.Set(perkA_SID, perkA_instruction.Frequency, perkA_instruction.pwmPattern, 6 - MathTool::GetPhaseShift(State.CCValues[CC_PERK_PHASE]), false, false, true, false);
	//perkB_instruction.Set(perkB_SID, perkB_instruction.Frequency, perkB_instruction.pwmPattern, MathTool::GetPhaseShift(State.CCValues[CC_PERK_PHASE]), false, false, true, false);

	////float level_factor = ((float)tone_velocity / 127.0) * ((float) CCValues[CC_ChannelVolume] / 127.0) * 2;

	////out_amp_value = 255 - (ADSR_Amp.DoTick(tone_on) * 2);
	//
	////if (State.out_amp_value >= (255 - gate_margin)) State.out_amp_value = 255;
	////if (State.out_amp_value <= gate_margin) State.out_amp_value = 0;
	///*
	//
	//
	//byte out_flt_A = ADSR_Filter.DoTick(tone_on);
	//byte out_flt_B = CCValues[CC_Cutoff] * 2;

	//out_flt_value = ((1.0 - flt_adsr_mix_factor) * (float)out_flt_B) + (flt_adsr_mix_factor * (float)out_flt_A);
	//
	//out_flt_value = 255 - out_flt_value;
	//*/

	//float waveform_mix_ration = MathTool::GetRatio((unsigned int)State.CCValues[CC_WaveformMix], 127, 1, 0);

	//State.out_waveform_mix = waveform_mix_ration * 100; // State.CCValues[CC_WaveformMix];

	//if (State.out_waveform_mix > 100) State.out_waveform_mix = 100;


	//State.out_waveform_b_flt = State.CCValues[CC_WaveformB_Shaper] * 2;
	//State.out_waveform_a_shaper = State.CCValues[CC_WaveformA_Shaper] * 2;

	//State.out_flt_gain = State.CCValues[CC_Resonance] * 2;

	return cT;
	
	
}

void MidiSoundControlClass::init()
{
	/*
	CCValues[CC_AmpAttack] = 5;
	CCValues[CC_AmpDecayTime] = 5;
	CCValues[CC_AmpRelease] = 5;
	CCValues[CC_AmpInitLevel] = 0;
	CCValues[CC_AmpSustainLevel] = 40;

	CCValues[CC_Cutoff] = 30;
	CCValues[CC_Resonance] = 30;

	CCValues[CC_FLT_ADSR_Mix] = 1;

	CCValues[CC_FLTAttack] = 5;
	CCValues[CC_FLTDecayTime] = 5;
	CCValues[CC_FLTRelease] = 5;
	CCValues[CC_FLTInitLevel] = 0;
	CCValues[CC_FLTSustainLevel] = 40;

	CCValues[CC_WaveformA_Shaper] = 127;
	CCValues[CC_WaveformB_Filter] = 64;
	CCValues[CC_WaveformMix] = 64;
	CCValues[CC_WaveformMix] = 64;*/
}


//MidiSoundControlClass MidiSoundControl;

