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

#include "MainViewTabInOut.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainViewTabInOut::MainViewTabInOut (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    group_Device.reset (new GroupComponent ("new group",
                                            TRANS("MIDI Outputs")));
    addAndMakeVisible (group_Device.get());
    group_Device->setTextLabelPosition (Justification::centred);
    group_Device->setColour (GroupComponent::outlineColourId, Colour (0x008e989b));

    group_Device->setBounds (256, 168, 300, 166);

    label6.reset (new Label (String(),
                             TRANS("BassZero")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    group_MIDI_inputs.reset (new GroupComponent ("new group",
                                                 TRANS("MIDI Inputs")));
    addAndMakeVisible (group_MIDI_inputs.get());
    group_MIDI_inputs->setTextLabelPosition (Justification::centred);
    group_MIDI_inputs->setColour (GroupComponent::outlineColourId, Colour (0x008e989b));

    group_MIDI_inputs->setBounds (264, 8, 300, 153);

    midiIn_1.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (midiIn_1.get());
    midiIn_1->setEditableText (false);
    midiIn_1->setJustificationType (Justification::centredLeft);
    midiIn_1->setTextWhenNothingSelected (String());
    midiIn_1->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midiIn_1->addListener (this);

    midiIn_2.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (midiIn_2.get());
    midiIn_2->setEditableText (false);
    midiIn_2->setJustificationType (Justification::centredLeft);
    midiIn_2->setTextWhenNothingSelected (String());
    midiIn_2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midiIn_2->addListener (this);

    midiIn_3.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (midiIn_3.get());
    midiIn_3->setEditableText (false);
    midiIn_3->setJustificationType (Justification::centredLeft);
    midiIn_3->setTextWhenNothingSelected (String());
    midiIn_3->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midiIn_3->addListener (this);

    midiIn_4.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (midiIn_4.get());
    midiIn_4->setEditableText (false);
    midiIn_4->setJustificationType (Justification::centredLeft);
    midiIn_4->setTextWhenNothingSelected (String());
    midiIn_4->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midiIn_4->addListener (this);

    toggleButton_enableMIDIIN.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton_enableMIDIIN.get());
    toggleButton_enableMIDIIN->setButtonText (TRANS("Enable direct MIDI inputs"));
    toggleButton_enableMIDIIN->setConnectedEdges (Button::ConnectedOnTop);
    toggleButton_enableMIDIIN->addListener (this);
    toggleButton_enableMIDIIN->setToggleState (true, dontSendNotification);

    toggleButton_enableMIDIIN->setBounds (16, 32, 190, 24);

    Device.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (Device.get());
    Device->setEditableText (false);
    Device->setJustificationType (Justification::centredLeft);
    Device->setTextWhenNothingSelected (String());
    Device->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Device->addListener (this);

    midiOut_1.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (midiOut_1.get());
    midiOut_1->setEditableText (false);
    midiOut_1->setJustificationType (Justification::centredLeft);
    midiOut_1->setTextWhenNothingSelected (String());
    midiOut_1->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midiOut_1->addListener (this);

    midiOut_2.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (midiOut_2.get());
    midiOut_2->setEditableText (false);
    midiOut_2->setJustificationType (Justification::centredLeft);
    midiOut_2->setTextWhenNothingSelected (String());
    midiOut_2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midiOut_2->addListener (this);

    toggleButton_enableMIDIIN2.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton_enableMIDIIN2.get());
    toggleButton_enableMIDIIN2->setButtonText (TRANS("Enable direct MIDI outputs"));
    toggleButton_enableMIDIIN2->setConnectedEdges (Button::ConnectedOnTop);
    toggleButton_enableMIDIIN2->addListener (this);
    toggleButton_enableMIDIIN2->setToggleState (true, dontSendNotification);

    toggleButton_enableMIDIIN2->setBounds (16, 64, 190, 24);

    toggleButton_MIDITrough.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton_MIDITrough.get());
    toggleButton_MIDITrough->setButtonText (TRANS("Forward Inputs to Outputs"));
    toggleButton_MIDITrough->setConnectedEdges (Button::ConnectedOnTop);
    toggleButton_MIDITrough->addListener (this);
    toggleButton_MIDITrough->setToggleState (true, dontSendNotification);

    toggleButton_MIDITrough->setBounds (16, 96, 190, 24);

    toggleButton_MIDITrough2.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton_MIDITrough2.get());
    toggleButton_MIDITrough2->setButtonText (TRANS("Forward VST Host to Outputs"));
    toggleButton_MIDITrough2->setConnectedEdges (Button::ConnectedOnTop);
    toggleButton_MIDITrough2->addListener (this);
    toggleButton_MIDITrough2->setToggleState (true, dontSendNotification);

    toggleButton_MIDITrough2->setBounds (16, 128, 200, 24);

    midiOut_3.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (midiOut_3.get());
    midiOut_3->setEditableText (false);
    midiOut_3->setJustificationType (Justification::centredLeft);
    midiOut_3->setTextWhenNothingSelected (String());
    midiOut_3->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midiOut_3->addListener (this);

    midiOut_4.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (midiOut_4.get());
    midiOut_4->setEditableText (false);
    midiOut_4->setJustificationType (Justification::centredLeft);
    midiOut_4->setTextWhenNothingSelected (String());
    midiOut_4->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    midiOut_4->addListener (this);

    Send5.reset (new TextButton ("new button"));
    addAndMakeVisible (Send5.get());
    Send5->setButtonText (TRANS("Rescan"));
    Send5->addListener (this);
    Send5->setColour (TextButton::buttonColourId, Colour (0xff8d029d));

    Send5->setBounds (16, 288, 120, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (840, 340);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainViewTabInOut::~MainViewTabInOut()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    group_Device = nullptr;
    label6 = nullptr;
    group_MIDI_inputs = nullptr;
    midiIn_1 = nullptr;
    midiIn_2 = nullptr;
    midiIn_3 = nullptr;
    midiIn_4 = nullptr;
    toggleButton_enableMIDIIN = nullptr;
    Device = nullptr;
    midiOut_1 = nullptr;
    midiOut_2 = nullptr;
    toggleButton_enableMIDIIN2 = nullptr;
    toggleButton_MIDITrough = nullptr;
    toggleButton_MIDITrough2 = nullptr;
    midiOut_3 = nullptr;
    midiOut_4 = nullptr;
    Send5 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainViewTabInOut::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainViewTabInOut::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label6->setBounds (16, 168 + 32, 92, 24);
    midiIn_1->setBounds (264 + 10, 8 + 24, roundToInt (300 * 0.9267f), 24);
    midiIn_2->setBounds (264 + 10, 8 + 56, roundToInt (300 * 0.9267f), 24);
    midiIn_3->setBounds (264 + 10, 8 + 88, roundToInt (300 * 0.9267f), 24);
    midiIn_4->setBounds (264 + 10, 8 + 120, roundToInt (300 * 0.9267f), 24);
    Device->setBounds (16, 168 + 64, roundToInt (300 * 0.7000f), 24);
    midiOut_1->setBounds (256 + 16, 168 + 24, roundToInt (300 * 0.9267f), 24);
    midiOut_2->setBounds (256 + 16, 168 + 56, roundToInt (300 * 0.9267f), 24);
    midiOut_3->setBounds (256 + 16, 168 + 88, roundToInt (300 * 0.9267f), 24);
    midiOut_4->setBounds (256 + 16, 168 + 120, roundToInt (300 * 0.9267f), 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainViewTabInOut::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == midiIn_1.get())
    {
        //[UserComboBoxCode_midiIn_1] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiIn_1]
    }
    else if (comboBoxThatHasChanged == midiIn_2.get())
    {
        //[UserComboBoxCode_midiIn_2] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiIn_2]
    }
    else if (comboBoxThatHasChanged == midiIn_3.get())
    {
        //[UserComboBoxCode_midiIn_3] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiIn_3]
    }
    else if (comboBoxThatHasChanged == midiIn_4.get())
    {
        //[UserComboBoxCode_midiIn_4] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiIn_4]
    }
    else if (comboBoxThatHasChanged == Device.get())
    {
        //[UserComboBoxCode_Device] -- add your combo box handling code here..
        //[/UserComboBoxCode_Device]
    }
    else if (comboBoxThatHasChanged == midiOut_1.get())
    {
        //[UserComboBoxCode_midiOut_1] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiOut_1]
    }
    else if (comboBoxThatHasChanged == midiOut_2.get())
    {
        //[UserComboBoxCode_midiOut_2] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiOut_2]
    }
    else if (comboBoxThatHasChanged == midiOut_3.get())
    {
        //[UserComboBoxCode_midiOut_3] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiOut_3]
    }
    else if (comboBoxThatHasChanged == midiOut_4.get())
    {
        //[UserComboBoxCode_midiOut_4] -- add your combo box handling code here..
        //[/UserComboBoxCode_midiOut_4]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void MainViewTabInOut::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButton_enableMIDIIN.get())
    {
        //[UserButtonCode_toggleButton_enableMIDIIN] -- add your button handler code here..
        //[/UserButtonCode_toggleButton_enableMIDIIN]
    }
    else if (buttonThatWasClicked == toggleButton_enableMIDIIN2.get())
    {
        //[UserButtonCode_toggleButton_enableMIDIIN2] -- add your button handler code here..
        //[/UserButtonCode_toggleButton_enableMIDIIN2]
    }
    else if (buttonThatWasClicked == toggleButton_MIDITrough.get())
    {
        //[UserButtonCode_toggleButton_MIDITrough] -- add your button handler code here..
        //[/UserButtonCode_toggleButton_MIDITrough]
    }
    else if (buttonThatWasClicked == toggleButton_MIDITrough2.get())
    {
        //[UserButtonCode_toggleButton_MIDITrough2] -- add your button handler code here..
        //[/UserButtonCode_toggleButton_MIDITrough2]
    }
    else if (buttonThatWasClicked == Send5.get())
    {
        //[UserButtonCode_Send5] -- add your button handler code here..
        //[/UserButtonCode_Send5]
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

<JUCER_COMPONENT documentType="Component" className="MainViewTabInOut" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="840" initialHeight="340">
  <BACKGROUND backgroundColour="323e44"/>
  <GROUPCOMPONENT name="new group" id="393a4f32646bf2ab" memberName="group_Device"
                  virtualName="" explicitFocusOrder="0" pos="256 168 300 166" outlinecol="8e989b"
                  title="MIDI Outputs" textpos="36"/>
  <LABEL name="" id="698bda7139ffb619" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="16 32 92 24" posRelativeY="393a4f32646bf2ab"
         edTextCol="ff000000" edBkgCol="0" labelText="BassZero" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="new group" id="811fb38e4c4a9e43" memberName="group_MIDI_inputs"
                  virtualName="" explicitFocusOrder="0" pos="264 8 300 153" outlinecol="8e989b"
                  title="MIDI Inputs" textpos="36"/>
  <COMBOBOX name="new combo box" id="c3e4a37c9df5b41b" memberName="midiIn_1"
            virtualName="" explicitFocusOrder="0" pos="10 24 92.667% 24"
            posRelativeX="811fb38e4c4a9e43" posRelativeY="811fb38e4c4a9e43"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="483e0708c8bfa018" memberName="midiIn_2"
            virtualName="" explicitFocusOrder="0" pos="10 56 92.667% 24"
            posRelativeX="811fb38e4c4a9e43" posRelativeY="811fb38e4c4a9e43"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="ebe590884258fe7b" memberName="midiIn_3"
            virtualName="" explicitFocusOrder="0" pos="10 88 92.667% 24"
            posRelativeX="811fb38e4c4a9e43" posRelativeY="811fb38e4c4a9e43"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="14f7b647c7b46bbe" memberName="midiIn_4"
            virtualName="" explicitFocusOrder="0" pos="10 120 92.667% 24"
            posRelativeX="811fb38e4c4a9e43" posRelativeY="811fb38e4c4a9e43"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="new toggle button" id="7df38ca8caee935f" memberName="toggleButton_enableMIDIIN"
                virtualName="" explicitFocusOrder="0" pos="16 32 190 24" posRelativeX="532fe1565902977"
                posRelativeY="532fe1565902977" buttonText="Enable direct MIDI inputs"
                connectedEdges="4" needsCallback="1" radioGroupId="0" state="1"/>
  <COMBOBOX name="new combo box" id="ecbaa1c00ca2afa8" memberName="Device"
            virtualName="" explicitFocusOrder="0" pos="16 64 70% 24" posRelativeY="393a4f32646bf2ab"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="8028ca28394b1ab4" memberName="midiOut_1"
            virtualName="" explicitFocusOrder="0" pos="16 24 92.667% 24"
            posRelativeX="393a4f32646bf2ab" posRelativeY="393a4f32646bf2ab"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="9ef3f007eac12c4a" memberName="midiOut_2"
            virtualName="" explicitFocusOrder="0" pos="16 56 92.667% 24"
            posRelativeX="393a4f32646bf2ab" posRelativeY="393a4f32646bf2ab"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="new toggle button" id="dee7dd051b910639" memberName="toggleButton_enableMIDIIN2"
                virtualName="" explicitFocusOrder="0" pos="16 64 190 24" posRelativeX="532fe1565902977"
                posRelativeY="532fe1565902977" buttonText="Enable direct MIDI outputs"
                connectedEdges="4" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="5f74eeca5b007460" memberName="toggleButton_MIDITrough"
                virtualName="" explicitFocusOrder="0" pos="16 96 190 24" posRelativeX="532fe1565902977"
                posRelativeY="532fe1565902977" buttonText="Forward Inputs to Outputs"
                connectedEdges="4" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="ec2917d37e193e1a" memberName="toggleButton_MIDITrough2"
                virtualName="" explicitFocusOrder="0" pos="16 128 200 24" posRelativeX="532fe1565902977"
                posRelativeY="532fe1565902977" buttonText="Forward VST Host to Outputs"
                connectedEdges="4" needsCallback="1" radioGroupId="0" state="1"/>
  <COMBOBOX name="new combo box" id="390aab74011251f5" memberName="midiOut_3"
            virtualName="" explicitFocusOrder="0" pos="16 88 92.667% 24"
            posRelativeX="393a4f32646bf2ab" posRelativeY="393a4f32646bf2ab"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="700d864c81b87e1" memberName="midiOut_4"
            virtualName="" explicitFocusOrder="0" pos="16 120 92.667% 24"
            posRelativeX="393a4f32646bf2ab" posRelativeY="393a4f32646bf2ab"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="new button" id="81b4e57bbf82b3a1" memberName="Send5" virtualName=""
              explicitFocusOrder="0" pos="16 288 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ff8d029d" buttonText="Rescan"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

