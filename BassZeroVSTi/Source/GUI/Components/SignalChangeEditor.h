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
class SignalChangeEditor  : public Component,
                            public imbSynthGUIComponent,
                            public Slider::Listener
{
public:
    //==============================================================================
    SignalChangeEditor (imbSynthStateData * synthState, String nameSufix, String parentName);
    ~SignalChangeEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	std::shared_ptr<OPMSignalUnitChange> modelComponent;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> Rate;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Slider> Period;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> Change;
    std::unique_ptr<Label> label4;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SignalChangeEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

