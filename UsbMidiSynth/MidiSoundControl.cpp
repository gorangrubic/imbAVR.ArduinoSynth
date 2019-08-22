// 
// 
// 

#include "MidiSoundControl.h"

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

/*
	switch (control) {
	
	case  CC_ModulationWheel:
		fx_Modulation = value;
		break;

	case  CC_ChannelVolume:
		amp_ChannelVolume = value;
		break;
	case  CC_Balance:
		amp_Balance = value;
		break;



	case  CC_Shaper:
		fx_Shaper = value;
		break;


	case  CC_FLT_ADSR_Mix:
		flt_ADSR_Mix = value;
		break;
	case  CC_Cutoff:
		flt_Cutoff = value;
		break;

	case  CC_AmpRelease:
		amp_ReleaseTime = value;
		break;
	case  CC_AmpAttack:
		amp_AttackTime = value;
		break;
	case  CC_AmpInitLevel:
		amp_InitLevel = value;
		break;
	case  CC_AmpSustainLevel:
		amp_SustainLevel = value;
		break;
	case  CC_AmpDecayTime:
		amp_DecayTime = value;
		break;


	case  CC_FLTAttack:
		flt_AttackTime = value;
		break;
	case  CC_FLTDecayTime:
		flt_DecayTime = value;
		break;
	case  CC_FLTRelease:
		flt_ReleaseTime = value;
		break;

	case  CC_FLTInitLevel:
		flt_InitLevel = value;
		break;
	case  CC_FLTSustainLevel:
		flt_SustainLevel = value;
		break;
	}
*/
	ApplyControls();
}

void MidiSoundControlClass::systemMessage(byte sysMsg, byte paramA, byte paramB)
{
}

void MidiSoundControlClass::ApplyControls() {

	

	ADSR_Amp.SetLevels(CCValues[CC_AmpInitLevel], 127 , CCValues[CC_AmpSustainLevel]);

	ADSR_Filter.SetLevels(CCValues[CC_FLTInitLevel], 127, CCValues[CC_FLTSustainLevel]);


	ADSR_Amp.SetTimes(CCValues[CC_AmpAttack], CCValues[CC_AmpDecayTime], CCValues[CC_AmpDecayTime]);

	ADSR_Filter.SetTimes(CCValues[CC_FLTAttack], CCValues[CC_FLTDecayTime], CCValues[CC_FLTRelease]);


}

void MidiSoundControlClass::DoTick() {


	//float level_factor = ((float)tone_velocity / 127.0) * ((float) CCValues[CC_ChannelVolume] / 127.0) * 2;

	out_amp_value = ADSR_Amp.DoTick(tone_on) * 2;

	float flt_adsr_mix_factor = ADSR_Filter.GetRatio(CCValues[CC_FLT_ADSR_Mix], 127);
	
	byte out_flt_A = ADSR_Filter.DoTick(tone_on);
	byte out_flt_B = CCValues[CC_Cutoff] * 2;

	out_flt_value = ((1.0 - flt_adsr_mix_factor) * (float)out_flt_B) + (flt_adsr_mix_factor * (float)out_flt_A);
	
	out_flt_value = 255 - out_flt_value;


	out_waveform_mix = CCValues[CC_WaveformMix] * 2;
	out_waveform_b_flt = CCValues[CC_WaveformB_Filter] * 2;
	out_waveform_a_shaper = CCValues[CC_WaveformA_Shaper] * 2;

	out_flt_gain = CCValues[CC_Resonance] * 2;


	
	
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

