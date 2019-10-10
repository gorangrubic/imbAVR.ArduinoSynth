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

#include "CommandBufferDisplay.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
CommandBufferDisplay::CommandBufferDisplay (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label.reset (new Label ("new label",
                            TRANS("CC Msgs\n")));
    addAndMakeVisible (label.get());
    label->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0x50181f22));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (192, 0, 80, 24);

    msgs_cc.reset (new Label ("new label",
                              TRANS("1")));
    addAndMakeVisible (msgs_cc.get());
    msgs_cc->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    msgs_cc->setJustificationType (Justification::centred);
    msgs_cc->setEditable (false, false, false);
    msgs_cc->setColour (Label::backgroundColourId, Colour (0x25f0ffff));
    msgs_cc->setColour (Label::textColourId, Colours::azure);
    msgs_cc->setColour (TextEditor::textColourId, Colours::black);
    msgs_cc->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    msgs_cc->setBounds (272, 0, 64, 24);

    label3.reset (new Label ("new label",
                             TRANS("OPM Msgs")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (Label::backgroundColourId, Colour (0x50181f22));
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (64, 0, 64, 24);

    msgs_opm.reset (new Label ("new label",
                               TRANS("1")));
    addAndMakeVisible (msgs_opm.get());
    msgs_opm->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    msgs_opm->setJustificationType (Justification::centred);
    msgs_opm->setEditable (false, false, false);
    msgs_opm->setColour (Label::backgroundColourId, Colour (0x25f0ffff));
    msgs_opm->setColour (Label::textColourId, Colours::azure);
    msgs_opm->setColour (TextEditor::textColourId, Colours::black);
    msgs_opm->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    msgs_opm->setBounds (128, 0, 64, 24);

    label2.reset (new Label ("new label",
                             TRANS("MIDI Msgs")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0x50181f22));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (336, 0, 80, 24);

    msgs_cc2.reset (new Label ("new label",
                               TRANS("1")));
    addAndMakeVisible (msgs_cc2.get());
    msgs_cc2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    msgs_cc2->setJustificationType (Justification::centred);
    msgs_cc2->setEditable (false, false, false);
    msgs_cc2->setColour (Label::backgroundColourId, Colour (0x25f0ffff));
    msgs_cc2->setColour (Label::textColourId, Colours::azure);
    msgs_cc2->setColour (TextEditor::textColourId, Colours::black);
    msgs_cc2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    msgs_cc2->setBounds (416, 0, 64, 24);

    label4.reset (new Label ("new label",
                             TRANS("Buffer\n")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (Label::backgroundColourId, Colour (0xff495358));
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (0, 0, 64, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (830, 24);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

CommandBufferDisplay::~CommandBufferDisplay()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    msgs_cc = nullptr;
    label3 = nullptr;
    msgs_opm = nullptr;
    label2 = nullptr;
    msgs_cc2 = nullptr;
    label4 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void CommandBufferDisplay::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void CommandBufferDisplay::resized()
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

<JUCER_COMPONENT documentType="Component" className="CommandBufferDisplay" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="830" initialHeight="24">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="new label" id="a579be9af7298cb3" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="192 0 80 24" bkgCol="50181f22" edTextCol="ff000000"
         edBkgCol="0" labelText="CC Msgs&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="1e18716abad2bc29" memberName="msgs_cc" virtualName=""
         explicitFocusOrder="0" pos="272 0 64 24" bkgCol="25f0ffff" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="ddf7b13950d11ebf" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="64 0 64 24" bkgCol="50181f22" edTextCol="ff000000"
         edBkgCol="0" labelText="OPM Msgs" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="179ecc7c0adbb30b" memberName="msgs_opm"
         virtualName="" explicitFocusOrder="0" pos="128 0 64 24" bkgCol="25f0ffff"
         textCol="fff0ffff" edTextCol="ff000000" edBkgCol="0" labelText="1"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="e5af8c71d65d607e" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="336 0 80 24" bkgCol="50181f22" edTextCol="ff000000"
         edBkgCol="0" labelText="MIDI Msgs" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="212d2fed4763e939" memberName="msgs_cc2"
         virtualName="" explicitFocusOrder="0" pos="416 0 64 24" bkgCol="25f0ffff"
         textCol="fff0ffff" edTextCol="ff000000" edBkgCol="0" labelText="1"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="a8cd01abfc74b420" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="0 0 64 24" bkgCol="ff495358" edTextCol="ff000000"
         edBkgCol="0" labelText="Buffer&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

