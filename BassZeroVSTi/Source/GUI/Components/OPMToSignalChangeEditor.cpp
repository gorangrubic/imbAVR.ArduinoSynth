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

#include "OPMToSignalChangeEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OPMToSignalChangeEditor::OPMToSignalChangeEditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    Amount.reset (new Slider ("new slider"));
    addAndMakeVisible (Amount.get());
    Amount->setRange (-100, 100, 1);
    Amount->setSliderStyle (Slider::LinearVertical);
    Amount->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Amount->addListener (this);

    Amount->setBounds (2, 0, 24, 76);

    label_signal.reset (new Label ("new label",
                                   TRANS("target")));
    addAndMakeVisible (label_signal.get());
    label_signal->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_signal->setJustificationType (Justification::centredLeft);
    label_signal->setEditable (false, false, false);
    label_signal->setColour (Label::backgroundColourId, Colour (0x25397daa));
    label_signal->setColour (TextEditor::textColourId, Colours::black);
    label_signal->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_signal2.reset (new Label ("new label",
                                    TRANS("change\n")));
    addAndMakeVisible (label_signal2.get());
    label_signal2->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_signal2->setJustificationType (Justification::centredLeft);
    label_signal2->setEditable (false, false, false);
    label_signal2->setColour (Label::backgroundColourId, Colour (0x25397daa));
    label_signal2->setColour (TextEditor::textColourId, Colours::black);
    label_signal2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_signal3.reset (new Label ("new label",
                                    TRANS("parameter")));
    addAndMakeVisible (label_signal3.get());
    label_signal3->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    label_signal3->setJustificationType (Justification::centredLeft);
    label_signal3->setEditable (false, false, false);
    label_signal3->setColour (Label::backgroundColourId, Colour (0x25397daa));
    label_signal3->setColour (TextEditor::textColourId, Colours::black);
    label_signal3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (120, 72);


    //[Constructor] You can add your own custom stuff here..
	modelComponent = synthState->model->opmControl.GetLink(nameSufix);
	if (modelComponent != nullptr) {


		modelComponent->Signal.attachControl(target_signal.get());
		modelComponent->ModAmt.attachControl(Amount.get());
		modelComponent->ModPar.attachControl(target_parameter.get());
		modelComponent->ModTar.attachControl(target_mod.get());

		setEnabled(true);
		setAlpha(1.0f);
	}
	else {
		setEnabled(false);
		setAlpha(0.5f);
	}


		//ModPar.attachControl(target_parameter.get());
    //[/Constructor]
}

OPMToSignalChangeEditor::~OPMToSignalChangeEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    Amount = nullptr;
    label_signal = nullptr;
    label_signal2 = nullptr;
    label_signal3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OPMToSignalChangeEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x25323e44));

    {
        int x = 0, y = 37, width = 18, height = 2;
        Colour fillColour = Colour (0x25f0ffff);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = -1, y = 6, width = 12, height = 12;
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
        int x = -2, y = 54, width = 12, height = 12;
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

void OPMToSignalChangeEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label_signal->setBounds (24, 8, getWidth() - 28, 16);
    label_signal2->setBounds (24, 28, getWidth() - 28, 16);
    label_signal3->setBounds (24, 48, getWidth() - 28, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OPMToSignalChangeEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == Amount.get())
    {
        //[UserSliderCode_Amount] -- add your slider handling code here..
        //[/UserSliderCode_Amount]
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

<JUCER_COMPONENT documentType="Component" className="OPMToSignalChangeEditor"
                 componentName="" parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="0"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="120" initialHeight="72">
  <BACKGROUND backgroundColour="25323e44">
    <RECT pos="0 37 18 2" fill="solid: 25f0ffff" hasStroke="0"/>
    <TEXT pos="-1 6 12 12" fill="solid: fff0ffff" hasStroke="0" text="+"
          fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="-2 54 12 12" fill="solid: fff0ffff" hasStroke="0" text="-"
          fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="15c7b68c42f32b6" memberName="Amount" virtualName=""
          explicitFocusOrder="0" pos="2 0 24 76" min="-100.0" max="100.0"
          int="1.0" style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="27645d4ec54b113" memberName="label_signal"
         virtualName="" explicitFocusOrder="0" pos="24 8 28M 16" bkgCol="25397daa"
         edTextCol="ff000000" edBkgCol="0" labelText="target" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="c83dbdf8b190a1ea" memberName="label_signal2"
         virtualName="" explicitFocusOrder="0" pos="24 28 28M 16" bkgCol="25397daa"
         edTextCol="ff000000" edBkgCol="0" labelText="change&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="9cb7c40e3757348d" memberName="label_signal3"
         virtualName="" explicitFocusOrder="0" pos="24 48 28M 16" bkgCol="25397daa"
         edTextCol="ff000000" edBkgCol="0" labelText="parameter" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

