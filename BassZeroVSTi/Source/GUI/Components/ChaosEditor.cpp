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

#include "ChaosEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ChaosEditor::ChaosEditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    Value.reset (new Slider ("DirectValue"));
    addAndMakeVisible (Value.get());
    Value->setTooltip (TRANS("Decay time\n"));
    Value->setRange (1, 127, 1);
    Value->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    Value->setTextBoxStyle (Slider::TextBoxBelow, true, 50, 10);
    Value->setColour (Slider::thumbColourId, Colour (0xffed6216));
    Value->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Value->addListener (this);

    label2.reset (new Label ("new label",
                             TRANS("Value")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0x005f9ea0));
    label2->setColour (Label::textColourId, Colours::azure);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (24, 4, 62, 16);

    Curve.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (Curve.get());
    Curve->setEditableText (false);
    Curve->setJustificationType (Justification::centredLeft);
    Curve->setTextWhenNothingSelected (TRANS("Triangle"));
    Curve->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Curve->addItem (TRANS("Triangle"), 1);
    Curve->addItem (TRANS("Ramp Down"), 2);
    Curve->addItem (TRANS("Ramp Up"), 3);
    Curve->addItem (TRANS("Square Pulse"), 4);
    Curve->addItem (TRANS("Sinewave"), 5);
    Curve->addItem (TRANS("Chaos"), 6);
    Curve->addListener (this);

    Curve->setBounds (88, 81, 148, 16);

    toggle_retrigger.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggle_retrigger.get());
    toggle_retrigger->setButtonText (TRANS("Re-trig."));
    toggle_retrigger->addListener (this);
    toggle_retrigger->setToggleState (true, dontSendNotification);

    toggle_retrigger->setBounds (160, 56, 63, 16);

    toggle_loop.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggle_loop.get());
    toggle_loop->setButtonText (TRANS("Loop"));
    toggle_loop->addListener (this);
    toggle_loop->setToggleState (true, dontSendNotification);

    toggle_loop->setBounds (88, 56, 63, 16);

    label3.reset (new Label ("new label",
                             TRANS("Time")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (88, 4, 80, 16);

    label5.reset (new Label ("new label",
                             TRANS("Factor")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (160, 4, 80, 16);

    Time.reset (new Slider ("new slider"));
    addAndMakeVisible (Time.get());
    Time->setRange (0, 127, 1);
    Time->setSliderStyle (Slider::LinearHorizontal);
    Time->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    Time->setColour (Slider::thumbColourId, Colour (0xff397daa));
    Time->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Time->addListener (this);

    Time->setBounds (88, 24, 80, 26);

    Factor.reset (new Slider ("new slider"));
    addAndMakeVisible (Factor.get());
    Factor->setRange (0, 127, 1);
    Factor->setSliderStyle (Slider::LinearHorizontal);
    Factor->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    Factor->setColour (Slider::thumbColourId, Colour (0xff397daa));
    Factor->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Factor->addListener (this);

    Factor->setBounds (160, 24, 80, 26);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ChaosEditor::~ChaosEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    Value = nullptr;
    label2 = nullptr;
    Curve = nullptr;
    toggle_retrigger = nullptr;
    toggle_loop = nullptr;
    label3 = nullptr;
    label5 = nullptr;
    Time = nullptr;
    Factor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ChaosEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x50323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ChaosEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    Value->setBounds (86 - 62, 16, 62, 78);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ChaosEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == Value.get())
    {
        //[UserSliderCode_Value] -- add your slider handling code here..
        //[/UserSliderCode_Value]
    }
    else if (sliderThatWasMoved == Time.get())
    {
        //[UserSliderCode_Time] -- add your slider handling code here..
        //[/UserSliderCode_Time]
    }
    else if (sliderThatWasMoved == Factor.get())
    {
        //[UserSliderCode_Factor] -- add your slider handling code here..
        //[/UserSliderCode_Factor]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void ChaosEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == Curve.get())
    {
        //[UserComboBoxCode_Curve] -- add your combo box handling code here..
        //[/UserComboBoxCode_Curve]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void ChaosEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggle_retrigger.get())
    {
        //[UserButtonCode_toggle_retrigger] -- add your button handler code here..
        //[/UserButtonCode_toggle_retrigger]
    }
    else if (buttonThatWasClicked == toggle_loop.get())
    {
        //[UserButtonCode_toggle_loop] -- add your button handler code here..
        //[/UserButtonCode_toggle_loop]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ChaosEditor::ConstructParameterLayout(std::vector<std::unique_ptr<AudioParameterInt>> params)
{
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ChaosEditor" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="50323e44"/>
  <SLIDER name="DirectValue" id="9258fb4fcb5b6574" memberName="Value" virtualName=""
          explicitFocusOrder="0" pos="86r 16 62 78" tooltip="Decay time&#10;"
          thumbcol="ffed6216" textboxoutline="8e989b" min="1.0" max="127.0"
          int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="50" textBoxHeight="10" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="c3a45ba72ca00580" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="24 4 62 16" bkgCol="5f9ea0" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Value" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="new combo box" id="62baf5ef154366df" memberName="Curve"
            virtualName="" explicitFocusOrder="0" pos="88 81 148 16" editable="0"
            layout="33" items="Triangle&#10;Ramp Down&#10;Ramp Up&#10;Square Pulse&#10;Sinewave&#10;Chaos"
            textWhenNonSelected="Triangle" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="new toggle button" id="2cfe8a56cb12fe68" memberName="toggle_retrigger"
                virtualName="" explicitFocusOrder="0" pos="160 56 63 16" buttonText="Re-trig."
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="eb3f284f0415ad84" memberName="toggle_loop"
                virtualName="" explicitFocusOrder="0" pos="88 56 63 16" buttonText="Loop"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <LABEL name="new label" id="f9922551998c59e2" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="88 4 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="37e4a23ecadc0cc9" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="160 4 80 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Factor" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="da120fb852e0c0e8" memberName="Time" virtualName=""
          explicitFocusOrder="0" pos="88 24 80 26" thumbcol="ff397daa"
          textboxoutline="8e989b" min="0.0" max="127.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="new slider" id="c401572f19b035c5" memberName="Factor" virtualName=""
          explicitFocusOrder="0" pos="160 24 80 26" thumbcol="ff397daa"
          textboxoutline="8e989b" min="0.0" max="127.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

