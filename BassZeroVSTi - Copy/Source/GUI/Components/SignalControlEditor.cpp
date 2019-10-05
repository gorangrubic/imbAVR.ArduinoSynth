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

#include "SignalControlEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SignalControlEditor::SignalControlEditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    toggle_PWMMode.reset (new ToggleButton ("PWM mode"));
    addAndMakeVisible (toggle_PWMMode.get());
    toggle_PWMMode->setButtonText (TRANS("PWM Cycle mode"));
    toggle_PWMMode->addListener (this);
    toggle_PWMMode->setToggleState (true, dontSendNotification);

    toggle_PWMMode->setBounds (8, 192, 120, 18);

    toggle_PitchRelative.reset (new ToggleButton ("PWM mode"));
    addAndMakeVisible (toggle_PitchRelative.get());
    toggle_PitchRelative->setButtonText (TRANS("Relative to Note"));
    toggle_PitchRelative->addListener (this);
    toggle_PitchRelative->setToggleState (true, dontSendNotification);

    toggle_PitchRelative->setBounds (8, 144, 150, 18);

    label.reset (new Label ("new label",
                            TRANS("Pitch Unit")));
    addAndMakeVisible (label.get());
    label->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (8, 96, 140, 16);

    PitchModulation.reset (new SignalChangeEditor());
    addAndMakeVisible (PitchModulation.get());
    PulsePattern.reset (new PatternEditor8bit());
    addAndMakeVisible (PulsePattern.get());
    PulsePattern->setBounds (8, 240, 132, 16);

    PhaseModulation.reset (new SignalChangeEditor());
    addAndMakeVisible (PhaseModulation.get());
    PhaseModulation->setBounds (192, 40, 300, 86);

    toggle_DoublePrescalar.reset (new ToggleButton ("PWM mode"));
    addAndMakeVisible (toggle_DoublePrescalar.get());
    toggle_DoublePrescalar->setButtonText (TRANS("Double prescalar"));
    toggle_DoublePrescalar->addListener (this);

    toggle_DoublePrescalar->setBounds (8, 168, 120, 18);

    PWMModulation.reset (new SignalChangeEditor());
    addAndMakeVisible (PWMModulation.get());
    toggle_Enabled.reset (new ToggleButton ("Phase modulation"));
    addAndMakeVisible (toggle_Enabled.get());
    toggle_Enabled->setButtonText (TRANS("Enabled"));
    toggle_Enabled->addListener (this);

    toggle_Enabled->setBounds (8, 40, 80, 18);

    ModBytePattern.reset (new PatternEditor8bit());
    addAndMakeVisible (ModBytePattern.get());
    ModBytePattern->setBounds (8, 296, 132, 16);

    label3.reset (new Label ("new label",
                             TRANS("Mod byte")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (8, 280, 132, 12);

    toggle_Sync.reset (new ToggleButton ("PWM mode"));
    addAndMakeVisible (toggle_Sync.get());
    toggle_Sync->setButtonText (TRANS("Sync oscilator"));
    toggle_Sync->addListener (this);
    toggle_Sync->setToggleState (true, dontSendNotification);

    toggle_Sync->setBounds (8, 64, 120, 18);

    label2.reset (new Label ("new label",
                             TRANS("PHASE\n")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0xff42a2c8));
    label2->setColour (Label::textColourId, Colours::azure);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4.reset (new Label ("new label",
                             TRANS("PWM")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (Label::backgroundColourId, Colour (0xff42a2c8));
    label4->setColour (Label::textColourId, Colours::azure);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5.reset (new Label ("new label",
                             TRANS("PITCH")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (Label::backgroundColourId, Colour (0xff42a2c8));
    label5->setColour (Label::textColourId, Colours::azure);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PitchUnit.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (PitchUnit.get());
    PitchUnit->setEditableText (false);
    PitchUnit->setJustificationType (Justification::centredLeft);
    PitchUnit->setTextWhenNothingSelected (TRANS("Semitone"));
    PitchUnit->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    PitchUnit->addItem (TRANS("Semitone"), 1);
    PitchUnit->addItem (TRANS("Octave"), 2);
    PitchUnit->addItem (TRANS("1 Hz"), 3);
    PitchUnit->addItem (TRANS("10 Hz"), 4);
    PitchUnit->addItem (TRANS("100 Hz"), 5);
    PitchUnit->addItem (TRANS("1000 Hz"), 6);
    PitchUnit->addListener (this);

    PitchUnit->setBounds (8, 112, 140, 18);

    label6.reset (new Label ("new label",
                             TRANS("Waveform Pattern")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (8, 224, 132, 12);

    label7.reset (new Label ("new label",
                             TRANS("SIGNAL GENERATOR MODULATIONS")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (Label::backgroundColourId, Colours::azure);
    label7->setColour (Label::textColourId, Colour (0xff181f22));
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_SignalName.reset (new Label ("new label",
                                       TRANS("WF A")));
    addAndMakeVisible (label_SignalName.get());
    label_SignalName->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_SignalName->setJustificationType (Justification::centredLeft);
    label_SignalName->setEditable (false, false, false);
    label_SignalName->setColour (Label::backgroundColourId, Colour (0xff42a2c8));
    label_SignalName->setColour (Label::textColourId, Colours::azure);
    label_SignalName->setColour (TextEditor::textColourId, Colours::black);
    label_SignalName->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (500, 330);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SignalControlEditor::~SignalControlEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    toggle_PWMMode = nullptr;
    toggle_PitchRelative = nullptr;
    label = nullptr;
    PitchModulation = nullptr;
    PulsePattern = nullptr;
    PhaseModulation = nullptr;
    toggle_DoublePrescalar = nullptr;
    PWMModulation = nullptr;
    toggle_Enabled = nullptr;
    ModBytePattern = nullptr;
    label3 = nullptr;
    toggle_Sync = nullptr;
    label2 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    PitchUnit = nullptr;
    label6 = nullptr;
    label7 = nullptr;
    label_SignalName = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SignalControlEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SignalControlEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    PitchModulation->setBounds ((192 + 0) + 0, (40 + 86 - -12) + 86 - -12, 290, 86);
    PWMModulation->setBounds (192 + 0, 40 + 86 - -12, 290, 86);
    label2->setBounds (192 + 0, 40 + 0, 76, 18);
    label4->setBounds ((192 + 0) + 0, (40 + 86 - -12) + 0, 76, 18);
    label5->setBounds (((192 + 0) + 0) + 0, ((40 + 86 - -12) + 86 - -12) + 0, 76, 18);
    label7->setBounds (192 + 0, 40 + -32, 300, 24);
    label_SignalName->setBounds (192 + -184, 40 + -32, 170, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SignalControlEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggle_PWMMode.get())
    {
        //[UserButtonCode_toggle_PWMMode] -- add your button handler code here..
        //[/UserButtonCode_toggle_PWMMode]
    }
    else if (buttonThatWasClicked == toggle_PitchRelative.get())
    {
        //[UserButtonCode_toggle_PitchRelative] -- add your button handler code here..
        //[/UserButtonCode_toggle_PitchRelative]
    }
    else if (buttonThatWasClicked == toggle_DoublePrescalar.get())
    {
        //[UserButtonCode_toggle_DoublePrescalar] -- add your button handler code here..
        //[/UserButtonCode_toggle_DoublePrescalar]
    }
    else if (buttonThatWasClicked == toggle_Enabled.get())
    {
        //[UserButtonCode_toggle_Enabled] -- add your button handler code here..
        //[/UserButtonCode_toggle_Enabled]
    }
    else if (buttonThatWasClicked == toggle_Sync.get())
    {
        //[UserButtonCode_toggle_Sync] -- add your button handler code here..
        //[/UserButtonCode_toggle_Sync]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void SignalControlEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == PitchUnit.get())
    {
        //[UserComboBoxCode_PitchUnit] -- add your combo box handling code here..
        //[/UserComboBoxCode_PitchUnit]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SignalControlEditor" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="500" initialHeight="330">
  <BACKGROUND backgroundColour="323e44"/>
  <TOGGLEBUTTON name="PWM mode" id="6d33055e74932b3e" memberName="toggle_PWMMode"
                virtualName="" explicitFocusOrder="0" pos="8 192 120 18" buttonText="PWM Cycle mode"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="PWM mode" id="a7988e262000c299" memberName="toggle_PitchRelative"
                virtualName="" explicitFocusOrder="0" pos="8 144 150 18" buttonText="Relative to Note"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <LABEL name="new label" id="62419e99cd4e31dd" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 96 140 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Pitch Unit" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <JUCERCOMP name="" id="7f1d0d3bdc7671de" memberName="PitchModulation" virtualName=""
             explicitFocusOrder="0" pos="0 -12R 290 86" posRelativeX="8f92a8fb69d2fac7"
             posRelativeY="8f92a8fb69d2fac7" sourceFile="SignalChangeEditor.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="3ab1288f6225dbb5" memberName="PulsePattern" virtualName=""
             explicitFocusOrder="0" pos="8 240 132 16" sourceFile="PatternEditor8bit.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="6f9f204dacc67317" memberName="PhaseModulation" virtualName=""
             explicitFocusOrder="0" pos="192 40 300 86" sourceFile="SignalChangeEditor.cpp"
             constructorParams=""/>
  <TOGGLEBUTTON name="PWM mode" id="6abda0a4a43af997" memberName="toggle_DoublePrescalar"
                virtualName="" explicitFocusOrder="0" pos="8 168 120 18" buttonText="Double prescalar"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <JUCERCOMP name="" id="8f92a8fb69d2fac7" memberName="PWMModulation" virtualName=""
             explicitFocusOrder="0" pos="0 -12R 290 86" posRelativeX="6f9f204dacc67317"
             posRelativeY="6f9f204dacc67317" sourceFile="SignalChangeEditor.cpp"
             constructorParams=""/>
  <TOGGLEBUTTON name="Phase modulation" id="77d6c8b2aec05069" memberName="toggle_Enabled"
                virtualName="" explicitFocusOrder="0" pos="8 40 80 18" buttonText="Enabled"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <JUCERCOMP name="" id="cf23902432a626a5" memberName="ModBytePattern" virtualName=""
             explicitFocusOrder="0" pos="8 296 132 16" sourceFile="PatternEditor8bit.cpp"
             constructorParams=""/>
  <LABEL name="new label" id="89a0af3ad6e90739" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="8 280 132 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Mod byte" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="PWM mode" id="4a332394867f75c9" memberName="toggle_Sync"
                virtualName="" explicitFocusOrder="0" pos="8 64 120 18" buttonText="Sync oscilator"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <LABEL name="new label" id="995d370610ffd3e1" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 0 76 18" posRelativeX="6f9f204dacc67317"
         posRelativeY="6f9f204dacc67317" bkgCol="ff42a2c8" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="PHASE&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="1c22575993c3197d" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="0 0 76 18" posRelativeX="8f92a8fb69d2fac7"
         posRelativeY="8f92a8fb69d2fac7" bkgCol="ff42a2c8" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="PWM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a5a86cc31d79c916" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0 0 76 18" posRelativeX="7f1d0d3bdc7671de"
         posRelativeY="7f1d0d3bdc7671de" bkgCol="ff42a2c8" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="PITCH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="ed8f1372d65f89dc" memberName="PitchUnit"
            virtualName="" explicitFocusOrder="0" pos="8 112 140 18" editable="0"
            layout="33" items="Semitone&#10;Octave&#10;1 Hz&#10;10 Hz&#10;100 Hz&#10;1000 Hz"
            textWhenNonSelected="Semitone" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="4001d2e0ab753430" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="8 224 132 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Waveform Pattern" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="2b6082db2be93abb" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="0 -32 300 24" posRelativeX="6f9f204dacc67317"
         posRelativeY="6f9f204dacc67317" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="SIGNAL GENERATOR MODULATIONS"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="14.0" kerning="0.0" bold="1"
         italic="0" justification="33" typefaceStyle="Bold"/>
  <LABEL name="new label" id="889b1fc075c6113d" memberName="label_SignalName"
         virtualName="" explicitFocusOrder="0" pos="-184 -32 170 24" posRelativeX="6f9f204dacc67317"
         posRelativeY="6f9f204dacc67317" bkgCol="ff42a2c8" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="WF A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

