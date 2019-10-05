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

#include "OSCBasicEditor.h"
#include "OSCBasicEditor.h"
#include "PERKEditor.h"
#include "PERKEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabWaveforms  : public Component,
                      public Slider::Listener
{
public:
    //==============================================================================
    TabWaveforms ();
    ~TabWaveforms();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* basszero_vstipage2_png;
    static const int basszero_vstipage2_pngSize;
    static const char* basszero_vsti_signalflow_png;
    static const int basszero_vsti_signalflow_pngSize;
    static const char* basszero_vsti_signalflow_png2;
    static const int basszero_vsti_signalflow_png2Size;
    static const char* basszero_vsti_signalflow_png3;
    static const int basszero_vsti_signalflow_png3Size;
    static const char* basszero_vsti_signalflow_png4;
    static const int basszero_vsti_signalflow_png4Size;
    static const char* basszero_vsti_signalflow_png5;
    static const int basszero_vsti_signalflow_png5Size;
    static const char* basszero_vsti_signalflow_png6;
    static const int basszero_vsti_signalflow_png6Size;
    static const char* basszero_background_jpg;
    static const int basszero_background_jpgSize;
    static const char* basszero_background_jpg2;
    static const int basszero_background_jpg2Size;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label7;
    std::unique_ptr<OSCBasicEditor> label_wfa_shape;
    std::unique_ptr<OSCBasicEditor> component_WFB;
    std::unique_ptr<PERKEditor> component_PERKA;
    std::unique_ptr<PERKEditor> component_PERKB;
    std::unique_ptr<Slider> Val;
    std::unique_ptr<Label> Title;
    std::unique_ptr<Label> Title3;
    std::unique_ptr<Label> Title4;
    std::unique_ptr<Label> label_WFA;
    std::unique_ptr<Label> Title6;
    std::unique_ptr<Label> label;
    Image cachedImage_basszero_background_jpg2_1;
    Image cachedImage_basszero_vsti_signalflow_png6_2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabWaveforms)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

