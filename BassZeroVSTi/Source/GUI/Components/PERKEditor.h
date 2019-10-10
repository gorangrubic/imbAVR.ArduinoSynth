/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/imbSynthStateData.h"
#include "../Components/imbSynthGUIComponent.h"
//[/Headers]

#include "SourceMixerComponent.h"
#include "OSCEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PERKEditor  : public Component,
                    public imbSynthGUIComponent
{
public:
    //==============================================================================
    PERKEditor (imbSynthStateData * synthState, String nameSufix);
    ~PERKEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void ConstructParameterLayout(std::vector<std::unique_ptr<AudioParameterInt>> params);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> Title4;
    std::unique_ptr<SourceMixerComponent> Shaper;
    std::unique_ptr<OSCEditor> OSC;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PERKEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

