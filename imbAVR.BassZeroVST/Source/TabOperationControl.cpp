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

#include "TabOperationControl.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabOperationControl::TabOperationControl ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    component_OPMA.reset (new SourceMixerComponent ("DIST"));
    addAndMakeVisible (component_OPMA.get());
    component_OPMA->setBounds (184, 400, 96, 112);

    group_OPMODES.reset (new GroupComponent ("new group",
                                             TRANS("Operation mode")));
    addAndMakeVisible (group_OPMODES.get());
    group_OPMODES->setColour (GroupComponent::outlineColourId, Colour (0x008e989b));

    group_OPMODES->setBounds (1064, 352, 128, 340);

    textButton.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton.get());
    textButton->setButtonText (TRANS("Bass line"));
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colours::blueviolet);

    textButton2.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton2.get());
    textButton2->setButtonText (TRANS("Lead synth"));
    textButton2->addListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colours::blueviolet);

    textButton4.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton4.get());
    textButton4->setButtonText (TRANS("Kick drum"));
    textButton4->addListener (this);
    textButton4->setColour (TextButton::buttonColourId, Colours::blueviolet);

    textButton5.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton5.get());
    textButton5->setButtonText (TRANS("Short FX"));
    textButton5->addListener (this);
    textButton5->setColour (TextButton::buttonColourId, Colours::blueviolet);

    textButton6.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton6.get());
    textButton6->setButtonText (TRANS("Long FX"));
    textButton6->addListener (this);
    textButton6->setColour (TextButton::buttonColourId, Colours::blueviolet);

    textButton7.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton7.get());
    textButton7->setButtonText (TRANS("Fat Synth"));
    textButton7->addListener (this);
    textButton7->setColour (TextButton::buttonColourId, Colours::blueviolet);

    textButton8.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton8.get());
    textButton8->setButtonText (TRANS("Lifter FX A"));
    textButton8->addListener (this);
    textButton8->setColour (TextButton::buttonColourId, Colours::blueviolet);

    textButton9.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton9.get());
    textButton9->setButtonText (TRANS("Lifter FX B"));
    textButton9->addListener (this);
    textButton9->setColour (TextButton::buttonColourId, Colours::blueviolet);

    Title.reset (new Label ("Title",
                            TRANS("MOD A")));
    addAndMakeVisible (Title.get());
    Title->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    Title->setJustificationType (Justification::centredLeft);
    Title->setEditable (false, false, false);
    Title->setColour (Label::backgroundColourId, Colours::cadetblue);
    Title->setColour (TextEditor::textColourId, Colours::black);
    Title->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title2.reset (new Label ("Title",
                             TRANS("MOD B")));
    addAndMakeVisible (Title2.get());
    Title2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    Title2->setJustificationType (Justification::centredLeft);
    Title2->setEditable (false, false, false);
    Title2->setColour (Label::backgroundColourId, Colours::cadetblue);
    Title2->setColour (TextEditor::textColourId, Colours::black);
    Title2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_OPMB.reset (new SourceMixerComponent ("DIST"));
    addAndMakeVisible (component_OPMB.get());
    component_OPM_VAL_A.reset (new Slider ("DirectValue"));
    addAndMakeVisible (component_OPM_VAL_A.get());
    component_OPM_VAL_A->setTooltip (TRANS("Decay time\n"));
    component_OPM_VAL_A->setRange (1, 100, 1);
    component_OPM_VAL_A->setSliderStyle (Slider::RotaryHorizontalDrag);
    component_OPM_VAL_A->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    component_OPM_VAL_A->addListener (this);

    label2.reset (new Label ("new label",
                             TRANS("VAL A")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_OPM_VAL_B.reset (new Slider ("DirectValue"));
    addAndMakeVisible (component_OPM_VAL_B.get());
    component_OPM_VAL_B->setTooltip (TRANS("Decay time\n"));
    component_OPM_VAL_B->setRange (1, 100, 1);
    component_OPM_VAL_B->setSliderStyle (Slider::RotaryHorizontalDrag);
    component_OPM_VAL_B->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    component_OPM_VAL_B->addListener (this);

    label3.reset (new Label ("new label",
                             TRANS("VAL B")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_OPM_VAL_C.reset (new Slider ("DirectValue"));
    addAndMakeVisible (component_OPM_VAL_C.get());
    component_OPM_VAL_C->setTooltip (TRANS("Decay time\n"));
    component_OPM_VAL_C->setRange (1, 100, 1);
    component_OPM_VAL_C->setSliderStyle (Slider::RotaryHorizontalDrag);
    component_OPM_VAL_C->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    component_OPM_VAL_C->addListener (this);

    label4.reset (new Label ("new label",
                             TRANS("VAL C")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    textEditor.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (true);
    textEditor->setReturnKeyStartsNewLine (true);
    textEditor->setReadOnly (true);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (false);
    textEditor->setPopupMenuEnabled (false);
    textEditor->setText (TRANS("Description of selected operation mode"));

    textEditor->setBounds (440, 104, 400, 240);

    textEditor2.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor2.get());
    textEditor2->setMultiLine (true);
    textEditor2->setReturnKeyStartsNewLine (true);
    textEditor2->setReadOnly (true);
    textEditor2->setScrollbarsShown (false);
    textEditor2->setCaretVisible (false);
    textEditor2->setPopupMenuEnabled (false);
    textEditor2->setColour (TextEditor::textColourId, Colours::grey);
    textEditor2->setText (TRANS("Operation modes (OPMs) are hardware level presets controling synthesis and modulation aspects that are not directly controllable from VSTi nor MIDI CC messages. OP MODs and VARs have different role in different OPMs. "));

    textEditor2->setBounds (440, 8, 400, 80);

    label_OPM.reset (new Label ("new label",
                                TRANS("OPERATION MODE")));
    addAndMakeVisible (label_OPM.get());
    label_OPM->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_OPM->setJustificationType (Justification::centredLeft);
    label_OPM->setEditable (false, false, false);
    label_OPM->setColour (Label::backgroundColourId, Colours::azure);
    label_OPM->setColour (Label::textColourId, Colours::cadetblue);
    label_OPM->setColour (TextEditor::textColourId, Colours::black);
    label_OPM->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_OPM->setBounds (184, 144, 190, 24);

    comboBox.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox.get());
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (TRANS("Bass"));
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Bass"), 1);
    comboBox->addSeparator();
    comboBox->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TabOperationControl::~TabOperationControl()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    component_OPMA = nullptr;
    group_OPMODES = nullptr;
    textButton = nullptr;
    textButton2 = nullptr;
    textButton4 = nullptr;
    textButton5 = nullptr;
    textButton6 = nullptr;
    textButton7 = nullptr;
    textButton8 = nullptr;
    textButton9 = nullptr;
    Title = nullptr;
    Title2 = nullptr;
    component_OPMB = nullptr;
    component_OPM_VAL_A = nullptr;
    label2 = nullptr;
    component_OPM_VAL_B = nullptr;
    label3 = nullptr;
    component_OPM_VAL_C = nullptr;
    label4 = nullptr;
    textEditor = nullptr;
    textEditor2 = nullptr;
    label_OPM = nullptr;
    comboBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TabOperationControl::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TabOperationControl::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textButton->setBounds (1064 + 128 / 2 - ((roundToInt (128 * 0.8984f)) / 2), 352 + 24, roundToInt (128 * 0.8984f), 24);
    textButton2->setBounds (1064 + 128 / 2 - ((roundToInt (128 * 0.8984f)) / 2), 352 + 56, roundToInt (128 * 0.8984f), 24);
    textButton4->setBounds (1064 + 128 / 2 - ((roundToInt (128 * 0.8984f)) / 2), 352 + 160, roundToInt (128 * 0.8984f), 24);
    textButton5->setBounds (1064 + 128 / 2 - ((roundToInt (128 * 0.8984f)) / 2), 352 + 210, roundToInt (128 * 0.8984f), 24);
    textButton6->setBounds (1064 + 128 / 2 - ((roundToInt (128 * 0.8984f)) / 2), 352 + 243, roundToInt (128 * 0.8984f), 24);
    textButton7->setBounds (1064 + 128 / 2 - ((roundToInt (128 * 0.8984f)) / 2), 352 + 88, roundToInt (128 * 0.8984f), 24);
    textButton8->setBounds (1064 + 128 / 2 - ((roundToInt (128 * 0.8984f)) / 2), 352 + 273, roundToInt (128 * 0.8984f), 24);
    textButton9->setBounds (1064 + 128 / 2 - ((roundToInt (128 * 0.8984f)) / 2), 352 + 305, roundToInt (128 * 0.8984f), 24);
    Title->setBounds (184 + 0, 400 + 0 - 24, 96, 24);
    Title2->setBounds ((184 + 96) + 0, (400 + 0) + 0 - 24, 96, 24);
    component_OPMB->setBounds (184 + 96, 400 + 0, 96, 112);
    component_OPM_VAL_A->setBounds (184 + 3, 144 + 87, 64, 64);
    label2->setBounds ((184 + 3) + 0, (144 + 87) + -24, 64, 24);
    component_OPM_VAL_B->setBounds (184 + 64, 144 + 112, 64, 64);
    label3->setBounds ((184 + 64) + 0, (144 + 112) + 0 - 24, 64, 24);
    component_OPM_VAL_C->setBounds (184 + 128, 144 + 88, 64, 64);
    label4->setBounds ((184 + 128) + 0, (144 + 88) + 0 - 24, 64, 24);
    comboBox->setBounds (184 + 0, 144 + 32, 188, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TabOperationControl::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton.get())
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2.get())
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton4.get())
    {
        //[UserButtonCode_textButton4] -- add your button handler code here..
        //[/UserButtonCode_textButton4]
    }
    else if (buttonThatWasClicked == textButton5.get())
    {
        //[UserButtonCode_textButton5] -- add your button handler code here..
        //[/UserButtonCode_textButton5]
    }
    else if (buttonThatWasClicked == textButton6.get())
    {
        //[UserButtonCode_textButton6] -- add your button handler code here..
        //[/UserButtonCode_textButton6]
    }
    else if (buttonThatWasClicked == textButton7.get())
    {
        //[UserButtonCode_textButton7] -- add your button handler code here..
        //[/UserButtonCode_textButton7]
    }
    else if (buttonThatWasClicked == textButton8.get())
    {
        //[UserButtonCode_textButton8] -- add your button handler code here..
        //[/UserButtonCode_textButton8]
    }
    else if (buttonThatWasClicked == textButton9.get())
    {
        //[UserButtonCode_textButton9] -- add your button handler code here..
        //[/UserButtonCode_textButton9]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void TabOperationControl::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == component_OPM_VAL_A.get())
    {
        //[UserSliderCode_component_OPM_VAL_A] -- add your slider handling code here..
        //[/UserSliderCode_component_OPM_VAL_A]
    }
    else if (sliderThatWasMoved == component_OPM_VAL_B.get())
    {
        //[UserSliderCode_component_OPM_VAL_B] -- add your slider handling code here..
        //[/UserSliderCode_component_OPM_VAL_B]
    }
    else if (sliderThatWasMoved == component_OPM_VAL_C.get())
    {
        //[UserSliderCode_component_OPM_VAL_C] -- add your slider handling code here..
        //[/UserSliderCode_component_OPM_VAL_C]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void TabOperationControl::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox.get())
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
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

<JUCER_COMPONENT documentType="Component" className="TabOperationControl" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="" id="f783ad21ae1cde8f" memberName="component_OPMA" virtualName=""
             explicitFocusOrder="0" pos="184 400 96 112" sourceFile="SourceMixerComponent.cpp"
             constructorParams="&quot;DIST&quot;"/>
  <GROUPCOMPONENT name="new group" id="28441e7094f7cb78" memberName="group_OPMODES"
                  virtualName="" explicitFocusOrder="0" pos="1064 352 128 340"
                  outlinecol="8e989b" title="Operation mode"/>
  <TEXTBUTTON name="new button" id="c4bd59df20b5ab34" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="-0.5Cc 24 89.844% 24"
              posRelativeX="28441e7094f7cb78" posRelativeY="28441e7094f7cb78"
              posRelativeW="28441e7094f7cb78" bgColOff="ff8a2be2" buttonText="Bass line"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="8480f576d1aa1d29" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="-0.5Cc 56 89.844% 24"
              posRelativeX="28441e7094f7cb78" posRelativeY="28441e7094f7cb78"
              posRelativeW="28441e7094f7cb78" bgColOff="ff8a2be2" buttonText="Lead synth"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="bd714cd5d1cb31d4" memberName="textButton4"
              virtualName="" explicitFocusOrder="0" pos="-0.5Cc 160 89.844% 24"
              posRelativeX="28441e7094f7cb78" posRelativeY="28441e7094f7cb78"
              posRelativeW="28441e7094f7cb78" bgColOff="ff8a2be2" buttonText="Kick drum"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="400a9fe731f39aca" memberName="textButton5"
              virtualName="" explicitFocusOrder="0" pos="-0.5Cc 210 89.844% 24"
              posRelativeX="28441e7094f7cb78" posRelativeY="28441e7094f7cb78"
              posRelativeW="28441e7094f7cb78" bgColOff="ff8a2be2" buttonText="Short FX"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="741599b6f0a61ba9" memberName="textButton6"
              virtualName="" explicitFocusOrder="0" pos="-0.5Cc 243 89.844% 24"
              posRelativeX="28441e7094f7cb78" posRelativeY="28441e7094f7cb78"
              posRelativeW="28441e7094f7cb78" bgColOff="ff8a2be2" buttonText="Long FX"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="6ea675c5c287c8c9" memberName="textButton7"
              virtualName="" explicitFocusOrder="0" pos="-0.5Cc 88 89.844% 24"
              posRelativeX="28441e7094f7cb78" posRelativeY="28441e7094f7cb78"
              posRelativeW="28441e7094f7cb78" bgColOff="ff8a2be2" buttonText="Fat Synth"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="a3fa0adf90cfe9f9" memberName="textButton8"
              virtualName="" explicitFocusOrder="0" pos="-0.5Cc 273 89.844% 24"
              posRelativeX="28441e7094f7cb78" posRelativeY="28441e7094f7cb78"
              posRelativeW="28441e7094f7cb78" bgColOff="ff8a2be2" buttonText="Lifter FX A"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="76921f86d9c9d509" memberName="textButton9"
              virtualName="" explicitFocusOrder="0" pos="-0.5Cc 305 89.844% 24"
              posRelativeX="28441e7094f7cb78" posRelativeY="28441e7094f7cb78"
              posRelativeW="28441e7094f7cb78" bgColOff="ff8a2be2" buttonText="Lifter FX B"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Title" id="e63b84fabc73ca75" memberName="Title" virtualName=""
         explicitFocusOrder="0" pos="0 0r 96 24" posRelativeX="f783ad21ae1cde8f"
         posRelativeY="f783ad21ae1cde8f" bkgCol="ff5f9ea0" edTextCol="ff000000"
         edBkgCol="0" labelText="MOD A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
  <LABEL name="Title" id="1be21c3c90a8e21a" memberName="Title2" virtualName=""
         explicitFocusOrder="0" pos="0 0r 96 24" posRelativeX="a282c0b20a726e97"
         posRelativeY="a282c0b20a726e97" bkgCol="ff5f9ea0" edTextCol="ff000000"
         edBkgCol="0" labelText="MOD B" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
  <JUCERCOMP name="" id="a282c0b20a726e97" memberName="component_OPMB" virtualName=""
             explicitFocusOrder="0" pos="0R 0 96 112" posRelativeX="f783ad21ae1cde8f"
             posRelativeY="f783ad21ae1cde8f" sourceFile="SourceMixerComponent.cpp"
             constructorParams="&quot;DIST&quot;"/>
  <SLIDER name="DirectValue" id="9258fb4fcb5b6574" memberName="component_OPM_VAL_A"
          virtualName="" explicitFocusOrder="0" pos="3 87 64 64" posRelativeX="68edd7ab819d5f21"
          posRelativeY="68edd7ab819d5f21" tooltip="Decay time&#10;" min="1.0"
          max="100.0" int="1.0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="c3a45ba72ca00580" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 -24 64 24" posRelativeX="9258fb4fcb5b6574"
         posRelativeY="9258fb4fcb5b6574" edTextCol="ff000000" edBkgCol="0"
         labelText="VAL A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <SLIDER name="DirectValue" id="e8691d262e63103" memberName="component_OPM_VAL_B"
          virtualName="" explicitFocusOrder="0" pos="64 112 64 64" posRelativeX="68edd7ab819d5f21"
          posRelativeY="68edd7ab819d5f21" tooltip="Decay time&#10;" min="1.0"
          max="100.0" int="1.0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="f92bb94970d53673" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="0 0r 64 24" posRelativeX="e8691d262e63103"
         posRelativeY="e8691d262e63103" edTextCol="ff000000" edBkgCol="0"
         labelText="VAL B" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <SLIDER name="DirectValue" id="73a4a424a3f96972" memberName="component_OPM_VAL_C"
          virtualName="" explicitFocusOrder="0" pos="128 88 64 64" posRelativeX="68edd7ab819d5f21"
          posRelativeY="68edd7ab819d5f21" tooltip="Decay time&#10;" min="1.0"
          max="100.0" int="1.0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="11c89457f06ac99" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="0 0r 64 24" posRelativeX="73a4a424a3f96972"
         posRelativeY="73a4a424a3f96972" edTextCol="ff000000" edBkgCol="0"
         labelText="VAL C" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <TEXTEDITOR name="new text editor" id="579bc3b9c3136d69" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="440 104 400 240" initialText="Description of selected operation mode"
              multiline="1" retKeyStartsLine="1" readonly="1" scrollbars="1"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="e39886dd8255cba6" memberName="textEditor2"
              virtualName="" explicitFocusOrder="0" pos="440 8 400 80" textcol="ff808080"
              initialText="Operation modes (OPMs) are hardware level presets controling synthesis and modulation aspects that are not directly controllable from VSTi nor MIDI CC messages. OP MODs and VARs have different role in different OPMs. "
              multiline="1" retKeyStartsLine="1" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <LABEL name="new label" id="68edd7ab819d5f21" memberName="label_OPM"
         virtualName="" explicitFocusOrder="0" pos="184 144 190 24" bkgCol="fff0ffff"
         textCol="ff5f9ea0" edTextCol="ff000000" edBkgCol="0" labelText="OPERATION MODE"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="1"
         italic="0" justification="33" typefaceStyle="Bold"/>
  <COMBOBOX name="new combo box" id="3d5e9118fb63659c" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="0 32 188 24" posRelativeX="68edd7ab819d5f21"
            posRelativeY="68edd7ab819d5f21" editable="0" layout="33" items="Bass&#10;"
            textWhenNonSelected="Bass" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

