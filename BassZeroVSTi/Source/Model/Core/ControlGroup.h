/*
  ==============================================================================

    ControlGroup.h
    Created: 15 Oct 2019 2:54:37am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ModelComponentDescription.h"

class ControlGroup : public ModelComponentDescription {
    
 
    public:
    
        ControlGroup(std::string _namePrefix="", std::string _shortName="", std::string _longName=""):ModelComponentDescription(_namePrefix, _shortName,_longName) { }
    
};