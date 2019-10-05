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

#include "PresetDefinitionEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PresetDefinitionEditor::PresetDefinitionEditor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label5.reset (new Label ("new label",
                             TRANS("Name")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (Label::backgroundColourId, Colours::azure);
    label5->setColour (Label::textColourId, Colour (0xff181f22));
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (0, 0, 48, 24);

    text_preset_name.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (text_preset_name.get());
    text_preset_name->setTooltip (TRANS("Title of the Operation Mode"));
    text_preset_name->setMultiLine (false);
    text_preset_name->setReturnKeyStartsNewLine (false);
    text_preset_name->setReadOnly (false);
    text_preset_name->setScrollbarsShown (false);
    text_preset_name->setCaretVisible (true);
    text_preset_name->setPopupMenuEnabled (true);
    text_preset_name->setText (TRANS("Bass"));

    label6.reset (new Label ("new label",
                             TRANS("Note\n")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (Label::backgroundColourId, Colours::azure);
    label6->setColour (Label::textColourId, Colour (0xff181f22));
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (0, 32, 48, 24);

    text_preset_note.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (text_preset_note.get());
    text_preset_note->setTooltip (TRANS("Title of the Operation Mode"));
    text_preset_note->setMultiLine (true);
    text_preset_note->setReturnKeyStartsNewLine (true);
    text_preset_note->setReadOnly (false);
    text_preset_note->setScrollbarsShown (true);
    text_preset_note->setCaretVisible (true);
    text_preset_note->setPopupMenuEnabled (true);
    text_preset_note->setText (TRANS("Progressive trance bass line with light punch dot"));

    label2.reset (new Label ("new label",
                             TRANS("File")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colours::azure);
    label2->setColour (Label::textColourId, Colour (0xff181f22));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    text_preset_file.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (text_preset_file.get());
    text_preset_file->setTooltip (TRANS("Title of the Operation Mode"));
    text_preset_file->setMultiLine (false);
    text_preset_file->setReturnKeyStartsNewLine (false);
    text_preset_file->setReadOnly (false);
    text_preset_file->setScrollbarsShown (false);
    text_preset_file->setCaretVisible (true);
    text_preset_file->setPopupMenuEnabled (true);
    text_preset_file->setText (TRANS("Bass.bzs"));

    label4.reset (new Label ("new label",
                             TRANS("Prog. ID")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (Label::backgroundColourId, Colours::azure);
    label4->setColour (Label::textColourId, Colour (0xff181f22));
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    text_preset_file2.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (text_preset_file2.get());
    text_preset_file2->setTooltip (TRANS("Title of the Operation Mode"));
    text_preset_file2->setMultiLine (false);
    text_preset_file2->setReturnKeyStartsNewLine (false);
    text_preset_file2->setReadOnly (true);
    text_preset_file2->setScrollbarsShown (false);
    text_preset_file2->setCaretVisible (false);
    text_preset_file2->setPopupMenuEnabled (true);
    text_preset_file2->setText (TRANS("1"));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (450, 200);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PresetDefinitionEditor::~PresetDefinitionEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label5 = nullptr;
    text_preset_name = nullptr;
    label6 = nullptr;
    text_preset_note = nullptr;
    label2 = nullptr;
    text_preset_file = nullptr;
    label4 = nullptr;
    text_preset_file2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PresetDefinitionEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PresetDefinitionEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    text_preset_name->setBounds (56, 0, getWidth() - 56, 24);
    text_preset_note->setBounds (56, 32, getWidth() - 54, getHeight() - 64);
    label2->setBounds (0, getHeight() - 24, 48, 24);
    text_preset_file->setBounds (56, getHeight() - 24, getWidth() - 224, 24);
    label4->setBounds (getWidth() - 160, getHeight() - 24, 64, 24);
    text_preset_file2->setBounds (getWidth() - 88, getHeight() - 24, 88, 24);
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

<JUCER_COMPONENT documentType="Component" className="PresetDefinitionEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="450" initialHeight="200">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="cdcd778c5d2cc957" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0 0 48 24" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="Name" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="70ba1419acb8f72c" memberName="text_preset_name"
              virtualName="" explicitFocusOrder="0" pos="56 0 56M 24" tooltip="Title of the Operation Mode"
              initialText="Bass" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="0" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="9075a608f9f34378" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="0 32 48 24" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="Note&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="fb2c4953e2b66de1" memberName="text_preset_note"
              virtualName="" explicitFocusOrder="0" pos="56 32 54M 64M" tooltip="Title of the Operation Mode"
              initialText="Progressive trance bass line with light punch dot"
              multiline="1" retKeyStartsLine="1" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="a7c9aa2aa7792ba7" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 24R 48 24" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="File" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="a4caf6f438c8677e" memberName="text_preset_file"
              virtualName="" explicitFocusOrder="0" pos="56 24R 224M 24" tooltip="Title of the Operation Mode"
              initialText="Bass.bzs" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="0" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="8dc61628e0277b0e" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="160R 24R 64 24" bkgCol="fff0ffff"
         textCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="Prog. ID"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="d99c560a59952b15" memberName="text_preset_file2"
              virtualName="" explicitFocusOrder="0" pos="0Rr 24R 88 24" tooltip="Title of the Operation Mode"
              initialText="1" multiline="0" retKeyStartsLine="0" readonly="1"
              scrollbars="0" caret="0" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

