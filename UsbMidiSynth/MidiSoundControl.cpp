// 
// 
// 

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


	State.CCValues[CC_AmpAttack] = 5;
	State.CCValues[CC_AmpDecayTime] = 5;
	State.CCValues[CC_AmpRelease] = 5;
	State.CCValues[CC_AmpInitLevel] = 0;
	State.CCValues[CC_AmpSustainLevel] = 60;

	State.CCValues[CC_FLTAttack] = 10;
	State.CCValues[CC_FLTInitLevel] = 100;
	State.CCValues[CC_FLTRelease] = 10;
	State.CCValues[CC_FLTSustainLevel] = 10;

	State.CCValues[CC_WaveformMix] = 64;
	State.CCValues[CC_WaveformA_Shaper] = 64;
	State.CCValues[CC_WaveformB_Filter] = 64;
	State.CCValues[CC_FLT_ADSR_Mix] = 64;

}

void MidiSoundControlClass::noteOn(byte channel, byte pitch, byte velocity) {
	
	if (channel_id != CHANNEL_ID_ALL && channel != channel_id) return;

	tone_pitch = pitchFrequency[pitch];

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

	State.CCValues[control] = value;

	ApplyControls();
}

void MidiSoundControlClass::systemMessage(byte sysMsg, byte paramA, byte paramB)
{
}

void MidiSoundControlClass::ApplyControls() {

	

	ADSR_Amp.SetLevels(State.CCValues[CC_AmpInitLevel], 127 , State.CCValues[CC_AmpSustainLevel]);

	ADSR_Filter.SetLevels(State.CCValues[CC_FLTInitLevel], 127, State.CCValues[CC_FLTSustainLevel]);


	ADSR_Amp.SetTimes(State.CCValues[CC_AmpAttack]*time_factor, State.CCValues[CC_AmpDecayTime] * time_factor, State.CCValues[CC_AmpRelease] * time_factor);

	ADSR_Filter.SetTimes(State.CCValues[CC_FLTAttack] * time_factor, State.CCValues[CC_FLTDecayTime] * time_factor, State.CCValues[CC_FLTRelease] * time_factor);

	


}

unsigned int MidiSoundControlClass::DoTick() {


	bool IsReleaseStage = NoteOnTime < NoteOffTime;
	unsigned long CurrentTime = millis();

	unsigned int cT = 0;

	if (IsReleaseStage) {
		cT = CurrentTime - NoteOffTime;
	}
	else {
		cT = CurrentTime - NoteOnTime;
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

