/*
  ==============================================================================

    ccTranslationEntry.h
    Created: 15 Oct 2019 3:59:09am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class ccTranslationEntry {
 
    
    public:
    
        unsigned int TargetID;
        unsigned int OutputID;
        
        ccTranslationEntry();
        
        ccTranslationEntry(unsigned int _target, unsigned int _output):
			TargetID{ _target },
			OutputID{ _output }
        {};
};