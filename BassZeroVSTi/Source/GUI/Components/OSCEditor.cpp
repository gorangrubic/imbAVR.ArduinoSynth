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

#include "OSCEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OSCEditor::OSCEditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    Phase.reset (new Slider ("DirectValue"));
    addAndMakeVisible (Phase.get());
    Phase->setTooltip (TRANS("Attack time"));
    Phase->setRange (0, 100, 1);
    Phase->setSliderStyle (Slider::LinearHorizontal);
    Phase->setTextBoxStyle (Slider::TextBoxBelow, true, 50, 12);
    Phase->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Phase->addListener (this);

    Phase->setBounds (0, 88, 96, 24);

    Title6.reset (new Label ("new label",
                             TRANS("PHASE")));
    addAndMakeVisible (Title6.get());
    Title6->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title6->setJustificationType (Justification::centred);
    Title6->setEditable (false, false, false);
    Title6->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title6->setColour (Label::textColourId, Colour (0xff181f22));
    Title6->setColour (TextEditor::textColourId, Colours::black);
    Title6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title6->setBounds (0, 64, 96, 16);

    Pitch.reset (new Slider ("DirectValue"));
    addAndMakeVisible (Pitch.get());
    Pitch->setTooltip (TRANS("Attack time"));
    Pitch->setRange (-12, 12, 1);
    Pitch->setSliderStyle (Slider::LinearHorizontal);
    Pitch->setTextBoxStyle (Slider::TextBoxBelow, false, 50, 12);
    Pitch->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Pitch->addListener (this);

    Pitch->setBounds (0, 19, 96, 36);

    Title7.reset (new Label ("new label",
                             TRANS("PITCH")));
    addAndMakeVisible (Title7.get());
    Title7->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title7->setJustificationType (Justification::centred);
    Title7->setEditable (false, false, false);
    Title7->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title7->setColour (Label::textColourId, Colour (0xff181f22));
    Title7->setColour (TextEditor::textColourId, Colours::black);
    Title7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title7->setBounds (0, 0, 96, 16);


    //[UserPreSize]

    //[/UserPreSize]

    setSize (192, 112);


    //[Constructor] You can add your own custom stuff here..
	modelComponent = synthState->model->components.GetPitchAndPhaseControlByName(nameSufix);

	if (modelComponent != nullptr) {

		modelComponent->Pitch.attachControl(Pitch.get());
		modelComponent->Phase.attachControl(Phase.get());

		setEnabled(true);
		setAlpha(1.0f);
	}
	else {
		setEnabled(false);
		setAlpha(0.5f);
	}

    //[/Constructor]
}

OSCEditor::~OSCEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    Phase = nullptr;
    Title6 = nullptr;
    Pitch = nullptr;
    Title7 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OSCEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OSCEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OSCEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == Phase.get())
    {
        //[UserSliderCode_Phase] -- add your slider handling code here..
        //[/UserSliderCode_Phase]
    }
    else if (sliderThatWasMoved == Pitch.get())
    {
        //[UserSliderCode_Pitch] -- add your slider handling code here..
        //[/UserSliderCode_Pitch]
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

<JUCER_COMPONENT documentType="Component" className="OSCEditor" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="192" initialHeight="112">
  <BACKGROUND backgroundColour="323e44"/>
  <SLIDER name="DirectValue" id="698565b936711330" memberName="Phase" virtualName=""
          explicitFocusOrder="0" pos="0 88 96 24" tooltip="Attack time"
          textboxoutline="8e989b" min="0.0" max="100.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="12" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="5fa84f286e291d78" memberName="Title6" virtualName=""
         explicitFocusOrder="0" pos="0 64 96 16" bkgCol="fff0f8ff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="PHASE" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="372e7c57fbadf318" memberName="Pitch" virtualName=""
          explicitFocusOrder="0" pos="0 19 96 36" tooltip="Attack time"
          textboxoutline="8e989b" min="-12.0" max="12.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="50"
          textBoxHeight="12" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="329c93008ae0234" memberName="Title7" virtualName=""
         explicitFocusOrder="0" pos="0 0 96 16" bkgCol="fff0f8ff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="PITCH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

