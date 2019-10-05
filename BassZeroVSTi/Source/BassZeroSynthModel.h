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


class BassZeroSynthModel : SynthDeviceModel {

public:

	ModulationFunctionADSR ADSR_A;
	ModulationFunctionADSR ADSR_B;
	
	ModulationFunctionENV ENV_A;
	ModulationFunctionENV ENV_B;
	ModulationFunctionENV ENV_C;

	ModulationFunctionLFO LFO_A;
	ModulationFunctionLFO LFO_B;
	ModulationFunctionLFO LFO_C;
	ModulationFunctionLFO LFO_D;

	ModulationSourceMacroControl CTRL_A;
	ModulationSourceMacroControl CTRL_B;
	ModulationSourceMacroControl CTRL_C;

	ModulationSourceMIDI VEL;
	

	void DeployModel(imbSynthAudioProcessor * synthProcessor) override;

	BassZeroSynthModel();

};