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

    b0.reset (new TextButton ("new button"));
    addAndMakeVisible (b0.get());
    b0->setButtonText (String());
    b0->setConnectedEdges (Button::ConnectedOnBottom);
    b0->addListener (this);
    b0->setColour (TextButton::buttonColourId, Colour (0x50000000));
    b0->setColour (TextButton::buttonOnColourId, Colour (0xffad0002));

    b0->setBounds (0, 0, 16, 16);

    b1.reset (new TextButton ("new button"));
    addAndMakeVisible (b1.get());
    b1->setButtonText (String());
    b1->addListener (this);
    b1->setColour (TextButton::buttonColourId, Colour (0x50000000));
    b1->setColour (TextButton::buttonOnColourId, Colour (0xffad0002));

    b1->setBounds (16, 0, 16, 16);

    b2.reset (new TextButton ("new button"));
    addAndMakeVisible (b2.get());
    b2->setButtonText (String());
    b2->addListener (this);
    b2->setColour (TextButton::buttonColourId, Colour (0x50000000));
    b2->setColour (TextButton::buttonOnColourId, Colour (0xffad0002));

    b2->setBounds (32, 0, 16, 16);

    b3.reset (new TextButton ("new button"));
    addAndMakeVisible (b3.get());
    b3->setButtonText (String());
    b3->addListener (this);
    b3->setColour (TextButton::buttonColourId, Colour (0x50000000));
    b3->setColour (TextButton::buttonOnColourId, Colour (0xffad0002));

    b3->setBounds (48, 0, 16, 16);

    b4.reset (new TextButton ("new button"));
    addAndMakeVisible (b4.get());
    b4->setButtonText (String());
    b4->addListener (this);
    b4->setColour (TextButton::buttonColourId, Colour (0x50000000));
    b4->setColour (TextButton::buttonOnColourId, Colour (0xffad0002));

    b4->setBounds (64, 0, 16, 16);

    b5.reset (new TextButton ("new button"));
    addAndMakeVisible (b5.get());
    b5->setButtonText (String());
    b5->addListener (this);
    b5->setColour (TextButton::buttonColourId, Colour (0x50000000));
    b5->setColour (TextButton::buttonOnColourId, Colour (0xffad0002));

    b5->setBounds (80, 0, 16, 16);

    b6.reset (new TextButton ("new button"));
    addAndMakeVisible (b6.get());
    b6->setButtonText (String());
    b6->addListener (this);
    b6->setColour (TextButton::buttonColourId, Colour (0x50000000));
    b6->setColour (TextButton::buttonOnColourId, Colour (0xffad0002));

    b6->setBounds (96, 0, 16, 16);

    b7.reset (new TextButton ("new button"));
    addAndMakeVisible (b7.get());
    b7->setButtonText (String());
    b7->addListener (this);
    b7->setColour (TextButton::buttonColourId, Colour (0x50000000));
    b7->setColour (TextButton::buttonOnColourId, Colour (0xffad0002));

    b7->setBounds (112, 0, 16, 16);


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

    b0 = nullptr;
    b1 = nullptr;
    b2 = nullptr;
    b3 = nullptr;
    b4 = nullptr;
    b5 = nullptr;
    b6 = nullptr;
    b7 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatternEditor8bit::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = 0, y = 0, width = 64, height = 16;
        Colour fillColour = Colour (0x25ffffff);
        Colour strokeColour = Colour (0x50602aa5);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 0);

    }

    {
        int x = 64, y = 0, width = 64, height = 16;
        Colour fillColour = Colour (0x251d2427);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

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

void PatternEditor8bit::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == b0.get())
    {
        //[UserButtonCode_b0] -- add your button handler code here..
        //[/UserButtonCode_b0]
    }
    else if (buttonThatWasClicked == b1.get())
    {
        //[UserButtonCode_b1] -- add your button handler code here..
        //[/UserButtonCode_b1]
    }
    else if (buttonThatWasClicked == b2.get())
    {
        //[UserButtonCode_b2] -- add your button handler code here..
        //[/UserButtonCode_b2]
    }
    else if (buttonThatWasClicked == b3.get())
    {
        //[UserButtonCode_b3] -- add your button handler code here..
        //[/UserButtonCode_b3]
    }
    else if (buttonThatWasClicked == b4.get())
    {
        //[UserButtonCode_b4] -- add your button handler code here..
        //[/UserButtonCode_b4]
    }
    else if (buttonThatWasClicked == b5.get())
    {
        //[UserButtonCode_b5] -- add your button handler code here..
        //[/UserButtonCode_b5]
    }
    else if (buttonThatWasClicked == b6.get())
    {
        //[UserButtonCode_b6] -- add your button handler code here..
        //[/UserButtonCode_b6]
    }
    else if (buttonThatWasClicked == b7.get())
    {
        //[UserButtonCode_b7] -- add your button handler code here..
        //[/UserButtonCode_b7]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
  <BACKGROUND backgroundColour="323e44">
    <RECT pos="0 0 64 16" fill="solid: 25ffffff" hasStroke="1" stroke="0.1, mitered, butt"
          strokeColour="solid: 50602aa5"/>
    <RECT pos="64 0 64 16" fill="solid: 251d2427" hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="new button" id="6663d1d32e1e4547" memberName="b0" virtualName=""
              explicitFocusOrder="0" pos="0 0 16 16" bgColOff="50000000" bgColOn="ffad0002"
              buttonText="" connectedEdges="8" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="77e7e865b301fbcd" memberName="b1" virtualName=""
              explicitFocusOrder="0" pos="16 0 16 16" bgColOff="50000000" bgColOn="ffad0002"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="c64c0278b3505331" memberName="b2" virtualName=""
              explicitFocusOrder="0" pos="32 0 16 16" bgColOff="50000000" bgColOn="ffad0002"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="1fce6a0e19a49e96" memberName="b3" virtualName=""
              explicitFocusOrder="0" pos="48 0 16 16" bgColOff="50000000" bgColOn="ffad0002"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="9767c5b7f44869b1" memberName="b4" virtualName=""
              explicitFocusOrder="0" pos="64 0 16 16" bgColOff="50000000" bgColOn="ffad0002"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="387116f68cee6bb3" memberName="b5" virtualName=""
              explicitFocusOrder="0" pos="80 0 16 16" bgColOff="50000000" bgColOn="ffad0002"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="3a250d4887087804" memberName="b6" virtualName=""
              explicitFocusOrder="0" pos="96 0 16 16" bgColOff="50000000" bgColOn="ffad0002"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="89b50564d2bf462e" memberName="b7" virtualName=""
              explicitFocusOrder="0" pos="112 0 16 16" bgColOff="50000000"
              bgColOn="ffad0002" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

