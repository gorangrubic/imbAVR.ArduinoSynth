#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "../Source/Application/Settings/imbSynthGeneralConfiguration.h"
#include "../Source/Application/Settings/imbSynthStateUtilityData.h"


#include "../Source/Application/GeneralDefinitions.h"


#include "../Source/Application/Data/ccTranslationMap.h"

#include "../Source/Data/Structures/SharedPointerVector.h"
#include "../Source/Data/Structures/SharedPointerMap.h"

//#include "../GUI/Global/CommandBufferDisplay.h"
//#include "../GUI/Global/ControlStateDisplay.h"
//#include "../GUI/Global/SynthStateDisplay.h"

//#include "../GUI/Global/CommandBufferDisplayModel.h"
//#include "../GUI/Global/ControlStateDisplayModel.h"
//#include "../GUI/Global/SynthStateDisplayModel.h"
//
//#include "../GUI/General/PresetFileBrowserModel.h"

#include "../Model/SynthDeviceModel.h"
#include "../Source/Application/SynthApplicationEnvironment.h"
#include "../Source/Data/Binding/dataInterfaceManager.h"

#include "../Source/Data/Structures/imbValueSet.h"
#include <vector>

#include "../Source/Application/Components/imbTimeScheduler.h"

#include "../Source/Model/Communication/ParameterMap.h"
#include "../Source/Model/Communication/ParameterMapEntry.h"
#include "../Source/Model/Communication/ParameterValueMessage.h"

#include "../Source/Model/imbControlParameterEnumerations.h"


class imbSynthStateData
{
    
public:

//

	//IOManager


	// ==================== timers

	imbTimeScheduler time_scheduler;
	
// ======================== Display models

	//PresetFileBrowserModel libraryFileBrowserModel;


// ======================== ENVIRONMENT DATA
	std::unique_ptr<SynthApplicationEnvironment> environment;

	dataInterfaceManager UIManager;
	

	//std::shared_ptr<SynthApplicationFolderCollection> folders;

	//IOPorts ioPorts;


	imbValueSet parameterLastValuesSent = imbValueSet();
	ParameterMap parameterMapCC = ParameterMap(imbControlParameterMessageType::ccMIDI);
	ParameterMap parameterMapSysEx = ParameterMap(imbControlParameterMessageType::sysExMsg);
	std::shared_ptr<SynthDeviceModel> model;

	ParameterMap * GetParameterMap(dataObjectPropertyBase * property);
	ParameterMapEntry * GetParameterMapEntry(dataObjectPropertyBase * property);

	/// <summary>
	/// Prepares parameter value messages.
	/// </summary>
	/// <param name="parClass">Class of parameters to process</param>
	/// <param name="forceAll">if set to <c>true</c> it will prepare all parameters, otherwise only ones having different value than saved in [parameterLastValuesSent].</param>
	/// <returns></returns>
	std::vector<ParametarValueMessage> prepareMessages(parameterClass parClass, bool forceAll);

	MidiMessage ConvertToMidi(ParametarValueMessage pvm);
	std::vector<MidiMessage> ConvertToMidi(std::vector<ParametarValueMessage> &pvm);
	

	ParametarValueMessage ConvertFromMidi(MidiMessage m);
	std::vector<ParametarValueMessage> ConvertFromMidi(std::vector<MidiMessage> m);



// ======================== STATE DATA

	juce::AudioProcessorValueTreeState * parameters;

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
		HardwareToOutputMap(new ccTranslationMap())
		//bufferDisplayModel(new CommandBufferDisplayModel()),
		//controlDisplayModel(new ControlStateDisplayModel(InputToHardwareMap, HardwareToOutputMap,environment)),
		//stateDisplayModel( new SynthStateDisplayModel() ),
		//libraryFileBrowserModel{ PresetFileBrowserModel() }
	{

	}

	~imbSynthStateData();
};

