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

#include "ADSREditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ADSREditor::ADSREditor (String title)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    AttackTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (AttackTime.get());
    AttackTime->setTooltip (TRANS("Attack time"));
    AttackTime->setRange (1, 127, 1);
    AttackTime->setSliderStyle (Slider::RotaryHorizontalDrag);
    AttackTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    AttackTime->addListener (this);

    AttackTime->setBounds (72, 32, 64, 64);

    label.reset (new Label ("new label",
                            TRANS("Attack")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (72, 8, 64, 24);

    DecayTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (DecayTime.get());
    DecayTime->setTooltip (TRANS("Decay time\n"));
    DecayTime->setRange (1, 127, 1);
    DecayTime->setSliderStyle (Slider::RotaryHorizontalDrag);
    DecayTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    DecayTime->addListener (this);

    DecayTime->setBounds (136, 32, 64, 64);

    label2.reset (new Label ("new label",
                             TRANS("Decay\n")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (136, 8, 64, 24);

    ReleaseTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (ReleaseTime.get());
    ReleaseTime->setTooltip (TRANS("Release time"));
    ReleaseTime->setRange (1, 127, 1);
    ReleaseTime->setSliderStyle (Slider::RotaryHorizontalDrag);
    ReleaseTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    ReleaseTime->addListener (this);

    ReleaseTime->setBounds (200, 32, 64, 64);

    label3.reset (new Label ("new label",
                             TRANS("Release\n")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (200, 8, 64, 24);

    InitLevel.reset (new Slider ("DirectValue"));
    addAndMakeVisible (InitLevel.get());
    InitLevel->setTooltip (TRANS("Initial level"));
    InitLevel->setRange (1, 127, 1);
    InitLevel->setSliderStyle (Slider::RotaryHorizontalDrag);
    InitLevel->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    InitLevel->setColour (Slider::thumbColourId, Colours::crimson);
    InitLevel->addListener (this);

    InitLevel->setBounds (266, 32, 64, 64);

    label4.reset (new Label ("new label",
                             TRANS("Initial\n")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (266, 9, 64, 24);

    SustainLevel.reset (new Slider ("DirectValue"));
    addAndMakeVisible (SustainLevel.get());
    SustainLevel->setTooltip (TRANS("Sustain level\n"));
    SustainLevel->setRange (1, 127, 1);
    SustainLevel->setSliderStyle (Slider::RotaryHorizontalDrag);
    SustainLevel->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    SustainLevel->setColour (Slider::thumbColourId, Colours::crimson);
    SustainLevel->addListener (this);

    SustainLevel->setBounds (330, 32, 64, 64);

    label5.reset (new Label ("new label",
                             TRANS("Sustain\n")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (330, 9, 64, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (394, 96);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ADSREditor::~ADSREditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    AttackTime = nullptr;
    label = nullptr;
    DecayTime = nullptr;
    label2 = nullptr;
    ReleaseTime = nullptr;
    label3 = nullptr;
    InitLevel = nullptr;
    label4 = nullptr;
    SustainLevel = nullptr;
    label5 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ADSREditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ADSREditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ADSREditor::sliderValueChanged (Slider* sliderThatWasMoved)
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
    else if (sliderThatWasMoved == InitLevel.get())
    {
        //[UserSliderCode_InitLevel] -- add your slider handling code here..
        //[/UserSliderCode_InitLevel]
    }
    else if (sliderThatWasMoved == SustainLevel.get())
    {
        //[UserSliderCode_SustainLevel] -- add your slider handling code here..
        //[/UserSliderCode_SustainLevel]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ADSREditor" componentName=""
                 parentClasses="public Component" constructorParams="String title"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="394" initialHeight="96">
  <BACKGROUND backgroundColour="323e44"/>
  <SLIDER name="DirectValue" id="df72ef78504c47be" memberName="AttackTime"
          virtualName="" explicitFocusOrder="0" pos="72 32 64 64" tooltip="Attack time"
          min="1.0" max="127.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="eb7f31cedb99e07" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="72 8 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="9258fb4fcb5b6574" memberName="DecayTime"
          virtualName="" explicitFocusOrder="0" pos="136 32 64 64" tooltip="Decay time&#10;"
          min="1.0" max="127.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="c3a45ba72ca00580" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="136 8 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="51fa9e9f52a3fc5d" memberName="ReleaseTime"
          virtualName="" explicitFocusOrder="0" pos="200 32 64 64" tooltip="Release time"
          min="1.0" max="127.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="c8bdcf903882f097" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="200 8 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="fe24b362f1390fa2" memberName="InitLevel"
          virtualName="" explicitFocusOrder="0" pos="266 32 64 64" tooltip="Initial level"
          thumbcol="ffdc143c" min="1.0" max="127.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="e2537dd020d310c4" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="266 9 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Initial&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="6a522a56e4d2ab40" memberName="SustainLevel"
          virtualName="" explicitFocusOrder="0" pos="330 32 64 64" tooltip="Sustain level&#10;"
          thumbcol="ffdc143c" min="1.0" max="127.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="7c4b83edc2e8e6c7" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="330 9 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

