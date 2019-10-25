/*
  ==============================================================================

    GUIStateManager.h
    Created: 24 Oct 2019 1:41:54pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
/* Manages what property & GUI component is in focus */
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataObjectProperty.h"

class GUIStateManager {
 
    public:
    
		dataElementBase dataInFocus;
		Component componentInFocus;
    
};