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

//[/MiscUserDefs]

//==============================================================================
ControlStateDisplay::ControlStateDisplay (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label_parameter.reset (new Label ("new label",
                                      TRANS("Par.ID")));
    addAndMakeVisible (label_parameter.get());
    label_parameter->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_parameter->setJustificationType (Justification::centred);
    label_parameter->setEditable (false, false, false);
    label_parameter->setColour (Label::backgroundColourId, Colour (0x50181f22));
    label_parameter->setColour (TextEditor::textColourId, Colours::black);
    label_parameter->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

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

    label_group.reset (new Label ("new label",
                                  TRANS("Group")));
    addAndMakeVisible (label_group.get());
    label_group->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_group->setJustificationType (Justification::centred);
    label_group->setEditable (false, false, false);
    label_group->setColour (Label::backgroundColourId, Colour (0x50181f22));
    label_group->setColour (TextEditor::textColourId, Colours::black);
    label_group->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_group->setBounds (0, 0, 48, 24);

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

    label_val.reset (new Label ("new label",
                                TRANS("Value")));
    addAndMakeVisible (label_val.get());
    label_val->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_val->setJustificationType (Justification::centred);
    label_val->setEditable (false, false, false);
    label_val->setColour (Label::backgroundColourId, Colour (0x25181f22));
    label_val->setColour (TextEditor::textColourId, Colours::black);
    label_val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    CCIn_label.reset (new Label ("new label",
                                 TRANS("In")));
    addAndMakeVisible (CCIn_label.get());
    CCIn_label->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    CCIn_label->setJustificationType (Justification::centred);
    CCIn_label->setEditable (false, false, false);
    CCIn_label->setColour (Label::backgroundColourId, Colour (0x25181f22));
    CCIn_label->setColour (TextEditor::textColourId, Colours::black);
    CCIn_label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    CCOut_label.reset (new Label ("new label",
                                  TRANS("Out")));
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

    CC_label.reset (new Label ("new label",
                               TRANS("Id")));
    addAndMakeVisible (CC_label.get());
    CC_label->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    CC_label->setJustificationType (Justification::centred);
    CC_label->setEditable (false, false, false);
    CC_label->setColour (Label::backgroundColourId, Colour (0x25181f22));
    CC_label->setColour (TextEditor::textColourId, Colours::black);
    CC_label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    text_ccID.reset (new Label ("new label",
                                TRANS("5")));
    addAndMakeVisible (text_ccID.get());
    text_ccID->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    text_ccID->setJustificationType (Justification::centred);
    text_ccID->setEditable (false, false, false);
    text_ccID->setColour (Label::backgroundColourId, Colour (0x25397daa));
    text_ccID->setColour (TextEditor::textColourId, Colour (0xff397daa));
    text_ccID->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    CCUnit_label.reset (new Label ("new label",
                                   TRANS("\n")));
    addAndMakeVisible (CCUnit_label.get());
    CCUnit_label->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    CCUnit_label->setJustificationType (Justification::centred);
    CCUnit_label->setEditable (false, false, false);
    CCUnit_label->setColour (Label::backgroundColourId, Colour (0x25181f22));
    CCUnit_label->setColour (TextEditor::textColourId, Colours::black);
    CCUnit_label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_info.reset (new Label ("new label",
                                 TRANS("Info")));
    addAndMakeVisible (label_info.get());
    label_info->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_info->setJustificationType (Justification::centred);
    label_info->setEditable (false, false, false);
    label_info->setColour (Label::backgroundColourId, Colour (0x50181f22));
    label_info->setColour (TextEditor::textColourId, Colours::black);
    label_info->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_info->setBounds (0, 28, 48, 24);

    text_info.reset (new Label ("new label",
                                String()));
    addAndMakeVisible (text_info.get());
    text_info->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    text_info->setJustificationType (Justification::centred);
    text_info->setEditable (false, false, false);
    text_info->setColour (Label::backgroundColourId, Colour (0x25646565));
    text_info->setColour (TextEditor::textColourId, Colours::black);
    text_info->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    text_class.reset (new Label ("new label",
                                 TRANS("CC Live")));
    addAndMakeVisible (text_class.get());
    text_class->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    text_class->setJustificationType (Justification::centred);
    text_class->setEditable (false, false, false);
    text_class->setColour (Label::backgroundColourId, Colour (0xff397daa));
    text_class->setColour (TextEditor::textColourId, Colour (0xff397daa));
    text_class->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (830, 52);


    //[Constructor] You can add your own custom stuff here..
	//synthState->controlStateDisplay = std::shared_ptr<ControlStateDisplay>(this);

	blockRefresh = false;
	controlDisplayModel = std::shared_ptr<ControlStateDisplayModel>(synthState->controlDisplayModel.get());
	CCOut_edit->onTextChange = [&, this] {
		this->Update();
	};
	CCIn_edit->onTextChange = [&, this] {
		this->Update();
	};
	Value_Edit->onTextChange = [&, this] {
		this->Update();
	};
	startTimer(GUIREFRESH_TIMEINTERVAL);

    //[/Constructor]
}

ControlStateDisplay::~ControlStateDisplay()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label_parameter = nullptr;
    Parameter_text = nullptr;
    label_group = nullptr;
    GroupName_text = nullptr;
    label_val = nullptr;
    CCIn_label = nullptr;
    CCOut_label = nullptr;
    Value_Edit = nullptr;
    CCIn_edit = nullptr;
    CCOut_edit = nullptr;
    CC_label = nullptr;
    text_ccID = nullptr;
    CCUnit_label = nullptr;
    label_info = nullptr;
    text_info = nullptr;
    text_class = nullptr;


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

    label_parameter->setBounds ((0 + 48) + 160, 0, 62, 24);
    Parameter_text->setBounds (((0 + 48) + 160) + 62, 0, getWidth() - 600, 24);
    GroupName_text->setBounds (0 + 48, 0, 160, 24);
    label_val->setBounds ((((0 + 48) + 160) + 62) + (getWidth() - 600), 0, 42, 24);
    CCIn_label->setBounds (((((((0 + 48) + 160) + 62) + (getWidth() - 600)) + 42) + 36) + 24, 0, 24, 24);
    CCOut_label->setBounds (((((((((((0 + 48) + 160) + 62) + (getWidth() - 600)) + 42) + 36) + 24) + 24) + 24) + 24) + 24, 0, 36, 24);
    Value_Edit->setBounds (((((0 + 48) + 160) + 62) + (getWidth() - 600)) + 42, 0, 36, 24);
    CCIn_edit->setBounds ((((((((0 + 48) + 160) + 62) + (getWidth() - 600)) + 42) + 36) + 24) + 24, 0, 24, 24);
    CCOut_edit->setBounds ((((((((((((0 + 48) + 160) + 62) + (getWidth() - 600)) + 42) + 36) + 24) + 24) + 24) + 24) + 24) + 36, 0, 24, 24);
    CC_label->setBounds (((((((((0 + 48) + 160) + 62) + (getWidth() - 600)) + 42) + 36) + 24) + 24) + 24, 0, 24, 24);
    text_ccID->setBounds ((((((((((0 + 48) + 160) + 62) + (getWidth() - 600)) + 42) + 36) + 24) + 24) + 24) + 24, 0, 24, 24);
    CCUnit_label->setBounds ((((((0 + 48) + 160) + 62) + (getWidth() - 600)) + 42) + 36, 0, 24, 24);
    text_info->setBounds (48, 28, getWidth() - 48, 24);
    text_class->setBounds ((((((((((0 + 48) + 160) + 62) + (getWidth() - 600)) + 42) + 36) + 24) + 24) + 24) + 24 - -86, 0, getWidth() - 762, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ControlStateDisplay::Update()
{
	if (!isValueUpdateCall) {

		//auto val_in = Value_Edit->getText();

		blockRefresh = true;
		controlDisplayModel->UpdateParameter(Value_Edit->getText(), CCIn_edit->getText(), CCOut_edit->getText());
		blockRefresh = false;
	}
}
void ControlStateDisplay::timerCallback()
{
	if (blockRefresh) return;

	if (hasKeyboardFocus(true)) {
		return;
	}

	isValueUpdateCall = true;
	Parameter_text->setText(controlDisplayModel->parameterID, juce::NotificationType::dontSendNotification);
	GroupName_text->setText(controlDisplayModel->parameterGroup, juce::NotificationType::dontSendNotification);




	//if (!Value_Edit->isTextInputActive())
		Value_Edit->setText(controlDisplayModel->parameterValue, juce::NotificationType::dontSendNotification);

	if (controlDisplayModel->isCCParameter) {
		if (!CCIn_edit->isEnabled()) CCIn_edit->setEnabled(true);
		if (!CCOut_edit->isEnabled()) CCOut_edit->setEnabled(true);
		//if (!CCIn_edit->i)
			CCIn_edit->setText(juce::String(controlDisplayModel->parameterCCIn), juce::NotificationType::dontSendNotification);
		//if (!CCOut_edit->isTextInputActive())
			CCOut_edit->setText(juce::String(controlDisplayModel->parameterCCOut), juce::NotificationType::dontSendNotification);
		text_ccID->setText(juce::String(controlDisplayModel->parameterCC), juce::NotificationType::dontSendNotification);
	}
	else {
		if (CCIn_edit->isEnabled())  CCIn_edit->setEnabled(false);
		if (CCOut_edit->isEnabled()) CCOut_edit->setEnabled(false);

		CCIn_edit->setText(juce::String(""), juce::NotificationType::dontSendNotification);
		CCOut_edit->setText(juce::String(""), juce::NotificationType::dontSendNotification);
		text_ccID->setText(juce::String(controlDisplayModel->parameterCC), juce::NotificationType::dontSendNotification);
	}
	isValueUpdateCall = false;
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
                 overlayOpacity="0.330" fixedSize="1" initialWidth="830" initialHeight="52">
  <BACKGROUND backgroundColour="b0323e44"/>
  <LABEL name="new label" id="a579be9af7298cb3" memberName="label_parameter"
         virtualName="" explicitFocusOrder="0" pos="0R 0 62 24" posRelativeX="179ecc7c0adbb30b"
         bkgCol="50181f22" edTextCol="ff000000" edBkgCol="0" labelText="Par.ID"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="1e18716abad2bc29" memberName="Parameter_text"
         virtualName="" explicitFocusOrder="0" pos="0R 0 600M 24" posRelativeX="a579be9af7298cb3"
         bkgCol="25f0ffff" textCol="fff0ffff" edTextCol="ff000000" edBkgCol="0"
         labelText="WFA_PWM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="ddf7b13950d11ebf" memberName="label_group"
         virtualName="" explicitFocusOrder="0" pos="0 0 48 24" bkgCol="50181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="Group" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="179ecc7c0adbb30b" memberName="GroupName_text"
         virtualName="" explicitFocusOrder="0" pos="0R 0 160 24" posRelativeX="ddf7b13950d11ebf"
         bkgCol="25f0ffff" textCol="fff0ffff" edTextCol="ff000000" edBkgCol="0"
         labelText="WFA" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="6a4583e4a56bb802" memberName="label_val"
         virtualName="" explicitFocusOrder="0" pos="0R 0 42 24" posRelativeX="1e18716abad2bc29"
         bkgCol="25181f22" edTextCol="ff000000" edBkgCol="0" labelText="Value"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="62aa170f7facad24" memberName="CCIn_label"
         virtualName="" explicitFocusOrder="0" pos="0R 0 24 24" posRelativeX="d77ace1ed8c5ef0a"
         bkgCol="25181f22" edTextCol="ff000000" edBkgCol="0" labelText="In"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="cb7f4e27d9d9ff20" memberName="CCOut_label"
         virtualName="" explicitFocusOrder="0" pos="0R 0 36 24" posRelativeX="448107c45cacbe"
         bkgCol="25181f22" edTextCol="ff000000" edBkgCol="0" labelText="Out"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <TEXTEDITOR name="new text editor" id="7abd47cb9a66661d" memberName="Value_Edit"
              virtualName="" explicitFocusOrder="0" pos="0R 0 36 24" posRelativeX="6a4583e4a56bb802"
              bkgcol="2542a2c8" initialText="127" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="501460b9a378a69c" memberName="CCIn_edit"
              virtualName="" explicitFocusOrder="0" pos="0R 0 24 24" posRelativeX="62aa170f7facad24"
              bkgcol="2542a2c8" initialText="70" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="3e13a6513a5a74e5" memberName="CCOut_edit"
              virtualName="" explicitFocusOrder="0" pos="0R 0 24 24" posRelativeX="cb7f4e27d9d9ff20"
              bkgcol="2542a2c8" initialText="48" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="0"/>
  <LABEL name="new label" id="dba2040aff782f3a" memberName="CC_label"
         virtualName="" explicitFocusOrder="0" pos="0R 0 24 24" posRelativeX="501460b9a378a69c"
         bkgCol="25181f22" edTextCol="ff000000" edBkgCol="0" labelText="Id"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="448107c45cacbe" memberName="text_ccID" virtualName=""
         explicitFocusOrder="0" pos="0R 0 24 24" posRelativeX="dba2040aff782f3a"
         bkgCol="25397daa" edTextCol="ff397daa" edBkgCol="0" labelText="5"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="d77ace1ed8c5ef0a" memberName="CCUnit_label"
         virtualName="" explicitFocusOrder="0" pos="0R 0 24 24" posRelativeX="7abd47cb9a66661d"
         bkgCol="25181f22" edTextCol="ff000000" edBkgCol="0" labelText="&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="a030a5898f1f0106" memberName="label_info"
         virtualName="" explicitFocusOrder="0" pos="0 28 48 24" bkgCol="50181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="Info" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="9d734f5c82f07f7e" memberName="text_info"
         virtualName="" explicitFocusOrder="0" pos="48 28 48M 24" bkgCol="25646565"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="6f1fef3252007f7c" memberName="text_class"
         virtualName="" explicitFocusOrder="0" pos="-86R 0 762M 24" posRelativeX="dba2040aff782f3a"
         bkgCol="ff397daa" edTextCol="ff397daa" edBkgCol="0" labelText="CC Live"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

