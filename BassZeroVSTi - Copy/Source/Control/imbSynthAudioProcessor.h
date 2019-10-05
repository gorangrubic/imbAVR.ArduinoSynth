#pragma once


#include "../JuceLibraryCode/JuceHeader.h"
#include "ParameterController.h"



class imbSynthAudioProcessor 
	: public AudioProcessor, 
	public AudioProcessorListener
{
public:

	ParameterController parameterController;

	juce::AudioProcessorValueTreeState parameters;
	

	AudioProcessorValueTreeState::ParameterLayout CreateParameterLayout();

	imbSynthAudioProcessor();
	~imbSynthAudioProcessor();
};
