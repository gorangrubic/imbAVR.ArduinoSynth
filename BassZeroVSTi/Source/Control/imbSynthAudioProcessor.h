#pragma once


#include "../JuceLibraryCode/JuceHeader.h"
//#include "ParameterController.h"
//#include "../Source/Model/SynthDeviceModel.h"
#include "../Model/SynthDeviceModel.h"

class imbSynthAudioProcessor 
		: public AudioProcessor, 
			public AudioProcessorListener
{

public:

	UndoManager undoManager;

	SynthDeviceModel * model;

//	ParameterController parameterController;

	juce::AudioProcessorValueTreeState parameters;
	juce::Identifier rootIdentifier;
	
	void DeployModel();

//	AudioProcessorValueTreeState::ParameterLayout CreateParameterLayout();

	void audioProcessorParameterChanged(AudioProcessor* processor,
		int parameterIndex,
		float newValue);

	void audioProcessorParameterChangeGestureEnd(AudioProcessor* processor,
		int parameterIndex);

	void audioProcessorChanged(AudioProcessor* processor);

	imbSynthAudioProcessor(SynthDeviceModel *_model, String name) :AudioProcessor(BusesProperties()),
		model{ _model },
		undoManager(),
		rootIdentifier(name),
		parameters(*this, &this->undoManager)
		//parameters(*this, &this->undoManager, name, CreateParameterLayout())
	{
		//DeployModel();

	
	};
	
	~imbSynthAudioProcessor();
};
