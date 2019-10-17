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

#include "../Source/Model/Core/PitchAndPhaseControl.h"

#include "Model/Components/OscilatorPerk.h"
#include "Model/Components/OscilatorWaveform.h"

#include "Model/Core/ModelModulatedControl.h"

#include "Model/OPM/OPMSignalUnit.h"
#include "Model/OPM/MacroControlLink.h"
#include "Model/OPM/OPMControlModel.h"

#include "Control\imbControlParameterEnumerations.h"
#include "../Source/Control/imbSynthAudioProcessor.h"

class BassZeroSynthModel 
	: public SynthDeviceModel {

public:






	// === ==== MODULATION SOURCES

	ModulationFunctionADSR ADSR_A;
	ModulationFunctionADSR ADSR_B;
	
	ModulationFunctionENV ENV_A;
	ModulationFunctionENV ENV_B;
	ModulationFunctionENV ENV_C;

	ModulationFunctionLFO LFO_A;
	ModulationFunctionLFO LFO_B;
	ModulationFunctionLFO LFO_C;
	ModulationFunctionLFO LFO_D;


	//ModulationSourceMacroControl CTRLA;

	/*imbControlParameter CTRL_A;
	imbControlParameter CTRL_B;
	imbControlParameter CTRL_C;*/

	ModulationSourceMIDI VEL;

	// =========================== OPM Macro Controls

	ModelModulatedControl OPM_MODA;
	ModelModulatedControl OPM_MODB;

	imbControlParameter OPM_VALA;
	imbControlParameter OPM_VALB;
	imbControlParameter OPM_VALC;

	// =========================== OPM Signal Units
	OPMSignalUnit OPM_WFA;
	OPMSignalUnit OPM_WFB;
	OPMSignalUnit FLT_RESA;
	OPMSignalUnit FLT_RESB;
	OPMSignalUnit OPM_PERKA;
	OPMSignalUnit OPM_PERKB;


	// =========================== Modulation Macro Controls links

	MacroControlLink MODA_MCL1;
	MacroControlLink MODA_MCL2;

	MacroControlLink MODB_MCL1;
	MacroControlLink MODB_MCL2;

	MacroControlLink VALA_MCL1;
	MacroControlLink VALB_MCL1;
	MacroControlLink VALC_MCL1;
	MacroControlLink VALC_MCL2;

	// ========================== Main components

	ControlGroup OPM_Group;
	ControlGroup MST_Group;
	ControlGroup WFA_Group;
	ControlGroup WFB_Group;
	ControlGroup PERKA_Group;
	ControlGroup PERKB_Group;

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

	PitchAndPhaseControl WFA;
	ModelModulatedControl WFA_PWM;
	ModelModulatedControl WFA_Shaper;

	PitchAndPhaseControl WFB;
	ModelModulatedControl WFB_PWM;
	ModelModulatedControl WFB_Shaper;

	PitchAndPhaseControl PERKA;
	ModelModulatedControl PERKA_PWM;
	ModelModulatedControl PERKA_HPFREQ;
	ModelModulatedControl PERKA_AMP;

	PitchAndPhaseControl PERKB;
	ModelModulatedControl PERKB_PWM;
	ModelModulatedControl PERKB_HPFREQ;
	ModelModulatedControl PERKB_AMP;
	
	ModelModulatedControl OSC_WF_MIX = ModelModulatedControl();
	ModelModulatedControl OSC_WF_FLT = ModelModulatedControl();
	

	void DeployModel();

	BassZeroSynthModel():SynthDeviceModel()
	{ };

};