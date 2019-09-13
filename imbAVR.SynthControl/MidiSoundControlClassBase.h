#pragma once

#include "ControlFunctionADSR.h"
#include "ControlFunction2PEnv.h"
#include "ControlFunctionLFO.h"
#include "ControlFunctionChaos.h"
#include "ControlFunctionCombine.h"

class MidiSoundControlClassBase
{
public:

	/*
	* Modulation source functions:
	* ADSR A	- Attack, Decay, Sustain, Release ENV function
	* ADSR B	- Attack, Decay, Sustain, Release ENV function
	* Chaos	- Random function, with time (target position change) and spread (range for target positions) parameters
	* ENV A	- Two point (A and B; time and value) linear interpolation, looped
	* ENV B	- Two point (A and B; time and value) linear interpolation, looped
	* LFO A	- One point (cycle time and peak value) linear interpolation, looped
	* LFO B	- One point (cycle time and peak value) linear interpolation, looped
	*/

	ControlFunctionADSR<CC_AmpAttack, CC_AmpDecayTime, CC_AmpRelease, CC_AmpInitLevel, CC_AmpSustainLevel> CF_ADSR_A;
	ControlFunctionADSR<CC_FLTAttack, CC_FLTDecayTime, CC_FLTRelease, CC_FLTInitLevel, CC_FLTSustainLevel> CF_ADSR_B;
	ControlFunctionChaos<CC_ChaosTime, CC_ChaosSpread, CC_ChaosTimeFactor> CF_Chaos;
	ControlFunction2PEnv<CC_ENVA_ATime, CC_ENVA_BTime, CC_ENVA_ALevel, CC_ENVA_BLevel> CF_ENV_A;
	ControlFunction2PEnv<CC_ENVB_ATime, CC_ENVB_BTime, CC_ENVB_ALevel, CC_ENVB_BLevel> CF_ENV_B;
	ControlFunctionLFO<CC_LFOATime, CC_LFOATimeFactor, CC_LFOAValue> CF_LFO_A;
	ControlFunctionLFO<CC_LFOBTime, CC_LFOBTimeFactor, CC_LFOBValue> CF_LFO_B;

	/*
	* Modulation target functions:
	* *_ModSrc		-- assigns modulation source
	* *_ModAmt		-- controls in what proportion the modulation function affects the controled value
	* *_Val		-- direct value control (applied in complement proportion to *_ModAmt)
	*/

	/*
	* CF_FLT_Cutoff	- Controls cut-off frequency at main low-pass filter circuit
	* CF_FLT_Dist		- Controls distortion dry/wet mix for the main sound component
	* CF_FLT_Res		- Controls resonance amount (i.e. Q factor) at main low-pass filer circuit
	* CF_FLT_Freq		- Controls resonant frequency at main low-pass filter circuit
	*/

	ControlFunctionCombine<CC_FLT_CutOff_ModSrc, CC_FLT_CutOff_ModAmt, CC_FLT_CutOff_Val> CF_FLT_CutOff;
	ControlFunctionCombine<CC_FLT_Dist_ModSrc, CC_FLT_Dist_ModAmt, CC_FLT_Dist_Val> CF_FLT_Dist;
	ControlFunctionCombine<CC_FLT_Res_ModSrc, CC_FLT_Res_ModAmt, CC_FLT_Res_Val> CF_FLT_Res;
	ControlFunctionCombine<CC_FLT_Freq_ModSrc, CC_FLT_Freq_ModAmt, CC_FLT_Freq_Val> CF_FLT_Freq;

	/*
	* CF_PERKA_Amp		- Controls volume (amplitude modulation) for PERK A square oscilator
	* CF_PERKA_Pan		- Controls stereo position (L/R pan) for PERK A square oscilator
	* CF_PERKB_Amp		- Controls volume (amplitude modulation) for PERK B square oscilator
	* CF_PERKB_Pan		- Controls stereo position (L/R pan) for PERK B square oscilator
	*/
	ControlFunctionCombine<CC_PERKA_Amp_ModSrc, CC_PERKA_Amp_ModAmt, CC_PERKA_Amp_Val> CF_PERKA_Amp;
	ControlFunctionCombine<CC_PERKA_Pan_ModSrc, CC_PERKA_Pan_ModAmt, CC_PERKA_Pan_Val> CF_PERKA_Pan;
	ControlFunctionCombine<CC_PERKB_Amp_ModSrc, CC_PERKB_Amp_ModAmt, CC_PERKB_Amp_Val> CF_PERKB_Amp;
	ControlFunctionCombine<CC_PERKB_Pan_ModSrc, CC_PERKB_Pan_ModAmt, CC_PERKB_Pan_Val> CF_PERKB_Pan;

	/*
	* CF_MAINCOMPONENT_Pan	- Controls stereo position (L/R pan) for the main component (mix of waveform A and B)
	*/
	ControlFunctionCombine<CC_MAINCOMPONENT_Pan_ModSrc, CC_MAINCOMPONENT_Pan_ModAmt, CC_MAINCOMPONENT_Pan_Val> CF_MAINCOMPONENT_Pan;

	MidiSoundControlClassBase();
	~MidiSoundControlClassBase();
};

