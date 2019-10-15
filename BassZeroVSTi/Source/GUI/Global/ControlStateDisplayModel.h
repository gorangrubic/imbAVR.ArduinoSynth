/*
  ==============================================================================

    ControlStateDisplayModel.h
    Created: 3 Oct 2019 5:19:29am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Control/imbControlParameter.h"
#include "../Source/Control/imbControlParameterEnumerations.h"
#include "../Source/Utility/ccTranslationMap.h"



class ControlStateDisplayModel {

public:

	std::unique_ptr<ccTranslationMap> & InputToHardwareMap;
	std::unique_ptr<ccTranslationMap> & HardwareToOutputMap;

	//std::shared_ptr<imbControlParameter> parameter_ptr;
	imbControlParameter * parameter_ptr;
	juce::String parameterID{ "" };
	juce::String parameterGroup{ "" };
	
	juce::String parameterValue{ "" };

	unsigned int parameterCC{ 0 };
	unsigned int parameterCCIn{ 0 };
	unsigned int parameterCCOut{ 0 };

	bool isCCParameter = true;

	void UpdateParameter(juce::String value, juce::String ccIn, juce::String ccOut);

	void SetParameter(imbControlParameter * parameter);

	ControlStateDisplayModel(std::unique_ptr<ccTranslationMap> & inputToHardwareMap, std::unique_ptr<ccTranslationMap> & hardwareToOutputMap);
};