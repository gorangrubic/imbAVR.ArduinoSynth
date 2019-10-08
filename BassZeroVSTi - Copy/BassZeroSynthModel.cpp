/*
  ==============================================================================

    BassZeroSynthModel.cpp
    Created: 4 Oct 2019 10:12:48pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "BassZeroSynthModel.h"


void BassZeroSynthModel::DeployModel(imbSynthAudioProcessor * synthProcessor)
{
//	SynthProcessor = synthProcessor;

	modulations.AddADSR(&ADSR_A);
	modulations.AddADSR(&ADSR_B);

	modulations.AddENV(&ENV_A);
	modulations.AddENV(&ENV_B);
	modulations.AddENV(&ENV_C);

	modulations.AddLFO(&LFO_A);
	modulations.AddLFO(&LFO_B);
	modulations.AddLFO(&LFO_C);
	modulations.AddLFO(&LFO_D);

	// =================== Deploying Macro Control Links
	opmControl.AddMacroControlLink(&MODA_MCL1, "MODA_MCL1", "OPM Macro Modulation A - 1");
	opmControl.AddMacroControlLink(&MODA_MCL2, "MODA_MCL2", "OPM Macro Modulation A - 2");
	opmControl.AddMacroControlLink(&MODB_MCL1, "MODB_MCL1", "OPM Macro Modulation B - 1");
	opmControl.AddMacroControlLink(&MODB_MCL2, "MODB_MCL2", "OPM Macro Modulation B - 2");

	opmControl.AddMacroControlLink(&VALA_MCL1, "VALA_MCL1", "OPM Macro Value A");
	opmControl.AddMacroControlLink(&VALB_MCL1, "VALB_MCL1", "OPM Macro Value B");
	opmControl.AddMacroControlLink(&VALC_MCL1, "VALC_MCL1", "OPM Macro Value C");
	opmControl.AddMacroControlLink(&VALC_MCL2, "VALC_MCL2", "OPM Macro Value C");

	opmControl.AddMacroControlLink(&MODA_MCL1, "MODA_MCL1", "OPM Macro Modulation A - 1");


	// =================== OPM Control parameters for the signal generator units

	opmControl.AddSignalUnit(&OPM_WFA, "WFA", "Waveform A");
	opmControl.AddSignalUnit(&OPM_WFB, "WFB", "Waveform B");

	opmControl.AddSignalUnit(&FLT_RESA, "FLT_RESA", "Filter Resonance A");
	opmControl.AddSignalUnit(&FLT_RESB, "FLT_RESB", "Filter Resonance B");

	opmControl.AddSignalUnit(&OPM_PERKA, "PERKA", "PERK A");
	opmControl.AddSignalUnit(&OPM_PERKB, "PERKB", "PERK B");


	// =================== MST components

	components.AddModulatedControl(&DIST_Overdrive, "DistDrive", "Distortion overdrive");
	components.AddModulatedControl(&DIST_Mix, "DistMix", "Distortion wet/dry mix");

	components.AddModulatedControl(&MST_Pan, "MstPan", "Master PAN");
	components.AddModulatedControl(&MST_Amp, "MstAmp", "Master AMP");
	
	components.AddModulatedControl(&MST_FLT_CUT, "FLT_Cut", "Master CutOff");
	components.AddModulatedControl(&MST_FLT_RES, "FLT_Res", "Master Resonance");

	components.AddModulatedControl(&MST_FLT_PITCH, "FLT_Freq", "Resonant oscilator frequency");
	components.AddModulatedControl(&MST_FLT_PWM, "FLT_Pwm", "PWM of resonant oscilator");

	components.AddModulatedControl(&MST_PAN_PERKA, "PERKA_Pan", "PERKA PAN");
	components.AddModulatedControl(&MST_PAN_PERKB, "PERKB_Pan", "PERKB PAN");

	components.AddModulatedControl(&OSC_WF_MIX, "WF_Mix", "WF A/B Mix");
	components.AddModulatedControl(&OSC_WF_FLT, "WF_FLT", "WF A/B Filter mix");

	components.AddPerk(&OSC_PERKA);
	components.AddPerk(&OSC_PERKB);

	components.AddWaveform(&OSC_WFA);
	components.AddWaveform(&OSC_WFB);

	// =========================== OPM Macro Controls
	components.AddModulatedControl(&OPM_MODA, "OPM_MODA", "Modulated parameter A");
	components.AddModulatedControl(&OPM_MODB, "OPM_MODB", "Modulated parameter B");

	components.AddCCParameter(&OPM_VALA, "OPM_VALA", "Value A", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);

	components.AddCCParameter(&OPM_VALB, "OPM_VALB", "Value B", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);

	components.AddCCParameter(&OPM_VALC, "OPM_VALC", "Value C", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);
	
}

BassZeroSynthModel::BassZeroSynthModel()
{
	//ShortName = "BassZero";
	//LongName = "hardy.Veles::BassZero VSTi";
}
