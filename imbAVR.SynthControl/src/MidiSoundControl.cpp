
#include "MidiSoundControl.h"

void MidiSoundControlClass::setPreset(byte presetID)
{
	//CCValues[CC_AmpAttack] = 5;
	//CCValues[CC_AmpDecayTime] = 5;
	//CCValues[CC_AmpRelease] = 5;
	//CCValues[CC_AmpInitLevel] = 0;
	//CCValues[CC_AmpSustainLevel] = 40;

	//CCValues[CC_Cutoff] = 30;
	//CCValues[CC_Resonance] = 30;

	//CCValues[CC_FLT_ADSR_Mix] = 1;

	//CCValues[CC_FLTAttack] = 5;
	//CCValues[CC_FLTDecayTime] = 5;
	//CCValues[CC_FLTRelease] = 5;
	//CCValues[CC_FLTInitLevel] = 0;
	//CCValues[CC_FLTSustainLevel] = 40;

	//CCValues[CC_WaveformA_Shaper] = 127;
	//CCValues[CC_WaveformB_Filter] = 64;
	//CCValues[CC_WaveformMix] = 64;

	State.CCValues.SetValue(CC_PERK_AmpATime, 24);
	State.CCValues.SetValue(CC_PERK_AmpBTime, 24);
	State.CCValues.SetValue(CC_PERK_AmpBLevel, 0);
	State.CCValues.SetValue(CC_PERK_AmpALevel, 127);

	State.CCValues.SetValue(CC_PERK_PitchATime, 24);
	State.CCValues.SetValue(CC_PERK_PitchBTime, 24);
	State.CCValues.SetValue(CC_PERK_PitchBLevel, 0);
	State.CCValues.SetValue(CC_PERK_PitchALevel, 127);

	State.CCValues.SetValue(CC_PERK_AmpBLevel, 0);

	State.CCValues.SetValue(CC_AmpAttack, 5);
	State.CCValues.SetValue(CC_AmpDecayTime, 5);
	State.CCValues.SetValue(CC_AmpRelease, 5);
	State.CCValues.SetValue(CC_AmpInitLevel, 0);
	State.CCValues.SetValue(CC_AmpSustainLevel, 60);

	//State.CCValues.SetValue(CC_FLTAttack, 10);
	State.CCValues.SetValue(CC_FLTInitLevel, 100);
	State.CCValues.SetValue(CC_FLTRelease, 10);
	State.CCValues.SetValue(CC_FLTSustainLevel, 10);

	State.CCValues.SetValue(CC_WaveformMix, 64);
	State.CCValues.SetValue(CC_WaveformA_Shaper, 64);
	State.CCValues.SetValue(CC_WaveformB_Filter, 64);

	State.CCValues.SetValue(CC_WaveformA_PWM, 64);
		State.CCValues.SetValue(CC_WaveformB_PWM, 64);

		State.CCValues.SetValue(CC_WaveformA_OctaveUp, 0);
		State.CCValues.SetValue(CC_WaveformB_OctaveUp, 0);

		State.CCValues.SetValue(CC_PerkA_OctaveUp, 127);
		State.CCValues.SetValue(CC_PerkB_OctaveUp, 127);

		State.CCValues.SetValue(CC_FLTPitch, 30);

		State.CCValues.SetValue(CC_FLT_ADSR_Mix, 64);

		State.CCValues.SetValue(CC_PERK_PWM, 64);

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

	
	CF_ADSR_A.Update(&State.CCValues);
	CF_ADSR_B.Update(&State.CCValues);


	ADSR_Amp.SetLevels(State.CCValues[CC_AmpInitLevel], 127 , State.CCValues[CC_AmpSustainLevel]);

	ADSR_Filter.SetLevels(State.CCValues[CC_FLTInitLevel], 127, State.CCValues[CC_FLTSustainLevel]);

	ENV_PerkAmp.SetLevels(State.CCValues[CC_PERK_AmpALevel], State.CCValues[CC_PERK_AmpBLevel]);
	
	ENV_PerkPitch.SetLevels(State.CCValues[CC_PERK_PitchALevel], State.CCValues[CC_PERK_PitchBLevel]);


	//ENV_PerkPitch.SetTimes(State.CCValues[CC_PERK_PitchATime] * time_factor, State.CCValues[CC_PERK_PitchBTime] * time_factor);

	ADSR_Amp.SetTimes(State.CCValues[CC_AmpAttack]*time_factor, State.CCValues[CC_AmpDecayTime] * time_factor, State.CCValues[CC_AmpRelease] * time_factor);

	ADSR_Filter.SetTimes(State.CCValues[CC_FLTAttack] * time_factor, State.CCValues[CC_FLTDecayTime] * time_factor, State.CCValues[CC_FLTRelease] * time_factor);

	ENV_PerkAmp.SetTimes(State.CCValues[CC_PERK_AmpATime] * time_factor, State.CCValues[CC_PERK_AmpBTime] * time_factor);

	ENV_PerkPitch.SetTimes(State.CCValues[CC_PERK_PitchATime] * time_factor, State.CCValues[CC_PERK_PitchBTime] * time_factor);
	


}

String MidiSoundControlClass::DescribeState() {

	String output = "pitch: ";
	output += tone_pitch;
	output += " on: ";
	output += tone_on;

	return output;

}

unsigned int MidiSoundControlClass::DoTick() {


	bool IsReleaseStage = NoteOnTime < NoteOffTime;
	unsigned long CurrentTime = millis();

	unsigned int cT = 0;
	unsigned int cTall = 0;

	if (IsReleaseStage) {
		cT = CurrentTime - NoteOffTime;
		cTall = CurrentTime - NoteOnTime;
	}
	else {
		cT = CurrentTime - NoteOnTime;
		cTall = CurrentTime - NoteOnTime;
	}

	
	if (IsReleaseStage) {

		if (cT > ADSR_Amp.ReleaseTime) {
			//State.out_amp_value = 0;
			//State.out_flt_value = 0;
			//tone_on = false;
		} else {

			State.out_amp_value = ADSR_Amp.ComputeR(cT);
			State.out_flt_value = ADSR_Filter.ComputeR(cT) ;
		}
	}
	else {
		
		State.out_amp_value = ADSR_Amp.ComputeADS(cT);
		State.out_flt_value = ADSR_Filter.ComputeADS(cT);
	}

	float flt_adsr_mix_factor = MathTool::GetRatio((unsigned int)State.CCValues[CC_FLT_ADSR_Mix], 127,1,0);

	State.out_amp_value = State.out_amp_value;
	State.out_flt_value = ( ((float)State.out_flt_value * flt_adsr_mix_factor) + (127 * (1- flt_adsr_mix_factor)))  * MathTool::GetRatio((unsigned int)State.CCValues[CC_Cutoff], 127, 1, 0);


	State.out_perkA_amp = ENV_PerkAmp.Compute(cTall);
	State.out_perkB_amp = State.out_perkA_amp; //ENV_PerkAmp.Compute(cTall);


	signalA_instruction.Frequency = tone_pitch;
	if (State.CCValues[CC_WaveformA_OctaveUp] == 127) signalA_instruction.Frequency = signalA_instruction.Frequency * 2;

	signalB_instruction.Frequency = tone_pitch;
	if (State.CCValues[CC_WaveformB_OctaveUp] == 127) signalB_instruction.Frequency = signalB_instruction.Frequency * 2;

	perkA_instruction.Frequency = tone_pitch;
	if (State.CCValues[CC_PerkA_OctaveUp] == 127) perkA_instruction.Frequency = perkA_instruction.Frequency * 2;

	perkB_instruction.Frequency = tone_pitch;
	if (State.CCValues[CC_PerkB_OctaveUp] == 127) perkB_instruction.Frequency = perkB_instruction.Frequency * 2;

	signalFLT_instruction.Frequency = State.CCValues[CC_FLTPitch];
	signalFLT_instruction.Set(signalFLT_SID, signalFLT_instruction.Frequency, B11110000,0, false, false, false, false);

	signalA_instruction.pwmPattern = MathTool::GetPWMWaveform(State.CCValues[CC_WaveformA_PWM]);
	signalB_instruction.pwmPattern = MathTool::GetPWMWaveform(State.CCValues[CC_WaveformB_PWM]);

	signalA_instruction.Set(signalA_SID, signalA_instruction.Frequency, signalA_instruction.pwmPattern, 0, true, true, true, true);
	signalB_instruction.Set(signalB_SID, signalB_instruction.Frequency, signalB_instruction.pwmPattern, 0, true, true, true, true);

	perkA_instruction.pwmPattern = MathTool::GetPWMWaveform(State.CCValues[CC_PERK_PWM]);
	perkB_instruction.pwmPattern = MathTool::GetPWMWaveform(127-State.CCValues[CC_PERK_PWM]);

	perkA_instruction.Set(perkA_SID, perkA_instruction.Frequency, perkA_instruction.pwmPattern, 6 - MathTool::GetPhaseShift(State.CCValues[CC_PERK_PHASE]), false, false, true, false);
	perkB_instruction.Set(perkB_SID, perkB_instruction.Frequency, perkB_instruction.pwmPattern, MathTool::GetPhaseShift(State.CCValues[CC_PERK_PHASE]), false, false, true, false);

	//float level_factor = ((float)tone_velocity / 127.0) * ((float) CCValues[CC_ChannelVolume] / 127.0) * 2;

	//out_amp_value = 255 - (ADSR_Amp.DoTick(tone_on) * 2);
	
	//if (State.out_amp_value >= (255 - gate_margin)) State.out_amp_value = 255;
	//if (State.out_amp_value <= gate_margin) State.out_amp_value = 0;
	/*
	
	
	byte out_flt_A = ADSR_Filter.DoTick(tone_on);
	byte out_flt_B = CCValues[CC_Cutoff] * 2;

	out_flt_value = ((1.0 - flt_adsr_mix_factor) * (float)out_flt_B) + (flt_adsr_mix_factor * (float)out_flt_A);
	
	out_flt_value = 255 - out_flt_value;
	*/

	float waveform_mix_ration = MathTool::GetRatio((unsigned int)State.CCValues[CC_WaveformMix], 127, 1, 0);

	State.out_waveform_mix = waveform_mix_ration * 100; // State.CCValues[CC_WaveformMix];

	if (State.out_waveform_mix > 100) State.out_waveform_mix = 100;


	State.out_waveform_b_flt = State.CCValues[CC_WaveformB_Filter] * 2;
	State.out_waveform_a_shaper = State.CCValues[CC_WaveformA_Shaper] * 2;

	State.out_flt_gain = State.CCValues[CC_Resonance] * 2;

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

