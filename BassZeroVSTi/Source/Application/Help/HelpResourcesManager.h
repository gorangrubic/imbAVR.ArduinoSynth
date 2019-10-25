/*
  ==============================================================================

    HelpResourcesManager.h
    Created: 12 Oct 2019 3:39:54am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Application/Files/SynthApplicationFolder.h"
#include "RandomTip.h"

class HelpResourcesManager {

public :

	SynthApplicationFolder * folder;
	
	HelpResourcesManager(SynthApplicationFolder&_folder)
	{
		folder = &_folder;
	}

};