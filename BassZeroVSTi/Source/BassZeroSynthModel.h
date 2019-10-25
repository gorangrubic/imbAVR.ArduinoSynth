/*
  ==============================================================================

    BassZeroSynthModel.h
    Created: 4 Oct 2019 10:12:48pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Model/SynthDeviceModel.h"


//#include "Model/Modulation/ModulationHub.h"
//#include "Control/imbSynthAudioProcessor.h"
//
//#include "../Source/Model/Core/PitchAndPhaseControl.h"
//
//#include "Model/Components/OscilatorPerk.h"
//#include "Model/Components/OscilatorWaveform.h"
//
//#include "Model/Core/ModelModulatedControl.h"
//
//#include "Model/OPM/OPMSignalUnit.h"
//#include "Model/OPM/MacroControlLink.h"
//#include "Model/OPM/OPMControlModel.h"
//
//#include "Control\imbControlParameterEnumerations.h"
//#include "../Source/Control/imbSynthAudioProcessor.h"

class BassZeroSynthModel 
	: public SynthDeviceModel {

public:

	// === ==== MODULATION SOURCES

	ModulationFunctionADSR ADSR_A = ModulationFunctionADSR("ADSR_A", "ADSR A", true);
	ModulationFunctionADSR ADSR_B = ModulationFunctionADSR("ADSR_B", "ADSR B", true);
	
	ModulationFunctionENV ENV_A = ModulationFunctionENV("ENV_A", "ENV A", true);
	ModulationFunctionENV ENV_B = ModulationFunctionENV("ENV_B", "ENV B");
	ModulationFunctionENV ENV_C = ModulationFunctionENV("ENV_C", "ENV C");

	ModulationFunctionLFO LFO_A = ModulationFunctionLFO("LFO_A", "LFO A", true);
	ModulationFunctionLFO LFO_B = ModulationFunctionLFO("LFO_B", "LFO B", true);
	ModulationFunctionLFO LFO_C = ModulationFunctionLFO("LFO_C", "LFO C");
	ModulationFunctionLFO LFO_D = ModulationFunctionLFO("LFO_D", "LFO D");

	ModulationSourceMacroControl CTRL_A = ModulationSourceMacroControl("CTRL_A", "CTRL A", true);
	ModulationSourceMacroControl CTRL_B = ModulationSourceMacroControl("CTRL_B", "CTRL B", true);
	ModulationSourceMacroControl CTRL_C = ModulationSourceMacroControl("CTRL_C", "CTRL C", true);
	ModulationSourceMacroControl CTRL_D = ModulationSourceMacroControl("CTRL_D", "CTRL D");
	ModulationSourceMacroControl CTRL_E = ModulationSourceMacroControl("CTRL_E", "CTRL E");
	

	//ModulationSourceMacroControl CTRLA;

	/*imbControlParameter CTRL_A;
	imbControlParameter CTRL_B;
	imbControlParameter CTRL_C;*/


	// =========================== OPM Macro Controls

	ModelModulatedControl MODA = ModelModulatedControl("MODA", "OPM Mod. A", "OPM modulated macro parameter","", parameterClass::opm);
	ModelModulatedControl MODB = ModelModulatedControl("MODB", "OPM Mod. B", "OPM modulated macro parameter", "", parameterClass::opm);

	dataIntProperty  VALA = dataIntProperty("ValA", 0, "Value A", "OPM macro parameter", "", "", 0, 127, parameterClass::opm);
	dataIntProperty  VALB = dataIntProperty("ValB", 0, "Value B", "OPM macro parameter", "", "", 0, 127, parameterClass::opm);
	dataIntProperty  VALC = dataIntProperty("ValC", 0, "Value C", "OPM macro parameter", "", "", 0, 127, parameterClass::opm);

	OscilatorBase WFA = OscilatorBase("WFA", "WF A", OscilatorType::waveform, "", "");
	OscilatorBase WFB = OscilatorBase("WFB", "WF B", OscilatorType::waveform, "", "");
	OscilatorBase FLT = OscilatorBase("FLT", "Filter", OscilatorType::filter, "", "");
	OscilatorBase PERKA = OscilatorBase("PERKA", "WF A", OscilatorType::perk, "", "");
	OscilatorBase PERKB = OscilatorBase("PERKB", "WF A", OscilatorType::perk, "", "");
	
	

	// =========================== Modulation Macro Controls links

	MacroControlLink MODA_MCL1 = MacroControlLink("MODA_MCL1", "MOD A link 1", "");
	MacroControlLink MODA_MCL2 = MacroControlLink("MODA_MCL2", "MOD A link 1", "");

	MacroControlLink MODB_MCL1 = MacroControlLink("MODB_MCL1", "MOD A link 1", "");
	MacroControlLink MODB_MCL2 = MacroControlLink("MODB_MCL2", "MOD A link 1", "");

	MacroControlLink VALA_MCL1 = MacroControlLink("VALA_MCL1", "MOD A link 1", "");
	MacroControlLink VALB_MCL1 = MacroControlLink("VALB_MCL1", "MOD A link 1", "");
	MacroControlLink VALC_MCL1 = MacroControlLink("VALC_MCL1", "MOD A link 1", "");
	MacroControlLink VALC_MCL2 = MacroControlLink("VALC_MCL2", "MOD A link 1", "");

	// ========================== Main components


	ModelModulatedControl DIST_Overdrive = ModelModulatedControl("MODA", "OPM Mod. A", "OPM modulated macro parameter", "", parameterClass::opm);
	ModelModulatedControl DIST_Mix = ModelModulatedControl();

	ModelModulatedControl MST_Pan = ModelModulatedControl("MST_Pan", "MST_Pan","", "", parameterClass::ccLive);
	ModelModulatedControl MST_Amp = ModelModulatedControl("MST_Amp", "MST_Amp","", "", parameterClass::ccLive);

	ModelModulatedControl MST_FLT_CUT = ModelModulatedControl("MST_FLT_CUT", "MST_FLT_CUT", "", "", parameterClass::ccLive);
	ModelModulatedControl MST_FLT_RES = ModelModulatedControl("MST_FLT_RES", "MST_FLT_RES", "", "", parameterClass::ccLive);

	ModelModulatedControl WF_MIX = ModelModulatedControl("WF_MIX", "WF_MIX", "", "", parameterClass::ccLive);
	

	void DeployModel();

	BassZeroSynthModel(std::string _version):SynthDeviceModel("BassZero", "hardy.Veles::BassZero", _version)
	{ };

};