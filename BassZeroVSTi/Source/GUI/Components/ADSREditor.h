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
#include "../Components/imbSynthGUIComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ADSREditor  : public Component,
                    public imbSynthGUIComponent,
                    public Slider::Listener
{
public:
    //==============================================================================
    ADSREditor (imbSynthStateData * synthState, String nameSufix);
    ~ADSREditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	std::shared_ptr<ModulationFunctionADSR> modelComponent;

	//String pname_AttackTime;
	//String pname_DecayTime;
	//String pname_ReleaseTime;

	//String pname_InitLevel;
	//String pname_SustainLevel;


	//std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Link_AttackTime;
	//std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Link_DecayTime;
	//std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Link_ReleaseTime;

	//std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Link_InitLevel;
	//std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Link_SustainLevel;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label6;
    std::unique_ptr<Slider> AttackTime;
    std::unique_ptr<Slider> DecayTime;
    std::unique_ptr<Slider> InitLevel;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Slider> SustainLevel;
    std::unique_ptr<Label> label5;
    std::unique_ptr<Slider> ReleaseTime;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSREditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

