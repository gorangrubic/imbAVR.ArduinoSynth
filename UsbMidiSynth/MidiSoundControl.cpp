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

	CCValues[CC_Cutoff] = 30;
	CCValues[CC_Resonance] = 30;

	//CCValues[CC_FLT_ADSR_Mix] = 1;

	//CCValues[CC_FLTAttack] = 5;
	//CCValues[CC_FLTDecayTime] = 5;
	//CCValues[CC_FLTRelease] = 5;
	//CCValues[CC_FLTInitLevel] = 0;
	//CCValues[CC_FLTSustainLevel] = 40;

	//CCValues[CC_WaveformA_Shaper] = 127;
	//CCValues[CC_WaveformB_Filter] = 64;
	//CCValues[CC_WaveformMix] = 64;


	CCValues[CC_AmpAttack] = 5;
	CCValues[CC_AmpDecayTime] = 5;
	CCValues[CC_AmpRelease] = 5;
	CCValues[CC_AmpInitLevel] = 0;
	CCValues[CC_AmpSustainLevel] = 60;

	CCValues[CC_FLTAttack] = 10;
	CCValues[CC_FLTInitLevel] = 100;
	CCValues[CC_FLTRelease] = 10;
	CCValues[CC_FLTSustainLevel] = 10;

	CCValues[CC_WaveformMix] = 64;
	CCValues[CC_WaveformA_Shaper] = 64;
	CCValues[CC_WaveformB_Filter] = 64;
	CCValues[CC_FLT_ADSR_Mix] = 64;

}

void MidiSoundControlClass::noteOn(byte channel, byte pitch, byte velocity) {
	
	if (channel_id != CHANNEL_ID_ALL && channel != channel_id) return;

	tone_pitch = pitchFrequency[pitch];

	tone_on = true;

	tone_velocity = velocity;
	
	
	
	ADSR_Amp.Restart();
	ADSR_Filter.Restart();

	
}

void MidiSoundControlClass::noteOff(byte channel, byte pitch, byte velocity) {

	if (channel_id != CHANNEL_ID_ALL && channel != channel_id) return;
	
	tone_on = false;

	ADSR_Amp.NoteOff();
	ADSR_Filter.NoteOff();

}

void MidiSoundControlClass::controlChange(byte channel, byte control, byte value) {
	
	if (channel_id != CHANNEL_ID_ALL && channel != channel_id) return;

	CCValues[control] = value;

	ApplyControls();
}

void MidiSoundControlClass::systemMessage(byte sysMsg, byte paramA, byte paramB)
{
}

void MidiSoundControlClass::ApplyControls() {

	

	ADSR_Amp.SetLevels(CCValues[CC_AmpInitLevel], 127 , CCValues[CC_AmpSustainLevel]);

	ADSR_Filter.SetLevels(CCValues[CC_FLTInitLevel], 127, CCValues[CC_FLTSustainLevel]);


	ADSR_Amp.SetTimes(CCValues[CC_AmpAttack]*time_factor, CCValues[CC_AmpDecayTime] * time_factor, CCValues[CC_AmpRelease] * time_factor);

	ADSR_Filter.SetTimes(CCValues[CC_FLTAttack] * time_factor, CCValues[CC_FLTDecayTime] * time_factor, CCValues[CC_FLTRelease] * time_factor);

	


}

void MidiSoundControlClass::DoTick() {


	//float level_factor = ((float)tone_velocity / 127.0) * ((float) CCValues[CC_ChannelVolume] / 127.0) * 2;

	out_amp_value = 255 - (ADSR_Amp.DoTick(tone_on) * 2);
	
	if (out_amp_value >= (255 - gate_margin)) out_amp_value = 255;
	if (out_amp_value <= gate_margin) out_amp_value = 0;

	float flt_adsr_mix_factor = ADSR_Filter.GetRatio(CCValues[CC_FLT_ADSR_Mix], 127);
	
	byte out_flt_A = ADSR_Filter.DoTick(tone_on);
	byte out_flt_B = CCValues[CC_Cutoff] * 2;

	out_flt_value = ((1.0 - flt_adsr_mix_factor) * (float)out_flt_B) + (flt_adsr_mix_factor * (float)out_flt_A);
	
	out_flt_value = 255 - out_flt_value;


	out_waveform_mix = CCValues[CC_WaveformMix] * 2;
	out_waveform_b_flt = CCValues[CC_WaveformB_Filter] * 2;
	out_waveform_a_shaper = CCValues[CC_WaveformA_Shaper] * 2;

	out_flt_gain = CCValues[CC_Resonance] * 2;

	if (ADSR_Amp.CurrentState == ADSRUnitState::off) {
		
	}
	
	
}

void MidiSoundControlClass::init()
{
	
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
}


//MidiSoundControlClass MidiSoundControl;

