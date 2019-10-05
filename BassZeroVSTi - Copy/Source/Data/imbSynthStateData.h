#pragma once

#include "imbSynthGeneralConfiguration.h"
#include "imbSynthStateUtilityData.h"
#include "imbSynthStatePresetLibrary.h"
#include "imbSynthPresetDefinition.h"
#include "SynthDeviceModel.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Control/ParameterController.h"

class imbSynthStateData
{
    
public:


// ======================== ENVIRONMENT DATA

    SynthDeviceModel deviceModel;



// ======================== STATE DATA

	juce::AudioProcessorValueTreeState parameters;

	ParameterController parameterController;

	imbSynthPresetDefinition currentPreset;

	imbSynthStatePresetLibrary presetLibrary;

	imbSynthGeneralConfiguration configuration;
	imbSynthStateUtilityData utilityData;


	imbSynthStateData();
	~imbSynthStateData();
};

