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
                             public imbSynthGUIComponent,
                             public Button::Listener,
                             public ComboBox::Listener
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
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<ToggleButton> toggle_PWMMode;
    std::unique_ptr<ToggleButton> toggle_PitchRelative;
    std::unique_ptr<Label> label;
    std::unique_ptr<SignalChangeEditor> PitchModulation;
    std::unique_ptr<PatternEditor8bit> PulsePattern;
    std::unique_ptr<SignalChangeEditor> PhaseModulation;
    std::unique_ptr<ToggleButton> toggle_DoublePrescalar;
    std::unique_ptr<SignalChangeEditor> PWMModulation;
    std::unique_ptr<ToggleButton> toggle_Enabled;
    std::unique_ptr<PatternEditor8bit> ModBytePattern;
    std::unique_ptr<Label> label3;
    std::unique_ptr<ToggleButton> toggle_Sync;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Label> label5;
    std::unique_ptr<ComboBox> PitchUnit;
    std::unique_ptr<Label> label6;
    std::unique_ptr<Label> label7;
    std::unique_ptr<Label> label_SignalName;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SignalControlEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

