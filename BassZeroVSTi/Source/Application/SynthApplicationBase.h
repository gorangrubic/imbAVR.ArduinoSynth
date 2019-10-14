/*
  ==============================================================================

    SynthApplicationBase.h
    Created: 12 Oct 2019 3:39:01am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once


#include "../../JuceLibraryCode/JuceHeader.h"


#include "CommandIDs.h"
#include "../Model/SynthDeviceModel.h"
#include "../Control/imbSynthAudioProcessor.h"
#include "../Data/imbSynthStateData.h"


class SynthApplicationBase {

public :

	std::shared_ptr<SynthDeviceModel> synthModel;
	std::shared_ptr<imbSynthAudioProcessor> synthProcessor;
	std::shared_ptr<imbSynthStateData> synthState;

	
	bool perform(CommandIDs commandID);
	

	SynthApplicationBase(SynthDeviceModel* _synthModel, imbSynthAudioProcessor * _synthProcessor, imbSynthStateData * _synthState):
		synthModel(_synthModel),
		synthProcessor(_synthProcessor),
		synthState(_synthState)
	{

	};
};