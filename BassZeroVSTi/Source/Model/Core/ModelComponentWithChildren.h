/*
  ==============================================================================

    ModelComponentWithChildren.h
    Created: 8 Oct 2019 5:35:08am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Model/SynthDeviceModelComponentBase.h"

class ModelComponentWithChildren {
    
 
    public:
    
		void AddChild(SynthDeviceModelComponentBase* child);

		

		std::list<SynthDeviceModelComponentBase*> ChildComponents;

		ModelComponentWithChildren();
};