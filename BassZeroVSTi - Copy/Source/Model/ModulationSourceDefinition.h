/*
  ==============================================================================

    ModulationSourceDefinition.h
    Created: 4 Oct 2019 8:38:19pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


enum ModulationSourceType {
    ADSR=1,
    LFO,
    ENV,
    CC,
    NOTE
}

class ModulationSourceDefinition {
 
    public:
    
        String ShortName;
        
}