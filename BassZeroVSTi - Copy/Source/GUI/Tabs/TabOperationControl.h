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
//[/Headers]

#include "Components/OPMToSignalChangeEditor.h"
#include "Components/OPMToSignalChangeEditor.h"
#include "Components/OPMToSignalChangeEditor.h"
#include "Components/OPMToSignalChangeEditor.h"
#include "Components/OPMToSignalChangeEditor.h"
#include "Components/OPMToSignalChangeEditor.h"
#include "Components/OPMToSignalChangeEditor.h"
#include "Components/OPMToSignalChangeEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabOperationControl  : public Component,
                             public imbSynthGUIComponent
{
public:
    //==============================================================================
    TabOperationControl (imbSynthStateData * synthState, String nameSufix);
    ~TabOperationControl();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<OPMToSignalChangeEditor> modA1;
    std::unique_ptr<OPMToSignalChangeEditor> modB1;
    std::unique_ptr<OPMToSignalChangeEditor> valC1;
    std::unique_ptr<OPMToSignalChangeEditor> valC2;
    std::unique_ptr<Label> labelMODA;
    std::unique_ptr<OPMToSignalChangeEditor> modA2;
    std::unique_ptr<Label> labelMODB;
    std::unique_ptr<OPMToSignalChangeEditor> modB2;
    std::unique_ptr<Label> labelMODA3;
    std::unique_ptr<Label> labelMODA4;
    std::unique_ptr<OPMToSignalChangeEditor> valA1;
    std::unique_ptr<OPMToSignalChangeEditor> valB1;
    std::unique_ptr<Label> LabelVALC;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabOperationControl)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

