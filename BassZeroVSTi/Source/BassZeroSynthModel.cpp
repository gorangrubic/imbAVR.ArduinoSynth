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


	AddGroup(&MST_Group, "MST", "Master mixer");
	AddGroup(&OPM_Group, "OPM", "Operation mode controls");
	AddGroup(&WFA_Group, "WFA", "Waveform A");
	AddGroup(&WFB_Group, "WFB", "Waveform B");
	AddGroup(&PERKA_Group, "PERKA", "PERK A");
	AddGroup(&PERKB_Group, "PERKB", "PERK B");

	MODULATIONS AddADSR(&ADSR_A);
	MODULATIONS AddADSR(&ADSR_B);

	MODULATIONS AddENV(&ENV_A);
	MODULATIONS AddENV(&ENV_B);
	MODULATIONS AddENV(&ENV_C);

	MODULATIONS AddLFO(&LFO_A);
	MODULATIONS AddLFO(&LFO_B);
	MODULATIONS AddLFO(&LFO_C);
	MODULATIONS AddLFO(&LFO_D);

	MODULATIONS AddMacroControl(new ModulationSourceMacroControl());
	MODULATIONS AddMacroControl(new ModulationSourceMacroControl());
	MODULATIONS AddMacroControl(new ModulationSourceMacroControl());


	// =================== Deploying Macro Control Links
	OPMCONTROL AddMacroControlLink(&MODA_MCL1, "MODA_MCL1", "OPM Macro Modulation A - 1");
	OPMCONTROL AddMacroControlLink(&MODA_MCL2, "MODA_MCL2", "OPM Macro Modulation A - 2");
	OPMCONTROL AddMacroControlLink(&MODB_MCL1, "MODB_MCL1", "OPM Macro Modulation B - 1");
	OPMCONTROL AddMacroControlLink(&MODB_MCL2, "MODB_MCL2", "OPM Macro Modulation B - 2");

	OPMCONTROL AddMacroControlLink(&VALA_MCL1, "VALA_MCL1", "OPM Macro Value A");
	OPMCONTROL AddMacroControlLink(&VALB_MCL1, "VALB_MCL1", "OPM Macro Value B");
	OPMCONTROL AddMacroControlLink(&VALC_MCL1, "VALC_MCL1", "OPM Macro Value C");
	OPMCONTROL AddMacroControlLink(&VALC_MCL2, "VALC_MCL2", "OPM Macro Value C");




	// =================== OPM Control parameters for the signal generator units

	OPMCONTROL AddSignalUnit(&OPM_WFA, "WFA_OSC", "Waveform A");
	OPM_WFA.AddChangeUnit(new OPMSignalUnitChange(), NameString_PWM, LabelString_PWM);
	OPM_WFA.AddChangeUnit(new OPMSignalUnitChange(), NameString_Pitch, LabelString_Pitch);
	OPM_WFA.AddChangeUnit(new OPMSignalUnitChange(), NameString_Phase, LabelString_Phase);

	OPMCONTROL AddSignalUnit(&OPM_WFB, "WFB_OSC", "Waveform B");
	OPM_WFB.AddChangeUnit(new OPMSignalUnitChange(), NameString_PWM, LabelString_PWM);
	OPM_WFB.AddChangeUnit(new OPMSignalUnitChange(), NameString_Pitch, LabelString_Pitch);
	OPM_WFB.AddChangeUnit(new OPMSignalUnitChange(), NameString_Phase, LabelString_Phase);


	OPMCONTROL AddSignalUnit(&FLT_RESA, "FLT_OSC", "Filter Resonance");
	FLT_RESA.AddChangeUnit(new OPMSignalUnitChange(), NameString_PWM, LabelString_PWM);
	FLT_RESA.AddChangeUnit(new OPMSignalUnitChange(), NameString_Pitch, LabelString_Pitch);
	FLT_RESA.AddChangeUnit(new OPMSignalUnitChange(), NameString_Phase, LabelString_Phase);


	OPMCONTROL AddSignalUnit(&OPM_PERKA, "PERKA_OSC", "PERK A");
	OPM_PERKA.AddChangeUnit(new OPMSignalUnitChange(), NameString_PWM, LabelString_PWM);
	OPM_PERKA.AddChangeUnit(new OPMSignalUnitChange(), NameString_Pitch, LabelString_Pitch);
	OPM_PERKA.AddChangeUnit(new OPMSignalUnitChange(), NameString_Phase, LabelString_Phase);


	OPMCONTROL AddSignalUnit(&OPM_PERKB, "PERKB_OSC", "PERK B");
	OPM_PERKB.AddChangeUnit(new OPMSignalUnitChange(), NameString_PWM, LabelString_PWM);
	OPM_PERKB.AddChangeUnit(new OPMSignalUnitChange(), NameString_Pitch, LabelString_Pitch);
	OPM_PERKB.AddChangeUnit(new OPMSignalUnitChange(), NameString_Phase, LabelString_Phase);


	opmControl.AddCCParameter(parameterController, &OPM_VALA, "OPM_VALA", "Value A", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);

	opmControl.AddCCParameter(parameterController, &OPM_VALB, "OPM_VALB", "Value B", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);

	opmControl.AddCCParameter(parameterController, &OPM_VALC, "OPM_VALC", "Value C", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);


	// =================== MST components

	COMPONENTS AddModulatedControl(&DIST_Overdrive, "DistDrive", "Distortion overdrive", &MST_Group);
	COMPONENTS AddModulatedControl(&DIST_Mix, "DistMix", "Distortion wet/dry mix", &MST_Group);

	COMPONENTS AddModulatedControl(&MST_Pan, "MstPan", "Master PAN", &MST_Group);
	COMPONENTS AddModulatedControl(&MST_Amp, "MstAmp", "Master AMP", &MST_Group);

	COMPONENTS AddModulatedControl(&MST_FLT_CUT, "FLT_Cut", "Master CutOff", &MST_Group);
	COMPONENTS AddModulatedControl(&MST_FLT_RES, "FLT_Res", "Master Resonance", &MST_Group);

	COMPONENTS AddModulatedControl(&MST_FLT_PITCH, "FLT_Freq", "Resonant oscilator frequency", &MST_Group);
	COMPONENTS AddModulatedControl(&MST_FLT_PWM, "FLT_Pwm", "PWM of resonant oscilator", &MST_Group);

	COMPONENTS AddModulatedControl(&MST_PAN_PERKA, "PERKA_Pan", "PERKA PAN", &MST_Group);
	COMPONENTS AddModulatedControl(&MST_PAN_PERKB, "PERKB_Pan", "PERKB PAN", &MST_Group);

	COMPONENTS AddModulatedControl(&OSC_WF_MIX, "WF_Mix", "WF A/B Mix", &MST_Group);
	COMPONENTS AddModulatedControl(&OSC_WF_FLT, "WF_FLT", "WF A/B Filter mix", &MST_Group);

	COMPONENTS AddPitchAndPhaseControl(&WFA, "WFA", "Waveform A", &WFA_Group);
	COMPONENTS AddModulatedControl(&WFA_PWM, "WFA_PWM", "PWM for Waveform A", &WFA_Group);
	COMPONENTS AddModulatedControl(&WFA_Shaper, "WFA_Shaper", "Shape modulation for WFA", &WFA_Group);

	COMPONENTS AddPitchAndPhaseControl(&WFB, "WFB", "Waveform B", &WFB_Group);
	COMPONENTS AddModulatedControl(&WFB_PWM, "WFB_PWM", "PWM for Waveform B", &WFB_Group);
	COMPONENTS AddModulatedControl(&WFB_Shaper, "WFB_Shaper", "Shape modulation for WFB", &WFB_Group);

	COMPONENTS AddPitchAndPhaseControl(&PERKA, "PERKA", "PERK A", &PERKA_Group);
	COMPONENTS AddModulatedControl(&PERKA_PWM, "PERKA_PWM", "PWM for PERK A", &PERKA_Group);
	COMPONENTS AddModulatedControl(&PERKA_HPFREQ, "PERKA_HPFREQ", "HP cutoff freq.", &PERKA_Group);
	COMPONENTS AddModulatedControl(&PERKA_AMP, "PERKA_AMP", "Volume of PERK A", &PERKA_Group);

	COMPONENTS AddPitchAndPhaseControl(&PERKB, "PERKB", "PERK B", &PERKB_Group);
	COMPONENTS AddModulatedControl(&PERKB_PWM, "PERKB_PWM", "PWM for PERK B", &PERKB_Group);
	COMPONENTS AddModulatedControl(&PERKB_HPFREQ, "PERKB_HPFREQ", "HP cutoff freq.", &PERKB_Group);
	COMPONENTS AddModulatedControl(&PERKB_AMP, "PERKB_AMP", "Volume of PERK B", &PERKB_Group);

	// =========================== OPM Macro Controls
	COMPONENTS AddModulatedControl(&OPM_MODA, "OPM_MODA", "Modulated parameter A", &OPM_Group);
	COMPONENTS AddModulatedControl(&OPM_MODB, "OPM_MODB", "Modulated parameter B", &OPM_Group);


	
	/*COMPONENTS AddCCParameter(parameterController, &CTRL_A, "CTRLA", "Macro control A", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);

	COMPONENTS AddCCParameter(parameterController, &CTRL_B, "CTRLB", "Macro control A", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);

	COMPONENTS AddCCParameter(parameterController, &CTRL_C, "CTRLC", "Macro control A", 0, 0, 127, -1, true, imbControlParameterMessageType::ccMIDI);
	*/
}
//
//BassZeroSynthModel::BassZeroSynthModel()
//{
//	//ShortName = "BassZero";
//	//LongName = "hardy.Veles::BassZero VSTi";
//}
