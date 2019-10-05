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

#include "SourceMixerComponent.h"
#include "SourceMixerComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabOperationControl  : public Component,
                             public Button::Listener,
                             public Slider::Listener,
                             public ComboBox::Listener
{
public:
    //==============================================================================
    TabOperationControl ();
    ~TabOperationControl();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<SourceMixerComponent> component_OPMA;
    std::unique_ptr<GroupComponent> group_OPMODES;
    std::unique_ptr<TextButton> textButton;
    std::unique_ptr<TextButton> textButton2;
    std::unique_ptr<TextButton> textButton4;
    std::unique_ptr<TextButton> textButton5;
    std::unique_ptr<TextButton> textButton6;
    std::unique_ptr<TextButton> textButton7;
    std::unique_ptr<TextButton> textButton8;
    std::unique_ptr<TextButton> textButton9;
    std::unique_ptr<Label> Title;
    std::unique_ptr<Label> Title2;
    std::unique_ptr<SourceMixerComponent> component_OPMB;
    std::unique_ptr<Slider> component_OPM_VAL_A;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Slider> component_OPM_VAL_B;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> component_OPM_VAL_C;
    std::unique_ptr<Label> label4;
    std::unique_ptr<TextEditor> textEditor;
    std::unique_ptr<TextEditor> textEditor2;
    std::unique_ptr<Label> label_OPM;
    std::unique_ptr<ComboBox> comboBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabOperationControl)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

