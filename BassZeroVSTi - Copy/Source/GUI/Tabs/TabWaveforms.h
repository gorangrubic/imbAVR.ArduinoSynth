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

#include "Components/OSCBasicEditor.h"
#include "Components/OSCBasicEditor.h"
#include "Components/PERKEditor.h"
#include "Components/PERKEditor.h"


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
    std::unique_ptr<OSCBasicEditor> label_wfa_shape;
    std::unique_ptr<OSCBasicEditor> component_WFB;
    std::unique_ptr<PERKEditor> component_PERKA;
    std::unique_ptr<PERKEditor> component_PERKB;
    std::unique_ptr<Label> label_WFA;
    std::unique_ptr<Label> Label_WFB;
    std::unique_ptr<Label> label_perkA;
    std::unique_ptr<Label> label_perkB;
    Image cachedImage_background1_jpg_1;
    Image cachedImage_basszero_vstiwaveform_png2_2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabWaveforms)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

