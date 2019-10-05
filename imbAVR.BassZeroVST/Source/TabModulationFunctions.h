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

#include "ADSREditor.h"
#include "ADSREditor.h"
#include "LFOEditor.h"
#include "LFOEditor.h"
#include "ENVEditor.h"
#include "ENVEditor.h"
#include "ChaosEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabModulationFunctions  : public Component
{
public:
    //==============================================================================
    TabModulationFunctions ();
    ~TabModulationFunctions();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* basszero_background_jpg;
    static const int basszero_background_jpgSize;
    static const char* basszero_background_jpg2;
    static const int basszero_background_jpg2Size;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label7;
    std::unique_ptr<ADSREditor> ADSRA_component;
    std::unique_ptr<ADSREditor> ADSRB_component;
    std::unique_ptr<LFOEditor> LFOB_component;
    std::unique_ptr<LFOEditor> LFOA_component;
    std::unique_ptr<ENVEditor> ENVA_component;
    std::unique_ptr<ENVEditor> ENVB_component;
    std::unique_ptr<ChaosEditor> CHAOS_Component;
    std::unique_ptr<Label> ADSRTitle;
    std::unique_ptr<Label> ADSRTitle2;
    std::unique_ptr<Label> Title;
    std::unique_ptr<Label> Title2;
    std::unique_ptr<Label> Title3;
    std::unique_ptr<Label> Title4;
    Image cachedImage_basszero_background_jpg2_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabModulationFunctions)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

