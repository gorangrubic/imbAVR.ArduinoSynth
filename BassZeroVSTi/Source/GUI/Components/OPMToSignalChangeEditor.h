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
class OPMToSignalChangeEditor  : public Component,
                                 public imbSynthGUIComponent,
                                 public Slider::Listener
{
public:
    //==============================================================================
    OPMToSignalChangeEditor (imbSynthStateData * synthState, String nameSufix);
    ~OPMToSignalChangeEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	std::shared_ptr<MacroControlLink> modelComponent;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> Amount;
    std::unique_ptr<Label> label_signal;
    std::unique_ptr<Label> label_signal2;
    std::unique_ptr<Label> label_signal3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OPMToSignalChangeEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

