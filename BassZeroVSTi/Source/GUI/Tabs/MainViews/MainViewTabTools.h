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
#include "../Source/GUI/Components/imbSynthGUIComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainViewTabTools  : public Component,
                          public imbSynthGUIComponent,
                          public Button::Listener,
                          public Slider::Listener
{
public:
    //==============================================================================
    MainViewTabTools (imbSynthStateData * synthState, String nameSufix);
    ~MainViewTabTools();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> group_IO;
    std::unique_ptr<GroupComponent> group_MIDITEST;
    std::unique_ptr<TextButton> Read;
    std::unique_ptr<ToggleButton> toggleButton;
    std::unique_ptr<Slider> slider_noteDuration;
    std::unique_ptr<Label> label;
    std::unique_ptr<Slider> slider_noteDuration2;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Slider> slider_bpm;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> Pitch;
    std::unique_ptr<Label> label5;
    std::unique_ptr<Slider> Velocity;
    std::unique_ptr<Label> label4;
    std::unique_ptr<TextButton> Write;
    std::unique_ptr<TextButton> SaveFile;
    std::unique_ptr<TextButton> ReadFile;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainViewTabTools)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

