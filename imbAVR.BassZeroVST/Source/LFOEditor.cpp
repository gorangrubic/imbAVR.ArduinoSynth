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

#include "LFOEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
LFOEditor::LFOEditor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    TimeA.reset (new Slider ("DirectValue"));
    addAndMakeVisible (TimeA.get());
    TimeA->setTooltip (TRANS("Attack time"));
    TimeA->setRange (1, 127, 1);
    TimeA->setSliderStyle (Slider::RotaryHorizontalDrag);
    TimeA->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    TimeA->addListener (this);

    TimeA->setBounds (67, 26, 64, 64);

    label.reset (new Label ("new label",
                            TRANS("Time\n")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (67, 2, 64, 24);

    LevelA.reset (new Slider ("DirectValue"));
    addAndMakeVisible (LevelA.get());
    LevelA->setTooltip (TRANS("Decay time\n"));
    LevelA->setRange (1, 127, 1);
    LevelA->setSliderStyle (Slider::RotaryHorizontalDrag);
    LevelA->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    LevelA->setColour (Slider::thumbColourId, Colours::crimson);
    LevelA->addListener (this);

    LevelA->setBounds (131, 26, 64, 64);

    label2.reset (new Label ("new label",
                             TRANS("Value")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (131, 2, 64, 24);

    TimeB.reset (new Slider ("DirectValue"));
    addAndMakeVisible (TimeB.get());
    TimeB->setTooltip (TRANS("Release time"));
    TimeB->setRange (1, 127, 1);
    TimeB->setSliderStyle (Slider::RotaryHorizontalDrag);
    TimeB->setTextBoxStyle (Slider::NoTextBox, true, 50, 20);
    TimeB->addListener (this);

    TimeB->setBounds (195, 26, 64, 64);

    label3.reset (new Label ("new label",
                             TRANS("Time Factor\n")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (195, 2, 64, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

LFOEditor::~LFOEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    TimeA = nullptr;
    label = nullptr;
    LevelA = nullptr;
    label2 = nullptr;
    TimeB = nullptr;
    label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void LFOEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LFOEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void LFOEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == TimeA.get())
    {
        //[UserSliderCode_TimeA] -- add your slider handling code here..
        //[/UserSliderCode_TimeA]
    }
    else if (sliderThatWasMoved == LevelA.get())
    {
        //[UserSliderCode_LevelA] -- add your slider handling code here..
        //[/UserSliderCode_LevelA]
    }
    else if (sliderThatWasMoved == TimeB.get())
    {
        //[UserSliderCode_TimeB] -- add your slider handling code here..
        //[/UserSliderCode_TimeB]
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

<JUCER_COMPONENT documentType="Component" className="LFOEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="323e44"/>
  <SLIDER name="DirectValue" id="df72ef78504c47be" memberName="TimeA" virtualName=""
          explicitFocusOrder="0" pos="67 26 64 64" tooltip="Attack time"
          min="1.0" max="127.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="eb7f31cedb99e07" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="67 2 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="9258fb4fcb5b6574" memberName="LevelA"
          virtualName="" explicitFocusOrder="0" pos="131 26 64 64" tooltip="Decay time&#10;"
          thumbcol="ffdc143c" min="1.0" max="127.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="c3a45ba72ca00580" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="131 2 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Value" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="51fa9e9f52a3fc5d" memberName="TimeB" virtualName=""
          explicitFocusOrder="0" pos="195 26 64 64" tooltip="Release time"
          min="1.0" max="127.0" int="1.0" style="RotaryHorizontalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="c8bdcf903882f097" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="195 2 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time Factor&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

