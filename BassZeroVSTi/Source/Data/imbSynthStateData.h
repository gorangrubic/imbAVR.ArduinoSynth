#pragma once

#include "imbSynthGeneralConfiguration.h"
#include "imbSynthStateUtilityData.h"
#include "imbSynthStatePresetLibrary.h"
#include "imbSynthPresetDefinition.h"

#include "../JuceLibraryCode/JuceHeader.h"
#include "../Control/ParameterController.h"

#include "../Source/Utility/ccTranslationMap.h"
#include "../Source/Model/Core/SharedPointerVector.h"

//#include "../GUI/Global/CommandBufferDisplay.h"
//#include "../GUI/Global/ControlStateDisplay.h"
//#include "../GUI/Global/SynthStateDisplay.h"

#include "../GUI/Global/CommandBufferDisplayModel.h"
#include "../GUI/Global/ControlStateDisplayModel.h"
#include "../GUI/Global/SynthStateDisplayModel.h"

#include "../GUI/General/PresetFileBrowserModel.h"

#include "../Model/SynthDeviceModel.h"



class imbSynthStateData
{
    
public:

// ======================== Display models

    std::unique_ptr<CommandBufferDisplayModel> bufferDisplayModel;

	//std::shared_ptr<ControlStateDisplay> controlStateDisplay{ nullptr };

	std::unique_ptr<ControlStateDisplayModel> controlDisplayModel;
    
	
	//std::shared_ptr<SynthStateDisplay> synthStateDisplay{ nullptr };
	std::unique_ptr<SynthStateDisplayModel> stateDisplayModel;
    
	PresetFileBrowserModel libraryFileBrowserModel;


// ======================== ENVIRONMENT DATA

	std::shared_ptr<SynthDeviceModel> model;

// ======================== STATE DATA

	juce::AudioProcessorValueTreeState * parameters;

	SharedPointerVector<imbControlParameter> Parameters;


	//ParameterController parameterController;

	imbSynthPresetDefinition currentPreset;

	imbSynthPresetDefinition presetSelected;
	imbSynthStatePresetLibrary presetLibrary;

	imbSynthGeneralConfiguration configuration;
	imbSynthStateUtilityData utilityData;

	
	std::unique_ptr<ccTranslationMap> InputToHardwareMap;
	std::unique_ptr<ccTranslationMap> HardwareToOutputMap;

	std::unique_ptr<FileChooser> fc;


	ccTranslationMap * GetCCMapByRole(ccTranslationMapRole mapRole);

	ccTranslationMapRole CheckCCMapRole(ccTranslationMapRole mapRole = ccTranslationMapRole::unknown, std::string msg_ins="");

	void LoadCCMap(std::string filepath="", ccTranslationMapRole mapRole= ccTranslationMapRole::unknown);

	void SaveCCMap(std::string filepath = "", ccTranslationMapRole mapRole = ccTranslationMapRole::unknown);

	
	juce::String inFocusParameterID{ "" };

	
	void Initiated();

	void SetParameterInFocus(imbControlParameter * parameter);


	imbSynthStateData(SynthDeviceModel * _model, juce::AudioProcessorValueTreeState * _parameters) :
		model{ _model },
		parameters{ _parameters },
		InputToHardwareMap(new ccTranslationMap()),
		HardwareToOutputMap(new ccTranslationMap()),
		bufferDisplayModel(new CommandBufferDisplayModel()),
		controlDisplayModel(new ControlStateDisplayModel(InputToHardwareMap, HardwareToOutputMap)),
		stateDisplayModel( new SynthStateDisplayModel() ),
		libraryFileBrowserModel{ PresetFileBrowserModel() }
	{

	}

	~imbSynthStateData();
};

