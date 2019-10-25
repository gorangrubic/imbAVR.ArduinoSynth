/*
  ==============================================================================

    imbStringBuilderFormatRule.h
    Created: 24 Oct 2019 11:54:30am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "imbStringBuilderState.h"

class imbStringBuilderFormatRule {
 
    public:
    
    virtual std::string GetPrefix(imbStringBuilderState &state)=0;
    virtual std::string GetSuffix(imbStringBuilderState &state)=0;
    
    virtual std::string GetFormatted(std::string content, imbStringBuilderState &state)=0;
    
};