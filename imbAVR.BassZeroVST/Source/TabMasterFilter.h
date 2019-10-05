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
//[/Headers]

#include "SourceMixerComponent.h"
#include "SourceMixerComponent.h"
#include "SourceMixerComponent.h"
#include "SourceMixerComponent.h"
#include "SourceMixerComponent.h"
#include "SourceMixerComponent.h"
#include "SourceMixerComponent.h"
#include "SourceMixerComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabMasterFilter  : public Component,
                         public Slider::Listener,
                         public ComboBox::Listener
{
public:
    //==============================================================================
    TabMasterFilter ();
    ~TabMasterFilter();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

    // Binary resources:
    static const char* basszero_background_jpg;
    static const int basszero_background_jpgSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> component_FLT_PWM;
    std::unique_ptr<SourceMixerComponent> component_FLT_CutOff;
    std::unique_ptr<Label> Title3;
    std::unique_ptr<Label> label4;
    std::unique_ptr<SourceMixerComponent> component_FLT_Res;
    std::unique_ptr<Label> Title5;
    std::unique_ptr<SourceMixerComponent> component_FLT_Freq;
    std::unique_ptr<Label> Title6;
    std::unique_ptr<SourceMixerComponent> component_MASTER_Amp;
    std::unique_ptr<Label> Title7;
    std::unique_ptr<SourceMixerComponent> component_MASTER_Pan;
    std::unique_ptr<Label> Title8;
    std::unique_ptr<SourceMixerComponent> component_FLT_Dist;
    std::unique_ptr<Label> Title9;
    std::unique_ptr<Slider> component_FLT_Dist_Overdrive;
    std::unique_ptr<Label> Title11;
    std::unique_ptr<Label> Title2;
    std::unique_ptr<SourceMixerComponent> component_OPMA;
    std::unique_ptr<Label> Title;
    std::unique_ptr<Label> Title4;
    std::unique_ptr<SourceMixerComponent> component_OPMB;
    std::unique_ptr<Slider> component_OPM_VAL_A;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> component_OPM_VAL_B;
    std::unique_ptr<Label> label5;
    std::unique_ptr<Slider> component_OPM_VAL_C;
    std::unique_ptr<Label> label6;
    std::unique_ptr<Label> label_OPM;
    std::unique_ptr<ComboBox> comboBox;
    std::unique_ptr<Label> label_OPM2;
    std::unique_ptr<Label> label_OPM3;
    std::unique_ptr<TextEditor> textEditor;
    Image cachedImage_basszero_background_jpg_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabMasterFilter)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

