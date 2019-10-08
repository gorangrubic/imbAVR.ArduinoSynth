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

#include "Model/Modulation/ModulationHub.h"
#include "Control/imbSynthAudioProcessor.h"

#include "Model/Components/OscilatorPerk.h";
#include "Model/Components/OscilatorWaveform.h";

#include "Model/Core/ModelModulatedControl.h"

#include "Model/OPM/OPMSignalUnit.h";
#include "Model/OPM/MacroControlLink.h";
#include "Model/OPM/OPMControlModel.h"

#include "Control\imbControlParameterEnumerations.h"

class BassZeroSynthModel : public SynthDeviceModel {

public:



	ModulationHub modulations;
	ComponentHub components;
	OPMControlModel opmControl;

	// === ==== MODULATION SOURCES

	ModulationFunctionADSR ADSR_A = ModulationFunctionADSR();
	ModulationFunctionADSR ADSR_B = ModulationFunctionADSR();
	
	ModulationFunctionENV ENV_A = ModulationFunctionENV();
	ModulationFunctionENV ENV_B = ModulationFunctionENV();
	ModulationFunctionENV ENV_C = ModulationFunctionENV();

	ModulationFunctionLFO LFO_A = ModulationFunctionLFO();
	ModulationFunctionLFO LFO_B = ModulationFunctionLFO();
	ModulationFunctionLFO LFO_C = ModulationFunctionLFO();
	ModulationFunctionLFO LFO_D = ModulationFunctionLFO();

	imbControlParameter CTRL_A;
	imbControlParameter CTRL_B;
	imbControlParameter CTRL_C;

	ModulationSourceMIDI VEL = ModulationSourceMIDI();

	// =========================== OPM Macro Controls

	ModelModulatedControl OPM_MODA = ModelModulatedControl();
	ModelModulatedControl OPM_MODB = ModelModulatedControl();

	imbControlParameter OPM_VALA;
	imbControlParameter OPM_VALB;
	imbControlParameter OPM_VALC;

	// =========================== OPM Signal Units
	OPMSignalUnit OPM_WFA = OPMSignalUnit();
	OPMSignalUnit OPM_WFB = OPMSignalUnit();
	OPMSignalUnit FLT_RESA = OPMSignalUnit();
	OPMSignalUnit FLT_RESB = OPMSignalUnit();
	OPMSignalUnit OPM_PERKA = OPMSignalUnit();
	OPMSignalUnit OPM_PERKB = OPMSignalUnit();


	// =========================== Modulation Macro Controls links

	MacroControlLink MODA_MCL1 = MacroControlLink();
	MacroControlLink MODA_MCL2 = MacroControlLink();

	MacroControlLink MODB_MCL1 = MacroControlLink();
	MacroControlLink MODB_MCL2 = MacroControlLink();

	MacroControlLink VALA_MCL1 = MacroControlLink();
	MacroControlLink VALB_MCL1 = MacroControlLink();
	MacroControlLink VALC_MCL1 = MacroControlLink();
	MacroControlLink VALC_MCL2 = MacroControlLink();

	// ========================== Main components

	ModelModulatedControl DIST_Overdrive = ModelModulatedControl();
	ModelModulatedControl DIST_Mix = ModelModulatedControl();

	ModelModulatedControl MST_Pan = ModelModulatedControl();
	ModelModulatedControl MST_Amp = ModelModulatedControl();

	
	ModelModulatedControl MST_FLT_CUT = ModelModulatedControl();
	ModelModulatedControl MST_FLT_RES = ModelModulatedControl();

	ModelModulatedControl MST_FLT_PITCH = ModelModulatedControl();
	ModelModulatedControl MST_FLT_PWM = ModelModulatedControl();



	ModelModulatedControl MST_PAN_PERKA = ModelModulatedControl();
	ModelModulatedControl MST_PAN_PERKB = ModelModulatedControl();

	OscilatorWaveform OSC_WFA = OscilatorWaveform();
	OscilatorWaveform OSC_WFB = OscilatorWaveform();
	


	OscilatorPerk OSC_PERKA = OscilatorPerk();
	OscilatorPerk OSC_PERKB = OscilatorPerk();

	ModelModulatedControl OSC_WF_MIX = ModelModulatedControl();
	ModelModulatedControl OSC_WF_FLT = ModelModulatedControl();
	

	void DeployModel(imbSynthAudioProcessor * synthProcessor);

	BassZeroSynthModel();

};