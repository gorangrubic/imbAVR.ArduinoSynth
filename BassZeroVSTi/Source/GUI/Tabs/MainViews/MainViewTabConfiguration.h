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

#include "../../General/PathBrowser.h"
#include "../../General/PathBrowser.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainViewTabConfiguration  : public Component,
                                  public imbSynthGUIComponent,
                                  public Button::Listener
{
public:
    //==============================================================================
    MainViewTabConfiguration ();
    ~MainViewTabConfiguration();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label3;
    std::unique_ptr<Label> label5;
    std::unique_ptr<TextEditor> text_name2;
    std::unique_ptr<PathBrowser> component;
    std::unique_ptr<TextEditor> needle_device_1;
    std::unique_ptr<TextEditor> needle_device_2;
    std::unique_ptr<TextEditor> needle_device_3;
    std::unique_ptr<Label> label7;
    std::unique_ptr<TextEditor> needle_input_1;
    std::unique_ptr<TextEditor> needle_device_4;
    std::unique_ptr<TextEditor> needle_device_5;
    std::unique_ptr<Label> label8;
    std::unique_ptr<TextEditor> needle_output_1;
    std::unique_ptr<TextEditor> needle_output_2;
    std::unique_ptr<TextEditor> needle_output_3;
    std::unique_ptr<ToggleButton> toggle_log_to_file;
    std::unique_ptr<ToggleButton> toggle_factory_readonly;
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> label9;
    std::unique_ptr<PathBrowser> component2;
    std::unique_ptr<Label> label10;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainViewTabConfiguration)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

