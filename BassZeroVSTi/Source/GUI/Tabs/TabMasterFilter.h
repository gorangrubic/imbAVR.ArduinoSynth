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

#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/OPMMacroControlEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabMasterFilter  : public Component,
                         public imbSynthGUIComponent
{
public:
    //==============================================================================
    TabMasterFilter (imbSynthStateData * synthState, String nameSufix);
    ~TabMasterFilter();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* background1_jpg;
    static const int background1_jpgSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<SourceMixerComponent> FLT_Cut;
    std::unique_ptr<SourceMixerComponent> FLT_Res;
    std::unique_ptr<SourceMixerComponent> FLT_Freq;
    std::unique_ptr<SourceMixerComponent> MstAmp;
    std::unique_ptr<SourceMixerComponent> MstPan;
    std::unique_ptr<SourceMixerComponent> DistMix;
    std::unique_ptr<Label> Title9;
    std::unique_ptr<SourceMixerComponent> DistDrive;
    std::unique_ptr<Label> Title10;
    std::unique_ptr<Label> Title7;
    std::unique_ptr<Label> Title8;
    std::unique_ptr<Label> label_OPM4;
    std::unique_ptr<Label> Title13;
    std::unique_ptr<Label> label_OPM5;
    std::unique_ptr<Label> label_OPM2;
    std::unique_ptr<Label> label_OPM3;
    std::unique_ptr<Label> Title2;
    std::unique_ptr<Label> Title3;
    std::unique_ptr<SourceMixerComponent> FLT_Pwm;
    std::unique_ptr<Label> Title5;
    std::unique_ptr<SourceMixerComponent> WF_FLT;
    std::unique_ptr<Label> Title6;
    std::unique_ptr<SourceMixerComponent> WF_Mix;
    std::unique_ptr<SourceMixerComponent> PERKB_Pan;
    std::unique_ptr<Label> Title14;
    std::unique_ptr<SourceMixerComponent> PERKA_Pan;
    std::unique_ptr<Label> Title15;
    std::unique_ptr<Label> label_OPM6;
    std::unique_ptr<Label> Title12;
    std::unique_ptr<OPMMacroControlEditor> OPM_Controls;
    std::unique_ptr<Label> label_OPM7;
    Image cachedImage_background1_jpg_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabMasterFilter)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

