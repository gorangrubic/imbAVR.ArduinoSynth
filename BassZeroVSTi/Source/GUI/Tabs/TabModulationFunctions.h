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

#include "../Components/ADSREditor.h"
#include "../Components/ADSREditor.h"
#include "../Components/ChaosEditor.h"
#include "../Components/ENVEditor.h"
#include "../Components/ENVEditor.h"
#include "../Components/ChaosEditor.h"
#include "../Components/ChaosEditor.h"
#include "../Components/ChaosEditor.h"
#include "../Components/ENVEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabModulationFunctions  : public Component,
                                public imbSynthGUIComponent,
                                public Slider::Listener
{
public:
    //==============================================================================
    TabModulationFunctions (imbSynthStateData * synthState, String nameSufix);
    ~TabModulationFunctions();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* background1_jpg;
    static const int background1_jpgSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<ADSREditor> ADSR_A;
    std::unique_ptr<ADSREditor> ADSR_B;
    std::unique_ptr<ChaosEditor> LFO_A;
    std::unique_ptr<ENVEditor> ENV_A;
    std::unique_ptr<ENVEditor> ENV_B;
    std::unique_ptr<ChaosEditor> LFO_B;
    std::unique_ptr<ChaosEditor> LFO_C;
    std::unique_ptr<ChaosEditor> LFO_D;
    std::unique_ptr<Label> label_WFA;
    std::unique_ptr<Label> label_WFA2;
    std::unique_ptr<ENVEditor> ENV_C;
    std::unique_ptr<Label> label_WFA3;
    std::unique_ptr<Label> label_WFA4;
    std::unique_ptr<Label> label_WFA5;
    std::unique_ptr<Label> label_WFA6;
    std::unique_ptr<Label> label_WFA7;
    std::unique_ptr<Label> label_WFA8;
    std::unique_ptr<Label> label_WFA9;
    std::unique_ptr<Label> label_WFA10;
    std::unique_ptr<Label> label_WFA11;
    std::unique_ptr<Label> label_WFA12;
    std::unique_ptr<Label> label_OPM2;
    std::unique_ptr<Slider> CTRLA;
    std::unique_ptr<Slider> CTRLB;
    std::unique_ptr<Slider> CTRLC;
    std::unique_ptr<Slider> CTRLC2;
    std::unique_ptr<Slider> CTRLC3;
    Image cachedImage_background1_jpg_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabModulationFunctions)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

