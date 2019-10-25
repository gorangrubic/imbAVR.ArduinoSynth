/*
  ==============================================================================

    imbStringBuilder.h
    Created: 23 Oct 2019 8:42:54am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "imbStringBuilderFormatBase.h"
#include "imbStringBuilderState.h"

class imbStringBuilder: 
    public imbStringBuilderState,
    public imbStringBuilderFormatBase {
    
    
    //int tabLevel = 0;
    //int blockLevel = 0;
 
    //std::shared_ptr<imbStringBuilderFormatBase> format; 
    
    
    
    public:
    

    
    imbStringBuilder(imbStringBuilderFormatBase * _format):format(_format)
    {
        
    }
    
}