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

#include "PERKEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PERKEditor::PERKEditor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    AttackTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (AttackTime.get());
    AttackTime->setTooltip (TRANS("Attack time"));
    AttackTime->setRange (-36, 36, 1);
    AttackTime->setSliderStyle (Slider::RotaryHorizontalDrag);
    AttackTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    AttackTime->addListener (this);

    AttackTime->setBounds (8, 59, 64, 64);

    label.reset (new Label ("new label",
                            TRANS("PITCH")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (8, 35, 64, 24);

    DecayTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (DecayTime.get());
    DecayTime->setTooltip (TRANS("Decay time\n"));
    DecayTime->setRange (1, 100, 1);
    DecayTime->setSliderStyle (Slider::RotaryHorizontalDrag);
    DecayTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    DecayTime->addListener (this);

    DecayTime->setBounds (72, 59, 64, 64);

    label2.reset (new Label ("new label",
                             TRANS("PWM")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (72, 35, 64, 24);

    ReleaseTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (ReleaseTime.get());
    ReleaseTime->setTooltip (TRANS("Release time"));
    ReleaseTime->setRange (1, 100, 1);
    ReleaseTime->setSliderStyle (Slider::RotaryHorizontalDrag);
    ReleaseTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    ReleaseTime->addListener (this);

    ReleaseTime->setBounds (136, 59, 64, 64);

    label3.reset (new Label ("new label",
                             TRANS("PHASE")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (136, 35, 64, 24);

    ModAmt.reset (new Slider ("Modulation amount"));
    addAndMakeVisible (ModAmt.get());
    ModAmt->setTooltip (TRANS("Source of modulation"));
    ModAmt->setRange (1, 100, 1);
    ModAmt->setSliderStyle (Slider::RotaryHorizontalDrag);
    ModAmt->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    ModAmt->setColour (Slider::thumbColourId, Colours::blueviolet);
    ModAmt->addListener (this);

    ModAmt->setBounds (256, 42, 48, 47);

    ModSrc.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (ModSrc.get());
    ModSrc->setEditableText (false);
    ModSrc->setJustificationType (Justification::centredLeft);
    ModSrc->setTextWhenNothingSelected (String());
    ModSrc->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    ModSrc->addItem (TRANS("OFF"), 1);
    ModSrc->addItem (TRANS("ADSR A"), 2);
    ModSrc->addItem (TRANS("ADSR B"), 3);
    ModSrc->addItem (TRANS("CHAOS"), 4);
    ModSrc->addItem (TRANS("ENV A"), 5);
    ModSrc->addItem (TRANS("ENV B"), 6);
    ModSrc->addItem (TRANS("LFO A"), 7);
    ModSrc->addItem (TRANS("LFO B"), 8);
    ModSrc->addItem (TRANS("VEL"), 9);
    ModSrc->addListener (this);

    ModSrc->setBounds (200, 90, 96, 24);

    Val.reset (new Slider ("DirectValue"));
    addAndMakeVisible (Val.get());
    Val->setTooltip (TRANS("Source of modulation"));
    Val->setRange (1, 127, 1);
    Val->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    Val->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    Val->addListener (this);

    Val->setBounds (204, 27, 64, 63);

    Title2.reset (new Label ("new label",
                             TRANS("AMP")));
    addAndMakeVisible (Title2.get());
    Title2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title2->setJustificationType (Justification::centred);
    Title2->setEditable (false, false, false);
    Title2->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title2->setColour (Label::textColourId, Colours::crimson);
    Title2->setColour (TextEditor::textColourId, Colours::black);
    Title2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title2->setBounds (200, 0, 96, 24);

    ModAmt2.reset (new Slider ("Modulation amount"));
    addAndMakeVisible (ModAmt2.get());
    ModAmt2->setTooltip (TRANS("Source of modulation"));
    ModAmt2->setRange (1, 100, 1);
    ModAmt2->setSliderStyle (Slider::RotaryHorizontalDrag);
    ModAmt2->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    ModAmt2->setColour (Slider::thumbColourId, Colours::blueviolet);
    ModAmt2->addListener (this);

    ModAmt2->setBounds (352, 42, 48, 47);

    ModSrc2.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (ModSrc2.get());
    ModSrc2->setEditableText (false);
    ModSrc2->setJustificationType (Justification::centredLeft);
    ModSrc2->setTextWhenNothingSelected (String());
    ModSrc2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    ModSrc2->addItem (TRANS("OFF"), 1);
    ModSrc2->addItem (TRANS("ADSR A"), 2);
    ModSrc2->addItem (TRANS("ADSR B"), 3);
    ModSrc2->addItem (TRANS("CHAOS"), 4);
    ModSrc2->addItem (TRANS("ENV A"), 5);
    ModSrc2->addItem (TRANS("ENV B"), 6);
    ModSrc2->addItem (TRANS("LFO A"), 7);
    ModSrc2->addItem (TRANS("LFO B"), 8);
    ModSrc2->addItem (TRANS("VEL"), 9);
    ModSrc2->addListener (this);

    ModSrc2->setBounds (296, 90, 96, 24);

    Val2.reset (new Slider ("DirectValue"));
    addAndMakeVisible (Val2.get());
    Val2->setTooltip (TRANS("Source of modulation"));
    Val2->setRange (1, 127, 1);
    Val2->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    Val2->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    Val2->addListener (this);

    Val2->setBounds (300, 27, 64, 63);

    Title3.reset (new Label ("new label",
                             TRANS("PAN")));
    addAndMakeVisible (Title3.get());
    Title3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title3->setJustificationType (Justification::centred);
    Title3->setEditable (false, false, false);
    Title3->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title3->setColour (Label::textColourId, Colours::crimson);
    Title3->setColour (TextEditor::textColourId, Colours::black);
    Title3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title3->setBounds (296, 0, 96, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PERKEditor::~PERKEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    AttackTime = nullptr;
    label = nullptr;
    DecayTime = nullptr;
    label2 = nullptr;
    ReleaseTime = nullptr;
    label3 = nullptr;
    ModAmt = nullptr;
    ModSrc = nullptr;
    Val = nullptr;
    Title2 = nullptr;
    ModAmt2 = nullptr;
    ModSrc2 = nullptr;
    Val2 = nullptr;
    Title3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PERKEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PERKEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PERKEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == AttackTime.get())
    {
        //[UserSliderCode_AttackTime] -- add your slider handling code here..
        //[/UserSliderCode_AttackTime]
    }
    else if (sliderThatWasMoved == DecayTime.get())
    {
        //[UserSliderCode_DecayTime] -- add your slider handling code here..
        //[/UserSliderCode_DecayTime]
    }
    else if (sliderThatWasMoved == ReleaseTime.get())
    {
        //[UserSliderCode_ReleaseTime] -- add your slider handling code here..
        //[/UserSliderCode_ReleaseTime]
    }
    else if (sliderThatWasMoved == ModAmt.get())
    {
        //[UserSliderCode_ModAmt] -- add your slider handling code here..
        //[/UserSliderCode_ModAmt]
    }
    else if (sliderThatWasMoved == Val.get())
    {
        //[UserSliderCode_Val] -- add your slider handling code here..
        //[/UserSliderCode_Val]
    }
    else if (sliderThatWasMoved == ModAmt2.get())
    {
        //[UserSliderCode_ModAmt2] -- add your slider handling code here..
        //[/UserSliderCode_ModAmt2]
    }
    else if (sliderThatWasMoved == Val2.get())
    {
        //[UserSliderCode_Val2] -- add your slider handling code here..
        //[/UserSliderCode_Val2]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PERKEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == ModSrc.get())
    {
        //[UserComboBoxCode_ModSrc] -- add your combo box handling code here..
        //[/UserComboBoxCode_ModSrc]
    }
    else if (comboBoxThatHasChanged == ModSrc2.get())
    {
        //[UserComboBoxCode_ModSrc2] -- add your combo box handling code here..
        //[/UserComboBoxCode_ModSrc2]
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

<JUCER_COMPONENT documentType="Component" className="PERKEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
  <SLIDER name="DirectValue" id="df72ef78504c47be" memberName="AttackTime"
          virtualName="" explicitFocusOrder="0" pos="8 59 64 64" tooltip="Attack time"
          min="-36.0" max="36.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="eb7f31cedb99e07" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 35 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="PITCH" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="9258fb4fcb5b6574" memberName="DecayTime"
          virtualName="" explicitFocusOrder="0" pos="72 59 64 64" tooltip="Decay time&#10;"
          min="1.0" max="100.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="c3a45ba72ca00580" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="72 35 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="PWM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="51fa9e9f52a3fc5d" memberName="ReleaseTime"
          virtualName="" explicitFocusOrder="0" pos="136 59 64 64" tooltip="Release time"
          min="1.0" max="100.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="c8bdcf903882f097" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="136 35 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="PHASE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="Modulation amount" id="ac75912c33562c58" memberName="ModAmt"
          virtualName="" explicitFocusOrder="0" pos="256 42 48 47" tooltip="Source of modulation"
          thumbcol="ff8a2be2" min="1.0" max="100.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="new combo box" id="e50909c7df52b24f" memberName="ModSrc"
            virtualName="" explicitFocusOrder="0" pos="200 90 96 24" editable="0"
            layout="33" items="OFF&#10;ADSR A&#10;ADSR B&#10;CHAOS&#10;ENV A&#10;ENV B&#10;LFO A&#10;LFO B&#10;VEL"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="DirectValue" id="d0a9ebf0ee2f274c" memberName="Val" virtualName=""
          explicitFocusOrder="0" pos="204 27 64 63" tooltip="Source of modulation"
          min="1.0" max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="4bbeb0561535668a" memberName="Title2" virtualName=""
         explicitFocusOrder="0" pos="200 0 96 24" bkgCol="fff0f8ff" textCol="ffdc143c"
         edTextCol="ff000000" edBkgCol="0" labelText="AMP" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="Modulation amount" id="ea67db6d75cea2d7" memberName="ModAmt2"
          virtualName="" explicitFocusOrder="0" pos="352 42 48 47" tooltip="Source of modulation"
          thumbcol="ff8a2be2" min="1.0" max="100.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="new combo box" id="370d56a31b28f28c" memberName="ModSrc2"
            virtualName="" explicitFocusOrder="0" pos="296 90 96 24" editable="0"
            layout="33" items="OFF&#10;ADSR A&#10;ADSR B&#10;CHAOS&#10;ENV A&#10;ENV B&#10;LFO A&#10;LFO B&#10;VEL"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="DirectValue" id="ae343667713c5ce" memberName="Val2" virtualName=""
          explicitFocusOrder="0" pos="300 27 64 63" tooltip="Source of modulation"
          min="1.0" max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="f461edf7df24b885" memberName="Title3" virtualName=""
         explicitFocusOrder="0" pos="296 0 96 24" bkgCol="fff0f8ff" textCol="ffdc143c"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

