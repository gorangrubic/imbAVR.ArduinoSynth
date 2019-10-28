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
#include "../Source/Application/imbSynthStateData.h"
#include "../Source/GUI/Components/imbSynthGUIComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainViewTabConfiguration  : public Component,
                                  public imbSynthGUIComponent,
                                  public Button::Listener,
                                  public Slider::Listener
{
public:
    //==============================================================================
    MainViewTabConfiguration (imbSynthStateData * synthState, String nameSufix);
    ~MainViewTabConfiguration();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* background2_jpg;
    static const int background2_jpgSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label3;
    std::unique_ptr<TextEditor> needle_midiDevice;
    std::unique_ptr<Label> label7;
    std::unique_ptr<TextEditor> needle_input;
    std::unique_ptr<Label> label8;
    std::unique_ptr<TextEditor> needle_output;
    std::unique_ptr<ToggleButton> toggle_log_to_file;
    std::unique_ptr<ToggleButton> toggle_factory_readonly;
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> label2;
    std::unique_ptr<TextEditor> needle_serialPort;
    std::unique_ptr<Slider> fullSyncPlayTimeout;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Slider> ccMessagesCycle;
    std::unique_ptr<Label> label6;
    std::unique_ptr<ToggleButton> confirmationNoteOnOff;
    std::unique_ptr<ToggleButton> confirmationCC;
    std::unique_ptr<ToggleButton> confirmationOPM;
    std::unique_ptr<Slider> confirmationRetryLimit;
    std::unique_ptr<Label> label9;
    std::unique_ptr<Slider> confirmationTimeout;
    std::unique_ptr<Label> label10;
    std::unique_ptr<Slider> deviceConnectRetry;
    std::unique_ptr<Label> label11;
    std::unique_ptr<Slider> UIRefreshRate;
    std::unique_ptr<Label> label12;
    std::unique_ptr<TextButton> ResetToDefaults;
    std::unique_ptr<Label> label13;
    std::unique_ptr<Slider> slider;
    std::unique_ptr<Label> label14;
    std::unique_ptr<Slider> slider2;
    Image cachedImage_background2_jpg_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainViewTabConfiguration)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

