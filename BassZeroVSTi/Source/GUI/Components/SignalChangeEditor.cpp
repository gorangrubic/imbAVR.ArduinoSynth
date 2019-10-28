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
#include "../Source/Application/imbSynthStateData.h"
//[/Headers]

#include "SignalChangeEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SignalChangeEditor::SignalChangeEditor (imbSynthStateData * synthState, String nameSufix, String parentName)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    Rate.reset (new Slider ("new slider"));
    addAndMakeVisible (Rate.get());
    Rate->setTooltip (TRANS("Number of clock cycles after which the Change is applied"));
    Rate->setRange (0, 127, 1);
    Rate->setSliderStyle (Slider::LinearHorizontal);
    Rate->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Rate->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Rate->addListener (this);

    Rate->setBounds (8, 62, 100, 24);

    label2.reset (new Label ("new label",
                             TRANS("Rate")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Period.reset (new Slider ("new slider"));
    addAndMakeVisible (Period.get());
    Period->setTooltip (TRANS("Rate x value = number of clock cycles per modulation function cycle"));
    Period->setRange (0, 64, 1);
    Period->setSliderStyle (Slider::LinearHorizontal);
    Period->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Period->setColour (Slider::textBoxHighlightColourId, Colour (0x0042a2c8));
    Period->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Period->addListener (this);

    Period->setBounds (8, 102, 100, 24);

    label3.reset (new Label ("new label",
                             TRANS("Period")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Change.reset (new Slider ("new slider"));
    addAndMakeVisible (Change.get());
    Change->setRange (-127, 127, 1);
    Change->setSliderStyle (Slider::LinearHorizontal);
    Change->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Change->addListener (this);

    Change->setBounds (8, 22, 100, 24);

    label4.reset (new Label ("new label",
                             TRANS("Change")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (110, 130);


    //[Constructor] You can add your own custom stuff here..
	auto signalUnit = synthState->model->opmControl.GetSignalUnit(parentName);

	if (signalUnit != nullptr) {

		modelComponent = signalUnit->GetUnitChange(parentName + "_" + nameSufix);
		if (modelComponent != nullptr) {
			modelComponent->Change.attachControl(Change.get());
			modelComponent->Rate.attachControl(Rate.get());
			modelComponent->Chaos.attachControl(toggle_Chaos.get());
			modelComponent->Enabled.attachControl(toggle_Enabled.get());
			modelComponent->Function.attachControl(Mode.get());
			modelComponent->Period.attachControl(Period.get());
			modelComponent->Sync.attachControl(toggle_Sync.get());
			setEnabled(true);
			setAlpha(1.0f);
		}
		else {
			setEnabled(false);
			setAlpha(0.5f);
		}

	}
	else {
		setEnabled(false);
		setAlpha(0.5f);
	}


    //[/Constructor]
}

SignalChangeEditor::~SignalChangeEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    Rate = nullptr;
    label2 = nullptr;
    Period = nullptr;
    label3 = nullptr;
    Change = nullptr;
    label4 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SignalChangeEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x25181f22));

    {
        int x = 95, y = 35, width = 12, height = 12;
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
        int x = 57, y = 25, width = 2, height = 18;
        Colour fillColour = Colour (0x25f0ffff);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 95, y = 35, width = 12, height = 12;
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
        int x = 8, y = 34, width = 12, height = 12;
        String text (TRANS("-"));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SignalChangeEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label2->setBounds (8 + 0, 62 + 0 - 12, 100, 12);
    label3->setBounds (8 + 0, 102 + 0 - 12, 100, 12);
    label4->setBounds (8 + 0, 22 + -2 - 12, 100, 12);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SignalChangeEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == Rate.get())
    {
        //[UserSliderCode_Rate] -- add your slider handling code here..
        //[/UserSliderCode_Rate]
    }
    else if (sliderThatWasMoved == Period.get())
    {
        //[UserSliderCode_Period] -- add your slider handling code here..
        //[/UserSliderCode_Period]
    }
    else if (sliderThatWasMoved == Change.get())
    {
        //[UserSliderCode_Change] -- add your slider handling code here..
        //[/UserSliderCode_Change]
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

<JUCER_COMPONENT documentType="Component" className="SignalChangeEditor" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix, String parentName"
                 variableInitialisers="" snapPixels="8" snapActive="0" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="110" initialHeight="130">
  <BACKGROUND backgroundColour="25181f22">
    <TEXT pos="95 35 12 12" fill="solid: fff0ffff" hasStroke="0" text="+"
          fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <GROUP>
      <RECT pos="57 25 2 18" fill="solid: 25f0ffff" hasStroke="0"/>
      <TEXT pos="95 35 12 12" fill="solid: fff0ffff" hasStroke="0" text="+"
            fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
            italic="0" justification="36"/>
      <TEXT pos="8 34 12 12" fill="solid: fff0ffff" hasStroke="0" text="-"
            fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
            italic="0" justification="36"/>
    </GROUP>
  </BACKGROUND>
  <SLIDER name="new slider" id="a4af4153ed7eefd3" memberName="Rate" virtualName=""
          explicitFocusOrder="0" pos="8 62 100 24" tooltip="Number of clock cycles after which the Change is applied"
          textboxoutline="8e989b" min="0.0" max="127.0" int="1.0" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="3f68c02d60b8de97" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 0r 100 12" posRelativeX="a4af4153ed7eefd3"
         posRelativeY="a4af4153ed7eefd3" edTextCol="ff000000" edBkgCol="0"
         labelText="Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="9bfc93658cb0ac69" memberName="Period" virtualName=""
          explicitFocusOrder="0" pos="8 102 100 24" tooltip="Rate x value = number of clock cycles per modulation function cycle"
          textboxhighlight="42a2c8" textboxoutline="8e989b" min="0.0" max="64.0"
          int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="1cc0e884482ee698" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="0 0r 100 12" posRelativeX="9bfc93658cb0ac69"
         posRelativeY="9bfc93658cb0ac69" edTextCol="ff000000" edBkgCol="0"
         labelText="Period" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="b12b34694a501845" memberName="Change" virtualName=""
          explicitFocusOrder="0" pos="8 22 100 24" min="-127.0" max="127.0"
          int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="652c032e7d221a41" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="0 -2r 100 12" posRelativeX="b12b34694a501845"
         posRelativeY="b12b34694a501845" edTextCol="ff000000" edBkgCol="0"
         labelText="Change" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

