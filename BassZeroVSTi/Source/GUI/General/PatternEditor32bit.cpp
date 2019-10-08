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
#include "../Source/Data/imbSynthStateData.h"
//[/Headers]

#include "PatternEditor32bit.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PatternEditor32bit::PatternEditor32bit (Pattern32BitModel _pattern)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    block1.reset (new PatternEditor8bit());
    addAndMakeVisible (block1.get());
    block1->setBounds (0, 0, 128, 16);

    block2.reset (new PatternEditor8bit());
    addAndMakeVisible (block2.get());
    block2->setBounds (128, 0, 128, 16);

    block3.reset (new PatternEditor8bit());
    addAndMakeVisible (block3.get());
    block3->setBounds (256, 0, 128, 16);

    block4.reset (new PatternEditor8bit());
    addAndMakeVisible (block4.get());
    block4->setBounds (384, 0, 128, 16);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (512, 16);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PatternEditor32bit::~PatternEditor32bit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    block1 = nullptr;
    block2 = nullptr;
    block3 = nullptr;
    block4 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatternEditor32bit::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 256, y = 0, width = 256, height = 16;
        Colour fillColour = Colour (0x10f0ffff);
        Colour strokeColour = Colour (0xff181f22);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    {
        int x = 0, y = 0, width = 256, height = 16;
        Colour fillColour = Colour (0x10181f22);
        Colour strokeColour = Colour (0xff181f22);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatternEditor32bit::resized()
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

<JUCER_COMPONENT documentType="Component" className="PatternEditor32bit" componentName=""
                 parentClasses="public Component" constructorParams="Pattern32BitModel _pattern"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="512" initialHeight="16">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="256 0 256 16" fill="solid: 10f0ffff" hasStroke="1" stroke="1, mitered, butt"
          strokeColour="solid: ff181f22"/>
    <RECT pos="0 0 256 16" fill="solid: 10181f22" hasStroke="1" stroke="1, mitered, butt"
          strokeColour="solid: ff181f22"/>
  </BACKGROUND>
  <JUCERCOMP name="" id="577892e8a3af699c" memberName="block1" virtualName=""
             explicitFocusOrder="0" pos="0 0 128 16" sourceFile="PatternEditor8bit.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="f4bf847837e253a9" memberName="block2" virtualName=""
             explicitFocusOrder="0" pos="128 0 128 16" sourceFile="PatternEditor8bit.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="c75fabcc6dcbf73b" memberName="block3" virtualName=""
             explicitFocusOrder="0" pos="256 0 128 16" sourceFile="PatternEditor8bit.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="81054733362e694b" memberName="block4" virtualName=""
             explicitFocusOrder="0" pos="384 0 128 16" sourceFile="PatternEditor8bit.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

