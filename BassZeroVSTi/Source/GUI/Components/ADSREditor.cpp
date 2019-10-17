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
ADSREditor::ADSREditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..



    //[/Constructor_pre]

    label.reset (new Label ("new label",
                            TRANS("Attack")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (120, 4, 64, 24);

    label2.reset (new Label ("new label",
                             TRANS("Decay\n")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (120, 28, 64, 24);

    label6.reset (new Label ("new label",
                             TRANS("Release")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (120, 54, 64, 24);

    AttackTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (AttackTime.get());
    AttackTime->setTooltip (TRANS("Attack time"));
    AttackTime->setRange (1, 127, 1);
    AttackTime->setSliderStyle (Slider::LinearHorizontal);
    AttackTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    AttackTime->addListener (this);

    AttackTime->setBounds (192, 4, 76, 24);

    DecayTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (DecayTime.get());
    DecayTime->setTooltip (TRANS("Decay time\n"));
    DecayTime->setRange (1, 127, 1);
    DecayTime->setSliderStyle (Slider::LinearHorizontal);
    DecayTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    DecayTime->addListener (this);

    DecayTime->setBounds (192, 28, 76, 24);

    InitLevel.reset (new Slider ("DirectValue"));
    addAndMakeVisible (InitLevel.get());
    InitLevel->setTooltip (TRANS("Initial level"));
    InitLevel->setRange (1, 127, 1);
    InitLevel->setSliderStyle (Slider::LinearHorizontal);
    InitLevel->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    InitLevel->setColour (Slider::thumbColourId, Colour (0xffad0002));
    InitLevel->addListener (this);

    InitLevel->setBounds (56, 31, 64, 24);

    label4.reset (new Label ("new label",
                             TRANS("Initial\n")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (0, 31, 64, 24);

    SustainLevel.reset (new Slider ("DirectValue"));
    addAndMakeVisible (SustainLevel.get());
    SustainLevel->setTooltip (TRANS("Sustain level\n"));
    SustainLevel->setRange (1, 127, 1);
    SustainLevel->setSliderStyle (Slider::LinearHorizontal);
    SustainLevel->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    SustainLevel->setColour (Slider::thumbColourId, Colour (0xffad0002));
    SustainLevel->addListener (this);

    SustainLevel->setBounds (56, 55, 64, 24);

    label5.reset (new Label ("new label",
                             TRANS("Sustain\n")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (0, 55, 64, 24);

    ReleaseTime.reset (new Slider ("DirectValue"));
    addAndMakeVisible (ReleaseTime.get());
    ReleaseTime->setTooltip (TRANS("Attack time"));
    ReleaseTime->setRange (1, 127, 1);
    ReleaseTime->setSliderStyle (Slider::LinearHorizontal);
    ReleaseTime->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    ReleaseTime->addListener (this);

    ReleaseTime->setBounds (192, 54, 76, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (394, 96);


    //[Constructor] You can add your own custom stuff here..
	modelComponent = synthState->model->modulations.GetADSRByName(nameSufix);
	if (modelComponent != nullptr) {

		modelComponent->AttackTime.attachControl(AttackTime.get());
		modelComponent->DecayTime.attachControl(DecayTime.get());
		modelComponent->ReleaseTime.attachControl(ReleaseTime.get());
		modelComponent->InitValue.attachControl(InitLevel.get());
		modelComponent->SustainValue.attachControl(SustainLevel.get());

		setEnabled(true);
		setAlpha(1.0f);
	}
	else {
		setEnabled(false);
		setAlpha(0.5f);
	}

    //[/Constructor]
}

ADSREditor::~ADSREditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    label2 = nullptr;
    label6 = nullptr;
    AttackTime = nullptr;
    DecayTime = nullptr;
    InitLevel = nullptr;
    label4 = nullptr;
    SustainLevel = nullptr;
    label5 = nullptr;
    ReleaseTime = nullptr;


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
    else if (sliderThatWasMoved == ReleaseTime.get())
    {
        //[UserSliderCode_ReleaseTime] -- add your slider handling code here..
        //[/UserSliderCode_ReleaseTime]
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
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="394" initialHeight="96">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="eb7f31cedb99e07" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="120 4 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="c3a45ba72ca00580" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="120 28 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="7060655080d5b7b2" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="120 54 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="DirectValue" id="df72ef78504c47be" memberName="AttackTime"
          virtualName="" explicitFocusOrder="0" pos="192 4 76 24" tooltip="Attack time"
          min="1.0" max="127.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="DirectValue" id="9258fb4fcb5b6574" memberName="DecayTime"
          virtualName="" explicitFocusOrder="0" pos="192 28 76 24" tooltip="Decay time&#10;"
          min="1.0" max="127.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="DirectValue" id="fe24b362f1390fa2" memberName="InitLevel"
          virtualName="" explicitFocusOrder="0" pos="56 31 64 24" tooltip="Initial level"
          thumbcol="ffad0002" min="1.0" max="127.0" int="1.0" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="e2537dd020d310c4" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="0 31 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Initial&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="DirectValue" id="6a522a56e4d2ab40" memberName="SustainLevel"
          virtualName="" explicitFocusOrder="0" pos="56 55 64 24" tooltip="Sustain level&#10;"
          thumbcol="ffad0002" min="1.0" max="127.0" int="1.0" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="7c4b83edc2e8e6c7" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0 55 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="DirectValue" id="bcb2b7b833dce3a5" memberName="ReleaseTime"
          virtualName="" explicitFocusOrder="0" pos="192 54 76 24" tooltip="Attack time"
          min="1.0" max="127.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

