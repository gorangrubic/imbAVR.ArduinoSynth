#pragma once


#include "../JuceLibraryCode/JuceHeader.h"
//#include "ParameterController.h"
//#include "../Source/Model/SynthDeviceModel.h"
#include "../Model/SynthDeviceModel.h"
#include "../Source/Application/Components/IOManager.h"
#include "../Source/Data/imbSynthStateData.h"

class imbSynthAudioProcessor 
		: public AudioProcessor, 
			public AudioProcessorListener
{

public:

	UndoManager undoManager;

	imbSynthStateData synthState;
	SynthDeviceModel * model;

	IOManager ioManager;


//	ParameterController parameterController;

	juce::AudioProcessorValueTreeState parameters;
//	juce::Identifier rootIdentifier;
	
	void DeployModel();


	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(AudioBuffer<float>&, MidiBuffer&) override;

	//==============================================================================
	AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const String getProgramName(int index) override;
	void changeProgramName(int index, const String& newName) override;

	//==============================================================================
	void getStateInformation(MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

	
//	AudioProcessorValueTreeState::ParameterLayout CreateParameterLayout();

	void audioProcessorParameterChanged(AudioProcessor* processor,
		int parameterIndex,
		float newValue);

	void audioProcessorParameterChangeGestureEnd(AudioProcessor* processor,
		int parameterIndex);

	void audioProcessorChanged(AudioProcessor* processor);

	imbSynthAudioProcessor(SynthDeviceModel *_model) :
		AudioProcessor(BusesProperties()),
		model{ _model },
		undoManager(),
		//rootIdentifier(_model),
		parameters(*this, &this->undoManager),
		synthState(model, &parameters)
		//parameters(*this, &this->undoManager, name, CreateParameterLayout())
	{
		//DeployModel();

	
	};
	
	~imbSynthAudioProcessor();
};
