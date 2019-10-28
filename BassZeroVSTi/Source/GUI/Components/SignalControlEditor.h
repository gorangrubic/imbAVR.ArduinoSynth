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
#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../Source/Application/imbSynthStateData.h"
#include "../Components/imbSynthGUIComponent.h"
#include "../Source/Model/Components/OscilatorBase.h"
//[/Headers]

#include "SignalChangeEditor.h"
#include "../General/PatternEditor8bit.h"
#include "SignalChangeEditor.h"
#include "SignalChangeEditor.h"
#include "../General/PatternEditor8bit.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SignalControlEditor  : public Component,
                             public imbSynthGUIComponent
{
public:
    //==============================================================================
    SignalControlEditor (imbSynthStateData * synthState, String nameSufix);
    ~SignalControlEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	std::shared_ptr<OscilatorBase> modelComponent;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<SignalChangeEditor> PitchModulation;
    std::unique_ptr<PatternEditor8bit> PulsePattern;
    std::unique_ptr<SignalChangeEditor> PhaseModulation;
    std::unique_ptr<SignalChangeEditor> PWMModulation;
    std::unique_ptr<PatternEditor8bit> ModBytePattern;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Label> label5;
    std::unique_ptr<Label> label6;
    std::unique_ptr<Label> label_SignalName;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SignalControlEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

