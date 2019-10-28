#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#include "../Source/Data/Model/dataObject.h"

/// <summary>
/// Utility data describe VSTi variables like: 
/// - currently/last selected MIDI input and outputs
/// - 
/// - MIDI CC in/synth/out mapping
/// - that are not part of VSTi global configuration
/// </summary>
class imbSynthStateUtilityData:public dataObject
{
public:

	dataStringProperty inputCCMapFilepath = dataStringProperty("inputCCMapFilepath", "", "Input CC map", "Filepath of last preset loaded", "", "", parameterClass::configuration);
	dataStringProperty outputCCMapFilepath = dataStringProperty("outputCCMapFilepath", "", "Output CC map", "Filepath of last preset loaded", "", "", parameterClass::configuration);
	dataStringProperty LastPresetFilepath = dataStringProperty("LastPresetFilePath", "", "Last preset", "Filepath of last preset loaded", "", "", parameterClass::configuration);

	imbSynthStateUtilityData(std::string _name, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "") :dataObject(_name, _label, _description, _unit, _helpUrl) {
		Add(&inputCCMapFilepath);
		Add(&outputCCMapFilepath);
		Add(&LastPresetFilepath);

	}
	~imbSynthStateUtilityData();
};

