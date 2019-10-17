#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#include "../Source/Utility/ccTranslationMap.h"

/// <summary>
/// Utility data describe VSTi variables like: 
/// - currently/last selected MIDI input and outputs
/// - 
/// - MIDI CC in/synth/out mapping
/// - that are not part of VSTi global configuration
/// </summary>
class imbSynthStateUtilityData
{
public:

	std::string inputToHardwareCCMapFilename{ "" };
	std::string hardwareToOutputCCMapFilename{ "" };

	std::string lastPresetFilePath{ "" };


	imbSynthStateUtilityData();
	~imbSynthStateUtilityData();
};

