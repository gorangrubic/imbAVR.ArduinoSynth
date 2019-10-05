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

#include "ModulationParamLink.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ModulationParamLink::ModulationParamLink ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    target_signal.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (target_signal.get());
    target_signal->setEditableText (false);
    target_signal->setJustificationType (Justification::centredLeft);
    target_signal->setTextWhenNothingSelected (String());
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

    label->setBounds (24, 44, 50, 18);

    target_mod.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (target_mod.get());
    target_mod->setEditableText (false);
    target_mod->setJustificationType (Justification::centredLeft);
    target_mod->setTextWhenNothingSelected (String());
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

    label2->setBounds (24, 66, 50, 18);

    target_parameter.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (target_parameter.get());
    target_parameter->setEditableText (false);
    target_parameter->setJustificationType (Justification::centredLeft);
    target_parameter->setTextWhenNothingSelected (String());
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

    label3->setBounds (24, 88, 50, 18);

    Amount.reset (new Slider ("new slider"));
    addAndMakeVisible (Amount.get());
    Amount->setRange (-100, 100, 1);
    Amount->setSliderStyle (Slider::LinearVertical);
    Amount->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Amount->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ModulationParamLink::~ModulationParamLink()
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
void ModulationParamLink::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ModulationParamLink::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    target_signal->setBounds (80, 44, getWidth() - 90, 18);
    target_mod->setBounds (80, 66, getWidth() - 90, 18);
    target_parameter->setBounds (80, 88, getWidth() - 90, 18);
    Amount->setBounds ((getWidth() / 2) + 112 - (24 / 2), (getHeight() / 2) + 60 - (68 / 2), 24, 68);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ModulationParamLink::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
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

void ModulationParamLink::sliderValueChanged (Slider* sliderThatWasMoved)
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

<JUCER_COMPONENT documentType="Component" className="ModulationParamLink" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <COMBOBOX name="new combo box" id="60018ead4932c973" memberName="target_signal"
            virtualName="" explicitFocusOrder="0" pos="80 44 90M 18" editable="0"
            layout="33" items="OFF&#10;WF A&#10;WF B&#10;FLT&#10;PERK A&#10;PERK B&#10;WF A&amp;B&#10;PERK A&amp;B&#10;ALL"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="9b71a4e403b102da" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="24 44 50 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Signal&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="942c20cfc5b81345" memberName="target_mod"
            virtualName="" explicitFocusOrder="0" pos="80 66 90M 18" editable="0"
            layout="33" items="PWM&#10;Phase&#10;Pitch" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="b42596e7e04c788f" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="24 66 50 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Mod" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="23f7e662b20a6100" memberName="target_parameter"
            virtualName="" explicitFocusOrder="0" pos="80 88 90M 18" editable="0"
            layout="33" items="Rate&#10;Change&#10;Period" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="dc39eb3bd19673df" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="24 88 50 18" edTextCol="ff000000"
         edBkgCol="0" labelText="Param." editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="15c7b68c42f32b6" memberName="Amount" virtualName=""
          explicitFocusOrder="0" pos="112Cc 60Cc 24 68" min="-100.0" max="100.0"
          int="1.0" style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

