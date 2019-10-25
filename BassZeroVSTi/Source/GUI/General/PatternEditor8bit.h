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
#include "../Source/Data/imbSynthStateData.h"
#include "../Source/Data/Model/dataPatternObject.h"
#include "../Components/imbSynthGUIComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatternEditor8bit  : public Component, public imbSynthParameterEditor
{
public:
    //==============================================================================
    PatternEditor8bit();
    ~PatternEditor8bit();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void Deploy(dataElementBase *p_target);
	
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	dataPatternObject * pattern;
	std::vector<std::unique_ptr<Slider>> cellComponents;
	int cellWidth;
	int cellHeight;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatternEditor8bit)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

