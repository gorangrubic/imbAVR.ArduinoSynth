#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "imbSynthGeneralConfiguration.h"
#include "imbSynthStateUtilityData.h"
#include "imbSynthStatePresetLibrary.h"
#include "imbSynthPresetDefinition.h"
#include "../Source/Application/GeneralDefinitions.h"


//#include "../Control/ParameterController.h"

#include "../Source/Utility/ccTranslationMap.h"
#include "../Source/Data/Structures/SharedPointerVector.h"
#include "../Source/Data/Structures/SharedPointerMap.h"

//#include "../GUI/Global/CommandBufferDisplay.h"
//#include "../GUI/Global/ControlStateDisplay.h"
//#include "../GUI/Global/SynthStateDisplay.h"

#include "../GUI/Global/CommandBufferDisplayModel.h"
#include "../GUI/Global/ControlStateDisplayModel.h"
#include "../GUI/Global/SynthStateDisplayModel.h"

#include "../GUI/General/PresetFileBrowserModel.h"

#include "../Model/SynthDeviceModel.h"
#include "../Source/Application/SynthApplicationEnvironment.h"
#include "../Source/Data/Binding/dataInterfaceManager.h"



class imbSynthStateData
{
    
public:

//

	//IOManager

	
// ======================== Display models


    
	PresetFileBrowserModel libraryFileBrowserModel;


// ======================== ENVIRONMENT DATA
	std::unique_ptr<SynthApplicationEnvironment> environment;

	dataInterfaceManager UIManager;

	//std::shared_ptr<SynthApplicationFolderCollection> folders;

	//IOPorts ioPorts;

	std::shared_ptr<SynthDeviceModel> model;

// ======================== STATE DATA

	juce::AudioProcessorValueTreeState * parameters;

	//SharedPointerVector<imbControlParameter> Parameters;

	

	//SharedPointerMap<std::string, imbControlParameter> ParametersByIDPath;

	//ParameterController parameterController;

	imbSynthPresetDefinition currentPreset;

	imbSynthPresetDefinition presetSelected;
	imbSynthStatePresetLibrary presetLibrary;

	imbSynthGeneralConfiguration configuration;

	imbSynthStateUtilityData utilityData;

	
	std::unique_ptr<ccTranslationMap> InputToHardwareMap;
	std::unique_ptr<ccTranslationMap> HardwareToOutputMap;

	std::unique_ptr<FileChooser> fc;

	//void LoadSettings(bool loadAs);
	//void SaveSettings(bool saveAs);

	ccTranslationMap * GetCCMapByRole(ccTranslationMapRole mapRole);

	ccTranslationMapRole CheckCCMapRole(ccTranslationMapRole mapRole = ccTranslationMapRole::unknown, std::string msg_ins="");

	void LoadCCMap(std::string filepath="", ccTranslationMapRole mapRole= ccTranslationMapRole::unknown);

	void SaveCCMap(std::string filepath = "", ccTranslationMapRole mapRole = ccTranslationMapRole::unknown);


	
	void Initiated();




	imbSynthStateData(SynthDeviceModel * _model, juce::AudioProcessorValueTreeState * _parameters) :
		model{ _model },
		parameters{ _parameters },
		environment(new SynthApplicationEnvironment()),
		configuration(environment->ioPorts),
		InputToHardwareMap(new ccTranslationMap()),
		HardwareToOutputMap(new ccTranslationMap()),
		//bufferDisplayModel(new CommandBufferDisplayModel()),
		//controlDisplayModel(new ControlStateDisplayModel(InputToHardwareMap, HardwareToOutputMap,environment)),
		//stateDisplayModel( new SynthStateDisplayModel() ),
		libraryFileBrowserModel{ PresetFileBrowserModel() }
	{

	}

	~imbSynthStateData();
};

