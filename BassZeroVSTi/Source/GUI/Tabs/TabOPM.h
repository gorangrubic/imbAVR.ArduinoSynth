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
#include "../../../JuceLibraryCode/JuceHeader.h"
//[/Headers]

#include "../Components/OPMEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"
#include "OPMToSignalChangeEditor.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabOPM  : public Component
{
public:
    //==============================================================================
    TabOPM (imbSynthStateData * synthState, String nameSufix);
    ~TabOPM();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<TabbedComponent> tabbedComponent;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<OPMEditor> MacroControls;
    std::unique_ptr<Component> MODA_MCL1;
    std::unique_ptr<Component> MODB_MCL1;
    std::unique_ptr<Component> VALC_MCL1;
    std::unique_ptr<Component> VALC_MCL2;
    std::unique_ptr<Component> MODA_MCL2;
    std::unique_ptr<Component> MODB_MCL2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabOPM)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

