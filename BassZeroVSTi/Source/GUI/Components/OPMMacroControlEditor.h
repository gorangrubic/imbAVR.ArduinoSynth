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

#include "SourceMixerComponent.h"
#include "SourceMixerComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OPMMacroControlEditor  : public Component,
                               public imbSynthGUIComponent,
                               public Slider::Listener
{
public:
    //==============================================================================
    OPMMacroControlEditor (imbSynthStateData * synthState, String nameSufix);
    ~OPMMacroControlEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	//std::shared_ptr<OPMControlModel> modelComponent;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> Title2;
    std::unique_ptr<Slider> VALA;
    std::unique_ptr<Label> Title5;
    std::unique_ptr<Label> Title6;
    std::unique_ptr<SourceMixerComponent> OPM_MODA;
    std::unique_ptr<Label> Title14;
    std::unique_ptr<Label> Title15;
    std::unique_ptr<Label> label_OPM6;
    std::unique_ptr<SourceMixerComponent> OPM_MODB;
    std::unique_ptr<Slider> VALB;
    std::unique_ptr<Label> Title3;
    std::unique_ptr<Slider> VALC;
    std::unique_ptr<Label> Title4;
    std::unique_ptr<Label> Title7;
    std::unique_ptr<Label> Title8;
    std::unique_ptr<Label> Title9;
    std::unique_ptr<Label> label_OPM2;
    std::unique_ptr<Slider> CTRLA;
    std::unique_ptr<Slider> CTRLB;
    std::unique_ptr<Slider> CTRLC;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OPMMacroControlEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

