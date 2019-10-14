/*
  ==============================================================================

    SynthApplicationCommandManager.h
    Created: 14 Oct 2019 7:40:54pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"

class SynthApplicationCommandManager  {
 
    public:

		ApplicationCommandTarget* mainCommandTarget;



		SynthApplicationCommandManager(ApplicationCommandTarget* _mainCommandTarget)
			: mainCommandTarget{_mainCommandTarget}
		{

		};

    
};