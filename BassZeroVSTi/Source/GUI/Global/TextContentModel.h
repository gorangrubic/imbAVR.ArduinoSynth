/*
  ==============================================================================

    TextContentModel.h
    Created: 15 Oct 2019 2:01:21am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class TextContentModel {
 
    public:
    
        juce::String text;
        
        TextContentModel(juce::String _text):text{_text} {
        }
};