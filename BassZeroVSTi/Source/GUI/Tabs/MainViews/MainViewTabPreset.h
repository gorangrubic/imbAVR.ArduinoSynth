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
#include "../../../../JuceLibraryCode/JuceHeader.h"
//[/Headers]

#include "../../General/PresetDefinitionEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainViewTabPreset  : public Component
{
public:
    //==============================================================================
    MainViewTabPreset ();
    ~MainViewTabPreset();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<PresetDefinitionEditor> presetDefinitionDisplay;
    std::unique_ptr<Label> label5;
    std::unique_ptr<TextEditor> text_preset_name;
    std::unique_ptr<Label> label2;
    std::unique_ptr<TextEditor> text_preset_name2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainViewTabPreset)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

