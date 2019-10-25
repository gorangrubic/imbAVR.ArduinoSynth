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

#include "../Components/OSCEditor.h"
#include "../Components/OSCEditor.h"
#include "../Components/OSCEditor.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/OSCEditor.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabWaveforms  : public Component,
                      public imbSynthGUIComponent
{
public:
    //==============================================================================
    TabWaveforms (imbSynthStateData * synthState, String nameSufix);
    ~TabWaveforms();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* background1_jpg;
    static const int background1_jpgSize;
    static const char* basszero_vstiwaveform_png2;
    static const int basszero_vstiwaveform_png2Size;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<OSCEditor> WFA;
    std::unique_ptr<OSCEditor> WFB;
    std::unique_ptr<OSCEditor> PERKA;
    std::unique_ptr<Label> label_WFA;
    std::unique_ptr<Label> Label_WFB;
    std::unique_ptr<Label> label_perkA;
    std::unique_ptr<Label> Title2;
    std::unique_ptr<SourceMixerComponent> WFA_PWM;
    std::unique_ptr<Label> Title3;
    std::unique_ptr<SourceMixerComponent> WFA_Shaper;
    std::unique_ptr<Label> Title4;
    std::unique_ptr<SourceMixerComponent> PERKA_PWM;
    std::unique_ptr<Label> Title5;
    std::unique_ptr<SourceMixerComponent> PERKA_HPFREQ;
    std::unique_ptr<Label> Title6;
    std::unique_ptr<SourceMixerComponent> PERKA_AMP;
    std::unique_ptr<OSCEditor> PERKB;
    std::unique_ptr<Label> label_perkB2;
    std::unique_ptr<Label> Title7;
    std::unique_ptr<SourceMixerComponent> PERKB_PWM;
    std::unique_ptr<Label> Title8;
    std::unique_ptr<SourceMixerComponent> PERKB_HPFREQ;
    std::unique_ptr<Label> Title9;
    std::unique_ptr<SourceMixerComponent> PERKB_AMP;
    std::unique_ptr<Label> Title10;
    std::unique_ptr<SourceMixerComponent> WFB_PWM;
    std::unique_ptr<Label> Title11;
    std::unique_ptr<SourceMixerComponent> WFB_Shaper;
    std::unique_ptr<Label> Title12;
    std::unique_ptr<SourceMixerComponent> WFA_Shaper2;
    std::unique_ptr<Label> Title13;
    std::unique_ptr<SourceMixerComponent> WFA_Shaper3;
    Image cachedImage_background1_jpg_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabWaveforms)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

