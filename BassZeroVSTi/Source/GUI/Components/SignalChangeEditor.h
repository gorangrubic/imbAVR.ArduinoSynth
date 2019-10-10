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
#include "../Source/Data/imbSynthStateData.h"
#include "../Components/imbSynthGUIComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SignalChangeEditor  : public Component,
                            public imbSynthGUIComponent,
                            public ComboBox::Listener,
                            public Slider::Listener,
                            public Button::Listener
{
public:
    //==============================================================================
    SignalChangeEditor (imbSynthStateData * synthState, String nameSufix);
    ~SignalChangeEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<ComboBox> Mode;
    std::unique_ptr<Label> label;
    std::unique_ptr<Slider> Rate;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Slider> Period;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> Change;
    std::unique_ptr<Label> label4;
    std::unique_ptr<ToggleButton> toggle_Enabled;
    std::unique_ptr<ToggleButton> toggle_Sync;
    std::unique_ptr<ToggleButton> toggle_Chaos;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SignalChangeEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

