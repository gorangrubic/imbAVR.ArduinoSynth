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

#include "SignalChangeEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SignalChangeEditor::SignalChangeEditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    Mode.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (Mode.get());
    Mode->setEditableText (false);
    Mode->setJustificationType (Justification::centred);
    Mode->setTextWhenNothingSelected (TRANS("One-Shot"));
    Mode->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Mode->addItem (TRANS("Continual"), 1);
    Mode->addItem (TRANS("One-shot"), 2);
    Mode->addItem (TRANS("Loop"), 3);
    Mode->addItem (TRANS("Mirror"), 4);
    Mode->addListener (this);

    Mode->setBounds (184, 64, 104, 16);

    label.reset (new Label ("new label",
                            TRANS("Mode")));
    addAndMakeVisible (label.get());
    label->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Rate.reset (new Slider ("new slider"));
    addAndMakeVisible (Rate.get());
    Rate->setTooltip (TRANS("Number of clock cycles after which the Change is applied"));
    Rate->setRange (0, 127, 1);
    Rate->setSliderStyle (Slider::LinearHorizontal);
    Rate->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Rate->addListener (this);

    Rate->setBounds (80, 20, 100, 24);

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
    Period->setRange (0, 64, 0);
    Period->setSliderStyle (Slider::LinearHorizontal);
    Period->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Period->addListener (this);

    Period->setBounds (80, 60, 100, 24);

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

    Change->setBounds (176, 20, 120, 24);

    label4.reset (new Label ("new label",
                             TRANS("Change")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    toggle_Enabled.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggle_Enabled.get());
    toggle_Enabled->setTooltip (TRANS("If modulation is activated"));
    toggle_Enabled->setButtonText (TRANS("Enabled"));
    toggle_Enabled->addListener (this);

    toggle_Enabled->setBounds (4, 28, 80, 18);

    toggle_Sync.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggle_Sync.get());
    toggle_Sync->setTooltip (TRANS("Resets modulation function on Note On"));
    toggle_Sync->setButtonText (TRANS("Sync"));
    toggle_Sync->addListener (this);

    toggle_Chaos.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggle_Chaos.get());
    toggle_Chaos->setTooltip (TRANS("Amount of Change is randomly set when new Period starts"));
    toggle_Chaos->setButtonText (TRANS("Chaos"));
    toggle_Chaos->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (290, 86);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SignalChangeEditor::~SignalChangeEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    Mode = nullptr;
    label = nullptr;
    Rate = nullptr;
    label2 = nullptr;
    Period = nullptr;
    label3 = nullptr;
    Change = nullptr;
    label4 = nullptr;
    toggle_Enabled = nullptr;
    toggle_Sync = nullptr;
    toggle_Chaos = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SignalChangeEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x20323e44));

    {
        int x = 273, y = 33, width = 12, height = 12;
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
        int x = 235, y = 23, width = 2, height = 18;
        Colour fillColour = Colour (0x25f0ffff);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 273, y = 33, width = 12, height = 12;
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
        int x = 186, y = 32, width = 12, height = 12;
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

    label->setBounds (184, 64 + -4 - 12, 104, 12);
    label2->setBounds (80 + 0, 20 + 0 - 12, 100, 12);
    label3->setBounds (80 + 0, 60 + 0 - 12, 100, 12);
    label4->setBounds (176 + 0, 20 + 0 - 12, 120, 12);
    toggle_Sync->setBounds (4 + 0, 28 + 18, 80, 18);
    toggle_Chaos->setBounds ((4 + 0) + 0, (28 + 18) + 18, 80, 18);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SignalChangeEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == Mode.get())
    {
        //[UserComboBoxCode_Mode] -- add your combo box handling code here..
        //[/UserComboBoxCode_Mode]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
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

void SignalChangeEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggle_Enabled.get())
    {
        //[UserButtonCode_toggle_Enabled] -- add your button handler code here..
        //[/UserButtonCode_toggle_Enabled]
    }
    else if (buttonThatWasClicked == toggle_Sync.get())
    {
        //[UserButtonCode_toggle_Sync] -- add your button handler code here..
        //[/UserButtonCode_toggle_Sync]
    }
    else if (buttonThatWasClicked == toggle_Chaos.get())
    {
        //[UserButtonCode_toggle_Chaos] -- add your button handler code here..
        //[/UserButtonCode_toggle_Chaos]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="0" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="290" initialHeight="86">
  <BACKGROUND backgroundColour="20323e44">
    <TEXT pos="273 33 12 12" fill="solid: fff0ffff" hasStroke="0" text="+"
          fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <GROUP>
      <RECT pos="235 23 2 18" fill="solid: 25f0ffff" hasStroke="0"/>
      <TEXT pos="273 33 12 12" fill="solid: fff0ffff" hasStroke="0" text="+"
            fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
            italic="0" justification="36"/>
      <TEXT pos="186 32 12 12" fill="solid: fff0ffff" hasStroke="0" text="-"
            fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
            italic="0" justification="36"/>
    </GROUP>
  </BACKGROUND>
  <COMBOBOX name="new combo box" id="948ce70fce7a41be" memberName="Mode"
            virtualName="" explicitFocusOrder="0" pos="184 64 104 16" editable="0"
            layout="36" items="Continual&#10;One-shot&#10;Loop&#10;Mirror"
            textWhenNonSelected="One-Shot" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="9c79db586984951a" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="184 -4r 104 12" posRelativeY="948ce70fce7a41be"
         edTextCol="ff000000" edBkgCol="0" labelText="Mode" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="a4af4153ed7eefd3" memberName="Rate" virtualName=""
          explicitFocusOrder="0" pos="80 20 100 24" tooltip="Number of clock cycles after which the Change is applied"
          min="0.0" max="127.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="3f68c02d60b8de97" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 0r 100 12" posRelativeX="a4af4153ed7eefd3"
         posRelativeY="a4af4153ed7eefd3" edTextCol="ff000000" edBkgCol="0"
         labelText="Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="9bfc93658cb0ac69" memberName="Period" virtualName=""
          explicitFocusOrder="0" pos="80 60 100 24" tooltip="Rate x value = number of clock cycles per modulation function cycle"
          min="0.0" max="64.0" int="0.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="1cc0e884482ee698" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="0 0r 100 12" posRelativeX="9bfc93658cb0ac69"
         posRelativeY="9bfc93658cb0ac69" edTextCol="ff000000" edBkgCol="0"
         labelText="Period" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="b12b34694a501845" memberName="Change" virtualName=""
          explicitFocusOrder="0" pos="176 20 120 24" min="-127.0" max="127.0"
          int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="652c032e7d221a41" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="0 0r 120 12" posRelativeX="b12b34694a501845"
         posRelativeY="b12b34694a501845" edTextCol="ff000000" edBkgCol="0"
         labelText="Change" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="212792f83b14bfef" memberName="toggle_Enabled"
                virtualName="" explicitFocusOrder="0" pos="4 28 80 18" tooltip="If modulation is activated"
                buttonText="Enabled" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="9cd767994aa0d5e2" memberName="toggle_Sync"
                virtualName="" explicitFocusOrder="0" pos="0 0R 80 18" posRelativeX="212792f83b14bfef"
                posRelativeY="212792f83b14bfef" tooltip="Resets modulation function on Note On"
                buttonText="Sync" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="4019a77e2e3cd8f0" memberName="toggle_Chaos"
                virtualName="" explicitFocusOrder="0" pos="0 0R 80 18" posRelativeX="9cd767994aa0d5e2"
                posRelativeY="9cd767994aa0d5e2" tooltip="Amount of Change is randomly set when new Period starts"
                buttonText="Chaos" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

