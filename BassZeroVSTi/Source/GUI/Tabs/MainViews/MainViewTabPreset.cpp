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

#include "MainViewTabPreset.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainViewTabPreset::MainViewTabPreset ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    presetDefinitionDisplay.reset (new PresetDefinitionEditor (&state->presetSelected));
    addAndMakeVisible (presetDefinitionDisplay.get());
    label5.reset (new Label ("new label",
                             TRANS("Type")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (Label::backgroundColourId, Colours::azure);
    label5->setColour (Label::textColourId, Colour (0xff181f22));
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (312, 0, 48, 24);

    text_preset_name.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (text_preset_name.get());
    text_preset_name->setTooltip (TRANS("Title of the Operation Mode"));
    text_preset_name->setMultiLine (false);
    text_preset_name->setReturnKeyStartsNewLine (false);
    text_preset_name->setReadOnly (false);
    text_preset_name->setScrollbarsShown (false);
    text_preset_name->setCaretVisible (true);
    text_preset_name->setPopupMenuEnabled (true);
    text_preset_name->setText (TRANS("Kick drum"));

    text_preset_name->setBounds (368, 0, 200, 24);

    label2.reset (new Label ("new label",
                             TRANS("Macro")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colours::azure);
    label2->setColour (Label::textColourId, Colour (0xff181f22));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (312, 280, 48, 24);

    text_preset_name2.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (text_preset_name2.get());
    text_preset_name2->setTooltip (TRANS("Title of the Operation Mode"));
    text_preset_name2->setMultiLine (true);
    text_preset_name2->setReturnKeyStartsNewLine (false);
    text_preset_name2->setReadOnly (true);
    text_preset_name2->setScrollbarsShown (false);
    text_preset_name2->setCaretVisible (false);
    text_preset_name2->setPopupMenuEnabled (true);
    text_preset_name2->setText (TRANS("Autogenerated description: how OPM macros are linked, how modulation macros are linked"));

    text_preset_name2->setBounds (312, 32, 280, 240);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainViewTabPreset::~MainViewTabPreset()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    presetDefinitionDisplay = nullptr;
    label5 = nullptr;
    text_preset_name = nullptr;
    label2 = nullptr;
    text_preset_name2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainViewTabPreset::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainViewTabPreset::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    presetDefinitionDisplay->setBounds (0, 0, proportionOfWidth (0.5000f), getHeight() - 0);
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

<JUCER_COMPONENT documentType="Component" className="MainViewTabPreset" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="" id="b0a6f0fa687bc200" memberName="presetDefinitionDisplay"
             virtualName="" explicitFocusOrder="0" pos="0 0 50% 0M" sourceFile="../../General/PresetDefinitionEditor.cpp"
             constructorParams="&amp;state-&gt;presetSelected"/>
  <LABEL name="new label" id="cdcd778c5d2cc957" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="312 0 48 24" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="Type" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="70ba1419acb8f72c" memberName="text_preset_name"
              virtualName="" explicitFocusOrder="0" pos="368 0 200 24" tooltip="Title of the Operation Mode"
              initialText="Kick drum" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="0" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="9c95e87e80ae3c44" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="312 280 48 24" bkgCol="fff0ffff"
         textCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="Macro"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="2a170bd72b28b984" memberName="text_preset_name2"
              virtualName="" explicitFocusOrder="0" pos="312 32 280 240" tooltip="Title of the Operation Mode"
              initialText="Autogenerated description: how OPM macros are linked, how modulation macros are linked"
              multiline="1" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
