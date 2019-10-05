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

#include "TabMainControl.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabMainControl::TabMainControl ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    group_Device.reset (new GroupComponent ("new group",
                                            TRANS("Outputs")));
    addAndMakeVisible (group_Device.get());
    group_Device->setTextLabelPosition (Justification::centred);
    group_Device->setColour (GroupComponent::outlineColourId, Colour (0x008e989b));

    group_Device->setBounds (432, 184, 400, 166);

    group_IO.reset (new GroupComponent ("new group",
                                        TRANS("Synth state & tools")));
    addAndMakeVisible (group_IO.get());
    group_IO->setTextLabelPosition (Justification::centredLeft);
    group_IO->setColour (GroupComponent::outlineColourId, Colour (0x008e989b));

    group_IO->setBounds (0, 246, 400, 108);

    group_MIDITEST.reset (new GroupComponent ("new group",
                                              TRANS("MIDI test loop")));
    addAndMakeVisible (group_MIDITEST.get());
    group_MIDITEST->setTextLabelPosition (Justification::centredLeft);
    group_MIDITEST->setColour (GroupComponent::outlineColourId, Colour (0x008e989b));

    group_MIDITEST->setBounds (0, 16, 400, 224);

    Send.reset (new TextButton ("new button"));
    addAndMakeVisible (Send.get());
    Send->setButtonText (TRANS("Read hardware"));
    Send->addListener (this);
    Send->setColour (TextButton::buttonColourId, Colours::crimson);

    toggleButton.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton.get());
    toggleButton->setButtonText (TRANS("Enable test loop"));
    toggleButton->setConnectedEdges (Button::ConnectedOnTop);
    toggleButton->addListener (this);

    slider_noteDuration.reset (new Slider ("new slider"));
    addAndMakeVisible (slider_noteDuration.get());
    slider_noteDuration->setRange (0, 16, 1);
    slider_noteDuration->setSliderStyle (Slider::LinearHorizontal);
    slider_noteDuration->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider_noteDuration->setColour (Slider::thumbColourId, Colours::crimson);
    slider_noteDuration->setColour (Slider::textBoxTextColourId, Colours::cadetblue);
    slider_noteDuration->addListener (this);

    label.reset (new Label ("new label",
                            TRANS("Note duration")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    slider_noteDuration2.reset (new Slider ("new slider"));
    addAndMakeVisible (slider_noteDuration2.get());
    slider_noteDuration2->setRange (0, 16, 1);
    slider_noteDuration2->setSliderStyle (Slider::LinearHorizontal);
    slider_noteDuration2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider_noteDuration2->setColour (Slider::thumbColourId, Colours::crimson);
    slider_noteDuration2->setColour (Slider::textBoxTextColourId, Colours::cadetblue);
    slider_noteDuration2->addListener (this);

    label2.reset (new Label ("new label",
                             TRANS("Loop duration")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    slider_bpm.reset (new Slider ("new slider"));
    addAndMakeVisible (slider_bpm.get());
    slider_bpm->setRange (120, 145, 1);
    slider_bpm->setSliderStyle (Slider::LinearHorizontal);
    slider_bpm->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider_bpm->setColour (Slider::thumbColourId, Colours::crimson);
    slider_bpm->setColour (Slider::textBoxTextColourId, Colours::crimson);
    slider_bpm->setColour (Slider::textBoxOutlineColourId, Colour (0xff3c3c3c));
    slider_bpm->addListener (this);

    label3.reset (new Label ("new label",
                             TRANS("BPM")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    slider_noteDuration3.reset (new Slider ("new slider"));
    addAndMakeVisible (slider_noteDuration3.get());
    slider_noteDuration3->setRange (-12, 12, 1);
    slider_noteDuration3->setSliderStyle (Slider::LinearHorizontal);
    slider_noteDuration3->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider_noteDuration3->setColour (Slider::thumbColourId, Colours::crimson);
    slider_noteDuration3->setColour (Slider::textBoxTextColourId, Colours::cadetblue);
    slider_noteDuration3->addListener (this);

    label5.reset (new Label ("new label",
                             TRANS("Pitch")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    slider_noteDuration4.reset (new Slider ("new slider"));
    addAndMakeVisible (slider_noteDuration4.get());
    slider_noteDuration4->setRange (0, 100, 1);
    slider_noteDuration4->setSliderStyle (Slider::LinearHorizontal);
    slider_noteDuration4->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider_noteDuration4->setColour (Slider::thumbColourId, Colours::crimson);
    slider_noteDuration4->setColour (Slider::textBoxTextColourId, Colours::cadetblue);
    slider_noteDuration4->addListener (this);

    label4.reset (new Label ("new label",
                             TRANS("Velocity")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Send2.reset (new TextButton ("new button"));
    addAndMakeVisible (Send2.get());
    Send2->setButtonText (TRANS("Write hardware"));
    Send2->addListener (this);
    Send2->setColour (TextButton::buttonColourId, Colours::crimson);

    Send3.reset (new TextButton ("new button"));
    addAndMakeVisible (Send3.get());
    Send3->setButtonText (TRANS("Save to file"));
    Send3->addListener (this);
    Send3->setColour (TextButton::buttonColourId, Colours::crimson);

    Send4.reset (new TextButton ("new button"));
    addAndMakeVisible (Send4.get());
    Send4->setButtonText (TRANS("Read from file"));
    Send4->addListener (this);
    Send4->setColour (TextButton::buttonColourId, Colours::crimson);

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
    group_MIDI_inputs->setTextLabelPosition (Justification::centredLeft);
    group_MIDI_inputs->setColour (GroupComponent::outlineColourId, Colour (0x008e989b));

    group_MIDI_inputs->setBounds (432, 17, 400, 180);

    comboBox_midiin1.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_midiin1.get());
    comboBox_midiin1->setEditableText (false);
    comboBox_midiin1->setJustificationType (Justification::centredLeft);
    comboBox_midiin1->setTextWhenNothingSelected (String());
    comboBox_midiin1->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_midiin1->addListener (this);

    comboBox_midiin2.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_midiin2.get());
    comboBox_midiin2->setEditableText (false);
    comboBox_midiin2->setJustificationType (Justification::centredLeft);
    comboBox_midiin2->setTextWhenNothingSelected (String());
    comboBox_midiin2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_midiin2->addListener (this);

    comboBox_midiin3.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_midiin3.get());
    comboBox_midiin3->setEditableText (false);
    comboBox_midiin3->setJustificationType (Justification::centredLeft);
    comboBox_midiin3->setTextWhenNothingSelected (String());
    comboBox_midiin3->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_midiin3->addListener (this);

    comboBox_midiin4.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_midiin4.get());
    comboBox_midiin4->setEditableText (false);
    comboBox_midiin4->setJustificationType (Justification::centredLeft);
    comboBox_midiin4->setTextWhenNothingSelected (String());
    comboBox_midiin4->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_midiin4->addListener (this);

    toggleButton_enableMIDIIN.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton_enableMIDIIN.get());
    toggleButton_enableMIDIIN->setButtonText (TRANS("Enable direct MIDI inputs"));
    toggleButton_enableMIDIIN->setConnectedEdges (Button::ConnectedOnTop);
    toggleButton_enableMIDIIN->addListener (this);
    toggleButton_enableMIDIIN->setToggleState (true, dontSendNotification);

    comboBox_midiin6.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_midiin6.get());
    comboBox_midiin6->setEditableText (false);
    comboBox_midiin6->setJustificationType (Justification::centredLeft);
    comboBox_midiin6->setTextWhenNothingSelected (String());
    comboBox_midiin6->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_midiin6->addListener (this);

    Send5.reset (new TextButton ("new button"));
    addAndMakeVisible (Send5.get());
    Send5->setButtonText (TRANS("Rescan"));
    Send5->addListener (this);
    Send5->setColour (TextButton::buttonColourId, Colours::crimson);

    comboBox_midiin5.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_midiin5.get());
    comboBox_midiin5->setEditableText (false);
    comboBox_midiin5->setJustificationType (Justification::centredLeft);
    comboBox_midiin5->setTextWhenNothingSelected (String());
    comboBox_midiin5->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_midiin5->addListener (this);

    label7.reset (new Label (String(),
                             TRANS("MIDI Outputs")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    comboBox_midiin7.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_midiin7.get());
    comboBox_midiin7->setEditableText (false);
    comboBox_midiin7->setJustificationType (Justification::centredLeft);
    comboBox_midiin7->setTextWhenNothingSelected (String());
    comboBox_midiin7->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_midiin7->addListener (this);

    Send6.reset (new TextButton ("new button"));
    addAndMakeVisible (Send6.get());
    Send6->setButtonText (TRANS("Diagnostic"));
    Send6->addListener (this);
    Send6->setColour (TextButton::buttonColourId, Colours::crimson);

    toggleButton_enableMIDIIN2.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton_enableMIDIIN2.get());
    toggleButton_enableMIDIIN2->setButtonText (TRANS("Enable direct MIDI outputs"));
    toggleButton_enableMIDIIN2->setConnectedEdges (Button::ConnectedOnTop);
    toggleButton_enableMIDIIN2->addListener (this);
    toggleButton_enableMIDIIN2->setToggleState (true, dontSendNotification);

    cachedImage_basszero_background_jpg2_1 = ImageCache::getFromMemory (basszero_background_jpg2, basszero_background_jpg2Size);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TabMainControl::~TabMainControl()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    group_Device = nullptr;
    group_IO = nullptr;
    group_MIDITEST = nullptr;
    Send = nullptr;
    toggleButton = nullptr;
    slider_noteDuration = nullptr;
    label = nullptr;
    slider_noteDuration2 = nullptr;
    label2 = nullptr;
    slider_bpm = nullptr;
    label3 = nullptr;
    slider_noteDuration3 = nullptr;
    label5 = nullptr;
    slider_noteDuration4 = nullptr;
    label4 = nullptr;
    Send2 = nullptr;
    Send3 = nullptr;
    Send4 = nullptr;
    label6 = nullptr;
    group_MIDI_inputs = nullptr;
    comboBox_midiin1 = nullptr;
    comboBox_midiin2 = nullptr;
    comboBox_midiin3 = nullptr;
    comboBox_midiin4 = nullptr;
    toggleButton_enableMIDIIN = nullptr;
    comboBox_midiin6 = nullptr;
    Send5 = nullptr;
    comboBox_midiin5 = nullptr;
    label7 = nullptr;
    comboBox_midiin7 = nullptr;
    Send6 = nullptr;
    toggleButton_enableMIDIIN2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TabMainControl::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 0, y = 0, width = 840, height = 444;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black);
        g.drawImage (cachedImage_basszero_background_jpg2_1,
                     x, y, width, height,
                     0, 0, cachedImage_basszero_background_jpg2_1.getWidth(), cachedImage_basszero_background_jpg2_1.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TabMainControl::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    Send->setBounds (0 + 15, 246 + 32, 120, 24);
    toggleButton->setBounds (0 + 16, 16 + 189, 150, 24);
    slider_noteDuration->setBounds (0 + 400 - 260, 16 + 88, 260, 24);
    label->setBounds ((0 + 400 - 260) + 0 - 100, (16 + 88) + 0, 100, 24);
    slider_noteDuration2->setBounds (0 + 400 - 260, 16 + 112, 260, 24);
    label2->setBounds ((0 + 400 - 260) + 0 - 100, (16 + 112) + 0, 100, 24);
    slider_bpm->setBounds (0 + 400 - 260, 16 + 149, 260, 36);
    label3->setBounds ((0 + 400 - 260) + 0 - 100, (16 + 149) + 0, 100, 24);
    slider_noteDuration3->setBounds (0 + 400 - 260, 16 + 58, 260, 24);
    label5->setBounds ((0 + 400 - 260) + 0 - 100, (16 + 88) + -30, 100, 24);
    slider_noteDuration4->setBounds (0 + 400 - 260, 16 + 25, 260, 24);
    label4->setBounds ((0 + 400 - 260) + -1 - 100, (16 + 88) + -63, 100, 24);
    Send2->setBounds (0 + 15, 246 + 64, 120, 24);
    Send3->setBounds (0 + 143, 246 + 32, 120, 24);
    Send4->setBounds (0 + 143, 246 + 64, 120, 24);
    label6->setBounds (432 + 10, 184 + 24, 92, 24);
    comboBox_midiin1->setBounds (448, 17 + 24, roundToInt (400 * 0.9250f), 24);
    comboBox_midiin2->setBounds (448, 17 + 56, roundToInt (400 * 0.9250f), 24);
    comboBox_midiin3->setBounds (448, 17 + 88, roundToInt (400 * 0.9250f), 24);
    comboBox_midiin4->setBounds (448, 17 + 120, roundToInt (400 * 0.9250f), 24);
    toggleButton_enableMIDIIN->setBounds (0 + 629, 16 + -5, 190, 24);
    comboBox_midiin6->setBounds (432 + 104, 184 + 24, roundToInt (400 * 0.7000f), 24);
    Send5->setBounds (0 + 271, 246 + 32, 120, 24);
    comboBox_midiin5->setBounds (432 + 16, 184 + 93, roundToInt (400 * 0.9250f), 24);
    label7->setBounds (432 + 10, 184 + 64, roundToInt (400 * 0.9500f), 24);
    comboBox_midiin7->setBounds (432 + 16, 184 + 126, roundToInt (400 * 0.9250f), 24);
    Send6->setBounds (0 + 271, 246 + 64, 120, 24);
    toggleButton_enableMIDIIN2->setBounds (0 + 624, 16 + 233, 190, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TabMainControl::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == Send.get())
    {
        //[UserButtonCode_Send] -- add your button handler code here..
        //[/UserButtonCode_Send]
    }
    else if (buttonThatWasClicked == toggleButton.get())
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
        //[/UserButtonCode_toggleButton]
    }
    else if (buttonThatWasClicked == Send2.get())
    {
        //[UserButtonCode_Send2] -- add your button handler code here..
        //[/UserButtonCode_Send2]
    }
    else if (buttonThatWasClicked == Send3.get())
    {
        //[UserButtonCode_Send3] -- add your button handler code here..
        //[/UserButtonCode_Send3]
    }
    else if (buttonThatWasClicked == Send4.get())
    {
        //[UserButtonCode_Send4] -- add your button handler code here..
        //[/UserButtonCode_Send4]
    }
    else if (buttonThatWasClicked == toggleButton_enableMIDIIN.get())
    {
        //[UserButtonCode_toggleButton_enableMIDIIN] -- add your button handler code here..
        //[/UserButtonCode_toggleButton_enableMIDIIN]
    }
    else if (buttonThatWasClicked == Send5.get())
    {
        //[UserButtonCode_Send5] -- add your button handler code here..
        //[/UserButtonCode_Send5]
    }
    else if (buttonThatWasClicked == Send6.get())
    {
        //[UserButtonCode_Send6] -- add your button handler code here..
        //[/UserButtonCode_Send6]
    }
    else if (buttonThatWasClicked == toggleButton_enableMIDIIN2.get())
    {
        //[UserButtonCode_toggleButton_enableMIDIIN2] -- add your button handler code here..
        //[/UserButtonCode_toggleButton_enableMIDIIN2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void TabMainControl::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider_noteDuration.get())
    {
        //[UserSliderCode_slider_noteDuration] -- add your slider handling code here..
        //[/UserSliderCode_slider_noteDuration]
    }
    else if (sliderThatWasMoved == slider_noteDuration2.get())
    {
        //[UserSliderCode_slider_noteDuration2] -- add your slider handling code here..
        //[/UserSliderCode_slider_noteDuration2]
    }
    else if (sliderThatWasMoved == slider_bpm.get())
    {
        //[UserSliderCode_slider_bpm] -- add your slider handling code here..
        //[/UserSliderCode_slider_bpm]
    }
    else if (sliderThatWasMoved == slider_noteDuration3.get())
    {
        //[UserSliderCode_slider_noteDuration3] -- add your slider handling code here..
        //[/UserSliderCode_slider_noteDuration3]
    }
    else if (sliderThatWasMoved == slider_noteDuration4.get())
    {
        //[UserSliderCode_slider_noteDuration4] -- add your slider handling code here..
        //[/UserSliderCode_slider_noteDuration4]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void TabMainControl::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox_midiin1.get())
    {
        //[UserComboBoxCode_comboBox_midiin1] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox_midiin1]
    }
    else if (comboBoxThatHasChanged == comboBox_midiin2.get())
    {
        //[UserComboBoxCode_comboBox_midiin2] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox_midiin2]
    }
    else if (comboBoxThatHasChanged == comboBox_midiin3.get())
    {
        //[UserComboBoxCode_comboBox_midiin3] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox_midiin3]
    }
    else if (comboBoxThatHasChanged == comboBox_midiin4.get())
    {
        //[UserComboBoxCode_comboBox_midiin4] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox_midiin4]
    }
    else if (comboBoxThatHasChanged == comboBox_midiin6.get())
    {
        //[UserComboBoxCode_comboBox_midiin6] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox_midiin6]
    }
    else if (comboBoxThatHasChanged == comboBox_midiin5.get())
    {
        //[UserComboBoxCode_comboBox_midiin5] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox_midiin5]
    }
    else if (comboBoxThatHasChanged == comboBox_midiin7.get())
    {
        //[UserComboBoxCode_comboBox_midiin7] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox_midiin7]
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

<JUCER_COMPONENT documentType="Component" className="TabMainControl" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <IMAGE pos="0 0 840 444" resource="basszero_background_jpg2" opacity="1.0"
           mode="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="393a4f32646bf2ab" memberName="group_Device"
                  virtualName="" explicitFocusOrder="0" pos="432 184 400 166" outlinecol="8e989b"
                  title="Outputs" textpos="36"/>
  <GROUPCOMPONENT name="new group" id="d44bfedad95ee328" memberName="group_IO"
                  virtualName="" explicitFocusOrder="0" pos="0 246 400 108" outlinecol="8e989b"
                  title="Synth state &amp; tools" textpos="33"/>
  <GROUPCOMPONENT name="new group" id="532fe1565902977" memberName="group_MIDITEST"
                  virtualName="" explicitFocusOrder="0" pos="0 16 400 224" outlinecol="8e989b"
                  title="MIDI test loop" textpos="33"/>
  <TEXTBUTTON name="new button" id="1eaf3791f3ec0d8" memberName="Send" virtualName=""
              explicitFocusOrder="0" pos="15 32 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ffdc143c" buttonText="Read hardware"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="new toggle button" id="f247140d4b3ed493" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="16 189 150 24" posRelativeX="532fe1565902977"
                posRelativeY="532fe1565902977" buttonText="Enable test loop"
                connectedEdges="4" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="new slider" id="b894ad866522ab7a" memberName="slider_noteDuration"
          virtualName="" explicitFocusOrder="0" pos="0Rr 88 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ffdc143c" textboxtext="ff5f9ea0"
          min="0.0" max="16.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="590d78a96d95f417" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0r 0 100 24" posRelativeX="b894ad866522ab7a"
         posRelativeY="b894ad866522ab7a" edTextCol="ff000000" edBkgCol="0"
         labelText="Note duration" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="8cdab6a4a52521ea" memberName="slider_noteDuration2"
          virtualName="" explicitFocusOrder="0" pos="0Rr 112 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ffdc143c" textboxtext="ff5f9ea0"
          min="0.0" max="16.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="2d31deb9a14e9516" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0r 0 100 24" posRelativeX="b894ad866522ab7a"
         posRelativeY="8cdab6a4a52521ea" edTextCol="ff000000" edBkgCol="0"
         labelText="Loop duration" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="90b8d711ec3b5129" memberName="slider_bpm"
          virtualName="" explicitFocusOrder="0" pos="0Rr 149 260 36" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ffdc143c" textboxtext="ffdc143c"
          textboxoutline="ff3c3c3c" min="120.0" max="145.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="3bffceec306bf2af" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="0r 0 100 24" posRelativeX="90b8d711ec3b5129"
         posRelativeY="90b8d711ec3b5129" edTextCol="ff000000" edBkgCol="0"
         labelText="BPM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="6dcb364d4a3d77a4" memberName="slider_noteDuration3"
          virtualName="" explicitFocusOrder="0" pos="0Rr 58 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ffdc143c" textboxtext="ff5f9ea0"
          min="-12.0" max="12.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a4b00718571d2318" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0r -30 100 24" posRelativeX="b894ad866522ab7a"
         posRelativeY="b894ad866522ab7a" edTextCol="ff000000" edBkgCol="0"
         labelText="Pitch" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="fcff0307f3220069" memberName="slider_noteDuration4"
          virtualName="" explicitFocusOrder="0" pos="0Rr 25 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ffdc143c" textboxtext="ff5f9ea0"
          min="0.0" max="100.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="91e9398673c967bd" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="-1r -63 100 24" posRelativeX="b894ad866522ab7a"
         posRelativeY="b894ad866522ab7a" edTextCol="ff000000" edBkgCol="0"
         labelText="Velocity" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="895ac3ceb43dfbef" memberName="Send2" virtualName=""
              explicitFocusOrder="0" pos="15 64 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ffdc143c" buttonText="Write hardware"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="43d3cf409c52e4d5" memberName="Send3" virtualName=""
              explicitFocusOrder="0" pos="143 32 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ffdc143c" buttonText="Save to file"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="58806260c847b610" memberName="Send4" virtualName=""
              explicitFocusOrder="0" pos="143 64 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ffdc143c" buttonText="Read from file"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="" id="698bda7139ffb619" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="10 24 92 24" posRelativeX="393a4f32646bf2ab"
         posRelativeY="393a4f32646bf2ab" edTextCol="ff000000" edBkgCol="0"
         labelText="BassZero" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="new group" id="811fb38e4c4a9e43" memberName="group_MIDI_inputs"
                  virtualName="" explicitFocusOrder="0" pos="432 17 400 180" outlinecol="8e989b"
                  title="MIDI Inputs" textpos="33"/>
  <COMBOBOX name="new combo box" id="c3e4a37c9df5b41b" memberName="comboBox_midiin1"
            virtualName="" explicitFocusOrder="0" pos="448 24 92.5% 24" posRelativeY="811fb38e4c4a9e43"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="483e0708c8bfa018" memberName="comboBox_midiin2"
            virtualName="" explicitFocusOrder="0" pos="448 56 92.5% 24" posRelativeY="811fb38e4c4a9e43"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="ebe590884258fe7b" memberName="comboBox_midiin3"
            virtualName="" explicitFocusOrder="0" pos="448 88 92.5% 24" posRelativeY="811fb38e4c4a9e43"
            posRelativeW="811fb38e4c4a9e43" editable="0" layout="33" items=""
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="14f7b647c7b46bbe" memberName="comboBox_midiin4"
            virtualName="" explicitFocusOrder="0" pos="448 120 92.5% 24"
            posRelativeY="811fb38e4c4a9e43" posRelativeW="811fb38e4c4a9e43"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="new toggle button" id="7df38ca8caee935f" memberName="toggleButton_enableMIDIIN"
                virtualName="" explicitFocusOrder="0" pos="629 -5 190 24" posRelativeX="532fe1565902977"
                posRelativeY="532fe1565902977" buttonText="Enable direct MIDI inputs"
                connectedEdges="4" needsCallback="1" radioGroupId="0" state="1"/>
  <COMBOBOX name="new combo box" id="ecbaa1c00ca2afa8" memberName="comboBox_midiin6"
            virtualName="" explicitFocusOrder="0" pos="104 24 70% 24" posRelativeX="393a4f32646bf2ab"
            posRelativeY="393a4f32646bf2ab" posRelativeW="811fb38e4c4a9e43"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="new button" id="81b4e57bbf82b3a1" memberName="Send5" virtualName=""
              explicitFocusOrder="0" pos="271 32 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ffdc143c" buttonText="Rescan"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="new combo box" id="8028ca28394b1ab4" memberName="comboBox_midiin5"
            virtualName="" explicitFocusOrder="0" pos="16 93 92.5% 24" posRelativeX="393a4f32646bf2ab"
            posRelativeY="393a4f32646bf2ab" posRelativeW="811fb38e4c4a9e43"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="" id="3af85530f1fb6d78" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="10 64 95% 24" posRelativeX="393a4f32646bf2ab"
         posRelativeY="393a4f32646bf2ab" posRelativeW="393a4f32646bf2ab"
         edTextCol="ff000000" edBkgCol="0" labelText="MIDI Outputs" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="9ef3f007eac12c4a" memberName="comboBox_midiin7"
            virtualName="" explicitFocusOrder="0" pos="16 126 92.5% 24" posRelativeX="393a4f32646bf2ab"
            posRelativeY="393a4f32646bf2ab" posRelativeW="811fb38e4c4a9e43"
            editable="0" layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="new button" id="11d30a7d0413f64a" memberName="Send6" virtualName=""
              explicitFocusOrder="0" pos="271 64 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ffdc143c" buttonText="Diagnostic"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="new toggle button" id="dee7dd051b910639" memberName="toggleButton_enableMIDIIN2"
                virtualName="" explicitFocusOrder="0" pos="624 233 190 24" posRelativeX="532fe1565902977"
                posRelativeY="532fe1565902977" buttonText="Enable direct MIDI outputs"
                connectedEdges="4" needsCallback="1" radioGroupId="0" state="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: basszero_background_jpg, 14299, "../basszero_background.jpg"
static const unsigned char resource_TabMainControl_basszero_background_jpg[] = { 255,216,255,225,0,24,69,120,105,102,0,0,73,73,42,0,8,0,0,0,0,0,0,0,0,0,0,0,255,236,0,17,68,117,99,107,121,0,1,0,4,0,0,0,
100,0,0,255,225,3,111,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,0,60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,
100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,32,60,120,58,120,109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,
115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,114,101,32,53,46,51,45,99,48,49,49,32,54,54,46,49,52,53,54,54,49,44,32,50,48,49,50,47,48,50,47,48,
54,45,49,52,58,53,54,58,50,55,32,32,32,32,32,32,32,32,34,62,32,60,114,100,102,58,82,68,70,32,120,109,108,110,115,58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,
57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,32,120,
109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,109,109,47,34,32,120,109,108,110,115,58,115,116,82,101,102,61,
34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,112,101,47,82,101,115,111,117,114,99,101,82,101,102,35,34,32,120,109,108,110,115,58,120,109,
112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,34,32,120,109,112,77,77,58,79,114,105,103,105,110,97,108,68,111,99,117,109,101,110,116,73,68,
61,34,120,109,112,46,100,105,100,58,66,53,48,70,68,51,55,53,65,54,69,49,69,57,49,49,56,51,65,67,66,56,54,65,48,49,49,48,49,53,53,50,34,32,120,109,112,77,77,58,68,111,99,117,109,101,110,116,73,68,61,34,
120,109,112,46,100,105,100,58,53,55,53,56,68,70,66,56,69,49,65,57,49,49,69,57,56,55,48,56,69,68,51,50,65,50,49,54,55,69,67,65,34,32,120,109,112,77,77,58,73,110,115,116,97,110,99,101,73,68,61,34,120,109,
112,46,105,105,100,58,53,55,53,56,68,70,66,55,69,49,65,57,49,49,69,57,56,55,48,56,69,68,51,50,65,50,49,54,55,69,67,65,34,32,120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,61,34,65,100,111,98,
101,32,80,104,111,116,111,115,104,111,112,32,67,83,54,32,40,87,105,110,100,111,119,115,41,34,62,32,60,120,109,112,77,77,58,68,101,114,105,118,101,100,70,114,111,109,32,115,116,82,101,102,58,105,110,115,
116,97,110,99,101,73,68,61,34,120,109,112,46,105,105,100,58,66,53,48,70,68,51,55,53,65,54,69,49,69,57,49,49,56,51,65,67,66,56,54,65,48,49,49,48,49,53,53,50,34,32,115,116,82,101,102,58,100,111,99,117,109,
101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,66,53,48,70,68,51,55,53,65,54,69,49,69,57,49,49,56,51,65,67,66,56,54,65,48,49,49,48,49,53,53,50,34,47,62,32,60,47,114,100,102,58,68,101,115,99,114,
105,112,116,105,111,110,62,32,60,47,114,100,102,58,82,68,70,62,32,60,47,120,58,120,109,112,109,101,116,97,62,32,60,63,120,112,97,99,107,101,116,32,101,110,100,61,34,114,34,63,62,255,238,0,14,65,100,111,
98,101,0,100,192,0,0,0,1,255,219,0,132,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,2,1,1,2,2,2,1,2,2,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,255,192,0,17,8,1,144,3,72,3,1,17,0,2,17,1,3,17,1,255,196,0,122,0,1,0,3,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,3,
4,2,5,10,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,6,16,0,2,2,1,1,6,6,2,3,1,0,3,1,0,0,0,0,1,17,2,33,18,240,49,65,81,34,3,97,113,129,145,177,225,161,193,209,241,50,19,66,82,4,98,17,1,0,2,2,3,1,1,1,1,1,0,
0,0,0,0,0,0,33,65,1,17,49,97,113,129,177,81,145,161,255,218,0,12,3,1,0,2,17,3,17,0,63,0,249,216,58,135,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,91,74,198,120,191,192,27,59,
93,188,172,78,220,2,182,214,169,76,40,219,224,11,106,166,175,19,183,225,19,34,221,53,211,89,168,87,77,45,74,42,253,72,41,179,90,159,73,81,155,185,104,171,219,151,242,81,231,95,184,211,226,147,113,229,
231,32,203,71,107,187,148,154,246,32,221,75,172,184,146,141,93,187,215,79,249,254,176,69,105,86,172,87,164,134,178,234,86,173,217,230,84,161,68,219,31,100,4,214,151,140,114,20,88,218,138,244,253,5,28,
59,41,172,242,101,74,86,213,102,211,95,38,69,103,178,90,95,75,244,249,94,37,50,205,100,177,43,122,227,250,42,50,247,123,106,119,16,231,12,55,174,244,248,113,41,173,51,181,14,2,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,59,165,120,191,64,54,118,251,111,14,50,249,240,3,125,106,253,99,111,66,43,71,110,150,
151,142,30,223,97,112,190,181,182,135,133,30,146,201,131,31,199,109,89,86,189,43,215,108,21,75,43,106,77,37,184,12,247,213,54,194,231,204,136,197,221,157,56,52,152,233,229,247,19,207,57,159,127,236,34,
59,118,136,230,190,0,244,123,55,111,126,231,157,189,130,182,210,214,73,165,183,129,50,97,173,90,218,107,187,195,111,2,42,249,180,172,96,182,144,117,75,199,144,178,16,157,180,238,200,174,130,109,21,198,
120,130,29,102,119,96,78,200,210,58,166,223,128,66,166,173,161,225,120,115,224,26,253,81,220,173,180,215,167,239,197,120,129,154,201,166,211,80,57,195,44,93,222,211,109,251,129,134,245,159,53,180,21,20,
128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,77,84,191,14,32,107,237,209,219,43,17,184,46,30,133,41,9,75,
123,124,1,170,157,183,169,101,115,39,43,166,154,81,205,186,190,252,89,14,22,86,175,75,155,126,75,70,229,211,78,22,121,122,145,45,203,171,212,186,176,246,101,93,195,53,170,230,221,92,215,155,225,240,65,
138,234,106,214,219,65,166,94,111,114,176,243,197,1,149,61,47,201,195,3,95,106,240,247,225,238,229,179,10,244,123,118,110,187,246,254,192,217,86,244,215,171,142,60,54,70,85,169,78,165,213,134,183,20,118,
147,151,159,160,136,73,233,121,245,37,22,67,133,213,246,4,195,149,156,114,41,66,78,94,126,128,136,110,173,55,191,137,40,181,119,163,211,94,172,173,197,94,89,251,157,183,169,117,123,240,250,96,101,181,
119,174,57,91,120,21,24,59,157,182,165,242,97,24,175,94,62,224,112,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,209,74,238,94,175,246,6,254,207,109,37,57,218,8,214,114,217,90,168,89,240,219,28,130,53,86,180,212,165,226,61,223,240,23,95,197,245,173,83,179,227,227,193,18,12,237,41,87,75,206,4,107,180,26,172,44,
227,128,130,81,101,86,212,188,175,178,248,184,103,186,172,223,59,113,32,199,100,161,231,25,246,69,71,159,222,73,47,89,40,197,117,153,230,17,52,183,15,84,6,254,205,212,111,127,143,0,189,183,85,172,63,89,
248,32,217,87,77,75,47,239,242,26,218,250,233,110,217,207,31,34,66,101,41,87,75,206,4,107,180,26,172,44,227,128,130,83,141,75,57,17,240,157,33,42,203,231,196,65,34,85,210,243,129,26,236,67,85,105,103,
200,44,171,189,107,169,101,204,110,247,240,41,204,178,222,181,155,67,230,246,242,27,70,78,229,19,171,41,183,159,122,71,147,192,50,203,101,14,61,188,130,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,89,74,241,244,64,110,236,211,131,91,248,224,138,219,85,11,118,222,37,26,234,150,154,244,249,243,217,145,112,210,163,
82,233,225,141,188,1,78,148,77,177,246,68,19,90,94,49,200,82,216,218,138,244,253,1,13,169,205,125,74,152,81,103,89,191,79,7,195,204,52,198,226,55,70,127,91,131,57,99,239,70,58,118,106,127,96,233,130,235,
15,154,217,149,20,167,14,64,211,75,198,120,61,191,0,122,93,187,167,90,145,90,233,117,169,77,113,3,74,215,75,41,183,78,120,237,226,67,151,105,167,89,75,28,133,22,150,212,87,167,232,3,107,82,198,121,149,
40,81,54,199,217,1,53,165,227,28,133,45,141,168,175,79,208,16,227,82,233,151,204,166,56,81,109,45,219,167,15,240,243,248,10,201,100,163,115,223,178,12,178,119,168,163,119,61,209,182,6,135,159,122,61,220,
86,226,162,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,148,165,192,26,187,117,109,168,88,88,252,5,195,210,237,
213,174,27,200,53,82,182,210,241,137,11,134,164,175,166,170,60,193,181,217,157,216,19,180,141,33,106,151,140,112,4,33,59,105,221,145,93,9,234,133,133,60,65,14,108,237,169,36,177,188,46,53,165,22,118,155,
225,114,34,178,54,248,198,255,0,202,80,92,51,150,94,244,197,118,206,71,167,156,48,221,101,248,254,202,140,205,67,104,14,168,225,199,63,144,54,246,187,143,10,119,63,159,224,15,66,182,105,166,190,137,202,
240,217,219,189,166,206,63,165,143,112,171,232,236,234,220,121,109,32,206,157,77,162,184,207,16,144,235,51,187,2,118,70,144,181,75,198,56,2,16,157,180,238,200,174,132,245,66,194,158,32,131,50,177,128,
57,106,211,108,97,160,172,150,173,180,188,109,207,120,25,111,87,17,5,79,94,127,122,142,102,1,168,99,186,135,60,254,66,56,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,212,174,60,95,192,27,251,93,184,107,193,79,31,80,55,82,173,188,56,133,178,247,38,87,13,93,186,219,71,250,221,242,69,233,122,78,43,213,200,14,179,43,56,
141,197,148,161,39,47,63,64,66,79,78,252,243,37,22,57,73,117,103,228,46,57,87,121,86,255,0,92,61,138,97,154,205,205,186,184,108,216,25,158,237,229,70,126,227,112,179,199,159,44,79,169,21,142,251,253,63,
146,178,162,235,115,244,127,160,43,2,250,93,239,226,183,129,232,118,187,146,212,189,255,0,199,232,138,219,219,109,55,152,199,17,147,13,52,109,211,253,111,124,247,63,178,83,77,25,138,245,103,228,34,115,
43,56,141,197,148,161,39,47,63,64,66,79,78,252,243,37,22,67,133,213,246,4,230,86,125,62,139,37,16,229,231,232,154,20,186,91,67,234,152,126,235,144,94,153,123,148,105,85,204,237,250,46,12,178,119,105,62,
152,97,48,243,123,148,134,215,61,191,5,70,96,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,58,170,151,225,196,13,93,186,
203,207,60,5,195,209,165,82,141,177,233,196,134,218,187,106,146,243,185,127,67,213,195,77,43,93,17,60,115,248,20,179,142,56,90,213,97,103,28,9,12,200,244,234,89,200,143,132,232,74,178,249,241,16,75,153,
170,171,200,141,44,252,87,119,88,174,121,122,5,81,220,181,85,176,222,210,57,76,179,90,201,55,147,72,207,110,226,135,158,62,228,94,89,239,106,190,47,246,247,123,21,54,165,185,109,132,113,101,53,126,254,
192,82,4,167,14,64,211,219,178,86,79,131,228,23,111,71,183,100,211,200,26,168,234,170,229,237,207,220,153,92,112,212,157,116,215,57,65,112,187,165,180,231,60,9,31,25,145,42,203,231,196,65,34,85,210,243,
129,26,236,26,172,44,227,128,130,70,171,169,115,44,124,4,171,47,62,100,130,92,181,93,47,56,24,225,113,156,239,76,253,202,82,43,15,199,235,113,87,44,215,170,78,22,84,125,12,75,47,63,187,69,47,159,13,164,
165,48,93,113,247,8,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,212,172,47,23,157,188,128,223,218,170,138,227,249,
34,233,182,177,169,74,148,92,141,52,211,47,167,123,152,219,192,202,174,173,170,170,250,113,33,117,151,110,213,138,227,148,110,192,77,100,118,174,165,211,62,48,83,78,85,235,54,196,126,200,105,91,189,85,
28,87,28,224,10,47,122,194,233,253,55,244,202,40,189,212,206,239,1,194,48,119,123,208,237,251,91,138,101,151,254,137,255,0,229,248,127,192,68,106,175,48,38,83,220,211,0,247,63,38,5,0,0,238,150,224,253,
54,241,3,111,103,185,27,247,147,43,134,250,217,53,41,109,253,1,166,183,172,85,70,231,241,192,46,50,212,174,181,46,152,159,192,63,93,166,166,216,245,230,68,145,53,165,227,28,133,22,54,162,189,63,65,71,
26,151,78,121,149,40,81,54,199,217,1,53,165,227,28,133,44,237,93,244,233,75,79,150,222,32,101,238,198,175,242,247,55,203,204,190,12,151,170,105,226,112,17,230,222,185,106,48,202,140,173,67,128,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,170,165,248,45,224,107,237,213,188,199,144,30,133,19,85,75,111,2,47,45,20,86,212,177,
224,182,241,97,90,106,236,173,108,34,72,237,90,218,30,239,117,225,226,85,237,14,246,211,92,4,115,110,229,181,45,222,75,249,7,16,171,254,175,85,176,183,63,22,5,79,185,104,143,29,177,192,105,54,226,214,
109,41,204,109,146,240,51,247,46,247,47,63,198,242,26,255,0,24,59,157,86,115,183,18,163,43,80,225,128,0,0,0,0,0,93,75,123,175,200,27,187,61,199,28,55,145,168,203,109,110,225,109,180,13,39,77,148,189,181,
44,78,54,97,121,95,87,102,237,140,111,76,25,117,54,210,241,146,87,73,27,58,161,97,79,18,144,156,202,228,39,100,105,18,229,227,203,196,16,39,104,221,146,87,68,109,205,181,66,133,199,37,165,199,42,123,138,
218,150,60,87,239,136,60,99,178,114,229,21,24,59,212,113,187,196,12,23,92,125,194,43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,93,74,194,92,222,201,1,187,181,71,27,248,199,45,160,141,83,90,220,138,150,209,84,213,171,213,183,209,21,114,78,109,212,7,57,85,125,94,159,207,34,10,175,103,21,234,246,221,246,92,25,84,238,219,151,
111,201,81,95,253,20,219,43,30,60,72,43,255,0,174,55,173,185,110,2,187,119,28,44,237,241,32,83,123,230,91,159,14,63,56,64,218,134,229,201,81,93,214,231,232,5,96,0,0,0,0,2,112,229,1,162,150,226,189,64,
244,59,87,197,122,189,246,228,21,174,150,122,151,83,38,120,54,215,219,110,109,213,231,231,207,200,138,182,179,165,205,188,158,220,1,158,93,67,133,213,246,17,48,245,44,227,145,74,18,114,243,244,4,36,244,
239,207,50,81,100,56,93,95,96,87,106,183,108,91,129,85,146,244,109,219,169,109,191,242,6,78,237,102,175,59,123,243,42,60,235,214,48,247,53,183,48,153,101,106,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,19,85,45,123,176,53,118,212,188,238,91,124,1,187,181,85,167,206,63,36,91,133,248,143,95,193,69,203,76,215,60,12,175,226,
83,83,101,169,129,91,117,210,210,101,157,162,142,229,149,86,242,152,97,238,119,165,239,247,106,2,42,255,0,167,255,0,165,238,191,114,7,26,215,254,223,33,118,157,73,255,0,229,238,255,0,144,132,167,185,166,
4,129,197,255,0,207,174,54,242,2,160,0,0,0,0,0,9,171,135,225,196,13,52,188,70,113,189,120,1,232,118,238,158,39,130,132,21,166,141,38,228,153,48,209,75,87,67,203,242,254,8,184,93,52,211,92,182,182,240,
2,206,151,109,249,228,95,196,145,42,203,207,153,32,145,42,233,121,192,141,118,13,86,22,113,192,65,46,108,171,173,54,243,5,241,113,195,53,171,89,182,112,190,25,6,75,37,15,56,254,56,154,70,30,245,84,120,
237,224,6,43,174,62,225,21,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,104,161,79,61,144,26,187,81,186,39,25,245,250,34,233,
186,159,231,212,168,239,135,168,29,234,134,158,159,66,105,122,70,165,45,181,135,192,104,219,134,225,20,100,239,90,82,198,120,126,148,16,96,181,103,43,124,21,21,0,0,0,4,181,185,176,19,59,192,0,0,0,0,0,
0,0,234,182,141,251,159,224,13,93,187,195,83,149,193,129,186,157,196,229,120,133,104,173,210,91,183,147,91,56,133,235,185,88,174,63,19,239,230,21,118,186,187,38,235,235,238,67,167,106,234,109,141,185,
3,73,87,171,171,195,75,144,163,89,75,181,98,184,229,232,13,101,203,181,117,172,79,137,77,101,85,180,234,190,55,174,91,130,178,56,140,86,60,67,57,102,239,85,66,192,48,243,239,88,109,112,123,124,149,25,
128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,82,150,144,23,129,171,183,51,133,143,209,23,13,85,111,78,55,166,81,96,68,203,231,
224,7,51,253,176,42,181,222,151,180,133,241,150,247,113,195,109,192,134,112,138,239,94,43,215,111,0,43,0,0,0,0,0,0,0,0,0,0,0,0,117,91,70,30,239,128,53,83,184,235,229,180,1,175,183,221,113,159,159,64,173,
42,205,165,159,162,11,87,118,218,147,244,219,128,209,181,149,238,219,85,176,167,217,133,118,187,150,210,247,122,255,0,96,237,219,189,180,215,8,131,167,123,107,88,225,252,248,149,117,78,38,206,215,112,
137,35,53,181,105,120,227,248,43,62,40,178,109,68,20,96,239,85,206,237,217,219,32,212,49,221,113,231,188,35,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,119,77,254,128,90,177,144,53,82,115,213,28,118,242,34,174,171,113,41,249,173,185,14,141,91,183,103,11,249,249,2,45,119,170,37,122,103,232,10,173,220,106,122,188,38,103,234,0,
162,221,204,52,155,115,182,242,155,84,219,123,194,32,8,109,45,254,223,64,80,0,0,0,0,0,0,0,0,0,0,0,0,1,213,108,215,151,47,224,11,171,108,97,227,111,96,97,162,189,215,11,170,35,152,210,180,174,228,181,153,
33,75,43,220,203,204,71,47,236,190,158,44,86,113,135,143,7,128,142,181,218,23,86,237,183,60,19,74,187,85,157,151,82,127,134,69,74,118,155,117,71,140,129,83,79,67,234,156,254,203,98,182,156,44,239,253,
21,25,123,181,110,223,206,220,192,193,106,239,94,223,160,140,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,148,225,166,5,224,91,
70,189,120,249,5,218,196,235,165,185,105,255,0,94,4,94,145,107,86,19,151,230,246,146,166,127,138,157,229,202,252,255,0,0,218,183,101,197,132,112,239,201,123,129,206,187,121,109,226,4,75,230,253,192,128,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,181,184,11,21,249,175,96,59,87,83,134,7,75,184,243,13,61,188,2,237,117,123,177,190,126,80,26,107,221,171,75,59,124,16,94,172,155,89,246,222,84,237,101,90,151,59,154,245,38,
148,154,233,105,111,254,133,142,92,66,141,252,74,42,186,79,126,203,159,153,12,127,198,14,229,82,109,174,121,41,150,91,168,115,207,228,35,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,89,71,195,216,11,55,1,222,188,68,47,215,176,28,55,32,85,107,190,27,185,241,3,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,37,89,174,62,140,11,169,
126,91,249,1,183,183,221,150,177,224,194,181,86,211,195,220,29,187,196,110,207,48,80,218,133,143,176,57,8,203,220,170,155,99,111,180,77,171,13,148,166,189,138,138,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,78,28,129,122,114,164,9,0,7,14,137,248,48,43,117,107,127,184,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,118,80,26,123,
119,136,107,215,108,129,191,181,102,219,252,249,112,246,34,180,38,227,207,121,71,78,98,179,232,65,22,153,201,112,42,178,182,125,189,55,175,98,30,48,119,42,247,242,198,222,76,168,203,117,14,121,252,129,
192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,163,225,236,5,128,0,0,2,139,36,155,72,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,3,186,60,199,63,144,54,246,91,207,84,127,4,86,234,185,91,228,163,188,194,207,135,144,18,211,152,110,89,7,13,127,13,21,25,123,148,195,206,223,104,138,195,106,225,174,43,111,201,81,64,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,195,144,47,78,84,129,32,67,105,111,2,183,118,247,99,228,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,41,195,79,196,13,125,183,213,15,115,219,224,13,253,182,180,239,254,121,63,129,194,248,180,35,168,172,239,193,37,92,184,156,110,42,41,189,84,126,61,119,242,34,250,195,220,170,80,215,145,112,101,150,
234,31,158,204,35,144,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,117,91,70,30,239,128,58,119,228,189,192,172,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,209,71,254,95,151,228,13,221,171,40,221,179,225,238,70,154,86,228,86,93,202,153,211,142,68,87,47,123,224,84,115,109,204,101,113,44,157,196,163,119,63,191,82,12,118,172,202,
123,215,201,81,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,74,173,240,247,3,175,249,248,254,0,157,11,199,
241,252,1,31,243,241,252,1,203,171,92,61,128,228,0,0,0,0,0,0,0,0,0,0,0,186,191,229,109,196,13,157,187,54,179,17,252,238,227,204,141,70,163,150,196,219,73,251,132,116,156,57,42,13,207,168,16,230,49,188,
24,237,79,113,56,94,235,207,138,34,177,119,42,211,220,84,102,186,135,60,254,64,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,39,
75,124,30,223,32,64,0,0,0,0,0,0,0,22,214,145,151,151,203,128,22,42,183,187,220,11,87,107,41,55,232,241,252,176,174,215,103,47,195,118,245,251,36,154,115,255,0,28,120,206,220,202,126,57,125,166,184,237,
242,17,77,169,205,71,143,222,230,5,78,141,120,160,57,3,181,70,214,92,122,1,203,77,111,2,0,0,0,0,0,0,0,91,71,134,185,63,144,47,165,184,1,174,182,105,87,171,243,191,236,138,190,101,239,244,254,0,232,168,
135,187,1,92,93,97,120,1,151,187,87,45,76,227,241,244,200,185,196,50,90,178,154,123,255,0,101,101,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
45,173,18,223,151,240,4,90,188,87,176,21,128,0,0,0,0,8,11,29,249,123,176,43,0,0,0,0,0,0,1,101,23,31,96,46,173,103,200,13,53,162,105,17,90,87,110,171,111,150,12,186,210,185,23,65,165,71,245,35,71,104,125,
186,190,27,122,132,85,110,202,149,183,62,97,121,103,183,103,46,49,183,32,105,67,237,113,137,242,253,132,117,161,248,126,127,128,57,181,90,195,91,124,131,74,93,57,123,1,192,0,0,0,0,0,4,213,195,159,127,
32,47,241,2,202,221,97,60,124,1,122,186,148,167,122,227,158,123,154,37,181,206,54,186,151,82,242,17,98,210,211,207,242,13,231,57,26,80,165,249,2,84,222,170,115,192,167,140,151,170,77,181,207,250,96,203,
53,215,31,112,142,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,119,69,199,150,239,48,45,0,5,87,80,231,131,249,3,128,0,0,0,0,0,0,0,0,0,0,0,1,101,165,
205,129,160,13,29,180,154,136,240,253,191,114,109,173,105,182,181,73,44,112,252,112,42,44,174,245,137,25,22,86,169,187,77,91,248,253,17,93,42,173,47,165,109,227,0,161,209,105,93,57,243,121,36,142,109,
78,172,85,165,27,110,46,205,97,83,174,94,63,18,84,114,233,87,190,160,151,47,183,95,253,86,222,140,14,95,105,54,154,75,111,114,10,45,217,203,196,121,126,248,1,154,221,167,197,76,120,103,37,52,169,246,252,
215,192,71,63,243,124,26,248,254,64,141,22,243,219,196,8,211,101,193,252,252,1,0,0,1,213,108,215,138,3,189,117,242,219,192,14,149,151,7,31,128,45,165,225,229,44,237,144,173,52,188,175,30,15,244,69,104,
148,210,199,208,76,34,203,43,18,248,248,131,31,214,107,213,102,22,30,205,123,3,150,70,184,115,42,102,25,218,135,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,5,233,66,72,9,0,4,53,41,160,40,0,0,0,0,0,0,0,0,0,0,0,0,117,95,244,128,184,13,157,185,140,173,176,22,41,173,112,5,180,87,83,178,194,207,232,202,175,170,179,181,176,188,70,7,105,91,67,90,83,42,
165,171,69,122,87,9,194,8,58,219,82,198,35,249,241,11,188,56,211,105,182,16,71,26,45,165,244,227,205,124,73,14,156,91,183,104,172,164,185,98,63,56,3,155,118,237,169,99,135,159,217,77,43,116,180,188,110,
27,77,43,116,148,241,183,144,129,85,187,83,27,126,121,2,21,91,177,201,45,188,119,201,69,79,178,229,225,226,119,126,230,64,165,210,201,76,3,48,174,213,79,207,152,69,32,0,0,0,7,85,179,77,46,15,0,108,237,
217,195,94,95,202,11,134,234,187,70,22,49,4,61,119,153,240,41,26,237,93,147,203,141,185,144,241,142,244,109,76,101,50,140,183,82,167,138,248,8,168,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,88,200,26,0,0,0,5,87,89,158,127,32,112,0,0,0,0,0,0,0,0,0,0,0,0,182,142,86,120,1,179,180,241,191,211,240,69,110,89,75,201,21,26,104,158,165,213,193,252,255,0,4,105,
166,137,245,117,16,88,147,85,137,207,49,73,100,56,93,95,96,76,61,75,56,228,82,136,115,108,239,252,3,110,116,244,198,167,231,36,165,220,161,209,194,74,252,138,109,14,143,82,206,54,144,110,220,255,0,205,
205,186,189,200,42,125,167,165,231,30,25,249,2,187,118,156,87,59,124,20,211,135,218,105,196,175,129,180,210,183,92,181,203,120,20,95,183,210,224,163,31,114,154,115,239,183,48,140,183,89,158,96,112,0,0,
0,0,107,237,239,126,65,112,244,40,158,149,158,88,219,137,14,57,90,148,184,42,13,64,20,94,143,78,255,0,96,172,87,163,174,121,239,8,203,101,15,195,128,28,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,38,95,55,238,7,85,183,7,239,252,129,104,0,57,178,154,191,12,237,232,5,32,0,0,0,7,85,105,76,237,253,129,13,203,144,32,0,0,0,0,0,2,106,225,252,129,170,142,
28,61,204,46,30,135,110,201,165,156,255,0,60,61,200,120,213,77,58,150,219,247,240,224,37,112,213,77,51,108,178,11,86,157,59,240,35,93,147,180,181,88,89,199,1,9,35,85,212,185,150,62,2,85,151,207,137,32,
145,42,233,121,192,141,118,13,86,22,113,192,65,35,211,169,103,34,62,19,162,43,47,242,32,151,58,41,165,195,132,90,237,119,151,54,165,116,215,51,236,67,215,54,165,53,36,155,242,127,208,94,103,42,95,110,
147,109,189,130,105,157,213,70,254,62,254,69,78,37,147,189,219,81,57,6,222,119,115,10,60,127,146,162,160,0,0,0,89,105,115,96,109,237,169,159,77,191,33,112,244,106,176,182,222,5,170,181,118,74,112,73,52,
105,82,243,187,209,141,154,86,212,162,156,75,47,123,182,163,142,223,178,45,48,222,187,215,21,187,111,18,178,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,4,171,53,196,11,43,116,240,240,255,0,0,118,5,110,153,196,1,14,144,166,64,224,0,0,0,0,0,0,0,0,0,0,0,182,142,87,138,248,3,127,106,235,167,27,126,2,182,213,164,211,137,95,40,100,195,87,110,245,155,
116,249,249,115,50,171,233,101,165,227,28,185,131,183,109,168,175,79,208,19,141,75,25,141,229,74,66,137,182,62,200,9,173,47,24,228,40,177,181,21,233,250,10,156,106,88,245,42,82,20,77,177,246,64,77,105,
120,199,33,69,141,168,175,79,208,6,150,165,53,204,111,41,58,86,213,102,201,215,201,193,22,89,172,150,135,210,231,154,95,146,153,101,189,101,68,21,30,127,123,181,213,187,127,13,217,8,207,162,188,190,64,
226,213,140,173,192,112,0,14,168,165,207,45,144,30,135,97,40,221,199,111,192,93,55,46,24,3,74,85,212,186,113,24,70,122,84,165,89,183,79,209,69,86,170,210,241,158,12,96,81,117,43,116,237,146,166,24,59,
213,206,20,123,110,241,220,6,59,168,115,193,252,132,112,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,117,188,97,229,124,1,98,105,238,96,113,119,136,
227,196,10,192,0,0,0,0,0,0,0,0,0,0,9,78,28,129,166,150,106,35,115,141,225,112,244,123,119,110,55,115,33,13,125,187,218,92,70,230,56,92,52,210,214,208,241,199,31,143,128,115,43,166,209,87,25,226,18,19,
153,88,192,12,203,194,240,22,66,19,182,157,217,21,208,77,162,184,207,16,67,172,206,236,9,217,26,66,213,47,24,224,8,66,118,211,187,34,186,19,213,11,10,120,130,12,202,198,0,117,77,191,0,133,45,95,67,198,
103,30,43,30,33,175,214,110,229,109,21,199,63,232,97,50,205,122,57,202,202,8,193,220,163,206,55,114,95,130,163,53,255,0,203,244,249,64,82,1,41,112,6,174,215,110,112,179,25,126,47,212,15,75,183,93,53,252,
145,90,235,91,69,112,163,108,19,42,212,149,181,169,75,113,85,61,115,105,174,2,66,167,91,104,120,196,251,3,44,253,202,218,20,172,12,38,89,59,180,111,135,135,174,224,97,231,119,41,13,167,137,220,84,102,
106,28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,186,91,135,176,27,59,87,114,148,237,63,96,111,165,155,156,241,224,
21,166,150,122,95,87,31,98,90,211,82,111,77,122,179,137,92,200,45,206,175,245,232,84,161,39,47,63,64,66,79,75,207,169,40,178,28,46,175,176,38,28,172,227,145,74,18,114,243,244,4,36,244,188,250,146,139,
33,194,234,251,2,97,234,89,199,34,148,36,229,231,232,14,97,186,181,171,60,201,75,106,187,148,122,83,213,202,127,144,114,205,220,163,213,190,118,222,94,19,76,125,202,55,169,202,219,240,8,121,125,196,214,
18,111,60,63,5,69,106,141,248,121,255,0,0,104,237,246,165,165,186,120,189,236,13,253,174,214,159,210,254,72,173,116,163,105,185,132,50,97,169,81,233,175,87,40,10,191,75,212,158,160,155,74,78,94,126,128,
173,213,233,125,91,253,133,46,255,0,213,61,202,56,175,87,151,237,1,150,245,135,13,207,140,240,220,57,76,176,119,187,111,57,241,227,238,84,96,189,120,250,48,43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,238,180,156,189,220,0,234,201,105,120,91,48,42,0,0,0,0,0,0,0,2,234,91,221,1,183,179,220,92,227,158,220,136,184,108,173,147,82,178,81,
162,182,172,87,49,149,233,244,69,106,78,186,147,159,78,31,1,86,45,50,225,249,146,25,145,42,233,121,192,141,118,13,86,22,113,192,65,41,105,106,92,196,124,39,72,74,178,243,230,32,145,42,233,121,192,141,
118,13,86,22,113,192,65,41,138,234,92,196,124,41,9,86,95,62,34,9,18,174,151,156,8,215,99,155,86,173,44,249,120,136,92,111,106,111,74,106,89,250,127,193,78,89,111,69,54,91,208,218,105,142,255,0,252,245,
114,214,222,200,160,191,249,171,140,144,93,78,221,83,80,6,154,118,234,219,151,133,187,110,44,109,116,190,148,162,166,118,220,23,241,118,154,165,89,126,68,73,219,182,150,165,204,71,196,157,33,42,203,207,
152,130,72,174,151,156,8,215,100,237,93,235,72,170,151,225,180,5,231,150,110,229,107,171,123,251,246,30,25,100,189,19,76,169,183,155,122,199,147,148,202,103,150,86,161,192,68,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,150,151,54,6,128,57,191,249,126,159,40,10,64,0,0,0,0,0,0,0,110,202,2,250,95,138,222,183,129,183,181,221,73,122,145,105,
177,60,39,142,127,76,163,85,59,149,118,93,60,54,146,42,250,222,173,217,233,243,254,8,114,237,52,233,41,99,144,45,45,168,175,79,208,18,218,212,177,234,88,74,66,137,182,62,200,9,173,47,24,228,40,177,181,
21,233,250,10,54,181,37,30,165,74,20,77,177,246,64,77,105,120,199,33,69,141,168,175,79,208,84,52,181,46,156,243,41,133,78,181,110,203,79,163,253,1,71,252,235,31,229,251,125,131,67,237,214,23,75,243,135,
153,245,36,154,88,169,85,101,209,24,240,248,2,218,170,205,186,103,197,175,128,59,174,149,87,143,192,162,118,150,212,87,167,232,9,109,106,88,245,44,37,33,68,219,31,100,4,214,151,140,114,20,90,45,14,181,
233,242,198,224,184,229,85,244,187,127,158,27,48,122,197,117,213,108,53,146,166,152,187,213,80,241,199,135,244,7,159,122,241,226,190,10,138,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,26,0,230,255,0,229,250,124,160,41,0,0,0,0,0,0,0,0,4,166,211,148,5,244,191,21,234,128,219,219,239,56,75,17,187,201,145,121,109,173,154,105,242,231,200,
13,61,187,218,109,186,127,142,12,44,46,165,173,165,184,227,252,120,131,245,100,218,43,11,204,36,58,204,238,192,157,145,164,45,82,241,142,0,132,39,109,59,178,43,161,61,80,176,167,136,32,204,172,96,2,213,
47,24,224,8,22,173,59,178,74,232,132,61,80,185,241,41,9,204,172,96,2,153,120,199,0,34,30,151,140,251,146,126,46,229,13,90,43,249,41,110,179,169,99,17,188,78,210,142,169,120,242,22,66,19,182,157,217,21,
208,77,162,184,207,16,67,172,206,236,9,217,26,66,213,47,24,224,8,66,118,211,187,34,186,19,213,11,10,120,130,28,219,86,165,9,67,81,242,23,28,51,93,90,111,133,141,147,32,197,122,202,106,54,226,105,30,119,
118,145,152,223,143,63,16,140,109,67,128,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,234,181,157,251,151,228,8,123,223,155,2,0,0,0,0,0,0,0,0,0,0,0,0,23,215,114,242,
0,212,166,128,160,14,213,27,223,128,56,106,28,48,0,0,0,0,0,0,0,37,54,156,160,47,173,248,167,28,194,226,27,187,93,198,218,206,31,224,156,13,117,179,79,14,39,30,0,245,163,183,103,167,253,109,200,46,26,84,
233,171,213,202,72,44,135,43,56,228,84,161,39,47,63,64,66,79,78,252,243,37,22,67,133,213,246,4,195,149,156,114,41,66,78,94,126,128,132,158,157,249,230,74,44,135,11,171,236,9,135,43,56,228,82,132,156,188,
253,1,16,244,239,207,50,81,100,56,93,95,96,76,57,89,199,34,148,36,229,231,232,8,73,233,121,245,37,22,67,133,213,246,4,195,149,156,114,41,66,78,94,126,128,132,158,157,249,230,74,44,135,11,171,236,3,77,
189,248,41,140,170,117,109,217,234,243,242,13,49,90,173,41,110,118,254,2,101,143,191,70,210,206,222,252,194,60,222,229,125,215,193,81,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,37,46,0,189,40,80,128,166,219,223,155,2,0,0,0,0,0,0,0,0,0,0,0,0,23,83,252,175,80,58,2,33,111,133,32,72,21,95,122,126,0,112,0,0,0,0,0,0,0,4,166,211,148,5,244,191,21,195,122,3,119,107,184,185,
146,218,231,13,117,178,135,151,183,236,114,156,52,171,86,43,156,227,215,250,34,237,165,58,234,89,153,88,41,58,237,210,85,151,207,137,33,36,74,186,94,112,35,93,131,85,133,156,112,16,74,113,169,103,34,62,
20,132,171,47,159,17,4,137,87,75,206,4,107,176,106,176,179,142,2,9,78,53,44,228,71,194,144,149,101,243,226,32,145,42,233,121,192,141,118,13,86,22,113,192,65,41,198,165,156,136,248,82,18,172,190,124,68,
18,37,93,47,56,17,174,193,170,194,206,56,8,37,56,212,179,145,31,9,210,18,172,190,124,68,18,37,93,47,56,17,174,193,170,194,206,56,8,37,56,212,179,145,31,10,112,213,101,185,223,188,44,178,222,181,210,243,
199,241,56,101,52,201,116,154,219,216,35,206,238,213,43,99,215,104,40,198,212,54,130,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,59,162,222,253,0,180,12,224,0,0,0,0,0,
0,0,0,0,0,0,0,22,118,247,53,227,243,253,1,96,0,0,87,117,132,249,126,192,172,0,0,0,0,0,0,0,0,18,156,57,3,69,47,25,91,158,240,55,118,187,170,56,145,166,186,219,21,199,143,184,70,186,222,186,151,79,183,201,
54,171,171,100,221,148,110,252,160,103,14,147,90,94,49,200,81,99,106,43,211,244,1,198,165,211,158,101,74,20,77,177,246,64,77,105,120,199,33,69,141,168,175,79,208,81,198,165,211,158,101,74,20,77,177,246,
64,77,105,120,199,33,69,141,168,175,79,208,81,198,165,211,158,101,74,20,77,177,246,64,77,105,120,199,33,69,141,168,175,79,208,81,181,169,99,60,202,148,40,155,99,236,128,154,210,241,142,66,150,198,212,
87,167,232,3,141,75,167,60,202,148,98,109,211,231,226,65,69,180,186,62,159,13,188,138,211,37,210,198,35,152,195,44,29,250,103,116,74,41,79,63,184,184,242,195,8,172,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,47,74,18,64,69,177,87,229,243,128,41,0,0,0,0,0,0,0,0,0,0,0,0,0,238,143,62,104,11,64,111,194,2,90,107,120,28,181,41,160,40,135,49,196,11,107,88,223,151,240,5,118,80,
216,16,0,0,23,87,252,175,95,144,56,181,99,43,112,28,0,0,4,166,211,3,69,46,214,83,195,11,135,161,219,187,105,110,252,127,64,108,165,237,169,110,219,129,50,97,174,150,179,118,81,228,23,158,86,85,217,214,
99,35,241,51,173,186,234,133,133,60,65,6,101,99,0,22,169,120,199,0,64,181,105,221,146,87,68,15,84,40,94,101,162,12,202,198,0,45,82,241,142,0,131,170,30,50,74,232,132,77,162,184,207,18,144,156,202,198,
0,102,94,23,128,178,16,157,180,238,200,174,130,109,21,198,120,130,29,102,119,96,78,200,210,22,169,120,199,0,66,19,182,157,217,21,208,158,168,88,83,196,16,102,86,48,1,106,151,140,112,4,56,122,180,60,111,
11,250,201,221,86,211,89,75,237,125,1,143,185,87,202,99,246,17,230,247,43,150,154,137,42,50,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,106,165,175,48,47,2,187,189,203,
212,10,192,0,0,0,0,0,0,0,0,0,0,0,0,11,25,3,64,29,83,120,200,181,169,242,228,45,85,186,53,187,63,33,28,70,119,103,242,0,10,175,191,211,246,192,224,0,0,37,54,183,54,7,74,239,142,80,16,210,222,183,63,195,
228,7,32,0,1,53,112,252,56,129,171,183,120,140,227,124,129,233,82,243,25,204,122,133,106,237,89,183,110,168,194,34,181,81,183,86,245,113,254,2,244,179,49,94,174,89,230,70,83,153,89,244,250,44,148,36,229,
231,232,8,73,233,223,158,100,162,200,112,186,190,192,156,202,207,13,197,146,132,156,188,253,1,9,61,59,243,204,148,89,14,23,87,216,19,157,75,62,133,146,132,156,188,253,1,9,61,59,243,204,148,89,14,23,87,
216,19,153,89,196,110,44,148,36,229,231,232,8,73,233,223,158,100,162,200,112,186,190,192,156,202,207,167,209,100,161,39,47,63,64,114,211,208,250,179,190,73,75,106,59,181,122,107,213,227,234,6,75,214,44,
212,251,23,148,203,204,239,85,166,219,224,254,138,49,93,69,188,243,183,168,71,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,119,77,237,248,1,104,20,217,205,159,134,54,245,3,
144,0,0,0,0,0,0,0,0,0,0,0,0,0,22,209,202,142,91,32,44,172,74,157,193,112,189,36,236,165,240,4,235,73,85,172,188,180,69,229,195,173,99,62,229,73,202,166,161,132,83,220,222,159,135,199,246,7,0,0,0,0,1,56,
159,16,0,0,0,3,170,218,49,193,254,0,219,218,188,89,75,123,126,194,189,10,90,175,62,4,56,107,237,186,105,121,127,88,248,34,225,165,104,211,85,62,64,151,77,87,82,230,88,248,130,85,151,159,50,65,34,85,210,
243,129,26,236,26,172,44,227,128,130,70,171,169,115,44,124,4,171,47,159,18,65,34,85,210,243,129,26,236,26,172,44,227,128,130,70,171,169,115,44,124,4,171,47,159,18,65,34,85,210,243,129,26,236,26,172,44,
227,128,130,71,167,82,206,68,124,39,66,85,151,207,136,130,68,171,165,231,2,53,216,53,88,89,199,1,4,141,87,82,230,88,248,9,86,94,124,201,4,145,93,47,56,17,174,201,218,155,170,233,174,119,48,190,178,247,
82,86,195,219,122,46,19,56,96,239,85,103,197,127,96,121,189,197,185,250,21,21,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,103,111,139,219,108,129,219,112,155,2,128,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,58,163,135,231,143,224,11,128,190,173,77,92,76,250,250,123,147,43,133,137,169,183,78,223,160,168,198,150,160,29,210,155,172,39,203,224,172,168,186,194,124,159,200,21,36,222,16,29,
58,180,167,220,14,64,0,0,0,0,0,0,0,182,150,225,197,110,3,208,236,119,19,196,125,122,145,105,186,151,73,110,158,51,250,10,215,91,173,53,233,120,202,112,65,124,167,101,143,82,166,133,19,108,125,144,19,90,
94,49,200,81,99,106,43,211,244,20,113,169,116,231,153,82,133,19,108,125,144,19,90,94,49,200,81,99,106,43,211,244,20,113,169,116,231,153,82,133,19,108,125,144,19,90,94,49,200,81,99,106,43,211,244,20,109,
106,88,207,50,165,9,169,182,60,252,72,9,173,47,24,228,40,177,181,21,233,250,10,56,212,186,115,204,169,66,137,182,62,200,9,173,47,24,228,40,183,23,211,166,189,59,194,225,151,187,26,151,79,15,45,219,202,
101,139,185,16,229,78,54,248,8,243,59,139,253,112,227,251,42,51,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,101,55,53,227,183,192,17,119,195,150,240,56,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,5,213,114,188,120,237,226,5,180,110,99,215,250,3,69,93,155,109,34,47,166,116,188,99,250,42,254,185,178,109,44,112,135,229,238,68,211,61,171,27,214,25,81,202,73,110,64,69,255,0,203,244,249,
64,82,0,0,0,0,0,0,0,3,118,80,26,251,87,134,154,227,243,253,129,233,118,237,53,252,5,109,165,237,166,184,226,101,101,173,59,106,134,148,68,237,146,201,172,105,50,229,227,203,196,36,9,218,55,100,149,209,
27,27,180,44,121,150,136,78,101,114,19,178,52,133,50,241,142,0,130,109,15,25,37,116,70,201,180,44,121,148,132,230,87,33,59,35,72,204,188,40,224,44,130,92,76,103,145,43,162,16,221,161,66,243,41,14,179,
62,2,118,70,144,155,151,140,112,4,19,109,47,25,37,116,70,206,168,88,83,196,164,39,50,185,9,217,26,68,185,120,242,241,4,9,218,55,100,149,209,27,115,125,80,161,113,201,105,112,163,187,171,86,237,159,216,
179,198,27,207,87,60,207,236,169,111,47,184,156,231,203,249,249,6,89,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,37,54,183,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,213,92,63,14,
32,92,5,244,111,124,196,254,9,107,181,137,61,47,60,66,254,141,56,175,86,223,64,69,169,213,18,183,110,231,180,4,141,40,181,35,43,219,145,81,85,191,203,219,136,20,196,238,2,90,107,122,2,0,0,0,0,0,0,0,119,
71,152,231,243,253,1,232,246,44,227,127,30,63,176,187,111,171,120,234,140,238,219,153,12,55,86,117,46,169,143,128,171,82,114,243,244,17,9,61,59,243,204,148,89,14,23,87,216,19,15,82,206,57,20,161,39,47,
63,64,66,79,78,252,243,37,22,67,133,213,246,4,195,212,179,142,69,40,73,203,207,208,16,147,211,191,60,201,69,144,225,117,125,129,48,229,103,28,138,80,147,151,159,160,33,39,165,231,212,148,89,14,23,87,216,
19,15,82,206,57,20,161,39,47,63,64,66,79,78,252,243,37,22,139,38,234,186,189,121,133,199,42,187,137,234,93,92,62,50,50,114,195,117,213,100,249,191,201,170,101,230,119,150,103,199,231,32,98,183,250,126,
127,57,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,41,110,15,211,111,0,46,171,135,224,192,189,105,117,223,159,235,192,53,214,120,91,93,
49,27,252,30,220,200,136,116,83,41,184,2,182,171,213,159,126,33,121,81,101,25,89,69,101,200,28,95,252,249,191,191,208,21,0,0,0,0,0,0,0,1,175,181,108,174,79,62,161,112,244,232,211,72,22,221,77,58,171,151,
237,236,101,127,90,43,167,170,31,52,243,192,65,157,165,42,233,121,192,141,118,131,85,133,156,112,16,72,213,117,46,101,143,128,149,101,231,204,144,72,149,116,188,224,70,187,6,171,11,56,224,32,145,170,234,
92,203,31,1,42,203,231,196,144,72,149,116,188,224,70,187,6,171,11,56,224,32,145,233,212,179,145,31,9,208,149,101,231,204,65,34,85,210,243,129,26,236,26,172,44,227,128,133,145,170,234,92,203,31,16,74,178,
243,230,72,36,74,186,94,112,35,93,136,178,174,157,248,140,8,91,83,220,85,212,178,247,50,158,242,197,104,212,227,116,138,76,188,238,242,223,28,45,248,132,145,112,48,223,253,63,79,132,17,200,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,221,148,5,233,202,144,45,173,177,15,135,231,250,11,142,87,171,40,171,75,236,138,186,84,204,99,144,253,75,113,
100,147,110,55,240,2,134,148,110,199,20,83,149,1,21,247,30,229,234,5,96,0,0,0,0,0,0,0,91,219,127,135,248,3,212,237,89,58,165,16,69,111,237,217,106,93,60,62,55,12,174,26,232,211,118,133,28,119,126,1,151,
73,173,47,24,228,74,75,27,81,94,159,160,169,198,165,140,198,242,165,33,68,219,31,100,4,214,151,140,114,20,88,218,138,244,253,5,78,53,44,102,55,149,41,10,38,216,251,32,38,180,188,99,144,162,198,212,87,
167,232,42,113,169,99,212,169,72,81,54,199,217,1,53,165,227,28,133,22,54,162,189,63,64,78,53,44,102,55,148,164,40,155,99,236,128,154,210,241,142,66,139,69,154,210,186,127,27,130,218,174,227,90,151,79,
6,15,214,43,255,0,167,136,201,105,30,119,121,174,174,25,254,11,131,44,23,255,0,79,211,225,4,114,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,154,184,126,28,64,189,61,205,1,125,110,218,199,60,175,216,92,46,86,178,178,198,220,200,121,195,166,222,99,126,204,10,156,232,120,156,255,0,5,241,125,229,158,211,57,227,31,1,149,23,222,188,128,224,
0,0,0,0,0,0,0,14,169,254,188,215,223,232,15,71,177,103,9,122,126,146,222,21,233,118,172,245,47,111,77,223,178,103,250,97,182,142,211,108,44,5,207,107,22,173,59,178,74,233,32,122,161,66,243,45,16,102,86,
48,1,76,188,99,128,32,234,135,140,146,186,33,19,104,174,51,196,164,39,50,177,128,25,151,133,224,44,132,39,109,59,178,43,160,155,69,113,158,32,135,89,157,216,19,178,52,133,170,94,49,192,16,132,237,167,
118,69,116,39,170,22,20,241,4,25,149,140,0,90,165,227,28,1,2,213,167,118,73,93,16,139,59,105,88,243,45,24,229,79,113,219,82,194,255,0,47,243,35,43,231,12,87,151,107,78,249,45,35,204,239,114,241,253,125,
1,138,255,0,233,250,124,32,142,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,59,173,163,15,119,192,22,166,214,224,52,85,204,57,133,240,
21,98,78,109,213,183,234,8,174,97,233,121,219,1,61,103,190,245,228,191,101,69,87,221,235,128,42,0,0,0,0,0,0,0,0,176,211,241,3,119,101,231,213,126,113,248,11,135,169,79,244,179,30,35,60,24,109,237,203,
118,234,228,204,170,229,58,119,250,138,75,33,194,234,251,2,97,234,89,199,34,148,36,229,231,232,8,73,233,223,158,100,162,198,156,46,175,94,96,76,61,75,56,228,82,132,156,188,253,1,9,61,47,62,164,162,200,
112,186,190,192,152,114,179,142,69,40,73,203,207,208,16,147,210,243,234,74,44,135,11,171,236,9,135,169,103,28,138,80,147,151,159,160,33,39,165,231,212,148,91,155,167,165,45,95,101,92,114,167,185,58,151,
87,135,150,204,131,21,167,169,206,115,159,19,72,243,59,175,59,230,91,250,8,199,109,239,204,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,1,101,45,193,250,127,0,91,87,13,114,3,69,93,101,167,36,84,61,58,119,241,219,212,47,17,133,55,222,188,151,236,172,170,181,103,43,127,200,21,0,0,0,0,0,0,0,0,3,95,105,229,55,224,253,121,5,195,213,164,116,
206,236,4,108,237,105,151,47,154,50,210,250,105,208,212,227,111,2,193,158,93,53,88,89,199,2,65,41,138,234,92,196,124,74,66,85,151,207,136,130,68,171,165,231,2,53,216,53,88,89,199,1,4,166,43,169,115,17,
240,164,37,89,124,248,136,36,74,186,94,112,35,93,131,85,133,156,112,16,74,90,90,151,49,31,9,210,18,172,188,249,136,36,74,186,94,112,35,93,131,85,133,156,112,16,74,98,186,151,49,31,10,66,85,151,207,136,
130,68,171,165,231,2,53,216,174,250,33,103,8,46,25,187,154,53,111,225,242,12,178,93,164,158,118,223,250,42,60,203,181,45,174,11,111,193,76,178,132,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,186,174,82,96,93,75,45,207,223,159,128,29,74,137,140,18,150,118,170,206,94,57,65,81,0,113,122,202,158,43,242,5,64,0,0,0,0,0,0,58,166,255,0,64,
53,118,247,238,156,175,216,202,225,233,209,172,99,211,221,16,237,163,183,101,46,107,191,228,46,26,107,101,161,244,231,250,34,254,59,213,88,172,174,94,129,53,151,82,181,37,19,226,88,65,68,219,31,100,4,
214,151,140,114,20,88,218,138,244,253,5,37,106,221,158,101,74,20,77,177,246,64,77,105,120,199,33,69,141,168,175,79,208,84,182,181,44,122,150,18,144,162,109,143,178,2,107,75,198,57,10,44,109,69,122,126,
130,141,173,73,71,169,82,133,19,108,125,144,67,178,84,120,240,128,182,167,185,106,233,170,211,28,95,240,6,94,227,78,216,81,143,146,225,51,150,62,237,150,84,112,127,216,30,109,222,31,139,219,240,84,82,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,84,170,115,60,0,184,0,0,0,0,1,67,222,252,216,16,0,0,0,0,0,1,213,92,89,123,123,129,167,
182,218,120,219,105,11,135,163,75,55,191,205,252,19,130,23,210,205,55,25,149,159,31,177,147,25,91,94,229,180,191,63,82,46,214,255,0,210,218,107,187,215,249,7,110,245,219,90,194,244,201,118,117,73,87,180,
217,109,242,13,10,246,117,111,18,190,61,194,235,14,181,94,42,225,57,219,196,38,176,234,94,164,163,16,37,53,9,151,47,119,128,178,16,157,180,238,200,174,130,109,21,198,120,130,29,102,119,96,78,200,210,22,
169,120,199,0,66,19,182,157,217,21,208,158,168,88,83,196,16,102,86,48,4,75,155,98,99,112,21,187,223,75,148,166,118,226,23,95,198,126,229,237,11,11,207,155,6,89,175,102,220,188,237,251,99,132,229,231,247,
108,250,147,226,252,10,49,93,229,46,95,176,142,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,255,217,0,0};

const char* TabMainControl::basszero_background_jpg = (const char*) resource_TabMainControl_basszero_background_jpg;
const int TabMainControl::basszero_background_jpgSize = 14299;

// JUCER_RESOURCE: basszero_background_jpg2, 10853, "../basszero_background.jpg"
static const unsigned char resource_TabMainControl_basszero_background_jpg2[] = { 255,216,255,224,0,16,74,70,73,70,0,1,2,0,0,100,0,100,0,0,255,236,0,17,68,117,99,107,121,0,1,0,4,0,0,0,96,0,0,255,238,0,
38,65,100,111,98,101,0,100,192,0,0,0,1,3,0,21,4,3,6,10,13,0,0,14,121,0,0,14,157,0,0,26,254,0,0,42,99,255,219,0,132,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,2,2,2,1,2,2,2,2,2,2,2,
2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1,1,3,2,2,3,4,3,3,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,255,194,0,17,8,1,188,3,72,
3,1,17,0,2,17,1,3,17,1,255,196,0,157,0,1,0,3,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,9,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,5,16,0,3,0,2,3,0,3,1,1,0,0,0,0,0,0,0,0,1,17,48,96,16,32,64,80,112,192,128,18,
17,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,18,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,19,1,0,2,0,3,5,8,2,3,1,1,1,1,0,0,0,1,0,17,16,33,49,96,65,81,97,113,32,48,64,240,129,145,161,177,80,193,112,209,225,128,241,
144,160,255,218,0,12,3,1,0,2,17,3,17,0,0,1,243,175,169,197,0,0,0,0,0,0,0,0,0,0,0,0,0,107,27,214,241,117,181,128,10,203,89,48,211,8,198,180,141,235,162,46,182,176,0,0,164,185,167,57,133,84,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,88,222,58,13,22,246,0,5,102,169,51,142,152,198,52,54,141,235,105,110,77,128,0,33,105,24,217,207,24,208,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
3,104,232,173,165,189,74,0,43,45,99,59,50,170,70,85,66,198,241,185,170,222,192,0,2,178,230,156,245,132,82,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,227,122,222,52,106,247,32,10,203,83,
52,198,171,16,103,84,6,145,189,111,26,45,172,0,1,5,101,198,206,120,198,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,155,70,245,182,86,186,181,200,133,172,68,82,206,115,10,0,84,18,107,27,214,
217,94,219,88,0,2,178,209,57,235,8,206,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,120,222,183,139,203,54,130,65,84,173,102,103,24,213,64,0,22,54,141,235,92,219,85,172,0,1,73,114,78,115,10,
128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,155,70,213,172,90,89,168,147,58,206,171,16,65,82,149,64,0,0,185,180,109,90,230,218,173,96,0,86,90,39,61,97,25,208,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,11,155,70,213,166,82,65,77,57,227,26,16,72,32,128,0,0,26,70,166,213,174,109,170,108,144,8,90,198,54,115,198,53,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,109,26,86,165,162,
74,214,102,81,149,84,0,0,0,0,1,164,106,107,90,197,150,73,22,68,176,81,57,235,24,206,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,22,53,139,214,132,144,80,172,86,41,166,96,0,0,0,0,1,120,212,210,
174,94,45,44,209,69,102,114,211,8,198,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,198,177,106,177,5,98,165,74,212,16,0,0,0,0,0,2,197,226,197,139,214,145,120,144,103,88,214,17,74,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,105,26,10,136,202,170,0,0,0,0,0,0,0,0,144,94,52,54,173,114,146,181,149,99,24,212,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,172,90,41,89,212,0,0,0,0,0,0,
0,0,0,22,55,141,171,76,134,122,99,24,148,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,203,196,17,84,32,0,0,0,0,0,0,0,0,0,214,55,173,162,209,90,202,177,140,106,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,36,184,32,160,0,0,0,0,0,0,0,0,0,44,116,70,213,166,80,103,166,49,137,74,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,88,130,0,0,0,0,0,0,0,0,0,0,36,222,54,173,34,209,77,50,49,140,
170,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,73,36,2,0,0,0,0,4,155,70,181,161,104,173,84,202,49,170,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,210,44,72,32,161,74,
130,72,0,0,0,53,141,43,66,224,131,34,145,141,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,130,0,0,0,0,0,2,77,98,229,234,196,144,80,164,102,88,131,58,128,0,0,177,172,88,181,88,146,166,113,153,157,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,46,10,16,0,0,0,0,0,185,172,105,90,197,162,84,69,149,41,80,84,172,80,161,21,4,0,11,22,139,22,52,161,6,113,141,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,114,65,
82,160,0,0,0,0,11,154,198,213,174,86,186,148,154,136,128,65,9,82,149,82,177,82,166,85,0,0,105,27,86,164,25,153,70,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,98,192,25,128,0,0,0,0,36,218,54,173,178,189,
213,174,64,2,4,176,65,5,82,149,145,156,99,64,1,120,222,182,36,161,140,99,85,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,177,37,8,0,0,0,0,0,105,27,87,68,93,171,220,128,0,0,66,214,34,51,179,3,158,160,0,
94,58,107,104,180,86,177,172,99,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,65,0,0,0,0,0,9,54,141,235,108,219,212,216,0,0,0,43,45,99,29,76,34,133,42,1,180,116,214,185,179,105,51,76,43,8,165,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,120,220,220,209,111,96,0,0,0,21,150,137,141,99,24,212,23,142,138,232,139,181,55,49,45,76,172,194,48,168,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,214,55,173,162,235,123,0,0,0,0,172,180,78,122,231,139,27,86,209,162,222,192,43,45,19,10,194,50,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,32,0,0,0,147,104,218,182,139,173,172,0,0,0,2,
146,209,51,36,208,178,222,192,0,164,185,167,57,133,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,134,96,0,0,0,147,104,222,182,150,197,172,0,0,0,2,37,169,36,147,96,0,8,150,134,22,115,198,84,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,12,192,0,0,0,44,109,27,86,210,216,181,128,0,0,0,0,0,0,1,73,115,78,115,10,168,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,104,84,16,64,0,0,1,99,104,222,181,
205,181,90,192,0,0,0,0,0,0,4,45,35,11,57,227,42,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,128,0,0,0,0,0,185,36,149,40,0,0,0,11,27,70,245,172,182,45,96,0,0,0,0,0,0,2,146,230,156,231,61,64,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,2,229,0,0,0,0,0,2,229,226,98,181,157,64,0,0,0,44,109,27,214,178,222,165,0,0,0,0,0,0,0,133,164,115,217,207,25,208,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,88,21,0,0,0,0,0,11,26,68,192,207,72,32,128,
0,0,2,198,241,185,170,218,201,0,0,0,0,0,0,0,164,185,39,49,141,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,185,82,0,0,0,0,0,2,77,34,240,164,86,179,170,128,0,0,2,230,241,185,162,222,192,0,0,0,0,0,0,43,46,105,206,
115,213,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,202,0,0,0,0,0,0,23,53,201,160,70,102,116,0,0,0,6,177,189,116,75,122,148,0,0,0,0,0,0,16,180,142,123,57,227,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,38,
177,97,66,35,42,21,0,0,0,36,222,58,13,86,246,0,0,0,0,0,0,1,73,113,179,154,49,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,230,176,160,35,42,86,116,0,0,0,47,29,53,209,45,234,80,0,0,0,0,0,0,82,92,211,
152,231,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,77,98,194,164,130,35,58,130,160,0,0,36,222,58,77,86,214,0,0,0,0,0,0,10,203,154,115,28,245,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,99,88,
154,177,4,68,70,90,84,0,0,0,214,58,107,121,111,96,0,0,0,0,0,0,172,185,167,49,207,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,230,145,52,3,44,116,168,0,0,1,99,164,233,150,245,40,0,0,0,0,0,1,89,114,
78,115,158,160,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,210,52,20,25,101,165,0,0,0,9,58,35,168,186,218,192,0,0,0,0,0,10,75,146,115,156,244,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,210,
46,41,150,90,80,0,0,0,29,17,210,104,183,176,0,0,0,0,0,16,82,92,108,231,140,104,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,54,202,72,43,85,170,0,0,0,177,180,116,86,153,182,169,169,64,0,0,0,0,21,
150,137,207,88,70,116,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,203,19,2,180,51,0,0,1,38,209,181,105,22,137,89,161,36,212,160,0,0,5,101,169,154,115,152,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,73,98,8,4,0,0,0,18,107,23,171,22,4,150,137,44,89,68,128,0,32,136,165,152,214,49,149,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,161,104,16,64,44,88,189,92,180,73,36,130,1,
5,106,134,113,141,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,65,0,0,73,104,185,98,65,32,130,0,32,165,102,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,144,
1,32,128,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,139,194,168,84,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,72,32,2,224,130,8,0,0,88,188,90,38,162,51,210,128,146,0,0,18,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,146,74,128,73,112,65,5,139,229,36,17,80,64,4,146,76,
77,40,34,165,42,209,36,85,72,0,176,40,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36,184,32,128,88,190,82,66,144,9,160,136,10,65,34,148,0,8,136,146,2,197,149,160,5,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,185,32,0,11,64,152,0,72,4,0,9,2,128,1,2,1,21,4,84,16,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,32,0,72,0,0,0,0,0,73,48,0,1,80,8,32,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,255,218,0,8,1,1,0,1,5,2,248,68,44,44,124,33,99,122,122,16,176,190,136,88,216,244,212,44,79,162,225,99,99,210,208,133,129,178,
246,66,198,244,213,133,151,139,213,11,27,30,146,132,46,247,34,196,244,181,214,148,185,23,9,226,99,209,215,118,82,243,113,39,194,120,94,144,133,230,79,139,133,143,71,94,123,197,41,123,61,54,151,199,120,
165,47,86,61,38,250,111,9,244,122,75,245,174,239,99,66,232,246,68,46,207,104,123,42,236,245,9,214,101,90,196,226,16,132,39,19,194,244,213,130,16,132,33,8,78,244,186,146,225,98,132,33,48,174,175,78,89,
166,4,46,175,76,66,206,251,161,116,99,211,150,118,136,78,136,93,88,244,196,33,103,107,162,66,236,244,228,47,3,33,9,129,143,78,79,60,63,201,48,177,233,233,250,152,244,244,253,44,99,211,211,244,177,234,
9,250,24,245,20,253,12,127,30,254,9,63,59,30,138,241,161,11,204,198,61,17,228,66,243,177,232,179,34,23,153,143,64,94,20,47,51,30,143,49,161,121,88,244,135,137,11,204,244,135,137,11,202,199,169,175,43,
30,166,133,228,99,213,23,145,143,103,122,189,41,74,82,229,99,213,169,74,82,148,165,41,120,165,41,74,82,235,212,165,41,74,82,148,187,53,251,22,108,243,171,214,39,104,66,16,152,39,241,53,47,20,165,41,74,
82,148,165,41,74,82,148,165,230,253,33,255,218,0,8,1,2,0,1,5,2,252,223,31,255,218,0,8,1,3,0,1,5,2,252,223,31,255,218,0,8,1,2,2,6,63,2,55,199,255,218,0,8,1,3,2,6,63,2,55,199,255,218,0,8,1,1,1,6,63,2,55,
199,255,218,0,8,1,1,3,1,63,33,252,32,130,4,59,44,123,18,138,15,116,34,68,216,209,4,29,195,63,72,199,5,20,33,219,99,4,27,26,32,132,59,46,11,22,14,10,12,93,210,65,6,197,136,32,237,92,112,28,23,29,49,81,
65,238,28,4,77,139,8,33,216,188,86,41,105,120,47,176,162,131,14,219,18,8,54,36,96,29,155,151,24,88,199,182,53,6,40,48,123,129,19,98,72,33,141,199,21,110,11,29,59,133,7,0,101,246,152,193,6,195,136,66,26,
98,177,75,75,75,101,224,190,232,28,1,194,251,14,2,36,118,32,52,131,46,44,88,196,240,0,194,7,27,151,28,24,32,216,82,24,6,89,46,46,15,129,32,97,6,5,246,68,118,20,134,22,75,151,47,18,252,8,194,47,1,36,94,
41,128,108,40,226,177,240,235,150,194,71,0,112,96,142,194,144,124,105,84,24,56,177,131,97,70,92,124,98,138,24,48,71,97,76,87,197,234,192,96,198,48,108,45,203,241,134,176,132,49,17,217,42,101,74,123,242,
44,47,6,48,108,120,92,34,176,169,81,138,194,187,176,193,197,210,49,252,237,74,240,33,2,17,83,213,129,135,6,163,9,93,192,193,151,46,92,188,71,230,207,8,8,18,176,169,93,148,97,193,180,167,179,120,8,28,82,
49,63,52,98,248,32,194,165,74,198,165,70,28,117,74,137,218,80,134,145,34,65,249,161,240,68,48,29,186,149,43,10,149,24,72,157,173,120,170,36,72,63,55,120,58,247,234,40,119,117,133,65,18,58,246,227,4,130,
13,140,32,197,8,119,117,19,1,135,176,16,118,18,8,54,49,69,23,122,196,192,99,174,32,129,133,74,192,68,142,198,40,160,247,201,4,180,36,128,236,177,32,131,99,71,0,123,231,18,29,192,130,37,59,24,53,7,0,97,
222,84,169,82,187,108,96,131,99,70,160,224,12,31,14,32,131,96,82,84,74,238,134,160,224,12,31,10,198,24,54,0,211,10,142,157,216,212,28,1,135,134,16,71,241,238,158,0,134,15,120,53,7,0,97,225,24,193,15,227,
143,2,33,138,74,143,116,53,7,16,240,162,15,199,26,71,192,157,138,239,10,40,188,43,137,171,241,187,188,17,224,74,40,48,240,108,118,7,33,216,112,39,118,162,217,113,118,158,237,71,8,120,86,246,192,142,53,
131,129,59,165,20,60,27,136,235,176,3,12,14,17,193,238,206,63,8,199,3,174,192,143,128,106,194,67,193,56,142,187,4,61,151,186,53,192,67,194,55,182,16,123,9,221,238,120,51,24,182,20,67,22,39,114,67,176,
191,0,197,176,179,11,151,221,154,194,12,25,114,241,185,114,251,149,193,69,142,187,8,53,46,92,182,91,221,144,123,15,207,60,107,198,229,203,151,46,94,23,22,40,182,80,101,246,222,36,196,95,108,6,22,46,202,
92,183,182,96,117,118,129,213,58,165,203,139,179,246,203,101,178,217,105,120,219,45,254,65,86,14,202,215,100,37,74,149,220,3,182,167,183,78,194,212,174,192,99,70,0,149,133,74,193,209,58,39,70,10,237,37,
224,169,82,165,74,149,43,23,96,235,26,149,43,197,167,101,118,16,237,220,185,100,178,101,225,46,94,23,47,97,237,150,203,101,178,217,120,151,222,0,15,86,14,169,213,58,167,84,234,157,82,201,120,45,254,15,
255,218,0,8,1,2,3,1,63,33,255,0,128,93,158,127,149,235,104,222,221,255,0,38,86,59,252,81,177,27,252,101,127,44,27,20,127,3,184,31,241,198,252,107,101,171,249,60,237,222,209,29,221,237,101,236,235,255,
0,214,99,248,173,218,151,10,255,0,152,141,148,124,41,181,36,118,160,254,62,127,145,42,86,222,86,209,215,117,93,154,149,255,0,126,94,21,179,247,47,179,125,205,237,51,180,151,46,92,185,127,207,223,255,218,
0,8,1,3,3,1,63,33,252,97,183,38,201,191,202,149,255,0,41,27,79,95,254,56,110,94,53,181,87,181,151,180,15,253,103,120,223,108,254,83,63,148,207,248,165,240,103,242,3,255,0,30,59,82,255,0,42,86,214,214,
214,212,169,82,191,252,81,255,0,255,218,0,12,3,1,0,2,17,3,17,0,0,16,146,73,36,146,73,36,146,73,36,146,73,36,146,77,43,146,78,194,138,23,36,146,18,144,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,
146,73,36,146,73,36,146,73,36,146,73,36,146,73,181,50,72,156,176,32,20,146,72,0,210,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,128,18,73,182,132,72,177,
50,73,35,51,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,132,130,73,226,132,201,52,172,73,36,166,97,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,
146,73,36,146,73,36,146,73,36,146,72,16,106,17,242,208,65,32,211,185,36,147,152,164,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,48,91,98,8,4,73,36,131,5,228,
146,18,144,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,3,23,22,130,70,201,36,146,5,23,146,73,204,82,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,
73,36,146,73,36,146,73,32,65,158,20,16,73,36,146,72,180,78,201,0,24,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,50,105,5,18,73,36,146,73,34,80,150,175,162,41,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,22,9,34,114,73,36,146,73,36,155,8,81,219,132,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,
146,73,36,128,137,52,210,73,36,146,73,36,146,15,176,223,156,52,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,97,12,146,73,36,146,73,36,146,73,4,90,51,35,18,73,36,
146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,75,18,73,36,146,73,36,146,73,36,146,41,252,218,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,
146,73,37,224,73,36,146,73,36,146,73,36,146,76,17,65,9,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,144,73,36,146,73,36,146,73,36,146,73,16,46,109,36,146,73,36,146,
73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,130,73,36,146,73,36,146,73,36,146,73,38,144,129,196,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,
73,36,146,73,36,16,73,36,146,73,32,66,9,16,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,34,179,44,32,146,73,36,158,65,36,34,73,36,146,73,36,146,73,36,
146,73,36,146,73,36,146,73,36,146,73,36,146,73,4,146,73,36,146,73,0,66,1,22,218,73,36,146,20,32,153,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,32,18,73,36,146,73,32,33,125,
138,146,37,132,146,64,158,16,89,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,4,146,73,36,146,73,36,154,61,199,230,89,2,78,73,36,210,64,164,146,73,36,146,73,36,146,73,36,146,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,130,198,164,144,212,200,0,41,36,138,0,52,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,130,73,36,146,73,36,146,104,32,146,73,
33,29,37,36,147,8,100,210,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,64,36,146,73,36,146,65,166,82,73,36,146,116,22,18,97,177,211,73,36,146,73,36,146,73,36,146,73,36,146,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,50,68,201,36,146,73,236,210,96,85,242,33,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,194,241,36,146,73,
35,33,33,105,145,208,164,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,32,146,73,36,129,74,228,146,73,36,30,236,105,146,26,144,146,73,36,146,73,36,146,73,36,146,73,36,146,
73,36,146,73,36,146,73,36,146,73,36,18,73,36,146,77,7,146,73,36,144,46,208,146,72,128,210,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,130,73,36,146,72,20,30,73,36,146,73,
36,146,73,39,216,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,144,65,36,146,73,32,65,121,36,146,73,36,146,73,36,18,121,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,
36,146,9,36,146,73,36,146,72,36,146,73,36,129,1,228,146,73,36,146,73,36,147,197,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,65,36,146,73,36,146,65,127,18,73,36,146,5,32,146,73,36,146,73,36,
146,1,52,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,65,36,146,73,36,146,72,47,242,73,36,146,73,18,54,73,36,146,73,36,146,64,86,18,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,4,146,
73,36,146,73,6,105,217,36,146,73,32,87,201,36,146,73,36,146,73,61,82,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,4,146,73,36,146,73,36,142,65,164,146,73,36,138,1,36,146,73,36,146,73,36,19,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,233,12,18,73,36,144,45,68,146,73,36,146,73,36,4,105,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,
146,67,36,250,73,36,146,76,0,146,73,36,146,73,36,146,165,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,64,84,18,193,36,146,72,18,114,73,36,146,73,36,146,48,228,146,73,36,
146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,1,144,103,36,146,73,34,4,201,36,146,73,36,146,78,52,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,22,
72,228,146,73,36,144,73,36,146,73,36,146,72,226,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,145,25,24,146,73,36,131,31,36,146,73,36,146,73,14,82,73,36,146,73,36,146,
73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,4,97,146,73,36,146,105,196,146,73,36,146,73,44,26,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,25,184,
73,36,146,14,51,134,73,36,146,73,35,49,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,0,46,9,36,146,73,198,248,214,12,146,73,7,139,73,36,146,73,36,146,73,36,146,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,2,73,36,146,72,40,128,5,41,175,255,0,253,218,105,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,
36,181,108,180,154,82,104,80,1,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,32,217,44,150,221,17,36,146,73,36,146,73,36,146,73,36,146,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,9,36,0,9,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,72,36,146,
73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,72,132,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,
73,36,146,73,36,146,73,36,146,72,36,130,65,36,146,73,207,18,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,32,18,73,32,129,159,118,89,94,164,198,100,0,16,
65,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,32,18,9,25,78,210,77,223,145,36,144,83,241,146,9,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,
36,146,73,36,146,73,33,173,254,73,255,0,210,64,72,51,125,82,9,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,144,73,32,16,9,36,146,73,2,219,100,32,146,73,36,146,73,
36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,146,73,36,255,218,0,8,1,1,3,1,63,16,252,37,5,249,
185,199,234,202,143,184,47,167,103,87,164,210,244,253,65,175,65,130,207,143,222,27,182,83,151,148,151,121,212,131,89,238,237,165,196,159,227,201,149,89,185,149,62,117,216,219,27,150,39,42,247,148,122,
124,176,61,224,81,217,91,86,60,158,115,126,5,140,20,245,206,13,55,44,4,115,154,127,17,12,91,189,187,99,127,188,23,235,247,53,252,231,44,30,90,196,166,182,44,45,162,80,19,79,227,172,21,233,6,255,0,110,
202,188,136,190,211,219,220,113,154,156,95,172,14,87,195,247,133,13,123,74,179,220,207,245,228,193,131,103,109,43,41,119,238,80,223,188,171,63,53,177,119,103,230,165,159,71,89,71,166,68,33,145,216,109,
145,21,126,229,31,162,34,229,239,23,139,239,16,105,155,53,58,125,103,141,249,50,188,188,164,184,62,57,144,119,193,188,251,66,206,145,38,191,155,38,177,194,37,53,177,33,109,74,128,222,212,163,211,35,172,
21,71,8,106,97,103,24,240,124,197,226,197,246,153,124,143,150,35,124,190,90,141,143,212,191,47,153,209,243,27,149,85,136,211,114,208,227,172,230,255,0,140,179,247,21,116,237,138,121,51,43,153,164,171,
63,53,254,77,241,215,98,119,222,106,12,239,219,171,52,14,25,250,195,27,137,227,30,95,86,115,47,145,164,247,247,28,38,135,163,14,119,199,183,115,151,212,223,158,164,209,243,100,246,62,165,29,59,73,100,
103,247,122,111,154,199,13,34,83,91,14,22,132,52,77,14,89,189,97,202,248,194,92,105,175,180,175,250,34,183,127,95,236,83,254,219,57,223,175,169,103,18,5,81,53,189,59,138,114,149,230,105,60,156,73,103,
79,168,83,167,104,103,214,28,186,125,74,155,225,244,205,246,195,221,159,31,168,109,61,225,202,248,205,15,95,188,22,179,102,251,123,164,80,93,120,17,111,47,234,116,39,73,243,202,95,151,204,232,249,138,
122,119,59,135,255,0,101,125,31,137,103,157,101,154,65,225,0,242,236,104,245,140,212,229,244,205,99,203,5,53,237,211,97,66,218,130,143,131,161,55,189,38,151,175,220,163,39,73,93,196,222,44,214,119,232,
65,99,40,204,211,121,223,238,31,253,149,230,105,57,222,187,189,103,162,252,75,130,238,103,49,41,21,228,71,72,119,250,74,27,244,102,248,242,108,41,206,248,19,65,22,167,172,163,39,73,206,248,99,194,123,
206,109,177,87,88,168,231,131,171,215,191,221,63,251,55,131,55,63,14,147,153,92,156,200,127,232,133,180,101,226,150,36,176,235,148,57,60,162,83,91,8,233,174,63,113,101,211,40,52,220,231,124,49,225,207,
156,83,171,151,177,18,121,162,39,143,180,121,61,226,159,243,192,169,175,190,248,15,249,254,192,238,107,227,238,11,175,158,83,137,243,253,205,12,253,24,7,73,110,26,199,29,62,224,206,253,250,147,125,230,
182,23,125,199,94,184,209,17,210,42,235,225,173,197,247,129,111,243,233,56,147,215,56,75,43,60,247,50,206,184,29,254,146,207,95,178,27,58,68,165,54,17,211,91,159,185,102,78,187,176,23,151,40,137,175,138,
69,83,75,131,46,234,65,178,226,89,80,88,155,207,178,26,111,143,220,169,191,53,176,182,23,188,214,1,215,40,173,244,154,228,196,165,60,85,199,157,102,151,179,30,117,199,3,157,241,154,156,243,58,195,103,
157,34,82,155,8,169,228,235,136,153,25,191,83,92,223,20,235,203,164,89,215,31,212,89,14,2,207,152,44,233,156,52,245,206,84,223,154,216,81,133,107,20,242,60,102,151,175,212,90,61,24,242,72,247,111,193,
201,122,205,78,89,157,33,179,206,145,41,77,145,229,75,242,249,157,39,207,56,137,168,247,166,167,82,105,154,15,163,7,68,135,25,237,22,243,135,71,210,10,83,205,74,179,225,245,177,233,209,198,122,31,108,
1,187,222,3,184,125,34,183,158,228,75,231,251,156,31,143,234,40,233,199,1,57,135,116,175,212,185,67,201,214,81,204,130,58,56,107,122,67,149,240,134,206,159,81,41,175,206,9,228,69,26,251,248,0,182,166,
251,118,233,99,246,206,1,234,195,141,246,148,132,60,61,73,79,47,146,113,15,88,139,202,7,159,212,179,159,220,94,225,86,94,210,206,187,200,35,79,104,30,144,124,111,172,74,85,103,254,224,148,215,9,188,225,
153,211,243,98,222,91,240,75,42,37,41,223,143,150,161,52,143,86,89,150,129,10,104,74,158,136,158,21,210,55,220,61,50,99,155,79,139,137,229,237,95,81,123,138,233,156,77,229,244,130,245,249,138,221,253,
196,60,255,0,115,145,245,41,53,19,176,51,95,125,240,231,247,63,168,44,163,51,51,132,27,46,86,253,210,226,205,79,152,44,250,148,60,157,63,52,114,235,137,202,248,119,235,35,147,159,189,195,159,172,222,244,
154,8,101,4,242,157,127,18,209,56,146,140,9,225,237,1,231,240,206,71,185,127,36,120,62,51,251,138,60,211,30,50,60,62,204,163,167,215,106,236,152,242,78,31,184,40,123,251,205,233,237,55,198,253,121,50,
220,252,143,230,128,41,203,193,42,121,111,138,200,239,212,249,38,147,206,248,106,118,104,225,41,57,24,241,18,162,120,71,255,0,44,228,87,92,198,87,167,169,194,92,95,188,114,203,179,228,244,102,247,164,
13,15,72,163,116,187,58,235,40,177,211,245,40,127,52,40,192,187,235,3,93,89,247,255,0,212,202,31,146,61,220,115,33,12,206,225,7,116,120,62,98,113,35,234,39,248,202,148,227,53,60,238,236,140,239,206,144,
233,214,253,161,222,250,97,188,61,167,7,211,175,9,97,18,154,127,54,41,163,21,117,239,213,60,183,205,246,242,104,215,82,47,152,183,123,119,109,58,79,99,234,114,188,241,133,121,153,244,184,6,239,83,40,148,
214,53,1,189,154,94,114,32,123,96,156,33,122,58,242,148,55,239,43,204,242,108,101,121,121,169,67,174,186,117,150,122,252,48,96,217,221,138,233,44,253,79,67,245,14,72,238,253,77,111,79,172,44,205,151,231,
228,37,71,63,162,5,228,74,70,157,34,127,179,87,205,147,88,130,159,173,139,211,50,90,78,47,254,203,183,231,187,153,7,121,6,251,180,172,183,75,188,234,71,206,184,62,209,117,235,241,42,115,205,143,195,47,
137,93,121,182,6,232,21,136,174,146,227,234,111,253,78,146,252,207,46,193,83,87,89,119,66,140,191,51,94,51,141,255,0,140,179,247,6,186,119,105,113,56,203,188,229,28,218,121,244,133,55,125,3,237,4,243,
148,14,16,43,176,150,84,79,121,103,174,126,179,80,220,207,88,216,23,71,163,245,221,178,229,52,210,104,103,211,250,150,126,226,174,157,218,94,177,224,157,30,125,32,184,121,245,135,20,10,211,180,55,251,
193,126,191,115,223,253,159,220,176,216,29,122,61,227,174,95,83,126,122,147,67,205,192,124,233,40,233,225,147,82,89,235,151,172,161,121,255,0,228,161,243,174,192,26,29,15,168,139,102,253,72,61,249,124,
206,34,251,167,92,190,166,252,245,39,147,140,246,62,165,29,60,40,223,5,250,207,47,50,92,126,66,154,186,203,192,102,29,62,178,149,122,69,26,147,50,233,245,159,118,235,148,223,158,164,187,206,178,206,159,
81,86,78,158,21,53,37,158,185,122,204,196,227,247,13,61,126,255,0,28,22,212,203,78,135,128,211,209,154,25,231,116,20,242,98,82,157,219,174,83,126,122,146,207,58,203,34,220,250,120,65,190,11,245,251,155,
239,95,238,111,61,125,191,28,115,88,180,61,124,3,205,56,159,83,75,214,121,168,150,84,127,95,132,135,30,124,161,167,45,30,234,245,58,74,243,221,245,50,60,251,193,184,175,175,131,75,42,51,91,223,209,153,
9,194,37,41,248,221,47,88,173,122,248,1,164,99,207,169,141,68,110,201,154,14,189,221,45,50,148,248,150,215,199,38,14,255,0,9,171,172,25,116,203,209,130,159,113,244,130,188,183,126,54,232,113,162,188,19,
200,226,118,78,190,253,229,249,51,118,190,120,203,63,125,98,221,237,224,198,87,194,11,245,62,96,223,235,237,148,27,250,127,95,159,84,242,223,29,149,195,176,44,230,71,54,181,202,160,133,151,221,13,55,52,
95,126,146,239,168,63,16,204,240,78,100,116,135,237,61,18,11,62,58,94,192,123,135,201,7,176,131,172,52,61,31,174,238,166,188,212,220,122,71,103,195,214,45,222,13,223,14,189,47,218,15,219,247,28,148,231,
249,241,166,230,234,242,116,197,65,123,191,188,5,159,81,3,152,244,188,161,25,157,59,145,164,102,131,232,203,142,191,100,89,143,131,212,204,197,114,102,167,167,234,106,108,5,77,113,211,172,86,115,223,131,
222,244,130,158,91,176,22,60,179,154,3,159,215,117,145,94,114,153,7,163,237,148,32,217,126,11,83,231,116,221,245,154,189,38,183,167,214,192,243,243,251,32,222,103,97,155,158,189,211,168,89,250,253,145,
228,116,250,154,60,22,167,206,147,71,163,50,47,157,211,83,96,191,220,131,216,211,235,221,100,29,126,242,143,49,229,126,186,199,151,71,226,106,240,78,145,235,232,126,226,213,230,174,163,154,188,246,8,81,
178,123,111,195,216,186,248,142,93,209,203,89,251,162,203,208,96,232,205,124,2,163,174,15,220,197,71,187,236,108,35,206,184,197,103,76,117,250,76,171,223,191,167,115,175,210,101,79,111,212,84,30,163,6,
10,64,116,150,113,59,229,183,148,121,117,250,151,121,220,69,187,207,29,132,57,95,24,53,58,126,98,248,126,230,177,64,111,255,0,123,157,47,88,178,58,19,125,185,148,235,153,1,199,223,253,193,114,249,193,
113,253,206,98,83,143,113,164,179,167,220,95,246,106,123,19,89,220,105,29,249,107,176,137,204,74,243,34,247,101,57,223,4,231,124,18,239,94,228,212,234,71,149,112,148,116,225,10,111,79,169,212,123,50,155,
255,0,100,167,24,57,154,230,31,168,7,135,164,15,31,121,114,249,203,113,150,229,45,202,91,148,183,41,110,50,249,199,209,50,121,113,150,245,79,98,80,108,166,130,111,149,224,196,31,238,81,30,109,250,158,
89,67,209,233,1,124,33,205,125,98,111,254,231,148,127,80,231,61,114,128,228,244,97,215,233,41,206,83,156,245,74,26,149,235,30,115,211,56,245,63,4,245,158,6,132,212,89,115,211,239,101,4,127,177,77,245,
211,180,41,163,20,215,251,32,31,55,14,15,151,247,5,198,253,165,185,75,114,249,150,229,243,45,202,116,190,38,111,34,60,77,250,220,71,25,239,238,56,108,255,0,49,251,251,156,239,130,115,190,9,206,248,32,
31,226,145,111,47,153,111,23,221,150,241,125,217,70,247,239,238,115,190,13,153,167,131,236,237,48,46,68,56,179,228,65,240,168,137,172,57,15,58,217,81,165,229,235,17,53,59,20,107,155,245,16,238,61,50,143,
11,239,20,110,123,64,186,16,91,253,141,103,162,112,53,128,26,96,151,148,200,87,60,42,244,156,175,146,34,106,118,65,116,157,46,155,10,39,167,24,179,76,251,22,107,161,243,133,59,199,218,45,203,164,234,202,
112,79,86,0,231,133,29,223,169,93,204,121,7,207,57,230,185,228,185,230,184,114,30,185,195,141,128,26,29,173,147,114,249,229,7,192,60,242,151,229,20,106,127,81,59,178,249,151,226,75,242,249,129,222,192,
13,48,86,169,176,98,122,113,154,100,96,135,251,151,220,144,227,125,9,210,5,126,240,179,127,212,203,90,58,215,110,207,63,228,179,200,203,29,59,189,124,229,47,234,224,106,118,20,53,136,244,216,68,81,91,
181,237,156,103,89,78,115,153,240,206,103,220,190,35,222,89,196,236,101,191,230,89,196,150,113,38,189,222,70,175,166,146,135,56,219,145,130,78,125,34,221,50,216,126,103,239,238,115,190,9,206,248,39,59,
224,157,39,207,41,126,95,51,152,157,31,50,251,130,91,120,125,78,143,153,209,243,58,62,103,71,204,232,249,157,31,51,163,230,116,124,206,143,153,204,74,16,115,190,185,207,53,79,53,79,37,79,53,79,37,36,167,
23,204,231,125,202,243,248,157,31,51,164,121,231,21,117,127,131,191,255,218,0,8,1,2,3,1,63,16,252,35,158,88,106,246,153,191,3,92,25,172,114,97,220,36,27,142,199,57,64,139,3,182,102,224,235,142,142,26,
119,12,209,195,71,99,117,112,213,135,105,206,5,97,171,23,56,68,184,61,195,6,37,193,189,139,90,33,145,20,59,76,10,150,18,224,47,97,154,196,168,119,12,27,142,78,197,234,225,171,216,188,46,224,84,101,118,
244,112,209,238,76,156,13,137,90,32,84,116,134,55,51,112,5,96,235,220,153,68,185,167,112,193,178,57,59,19,171,134,168,75,153,176,3,11,37,37,176,59,148,184,49,46,105,219,97,147,129,176,235,80,211,7,92,
53,129,88,81,223,37,193,137,115,51,180,198,25,145,201,216,119,92,82,240,5,97,126,0,151,6,107,41,37,225,120,186,96,115,33,177,133,168,102,248,20,185,124,112,161,193,153,47,19,92,52,118,25,201,236,92,205,
148,120,74,73,108,179,4,25,73,45,192,210,57,144,211,97,82,224,203,38,108,170,241,53,47,4,174,195,71,97,147,13,30,47,88,96,229,52,193,44,131,102,195,83,15,24,246,141,29,163,116,134,152,153,56,58,65,179,
104,204,19,3,76,52,118,164,116,131,123,32,178,151,5,76,229,247,172,27,237,104,236,122,192,174,213,84,185,108,190,235,73,99,217,75,131,123,32,90,153,178,165,50,210,82,89,141,76,229,157,197,18,146,15,99,
71,99,92,78,184,212,169,82,165,75,76,22,97,68,166,93,107,219,123,14,112,216,221,28,29,123,138,149,42,102,96,187,154,195,38,187,78,144,211,11,48,118,53,154,224,59,170,195,72,55,30,211,166,11,128,225,163,
177,166,78,6,76,59,205,38,179,50,13,246,53,98,212,11,193,32,196,184,55,177,137,112,110,36,30,247,76,28,156,86,25,71,55,10,193,131,113,201,216,215,44,18,187,214,25,49,150,76,224,69,129,217,209,192,216,
221,48,209,239,82,93,75,37,146,214,7,105,32,199,99,180,154,205,59,218,149,42,87,109,154,56,25,59,29,164,75,154,120,118,17,217,4,185,167,134,99,147,129,147,176,86,119,154,224,151,52,240,206,7,96,93,112,
27,239,53,193,46,105,225,89,163,129,176,26,176,210,13,247,137,112,137,112,124,43,13,38,142,192,104,134,108,164,164,130,247,137,112,98,65,240,140,53,142,155,2,100,226,144,211,188,102,179,70,30,13,154,56,
27,0,144,204,199,71,189,50,98,101,15,8,195,73,191,96,28,225,147,138,92,204,131,125,219,53,154,48,240,108,209,29,118,5,32,223,99,71,188,50,112,30,20,236,19,147,53,197,46,25,61,219,24,120,86,141,130,214,
25,61,135,94,237,210,26,77,240,240,78,7,96,210,224,214,46,189,225,29,97,224,157,33,164,117,216,68,184,53,137,167,118,107,128,240,78,27,246,21,215,19,78,236,142,100,28,47,192,25,184,26,108,42,95,124,26,
224,147,50,92,185,100,185,125,219,2,136,236,163,147,53,236,84,163,6,100,185,120,92,185,114,240,185,112,43,3,61,148,75,150,148,202,149,42,103,46,107,133,24,41,148,202,101,56,41,43,7,61,157,162,103,45,151,
44,150,75,37,146,229,178,217,155,2,191,226,155,37,142,211,49,155,45,52,217,165,168,174,22,224,164,178,89,44,150,96,205,128,98,151,6,165,146,201,73,99,178,43,120,83,51,196,168,134,53,42,86,1,125,161,217,
29,144,169,76,166,83,41,153,246,115,237,148,148,192,183,142,114,152,21,179,244,74,37,18,137,68,162,81,252,39,255,218,0,8,1,3,3,1,63,16,252,48,69,174,206,136,235,218,24,230,118,198,162,94,201,153,17,207,
178,100,71,182,49,59,106,38,200,132,93,144,139,220,141,196,174,222,164,118,64,236,132,94,232,102,167,108,106,38,199,154,227,78,12,136,189,224,196,190,216,217,19,99,140,110,95,126,49,47,180,53,29,142,37,
197,240,67,18,251,70,145,54,136,102,76,71,178,118,142,229,202,28,20,192,168,233,180,214,203,218,187,127,225,231,255,0,144,117,42,83,43,105,140,162,214,10,76,153,70,10,118,132,237,91,45,193,147,42,86,207,
153,157,205,184,50,98,108,232,193,221,141,196,238,66,240,77,146,27,137,93,216,220,78,216,77,37,176,110,38,200,140,212,154,119,102,100,78,214,132,91,196,110,38,200,141,68,190,239,73,147,19,16,153,17,111,
176,53,28,205,146,24,151,222,178,153,29,193,68,217,33,137,126,27,83,100,198,37,248,85,29,147,24,158,23,83,101,6,39,133,59,40,49,43,194,58,108,174,167,132,52,142,202,12,30,16,236,169,153,224,200,233,178,
163,7,131,221,178,218,158,12,211,3,101,8,248,35,77,150,38,175,4,100,108,177,52,120,39,77,151,212,240,38,177,217,87,1,137,114,210,158,248,40,142,204,92,185,114,201,67,130,158,228,42,46,207,91,46,88,202,
37,37,37,37,37,18,194,46,209,220,185,114,255,0,249,133,79,113,76,169,91,59,120,223,111,57,79,252,13,255,217,0,0};

const char* TabMainControl::basszero_background_jpg2 = (const char*) resource_TabMainControl_basszero_background_jpg2;
const int TabMainControl::basszero_background_jpg2Size = 10853;


//[EndFile] You can add extra defines here...
//[/EndFile]

