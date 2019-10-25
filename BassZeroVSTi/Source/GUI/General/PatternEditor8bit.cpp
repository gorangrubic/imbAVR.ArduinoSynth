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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PatternEditor8bit.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PatternEditor8bit::PatternEditor8bit ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (128, 16);


    //[Constructor] You can add your own custom stuff here..

    //[/Constructor]
}

PatternEditor8bit::~PatternEditor8bit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

void PatternEditor8bit::Deploy(dataElementBase * p_target)
{
	pattern = static_cast<dataPatternObject*>(p_target);

	auto allCells = pattern->GetAllCells();

	Slider::SliderStyle cellStyle = Slider::SliderStyle::LinearBarVertical;

	switch (pattern->cellType)
	{
	case parameterValueType::Boolean:
		cellStyle = Slider::SliderStyle::LinearBarVertical;
		break;
	case parameterValueType::Float:
		cellStyle = Slider::SliderStyle::LinearBarVertical;
		break;
	case parameterValueType::Integer:
		cellStyle = Slider::SliderStyle::LinearVertical;
		break;
	}
	
	
	cellWidth = getWidth() / allCells.size();
	cellHeight = getHeight();

	int x = 0;
	for each (auto cell in allCells)
	{
		std::unique_ptr<Slider> cellComponent = std::unique_ptr<Slider>(new Slider(cellStyle, Slider::TextEntryBoxPosition::NoTextBox));
		addAndMakeVisible(cellComponent.get());
		cellComponent->setSize(cellWidth, cellHeight);
		cellComponent->setTopLeftPosition(x, 0);
		
		x += cellWidth;
		//= std::unique_ptr<Component>(new)
	}
	
	
	
}

//==============================================================================
void PatternEditor8bit::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff495358));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatternEditor8bit::resized()
{
    //[UserPreResize] Add your own custom resize code here..
	
	
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PatternEditor8bit" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="128" initialHeight="16">
  <BACKGROUND backgroundColour="ff495358"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

