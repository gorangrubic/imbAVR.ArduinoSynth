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

#include "MainViewTabConfiguration.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainViewTabConfiguration::MainViewTabConfiguration ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    label3.reset (new Label ("new label",
                             TRANS("Device needles")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label3->setColour (TextEditor::textColourId, Colour (0xff495358));
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (16, 32, 180, 24);

    label5.reset (new Label ("new label",
                             TRANS("Needle 1")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (Label::backgroundColourId, Colours::azure);
    label5->setColour (Label::textColourId, Colour (0xff181f22));
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (464, 424, 112, 24);

    text_name2.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (text_name2.get());
    text_name2->setTooltip (TRANS("Title of the Operation Mode"));
    text_name2->setMultiLine (false);
    text_name2->setReturnKeyStartsNewLine (false);
    text_name2->setReadOnly (false);
    text_name2->setScrollbarsShown (true);
    text_name2->setCaretVisible (true);
    text_name2->setPopupMenuEnabled (true);
    text_name2->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    text_name2->setText (TRANS("Arduino Pro Micro"));

    text_name2->setBounds (584, 424, 176, 24);

    component.reset (new PathBrowser ("Presets", ""));
    addAndMakeVisible (component.get());
    component->setBounds (208, 32, 440, 24);

    needle_device_1.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_device_1.get());
    needle_device_1->setTooltip (TRANS("Title of the Operation Mode"));
    needle_device_1->setMultiLine (false);
    needle_device_1->setReturnKeyStartsNewLine (false);
    needle_device_1->setReadOnly (false);
    needle_device_1->setScrollbarsShown (false);
    needle_device_1->setCaretVisible (true);
    needle_device_1->setPopupMenuEnabled (true);
    needle_device_1->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    needle_device_1->setText (TRANS("Pro Micro"));

    needle_device_1->setBounds (16, 56, 180, 24);

    needle_device_2.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_device_2.get());
    needle_device_2->setTooltip (TRANS("Title of the Operation Mode"));
    needle_device_2->setMultiLine (false);
    needle_device_2->setReturnKeyStartsNewLine (false);
    needle_device_2->setReadOnly (false);
    needle_device_2->setScrollbarsShown (false);
    needle_device_2->setCaretVisible (true);
    needle_device_2->setPopupMenuEnabled (true);
    needle_device_2->setColour (TextEditor::backgroundColourId, Colour (0xff1d2427));
    needle_device_2->setText (TRANS("BassZero"));

    needle_device_2->setBounds (16, 80, 180, 24);

    needle_device_3.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_device_3.get());
    needle_device_3->setTooltip (TRANS("Title of the Operation Mode"));
    needle_device_3->setMultiLine (false);
    needle_device_3->setReturnKeyStartsNewLine (false);
    needle_device_3->setReadOnly (false);
    needle_device_3->setScrollbarsShown (false);
    needle_device_3->setCaretVisible (true);
    needle_device_3->setPopupMenuEnabled (true);
    needle_device_3->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    needle_device_3->setText (String());

    needle_device_3->setBounds (16, 104, 180, 24);

    label7.reset (new Label ("new label",
                             TRANS("MIDI Input needles")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label7->setColour (TextEditor::textColourId, Colour (0xff495358));
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label7->setBounds (16, 133, 180, 24);

    needle_input_1.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_input_1.get());
    needle_input_1->setTooltip (TRANS("Title of the Operation Mode"));
    needle_input_1->setMultiLine (false);
    needle_input_1->setReturnKeyStartsNewLine (false);
    needle_input_1->setReadOnly (false);
    needle_input_1->setScrollbarsShown (false);
    needle_input_1->setCaretVisible (true);
    needle_input_1->setPopupMenuEnabled (true);
    needle_input_1->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    needle_input_1->setText (TRANS("Novation"));

    needle_input_1->setBounds (16, 157, 180, 24);

    needle_device_4.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_device_4.get());
    needle_device_4->setTooltip (TRANS("Title of the Operation Mode"));
    needle_device_4->setMultiLine (false);
    needle_device_4->setReturnKeyStartsNewLine (false);
    needle_device_4->setReadOnly (false);
    needle_device_4->setScrollbarsShown (false);
    needle_device_4->setCaretVisible (true);
    needle_device_4->setPopupMenuEnabled (true);
    needle_device_4->setColour (TextEditor::backgroundColourId, Colour (0xff1d2427));
    needle_device_4->setText (TRANS("UC33"));

    needle_device_4->setBounds (16, 181, 180, 24);

    needle_device_5.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_device_5.get());
    needle_device_5->setTooltip (TRANS("Title of the Operation Mode"));
    needle_device_5->setMultiLine (false);
    needle_device_5->setReturnKeyStartsNewLine (false);
    needle_device_5->setReadOnly (false);
    needle_device_5->setScrollbarsShown (false);
    needle_device_5->setCaretVisible (true);
    needle_device_5->setPopupMenuEnabled (true);
    needle_device_5->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    needle_device_5->setText (String());

    needle_device_5->setBounds (16, 205, 180, 24);

    label8.reset (new Label ("new label",
                             TRANS("MIDI Output needles")));
    addAndMakeVisible (label8.get());
    label8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label8->setColour (TextEditor::textColourId, Colour (0xff495358));
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label8->setBounds (16, 228, 180, 24);

    needle_output_1.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_output_1.get());
    needle_output_1->setTooltip (TRANS("Title of the Operation Mode"));
    needle_output_1->setMultiLine (false);
    needle_output_1->setReturnKeyStartsNewLine (false);
    needle_output_1->setReadOnly (false);
    needle_output_1->setScrollbarsShown (false);
    needle_output_1->setCaretVisible (true);
    needle_output_1->setPopupMenuEnabled (true);
    needle_output_1->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    needle_output_1->setText (TRANS("MIDI Out"));

    needle_output_1->setBounds (16, 252, 180, 24);

    needle_output_2.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_output_2.get());
    needle_output_2->setTooltip (TRANS("Title of the Operation Mode"));
    needle_output_2->setMultiLine (false);
    needle_output_2->setReturnKeyStartsNewLine (false);
    needle_output_2->setReadOnly (false);
    needle_output_2->setScrollbarsShown (false);
    needle_output_2->setCaretVisible (true);
    needle_output_2->setPopupMenuEnabled (true);
    needle_output_2->setColour (TextEditor::backgroundColourId, Colour (0xff1d2427));
    needle_output_2->setText (String());

    needle_output_2->setBounds (16, 276, 180, 24);

    needle_output_3.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_output_3.get());
    needle_output_3->setTooltip (TRANS("Title of the Operation Mode"));
    needle_output_3->setMultiLine (false);
    needle_output_3->setReturnKeyStartsNewLine (false);
    needle_output_3->setReadOnly (false);
    needle_output_3->setScrollbarsShown (false);
    needle_output_3->setCaretVisible (true);
    needle_output_3->setPopupMenuEnabled (true);
    needle_output_3->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    needle_output_3->setText (String());

    needle_output_3->setBounds (16, 300, 180, 24);

    toggle_log_to_file.reset (new ToggleButton (String()));
    addAndMakeVisible (toggle_log_to_file.get());
    toggle_log_to_file->setButtonText (TRANS("Save log to file"));
    toggle_log_to_file->addListener (this);

    toggle_log_to_file->setBounds (208, 272, 150, 24);

    toggle_factory_readonly.reset (new ToggleButton (String()));
    addAndMakeVisible (toggle_factory_readonly.get());
    toggle_factory_readonly->setButtonText (TRANS("Factory presets read-only"));
    toggle_factory_readonly->addListener (this);

    toggle_factory_readonly->setBounds (208, 296, 240, 24);

    label.reset (new Label ("new label",
                            TRANS("Auto-select needles")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (16, 8, 150, 24);

    label9.reset (new Label ("new label",
                             TRANS("VSTi workspace path")));
    addAndMakeVisible (label9.get());
    label9->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label9->setBounds (208, 8, 150, 24);

    component2.reset (new PathBrowser ("Presets", ""));
    addAndMakeVisible (component2.get());
    component2->setBounds (210, 83, 440, 24);

    label10.reset (new Label ("new label",
                              TRANS("Default library path")));
    addAndMakeVisible (label10.get());
    label10->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label10->setBounds (210, 59, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (840, 340);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainViewTabConfiguration::~MainViewTabConfiguration()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label3 = nullptr;
    label5 = nullptr;
    text_name2 = nullptr;
    component = nullptr;
    needle_device_1 = nullptr;
    needle_device_2 = nullptr;
    needle_device_3 = nullptr;
    label7 = nullptr;
    needle_input_1 = nullptr;
    needle_device_4 = nullptr;
    needle_device_5 = nullptr;
    label8 = nullptr;
    needle_output_1 = nullptr;
    needle_output_2 = nullptr;
    needle_output_3 = nullptr;
    toggle_log_to_file = nullptr;
    toggle_factory_readonly = nullptr;
    label = nullptr;
    label9 = nullptr;
    component2 = nullptr;
    label10 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainViewTabConfiguration::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainViewTabConfiguration::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainViewTabConfiguration::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggle_log_to_file.get())
    {
        //[UserButtonCode_toggle_log_to_file] -- add your button handler code here..
        //[/UserButtonCode_toggle_log_to_file]
    }
    else if (buttonThatWasClicked == toggle_factory_readonly.get())
    {
        //[UserButtonCode_toggle_factory_readonly] -- add your button handler code here..
        //[/UserButtonCode_toggle_factory_readonly]
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

<JUCER_COMPONENT documentType="Component" className="MainViewTabConfiguration"
                 componentName="" parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="840"
                 initialHeight="340">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="1ec85516c8bd1f70" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="16 32 180 24" bkgCol="ff397daa" edTextCol="ff495358"
         edBkgCol="0" labelText="Device needles" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="cdcd778c5d2cc957" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="464 424 112 24" bkgCol="fff0ffff"
         textCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="Needle 1"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="70ba1419acb8f72c" memberName="text_name2"
              virtualName="" explicitFocusOrder="0" pos="584 424 176 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="Arduino Pro Micro" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <JUCERCOMP name="" id="d2dfb90203789c8b" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="208 32 440 24" sourceFile="PathBrowser.cpp"
             constructorParams="&quot;Presets&quot;, &quot;&quot;"/>
  <TEXTEDITOR name="new text editor" id="922d1416b90b6e43" memberName="needle_device_1"
              virtualName="" explicitFocusOrder="0" pos="16 56 180 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="Pro Micro" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="723f5aa1f4bf2e82" memberName="needle_device_2"
              virtualName="" explicitFocusOrder="0" pos="16 80 180 24" tooltip="Title of the Operation Mode"
              bkgcol="ff1d2427" initialText="BassZero" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="44ddf2c87a066ee5" memberName="needle_device_3"
              virtualName="" explicitFocusOrder="0" pos="16 104 180 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="8c2150196038fc1f" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="16 133 180 24" bkgCol="ff397daa"
         edTextCol="ff495358" edBkgCol="0" labelText="MIDI Input needles"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="2f3c4c9d2266a62d" memberName="needle_input_1"
              virtualName="" explicitFocusOrder="0" pos="16 157 180 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="Novation" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="285433645b4f5a4e" memberName="needle_device_4"
              virtualName="" explicitFocusOrder="0" pos="16 181 180 24" tooltip="Title of the Operation Mode"
              bkgcol="ff1d2427" initialText="UC33" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="83dd51f88b339445" memberName="needle_device_5"
              virtualName="" explicitFocusOrder="0" pos="16 205 180 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="168e0cc17ec7a6c1" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="16 228 180 24" bkgCol="ff397daa"
         edTextCol="ff495358" edBkgCol="0" labelText="MIDI Output needles"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="1c9074d6a5225949" memberName="needle_output_1"
              virtualName="" explicitFocusOrder="0" pos="16 252 180 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="MIDI Out" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="705673ce5623efe5" memberName="needle_output_2"
              virtualName="" explicitFocusOrder="0" pos="16 276 180 24" tooltip="Title of the Operation Mode"
              bkgcol="ff1d2427" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="355fb1694b45a080" memberName="needle_output_3"
              virtualName="" explicitFocusOrder="0" pos="16 300 180 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="" id="b938ea99f84115c4" memberName="toggle_log_to_file"
                virtualName="" explicitFocusOrder="0" pos="208 272 150 24" buttonText="Save log to file"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="" id="d98817afb6da0945" memberName="toggle_factory_readonly"
                virtualName="" explicitFocusOrder="0" pos="208 296 240 24" buttonText="Factory presets read-only"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="18d0c664b6949a90" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="16 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Auto-select needles" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="b7dac7da1bace239" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="208 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="VSTi workspace path" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <JUCERCOMP name="" id="4773bf4b55a56372" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="210 83 440 24" sourceFile="PathBrowser.cpp"
             constructorParams="&quot;Presets&quot;, &quot;&quot;"/>
  <LABEL name="new label" id="6d09ce8849b41101" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="210 59 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Default library path" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

