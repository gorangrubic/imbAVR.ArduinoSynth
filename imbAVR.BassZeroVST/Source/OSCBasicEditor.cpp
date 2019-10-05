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

#include "OSCBasicEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OSCBasicEditor::OSCBasicEditor ()
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

    AttackTime->setBounds (5, 50, 64, 64);

    label.reset (new Label ("new label",
                            TRANS("PITCH")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (5, 26, 64, 24);

    DecayTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (DecayTime.get());
    DecayTime->setTooltip (TRANS("Decay time\n"));
    DecayTime->setRange (1, 100, 1);
    DecayTime->setSliderStyle (Slider::RotaryHorizontalDrag);
    DecayTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    DecayTime->addListener (this);

    DecayTime->setBounds (69, 50, 64, 64);

    label2.reset (new Label ("new label",
                             TRANS("PWM")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (69, 26, 64, 24);

    ReleaseTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (ReleaseTime.get());
    ReleaseTime->setTooltip (TRANS("Release time"));
    ReleaseTime->setRange (1, 100, 1);
    ReleaseTime->setSliderStyle (Slider::RotaryHorizontalDrag);
    ReleaseTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    ReleaseTime->addListener (this);

    ReleaseTime->setBounds (133, 50, 64, 64);

    label3.reset (new Label ("new label",
                             TRANS("PHASE")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (133, 26, 64, 24);

    ModAmt.reset (new Slider ("Modulation amount"));
    addAndMakeVisible (ModAmt.get());
    ModAmt->setTooltip (TRANS("Source of modulation"));
    ModAmt->setRange (1, 100, 1);
    ModAmt->setSliderStyle (Slider::RotaryHorizontalDrag);
    ModAmt->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    ModAmt->setColour (Slider::thumbColourId, Colours::blueviolet);
    ModAmt->addListener (this);

    ModAmt->setBounds (256, 33, 48, 47);

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

    ModSrc->setBounds (200, 81, 96, 24);

    Val.reset (new Slider ("DirectValue"));
    addAndMakeVisible (Val.get());
    Val->setTooltip (TRANS("Source of modulation"));
    Val->setRange (1, 127, 1);
    Val->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    Val->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    Val->addListener (this);

    Val->setBounds (204, 18, 64, 63);

    Title2.reset (new Label ("new label",
                             TRANS("Shape")));
    addAndMakeVisible (Title2.get());
    Title2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title2->setJustificationType (Justification::centred);
    Title2->setEditable (false, false, false);
    Title2->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title2->setColour (Label::textColourId, Colours::crimson);
    Title2->setColour (TextEditor::textColourId, Colours::black);
    Title2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title2->setBounds (200, 0, 96, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (330, 120);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OSCBasicEditor::~OSCBasicEditor()
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


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OSCBasicEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OSCBasicEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OSCBasicEditor::sliderValueChanged (Slider* sliderThatWasMoved)
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

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void OSCBasicEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == ModSrc.get())
    {
        //[UserComboBoxCode_ModSrc] -- add your combo box handling code here..
        //[/UserComboBoxCode_ModSrc]
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

<JUCER_COMPONENT documentType="Component" className="OSCBasicEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="330" initialHeight="120">
  <BACKGROUND backgroundColour="323e44"/>
  <SLIDER name="DirectValue" id="df72ef78504c47be" memberName="AttackTime"
          virtualName="" explicitFocusOrder="0" pos="5 50 64 64" tooltip="Attack time"
          min="-36.0" max="36.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="eb7f31cedb99e07" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="5 26 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="PITCH" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="9258fb4fcb5b6574" memberName="DecayTime"
          virtualName="" explicitFocusOrder="0" pos="69 50 64 64" tooltip="Decay time&#10;"
          min="1.0" max="100.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="c3a45ba72ca00580" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="69 26 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="PWM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="51fa9e9f52a3fc5d" memberName="ReleaseTime"
          virtualName="" explicitFocusOrder="0" pos="133 50 64 64" tooltip="Release time"
          min="1.0" max="100.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="c8bdcf903882f097" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="133 26 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="PHASE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="Modulation amount" id="ac75912c33562c58" memberName="ModAmt"
          virtualName="" explicitFocusOrder="0" pos="256 33 48 47" tooltip="Source of modulation"
          thumbcol="ff8a2be2" min="1.0" max="100.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="new combo box" id="e50909c7df52b24f" memberName="ModSrc"
            virtualName="" explicitFocusOrder="0" pos="200 81 96 24" editable="0"
            layout="33" items="OFF&#10;ADSR A&#10;ADSR B&#10;CHAOS&#10;ENV A&#10;ENV B&#10;LFO A&#10;LFO B&#10;VEL"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="DirectValue" id="d0a9ebf0ee2f274c" memberName="Val" virtualName=""
          explicitFocusOrder="0" pos="204 18 64 63" tooltip="Source of modulation"
          min="1.0" max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="4bbeb0561535668a" memberName="Title2" virtualName=""
         explicitFocusOrder="0" pos="200 0 96 24" bkgCol="fff0f8ff" textCol="ffdc143c"
         edTextCol="ff000000" edBkgCol="0" labelText="Shape" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

