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

#include "SourceMixerComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SourceMixerComponent::SourceMixerComponent (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
	state = std::shared_ptr<imbSynthStateData>(synthState);
    //[/Constructor_pre]

    ModAmt.reset (new Slider ("Modulation amount"));
    addAndMakeVisible (ModAmt.get());
    ModAmt->setTooltip (TRANS("Source of modulation"));
    ModAmt->setRange (-127, 127, 1);
    ModAmt->setSliderStyle (Slider::LinearVertical);
    ModAmt->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    ModAmt->setColour (Slider::thumbColourId, Colour (0xff397daa));
    ModAmt->setColour (Slider::trackColourId, Colour (0xff1d2427));
    ModAmt->addListener (this);

    ModAmt->setBounds (73, 0, 24, 96);

    ModSrc.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (ModSrc.get());
    ModSrc->setEditableText (false);
    ModSrc->setJustificationType (Justification::centred);
    ModSrc->setTextWhenNothingSelected (TRANS("OFF"));
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

    ModSrc->setBounds (2, 77, 68, 16);

    Val.reset (new Slider ("DirectValue"));
    addAndMakeVisible (Val.get());
    Val->setTooltip (TRANS("Source of modulation"));
    Val->setRange (1, 127, 1);
    Val->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    Val->setTextBoxStyle (Slider::NoTextBox, false, 50, 10);
    Val->setColour (Slider::thumbColourId, Colour (0xffed6216));
    Val->setColour (Slider::trackColourId, Colour (0xfffe9900));
    Val->setColour (Slider::rotarySliderFillColourId, Colour (0xff495358));
    Val->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff646565));
    Val->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Val->addListener (this);

    Val->setBounds (0, 0, 76, 76);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (96, 96);


    //[Constructor] You can add your own custom stuff here..

	modelComponent = synthState->model->components.GetModulatedControlByName(nameSufix);
	if (modelComponent != nullptr) {

		modelComponent->ModAmt.attachControl(ModAmt.get());
		modelComponent->ModSrc.attachControl(ModSrc.get());
		modelComponent->Val.attachControl(Val.get());

		setEnabled(true);
		setAlpha(1.0f);
	}
	else {
		setEnabled(false);
		setAlpha(0.5f);
	}

    //[/Constructor]
}

SourceMixerComponent::~SourceMixerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    ModAmt = nullptr;
    ModSrc = nullptr;
    Val = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SourceMixerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x25181f22));

    {
        int x = 74, y = 48, width = 20, height = 1;
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 70, y = 6, width = 12, height = 12;
        String text (TRANS("+"));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 71, y = 74, width = 12, height = 12;
        String text (TRANS("-"));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SourceMixerComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SourceMixerComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == ModAmt.get())
    {
        //[UserSliderCode_ModAmt] -- add your slider handling code here..
		modelComponent->ModAmt.SetValue(ModAmt->getValue());
		state->SetParameterInFocus(&modelComponent->ModAmt);
        //[/UserSliderCode_ModAmt]
    }
    else if (sliderThatWasMoved == Val.get())
    {
        //[UserSliderCode_Val] -- add your slider handling code here..
		modelComponent->Val.SetValue(Val->getValue());
		//state->controlDisplayModel->SetParameter(&modelComponent->Val);
		state->SetParameterInFocus(&modelComponent->Val);
        //[/UserSliderCode_Val]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SourceMixerComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == ModSrc.get())
    {
        //[UserComboBoxCode_ModSrc] -- add your combo box handling code here..
		modelComponent->ModSrc.SetValue(ModSrc->getSelectedItemIndex());
		state->SetParameterInFocus(&modelComponent->ModSrc);
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

<JUCER_COMPONENT documentType="Component" className="SourceMixerComponent" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="0" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="96" initialHeight="96">
  <BACKGROUND backgroundColour="25181f22">
    <RECT pos="74 48 20 1" fill="solid: fff0ffff" hasStroke="0"/>
    <TEXT pos="70 6 12 12" fill="solid: fff0ffff" hasStroke="0" text="+"
          fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="71 74 12 12" fill="solid: fff0ffff" hasStroke="0" text="-"
          fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="Modulation amount" id="ac75912c33562c58" memberName="ModAmt"
          virtualName="" explicitFocusOrder="0" pos="73 0 24 96" tooltip="Source of modulation"
          thumbcol="ff397daa" trackcol="ff1d2427" min="-127.0" max="127.0"
          int="1.0" style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="50" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="new combo box" id="e50909c7df52b24f" memberName="ModSrc"
            virtualName="" explicitFocusOrder="0" pos="2 77 68 16" editable="0"
            layout="36" items="OFF&#10;ADSR A&#10;ADSR B&#10;CHAOS&#10;ENV A&#10;ENV B&#10;LFO A&#10;LFO B&#10;VEL"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <SLIDER name="DirectValue" id="df72ef78504c47be" memberName="Val" virtualName=""
          explicitFocusOrder="0" pos="0 0 76 76" tooltip="Source of modulation"
          thumbcol="ffed6216" trackcol="fffe9900" rotarysliderfill="ff495358"
          rotaryslideroutline="ff646565" textboxoutline="8e989b" min="1.0"
          max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="50" textBoxHeight="10" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

