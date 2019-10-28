/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Control\imbSynthAudioProcessor.h"
#include "Model\SynthDeviceModel.h"
#include "BassZeroSynthModel.h"
#include "../Source/Application/imbSynthStateData.h"
#include "BassZeroApplication.h"

//==============================================================================
/**
*/
class BassZeroVstiAudioProcessor  : public imbSynthAudioProcessor
{
public:

	BassZeroApplication bassZeroApplication;
	BassZeroSynthModel bassZeroModel;
	
	

    //==============================================================================
	BassZeroVstiAudioProcessor() :
		bassZeroModel(JucePlugin_VersionString),
		imbSynthAudioProcessor(&bassZeroModel),
		
		bassZeroApplication(&bassZeroModel, this, &synthState)
	{


		this->bassZeroModel.PreDeployModel();
		this->bassZeroModel.Deploy();
		this->bassZeroModel.DeployModel();
		this->bassZeroModel.AfterDeployModel();
		this->bassZeroModel.ConstructParameters(parameters);

		synthState.Initiated();

		this->bassZeroModel.PrepareEnums(synthState.environment->enums);
		this->bassZeroModel.DeployEnums(synthState.environment->enums);

		this->Start();

	};
    ~BassZeroVstiAudioProcessor();

  

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BassZeroVstiAudioProcessor)
};
