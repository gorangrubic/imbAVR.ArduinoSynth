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
#include "../Source/GUI/Components/imbSynthGUIComponent.h"
//[/Headers]

#include "GUI/Global/ControlStateDisplay.h"
#include "GUI/Global/SynthStateDisplay.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class BassZeroGUI  : public Component,
                     public imbSynthGUIComponent
{
public:
    //==============================================================================
    BassZeroGUI (imbSynthStateData * synthState);
    ~BassZeroGUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* background2_jpg;
    static const int background2_jpgSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TabbedComponent> tabbedComponent;
    std::unique_ptr<ControlStateDisplay> controlStateDisplay;
    std::unique_ptr<SynthStateDisplay> synthStatusDisplay;
    Image cachedImage_background2_jpg_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BassZeroGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

