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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ChaosEditor  : public Component,
                     public imbSynthGUIComponent,
                     public Slider::Listener
{
public:
    //==============================================================================
    ChaosEditor (imbSynthStateData * synthState, String nameSufix);
    ~ChaosEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	std::shared_ptr<ModulationFunctionLFO> modelComponent;


	//String pname_Value;
	//String pname_Curve;
	//String pname_Time;
	//String pname_Factor;

	//String pname_Retrigger;
	//String pname_Loop;


	//std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Link_AttackTime;
	//std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Link_DecayTime;
	//std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Link_ReleaseTime;

	//std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Link_InitLevel;
	//std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> Link_SustainLevel;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> Value;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Label> label5;
    std::unique_ptr<Slider> Time;
    std::unique_ptr<Slider> Factor;
    std::unique_ptr<Label> Curve2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChaosEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

