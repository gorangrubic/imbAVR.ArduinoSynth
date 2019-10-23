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
#include "../Components/imbSynthGUIComponent.h"
#include "ControlStateDisplayModel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ControlStateDisplay  : public Component,
                             public imbSynthGUIComponent,
                             private Timer
{
public:
    //==============================================================================
    ControlStateDisplay (imbSynthStateData * synthState, String nameSufix);
    ~ControlStateDisplay();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void Update();
	void timerCallback() override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	std::shared_ptr<ControlStateDisplayModel> controlDisplayModel;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label_parameter;
    std::unique_ptr<Label> Parameter_text;
    std::unique_ptr<Label> label_group;
    std::unique_ptr<Label> GroupName_text;
    std::unique_ptr<Label> label_val;
    std::unique_ptr<Label> CCIn_label;
    std::unique_ptr<Label> CCOut_label;
    std::unique_ptr<TextEditor> Value_Edit;
    std::unique_ptr<TextEditor> CCIn_edit;
    std::unique_ptr<TextEditor> CCOut_edit;
    std::unique_ptr<Label> CC_label;
    std::unique_ptr<Label> text_ccID;
    std::unique_ptr<Label> CCUnit_label;
    std::unique_ptr<Label> label_info;
    std::unique_ptr<Label> text_info;
    std::unique_ptr<Label> text_class;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ControlStateDisplay)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

