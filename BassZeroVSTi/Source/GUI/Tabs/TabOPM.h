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
#include "../Source/GUI/Components/OPMToSignalChangeEditor.h";
#include "../Source/GUI/Components/SignalControlEditor.h";
//[/Headers]

#include "../Components/OPMEditor.h"
#include "../Components/SourceMixerComponent.h"
#include "../Components/SourceMixerComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TabOPM  : public Component,
                public Slider::Listener
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
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::unique_ptr<TabbedComponent> tabbedComponent;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<OPMEditor> MacroControls;
    std::unique_ptr<TabbedComponent> tabbedComponent;
    std::unique_ptr<Label> Title2;
    std::unique_ptr<Slider> VALA;
    std::unique_ptr<Label> Title5;
    std::unique_ptr<Label> Title6;
    std::unique_ptr<SourceMixerComponent> OPM_MODA;
    std::unique_ptr<SourceMixerComponent> OPM_MODB;
    std::unique_ptr<Slider> VALB;
    std::unique_ptr<Label> Title3;
    std::unique_ptr<Slider> VALC;
    std::unique_ptr<Label> Title4;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabOPM)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

