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

#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OPMEditor  : public Component,
                   public imbSynthGUIComponent
{
public:
    //==============================================================================
    OPMEditor (imbSynthStateData * synthState, String nameSufix);
    ~OPMEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<OPMToSignalChangeEditor> MODA_MCL1;
    std::unique_ptr<OPMToSignalChangeEditor> MODB_MCL1;
    std::unique_ptr<OPMToSignalChangeEditor> VALC_MCL1;
    std::unique_ptr<OPMToSignalChangeEditor> VALC_MCL2;
    std::unique_ptr<Label> labelMODA;
    std::unique_ptr<OPMToSignalChangeEditor> MODA_MCL2;
    std::unique_ptr<Label> labelMODB;
    std::unique_ptr<OPMToSignalChangeEditor> MODB_MCL2;
    std::unique_ptr<Label> labelMODA3;
    std::unique_ptr<Label> labelMODA4;
    std::unique_ptr<OPMToSignalChangeEditor> VALA_MCL1;
    std::unique_ptr<OPMToSignalChangeEditor> VALB_MCL1;
    std::unique_ptr<Label> LabelVALC;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OPMEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

