/*
  ==============================================================================

    BassZeroApplication.h
    Created: 12 Oct 2019 3:40:20am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once


#include "../JuceLibraryCode/JuceHeader.h"
#include "Application\SynthApplicationBase.h"
#include "Control\imbSynthAudioProcessor.h"
#include "Model\SynthDeviceModel.h"
#include "BassZeroSynthModel.h"
#include "../Source/Application/imbSynthStateData.h"
#include "BassZeroApplication.h"
//#include "BassZeroVstiAudioProcessor.h"


class BassZeroApplication: public SynthApplicationBase {

	

public :

	std::shared_ptr<BassZeroSynthModel> bassZeroModel;
//	std::shared_ptr<BassZeroVstiAudioProcessor> bassZeroProcessor;

	BassZeroApplication(BassZeroSynthModel * _synthModel, imbSynthAudioProcessor * _synthProcessor, imbSynthStateData * _synthState)
		:SynthApplicationBase(_synthModel, _synthProcessor, _synthState),
		bassZeroModel(_synthModel)//, bassZeroProcessor(_synthProcessor)
	{

	};
};