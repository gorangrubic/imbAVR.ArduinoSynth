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
SourceMixerComponent::SourceMixerComponent (String title)
{
    //[Constructor_pre] You can add your own custom stuff here..
    _title = title;

    //[/Constructor_pre]

    ModAmt.reset (new Slider ("Modulation amount"));
    addAndMakeVisible (ModAmt.get());
    ModAmt->setTooltip (TRANS("Source of modulation"));
    ModAmt->setRange (-127, 127, 1);
    ModAmt->setSliderStyle (Slider::LinearVertical);
    ModAmt->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    ModAmt->setColour (Slider::thumbColourId, Colours::blueviolet);
    ModAmt->addListener (this);

    ModAmt->setBounds (72, 0, 24, 86);

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

    ModSrc->setBounds (0, 88, 96, 21);

    Val.reset (new Slider ("DirectValue"));
    addAndMakeVisible (Val.get());
    Val->setTooltip (TRANS("Source of modulation"));
    Val->setRange (1, 127, 1);
    Val->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    Val->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    Val->setColour (Slider::thumbColourId, Colour (0xffea0001));
    Val->addListener (this);

    Val->setBounds (8, 16, 64, 64);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (96, 112);


    //[Constructor] You can add your own custom stuff here..
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

void SourceMixerComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
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

<JUCER_COMPONENT documentType="Component" className="SourceMixerComponent" componentName=""
                 parentClasses="public Component" constructorParams="String title"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="96" initialHeight="112">
  <BACKGROUND backgroundColour="323e44"/>
  <SLIDER name="Modulation amount" id="ac75912c33562c58" memberName="ModAmt"
          virtualName="" explicitFocusOrder="0" pos="72 0 24 86" tooltip="Source of modulation"
          thumbcol="ff8a2be2" min="-127.0" max="127.0" int="1.0" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="new combo box" id="e50909c7df52b24f" memberName="ModSrc"
            virtualName="" explicitFocusOrder="0" pos="0 88 96 21" editable="0"
            layout="33" items="OFF&#10;ADSR A&#10;ADSR B&#10;CHAOS&#10;ENV A&#10;ENV B&#10;LFO A&#10;LFO B&#10;VEL"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="DirectValue" id="df72ef78504c47be" memberName="Val" virtualName=""
          explicitFocusOrder="0" pos="8 16 64 64" tooltip="Source of modulation"
          thumbcol="ffea0001" min="1.0" max="127.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

