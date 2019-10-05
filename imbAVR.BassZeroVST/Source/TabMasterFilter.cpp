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

#include "TabMasterFilter.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabMasterFilter::TabMasterFilter ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    component_FLT_PWM.reset (new Slider ("DirectValue"));
    addAndMakeVisible (component_FLT_PWM.get());
    component_FLT_PWM->setTooltip (TRANS("Decay time\n"));
    component_FLT_PWM->setRange (1, 100, 1);
    component_FLT_PWM->setSliderStyle (Slider::RotaryHorizontalDrag);
    component_FLT_PWM->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    component_FLT_PWM->addListener (this);

    component_FLT_CutOff.reset (new SourceMixerComponent ("DIST"));
    addAndMakeVisible (component_FLT_CutOff.get());
    component_FLT_CutOff->setBounds (424, 56, 96, 112);

    Title3.reset (new Label ("new label",
                             TRANS("CUTOFF")));
    addAndMakeVisible (Title3.get());
    Title3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title3->setJustificationType (Justification::centred);
    Title3->setEditable (false, false, false);
    Title3->setColour (Label::backgroundColourId, Colour (0xff8d029d));
    Title3->setColour (Label::textColourId, Colours::azure);
    Title3->setColour (TextEditor::textColourId, Colours::black);
    Title3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4.reset (new Label ("new label",
                             TRANS("MAIN FILTER")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (Label::backgroundColourId, Colours::azure);
    label4->setColour (Label::textColourId, Colours::cadetblue);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (424, 8, 400, 24);

    component_FLT_Res.reset (new SourceMixerComponent ("DIST"));
    addAndMakeVisible (component_FLT_Res.get());
    Title5.reset (new Label ("new label",
                             TRANS("RESONANCE")));
    addAndMakeVisible (Title5.get());
    Title5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title5->setJustificationType (Justification::centred);
    Title5->setEditable (false, false, false);
    Title5->setColour (Label::backgroundColourId, Colour (0xff8d029d));
    Title5->setColour (Label::textColourId, Colours::azure);
    Title5->setColour (TextEditor::textColourId, Colours::black);
    Title5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_FLT_Freq.reset (new SourceMixerComponent ("DIST"));
    addAndMakeVisible (component_FLT_Freq.get());
    Title6.reset (new Label ("new label",
                             TRANS("OSC.FREQ\n")));
    addAndMakeVisible (Title6.get());
    Title6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title6->setJustificationType (Justification::centred);
    Title6->setEditable (false, false, false);
    Title6->setColour (Label::backgroundColourId, Colour (0xff8d029d));
    Title6->setColour (Label::textColourId, Colours::azure);
    Title6->setColour (TextEditor::textColourId, Colours::black);
    Title6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_MASTER_Amp.reset (new SourceMixerComponent ("DIST"));
    addAndMakeVisible (component_MASTER_Amp.get());
    Title7.reset (new Label ("new label",
                             TRANS("AMP")));
    addAndMakeVisible (Title7.get());
    Title7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title7->setJustificationType (Justification::centred);
    Title7->setEditable (false, false, false);
    Title7->setColour (Label::backgroundColourId, Colour (0xff397daa));
    Title7->setColour (Label::textColourId, Colours::azure);
    Title7->setColour (TextEditor::textColourId, Colours::black);
    Title7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_MASTER_Pan.reset (new SourceMixerComponent ("DIST"));
    addAndMakeVisible (component_MASTER_Pan.get());
    component_MASTER_Pan->setBounds (632, 240, 96, 112);

    Title8.reset (new Label ("new label",
                             TRANS("PAN")));
    addAndMakeVisible (Title8.get());
    Title8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title8->setJustificationType (Justification::centred);
    Title8->setEditable (false, false, false);
    Title8->setColour (Label::backgroundColourId, Colour (0xff397daa));
    Title8->setColour (Label::textColourId, Colours::azure);
    Title8->setColour (TextEditor::textColourId, Colours::black);
    Title8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_FLT_Dist.reset (new SourceMixerComponent ("DIST"));
    addAndMakeVisible (component_FLT_Dist.get());
    Title9.reset (new Label ("new label",
                             TRANS("MIX")));
    addAndMakeVisible (Title9.get());
    Title9->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title9->setJustificationType (Justification::centred);
    Title9->setEditable (false, false, false);
    Title9->setColour (Label::backgroundColourId, Colour (0xfffe9900));
    Title9->setColour (Label::textColourId, Colours::azure);
    Title9->setColour (TextEditor::textColourId, Colours::black);
    Title9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_FLT_Dist_Overdrive.reset (new Slider ("DirectValue"));
    addAndMakeVisible (component_FLT_Dist_Overdrive.get());
    component_FLT_Dist_Overdrive->setTooltip (TRANS("Source of modulation"));
    component_FLT_Dist_Overdrive->setRange (-127, 127, 1);
    component_FLT_Dist_Overdrive->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    component_FLT_Dist_Overdrive->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    component_FLT_Dist_Overdrive->setColour (Slider::thumbColourId, Colours::crimson);
    component_FLT_Dist_Overdrive->addListener (this);

    component_FLT_Dist_Overdrive->setBounds (424, 240, 96, 84);

    Title11.reset (new Label ("new label",
                              TRANS("OVERDRIVE")));
    addAndMakeVisible (Title11.get());
    Title11->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title11->setJustificationType (Justification::centred);
    Title11->setEditable (false, false, false);
    Title11->setColour (Label::backgroundColourId, Colour (0xfffe9900));
    Title11->setColour (TextEditor::textColourId, Colours::black);
    Title11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title2.reset (new Label ("new label",
                             TRANS("OSC.PWM")));
    addAndMakeVisible (Title2.get());
    Title2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title2->setJustificationType (Justification::centred);
    Title2->setEditable (false, false, false);
    Title2->setColour (Label::backgroundColourId, Colour (0xff8d029d));
    Title2->setColour (Label::textColourId, Colours::azure);
    Title2->setColour (TextEditor::textColourId, Colours::black);
    Title2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_OPMA.reset (new SourceMixerComponent ("DIST"));
    addAndMakeVisible (component_OPMA.get());
    component_OPMA->setBounds (8, 224, 96, 112);

    Title.reset (new Label ("Title",
                            TRANS("MOD A")));
    addAndMakeVisible (Title.get());
    Title->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    Title->setJustificationType (Justification::centredLeft);
    Title->setEditable (false, false, false);
    Title->setColour (Label::backgroundColourId, Colours::cadetblue);
    Title->setColour (TextEditor::textColourId, Colours::black);
    Title->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title4.reset (new Label ("Title",
                             TRANS("MOD B")));
    addAndMakeVisible (Title4.get());
    Title4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    Title4->setJustificationType (Justification::centredLeft);
    Title4->setEditable (false, false, false);
    Title4->setColour (Label::backgroundColourId, Colours::cadetblue);
    Title4->setColour (TextEditor::textColourId, Colours::black);
    Title4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_OPMB.reset (new SourceMixerComponent ("DIST"));
    addAndMakeVisible (component_OPMB.get());
    component_OPM_VAL_A.reset (new Slider ("DirectValue"));
    addAndMakeVisible (component_OPM_VAL_A.get());
    component_OPM_VAL_A->setTooltip (TRANS("Decay time\n"));
    component_OPM_VAL_A->setRange (1, 100, 1);
    component_OPM_VAL_A->setSliderStyle (Slider::RotaryHorizontalDrag);
    component_OPM_VAL_A->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    component_OPM_VAL_A->addListener (this);

    label3.reset (new Label ("new label",
                             TRANS("VAL A")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_OPM_VAL_B.reset (new Slider ("DirectValue"));
    addAndMakeVisible (component_OPM_VAL_B.get());
    component_OPM_VAL_B->setTooltip (TRANS("Decay time\n"));
    component_OPM_VAL_B->setRange (1, 100, 1);
    component_OPM_VAL_B->setSliderStyle (Slider::RotaryHorizontalDrag);
    component_OPM_VAL_B->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    component_OPM_VAL_B->addListener (this);

    label5.reset (new Label ("new label",
                             TRANS("VAL B")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    component_OPM_VAL_C.reset (new Slider ("DirectValue"));
    addAndMakeVisible (component_OPM_VAL_C.get());
    component_OPM_VAL_C->setTooltip (TRANS("Decay time\n"));
    component_OPM_VAL_C->setRange (1, 100, 1);
    component_OPM_VAL_C->setSliderStyle (Slider::RotaryHorizontalDrag);
    component_OPM_VAL_C->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    component_OPM_VAL_C->addListener (this);

    label6.reset (new Label ("new label",
                             TRANS("VAL C")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_OPM.reset (new Label ("new label",
                                TRANS("OPERATION MODE")));
    addAndMakeVisible (label_OPM.get());
    label_OPM->setTooltip (TRANS("Operation modes (OPMs) are hardware level presets controling synthesis and modulation aspects that are not directly controllable from VSTi nor MIDI CC messages. OP MODs and VARs have different role in different OPMs. "));
    label_OPM->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_OPM->setJustificationType (Justification::centredLeft);
    label_OPM->setEditable (false, false, false);
    label_OPM->setColour (Label::backgroundColourId, Colours::azure);
    label_OPM->setColour (Label::textColourId, Colours::cadetblue);
    label_OPM->setColour (TextEditor::textColourId, Colours::black);
    label_OPM->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_OPM->setBounds (8, 8, 400, 24);

    comboBox.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox.get());
    comboBox->setTooltip (TRANS("Operation modes (OPMs) are hardware level presets controling synthesis and modulation aspects that are not directly controllable from VSTi nor MIDI CC messages. OP MODs and VARs have different role in different OPMs. "));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (TRANS("Bass"));
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Bass"), 1);
    comboBox->addItem (TRANS("Lead"), 2);
    comboBox->addItem (TRANS("Fat Synth"), 3);
    comboBox->addItem (TRANS("Kick"), 4);
    comboBox->addItem (TRANS("Fast FX"), 5);
    comboBox->addItem (TRANS("Slow FX"), 6);
    comboBox->addItem (TRANS("Uplifter FX"), 7);
    comboBox->addItem (TRANS("Downlifter FX"), 8);
    comboBox->addItem (TRANS("Chaos FX"), 9);
    comboBox->addSeparator();
    comboBox->addListener (this);

    label_OPM2.reset (new Label ("new label",
                                 TRANS("MASTER OUT")));
    addAndMakeVisible (label_OPM2.get());
    label_OPM2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_OPM2->setJustificationType (Justification::centred);
    label_OPM2->setEditable (false, false, false);
    label_OPM2->setColour (Label::backgroundColourId, Colours::azure);
    label_OPM2->setColour (Label::textColourId, Colours::cadetblue);
    label_OPM2->setColour (TextEditor::textColourId, Colours::black);
    label_OPM2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_OPM2->setBounds (632, 192, 192, 24);

    label_OPM3.reset (new Label ("new label",
                                 TRANS("DISTORTION")));
    addAndMakeVisible (label_OPM3.get());
    label_OPM3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_OPM3->setJustificationType (Justification::centred);
    label_OPM3->setEditable (false, false, false);
    label_OPM3->setColour (Label::backgroundColourId, Colours::azure);
    label_OPM3->setColour (Label::textColourId, Colours::cadetblue);
    label_OPM3->setColour (TextEditor::textColourId, Colours::black);
    label_OPM3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_OPM3->setBounds (424, 192, 192, 24);

    textEditor.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (true);
    textEditor->setReturnKeyStartsNewLine (true);
    textEditor->setReadOnly (true);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (false);
    textEditor->setPopupMenuEnabled (false);
    textEditor->setText (TRANS("Description of selected operation mode"));

    textEditor->setBounds (216, 40, 192, 310);

    cachedImage_basszero_background_jpg_1 = ImageCache::getFromMemory (basszero_background_jpg, basszero_background_jpgSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TabMasterFilter::~TabMasterFilter()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    component_FLT_PWM = nullptr;
    component_FLT_CutOff = nullptr;
    Title3 = nullptr;
    label4 = nullptr;
    component_FLT_Res = nullptr;
    Title5 = nullptr;
    component_FLT_Freq = nullptr;
    Title6 = nullptr;
    component_MASTER_Amp = nullptr;
    Title7 = nullptr;
    component_MASTER_Pan = nullptr;
    Title8 = nullptr;
    component_FLT_Dist = nullptr;
    Title9 = nullptr;
    component_FLT_Dist_Overdrive = nullptr;
    Title11 = nullptr;
    Title2 = nullptr;
    component_OPMA = nullptr;
    Title = nullptr;
    Title4 = nullptr;
    component_OPMB = nullptr;
    component_OPM_VAL_A = nullptr;
    label3 = nullptr;
    component_OPM_VAL_B = nullptr;
    label5 = nullptr;
    component_OPM_VAL_C = nullptr;
    label6 = nullptr;
    label_OPM = nullptr;
    comboBox = nullptr;
    label_OPM2 = nullptr;
    label_OPM3 = nullptr;
    textEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TabMasterFilter::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 0, y = 0, width = 840, height = 444;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black);
        g.drawImage (cachedImage_basszero_background_jpg_1,
                     x, y, width, height,
                     0, 0, cachedImage_basszero_background_jpg_1.getWidth(), cachedImage_basszero_background_jpg_1.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TabMasterFilter::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    component_FLT_PWM->setBounds (((424 + 96) + 96 - -16) + 96, ((56 + 0) + 0) + 8, 96, 68);
    Title3->setBounds (424 + 0, 56 + 0 - 24, 96, 24);
    component_FLT_Res->setBounds (424 + 96, 56 + 0, 96, 112);
    Title5->setBounds ((424 + 96) + 0, (56 + 0) + 0 - 24, 96, 24);
    component_FLT_Freq->setBounds ((424 + 96) + 96 - -16, (56 + 0) + 0, 96, 112);
    Title6->setBounds (((424 + 96) + 96 - -16) + 0, ((56 + 0) + 0) + 0 - 24, 96, 24);
    component_MASTER_Amp->setBounds (632 + 96, 240 + 0, 96, 112);
    Title7->setBounds ((632 + 96) + 0, (240 + 0) + 0 - 24, 96, 24);
    Title8->setBounds (632 + 0, 240 + 0 - 24, 96, 24);
    component_FLT_Dist->setBounds (424 + 96, 240 + 0, 96, 112);
    Title9->setBounds ((424 + 96) + 0, (240 + 0) + -24, 96, 24);
    Title11->setBounds (424 + 0, 240 + 0 - 24, 96, 24);
    Title2->setBounds ((((424 + 96) + 96 - -16) + 96) + 96 / 2 - (96 / 2), (((56 + 0) + 0) + 8) + -8 - 24, 96, 24);
    Title->setBounds (8 + 0, 224 + 0 - 24, 96, 24);
    Title4->setBounds ((8 + 96) + 0, (224 + 0) + 0 - 24, 96, 24);
    component_OPMB->setBounds (8 + 96, 224 + 0, 96, 112);
    component_OPM_VAL_A->setBounds (8 + 1, 8 + 88, 64, 64);
    label3->setBounds ((8 + 1) + 0, (8 + 88) + 0 - 24, 64, 24);
    component_OPM_VAL_B->setBounds (8 + 70, 8 + 88, 64, 64);
    label5->setBounds ((8 + 70) + 0, (8 + 88) + 0 - 24, 64, 24);
    component_OPM_VAL_C->setBounds (8 + 136, 8 + 88, 64, 64);
    label6->setBounds ((8 + 136) + 0, (8 + 88) + 0 - 24, 64, 24);
    comboBox->setBounds (8 + 0, 8 + 32, 200, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TabMasterFilter::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == component_FLT_PWM.get())
    {
        //[UserSliderCode_component_FLT_PWM] -- add your slider handling code here..
        //[/UserSliderCode_component_FLT_PWM]
    }
    else if (sliderThatWasMoved == component_FLT_Dist_Overdrive.get())
    {
        //[UserSliderCode_component_FLT_Dist_Overdrive] -- add your slider handling code here..
        //[/UserSliderCode_component_FLT_Dist_Overdrive]
    }
    else if (sliderThatWasMoved == component_OPM_VAL_A.get())
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

void TabMasterFilter::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
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

<JUCER_COMPONENT documentType="Component" className="TabMasterFilter" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <IMAGE pos="0 0 840 444" resource="basszero_background_jpg" opacity="1.0"
           mode="0"/>
  </BACKGROUND>
  <SLIDER name="DirectValue" id="9258fb4fcb5b6574" memberName="component_FLT_PWM"
          virtualName="" explicitFocusOrder="0" pos="0R 8 96 68" posRelativeX="b56eaad09b7096eb"
          posRelativeY="b56eaad09b7096eb" tooltip="Decay time&#10;" min="1.0"
          max="100.0" int="1.0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <JUCERCOMP name="" id="f783ad21ae1cde8f" memberName="component_FLT_CutOff"
             virtualName="" explicitFocusOrder="0" pos="424 56 96 112" sourceFile="SourceMixerComponent.cpp"
             constructorParams="&quot;DIST&quot;"/>
  <LABEL name="new label" id="a365bba2f343cade" memberName="Title3" virtualName=""
         explicitFocusOrder="0" pos="0 0r 96 24" posRelativeX="f783ad21ae1cde8f"
         posRelativeY="f783ad21ae1cde8f" bkgCol="ff8d029d" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="CUTOFF" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="68edd7ab819d5f21" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="424 8 400 24" bkgCol="fff0ffff" textCol="ff5f9ea0"
         edTextCol="ff000000" edBkgCol="0" labelText="MAIN FILTER" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
  <JUCERCOMP name="" id="4f47fe21802b0b52" memberName="component_FLT_Res"
             virtualName="" explicitFocusOrder="0" pos="0R 0 96 112" posRelativeX="f783ad21ae1cde8f"
             posRelativeY="f783ad21ae1cde8f" sourceFile="SourceMixerComponent.cpp"
             constructorParams="&quot;DIST&quot;"/>
  <LABEL name="new label" id="3774e162b98c4dbd" memberName="Title5" virtualName=""
         explicitFocusOrder="0" pos="0 0r 96 24" posRelativeX="4f47fe21802b0b52"
         posRelativeY="4f47fe21802b0b52" bkgCol="ff8d029d" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="RESONANCE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="b56eaad09b7096eb" memberName="component_FLT_Freq"
             virtualName="" explicitFocusOrder="0" pos="-16R 0 96 112" posRelativeX="4f47fe21802b0b52"
             posRelativeY="4f47fe21802b0b52" sourceFile="SourceMixerComponent.cpp"
             constructorParams="&quot;DIST&quot;"/>
  <LABEL name="new label" id="48aaacf0986cbf0a" memberName="Title6" virtualName=""
         explicitFocusOrder="0" pos="0 0r 96 24" posRelativeX="b56eaad09b7096eb"
         posRelativeY="b56eaad09b7096eb" bkgCol="ff8d029d" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="OSC.FREQ&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="45f28b35571d9af" memberName="component_MASTER_Amp"
             virtualName="" explicitFocusOrder="0" pos="0R 0 96 112" posRelativeX="c46bf90001e86e33"
             posRelativeY="c46bf90001e86e33" sourceFile="SourceMixerComponent.cpp"
             constructorParams="&quot;DIST&quot;"/>
  <LABEL name="new label" id="8d041e19741b51f7" memberName="Title7" virtualName=""
         explicitFocusOrder="0" pos="0 0r 96 24" posRelativeX="45f28b35571d9af"
         posRelativeY="45f28b35571d9af" bkgCol="ff397daa" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="AMP" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="c46bf90001e86e33" memberName="component_MASTER_Pan"
             virtualName="" explicitFocusOrder="0" pos="632 240 96 112" sourceFile="SourceMixerComponent.cpp"
             constructorParams="&quot;DIST&quot;"/>
  <LABEL name="new label" id="bb7808287937fa77" memberName="Title8" virtualName=""
         explicitFocusOrder="0" pos="0 0r 96 24" posRelativeX="c46bf90001e86e33"
         posRelativeY="c46bf90001e86e33" bkgCol="ff397daa" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="e0d2854f1680301b" memberName="component_FLT_Dist"
             virtualName="" explicitFocusOrder="0" pos="0R 0 96 112" posRelativeX="6403b62a87af5079"
             posRelativeY="6403b62a87af5079" sourceFile="SourceMixerComponent.cpp"
             constructorParams="&quot;DIST&quot;"/>
  <LABEL name="new label" id="64301b01a91ef216" memberName="Title9" virtualName=""
         explicitFocusOrder="0" pos="0 -24 96 24" posRelativeX="e0d2854f1680301b"
         posRelativeY="e0d2854f1680301b" bkgCol="fffe9900" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="MIX" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="6403b62a87af5079" memberName="component_FLT_Dist_Overdrive"
          virtualName="" explicitFocusOrder="0" pos="424 240 96 84" tooltip="Source of modulation"
          thumbcol="ffdc143c" min="-127.0" max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="5813524eef0a783d" memberName="Title11" virtualName=""
         explicitFocusOrder="0" pos="0 0r 96 24" posRelativeX="6403b62a87af5079"
         posRelativeY="6403b62a87af5079" bkgCol="fffe9900" edTextCol="ff000000"
         edBkgCol="0" labelText="OVERDRIVE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="cff3fda1ddb79d1f" memberName="Title2" virtualName=""
         explicitFocusOrder="0" pos="0Cc -8r 96 24" posRelativeX="9258fb4fcb5b6574"
         posRelativeY="9258fb4fcb5b6574" bkgCol="ff8d029d" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="OSC.PWM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="e563ecd392baaf03" memberName="component_OPMA" virtualName=""
             explicitFocusOrder="0" pos="8 224 96 112" sourceFile="SourceMixerComponent.cpp"
             constructorParams="&quot;DIST&quot;"/>
  <LABEL name="Title" id="e63b84fabc73ca75" memberName="Title" virtualName=""
         explicitFocusOrder="0" pos="0 0r 96 24" posRelativeX="e563ecd392baaf03"
         posRelativeY="e563ecd392baaf03" bkgCol="ff5f9ea0" edTextCol="ff000000"
         edBkgCol="0" labelText="MOD A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
  <LABEL name="Title" id="1be21c3c90a8e21a" memberName="Title4" virtualName=""
         explicitFocusOrder="0" pos="0 0r 96 24" posRelativeX="a282c0b20a726e97"
         posRelativeY="a282c0b20a726e97" bkgCol="ff5f9ea0" edTextCol="ff000000"
         edBkgCol="0" labelText="MOD B" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
  <JUCERCOMP name="" id="a282c0b20a726e97" memberName="component_OPMB" virtualName=""
             explicitFocusOrder="0" pos="0R 0 96 112" posRelativeX="e563ecd392baaf03"
             posRelativeY="e563ecd392baaf03" sourceFile="SourceMixerComponent.cpp"
             constructorParams="&quot;DIST&quot;"/>
  <SLIDER name="DirectValue" id="f29fd8d619498ce" memberName="component_OPM_VAL_A"
          virtualName="" explicitFocusOrder="0" pos="1 88 64 64" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" min="1.0"
          max="100.0" int="1.0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="c3a45ba72ca00580" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="0 0r 64 24" posRelativeX="f29fd8d619498ce"
         posRelativeY="f29fd8d619498ce" edTextCol="ff000000" edBkgCol="0"
         labelText="VAL A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <SLIDER name="DirectValue" id="e8691d262e63103" memberName="component_OPM_VAL_B"
          virtualName="" explicitFocusOrder="0" pos="70 88 64 64" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" min="1.0"
          max="100.0" int="1.0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="f92bb94970d53673" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0 0r 64 24" posRelativeX="e8691d262e63103"
         posRelativeY="e8691d262e63103" edTextCol="ff000000" edBkgCol="0"
         labelText="VAL B" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <SLIDER name="DirectValue" id="73a4a424a3f96972" memberName="component_OPM_VAL_C"
          virtualName="" explicitFocusOrder="0" pos="136 88 64 64" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" min="1.0"
          max="100.0" int="1.0" style="RotaryHorizontalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="11c89457f06ac99" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="0 0r 64 24" posRelativeX="73a4a424a3f96972"
         posRelativeY="73a4a424a3f96972" edTextCol="ff000000" edBkgCol="0"
         labelText="VAL C" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="new label" id="5eeb447276336bd" memberName="label_OPM"
         virtualName="" explicitFocusOrder="0" pos="8 8 400 24" tooltip="Operation modes (OPMs) are hardware level presets controling synthesis and modulation aspects that are not directly controllable from VSTi nor MIDI CC messages. OP MODs and VARs have different role in different OPMs. "
         bkgCol="fff0ffff" textCol="ff5f9ea0" edTextCol="ff000000" edBkgCol="0"
         labelText="OPERATION MODE" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="33" typefaceStyle="Bold"/>
  <COMBOBOX name="new combo box" id="3d5e9118fb63659c" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="0 32 200 24" posRelativeX="5eeb447276336bd"
            posRelativeY="5eeb447276336bd" tooltip="Operation modes (OPMs) are hardware level presets controling synthesis and modulation aspects that are not directly controllable from VSTi nor MIDI CC messages. OP MODs and VARs have different role in different OPMs. "
            editable="0" layout="33" items="Bass&#10;Lead&#10;Fat Synth&#10;Kick&#10;Fast FX&#10;Slow FX&#10;Uplifter FX&#10;Downlifter FX&#10;Chaos FX&#10;"
            textWhenNonSelected="Bass" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="9625eaef48bbdc8f" memberName="label_OPM2"
         virtualName="" explicitFocusOrder="0" pos="632 192 192 24" bkgCol="fff0ffff"
         textCol="ff5f9ea0" edTextCol="ff000000" edBkgCol="0" labelText="MASTER OUT"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="1"
         italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="new label" id="fcf57e920b215810" memberName="label_OPM3"
         virtualName="" explicitFocusOrder="0" pos="424 192 192 24" bkgCol="fff0ffff"
         textCol="ff5f9ea0" edTextCol="ff000000" edBkgCol="0" labelText="DISTORTION"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="1"
         italic="0" justification="36" typefaceStyle="Bold"/>
  <TEXTEDITOR name="new text editor" id="579bc3b9c3136d69" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="216 40 192 310" initialText="Description of selected operation mode"
              multiline="1" retKeyStartsLine="1" readonly="1" scrollbars="1"
              caret="0" popupmenu="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: basszero_background_jpg, 10853, "../basszero_background.jpg"
static const unsigned char resource_TabMasterFilter_basszero_background_jpg[] = { 255,216,255,224,0,16,74,70,73,70,0,1,2,0,0,100,0,100,0,0,255,236,0,17,68,117,99,107,121,0,1,0,4,0,0,0,96,0,0,255,238,0,
38,65,100,111,98,101,0,100,192,0,0,0,1,3,0,21,4,3,6,10,13,0,0,14,121,0,0,14,157,0,0,26,254,0,0,42,99,255,219,0,132,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,2,2,2,1,2,2,2,2,2,2,2,
2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1,1,3,2,2,3,4,3,3,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,255,194,0,17,8,1,188,3,72,
3,1,17,0,2,17,1,3,17,1,255,196,0,157,0,1,0,3,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,9,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,5,16,0,3,0,2,3,0,3,1,1,0,0,0,0,0,0,0,0,1,17,48,96,16,32,64,80,112,192,128,18,
17,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,18,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,19,1,0,2,0,3,5,8,2,3,1,1,1,1,0,0,0,1,0,17,16,33,49,96,65,81,97,113,32,48,64,240,129,145,161,177,80,193,112,209,225,128,241,
144,160,255,218,0,12,3,1,0,2,17,3,17,0,0,1,243,175,169,197,0,0,0,0,0,0,0,0,0,0,0,0,0,107,27,214,241,117,181,128,10,203,89,48,211,8,198,180,141,235,162,46,182,176,0,0,164,185,167,57,133,84,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,88,222,58,13,22,246,0,5,102,169,51,142,152,198,52,54,141,235,105,110,77,128,0,33,105,24,217,207,24,208,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
3,104,232,173,165,189,74,0,43,45,99,59,50,170,70,85,66,198,241,185,170,222,192,0,2,178,230,156,245,132,82,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,227,122,222,52,106,247,32,10,203,83,
52,198,171,16,103,84,6,145,189,111,26,45,172,0,1,5,101,198,206,120,198,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,155,70,245,182,86,186,181,200,133,172,68,82,206,115,10,0,84,18,107,27,214,
217,94,219,88,0,2,178,209,57,235,8,206,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,120,222,183,139,203,54,130,65,84,173,102,103,24,213,64,0,22,54,141,235,92,219,85,172,0,1,73,114,78,115,10,
128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,155,70,213,172,90,89,168,147,58,206,171,16,65,82,149,64,0,0,185,180,109,90,230,218,173,96,0,86,90,39,61,97,25,208,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,11,155,70,213,166,82,65,77,57,227,26,16,72,32,128,0,0,26,70,166,213,174,109,170,108,144,8,90,198,54,115,198,53,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,109,26,86,165,162,
74,214,102,81,149,84,0,0,0,0,1,164,106,107,90,197,150,73,22,68,176,81,57,235,24,206,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,22,53,139,214,132,144,80,172,86,41,166,96,0,0,0,0,1,120,212,210,
174,94,45,44,209,69,102,114,211,8,198,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,198,177,106,177,5,98,165,74,212,16,0,0,0,0,0,2,197,226,197,139,214,145,120,144,103,88,214,17,74,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,105,26,10,136,202,170,0,0,0,0,0,0,0,0,144,94,52,54,173,114,146,181,149,99,24,212,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,172,90,41,89,212,0,0,0,0,0,0,
0,0,0,22,55,141,171,76,134,122,99,24,148,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,203,196,17,84,32,0,0,0,0,0,0,0,0,0,214,55,173,162,209,90,202,177,140,106,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,36,184,32,160,0,0,0,0,0,0,0,0,0,44,116,70,213,166,80,103,166,49,137,74,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,88,130,0,0,0,0,0,0,0,0,0,0,36,222,54,173,34,209,77,50,49,140,
170,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,36,2,0,0,0,0,4,155,70,181,161,104,173,84,202,49,170,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,210,44,72,32,161,74,
130,72,0,0,0,53,141,43,66,224,131,34,145,141,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,130,0,0,0,0,0,2,77,98,229,234,196,144,80,164,102,88,131,58,128,0,0,177,172,88,181,88,146,166,113,153,157,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,46,10,16,0,0,0,0,0,185,172,105,90,197,162,84,69,149,41,80,84,172,80,161,21,4,0,11,22,139,22,52,161,6,113,141,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,114,65,
82,160,0,0,0,0,11,154,198,213,174,86,186,148,154,136,128,65,9,82,149,82,177,82,166,85,0,0,105,27,86,164,25,153,70,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,98,192,25,128,0,0,0,0,36,218,54,173,178,189,
213,174,64,2,4,176,65,5,82,149,145,156,99,64,1,120,222,182,36,161,140,99,85,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,177,37,8,0,0,0,0,0,105,27,87,68,93,171,220,128,0,0,66,214,34,51,179,3,158,160,0,
94,58,107,104,180,86,177,172,99,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,65,0,0,0,0,0,9,54,141,235,108,219,212,216,0,0,0,43,45,99,29,76,34,133,42,1,180,116,214,185,179,105,51,76,43,8,165,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,120,220,220,209,111,96,0,0,0,21,150,137,141,99,24,212,23,142,138,232,139,181,55,49,45,76,172,194,48,168,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,214,55,173,162,235,123,0,0,0,0,172,180,78,122,231,139,27,86,209,162,222,192,43,45,19,10,194,50,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,32,0,0,0,147,104,218,182,139,173,172,0,0,0,2,
146,209,51,36,208,178,222,192,0,164,185,167,57,133,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,134,96,0,0,0,147,104,222,182,150,197,172,0,0,0,2,37,169,36,147,96,0,8,150,134,22,115,198,84,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,12,192,0,0,0,44,109,27,86,210,216,181,128,0,0,0,0,0,0,1,73,115,78,115,10,168,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,104,84,16,64,0,0,1,99,104,222,181,
205,181,90,192,0,0,0,0,0,0,4,45,35,11,57,227,42,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,128,0,0,0,0,0,185,36,149,40,0,0,0,11,27,70,245,172,182,45,96,0,0,0,0,0,0,2,146,230,156,231,61,64,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,2,229,0,0,0,0,0,2,229,226,98,181,157,64,0,0,0,44,109,27,214,178,222,165,0,0,0,0,0,0,0,133,164,115,217,207,25,208,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,88,21,0,0,0,0,0,11,26,68,192,207,72,32,128,
0,0,2,198,241,185,170,218,201,0,0,0,0,0,0,0,164,185,39,49,141,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,185,82,0,0,0,0,0,2,77,34,240,164,86,179,170,128,0,0,2,230,241,185,162,222,192,0,0,0,0,0,0,43,46,105,206,
115,213,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,202,0,0,0,0,0,0,23,53,201,160,70,102,116,0,0,0,6,177,189,116,75,122,148,0,0,0,0,0,0,16,180,142,123,57,227,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,38,
177,97,66,35,42,21,0,0,0,36,222,58,13,86,246,0,0,0,0,0,0,1,73,113,179,154,49,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,230,176,160,35,42,86,116,0,0,0,47,29,53,209,45,234,80,0,0,0,0,0,0,82,92,211,
152,231,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,77,98,194,164,130,35,58,130,160,0,0,36,222,58,77,86,214,0,0,0,0,0,0,10,203,154,115,28,245,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,99,88,
154,177,4,68,70,90,84,0,0,0,214,58,107,121,111,96,0,0,0,0,0,0,172,185,167,49,207,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,230,145,52,3,44,116,168,0,0,1,99,164,233,150,245,40,0,0,0,0,0,1,89,114,
78,115,158,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,210,52,20,25,101,165,0,0,0,9,58,35,168,186,218,192,0,0,0,0,0,10,75,146,115,156,244,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,210,
46,41,150,90,80,0,0,0,29,17,210,104,183,176,0,0,0,0,0,16,82,92,108,231,140,104,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,54,202,72,43,85,170,0,0,0,177,180,116,86,153,182,169,169,64,0,0,0,0,21,
150,137,207,88,70,116,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,203,19,2,180,51,0,0,1,38,209,181,105,22,137,89,161,36,212,160,0,0,5,101,169,154,115,152,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,73,98,8,4,0,0,0,18,107,23,171,22,4,150,137,44,89,68,128,0,32,136,165,152,214,49,149,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,161,104,16,64,44,88,189,92,180,73,36,130,1,
5,106,134,113,141,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,65,0,0,73,104,185,98,65,32,130,0,32,165,102,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,144,
1,32,128,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,139,194,168,84,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,72,32,2,224,130,8,0,0,88,188,90,38,162,51,210,128,146,0,0,18,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,146,74,128,73,112,65,5,139,229,36,17,80,64,4,146,76,
77,40,34,165,42,209,36,85,72,0,176,40,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,184,32,128,88,190,82,66,144,9,160,136,10,65,34,148,0,8,136,146,2,197,149,160,5,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,185,32,0,11,64,152,0,72,4,0,9,2,128,1,2,1,21,4,84,16,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,32,0,72,0,0,0,0,0,73,48,0,1,80,8,32,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,218,0,8,1,1,0,1,5,2,248,68,44,44,124,33,99,122,122,16,176,190,136,88,216,244,212,44,79,162,225,99,99,210,208,133,129,178,
246,66,198,244,213,133,151,139,213,11,27,30,146,132,46,247,34,196,244,181,214,148,185,23,9,226,99,209,215,118,82,243,113,39,194,120,94,144,133,230,79,139,133,143,71,94,123,197,41,123,61,54,151,199,120,
165,47,86,61,38,250,111,9,244,122,75,245,174,239,99,66,232,246,68,46,207,104,123,42,236,245,9,214,101,90,196,226,16,132,39,19,194,244,213,130,16,132,33,8,78,244,186,146,225,98,132,33,48,174,175,78,89,
166,4,46,175,76,66,206,251,161,116,99,211,150,118,136,78,136,93,88,244,196,33,103,107,162,66,236,244,228,47,3,33,9,129,143,78,79,60,63,201,48,177,233,233,250,152,244,244,253,44,99,211,211,244,177,234,
9,250,24,245,20,253,12,127,30,254,9,63,59,30,138,241,161,11,204,198,61,17,228,66,243,177,232,179,34,23,153,143,64,94,20,47,51,30,143,49,161,121,88,244,135,137,11,204,244,135,137,11,202,199,169,175,43,
30,166,133,228,99,213,23,145,143,103,122,189,41,74,82,229,99,213,169,74,82,148,165,41,120,165,41,74,82,235,212,165,41,74,82,148,187,53,251,22,108,243,171,214,39,104,66,16,152,39,241,53,47,20,165,41,74,
82,148,165,41,74,82,148,165,230,253,33,255,218,0,8,1,2,0,1,5,2,252,223,31,255,218,0,8,1,3,0,1,5,2,252,223,31,255,218,0,8,1,2,2,6,63,2,55,199,255,218,0,8,1,3,2,6,63,2,55,199,255,218,0,8,1,1,1,6,63,2,55,
199,255,218,0,8,1,1,3,1,63,33,252,32,130,4,59,44,123,18,138,15,116,34,68,216,209,4,29,195,63,72,199,5,20,33,219,99,4,27,26,32,132,59,46,11,22,14,10,12,93,210,65,6,197,136,32,237,92,112,28,23,29,49,81,
65,238,28,4,77,139,8,33,216,188,86,41,105,120,47,176,162,131,14,219,18,8,54,36,96,29,155,151,24,88,199,182,53,6,40,48,123,129,19,98,72,33,141,199,21,110,11,29,59,133,7,0,101,246,152,193,6,195,136,66,26,
98,177,75,75,75,101,224,190,232,28,1,194,251,14,2,36,118,32,52,131,46,44,88,196,240,0,194,7,27,151,28,24,32,216,82,24,6,89,46,46,15,129,32,97,6,5,246,68,118,20,134,22,75,151,47,18,252,8,194,47,1,36,94,
41,128,108,40,226,177,240,235,150,194,71,0,112,96,142,194,144,124,105,84,24,56,177,131,97,70,92,124,98,138,24,48,71,97,76,87,197,234,192,96,198,48,108,45,203,241,134,176,132,49,17,217,42,101,74,123,242,
44,47,6,48,108,120,92,34,176,169,81,138,194,187,176,193,197,210,49,252,237,74,240,33,2,17,83,213,129,135,6,163,9,93,192,193,151,46,92,188,71,230,207,8,8,18,176,169,93,148,97,193,180,167,179,120,8,28,82,
49,63,52,98,248,32,194,165,74,198,165,70,28,117,74,137,218,80,134,145,34,65,249,161,240,68,48,29,186,149,43,10,149,24,72,157,173,120,170,36,72,63,55,120,58,247,234,40,119,117,133,65,18,58,246,227,4,130,
13,140,32,197,8,119,117,19,1,135,176,16,118,18,8,54,49,69,23,122,196,192,99,174,32,129,133,74,192,68,142,198,40,160,247,201,4,180,36,128,236,177,32,131,99,71,0,123,231,18,29,192,130,37,59,24,53,7,0,97,
222,84,169,82,187,108,96,131,99,70,160,224,12,31,14,32,131,96,82,84,74,238,134,160,224,12,31,10,198,24,54,0,211,10,142,157,216,212,28,1,135,134,16,71,241,238,158,0,134,15,120,53,7,0,97,225,24,193,15,227,
143,2,33,138,74,143,116,53,7,16,240,162,15,199,26,71,192,157,138,239,10,40,188,43,137,171,241,187,188,17,224,74,40,48,240,108,118,7,33,216,112,39,118,162,217,113,118,158,237,71,8,120,86,246,192,142,53,
131,129,59,165,20,60,27,136,235,176,3,12,14,17,193,238,206,63,8,199,3,174,192,143,128,106,194,67,193,56,142,187,4,61,151,186,53,192,67,194,55,182,16,123,9,221,238,120,51,24,182,20,67,22,39,114,67,176,
191,0,197,176,179,11,151,221,154,194,12,25,114,241,185,114,251,149,193,69,142,187,8,53,46,92,182,91,221,144,123,15,207,60,107,198,229,203,151,46,94,23,22,40,182,80,101,246,222,36,196,95,108,6,22,46,202,
92,183,182,96,117,118,129,213,58,165,203,139,179,246,203,101,178,217,105,120,219,45,254,65,86,14,202,215,100,37,74,149,220,3,182,167,183,78,194,212,174,192,99,70,0,149,133,74,193,209,58,39,70,10,237,37,
224,169,82,165,74,149,43,23,96,235,26,149,43,197,167,101,118,16,237,220,185,100,178,101,225,46,94,23,47,97,237,150,203,101,178,217,120,151,222,0,15,86,14,169,213,58,167,84,234,157,82,201,120,45,254,15,
255,218,0,8,1,2,3,1,63,33,255,0,128,93,158,127,149,235,104,222,221,255,0,38,86,59,252,81,177,27,252,101,127,44,27,20,127,3,184,31,241,198,252,107,101,171,249,60,237,222,209,29,221,237,101,236,235,255,
0,214,99,248,173,218,151,10,255,0,152,141,148,124,41,181,36,118,160,254,62,127,145,42,86,222,86,209,215,117,93,154,149,255,0,126,94,21,179,247,47,179,125,205,237,51,180,151,46,92,185,127,207,223,255,218,
0,8,1,3,3,1,63,33,252,97,183,38,201,191,202,149,255,0,41,27,79,95,254,56,110,94,53,181,87,181,151,180,15,253,103,120,223,108,254,83,63,148,207,248,165,240,103,242,3,255,0,30,59,82,255,0,42,86,214,214,
214,212,169,82,191,252,81,255,0,255,218,0,12,3,1,0,2,17,3,17,0,0,16,146,73,36,146,73,36,146,73,36,146,73,36,146,77,43,146,78,194,138,23,36,146,18,144,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,
146,73,36,146,73,36,146,73,36,146,73,36,146,73,181,50,72,156,176,32,20,146,72,0,210,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,128,18,73,182,132,72,177,
50,73,35,51,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,132,130,73,226,132,201,52,172,73,36,166,97,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,
146,73,36,146,73,36,146,73,36,146,72,16,106,17,242,208,65,32,211,185,36,147,152,164,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,48,91,98,8,4,73,36,131,5,228,
146,18,144,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,3,23,22,130,70,201,36,146,5,23,146,73,204,82,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,
73,36,146,73,36,146,73,32,65,158,20,16,73,36,146,72,180,78,201,0,24,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,50,105,5,18,73,36,146,73,34,80,150,175,162,41,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,22,9,34,114,73,36,146,73,36,155,8,81,219,132,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,
146,73,36,128,137,52,210,73,36,146,73,36,146,15,176,223,156,52,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,97,12,146,73,36,146,73,36,146,73,4,90,51,35,18,73,36,
146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,75,18,73,36,146,73,36,146,73,36,146,41,252,218,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,
146,73,37,224,73,36,146,73,36,146,73,36,146,76,17,65,9,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,144,73,36,146,73,36,146,73,36,146,73,16,46,109,36,146,73,36,146,
73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,130,73,36,146,73,36,146,73,36,146,73,38,144,129,196,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,
73,36,146,73,36,16,73,36,146,73,32,66,9,16,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,34,179,44,32,146,73,36,158,65,36,34,73,36,146,73,36,146,73,36,
146,73,36,146,73,36,146,73,36,146,73,36,146,73,4,146,73,36,146,73,0,66,1,22,218,73,36,146,20,32,153,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,32,18,73,36,146,73,32,33,125,
138,146,37,132,146,64,158,16,89,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,4,146,73,36,146,73,36,154,61,199,230,89,2,78,73,36,210,64,164,146,73,36,146,73,36,146,73,36,146,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,130,198,164,144,212,200,0,41,36,138,0,52,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,130,73,36,146,73,36,146,104,32,146,73,
33,29,37,36,147,8,100,210,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,64,36,146,73,36,146,65,166,82,73,36,146,116,22,18,97,177,211,73,36,146,73,36,146,73,36,146,73,36,146,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,50,68,201,36,146,73,236,210,96,85,242,33,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,194,241,36,146,73,
35,33,33,105,145,208,164,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,32,146,73,36,129,74,228,146,73,36,30,236,105,146,26,144,146,73,36,146,73,36,146,73,36,146,73,36,146,
73,36,146,73,36,146,73,36,146,73,36,18,73,36,146,77,7,146,73,36,144,46,208,146,72,128,210,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,130,73,36,146,72,20,30,73,36,146,73,
36,146,73,39,216,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,144,65,36,146,73,32,65,121,36,146,73,36,146,73,36,18,121,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,
36,146,9,36,146,73,36,146,72,36,146,73,36,129,1,228,146,73,36,146,73,36,147,197,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,65,36,146,73,36,146,65,127,18,73,36,146,5,32,146,73,36,146,73,36,
146,1,52,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,65,36,146,73,36,146,72,47,242,73,36,146,73,18,54,73,36,146,73,36,146,64,86,18,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,4,146,
73,36,146,73,6,105,217,36,146,73,32,87,201,36,146,73,36,146,73,61,82,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,4,146,73,36,146,73,36,142,65,164,146,73,36,138,1,36,146,73,36,146,73,36,19,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,233,12,18,73,36,144,45,68,146,73,36,146,73,36,4,105,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,
146,67,36,250,73,36,146,76,0,146,73,36,146,73,36,146,165,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,64,84,18,193,36,146,72,18,114,73,36,146,73,36,146,48,228,146,73,36,
146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,1,144,103,36,146,73,34,4,201,36,146,73,36,146,78,52,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,22,
72,228,146,73,36,144,73,36,146,73,36,146,72,226,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,145,25,24,146,73,36,131,31,36,146,73,36,146,73,14,82,73,36,146,73,36,146,
73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,4,97,146,73,36,146,105,196,146,73,36,146,73,44,26,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,25,184,
73,36,146,14,51,134,73,36,146,73,35,49,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,0,46,9,36,146,73,198,248,214,12,146,73,7,139,73,36,146,73,36,146,73,36,146,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,2,73,36,146,72,40,128,5,41,175,255,0,253,218,105,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,
36,181,108,180,154,82,104,80,1,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,32,217,44,150,221,17,36,146,73,36,146,73,36,146,73,36,146,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,9,36,0,9,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,72,36,146,
73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,72,132,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,
73,36,146,73,36,146,73,36,146,72,36,130,65,36,146,73,207,18,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,32,18,73,32,129,159,118,89,94,164,198,100,0,16,
65,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,32,18,9,25,78,210,77,223,145,36,144,83,241,146,9,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,
36,146,73,36,146,73,33,173,254,73,255,0,210,64,72,51,125,82,9,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,144,73,32,16,9,36,146,73,2,219,100,32,146,73,36,146,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,255,218,0,8,1,1,3,1,63,16,252,37,5,249,
185,199,234,202,143,184,47,167,103,87,164,210,244,253,65,175,65,130,207,143,222,27,182,83,151,148,151,121,212,131,89,238,237,165,196,159,227,201,149,89,185,149,62,117,216,219,27,150,39,42,247,148,122,
124,176,61,224,81,217,91,86,60,158,115,126,5,140,20,245,206,13,55,44,4,115,154,127,17,12,91,189,187,99,127,188,23,235,247,53,252,231,44,30,90,196,166,182,44,45,162,80,19,79,227,172,21,233,6,255,0,110,
202,188,136,190,211,219,220,113,154,156,95,172,14,87,195,247,133,13,123,74,179,220,207,245,228,193,131,103,109,43,41,119,238,80,223,188,171,63,53,177,119,103,230,165,159,71,89,71,166,68,33,145,216,109,
145,21,126,229,31,162,34,229,239,23,139,239,16,105,155,53,58,125,103,141,249,50,188,188,164,184,62,57,144,119,193,188,251,66,206,145,38,191,155,38,177,194,37,53,177,33,109,74,128,222,212,163,211,35,172,
21,71,8,106,97,103,24,240,124,197,226,197,246,153,124,143,150,35,124,190,90,141,143,212,191,47,153,209,243,27,149,85,136,211,114,208,227,172,230,255,0,140,179,247,21,116,237,138,121,51,43,153,164,171,
63,53,254,77,241,215,98,119,222,106,12,239,219,171,52,14,25,250,195,27,137,227,30,95,86,115,47,145,164,247,247,28,38,135,163,14,119,199,183,115,151,212,223,158,164,209,243,100,246,62,165,29,59,73,100,
103,247,122,111,154,199,13,34,83,91,14,22,132,52,77,14,89,189,97,202,248,194,92,105,175,180,175,250,34,183,127,95,236,83,254,219,57,223,175,169,103,18,5,81,53,189,59,138,114,149,230,105,60,156,73,103,
79,168,83,167,104,103,214,28,186,125,74,155,225,244,205,246,195,221,159,31,168,109,61,225,202,248,205,15,95,188,22,179,102,251,123,164,80,93,120,17,111,47,234,116,39,73,243,202,95,151,204,232,249,138,
122,119,59,135,255,0,101,125,31,137,103,157,101,154,65,225,0,242,236,104,245,140,212,229,244,205,99,203,5,53,237,211,97,66,218,130,143,131,161,55,189,38,151,175,220,163,39,73,93,196,222,44,214,119,232,
65,99,40,204,211,121,223,238,31,253,149,230,105,57,222,187,189,103,162,252,75,130,238,103,49,41,21,228,71,72,119,250,74,27,244,102,248,242,108,41,206,248,19,65,22,167,172,163,39,73,206,248,99,194,123,
206,109,177,87,88,168,231,131,171,215,191,221,63,251,55,131,55,63,14,147,153,92,156,200,127,232,133,180,101,226,150,36,176,235,148,57,60,162,83,91,8,233,174,63,113,101,211,40,52,220,231,124,49,225,207,
156,83,171,151,177,18,121,162,39,143,180,121,61,226,159,243,192,169,175,190,248,15,249,254,192,238,107,227,238,11,175,158,83,137,243,253,205,12,253,24,7,73,110,26,199,29,62,224,206,253,250,147,125,230,
182,23,125,199,94,184,209,17,210,42,235,225,173,197,247,129,111,243,233,56,147,215,56,75,43,60,247,50,206,184,29,254,146,207,95,178,27,58,68,165,54,17,211,91,159,185,102,78,187,176,23,151,40,137,175,138,
69,83,75,131,46,234,65,178,226,89,80,88,155,207,178,26,111,143,220,169,191,53,176,182,23,188,214,1,215,40,173,244,154,228,196,165,60,85,199,157,102,151,179,30,117,199,3,157,241,154,156,243,58,195,103,
157,34,82,155,8,169,228,235,136,153,25,191,83,92,223,20,235,203,164,89,215,31,212,89,14,2,207,152,44,233,156,52,245,206,84,223,154,216,81,133,107,20,242,60,102,151,175,212,90,61,24,242,72,247,111,193,
201,122,205,78,89,157,33,179,206,145,41,77,145,229,75,242,249,157,39,207,56,137,168,247,166,167,82,105,154,15,163,7,68,135,25,237,22,243,135,71,210,10,83,205,74,179,225,245,177,233,209,198,122,31,108,
1,187,222,3,184,125,34,183,158,228,75,231,251,156,31,143,234,40,233,199,1,57,135,116,175,212,185,67,201,214,81,204,130,58,56,107,122,67,149,240,134,206,159,81,41,175,206,9,228,69,26,251,248,0,182,166,
251,118,233,99,246,206,1,234,195,141,246,148,132,60,61,73,79,47,146,113,15,88,139,202,7,159,212,179,159,220,94,225,86,94,210,206,187,200,35,79,104,30,144,124,111,172,74,85,103,254,224,148,215,9,188,225,
153,211,243,98,222,91,240,75,42,37,41,223,143,150,161,52,143,86,89,150,129,10,104,74,158,136,158,21,210,55,220,61,50,99,155,79,139,137,229,237,95,81,123,138,233,156,77,229,244,130,245,249,138,221,253,
196,60,255,0,115,145,245,41,53,19,176,51,95,125,240,231,247,63,168,44,163,51,51,132,27,46,86,253,210,226,205,79,152,44,250,148,60,157,63,52,114,235,137,202,248,119,235,35,147,159,189,195,159,172,222,244,
154,8,101,4,242,157,127,18,209,56,146,140,9,225,237,1,231,240,206,71,185,127,36,120,62,51,251,138,60,211,30,50,60,62,204,163,167,215,106,236,152,242,78,31,184,40,123,251,205,233,237,55,198,253,121,50,
220,252,143,230,128,41,203,193,42,121,111,138,200,239,212,249,38,147,206,248,106,118,104,225,41,57,24,241,18,162,120,71,255,0,44,228,87,92,198,87,167,169,194,92,95,188,114,203,179,228,244,102,247,164,
13,15,72,163,116,187,58,235,40,177,211,245,40,127,52,40,192,187,235,3,93,89,247,255,0,212,202,31,146,61,220,115,33,12,206,225,7,116,120,62,98,113,35,234,39,248,202,148,227,53,60,238,236,140,239,206,144,
233,214,253,161,222,250,97,188,61,167,7,211,175,9,97,18,154,127,54,41,163,21,117,239,213,60,183,205,246,242,104,215,82,47,152,183,123,119,109,58,79,99,234,114,188,241,133,121,153,244,184,6,239,83,40,148,
214,53,1,189,154,94,114,32,123,96,156,33,122,58,242,148,55,239,43,204,242,108,101,121,121,169,67,174,186,117,150,122,252,48,96,217,221,138,233,44,253,79,67,245,14,72,238,253,77,111,79,172,44,205,151,231,
228,37,71,63,162,5,228,74,70,157,34,127,179,87,205,147,88,130,159,173,139,211,50,90,78,47,254,203,183,231,187,153,7,121,6,251,180,172,183,75,188,234,71,206,184,62,209,117,235,241,42,115,205,143,195,47,
137,93,121,182,6,232,21,136,174,146,227,234,111,253,78,146,252,207,46,193,83,87,89,119,66,140,191,51,94,51,141,255,0,140,179,247,6,186,119,105,113,56,203,188,229,28,218,121,244,133,55,125,3,237,4,243,
148,14,16,43,176,150,84,79,121,103,174,126,179,80,220,207,88,216,23,71,163,245,221,178,229,52,210,104,103,211,250,150,126,226,174,157,218,94,177,224,157,30,125,32,184,121,245,135,20,10,211,180,55,251,
193,126,191,115,223,253,159,220,176,216,29,122,61,227,174,95,83,126,122,147,67,205,192,124,233,40,233,225,147,82,89,235,151,172,161,121,255,0,228,161,243,174,192,26,29,15,168,139,102,253,72,61,249,124,
206,34,251,167,92,190,166,252,245,39,147,140,246,62,165,29,60,40,223,5,250,207,47,50,92,126,66,154,186,203,192,102,29,62,178,149,122,69,26,147,50,233,245,159,118,235,148,223,158,164,187,206,178,206,159,
81,86,78,158,21,53,37,158,185,122,204,196,227,247,13,61,126,255,0,28,22,212,203,78,135,128,211,209,154,25,231,116,20,242,98,82,157,219,174,83,126,122,146,207,58,203,34,220,250,120,65,190,11,245,251,155,
239,95,238,111,61,125,191,28,115,88,180,61,124,3,205,56,159,83,75,214,121,168,150,84,127,95,132,135,30,124,161,167,45,30,234,245,58,74,243,221,245,50,60,251,193,184,175,175,131,75,42,51,91,223,209,153,
9,194,37,41,248,221,47,88,173,122,248,1,164,99,207,169,141,68,110,201,154,14,189,221,45,50,148,248,150,215,199,38,14,255,0,9,171,172,25,116,203,209,130,159,113,244,130,188,183,126,54,232,113,162,188,19,
200,226,118,78,190,253,229,249,51,118,190,120,203,63,125,98,221,237,224,198,87,194,11,245,62,96,223,235,237,148,27,250,127,95,159,84,242,223,29,149,195,176,44,230,71,54,181,202,160,133,151,221,13,55,52,
95,126,146,239,168,63,16,204,240,78,100,116,135,237,61,18,11,62,58,94,192,123,135,201,7,176,131,172,52,61,31,174,238,166,188,212,220,122,71,103,195,214,45,222,13,223,14,189,47,218,15,219,247,28,148,231,
249,241,166,230,234,242,116,197,65,123,191,188,5,159,81,3,152,244,188,161,25,157,59,145,164,102,131,232,203,142,191,100,89,143,131,212,204,197,114,102,167,167,234,106,108,5,77,113,211,172,86,115,223,131,
222,244,130,158,91,176,22,60,179,154,3,159,215,117,145,94,114,153,7,163,237,148,32,217,126,11,83,231,116,221,245,154,189,38,183,167,214,192,243,243,251,32,222,103,97,155,158,189,211,168,89,250,253,145,
228,116,250,154,60,22,167,206,147,71,163,50,47,157,211,83,96,191,220,131,216,211,235,221,100,29,126,242,143,49,229,126,186,199,151,71,226,106,240,78,145,235,232,126,226,213,230,174,163,154,188,246,8,81,
178,123,111,195,216,186,248,142,93,209,203,89,251,162,203,208,96,232,205,124,2,163,174,15,220,197,71,187,236,108,35,206,184,197,103,76,117,250,76,171,223,191,167,115,175,210,101,79,111,212,84,30,163,6,
10,64,116,150,113,59,229,183,148,121,117,250,151,121,220,69,187,207,29,132,57,95,24,53,58,126,98,248,126,230,177,64,111,255,0,123,157,47,88,178,58,19,125,185,148,235,153,1,199,223,253,193,114,249,193,
113,253,206,98,83,143,113,164,179,167,220,95,246,106,123,19,89,220,105,29,249,107,176,137,204,74,243,34,247,101,57,223,4,231,124,18,239,94,228,212,234,71,149,112,148,116,225,10,111,79,169,212,123,50,155,
255,0,100,167,24,57,154,230,31,168,7,135,164,15,31,121,114,249,203,113,150,229,45,202,91,148,183,41,110,50,249,199,209,50,121,113,150,245,79,98,80,108,166,130,111,149,224,196,31,238,81,30,109,250,158,
89,67,209,233,1,124,33,205,125,98,111,254,231,148,127,80,231,61,114,128,228,244,97,215,233,41,206,83,156,245,74,26,149,235,30,115,211,56,245,63,4,245,158,6,132,212,89,115,211,239,101,4,127,177,77,245,
211,180,41,163,20,215,251,32,31,55,14,15,151,247,5,198,253,165,185,75,114,249,150,229,243,45,202,116,190,38,111,34,60,77,250,220,71,25,239,238,56,108,255,0,49,251,251,156,239,130,115,190,9,206,248,32,
31,226,145,111,47,153,111,23,221,150,241,125,217,70,247,239,238,115,190,13,153,167,131,236,237,48,46,68,56,179,228,65,240,168,137,172,57,15,58,217,81,165,229,235,17,53,59,20,107,155,245,16,238,61,50,143,
11,239,20,110,123,64,186,16,91,253,141,103,162,112,53,128,26,96,151,148,200,87,60,42,244,156,175,146,34,106,118,65,116,157,46,155,10,39,167,24,179,76,251,22,107,161,243,133,59,199,218,45,203,164,234,202,
112,79,86,0,231,133,29,223,169,93,204,121,7,207,57,230,185,228,185,230,184,114,30,185,195,141,128,26,29,173,147,114,249,229,7,192,60,242,151,229,20,106,127,81,59,178,249,151,226,75,242,249,129,222,192,
13,48,86,169,176,98,122,113,154,100,96,135,251,151,220,144,227,125,9,210,5,126,240,179,127,212,203,90,58,215,110,207,63,228,179,200,203,29,59,189,124,229,47,234,224,106,118,20,53,136,244,216,68,81,91,
181,237,156,103,89,78,115,153,240,206,103,220,190,35,222,89,196,236,101,191,230,89,196,150,113,38,189,222,70,175,166,146,135,56,219,145,130,78,125,34,221,50,216,126,103,239,238,115,190,9,206,248,39,59,
224,157,39,207,41,126,95,51,152,157,31,50,251,130,91,120,125,78,143,153,209,243,58,62,103,71,204,232,249,157,31,51,163,230,116,124,206,143,153,204,74,16,115,190,185,207,53,79,53,79,37,79,53,79,37,36,167,
23,204,231,125,202,243,248,157,31,51,164,121,231,21,117,127,131,191,255,218,0,8,1,2,3,1,63,16,252,35,158,88,106,246,153,191,3,92,25,172,114,97,220,36,27,142,199,57,64,139,3,182,102,224,235,142,142,26,
119,12,209,195,71,99,117,112,213,135,105,206,5,97,171,23,56,68,184,61,195,6,37,193,189,139,90,33,145,20,59,76,10,150,18,224,47,97,154,196,168,119,12,27,142,78,197,234,225,171,216,188,46,224,84,101,118,
244,112,209,238,76,156,13,137,90,32,84,116,134,55,51,112,5,96,235,220,153,68,185,167,112,193,178,57,59,19,171,134,168,75,153,176,3,11,37,37,176,59,148,184,49,46,105,219,97,147,129,176,235,80,211,7,92,
53,129,88,81,223,37,193,137,115,51,180,198,25,145,201,216,119,92,82,240,5,97,126,0,151,6,107,41,37,225,120,186,96,115,33,177,133,168,102,248,20,185,124,112,161,193,153,47,19,92,52,118,25,201,236,92,205,
148,120,74,73,108,179,4,25,73,45,192,210,57,144,211,97,82,224,203,38,108,170,241,53,47,4,174,195,71,97,147,13,30,47,88,96,229,52,193,44,131,102,195,83,15,24,246,141,29,163,116,134,152,153,56,58,65,179,
104,204,19,3,76,52,118,164,116,131,123,32,178,151,5,76,229,247,172,27,237,104,236,122,192,174,213,84,185,108,190,235,73,99,217,75,131,123,32,90,153,178,165,50,210,82,89,141,76,229,157,197,18,146,15,99,
71,99,92,78,184,212,169,82,165,75,76,22,97,68,166,93,107,219,123,14,112,216,221,28,29,123,138,149,42,102,96,187,154,195,38,187,78,144,211,11,48,118,53,154,224,59,170,195,72,55,30,211,166,11,128,225,163,
177,166,78,6,76,59,205,38,179,50,13,246,53,98,212,11,193,32,196,184,55,177,137,112,110,36,30,247,76,28,156,86,25,71,55,10,193,131,113,201,216,215,44,18,187,214,25,49,150,76,224,69,129,217,209,192,216,
221,48,209,239,82,93,75,37,146,214,7,105,32,199,99,180,154,205,59,218,149,42,87,109,154,56,25,59,29,164,75,154,120,118,17,217,4,185,167,134,99,147,129,147,176,86,119,154,224,151,52,240,206,7,96,93,112,
27,239,53,193,46,105,225,89,163,129,176,26,176,210,13,247,137,112,137,112,124,43,13,38,142,192,104,134,108,164,164,130,247,137,112,98,65,240,140,53,142,155,2,100,226,144,211,188,102,179,70,30,13,154,56,
27,0,144,204,199,71,189,50,98,101,15,8,195,73,191,96,28,225,147,138,92,204,131,125,219,53,154,48,240,108,209,29,118,5,32,223,99,71,188,50,112,30,20,236,19,147,53,197,46,25,61,219,24,120,86,141,130,214,
25,61,135,94,237,210,26,77,240,240,78,7,96,210,224,214,46,189,225,29,97,224,157,33,164,117,216,68,184,53,137,167,118,107,128,240,78,27,246,21,215,19,78,236,142,100,28,47,192,25,184,26,108,42,95,124,26,
224,147,50,92,185,100,185,125,219,2,136,236,163,147,53,236,84,163,6,100,185,120,92,185,114,240,185,112,43,3,61,148,75,150,148,202,149,42,103,46,107,133,24,41,148,202,101,56,41,43,7,61,157,162,103,45,151,
44,150,75,37,146,229,178,217,155,2,191,226,155,37,142,211,49,155,45,52,217,165,168,174,22,224,164,178,89,44,150,96,205,128,98,151,6,165,146,201,73,99,178,43,120,83,51,196,168,134,53,42,86,1,125,161,217,
29,144,169,76,166,83,41,153,246,115,237,148,148,192,183,142,114,152,21,179,244,74,37,18,137,68,162,81,252,39,255,218,0,8,1,3,3,1,63,16,252,48,69,174,206,136,235,218,24,230,118,198,162,94,201,153,17,207,
178,100,71,182,49,59,106,38,200,132,93,144,139,220,141,196,174,222,164,118,64,236,132,94,232,102,167,108,106,38,199,154,227,78,12,136,189,224,196,190,216,217,19,99,140,110,95,126,49,47,180,53,29,142,37,
197,240,67,18,251,70,145,54,136,102,76,71,178,118,142,229,202,28,20,192,168,233,180,214,203,218,187,127,225,231,255,0,144,117,42,83,43,105,140,162,214,10,76,153,70,10,118,132,237,91,45,193,147,42,86,207,
153,157,205,184,50,98,108,232,193,221,141,196,238,66,240,77,146,27,137,93,216,220,78,216,77,37,176,110,38,200,140,212,154,119,102,100,78,214,132,91,196,110,38,200,141,68,190,239,73,147,19,16,153,17,111,
176,53,28,205,146,24,151,222,178,153,29,193,68,217,33,137,126,27,83,100,198,37,248,85,29,147,24,158,23,83,101,6,39,133,59,40,49,43,194,58,108,174,167,132,52,142,202,12,30,16,236,169,153,224,200,233,178,
163,7,131,221,178,218,158,12,211,3,101,8,248,35,77,150,38,175,4,100,108,177,52,120,39,77,151,212,240,38,177,217,87,1,137,114,210,158,248,40,142,204,92,185,114,201,67,130,158,228,42,46,207,91,46,88,202,
37,37,37,37,37,18,194,46,209,220,185,114,255,0,249,133,79,113,76,169,91,59,120,223,111,57,79,252,13,255,217,0,0};

const char* TabMasterFilter::basszero_background_jpg = (const char*) resource_TabMasterFilter_basszero_background_jpg;
const int TabMasterFilter::basszero_background_jpgSize = 10853;


//[EndFile] You can add extra defines here...
//[/EndFile]

