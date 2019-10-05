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



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PERKEditor  : public Component,
                    public Slider::Listener,
                    public ComboBox::Listener
{
public:
    //==============================================================================
    PERKEditor ();
    ~PERKEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> AttackTime;
    std::unique_ptr<Label> label;
    std::unique_ptr<Slider> DecayTime;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Slider> ReleaseTime;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> ModAmt;
    std::unique_ptr<ComboBox> ModSrc;
    std::unique_ptr<Slider> Val;
    std::unique_ptr<Label> Title2;
    std::unique_ptr<Slider> ModAmt2;
    std::unique_ptr<ComboBox> ModSrc2;
    std::unique_ptr<Slider> Val2;
    std::unique_ptr<Label> Title3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PERKEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

