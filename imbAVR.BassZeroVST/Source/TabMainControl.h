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
class TabMainControl  : public Component,
                        public Button::Listener,
                        public Slider::Listener,
                        public ComboBox::Listener
{
public:
    //==============================================================================
    TabMainControl ();
    ~TabMainControl();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

    // Binary resources:
    static const char* basszero_background_jpg;
    static const int basszero_background_jpgSize;
    static const char* basszero_background_jpg2;
    static const int basszero_background_jpg2Size;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> group_Device;
    std::unique_ptr<GroupComponent> group_IO;
    std::unique_ptr<GroupComponent> group_MIDITEST;
    std::unique_ptr<TextButton> Send;
    std::unique_ptr<ToggleButton> toggleButton;
    std::unique_ptr<Slider> slider_noteDuration;
    std::unique_ptr<Label> label;
    std::unique_ptr<Slider> slider_noteDuration2;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Slider> slider_bpm;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> slider_noteDuration3;
    std::unique_ptr<Label> label5;
    std::unique_ptr<Slider> slider_noteDuration4;
    std::unique_ptr<Label> label4;
    std::unique_ptr<TextButton> Send2;
    std::unique_ptr<TextButton> Send3;
    std::unique_ptr<TextButton> Send4;
    std::unique_ptr<Label> label6;
    std::unique_ptr<GroupComponent> group_MIDI_inputs;
    std::unique_ptr<ComboBox> comboBox_midiin1;
    std::unique_ptr<ComboBox> comboBox_midiin2;
    std::unique_ptr<ComboBox> comboBox_midiin3;
    std::unique_ptr<ComboBox> comboBox_midiin4;
    std::unique_ptr<ToggleButton> toggleButton_enableMIDIIN;
    std::unique_ptr<ComboBox> comboBox_midiin6;
    std::unique_ptr<TextButton> Send5;
    std::unique_ptr<ComboBox> comboBox_midiin5;
    std::unique_ptr<Label> label7;
    std::unique_ptr<ComboBox> comboBox_midiin7;
    std::unique_ptr<TextButton> Send6;
    std::unique_ptr<ToggleButton> toggleButton_enableMIDIIN2;
    Image cachedImage_basszero_background_jpg2_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabMainControl)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

