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

#include "SynthStateDisplay.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SynthStateDisplay::SynthStateDisplay (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label_status.reset (new Label ("new label",
                                   TRANS("Status")));
    addAndMakeVisible (label_status.get());
    label_status->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_status->setJustificationType (Justification::centred);
    label_status->setEditable (false, false, false);
    label_status->setColour (Label::backgroundColourId, Colour (0x50181f22));
    label_status->setColour (TextEditor::textColourId, Colours::black);
    label_status->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_status->setBounds (0, 0, 64, 24);

    label_message.reset (new Label ("new label",
                                    TRANS("Device not connected")));
    addAndMakeVisible (label_message.get());
    label_message->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_message->setJustificationType (Justification::centredLeft);
    label_message->setEditable (false, false, false);
    label_message->setColour (Label::backgroundColourId, Colour (0x25f0ffff));
    label_message->setColour (Label::textColourId, Colours::azure);
    label_message->setColour (TextEditor::textColourId, Colours::black);
    label_message->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 24);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SynthStateDisplay::~SynthStateDisplay()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label_status = nullptr;
    label_message = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SynthStateDisplay::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SynthStateDisplay::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label_message->setBounds (64, 0, getWidth() - 64, 24);
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

<JUCER_COMPONENT documentType="Component" className="SynthStateDisplay" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="600" initialHeight="24">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="ddf7b13950d11ebf" memberName="label_status"
         virtualName="" explicitFocusOrder="0" pos="0 0 64 24" bkgCol="50181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="Status" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="179ecc7c0adbb30b" memberName="label_message"
         virtualName="" explicitFocusOrder="0" pos="64 0 64M 24" bkgCol="25f0ffff"
         textCol="fff0ffff" edTextCol="ff000000" edBkgCol="0" labelText="Device not connected"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

