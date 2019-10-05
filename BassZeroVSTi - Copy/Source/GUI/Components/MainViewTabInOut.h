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



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainViewTabInOut  : public Component,
                          public imbSynthGUIComponent,
                          public ComboBox::Listener,
                          public Button::Listener
{
public:
    //==============================================================================
    MainViewTabInOut (imbSynthStateData * synthState, String nameSufix);
    ~MainViewTabInOut();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> group_Device;
    std::unique_ptr<Label> label6;
    std::unique_ptr<GroupComponent> group_MIDI_inputs;
    std::unique_ptr<ComboBox> midiIn_1;
    std::unique_ptr<ComboBox> midiIn_2;
    std::unique_ptr<ComboBox> midiIn_3;
    std::unique_ptr<ComboBox> midiIn_4;
    std::unique_ptr<ToggleButton> toggleButton_enableMIDIIN;
    std::unique_ptr<ComboBox> Device;
    std::unique_ptr<ComboBox> midiOut_1;
    std::unique_ptr<ComboBox> midiOut_2;
    std::unique_ptr<ToggleButton> toggleButton_enableMIDIIN2;
    std::unique_ptr<ToggleButton> toggleButton_MIDITrough;
    std::unique_ptr<ToggleButton> toggleButton_MIDITrough2;
    std::unique_ptr<ComboBox> midiOut_3;
    std::unique_ptr<ComboBox> midiOut_4;
    std::unique_ptr<TextButton> Send5;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainViewTabInOut)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

