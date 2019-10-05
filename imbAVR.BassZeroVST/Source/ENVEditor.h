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
#include "imbControlParameter.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ENVEditor  : public Component,
                   public Slider::Listener
{
public:
    //==============================================================================
    ENVEditor ();
    ~ENVEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void Connect(imbControlParameter * _parTimeA,    imbControlParameter * _parTimeB,    imbControlParameter * _parLevelA,    imbControlParameter * _parLevelB);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    imbControlParameter * parTimeA;
    imbControlParameter * parTimeB;
    imbControlParameter * parLevelA;
    imbControlParameter * parLevelB;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> TimeA;
    std::unique_ptr<Label> label;
    std::unique_ptr<Slider> LevelA;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Slider> TimeB;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Slider> LevelB;
    std::unique_ptr<Label> label4;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ENVEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

