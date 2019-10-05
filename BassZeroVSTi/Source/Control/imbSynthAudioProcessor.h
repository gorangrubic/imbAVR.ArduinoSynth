#pragma once


#include "../JuceLibraryCode/JuceHeader.h"
#include "ParameterController.h"


class imbSynthAudioProcessor 
		: public AudioProcessor, 
			public AudioProcessorListener
{
public:

	UndoManager undoManager;

	SynthDeviceModel * model;

	ParameterController parameterController;

	juce::AudioProcessorValueTreeState parameters;
	

	AudioProcessorValueTreeState::ParameterLayout CreateParameterLayout();

	imbSynthAudioProcessor();
	~imbSynthAudioProcessor();
};
