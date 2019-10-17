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

#include "ENVEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ENVEditor::ENVEditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    toggle_startWithB.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggle_startWithB.get());
    toggle_startWithB->setButtonText (TRANS("Start with B"));
    toggle_startWithB->addListener (this);
    toggle_startWithB->setToggleState (true, dontSendNotification);

    toggle_startWithB->setBounds (34, 49, 96, 16);

    toggle_loop.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggle_loop.get());
    toggle_loop->setButtonText (TRANS("Loop"));
    toggle_loop->addListener (this);
    toggle_loop->setToggleState (true, dontSendNotification);

    toggle_loop->setBounds (149, 49, 96, 16);

    label2.reset (new Label ("new label",
                             TRANS("Time A")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (32, 1, 64, 16);

    label3.reset (new Label ("new label",
                             TRANS("Value A")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (32, 26, 64, 16);

    TimeA.reset (new Slider ("new slider"));
    addAndMakeVisible (TimeA.get());
    TimeA->setRange (1, 127, 1);
    TimeA->setSliderStyle (Slider::LinearHorizontal);
    TimeA->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    TimeA->setColour (Slider::thumbColourId, Colours::cadetblue);
    TimeA->addListener (this);

    TimeA->setBounds (75, -3, 76, 24);

    ValueA.reset (new Slider ("new slider"));
    addAndMakeVisible (ValueA.get());
    ValueA->setRange (0, 127, 1);
    ValueA->setSliderStyle (Slider::LinearHorizontal);
    ValueA->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ValueA->setColour (Slider::thumbColourId, Colours::cadetblue);
    ValueA->addListener (this);

    ValueA->setBounds (75, 22, 76, 24);

    label5.reset (new Label ("new label",
                             TRANS("Time B")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (147, 1, 64, 16);

    label6.reset (new Label ("new label",
                             TRANS("Value B")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (147, 26, 64, 16);

    TimeB.reset (new Slider ("new slider"));
    addAndMakeVisible (TimeB.get());
    TimeB->setRange (1, 127, 1);
    TimeB->setSliderStyle (Slider::LinearHorizontal);
    TimeB->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    TimeB->setColour (Slider::thumbColourId, Colours::cadetblue);
    TimeB->addListener (this);

    TimeB->setBounds (192, -3, 76, 24);

    ValueB.reset (new Slider ("new slider"));
    addAndMakeVisible (ValueB.get());
    ValueB->setRange (1, 127, 1);
    ValueB->setSliderStyle (Slider::LinearHorizontal);
    ValueB->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    ValueB->setColour (Slider::thumbColourId, Colours::cadetblue);
    ValueB->addListener (this);

    ValueB->setBounds (192, 22, 76, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	modelComponent = synthState->model->modulations.GetENVByName(nameSufix);
	modelComponent->Loop.attachControl(toggle_loop.get());
	modelComponent->StartWithB.attachControl(toggle_startWithB.get());
	modelComponent->TimeA.attachControl(TimeA.get());
	modelComponent->TimeB.attachControl(TimeB.get());
	modelComponent->ValueA.attachControl(ValueA.get());
	modelComponent->ValueB.attachControl(ValueB.get());
    //[/Constructor]
}

ENVEditor::~ENVEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    toggle_startWithB = nullptr;
    toggle_loop = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    TimeA = nullptr;
    ValueA = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    TimeB = nullptr;
    ValueB = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ENVEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x50323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ENVEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ENVEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggle_startWithB.get())
    {
        //[UserButtonCode_toggle_startWithB] -- add your button handler code here..
        //[/UserButtonCode_toggle_startWithB]
    }
    else if (buttonThatWasClicked == toggle_loop.get())
    {
        //[UserButtonCode_toggle_loop] -- add your button handler code here..
        //[/UserButtonCode_toggle_loop]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ENVEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == TimeA.get())
    {
        //[UserSliderCode_TimeA] -- add your slider handling code here..
        //[/UserSliderCode_TimeA]
    }
    else if (sliderThatWasMoved == ValueA.get())
    {
        //[UserSliderCode_ValueA] -- add your slider handling code here..
        //[/UserSliderCode_ValueA]
    }
    else if (sliderThatWasMoved == TimeB.get())
    {
        //[UserSliderCode_TimeB] -- add your slider handling code here..
        //[/UserSliderCode_TimeB]
    }
    else if (sliderThatWasMoved == ValueB.get())
    {
        //[UserSliderCode_ValueB] -- add your slider handling code here..
        //[/UserSliderCode_ValueB]
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

<JUCER_COMPONENT documentType="Component" className="ENVEditor" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="50323e44"/>
  <TOGGLEBUTTON name="new toggle button" id="2cfe8a56cb12fe68" memberName="toggle_startWithB"
                virtualName="" explicitFocusOrder="0" pos="34 49 96 16" buttonText="Start with B"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="eb3f284f0415ad84" memberName="toggle_loop"
                virtualName="" explicitFocusOrder="0" pos="149 49 96 16" buttonText="Loop"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <LABEL name="new label" id="d2451e9917b20736" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="32 1 64 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Time A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="dba5cb32749b8242" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="32 26 64 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Value A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="6ca730a9abe41a69" memberName="TimeA" virtualName=""
          explicitFocusOrder="0" pos="75 -3 76 24" thumbcol="ff5f9ea0"
          min="1.0" max="127.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="f3df82c31fff81d2" memberName="ValueA" virtualName=""
          explicitFocusOrder="0" pos="75 22 76 24" thumbcol="ff5f9ea0"
          min="0.0" max="127.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="56be2193c0007234" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="147 1 64 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Time B" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="bbe3dd328a86b120" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="147 26 64 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Value B" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="fb709a93f4a268fd" memberName="TimeB" virtualName=""
          explicitFocusOrder="0" pos="192 -3 76 24" thumbcol="ff5f9ea0"
          min="1.0" max="127.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="c49f667b41db0eeb" memberName="ValueB" virtualName=""
          explicitFocusOrder="0" pos="192 22 76 24" thumbcol="ff5f9ea0"
          min="1.0" max="127.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

