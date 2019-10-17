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
#include "../Source/Model/Core/ModelModulatedControl.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SourceMixerComponent  : public Component,
                              public imbSynthGUIComponent,
                              public Slider::Listener,
                              public ComboBox::Listener
{
public:
    //==============================================================================
    SourceMixerComponent (imbSynthStateData * synthState, String nameSufix);
    ~SourceMixerComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	//void Update();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	std::shared_ptr<ModelModulatedControl> modelComponent;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> ModAmt;
    std::unique_ptr<ComboBox> ModSrc;
    std::unique_ptr<Slider> Val;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SourceMixerComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

