#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "juce_audio_processors\utilities\juce_AudioParameterInt.h"
#include "juce_audio_processors\processors\juce_AudioProcessorParameterGroup.h";
#include "imbControlParameter.h"
#include "imbParameterGroupBase.h"

#include "imbSynthAudioProcessor.h"

class ParameterGroupWaveform : public imbParameterGroupBase
{

protected:

	juce::AudioProcessorParameterGroup CP_Group;

	imbControlParameter * CP_Pitch;
	imbControlParameter * CP_PWM;
	imbControlParameter * CP_Phase;
	
	imbSynthAudioProcessor * ParentProcessor;

	String GroupName;

public:
	ParameterGroupWaveform(imbSynthAudioProcessor * _ParentProcessor, String _groupName);

	~ParameterGroupWaveform();
};

