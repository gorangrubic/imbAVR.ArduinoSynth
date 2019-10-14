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




class ControlStateDisplayModel {

public:

	juce::String parameterID{ "" };
	juce::String parameterGroup{ "" };
	
	juce::String parameterValue{ "" };

	unsigned int parameterCC{ 0 };
	unsigned int parameterCCIn{ 0 };
	unsigned int parameterCCOut{ 0 };

	void SetParameter(imbControlParameter * parameter);

	ControlStateDisplayModel();
};