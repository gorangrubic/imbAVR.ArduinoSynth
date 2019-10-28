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
#include "imbSynthAudioProcessor.h"
#include "imbSynthStateData.h"
#include "../Data/Structures/SharedPointerVector.h"

#include "../Source/Utility/imbGeneralTools.h"


class SynthApplicationBase {

public :

	std::shared_ptr<SynthDeviceModel> synthModel;
	std::shared_ptr<imbSynthAudioProcessor> synthProcessor;
	std::shared_ptr<imbSynthStateData> synthState;

	
	
	
	
	bool perform(CommandIDs commandID);
	
	/*Saves screenshot of current processor editor */
	std::string SaveScreenshot(std::string filename = "", bool showMessage=true);

	SynthApplicationBase(SynthDeviceModel* _synthModel, imbSynthAudioProcessor * _synthProcessor, imbSynthStateData * _synthState):
		synthModel(_synthModel),
		synthProcessor(_synthProcessor),
		synthState(_synthState)
	{
		
	};
};