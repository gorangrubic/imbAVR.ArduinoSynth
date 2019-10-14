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

#include "ControlStateDisplay.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#define GUIREFRESH_TIMEINTERVAL 250
//[/MiscUserDefs]

//==============================================================================
ControlStateDisplay::ControlStateDisplay (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label.reset (new Label ("new label",
                            TRANS("Parameter")));
    addAndMakeVisible (label.get());
    label->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0x50181f22));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (152, 0, 80, 24);

    Parameter_text.reset (new Label ("new label",
                                     TRANS("WFA_PWM")));
    addAndMakeVisible (Parameter_text.get());
    Parameter_text->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Parameter_text->setJustificationType (Justification::centredLeft);
    Parameter_text->setEditable (false, false, false);
    Parameter_text->setColour (Label::backgroundColourId, Colour (0x25f0ffff));
    Parameter_text->setColour (Label::textColourId, Colours::azure);
    Parameter_text->setColour (TextEditor::textColourId, Colours::black);
    Parameter_text->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3.reset (new Label ("new label",
                             TRANS("Group")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (Label::backgroundColourId, Colour (0x50181f22));
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (0, 0, 64, 24);

    GroupName_text.reset (new Label ("new label",
                                     TRANS("WFA")));
    addAndMakeVisible (GroupName_text.get());
    GroupName_text->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    GroupName_text->setJustificationType (Justification::centredLeft);
    GroupName_text->setEditable (false, false, false);
    GroupName_text->setColour (Label::backgroundColourId, Colour (0x25f0ffff));
    GroupName_text->setColour (Label::textColourId, Colours::azure);
    GroupName_text->setColour (TextEditor::textColourId, Colours::black);
    GroupName_text->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    GroupName_text->setBounds (64, 0, 86, 24);

    label5.reset (new Label ("new label",
                             TRANS("Value")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (Label::backgroundColourId, Colour (0x25181f22));
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    CCIn_label.reset (new Label ("new label",
                                 TRANS("CC in")));
    addAndMakeVisible (CCIn_label.get());
    CCIn_label->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    CCIn_label->setJustificationType (Justification::centred);
    CCIn_label->setEditable (false, false, false);
    CCIn_label->setColour (Label::backgroundColourId, Colour (0x25181f22));
    CCIn_label->setColour (TextEditor::textColourId, Colours::black);
    CCIn_label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    CCOut_label.reset (new Label ("new label",
                                  TRANS("CC out")));
    addAndMakeVisible (CCOut_label.get());
    CCOut_label->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    CCOut_label->setJustificationType (Justification::centred);
    CCOut_label->setEditable (false, false, false);
    CCOut_label->setColour (Label::backgroundColourId, Colour (0x25181f22));
    CCOut_label->setColour (TextEditor::textColourId, Colours::black);
    CCOut_label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Value_Edit.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (Value_Edit.get());
    Value_Edit->setMultiLine (false);
    Value_Edit->setReturnKeyStartsNewLine (false);
    Value_Edit->setReadOnly (false);
    Value_Edit->setScrollbarsShown (false);
    Value_Edit->setCaretVisible (true);
    Value_Edit->setPopupMenuEnabled (false);
    Value_Edit->setColour (TextEditor::backgroundColourId, Colour (0x2542a2c8));
    Value_Edit->setText (TRANS("127"));

    CCIn_edit.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (CCIn_edit.get());
    CCIn_edit->setMultiLine (false);
    CCIn_edit->setReturnKeyStartsNewLine (false);
    CCIn_edit->setReadOnly (false);
    CCIn_edit->setScrollbarsShown (false);
    CCIn_edit->setCaretVisible (true);
    CCIn_edit->setPopupMenuEnabled (false);
    CCIn_edit->setColour (TextEditor::backgroundColourId, Colour (0x2542a2c8));
    CCIn_edit->setText (TRANS("70"));

    CCOut_edit.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (CCOut_edit.get());
    CCOut_edit->setMultiLine (false);
    CCOut_edit->setReturnKeyStartsNewLine (false);
    CCOut_edit->setReadOnly (false);
    CCOut_edit->setScrollbarsShown (false);
    CCOut_edit->setCaretVisible (true);
    CCOut_edit->setPopupMenuEnabled (false);
    CCOut_edit->setColour (TextEditor::backgroundColourId, Colour (0x2542a2c8));
    CCOut_edit->setText (TRANS("48"));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (830, 24);


    //[Constructor] You can add your own custom stuff here..
	//synthState->controlStateDisplay = std::shared_ptr<ControlStateDisplay>(this);
	controlDisplayModel = std::shared_ptr<ControlStateDisplayModel>(synthState->controlDisplayModel.get());
	startTimer(GUIREFRESH_TIMEINTERVAL);
    //[/Constructor]
}

ControlStateDisplay::~ControlStateDisplay()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    Parameter_text = nullptr;
    label3 = nullptr;
    GroupName_text = nullptr;
    label5 = nullptr;
    CCIn_label = nullptr;
    CCOut_label = nullptr;
    Value_Edit = nullptr;
    CCIn_edit = nullptr;
    CCOut_edit = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ControlStateDisplay::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xb0323e44));

    //[UserPaint] Add your own custom painting code here..

    //[/UserPaint]
}

void ControlStateDisplay::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    Parameter_text->setBounds (232, 0, getWidth() - 570, 24);
    label5->setBounds ((((((getWidth() - 48) + 0 - 64) + 0 - 48) + 0 - 64) + 0 - 48) + 0 - 64, 0, 64, 24);
    CCIn_label->setBounds ((((getWidth() - 48) + 0 - 64) + 0 - 48) + 0 - 64, 0, 64, 24);
    CCOut_label->setBounds ((getWidth() - 48) + 0 - 64, 0, 64, 24);
    Value_Edit->setBounds (((((getWidth() - 48) + 0 - 64) + 0 - 48) + 0 - 64) + 0 - 48, 0, 48, 24);
    CCIn_edit->setBounds (((getWidth() - 48) + 0 - 64) + 0 - 48, 0, 48, 24);
    CCOut_edit->setBounds (getWidth() - 48, 0, 48, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ControlStateDisplay::Update()
{

}
void ControlStateDisplay::timerCallback()
{
	Parameter_text->setText(controlDisplayModel->parameterID, juce::NotificationType::dontSendNotification);
	GroupName_text->setText(controlDisplayModel->parameterGroup, juce::NotificationType::dontSendNotification);
	Value_Edit->setText(controlDisplayModel->parameterValue, juce::NotificationType::dontSendNotification);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ControlStateDisplay" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent, private Timer"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="830" initialHeight="24">
  <BACKGROUND backgroundColour="b0323e44"/>
  <LABEL name="new label" id="a579be9af7298cb3" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="152 0 80 24" bkgCol="50181f22" edTextCol="ff000000"
         edBkgCol="0" labelText="Parameter" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="1e18716abad2bc29" memberName="Parameter_text"
         virtualName="" explicitFocusOrder="0" pos="232 0 570M 24" bkgCol="25f0ffff"
         textCol="fff0ffff" edTextCol="ff000000" edBkgCol="0" labelText="WFA_PWM"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="new label" id="ddf7b13950d11ebf" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="0 0 64 24" bkgCol="50181f22" edTextCol="ff000000"
         edBkgCol="0" labelText="Group" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="179ecc7c0adbb30b" memberName="GroupName_text"
         virtualName="" explicitFocusOrder="0" pos="64 0 86 24" bkgCol="25f0ffff"
         textCol="fff0ffff" edTextCol="ff000000" edBkgCol="0" labelText="WFA"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="new label" id="6a4583e4a56bb802" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0r 0 64 24" posRelativeX="7abd47cb9a66661d"
         bkgCol="25181f22" edTextCol="ff000000" edBkgCol="0" labelText="Value"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="62aa170f7facad24" memberName="CCIn_label"
         virtualName="" explicitFocusOrder="0" pos="0r 0 64 24" posRelativeX="501460b9a378a69c"
         bkgCol="25181f22" edTextCol="ff000000" edBkgCol="0" labelText="CC in"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="cb7f4e27d9d9ff20" memberName="CCOut_label"
         virtualName="" explicitFocusOrder="0" pos="0r 0 64 24" posRelativeX="3e13a6513a5a74e5"
         bkgCol="25181f22" edTextCol="ff000000" edBkgCol="0" labelText="CC out"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <TEXTEDITOR name="new text editor" id="7abd47cb9a66661d" memberName="Value_Edit"
              virtualName="" explicitFocusOrder="0" pos="0r 0 48 24" posRelativeX="62aa170f7facad24"
              bkgcol="2542a2c8" initialText="127" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="501460b9a378a69c" memberName="CCIn_edit"
              virtualName="" explicitFocusOrder="0" pos="0r 0 48 24" posRelativeX="cb7f4e27d9d9ff20"
              bkgcol="2542a2c8" initialText="70" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="3e13a6513a5a74e5" memberName="CCOut_edit"
              virtualName="" explicitFocusOrder="0" pos="0Rr 0 48 24" bkgcol="2542a2c8"
              initialText="48" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="0" caret="1" popupmenu="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

