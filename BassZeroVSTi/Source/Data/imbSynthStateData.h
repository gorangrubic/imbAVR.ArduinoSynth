#pragma once

#include "imbSynthGeneralConfiguration.h"
#include "imbSynthStateUtilityData.h"
#include "imbSynthStatePresetLibrary.h"
#include "imbSynthPresetDefinition.h"

#include "../JuceLibraryCode/JuceHeader.h"
#include "../Control/ParameterController.h"

#include "../GUI/Global/CommandBufferDisplayModel.h"
#include "../GUI/Global/ControlStateDisplayModel.h"
#include "../GUI/Global/SynthStateDisplayModel.h"

#include "../Model/SynthDeviceModel.h"

class imbSynthStateData
{
    
public:

// ======================== Display models

    CommandBufferDisplayModel bufferDisplayModel;
    ControlStateDisplayModel controlDisplayModel;
    SynthStateDisplayModel stateDisplayModel;


// ======================== ENVIRONMENT DATA

	SynthDeviceModel * model;

// ======================== STATE DATA

	juce::AudioProcessorValueTreeState * parameters;

	ParameterController parameterController;

	imbSynthPresetDefinition currentPreset;

	imbSynthStatePresetLibrary presetLibrary;

	imbSynthGeneralConfiguration configuration;
	imbSynthStateUtilityData utilityData;


	imbSynthStateData();
	~imbSynthStateData();
};

