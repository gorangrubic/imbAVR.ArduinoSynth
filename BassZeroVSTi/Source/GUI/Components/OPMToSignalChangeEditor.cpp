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
#include "../Source/Data/imbSynthStateData.h"
//[/Headers]

#include "OPMToSignalChangeEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OPMToSignalChangeEditor::OPMToSignalChangeEditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    target_signal.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (target_signal.get());
    target_signal->setEditableText (false);
    target_signal->setJustificationType (Justification::centredLeft);
    target_signal->setTextWhenNothingSelected (TRANS("OFF"));
    target_signal->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    target_signal->addItem (TRANS("OFF"), 1);
    target_signal->addItem (TRANS("WF A"), 2);
    target_signal->addItem (TRANS("WF B"), 3);
    target_signal->addItem (TRANS("FLT"), 4);
    target_signal->addItem (TRANS("PERK A"), 5);
    target_signal->addItem (TRANS("PERK B"), 6);
    target_signal->addItem (TRANS("WF A&B"), 7);
    target_signal->addItem (TRANS("PERK A&B"), 8);
    target_signal->addItem (TRANS("ALL"), 9);
    target_signal->addListener (this);

    label.reset (new Label ("new label",
                            TRANS("Signal\n")));
    addAndMakeVisible (label.get());
    label->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (23, 4, 50, 18);

    target_mod.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (target_mod.get());
    target_mod->setEditableText (false);
    target_mod->setJustificationType (Justification::centredLeft);
    target_mod->setTextWhenNothingSelected (TRANS("PWM"));
    target_mod->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    target_mod->addItem (TRANS("PWM"), 1);
    target_mod->addItem (TRANS("Phase"), 2);
    target_mod->addItem (TRANS("Pitch"), 3);
    target_mod->addListener (this);

    label2.reset (new Label ("new label",
                             TRANS("Mod")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (23, 27, 50, 18);

    target_parameter.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (target_parameter.get());
    target_parameter->setEditableText (false);
    target_parameter->setJustificationType (Justification::centredLeft);
    target_parameter->setTextWhenNothingSelected (TRANS("Rate"));
    target_parameter->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    target_parameter->addItem (TRANS("Rate"), 1);
    target_parameter->addItem (TRANS("Change"), 2);
    target_parameter->addItem (TRANS("Period"), 3);
    target_parameter->addListener (this);

    label3.reset (new Label ("new label",
                             TRANS("Param.")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (23, 49, 50, 18);

    Amount.reset (new Slider ("new slider"));
    addAndMakeVisible (Amount.get());
    Amount->setRange (-100, 100, 1);
    Amount->setSliderStyle (Slider::LinearVertical);
    Amount->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Amount->addListener (this);

    Amount->setBounds (2, 0, 24, 76);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (180, 72);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OPMToSignalChangeEditor::~OPMToSignalChangeEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    target_signal = nullptr;
    label = nullptr;
    target_mod = nullptr;
    label2 = nullptr;
    target_parameter = nullptr;
    label3 = nullptr;
    Amount = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OPMToSignalChangeEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

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

    target_signal->setBounds (79, 5, getWidth() - 90, 16);
    target_mod->setBounds (79, 27, getWidth() - 90, 16);
    target_parameter->setBounds (79, 49, getWidth() - 90, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OPMToSignalChangeEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == target_signal.get())
    {
        //[UserComboBoxCode_target_signal] -- add your combo box handling code here..
        //[/UserComboBoxCode_target_signal]
    }
    else if (comboBoxThatHasChanged == target_mod.get())
    {
        //[UserComboBoxCode_target_mod] -- add your combo box handling code here..
        //[/UserComboBoxCode_target_mod]
    }
    else if (comboBoxThatHasChanged == target_parameter.get())
    {
        //[UserComboBoxCode_target_parameter] -- add your combo box handling code here..
        //[/UserComboBoxCode_target_parameter]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
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
                 variableInitialisers="" snapPixels="8" snapActive="0" snapShown="0"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="180" initialHeight="72">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 37 18 2" fill="solid: 25f0ffff" hasStroke="0"/>
    <TEXT pos="-1 6 12 12" fill="solid: fff0ffff" hasStroke="0" text="+"
          fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="-2 54 12 12" fill="solid: fff0ffff" hasStroke="0" text="-"
          fontname="Default font" fontsize="10.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <COMBOBOX name="new combo box" id="60018ead4932c973" memberName="target_signal"
            virtualName="" explicitFocusOrder="0" pos="79 5 90M 16" editable="0"
            layout="33" items="OFF&#10;WF A&#10;WF B&#10;FLT&#10;PERK A&#10;PERK B&#10;WF A&amp;B&#10;PERK A&amp;B&#10;ALL"
            textWhenNonSelected="OFF" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="9b71a4e403b102da" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="23 4 50 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Signal&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="942c20cfc5b81345" memberName="target_mod"
            virtualName="" explicitFocusOrder="0" pos="79 27 90M 16" editable="0"
            layout="33" items="PWM&#10;Phase&#10;Pitch" textWhenNonSelected="PWM"
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="b42596e7e04c788f" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="23 27 50 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Mod" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="23f7e662b20a6100" memberName="target_parameter"
            virtualName="" explicitFocusOrder="0" pos="79 49 90M 16" editable="0"
            layout="33" items="Rate&#10;Change&#10;Period" textWhenNonSelected="Rate"
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="dc39eb3bd19673df" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="23 49 50 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Param." editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="15c7b68c42f32b6" memberName="Amount" virtualName=""
          explicitFocusOrder="0" pos="2 0 24 76" min="-100.0" max="100.0"
          int="1.0" style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

