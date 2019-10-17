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
#include "../Source/GUI/Components/imbSynthGUIComponent.h"
//[/Headers]

#include "OPMMacroControlEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OPMMacroControlEditor::OPMMacroControlEditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    Title2.reset (new Label ("new label",
                             TRANS("MOD B")));
    addAndMakeVisible (Title2.get());
    Title2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title2->setJustificationType (Justification::centred);
    Title2->setEditable (false, false, false);
    Title2->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title2->setColour (Label::textColourId, Colour (0xff181f22));
    Title2->setColour (TextEditor::textColourId, Colours::black);
    Title2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title2->setBounds (96, 24, 96, 16);

    VALA.reset (new Slider ("DirectValue"));
    addAndMakeVisible (VALA.get());
    VALA->setTooltip (TRANS("Decay time\n"));
    VALA->setRange (1, 100, 1);
    VALA->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    VALA->setTextBoxStyle (Slider::NoTextBox, true, 50, 10);
    VALA->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    VALA->addListener (this);

    VALA->setBounds (0, 160, 64, 68);

    Title5.reset (new Label ("new label",
                             TRANS("VAL A")));
    addAndMakeVisible (Title5.get());
    Title5->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title5->setJustificationType (Justification::centred);
    Title5->setEditable (false, false, false);
    Title5->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title5->setColour (Label::textColourId, Colour (0xff181f22));
    Title5->setColour (TextEditor::textColourId, Colours::black);
    Title5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title5->setBounds (0, 144, 64, 16);

    Title6.reset (new Label ("new label",
                             TRANS("MOD A")));
    addAndMakeVisible (Title6.get());
    Title6->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title6->setJustificationType (Justification::centred);
    Title6->setEditable (false, false, false);
    Title6->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title6->setColour (Label::textColourId, Colour (0xff181f22));
    Title6->setColour (TextEditor::textColourId, Colours::black);
    Title6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title6->setBounds (0, 24, 96, 16);

    OPM_MODA.reset (new SourceMixerComponent (synthState, "OPM_MODA"));
    addAndMakeVisible (OPM_MODA.get());
    OPM_MODA->setBounds (0, 40, 96, 96);

    Title14.reset (new Label ("new label",
                              TRANS("PERK B PAN")));
    addAndMakeVisible (Title14.get());
    Title14->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title14->setJustificationType (Justification::centred);
    Title14->setEditable (false, false, false);
    Title14->setColour (Label::backgroundColourId, Colours::azure);
    Title14->setColour (Label::textColourId, Colour (0xff181f22));
    Title14->setColour (TextEditor::textColourId, Colours::black);
    Title14->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title14->setBounds (-194, -170, 96, 16);

    Title15.reset (new Label ("new label",
                              TRANS("PERK A PAN")));
    addAndMakeVisible (Title15.get());
    Title15->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title15->setJustificationType (Justification::centred);
    Title15->setEditable (false, false, false);
    Title15->setColour (Label::backgroundColourId, Colours::azure);
    Title15->setColour (Label::textColourId, Colour (0xff181f22));
    Title15->setColour (TextEditor::textColourId, Colours::black);
    Title15->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title15->setBounds (-290, -170, 96, 16);

    label_OPM6.reset (new Label ("new label",
                                 TRANS("OPM")));
    addAndMakeVisible (label_OPM6.get());
    label_OPM6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_OPM6->setJustificationType (Justification::centred);
    label_OPM6->setEditable (false, false, false);
    label_OPM6->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label_OPM6->setColour (Label::textColourId, Colours::azure);
    label_OPM6->setColour (TextEditor::textColourId, Colours::black);
    label_OPM6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_OPM6->setBounds (0, 0, 192, 24);

    OPM_MODB.reset (new SourceMixerComponent (synthState, "OPM_MODB"));
    addAndMakeVisible (OPM_MODB.get());
    OPM_MODB->setBounds (96, 40, 96, 96);

    VALB.reset (new Slider ("DirectValue"));
    addAndMakeVisible (VALB.get());
    VALB->setTooltip (TRANS("Decay time\n"));
    VALB->setRange (1, 100, 1);
    VALB->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    VALB->setTextBoxStyle (Slider::NoTextBox, true, 50, 10);
    VALB->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    VALB->addListener (this);

    VALB->setBounds (64, 160, 64, 68);

    Title3.reset (new Label ("new label",
                             TRANS("VAL B")));
    addAndMakeVisible (Title3.get());
    Title3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title3->setJustificationType (Justification::centred);
    Title3->setEditable (false, false, false);
    Title3->setColour (Label::backgroundColourId, Colours::azure);
    Title3->setColour (Label::textColourId, Colour (0xff181f22));
    Title3->setColour (TextEditor::textColourId, Colours::black);
    Title3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title3->setBounds (64, 144, 64, 16);

    VALC.reset (new Slider ("DirectValue"));
    addAndMakeVisible (VALC.get());
    VALC->setTooltip (TRANS("Decay time\n"));
    VALC->setRange (1, 100, 1);
    VALC->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    VALC->setTextBoxStyle (Slider::NoTextBox, true, 50, 10);
    VALC->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    VALC->addListener (this);

    VALC->setBounds (128, 160, 64, 68);

    Title4.reset (new Label ("new label",
                             TRANS("VAL C")));
    addAndMakeVisible (Title4.get());
    Title4->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title4->setJustificationType (Justification::centred);
    Title4->setEditable (false, false, false);
    Title4->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title4->setColour (Label::textColourId, Colour (0xff181f22));
    Title4->setColour (TextEditor::textColourId, Colours::black);
    Title4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title4->setBounds (128, 144, 64, 16);

    Title7.reset (new Label ("new label",
                             TRANS("CTRL A")));
    addAndMakeVisible (Title7.get());
    Title7->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title7->setJustificationType (Justification::centred);
    Title7->setEditable (false, false, false);
    Title7->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title7->setColour (Label::textColourId, Colour (0xff181f22));
    Title7->setColour (TextEditor::textColourId, Colours::black);
    Title7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title7->setBounds (0, 256, 64, 16);

    Title8.reset (new Label ("new label",
                             TRANS("CTRL B")));
    addAndMakeVisible (Title8.get());
    Title8->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title8->setJustificationType (Justification::centred);
    Title8->setEditable (false, false, false);
    Title8->setColour (Label::backgroundColourId, Colours::azure);
    Title8->setColour (Label::textColourId, Colour (0xff181f22));
    Title8->setColour (TextEditor::textColourId, Colours::black);
    Title8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title8->setBounds (64, 256, 64, 16);

    Title9.reset (new Label ("new label",
                             TRANS("CTRL C")));
    addAndMakeVisible (Title9.get());
    Title9->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title9->setJustificationType (Justification::centred);
    Title9->setEditable (false, false, false);
    Title9->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title9->setColour (Label::textColourId, Colour (0xff181f22));
    Title9->setColour (TextEditor::textColourId, Colours::black);
    Title9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title9->setBounds (128, 256, 64, 16);

    label_OPM2.reset (new Label ("new label",
                                 TRANS("MACRO CONTROLS")));
    addAndMakeVisible (label_OPM2.get());
    label_OPM2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_OPM2->setJustificationType (Justification::centred);
    label_OPM2->setEditable (false, false, false);
    label_OPM2->setColour (Label::backgroundColourId, Colour (0xff029d4d));
    label_OPM2->setColour (Label::textColourId, Colours::azure);
    label_OPM2->setColour (TextEditor::textColourId, Colours::black);
    label_OPM2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_OPM2->setBounds (0, 232, 192, 24);

    CTRLA.reset (new Slider ("DirectValue"));
    addAndMakeVisible (CTRLA.get());
    CTRLA->setTooltip (TRANS("Decay time\n"));
    CTRLA->setRange (1, 100, 1);
    CTRLA->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    CTRLA->setTextBoxStyle (Slider::NoTextBox, true, 50, 10);
    CTRLA->setColour (Slider::thumbColourId, Colour (0xff029d4d));
    CTRLA->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    CTRLA->addListener (this);

    CTRLA->setBounds (-2, 272, 64, 76);

    CTRLB.reset (new Slider ("DirectValue"));
    addAndMakeVisible (CTRLB.get());
    CTRLB->setTooltip (TRANS("Decay time\n"));
    CTRLB->setRange (1, 100, 1);
    CTRLB->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    CTRLB->setTextBoxStyle (Slider::NoTextBox, true, 50, 10);
    CTRLB->setColour (Slider::thumbColourId, Colour (0xff029d4d));
    CTRLB->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    CTRLB->addListener (this);

    CTRLB->setBounds (62, 272, 64, 76);

    CTRLC.reset (new Slider ("DirectValue"));
    addAndMakeVisible (CTRLC.get());
    CTRLC->setTooltip (TRANS("Decay time\n"));
    CTRLC->setRange (1, 100, 1);
    CTRLC->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    CTRLC->setTextBoxStyle (Slider::NoTextBox, true, 50, 10);
    CTRLC->setColour (Slider::thumbColourId, Colour (0xff029d4d));
    CTRLC->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    CTRLC->addListener (this);

    CTRLC->setBounds (126, 272, 64, 76);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (192, 360);


    //[Constructor] You can add your own custom stuff here..
	synthState->model->opmControl.AttachParameter<Slider>("OPM_VALA", VALA.get());
	synthState->model->opmControl.AttachParameter<Slider>("OPM_VALB", VALB.get());
	synthState->model->opmControl.AttachParameter<Slider>("OPM_VALC", VALC.get());

	synthState->model->modulations.GetMacroByName("CTRL_A")->AttachParameter<Slider>("Value", CTRLA.get());
	synthState->model->modulations.GetMacroByName("CTRL_B")->AttachParameter<Slider>("Value", CTRLB.get());
	synthState->model->modulations.GetMacroByName("CTRL_C")->AttachParameter<Slider>("Value", CTRLC.get());
    //[/Constructor]
}

OPMMacroControlEditor::~OPMMacroControlEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    Title2 = nullptr;
    VALA = nullptr;
    Title5 = nullptr;
    Title6 = nullptr;
    OPM_MODA = nullptr;
    Title14 = nullptr;
    Title15 = nullptr;
    label_OPM6 = nullptr;
    OPM_MODB = nullptr;
    VALB = nullptr;
    Title3 = nullptr;
    VALC = nullptr;
    Title4 = nullptr;
    Title7 = nullptr;
    Title8 = nullptr;
    Title9 = nullptr;
    label_OPM2 = nullptr;
    CTRLA = nullptr;
    CTRLB = nullptr;
    CTRLC = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OPMMacroControlEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OPMMacroControlEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OPMMacroControlEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == VALA.get())
    {
        //[UserSliderCode_VALA] -- add your slider handling code here..
        //[/UserSliderCode_VALA]
    }
    else if (sliderThatWasMoved == VALB.get())
    {
        //[UserSliderCode_VALB] -- add your slider handling code here..
        //[/UserSliderCode_VALB]
    }
    else if (sliderThatWasMoved == VALC.get())
    {
        //[UserSliderCode_VALC] -- add your slider handling code here..
        //[/UserSliderCode_VALC]
    }
    else if (sliderThatWasMoved == CTRLA.get())
    {
        //[UserSliderCode_CTRLA] -- add your slider handling code here..
        //[/UserSliderCode_CTRLA]
    }
    else if (sliderThatWasMoved == CTRLB.get())
    {
        //[UserSliderCode_CTRLB] -- add your slider handling code here..
        //[/UserSliderCode_CTRLB]
    }
    else if (sliderThatWasMoved == CTRLC.get())
    {
        //[UserSliderCode_CTRLC] -- add your slider handling code here..
        //[/UserSliderCode_CTRLC]
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

<JUCER_COMPONENT documentType="Component" className="OPMMacroControlEditor" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="192" initialHeight="360">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="ebca27112e99bb6c" memberName="Title2" virtualName=""
         explicitFocusOrder="0" pos="96 24 96 16" bkgCol="fff0f8ff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="MOD B" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="f29fd8d619498ce" memberName="VALA" virtualName=""
          explicitFocusOrder="0" pos="0 160 64 68" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" textboxoutline="8e989b"
          min="1.0" max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="10" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="b54c3a5594317ad7" memberName="Title5" virtualName=""
         explicitFocusOrder="0" pos="0 144 64 16" bkgCol="fff0f8ff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="VAL A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="a1c56561ddda84d0" memberName="Title6" virtualName=""
         explicitFocusOrder="0" pos="0 24 96 16" bkgCol="fff0f8ff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="MOD A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="OPM_MODA" id="2864d35105104cbd" memberName="OPM_MODA" virtualName=""
             explicitFocusOrder="0" pos="0 40 96 96" sourceFile="SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;OPM_MODA&quot;"/>
  <LABEL name="new label" id="bb977033edf56b53" memberName="Title14" virtualName=""
         explicitFocusOrder="0" pos="-194 -170 96 16" posRelativeX="e0d2854f1680301b"
         posRelativeY="e0d2854f1680301b" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="PERK B PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="17c549a758294aef" memberName="Title15" virtualName=""
         explicitFocusOrder="0" pos="-290 -170 96 16" posRelativeX="e0d2854f1680301b"
         posRelativeY="e0d2854f1680301b" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="PERK A PAN" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="e7468f525dcf4c5b" memberName="label_OPM6"
         virtualName="" explicitFocusOrder="0" pos="0 0 192 24" bkgCol="ff397daa"
         textCol="fff0ffff" edTextCol="ff000000" edBkgCol="0" labelText="OPM"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="1"
         italic="0" justification="36" typefaceStyle="Bold"/>
  <JUCERCOMP name="OPM_MODB" id="1dafcc7e8eda101d" memberName="OPM_MODB" virtualName=""
             explicitFocusOrder="0" pos="96 40 96 96" sourceFile="SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;OPM_MODB&quot;"/>
  <SLIDER name="DirectValue" id="11a6daa6c6f9aa38" memberName="VALB" virtualName=""
          explicitFocusOrder="0" pos="64 160 64 68" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" textboxoutline="8e989b"
          min="1.0" max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="10" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="5199123e3efd7734" memberName="Title3" virtualName=""
         explicitFocusOrder="0" pos="64 144 64 16" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="VAL B" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="7bc2a0f57e067caa" memberName="VALC" virtualName=""
          explicitFocusOrder="0" pos="128 160 64 68" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" textboxoutline="8e989b"
          min="1.0" max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="10" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="758209e6b61653a9" memberName="Title4" virtualName=""
         explicitFocusOrder="0" pos="128 144 64 16" bkgCol="fff0f8ff"
         textCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="VAL C"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="ae01c406088243b8" memberName="Title7" virtualName=""
         explicitFocusOrder="0" pos="0 256 64 16" bkgCol="fff0f8ff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="CTRL A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="c3b9f4223b175a28" memberName="Title8" virtualName=""
         explicitFocusOrder="0" pos="64 256 64 16" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="CTRL B" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="6742b72bce6da06a" memberName="Title9" virtualName=""
         explicitFocusOrder="0" pos="128 256 64 16" bkgCol="fff0f8ff"
         textCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="CTRL C"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="cd567f72be297e32" memberName="label_OPM2"
         virtualName="" explicitFocusOrder="0" pos="0 232 192 24" bkgCol="ff029d4d"
         textCol="fff0ffff" edTextCol="ff000000" edBkgCol="0" labelText="MACRO CONTROLS"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="1"
         italic="0" justification="36" typefaceStyle="Bold"/>
  <SLIDER name="DirectValue" id="88dc11d212aae427" memberName="CTRLA" virtualName=""
          explicitFocusOrder="0" pos="-2 272 64 76" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" thumbcol="ff029d4d"
          textboxoutline="8e989b" min="1.0" max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="10" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="DirectValue" id="f4693b0c161482f7" memberName="CTRLB" virtualName=""
          explicitFocusOrder="0" pos="62 272 64 76" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" thumbcol="ff029d4d"
          textboxoutline="8e989b" min="1.0" max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="10" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="DirectValue" id="bdac24d826f2a4e0" memberName="CTRLC" virtualName=""
          explicitFocusOrder="0" pos="126 272 64 76" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" thumbcol="ff029d4d"
          textboxoutline="8e989b" min="1.0" max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="10" skewFactor="1.0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

