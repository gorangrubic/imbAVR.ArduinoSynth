/*
  ==============================================================================

    BassZeroSynthModel.cpp
    Created: 4 Oct 2019 10:12:48pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "BassZeroSynthModel.h"



void BassZeroSynthModel::DeployModel()
{
	parameterController.Reset();
	//modelConstructionTools.parameterController.Reset();

	//ModelConstructionTools::parameterController.Reset();

//	SynthProcessor = synthProcessor;

	MODULATIONS AddADSR(&ADSR_A);
	MODULATIONS AddADSR(&ADSR_B);

	MODULATIONS AddENV(&ENV_A);
	MODULATIONS AddENV(&ENV_B);
	MODULATIONS AddENV(&ENV_C);

	MODULATIONS AddLFO(&LFO_A);
	MODULATIONS AddLFO(&LFO_B);
	MODULATIONS AddLFO(&LFO_C);
	MODULATIONS AddLFO(&LFO_D);

	
	// =================== Deploying Macro Control Links
	OPMCONTROL AddMacroControlLink(&MODA_MCL1, "MODA_MCL1", "OPM Macro Modulation A - 1");
	OPMCONTROL AddMacroControlLink(&MODA_MCL2, "MODA_MCL2", "OPM Macro Modulation A - 2");
	OPMCONTROL AddMacroControlLink(&MODB_MCL1, "MODB_MCL1", "OPM Macro Modulation B - 1");
	OPMCONTROL AddMacroControlLink(&MODB_MCL2, "MODB_MCL2", "OPM Macro Modulation B - 2");

	OPMCONTROL AddMacroControlLink(&VALA_MCL1, "VALA_MCL1", "OPM Macro Value A");
	OPMCONTROL AddMacroControlLink(&VALB_MCL1, "VALB_MCL1", "OPM Macro Value B");
	OPMCONTROL AddMacroControlLink(&VALC_MCL1, "VALC_MCL1", "OPM Macro Value C");
	OPMCONTROL AddMacroControlLink(&VALC_MCL2, "VALC_MCL2", "OPM Macro Value C");

	OPMCONTROL AddMacroControlLink(&MODA_MCL1, "MODA_MCL1", "OPM Macro Modulation A - 1");


	// =================== OPM Control parameters for the signal generator units

	OPMCONTROL AddSignalUnit(&OPM_WFA, "WFA", "Waveform A");
	OPMCONTROL AddSignalUnit(&OPM_WFB, "WFB", "Waveform B");

	OPMCONTROL AddSignalUnit(&FLT_RESA, "FLT_RESA", "Filter Resonance A");
	OPMCONTROL AddSignalUnit(&FLT_RESB, "FLT_RESB", "Filter Resonance B");

	OPMCONTROL AddSignalUnit(&OPM_PERKA, "PERKA", "PERK A");
	OPMCONTROL AddSignalUnit(&OPM_PERKB, "PERKB", "PERK B");


	// =================== MST components

	COMPONENTS AddModulatedControl(&DIST_Overdrive, "DistDrive", "Distortion overdrive");
	COMPONENTS AddModulatedControl(&DIST_Mix, "DistMix", "Distortion wet/dry mix");

	COMPONENTS AddModulatedControl(&MST_Pan, "MstPan", "Master PAN");
	COMPONENTS AddModulatedControl(&MST_Amp, "MstAmp", "Master AMP");
	
	COMPONENTS AddModulatedControl(&MST_FLT_CUT, "FLT_Cut", "Master CutOff");
	COMPONENTS AddModulatedControl(&MST_FLT_RES, "FLT_Res", "Master Resonance");

	COMPONENTS AddModulatedControl(&MST_FLT_PITCH, "FLT_Freq", "Resonant oscilator frequency");
	COMPONENTS AddModulatedControl(&MST_FLT_PWM, "FLT_Pwm", "PWM of resonant oscilator");

	COMPONENTS AddModulatedControl(&MST_PAN_PERKA, "PERKA_Pan", "PERKA PAN");
	COMPONENTS AddModulatedControl(&MST_PAN_PERKB, "PERKB_Pan", "PERKB PAN");

	COMPONENTS AddModulatedControl(&OSC_WF_MIX, "WF_Mix", "WF A/B Mix");
	COMPONENTS AddModulatedControl(&OSC_WF_FLT, "WF_FLT", "WF A/B Filter mix");

	COMPONENTS AddPerk(&OSC_PERKA);
	COMPONENTS AddPerk(&OSC_PERKB);

	COMPONENTS AddWaveform(&OSC_WFA);
	COMPONENTS AddWaveform(&OSC_WFB);

	// =========================== OPM Macro Controls
	COMPONENTS AddModulatedControl(&OPM_MODA, "OPM_MODA", "Modulated parameter A");
	COMPONENTS AddModulatedControl(&OPM_MODB, "OPM_MODB", "Modulated parameter B");

	COMPONENTS AddCCParameter(parameterController,&OPM_VALA, "OPM_VALA", "Value A", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);

	COMPONENTS AddCCParameter(parameterController, &OPM_VALB, "OPM_VALB", "Value B", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);

	COMPONENTS AddCCParameter(parameterController, &OPM_VALC, "OPM_VALC", "Value C", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);
	

	
}
//
//BassZeroSynthModel::BassZeroSynthModel()
//{
//	//ShortName = "BassZero";
//	//LongName = "hardy.Veles::BassZero VSTi";
//}
