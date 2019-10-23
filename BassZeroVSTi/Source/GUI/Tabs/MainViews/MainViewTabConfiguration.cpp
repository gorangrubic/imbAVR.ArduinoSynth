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

#include "MainViewTabConfiguration.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainViewTabConfiguration::MainViewTabConfiguration (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
	state = std::shared_ptr<imbSynthStateData>(synthState);
    //[/Constructor_pre]

    label3.reset (new Label ("new label",
                             TRANS("MIDI Device needles")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label3->setColour (TextEditor::textColourId, Colour (0xff495358));
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (16, 32, 300, 24);

    label5.reset (new Label ("new label",
                             TRANS("Needle 1")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (Label::backgroundColourId, Colours::azure);
    label5->setColour (Label::textColourId, Colour (0xff181f22));
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (464, 424, 112, 24);

    text_name2.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (text_name2.get());
    text_name2->setTooltip (TRANS("Title of the Operation Mode"));
    text_name2->setMultiLine (false);
    text_name2->setReturnKeyStartsNewLine (false);
    text_name2->setReadOnly (false);
    text_name2->setScrollbarsShown (true);
    text_name2->setCaretVisible (true);
    text_name2->setPopupMenuEnabled (true);
    text_name2->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    text_name2->setText (TRANS("Arduino Pro Micro"));

    text_name2->setBounds (584, 424, 176, 24);

    needle_midiDevice.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_midiDevice.get());
    needle_midiDevice->setTooltip (TRANS("Title of the Operation Mode"));
    needle_midiDevice->setMultiLine (false);
    needle_midiDevice->setReturnKeyStartsNewLine (false);
    needle_midiDevice->setReadOnly (false);
    needle_midiDevice->setScrollbarsShown (false);
    needle_midiDevice->setCaretVisible (true);
    needle_midiDevice->setPopupMenuEnabled (true);
    needle_midiDevice->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    needle_midiDevice->setText (TRANS("Pro Micro|BassZero"));

    needle_midiDevice->setBounds (16, 56, 300, 24);

    label7.reset (new Label ("new label",
                             TRANS("MIDI Input needles")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label7->setColour (TextEditor::textColourId, Colour (0xff495358));
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label7->setBounds (16, 133, 300, 24);

    needle_input.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_input.get());
    needle_input->setTooltip (TRANS("Title of the Operation Mode"));
    needle_input->setMultiLine (false);
    needle_input->setReturnKeyStartsNewLine (false);
    needle_input->setReadOnly (false);
    needle_input->setScrollbarsShown (false);
    needle_input->setCaretVisible (true);
    needle_input->setPopupMenuEnabled (true);
    needle_input->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    needle_input->setText (TRANS("Novation"));

    needle_input->setBounds (16, 157, 300, 24);

    label8.reset (new Label ("new label",
                             TRANS("MIDI Output needles")));
    addAndMakeVisible (label8.get());
    label8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label8->setColour (TextEditor::textColourId, Colour (0xff495358));
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label8->setBounds (16, 184, 300, 24);

    needle_output.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_output.get());
    needle_output->setTooltip (TRANS("Title of the Operation Mode"));
    needle_output->setMultiLine (false);
    needle_output->setReturnKeyStartsNewLine (false);
    needle_output->setReadOnly (false);
    needle_output->setScrollbarsShown (false);
    needle_output->setCaretVisible (true);
    needle_output->setPopupMenuEnabled (true);
    needle_output->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    needle_output->setText (TRANS("MIDI Out"));

    needle_output->setBounds (16, 208, 300, 24);

    toggle_log_to_file.reset (new ToggleButton (String()));
    addAndMakeVisible (toggle_log_to_file.get());
    toggle_log_to_file->setButtonText (TRANS("Save log to file"));
    toggle_log_to_file->addListener (this);

    toggle_log_to_file->setBounds (16, 240, 150, 24);

    toggle_factory_readonly.reset (new ToggleButton (String()));
    addAndMakeVisible (toggle_factory_readonly.get());
    toggle_factory_readonly->setButtonText (TRANS("Factory presets read-only"));
    toggle_factory_readonly->addListener (this);

    toggle_factory_readonly->setBounds (16, 264, 240, 24);

    label.reset (new Label ("new label",
                            TRANS("Auto-select needles")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (16, 8, 150, 24);

    label2.reset (new Label ("new label",
                             TRANS("Device Serial Port")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label2->setColour (TextEditor::textColourId, Colour (0xff495358));
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (16, 82, 300, 24);

    needle_serialPort.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (needle_serialPort.get());
    needle_serialPort->setTooltip (TRANS("Title of the Operation Mode"));
    needle_serialPort->setMultiLine (false);
    needle_serialPort->setReturnKeyStartsNewLine (false);
    needle_serialPort->setReadOnly (false);
    needle_serialPort->setScrollbarsShown (false);
    needle_serialPort->setCaretVisible (true);
    needle_serialPort->setPopupMenuEnabled (true);
    needle_serialPort->setColour (TextEditor::backgroundColourId, Colour (0xff181f22));
    needle_serialPort->setText (TRANS("COM16|COM36"));

    needle_serialPort->setBounds (16, 106, 300, 24);

    fullSyncPlayTimeout.reset (new Slider ("new slider"));
    addAndMakeVisible (fullSyncPlayTimeout.get());
    fullSyncPlayTimeout->setRange (100, 1000, 1);
    fullSyncPlayTimeout->setSliderStyle (Slider::LinearHorizontal);
    fullSyncPlayTimeout->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    fullSyncPlayTimeout->setColour (Slider::thumbColourId, Colour (0xffed6216));
    fullSyncPlayTimeout->setColour (Slider::textBoxTextColourId, Colours::azure);
    fullSyncPlayTimeout->setColour (Slider::textBoxOutlineColourId, Colour (0x003c3c3c));
    fullSyncPlayTimeout->addListener (this);

    label4.reset (new Label (String(),
                             TRANS("Full sync play timeout (ms)")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (Label::backgroundColourId, Colour (0xffed6216));
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (344, 32, 190, 24);

    ccMessagesCycle.reset (new Slider ("new slider"));
    addAndMakeVisible (ccMessagesCycle.get());
    ccMessagesCycle->setRange (10, 200, 1);
    ccMessagesCycle->setSliderStyle (Slider::LinearHorizontal);
    ccMessagesCycle->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    ccMessagesCycle->setColour (Slider::thumbColourId, Colour (0xffed6216));
    ccMessagesCycle->setColour (Slider::textBoxTextColourId, Colours::azure);
    ccMessagesCycle->setColour (Slider::textBoxOutlineColourId, Colour (0x003c3c3c));
    ccMessagesCycle->addListener (this);

    label6.reset (new Label (String(),
                             TRANS("CC messages cycle (ms)")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (Label::backgroundColourId, Colour (0xffed6216));
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (344, 64, 190, 24);

    confirmationNoteOnOff.reset (new ToggleButton (String()));
    addAndMakeVisible (confirmationNoteOnOff.get());
    confirmationNoteOnOff->setButtonText (TRANS("Confirmation protocol for Note On/Off"));
    confirmationNoteOnOff->addListener (this);

    confirmationNoteOnOff->setBounds (344, 104, 360, 24);

    confirmationCC.reset (new ToggleButton (String()));
    addAndMakeVisible (confirmationCC.get());
    confirmationCC->setButtonText (TRANS("Confirmation protocol for CC"));
    confirmationCC->addListener (this);

    confirmationCC->setBounds (344, 128, 360, 24);

    confirmationOPM.reset (new ToggleButton (String()));
    addAndMakeVisible (confirmationOPM.get());
    confirmationOPM->setButtonText (TRANS("Confirmation protocol for OPM"));
    confirmationOPM->addListener (this);

    confirmationOPM->setBounds (344, 152, 360, 24);

    confirmationRetryLimit.reset (new Slider ("new slider"));
    addAndMakeVisible (confirmationRetryLimit.get());
    confirmationRetryLimit->setRange (1, 10, 1);
    confirmationRetryLimit->setSliderStyle (Slider::LinearHorizontal);
    confirmationRetryLimit->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    confirmationRetryLimit->setColour (Slider::thumbColourId, Colour (0xff397daa));
    confirmationRetryLimit->setColour (Slider::textBoxTextColourId, Colours::azure);
    confirmationRetryLimit->setColour (Slider::textBoxOutlineColourId, Colour (0x003c3c3c));
    confirmationRetryLimit->addListener (this);

    label9.reset (new Label (String(),
                             TRANS("Confirmation retry limit")));
    addAndMakeVisible (label9.get());
    label9->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label9->setBounds (344, 192, 190, 24);

    confirmationTimeout.reset (new Slider ("new slider"));
    addAndMakeVisible (confirmationTimeout.get());
    confirmationTimeout->setRange (1, 10, 1);
    confirmationTimeout->setSliderStyle (Slider::LinearHorizontal);
    confirmationTimeout->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    confirmationTimeout->setColour (Slider::thumbColourId, Colour (0xff397daa));
    confirmationTimeout->setColour (Slider::textBoxTextColourId, Colours::azure);
    confirmationTimeout->setColour (Slider::textBoxOutlineColourId, Colour (0x003c3c3c));
    confirmationTimeout->addListener (this);

    label10.reset (new Label (String(),
                              TRANS("Confirmation timeout (ms)")));
    addAndMakeVisible (label10.get());
    label10->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (Label::backgroundColourId, Colour (0xff397daa));
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label10->setBounds (344, 224, 190, 24);

    deviceConnectRetry.reset (new Slider ("new slider"));
    addAndMakeVisible (deviceConnectRetry.get());
    deviceConnectRetry->setRange (500, 5000, 1);
    deviceConnectRetry->setSliderStyle (Slider::LinearHorizontal);
    deviceConnectRetry->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    deviceConnectRetry->setColour (Slider::thumbColourId, Colour (0xff029d4d));
    deviceConnectRetry->setColour (Slider::textBoxTextColourId, Colours::azure);
    deviceConnectRetry->setColour (Slider::textBoxOutlineColourId, Colour (0x003c3c3c));
    deviceConnectRetry->addListener (this);

    label11.reset (new Label (String(),
                              TRANS("Device connect retry (ms)")));
    addAndMakeVisible (label11.get());
    label11->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (Label::backgroundColourId, Colour (0xff029d4d));
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label11->setBounds (344, 267, 190, 24);

    UIRefreshRate.reset (new Slider ("new slider"));
    addAndMakeVisible (UIRefreshRate.get());
    UIRefreshRate->setRange (100, 1000, 1);
    UIRefreshRate->setSliderStyle (Slider::LinearHorizontal);
    UIRefreshRate->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    UIRefreshRate->setColour (Slider::thumbColourId, Colour (0xff029d4d));
    UIRefreshRate->setColour (Slider::textBoxTextColourId, Colours::azure);
    UIRefreshRate->setColour (Slider::textBoxOutlineColourId, Colour (0x003c3c3c));
    UIRefreshRate->addListener (this);

    label12.reset (new Label (String(),
                              TRANS("UI refresh rate (ms)")));
    addAndMakeVisible (label12.get());
    label12->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (Label::backgroundColourId, Colour (0xff029d4d));
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label12->setBounds (344, 297, 190, 24);

    logFailStats.reset (new ToggleButton (String()));
    addAndMakeVisible (logFailStats.get());
    logFailStats->setButtonText (TRANS("Log fail stats"));
    logFailStats->addListener (this);

    logFailStats->setBounds (648, 104, 150, 24);

    ResetToDefaults.reset (new TextButton ("new button"));
    addAndMakeVisible (ResetToDefaults.get());
    ResetToDefaults->setButtonText (TRANS("Reset to defaults"));
    ResetToDefaults->addListener (this);
    ResetToDefaults->setColour (TextButton::buttonColourId, Colour (0xff397daa));

    ResetToDefaults->setBounds (16, 296, 300, 24);

    cachedImage_background2_jpg_1 = ImageCache::getFromMemory (background2_jpg, background2_jpgSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (840, 340);


    //[Constructor] You can add your own custom stuff here..
	state->configuration.NeedleMIDIDevice.attachControl(needle_midiDevice.get());
	state->configuration.NeedleMIDIInput.attachControl(needle_input.get());
	state->configuration.NeedleMIDIOutput.attachControl(needle_output.get());
	state->configuration.NeedleSerialPort.attachControl(needle_serialPort.get());

	state->configuration.SaveLogToFile.attachControl(toggle_log_to_file.get());
	state->configuration.FactoryPresetsReadOnly.attachControl(toggle_factory_readonly.get());

	state->configuration.ioSettings.FullSyncPlayTimeout.attachControl(fullSyncPlayTimeout.get());
	state->configuration.ioSettings.CCMessagesCycle.attachControl(ccMessagesCycle.get());

	state->configuration.ioSettings.ConfirmationForNote.attachControl(confirmationNoteOnOff.get());
	state->configuration.ioSettings.ConfirmationForCC.attachControl(confirmationCC.get());
	state->configuration.ioSettings.ConfirmationForOPM.attachControl(confirmationOPM.get());
	state->configuration.ioSettings.ConfirmationRetryLimit.attachControl(confirmationRetryLimit.get());
	state->configuration.ioSettings.ConfirmationTimeout.attachControl(confirmationTimeout.get());
	state->configuration.ioSettings.DeviceConnectRetry.attachControl(deviceConnectRetry.get());
	state->configuration.ioSettings.UIRefreshRate.attachControl(UIRefreshRate.get());


    //[/Constructor]
}

MainViewTabConfiguration::~MainViewTabConfiguration()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label3 = nullptr;
    label5 = nullptr;
    text_name2 = nullptr;
    needle_midiDevice = nullptr;
    label7 = nullptr;
    needle_input = nullptr;
    label8 = nullptr;
    needle_output = nullptr;
    toggle_log_to_file = nullptr;
    toggle_factory_readonly = nullptr;
    label = nullptr;
    label2 = nullptr;
    needle_serialPort = nullptr;
    fullSyncPlayTimeout = nullptr;
    label4 = nullptr;
    ccMessagesCycle = nullptr;
    label6 = nullptr;
    confirmationNoteOnOff = nullptr;
    confirmationCC = nullptr;
    confirmationOPM = nullptr;
    confirmationRetryLimit = nullptr;
    label9 = nullptr;
    confirmationTimeout = nullptr;
    label10 = nullptr;
    deviceConnectRetry = nullptr;
    label11 = nullptr;
    UIRefreshRate = nullptr;
    label12 = nullptr;
    logFailStats = nullptr;
    ResetToDefaults = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainViewTabConfiguration::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = 0, y = -50, width = 840, height = 460;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black.withAlpha (0.200f));
        g.drawImage (cachedImage_background2_jpg_1,
                     x, y, width, height,
                     0, 0, cachedImage_background2_jpg_1.getWidth(), cachedImage_background2_jpg_1.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainViewTabConfiguration::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    fullSyncPlayTimeout->setBounds (822 - 260, 32, 260, 24);
    ccMessagesCycle->setBounds (822 - 260, 64, 260, 24);
    confirmationRetryLimit->setBounds (822 - 260, 192, 260, 24);
    confirmationTimeout->setBounds (822 - 260, 224, 260, 24);
    deviceConnectRetry->setBounds (822 - 260, 267, 260, 24);
    UIRefreshRate->setBounds (822 - 260, 297, 260, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainViewTabConfiguration::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggle_log_to_file.get())
    {
        //[UserButtonCode_toggle_log_to_file] -- add your button handler code here..
        //[/UserButtonCode_toggle_log_to_file]
    }
    else if (buttonThatWasClicked == toggle_factory_readonly.get())
    {
        //[UserButtonCode_toggle_factory_readonly] -- add your button handler code here..
        //[/UserButtonCode_toggle_factory_readonly]
    }
    else if (buttonThatWasClicked == confirmationNoteOnOff.get())
    {
        //[UserButtonCode_confirmationNoteOnOff] -- add your button handler code here..
        //[/UserButtonCode_confirmationNoteOnOff]
    }
    else if (buttonThatWasClicked == confirmationCC.get())
    {
        //[UserButtonCode_confirmationCC] -- add your button handler code here..
        //[/UserButtonCode_confirmationCC]
    }
    else if (buttonThatWasClicked == confirmationOPM.get())
    {
        //[UserButtonCode_confirmationOPM] -- add your button handler code here..
        //[/UserButtonCode_confirmationOPM]
    }
    else if (buttonThatWasClicked == logFailStats.get())
    {
        //[UserButtonCode_logFailStats] -- add your button handler code here..
        //[/UserButtonCode_logFailStats]
    }
    else if (buttonThatWasClicked == ResetToDefaults.get())
    {
        //[UserButtonCode_ResetToDefaults] -- add your button handler code here..
        //[/UserButtonCode_ResetToDefaults]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MainViewTabConfiguration::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == fullSyncPlayTimeout.get())
    {
        //[UserSliderCode_fullSyncPlayTimeout] -- add your slider handling code here..
        //[/UserSliderCode_fullSyncPlayTimeout]
    }
    else if (sliderThatWasMoved == ccMessagesCycle.get())
    {
        //[UserSliderCode_ccMessagesCycle] -- add your slider handling code here..
        //[/UserSliderCode_ccMessagesCycle]
    }
    else if (sliderThatWasMoved == confirmationRetryLimit.get())
    {
        //[UserSliderCode_confirmationRetryLimit] -- add your slider handling code here..
        //[/UserSliderCode_confirmationRetryLimit]
    }
    else if (sliderThatWasMoved == confirmationTimeout.get())
    {
        //[UserSliderCode_confirmationTimeout] -- add your slider handling code here..
        //[/UserSliderCode_confirmationTimeout]
    }
    else if (sliderThatWasMoved == deviceConnectRetry.get())
    {
        //[UserSliderCode_deviceConnectRetry] -- add your slider handling code here..
        //[/UserSliderCode_deviceConnectRetry]
    }
    else if (sliderThatWasMoved == UIRefreshRate.get())
    {
        //[UserSliderCode_UIRefreshRate] -- add your slider handling code here..
        //[/UserSliderCode_UIRefreshRate]
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

<JUCER_COMPONENT documentType="Component" className="MainViewTabConfiguration"
                 componentName="" parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="840" initialHeight="340">
  <BACKGROUND backgroundColour="323e44">
    <IMAGE pos="0 -50 840 460" resource="background2_jpg" opacity="0.2"
           mode="0"/>
  </BACKGROUND>
  <LABEL name="new label" id="1ec85516c8bd1f70" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="16 32 300 24" bkgCol="ff397daa" edTextCol="ff495358"
         edBkgCol="0" labelText="MIDI Device needles" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="cdcd778c5d2cc957" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="464 424 112 24" bkgCol="fff0ffff"
         textCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="Needle 1"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="70ba1419acb8f72c" memberName="text_name2"
              virtualName="" explicitFocusOrder="0" pos="584 424 176 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="Arduino Pro Micro" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="922d1416b90b6e43" memberName="needle_midiDevice"
              virtualName="" explicitFocusOrder="0" pos="16 56 300 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="Pro Micro|BassZero" multiline="0"
              retKeyStartsLine="0" readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="8c2150196038fc1f" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="16 133 300 24" bkgCol="ff397daa"
         edTextCol="ff495358" edBkgCol="0" labelText="MIDI Input needles"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="2f3c4c9d2266a62d" memberName="needle_input"
              virtualName="" explicitFocusOrder="0" pos="16 157 300 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="Novation" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="168e0cc17ec7a6c1" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="16 184 300 24" bkgCol="ff397daa"
         edTextCol="ff495358" edBkgCol="0" labelText="MIDI Output needles"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="1c9074d6a5225949" memberName="needle_output"
              virtualName="" explicitFocusOrder="0" pos="16 208 300 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="MIDI Out" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="" id="b938ea99f84115c4" memberName="toggle_log_to_file"
                virtualName="" explicitFocusOrder="0" pos="16 240 150 24" buttonText="Save log to file"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="" id="d98817afb6da0945" memberName="toggle_factory_readonly"
                virtualName="" explicitFocusOrder="0" pos="16 264 240 24" buttonText="Factory presets read-only"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="18d0c664b6949a90" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="16 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Auto-select needles" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2dd2f71bb911aa24" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="16 82 300 24" bkgCol="ff397daa" edTextCol="ff495358"
         edBkgCol="0" labelText="Device Serial Port" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="6d9067a21dbc2451" memberName="needle_serialPort"
              virtualName="" explicitFocusOrder="0" pos="16 106 300 24" tooltip="Title of the Operation Mode"
              bkgcol="ff181f22" initialText="COM16|COM36" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
  <SLIDER name="new slider" id="90b8d711ec3b5129" memberName="fullSyncPlayTimeout"
          virtualName="" explicitFocusOrder="0" pos="822r 32 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ffed6216" textboxtext="fff0ffff"
          textboxoutline="3c3c3c" min="100.0" max="1000.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="" id="d2961cee5a0341e7" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="344 32 190 24" posRelativeY="393a4f32646bf2ab"
         bkgCol="ffed6216" edTextCol="ff000000" edBkgCol="0" labelText="Full sync play timeout (ms)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <SLIDER name="new slider" id="76c94e8940471a6f" memberName="ccMessagesCycle"
          virtualName="" explicitFocusOrder="0" pos="822r 64 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ffed6216" textboxtext="fff0ffff"
          textboxoutline="3c3c3c" min="10.0" max="200.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="" id="9a32073009c62196" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="344 64 190 24" posRelativeY="393a4f32646bf2ab"
         bkgCol="ffed6216" edTextCol="ff000000" edBkgCol="0" labelText="CC messages cycle (ms)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TOGGLEBUTTON name="" id="4cc6ebac49fe7816" memberName="confirmationNoteOnOff"
                virtualName="" explicitFocusOrder="0" pos="344 104 360 24" buttonText="Confirmation protocol for Note On/Off"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="" id="ac3984931dd16cfe" memberName="confirmationCC" virtualName=""
                explicitFocusOrder="0" pos="344 128 360 24" buttonText="Confirmation protocol for CC"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="" id="1b9c4f59adc6eb25" memberName="confirmationOPM" virtualName=""
                explicitFocusOrder="0" pos="344 152 360 24" buttonText="Confirmation protocol for OPM"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="new slider" id="6f7dfd62a9b9675f" memberName="confirmationRetryLimit"
          virtualName="" explicitFocusOrder="0" pos="822r 192 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ff397daa" textboxtext="fff0ffff"
          textboxoutline="3c3c3c" min="1.0" max="10.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="" id="f6b071998fad5def" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="344 192 190 24" posRelativeY="393a4f32646bf2ab"
         bkgCol="ff397daa" edTextCol="ff000000" edBkgCol="0" labelText="Confirmation retry limit"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <SLIDER name="new slider" id="8eaf92a6b83957cd" memberName="confirmationTimeout"
          virtualName="" explicitFocusOrder="0" pos="822r 224 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ff397daa" textboxtext="fff0ffff"
          textboxoutline="3c3c3c" min="1.0" max="10.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="" id="cec5c85ad469fd4b" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="344 224 190 24" posRelativeY="393a4f32646bf2ab"
         bkgCol="ff397daa" edTextCol="ff000000" edBkgCol="0" labelText="Confirmation timeout (ms)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <SLIDER name="new slider" id="5e9db55d152d6307" memberName="deviceConnectRetry"
          virtualName="" explicitFocusOrder="0" pos="822r 267 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ff029d4d" textboxtext="fff0ffff"
          textboxoutline="3c3c3c" min="500.0" max="5000.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="" id="65805ac2fae4a5d8" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="344 267 190 24" posRelativeY="393a4f32646bf2ab"
         bkgCol="ff029d4d" edTextCol="ff000000" edBkgCol="0" labelText="Device connect retry (ms)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <SLIDER name="new slider" id="948450c90be9576f" memberName="UIRefreshRate"
          virtualName="" explicitFocusOrder="0" pos="822r 297 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ff029d4d" textboxtext="fff0ffff"
          textboxoutline="3c3c3c" min="100.0" max="1000.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="" id="33136056baf963b" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="344 297 190 24" posRelativeY="393a4f32646bf2ab"
         bkgCol="ff029d4d" edTextCol="ff000000" edBkgCol="0" labelText="UI refresh rate (ms)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TOGGLEBUTTON name="" id="4ab1bbd887e6b414" memberName="logFailStats" virtualName=""
                explicitFocusOrder="0" pos="648 104 150 24" buttonText="Log fail stats"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="new button" id="81b4e57bbf82b3a1" memberName="ResetToDefaults"
              virtualName="" explicitFocusOrder="0" pos="16 296 300 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ff397daa" buttonText="Reset to defaults"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: background2_jpg, 110571, "../../../../../Resources/Background2.jpg"
static const unsigned char resource_MainViewTabConfiguration_background2_jpg[] = { 255,216,255,224,0,16,74,70,73,70,0,1,2,0,0,100,0,100,0,0,255,236,0,17,68,117,99,107,121,0,1,0,4,0,0,0,96,0,0,255,238,
0,38,65,100,111,98,101,0,100,192,0,0,0,1,3,0,21,4,3,6,10,13,0,0,73,59,0,0,123,134,0,0,238,1,0,1,175,233,255,219,0,132,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,2,2,2,1,2,2,2,2,2,
2,2,2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1,1,3,2,2,3,4,3,3,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,255,194,0,17,8,1,204,3,
72,3,1,17,0,2,17,1,3,17,1,255,196,0,228,0,0,2,3,1,1,1,1,0,0,0,0,0,0,0,0,0,3,4,1,2,6,5,0,7,9,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,5,16,0,2,2,2,2,2,3,0,2,1,4,2,2,3,1,0,1,2,0,17,18,3,16,4,33,49,50,19,
5,34,20,51,65,35,21,6,32,96,36,52,48,112,192,66,17,0,1,3,3,2,2,6,7,5,6,4,5,2,4,7,0,1,0,17,2,16,33,3,49,4,65,18,32,81,97,113,34,19,129,145,161,50,66,82,5,177,193,209,114,20,225,98,130,146,178,35,48,162,
194,51,67,115,36,21,6,241,99,240,210,52,22,211,68,84,116,37,149,54,18,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,19,1,1,0,2,2,1,3,3,4,3,1,1,1,1,0,0,1,17,0,33,16,49,65,81,97,113,129,145,161,32,48,177,193,64,240,
209,80,225,241,96,255,218,0,12,3,1,0,2,17,3,17,0,0,1,252,217,244,124,114,87,129,67,122,138,102,222,162,11,96,37,102,193,130,148,214,81,98,32,111,81,60,211,89,69,136,128,246,6,95,7,177,105,111,94,46,129,
149,205,69,51,100,177,48,40,182,154,202,235,205,56,138,173,138,14,162,42,194,120,2,148,241,0,142,146,115,84,164,23,19,49,247,41,228,40,107,81,117,146,6,44,90,86,44,18,214,45,87,65,75,106,98,197,51,75,
85,36,28,55,168,174,109,170,232,53,136,189,89,3,43,122,138,102,218,188,21,1,41,172,144,18,158,193,75,53,72,115,81,60,221,4,188,107,31,164,101,236,167,44,232,202,141,143,202,10,76,110,231,147,41,43,95,
154,234,228,108,29,130,135,151,232,18,225,83,141,99,165,4,6,245,22,150,32,149,5,34,212,100,87,21,139,0,189,235,117,10,234,34,166,8,139,41,10,150,4,116,147,154,164,36,176,1,147,200,178,184,138,170,230,
13,147,34,185,172,106,82,209,193,42,74,17,13,234,39,154,90,169,32,225,155,2,177,5,176,82,248,154,34,2,86,181,22,205,146,104,136,9,75,87,69,229,53,131,89,41,14,106,39,154,74,241,83,208,68,250,36,222,135,
58,5,57,25,171,59,19,89,189,243,214,227,117,183,71,155,197,176,6,51,92,249,53,172,206,187,181,76,235,86,169,156,123,156,130,111,87,81,53,242,139,136,179,230,186,205,34,70,53,21,205,61,130,89,41,147,40,
178,244,107,122,171,169,8,46,0,233,39,57,110,115,83,172,171,140,23,69,21,196,85,108,80,117,17,86,82,171,197,76,122,90,32,165,59,168,150,105,42,11,2,134,108,18,210,15,96,101,241,224,214,47,43,54,1,98,45,
87,65,75,122,42,45,41,172,162,200,56,115,81,60,219,213,146,146,193,122,178,6,86,245,20,205,189,94,58,246,57,157,231,174,116,106,73,114,183,44,157,53,229,154,35,151,9,89,227,174,22,105,203,22,20,142,176,
101,229,167,38,155,185,12,215,50,230,139,226,176,123,3,47,131,216,182,45,235,213,244,21,149,232,162,11,37,203,11,134,12,153,67,78,5,108,80,117,17,83,146,128,82,18,120,9,211,76,41,194,75,68,131,163,217,
85,20,51,96,37,241,3,22,45,43,22,9,107,22,171,160,229,240,206,162,153,165,170,146,14,27,212,87,54,197,236,162,214,47,87,64,74,214,162,185,182,60,22,192,74,107,33,106,86,47,86,64,202,221,138,75,106,244,
26,197,229,61,144,6,83,89,69,130,176,238,162,89,165,170,158,43,6,176,107,88,103,81,92,219,212,5,69,241,91,212,85,117,43,163,95,32,86,227,72,138,180,128,89,6,93,50,198,177,72,139,41,15,22,0,116,147,154,
164,60,16,92,58,96,172,231,228,202,1,102,170,53,168,174,105,236,162,210,47,82,148,88,134,245,19,205,37,65,96,80,214,160,37,172,26,193,44,69,168,136,9,90,212,91,54,79,6,177,121,75,101,197,229,53,148,95,
20,134,181,21,205,177,224,214,47,41,172,144,18,154,202,47,138,67,186,137,102,146,188,65,88,45,149,81,195,90,138,230,222,162,11,96,37,107,80,18,210,10,68,12,126,190,138,168,43,32,143,20,28,69,22,193,145,
101,33,137,103,90,164,94,146,115,150,197,139,162,234,193,116,81,91,69,214,78,81,147,184,91,20,213,237,7,23,169,42,82,28,212,79,52,149,5,129,67,54,9,71,12,88,25,124,120,61,139,74,205,128,150,11,81,16,50,
222,139,98,217,165,178,171,32,225,205,69,51,109,86,46,139,202,90,186,47,41,108,172,179,67,135,117,18,205,37,120,130,176,74,242,10,86,181,21,205,189,86,15,98,242,177,101,20,80,107,42,181,136,27,177,44,
83,80,171,120,173,43,72,5,168,210,40,183,60,21,22,94,138,32,188,132,225,166,229,87,83,7,68,149,180,93,100,24,250,32,167,36,1,146,103,144,90,6,59,184,150,109,235,197,144,82,177,101,20,80,197,129,95,68,
12,234,43,154,123,6,181,139,85,208,114,205,49,98,153,165,170,196,208,225,189,69,165,244,18,202,45,98,212,68,4,165,170,146,14,28,212,83,54,213,100,170,214,47,86,64,202,214,162,185,182,168,131,216,188,167,
178,0,202,90,169,226,144,230,162,121,165,178,171,226,153,28,17,215,183,116,34,164,32,58,42,175,34,139,1,11,0,46,50,159,52,77,106,245,22,65,143,162,42,64,136,186,220,146,192,14,146,113,151,6,207,162,224,
168,214,72,9,88,176,50,248,168,214,162,185,167,178,139,72,181,93,40,181,134,245,19,205,37,65,96,80,214,160,37,172,26,193,173,98,212,84,94,86,108,94,89,61,70,64,203,234,186,66,210,45,69,69,229,107,81,108,
217,60,26,197,229,53,146,2,82,217,85,241,72,119,89,75,58,37,120,240,56,53,149,81,195,86,43,139,106,138,250,58,209,93,69,212,97,136,6,72,234,115,213,144,71,129,136,51,139,62,128,211,200,170,220,146,226,
231,69,57,235,98,193,17,101,96,205,179,148,134,64,150,210,144,222,162,153,166,178,20,113,106,177,82,144,238,162,89,164,168,46,129,149,155,4,180,131,88,37,244,120,61,139,74,197,129,151,199,168,168,25,109,
70,177,108,210,213,67,34,210,179,96,37,241,224,214,47,41,40,136,188,165,170,146,14,29,212,75,52,149,227,192,224,181,40,25,90,212,87,54,245,88,61,139,230,176,130,94,221,186,245,169,66,167,69,57,170,192,
50,65,14,38,112,1,160,33,108,96,153,110,181,243,93,4,69,124,16,176,184,96,232,146,180,128,89,23,49,90,194,92,233,106,104,100,213,143,3,135,117,18,205,189,64,68,12,172,89,64,82,158,193,75,226,6,117,21,
205,98,193,45,98,213,116,28,190,24,212,87,52,149,5,129,67,122,139,102,248,240,107,1,45,168,200,180,164,168,36,28,57,168,166,109,170,196,3,130,85,208,18,181,168,182,108,212,67,22,45,41,236,128,50,150,171,
148,17,95,80,84,212,229,79,3,25,65,40,199,17,53,184,3,15,112,140,186,138,208,205,115,19,27,102,166,94,242,216,109,16,86,80,43,32,199,209,21,32,64,6,113,51,136,72,12,59,210,39,155,115,213,116,12,167,178,
0,202,123,5,47,138,141,234,41,154,107,42,180,139,85,210,139,88,107,81,76,210,84,22,5,13,106,2,90,193,108,162,214,36,99,81,92,210,84,22,5,14,106,43,155,226,245,5,34,212,84,94,86,108,94,89,32,98,197,165,
53,146,2,82,213,79,20,135,117,18,197,185,227,67,110,137,88,74,168,7,145,37,185,81,164,77,93,69,212,103,17,50,182,82,58,7,208,215,6,115,110,118,115,93,69,16,234,40,182,14,139,45,137,8,139,47,69,57,107,
128,102,32,128,66,234,92,94,83,216,41,102,169,13,234,41,154,90,240,56,181,88,128,112,230,162,121,183,168,130,88,25,89,176,74,56,61,131,88,136,25,212,87,53,139,2,190,138,141,106,2,90,193,108,162,214,38,
142,139,74,197,129,151,199,131,216,180,165,171,162,242,146,160,144,112,238,162,89,183,169,60,14,10,122,40,125,46,208,45,202,141,34,106,218,9,115,168,162,88,101,122,139,218,78,82,224,174,66,120,237,203,
178,62,116,131,62,134,190,91,158,12,138,171,232,154,193,112,136,178,152,225,51,143,134,1,147,165,33,189,69,51,75,94,7,19,86,36,20,57,168,158,109,234,2,32,101,98,202,129,148,246,13,98,32,103,81,92,211,
216,53,136,240,91,4,190,134,117,23,150,177,225,157,69,115,79,96,151,209,1,236,12,179,70,69,165,37,65,32,225,205,69,51,109,86,32,28,18,174,128,149,155,23,150,98,177,171,211,180,211,41,10,184,114,164,3,
58,73,134,56,54,65,39,90,93,169,194,12,189,100,77,91,57,41,144,185,153,126,138,176,181,8,88,9,97,180,65,89,64,173,133,140,86,176,159,59,122,189,131,95,22,169,65,74,230,162,121,183,61,68,64,74,123,60,2,
83,216,37,244,84,111,81,76,211,89,85,164,90,174,148,90,195,122,137,230,146,162,47,96,101,61,131,88,143,5,176,75,232,99,81,92,210,84,22,65,74,222,162,217,190,47,80,82,45,69,69,229,102,197,229,146,6,44,
90,82,147,3,143,161,235,69,60,8,233,39,53,74,120,144,67,6,85,51,41,173,174,156,211,71,48,86,231,153,43,150,51,47,93,114,204,241,104,209,181,107,178,156,245,96,25,32,135,145,69,144,200,186,230,147,61,33,
64,14,110,43,155,36,213,208,50,150,174,139,202,123,5,44,213,33,205,68,243,75,94,41,30,47,80,14,28,212,79,54,245,16,75,3,43,54,9,71,7,176,107,226,176,214,162,153,183,168,8,129,149,173,64,75,88,45,149,90,
69,168,200,180,172,88,25,125,81,12,88,180,164,162,34,242,146,160,152,22,93,29,77,99,110,146,72,32,228,162,11,116,81,95,60,13,37,121,76,230,233,24,37,120,169,17,167,179,177,55,133,185,160,83,75,46,156,
10,208,105,21,89,36,50,42,175,167,49,126,126,205,162,224,104,148,84,90,83,216,37,146,144,222,162,153,164,169,74,75,226,213,32,161,205,68,243,111,81,5,176,18,177,101,1,74,123,6,177,16,53,168,166,105,236,
20,165,176,18,179,96,148,112,107,40,177,16,53,168,166,105,236,18,201,88,61,128,150,212,100,90,82,84,22,5,14,106,41,155,53,108,172,8,234,214,233,84,87,17,85,228,38,113,1,168,174,105,172,117,118,115,84,
76,109,136,148,135,117,18,205,37,65,37,99,233,203,140,78,16,205,139,202,200,216,253,116,102,180,40,178,212,185,112,37,204,253,206,79,35,148,39,74,67,122,138,230,218,174,131,151,197,170,200,25,92,212,79,
54,199,168,168,9,77,100,128,148,246,9,125,21,27,212,83,52,214,85,107,30,9,101,22,144,123,6,177,16,53,168,166,105,172,162,196,64,107,6,177,7,177,105,111,94,46,129,149,189,69,179,124,94,200,90,69,168,200,
174,46,154,171,110,110,205,156,214,133,17,83,9,39,8,228,216,152,217,181,154,59,63,57,34,188,88,20,26,200,5,43,54,47,46,209,64,102,174,86,149,139,6,163,130,84,154,137,123,202,242,115,212,229,9,19,49,87,
11,226,200,93,65,47,170,66,32,37,111,81,92,217,38,136,128,148,182,92,94,83,216,37,146,144,230,162,121,165,168,43,30,171,164,40,225,205,68,243,111,80,53,98,121,165,168,42,122,9,101,22,144,222,162,153,183,
168,130,88,25,90,212,4,181,130,89,11,72,154,98,197,115,79,96,165,154,174,76,39,101,173,53,184,75,137,154,222,47,139,0,58,73,205,94,114,16,104,249,242,122,172,128,149,155,23,150,197,70,53,22,205,61,157,
246,186,18,227,110,100,169,88,232,234,27,58,230,217,39,209,37,170,186,139,45,70,81,117,202,167,6,67,160,21,173,197,243,96,181,93,3,41,40,168,180,166,176,107,37,33,205,68,243,73,82,80,244,90,164,20,57,
168,158,109,234,2,160,37,98,202,129,150,197,235,192,161,189,69,51,111,81,5,176,18,179,96,148,112,107,42,181,136,26,212,83,52,246,13,124,86,15,96,101,154,50,45,139,122,177,190,183,138,103,181,157,150,118,
241,114,194,32,145,130,235,147,185,225,196,213,97,173,69,115,77,103,128,202,74,241,7,78,93,125,159,58,130,84,22,58,210,238,76,241,140,77,234,188,178,64,210,38,174,167,61,126,122,205,226,224,170,212,123,
21,205,45,149,89,7,14,106,41,155,106,186,14,88,47,86,64,202,222,162,153,182,60,22,192,74,123,60,2,83,216,53,130,176,230,162,121,183,168,130,216,9,88,178,138,40,53,148,88,34,27,212,79,52,214,81,124,86,
13,96,214,32,246,45,45,235,197,208,57,173,216,182,109,107,191,90,182,190,114,207,125,117,231,53,115,183,57,248,154,239,203,163,62,116,133,169,64,202,74,130,65,195,186,137,102,222,188,116,13,12,214,74,
226,0,202,205,128,151,74,189,181,195,92,118,230,182,0,84,97,11,130,32,226,92,228,114,49,82,218,14,26,212,94,95,65,108,20,190,38,136,128,149,173,69,179,100,245,25,23,148,181,116,94,83,88,57,102,169,14,
106,39,154,90,130,167,160,150,72,9,77,101,23,197,33,205,68,243,75,80,65,88,45,149,81,195,122,138,102,222,162,11,96,37,107,80,18,214,9,100,102,246,23,156,131,212,94,95,166,46,84,228,38,241,174,13,207,54,
91,32,171,189,47,56,207,89,96,80,238,162,185,186,21,235,141,8,170,172,241,43,155,29,75,54,51,127,63,100,67,86,43,41,172,242,244,101,230,89,222,141,91,84,58,41,205,83,21,46,38,98,110,1,155,88,54,160,151,
199,131,88,188,173,106,45,155,36,209,16,18,146,138,139,74,107,6,178,82,28,212,79,54,245,98,165,98,245,40,41,91,212,83,54,245,72,115,81,60,210,87,136,43,5,178,1,74,222,162,153,183,168,131,88,188,172,216,
37,28,26,170,86,32,111,81,60,86,205,205,210,73,133,67,217,170,154,108,197,220,237,230,222,32,32,185,209,79,156,39,58,172,89,34,93,226,245,4,213,196,85,108,12,69,156,186,239,151,60,153,4,189,120,240,56,
119,81,44,222,201,180,106,224,6,208,74,17,196,89,115,169,152,145,164,86,86,119,4,181,139,85,208,82,218,143,98,185,165,178,171,32,225,205,69,51,109,87,74,45,98,245,116,4,173,234,41,155,106,244,22,192,74,
123,42,181,43,4,169,64,202,222,162,153,182,60,26,197,229,98,202,2,148,214,81,96,172,57,168,158,105,106,167,138,65,227,68,189,235,91,76,41,198,179,191,46,192,249,154,109,199,218,129,100,230,87,78,92,109,
200,17,105,79,102,174,107,182,180,29,68,84,197,197,194,21,46,4,13,206,46,19,175,23,64,202,123,36,219,77,245,145,101,146,163,136,146,180,128,95,158,178,56,185,66,41,189,68,243,73,80,72,56,107,81,121,125,
5,176,75,17,106,34,2,86,181,22,205,147,212,100,94,82,213,209,121,77,96,214,74,67,86,43,45,143,6,177,121,79,100,1,148,214,81,124,82,29,212,75,52,181,4,21,131,89,69,28,53,168,175,58,237,110,110,153,69,84,
201,243,107,31,141,219,88,182,110,186,229,225,92,227,224,246,110,38,242,76,243,70,181,39,55,232,77,25,22,82,30,44,0,233,39,57,110,73,113,113,132,17,200,91,88,156,112,81,35,175,102,146,109,196,34,192,66,
197,10,11,51,243,240,209,5,232,67,54,9,105,6,176,75,232,240,107,23,149,155,1,47,137,162,32,101,189,21,22,148,182,85,100,28,57,168,158,105,42,75,162,242,150,203,139,202,91,42,190,41,14,234,37,154,74,241,
5,96,150,121,69,13,106,43,155,122,136,53,139,230,176,154,171,174,154,176,149,90,25,84,14,179,173,206,248,23,60,120,218,181,157,78,130,38,189,165,206,92,240,34,213,161,151,92,44,189,20,65,100,185,97,112,
225,81,53,109,23,89,6,62,136,41,192,39,206,210,181,39,136,143,166,128,104,164,4,23,50,23,60,200,30,76,234,6,223,68,12,234,43,154,197,130,90,197,170,232,41,109,71,177,92,210,213,73,7,14,106,41,155,33,44,
162,214,47,87,64,74,90,169,32,225,205,68,243,111,86,42,86,9,82,129,149,173,69,115,109,81,7,177,121,79,101,84,80,107,41,155,17,176,186,210,89,206,86,10,11,152,244,223,25,195,36,159,81,85,22,224,11,38,108,
227,107,43,102,235,151,166,60,160,8,50,136,171,72,5,144,99,232,130,152,186,46,183,44,72,3,133,113,147,150,245,226,233,173,155,208,36,11,43,104,186,164,152,36,113,20,205,99,82,150,210,45,87,74,45,97,189,
68,243,73,80,88,20,55,168,188,177,4,178,139,88,181,21,23,149,155,23,150,79,6,176,18,201,123,33,71,4,171,160,37,107,81,108,217,60,26,197,229,53,146,2,82,217,85,241,72,119,81,44,82,141,154,5,235,91,8,101,
8,242,112,23,170,112,83,47,115,184,155,235,167,48,193,166,169,93,48,73,53,190,56,242,233,136,95,3,30,68,214,225,81,101,185,37,197,206,146,115,150,228,132,51,9,68,230,215,38,24,179,107,55,208,6,62,136,
43,37,12,122,113,80,145,82,148,230,162,121,183,168,8,129,149,155,4,180,131,88,37,136,144,246,45,43,54,2,95,30,11,96,101,189,21,22,148,182,85,74,139,202,205,139,203,36,12,88,180,165,171,162,242,150,170,
120,164,59,168,150,105,43,199,129,193,163,182,115,151,71,103,73,174,18,116,215,166,139,43,136,21,203,166,118,231,105,53,211,92,43,34,212,235,231,90,197,249,219,43,86,182,87,19,142,186,133,101,20,91,158,
10,44,116,83,158,182,44,16,88,56,84,77,90,64,44,156,195,33,172,91,55,232,109,72,2,229,143,1,28,79,151,164,199,130,80,70,44,160,41,88,176,50,248,129,157,69,115,88,176,75,88,181,17,5,44,209,236,87,52,149,
4,131,135,53,20,205,147,193,172,4,183,162,34,242,146,160,144,112,238,162,89,183,169,60,14,11,86,64,74,213,138,202,104,221,181,142,185,233,203,172,172,61,154,73,172,219,59,6,172,80,204,92,103,37,215,175,
85,114,172,233,154,234,32,87,54,153,235,158,220,214,137,126,125,115,244,9,72,175,162,107,1,11,0,8,50,136,171,72,5,144,103,65,57,234,80,137,158,51,73,183,87,84,7,73,57,170,67,193,69,142,61,206,86,65,230,
177,66,175,85,97,189,69,51,77,101,86,145,106,186,13,98,27,212,79,52,149,5,129,67,90,128,150,176,91,40,181,139,81,236,87,52,149,5,129,67,154,138,102,201,123,33,71,4,171,160,37,103,81,124,217,168,134,53,
22,205,49,164,94,196,184,38,123,214,233,215,231,172,253,28,249,184,83,66,171,153,116,53,157,165,208,77,117,81,53,228,37,13,17,243,116,122,205,180,222,21,152,173,212,213,73,28,68,21,144,68,130,30,68,214,
193,145,117,146,197,197,202,51,45,20,176,68,89,88,44,138,171,104,186,193,243,246,110,138,102,155,79,80,226,213,98,165,33,205,68,243,73,80,89,5,43,54,9,105,6,176,107,88,144,246,45,43,22,6,95,85,97,173,
64,75,88,45,149,90,69,168,200,180,172,216,188,179,81,12,88,180,165,171,162,242,150,171,7,141,195,71,185,249,182,90,13,93,82,224,238,123,210,130,204,226,6,86,181,21,205,189,63,31,67,84,213,164,249,194,
80,250,27,72,38,21,54,237,50,207,207,13,17,171,106,65,14,162,203,3,40,162,220,240,84,89,122,8,138,201,96,136,178,156,42,38,173,32,22,65,157,4,231,169,207,28,36,199,161,99,192,233,205,68,243,111,81,4,176,
50,177,101,20,80,197,129,151,196,12,234,43,154,123,6,177,30,11,96,165,154,58,1,107,18,49,168,174,107,22,6,95,84,65,236,4,182,162,162,242,146,160,144,112,238,162,121,179,26,133,208,219,192,147,46,157,221,
52,147,88,219,135,38,187,134,5,24,177,105,79,101,79,75,244,182,170,34,152,4,221,211,179,70,51,105,203,179,101,53,144,185,228,154,25,118,2,171,98,3,162,170,242,40,176,92,186,1,72,50,136,171,40,21,176,33,
244,69,72,17,0,178,92,144,7,69,62,104,138,196,132,176,42,123,32,12,167,176,75,226,176,222,162,153,167,178,139,72,154,34,81,107,13,106,41,154,74,130,200,41,79,96,214,35,193,108,20,190,24,212,87,52,149,
5,144,82,185,168,166,108,151,168,7,4,166,35,109,52,253,152,232,224,39,106,221,185,243,148,112,219,53,243,212,82,202,158,41,14,234,108,243,183,196,19,144,104,85,52,1,210,94,29,205,229,232,174,13,155,217,
160,154,214,128,81,133,36,25,225,196,65,88,6,72,33,228,77,108,21,2,190,44,17,22,94,130,32,182,36,42,44,168,38,54,228,88,172,88,45,89,41,14,106,39,154,90,130,145,106,177,0,225,205,68,243,111,80,17,3,43,
54,9,71,6,178,139,226,176,214,162,153,183,168,8,129,149,173,64,75,88,37,144,180,139,81,145,105,88,176,50,248,239,203,177,164,151,29,50,141,157,70,182,43,129,100,117,188,154,86,231,1,23,169,36,20,110,151,
176,170,14,34,203,151,78,18,125,13,101,121,236,190,215,41,50,54,120,211,203,223,94,130,115,84,229,9,4,58,139,44,12,34,203,36,134,69,85,244,73,100,176,84,85,78,21,19,86,144,11,38,1,153,68,243,75,164,213,
35,197,235,192,161,205,68,243,111,81,4,176,50,177,101,20,80,123,6,177,16,53,168,166,105,236,18,145,3,43,58,130,148,112,107,40,181,137,24,212,87,52,246,9,124,68,30,192,75,106,44,155,73,183,232,103,207,
230,87,53,154,118,230,176,172,169,95,73,154,9,133,185,2,2,86,108,94,93,34,233,85,196,73,89,76,122,46,187,85,93,19,30,94,146,100,140,181,149,53,146,246,149,180,18,136,109,21,89,60,48,138,43,200,162,193,
112,130,225,6,81,21,96,25,32,142,130,32,164,46,103,147,36,133,137,161,13,234,41,155,106,240,84,4,167,179,192,37,61,130,95,21,134,245,20,205,53,149,90,199,130,89,69,164,30,193,172,68,13,106,41,154,107,
40,177,16,26,193,47,131,162,210,146,160,176,214,111,209,233,5,231,198,49,159,29,187,117,107,134,184,229,75,244,181,242,240,211,34,140,234,43,154,90,232,27,89,162,144,120,205,38,153,2,214,117,51,214,108,
165,232,171,73,195,49,72,123,52,115,90,5,129,180,73,92,69,214,129,75,1,36,113,16,83,148,36,16,250,38,190,12,129,95,22,8,44,58,159,47,79,101,234,46,160,37,53,150,23,148,246,10,89,170,67,154,137,230,150,
160,172,120,189,144,163,135,53,19,205,189,68,53,168,158,105,172,170,214,32,45,148,90,67,122,138,102,222,162,9,96,101,111,81,105,98,9,90,92,222,229,183,56,179,56,248,98,187,235,163,183,231,172,197,154,
220,239,175,68,79,157,34,213,4,131,143,170,10,52,66,74,148,24,48,87,41,199,208,215,203,98,128,19,0,151,179,87,53,216,82,146,80,168,250,115,148,229,11,1,29,69,150,163,40,186,248,144,232,162,188,137,175,
139,6,69,87,49,115,200,145,124,211,232,58,146,144,230,162,121,164,169,40,68,18,188,10,28,212,79,54,245,1,80,18,177,101,20,81,96,150,85,71,13,234,41,155,122,136,45,128,149,155,4,163,131,89,85,164,72,206,
162,153,191,65,86,22,12,60,139,178,9,117,150,233,43,230,153,82,205,114,180,74,159,89,249,204,77,88,147,71,46,161,72,138,43,136,170,216,249,195,63,66,89,85,81,67,172,165,16,76,69,139,199,209,75,180,98,
165,128,142,32,84,67,104,170,201,225,148,77,93,69,86,11,132,64,45,198,81,21,96,25,203,76,68,142,216,164,183,210,232,53,136,189,89,3,43,122,138,102,216,245,21,1,41,236,128,50,158,193,172,21,135,53,19,205,
189,68,22,192,74,197,148,81,65,172,162,196,64,222,162,121,166,178,139,226,176,197,155,233,185,46,159,52,204,189,65,179,183,160,184,118,19,205,212,91,213,51,105,171,186,204,92,241,145,105,88,178,242,253,
5,170,142,162,42,114,83,38,106,150,166,2,229,56,250,65,13,20,65,49,86,10,62,140,166,85,199,17,85,146,6,209,37,109,0,180,8,93,4,190,29,78,122,156,161,96,35,232,154,201,100,249,170,123,43,81,53,1,43,122,
138,230,201,224,214,47,41,172,176,188,166,178,139,226,144,230,162,121,165,168,42,122,11,100,1,148,214,81,96,172,57,168,158,105,108,133,169,16,107,6,181,134,117,21,205,118,183,115,70,76,204,112,110,87,
150,35,117,170,242,252,223,57,154,212,215,78,107,16,206,157,123,22,224,153,165,138,202,74,217,203,211,82,30,36,9,208,78,122,242,83,129,102,174,86,149,131,52,207,97,170,38,5,58,166,201,167,81,21,105,6,
162,8,88,161,67,160,156,229,57,66,224,7,81,117,160,194,1,96,145,132,81,113,247,28,188,95,85,180,34,2,82,209,17,105,77,96,214,74,67,154,137,230,146,164,169,88,37,120,20,55,168,166,109,234,144,238,162,89,
165,168,34,42,22,202,168,225,189,69,51,111,81,5,176,18,179,168,212,187,57,163,166,22,78,108,120,103,83,103,54,213,159,58,147,199,105,118,117,243,28,194,155,253,85,151,17,114,18,200,73,126,158,168,173,
139,146,0,57,203,71,21,212,229,170,168,35,131,115,172,155,70,204,147,59,25,190,193,36,3,58,41,205,82,144,92,0,226,5,66,56,139,47,136,27,68,149,196,93,106,88,42,98,14,92,134,177,101,45,84,144,112,230,162,
153,182,171,165,22,177,122,178,6,86,245,20,205,181,122,11,96,37,61,148,88,43,4,175,32,165,111,81,76,219,212,65,172,94,86,44,162,138,13,101,86,176,250,253,20,225,203,138,102,164,30,143,166,234,242,229,
194,204,177,168,244,214,206,223,157,76,200,73,126,141,167,25,113,44,197,73,222,151,86,172,34,74,218,44,182,6,60,153,245,200,220,220,221,205,96,238,108,110,165,200,140,235,58,124,236,164,4,69,213,164,170,
174,56,138,172,149,29,68,85,180,10,140,33,112,71,135,83,158,167,50,73,196,144,80,231,72,182,111,168,137,73,106,90,136,128,149,173,69,179,100,240,107,23,148,214,72,9,77,101,23,197,33,173,69,115,108,120,
53,139,202,123,32,12,166,178,139,226,144,238,162,89,165,168,28,54,211,89,235,156,238,84,134,181,39,58,223,234,242,36,201,32,35,65,166,169,175,159,102,82,200,29,93,181,161,79,159,37,236,28,187,133,125,
93,68,148,129,81,101,177,128,185,114,12,187,51,24,112,236,126,55,11,243,196,250,26,178,170,141,162,235,37,7,81,21,105,6,162,8,88,161,67,162,156,213,49,82,224,7,81,117,202,167,22,65,145,83,70,69,229,102,
197,229,147,212,84,4,164,162,34,242,150,171,19,67,135,53,19,205,37,120,42,45,41,172,144,18,154,202,47,138,67,186,137,102,146,188,65,88,45,144,10,87,181,54,121,222,18,228,80,104,94,52,85,170,186,206,201,
155,72,30,93,173,185,6,56,217,167,161,157,53,215,44,217,130,69,169,228,217,205,180,120,32,185,209,78,66,192,225,116,93,121,41,148,185,94,93,88,85,131,180,175,162,10,115,192,66,18,64,51,162,156,213,41,
1,5,199,16,74,1,180,93,124,65,159,185,203,224,205,129,182,11,81,16,50,218,143,98,185,165,178,171,32,225,205,69,51,109,86,42,86,47,87,64,74,90,169,32,225,205,68,243,111,82,120,164,18,165,3,43,90,138,230,
216,240,107,23,151,73,92,0,80,82,177,161,93,21,188,134,113,249,26,155,55,55,88,108,197,172,17,16,123,14,214,214,223,25,134,115,199,122,205,100,220,132,36,9,113,84,228,14,140,42,201,135,70,245,21,205,250,
2,243,206,202,220,177,32,14,146,115,84,164,4,69,213,164,170,174,56,139,47,138,142,162,42,210,9,104,100,19,155,32,207,83,58,138,102,150,170,72,56,111,81,108,223,4,178,139,88,181,17,1,43,90,139,102,201,
224,214,2,89,171,144,14,9,87,64,74,214,162,185,182,32,61,139,202,107,60,6,82,213,79,20,135,117,18,205,36,108,45,234,174,50,78,122,80,60,191,73,211,231,209,207,79,65,105,120,107,83,203,176,107,166,114,
147,36,157,5,221,8,43,40,21,241,193,76,246,178,150,110,133,123,6,29,45,94,58,230,162,107,178,156,229,185,224,162,195,36,138,141,162,235,226,163,200,130,178,148,81,23,46,84,25,208,79,152,192,146,11,234,
10,86,181,1,45,96,214,13,107,18,26,197,229,102,197,229,147,212,100,94,82,81,17,121,75,85,10,139,202,205,139,203,53,16,197,139,74,91,44,2,82,217,85,241,72,119,81,44,210,87,143,3,131,89,18,238,102,186,182,
124,222,22,72,135,244,218,181,152,103,139,3,130,212,20,41,78,106,118,51,173,81,69,230,33,23,176,138,175,134,17,85,229,38,58,205,244,185,129,13,101,76,217,45,95,67,150,202,112,168,154,182,139,172,131,31,
68,21,130,0,151,46,64,19,164,156,213,41,1,14,121,137,98,146,140,99,80,50,248,129,141,69,179,88,176,82,212,154,42,6,91,81,172,91,52,181,82,65,195,154,138,102,205,122,13,96,37,189,17,23,148,149,4,131,135,
117,18,205,189,73,224,112,91,36,12,173,106,43,155,122,98,62,140,168,203,132,100,96,225,202,223,93,100,36,226,72,230,162,89,166,170,21,208,112,197,134,93,12,186,65,101,185,1,145,101,125,19,94,122,12,198,
220,134,82,81,81,105,118,71,105,169,6,62,136,41,139,1,44,88,240,19,164,156,213,33,224,168,178,180,149,85,198,211,48,102,36,172,55,184,164,167,176,107,88,181,93,6,190,134,117,20,205,37,65,96,80,222,162,
217,190,9,101,22,177,106,61,138,230,146,160,176,40,115,81,76,217,171,144,14,9,87,64,74,213,139,75,53,16,197,139,74,123,32,234,77,108,151,156,152,121,41,14,234,3,58,250,46,174,74,78,34,82,13,85,7,6,233,
22,205,45,117,37,209,13,171,232,178,128,229,163,37,0,136,220,230,229,53,131,89,41,13,106,117,51,173,130,144,1,37,139,139,157,20,231,173,207,5,22,25,37,21,86,209,117,144,99,232,130,226,217,74,40,91,75,
21,43,13,234,39,154,74,130,200,41,90,212,12,180,130,217,69,172,72,123,22,149,139,3,47,138,141,234,45,44,65,44,133,164,90,138,139,202,205,139,203,53,16,197,139,74,90,178,2,82,213,79,20,141,237,49,53,198,
76,180,146,14,27,175,161,91,140,142,117,202,217,182,162,29,106,42,247,70,212,97,206,58,101,83,64,186,195,36,102,108,25,32,225,155,1,47,168,200,9,100,209,46,184,89,122,9,201,85,146,195,229,84,225,17,69,
105,0,178,12,232,39,61,78,120,17,99,152,152,217,7,14,110,39,45,234,32,150,6,86,108,24,41,88,176,75,17,3,58,138,230,158,193,172,71,168,168,25,109,70,64,173,98,70,53,21,205,98,192,203,226,6,44,94,91,209,
17,121,73,80,72,56,119,81,44,219,212,146,110,166,158,50,108,231,161,155,22,205,57,244,13,105,84,230,71,74,152,89,14,80,88,64,208,167,206,69,44,169,39,118,93,153,199,49,169,91,1,45,170,2,160,37,111,81,
108,221,195,93,67,148,153,100,78,139,98,217,167,177,217,116,107,210,94,130,32,164,46,4,177,98,64,29,20,230,174,38,68,208,148,16,246,64,25,79,96,165,241,81,189,69,51,79,96,214,177,106,186,82,90,141,106,
41,154,74,130,192,160,246,13,98,60,22,193,75,52,100,90,82,84,22,5,14,106,41,155,37,234,1,193,42,232,9,122,246,107,230,238,124,253,159,88,174,41,232,134,238,235,157,39,52,128,6,158,196,26,198,220,193,39,
118,94,154,99,232,112,205,139,203,175,94,218,157,50,103,34,229,53,172,94,165,7,46,165,117,38,20,230,92,209,100,172,51,168,174,109,168,137,105,122,42,84,154,20,189,244,101,172,218,36,142,215,74,106,19,
53,34,240,198,224,165,154,164,57,168,158,105,172,170,214,60,18,202,45,33,205,68,243,111,80,17,3,43,54,9,105,5,178,139,226,176,214,162,153,164,168,46,129,149,189,69,179,96,37,65,72,181,25,22,149,155,23,
150,106,33,139,1,46,241,76,124,237,9,81,30,139,203,245,45,49,113,158,79,18,62,187,155,126,115,114,172,51,168,28,223,161,53,143,68,238,86,149,139,12,186,217,174,114,118,131,47,41,7,103,42,86,235,175,3,
49,201,58,140,102,232,151,184,9,114,233,159,176,136,9,91,212,87,54,73,162,32,37,233,214,230,95,158,37,108,174,108,149,134,247,20,148,149,37,35,197,234,1,195,154,137,230,222,162,9,96,101,98,202,40,160,
246,13,98,32,103,81,92,211,216,41,73,96,101,106,192,173,32,182,86,90,18,49,98,178,158,193,47,136,131,216,9,111,68,69,229,37,64,193,211,151,157,172,165,155,122,156,142,110,174,185,201,145,144,16,205,128,
95,163,93,100,83,151,114,180,167,179,85,53,210,92,85,202,164,17,31,89,92,194,230,110,124,116,225,133,117,20,94,48,173,205,101,212,175,117,78,138,171,201,134,56,72,74,178,6,91,209,172,87,55,179,93,201,
121,196,29,36,198,228,74,177,74,241,106,144,80,230,162,121,183,168,130,216,9,79,100,40,96,246,10,95,85,97,189,69,51,77,101,86,177,224,182,13,105,26,240,106,104,232,173,236,82,91,89,232,0,185,217,165,229,
227,37,172,232,205,50,156,122,145,56,115,83,45,18,94,188,10,9,68,69,229,232,27,118,132,124,251,57,99,81,92,210,233,244,69,65,113,23,53,32,211,203,177,56,203,153,185,229,26,25,116,42,210,13,120,130,183,
60,185,68,158,58,84,121,116,224,214,129,75,11,24,214,117,84,196,208,211,30,156,250,152,212,215,110,104,129,83,147,22,92,131,34,3,78,106,39,155,106,144,136,9,122,70,246,94,90,130,206,140,188,123,5,29,91,
57,18,232,12,165,157,137,81,171,138,141,203,77,100,217,215,26,231,157,77,88,214,116,84,235,203,201,166,78,93,157,41,77,29,59,18,148,20,2,200,130,245,17,101,230,39,125,82,78,104,181,25,22,149,139,3,47,
170,33,157,72,205,250,27,87,76,156,103,211,199,84,214,221,116,147,42,102,145,138,219,75,10,202,66,174,58,138,45,138,14,34,74,210,13,68,20,144,100,15,167,57,78,80,176,17,228,81,96,58,5,124,72,100,85,74,
152,28,148,178,212,75,1,41,106,232,188,166,176,107,39,119,53,251,41,45,105,52,232,75,197,176,199,65,102,45,168,166,106,213,65,211,154,62,156,161,66,245,7,138,195,218,202,57,209,106,165,98,6,245,23,150,
176,214,162,153,190,44,22,192,74,230,162,210,214,36,181,82,47,70,177,92,211,216,89,119,77,65,212,76,172,162,77,37,44,178,20,144,7,81,158,91,87,32,32,17,196,160,178,184,137,172,146,116,83,152,173,160,148,
39,134,144,43,83,162,156,197,33,5,129,29,20,69,124,25,17,151,13,37,44,46,162,210,183,168,174,108,30,26,212,87,52,180,91,21,205,189,65,37,33,253,101,12,232,149,226,145,3,22,84,12,174,235,41,103,94,36,61,
159,255,218,0,8,1,1,0,1,5,2,138,1,140,40,204,133,64,72,151,112,165,8,145,189,194,247,2,147,15,142,24,127,24,173,80,249,52,71,10,160,195,236,123,114,15,22,68,249,22,90,225,79,131,7,130,90,224,66,120,95,
122,58,152,112,54,0,181,60,175,3,90,212,214,104,236,33,184,205,162,174,81,215,19,13,20,138,216,194,114,63,89,1,209,118,43,232,58,157,189,194,224,202,51,200,224,168,2,33,168,222,230,68,192,183,15,177,237,
234,160,106,30,201,82,56,80,8,131,193,102,6,81,151,23,201,97,92,6,24,193,226,18,76,195,132,246,252,103,224,11,132,87,20,49,139,208,222,221,77,137,183,91,238,233,118,186,202,52,239,41,211,232,118,119,109,
236,235,58,119,244,58,45,223,219,161,55,118,247,236,252,253,167,183,171,166,219,58,227,175,217,58,117,117,119,246,103,162,173,83,163,208,233,118,122,107,249,127,151,219,93,61,46,247,105,58,221,125,189,
167,219,167,118,173,199,169,183,171,216,234,126,103,224,126,151,99,103,68,236,239,127,184,176,245,123,99,126,254,182,238,171,68,244,125,136,90,224,82,120,95,110,40,64,244,39,83,172,79,10,138,68,67,77,
177,131,113,155,87,184,192,14,44,97,21,177,44,217,79,172,212,215,68,236,20,97,216,42,137,155,181,102,174,141,173,202,138,136,106,53,19,50,48,45,194,40,199,170,129,170,124,137,82,56,64,8,62,199,182,107,
148,103,152,60,150,90,17,88,1,7,137,100,192,151,194,123,126,51,161,87,8,174,0,21,20,209,99,148,163,44,196,247,179,187,217,235,255,0,214,191,59,111,99,111,71,169,216,77,253,14,199,99,111,115,254,201,249,
189,239,221,127,223,110,171,127,216,147,189,250,27,15,232,237,235,105,252,201,218,236,116,186,189,39,217,212,238,78,199,120,235,253,159,210,236,117,181,31,217,15,179,110,253,223,160,79,229,118,116,245,
127,235,191,149,223,235,119,247,119,187,9,213,63,177,189,186,61,173,27,247,47,91,95,89,255,0,87,243,251,253,142,191,230,117,78,254,135,87,254,188,255,0,166,201,249,218,123,125,221,127,129,253,158,215,
115,254,186,20,158,7,183,30,34,181,15,102,136,225,84,24,103,83,79,219,181,202,212,201,132,3,34,235,143,10,70,49,78,39,86,211,151,214,120,215,68,237,21,199,216,49,162,103,149,227,5,198,107,53,28,130,123,
58,62,229,201,162,174,81,133,24,213,80,53,66,114,56,144,34,0,99,123,140,215,40,207,80,123,101,0,69,96,1,247,50,38,4,190,23,219,215,1,168,123,36,87,10,5,69,52,89,178,148,101,197,22,88,87,25,12,97,21,14,
205,135,95,95,181,218,235,198,253,207,217,114,118,62,199,217,251,191,179,181,58,221,244,234,116,206,205,140,159,110,237,186,180,126,151,232,244,23,103,103,181,181,135,237,254,178,245,250,159,167,250,61,
21,221,216,236,118,54,183,103,176,243,167,250,63,167,249,131,179,251,223,187,221,211,214,255,0,176,126,239,95,66,254,231,236,105,219,179,246,63,91,111,101,255,0,236,223,246,7,113,255,0,102,255,0,180,25,
167,246,255,0,107,171,179,111,123,187,191,103,91,183,219,252,253,157,207,209,239,254,139,43,84,62,77,17,194,168,48,251,30,217,129,226,200,136,173,181,215,174,58,250,226,48,196,251,6,139,57,104,53,147,
194,124,182,138,157,187,213,179,94,229,58,234,231,149,224,34,145,53,154,59,8,110,51,104,171,148,117,196,194,65,94,238,138,138,213,9,185,137,225,40,199,247,11,131,40,207,35,134,80,4,67,64,251,153,24,171,
112,251,30,222,170,6,161,242,37,72,225,0,32,193,224,179,92,196,240,190,75,138,224,48,2,122,150,76,195,196,79,108,217,76,79,11,228,184,174,50,21,60,137,119,48,241,18,63,185,153,128,92,34,184,32,99,21,177,
135,249,26,60,40,6,55,184,204,8,150,68,246,74,208,136,124,55,190,142,156,1,114,208,33,104,98,252,182,15,17,118,98,190,205,21,227,102,133,221,167,165,182,162,26,109,140,27,140,154,148,100,93,113,226,198,
17,91,24,88,180,250,205,68,85,121,219,210,116,109,153,248,163,60,142,10,138,136,106,55,147,50,49,86,225,240,99,213,64,213,62,68,169,28,32,6,55,177,237,154,229,30,7,146,203,66,43,0,39,169,100,192,151,194,
123,122,60,103,66,174,17,92,6,0,79,34,89,129,56,79,111,231,140,205,1,112,138,226,134,49,77,66,114,152,158,20,3,27,193,140,192,137,100,79,112,165,8,135,195,123,133,201,129,73,135,196,234,105,251,118,186,
128,177,95,17,242,52,71,8,170,65,246,190,25,217,91,140,152,78,194,29,125,132,96,250,226,176,198,41,196,179,22,131,89,227,93,19,180,113,246,120,162,97,5,103,103,79,219,175,17,81,13,70,32,241,145,138,185,
70,20,99,85,64,213,61,156,72,17,40,198,247,11,220,163,61,65,25,64,17,88,0,125,203,38,4,190,23,219,209,224,49,3,228,74,215,11,85,20,209,102,202,4,190,19,219,209,227,34,0,23,8,174,0,21,20,209,99,148,196,
240,160,24,226,140,200,84,242,56,41,66,33,141,238,23,38,5,38,31,28,48,254,49,91,25,243,109,26,14,141,81,21,88,55,134,30,221,213,132,178,32,254,69,211,17,17,134,39,223,109,50,215,214,236,148,113,172,158,
19,229,180,112,54,98,181,114,138,240,17,113,154,205,23,96,220,119,117,148,117,25,70,21,197,140,96,53,9,185,129,168,148,99,251,133,238,81,51,215,12,160,8,134,161,242,101,152,171,112,251,30,222,170,6,161,
242,37,107,132,170,62,199,130,205,115,19,194,249,46,43,140,136,31,34,86,184,90,168,13,22,108,166,39,133,242,92,87,25,10,158,68,185,135,136,134,63,185,153,128,92,34,184,32,99,21,177,132,228,104,240,160,
24,254,15,71,86,78,238,164,75,43,61,150,76,68,214,212,173,236,120,37,203,65,172,183,11,242,218,163,29,250,254,173,157,30,213,235,246,104,175,8,138,68,67,76,236,27,140,154,40,200,186,227,198,67,13,186,
198,196,243,173,137,185,129,225,61,191,185,159,138,38,121,28,21,24,196,53,27,201,153,24,171,148,34,140,98,42,6,169,242,37,104,68,162,15,177,237,154,229,30,7,182,90,17,88,1,61,75,38,4,184,125,143,5,154,
230,36,240,190,220,87,1,128,19,200,150,96,79,17,61,189,30,51,48,11,132,87,30,49,138,106,19,148,196,240,160,24,222,12,44,42,121,16,2,236,189,113,167,84,212,104,63,202,29,132,197,66,208,138,43,239,96,254,
49,95,17,242,56,178,241,218,235,141,154,149,142,183,209,181,118,7,101,110,50,34,15,228,93,49,225,88,97,1,196,150,45,6,179,198,191,151,233,233,163,51,241,83,200,227,17,81,13,70,32,153,145,138,185,70,20,
99,17,80,26,151,115,26,17,42,55,184,94,229,30,7,182,80,4,86,0,31,114,204,85,190,23,219,209,224,49,0,123,113,66,43,0,39,145,44,192,151,194,251,114,15,25,16,0,184,69,112,43,24,166,139,28,166,39,133,0,199,
20,102,66,167,145,198,20,34,24,254,250,58,172,157,132,197,66,209,133,24,224,99,17,241,135,249,28,88,113,173,85,135,103,126,221,27,53,254,130,223,246,116,111,18,205,110,213,245,237,235,236,250,26,35,0,
167,216,52,75,150,139,172,158,19,229,180,112,54,82,213,194,10,199,80,234,218,176,49,77,22,32,202,150,98,140,163,10,48,145,80,26,132,220,194,132,72,254,225,121,68,195,227,134,80,4,86,160,124,153,102,42,
220,62,199,183,32,136,24,137,242,37,107,132,170,62,252,203,49,84,24,98,251,114,15,25,17,62,68,173,112,181,81,77,22,108,166,39,133,162,92,87,25,10,158,71,24,10,136,124,191,147,51,48,45,194,42,42,151,101,
214,169,166,35,99,9,200,224,192,77,106,173,28,83,71,117,34,89,17,208,110,27,180,157,45,58,189,246,214,50,87,157,173,95,98,22,38,116,118,23,135,218,252,182,15,17,118,98,62,68,130,188,34,169,17,13,51,176,
105,70,119,144,210,249,44,43,139,24,192,106,19,115,14,18,63,185,159,138,38,27,28,21,24,197,53,24,217,150,98,174,80,138,49,136,34,6,169,242,37,104,68,170,111,98,22,185,137,60,15,110,65,16,49,19,228,74,
208,137,84,125,143,101,174,98,79,11,237,197,112,24,1,60,137,112,32,168,158,220,131,198,70,1,113,133,113,227,24,166,161,55,58,61,118,227,88,13,54,10,104,206,164,79,43,61,198,214,21,102,182,160,245,148,
253,5,46,161,110,25,214,222,116,59,98,218,251,154,62,182,87,194,117,247,255,0,96,98,87,132,85,32,251,95,12,238,173,40,203,34,15,228,93,49,225,88,96,234,24,50,157,78,88,152,19,132,246,252,103,226,174,16,
71,24,138,138,106,49,185,82,204,81,148,97,70,18,42,3,82,238,20,161,18,55,184,94,229,19,192,140,160,8,173,64,251,225,42,155,220,45,115,18,120,30,220,80,138,212,39,145,44,192,128,240,158,220,131,198,70,
128,202,17,92,10,198,41,162,90,230,39,133,0,199,20,66,150,40,81,53,79,43,46,29,96,44,212,106,108,242,119,111,223,170,31,211,223,23,186,230,127,123,93,235,221,173,227,129,139,40,101,243,172,159,38,136,
157,45,212,223,86,189,201,191,83,105,219,173,219,91,167,103,95,99,92,178,32,254,69,211,17,17,128,83,236,120,37,203,69,215,124,39,203,244,244,138,129,232,123,132,17,192,81,81,77,22,32,202,150,98,139,140,
43,139,24,192,106,19,115,15,17,35,251,133,224,4,195,227,134,80,4,86,168,124,153,102,42,220,62,199,183,32,128,164,240,35,40,2,43,80,62,79,153,102,42,131,15,181,246,228,30,50,34,124,137,90,225,106,160,52,
75,92,196,240,180,75,138,227,33,83,200,227,163,215,7,141,102,142,194,9,159,99,69,92,163,12,76,96,165,59,61,74,138,213,9,200,226,68,211,221,116,154,14,189,171,217,233,253,157,132,234,104,88,195,65,31,78,
179,60,137,217,211,247,43,45,13,91,91,83,117,183,166,205,109,236,66,236,98,166,80,251,95,150,192,42,46,204,71,200,149,43,29,67,175,215,137,139,224,179,3,40,203,48,11,44,43,139,24,192,106,18,76,195,196,
79,111,238,103,224,2,97,21,198,35,24,166,163,27,53,44,197,92,163,10,49,136,168,9,19,217,43,66,43,84,62,77,25,102,42,131,15,177,237,136,34,89,19,217,43,66,37,81,246,60,18,215,49,39,133,246,226,184,14,0,
158,71,1,5,68,52,92,131,20,22,58,239,94,181,92,163,46,60,120,194,43,99,25,178,152,55,26,192,105,250,29,92,24,2,78,190,162,210,105,68,150,82,63,111,74,199,238,168,31,223,219,53,126,150,197,131,191,169,
216,16,103,117,10,184,91,154,246,54,151,209,189,54,205,128,99,21,241,31,34,84,168,154,213,72,62,215,195,59,134,148,103,127,89,139,228,178,215,10,192,44,30,33,98,96,78,19,219,241,159,138,184,69,113,136,
168,166,163,27,148,101,152,162,227,10,48,145,80,26,151,112,165,8,145,189,194,247,2,147,27,193,140,69,64,72,158,201,90,17,61,55,184,94,224,82,120,30,220,80,138,212,39,145,46,42,131,194,251,114,15,25,17,
0,200,176,174,17,177,154,182,13,168,173,137,102,202,96,220,107,0,157,130,139,108,68,135,189,214,10,59,58,26,3,15,153,171,167,171,76,36,8,127,65,82,110,220,251,154,100,96,91,132,81,157,77,184,182,221,99,
110,176,112,159,34,185,235,58,123,170,211,88,86,15,225,135,183,112,194,140,178,32,242,93,2,136,140,2,237,64,234,65,214,197,137,129,47,133,246,252,7,161,238,16,71,0,10,138,104,177,6,81,150,98,139,140,43,
140,133,64,106,93,204,60,68,143,238,23,128,19,15,142,25,70,49,90,167,184,82,132,72,222,225,123,129,73,135,196,17,148,1,21,168,123,62,71,10,160,195,237,125,185,7,140,136,159,34,203,92,45,84,6,137,107,131,
91,49,32,137,209,218,53,237,216,43,129,176,5,155,123,139,166,108,237,110,217,49,21,16,209,214,187,54,58,131,91,187,67,74,236,219,179,176,88,87,6,177,138,213,9,202,98,104,18,14,140,118,47,232,107,250,251,
17,152,30,19,110,221,83,251,157,139,254,230,197,26,187,122,246,205,108,0,106,177,11,177,139,175,40,125,167,203,244,245,1,192,106,30,201,4,112,160,17,23,193,102,6,81,150,98,139,44,43,140,134,48,26,132,
147,48,241,19,219,241,159,128,9,132,87,5,70,49,77,70,54,104,203,49,84,24,194,140,206,0,76,62,56,101,24,197,106,135,201,163,44,197,80,97,246,61,177,4,75,34,123,37,104,68,244,125,143,4,181,192,164,240,190,
220,87,29,1,231,189,166,231,145,58,187,190,221,74,138,68,74,189,221,126,182,200,255,0,159,31,94,237,80,11,154,244,29,143,173,23,90,246,59,9,167,83,51,59,41,168,77,204,79,8,1,143,238,23,21,83,164,231,233,
239,139,214,84,1,16,212,111,112,177,48,45,206,174,252,160,247,178,177,138,248,143,145,42,86,108,65,177,2,212,62,199,182,96,101,25,102,15,37,150,184,86,1,96,241,9,38,4,225,61,191,25,248,2,225,21,197,10,
138,104,177,185,70,89,138,46,48,163,9,21,1,34,93,204,70,49,77,66,108,209,150,98,168,49,188,24,204,8,150,68,246,74,208,137,233,189,194,215,2,147,192,246,226,132,86,161,236,249,28,42,131,58,91,96,163,59,
41,131,245,118,125,123,115,96,0,200,186,227,192,35,24,221,93,76,116,234,250,151,105,250,117,187,182,198,74,37,197,113,152,169,228,113,136,168,134,167,73,134,93,191,254,190,70,42,220,34,140,192,236,135,
163,184,15,41,21,200,112,45,38,176,164,55,200,123,119,12,40,153,223,212,85,135,152,203,66,43,0,15,177,11,19,2,95,11,237,248,15,66,174,16,71,0,10,138,104,177,185,70,89,138,46,48,174,50,24,192,106,93,204,
60,68,143,238,89,138,1,140,40,194,194,165,145,61,194,148,34,70,247,11,220,10,76,62,32,140,60,69,106,30,205,17,194,168,32,251,30,220,131,197,145,20,156,144,135,213,222,213,146,41,241,161,254,205,74,104,
179,150,131,89,49,182,34,68,237,245,178,59,244,49,157,174,207,216,211,200,227,17,81,13,22,32,241,145,138,183,24,81,233,26,223,223,35,250,176,26,132,220,196,137,209,112,187,53,128,103,232,232,190,58,155,
131,245,232,207,34,15,110,129,86,107,96,6,244,93,162,138,54,68,192,183,12,30,222,170,6,161,242,36,17,194,129,81,77,22,108,165,25,113,69,150,21,192,97,140,30,37,147,48,241,19,219,251,153,248,0,152,69,113,
67,24,13,75,185,135,136,145,253,204,224,82,97,21,193,3,24,173,80,249,52,120,85,6,31,99,219,48,34,89,19,217,43,66,33,240,125,250,157,45,231,47,168,184,218,159,94,207,205,127,231,176,80,119,84,93,159,160,
236,61,207,34,116,19,207,96,132,209,20,209,98,15,25,24,6,81,133,113,227,24,13,66,110,117,212,141,221,209,122,18,140,127,112,191,143,51,175,220,217,150,223,241,149,0,126,121,154,216,8,244,76,46,198,42,
101,24,81,30,255,0,79,80,224,53,79,145,42,71,8,1,7,216,246,205,114,143,3,201,101,174,21,128,16,120,132,147,2,95,9,237,248,206,128,23,8,174,40,84,83,81,141,202,50,204,79,111,198,126,0,184,69,113,67,24,
166,161,54,104,240,160,24,194,140,102,4,75,34,123,133,104,68,62,27,220,47,112,41,51,171,215,15,31,89,213,177,199,133,37,78,173,163,235,253,4,182,208,199,86,217,183,86,222,211,127,71,124,29,45,192,236,
235,238,157,53,35,79,127,105,176,50,44,184,240,15,241,10,73,211,210,51,250,218,39,245,53,195,212,208,103,252,120,39,177,215,219,164,205,15,254,235,235,251,17,149,144,204,69,68,53,9,254,79,219,217,179,
94,70,126,104,203,107,12,76,122,198,43,227,62,68,161,1,208,108,92,49,102,247,25,238,81,224,123,101,161,21,128,7,140,137,129,47,133,246,245,192,122,30,225,21,194,129,81,77,22,108,166,39,133,0,150,21,198,
66,161,21,192,2,162,154,140,114,148,120,80,12,97,70,22,21,44,137,119,10,80,136,99,123,133,201,129,73,135,196,17,135,137,171,201,85,0,118,186,231,102,184,170,12,233,181,235,222,185,234,98,12,210,217,234,
200,136,63,145,116,199,132,97,143,112,255,0,242,1,162,88,152,16,196,70,216,221,93,9,170,109,21,192,217,75,87,60,175,27,127,59,91,174,157,108,189,157,102,143,127,71,216,102,70,40,202,48,163,13,99,58,59,
62,189,228,229,10,16,38,176,12,216,41,163,108,6,81,51,191,164,193,25,64,17,26,129,247,50,38,5,184,98,251,122,168,26,135,178,86,184,80,42,15,5,155,41,137,225,124,151,21,192,97,140,245,44,153,135,136,158,
217,178,152,158,20,2,92,87,25,10,158,68,187,152,120,136,99,251,153,152,22,225,21,193,31,198,43,99,15,147,71,133,80,103,83,78,48,123,118,82,59,186,112,123,34,126,121,189,172,152,141,139,131,254,102,207,
246,15,177,224,238,237,235,89,253,213,51,91,253,137,187,255,0,176,227,128,244,58,90,49,90,43,194,162,145,16,211,108,96,220,102,208,32,114,235,143,27,186,186,182,174,206,182,237,112,26,132,220,192,240,
148,99,127,22,211,180,109,67,176,85,19,60,175,12,128,44,214,193,102,204,94,109,214,117,62,68,197,91,135,193,30,222,170,6,169,242,37,72,225,0,32,251,30,217,174,81,224,121,44,181,194,176,2,122,150,76,9,
124,39,183,163,198,126,0,184,69,112,24,1,60,137,100,204,60,68,246,254,230,102,1,112,138,226,134,49,77,66,114,152,158,20,3,27,193,140,192,137,165,25,220,70,215,136,152,174,205,91,23,23,233,26,236,29,132,
206,230,179,247,116,77,109,95,125,238,207,1,168,117,252,234,237,41,93,241,84,17,171,95,217,181,60,51,178,183,25,48,0,100,93,113,224,17,132,83,137,102,45,62,179,198,186,39,126,157,108,79,79,65,159,211,
209,95,241,192,205,218,118,117,218,105,217,244,196,236,105,113,175,179,161,97,216,155,12,205,162,166,81,133,25,250,26,134,205,80,53,79,103,18,4,74,49,189,194,247,40,158,7,182,80,4,86,0,31,114,201,129,
47,133,246,244,120,12,64,246,74,215,10,5,69,52,89,178,129,47,132,246,244,120,204,208,23,8,174,40,99,20,212,99,148,196,240,160,24,226,140,44,42,121,28,20,161,16,206,174,176,169,14,194,96,66,208,138,61,
221,116,221,113,254,244,239,127,25,214,111,254,70,196,217,128,252,248,159,153,173,131,126,112,190,186,29,75,250,36,125,242,200,159,156,153,236,116,196,68,97,137,128,209,103,45,6,178,120,215,89,109,21,
192,217,75,87,40,175,1,23,25,172,209,236,42,111,86,70,70,200,197,25,70,20,85,153,14,173,163,118,136,173,140,39,34,117,144,38,237,35,94,198,247,11,220,162,103,174,25,64,17,90,129,242,101,152,171,112,251,
95,111,85,3,80,249,18,181,194,85,31,99,193,102,185,137,225,124,151,21,198,68,15,145,43,92,45,84,83,69,155,41,137,225,64,37,197,113,144,169,228,75,152,120,136,99,251,153,152,22,225,20,122,103,253,134,81,
132,70,198,19,145,219,164,190,190,160,63,217,214,170,211,244,133,34,156,89,221,88,75,97,27,98,44,70,87,215,250,11,16,248,62,255,0,63,198,179,188,157,195,89,60,39,203,96,241,23,102,43,87,40,175,10,138,
68,67,76,236,26,84,201,162,140,139,174,60,119,235,40,13,66,110,96,103,75,252,26,232,157,130,140,59,60,0,76,236,233,251,53,250,37,70,49,13,70,242,102,70,42,229,15,131,28,138,129,170,124,137,82,56,74,32,
251,30,217,174,98,120,30,217,104,69,96,4,242,37,152,18,225,131,193,102,185,137,225,124,151,21,192,97,83,200,150,102,30,34,123,122,60,102,96,23,8,174,40,99,20,212,236,46,45,209,83,244,206,177,27,149,197,
52,103,82,23,78,61,139,43,59,230,245,20,161,164,229,171,91,80,236,237,93,33,246,54,198,232,237,39,95,103,73,219,160,193,239,170,7,245,123,164,163,234,220,14,191,145,162,188,34,41,7,218,26,103,96,220,100,
98,140,139,174,60,43,12,34,156,73,98,211,235,51,183,171,102,231,215,249,236,79,107,172,250,12,207,199,85,8,208,65,94,48,92,102,182,198,57,12,123,186,105,178,49,87,40,194,140,98,42,3,83,220,43,66,37,70,
247,11,220,163,192,246,202,0,138,192,3,238,89,138,151,194,251,122,60,100,64,30,220,80,138,192,9,228,75,48,32,60,39,183,163,198,70,1,112,138,224,86,49,77,66,114,152,158,20,3,58,186,109,251,70,247,244,118,
15,170,117,118,20,223,187,105,214,48,24,77,70,163,214,95,160,124,23,38,116,1,125,12,40,246,118,253,155,88,120,233,235,220,142,173,136,220,152,109,162,39,68,222,158,222,181,126,191,79,109,50,251,119,86,
18,200,131,249,23,76,68,70,1,96,52,75,150,131,89,60,107,249,109,28,13,148,42,225,5,103,104,3,160,40,173,26,190,221,154,206,37,216,55,25,52,85,202,56,196,205,161,54,234,116,58,216,26,132,220,194,132,74,
143,238,23,185,68,195,227,134,80,4,86,160,125,203,49,86,225,246,61,185,4,64,196,15,145,43,92,37,84,242,37,152,170,15,11,237,200,60,100,64,3,34,86,184,90,168,13,22,108,166,39,133,162,92,87,25,10,138,172,
89,23,4,218,1,126,132,212,106,59,132,238,238,76,245,117,251,143,166,107,173,161,134,38,119,156,62,201,249,155,49,94,198,202,215,163,165,179,104,77,90,245,205,106,173,31,229,221,215,97,152,25,249,231,206,
192,78,177,97,181,50,236,213,53,181,43,123,30,9,114,208,107,45,194,124,182,143,17,118,98,42,201,5,120,69,82,34,26,103,96,211,186,213,171,82,108,218,122,250,21,3,174,60,100,49,138,113,133,139,79,172,212,
237,105,200,63,185,159,138,38,31,28,21,24,196,53,27,201,153,24,171,112,248,35,219,145,80,53,79,145,43,66,37,81,246,61,150,185,137,60,47,183,32,136,24,137,242,37,107,133,170,131,193,45,115,19,194,249,46,
43,128,192,9,228,75,152,10,136,124,245,117,136,198,134,102,126,112,201,153,113,61,143,243,234,97,179,175,189,62,189,186,59,27,58,231,254,71,91,205,221,207,227,16,3,58,126,55,108,79,177,75,174,51,183,216,
109,35,163,183,52,125,75,134,237,103,83,244,246,253,91,91,229,218,79,175,118,158,203,106,116,95,177,79,130,190,246,1,140,87,196,124,142,37,120,69,82,15,181,52,206,193,165,25,145,138,50,46,184,241,244,
107,216,66,170,64,113,37,139,65,172,241,174,175,111,185,246,120,0,152,203,55,107,250,182,98,49,136,106,49,179,82,204,85,184,194,140,98,42,3,83,217,43,66,37,70,247,11,220,196,158,7,182,80,4,86,160,125,
249,28,37,81,246,33,107,129,73,225,125,184,161,21,128,19,200,150,96,64,120,79,110,65,227,35,0,184,186,139,58,168,85,236,16,58,179,243,91,29,140,217,78,202,159,191,162,215,167,185,172,18,226,140,200,84,
242,39,85,171,121,214,2,205,108,20,111,217,246,237,213,176,234,113,184,236,93,253,95,236,35,12,79,87,111,217,175,244,52,135,209,58,93,191,166,31,228,113,97,198,181,86,13,242,30,221,213,133,75,34,15,228,
93,49,17,24,5,48,26,37,139,69,215,124,107,249,109,28,13,148,181,112,130,188,4,92,98,26,46,193,167,115,65,217,175,35,20,101,24,81,132,138,128,212,38,230,20,34,71,247,11,220,162,97,241,195,40,2,43,80,62,
76,179,21,110,31,99,219,144,64,82,120,30,217,64,17,90,135,179,228,75,138,160,240,190,220,131,198,68,65,252,139,46,60,45,84,6,143,77,108,96,211,188,223,237,45,25,211,21,178,118,92,125,191,158,127,151,99,
89,109,83,1,81,12,122,37,14,47,246,52,85,202,118,255,0,134,169,163,164,170,145,31,25,221,209,153,234,185,210,243,118,129,173,219,223,79,179,29,212,138,50,200,158,203,38,34,107,96,21,189,143,16,185,49,
117,229,194,124,182,85,65,179,17,242,37,74,240,138,164,68,52,206,193,165,25,145,138,50,46,184,241,144,199,179,171,234,218,13,66,73,152,120,137,237,253,204,252,0,76,62,56,42,49,138,106,55,147,44,197,92,
161,240,99,16,68,12,68,246,74,208,138,213,15,147,230,89,138,160,195,236,123,114,8,153,17,62,68,173,112,181,70,15,4,181,192,164,240,190,254,188,153,84,42,174,192,23,190,109,252,137,208,255,0,32,65,93,175,
243,254,115,227,217,216,65,157,157,127,94,236,140,2,225,21,199,140,116,156,181,43,99,59,103,61,61,46,169,169,216,112,186,122,251,67,172,238,104,19,167,187,236,93,218,190,196,101,42,197,104,117,123,87,
53,176,1,170,225,118,49,80,180,34,138,251,216,6,49,95,17,242,37,74,240,138,164,31,106,105,157,195,74,50,204,81,145,117,11,194,176,194,3,140,44,90,125,126,39,99,87,216,143,238,103,226,137,132,87,24,138,
138,106,49,179,82,204,85,184,194,140,98,42,3,83,220,41,66,36,111,112,189,192,164,198,240,99,16,68,4,137,236,149,161,19,211,123,133,174,5,39,133,246,226,132,86,161,60,137,209,75,43,173,72,155,218,251,14,
65,159,159,254,76,216,13,227,46,198,191,225,182,119,117,135,209,1,168,77,204,79,31,156,67,234,216,40,145,97,74,46,185,250,4,135,87,101,109,33,219,76,58,49,111,176,109,157,158,191,218,11,52,11,115,175,
217,184,60,71,172,98,190,32,255,0,35,137,2,107,85,33,190,67,219,184,97,70,89,16,121,46,129,68,70,1,79,177,226,22,38,46,187,227,95,203,111,3,101,0,9,133,74,206,198,191,171,104,2,162,154,44,110,81,150,98,
139,140,43,140,133,64,106,93,204,40,68,143,238,23,184,1,48,248,225,148,1,21,170,123,133,40,68,141,238,23,184,20,152,96,140,160,8,173,67,217,242,56,85,4,69,246,228,25,165,62,189,121,176,30,227,251,159,
153,87,55,154,236,22,184,168,72,62,67,107,250,246,184,174,51,21,63,61,138,180,250,198,51,89,163,250,84,119,244,244,125,141,155,70,33,83,78,225,180,127,171,86,61,174,175,217,1,198,93,158,182,242,68,214,
21,163,138,104,219,3,10,51,200,131,201,116,10,179,91,0,173,236,120,133,216,197,215,148,62,211,229,178,170,7,196,124,137,82,188,34,169,17,13,51,176,105,221,210,91,93,152,162,203,10,227,33,140,6,161,36,
204,60,68,246,254,230,126,0,38,31,28,21,24,197,53,15,147,70,89,138,160,198,240,97,120,20,152,124,112,202,49,138,213,15,147,70,92,85,6,31,99,219,16,68,178,39,178,86,167,89,51,221,172,140,79,190,203,225,
168,181,192,164,206,135,180,172,187,130,183,78,190,209,253,121,222,210,113,129,69,68,52,116,236,3,124,205,162,174,81,151,25,223,79,227,161,6,190,188,238,237,163,155,101,215,221,246,137,172,3,59,189,64,
236,65,4,184,157,94,206,115,202,240,218,192,89,173,128,13,87,11,177,138,153,67,224,175,189,149,81,95,17,242,37,74,241,173,84,131,237,77,23,112,210,140,179,20,100,93,113,226,212,235,117,193,199,136,73,
51,14,19,219,241,159,128,46,17,92,80,168,166,163,27,52,101,152,160,24,194,140,36,84,4,137,238,21,24,197,53,9,179,70,89,138,160,198,240,99,16,68,178,39,178,86,132,67,224,251,133,174,126,126,150,34,45,95,
233,208,17,90,135,64,92,242,38,251,251,149,1,157,79,240,35,5,109,165,94,111,212,117,108,200,192,50,140,181,198,157,131,102,136,167,18,205,148,109,57,44,214,1,61,195,125,141,90,219,107,106,93,122,117,209,
158,87,142,207,73,54,163,43,33,67,83,71,107,237,48,187,24,169,148,97,68,120,155,43,24,175,136,249,18,132,9,173,84,134,249,15,110,225,133,19,60,136,60,151,64,162,35,128,167,216,241,11,19,23,94,92,118,210,
182,191,1,232,85,194,43,128,5,69,52,88,220,163,46,40,184,194,140,200,84,6,165,220,194,132,72,254,229,152,160,24,194,140,44,42,89,19,220,41,66,36,111,112,189,192,164,195,7,182,30,39,76,141,93,115,228,209,
19,178,249,238,85,6,31,127,157,225,118,50,176,217,231,102,68,78,135,243,215,221,95,175,78,173,131,106,111,212,55,104,128,209,45,115,3,58,27,60,37,19,176,87,31,96,11,83,202,195,108,253,126,170,233,213,
54,246,127,174,189,126,207,221,198,109,54,117,87,178,187,117,54,151,4,131,215,236,174,253,81,91,24,78,68,161,2,107,10,99,252,163,108,12,40,207,34,15,37,208,42,205,108,0,106,177,11,177,139,175,40,125,167,
203,101,84,15,136,249,30,246,163,244,69,2,162,154,44,217,74,50,226,139,44,43,140,134,48,120,132,147,48,241,18,63,185,159,128,9,132,87,24,140,96,36,75,185,133,8,145,253,204,224,82,97,241,195,1,140,86,168,
124,154,60,34,103,8,198,15,125,141,170,53,75,34,123,61,77,120,245,224,48,207,206,106,29,166,47,163,168,229,30,118,180,83,184,224,61,13,47,245,237,242,56,84,82,38,179,77,176,134,154,52,255,0,242,179,104,
5,206,195,231,176,18,167,175,191,239,211,21,177,157,157,67,178,175,165,245,148,118,214,221,103,77,203,176,83,67,176,17,70,121,94,25,0,89,173,128,13,68,194,236,98,166,80,138,43,239,101,84,87,196,124,137,
66,162,107,10,67,123,83,71,105,27,23,19,112,121,44,181,192,96,22,15,18,201,129,56,79,111,198,126,0,184,69,113,66,162,154,140,114,148,101,152,145,253,204,224,4,194,43,138,24,197,53,9,179,71,133,0,198,247,
25,129,19,69,253,191,34,218,241,29,231,164,79,77,238,117,152,255,0,95,19,140,30,250,98,166,223,58,195,80,234,110,251,3,39,141,250,78,151,85,4,69,240,122,187,198,221,115,54,1,70,69,215,30,6,56,206,222,
223,175,94,173,27,55,205,125,29,122,196,214,3,77,187,31,167,185,29,118,47,103,90,238,215,137,190,174,227,167,100,40,161,102,182,198,57,4,204,218,42,101,24,81,30,38,202,198,43,227,62,68,161,81,53,133,33,
254,67,219,184,97,137,51,200,131,201,116,10,38,234,77,176,120,132,147,2,95,11,237,248,15,66,174,17,92,0,42,41,162,199,41,71,133,23,24,81,153,10,132,87,20,49,138,106,49,202,81,225,64,49,133,24,88,84,178,
39,184,82,132,67,52,127,246,97,216,76,236,19,183,105,130,48,241,168,86,166,217,134,159,102,136,157,19,254,226,235,87,83,239,91,148,117,236,39,99,94,221,67,114,184,125,76,63,145,101,198,106,216,117,62,
183,86,215,20,209,103,45,6,179,198,186,39,126,143,183,124,251,0,93,155,83,88,209,217,251,27,185,175,61,90,156,233,154,182,174,229,236,104,184,196,25,212,217,246,234,205,162,174,81,198,38,49,24,197,108,
97,57,18,132,9,172,3,31,195,70,216,8,162,103,145,7,183,64,171,53,176,80,213,112,179,24,186,242,157,241,91,215,219,215,1,168,123,36,17,194,129,81,77,22,108,166,39,133,22,92,87,25,10,131,196,178,102,30,
34,123,99,148,196,240,160,24,226,140,200,84,242,37,220,195,196,67,27,220,46,96,82,97,20,122,158,59,12,163,29,239,245,234,86,168,124,154,51,201,58,209,72,237,255,0,29,67,219,48,35,165,254,108,153,97,249,
178,208,211,180,233,125,27,21,245,246,116,46,224,65,70,44,76,8,76,233,110,137,242,216,40,65,178,150,174,81,94,2,41,29,141,227,74,230,89,198,204,92,127,49,180,29,111,161,219,91,134,87,94,222,143,173,186,
155,66,108,138,216,194,217,79,172,212,215,70,108,31,202,54,192,69,19,60,175,12,128,44,214,193,67,81,48,187,24,169,148,97,68,123,217,68,64,229,71,232,127,45,133,107,132,0,131,236,123,102,185,71,129,228,
178,215,1,128,19,212,178,96,78,19,219,241,159,128,46,17,92,100,42,121,18,238,97,226,39,183,247,51,48,11,132,87,20,49,138,106,19,145,235,130,55,78,219,7,102,240,99,48,35,64,189,214,86,119,13,233,43,66,
126,123,86,246,249,108,241,180,177,48,41,51,70,243,165,181,149,105,220,234,174,212,101,100,33,168,127,175,95,119,216,145,17,72,136,105,182,50,183,7,97,85,98,221,141,191,209,223,63,160,243,72,195,71,125,
41,193,169,167,176,218,220,233,27,117,108,70,212,253,102,27,87,104,243,62,207,0,19,13,175,5,23,25,173,130,199,32,153,155,24,169,148,97,71,212,122,198,43,99,62,68,161,81,53,128,67,252,187,255,0,38,107,
148,120,30,217,104,69,96,1,226,201,129,47,133,246,244,120,200,128,5,194,43,128,5,69,52,89,178,129,56,79,111,71,140,204,2,225,21,197,12,98,154,132,229,49,60,40,6,48,163,6,192,11,48,69,103,98,222,225,74,
19,243,191,204,255,0,46,241,254,5,201,129,73,157,111,29,129,239,182,181,182,43,80,246,122,251,219,65,12,24,63,87,87,97,55,105,125,46,61,174,236,27,91,141,171,145,16,127,34,233,136,136,195,29,169,154,105,
214,154,35,57,104,53,158,59,96,29,110,56,232,246,241,157,205,31,98,116,88,253,115,5,198,107,52,92,134,51,54,138,185,70,24,152,196,21,138,216,194,114,39,89,2,107,0,205,159,40,219,46,5,38,27,16,123,253,
53,1,162,181,3,238,89,48,45,195,237,125,189,84,13,67,228,74,215,11,85,20,209,102,202,98,120,95,37,197,113,145,0,11,132,87,2,170,41,162,205,148,196,240,160,24,226,184,200,84,242,37,204,60,77,157,139,210,
222,230,102,5,185,209,74,51,244,171,133,108,102,131,125,140,72,157,175,254,194,128,99,123,30,217,129,154,59,13,164,166,220,149,145,119,78,207,65,180,9,211,236,253,6,193,131,193,46,90,13,100,240,181,123,
251,93,116,159,223,215,19,244,244,129,175,110,189,199,186,10,245,224,81,83,169,184,108,84,3,87,106,100,209,87,34,235,143,25,12,34,182,48,182,83,235,32,77,116,102,207,148,59,44,0,76,54,56,100,1,102,182,
11,24,130,103,121,203,111,85,184,125,143,111,68,64,213,62,68,173,112,149,71,216,246,205,115,19,194,249,46,43,128,192,9,228,75,48,39,0,209,102,202,98,120,90,37,197,112,24,84,242,37,204,60,68,246,244,120,
204,192,46,17,92,16,49,138,216,206,160,255,0,107,19,59,173,123,212,3,27,193,209,254,103,117,35,183,254,123,34,123,133,104,69,62,19,115,105,125,29,132,219,11,147,54,116,19,124,221,215,217,164,244,187,63,
91,236,3,24,175,136,249,18,190,55,116,209,167,215,92,126,104,255,0,127,244,182,41,211,44,192,44,245,159,233,218,201,100,48,194,41,196,150,45,62,179,83,93,19,180,121,159,103,128,9,134,215,130,139,140,214,
216,199,33,140,201,162,38,81,133,24,228,17,185,179,220,26,167,200,149,161,18,140,111,113,154,229,30,7,182,80,4,86,0,25,234,89,129,47,133,246,244,120,200,128,190,220,87,1,128,19,200,150,96,65,194,123,122,
60,102,96,23,8,174,60,99,20,212,39,41,137,225,0,49,197,29,107,142,178,234,70,243,150,239,35,141,105,91,39,100,214,230,247,11,147,2,220,48,123,63,198,105,238,196,216,2,159,228,118,244,181,180,212,143,173,
81,85,129,246,191,39,117,97,59,122,139,162,140,155,87,95,250,250,187,187,50,216,167,248,193,226,22,38,117,239,110,169,175,229,180,112,54,80,162,97,5,120,193,113,154,206,37,200,99,50,104,139,148,113,137,
140,192,172,86,198,19,148,58,200,27,95,13,122,227,123,133,238,81,51,212,17,148,1,21,128,7,220,179,21,110,31,107,237,200,60,100,64,249,18,181,194,213,79,34,89,138,160,240,190,220,131,198,68,64,50,37,107,
129,85,20,209,102,202,98,120,80,9,113,92,100,42,121,19,80,207,111,214,2,147,65,15,150,171,154,220,253,138,165,167,124,99,190,16,49,138,216,195,252,142,36,112,128,24,187,182,105,109,61,237,100,182,212,
216,181,44,137,242,44,152,137,173,128,83,239,87,95,94,173,157,174,230,3,18,220,47,183,227,243,183,86,186,184,65,94,21,84,136,134,153,216,52,163,50,104,171,145,117,196,204,134,49,91,24,88,180,250,200,19,
85,19,179,220,59,60,119,152,224,124,112,84,99,16,212,62,76,200,197,91,135,216,246,228,17,3,84,249,18,180,34,85,31,99,193,102,185,137,60,47,183,32,136,24,137,242,37,107,133,170,128,209,45,115,19,194,209,
46,43,128,192,9,228,75,152,10,136,124,189,25,209,91,219,246,52,223,254,2,43,143,24,235,255,0,34,54,51,244,14,91,241,60,32,6,55,184,204,15,10,174,98,116,183,57,31,157,167,82,128,0,214,212,27,219,22,3,254,
73,90,47,103,67,67,219,235,131,253,253,32,246,59,187,28,64,212,61,154,35,133,80,71,67,252,168,105,157,131,74,51,35,20,100,93,113,224,48,194,41,198,22,45,62,179,83,95,189,190,231,217,224,2,97,5,120,193,
113,155,54,231,181,141,154,150,98,174,81,133,24,196,84,13,83,217,43,66,37,70,247,11,92,196,158,7,182,90,17,88,1,60,142,18,168,251,30,203,92,10,79,11,237,197,112,26,132,242,56,8,15,9,237,200,60,100,96,
23,24,87,29,20,3,175,59,143,138,147,115,19,198,144,14,205,130,143,123,252,165,133,79,34,5,119,159,208,223,138,254,124,209,214,235,164,108,110,29,140,102,206,206,181,155,119,237,119,235,119,3,29,128,99,
217,234,253,144,28,39,200,226,71,10,1,7,216,246,204,15,22,103,231,46,91,29,49,17,24,5,125,154,208,255,0,115,66,159,239,105,105,175,13,156,107,249,109,224,108,160,1,48,130,188,96,184,205,103,18,236,26,
81,153,52,236,190,58,216,81,132,140,96,53,46,225,74,17,35,251,133,238,81,48,248,225,148,1,21,168,31,38,89,138,160,195,237,125,185,6,5,39,129,237,133,8,173,67,253,124,137,102,42,131,194,251,114,15,25,17,
62,68,173,112,181,80,26,37,174,96,102,181,193,53,128,79,233,31,247,166,98,162,88,123,155,250,43,180,142,142,169,171,171,215,88,218,244,131,14,198,128,92,125,154,144,158,238,133,150,175,171,118,221,197,
149,177,135,249,28,72,157,110,213,77,106,173,59,93,84,218,118,106,125,44,204,15,22,68,246,89,104,69,52,15,190,166,191,167,89,114,102,206,194,36,217,217,219,178,47,183,224,61,13,125,157,202,83,181,173,
184,69,82,34,26,103,96,210,140,200,197,25,23,92,120,200,97,234,110,220,118,108,38,230,30,34,71,247,51,241,68,195,227,130,160,8,166,161,242,101,152,171,112,248,34,57,4,64,196,79,145,43,66,43,84,62,79,153,
102,42,131,15,181,246,228,30,50,34,124,137,90,225,106,160,240,75,92,196,158,22,173,197,113,213,166,219,60,172,218,249,236,196,84,67,70,193,121,216,238,108,208,71,117,218,55,117,196,254,246,217,214,221,
247,234,237,166,90,20,212,39,41,137,157,45,222,123,61,113,177,91,220,102,7,142,158,246,43,254,187,53,46,27,122,51,22,213,15,184,88,152,22,231,250,244,250,184,182,246,68,77,253,182,217,3,80,246,104,137,
70,40,4,69,240,89,129,136,251,82,14,255,0,96,65,222,218,75,247,55,8,59,219,166,175,210,214,87,230,187,95,183,161,191,185,217,49,123,91,196,213,220,214,243,179,186,63,25,248,162,97,21,198,35,24,166,163,
27,52,101,152,171,113,133,24,196,84,4,137,238,20,161,18,163,123,133,238,98,76,111,6,49,4,75,34,123,37,104,68,244,125,143,101,174,5,39,133,246,226,132,12,0,158,71,1,65,0,149,61,77,227,108,237,236,81,170,
100,96,25,70,21,53,255,0,147,198,29,241,20,212,38,230,38,117,31,29,200,170,243,114,125,123,33,97,66,193,214,249,107,237,105,250,156,160,2,33,169,173,240,221,189,118,21,95,210,121,167,102,173,209,212,70,
233,233,51,111,231,120,254,134,216,157,34,38,190,190,180,59,251,11,162,108,218,251,74,0,70,190,182,221,167,87,79,74,19,245,213,25,223,80,164,121,44,181,194,176,2,15,16,177,48,37,241,213,222,218,118,108,
250,247,235,219,172,234,112,254,0,184,65,28,5,21,20,209,99,114,140,179,20,92,97,70,18,42,2,68,187,152,80,137,31,220,47,112,2,97,241,195,40,2,43,80,247,10,80,137,27,220,47,112,41,60,15,110,40,69,106,30,
207,145,194,168,60,47,183,32,241,145,16,127,34,172,218,91,179,189,118,106,21,140,6,137,107,154,148,253,147,180,161,181,56,174,51,20,44,16,72,157,228,173,152,10,136,106,116,219,36,125,99,106,238,93,154,
152,45,194,40,143,109,88,239,234,174,216,218,246,104,139,216,220,8,238,110,80,63,65,98,119,180,25,179,190,50,126,214,237,145,152,24,154,223,97,211,211,26,224,242,93,2,137,173,128,95,208,112,119,75,102,
129,47,133,246,252,117,180,182,208,58,58,76,223,249,239,172,116,118,81,239,106,82,145,77,22,32,202,50,204,81,113,133,113,144,198,3,82,238,97,226,36,127,115,56,1,48,248,224,168,198,41,168,124,154,50,204,
85,6,31,113,58,137,179,166,223,154,151,223,252,237,58,123,111,249,186,58,250,122,159,149,172,119,15,85,95,87,91,74,47,71,103,228,169,221,255,0,11,183,88,127,207,254,182,164,233,235,237,107,111,192,223,
7,83,170,15,245,213,181,107,234,117,117,235,212,186,83,188,218,7,111,119,95,162,163,175,181,116,110,235,246,181,245,181,234,48,120,37,174,5,39,133,171,113,92,105,97,156,216,132,167,152,20,84,95,7,198,
59,245,125,218,201,97,0,184,194,167,231,130,16,214,27,53,174,213,126,174,205,80,135,39,171,210,216,12,214,1,155,7,151,233,233,121,179,164,103,244,187,51,250,221,133,131,173,188,207,248,237,212,157,4,19,
64,77,74,213,112,187,24,169,148,114,18,107,211,183,177,179,250,90,81,106,163,162,108,77,157,93,202,74,149,138,142,243,173,249,249,76,113,138,105,157,195,70,235,94,221,255,0,89,70,101,216,236,181,192,97,
140,6,161,36,204,56,235,109,77,111,218,252,193,216,218,223,131,191,67,127,197,237,250,135,253,107,185,177,181,254,110,189,131,119,231,14,166,193,253,68,233,244,147,70,196,95,205,209,176,117,58,143,223,
125,93,30,166,205,15,210,80,116,104,208,157,110,206,158,186,110,77,26,119,37,245,119,235,126,182,180,126,194,127,95,119,178,84,99,253,205,159,213,94,238,193,185,191,95,46,218,247,251,161,255,0,229,123,
38,117,156,234,99,222,76,95,245,14,229,127,217,190,207,91,245,191,170,231,244,207,217,253,208,177,123,72,154,245,118,246,235,237,47,124,236,102,239,50,246,31,115,108,93,191,175,191,126,215,236,7,215,183,
115,108,81,237,197,8,26,132,242,56,10,12,211,254,109,102,155,99,6,157,174,177,39,35,0,202,104,235,150,121,227,14,207,84,109,159,94,221,101,52,109,220,83,71,214,147,88,6,108,20,97,216,42,140,242,188,20,
1,102,182,168,228,19,11,177,138,153,70,20,71,189,149,140,87,196,124,201,66,162,107,10,67,124,135,183,101,121,70,121,131,201,116,10,35,118,117,232,215,187,115,110,97,226,89,48,37,240,158,223,140,232,85,
194,42,30,255,0,218,201,222,64,71,235,108,71,215,250,75,171,106,119,87,250,251,255,0,72,118,246,191,111,99,167,95,122,13,103,244,157,102,191,212,254,188,255,0,146,93,122,223,244,50,58,59,141,165,31,182,
251,123,27,59,108,219,54,111,83,175,95,110,219,115,253,155,39,152,42,26,225,190,49,110,27,229,61,55,177,237,175,145,237,177,169,175,209,247,60,193,143,11,242,217,192,202,180,255,0,159,133,248,238,254,
165,233,254,142,109,235,132,198,61,112,63,199,5,241,252,56,213,239,111,202,31,179,145,31,225,53,92,127,124,46,20,223,33,239,103,198,127,42,135,26,154,190,45,242,95,109,156,124,177,217,158,105,239,103,
11,120,159,124,12,56,79,150,206,60,207,16,215,31,255,0,152,183,14,92,164,127,115,205,114,113,175,255,218,0,8,1,2,0,1,5,2,255,0,246,159,250,241,254,147,215,254,99,255,0,103,241,255,0,226,175,255,0,153,
235,255,218,0,8,1,3,0,1,5,2,255,0,223,171,255,0,85,255,0,78,63,212,123,247,63,215,255,0,19,199,250,15,252,61,255,0,225,254,159,233,255,0,169,89,226,207,254,94,127,240,185,102,89,150,121,179,47,255,0,229,
150,175,253,214,255,0,246,239,255,218,0,8,1,2,2,6,63,2,62,87,255,218,0,8,1,3,2,6,63,2,62,87,255,218,0,8,1,1,1,6,63,2,232,55,101,110,158,135,162,212,181,108,158,165,10,183,66,244,126,131,40,229,152,252,
177,249,123,104,6,170,203,169,232,247,210,158,132,226,186,166,236,167,0,72,238,161,92,17,37,24,204,56,40,198,65,198,177,151,88,171,81,186,5,213,171,173,2,225,210,118,232,105,75,161,64,244,117,116,239,
209,101,106,216,112,166,211,117,132,79,52,247,123,189,246,210,27,124,88,165,60,143,178,195,183,204,79,133,221,252,254,174,8,226,205,143,38,60,177,45,44,121,34,97,146,39,186,87,66,123,141,190,227,4,102,
60,7,54,28,152,132,236,246,231,23,89,50,140,57,78,60,92,190,110,65,142,92,152,249,203,14,99,160,126,11,105,25,98,203,139,14,243,62,28,24,247,51,195,63,39,155,46,65,142,196,216,172,152,207,193,35,29,25,
219,143,164,44,152,35,47,47,63,233,55,27,157,172,12,9,253,84,246,208,57,142,48,218,25,66,50,229,235,54,226,176,109,54,248,252,204,219,156,184,246,248,113,143,123,38,92,211,242,226,61,36,173,222,219,97,
207,245,44,123,92,185,33,250,141,182,12,134,57,113,227,159,39,152,209,114,33,46,14,183,217,249,249,127,67,12,51,148,12,111,63,59,112,54,237,216,206,142,228,109,243,29,188,75,28,227,22,67,132,31,204,204,
164,54,187,108,217,229,24,243,72,97,197,60,166,49,237,228,5,16,108,69,136,54,32,132,86,247,234,27,253,230,235,105,131,107,186,216,108,192,217,236,49,111,243,101,205,191,197,184,204,45,155,113,182,17,136,
27,99,196,234,179,199,233,127,83,223,101,221,96,218,238,247,158,71,212,126,147,139,97,12,216,118,59,121,110,242,136,79,109,187,221,120,198,56,74,77,32,1,109,93,79,46,223,105,186,220,99,199,254,230,76,
59,124,185,97,142,220,215,48,4,11,33,139,6,28,185,242,157,49,97,132,178,206,92,116,131,149,44,25,48,228,199,154,50,228,56,103,9,71,40,151,87,44,174,235,14,63,169,225,222,108,49,206,64,204,203,103,47,60,
98,123,152,227,220,75,16,159,243,5,13,166,215,234,159,93,158,89,243,206,255,0,248,247,211,97,143,30,60,80,57,103,57,202,127,85,17,134,60,112,6,82,145,176,23,91,157,175,210,78,127,171,226,195,151,44,112,
110,54,251,60,209,150,231,4,39,202,50,121,94,41,64,75,86,42,113,229,144,48,255,0,112,49,6,12,121,111,213,117,13,188,246,219,136,238,50,114,152,97,150,28,131,52,196,238,26,36,57,116,113,238,49,101,195,
150,62,246,60,216,229,138,113,244,78,244,191,78,213,178,25,166,60,63,0,249,136,163,223,186,158,180,26,140,143,96,39,189,6,46,225,222,151,96,72,163,171,167,236,122,49,11,177,168,205,193,88,18,140,37,110,
61,160,163,9,112,246,167,161,116,226,186,166,163,116,30,154,34,130,209,104,153,94,183,163,209,223,162,202,213,118,187,116,246,24,182,249,167,134,25,190,179,245,191,56,225,145,199,60,162,59,47,167,52,73,
141,249,70,173,163,250,23,210,183,185,55,89,35,151,97,151,255,0,39,143,235,78,51,188,222,109,182,120,190,157,180,49,242,99,44,152,201,158,41,238,37,60,126,49,203,35,204,191,242,8,109,242,253,95,117,130,
63,74,142,92,199,121,40,254,158,57,99,190,194,99,41,70,38,126,39,247,111,214,182,27,60,243,7,105,139,31,210,241,224,217,202,92,187,57,101,255,0,183,226,156,4,227,35,202,217,115,55,57,43,105,31,59,117,
159,125,147,127,134,25,182,251,137,78,81,153,142,97,205,12,144,201,110,72,181,193,30,31,66,199,12,114,140,119,255,0,74,222,79,101,187,201,55,229,31,68,203,184,50,199,184,159,238,237,36,101,9,159,148,192,
112,88,254,165,176,142,93,182,13,172,240,195,232,198,98,248,182,255,0,77,229,142,46,195,48,0,51,235,145,39,138,223,127,228,91,104,71,30,215,123,181,135,253,130,1,155,30,235,234,241,158,60,162,63,254,196,
67,52,31,132,196,15,21,244,124,95,171,250,206,223,107,47,167,109,247,56,163,177,199,183,27,108,219,185,255,0,245,19,127,50,38,121,35,155,154,14,110,0,3,69,12,155,209,186,142,61,198,199,232,127,247,29,
230,244,237,163,186,222,109,15,254,64,34,51,100,242,37,34,37,228,89,231,121,0,37,197,204,223,123,255,0,146,224,250,150,45,207,233,225,182,195,182,218,136,98,34,126,92,112,99,196,50,242,249,95,8,131,114,
178,150,219,54,47,169,253,39,101,63,168,125,79,115,176,63,76,220,108,183,91,115,9,111,14,222,81,150,60,57,4,12,240,202,6,32,140,190,227,112,105,29,142,226,123,188,187,216,238,126,159,143,46,13,214,227,
15,145,188,203,135,30,231,46,211,251,227,159,47,142,39,25,136,60,231,194,2,221,249,158,119,247,113,109,99,187,230,196,223,218,199,201,229,115,90,194,209,101,245,156,153,182,27,79,168,196,253,107,255,0,
29,128,195,188,158,250,24,227,35,177,250,153,230,31,246,252,216,39,204,25,189,230,236,89,246,24,62,139,244,255,0,165,254,167,99,191,27,143,168,253,59,39,213,101,185,218,109,161,178,201,57,203,155,234,
91,157,196,99,133,191,221,104,131,40,60,92,58,250,126,211,63,212,190,181,250,189,175,211,254,149,250,125,159,210,240,195,105,177,219,126,163,103,143,116,60,169,121,242,148,231,62,113,57,76,64,115,76,150,
179,21,255,0,144,13,230,15,170,109,118,187,255,0,168,125,43,245,91,221,142,235,0,222,226,250,148,62,153,250,169,98,220,66,98,62,103,153,44,146,159,192,242,137,60,45,183,250,158,219,117,245,63,172,125,
59,105,131,235,91,89,230,206,49,125,47,235,223,77,193,56,237,177,228,56,38,115,110,132,241,99,243,226,64,142,156,217,28,68,30,101,245,13,151,209,62,161,245,143,169,75,254,143,60,190,147,245,45,148,27,
158,127,80,197,177,132,240,100,195,184,203,253,254,108,160,123,145,240,25,93,100,250,55,211,114,195,60,242,242,255,0,222,126,169,139,255,0,206,100,143,139,244,216,79,255,0,164,197,33,175,252,73,14,109,
4,27,232,24,229,187,250,214,215,109,185,219,238,179,231,255,0,182,226,219,126,155,115,245,56,125,67,46,41,249,178,57,96,101,155,30,47,44,8,203,221,129,4,123,215,221,253,75,110,119,242,223,127,246,174,
81,139,234,159,82,253,40,222,238,182,159,253,215,244,253,182,25,255,0,211,206,121,57,240,75,204,16,203,59,218,45,238,45,198,243,103,159,115,250,172,191,82,59,127,172,238,225,147,39,234,113,236,14,8,75,
109,3,147,222,24,179,101,243,121,131,177,49,139,240,91,217,125,70,121,115,97,219,111,54,120,254,145,155,112,103,146,112,221,100,230,57,177,98,150,75,249,103,23,138,96,88,17,30,187,214,213,178,122,61,3,
218,17,188,207,98,2,54,229,176,28,26,140,181,66,129,216,81,212,240,75,254,25,120,127,203,149,253,137,248,81,136,65,180,160,12,246,186,176,37,117,56,163,142,170,23,209,147,133,111,126,58,118,142,164,218,
112,106,53,56,116,30,154,35,70,90,38,87,173,232,244,214,129,119,81,186,14,221,13,41,116,40,199,170,177,196,103,51,138,19,158,72,99,50,62,92,50,101,17,140,136,26,3,33,8,191,114,195,61,182,231,62,222,120,
39,147,46,9,97,205,147,25,195,155,44,6,57,74,60,135,195,41,8,128,72,213,148,76,190,167,189,60,158,103,36,124,252,158,92,78,92,126,76,154,62,235,202,37,141,151,153,150,115,203,54,3,154,114,51,145,17,143,
32,188,186,128,66,18,250,167,212,12,71,40,190,239,51,145,140,137,69,203,185,17,32,55,82,222,12,56,247,63,247,13,254,12,155,77,198,238,121,227,229,67,105,151,40,201,49,24,136,243,25,228,17,229,36,203,71,
181,237,12,114,201,57,99,199,204,113,227,50,38,24,204,245,97,160,118,88,246,211,207,154,88,48,75,44,240,96,150,73,28,56,167,157,185,204,98,109,19,62,80,237,171,41,97,217,239,183,59,124,51,60,242,197,143,
52,227,136,228,102,230,229,211,155,183,85,158,121,119,57,242,79,114,199,115,44,153,178,78,91,130,37,207,227,50,62,43,245,168,237,135,212,247,195,20,113,121,49,128,220,230,240,98,229,229,228,23,113,15,
221,209,75,30,211,123,184,219,226,156,185,167,139,30,89,12,82,158,143,203,238,243,118,169,103,220,230,203,184,207,62,94,108,217,242,75,46,73,8,142,81,121,185,176,11,39,62,124,210,243,99,8,101,230,201,
51,230,67,19,114,137,62,162,44,25,101,63,78,250,150,255,0,97,231,114,121,223,161,221,238,54,158,111,150,252,188,222,68,135,55,47,49,101,45,182,243,235,95,86,221,237,230,220,248,55,63,81,222,103,195,62,
83,204,30,57,102,65,98,161,182,195,245,143,168,97,195,134,60,152,99,143,119,154,30,70,51,240,192,130,240,137,125,5,148,115,97,250,166,242,19,142,215,22,200,24,110,50,15,250,60,1,161,136,252,208,143,0,
86,29,236,254,165,190,59,189,176,35,109,184,253,86,104,229,219,68,185,108,102,39,192,46,125,213,143,39,253,227,234,48,158,25,156,152,165,139,121,159,1,199,148,194,88,185,135,146,98,210,229,145,15,212,
87,255,0,232,254,187,255,0,247,31,80,255,0,241,22,226,120,126,171,191,140,247,121,60,237,217,253,86,105,126,171,55,207,144,76,145,57,95,83,117,159,54,227,121,186,207,151,119,8,226,221,100,205,184,203,
146,123,156,80,156,114,8,228,51,47,48,37,8,144,15,80,234,95,168,216,110,115,236,243,49,137,201,182,203,60,83,150,51,172,79,38,177,60,65,178,132,247,251,205,206,238,88,227,201,139,245,25,167,148,98,129,
46,209,18,180,71,96,171,212,161,86,66,3,222,145,96,163,17,126,179,214,105,126,234,58,187,46,13,70,60,80,109,22,44,241,225,225,151,106,137,30,32,67,250,213,130,234,163,246,123,105,232,78,41,170,213,147,
118,83,80,9,138,243,163,199,223,239,235,171,210,245,106,55,64,191,67,84,80,92,58,78,213,209,105,75,161,75,209,232,239,93,42,197,10,49,234,173,211,191,10,26,181,26,150,161,163,244,90,140,175,91,211,205,
144,241,75,221,236,143,237,92,23,10,15,82,13,70,103,86,30,132,250,82,67,139,91,243,4,112,203,190,29,252,69,45,70,118,90,161,75,150,113,71,87,79,217,67,25,7,4,46,95,135,88,30,202,51,112,232,61,10,113,93,
107,175,65,233,162,52,209,104,153,94,183,163,209,223,162,202,221,23,163,191,69,186,22,26,143,240,90,157,74,245,61,32,227,193,27,207,185,88,51,83,174,234,195,94,9,244,163,162,130,238,163,104,156,22,230,
62,100,79,106,132,198,165,196,187,36,40,28,209,213,211,217,168,196,33,213,70,103,179,43,46,167,10,222,252,111,20,253,149,181,117,77,210,122,105,86,101,162,110,133,232,244,119,160,90,209,186,14,221,7,122,
235,70,255,0,10,245,110,202,221,62,180,61,22,165,171,97,115,193,7,12,117,145,253,234,93,30,244,59,211,81,180,87,58,241,173,202,43,156,107,143,197,232,226,154,94,228,181,236,61,105,236,212,191,20,26,128,
51,171,5,212,244,126,207,109,47,212,173,78,120,218,51,234,225,47,219,208,239,29,7,166,149,102,163,82,212,46,173,77,86,168,160,181,233,105,93,22,148,186,20,110,131,218,186,86,232,81,187,58,15,217,67,86,
163,82,194,135,165,230,157,33,238,254,127,216,154,141,162,185,244,167,214,151,60,81,79,212,174,158,212,30,165,165,184,250,84,163,195,88,254,82,188,163,121,195,78,216,171,15,66,125,40,13,2,183,10,51,173,
80,165,206,161,74,7,143,30,162,136,58,135,20,127,79,69,155,133,26,150,161,78,41,170,214,172,253,45,17,166,139,68,202,234,221,7,163,189,116,173,208,110,131,209,235,110,151,11,143,240,90,157,72,71,82,75,
4,34,11,183,219,66,250,39,28,105,193,149,153,50,10,221,116,244,171,13,120,39,210,158,104,247,177,235,219,21,205,29,98,84,50,13,56,246,46,234,51,178,185,213,10,7,52,117,116,238,26,140,67,168,230,142,158,
236,219,175,133,25,149,170,253,149,181,117,171,63,65,250,44,203,68,212,181,108,157,106,181,160,90,209,149,213,171,100,235,84,239,91,26,48,232,112,184,233,94,173,217,91,167,214,133,89,28,167,133,163,223,
197,118,43,50,106,22,161,90,106,159,74,93,23,132,76,9,60,164,56,67,154,6,55,224,121,191,4,208,157,245,109,15,182,134,62,191,177,24,240,55,137,236,42,231,193,51,226,236,237,165,207,26,63,82,186,119,13,
70,60,80,106,0,202,193,117,58,49,58,72,50,32,143,16,232,235,208,215,81,91,167,232,179,81,169,106,21,100,235,85,170,40,45,122,101,58,214,161,107,70,232,112,163,173,42,197,10,55,103,65,251,43,110,131,33,
17,169,44,132,32,0,240,143,79,26,21,165,211,154,23,224,141,27,219,70,209,114,79,73,89,248,133,40,29,65,111,69,57,114,248,160,250,252,67,241,92,208,144,148,77,193,9,199,191,15,16,237,236,160,197,34,63,
112,253,212,30,165,110,6,140,202,195,208,186,168,237,64,87,21,162,142,81,195,195,38,160,165,207,10,221,61,26,172,220,40,212,181,10,181,53,90,213,158,253,7,167,114,52,210,141,77,122,92,59,235,165,110,131,
116,30,143,91,116,184,7,29,9,102,144,176,180,126,250,23,171,94,157,74,232,157,104,93,18,56,211,205,249,109,47,202,106,56,192,159,20,80,148,25,139,74,203,158,62,228,253,146,86,213,220,118,47,253,193,239,
14,190,212,250,81,217,30,244,23,26,51,178,185,215,138,30,154,7,42,80,55,6,200,131,172,73,20,122,138,51,43,85,251,58,58,244,25,239,91,167,161,122,179,81,169,106,217,61,56,89,26,105,208,181,108,158,143,
91,26,48,232,112,163,244,47,65,17,172,139,40,226,189,160,7,165,169,212,234,232,157,109,66,250,39,141,253,151,87,197,30,95,153,204,130,247,113,55,87,44,191,21,238,67,214,66,105,70,67,185,164,188,18,7,179,
143,168,162,3,119,35,19,164,131,122,212,162,117,5,189,84,117,229,75,73,123,189,146,253,170,81,152,236,82,199,46,6,221,177,81,156,75,16,83,197,223,136,234,149,27,69,115,175,21,233,165,207,20,83,245,43,
167,112,212,239,81,205,22,183,134,109,236,163,43,85,219,163,175,66,230,237,91,167,232,179,43,38,165,168,85,147,173,104,80,90,209,169,106,217,61,74,11,90,55,67,133,31,160,197,10,53,58,169,44,231,128,104,
119,181,15,83,39,6,141,193,153,89,147,80,134,143,136,105,107,174,124,66,220,97,213,221,87,209,147,100,241,199,252,225,115,11,250,209,147,136,192,128,253,111,162,247,121,143,92,174,152,98,135,242,69,127,
181,30,241,0,254,196,218,39,248,227,167,104,234,167,52,125,35,129,11,152,30,58,113,5,22,239,79,212,174,157,194,40,43,53,142,148,101,101,116,98,116,144,100,65,23,137,110,152,165,207,10,221,63,103,69,155,
130,181,92,117,80,215,94,131,63,72,171,83,90,20,22,180,110,135,14,149,208,106,217,61,30,182,66,34,228,150,10,56,227,164,67,119,154,55,101,56,2,99,221,71,236,163,154,49,94,110,48,209,248,162,56,118,166,
1,201,208,47,239,19,167,187,21,224,198,7,107,93,31,135,173,94,124,223,151,197,251,17,228,198,79,108,165,248,47,119,31,170,95,138,60,209,198,223,196,23,136,24,63,29,66,230,23,29,97,115,143,115,38,163,170,
84,120,250,71,9,32,99,252,81,58,133,102,235,175,122,115,107,209,218,225,30,244,23,21,161,67,32,252,178,76,80,165,232,234,233,248,84,81,153,90,174,7,15,240,89,238,213,186,122,26,233,208,103,173,235,126,
8,211,78,133,171,100,244,126,139,116,4,129,105,117,161,33,220,71,81,78,180,93,154,209,138,29,76,188,83,140,123,200,92,167,35,217,172,36,85,178,15,75,143,181,120,78,188,65,76,110,20,231,23,145,55,15,240,
197,57,44,58,202,144,199,226,253,227,238,167,148,201,236,208,14,131,83,202,123,79,65,251,193,74,7,142,157,133,16,69,221,187,154,156,241,60,164,38,203,224,151,95,194,127,4,250,250,117,69,14,244,215,90,
38,87,226,189,52,185,83,135,9,34,14,177,45,77,106,27,133,25,90,174,223,224,177,60,43,116,253,22,101,100,212,45,66,174,158,134,186,81,169,106,217,63,64,85,186,28,40,244,0,113,209,16,117,22,92,179,247,50,
88,246,30,180,27,74,1,173,149,147,71,197,46,205,7,165,94,100,14,168,217,61,244,122,122,23,246,73,29,114,184,1,0,79,49,226,89,159,212,174,120,90,35,82,174,88,112,135,10,240,14,58,14,80,35,80,95,210,132,
155,80,8,244,162,64,180,192,151,167,74,53,26,19,148,123,1,178,190,71,254,24,254,10,226,51,246,31,98,111,114,93,71,138,46,120,162,220,110,159,169,93,59,208,40,229,139,94,211,3,175,164,237,211,20,191,85,
29,93,59,240,232,179,112,86,77,75,10,26,235,208,101,100,212,45,67,71,169,66,173,254,21,208,106,121,132,63,37,135,230,43,206,128,252,255,0,138,125,19,19,226,133,143,111,82,123,247,82,250,53,223,69,104,
1,249,124,63,98,254,220,253,18,252,66,241,68,129,214,46,40,32,59,228,122,130,17,141,128,245,146,184,121,147,143,134,63,252,112,70,82,46,79,70,245,106,114,252,165,143,245,125,234,50,63,12,189,146,79,66,
234,221,15,42,101,228,61,210,126,32,130,96,214,187,87,180,167,42,80,60,71,181,17,33,226,137,99,232,69,10,104,153,93,10,94,142,174,157,250,44,173,87,2,237,254,11,61,110,172,56,127,130,213,189,110,143,74,
213,178,122,58,56,79,105,138,99,161,112,123,136,70,31,41,183,108,74,29,83,240,159,74,97,101,170,20,187,7,31,178,142,220,146,235,138,32,177,145,62,240,234,71,36,189,23,247,138,50,145,114,85,208,163,118,
83,170,143,66,178,14,176,37,234,178,159,103,47,245,138,181,57,32,30,71,130,127,1,236,6,254,212,65,23,234,60,20,102,61,224,66,25,56,16,8,244,210,226,225,30,244,59,211,50,208,174,113,161,180,255,0,48,87,
173,232,244,214,162,140,173,87,110,134,157,22,39,133,110,158,135,166,213,186,122,30,139,82,213,178,122,148,42,200,16,88,187,131,218,161,49,241,107,216,66,243,6,176,215,242,171,168,158,58,30,240,157,93,
151,98,241,78,35,188,221,49,159,249,103,247,5,24,227,151,93,154,67,183,141,57,117,132,60,35,168,211,170,143,217,91,116,71,104,144,246,115,125,200,139,3,35,15,181,250,14,81,137,248,195,3,218,139,132,114,
1,120,183,166,31,178,156,159,41,49,127,243,45,10,101,122,223,173,78,60,37,236,40,131,172,75,31,69,53,160,86,110,147,183,67,74,93,10,94,142,174,157,248,116,91,177,90,182,28,43,116,239,67,208,178,106,22,
161,163,212,161,86,232,94,167,17,210,119,143,100,130,225,202,67,21,56,124,164,143,66,150,35,164,188,67,191,68,25,25,72,176,11,150,15,8,246,123,198,157,74,121,15,15,8,239,213,25,7,230,151,134,61,230,182,
233,112,184,232,99,61,191,109,148,187,12,79,181,149,234,202,202,56,167,126,102,28,206,197,100,125,57,39,253,40,149,146,63,148,162,233,197,53,90,162,16,67,44,91,170,99,183,160,244,209,20,41,162,101,116,
41,122,61,29,234,40,202,213,176,212,116,52,232,178,181,108,56,116,52,232,181,111,91,244,103,41,222,55,128,239,92,146,191,87,104,42,200,72,106,11,143,66,4,95,155,197,235,10,57,98,61,239,9,239,213,99,158,
158,47,97,181,60,16,151,151,27,7,240,196,158,187,175,128,122,127,5,240,127,55,226,189,195,110,171,253,136,6,46,101,43,53,245,101,143,24,54,136,50,244,200,208,80,58,229,1,207,80,92,217,75,126,236,117,245,
175,246,193,237,36,148,254,86,54,215,64,189,198,238,36,47,4,253,19,252,66,241,65,135,2,47,26,98,13,241,69,74,29,96,132,98,108,69,136,163,246,80,161,40,235,247,133,200,194,254,241,28,69,36,31,224,255,0,
80,77,70,112,253,84,61,171,180,167,42,80,58,72,41,70,67,197,18,200,209,153,104,153,94,183,163,209,222,189,212,110,131,181,250,26,82,245,99,213,208,210,228,116,52,232,183,101,110,158,135,162,212,181,4,
5,204,138,17,128,208,39,102,156,125,222,222,202,152,252,146,35,208,110,165,217,226,31,195,122,99,151,19,17,235,209,54,139,93,80,160,114,178,118,48,245,4,245,17,141,201,76,220,210,62,244,144,109,40,3,58,
176,93,79,78,124,94,9,51,242,252,43,28,100,24,243,63,170,234,253,75,206,197,171,120,227,214,220,122,92,46,40,63,120,24,253,234,233,205,11,132,104,205,233,86,5,121,131,133,166,175,91,244,53,160,171,116,
29,171,162,210,151,66,129,232,234,233,223,135,74,245,110,202,221,59,240,161,171,81,169,106,26,61,78,67,198,208,252,168,38,94,96,247,103,175,100,191,106,101,40,147,239,71,236,63,181,117,221,78,63,44,136,
244,41,68,159,114,118,238,144,116,83,245,38,156,131,252,162,229,120,96,91,180,128,163,54,103,225,233,89,31,231,40,53,121,219,197,59,247,65,62,148,123,247,86,212,215,69,193,197,197,189,8,14,202,56,35,30,
66,61,7,189,94,46,62,104,248,133,94,160,139,51,55,161,9,113,210,67,168,174,86,224,172,19,122,232,72,161,116,120,137,11,133,40,245,104,122,197,53,174,189,45,17,66,154,38,87,66,151,163,209,222,186,209,149,
170,30,143,71,126,29,22,232,88,106,63,193,106,8,11,113,145,234,136,64,104,3,1,216,19,187,210,112,150,156,15,81,82,7,129,80,254,47,177,211,89,147,143,138,32,255,0,165,78,29,113,246,196,160,188,188,54,0,
248,228,62,234,227,97,240,139,44,143,111,23,218,30,142,163,14,219,247,11,161,192,43,112,163,58,213,10,7,58,143,217,71,87,79,102,103,163,16,131,227,137,183,80,94,233,29,210,63,122,111,238,105,243,71,240,
94,9,201,251,64,63,98,229,152,103,208,141,8,167,60,110,8,188,79,16,159,156,14,177,34,34,71,173,23,203,15,230,9,225,33,46,226,15,217,77,86,169,169,204,27,158,23,110,184,244,30,154,35,70,101,162,110,133,
232,244,119,160,90,233,70,232,59,95,160,239,91,81,186,26,106,58,87,171,118,86,233,232,87,153,169,201,236,2,212,224,202,201,148,114,141,13,165,222,160,221,103,250,105,142,95,152,44,103,172,183,243,6,71,
151,194,77,129,60,21,242,250,163,251,83,249,146,245,4,91,33,23,249,127,106,132,12,159,148,235,165,137,71,182,49,63,233,251,168,202,114,61,66,32,246,159,253,16,165,232,234,236,158,205,70,33,221,6,210,128,
51,171,46,167,163,142,175,109,61,11,148,255,0,232,122,212,160,117,142,171,90,137,68,144,70,132,40,201,192,148,163,113,251,194,135,181,93,18,104,109,225,151,138,63,133,89,168,221,2,172,158,154,208,45,122,
78,213,209,105,70,40,81,186,28,58,87,66,141,217,208,119,123,80,167,29,6,81,236,50,254,167,69,133,10,211,85,56,144,206,61,168,62,177,231,127,83,43,240,67,254,96,254,146,163,47,150,64,250,139,171,119,131,
194,141,162,124,147,229,237,212,174,120,191,188,215,236,88,231,223,31,189,94,134,95,251,159,96,71,20,180,148,4,227,222,11,20,246,160,65,168,204,234,193,117,81,255,0,248,122,218,154,232,181,100,41,9,61,
231,141,143,120,183,65,208,252,210,76,66,236,163,55,5,96,140,62,45,71,122,191,14,8,181,10,113,77,86,181,103,232,61,52,69,5,162,209,53,45,208,122,59,215,74,177,66,140,122,14,252,43,110,149,184,138,117,
147,96,20,35,241,114,14,110,217,18,234,93,147,63,96,161,127,122,50,49,61,224,178,245,81,148,242,112,148,7,243,19,251,19,104,160,231,254,32,254,147,76,103,247,7,176,50,46,140,245,127,116,117,149,205,50,
231,236,10,112,234,147,250,199,236,82,102,240,248,191,151,246,80,40,183,207,34,86,28,163,80,254,196,8,191,53,213,135,161,62,148,116,80,86,225,70,117,170,20,14,104,234,233,220,54,170,2,3,64,92,232,46,83,
25,199,249,73,65,216,196,216,74,58,61,25,184,40,6,224,255,0,205,226,93,78,40,227,170,133,211,133,230,196,120,101,239,118,75,246,173,86,181,103,232,61,52,70,140,203,68,212,183,65,214,169,222,129,107,165,
26,150,173,147,209,235,106,55,67,133,199,74,235,204,35,195,31,119,182,95,177,79,208,61,81,89,35,218,62,202,110,49,105,205,41,17,252,50,81,156,156,199,153,167,214,1,92,226,92,192,135,4,105,66,250,39,28,
86,56,246,200,250,168,25,188,50,148,125,174,153,31,150,30,24,166,2,253,136,147,2,33,32,197,236,141,157,212,226,220,109,220,157,119,76,254,43,153,175,9,131,232,209,75,12,184,146,96,135,125,91,69,115,175,
20,40,28,209,213,211,189,168,199,138,13,64,25,213,130,239,89,31,128,127,72,41,251,16,143,195,172,187,151,99,39,29,212,213,106,201,187,41,44,114,62,252,125,71,84,96,117,137,171,208,213,154,141,75,82,234,
201,214,171,84,80,90,209,186,15,71,90,167,160,90,233,70,232,61,168,253,6,40,81,187,40,35,29,101,101,24,112,138,201,45,94,82,35,214,178,255,0,7,222,139,232,200,204,27,121,210,126,226,84,227,215,27,119,
139,174,83,124,71,135,82,230,132,129,9,169,46,93,34,57,125,87,52,203,30,216,159,90,156,244,60,190,221,2,231,151,131,31,95,25,119,47,12,111,215,172,138,191,4,84,114,141,99,105,119,38,83,135,116,135,216,
167,143,78,96,71,165,11,144,65,215,136,33,9,252,78,210,29,70,151,60,81,79,212,174,157,195,80,63,27,32,220,62,250,51,43,15,66,234,122,2,212,117,103,92,156,102,125,130,235,150,30,190,1,114,3,115,115,38,
247,138,20,185,212,81,213,211,219,74,121,128,94,35,197,249,106,205,70,165,168,85,169,170,214,172,253,46,228,105,165,110,181,163,116,56,116,152,160,212,29,7,175,157,252,49,252,81,61,64,159,85,50,129,213,
19,237,76,178,126,114,161,43,3,60,99,214,202,113,237,183,113,186,120,29,117,137,247,74,241,192,194,93,158,32,136,198,8,253,243,102,238,172,163,215,11,122,10,229,58,56,50,237,2,235,151,179,134,150,167,
151,11,78,98,253,113,138,228,145,188,15,249,74,47,119,183,160,163,3,232,61,113,81,145,45,23,99,221,43,34,220,81,60,37,227,30,148,255,0,4,173,33,216,132,162,65,137,226,136,65,89,172,105,215,117,97,170,
125,40,237,64,87,27,45,19,58,185,213,10,115,230,145,151,1,29,0,136,238,92,177,0,1,212,157,93,59,134,163,16,232,119,53,25,184,50,178,229,63,16,184,236,40,199,134,177,237,138,113,213,91,83,94,131,61,250,
15,78,228,105,165,26,150,173,147,211,133,145,166,149,186,13,208,122,61,109,70,164,96,53,151,177,8,141,0,101,144,216,25,67,151,171,222,240,211,39,228,251,214,139,47,122,111,150,68,122,13,212,102,220,57,
79,219,86,236,167,82,198,253,163,214,17,58,210,68,150,2,234,121,62,99,234,26,33,49,195,81,214,16,63,12,134,132,47,11,115,195,79,193,17,212,162,126,40,248,101,232,79,22,230,199,226,97,198,60,105,229,203,
220,145,177,63,1,93,233,205,169,113,162,61,232,119,166,189,27,69,115,170,20,185,163,171,167,112,212,239,65,168,3,43,5,212,244,112,46,222,218,122,21,151,48,30,44,110,127,135,138,215,161,173,200,173,211,
244,89,168,212,181,10,178,117,173,10,11,90,53,45,91,39,163,208,85,186,28,40,232,229,34,230,209,238,226,187,58,208,29,114,30,160,152,169,126,79,245,83,32,237,251,150,72,246,3,234,178,156,120,179,199,174,
215,163,246,80,171,40,203,229,144,62,162,235,177,89,150,79,201,253,86,167,62,64,60,194,1,17,249,120,250,232,120,187,47,58,3,197,241,196,113,237,94,43,66,86,149,13,188,38,241,252,40,49,100,63,146,95,114,
107,173,19,104,174,87,93,233,115,197,22,79,212,174,157,195,80,32,205,110,20,102,86,245,43,241,163,181,30,154,45,86,168,81,164,117,8,143,132,222,61,212,186,126,139,50,178,106,22,161,86,166,189,6,126,157,
147,212,160,181,163,116,56,116,174,161,24,252,69,144,136,208,6,64,106,161,17,192,19,252,199,246,82,127,147,239,92,215,209,100,239,31,98,143,84,163,32,125,78,156,119,41,14,7,197,30,227,209,224,28,44,103,
174,35,214,201,251,22,75,95,151,236,186,57,230,44,61,207,198,146,249,165,225,143,167,85,201,241,64,0,221,113,210,134,120,133,190,40,142,29,161,114,31,122,58,126,244,81,198,108,117,7,168,163,25,234,11,
26,12,121,13,254,25,117,162,233,199,26,118,45,66,33,5,102,177,210,141,218,173,197,57,181,29,145,64,174,54,90,20,206,152,241,67,211,64,230,142,174,157,195,51,211,71,48,121,14,238,43,217,70,101,106,184,
28,58,58,244,25,239,208,122,30,202,233,208,103,233,95,130,61,43,86,201,212,178,30,30,17,222,129,191,117,37,212,60,62,160,172,167,249,62,244,193,101,252,203,17,253,232,191,174,131,37,132,163,237,137,183,
75,148,252,36,143,191,239,67,169,145,7,66,25,71,24,118,16,17,246,82,17,211,193,205,252,197,190,228,36,9,4,46,124,145,99,195,180,117,181,60,236,39,150,98,252,188,36,185,133,143,197,19,172,100,23,52,127,
220,143,249,130,111,101,60,172,135,197,164,101,243,126,218,16,26,133,118,148,230,212,184,209,30,244,59,215,21,162,101,126,40,82,230,142,174,157,237,78,244,26,128,50,178,191,21,40,240,214,61,197,59,112,
255,0,5,137,225,91,167,161,171,50,178,106,90,183,79,67,217,93,40,212,181,108,159,160,21,148,97,197,175,222,83,11,34,73,235,62,171,167,58,200,147,73,146,222,235,63,166,153,15,239,125,203,185,9,112,33,211,
27,130,27,208,165,140,250,59,144,163,118,83,36,52,230,136,151,168,181,57,181,179,208,245,50,137,28,113,143,97,43,158,67,195,15,108,151,98,148,201,247,120,117,166,210,99,222,9,248,162,44,31,255,0,85,207,
15,127,136,249,255,0,106,54,186,237,92,153,125,239,134,95,55,237,161,113,162,52,111,106,208,166,209,7,94,154,92,241,69,147,245,43,167,122,15,82,179,91,133,24,43,122,149,248,208,22,189,30,156,224,94,26,
254,83,81,75,158,21,186,119,225,209,102,224,172,154,150,161,174,189,13,44,172,154,150,161,163,212,161,86,172,122,135,136,250,19,150,234,116,84,143,95,135,215,92,189,209,251,211,30,43,39,231,149,48,241,
240,7,86,67,40,180,163,175,95,37,30,184,207,89,228,63,197,106,48,163,118,40,100,249,75,31,74,132,108,9,131,158,30,35,122,71,24,234,230,40,72,120,100,56,132,68,131,78,33,207,81,161,112,140,225,105,176,
183,9,38,33,136,224,83,123,80,199,63,123,72,203,230,253,169,180,235,87,68,208,186,36,113,171,186,33,5,102,177,210,141,218,187,74,115,71,107,163,222,129,166,133,51,166,40,83,150,127,16,49,61,198,202,80,
249,73,9,213,211,191,69,149,170,224,112,255,0,5,158,183,86,161,233,181,111,91,163,89,228,109,79,40,61,215,76,131,241,88,241,142,217,159,176,87,43,126,239,222,159,69,151,254,100,255,0,169,58,135,103,48,
255,0,50,14,89,237,236,117,215,192,246,130,140,120,107,30,238,140,38,224,25,194,250,107,165,29,93,17,33,225,107,209,136,89,15,7,229,31,195,225,92,177,244,158,0,47,46,33,237,226,151,18,86,139,169,232,100,
45,144,11,75,175,189,24,200,49,8,174,89,159,31,3,243,55,223,79,185,106,154,141,110,234,246,148,230,151,26,35,222,135,122,102,90,20,200,58,183,93,46,173,162,117,114,157,233,25,240,152,99,223,20,40,202,
213,118,191,67,78,139,63,10,221,61,15,77,171,116,244,61,22,165,169,1,196,248,191,154,234,201,244,186,153,125,60,63,203,82,127,247,62,229,99,162,159,231,151,218,153,16,255,0,25,251,29,115,3,113,40,201,
251,164,132,199,167,176,174,30,100,95,151,183,178,143,89,99,60,60,67,185,49,65,180,160,26,218,234,203,169,194,35,137,145,183,105,43,174,100,60,143,107,125,212,63,52,135,135,241,92,178,62,48,56,252,66,
186,242,204,105,36,113,200,92,123,83,139,17,112,87,41,32,101,0,56,176,230,237,161,92,19,154,92,104,141,25,189,43,66,153,7,86,235,165,250,209,100,253,74,229,59,162,135,122,177,22,225,70,10,201,248,196,
243,15,178,142,221,13,41,116,41,126,170,58,186,126,206,139,43,38,165,135,10,221,61,13,91,130,178,106,91,160,244,237,118,92,163,65,97,220,135,122,156,159,221,14,59,244,163,81,254,105,159,194,132,159,152,
210,125,146,7,214,22,64,91,71,245,93,49,247,39,169,234,52,243,0,240,203,222,236,151,237,66,140,163,48,236,13,255,0,41,64,245,233,71,189,92,44,165,191,219,36,143,226,211,217,66,93,152,57,238,70,94,174,
192,132,129,98,46,10,241,14,89,181,248,70,85,187,9,143,118,74,81,152,99,20,39,29,66,230,111,216,87,162,141,237,90,38,245,171,162,69,232,93,56,227,77,86,168,132,19,56,183,10,48,93,165,57,166,151,8,247,
160,81,139,106,8,245,217,51,82,232,80,61,30,142,253,22,86,171,129,195,252,22,86,77,75,14,20,61,54,166,49,251,241,246,23,87,62,148,238,163,15,152,185,238,10,232,210,1,135,19,235,147,167,236,53,200,223,
187,247,172,131,247,37,246,83,203,248,163,167,108,127,98,241,11,74,215,77,192,222,39,172,39,175,35,248,177,123,96,127,10,48,90,161,66,108,12,197,251,90,212,229,26,228,183,240,132,254,236,126,114,157,132,
136,15,205,43,208,130,30,203,203,62,44,58,192,113,17,236,92,208,46,19,1,253,200,139,75,71,236,68,49,113,98,185,73,104,228,177,236,161,33,244,161,125,19,138,106,181,77,70,112,253,84,43,180,167,52,184,209,
30,244,19,50,208,166,65,213,186,233,144,31,153,255,0,155,197,71,166,189,22,86,171,181,250,26,116,88,245,116,52,225,208,211,162,213,186,122,23,80,227,114,127,203,70,96,202,68,104,60,3,209,91,44,99,247,
35,246,44,191,150,127,210,172,157,79,242,127,169,29,120,132,84,103,18,198,39,84,8,247,135,188,58,138,228,63,194,120,130,142,57,88,143,109,2,19,30,145,214,20,100,225,136,177,235,20,117,118,79,194,140,66,
230,144,254,214,48,34,7,205,47,122,128,51,218,233,228,123,128,188,138,148,91,144,234,47,172,87,55,28,119,244,113,92,240,234,188,78,133,115,71,210,56,130,142,88,251,192,120,135,204,63,21,101,251,208,177,
238,90,173,89,53,25,195,145,66,184,39,52,46,52,70,140,222,149,96,83,32,234,212,47,214,137,9,250,149,202,119,93,241,30,194,200,43,112,233,59,116,52,165,208,163,30,170,221,59,240,233,94,173,217,91,167,122,
30,139,44,126,159,233,40,176,82,151,22,97,222,81,163,174,251,46,54,89,123,155,215,106,50,239,129,77,162,35,180,138,115,13,62,33,214,16,147,219,130,63,48,247,100,154,65,140,117,21,242,101,252,31,130,99,
197,6,210,140,206,172,23,83,209,251,61,171,174,103,221,8,202,101,201,212,168,206,58,196,250,194,181,196,135,176,169,67,229,44,59,151,52,79,120,225,32,163,40,23,4,95,176,174,120,251,146,255,0,44,144,4,
176,202,57,15,121,211,219,71,236,87,78,104,65,29,171,177,168,205,233,86,5,55,174,132,138,23,78,41,170,213,16,130,103,22,163,5,140,245,196,253,181,209,26,233,75,161,75,209,232,239,209,101,106,177,234,173,
211,191,14,139,116,45,196,116,49,159,222,251,109,65,143,228,185,239,53,101,140,126,240,62,171,166,209,23,58,152,143,107,214,47,251,223,210,232,250,214,78,204,146,254,170,182,176,38,227,239,81,33,165,25,
125,234,205,25,199,67,248,163,25,6,34,143,30,244,230,211,22,144,251,232,247,238,160,86,225,77,88,68,18,126,212,77,249,164,108,0,127,177,15,15,43,252,197,190,197,239,195,218,161,9,200,63,43,63,98,140,190,
96,222,152,209,207,186,125,224,139,177,132,162,238,61,104,196,235,19,170,140,136,247,162,254,148,58,154,140,207,102,42,193,119,208,145,213,66,233,197,53,90,166,163,56,126,170,22,226,184,39,52,184,22,71,
189,98,254,47,180,45,22,137,149,235,122,61,29,250,45,208,126,61,7,232,183,67,75,145,210,189,99,216,98,125,69,209,145,208,7,82,145,214,69,202,186,122,57,248,34,101,235,240,171,113,80,29,115,127,80,172,
61,63,210,130,202,223,57,61,11,251,132,233,196,30,181,204,11,131,197,120,173,33,164,186,145,140,199,18,199,129,65,9,71,81,234,144,66,80,187,250,211,104,174,117,67,141,3,149,40,2,207,103,236,117,224,143,
167,137,87,100,246,106,14,201,125,200,83,200,149,193,247,123,15,82,243,32,60,88,245,237,135,236,82,143,81,255,0,44,168,227,170,151,234,78,41,170,213,147,81,156,59,126,218,26,57,161,113,165,89,149,130,
101,117,140,14,175,180,214,201,233,173,2,214,141,208,122,58,209,105,75,161,70,232,61,186,87,171,118,86,233,221,237,76,112,127,122,49,148,253,22,86,232,100,63,148,125,244,132,64,248,76,189,103,246,80,172,
125,178,79,162,201,222,63,166,134,189,112,58,199,240,79,9,91,218,235,151,37,193,92,208,124,144,255,0,52,105,226,63,219,39,196,62,244,241,47,19,112,71,16,159,169,93,151,6,167,137,155,181,6,147,183,200,
29,123,147,255,0,42,3,150,126,198,77,142,78,126,95,139,218,165,193,219,250,168,244,18,58,129,203,62,245,40,15,118,113,38,62,183,246,83,85,171,33,221,75,155,145,91,167,52,32,138,179,43,4,222,186,18,40,
93,56,78,181,210,32,127,169,107,64,181,233,104,141,52,173,208,110,131,209,222,142,180,171,20,40,221,7,126,21,181,27,161,110,34,160,181,228,73,255,0,74,118,100,127,118,49,31,234,174,47,207,31,181,55,254,
138,127,195,253,43,169,94,183,92,208,54,58,142,5,56,247,134,177,227,78,104,180,37,214,63,4,121,133,190,97,112,134,57,255,0,183,35,199,225,37,89,168,218,221,88,122,23,136,88,245,167,199,224,151,87,194,
83,72,52,133,136,167,63,8,68,250,228,128,26,153,129,232,215,160,7,195,147,194,123,248,40,75,140,11,142,226,24,160,231,135,236,163,171,167,179,51,209,136,116,58,154,140,207,102,86,9,168,72,234,161,116,
226,154,173,89,53,25,238,178,75,247,143,168,91,163,166,136,211,69,162,106,91,160,244,119,174,180,101,116,27,160,244,122,218,141,208,225,113,210,189,33,30,168,129,236,77,125,61,171,33,253,226,61,86,93,
74,235,25,255,0,220,135,245,82,93,209,232,181,30,54,32,189,172,87,46,111,231,31,122,183,137,244,189,150,154,240,92,220,190,89,235,141,189,139,146,82,231,3,221,151,22,161,239,67,189,113,163,199,223,135,
87,196,19,113,58,113,186,136,248,229,121,247,161,1,164,63,168,171,209,233,12,142,46,47,222,45,70,55,116,26,128,50,176,93,244,113,213,66,253,73,197,53,90,178,110,202,51,220,138,119,171,162,74,156,250,162,
125,106,245,102,163,82,213,178,117,170,214,129,107,70,232,61,168,235,84,245,181,27,160,246,163,244,46,133,27,178,157,75,28,77,252,67,213,170,37,222,200,158,160,254,164,95,189,56,166,63,207,31,181,89,147,
126,228,105,106,26,61,79,33,183,203,240,148,57,255,0,182,109,125,98,188,37,199,2,52,163,104,174,117,226,186,239,75,158,40,163,148,7,46,227,170,46,140,3,28,159,208,157,245,168,164,241,245,30,111,230,86,
11,169,232,237,127,190,142,173,77,86,172,155,178,151,55,49,163,246,43,167,52,32,129,215,86,110,10,56,199,196,92,247,4,212,45,66,173,77,86,181,215,252,29,43,117,173,27,160,246,163,173,42,197,10,55,65,251,
43,100,101,242,199,218,83,112,102,89,59,155,249,139,87,128,112,177,254,120,253,168,168,150,255,0,134,63,168,244,154,156,177,18,39,176,33,206,208,29,183,62,196,242,124,135,182,195,212,19,0,0,234,22,69,
250,209,110,55,92,209,143,49,23,229,209,211,78,50,143,99,2,201,252,198,239,140,254,224,143,247,63,203,63,193,6,18,159,162,222,212,208,3,24,253,223,122,182,171,169,143,220,251,36,16,43,141,150,137,157,
49,40,80,57,225,251,40,234,233,220,51,61,24,135,67,169,168,205,193,149,147,81,192,225,73,203,134,145,238,21,215,160,207,208,122,119,35,77,40,202,234,221,7,167,11,35,77,43,116,26,182,79,71,173,168,221,
3,43,3,145,251,44,45,72,143,152,253,157,8,254,104,253,171,208,163,255,0,44,127,81,77,217,78,165,104,202,93,192,148,252,173,249,136,31,98,241,228,244,68,126,40,188,95,79,126,235,194,205,217,106,118,47,
9,19,151,80,208,39,50,247,79,133,172,2,17,202,194,93,127,12,147,6,235,101,207,143,223,226,62,111,218,136,107,191,30,20,122,148,42,202,100,252,162,47,222,95,238,66,129,202,190,72,143,77,211,243,233,251,
179,87,201,254,89,15,185,120,114,64,246,3,226,163,27,186,13,221,106,0,202,203,190,142,5,218,151,234,78,41,169,70,47,226,157,135,119,26,235,118,173,211,208,213,154,141,75,86,201,214,181,11,90,53,45,91,
39,163,244,90,130,156,40,245,132,126,88,128,152,161,17,164,32,7,164,222,141,217,72,240,184,251,85,215,153,206,109,6,110,95,74,188,166,125,65,23,143,174,82,79,8,67,249,111,78,206,165,172,71,121,76,114,
67,249,130,215,155,186,63,138,230,198,222,32,225,74,25,36,108,91,148,90,40,209,208,199,148,219,225,153,225,222,174,52,71,225,159,9,4,211,29,199,225,41,168,202,245,189,3,251,196,243,75,189,93,120,72,156,
186,135,5,121,48,249,99,97,78,234,216,243,15,150,87,67,152,249,114,60,14,158,186,59,94,143,77,22,171,84,7,101,24,155,144,187,145,159,13,35,220,174,159,162,205,70,161,106,21,106,107,208,103,233,217,58,
214,133,10,183,67,135,74,232,83,28,77,248,159,69,213,151,82,156,186,228,125,73,251,43,6,235,31,109,35,24,128,71,42,247,35,235,43,220,143,181,88,64,122,15,226,165,205,203,207,216,194,198,234,93,113,241,
122,191,101,93,121,82,227,120,247,163,144,15,20,61,238,216,126,202,181,14,41,31,20,125,177,253,138,232,184,230,239,209,62,34,223,185,47,197,17,144,24,247,244,89,71,38,81,199,195,3,247,167,36,68,69,114,
195,195,15,243,74,150,166,135,212,157,186,30,9,72,125,137,185,129,244,127,242,178,184,199,234,151,226,131,8,122,143,226,174,32,125,7,241,64,101,6,22,103,30,32,188,19,215,73,197,143,218,156,228,36,124,
50,26,21,124,167,212,19,203,146,99,185,143,177,52,191,182,123,125,223,90,242,67,92,60,251,5,89,184,43,85,192,225,67,93,122,12,247,232,61,59,171,167,65,159,165,126,149,213,171,100,244,116,8,177,26,39,208,
139,76,41,72,27,136,145,235,183,70,31,158,63,106,224,9,29,203,25,252,195,160,7,9,248,81,140,131,219,217,162,148,62,82,222,170,50,4,106,11,142,240,163,45,57,197,211,255,0,195,150,157,157,137,232,93,66,
99,71,15,220,108,185,177,18,39,31,84,130,108,209,236,60,191,129,94,12,145,127,148,218,94,212,98,110,59,83,177,143,229,211,218,188,25,99,214,196,55,216,189,236,126,185,126,11,197,49,232,15,246,175,12,124,
95,52,181,95,52,254,80,116,79,51,220,56,10,105,203,31,154,90,32,101,227,47,199,79,80,77,24,242,247,0,62,197,161,80,34,196,243,9,55,22,87,173,232,234,233,222,157,113,62,244,14,133,6,105,66,67,212,140,15,
160,245,132,202,213,112,46,223,224,179,240,173,211,208,213,153,89,53,45,91,167,167,119,78,213,178,122,61,5,90,130,81,55,246,16,160,35,196,188,135,16,203,133,30,144,252,209,251,105,167,186,68,190,228,40,
221,136,17,192,191,169,62,156,195,216,80,159,9,143,104,79,217,66,164,58,165,246,132,97,45,15,177,114,203,78,7,132,133,25,6,213,53,129,213,151,48,240,207,175,129,239,71,154,61,199,225,94,25,145,217,168,
255,0,50,241,198,39,216,85,241,203,208,65,87,199,55,244,126,40,242,226,238,114,223,98,247,185,71,84,108,153,114,194,38,71,176,47,238,120,165,242,252,32,253,232,3,220,189,52,185,226,185,70,145,30,217,93,
58,235,244,84,43,112,167,203,15,155,175,185,48,18,63,197,117,205,140,243,126,233,247,148,177,31,204,59,198,171,22,86,189,227,211,20,185,225,91,167,232,178,178,106,22,161,233,254,171,38,88,224,195,8,202,
89,11,79,46,108,159,223,24,64,140,109,30,110,249,5,44,112,221,198,121,255,0,75,250,216,67,201,148,96,118,255,0,166,253,99,25,19,225,201,229,221,152,143,222,91,253,174,219,114,50,101,218,229,220,159,39,
144,249,126,78,2,100,68,114,31,122,120,226,60,86,2,197,137,179,224,201,155,14,232,203,105,61,172,254,174,24,129,45,190,244,191,246,220,14,89,97,180,36,255,0,28,150,92,91,207,22,28,91,173,182,204,28,82,
32,110,50,239,115,114,99,49,58,242,156,124,217,1,226,7,106,220,74,123,63,167,226,142,44,25,50,249,187,15,169,126,167,52,39,16,209,120,126,163,59,192,201,129,181,157,221,109,242,141,175,211,243,207,52,
243,243,203,123,245,15,210,200,121,114,17,12,63,81,134,222,133,159,150,91,142,88,74,17,48,218,109,165,245,15,42,82,219,195,52,137,148,12,99,228,188,188,19,4,243,11,133,47,63,36,177,204,102,205,135,156,
109,231,61,158,60,155,124,178,194,70,92,182,242,239,14,163,107,150,10,57,242,72,206,67,30,45,199,151,159,6,108,123,61,204,39,202,121,113,230,132,135,57,105,95,78,44,74,197,182,27,28,24,62,161,187,229,
203,134,56,103,245,9,75,111,180,140,60,243,147,36,103,60,175,207,0,241,136,28,205,126,167,243,65,203,135,108,37,158,57,50,239,182,153,182,103,28,176,236,242,239,180,60,220,194,112,195,46,86,47,214,5,150,
46,125,239,149,231,248,182,252,251,115,108,124,231,31,54,110,73,31,44,18,45,203,204,89,111,241,16,70,251,102,70,94,87,180,176,226,145,197,154,54,214,81,113,47,202,36,177,194,99,6,79,168,75,6,61,207,147,
188,220,29,174,216,199,114,121,227,30,97,44,99,154,56,154,126,248,126,110,198,59,29,166,111,165,226,135,234,242,237,227,151,155,54,234,88,249,114,238,60,174,108,18,197,153,140,12,122,249,188,79,220,190,
159,28,120,246,251,51,190,195,224,17,158,115,136,229,253,86,93,188,95,207,50,49,230,48,109,91,138,207,189,220,191,149,183,231,254,196,73,134,76,211,132,161,136,220,130,194,51,203,14,110,61,75,245,88,176,
254,156,227,207,28,27,140,120,229,57,226,254,236,12,241,152,121,210,148,175,201,39,114,182,19,219,199,36,70,109,164,167,146,89,165,19,41,229,142,247,54,7,240,129,202,57,96,45,126,254,149,208,166,33,251,
240,254,165,101,40,233,205,18,2,186,126,202,195,172,66,32,250,2,49,227,172,123,194,229,209,172,221,213,156,186,228,27,208,23,0,72,238,92,179,15,246,132,76,63,185,30,205,87,186,95,184,175,55,40,229,17,
188,98,117,38,133,194,33,173,213,193,88,114,31,221,77,9,131,249,135,42,180,57,191,41,9,188,185,47,246,207,172,15,181,57,229,143,124,159,250,87,142,70,93,131,194,17,0,8,135,224,139,113,171,186,145,58,69,
253,139,157,152,74,87,148,189,219,171,182,73,14,189,61,74,214,92,166,62,46,19,226,23,187,204,58,226,174,188,49,148,187,130,18,205,102,248,70,165,114,128,205,102,64,173,52,80,203,0,210,7,197,213,40,155,
33,230,159,4,75,179,179,159,66,180,68,35,240,129,175,165,10,7,163,171,167,161,243,54,248,119,32,197,185,115,28,226,49,61,127,244,243,129,91,163,131,105,44,59,109,174,251,115,178,132,182,59,109,246,255,
0,62,105,97,151,196,39,144,192,8,134,114,227,91,3,194,81,221,79,38,47,28,32,50,67,107,155,46,12,99,38,40,103,140,243,31,12,176,198,80,200,15,186,101,214,22,54,148,252,220,184,163,60,95,244,242,59,60,220,
241,4,66,57,193,99,150,236,204,207,103,116,113,226,243,121,177,228,193,143,52,243,109,51,237,182,191,223,220,195,104,37,143,38,95,126,34,83,14,226,61,106,114,134,227,113,158,24,252,50,253,38,198,123,137,
9,1,204,100,71,52,91,23,84,141,207,202,165,139,125,185,142,222,126,118,124,48,140,112,228,203,255,0,211,238,14,216,206,90,114,227,231,140,135,25,91,221,91,137,157,134,199,54,93,182,231,107,181,25,70,111,
168,24,102,25,49,102,38,94,28,192,95,203,12,204,179,203,203,217,228,220,121,152,252,189,190,243,117,45,166,1,128,243,115,24,200,228,196,242,7,148,49,158,156,15,9,143,238,108,119,135,119,244,221,160,218,
101,132,231,142,51,222,227,200,92,74,228,194,92,162,81,61,93,122,172,195,28,161,143,200,193,250,140,178,202,101,201,28,49,203,28,114,151,128,19,225,18,115,216,22,227,38,28,255,0,168,150,51,38,25,35,45,
180,196,113,253,63,115,185,148,155,198,225,241,197,175,222,206,178,225,27,161,45,230,222,25,101,151,15,151,40,226,254,196,76,242,70,57,30,242,128,5,236,5,172,77,156,110,51,64,100,51,102,7,156,196,70,121,
39,140,91,28,241,151,254,212,174,253,94,140,18,137,152,218,230,247,181,230,128,142,95,46,77,205,125,46,61,87,81,201,44,50,219,14,121,74,34,19,151,54,227,107,135,6,76,243,35,206,127,16,228,110,97,107,232,
178,159,44,224,59,113,12,146,24,165,41,249,152,76,198,63,248,196,248,249,165,27,233,216,179,203,14,219,38,228,71,52,96,48,243,100,151,145,9,227,18,6,71,15,41,38,78,195,185,79,24,6,54,199,46,89,17,41,99,
243,49,140,156,167,75,197,216,218,133,130,253,39,44,60,190,182,151,63,251,158,103,91,106,142,118,135,55,233,63,70,205,46,95,47,244,63,246,247,215,94,79,106,158,248,108,54,99,117,155,36,242,102,45,156,
225,159,154,94,99,203,231,96,50,2,65,236,209,150,92,153,51,100,207,231,67,60,51,71,60,242,78,25,63,81,3,2,225,238,65,46,59,87,211,220,98,255,0,248,236,145,203,140,242,201,243,206,6,60,167,37,252,92,176,
132,96,25,188,33,74,113,103,56,179,225,60,218,114,238,112,75,110,116,226,210,67,20,254,159,178,201,24,100,205,60,124,199,125,31,46,57,165,207,202,60,172,209,176,224,247,80,134,125,166,223,32,197,39,219,
196,75,115,143,30,40,249,56,246,252,173,25,248,128,142,49,114,121,186,201,71,123,13,166,12,123,191,58,89,227,147,20,243,227,143,153,60,199,57,230,16,151,136,115,27,118,89,121,184,246,27,73,78,67,151,54,
60,135,114,118,121,237,241,97,132,227,27,245,105,212,2,158,111,209,109,6,124,146,148,178,101,51,250,134,89,228,243,109,49,47,63,60,159,156,18,15,27,166,193,180,219,224,230,142,120,78,95,221,203,57,126,
163,109,45,175,189,146,78,34,4,203,1,199,87,96,176,140,219,77,190,230,91,112,97,134,121,14,120,248,12,206,70,152,199,32,38,1,37,191,11,47,214,30,92,185,60,201,207,44,114,131,229,231,25,92,78,51,228,111,
14,64,72,45,193,110,167,186,197,139,112,55,121,198,124,162,92,216,249,114,199,153,140,14,34,57,91,156,134,211,177,109,51,98,197,139,20,118,51,140,246,248,129,201,56,19,28,222,123,200,202,78,73,58,232,
182,241,144,139,109,177,28,48,103,115,19,158,123,139,191,23,153,67,38,92,88,39,31,32,237,231,128,198,126,86,104,206,94,108,204,154,79,207,60,135,156,144,125,237,26,193,12,56,182,184,113,96,28,242,17,230,
201,57,28,179,0,115,153,18,228,134,97,192,117,106,176,99,147,54,219,20,176,193,157,204,78,121,238,47,218,243,52,181,108,159,74,58,197,255,0,50,63,213,64,203,204,198,29,253,232,141,123,235,18,125,193,114,
122,207,85,56,7,29,203,154,54,201,236,146,241,99,151,170,222,196,60,60,163,230,32,139,33,17,104,196,122,232,196,118,174,198,163,118,45,19,105,66,69,232,93,56,167,220,181,68,32,152,55,91,87,189,57,181,
46,46,17,239,67,189,105,233,90,20,202,252,80,106,62,67,123,180,71,188,83,157,62,24,240,9,213,211,189,69,25,90,153,206,231,109,135,60,115,238,114,238,249,95,46,63,39,54,114,242,228,48,150,146,179,130,250,
33,148,108,182,240,203,15,246,101,183,150,227,107,229,128,24,68,249,19,6,64,117,191,63,92,150,76,248,176,98,195,187,203,9,227,158,108,50,203,138,7,204,198,113,25,121,112,60,156,247,238,236,67,113,139,
99,180,199,159,205,199,154,83,3,44,227,205,139,56,206,208,140,229,253,176,76,110,221,193,133,148,118,217,118,216,243,195,30,108,153,241,243,207,60,27,38,104,67,25,127,38,81,112,208,10,121,183,59,13,190,
71,201,147,52,71,54,227,28,96,115,79,206,156,127,181,40,255,0,108,228,50,147,112,123,21,184,129,16,3,113,184,199,185,159,36,121,57,103,140,100,0,68,70,194,63,220,54,94,70,125,188,51,227,231,57,96,242,
201,143,38,57,74,34,37,142,51,199,148,106,235,150,24,113,99,140,14,211,38,216,99,57,127,233,178,236,204,229,18,60,201,72,201,206,73,18,252,86,111,210,236,182,152,127,81,15,47,56,255,0,168,200,37,138,89,
4,229,1,207,63,12,36,205,215,218,167,139,6,215,109,132,101,18,231,151,247,178,228,254,230,215,46,212,248,167,43,6,202,109,220,178,229,253,46,8,238,179,199,36,50,238,65,205,127,62,60,147,144,129,151,32,
148,193,47,102,189,128,94,84,177,195,54,59,176,155,188,92,191,13,67,141,15,161,99,220,101,134,44,158,84,162,70,25,137,75,9,2,126,99,74,252,210,18,36,189,220,186,253,71,147,132,101,230,121,79,155,117,148,
228,137,28,166,39,207,201,33,202,69,145,199,139,4,48,70,114,18,201,202,103,57,72,199,64,249,9,104,142,175,90,203,44,184,49,100,231,229,47,227,199,40,180,57,44,96,95,148,241,8,207,194,29,152,71,221,136,
3,148,15,64,167,21,119,244,43,105,208,44,175,95,177,26,112,106,223,69,225,235,167,165,26,113,87,122,4,40,25,99,252,227,237,173,245,101,253,222,94,110,199,230,255,0,34,31,235,231,229,246,161,238,55,195,
203,213,95,23,223,247,33,203,163,82,255,0,45,11,117,123,21,221,29,95,131,208,247,47,69,59,27,177,155,160,125,31,109,36,221,154,171,179,241,106,248,181,244,162,133,108,236,188,78,172,238,252,122,169,233,
71,188,161,222,23,139,79,66,60,141,205,193,209,243,31,155,182,131,211,75,55,167,161,219,81,79,177,93,213,169,126,170,91,85,122,154,240,102,232,22,95,255,218,0,8,1,1,3,1,63,33,171,231,174,177,148,111,174,
176,128,58,156,43,103,104,251,206,40,205,95,227,20,138,250,229,10,189,73,243,195,59,72,71,126,50,109,17,31,78,16,36,35,247,205,137,62,248,41,244,97,164,243,237,130,40,244,224,11,230,189,102,194,29,238,
119,188,240,18,36,190,185,87,203,247,194,238,245,164,205,3,221,199,27,220,193,224,236,125,56,9,26,222,253,110,30,70,47,153,231,35,55,85,224,165,130,50,184,34,249,247,197,15,70,55,112,246,205,134,167,175,
16,216,183,241,145,79,91,99,229,94,239,142,25,34,163,124,27,114,155,10,124,87,241,146,78,208,103,172,202,190,92,68,234,208,51,185,237,192,58,176,171,139,9,226,58,158,249,47,89,160,6,1,33,155,230,137,190,
188,103,168,52,111,175,10,74,45,148,218,94,55,193,84,155,235,28,150,30,169,172,98,0,62,183,237,159,153,32,31,83,223,62,128,1,91,249,195,61,36,39,218,112,67,15,207,190,9,208,191,6,118,244,234,231,146,217,
142,210,174,187,249,224,69,53,73,136,83,209,222,30,190,152,246,157,122,107,39,191,86,176,68,122,41,142,124,193,247,202,64,208,216,39,26,224,221,187,205,234,54,248,247,250,224,53,214,248,243,64,211,137,
20,123,28,113,125,48,30,145,58,193,186,95,214,84,151,70,2,73,223,156,61,94,251,224,0,183,36,246,179,132,234,247,153,218,46,26,118,18,245,199,129,136,143,126,217,42,34,58,154,77,113,64,1,36,111,156,91,
143,201,253,226,56,250,94,55,29,141,121,124,123,240,4,223,133,26,236,156,67,79,150,91,192,131,18,196,128,227,203,3,235,56,11,236,205,172,78,25,209,77,180,219,188,162,127,191,84,8,141,176,115,114,109,202,
146,212,62,32,158,216,249,118,103,237,49,180,209,137,235,15,3,173,241,11,94,204,25,39,113,161,132,181,66,175,14,231,88,154,22,216,166,201,77,151,214,62,62,153,47,98,98,253,112,163,17,125,78,195,3,17,4,
169,1,65,17,28,47,90,200,99,84,246,217,123,122,107,106,53,219,157,44,80,190,184,198,52,99,160,90,255,0,163,220,91,92,118,223,140,167,110,151,65,80,146,24,77,56,175,114,32,14,221,76,114,16,145,173,88,135,
129,7,212,193,109,212,71,231,128,78,13,72,24,247,72,5,104,81,83,176,93,239,34,171,118,140,133,203,224,166,252,225,135,210,216,42,33,30,161,188,99,140,21,40,187,32,112,143,17,24,46,119,110,238,223,156,
81,31,68,126,216,230,33,63,38,68,73,61,110,61,207,76,137,18,142,190,248,33,16,187,224,140,149,223,182,59,88,126,59,67,28,133,77,62,163,224,203,134,255,0,48,148,215,18,21,132,175,137,148,139,101,58,122,
192,93,27,114,0,48,61,48,54,249,131,60,55,130,184,100,29,35,192,130,145,155,133,212,227,168,93,38,44,193,79,37,235,54,148,1,118,183,87,199,5,0,117,76,147,9,9,58,215,8,222,72,22,205,204,63,16,5,254,48,
123,218,4,248,78,18,45,127,65,234,124,224,152,174,181,120,29,136,107,239,139,212,28,47,231,94,158,51,218,167,122,203,30,143,249,131,17,244,205,128,148,108,215,12,80,54,190,115,126,10,255,0,56,13,107,112,
226,145,216,125,240,207,153,197,19,209,48,76,175,81,193,186,91,246,214,81,219,165,215,190,64,9,222,174,17,79,93,175,27,11,203,15,108,101,103,94,49,40,24,247,27,246,200,14,143,141,240,181,244,109,251,100,
177,17,154,65,56,16,0,215,174,9,191,84,197,155,231,133,203,98,245,239,235,193,89,244,112,80,132,122,206,237,36,219,117,148,242,235,175,108,83,218,141,250,101,195,175,7,205,196,207,109,108,212,136,245,
88,83,205,16,106,178,136,225,116,193,211,36,126,250,151,225,76,236,110,149,238,160,245,57,93,132,158,11,116,183,145,224,224,0,186,233,186,236,150,62,15,52,125,29,172,117,29,186,124,108,212,11,176,97,151,
30,208,223,74,169,229,127,0,98,4,16,166,145,103,43,15,129,70,6,7,65,174,214,147,22,55,113,130,203,11,215,153,67,209,219,88,142,109,214,164,80,124,113,32,107,88,34,9,66,122,118,197,133,119,124,97,238,174,
212,79,192,249,166,174,187,202,27,104,222,58,112,133,80,189,162,19,97,252,190,209,102,24,33,144,77,166,156,211,160,116,109,3,66,86,225,38,44,129,105,96,69,81,135,183,244,127,70,65,133,74,45,206,228,179,
172,149,147,111,124,217,51,104,98,198,44,146,236,37,245,102,166,36,55,174,194,196,72,6,132,45,193,97,253,61,131,237,27,186,78,9,109,233,192,47,15,215,24,241,147,106,254,68,77,29,135,82,177,24,216,146,
124,226,69,61,20,201,138,82,199,4,213,55,190,6,82,183,250,199,116,119,185,222,120,4,222,175,121,95,92,42,175,162,93,102,139,243,137,220,47,232,190,92,78,185,208,77,19,88,10,192,175,166,4,3,2,245,243,154,
182,23,125,118,253,51,203,85,181,241,174,54,234,34,93,87,115,18,51,34,118,151,95,36,205,6,175,223,93,67,238,193,78,154,91,110,184,16,132,71,232,153,210,164,38,189,120,2,151,70,211,10,62,128,95,227,19,
214,95,82,94,55,108,173,149,179,94,220,11,74,127,37,205,216,235,98,122,102,252,235,87,245,21,146,219,166,209,212,215,156,216,220,153,246,38,26,222,81,148,40,51,95,60,110,195,108,239,19,100,30,177,97,106,
112,3,66,159,222,25,248,190,48,236,249,193,44,62,206,13,210,126,154,198,215,187,103,190,66,14,157,102,167,123,218,250,113,184,188,232,201,164,233,111,223,10,79,66,125,241,237,58,244,214,74,63,86,183,142,
148,247,113,253,109,101,130,39,109,9,231,133,0,31,92,5,164,174,230,44,222,219,215,12,16,191,233,157,107,211,32,47,91,254,48,35,81,48,111,47,182,178,180,86,29,96,74,190,112,228,117,59,245,120,210,77,176,
249,241,195,205,237,244,196,90,105,104,77,97,4,109,5,232,202,235,62,21,92,59,61,0,29,25,226,164,76,165,69,132,147,100,199,171,143,53,33,162,193,7,160,97,6,9,44,104,217,20,86,65,58,205,9,176,180,27,201,
21,22,106,28,52,73,148,211,108,210,86,119,51,185,167,35,166,174,227,131,69,232,207,126,132,13,6,214,104,152,60,226,160,80,64,65,97,97,19,109,228,67,160,65,210,94,133,72,123,58,222,65,212,161,96,171,216,
4,210,204,61,50,8,163,103,64,1,232,25,245,119,213,98,60,72,245,9,146,86,255,0,232,145,32,234,190,185,111,111,93,135,66,96,74,119,142,139,239,122,68,253,165,115,103,91,114,180,51,171,16,140,240,210,24,
28,208,170,132,26,179,170,13,190,185,109,96,209,19,126,103,247,67,167,58,124,144,142,76,4,108,0,117,13,23,188,79,49,163,213,45,54,32,183,134,79,58,212,68,82,141,99,105,121,49,138,169,54,72,235,94,226,
24,5,243,94,177,110,14,252,119,188,130,132,143,159,92,171,187,133,214,209,217,227,12,15,119,237,142,39,185,133,193,216,222,181,196,187,77,239,214,230,247,126,168,198,174,173,156,211,193,13,132,80,190,
67,4,64,210,233,245,50,87,105,128,65,234,33,214,22,54,158,123,226,80,2,87,127,23,4,74,108,107,213,207,32,148,188,14,231,212,184,2,246,75,52,174,82,108,251,5,103,211,36,157,164,125,153,196,206,170,160,
180,224,55,88,85,197,138,83,77,60,119,128,189,124,253,51,64,16,0,1,237,151,166,195,125,120,192,1,189,27,235,190,33,80,38,80,218,92,162,58,80,158,58,125,222,115,119,85,72,98,50,193,234,226,66,180,31,94,
5,0,51,102,9,237,132,251,78,8,97,73,223,190,9,208,191,6,59,58,117,112,236,189,98,180,171,173,190,156,13,143,58,49,138,78,157,225,123,244,197,123,123,241,227,35,186,122,147,4,15,69,49,207,144,202,64,208,
217,78,30,65,230,239,55,224,175,208,184,8,190,117,192,72,83,95,108,17,71,215,28,23,198,9,240,157,55,5,233,124,248,202,245,116,125,176,16,173,249,48,117,123,239,131,34,222,250,244,184,251,96,176,61,227,
143,113,184,87,96,151,174,30,195,212,243,237,154,29,39,190,11,227,94,190,38,87,237,214,3,113,243,129,35,169,249,224,143,177,134,125,184,29,166,169,172,87,101,200,173,157,141,79,28,56,215,82,239,217,200,
104,70,159,199,12,52,36,159,56,189,102,178,223,162,241,82,1,65,254,248,247,11,53,139,96,69,241,123,114,101,16,61,114,174,238,240,214,218,123,224,140,235,14,207,147,26,87,195,53,193,72,215,175,174,117,
87,122,185,190,181,179,210,112,6,224,142,174,118,198,150,223,156,129,212,17,238,220,25,18,62,58,195,132,209,247,235,4,83,209,79,206,76,16,69,33,247,214,25,32,3,185,239,196,13,141,249,129,188,139,91,215,
202,99,50,217,179,215,130,32,173,165,73,222,125,220,185,83,186,120,255,0,67,146,21,134,239,196,200,74,105,173,157,152,10,195,110,72,8,30,159,55,52,218,46,250,239,6,86,209,175,3,0,19,158,254,156,34,130,
233,11,214,72,211,94,67,34,146,66,180,219,174,33,123,116,125,58,113,95,152,247,23,252,158,112,196,121,29,22,207,24,39,66,252,99,211,213,55,192,152,174,169,120,29,206,181,136,245,12,159,142,241,94,222,
252,120,200,252,39,122,195,67,211,6,35,233,137,34,41,185,120,98,206,223,92,223,128,95,166,11,94,186,156,1,177,71,4,249,159,179,138,7,209,48,76,249,13,193,250,91,251,99,124,180,63,76,32,21,189,123,225,
20,245,218,240,7,220,195,219,25,89,215,140,22,62,204,123,141,194,7,67,226,111,133,15,163,111,219,28,17,25,174,248,16,0,213,239,221,184,38,254,23,30,71,180,224,200,213,222,143,75,159,29,97,163,167,113,
197,59,87,231,1,59,9,100,225,79,106,55,233,140,66,35,227,136,0,16,38,252,226,220,159,25,108,246,175,20,160,31,232,226,181,246,147,235,151,89,30,187,205,42,144,61,114,175,121,116,109,55,172,53,13,26,159,
110,22,109,243,226,240,82,29,165,245,203,69,123,92,180,218,235,219,130,40,192,73,125,242,45,26,59,226,129,9,130,210,102,228,244,102,67,217,143,114,186,250,228,137,80,96,120,147,131,114,83,94,135,88,237,
118,109,229,188,78,51,182,189,111,124,26,67,70,37,213,51,64,247,127,156,116,88,14,254,48,210,90,181,77,35,145,88,27,244,243,129,37,130,245,235,138,93,212,93,93,127,56,252,116,31,105,174,53,40,90,111,180,
25,137,20,239,220,200,147,101,252,147,60,35,93,67,172,73,182,139,125,184,16,132,79,62,166,65,146,68,215,66,55,136,15,172,55,60,97,100,46,104,157,186,61,174,90,142,223,127,212,250,228,144,27,224,248,215,
0,219,212,252,220,102,215,162,100,185,238,195,169,155,29,19,219,62,132,48,214,241,38,80,116,207,207,13,115,182,119,237,138,238,149,214,44,41,169,252,240,65,161,147,127,56,99,251,152,119,132,94,143,13,
193,58,79,211,27,85,242,123,228,40,61,117,149,103,169,87,211,141,205,231,70,69,39,75,112,164,244,63,75,143,113,184,68,232,242,77,227,165,249,113,207,181,140,8,24,245,196,66,125,112,29,18,187,198,155,219,
122,246,224,163,11,235,49,35,31,25,1,125,255,0,140,8,212,158,248,64,164,244,156,40,126,183,237,113,193,3,59,224,32,77,127,219,136,245,47,115,30,111,111,12,40,2,137,125,250,227,101,237,154,76,143,207,140,
237,212,2,215,21,123,198,82,189,112,0,8,78,29,245,84,12,240,206,7,217,83,235,50,172,165,252,184,11,93,53,227,137,108,195,191,174,75,67,71,138,4,38,108,73,130,159,70,26,71,191,108,49,64,121,250,28,64,249,
179,27,178,168,3,106,225,133,20,245,11,254,101,93,189,227,134,168,250,233,195,15,81,79,140,113,189,7,243,146,11,70,140,211,145,117,50,121,93,155,59,189,96,136,151,79,45,224,19,85,94,250,241,193,12,141,
161,125,51,72,52,186,79,76,214,149,209,243,63,253,125,51,66,174,31,141,255,0,88,88,26,121,188,74,0,38,155,193,9,0,81,15,87,130,245,2,238,27,112,77,179,237,218,24,197,118,15,204,225,81,26,184,45,52,224,
93,80,172,108,106,154,217,128,189,29,109,246,192,150,237,26,2,111,251,101,137,99,223,94,50,176,61,56,82,20,31,201,56,123,78,210,98,178,207,156,65,41,175,77,222,13,4,51,120,39,181,9,246,156,16,122,61,110,
29,65,113,181,240,184,74,94,188,226,151,217,191,107,192,159,130,24,196,124,183,155,238,104,251,98,253,173,248,241,130,110,158,164,193,3,209,76,115,230,63,56,148,2,143,87,133,145,235,107,155,240,11,244,
222,33,23,203,227,128,169,20,101,193,16,250,227,131,232,228,115,73,211,112,89,59,121,241,155,235,211,0,7,150,14,175,125,240,72,107,1,240,11,246,198,37,237,189,117,174,44,96,61,88,98,70,122,100,135,210,
255,0,25,236,19,173,224,190,62,190,50,191,108,4,43,125,125,48,53,117,63,60,76,170,244,103,3,183,170,126,49,79,106,252,185,21,87,177,169,227,137,52,194,95,179,136,104,110,167,26,58,64,159,36,152,247,38,
189,114,223,135,20,32,40,58,251,241,238,22,107,54,1,23,223,188,144,169,3,215,21,118,247,151,237,167,191,119,5,79,246,76,210,155,205,186,123,97,17,183,195,53,78,54,133,245,122,225,170,219,215,147,135,189,
84,58,129,193,36,128,210,251,228,106,104,170,63,59,197,15,80,126,219,195,164,79,73,214,16,6,31,154,98,69,61,20,201,130,8,180,62,249,0,6,218,79,68,222,47,174,169,235,209,255,0,48,199,221,6,120,126,230,
75,91,215,202,99,50,237,67,215,136,101,190,69,213,51,173,101,2,195,119,226,100,189,175,168,210,96,43,1,92,212,4,7,83,89,88,97,239,171,112,88,55,74,188,17,4,49,247,244,207,2,77,122,30,156,132,145,212,125,
71,22,108,205,27,18,116,243,171,192,20,32,234,225,130,117,39,219,132,70,205,5,190,216,116,5,196,244,87,179,129,38,172,243,233,192,238,246,196,108,55,225,200,247,224,239,21,242,248,241,129,232,78,201,150,
3,196,254,48,98,39,140,98,133,255,0,156,49,103,153,222,111,193,95,231,22,207,172,215,3,96,81,244,195,62,101,251,239,20,15,162,96,153,244,55,7,233,111,207,140,105,240,95,139,146,131,163,172,34,143,59,120,
139,125,93,30,152,202,206,176,177,246,56,247,21,194,7,71,164,222,8,143,124,80,125,28,142,105,233,188,34,134,159,62,51,219,211,0,131,203,4,195,214,240,100,106,239,71,206,62,103,88,104,233,220,113,78,213,
249,192,118,93,89,39,14,123,35,113,32,161,212,226,0,18,7,205,197,185,62,50,240,190,47,17,104,7,217,54,156,86,189,234,79,174,92,50,61,119,154,85,32,23,139,163,105,189,97,210,104,132,251,112,245,183,93,
157,94,45,79,41,125,112,189,66,243,59,102,106,224,155,146,167,111,213,224,105,64,146,251,228,41,41,182,30,190,155,203,99,179,196,193,42,142,155,105,150,61,12,207,40,18,130,62,142,9,4,32,80,244,147,139,
228,171,94,129,172,118,246,109,182,32,17,218,30,183,130,224,237,159,185,246,239,6,234,180,244,248,248,113,1,139,234,125,35,134,66,213,170,105,192,86,2,190,153,20,160,94,181,191,166,29,112,124,165,222,
1,218,219,94,186,227,72,141,39,188,179,29,41,223,190,56,19,171,61,44,153,227,26,235,93,98,143,1,117,111,16,192,8,246,122,97,133,40,151,128,237,175,94,176,194,6,205,71,120,39,162,226,118,233,79,199,27,
224,107,69,241,174,5,171,212,252,220,178,175,70,228,95,29,103,187,244,58,192,174,137,237,115,68,122,28,33,194,167,231,190,30,231,153,222,41,150,94,174,45,18,107,211,231,139,13,6,121,76,49,251,236,195,
179,8,189,30,27,188,27,164,227,75,232,127,57,16,61,117,159,51,21,246,225,157,245,208,124,100,41,232,239,10,79,67,249,197,187,79,241,130,109,122,36,199,74,123,184,167,205,62,142,32,32,81,254,120,138,122,
239,37,7,71,88,33,30,119,196,91,86,186,61,49,218,237,48,209,211,211,20,237,63,46,16,41,61,39,14,31,173,248,200,27,19,251,224,34,26,255,0,183,17,178,30,102,107,215,111,1,84,10,22,6,250,227,101,237,154,
90,137,239,227,60,242,1,111,12,79,69,50,4,33,63,190,53,213,122,51,227,223,129,246,84,250,204,171,41,127,46,33,107,166,181,56,150,204,52,226,26,86,255,0,249,147,55,159,211,109,244,53,148,141,81,36,206,
193,167,119,41,118,147,248,193,136,247,236,245,145,68,29,48,130,135,16,233,86,67,174,177,111,33,240,189,184,150,205,18,122,222,42,6,198,118,199,15,60,57,106,216,247,185,149,243,133,75,203,223,6,225,29,
17,248,54,200,245,55,144,232,138,199,173,195,42,180,171,119,171,254,100,97,144,30,135,227,254,184,212,98,32,190,157,228,212,105,116,251,100,142,213,133,72,157,245,214,2,108,60,238,241,40,1,40,217,237,
112,3,84,40,135,139,196,230,165,183,221,184,38,252,210,248,200,247,96,235,204,206,215,194,250,255,0,204,242,56,158,101,60,253,120,42,61,71,38,165,166,183,233,148,248,115,171,98,117,53,130,146,199,188,
18,15,78,17,40,16,251,206,30,211,201,231,19,197,243,138,68,154,244,226,90,32,249,41,131,191,132,39,208,156,80,240,73,222,29,66,224,105,123,92,59,223,88,133,30,159,110,10,207,93,24,196,107,123,248,194,
248,117,246,197,251,91,241,227,4,221,61,73,130,7,162,152,226,123,153,0,10,54,112,12,61,109,205,248,43,244,222,49,171,219,53,197,41,10,50,195,12,249,28,130,71,78,159,124,83,180,253,112,91,95,68,205,20,
247,113,79,155,241,128,16,40,240,2,53,189,250,254,112,31,0,191,66,228,165,106,250,113,98,165,108,176,184,145,158,153,3,209,127,140,208,233,61,240,127,26,238,248,156,31,80,117,129,160,212,252,240,17,85,
232,207,254,241,229,233,79,172,197,94,213,249,115,98,151,100,62,156,73,86,19,120,138,43,174,24,77,73,39,174,55,89,175,92,183,0,125,16,244,171,145,192,66,0,198,223,126,54,210,217,12,221,232,181,223,120,
160,16,61,125,217,139,118,237,205,0,216,242,236,114,66,67,83,226,112,168,223,104,213,50,47,67,246,205,187,118,220,239,22,186,251,130,248,119,233,155,17,223,116,61,132,249,206,182,97,101,74,7,215,142,244,
31,144,223,209,51,79,213,247,71,159,171,4,140,159,24,101,113,220,181,15,228,120,193,17,232,167,217,201,216,8,162,31,125,97,6,3,176,39,158,52,42,106,251,100,83,201,189,178,50,236,217,235,248,224,127,119,
187,170,99,165,30,206,240,24,96,91,246,201,242,19,214,108,112,77,11,237,155,194,107,214,213,211,175,125,97,212,177,119,112,245,121,187,224,144,216,199,175,183,8,233,233,49,103,242,202,138,72,23,94,120,
149,80,58,187,48,232,157,79,30,220,123,129,3,190,245,135,80,184,54,188,155,56,2,70,229,224,247,123,107,2,213,190,204,142,217,163,206,47,229,241,227,3,208,157,147,44,30,159,243,6,34,120,198,144,242,250,
156,33,67,183,215,55,178,87,94,152,182,39,115,92,83,96,171,184,96,158,242,191,125,226,136,250,35,147,207,163,120,116,141,99,79,130,253,242,80,61,44,200,64,81,188,3,13,110,230,251,10,255,0,63,76,123,46,
214,107,142,202,80,206,152,98,249,197,3,232,220,158,63,12,38,134,159,52,207,111,76,2,15,44,17,13,111,239,193,145,171,190,190,115,226,204,233,233,220,197,61,171,242,226,54,46,186,225,79,108,110,64,85,154,
123,226,96,26,3,230,253,241,219,16,123,222,86,29,234,254,120,157,2,123,7,142,43,94,245,50,251,1,235,58,136,43,190,190,95,214,42,247,145,131,102,205,224,72,33,9,194,157,212,236,9,114,62,142,91,27,76,190,
28,180,90,158,189,161,245,202,1,90,158,3,124,21,40,82,124,185,68,41,183,159,239,15,95,77,224,0,22,8,60,154,251,56,230,137,249,184,34,158,140,197,169,48,126,147,170,95,56,174,41,26,108,147,52,54,205,251,
219,159,14,62,213,52,12,163,60,112,117,41,244,62,113,16,252,161,235,123,226,233,176,199,108,112,194,247,127,56,169,234,37,248,194,97,176,233,154,193,58,23,233,147,74,2,245,173,253,48,233,75,242,111,8,
205,110,203,193,244,90,79,86,89,227,52,242,213,61,31,56,23,125,16,235,191,182,118,63,199,88,137,177,37,215,124,70,168,35,234,94,183,132,216,147,173,120,227,65,179,81,174,11,162,230,133,213,63,23,141,176,
109,178,252,112,109,94,167,230,224,49,47,166,87,167,93,231,188,244,211,48,107,113,63,140,8,30,135,14,104,80,125,251,225,110,118,226,153,94,215,255,0,204,68,73,175,79,153,196,186,6,77,161,135,127,125,156,
74,244,124,239,13,192,184,210,250,31,206,69,47,87,121,168,188,149,246,224,154,250,232,62,50,20,214,247,145,58,116,155,247,226,155,27,59,67,62,233,95,190,12,71,209,28,158,116,241,235,134,208,107,214,152,
234,158,139,147,3,177,103,223,4,99,206,248,25,181,107,215,166,59,88,125,115,163,167,165,197,59,87,229,194,10,126,56,80,250,110,252,76,129,177,63,190,2,26,39,215,205,243,136,161,7,191,108,215,221,94,44,
29,20,75,163,219,58,207,161,28,213,164,153,173,100,2,218,112,194,15,20,200,16,132,214,19,244,3,235,128,161,12,160,123,143,205,200,250,101,245,208,250,204,166,82,159,55,249,202,5,236,60,112,59,82,7,126,
184,133,98,143,55,65,61,51,109,236,143,194,201,245,196,234,17,54,53,158,253,39,96,175,239,15,72,125,160,235,232,227,226,191,119,168,251,153,168,7,76,65,102,118,46,31,192,152,199,183,215,166,211,22,224,
219,227,223,18,81,61,62,113,108,111,181,246,48,89,65,219,127,81,249,48,4,245,146,9,210,125,50,109,153,246,79,71,219,1,64,37,189,46,190,61,28,139,208,191,76,157,43,179,102,155,214,104,141,225,228,223,174,
9,162,171,23,233,199,89,162,15,89,222,78,134,150,143,182,40,69,172,213,68,238,67,88,164,216,124,222,38,4,19,68,75,252,228,139,225,227,67,219,95,108,50,0,61,123,249,192,83,31,75,145,110,173,225,178,217,
31,94,250,224,168,245,49,209,45,235,121,79,143,159,108,234,216,157,70,96,180,177,239,13,129,233,194,209,176,62,243,219,132,220,237,39,231,22,127,41,255,0,49,66,73,162,235,207,18,209,7,206,195,89,229,58,
67,175,109,113,67,193,39,190,116,139,246,192,170,246,184,119,190,177,10,61,62,215,130,53,237,3,24,141,111,198,71,195,70,45,218,223,219,4,218,147,179,12,15,71,28,79,115,33,1,70,230,200,41,242,98,34,250,
31,206,69,47,87,121,168,188,151,227,130,107,189,232,62,51,97,14,247,50,14,146,62,125,113,78,215,239,130,218,247,19,52,15,119,249,197,62,99,237,129,19,97,247,224,4,106,125,255,0,56,15,128,95,182,74,86,
173,248,215,26,171,15,87,70,36,83,211,36,122,47,241,158,105,39,88,63,141,122,211,131,1,111,255,0,184,26,8,111,239,192,69,87,81,201,122,175,211,62,84,159,89,149,123,87,235,134,88,142,111,174,151,232,113,
188,51,99,244,112,53,90,143,125,159,60,104,4,0,137,105,39,156,91,161,60,55,59,197,208,241,0,30,139,220,153,182,239,34,252,191,227,54,117,110,108,32,46,190,114,43,240,79,91,125,177,33,31,89,223,212,123,
250,231,66,58,71,77,62,166,45,114,176,84,14,135,193,144,126,177,127,30,191,24,160,143,68,18,253,178,193,219,116,5,30,227,45,237,219,115,39,236,246,252,252,140,27,109,111,159,24,15,226,111,162,205,22,154,
43,194,169,172,155,42,44,125,119,154,39,168,57,116,136,248,134,177,68,67,167,186,96,129,232,167,217,199,216,8,160,137,116,235,36,232,216,136,119,241,198,132,86,174,250,200,164,109,220,191,247,2,29,45,
2,239,241,157,167,133,245,196,111,104,187,140,123,250,240,162,189,111,248,200,48,68,254,48,79,15,219,52,5,97,233,172,213,44,123,184,114,62,254,252,18,18,88,247,244,241,194,58,122,67,61,85,244,202,164,
147,98,121,213,226,84,32,146,236,28,234,73,36,215,183,29,27,13,27,231,83,58,69,251,98,106,250,111,134,160,219,94,190,252,29,159,78,189,240,44,13,123,202,219,24,119,139,249,125,245,129,91,68,202,33,209,
63,140,24,143,166,53,66,255,0,206,5,67,204,222,87,114,87,87,255,0,204,91,47,153,174,8,215,153,3,25,64,239,199,190,67,113,135,174,41,218,251,224,54,186,118,97,129,232,226,137,238,100,225,176,223,60,5,141,
110,251,230,247,59,124,251,253,51,124,181,89,199,101,132,101,102,8,190,113,65,244,199,49,15,108,38,67,79,154,103,245,128,64,40,224,136,67,119,231,130,35,87,127,206,74,176,204,233,233,220,202,189,171,245,
198,10,93,117,239,199,97,162,55,16,21,124,61,224,179,24,61,87,88,149,33,250,30,162,183,213,202,80,65,238,57,105,85,217,251,206,35,208,246,149,41,197,172,94,129,245,202,69,1,235,233,146,16,128,94,207,235,
59,197,144,176,166,211,248,192,106,80,122,13,240,246,94,240,19,145,0,170,227,141,138,58,224,251,190,126,152,23,208,151,247,59,199,96,244,29,164,59,197,227,79,141,223,127,250,199,110,130,8,213,244,63,222,
62,50,249,76,5,74,141,20,254,92,65,246,67,126,195,248,194,69,59,196,162,125,49,161,20,96,107,181,251,247,142,104,158,253,220,174,250,210,116,123,225,49,81,52,182,127,89,160,130,34,8,123,113,104,10,173,
246,53,141,214,71,194,249,250,231,179,32,222,239,126,56,162,108,78,216,249,195,11,221,252,226,161,208,59,248,194,224,80,233,214,15,210,95,108,6,252,240,250,248,127,172,139,14,252,225,24,243,107,192,10,
245,247,213,246,199,191,92,84,122,63,230,127,240,88,137,177,229,174,248,240,160,141,236,190,46,78,196,146,107,199,4,1,90,141,193,84,98,106,246,157,123,94,15,44,58,119,220,224,218,189,79,239,1,136,55,172,
246,29,111,61,231,93,111,14,197,68,223,211,10,71,161,195,173,176,122,247,223,11,115,204,239,20,202,246,191,254,98,34,79,167,207,18,236,26,136,161,231,59,223,14,206,36,78,159,59,205,128,83,228,193,80,232,
159,198,26,68,199,174,207,198,184,21,13,89,149,220,219,171,155,229,187,154,225,149,166,221,179,62,85,110,189,240,210,62,137,140,82,39,143,92,219,29,122,211,29,41,232,166,76,9,69,159,124,16,137,189,240,
51,106,215,29,172,62,185,209,211,210,226,158,213,250,224,133,62,231,14,31,207,196,200,113,217,243,231,128,0,212,255,0,124,230,130,130,239,52,247,111,11,56,91,52,54,102,182,159,162,251,51,168,93,38,107,
208,39,147,211,53,42,64,53,78,130,248,225,48,221,83,105,215,198,28,132,232,251,231,216,168,207,231,6,121,9,240,158,198,127,16,31,195,50,101,29,58,78,190,153,167,182,162,59,163,223,120,42,3,87,200,220,
192,80,6,212,128,125,113,145,154,121,64,251,29,185,188,103,228,141,116,107,133,245,227,169,12,241,83,93,229,143,71,252,193,141,202,16,55,208,38,227,238,107,60,64,54,244,118,56,139,81,160,249,104,226,248,
34,255,0,56,140,199,233,29,228,57,125,207,141,125,167,145,64,239,198,8,122,222,190,49,68,244,15,231,22,3,181,31,124,19,164,252,14,109,218,111,97,235,215,140,215,19,180,190,125,60,224,57,85,217,126,56,
235,118,217,229,159,76,76,52,144,125,60,142,253,28,26,54,215,165,51,64,180,248,50,65,136,253,248,235,59,29,57,51,71,106,19,207,16,129,247,249,192,91,30,243,32,221,45,225,242,217,61,251,235,207,5,71,168,
228,212,17,235,233,150,240,231,70,221,96,52,84,123,195,96,122,126,111,26,123,14,253,189,158,220,38,231,146,126,113,93,153,162,72,234,147,137,104,131,54,83,172,242,157,33,215,182,184,161,224,235,223,58,
69,250,152,20,175,107,246,195,189,236,192,32,244,247,213,224,141,123,67,21,101,123,92,160,155,241,243,196,202,154,136,190,46,119,163,71,116,226,68,137,249,205,129,215,201,130,159,70,69,46,207,57,168,188,
151,227,128,111,59,235,29,136,119,185,147,161,55,171,235,149,124,184,61,223,162,102,139,229,197,62,111,198,13,167,99,239,192,8,214,247,235,249,192,242,21,254,126,153,9,186,188,56,172,61,86,24,145,76,145,
232,255,0,152,221,195,93,76,32,45,135,186,227,35,68,80,246,38,176,78,207,52,158,158,152,122,210,19,235,194,4,122,31,25,22,194,135,183,252,199,154,206,109,63,217,233,154,111,81,233,255,0,185,101,106,173,
189,103,20,43,14,223,124,42,170,73,34,251,255,0,204,44,158,116,168,121,152,21,221,161,134,36,243,227,20,76,246,22,79,237,202,103,183,20,242,1,154,61,248,217,213,92,69,96,61,98,75,68,255,0,179,198,43,80,
5,246,55,22,248,237,207,70,248,244,205,98,24,157,65,92,12,237,243,145,122,23,233,149,253,78,138,250,117,132,26,29,111,22,219,124,93,36,126,31,140,104,117,122,125,47,103,52,52,116,251,101,153,81,126,95,
57,162,71,97,202,34,211,226,24,128,2,121,245,48,68,122,41,246,113,79,40,160,159,58,197,59,38,163,64,211,175,83,12,121,7,155,188,222,163,110,231,255,0,184,40,186,188,28,236,250,204,116,183,215,20,95,79,
249,146,96,211,4,232,115,64,86,30,48,36,173,124,225,234,247,223,4,2,219,30,190,220,38,175,112,206,209,126,134,122,2,108,79,58,227,196,201,46,253,178,84,68,73,52,245,56,168,132,209,190,117,157,34,207,115,
19,119,178,241,73,217,47,175,191,7,187,219,88,22,7,126,51,66,198,30,113,111,47,190,89,218,38,81,14,181,252,112,209,161,36,223,121,210,175,212,192,167,225,126,216,119,235,128,131,211,237,125,248,35,94,
100,49,238,7,126,61,242,6,144,61,113,78,215,239,132,237,105,223,88,97,122,56,162,123,153,56,59,27,215,1,99,91,223,174,30,103,111,156,223,91,185,194,55,97,25,89,157,159,56,160,250,55,28,196,61,189,114,
50,72,249,166,63,198,66,1,71,88,34,16,221,224,247,66,189,31,254,6,118,148,160,3,163,163,79,182,72,249,44,245,198,5,48,187,210,109,246,193,59,180,253,71,14,132,218,6,200,250,228,69,78,180,127,229,148,245,
188,31,250,253,176,168,7,82,62,249,151,160,131,222,37,254,52,117,105,130,159,168,251,135,223,62,204,192,220,149,195,130,239,46,86,189,234,99,178,129,241,154,213,208,23,177,254,56,65,5,213,59,193,53,234,
19,132,104,93,119,130,122,23,224,185,217,145,93,219,157,49,90,46,191,128,223,228,49,200,171,175,231,129,20,134,167,206,33,79,71,138,215,167,196,199,220,67,215,29,50,31,92,30,62,76,113,61,207,169,157,192,
40,132,31,78,21,128,170,221,245,214,111,88,30,14,133,250,224,198,141,192,187,252,103,91,18,190,157,135,232,225,168,41,45,247,141,62,71,28,79,71,5,145,215,78,83,165,191,108,135,105,31,30,184,116,39,126,
125,240,140,121,90,240,2,189,126,216,247,235,137,64,247,159,108,237,23,237,148,52,73,125,248,240,187,27,223,182,242,116,137,173,105,235,129,0,6,141,220,75,143,165,255,0,184,146,61,167,3,119,15,202,123,
240,108,190,152,12,65,189,103,102,157,103,188,253,240,236,84,76,208,29,67,135,219,100,62,253,241,86,105,124,251,98,153,94,215,255,0,204,216,118,53,235,227,223,131,106,250,117,133,96,139,227,53,44,64,245,
214,41,218,229,155,68,244,193,80,235,95,199,9,43,127,139,193,72,106,203,235,149,42,246,185,190,181,179,132,86,154,116,185,234,168,183,94,248,105,31,68,113,204,66,125,105,155,35,175,90,99,165,61,23,38,
4,162,207,190,8,196,222,248,25,118,215,237,142,200,119,185,146,17,61,46,87,213,251,224,198,222,230,69,209,223,203,242,97,77,41,133,233,129,192,189,123,49,243,7,31,111,255,0,203,63,71,0,26,11,215,157,230,
191,69,175,93,253,179,77,106,218,240,195,72,133,96,184,78,199,227,219,27,29,71,164,21,245,58,206,226,70,9,73,3,121,168,16,53,141,133,2,103,241,22,71,161,236,96,128,93,107,191,235,44,130,19,243,120,209,
133,232,253,178,47,66,253,51,234,147,235,50,250,226,76,87,84,188,6,198,26,251,227,142,248,111,69,223,242,97,171,238,254,12,95,206,186,154,235,54,119,38,88,244,79,227,6,55,13,37,180,24,117,191,57,8,175,
173,254,0,252,224,171,165,130,17,140,133,34,7,162,159,247,27,162,222,194,235,124,112,235,98,123,245,134,15,185,62,29,226,137,232,31,206,109,135,168,235,188,58,201,125,156,5,169,100,122,80,126,166,74,10,
244,194,213,123,237,227,113,121,103,198,69,77,151,88,162,122,28,208,45,62,12,148,98,126,113,206,179,177,214,75,162,106,136,38,175,8,0,234,247,243,130,108,123,203,255,0,114,45,243,117,195,200,21,63,61,
121,224,40,245,28,25,210,39,241,150,242,250,144,206,141,186,235,1,198,250,225,176,58,159,118,240,175,96,251,159,30,220,38,231,105,248,197,69,125,102,48,146,104,164,226,116,100,151,126,51,200,34,39,143,
110,41,229,215,94,216,234,54,247,172,41,29,78,27,103,104,123,239,130,153,165,159,108,85,21,245,202,21,100,147,231,134,74,144,142,252,100,218,34,62,156,53,16,143,223,54,36,251,245,130,159,70,69,46,207,
56,102,169,17,120,22,242,222,177,220,142,247,59,222,120,9,189,94,238,87,215,41,183,220,75,172,16,61,223,231,28,249,143,182,15,167,99,233,223,1,35,91,250,230,133,17,236,27,197,10,186,19,174,241,247,200,
33,226,245,47,254,56,82,160,236,174,179,104,208,95,215,95,231,188,135,22,95,227,58,22,157,75,172,132,234,139,111,140,251,116,137,246,119,154,38,137,234,68,222,6,229,88,42,40,122,39,142,4,197,11,23,201,
183,235,145,122,23,233,159,42,79,172,203,134,170,187,32,250,206,40,86,19,120,192,175,103,143,29,128,73,155,59,147,52,94,216,231,63,230,96,222,90,18,133,255,0,241,227,127,91,113,25,96,245,137,29,19,254,
204,141,162,74,244,182,125,114,122,137,17,223,245,128,35,29,79,131,133,128,89,223,131,249,193,186,79,129,199,125,207,80,248,205,133,51,175,115,239,149,5,90,109,240,112,174,253,135,111,89,224,42,198,123,
151,232,226,32,144,158,235,30,211,167,198,166,79,126,173,102,138,122,41,159,157,62,249,72,90,61,9,194,200,60,221,230,244,74,248,200,171,171,120,120,236,255,0,152,233,143,121,5,122,47,241,129,26,73,214,
13,229,253,101,104,186,58,192,149,111,206,30,175,125,240,0,45,201,244,235,132,234,247,152,247,23,61,192,219,175,110,59,134,36,187,246,201,66,34,73,175,19,138,136,36,13,243,169,158,170,250,152,142,62,149,
225,177,216,215,175,191,158,19,115,180,214,43,178,230,139,102,169,56,125,25,37,223,140,134,132,71,211,133,36,132,147,60,11,223,121,71,209,126,215,12,52,30,143,211,190,61,234,200,99,220,17,124,119,188,
145,66,7,174,178,174,213,194,247,105,239,167,12,47,124,211,228,50,80,118,108,214,184,53,218,222,253,115,214,118,234,230,250,213,103,1,226,35,5,206,239,59,236,193,161,244,115,73,254,212,255,0,179,40,136,
149,71,81,35,138,206,230,62,181,71,234,97,119,48,7,209,183,245,135,8,1,108,245,115,200,153,63,239,156,243,92,246,128,190,95,31,76,219,80,95,62,174,72,190,86,122,229,61,1,243,182,252,99,125,12,169,233,
63,98,241,185,88,70,228,151,177,174,184,136,3,3,46,75,30,242,176,239,87,138,182,67,236,28,94,178,234,98,178,195,227,25,144,53,245,177,138,47,245,31,219,2,32,190,76,19,219,9,192,58,23,81,122,192,236,29,
121,46,159,166,64,20,190,204,223,92,99,221,218,223,138,193,37,93,75,243,159,134,255,0,35,132,218,26,159,56,146,154,119,245,194,247,58,151,40,93,31,16,153,61,38,49,38,65,60,51,28,79,115,5,228,16,18,132,
131,245,48,199,40,27,95,57,191,0,191,101,192,107,91,156,80,34,140,195,11,221,197,19,209,48,76,137,58,112,110,151,219,43,229,163,9,10,223,156,35,30,245,120,2,47,93,123,99,222,186,196,163,229,51,180,111,
219,32,58,62,55,194,235,225,183,232,92,150,132,102,180,240,32,1,163,119,206,37,199,210,255,0,220,77,94,210,254,120,30,224,167,175,127,94,13,171,233,130,196,17,235,59,182,214,247,172,247,28,123,15,83,207,
182,74,136,142,166,158,42,0,73,27,231,23,226,247,198,113,244,175,13,140,22,191,190,14,215,211,172,221,4,122,245,205,74,160,61,117,138,187,92,187,109,61,60,153,100,52,106,125,184,73,91,245,241,78,10,67,
86,95,92,180,87,181,205,245,173,248,224,5,80,29,95,124,139,141,22,253,240,210,62,142,49,68,39,231,54,132,159,57,4,195,228,173,41,241,142,66,46,222,58,206,17,170,3,188,210,232,190,101,113,227,58,1,122,
3,61,84,3,222,154,127,120,153,160,2,249,237,126,28,175,223,54,86,173,0,90,122,110,110,223,118,235,215,216,225,214,174,250,93,79,97,134,221,254,27,62,247,29,4,194,145,94,231,198,106,209,100,246,31,214,
104,22,46,250,239,61,194,221,240,91,0,162,111,191,76,14,167,97,177,126,216,52,250,28,253,75,71,231,52,21,7,145,126,89,132,252,6,214,212,185,235,119,175,247,83,7,143,5,2,239,253,124,96,43,70,109,17,245,
56,45,227,161,220,196,40,82,224,44,83,78,176,25,110,242,132,103,19,98,189,139,192,170,117,63,57,188,16,68,122,76,30,51,137,85,15,226,226,254,117,212,205,44,55,122,244,194,239,162,111,214,151,6,34,120,
203,160,26,59,3,195,24,43,29,244,76,87,198,104,244,23,52,232,137,61,115,197,72,248,124,63,71,9,155,109,232,224,159,54,190,48,210,62,230,1,105,236,220,27,164,253,53,141,45,116,236,247,200,65,81,215,198,
22,187,222,215,141,197,229,135,182,69,103,94,48,81,61,15,231,29,5,191,108,144,232,248,223,15,95,125,101,130,39,109,9,231,132,0,26,189,252,224,47,82,247,49,230,246,222,16,97,167,231,174,54,15,91,254,48,
35,81,63,140,23,203,229,209,149,245,235,172,130,175,100,195,96,117,62,237,227,77,54,237,231,199,15,55,180,225,86,1,31,121,56,189,95,79,239,42,25,30,187,206,246,137,189,147,42,249,199,81,183,189,97,64,
53,14,19,103,110,223,60,29,29,95,227,21,20,190,249,66,175,167,143,60,75,110,136,239,37,104,136,255,0,249,197,2,17,241,128,210,96,167,209,157,143,59,195,28,77,139,197,25,138,7,131,223,23,96,1,59,87,203,
175,87,121,11,163,90,69,119,219,215,27,119,111,155,222,23,91,70,37,214,95,251,59,237,114,99,200,250,159,216,97,240,118,62,154,198,238,42,123,157,191,56,14,93,22,206,238,29,108,62,83,206,67,181,85,190,
14,0,196,118,111,180,28,161,90,49,123,208,228,15,71,252,206,230,98,35,73,235,128,21,112,246,255,0,225,147,228,29,166,215,189,122,24,58,83,99,94,188,21,150,141,220,59,202,77,159,130,191,140,73,90,135,214,
99,177,29,143,99,177,198,181,86,22,219,61,186,197,206,122,31,32,104,157,154,193,117,67,254,176,225,41,137,108,248,61,253,114,46,116,150,1,33,155,91,143,198,104,189,184,74,40,65,157,111,190,62,61,247,170,
255,0,209,142,198,7,171,214,46,148,39,91,181,156,75,2,145,31,156,244,17,164,248,156,18,218,62,172,59,195,220,53,128,14,201,51,211,195,244,235,59,135,76,171,47,102,223,78,1,171,206,177,138,78,157,225,123,
244,113,237,61,248,241,147,223,84,73,130,41,232,166,41,239,33,247,203,104,154,122,225,100,60,221,230,245,74,239,16,139,231,134,136,95,249,137,20,124,99,130,248,192,244,39,77,193,122,95,62,50,189,93,29,
96,37,91,242,96,234,247,223,2,5,185,209,233,120,23,87,188,199,176,185,238,6,198,189,175,15,97,234,121,246,205,13,73,239,130,248,215,175,140,171,244,235,36,171,218,96,48,58,159,155,198,154,118,195,60,107,
129,218,106,159,140,87,98,228,11,103,99,83,137,33,234,93,228,52,35,79,227,134,26,18,77,226,117,154,203,126,142,14,160,40,63,223,16,105,108,152,183,4,95,30,249,34,137,61,114,189,249,194,91,105,239,154,
154,58,222,158,175,174,40,158,137,252,227,160,180,105,173,83,52,14,221,62,174,0,163,91,223,174,107,50,77,151,114,48,117,90,99,173,73,158,218,151,193,215,227,1,4,84,175,246,45,207,25,18,168,158,142,241,
195,181,92,171,36,244,166,253,58,250,230,130,181,229,15,197,205,192,154,137,168,81,158,16,216,127,204,32,132,5,179,223,137,100,174,253,188,231,160,252,30,124,71,215,188,98,85,54,122,240,99,239,29,83,130,
37,97,27,246,200,77,83,91,60,96,46,131,52,1,0,132,195,235,219,84,41,74,158,152,15,179,178,251,222,59,213,26,75,167,99,223,215,17,110,31,234,153,122,249,147,22,108,249,200,10,144,47,173,224,162,32,234,
229,108,106,35,194,174,19,231,216,30,241,27,137,2,223,56,119,7,224,184,238,169,212,31,23,15,22,167,166,87,133,214,223,5,246,224,11,107,80,243,112,195,42,8,122,145,199,168,162,190,163,211,143,121,239,199,
140,142,233,59,38,26,30,152,160,125,241,36,69,55,56,98,129,219,119,155,240,87,249,192,107,235,39,20,136,166,24,30,248,162,122,38,9,145,61,27,131,244,191,172,175,150,143,182,16,10,223,156,35,30,187,94,
4,214,247,175,107,140,172,235,198,11,3,222,56,247,27,132,14,143,73,194,135,209,183,237,113,193,3,53,192,128,3,94,187,184,151,248,92,121,31,39,2,84,177,235,210,231,241,131,165,174,227,143,97,92,7,144,108,
18,120,225,197,122,155,190,216,132,34,58,156,104,0,64,155,243,139,114,107,47,158,215,142,192,15,244,94,54,222,245,214,89,100,122,239,52,42,64,245,202,189,229,219,105,239,222,26,157,26,159,110,18,109,243,
226,156,93,160,207,43,0,59,224,246,70,140,163,177,79,16,226,211,5,217,230,216,253,28,78,228,163,242,57,242,248,126,255,0,233,133,168,167,143,76,171,41,245,179,255,0,140,223,90,167,204,31,219,145,184,162,
130,62,249,17,235,45,53,122,145,233,235,198,186,86,223,73,131,126,219,121,111,206,54,82,137,225,211,192,166,222,229,213,50,205,211,252,243,241,136,111,71,218,76,48,218,175,39,99,128,186,54,224,64,128,
189,124,230,173,133,221,157,184,61,213,109,122,235,141,98,20,55,222,58,206,145,116,135,166,68,211,93,67,8,237,228,6,221,94,10,64,211,207,132,198,130,180,187,168,250,155,206,187,253,55,203,24,3,212,61,
29,79,57,78,232,189,7,248,102,216,130,162,213,235,194,52,93,132,215,253,15,25,54,211,184,192,67,87,14,147,127,76,148,247,157,2,107,17,108,58,239,219,20,246,117,60,76,221,232,157,146,247,134,227,162,125,
117,112,98,39,102,241,122,199,238,118,39,247,134,53,195,108,239,219,21,221,43,172,88,95,142,8,52,41,253,225,159,120,248,195,179,231,8,189,30,27,188,58,137,198,151,208,245,239,145,3,215,89,169,122,247,
244,227,115,121,97,237,145,83,174,240,164,244,63,156,123,141,194,39,216,152,246,227,158,246,156,96,64,250,47,175,17,9,245,192,117,74,239,26,111,155,215,183,8,48,209,47,227,128,179,232,224,70,162,123,248,
194,7,71,164,225,67,232,219,246,184,224,161,154,120,0,9,175,93,220,70,201,235,49,228,123,75,192,148,1,252,137,197,107,237,149,12,143,93,231,107,32,23,121,87,188,101,43,215,0,3,169,194,237,106,42,122,206,
6,190,22,124,229,89,75,239,219,128,181,122,158,60,241,34,152,107,188,132,38,205,60,157,120,178,74,120,194,172,119,29,245,150,187,76,156,186,126,49,167,234,96,145,6,237,122,87,10,33,86,191,72,153,162,19,
175,123,127,178,230,230,59,221,179,231,94,134,124,151,250,237,197,162,163,30,135,8,113,23,101,215,208,97,32,179,175,145,254,241,40,93,75,52,195,8,250,100,16,205,248,245,202,2,73,11,182,224,55,42,173,122,
224,134,195,176,189,161,130,41,71,125,153,43,209,255,0,48,8,61,68,58,192,138,166,239,20,0,21,223,136,92,13,32,216,215,175,124,15,137,35,88,96,147,43,237,219,49,138,236,62,179,132,68,213,160,182,71,2,234,
194,177,112,59,32,161,67,161,132,78,196,250,60,252,103,78,196,38,178,164,177,239,171,154,47,108,82,109,81,17,197,39,162,22,200,252,84,225,117,27,30,113,201,129,234,245,144,74,30,13,173,103,6,179,220,206,
183,191,163,59,254,147,226,78,8,61,30,183,14,160,184,218,251,176,148,189,98,148,55,173,188,21,158,186,49,136,249,111,11,225,215,219,23,237,239,199,140,142,253,68,193,17,232,166,41,243,7,223,18,208,81,
234,240,178,61,110,243,126,10,253,49,8,190,89,174,2,16,166,172,193,17,239,142,15,166,71,225,58,110,11,215,213,227,47,139,163,172,6,195,126,76,29,94,252,18,26,192,124,2,239,24,149,219,122,246,224,34,192,
196,179,233,157,102,201,247,205,13,68,247,207,102,29,223,19,42,228,151,209,128,129,212,252,222,53,213,108,51,198,184,29,189,41,248,197,61,171,243,144,47,80,53,60,113,38,152,75,249,196,52,91,253,112,166,
181,36,152,221,83,94,185,241,9,252,92,247,153,55,242,254,217,168,66,131,174,208,111,2,117,182,67,227,55,100,49,171,107,144,100,208,190,47,95,103,34,111,165,123,17,255,0,60,17,218,175,93,35,135,163,32,
31,11,127,88,230,118,31,206,72,244,189,65,182,71,37,74,237,185,221,201,51,29,86,199,227,183,58,22,190,161,211,208,185,249,11,248,127,120,38,233,29,127,57,221,26,90,96,214,246,159,161,100,32,232,126,144,
95,108,44,12,63,58,199,74,122,41,145,4,17,212,125,240,201,0,29,207,126,32,108,111,204,13,229,54,222,179,180,49,137,118,108,245,157,112,68,141,157,46,163,92,17,43,8,223,182,74,106,154,217,217,130,88,10,
230,160,16,116,13,101,225,167,125,91,132,193,186,85,250,240,74,129,238,135,181,246,120,103,67,196,197,155,62,114,2,164,11,173,220,251,143,228,194,128,58,165,201,47,145,169,214,181,192,189,163,69,179,198,
118,195,241,136,158,132,246,201,215,215,55,0,237,21,167,211,6,155,48,219,233,120,29,207,164,49,27,13,248,114,61,248,59,197,123,95,30,48,61,9,217,48,208,60,96,196,125,28,66,133,55,246,225,138,30,95,57,
191,5,127,156,6,189,102,184,20,34,143,120,103,204,254,113,68,244,71,35,159,67,112,94,150,252,248,198,249,104,112,136,30,157,97,23,187,111,2,199,189,232,244,198,86,117,134,142,157,199,20,237,95,156,32,
108,61,38,8,167,190,56,62,153,236,211,173,224,253,29,249,241,159,215,88,15,80,193,212,107,127,126,4,104,234,51,211,39,167,88,118,245,108,113,78,213,249,192,121,29,130,78,28,94,147,127,76,72,42,234,113,
160,9,2,122,220,91,147,227,47,15,107,194,154,1,7,193,239,195,40,12,0,242,174,12,208,23,221,33,248,26,205,152,135,230,54,42,181,107,137,87,165,220,66,96,33,35,237,195,141,213,242,26,166,73,78,179,238,63,
215,174,21,10,153,125,115,112,189,119,108,196,157,181,215,182,123,238,47,205,24,66,80,18,95,124,172,183,104,237,247,141,217,232,120,244,15,67,25,210,105,78,130,194,158,205,62,163,179,252,176,69,61,20,
251,103,152,82,205,251,224,180,52,1,243,51,177,212,253,195,62,181,194,158,52,238,65,63,156,118,249,55,229,137,135,229,175,94,11,33,163,18,234,153,160,123,191,206,80,44,55,126,38,79,218,250,141,35,128,
172,5,125,50,32,16,30,154,243,115,70,194,214,203,94,240,117,182,218,252,113,164,66,137,239,44,199,78,44,37,236,47,89,227,26,235,93,96,199,128,233,107,171,148,27,114,233,209,219,241,155,195,167,80,9,238,
204,134,252,144,75,115,217,226,1,179,163,185,131,36,187,253,119,127,182,104,157,189,79,23,141,146,85,178,182,107,128,77,106,117,234,220,218,77,233,19,211,23,210,132,245,234,98,254,95,30,48,43,164,246,
202,1,237,252,103,91,49,14,22,89,239,223,15,115,204,197,94,229,234,226,162,77,78,190,120,40,104,100,220,245,195,62,107,134,147,228,194,47,208,110,13,210,113,165,174,159,206,68,15,78,179,83,121,219,198,
231,234,192,200,82,117,222,20,158,135,79,190,45,218,112,15,220,38,61,191,46,57,246,190,152,225,2,255,0,110,2,6,167,253,201,64,244,235,4,163,206,248,22,53,107,163,211,30,221,166,26,58,119,28,83,181,126,
92,32,165,246,247,225,79,108,111,218,226,130,172,215,1,0,154,196,108,135,153,154,227,218,94,2,168,20,46,141,245,197,55,219,172,214,212,126,124,102,181,72,5,225,148,30,249,225,67,61,24,62,38,253,160,198,
166,173,40,104,95,254,120,183,62,229,40,253,207,227,38,163,30,111,38,95,71,198,120,74,59,64,189,240,59,83,71,126,185,100,130,71,223,172,249,114,126,128,254,242,129,169,233,149,118,209,93,159,254,185,74,
172,255,0,153,124,109,161,225,7,111,213,207,116,134,134,223,182,89,50,73,84,217,167,120,97,248,30,36,199,22,37,109,218,217,223,182,36,173,111,94,183,40,30,67,247,15,237,158,81,43,111,111,254,242,240,135,
176,158,211,235,222,40,253,65,252,228,129,104,209,154,114,61,77,228,242,187,54,105,189,96,137,7,79,45,224,110,85,90,245,196,74,59,15,88,56,145,75,79,95,92,149,54,127,204,42,71,169,174,176,210,21,189,109,
226,16,2,87,101,241,112,14,168,82,30,30,248,134,232,182,251,184,38,253,175,67,35,93,35,171,185,158,194,15,181,24,153,27,122,123,227,74,211,111,161,255,0,184,21,117,67,26,41,79,35,199,120,11,209,239,246,
205,65,64,0,6,186,195,105,176,223,86,152,48,122,26,249,224,9,31,118,17,246,115,69,176,62,254,255,0,92,123,78,210,98,50,207,75,138,68,154,244,224,168,65,155,217,131,191,134,79,180,226,7,163,231,120,117,
11,129,79,194,225,41,122,243,138,223,81,183,211,130,111,118,140,98,158,142,240,190,26,31,166,47,218,223,143,24,38,252,18,96,129,232,166,57,243,31,156,128,5,27,196,19,214,239,55,224,23,249,198,34,249,124,
113,64,130,140,176,196,138,97,162,60,233,247,197,59,79,215,5,217,247,49,237,249,113,79,155,241,128,18,159,237,192,64,212,251,247,239,137,216,11,191,156,213,173,91,192,70,3,178,235,227,29,107,62,244,254,
51,67,82,123,224,254,53,235,193,251,3,3,65,9,249,227,85,87,163,60,112,82,117,143,171,134,66,161,55,218,249,126,184,99,95,160,142,159,140,125,62,95,124,85,105,179,126,183,44,99,216,54,199,191,103,60,214,
163,246,63,201,158,217,135,187,122,165,192,20,77,218,231,104,186,48,211,127,158,176,56,128,196,242,175,228,215,26,90,179,150,26,39,245,146,34,40,55,231,253,217,176,67,231,221,102,159,222,27,168,242,127,
144,239,0,99,113,231,177,193,0,235,196,244,153,231,90,124,215,79,209,193,221,189,71,198,47,109,160,190,27,254,178,187,216,62,70,190,206,52,160,147,200,61,240,72,216,123,107,251,224,52,64,32,191,23,35,
83,69,81,249,222,40,69,161,251,55,10,145,59,147,172,32,20,124,211,30,220,136,1,22,137,123,193,52,1,52,56,65,20,239,183,223,41,190,111,102,71,93,170,111,124,118,149,189,43,41,174,0,147,13,223,182,79,208,
158,179,102,44,157,98,122,61,56,50,144,239,96,253,220,246,248,146,255,0,167,88,44,27,165,94,5,33,140,125,247,174,21,65,185,11,214,72,211,94,102,73,54,10,38,238,184,25,87,194,247,82,253,46,104,31,9,53,
237,195,234,4,157,225,212,46,7,119,181,56,2,70,229,245,215,3,187,219,88,139,86,252,100,123,154,49,94,215,199,140,19,116,157,147,13,15,76,80,39,174,33,66,155,225,12,60,239,121,191,5,126,155,197,178,157,
205,113,77,130,174,225,134,124,203,247,197,3,232,142,79,62,141,225,210,52,249,199,211,211,0,131,163,172,132,5,27,192,49,173,215,215,55,224,23,237,113,136,174,215,199,26,170,4,213,214,36,83,211,28,31,76,
159,100,157,96,243,90,124,210,103,245,128,245,12,29,13,111,129,38,174,236,249,207,139,48,210,245,108,202,123,87,229,193,54,174,168,113,15,100,222,58,189,246,81,235,206,223,108,255,0,240,252,92,210,7,253,
191,124,119,128,234,55,161,31,222,72,171,171,154,124,167,221,184,17,180,178,23,187,243,154,30,3,126,205,142,108,61,67,229,194,22,18,58,47,240,230,193,210,49,217,173,15,56,171,183,110,81,19,103,190,63,
28,95,232,191,251,134,77,185,158,167,79,171,154,168,192,4,0,196,125,28,86,201,138,53,253,5,205,135,116,149,173,239,159,71,36,244,154,30,186,51,165,195,126,177,211,135,231,35,250,31,195,188,149,21,54,201,
177,253,227,127,156,243,100,6,119,93,158,230,119,15,5,61,96,246,5,62,217,229,2,80,71,209,205,4,182,33,44,147,139,228,166,187,209,172,106,246,109,47,156,68,47,40,122,240,105,108,49,219,41,130,35,209,114,
192,192,239,226,97,228,217,106,132,71,4,96,159,166,68,2,3,209,158,115,70,151,203,189,225,235,221,181,225,49,244,223,172,129,229,249,192,60,34,8,31,140,145,54,89,233,100,207,24,215,90,235,20,120,11,171,
120,164,128,158,78,147,1,66,79,7,136,223,28,106,119,27,43,237,50,172,89,136,8,234,62,39,68,113,219,223,97,242,117,133,65,182,189,124,112,45,94,167,230,224,90,189,38,87,163,174,243,223,124,26,48,47,113,
63,140,208,30,220,33,195,67,239,223,14,89,219,59,197,119,74,234,226,162,79,167,22,26,30,228,60,225,158,246,204,59,50,84,233,227,123,195,164,92,105,125,15,231,34,47,87,53,23,146,190,220,19,91,222,131,227,
54,77,78,240,209,30,117,243,199,144,108,237,12,51,230,191,124,81,31,68,126,217,60,250,61,115,100,26,124,211,31,79,75,144,128,81,214,12,8,93,240,44,106,239,172,123,101,152,104,233,233,138,118,175,203,132,
20,252,112,161,244,221,248,153,1,86,119,192,64,53,62,191,206,83,8,61,226,13,179,111,129,229,250,24,10,193,15,131,35,150,23,4,171,254,248,37,75,232,205,226,129,53,79,76,26,36,6,248,244,246,205,181,223,
251,135,223,28,253,146,117,179,79,239,32,66,19,92,59,234,232,41,235,61,242,101,247,73,245,153,189,20,85,223,172,121,247,202,5,210,158,14,5,80,169,124,76,221,55,116,244,52,62,134,108,183,232,23,179,0,186,
10,72,199,214,227,58,133,155,181,255,0,235,21,90,42,52,141,50,225,184,139,186,255,0,209,138,128,60,192,124,13,123,111,233,198,254,221,137,175,248,56,155,129,124,7,75,245,196,190,176,155,221,250,113,65,
177,78,221,225,131,214,211,227,28,110,160,254,114,65,176,209,154,202,122,23,233,147,165,97,108,124,245,227,12,68,240,189,239,2,74,215,107,192,157,91,67,203,62,152,1,65,165,211,237,140,83,215,218,230,185,
9,217,163,88,164,216,124,222,34,4,18,136,131,226,249,192,154,161,68,38,175,199,18,154,150,222,182,220,19,126,105,122,50,53,216,58,187,159,78,17,218,28,218,200,224,221,93,87,215,17,16,222,162,119,246,196,
15,135,79,115,127,235,58,54,3,90,102,10,75,30,240,164,122,112,169,116,31,116,246,225,109,60,152,147,249,79,31,76,82,36,209,227,137,104,131,54,83,6,254,140,159,105,196,143,71,173,222,29,66,224,82,190,184,
74,94,188,226,20,122,125,184,43,61,116,24,196,107,126,50,39,78,177,110,214,253,245,130,109,125,204,16,61,23,28,249,140,132,54,27,155,32,215,201,137,23,208,254,114,34,148,179,53,23,146,252,112,44,53,223,
95,76,118,67,189,204,144,137,189,95,92,83,218,191,92,20,167,220,199,183,231,20,252,223,24,25,29,159,62,120,1,26,159,239,156,30,64,92,208,173,91,248,227,69,64,236,186,61,177,35,50,71,162,255,0,25,20,182,
63,161,254,206,13,185,210,236,73,144,175,102,250,43,252,204,9,11,70,97,68,67,249,199,20,74,244,112,145,214,159,235,255,0,172,133,17,252,227,254,82,101,94,213,250,230,200,87,177,246,226,77,48,159,222,42,
21,212,225,35,138,16,132,73,6,146,121,197,186,19,195,122,193,61,174,151,253,61,112,180,133,110,137,107,150,227,160,243,251,56,64,143,65,189,76,118,143,255,0,137,123,250,229,95,65,103,166,233,250,103,126,
247,60,228,239,185,31,233,134,51,237,241,50,44,136,130,189,111,183,245,138,137,236,125,204,19,164,252,14,109,219,182,231,174,26,173,184,94,211,239,135,113,84,31,7,8,53,6,159,108,139,42,45,62,187,197,71,
168,63,94,240,184,137,233,13,98,3,97,243,76,72,167,162,153,208,65,22,34,94,240,250,129,177,53,126,56,146,41,174,220,138,79,123,219,254,224,67,163,80,187,252,112,39,187,229,148,199,76,123,243,128,73,129,
111,219,39,193,19,214,108,114,254,95,108,210,2,3,160,103,241,134,194,135,179,205,194,96,189,90,250,222,46,67,98,246,246,79,25,11,252,29,61,125,28,125,206,228,222,127,241,95,243,40,73,36,164,243,174,37,
66,14,174,195,89,230,36,147,94,220,123,129,35,124,235,58,69,251,96,119,123,94,8,131,112,251,94,15,119,182,177,22,173,248,200,203,52,98,253,175,235,0,118,147,188,52,15,24,49,19,195,141,33,123,251,112,10,
30,115,123,146,186,191,254,99,217,119,102,184,34,223,93,24,232,135,126,50,14,146,122,250,226,157,175,223,5,181,211,179,12,15,69,251,99,137,238,100,97,176,223,60,1,141,111,126,184,93,142,223,62,255,0,76,
156,86,171,244,225,197,98,106,176,193,20,199,7,211,39,136,123,100,104,105,243,73,192,16,10,57,64,183,238,165,243,128,172,16,248,49,17,86,254,215,223,54,137,63,26,120,195,219,213,179,18,209,95,151,183,
31,185,108,134,187,207,245,158,156,217,153,254,140,250,152,184,151,85,164,247,243,145,3,254,243,248,115,88,26,2,116,127,120,247,16,123,222,94,29,234,241,242,30,193,227,61,89,175,225,15,231,45,98,216,15,
174,38,176,13,215,163,245,231,154,0,175,83,79,244,51,190,240,83,211,65,72,123,30,216,69,67,217,0,135,250,120,223,165,236,157,141,252,30,216,219,116,253,207,71,220,235,59,153,79,32,205,127,59,192,233,34,
61,48,221,42,235,249,207,138,215,252,95,124,178,225,73,245,198,154,83,111,246,225,235,233,151,70,87,136,96,148,236,141,180,207,104,25,138,106,18,148,119,71,53,16,216,136,107,233,198,156,85,78,250,234,
102,222,55,180,190,126,184,17,216,97,189,254,56,38,182,24,237,154,193,1,238,191,206,88,52,14,254,48,178,1,90,89,211,131,245,179,219,38,108,3,192,204,10,143,187,223,235,134,205,110,203,192,194,76,79,43,
44,241,142,159,95,124,117,7,168,94,179,190,89,214,130,125,176,111,194,11,93,94,41,160,21,69,208,211,237,145,9,36,233,227,207,26,13,154,141,195,160,191,108,77,94,211,251,227,111,97,247,190,56,54,175,83,
243,112,44,95,76,173,235,174,241,127,47,235,2,247,19,248,205,1,214,167,190,184,90,134,159,158,248,91,158,102,42,202,151,171,255,0,230,34,36,241,215,207,18,148,29,54,135,156,239,242,59,56,149,58,126,115,
100,20,249,48,84,60,127,204,52,147,215,30,118,112,42,26,185,189,206,221,95,255,0,51,124,183,115,92,34,180,219,182,103,202,173,31,156,24,143,162,56,230,33,60,122,153,182,36,245,184,250,122,100,64,148,117,
130,17,11,190,6,109,90,253,177,218,195,235,157,29,61,49,40,211,178,221,182,191,67,44,159,119,187,139,251,183,248,79,231,9,43,103,207,156,219,253,157,112,1,32,95,77,238,249,201,10,13,63,143,108,237,158,
179,217,151,241,193,146,27,122,29,151,217,223,23,222,245,143,52,9,233,233,154,213,208,23,177,254,56,149,236,237,163,223,167,7,49,58,62,248,27,146,17,234,36,193,73,85,19,196,125,242,47,66,253,51,111,225,
123,177,17,24,209,29,159,124,128,138,12,189,191,99,239,194,161,154,53,167,243,61,220,5,185,52,100,59,99,115,95,232,255,0,226,255,0,89,66,181,216,199,94,60,231,138,132,239,9,26,136,191,103,79,250,184,168,
125,48,232,7,76,32,179,141,80,170,159,6,38,225,60,23,183,235,143,175,66,111,119,233,197,22,197,59,99,130,15,187,237,113,199,234,7,233,114,16,52,104,235,6,233,55,217,207,42,145,104,62,122,194,24,223,11,
230,253,114,73,90,237,126,56,23,235,48,237,153,21,26,93,62,216,150,19,167,233,102,15,21,62,13,100,100,107,239,196,64,130,81,16,124,95,56,13,226,20,66,107,237,196,54,167,107,238,226,172,251,203,227,235,
146,58,33,215,182,76,13,255,0,218,246,235,31,45,149,235,223,5,103,168,225,177,4,122,207,97,215,121,213,183,93,96,180,86,247,132,192,244,254,248,87,184,69,237,143,211,132,220,237,63,24,169,175,172,255,
0,152,164,73,214,167,18,194,12,221,67,89,229,240,201,244,39,16,61,31,156,233,23,237,129,79,221,243,135,123,217,231,16,199,167,219,130,45,245,209,149,101,123,89,255,0,50,146,125,58,249,226,101,78,155,103,
156,239,123,29,137,190,24,36,79,206,108,3,95,38,8,190,135,243,145,75,178,239,53,20,217,120,25,118,222,190,152,236,135,123,153,33,19,122,190,185,95,87,239,149,213,247,49,210,252,184,167,205,248,192,74,
168,250,59,207,69,149,238,220,254,112,240,81,110,183,249,207,0,52,175,141,61,24,90,106,139,229,110,56,245,195,52,131,148,138,122,103,181,11,11,12,5,81,50,28,2,150,142,146,248,192,54,192,67,229,19,38,26,
14,251,47,97,215,182,117,4,39,231,128,12,47,71,34,244,47,211,43,133,1,235,40,254,114,175,106,253,115,104,46,208,63,28,29,140,236,250,56,210,169,225,166,197,231,45,216,218,60,119,125,140,88,150,68,144,
234,79,56,79,53,181,218,116,31,87,58,224,103,187,238,95,24,106,1,211,115,185,154,229,128,205,11,48,1,56,125,128,24,121,123,17,212,76,81,58,58,107,89,117,65,6,126,49,255,0,87,143,40,35,203,177,201,41,13,
79,137,135,102,52,151,219,220,96,221,39,192,229,189,187,108,61,126,153,166,110,245,125,62,249,80,85,130,190,147,133,90,182,159,111,108,139,42,42,159,95,156,74,35,176,251,94,240,24,181,233,12,64,1,60,250,
152,34,61,20,197,60,162,136,125,245,150,21,179,97,58,120,120,130,213,175,95,140,139,193,93,237,255,0,114,91,163,90,31,249,199,229,40,202,107,58,214,1,46,183,126,217,54,8,158,179,102,22,77,124,61,167,236,
225,213,88,117,129,37,125,112,228,122,119,239,193,1,177,143,95,110,17,211,211,89,218,47,208,206,206,141,137,231,87,137,161,4,151,126,38,76,34,36,154,122,156,124,6,141,239,172,233,23,234,96,93,123,94,0,
145,184,62,186,239,131,221,237,163,25,96,119,227,52,88,195,188,91,181,247,203,53,68,193,80,241,194,36,143,151,121,208,47,212,192,167,209,255,0,48,239,123,61,48,10,61,62,223,94,8,214,236,134,45,192,239,
198,67,162,79,92,83,218,225,53,180,118,97,129,238,253,177,196,247,50,112,118,55,167,128,241,173,215,214,225,119,59,124,251,253,50,113,90,174,74,189,191,75,127,230,103,64,17,105,12,48,61,223,174,122,157,
3,223,171,248,184,230,33,237,235,145,181,167,205,48,253,33,191,46,2,1,77,60,247,244,192,136,212,255,0,60,111,2,167,225,209,50,42,194,159,21,252,98,72,66,154,108,191,227,149,245,197,246,58,235,223,142,
193,132,110,18,93,122,14,191,232,231,121,32,72,4,232,223,223,41,65,7,189,250,101,165,94,207,223,17,7,147,227,220,252,153,166,188,232,72,215,231,142,248,125,29,116,127,120,18,254,14,143,231,31,168,228,
41,245,117,215,215,137,107,77,155,79,227,13,19,210,1,132,251,226,37,34,33,17,250,227,14,223,244,99,108,95,254,17,255,0,87,29,219,45,65,241,114,212,166,127,88,8,171,173,190,11,237,197,151,10,79,151,26,
98,155,97,173,250,35,249,202,162,233,241,9,138,32,27,143,169,135,216,20,251,107,20,249,138,122,142,117,85,82,18,250,117,194,176,42,214,250,235,55,172,59,37,155,250,224,198,141,192,187,252,113,70,48,207,
59,152,97,62,175,231,40,157,14,240,18,8,142,150,116,224,253,108,246,205,123,33,232,235,2,163,191,62,255,0,92,51,53,182,175,175,5,91,67,59,95,105,237,142,246,218,190,160,247,191,92,74,250,166,118,139,244,
48,163,193,46,187,227,194,130,39,159,108,154,34,58,154,122,226,128,3,68,110,37,199,210,255,0,220,77,94,210,254,120,27,184,125,206,211,223,131,106,245,58,247,184,22,6,245,157,154,117,150,242,229,218,162,
97,64,234,28,61,118,39,191,125,241,86,106,204,171,43,218,229,4,118,15,174,187,243,193,238,243,53,155,160,219,227,188,212,177,3,215,88,167,107,150,106,211,5,67,173,127,24,99,202,223,227,130,144,213,239,
215,61,103,122,185,190,181,179,128,241,105,210,231,204,22,143,206,12,71,209,28,115,16,159,156,34,8,22,30,231,242,99,165,244,41,150,33,69,62,255,0,24,199,102,255,0,211,124,240,51,237,174,108,67,183,89,
100,246,124,228,156,187,106,247,137,85,95,234,88,1,183,199,139,138,250,212,125,22,64,192,157,153,119,254,152,20,60,16,70,96,218,213,109,245,127,243,34,0,192,203,37,143,127,57,163,187,115,173,157,152,218,
237,2,53,219,243,199,88,186,76,89,128,158,75,214,33,210,219,72,208,223,142,19,85,170,109,58,248,201,70,131,244,39,255,0,44,22,123,237,62,169,192,137,73,235,211,239,4,233,63,5,199,171,104,23,214,101,234,
212,198,175,96,221,15,72,199,36,232,142,30,230,117,247,195,241,78,205,72,254,153,63,29,231,148,215,90,18,100,172,137,217,50,159,162,127,24,168,125,28,218,8,68,118,5,156,51,1,85,243,209,138,245,135,131,
161,126,185,209,173,147,123,252,113,69,69,119,189,225,131,238,251,59,199,27,208,63,156,218,14,232,225,214,75,237,172,90,94,133,160,234,245,132,50,119,171,231,9,236,221,151,227,136,55,229,135,108,200,174,
213,175,140,74,9,211,244,185,167,161,223,70,64,116,189,235,124,107,207,195,47,249,50,18,19,84,65,235,132,0,26,242,252,224,155,31,75,255,0,113,102,246,240,249,10,31,191,94,120,216,61,71,235,131,44,137,
252,103,188,250,147,43,91,117,214,3,69,111,120,68,30,156,43,109,157,188,238,112,157,123,76,87,103,214,99,66,110,181,56,157,25,173,239,198,121,68,70,117,237,174,20,242,229,219,105,233,58,194,129,212,56,
106,173,167,231,190,10,102,172,197,81,95,92,164,155,212,251,240,201,82,19,111,139,157,232,136,239,92,32,72,71,239,128,210,79,156,17,125,14,116,82,150,56,102,169,178,240,128,23,167,134,218,93,238,119,252,
102,156,176,37,60,247,231,30,241,20,237,117,167,243,131,221,250,38,104,190,92,244,159,71,210,6,255,0,56,3,177,122,59,206,135,204,62,175,1,67,38,110,176,147,251,48,253,35,30,132,15,239,60,134,16,122,61,
152,97,210,166,193,141,63,81,249,196,138,122,107,36,118,151,242,76,110,225,174,166,9,189,78,237,241,148,123,111,235,180,253,156,48,180,111,169,179,126,48,245,164,63,126,4,17,232,240,202,122,47,193,255,
0,51,230,95,82,92,214,10,49,228,225,209,255,0,155,132,248,224,16,38,176,124,35,219,227,4,111,235,61,139,251,50,47,95,63,76,122,172,36,144,235,172,96,71,131,84,191,201,140,72,159,192,124,158,216,9,20,0,
210,38,241,2,178,249,132,124,241,215,21,103,125,99,146,195,213,232,197,208,36,243,124,251,112,107,177,70,235,211,134,120,186,159,19,13,35,238,99,75,123,123,140,31,164,248,28,91,220,222,193,243,154,4,199,
94,230,84,82,197,95,7,10,239,216,118,245,148,101,69,190,157,229,9,29,143,139,222,81,40,62,33,146,29,61,58,217,130,7,162,159,103,20,247,64,252,44,198,134,194,232,158,120,120,135,107,95,254,96,41,5,119,
44,254,114,162,241,3,184,109,248,112,199,142,207,175,102,117,175,76,130,189,111,248,192,141,34,96,222,95,109,101,104,172,58,48,36,157,225,234,247,223,0,1,111,79,235,132,234,247,153,218,47,208,206,202,
166,196,243,174,38,163,36,187,241,144,208,137,60,61,78,58,32,146,55,206,179,165,95,169,136,235,235,195,67,177,175,47,191,158,58,29,83,241,138,236,198,138,186,212,225,249,72,111,126,50,55,17,31,79,109,
112,164,208,210,111,188,255,0,232,176,83,232,159,198,26,125,125,176,74,61,31,167,0,95,53,209,139,112,109,241,222,242,5,18,62,125,114,190,174,20,27,161,31,56,41,9,164,246,104,199,27,217,252,225,99,102,
208,199,160,250,185,223,203,129,99,91,223,174,30,103,111,156,133,117,240,225,39,252,112,45,7,169,235,119,154,47,157,247,158,160,213,124,135,245,134,38,146,150,149,130,78,14,8,235,168,127,239,6,87,60,62,
183,159,140,72,130,27,224,6,47,119,199,156,112,11,66,109,232,112,136,234,106,246,76,171,229,251,224,157,212,233,245,250,112,22,88,70,226,194,120,142,147,223,55,205,4,251,181,195,80,12,0,33,48,3,18,214,
53,27,122,196,113,99,213,240,186,49,201,44,7,98,96,248,10,36,162,118,56,235,189,78,238,90,161,84,135,167,119,0,7,198,46,189,159,108,243,114,133,183,226,120,113,8,141,125,159,103,217,201,48,105,83,201,
105,28,241,16,137,233,233,195,89,93,31,81,130,116,159,129,113,221,115,168,62,46,13,77,167,245,149,65,107,111,130,241,69,66,147,221,198,148,166,222,147,15,89,212,185,68,116,124,66,100,244,157,196,155,207,
105,25,138,55,185,150,149,21,132,190,156,35,1,86,239,227,55,227,62,128,191,92,234,5,96,28,85,166,147,2,27,234,202,38,129,223,198,47,80,80,215,70,178,46,148,81,249,50,189,93,24,73,39,126,112,140,123,213,
224,129,111,127,107,143,122,217,137,64,247,159,108,123,141,202,30,9,100,223,11,175,132,127,27,201,98,35,227,73,174,40,0,32,77,249,197,191,194,227,56,249,47,22,238,31,230,112,109,95,79,205,192,66,17,235,
59,180,235,212,153,79,46,61,163,36,187,241,144,208,142,167,21,52,36,155,243,169,159,10,247,198,117,243,195,99,5,175,127,94,15,119,153,172,221,4,95,29,230,165,68,15,93,98,174,213,203,182,211,4,103,71,143,
182,26,79,156,105,91,240,205,94,28,93,87,125,102,10,143,99,173,51,98,166,135,182,72,93,255,0,165,250,184,138,211,78,151,60,38,139,126,248,105,31,68,113,79,130,123,219,49,116,100,18,222,161,142,148,244,
83,38,41,71,95,124,32,68,55,126,145,253,224,247,67,251,188,57,202,215,219,55,202,149,243,114,34,205,2,142,200,152,209,215,253,137,228,193,155,124,120,188,56,171,13,223,182,5,126,17,126,7,244,206,244,96,
2,64,189,121,173,202,198,139,190,187,251,102,154,213,181,224,148,79,143,67,9,120,247,194,252,135,250,200,240,31,129,217,236,121,203,175,80,22,194,232,232,225,33,131,229,246,201,17,112,71,105,242,125,61,
48,97,27,238,62,143,163,132,180,9,79,6,215,182,34,139,8,77,137,150,202,45,189,188,63,247,63,143,76,169,71,98,205,31,78,3,106,65,247,205,156,223,116,242,100,95,167,126,216,167,179,169,226,102,236,132,236,
158,185,79,209,63,140,84,62,153,180,0,111,96,117,194,16,21,103,125,24,175,140,209,232,46,116,75,96,78,248,117,5,93,251,96,159,41,62,29,226,137,232,143,231,54,131,186,55,206,29,36,190,102,177,217,125,45,
60,94,178,69,81,102,157,151,231,8,237,234,95,142,61,108,50,123,31,250,198,86,117,227,18,129,227,249,206,209,185,32,244,248,223,15,95,71,188,150,68,101,16,78,16,0,107,215,231,4,216,61,102,60,223,55,134,
72,80,253,250,224,44,250,56,48,200,154,239,198,123,226,22,164,235,43,234,235,172,6,138,222,240,136,58,159,223,14,217,183,111,49,156,59,143,165,226,212,1,127,153,193,181,125,58,247,184,40,100,122,239,59,
218,3,212,153,87,206,93,27,123,214,106,14,161,56,109,29,167,210,240,82,26,179,231,45,21,245,202,85,122,254,120,41,66,9,223,190,27,24,29,15,100,225,222,18,236,62,110,72,133,251,60,127,247,130,41,233,157,
139,178,239,227,12,213,54,46,123,81,95,156,135,121,108,6,178,238,135,123,157,228,20,77,234,250,227,74,187,111,216,127,220,161,109,16,186,105,154,7,187,144,241,169,254,189,177,163,139,63,212,215,166,63,
13,246,27,199,190,10,217,249,15,166,13,11,23,204,243,144,109,109,222,120,220,103,172,246,103,181,17,6,9,20,238,121,58,114,31,105,127,137,157,11,78,165,184,147,166,150,223,28,13,144,39,217,48,206,3,190,
142,247,211,123,192,0,0,3,64,104,12,44,46,141,166,81,15,101,246,6,109,132,227,179,105,247,205,100,173,245,191,244,227,20,91,176,211,63,156,173,125,159,238,176,165,120,119,131,250,127,24,205,248,56,224,
59,249,116,26,126,217,208,104,4,3,169,38,111,246,30,215,88,48,122,27,206,183,137,104,0,203,55,223,11,96,218,121,235,16,150,23,87,161,197,208,36,247,181,224,176,11,27,246,112,251,45,39,196,225,149,167,
138,244,195,188,61,195,88,237,108,222,195,214,100,33,83,175,112,197,141,45,42,250,113,82,123,14,222,177,46,161,111,223,10,104,118,62,47,121,84,160,248,214,72,116,244,147,102,109,231,99,238,127,92,83,222,
103,223,18,10,54,232,247,225,100,30,109,114,58,165,119,48,82,249,188,52,66,255,0,204,72,163,227,32,47,139,252,96,120,73,211,112,95,47,159,25,93,23,71,88,18,173,244,152,58,186,159,158,1,41,182,25,191,110,
19,185,228,214,61,133,206,205,134,196,61,175,15,97,234,93,251,102,150,162,123,248,207,101,0,181,202,191,78,177,148,175,93,96,16,117,63,190,29,179,182,31,102,112,61,58,83,241,138,236,92,97,108,213,53,196,
182,234,93,228,182,52,103,252,225,26,132,234,103,67,50,135,163,254,98,173,41,117,245,165,134,148,116,251,161,159,235,99,7,219,33,242,89,139,112,109,241,239,146,40,147,215,8,139,180,125,204,207,162,152,
36,153,236,61,31,12,242,249,205,3,238,100,161,217,179,90,199,215,208,254,71,0,37,237,95,92,53,79,172,158,140,205,181,170,255,0,88,51,98,215,135,254,216,55,53,68,247,235,62,152,96,33,116,188,249,143,179,
139,208,173,158,184,44,103,252,200,9,35,231,34,211,77,91,225,237,250,187,200,64,83,76,56,64,22,207,87,130,42,45,221,195,110,82,108,251,118,207,166,49,45,65,158,179,137,157,85,65,117,254,156,154,39,109,
232,61,95,108,28,80,52,205,190,240,58,246,62,166,64,163,123,236,149,254,50,157,65,189,206,199,220,205,32,62,95,161,214,121,224,3,186,236,126,51,87,237,232,249,39,195,227,12,127,98,124,142,12,208,85,130,
245,222,50,52,166,172,241,145,72,64,186,221,224,160,14,162,253,178,90,118,18,117,173,112,130,200,147,105,188,59,195,224,92,118,61,117,31,75,135,101,179,250,203,240,186,219,189,95,110,42,45,82,30,248,211,
208,239,126,48,189,206,166,80,186,62,60,100,247,88,196,153,4,240,204,113,143,83,28,170,43,41,241,196,128,109,181,248,192,192,4,158,130,149,253,226,26,249,102,184,160,69,25,134,7,187,142,7,209,193,50,36,
233,193,250,91,243,227,43,213,209,246,194,1,91,243,132,99,222,188,25,23,174,189,174,50,179,175,24,44,15,120,227,220,110,2,120,37,147,133,61,168,223,166,75,17,31,26,120,160,0,209,55,231,22,255,0,11,143,
35,218,95,207,1,154,61,25,192,237,53,77,98,187,23,34,182,20,154,158,47,14,43,212,187,246,196,33,17,212,227,64,2,4,223,157,76,91,147,89,108,246,225,69,0,131,239,235,198,219,221,241,155,137,30,187,196,65,
8,55,254,254,113,85,171,92,219,31,70,233,29,125,143,231,5,73,13,79,183,9,41,249,154,214,127,248,214,127,243,133,195,180,95,92,112,121,63,253,61,51,125,110,254,56,42,16,132,191,63,233,147,65,17,118,61,
247,159,237,29,44,22,33,48,90,73,140,213,137,233,120,143,124,83,64,35,216,154,97,100,161,164,236,124,71,140,114,93,225,205,116,173,125,178,189,193,24,157,141,190,49,143,226,225,179,167,179,149,251,224,
47,173,90,166,58,81,239,40,44,55,126,38,64,166,251,59,28,5,97,183,208,196,78,216,15,67,108,223,242,183,136,116,7,179,60,209,217,75,240,167,15,57,124,15,254,101,172,149,45,80,161,223,182,75,252,174,122,
159,241,203,111,182,26,217,168,189,61,126,76,182,33,233,105,33,51,208,60,122,142,196,195,176,199,224,116,254,114,16,60,4,232,71,137,159,18,150,120,153,218,12,244,193,169,210,54,123,112,34,149,104,187,
135,124,108,40,107,239,155,25,190,239,169,172,139,125,187,246,199,216,58,158,38,110,244,157,146,247,132,227,196,254,46,10,132,236,222,54,160,237,177,227,133,48,220,119,226,98,187,225,117,232,57,88,29,
144,55,195,74,21,218,96,158,234,79,135,120,162,250,86,2,103,208,220,31,164,223,182,52,248,47,197,200,65,81,214,17,79,93,175,199,27,139,203,15,108,138,206,188,97,73,232,127,56,247,27,132,78,143,36,223,
14,31,125,56,225,17,148,156,4,9,175,95,155,136,217,47,115,30,111,111,12,48,8,119,239,215,27,39,209,205,13,68,247,241,128,155,41,44,147,133,61,177,184,208,68,124,113,0,1,163,206,238,45,201,241,151,131,
218,94,4,160,31,144,156,86,190,210,125,114,225,145,235,190,243,181,144,11,188,171,222,50,149,123,194,128,66,28,54,171,81,78,132,177,220,50,249,76,72,39,223,27,203,69,63,61,179,1,234,245,226,121,224,139,
128,82,124,63,253,50,84,161,54,214,75,255,0,218,51,251,202,4,35,128,210,102,159,184,159,187,51,90,20,187,31,76,2,128,241,61,29,241,91,85,92,119,67,189,204,13,191,115,236,76,37,21,160,221,185,161,26,128,
237,119,245,61,178,16,58,14,177,241,142,55,191,227,22,238,187,30,207,102,90,225,227,224,250,62,230,69,43,11,214,183,135,92,31,41,119,129,185,74,239,163,128,49,29,155,237,12,112,221,62,127,91,241,147,161,
78,222,222,121,115,216,14,161,214,32,219,69,190,220,58,160,199,242,140,150,134,186,215,175,18,135,181,107,4,219,245,127,56,172,148,52,54,246,127,214,21,44,111,60,246,127,35,192,209,42,180,175,76,224,93,
80,175,231,12,82,244,137,255,0,48,22,195,173,190,198,116,20,0,16,234,26,205,254,195,218,235,14,47,67,126,185,214,207,24,214,4,25,67,124,23,81,182,119,214,41,44,30,175,88,154,90,154,55,219,56,150,7,68,
103,174,8,253,24,159,18,112,69,235,124,221,230,201,19,219,54,91,242,120,179,34,60,44,114,136,105,173,244,143,245,193,53,245,208,119,146,167,163,188,41,240,79,139,143,121,239,199,140,158,253,68,193,17,
232,166,41,243,7,223,88,150,130,143,92,44,158,190,112,31,5,119,140,75,219,233,193,66,11,235,137,24,248,200,30,139,252,102,135,73,239,130,255,0,111,25,95,182,2,21,190,190,152,58,141,111,128,129,169,255,
0,110,35,212,30,243,94,246,240,81,128,162,95,126,184,217,123,57,161,168,158,249,236,234,91,227,42,227,50,189,73,128,136,106,126,111,26,234,182,25,227,92,15,178,167,226,226,158,203,144,47,80,53,56,140,
250,215,231,175,234,228,180,173,254,181,194,154,212,146,99,117,154,202,31,136,191,75,254,176,98,61,251,62,112,233,68,210,238,7,8,60,172,153,106,17,2,94,212,152,154,136,39,126,185,123,123,83,238,28,63,
118,158,253,224,133,239,248,205,3,238,97,112,186,104,205,100,60,91,239,124,251,176,143,106,182,104,116,143,164,205,37,213,169,81,232,250,229,165,71,166,137,118,29,252,240,187,134,47,233,123,153,211,155,
169,68,222,56,69,172,58,104,183,174,176,177,26,121,184,247,241,140,159,98,189,15,190,8,10,205,36,223,191,95,156,124,107,243,31,222,33,77,222,211,205,236,174,70,46,227,98,62,33,102,60,61,147,235,211,134,
136,218,122,234,224,163,77,35,71,200,152,236,148,15,195,211,223,42,105,123,242,26,63,44,5,208,102,160,16,26,38,178,209,179,190,173,192,96,223,107,234,222,40,3,60,159,84,225,26,133,82,111,174,241,145,165,
234,251,98,162,16,46,183,120,40,3,54,97,158,196,36,235,90,224,246,73,37,187,205,178,63,24,42,245,212,125,46,29,151,103,166,15,53,214,221,234,240,37,189,33,230,227,58,111,195,225,192,124,52,121,241,139,
197,55,207,27,191,219,4,221,35,178,97,136,244,113,196,247,49,64,10,54,126,56,67,15,45,174,111,192,47,211,120,134,190,179,92,5,72,163,44,195,62,71,20,15,163,112,76,211,209,184,47,71,126,124,102,250,244,
192,1,229,130,97,235,94,12,141,93,232,249,199,182,117,134,142,157,199,20,237,95,156,4,236,37,147,18,41,233,146,61,31,243,61,130,117,188,31,198,189,124,112,125,65,214,14,131,91,251,240,50,171,168,206,7,
111,84,214,41,237,95,156,143,35,100,36,241,195,139,210,111,233,137,5,93,71,141,0,144,39,173,199,185,53,235,150,207,110,40,64,52,254,248,216,213,185,77,103,110,239,113,252,100,197,32,122,253,177,172,107,
254,139,235,151,109,167,191,102,26,157,26,159,108,215,40,139,123,234,29,140,63,88,127,137,155,39,148,190,185,104,167,210,247,135,107,91,241,193,14,160,58,198,148,37,94,190,247,128,154,98,187,164,127,38,
30,140,143,137,214,1,101,91,212,190,248,8,169,80,222,238,125,62,185,74,140,3,176,201,246,201,18,1,168,78,147,142,189,84,250,1,142,223,54,252,177,205,14,136,6,253,28,21,159,111,250,245,155,85,166,159,9,
142,109,61,16,191,67,248,185,66,59,1,216,255,0,231,1,88,27,205,64,40,30,154,205,82,197,243,222,80,223,81,235,109,190,248,94,185,79,133,125,156,144,49,81,239,193,96,60,33,233,114,102,154,235,88,110,31,
64,170,234,240,82,0,158,78,147,33,3,192,78,180,240,153,214,148,217,226,103,104,63,24,55,52,166,207,110,0,90,173,151,122,239,128,170,212,53,229,115,97,54,108,79,38,176,22,161,163,183,211,22,242,157,67,
68,192,190,195,196,186,195,113,209,59,248,193,136,157,155,199,176,232,207,140,244,137,3,236,127,6,33,67,182,119,149,217,43,171,214,45,148,238,107,128,13,21,119,48,79,154,253,29,225,164,125,204,19,62,134,
224,253,39,248,198,151,208,191,124,148,15,78,176,148,121,219,198,199,234,192,244,200,172,235,11,31,99,138,118,174,16,58,61,39,14,31,207,198,56,64,167,247,192,64,241,128,65,209,214,8,135,150,240,108,106,
239,70,122,203,48,211,211,185,138,118,175,203,136,10,93,117,239,194,158,212,111,218,226,130,134,105,224,0,18,31,91,138,217,61,115,92,187,75,192,42,129,143,131,105,197,107,222,166,92,50,61,119,154,213,
32,23,59,202,39,203,188,208,4,33,51,214,134,190,123,126,114,231,74,42,26,251,189,243,200,90,159,15,254,114,212,242,159,57,108,165,254,112,168,94,159,183,128,169,133,254,178,100,173,26,60,80,53,31,24,230,
137,130,47,163,89,160,243,189,229,129,103,7,83,199,140,54,104,122,11,79,192,254,178,226,67,168,232,158,217,183,54,251,143,215,4,173,152,71,110,253,153,32,252,25,61,164,111,95,57,114,141,24,237,142,24,
125,69,252,226,139,100,21,246,185,32,108,52,102,156,139,160,87,211,21,234,179,234,14,205,126,49,11,117,100,20,172,188,237,22,244,131,95,76,54,20,81,252,159,108,16,84,236,250,99,167,215,21,30,140,236,60,
108,246,192,187,208,125,247,191,39,16,128,5,118,121,11,128,117,66,144,240,241,21,168,110,184,53,221,237,237,145,174,145,215,183,27,36,213,165,108,103,2,133,175,229,112,197,58,136,152,11,209,214,223,108,
234,40,0,0,97,13,96,217,176,223,86,152,49,122,59,243,194,68,64,107,223,190,18,225,177,231,21,26,94,175,95,198,35,70,164,13,218,204,247,34,31,129,249,200,70,6,110,166,24,253,29,156,72,244,122,221,225,184,
23,27,75,234,100,82,245,149,126,162,175,167,12,175,174,143,166,49,79,71,120,83,224,159,124,95,180,223,30,48,77,248,36,193,17,232,184,167,205,62,142,0,64,163,193,41,175,92,7,192,46,241,137,93,190,156,106,
162,189,97,137,20,244,195,68,121,215,206,41,218,126,184,41,79,185,143,111,206,56,127,63,25,2,170,124,249,224,32,53,63,238,39,128,123,198,154,237,189,112,81,128,162,93,124,103,89,247,38,104,106,76,246,
225,221,246,226,67,209,172,5,4,39,230,241,174,171,160,207,142,47,186,79,172,199,176,13,188,232,215,126,198,52,23,97,227,9,222,153,124,11,155,85,222,203,235,113,170,45,254,78,60,18,116,253,57,82,180,238,
231,174,165,159,154,225,172,177,0,160,252,205,241,6,150,204,91,3,111,143,124,138,137,56,31,102,199,215,53,19,85,91,250,24,10,90,253,67,212,217,158,228,40,149,246,202,124,63,108,219,43,182,230,155,244,
195,72,158,30,88,102,218,98,245,227,142,147,68,31,18,228,234,104,180,126,114,128,23,79,117,12,186,81,208,31,115,239,237,135,80,242,93,173,226,100,65,31,92,36,137,11,67,223,141,113,102,43,240,254,176,77,
249,165,235,35,46,213,243,56,50,122,31,44,240,224,201,48,141,251,100,246,132,214,230,204,166,163,154,128,64,16,6,97,49,179,190,173,192,33,190,215,222,240,169,4,252,132,225,26,13,176,94,187,198,13,62,103,
143,166,40,49,2,235,119,128,128,106,40,106,107,15,115,164,36,235,90,224,94,209,162,216,245,157,129,117,63,239,183,248,192,238,246,188,25,6,225,246,224,119,123,107,24,141,111,215,35,220,209,138,246,190,
60,96,155,164,236,152,98,61,28,80,39,174,64,69,27,194,24,121,110,111,193,95,166,241,172,189,179,92,82,144,163,44,48,197,243,138,15,163,145,205,55,173,225,20,52,249,241,143,167,166,1,7,71,33,13,135,128,
99,91,175,174,23,192,47,218,228,165,106,250,117,198,170,3,213,209,137,20,244,201,30,143,249,158,213,58,222,15,227,94,190,51,250,235,15,168,48,116,26,223,223,129,42,172,220,207,140,59,122,189,98,158,213,
249,112,236,215,100,61,231,18,85,132,222,36,21,117,28,211,90,111,225,254,46,104,4,0,136,52,9,231,46,162,15,91,127,219,114,217,222,184,69,165,41,224,190,115,253,223,167,43,82,210,6,107,0,183,223,122,50,
34,164,12,239,188,171,77,158,248,99,58,53,62,220,12,237,243,226,228,125,49,39,76,81,151,241,151,2,16,87,49,246,255,0,172,164,175,55,171,254,158,92,20,37,208,0,251,97,85,135,79,182,77,149,23,229,188,70,
41,194,122,94,174,227,155,158,12,129,163,236,225,93,31,34,147,238,96,65,81,79,90,99,201,178,73,23,251,246,205,207,125,155,109,239,255,0,51,189,185,174,149,183,54,209,222,230,48,174,175,94,188,20,141,249,
244,196,158,230,191,32,254,242,128,192,183,226,97,228,135,213,54,56,51,4,191,25,16,8,15,70,121,190,48,46,5,243,222,251,195,215,91,106,241,40,98,163,222,112,85,7,132,47,89,51,77,123,102,195,129,105,187,
171,196,172,1,46,203,19,6,194,116,107,161,30,38,119,146,171,60,76,233,86,102,193,165,42,112,211,188,217,119,41,120,58,191,222,225,247,239,2,197,244,153,94,157,119,139,249,127,88,21,184,153,64,58,39,241,
131,27,233,140,80,190,159,28,53,207,51,188,87,116,174,175,88,182,39,211,139,13,13,187,67,206,15,172,223,190,26,71,220,201,231,79,27,222,29,35,94,184,235,183,75,241,114,96,232,235,8,99,206,248,139,118,
215,71,166,59,89,215,120,104,137,232,190,188,118,19,100,168,102,191,34,253,28,80,62,136,228,243,232,245,200,208,211,230,152,250,122,96,16,10,56,34,16,173,249,224,204,106,239,249,201,86,25,157,61,59,153,
87,181,126,92,32,167,227,133,61,177,191,107,144,21,102,158,2,1,160,250,223,190,43,98,15,123,202,195,189,95,207,19,11,112,234,131,251,222,61,127,86,122,135,255,0,185,121,64,122,250,102,181,72,5,224,133,
54,32,215,211,130,96,66,39,25,87,74,233,83,215,38,93,62,95,124,112,249,44,11,40,117,140,74,206,169,207,246,23,223,254,48,88,167,69,119,125,186,252,96,11,83,216,8,62,156,88,25,94,33,128,161,45,41,179,221,
235,237,148,20,104,55,190,217,185,98,3,159,87,209,202,16,34,66,14,111,16,118,235,50,90,17,216,105,166,62,3,111,143,124,67,90,222,189,127,28,94,38,198,118,204,211,228,113,198,247,252,97,112,180,233,200,
189,14,67,180,143,143,92,187,147,220,55,144,18,85,86,188,105,43,176,242,203,237,139,137,78,169,211,227,188,59,229,244,33,103,177,142,152,122,150,79,174,20,211,210,198,253,156,68,0,61,71,158,240,27,68,
54,35,94,124,113,29,168,109,126,113,86,125,229,241,245,206,219,72,235,219,129,59,195,74,172,103,2,138,215,229,188,68,160,245,31,63,108,18,233,209,95,96,206,173,0,0,10,26,215,140,1,17,105,125,239,247,215,
10,71,167,10,135,96,251,203,227,133,185,218,98,153,95,89,255,0,49,17,38,167,94,236,224,142,192,200,212,193,191,163,39,219,137,30,135,223,120,117,11,246,192,167,238,249,194,82,245,231,16,163,201,126,56,
38,190,186,12,98,53,189,204,137,211,167,233,139,118,183,239,172,22,215,209,48,68,122,46,41,243,31,103,2,208,163,155,32,215,201,142,151,208,254,114,98,236,89,135,165,231,124,12,218,181,235,211,29,168,125,
114,66,39,165,197,59,87,235,130,20,251,152,246,227,135,243,241,144,227,179,231,207,1,129,169,245,254,112,31,0,187,246,252,103,116,213,191,28,80,168,20,75,163,219,58,214,125,40,230,173,36,193,124,127,31,
214,123,138,31,33,191,206,38,27,170,109,58,248,192,235,225,61,235,252,39,26,42,189,31,182,69,232,95,166,122,148,252,243,42,123,47,203,255,0,114,138,112,0,116,45,247,239,130,254,72,191,140,99,108,150,179,
119,208,114,37,52,116,10,62,75,194,53,173,38,151,89,191,212,239,70,177,150,138,122,174,175,87,25,163,103,134,127,169,142,172,207,89,243,176,244,194,196,178,254,131,191,174,65,165,89,248,197,224,139,249,
113,5,106,99,170,15,72,223,183,217,128,59,21,234,236,113,30,75,161,217,52,39,147,6,65,189,59,248,28,29,135,217,247,200,250,63,108,216,169,189,207,92,52,9,222,175,120,36,237,111,7,181,54,207,231,59,38,
235,175,174,44,175,176,145,163,232,97,113,9,220,134,179,93,228,73,167,238,227,72,187,253,11,233,183,235,157,55,99,166,239,9,9,61,65,239,196,160,54,110,253,114,107,220,222,158,207,120,103,99,21,255,0,225,
157,236,217,130,124,79,42,148,214,117,172,2,93,110,253,178,90,8,154,220,217,131,116,190,221,102,144,160,58,6,127,24,108,40,123,249,194,65,238,175,150,241,112,50,31,47,103,182,40,21,64,10,190,0,192,55,
132,223,5,254,241,103,250,101,9,36,11,175,60,74,162,14,174,195,89,230,36,158,61,184,107,192,147,189,225,212,46,5,43,218,255,0,56,123,227,16,222,190,215,131,221,237,172,101,43,126,50,61,205,24,191,107,
250,192,61,164,236,195,64,241,138,34,122,226,72,83,124,2,134,174,238,111,98,87,207,191,211,30,203,230,107,130,45,245,208,98,162,29,248,200,58,116,249,245,197,59,95,124,22,215,78,204,16,61,23,249,197,62,
99,237,131,105,216,251,240,2,53,189,250,225,234,21,254,126,153,41,186,191,110,28,86,19,85,134,36,83,28,31,76,243,192,157,97,54,180,249,164,224,168,22,224,104,33,191,191,11,82,6,94,221,123,201,108,47,211,
254,103,155,105,25,225,152,204,170,48,223,170,31,140,60,195,178,30,243,138,21,132,222,81,43,173,239,139,25,190,93,209,153,114,12,193,89,186,119,112,255,0,123,46,31,76,50,130,165,29,124,57,241,84,255,0,
63,229,155,122,183,40,176,30,190,113,49,68,12,147,109,91,190,59,167,215,46,156,200,47,255,0,183,240,195,31,166,167,196,224,103,111,159,124,139,208,253,177,208,2,35,119,215,131,98,217,213,242,31,92,141,
149,130,17,139,134,223,156,53,244,255,0,172,243,133,212,105,248,157,228,210,52,91,247,195,72,250,35,154,102,79,73,142,104,147,207,169,137,176,222,225,235,222,54,213,136,44,190,71,175,161,148,126,171,209,
223,177,231,43,87,171,208,61,231,71,182,107,130,182,231,116,109,220,198,103,165,96,29,254,51,255,0,220,97,206,206,188,204,116,167,190,40,175,143,249,132,232,117,214,125,152,197,252,29,96,66,25,235,62,
112,158,218,243,143,72,22,239,254,216,23,77,240,63,140,52,117,236,189,45,205,152,165,166,120,31,241,76,166,22,130,15,180,105,199,176,103,85,103,220,195,41,5,221,159,137,139,148,95,85,95,235,215,4,237,
110,52,249,3,235,147,68,146,77,120,156,116,108,52,111,157,97,208,95,182,38,175,147,124,109,108,53,235,227,131,179,233,215,190,5,129,206,198,48,197,188,176,47,104,153,64,58,215,241,157,111,211,26,161,255,
0,71,21,103,153,138,189,187,234,255,0,249,136,201,62,156,88,104,123,144,243,157,254,251,28,52,143,185,146,206,159,156,54,131,94,180,193,80,241,134,145,247,199,157,134,248,10,134,174,253,243,123,157,190,
125,254,153,190,90,172,246,225,27,198,153,89,134,47,156,80,62,136,227,152,135,183,174,70,73,31,52,199,211,211,33,0,163,172,16,136,93,240,108,218,239,59,88,102,116,244,238,101,94,213,250,225,141,159,111,
124,112,212,138,59,19,12,40,22,199,90,183,225,205,7,131,217,189,93,251,188,76,1,129,254,249,203,144,65,239,43,14,245,115,97,255,0,89,193,123,107,126,41,73,154,253,53,254,177,254,178,187,46,166,60,208,
31,111,76,214,174,128,189,143,241,149,167,74,254,123,63,57,164,130,188,165,91,99,184,74,125,233,194,169,93,109,61,113,220,193,33,225,46,57,29,20,30,30,147,239,139,21,170,251,254,127,227,16,133,93,79,191,
6,41,13,96,168,233,119,245,63,140,237,220,225,244,8,235,227,54,189,232,65,62,127,235,128,251,39,244,157,178,144,29,72,4,126,248,156,55,205,109,244,179,34,141,7,183,254,79,10,253,125,61,55,244,97,212,151,
228,181,237,116,96,78,193,96,38,187,218,104,254,115,127,158,142,190,51,43,19,99,60,226,132,216,123,4,95,30,185,119,72,87,94,248,61,30,58,159,129,250,75,236,228,134,241,98,231,122,249,193,1,59,243,132,
73,186,237,224,13,121,103,172,198,86,108,241,137,71,163,249,206,193,126,134,64,66,126,120,4,129,235,192,7,191,79,190,95,209,200,79,225,210,57,189,201,191,81,233,196,0,44,238,226,212,125,46,118,61,167,
227,132,247,5,55,119,56,43,62,142,11,16,111,89,236,58,219,172,247,157,117,28,22,138,143,120,82,61,14,23,109,145,235,223,124,81,158,113,76,175,107,63,230,41,18,107,211,231,137,97,6,108,80,206,215,195,212,
251,113,3,209,249,206,145,126,166,5,43,199,252,194,82,236,243,140,99,201,126,56,38,183,190,178,172,175,107,255,0,230,82,77,235,174,38,54,116,139,60,231,111,145,216,152,105,31,124,98,144,159,156,216,29,
122,211,18,41,232,185,49,74,44,251,224,233,77,239,129,159,109,252,99,178,29,238,100,132,77,234,229,94,215,239,130,148,251,152,246,252,226,159,155,227,3,35,179,231,207,0,35,88,60,128,191,159,182,121,22,
41,246,14,58,187,127,66,228,126,248,224,176,162,93,30,217,214,122,211,188,110,225,175,76,173,241,123,78,167,133,118,189,90,159,79,206,89,4,39,230,241,3,11,209,251,98,11,105,15,149,112,0,88,83,195,217,
141,183,118,55,237,191,137,136,48,175,99,130,216,194,97,132,217,62,117,255,0,229,133,101,15,29,163,201,241,138,254,36,122,28,241,83,94,185,241,9,252,96,80,236,64,249,92,187,20,7,64,179,121,126,62,219,
236,191,188,96,57,97,218,167,185,128,189,26,159,195,70,92,71,157,43,125,169,137,234,127,171,185,134,52,135,237,112,106,95,12,7,192,205,99,254,181,190,240,93,31,103,2,175,244,35,155,134,3,99,253,79,198,
17,3,25,94,158,48,90,85,236,191,28,116,171,105,229,234,248,194,79,106,248,255,0,138,97,164,244,63,156,104,54,61,186,125,177,54,179,215,91,49,210,252,231,202,186,251,228,194,141,182,19,207,21,157,11,81,
85,232,50,186,79,87,255,0,145,148,2,175,84,135,185,167,27,75,180,94,205,67,2,145,107,219,217,79,227,58,200,43,214,255,0,140,155,4,79,227,6,240,253,179,168,172,58,154,192,113,91,222,27,7,167,126,252,105,
27,24,245,241,237,194,110,121,33,138,138,252,102,137,35,170,78,38,162,18,93,248,207,32,136,158,61,184,116,211,82,111,183,58,69,250,152,23,94,215,130,32,220,191,78,248,61,222,208,198,88,29,248,205,22,104,
245,197,59,92,39,183,93,225,136,244,120,52,40,13,63,64,229,176,16,119,227,4,41,66,242,182,175,15,241,118,200,81,118,84,175,91,211,77,195,129,40,12,18,248,32,119,26,14,141,215,163,161,249,39,225,18,4,196,
157,172,93,192,243,235,15,128,13,245,132,12,48,30,211,230,183,231,55,196,210,91,97,179,145,52,19,107,26,107,187,175,117,89,58,162,133,198,236,105,133,242,51,164,78,186,75,89,114,80,165,31,100,53,213,188,
161,232,169,252,7,155,10,162,81,76,143,23,87,0,80,165,209,220,64,75,45,247,111,7,197,223,89,161,75,214,50,212,150,246,5,0,67,181,45,56,111,68,30,200,235,229,109,104,134,104,247,238,236,255,0,23,162,239,
29,166,229,65,192,17,206,145,235,216,41,182,192,102,35,202,110,212,137,212,161,37,132,160,5,157,36,3,118,49,234,193,20,247,197,7,211,28,196,61,178,55,163,230,156,21,2,143,251,227,11,65,13,253,248,51,197,
212,207,68,228,91,11,244,191,198,53,138,188,211,102,191,56,194,149,71,99,225,53,139,133,123,7,191,15,98,194,55,30,155,104,66,55,220,200,191,93,222,153,41,91,111,70,199,77,220,223,136,76,166,123,103,132,
2,251,175,239,43,26,155,53,76,184,178,7,135,164,245,28,88,22,235,195,242,121,250,96,177,62,179,119,231,4,126,63,138,167,137,196,245,18,35,95,235,14,193,97,177,177,38,110,151,212,112,251,58,196,8,31,113,
126,46,62,146,245,95,243,49,114,201,213,147,210,248,113,98,199,173,255,0,41,146,126,3,204,11,236,114,3,237,167,253,28,232,173,192,218,207,187,150,101,69,126,255,0,56,105,178,196,114,136,186,124,66,98,
136,1,99,234,97,61,109,190,179,41,134,229,65,11,163,215,3,182,33,117,143,26,63,222,0,64,3,160,33,248,199,130,217,125,143,243,142,229,85,13,79,183,102,108,52,108,158,113,73,243,131,252,100,241,133,183,
176,222,211,71,211,35,80,53,14,128,194,99,163,254,96,38,194,180,251,56,140,226,244,155,3,243,28,20,173,104,66,15,201,119,158,144,192,13,15,87,151,11,87,155,190,0,11,113,61,117,215,8,227,222,103,104,184,
105,182,165,215,111,13,177,176,216,108,109,188,109,153,229,54,230,138,157,106,139,234,24,96,133,150,156,184,3,16,22,58,164,36,147,246,17,111,71,225,187,45,100,239,0,196,29,188,19,65,5,54,30,7,166,112,
44,148,137,102,142,85,17,241,190,111,226,144,163,233,20,109,232,2,249,252,182,64,69,215,82,40,40,54,176,155,185,0,151,181,203,217,243,122,12,108,96,84,210,234,171,154,2,21,70,139,94,22,144,88,40,227,78,
221,161,67,235,107,80,203,62,183,214,62,235,58,54,179,20,84,184,253,94,247,119,72,116,86,225,57,32,234,153,105,232,70,243,86,148,42,71,114,245,232,130,27,82,253,12,209,178,28,40,214,8,145,209,94,145,73,
166,240,136,145,98,82,21,83,97,147,8,209,109,87,0,248,163,103,70,84,171,183,87,9,232,3,239,59,207,247,220,187,255,0,3,21,22,131,249,142,121,173,158,137,172,214,83,224,110,21,166,15,201,245,50,2,45,127,
65,46,195,120,35,227,29,169,101,17,122,75,130,52,7,154,162,218,46,166,169,216,209,231,190,73,47,21,232,161,159,120,245,46,19,27,149,0,24,211,114,134,35,233,156,226,39,133,136,215,69,64,48,53,168,166,52,
84,69,111,194,250,9,21,48,190,234,33,14,105,162,136,196,29,234,188,136,129,78,228,110,30,179,176,171,4,7,56,238,143,133,64,13,131,210,8,166,77,45,163,102,38,94,141,85,236,64,128,109,167,216,68,7,8,33,
218,188,108,143,64,195,24,112,33,107,177,177,181,53,48,159,242,69,143,116,88,132,240,128,222,160,32,73,139,56,100,175,101,33,225,99,33,56,210,244,218,154,153,48,37,29,125,240,66,33,119,193,207,182,185,
218,195,235,50,71,106,179,215,43,235,135,27,124,123,224,191,232,192,228,5,97,27,241,46,82,45,148,233,235,22,187,184,221,189,19,191,124,136,3,38,89,44,123,195,73,189,4,9,233,253,240,47,107,207,197,61,98,
139,133,166,248,189,103,159,124,91,217,217,164,175,174,153,92,119,217,131,224,247,140,99,163,104,190,87,94,175,9,181,106,54,158,222,50,76,36,36,225,58,215,162,251,204,19,164,252,11,157,219,36,47,174,94,
173,79,156,191,10,18,248,47,5,189,13,125,241,10,119,237,35,214,127,93,229,77,233,214,132,153,43,1,59,38,123,25,142,39,190,108,32,68,132,30,17,128,170,221,245,141,233,47,135,133,250,231,169,0,5,223,175,
142,42,133,73,231,120,32,251,191,156,113,189,3,246,112,201,220,233,76,30,70,244,211,50,142,232,11,161,243,132,49,190,22,238,253,115,114,54,181,120,9,242,77,183,248,198,41,170,194,195,254,251,226,80,49,
212,87,232,100,7,67,247,227,164,118,62,191,124,157,132,214,161,53,192,128,6,189,126,112,77,143,165,255,0,184,179,124,231,126,129,223,176,67,80,232,132,142,241,194,253,125,19,64,35,189,43,79,4,7,39,108,
65,232,77,155,111,109,228,89,100,52,90,16,54,251,42,34,129,164,247,32,29,215,165,164,245,198,55,208,121,55,52,80,197,48,12,134,75,164,198,67,233,167,130,76,90,79,172,3,124,209,168,122,106,111,53,113,198,
40,90,1,246,213,168,19,1,42,181,215,196,244,87,43,11,218,32,13,166,205,160,132,197,192,59,42,204,2,159,234,52,170,199,125,15,68,157,205,196,160,38,14,145,24,160,214,21,114,238,64,153,236,155,9,123,141,
229,16,221,168,9,47,62,137,214,177,54,83,86,72,33,85,59,47,102,16,148,133,18,221,160,176,246,95,105,140,184,26,156,14,13,172,0,219,125,120,119,222,63,252,71,95,92,221,236,19,237,159,29,231,117,246,251,
222,52,249,117,125,103,215,55,250,254,153,173,254,56,245,167,127,44,252,167,58,62,76,214,223,107,187,204,199,212,239,250,205,29,61,93,222,189,248,237,255,0,93,100,234,234,184,90,78,252,124,227,218,252,
173,206,159,169,212,199,183,231,47,71,250,103,220,223,30,205,223,93,247,151,179,189,255,0,254,51,80,245,221,227,167,77,151,214,102,199,202,243,61,251,125,243,174,151,115,200,158,122,253,243,255,0,206,
63,210,113,191,63,233,155,95,25,175,43,141,250,61,143,91,199,71,135,111,137,199,174,250,167,123,102,245,209,125,243,164,117,61,19,241,197,251,49,126,110,127,10,241,163,94,212,240,61,248,103,143,79,62,
185,84,157,221,100,233,159,15,88,227,208,44,242,79,198,95,180,121,103,231,159,76,219,94,207,121,172,241,122,186,244,153,224,122,159,206,77,223,82,124,240,124,163,115,214,123,103,159,4,250,254,115,225,
197,248,61,184,174,221,84,200,211,215,246,101,107,239,69,234,220,214,250,159,12,254,83,51,61,247,239,207,255,0,204,233,244,243,122,153,29,120,106,122,143,151,245,157,159,62,58,231,171,173,125,251,250,
241,209,245,254,50,62,91,251,113,212,238,125,152,118,252,19,251,206,175,25,231,187,199,253,191,110,54,62,150,117,125,182,97,60,250,126,120,245,164,247,245,207,227,56,116,250,27,109,235,147,179,231,206,
120,109,215,173,239,223,63,255,218,0,8,1,2,3,1,63,33,225,253,83,131,30,47,238,191,178,185,56,49,255,0,20,199,139,250,39,7,235,127,81,250,223,213,56,49,226,254,171,198,184,167,11,63,78,185,92,175,26,229,
95,212,126,183,139,254,84,224,127,116,253,217,193,143,23,246,221,225,239,146,19,128,107,59,214,29,241,53,135,13,99,222,60,28,117,157,225,222,77,231,156,243,250,31,252,153,193,251,179,151,139,251,111,234,
214,67,136,100,229,14,38,32,231,92,38,67,33,144,200,100,50,50,28,57,39,233,57,95,252,35,30,47,234,63,91,250,143,214,254,169,193,250,95,213,56,49,226,255,0,134,127,159,112,230,112,126,183,245,31,187,56,
49,226,254,196,224,199,139,251,71,235,156,28,175,254,4,224,253,185,193,205,253,71,232,156,24,254,163,244,78,12,120,191,180,99,250,167,7,55,244,63,248,83,245,206,12,120,191,168,253,111,234,63,91,251,175,
234,156,24,241,127,101,195,255,0,14,112,99,197,253,71,235,127,81,205,253,15,234,159,173,226,254,137,193,143,23,246,140,120,95,240,207,240,92,191,168,253,185,193,205,253,169,203,250,31,213,56,49,226,254,
219,250,166,56,103,159,240,211,252,43,251,83,131,30,47,234,63,91,250,143,214,254,163,245,188,95,209,56,49,226,255,0,141,127,199,156,24,241,127,81,251,115,131,155,250,31,212,126,183,139,250,39,6,60,95,
210,255,0,228,78,12,120,191,168,253,185,193,205,253,163,155,250,31,213,56,49,253,169,203,251,147,252,167,47,248,51,131,30,47,238,191,161,253,151,245,31,162,114,241,127,243,47,237,78,12,120,191,168,253,
185,251,47,234,63,91,197,253,19,151,247,239,232,159,230,78,12,120,191,168,253,185,193,143,23,244,63,162,112,115,127,67,197,253,19,151,244,63,226,95,208,255,0,135,56,49,226,254,219,250,167,6,60,95,216,
156,28,223,221,127,101,114,126,204,224,199,247,239,232,159,180,229,255,0,6,112,99,197,253,71,235,191,186,254,163,245,191,183,127,98,112,99,197,253,19,131,155,251,183,246,167,6,60,95,212,126,233,251,115,
131,155,250,31,210,228,253,243,30,47,234,49,253,79,239,159,162,112,99,197,253,183,245,78,12,127,106,112,99,197,253,15,236,191,226,152,254,212,253,47,237,78,94,47,232,63,91,250,167,6,60,95,216,156,24,241,
127,104,253,147,131,247,76,127,106,112,99,197,253,19,247,207,221,156,24,241,127,104,199,139,254,12,224,230,254,214,191,194,191,162,112,126,243,197,253,169,203,197,253,183,252,57,193,205,253,71,235,127,
106,127,224,159,162,114,241,127,109,253,83,131,244,191,170,112,99,197,255,0,30,112,99,197,253,219,250,39,6,63,190,254,163,245,191,170,112,99,197,253,137,193,143,23,246,143,240,39,23,252,107,250,39,239,
152,241,127,106,112,99,251,83,131,30,47,237,24,254,169,142,31,173,224,255,0,201,49,226,254,163,244,78,95,212,126,183,247,12,127,84,224,199,139,254,25,254,49,250,39,236,206,7,245,191,168,253,111,234,159,
173,226,254,137,193,143,23,244,191,185,63,101,255,0,34,254,203,251,19,131,30,47,237,78,12,120,188,63,170,112,99,197,255,0,26,254,135,245,31,248,61,126,131,30,47,234,63,91,250,143,214,254,235,197,253,223,
31,249,102,60,95,212,126,183,245,28,223,208,254,163,245,191,170,126,155,251,19,131,31,216,241,255,0,135,56,63,116,230,254,209,205,253,15,23,244,78,12,127,112,199,255,0,98,112,99,197,253,215,244,63,178,
254,225,143,23,244,78,12,127,106,112,127,225,156,24,241,127,81,250,223,221,127,106,114,254,221,253,163,30,47,232,159,231,24,241,127,193,156,28,223,216,156,28,223,208,254,199,159,214,127,133,127,240,39,
7,237,206,12,120,191,177,56,57,191,186,254,175,31,168,199,139,254,12,255,0,53,253,137,193,143,23,245,31,174,254,235,254,41,143,236,28,79,211,127,240,39,6,60,95,212,127,148,115,127,67,197,253,26,255,0,
32,255,0,48,199,129,215,237,191,170,112,99,251,83,131,155,250,31,223,63,68,253,199,255,0,5,224,253,79,234,156,24,241,127,98,112,99,197,255,0,36,199,139,255,0,158,119,143,234,156,24,241,127,104,199,139,
254,25,251,230,63,249,126,63,68,224,199,139,254,116,224,199,255,0,10,112,99,254,99,197,253,7,235,127,84,224,253,47,234,156,24,241,127,199,159,182,99,255,0,132,126,183,245,78,12,120,191,177,56,49,226,254,
209,143,234,156,31,179,127,245,167,47,23,246,39,6,60,95,218,49,253,83,131,155,251,175,238,24,255,0,153,227,131,244,78,94,47,232,63,91,197,253,183,245,78,12,120,127,104,253,7,254,139,250,142,111,232,127,
84,253,111,23,244,78,12,120,191,171,175,208,126,185,193,254,35,254,100,224,230,254,135,245,78,94,47,15,234,156,24,241,127,104,199,245,79,211,127,67,255,0,154,101,253,169,203,251,83,151,247,94,47,234,49,
226,254,209,143,238,78,95,243,38,184,63,91,250,143,214,254,163,245,188,95,209,56,49,253,195,31,220,156,206,47,254,27,250,140,120,191,161,253,71,235,120,191,162,112,99,197,253,137,193,205,253,169,251,39,
254,28,224,199,139,251,175,232,127,101,253,169,250,111,254,4,229,226,255,0,131,56,49,226,254,163,245,191,186,254,212,229,226,254,137,193,143,238,28,223,212,126,137,250,111,237,207,213,57,120,191,168,253,
185,193,205,253,15,234,63,91,250,167,233,185,47,235,159,166,254,137,193,143,236,95,208,126,236,253,55,59,230,126,236,224,199,139,251,19,131,155,250,31,217,127,101,253,15,23,14,103,6,60,95,216,156,79,221,
156,188,95,219,127,84,224,199,139,250,143,215,121,184,245,205,203,151,139,250,158,15,209,57,127,84,224,255,0,2,255,0,224,79,209,114,229,226,243,127,71,127,164,127,76,201,250,39,19,153,250,167,47,23,244,
79,253,41,193,143,23,244,206,28,156,204,156,78,103,236,191,168,253,147,245,24,241,191,252,243,30,15,209,174,12,127,87,143,212,99,250,181,159,255,218,0,8,1,3,3,1,63,33,253,167,153,254,61,228,255,0,21,195,
247,207,240,239,39,19,245,77,113,190,39,1,114,100,222,120,224,175,33,172,131,147,55,196,192,57,55,250,95,214,127,156,254,235,251,183,147,247,74,100,235,14,156,92,167,9,133,199,91,198,78,46,241,156,55,
134,23,14,120,207,102,80,214,50,101,214,111,255,0,64,127,192,63,195,169,192,239,130,195,138,224,185,114,224,83,59,224,70,83,128,194,185,94,42,202,224,166,42,254,193,250,15,243,159,240,15,241,95,219,188,
63,227,63,172,253,78,31,248,143,238,222,28,63,106,240,225,196,255,0,13,255,0,15,172,55,254,115,254,1,251,167,248,175,249,14,31,191,63,105,230,126,233,255,0,129,120,112,255,0,207,188,56,113,63,195,127,
118,254,251,135,19,255,0,1,255,0,10,127,134,255,0,128,126,233,254,43,193,251,183,244,117,131,251,39,248,174,28,79,221,63,116,255,0,14,240,255,0,144,241,127,121,253,167,14,39,248,111,235,63,116,253,135,
15,218,63,241,111,14,28,79,240,220,63,113,253,219,201,251,167,19,246,174,95,216,121,63,240,156,56,159,248,231,234,63,194,159,248,78,28,79,252,7,245,159,228,79,209,114,254,137,251,239,237,156,79,240,222,
103,237,63,172,253,147,252,87,245,159,227,31,226,191,183,120,127,240,111,232,112,230,255,0,129,127,206,112,255,0,48,253,211,137,250,230,76,156,31,186,99,203,250,79,241,220,63,240,159,222,63,106,96,76,
188,159,176,225,250,142,122,255,0,12,255,0,14,240,254,221,225,230,127,131,127,100,253,135,247,15,208,127,225,56,113,63,105,230,127,140,126,201,139,251,238,31,172,255,0,46,240,225,251,142,28,79,240,222,
103,235,121,111,19,39,15,234,153,57,121,159,169,226,254,219,254,1,196,255,0,58,240,254,204,253,38,63,183,121,63,102,127,138,254,179,252,87,247,95,222,63,73,250,239,14,31,191,63,83,135,239,159,225,222,
79,218,188,56,127,138,254,135,14,47,249,19,244,95,223,127,192,63,106,242,127,138,225,250,92,56,112,226,113,63,241,28,56,159,186,126,167,252,199,153,254,8,227,254,59,223,239,191,186,255,0,152,225,254,19,
151,244,152,242,99,254,36,230,126,195,251,111,248,7,237,94,79,221,56,63,69,225,225,253,15,234,49,195,255,0,17,195,137,251,167,238,159,225,223,217,243,251,15,7,35,127,195,120,235,246,92,56,159,225,191,
172,253,211,246,79,218,188,159,164,253,47,248,147,245,159,176,254,235,251,175,235,63,100,253,179,31,217,127,67,255,0,153,120,121,159,248,103,232,56,243,135,233,127,89,250,47,15,254,43,135,19,255,0,28,
229,224,253,227,135,14,39,254,19,135,19,252,55,247,95,214,126,147,151,131,135,14,31,217,156,60,94,19,244,159,249,175,51,246,159,240,15,216,127,67,135,232,63,100,253,87,252,199,246,111,14,31,191,63,197,
121,63,108,253,47,47,23,255,0,22,240,225,196,255,0,192,127,104,255,0,22,126,167,15,242,220,63,195,188,63,186,243,63,195,127,73,251,78,28,188,159,249,110,31,184,243,63,193,56,127,69,225,195,255,0,105,195,
137,251,78,31,226,188,159,160,253,147,246,28,159,160,226,127,152,247,250,207,252,11,195,135,236,63,172,255,0,14,240,159,250,23,135,246,239,15,51,252,131,246,156,57,235,14,14,255,0,201,121,127,118,240,
225,196,253,167,15,220,127,206,156,60,26,255,0,45,253,227,246,175,14,28,79,242,14,60,254,139,195,201,251,142,28,184,127,252,27,250,79,242,46,95,216,53,251,143,248,207,248,135,234,188,56,126,201,251,143,
248,135,249,207,238,222,79,221,63,116,253,135,245,153,127,106,112,126,171,201,254,68,253,211,245,63,172,253,211,246,30,103,248,247,147,252,151,247,15,242,143,216,112,195,135,247,231,235,185,114,229,253,
103,248,239,238,191,226,31,178,126,163,135,247,38,79,209,127,198,191,190,254,203,135,19,252,163,252,89,254,85,228,230,229,253,251,195,135,249,135,238,156,77,254,167,244,92,191,172,199,244,156,204,127,
195,185,114,254,155,195,135,248,175,248,135,249,206,28,222,38,76,153,56,191,162,114,254,217,196,255,0,13,230,126,211,254,99,135,236,56,113,63,84,226,229,203,151,244,79,219,56,156,152,254,237,225,230,126,
236,226,100,192,223,19,38,76,156,78,3,143,60,28,63,172,226,126,167,15,210,114,159,174,126,153,251,7,18,255,0,131,121,153,56,78,39,50,224,102,178,103,71,233,79,211,114,229,203,50,229,203,188,188,222,46,
94,111,39,238,159,162,100,255,0,198,188,159,166,229,203,193,151,139,151,47,23,244,175,238,191,178,254,179,147,244,235,247,92,63,197,127,89,251,39,238,56,126,191,255,218,0,12,3,1,0,2,17,3,17,0,0,16,114,
48,194,109,151,226,65,241,179,89,184,11,29,100,225,180,11,105,164,9,101,146,0,187,219,55,226,143,0,224,12,97,102,29,207,39,111,183,135,159,241,46,233,73,92,98,15,23,207,49,48,136,127,218,38,194,96,150,
88,37,6,217,41,252,112,35,12,8,240,79,33,220,104,118,59,114,56,228,137,167,121,193,196,103,24,249,187,243,97,180,110,10,203,36,65,65,20,80,105,128,218,69,64,208,224,13,134,242,93,169,167,67,178,3,158,
93,161,115,198,70,179,232,23,117,233,59,30,25,192,127,34,206,180,16,37,150,154,13,178,144,5,6,28,252,109,111,223,30,117,131,0,57,147,24,55,62,221,209,28,237,120,155,229,185,56,114,71,227,30,67,232,160,
216,109,146,170,9,16,81,100,20,194,254,229,176,197,140,56,3,3,57,135,97,172,249,236,136,199,203,183,217,3,135,4,126,121,194,236,207,5,242,193,13,18,145,253,22,75,65,180,0,188,12,9,227,2,55,59,73,54,214,
29,10,232,14,57,63,29,212,26,226,71,43,156,110,248,236,39,190,196,209,41,2,209,15,52,26,64,166,193,124,4,56,43,113,241,153,124,97,208,12,40,224,198,56,216,17,198,44,115,185,230,237,151,32,249,216,42,80,
216,45,146,65,37,250,74,76,182,65,64,87,30,219,91,198,195,132,56,192,14,14,198,29,236,131,66,133,27,15,46,251,118,79,252,3,248,243,174,219,12,144,10,4,175,2,96,150,24,13,29,234,56,100,56,39,12,2,220,126,
37,223,202,127,35,1,182,242,254,118,0,123,136,60,108,113,185,122,129,40,162,11,108,6,120,68,130,88,109,16,78,55,146,112,228,109,215,246,97,177,135,90,56,3,153,39,167,112,71,24,3,198,195,153,182,124,182,
234,4,54,27,68,124,3,49,130,217,45,48,29,7,157,10,223,127,111,29,28,16,163,2,57,55,159,70,0,97,40,28,111,61,147,47,137,58,116,99,69,164,67,72,184,39,165,162,216,9,0,209,61,206,183,208,241,193,192,30,57,
187,115,240,184,110,39,38,243,206,218,201,240,252,1,143,36,243,24,68,180,139,223,128,129,33,252,208,13,2,11,99,104,198,24,158,64,227,19,182,223,25,199,226,206,33,54,143,205,154,13,193,28,64,79,59,110,
243,104,162,74,12,146,80,20,21,248,8,4,10,96,17,158,176,174,116,27,109,249,188,108,96,195,12,34,220,73,197,24,21,198,132,115,181,179,207,47,32,178,201,12,78,64,12,12,49,228,160,74,64,49,101,99,83,184,
223,195,135,2,82,48,230,109,206,196,113,200,216,140,132,51,106,103,195,242,78,132,144,131,4,134,94,60,145,249,4,52,2,32,180,206,117,153,185,28,114,165,3,28,102,221,124,101,27,205,185,252,92,55,3,248,54,
0,113,197,15,54,155,203,242,219,58,112,78,127,251,48,8,50,17,12,177,135,58,64,177,244,111,182,230,241,144,179,141,140,227,243,110,23,112,23,18,49,199,252,16,217,40,128,191,32,254,191,169,109,143,2,146,
201,38,237,168,27,15,14,235,110,7,24,138,81,195,146,56,34,243,135,55,112,106,60,15,224,223,31,64,44,191,191,27,125,58,220,144,6,4,22,152,8,223,144,180,254,55,228,99,137,20,140,113,27,101,168,28,97,118,
231,225,120,216,15,160,221,52,193,0,5,81,167,12,158,36,133,128,1,159,73,45,35,149,68,116,6,28,123,142,199,219,182,219,19,142,23,110,59,35,140,192,248,91,192,89,103,198,13,24,84,199,226,70,28,128,54,218,
83,82,44,2,3,44,114,39,148,110,53,27,157,252,28,98,69,91,224,124,192,31,142,24,205,192,232,167,50,153,131,138,160,105,175,99,143,197,243,225,71,40,178,0,195,249,110,206,67,249,219,145,207,32,114,184,227,
158,65,201,97,132,219,156,69,129,64,191,235,130,11,60,5,211,76,5,192,152,131,134,196,182,82,7,127,140,62,145,208,24,96,134,27,30,110,216,140,22,62,77,186,220,158,57,5,76,81,17,236,74,37,207,144,109,128,
137,41,114,22,204,178,91,104,247,108,28,17,200,156,211,184,212,110,54,100,107,228,219,236,129,227,2,54,60,102,27,163,141,9,220,252,57,72,18,130,4,180,137,95,114,195,36,60,219,159,15,196,187,233,142,199,
116,7,56,29,150,248,140,113,35,177,206,27,124,218,4,22,248,92,17,140,104,32,10,13,160,83,97,226,15,236,2,233,204,88,54,48,252,70,4,99,99,24,108,8,231,130,48,220,243,119,231,53,233,64,24,199,76,30,132,
104,128,218,37,52,25,0,175,128,65,54,130,207,97,194,48,112,6,2,227,14,255,0,75,237,71,13,135,151,125,251,7,12,23,104,180,75,197,61,93,41,34,82,65,160,10,8,0,184,220,20,209,16,7,199,33,108,47,50,109,165,
187,13,145,219,219,55,31,130,53,192,29,120,108,150,153,109,158,9,225,120,19,32,162,152,40,54,136,7,2,200,46,246,167,235,121,96,216,225,161,28,17,142,147,67,185,35,28,65,195,106,148,29,51,192,91,1,194,
43,144,122,96,0,131,76,148,88,107,34,139,32,167,253,167,15,134,28,193,192,28,27,196,35,128,56,241,28,119,92,229,129,192,29,244,83,116,19,77,116,51,36,148,1,73,132,193,43,16,26,45,34,55,224,194,78,24,21,
240,216,203,182,131,131,48,131,111,204,248,124,98,203,146,210,88,227,218,83,133,78,216,148,128,104,150,128,5,162,218,37,20,75,160,113,141,223,29,228,227,225,102,130,153,6,244,221,207,196,140,61,163,70,
245,91,110,177,47,22,67,80,52,9,109,130,89,13,176,90,97,144,11,63,189,190,252,156,54,52,225,198,5,108,37,214,12,10,198,194,113,29,61,23,194,18,113,5,69,42,44,252,80,96,2,216,5,176,80,1,160,201,110,189,
193,195,147,8,56,114,55,231,240,48,228,110,15,99,29,245,9,174,193,229,62,1,192,162,102,171,6,14,69,146,82,1,144,27,104,6,131,76,141,253,18,1,142,55,126,62,19,13,206,232,254,101,31,145,253,58,16,25,120,
132,118,242,166,215,37,230,17,21,32,217,33,166,64,32,182,1,105,146,209,28,242,54,219,114,120,200,91,134,194,81,249,183,147,48,36,17,65,35,98,214,92,134,72,125,211,210,31,48,154,100,2,75,96,148,137,64,
2,194,239,109,183,135,142,69,168,225,204,25,27,121,195,155,177,52,214,63,152,119,2,196,157,217,37,131,226,46,127,17,1,148,65,108,164,0,109,18,26,111,210,57,192,152,6,24,141,248,211,158,48,155,211,145,
144,100,64,219,42,55,171,130,16,109,33,203,177,22,119,68,148,138,108,6,152,69,34,208,11,190,57,199,115,232,219,237,137,195,11,191,31,137,135,192,108,8,205,150,183,221,173,190,41,178,208,7,228,89,204,166,
192,109,150,81,5,128,83,5,63,54,30,205,150,248,30,49,34,117,241,62,116,76,227,142,202,109,116,58,210,115,174,49,130,85,93,182,49,187,38,144,96,22,81,5,160,89,33,173,209,248,108,200,231,0,97,28,99,134,
34,230,48,194,238,211,95,119,27,73,236,137,47,22,9,102,164,83,192,162,72,101,144,83,41,2,26,65,148,18,224,14,48,67,157,143,55,110,68,43,12,38,216,100,108,52,53,157,205,21,105,20,150,26,96,182,1,4,50,209,
13,178,153,41,164,81,32,52,97,226,157,105,220,121,54,251,160,57,242,109,254,96,225,128,109,140,161,247,19,9,6,253,82,76,164,14,48,28,242,45,0,218,65,146,81,64,150,133,174,141,252,167,243,184,131,156,70,
223,100,70,28,145,178,237,151,116,28,2,94,46,123,207,36,150,9,45,205,187,172,178,81,1,22,1,72,182,9,123,216,61,35,32,56,132,142,55,0,115,200,24,46,124,187,33,201,232,226,197,171,248,14,248,146,24,136,
151,134,117,128,81,68,54,202,68,54,144,2,58,48,35,25,120,231,97,229,220,131,198,199,219,191,252,131,167,12,154,107,43,93,176,7,198,216,13,250,49,44,4,65,64,180,66,105,22,64,70,158,177,51,31,118,242,31,
206,192,237,185,219,189,209,60,224,15,214,34,185,65,96,22,41,20,17,41,240,136,208,54,26,64,166,137,96,22,80,36,177,188,181,125,104,244,172,8,227,9,184,252,1,143,32,231,177,195,173,70,160,243,138,63,20,
209,45,32,159,230,110,75,40,134,9,109,128,219,41,37,166,227,22,40,224,14,36,99,133,192,28,112,15,59,110,102,219,144,150,52,17,224,203,152,91,4,246,223,228,113,9,36,148,17,5,6,144,44,48,49,35,140,10,192,
94,108,223,73,137,168,115,183,166,238,126,36,230,138,26,38,250,65,194,133,232,32,7,212,123,107,100,36,209,105,130,139,37,4,52,230,45,158,194,225,240,167,195,77,131,107,102,195,240,70,60,2,14,79,100,113,
44,146,44,32,182,255,0,132,108,41,51,17,191,201,50,65,5,150,88,255,0,127,46,27,152,117,163,2,54,18,232,118,0,113,225,56,239,192,255,0,74,245,141,146,9,231,238,203,120,210,249,3,3,134,31,92,143,23,176,
47,240,225,144,177,156,57,11,193,120,56,96,23,54,145,70,222,155,115,124,213,2,76,18,56,198,109,200,172,32,75,248,244,204,27,13,6,192,246,215,156,11,8,195,155,190,31,9,199,247,108,34,190,79,201,170,31,
129,8,225,27,119,238,44,250,146,6,0,188,181,191,242,211,48,104,7,10,63,220,20,140,113,155,233,253,60,124,36,195,35,196,15,126,173,99,33,46,128,241,152,99,188,24,4,178,24,173,18,38,229,2,8,29,63,199,4,
47,84,71,129,181,196,195,222,203,16,11,92,17,249,0,237,193,70,30,58,51,106,49,65,48,251,47,54,217,73,18,218,8,146,11,0,166,66,4,180,42,187,29,249,54,99,243,99,58,65,26,114,79,220,13,129,163,251,176,58,
136,71,221,169,35,72,151,217,37,38,155,64,182,90,64,148,9,100,7,41,220,221,151,3,18,54,224,111,151,255,0,127,255,218,0,8,1,1,3,1,63,16,100,169,128,219,160,38,177,83,40,66,141,238,54,142,26,50,41,230,181,
191,94,8,247,105,5,9,59,158,252,121,80,77,165,126,239,92,216,156,214,130,133,190,59,202,118,162,2,13,7,247,193,129,212,12,68,235,183,44,17,68,80,196,34,107,141,113,233,26,252,173,239,8,218,6,52,17,250,
227,184,221,44,234,165,198,33,0,59,93,38,79,113,20,205,176,125,248,55,69,2,13,26,55,183,17,113,63,81,228,245,145,13,26,2,94,218,30,250,197,202,178,246,169,166,85,219,80,36,124,250,92,58,73,8,61,1,196,
1,146,207,181,223,227,54,151,81,180,124,60,46,94,231,66,186,121,248,194,196,62,8,253,30,185,76,232,26,32,18,240,86,25,10,2,134,252,252,228,16,128,88,26,39,173,205,97,106,206,171,48,120,88,212,13,62,238,
4,80,101,222,235,227,188,191,252,246,49,16,64,166,238,193,124,100,147,18,112,83,0,190,46,143,93,247,214,1,20,18,128,36,43,237,130,99,207,132,3,213,195,90,8,86,188,79,185,137,34,133,177,84,190,187,203,
25,85,104,62,33,99,193,147,222,30,180,137,245,196,54,164,74,208,97,47,203,130,80,43,183,94,129,95,182,74,119,200,17,2,110,219,114,128,6,209,171,82,147,209,192,50,187,4,74,87,97,224,193,68,70,34,35,232,
155,202,129,138,170,81,238,106,249,225,16,0,10,99,118,179,188,56,96,55,2,93,90,189,92,150,66,48,105,40,127,44,242,136,247,226,167,129,225,194,76,218,34,38,35,60,60,158,62,38,18,64,69,6,128,63,176,226,
149,4,157,77,54,49,247,192,40,221,84,75,244,197,220,55,68,103,138,89,243,130,52,170,142,246,30,215,55,156,54,134,15,132,227,79,20,13,170,163,96,125,49,58,190,80,136,189,247,148,33,40,133,124,91,112,196,
186,238,35,215,39,16,22,13,145,62,184,5,216,37,237,6,99,35,186,193,233,20,207,50,141,98,72,232,225,24,138,105,168,80,60,124,100,92,7,88,96,246,102,0,111,48,3,94,189,78,14,33,101,54,138,110,199,93,99,119,
128,62,232,225,166,193,85,246,155,251,225,160,97,83,54,61,226,224,155,211,18,62,93,76,210,166,200,10,27,110,9,33,12,9,104,93,219,227,15,37,142,201,170,147,141,248,202,2,160,67,174,181,136,10,13,7,76,74,
125,113,96,34,129,38,186,142,2,9,13,40,107,237,149,243,137,8,93,89,237,195,53,40,0,16,69,187,200,61,21,17,66,190,62,120,24,144,59,47,72,244,152,150,196,218,65,7,232,195,141,180,32,117,181,215,227,13,35,
220,240,245,140,204,70,218,110,181,182,63,114,177,245,251,225,134,147,138,215,32,163,176,181,232,93,150,126,80,116,66,49,15,25,23,48,92,186,3,3,123,107,60,128,191,155,49,129,84,164,11,112,49,181,9,17,
199,222,173,12,89,151,54,135,130,186,123,228,132,92,115,224,123,186,137,67,40,184,163,3,230,232,217,202,135,204,7,20,162,115,39,46,118,240,86,66,80,226,89,99,38,42,109,42,178,107,188,82,184,116,210,180,
74,81,173,224,220,176,95,35,96,122,172,46,107,199,187,140,0,136,145,28,5,34,180,30,165,245,194,14,215,121,153,78,26,74,76,15,93,211,13,64,79,42,33,108,210,131,169,161,29,216,20,77,186,202,243,187,117,
210,90,21,134,131,38,184,122,106,89,8,138,155,145,217,143,26,61,143,181,154,123,177,135,242,113,225,51,84,246,131,134,50,242,95,112,153,139,16,70,152,159,91,143,37,6,202,112,68,29,235,59,127,124,151,106,
88,105,27,41,131,80,50,219,29,212,241,78,14,149,110,0,200,61,184,2,96,40,6,136,174,83,247,168,245,171,139,9,161,37,161,239,112,125,131,208,215,211,188,17,82,137,15,163,148,20,145,141,242,135,94,248,198,
0,180,245,77,94,40,17,42,88,5,190,249,68,103,152,40,124,98,207,49,60,116,22,62,102,30,175,198,233,181,91,183,110,243,108,202,53,108,207,128,50,158,185,214,157,39,102,17,196,198,232,218,255,0,33,150,141,
168,33,86,233,125,49,0,20,232,54,184,72,191,8,43,187,181,200,239,212,123,69,97,60,250,24,2,1,245,173,39,180,224,161,118,41,210,175,120,136,163,216,163,231,103,198,82,20,144,176,170,119,237,137,32,208,
4,109,225,171,145,219,80,52,14,143,118,42,246,223,159,109,103,110,229,54,136,131,215,173,205,104,64,34,108,137,174,54,201,110,167,69,4,108,125,112,165,0,98,204,125,252,48,62,81,134,140,80,126,187,60,154,
192,132,145,139,78,196,124,14,156,79,214,21,16,20,174,143,78,9,244,139,181,237,208,99,148,80,10,34,34,19,206,2,212,24,109,124,7,89,100,97,18,3,79,174,78,160,72,3,72,63,92,35,21,32,175,110,142,49,29,171,
243,148,35,36,80,179,93,122,240,44,26,45,64,158,134,45,48,120,202,15,213,229,205,37,80,3,91,22,235,227,133,66,102,171,9,41,171,49,138,147,113,240,180,252,97,48,193,75,236,59,205,30,70,132,183,173,159,
253,200,74,78,136,171,235,214,33,108,20,5,7,163,215,125,97,140,8,131,177,116,119,113,118,213,157,135,170,26,224,217,176,0,21,242,241,239,128,2,180,214,202,125,112,18,233,65,77,89,63,23,15,147,91,19,71,
232,107,15,96,101,132,105,169,196,9,136,0,245,164,221,250,98,239,184,128,151,174,184,105,72,107,109,170,248,154,222,24,2,250,147,87,197,244,201,102,9,104,61,3,231,131,66,34,53,4,166,169,155,225,69,164,
161,218,190,49,0,1,85,17,45,48,113,72,20,8,0,190,113,130,234,0,20,0,66,76,212,51,176,116,69,187,196,190,147,176,131,29,120,64,82,194,182,206,118,254,64,129,7,230,198,62,119,177,18,122,147,227,178,153,
81,101,56,180,2,137,90,88,3,19,245,157,63,118,205,16,177,169,198,188,136,138,25,214,152,20,38,178,207,197,34,144,97,231,235,182,18,216,0,12,24,251,176,47,78,42,234,253,154,105,131,140,255,0,142,61,193,
164,134,57,78,96,54,28,147,19,34,237,65,189,11,148,107,73,2,118,65,0,238,41,36,57,145,64,228,70,180,64,132,21,244,20,189,91,125,140,73,250,146,173,128,57,75,103,106,128,55,41,12,139,96,75,109,41,247,68,
36,29,77,49,149,89,151,245,130,242,196,178,226,167,32,26,45,178,124,77,161,25,58,100,35,97,9,5,135,54,158,105,156,129,240,161,190,144,193,79,83,132,96,0,214,196,26,4,22,39,80,162,66,12,97,188,129,6,100,
173,100,174,91,101,108,131,169,192,242,235,32,96,162,199,194,11,84,113,145,53,226,152,67,138,170,42,8,158,190,115,118,223,136,163,31,227,52,32,128,31,69,153,167,224,44,119,34,118,251,188,35,73,154,22,
1,7,121,72,90,216,236,46,217,59,196,99,209,8,74,151,167,20,85,74,246,170,220,23,74,44,13,143,130,254,115,72,145,17,58,136,229,222,137,82,88,89,79,71,232,111,7,24,65,77,32,122,32,19,0,33,24,1,85,250,101,
91,222,130,171,91,119,139,41,88,93,3,111,132,193,39,181,194,116,104,62,188,89,84,233,0,43,245,122,222,80,161,138,81,163,60,147,198,106,90,17,80,84,219,239,136,12,186,232,132,21,105,3,236,120,203,194,122,
125,145,116,27,203,123,223,71,219,89,75,144,45,29,142,207,108,7,12,160,32,6,253,219,194,167,86,204,98,68,52,221,98,145,3,228,64,245,118,196,203,180,65,151,141,250,84,193,245,169,106,87,120,144,206,39,
108,174,129,185,197,252,2,246,169,16,3,182,46,11,125,129,1,29,47,212,193,93,127,208,134,193,240,248,189,63,46,41,81,27,136,242,4,218,250,220,130,10,138,37,163,231,88,40,21,134,207,149,46,37,3,177,19,233,
136,40,113,65,81,63,46,24,176,116,182,132,190,152,1,12,148,80,125,45,185,40,116,64,106,171,60,112,88,194,69,189,122,189,122,196,18,65,111,162,141,98,137,100,13,244,142,13,37,106,37,19,219,255,0,185,13,
9,233,19,247,117,155,74,129,160,235,195,235,130,137,72,145,216,44,213,244,193,9,76,136,174,143,164,59,225,145,228,192,86,67,211,198,38,237,64,210,39,105,191,76,106,5,29,190,161,161,248,194,18,235,209,
30,190,153,37,0,176,116,39,215,12,78,128,223,122,102,64,165,21,14,196,117,248,197,87,168,52,2,61,61,39,26,121,21,90,123,110,166,10,17,77,144,245,101,195,219,58,66,176,0,223,205,226,62,37,23,197,29,189,
12,69,43,74,68,244,70,96,93,65,65,219,81,252,225,8,116,70,136,142,45,0,243,84,3,214,184,169,160,32,20,15,182,38,96,162,129,42,155,221,184,192,90,77,109,7,130,193,134,2,139,21,207,207,191,175,223,34,208,
138,165,64,28,129,96,249,135,96,71,2,210,73,86,180,207,238,140,176,18,136,5,142,186,9,173,51,5,8,139,143,52,126,215,149,2,53,128,13,1,142,245,148,124,141,56,12,140,8,128,60,115,134,79,131,122,212,50,106,
236,169,69,110,218,112,48,182,25,160,168,49,167,106,9,134,201,208,20,59,220,76,139,58,164,33,0,41,139,91,118,89,34,106,156,1,236,50,72,184,146,66,218,112,204,242,20,111,128,240,85,228,8,57,232,49,76,18,
211,43,153,44,19,93,0,128,99,112,141,87,107,173,243,78,117,144,137,218,72,10,229,124,184,189,105,85,133,67,84,36,210,165,16,9,179,13,85,107,152,242,21,84,223,218,9,126,248,106,103,159,74,104,8,70,191,
85,207,203,121,45,102,155,90,82,161,165,170,132,160,59,52,19,172,227,26,83,8,225,2,13,243,36,121,68,21,197,160,143,126,233,73,64,56,20,21,167,172,166,55,244,64,72,134,55,14,236,21,185,54,170,6,203,134,
232,160,65,163,71,174,81,88,239,45,105,185,49,152,16,136,143,151,78,40,82,87,181,90,220,240,146,1,5,231,210,254,114,8,64,32,244,173,126,51,98,73,103,160,46,242,198,64,26,169,169,249,200,172,5,94,143,56,
40,34,38,61,9,223,211,42,96,218,201,126,189,64,59,113,182,50,210,82,150,87,191,27,232,56,96,85,0,8,4,158,178,204,50,130,80,68,240,58,205,79,181,67,170,196,51,78,1,216,10,235,91,193,24,5,217,83,224,59,
224,146,88,65,98,32,152,174,100,180,67,67,191,153,145,30,197,8,10,84,245,5,246,49,101,65,32,44,7,157,131,19,198,16,6,52,65,47,95,237,141,224,40,125,19,238,92,174,246,237,174,221,184,68,152,4,0,39,128,
177,245,225,15,121,111,167,103,203,113,117,129,40,90,132,251,184,130,5,130,161,208,42,190,129,155,25,174,1,4,223,173,194,148,6,155,141,71,164,233,196,97,216,45,82,143,235,5,17,24,155,19,72,153,180,202,
14,129,94,161,114,236,36,11,77,164,30,58,123,183,229,196,104,236,7,70,239,143,140,116,62,33,66,123,247,145,228,23,72,149,103,140,239,120,235,160,19,119,184,245,222,95,132,80,4,0,255,0,135,20,44,1,176,
99,118,62,248,45,50,202,136,63,78,178,148,94,192,61,178,238,119,46,33,6,238,12,118,15,165,192,36,13,37,74,246,135,26,96,33,13,170,155,198,237,87,68,136,189,228,53,40,197,124,91,150,69,77,29,52,248,193,
151,67,54,19,207,175,156,34,108,18,247,6,98,40,244,19,194,44,76,122,44,145,164,136,232,243,190,17,25,84,154,134,131,163,227,54,96,29,97,178,47,159,92,98,65,80,13,132,243,194,18,146,157,181,242,142,177,
59,96,135,239,135,93,18,179,190,176,145,73,88,26,58,105,49,18,129,146,58,62,253,99,1,166,144,190,171,131,219,66,9,177,11,230,235,6,37,142,235,106,235,132,184,192,130,165,2,253,48,2,138,151,76,148,198,
193,20,12,107,168,203,243,132,71,22,238,107,227,211,11,201,18,16,168,89,219,192,18,20,215,72,62,91,193,29,132,199,106,62,29,25,17,178,45,122,22,223,56,160,10,160,131,192,103,158,1,64,198,133,243,237,138,
6,37,190,214,183,253,112,39,86,0,84,19,242,152,246,198,251,250,253,241,201,82,9,60,47,101,201,212,3,75,41,114,22,141,17,238,55,183,131,18,13,246,32,129,231,231,25,206,0,198,163,193,0,70,88,138,137,55,
151,174,187,11,29,226,84,212,20,117,82,235,6,35,6,54,37,28,98,152,200,109,4,159,183,4,18,43,64,97,171,158,52,145,217,224,37,152,180,148,30,133,86,116,226,138,74,237,85,115,191,36,178,4,118,97,148,64,144,
246,152,209,141,34,31,35,129,132,162,52,108,112,50,27,110,147,167,227,5,2,212,84,175,161,122,195,189,49,233,1,23,222,240,226,2,137,6,146,194,228,233,17,0,136,213,252,103,151,224,59,130,183,211,234,244,
158,174,60,185,68,5,81,228,111,120,225,213,21,86,59,164,205,158,178,23,90,35,55,45,96,83,127,224,229,243,28,0,147,165,159,28,1,104,84,216,13,122,55,60,212,40,13,5,250,80,194,200,203,241,144,139,237,222,
87,123,119,222,251,243,145,241,101,21,244,172,9,223,78,62,210,55,81,13,236,245,232,122,223,92,3,193,46,245,181,254,115,103,5,66,2,111,95,24,8,20,232,10,224,215,13,3,85,84,149,239,183,41,184,200,80,136,
219,210,111,36,73,161,8,40,134,142,26,157,21,65,81,183,206,36,83,211,90,68,252,99,48,39,116,133,71,199,120,234,55,64,129,143,143,140,145,214,22,136,162,124,240,41,252,5,138,213,175,8,228,68,165,134,12,
161,175,38,189,216,169,139,22,48,202,46,148,211,231,13,83,70,105,103,219,3,173,88,32,119,61,25,131,213,168,61,95,30,114,190,146,136,96,199,192,120,226,214,72,131,181,107,208,99,212,96,20,72,136,76,18,
44,83,101,224,44,203,181,148,34,104,251,96,50,81,65,183,127,92,17,236,65,190,221,99,25,218,19,223,2,181,129,14,206,207,158,1,9,65,187,0,30,152,161,93,89,228,47,94,251,114,133,13,0,171,93,222,27,172,138,
190,73,118,117,136,55,91,143,146,159,140,161,48,82,251,13,201,106,35,64,183,174,143,251,145,104,58,51,249,117,136,138,84,104,123,89,113,10,135,176,232,248,238,228,182,237,27,13,154,254,248,54,77,208,109,
219,241,188,238,182,158,147,78,52,39,75,73,171,39,214,97,81,197,177,154,125,189,50,170,121,132,104,201,111,16,90,128,174,166,223,214,0,221,104,3,167,169,196,165,5,33,109,60,31,124,48,5,239,163,94,215,
211,40,142,194,29,5,255,0,231,26,111,1,10,148,238,166,33,90,90,210,147,88,212,10,64,199,180,82,252,230,148,203,98,179,226,245,131,236,136,104,105,226,215,141,98,157,131,162,45,222,66,120,40,17,77,222,
13,128,2,23,13,141,198,212,166,190,184,164,218,162,29,109,115,173,255,0,247,249,203,20,20,134,235,80,188,19,66,217,15,44,57,36,107,30,65,222,187,147,32,132,42,186,117,138,42,87,213,125,49,176,232,10,148,
179,120,96,52,67,219,229,239,157,101,34,148,232,104,55,246,185,29,105,223,94,249,77,42,158,26,20,248,239,42,167,194,123,67,251,152,10,239,2,16,87,129,2,164,32,232,232,191,25,169,9,132,71,189,248,244,195,
72,239,72,179,190,240,149,23,226,42,125,125,112,130,205,141,118,56,54,54,159,81,165,194,150,76,70,52,22,121,127,139,135,71,46,35,85,227,224,188,88,21,1,96,65,110,242,216,132,96,215,147,58,190,184,184,
164,151,169,13,7,180,197,85,85,87,181,118,226,244,34,165,236,249,216,152,84,8,132,146,68,193,174,54,7,161,17,252,97,20,217,64,104,30,155,224,192,4,41,128,21,63,6,3,90,43,74,166,247,141,32,32,136,147,106,
20,43,241,50,221,181,140,3,64,222,183,79,81,56,43,150,85,2,15,147,172,220,0,20,16,68,245,214,32,148,212,58,21,127,182,14,7,114,164,26,236,239,167,5,32,122,74,172,93,19,191,158,44,102,146,42,108,239,227,
5,197,73,0,32,90,58,91,193,127,137,87,203,8,105,205,75,71,112,168,61,89,136,149,160,135,119,17,158,179,172,3,3,238,6,31,134,79,153,149,226,146,45,87,179,91,56,83,113,124,212,9,253,224,29,196,160,141,48,
85,5,130,190,193,139,64,96,0,73,2,125,112,61,192,155,81,250,224,193,88,149,242,165,196,160,105,17,31,115,47,221,54,14,201,28,3,33,237,116,10,244,239,188,52,194,21,176,124,23,188,116,71,64,53,86,56,17,
105,161,7,85,223,219,61,166,200,117,19,20,15,81,27,233,28,181,20,154,84,77,245,63,188,28,74,124,137,62,249,180,192,58,29,105,237,220,205,141,164,81,216,47,139,233,146,10,187,128,164,62,135,172,225,0,157,
224,86,67,241,113,165,106,5,34,86,207,166,53,19,65,20,232,217,252,97,200,225,236,100,215,241,154,136,74,116,9,226,220,49,29,1,246,102,36,93,45,122,35,172,169,83,80,157,58,254,184,20,34,42,162,187,113,
65,10,70,193,123,103,120,11,103,133,208,35,254,240,186,19,70,26,70,92,68,208,164,126,70,96,93,64,160,237,168,254,114,194,213,71,106,63,77,101,176,46,200,17,24,150,255,0,89,248,246,197,222,130,10,209,63,
248,101,74,26,1,240,239,94,188,24,160,173,165,85,95,219,17,147,87,98,19,219,227,34,208,138,161,208,15,26,58,220,4,218,207,77,226,34,137,17,137,232,152,104,197,216,135,149,76,21,163,106,236,61,189,14,176,
146,90,11,65,2,253,114,5,44,0,190,0,153,188,164,132,101,140,110,105,68,103,187,91,194,3,33,0,68,247,39,78,79,248,123,229,121,74,218,118,62,253,92,91,0,106,172,7,231,40,42,3,4,69,55,219,227,131,153,8,82,
192,233,249,198,211,132,117,225,9,192,17,89,34,43,62,111,120,98,176,49,172,76,119,27,166,250,42,14,49,0,3,180,81,48,37,77,40,21,77,253,184,58,197,36,22,4,54,220,96,21,184,43,208,19,106,250,101,244,35,
27,223,135,177,33,227,87,206,40,81,87,106,170,253,240,144,211,32,128,74,123,230,145,4,0,129,116,252,100,41,148,215,65,63,134,36,89,90,230,41,54,221,143,166,8,2,87,160,21,126,216,56,48,96,226,213,108,248,
201,108,72,69,248,22,165,189,96,154,18,162,3,104,27,227,74,165,54,209,191,152,92,32,130,138,40,166,157,123,98,150,142,14,216,7,216,48,179,70,178,97,104,183,226,207,99,236,97,169,13,220,234,199,65,217,
143,183,94,47,166,11,117,144,44,101,39,215,17,152,200,0,8,139,61,103,6,20,206,200,5,103,77,214,68,0,216,118,15,230,122,229,245,64,3,54,70,206,175,22,220,226,1,67,162,88,241,163,34,62,110,200,67,205,194,
60,133,132,82,209,34,250,229,113,24,96,104,5,87,211,17,68,167,96,129,175,65,245,92,52,102,35,68,106,62,73,48,174,146,85,124,170,224,204,0,62,233,67,106,225,144,12,11,209,187,117,223,88,201,36,212,9,165,
243,223,88,138,128,8,42,166,113,210,80,10,122,235,44,160,8,71,80,30,31,28,84,133,18,161,166,236,158,184,85,50,202,108,31,235,11,171,60,35,165,151,235,46,45,2,214,131,25,128,226,182,147,83,130,180,98,160,
218,177,191,214,90,169,184,72,143,158,176,34,82,133,81,218,245,151,104,40,107,163,237,214,65,20,51,99,223,77,243,132,79,66,94,224,204,100,30,147,238,40,229,176,213,3,174,159,175,13,140,171,65,101,2,79,
166,6,141,187,228,63,150,220,126,75,0,86,19,129,246,114,65,217,177,252,226,119,65,31,59,254,240,87,178,140,218,135,253,192,46,194,236,62,158,158,115,114,36,39,72,125,241,96,77,40,15,29,229,106,148,8,196,
66,224,196,177,221,53,93,112,88,72,85,82,181,125,250,196,0,211,99,68,246,245,113,149,10,233,208,71,175,157,240,24,19,84,141,25,126,113,17,118,145,250,97,59,102,192,237,168,193,7,98,107,109,61,221,25,22,
56,150,181,18,219,138,0,170,8,30,3,60,126,21,12,104,190,125,177,64,98,91,237,67,191,235,129,30,142,144,96,147,202,120,196,250,150,95,92,78,43,96,83,116,246,95,140,134,26,52,163,62,47,89,59,102,207,228,
23,111,0,96,91,43,1,3,251,192,199,8,83,177,30,24,128,11,41,97,217,125,115,110,150,40,145,143,209,197,169,172,42,104,174,12,71,211,212,167,231,28,240,26,1,65,60,126,56,32,145,81,3,13,95,57,35,68,9,181,
26,61,49,113,96,244,85,103,78,32,162,175,43,92,54,52,157,64,63,252,96,6,67,80,61,140,111,224,76,35,191,3,127,41,143,227,161,30,211,221,187,248,192,84,1,87,160,54,248,192,206,85,25,215,93,23,199,120,147,
236,6,181,93,22,187,152,166,177,142,129,190,43,192,74,32,182,244,176,62,115,118,70,167,162,254,24,208,238,159,194,168,47,188,198,27,182,130,40,244,123,194,130,212,171,64,196,147,188,33,186,2,247,6,102,
165,188,10,111,63,14,8,20,32,196,78,131,207,166,241,2,51,91,204,191,36,237,238,56,105,166,85,218,193,184,175,75,237,61,242,251,161,64,68,29,234,74,24,25,150,182,103,88,190,221,229,119,183,125,251,249,
198,34,108,33,185,58,60,98,41,68,69,17,240,154,194,154,59,222,182,250,101,236,104,104,17,233,23,172,246,112,1,212,245,244,200,25,120,27,229,119,54,225,186,56,150,66,59,59,55,231,24,38,148,106,182,116,
116,112,229,239,117,88,70,217,189,228,253,136,22,233,161,61,19,234,99,181,22,36,36,122,236,202,235,75,16,136,62,53,146,106,55,73,96,232,215,158,11,57,161,77,136,135,247,149,32,53,166,129,77,53,243,198,
197,26,72,169,26,211,151,19,6,48,179,24,83,64,73,245,220,102,9,74,82,236,178,152,91,40,34,170,36,94,189,184,165,112,72,13,170,47,88,191,160,40,2,33,60,95,24,32,129,123,30,10,204,69,176,105,26,151,196,
235,4,90,72,54,52,251,211,10,250,64,189,186,56,221,193,9,242,57,171,198,33,124,174,189,56,12,37,106,211,0,244,250,226,134,195,135,144,122,123,237,203,76,168,2,189,139,127,28,60,91,21,70,201,75,140,7,210,
123,138,63,25,66,208,166,119,6,226,171,0,222,192,158,211,38,168,58,125,142,250,197,68,232,144,122,24,224,175,40,104,196,94,191,57,106,61,99,94,181,193,21,87,64,84,91,243,174,242,205,109,169,72,130,249,
203,132,145,136,105,103,191,115,10,134,91,29,131,237,233,148,65,91,136,161,146,220,70,187,23,212,238,253,112,211,176,22,118,134,108,130,26,182,79,198,92,121,65,38,152,175,101,74,15,67,119,11,165,40,34,
136,203,227,52,208,45,21,85,132,239,235,195,123,224,10,133,122,204,5,216,135,76,240,245,125,241,168,20,195,30,209,75,243,154,19,45,137,99,237,122,205,147,11,27,148,58,91,235,197,122,197,98,192,155,187,
206,227,162,14,200,175,247,193,23,128,108,175,85,184,200,101,55,74,106,248,239,172,102,105,74,150,10,167,159,140,52,223,76,44,105,116,41,208,251,231,88,77,141,48,53,84,63,214,106,12,41,232,151,93,226,
72,80,75,60,98,171,85,95,85,244,198,195,160,42,83,173,225,160,116,15,111,254,175,12,149,40,208,32,111,215,215,211,35,173,119,215,190,19,138,169,225,18,159,29,227,9,111,29,146,119,224,181,198,196,206,152,
150,190,213,81,248,224,72,216,165,228,180,62,216,201,51,4,236,100,70,251,230,137,10,33,79,65,192,205,208,238,145,166,221,220,134,160,236,4,239,160,205,157,109,93,84,214,32,160,136,4,82,61,225,88,41,224,
236,168,119,47,0,13,230,204,16,124,174,178,153,36,96,29,246,203,47,174,32,109,104,179,66,210,122,78,241,85,85,85,237,93,184,251,204,77,98,199,166,251,157,186,184,250,88,9,176,49,65,224,211,237,132,13,
58,46,137,242,199,231,235,134,251,97,0,9,31,55,241,128,16,58,2,173,248,192,84,14,142,148,239,120,222,202,39,112,23,123,59,201,58,110,210,52,32,21,245,120,40,184,237,170,130,44,55,131,96,66,128,104,158,
185,96,8,33,180,187,39,165,195,194,244,168,134,187,235,198,3,116,205,73,18,244,132,224,248,194,65,136,180,184,5,102,36,11,149,240,141,190,12,126,62,216,58,244,177,139,169,232,226,108,1,232,218,15,198,
58,21,187,7,116,205,207,89,159,236,240,225,75,18,10,211,90,158,120,67,98,235,218,194,127,120,3,113,32,1,167,197,192,10,36,21,67,64,122,226,154,176,8,104,128,146,121,200,10,145,78,193,250,152,107,104,108,
123,105,112,81,17,136,136,250,38,241,48,36,101,232,72,246,224,121,20,237,224,23,198,51,48,166,136,123,89,157,120,136,37,218,15,39,0,87,152,128,80,111,175,198,89,234,66,29,73,49,68,178,35,125,35,150,32,
236,154,19,204,152,88,144,244,157,119,59,203,213,210,80,117,225,133,85,82,40,196,172,202,128,221,195,93,31,239,129,6,173,160,172,140,117,74,48,155,46,219,245,205,52,208,197,53,27,250,245,148,194,30,197,
249,117,214,15,144,168,5,19,223,227,219,12,98,0,79,72,204,103,12,161,125,135,59,250,16,61,131,199,175,92,64,33,178,146,181,215,158,176,150,85,52,81,23,71,94,248,189,15,53,87,166,119,192,14,144,1,175,171,
223,37,65,38,148,216,47,153,130,40,236,137,59,103,139,220,193,208,37,177,18,253,113,177,71,122,145,24,150,255,0,88,246,234,109,215,166,59,236,24,173,26,95,235,11,96,148,77,148,142,169,190,39,32,173,165,
85,94,95,56,45,118,233,66,95,29,227,204,16,86,88,71,223,190,8,31,54,0,28,34,40,145,24,158,137,130,140,88,128,60,174,84,147,65,74,171,231,8,42,193,36,144,47,142,241,86,85,96,5,240,24,204,151,176,41,214,
25,117,57,242,43,223,158,29,199,37,64,130,199,145,83,35,224,83,170,12,196,217,74,220,242,95,61,92,91,0,121,88,11,239,150,21,1,136,109,239,183,130,36,135,98,192,122,252,227,66,130,117,216,135,171,227,55,
6,108,207,47,201,35,229,244,195,162,108,110,164,157,247,126,48,21,5,64,145,46,252,14,179,111,244,151,170,161,115,84,16,140,5,30,141,245,193,161,218,68,11,227,108,56,13,243,119,32,134,171,239,113,250,82,
18,16,9,171,59,244,205,13,5,73,234,120,244,152,170,170,213,218,187,85,196,169,111,104,9,78,178,139,236,26,48,178,0,143,100,235,208,9,41,35,192,10,194,167,223,34,99,10,42,17,44,121,246,19,4,64,149,208,
10,183,227,23,197,18,126,66,135,218,19,12,242,98,164,118,189,164,175,115,54,200,196,72,224,21,235,175,103,193,130,32,136,136,34,52,71,126,48,199,98,118,208,26,29,194,224,6,22,33,210,154,98,75,208,103,
66,248,199,22,208,36,40,244,112,116,27,33,66,105,36,54,62,252,77,150,64,24,136,59,248,196,0,92,136,84,38,143,89,198,202,34,138,27,96,158,206,31,35,220,66,137,247,150,101,15,136,14,154,27,79,92,9,239,173,
4,105,61,214,207,124,9,34,247,165,212,47,141,18,248,193,166,81,210,7,202,251,107,223,21,8,5,65,190,199,78,21,2,65,93,58,15,92,214,0,0,9,4,39,140,64,40,66,2,37,223,166,50,75,170,175,149,92,235,5,184,168,
189,42,220,235,124,34,1,96,53,2,254,122,197,133,81,173,38,175,153,233,144,148,20,18,173,215,147,174,3,207,129,1,77,199,191,25,36,39,64,232,2,53,241,193,190,228,41,217,79,61,107,120,85,113,99,19,78,38,
168,236,7,86,83,230,92,64,17,107,103,84,197,177,110,202,169,92,90,46,194,27,86,111,53,84,216,36,87,158,176,13,52,67,95,43,151,104,52,107,248,117,155,17,12,216,125,116,220,35,72,9,119,161,152,134,118,125,
165,143,220,203,64,52,30,200,143,215,133,38,11,68,87,169,211,135,161,191,123,12,123,93,184,44,75,161,72,17,123,120,27,118,235,70,70,254,113,4,250,131,225,22,143,215,13,148,1,67,81,179,190,250,202,240,
158,197,71,207,93,96,150,81,64,29,158,255,0,24,52,210,20,244,140,198,80,205,7,229,167,241,158,46,133,189,137,52,244,241,175,178,148,131,93,124,49,137,109,187,217,219,193,231,29,160,135,85,0,249,226,6,
59,144,83,93,250,204,68,90,82,63,76,7,42,13,14,218,143,231,34,160,147,18,180,248,235,32,58,163,98,116,91,174,241,86,85,97,11,224,200,145,97,161,68,66,255,0,24,232,147,94,173,173,237,226,247,174,128,208,
146,109,220,200,238,10,89,102,11,130,176,10,77,157,239,52,230,91,177,254,112,133,46,173,55,177,103,1,40,182,150,20,73,252,224,66,132,15,98,39,206,119,215,251,55,137,4,4,88,176,19,119,41,217,210,137,18,
252,14,179,106,106,2,189,21,46,176,173,11,210,249,7,216,237,246,192,222,26,131,67,51,181,85,247,120,29,163,38,144,210,237,119,214,78,34,84,2,35,71,115,126,51,64,223,104,170,26,31,92,68,162,155,85,170,
253,112,16,198,84,3,224,124,96,26,3,72,67,78,10,34,49,17,31,68,203,105,104,128,220,247,108,112,154,171,212,77,220,212,201,195,184,42,84,233,79,76,41,68,116,244,35,234,89,120,67,83,76,66,244,49,48,84,34,
34,34,49,19,116,153,82,236,10,194,177,122,14,227,191,124,43,83,150,162,45,17,218,52,142,241,195,86,131,163,31,164,41,238,99,109,163,64,232,158,143,120,68,0,139,54,107,215,70,253,154,240,102,203,161,139,
233,12,112,130,192,34,63,87,166,13,149,73,200,9,97,239,196,190,199,22,1,158,152,119,57,36,6,11,117,101,152,61,240,136,244,8,190,142,248,222,38,226,34,117,117,249,192,232,8,131,220,99,157,228,21,190,150,
120,239,0,101,52,208,31,1,118,38,47,69,124,11,26,136,0,121,9,127,45,148,190,166,11,62,129,3,83,110,69,83,9,94,81,226,117,10,93,169,228,207,108,72,165,25,228,216,228,197,85,5,179,121,178,5,58,4,65,248,
201,216,9,165,116,167,103,0,230,104,131,17,12,2,5,144,210,15,134,184,76,119,4,195,16,252,97,10,208,198,77,98,138,68,16,127,12,194,8,165,46,205,151,237,149,154,136,85,80,237,151,219,139,198,196,128,85,
75,144,144,64,32,90,107,197,241,131,148,66,168,129,185,149,108,29,33,72,234,78,176,197,164,188,138,61,61,225,30,33,18,237,72,223,215,27,185,33,62,153,168,1,1,180,244,41,174,11,16,65,81,96,30,12,80,208,
157,58,47,69,153,186,36,2,158,247,219,61,56,42,95,0,233,37,59,244,196,246,72,157,34,192,45,210,147,184,55,13,156,20,87,97,60,245,233,132,11,171,166,147,249,202,20,211,80,234,53,127,24,11,104,22,209,43,
60,101,80,26,55,29,39,125,112,150,105,73,74,244,30,112,132,65,251,116,49,236,243,128,132,232,42,4,94,222,18,140,93,0,232,19,127,92,131,211,178,38,196,90,97,183,96,41,219,49,164,0,106,22,143,95,92,41,15,
97,161,62,142,55,201,68,135,167,120,93,82,129,20,70,95,25,169,74,167,106,233,221,227,75,232,32,24,43,186,158,49,42,238,14,148,220,241,103,156,44,2,208,36,223,81,151,231,58,52,182,34,95,174,18,152,164,
144,217,226,158,252,119,200,43,22,0,111,27,37,4,32,243,78,205,224,43,2,175,131,188,25,224,7,66,249,96,16,167,74,9,124,65,235,41,45,54,78,182,143,235,13,111,211,21,173,7,148,86,167,223,28,211,84,192,176,
182,220,148,128,54,24,37,215,120,226,232,100,218,52,77,245,163,238,226,21,43,234,183,172,89,100,4,17,75,19,88,160,87,200,50,72,247,222,239,10,26,8,200,24,249,75,179,4,233,46,136,46,254,152,79,162,184,
210,74,30,167,121,112,49,5,42,15,143,103,166,8,72,241,0,73,117,223,5,198,107,94,65,178,119,209,136,70,233,96,69,236,72,123,205,18,20,66,158,151,241,154,44,4,119,178,189,215,159,92,134,114,196,88,63,67,
54,125,181,122,205,103,94,85,101,109,116,2,116,249,197,49,132,73,85,80,221,23,126,152,154,106,80,117,188,246,109,79,169,233,133,17,5,162,129,17,55,68,193,65,8,72,95,81,102,188,143,15,211,14,149,206,223,
19,68,234,76,239,110,215,183,11,169,120,108,0,70,124,56,201,17,6,117,139,139,10,79,142,175,94,216,4,69,204,4,58,78,233,113,16,89,144,19,110,119,128,65,211,91,175,108,51,51,65,217,7,155,221,202,85,31,195,
72,1,215,158,5,77,66,109,10,58,166,77,100,204,79,121,4,5,233,59,61,28,238,237,68,79,8,123,40,79,103,1,44,75,77,10,235,198,10,86,195,101,18,205,154,120,160,48,186,0,35,109,229,137,64,88,136,173,232,245,
224,34,192,178,22,145,53,151,169,29,130,80,113,30,197,208,124,186,51,220,207,206,22,157,20,44,90,251,240,198,162,152,109,97,63,188,62,195,40,67,113,212,151,5,168,160,85,24,6,47,52,0,1,0,4,241,142,5,192,
232,17,90,250,102,247,67,99,219,124,224,162,38,145,163,238,97,96,37,54,195,33,154,55,198,173,1,34,157,3,140,1,125,16,213,243,236,196,244,210,20,218,54,161,192,49,182,132,16,111,151,227,36,250,144,135,
73,61,176,98,62,136,254,112,180,5,210,232,77,142,28,44,44,162,75,245,117,133,81,245,1,212,107,52,70,160,108,154,89,227,42,246,110,21,123,30,125,231,3,214,171,65,94,158,190,49,138,66,97,54,46,222,189,240,
142,193,2,52,246,243,223,92,89,108,129,96,18,246,250,96,155,4,5,26,34,190,48,150,177,9,220,27,142,140,20,42,168,76,48,169,123,15,231,10,149,161,60,202,50,224,102,192,69,71,105,227,52,224,77,109,122,67,
190,33,10,32,240,65,221,247,201,114,5,65,42,15,198,6,145,217,16,243,60,95,76,170,12,237,17,47,215,25,140,61,200,52,212,184,253,189,189,50,186,130,2,88,118,127,88,91,4,162,68,167,162,145,235,1,88,109,116,
7,107,139,128,43,112,74,175,228,196,40,203,13,23,172,151,30,108,5,103,68,103,158,40,34,246,81,107,119,17,72,145,24,158,248,52,11,0,13,85,214,110,133,80,34,244,225,66,21,220,8,23,81,221,197,94,219,209,
244,53,150,233,216,20,233,158,62,112,128,10,116,234,139,114,94,151,248,170,111,208,59,115,118,35,44,245,4,170,215,223,4,233,37,148,20,184,41,8,155,226,239,220,179,21,199,159,41,2,238,96,80,210,24,8,205,
235,219,132,97,220,22,161,154,247,110,78,1,194,45,0,212,131,13,199,23,118,104,78,186,218,93,123,12,29,46,249,66,38,214,175,196,202,200,136,1,194,123,153,35,157,132,133,66,223,23,192,224,249,205,110,71,
116,72,250,96,73,186,45,133,232,246,194,82,150,249,240,23,201,227,21,3,178,224,89,167,173,241,137,172,199,71,76,79,62,185,166,40,133,74,246,241,140,210,169,82,233,245,120,31,159,156,96,39,98,206,200,61,
19,103,198,77,66,137,211,47,182,126,199,89,61,7,175,145,176,242,141,56,5,47,0,209,183,106,161,116,111,239,9,133,158,129,55,226,97,16,70,42,157,130,155,212,195,182,40,167,99,69,242,244,192,128,132,180,
5,50,28,106,80,10,213,65,208,175,110,17,41,208,53,83,126,152,229,232,31,107,217,129,42,168,0,168,244,77,254,114,26,183,106,140,98,68,11,245,199,253,184,246,255,0,2,29,81,247,14,56,64,90,181,53,206,155,
169,247,49,248,251,98,28,169,178,181,180,234,96,183,189,171,71,214,117,128,173,199,65,168,19,185,235,120,7,212,161,80,27,165,247,225,218,202,140,221,217,128,137,5,0,217,105,210,225,84,90,21,70,0,187,198,
96,0,0,128,2,120,196,66,132,32,34,88,229,10,146,215,181,84,224,97,10,221,177,86,252,56,117,3,64,189,3,87,223,172,73,33,77,104,16,92,42,145,1,111,229,56,168,248,37,67,180,123,194,108,12,5,8,35,77,113,82,
11,162,173,107,189,117,131,216,6,59,17,250,184,169,54,80,22,84,191,89,113,0,139,69,54,107,233,155,76,108,170,175,212,226,221,118,173,133,99,127,172,38,163,117,27,25,190,174,6,108,161,180,101,189,101,58,
124,138,232,251,26,203,99,20,0,249,211,128,105,4,3,219,235,136,38,147,249,166,40,96,128,44,102,187,53,231,1,43,25,122,19,229,198,67,123,2,207,7,58,45,64,27,52,179,198,35,103,185,109,123,30,124,94,7,169,
55,224,105,235,136,136,19,162,162,237,235,2,150,1,17,61,94,126,50,133,119,186,145,194,236,81,2,118,111,12,2,1,7,160,97,26,51,82,248,166,63,140,52,37,90,128,68,154,82,60,31,141,149,80,105,112,224,180,221,
209,61,189,92,105,68,212,233,167,175,207,21,43,97,49,24,206,223,108,70,59,73,243,48,156,23,192,118,212,127,120,228,138,77,11,99,243,147,88,17,119,9,244,197,89,91,8,123,24,38,0,102,210,33,232,246,207,27,
145,175,119,149,224,254,91,132,0,105,55,237,130,168,1,236,95,213,205,247,98,246,163,247,58,199,168,22,197,63,206,20,134,160,7,134,183,80,15,151,130,155,70,139,10,1,252,225,20,40,8,17,61,134,147,1,122,
47,110,189,2,227,72,208,10,14,199,213,155,226,77,80,199,201,6,228,125,203,25,10,250,96,162,39,98,38,135,102,252,224,145,2,178,1,5,15,99,214,68,192,93,178,2,180,218,122,246,60,122,27,61,128,2,195,79,156,
64,208,74,48,93,29,229,106,81,33,58,1,60,49,35,118,47,7,169,248,187,123,152,6,43,29,87,192,145,17,194,179,46,234,71,160,8,85,123,240,230,164,65,55,197,61,84,63,76,25,240,217,232,55,168,211,146,54,33,32,
38,160,26,62,142,62,60,9,81,89,210,158,152,64,66,82,111,153,94,15,103,191,203,138,195,4,240,143,131,31,219,228,154,218,169,248,124,57,52,7,200,224,65,78,189,187,202,145,121,10,119,210,61,71,19,49,69,61,
52,222,252,92,5,79,197,33,13,211,222,190,112,120,150,211,104,246,147,243,146,155,14,189,244,96,17,18,128,83,193,244,192,17,236,4,1,44,247,112,134,123,5,32,31,4,194,123,171,49,242,205,51,126,214,5,2,110,
244,221,192,218,203,187,34,83,220,118,96,179,47,234,73,0,94,132,79,156,68,81,236,81,249,28,52,208,109,231,74,48,154,37,139,34,190,28,88,13,222,224,159,92,144,10,128,36,109,190,48,153,168,34,45,77,183,
21,161,17,85,218,31,235,135,136,73,27,97,183,244,98,69,40,207,38,199,38,42,169,30,171,252,228,10,33,99,2,15,196,201,33,21,186,160,135,97,56,216,60,13,2,33,231,1,69,71,96,130,157,107,231,135,82,0,50,108,
83,174,178,139,160,236,180,125,230,37,104,161,3,174,255,0,56,119,213,246,108,126,216,72,48,5,84,9,210,251,112,202,88,128,27,90,192,70,0,4,26,154,36,246,205,40,65,82,32,86,121,197,21,219,224,68,62,33,172,
58,152,148,1,163,212,192,182,232,94,250,56,128,118,132,249,27,134,174,138,5,74,172,166,184,52,65,178,138,132,212,31,156,66,146,20,32,189,23,14,12,176,10,155,245,89,198,204,181,228,44,111,127,76,71,228,
42,43,166,250,200,22,72,108,33,111,191,120,170,166,247,180,142,58,64,192,38,206,240,12,32,128,123,120,198,17,137,252,216,216,136,4,33,66,119,39,79,15,54,218,40,61,2,111,172,35,0,112,160,7,161,112,196,
0,96,232,34,249,225,72,209,76,29,2,109,249,201,26,59,68,104,139,110,92,235,86,30,102,73,16,53,22,159,124,48,15,6,164,250,111,241,141,234,169,65,237,188,221,208,29,162,50,248,201,121,64,182,170,4,171,240,
240,15,11,96,144,43,215,29,128,173,106,161,239,46,6,161,108,52,143,81,119,243,142,176,150,197,59,250,224,102,164,142,72,212,215,191,0,170,22,197,132,55,252,229,50,130,80,104,104,236,247,197,182,18,149,
92,97,42,212,12,248,152,237,150,123,227,133,243,65,4,179,82,245,149,106,3,4,5,80,125,176,214,206,204,216,120,60,55,176,206,220,73,167,73,164,124,97,214,53,89,10,135,127,108,113,22,108,44,106,150,250,99,
70,125,42,88,104,41,239,21,85,85,124,187,125,50,210,192,198,133,136,215,190,9,160,137,176,143,216,15,14,250,116,122,56,201,111,0,98,165,32,67,13,239,232,246,71,206,28,212,107,107,79,82,87,213,192,131,
210,13,68,236,248,61,112,98,119,179,64,123,143,240,194,3,60,113,67,204,219,132,58,175,68,190,225,254,51,96,197,6,196,70,95,76,241,138,22,227,21,141,53,3,189,246,249,199,119,0,149,201,109,29,225,178,44,
15,143,122,158,45,247,114,8,193,129,208,253,12,87,88,183,240,189,3,240,246,98,69,25,122,168,136,233,94,19,95,93,101,115,187,92,128,244,61,47,30,171,54,96,17,227,188,105,77,86,64,49,185,238,192,129,208,
16,234,107,209,39,17,237,74,169,160,12,89,231,25,162,38,156,26,104,42,252,186,246,193,33,84,218,35,166,239,88,136,107,18,40,223,127,76,93,130,230,208,154,188,238,149,62,198,16,80,232,26,223,123,155,48,
213,29,232,39,92,0,205,208,54,182,24,0,129,129,210,121,62,184,166,23,105,122,172,127,120,20,66,13,52,39,219,5,109,143,35,30,145,37,226,16,69,208,0,155,55,241,130,146,130,98,34,27,227,174,248,141,128,40,
157,235,125,99,251,19,114,148,31,153,113,113,37,104,122,81,25,175,28,33,192,214,148,139,194,188,49,174,210,27,86,36,195,228,138,24,221,235,172,24,93,65,74,32,1,124,226,179,80,0,8,0,33,38,46,0,68,145,233,
231,4,19,45,93,173,187,225,120,4,36,68,72,80,134,206,15,136,39,97,208,94,177,8,46,180,134,175,159,102,35,36,128,83,216,55,67,136,131,109,0,155,93,191,24,117,145,138,8,142,167,143,124,59,62,76,211,43,234,
232,70,142,7,218,37,232,126,174,8,105,161,126,24,158,192,34,124,142,6,135,84,130,210,178,154,223,27,17,36,169,80,148,239,231,33,64,133,79,161,102,43,145,64,42,23,119,124,82,13,72,66,9,101,112,2,8,16,168,
68,87,198,58,151,99,93,233,184,129,4,221,152,79,126,191,24,8,34,189,0,79,83,191,198,21,22,252,70,153,133,205,2,42,118,135,94,248,180,32,234,219,179,85,119,192,194,160,135,64,252,224,28,129,80,77,131,241,
233,129,164,119,68,34,179,197,244,202,91,77,181,35,247,197,244,91,210,108,103,102,52,81,35,90,122,57,95,97,177,44,48,49,93,81,32,167,200,241,48,21,134,215,64,118,184,180,205,93,10,171,112,201,176,182,
32,189,189,117,154,125,129,86,67,76,224,131,191,180,54,55,213,31,39,156,57,132,181,212,127,99,200,249,19,41,238,72,88,87,215,22,182,16,71,107,195,112,129,89,26,15,65,77,184,171,42,176,2,182,6,131,121,
229,106,2,5,68,219,205,192,34,66,3,170,43,223,157,231,116,30,165,124,10,185,89,4,11,7,94,222,166,33,55,250,71,250,192,98,210,67,236,45,178,182,89,138,213,18,121,28,29,205,157,225,246,5,202,8,50,217,229,
243,128,91,81,7,121,93,3,22,25,20,202,179,68,95,183,215,27,17,151,184,8,132,116,243,46,2,244,88,43,236,24,102,193,61,160,146,121,222,57,81,80,4,105,122,235,8,197,116,219,219,67,136,3,194,49,216,224,180,
40,79,96,65,235,79,115,50,32,85,95,255,0,137,61,251,98,236,58,13,90,15,189,214,53,65,24,131,6,39,159,92,62,48,157,74,244,155,19,212,117,134,161,48,221,247,10,237,62,250,247,241,150,192,144,140,21,14,209,
205,40,13,128,64,69,39,180,205,201,54,94,146,179,84,64,140,8,215,86,196,114,62,203,170,175,219,16,9,70,178,107,181,123,73,128,209,210,77,11,167,149,49,199,80,69,173,144,39,3,2,131,59,77,30,169,149,114,
121,186,70,211,161,27,131,242,100,139,144,183,110,119,228,123,61,76,14,36,68,58,19,210,24,178,78,232,40,77,38,58,83,209,123,239,30,240,82,8,35,175,124,13,148,160,141,52,240,124,112,194,42,85,86,183,94,
48,75,126,246,154,61,172,235,5,94,130,29,129,15,30,183,129,68,182,85,1,186,11,215,138,58,0,124,173,240,125,113,80,7,148,143,99,172,42,154,133,84,64,13,249,197,129,32,0,10,0,124,100,249,8,72,221,239,188,
177,177,42,187,90,28,40,64,49,2,12,43,193,244,34,225,79,13,83,237,143,155,39,76,40,63,19,22,74,12,43,122,215,124,84,84,6,7,180,118,225,41,6,2,132,35,77,124,113,94,11,54,93,167,159,108,30,193,99,2,63,87,
21,45,148,14,171,95,89,113,0,70,194,149,41,244,205,184,246,93,173,15,158,55,109,172,157,172,111,127,76,82,217,173,38,139,230,78,177,14,17,32,25,184,173,225,48,50,192,30,65,219,241,132,152,132,32,157,71,
175,124,59,62,113,89,7,238,196,104,222,176,112,70,162,194,62,247,120,170,54,183,44,179,33,38,192,21,40,235,198,33,76,136,182,190,29,181,224,245,20,216,58,234,118,231,156,3,228,69,219,215,121,56,212,138,
17,242,208,250,76,110,84,189,213,110,17,109,139,65,41,244,184,33,146,20,244,142,80,89,168,182,21,167,241,128,131,106,234,17,55,185,56,183,117,74,130,151,95,12,104,161,118,164,30,207,213,149,237,6,194,
0,28,2,120,93,161,140,237,246,205,128,49,74,116,251,253,114,144,93,152,106,212,100,208,85,181,80,126,112,160,168,68,86,224,1,186,231,117,7,57,104,250,56,127,104,84,1,230,70,141,143,179,237,154,195,160,
30,251,191,116,254,56,88,175,77,0,52,155,238,24,55,212,64,148,60,95,12,164,77,68,229,243,182,239,138,249,50,186,147,123,151,213,21,223,117,201,170,64,16,183,91,157,239,130,72,84,215,84,19,249,193,53,64,
130,42,44,54,63,43,233,139,235,195,224,87,160,24,134,58,59,229,198,89,234,93,101,192,26,35,164,62,215,171,244,153,22,238,138,201,87,5,17,59,26,124,153,64,33,141,149,132,113,179,32,1,122,35,112,10,70,36,
160,248,59,184,26,2,53,69,104,254,76,96,157,181,164,87,238,98,112,6,211,122,166,130,172,49,131,200,132,2,125,65,125,220,40,137,164,116,251,224,176,99,209,0,166,250,124,97,54,211,168,155,246,200,142,168,
150,78,246,170,239,211,31,95,66,189,7,222,29,96,216,8,166,241,225,81,125,214,40,58,64,159,72,112,95,102,47,131,38,64,105,106,171,180,10,226,165,176,49,17,85,24,60,226,72,163,202,74,52,23,222,97,128,190,
151,8,210,106,254,112,152,210,130,42,30,221,126,114,23,96,151,190,143,25,4,130,104,8,143,193,244,201,69,1,130,197,115,109,17,248,61,113,234,122,100,78,90,77,66,251,24,10,145,72,32,47,108,198,212,73,0,
106,1,189,159,60,52,2,84,106,168,246,179,2,14,194,31,145,193,77,133,87,218,176,24,42,197,145,30,250,113,64,218,246,66,124,185,168,16,64,40,109,190,49,17,148,65,26,155,109,201,170,104,149,218,137,233,193,
99,208,128,80,122,167,182,36,80,105,225,58,126,248,212,54,136,77,123,228,30,131,70,9,126,38,14,152,8,131,98,142,250,225,11,4,150,129,7,203,125,103,98,193,131,73,124,113,32,160,27,139,208,245,214,81,247,
2,8,63,51,18,166,208,3,175,111,156,52,138,82,236,222,254,216,45,184,66,170,13,121,123,113,125,113,32,21,81,114,11,16,10,141,77,106,123,102,224,93,136,64,172,243,137,87,225,16,7,193,128,210,18,132,136,
252,252,96,6,65,165,242,71,15,181,73,83,68,151,93,56,50,128,24,232,159,119,29,141,74,142,171,95,139,136,2,144,37,55,179,233,136,134,49,46,214,2,249,113,177,10,164,246,183,188,21,49,155,219,67,196,203,
137,160,216,74,175,191,120,130,169,123,85,231,23,33,72,6,17,217,227,8,146,16,15,105,175,198,48,12,77,223,92,223,168,6,209,154,151,133,139,220,169,218,4,223,82,101,25,53,10,13,189,22,76,148,172,234,8,4,
95,60,118,76,230,70,0,246,252,225,131,68,164,68,68,90,58,203,157,97,7,153,144,70,13,139,15,93,249,251,96,160,248,83,241,189,103,105,84,72,124,92,5,68,233,82,62,58,201,24,40,139,181,9,111,199,23,162,123,
161,121,43,221,175,202,101,202,98,148,85,171,216,196,252,102,208,42,13,214,132,123,249,205,248,95,138,59,53,221,17,125,71,13,52,88,73,11,30,1,118,112,11,19,208,129,98,80,215,36,167,169,124,242,33,43,234,
101,10,234,242,87,207,70,13,13,97,7,115,118,11,232,204,73,0,209,16,75,226,100,56,13,212,150,140,242,248,15,43,157,188,195,217,29,161,218,255,0,117,134,173,172,165,215,71,16,63,126,143,40,249,203,115,169,
168,6,128,240,25,163,105,96,176,170,59,197,68,13,90,53,110,237,235,36,16,133,108,66,234,156,85,218,215,223,11,42,42,162,68,30,156,57,0,122,36,33,175,231,134,210,16,58,155,60,131,222,240,42,39,85,54,250,
98,11,46,196,87,181,55,2,62,153,111,1,106,170,169,22,224,87,34,133,144,17,189,113,220,160,187,42,132,96,124,99,117,98,236,68,100,243,129,230,40,69,248,179,34,17,208,145,39,215,120,78,136,192,141,60,248,
198,190,178,170,93,85,236,54,121,79,140,83,35,40,37,41,177,190,28,14,132,70,97,21,163,231,130,46,141,38,8,58,54,227,122,225,97,32,214,120,94,251,201,244,210,0,244,91,84,58,205,3,168,118,147,246,0,224,
188,75,168,164,234,199,10,39,191,230,110,3,172,1,95,97,223,227,36,132,170,137,241,179,9,169,240,69,27,144,66,9,69,45,79,29,224,31,128,149,95,71,121,179,139,65,241,174,184,1,155,160,69,118,246,192,8,24,
22,59,217,245,193,75,100,39,170,199,214,92,30,64,52,208,143,208,197,10,31,64,212,58,223,92,34,8,8,64,37,27,111,227,40,181,2,192,123,83,71,92,42,145,5,109,191,19,22,129,155,208,32,253,23,31,68,169,7,162,
244,253,184,122,1,115,107,23,133,51,124,80,41,100,10,173,28,62,72,161,141,222,186,243,131,10,64,85,68,0,249,197,101,212,0,8,0,39,140,94,0,36,145,29,121,195,156,196,23,107,78,254,249,214,42,32,211,5,3,
33,77,119,198,133,132,216,235,182,175,174,32,108,214,131,69,254,24,196,196,109,168,181,173,188,113,85,17,0,13,173,194,79,0,58,53,52,73,155,65,10,161,27,103,156,82,169,249,117,246,192,104,193,216,136,252,
152,97,160,211,226,48,81,19,72,136,250,38,243,210,140,136,44,55,47,7,236,104,147,160,83,191,156,242,5,149,13,122,89,50,187,208,8,64,30,12,200,19,128,130,89,92,5,0,129,80,136,175,140,122,74,33,240,55,22,
22,154,77,131,222,255,0,88,40,34,181,160,9,235,231,11,70,132,246,211,50,243,64,138,157,167,143,76,140,32,58,85,217,10,187,226,140,40,192,64,32,59,125,243,96,129,58,42,93,248,205,241,111,16,141,158,143,
166,47,106,94,234,111,223,25,139,218,84,148,248,44,192,153,75,48,47,103,157,186,167,215,219,39,254,202,210,3,244,192,251,177,80,60,176,119,37,247,184,70,161,130,236,218,125,167,126,151,40,4,212,21,41,
218,227,51,19,43,162,237,240,152,27,66,168,67,72,64,246,225,237,204,166,193,173,247,214,65,137,237,116,175,31,83,30,38,134,45,66,251,23,108,5,245,203,193,90,71,81,9,235,111,203,138,19,164,149,82,129,119,
42,248,49,119,38,170,176,52,3,208,104,49,68,166,149,8,159,35,2,35,76,14,161,47,243,196,19,162,123,37,134,95,76,44,144,62,19,252,92,71,155,217,157,81,252,117,148,202,80,108,174,63,235,226,32,59,232,59,
156,58,245,43,238,240,25,86,225,72,69,14,207,83,13,124,181,80,209,228,253,243,65,164,116,163,73,54,111,35,130,145,68,186,124,225,24,169,216,246,208,226,0,236,105,142,200,130,45,24,150,128,3,203,157,20,
23,236,94,215,7,73,162,153,116,71,119,121,161,5,165,17,233,190,6,156,46,77,217,16,7,118,75,191,124,239,110,215,183,21,6,13,89,81,74,88,253,177,220,38,131,162,145,62,153,185,38,203,210,7,21,17,136,191,
6,186,244,79,124,153,51,162,48,238,119,214,80,111,3,37,2,119,9,244,247,203,58,20,161,217,88,119,112,123,101,35,177,145,244,226,78,48,132,87,65,241,226,220,220,186,37,68,210,223,62,152,132,22,78,250,189,
152,26,36,108,128,62,211,16,26,123,211,9,217,58,205,20,234,46,190,184,247,130,132,32,142,175,159,124,137,54,232,13,19,71,199,0,237,236,105,54,157,6,1,5,244,68,61,180,235,9,233,78,134,192,157,206,13,1,
155,85,1,106,36,55,136,138,58,70,39,185,132,237,20,2,173,58,203,226,128,218,34,176,241,144,42,160,6,251,113,64,106,0,5,2,124,99,247,10,33,19,111,155,110,17,175,109,118,209,127,174,0,0,56,194,11,217,224,
250,18,1,78,147,117,246,199,246,38,180,80,95,105,113,90,66,133,111,94,175,13,33,66,40,26,25,231,37,152,8,161,4,73,174,25,46,160,1,64,4,212,196,68,2,20,108,179,201,134,9,34,139,181,219,194,46,237,65,1,
143,143,126,60,104,118,77,157,188,250,230,212,124,80,80,190,221,229,122,194,2,27,7,6,9,32,48,109,124,191,25,104,65,69,15,68,154,224,56,254,38,163,119,191,92,59,104,177,88,175,124,216,150,231,181,243,136,
48,40,67,228,113,252,244,6,212,217,243,231,130,68,82,192,192,212,239,29,70,182,59,121,50,119,137,198,164,8,72,111,167,227,20,85,74,246,170,174,24,105,68,1,80,190,151,53,36,2,15,64,197,141,157,207,162,
99,248,193,37,234,54,131,167,59,202,231,84,176,54,235,206,106,167,128,52,241,215,198,21,90,130,65,38,250,251,23,178,100,47,86,161,177,223,93,218,251,11,131,113,8,65,51,255,0,142,88,203,134,70,139,117,
233,159,86,124,54,86,85,65,128,0,170,160,26,210,109,116,224,213,61,4,244,189,27,185,217,120,105,80,15,9,175,161,155,13,173,135,3,217,50,25,125,238,35,202,211,191,110,32,8,32,81,95,63,129,236,24,49,144,
62,41,15,121,136,226,209,79,30,15,147,20,246,174,238,213,222,61,90,80,4,62,0,177,224,145,177,237,236,147,231,45,211,80,68,233,163,188,5,176,88,43,60,6,241,128,32,0,9,2,110,247,154,32,168,98,45,31,140,
24,85,129,87,85,113,76,71,91,128,25,240,110,80,38,124,240,123,129,0,47,68,125,177,88,50,81,65,222,173,185,27,0,52,34,170,60,62,113,89,129,21,211,91,239,250,160,100,51,217,3,167,195,64,199,11,131,249,0,
193,212,242,182,123,95,110,13,170,214,2,20,72,248,235,241,146,210,22,10,139,242,98,174,183,22,74,248,41,220,200,43,82,36,116,44,214,221,98,125,126,80,105,236,67,185,192,124,77,183,37,22,7,140,163,171,
8,170,179,15,203,142,13,37,88,75,63,24,98,87,208,123,153,56,128,176,118,19,235,128,27,161,47,112,102,57,160,68,33,40,138,121,201,148,44,144,196,142,143,60,72,101,82,105,10,6,131,227,34,32,58,237,5,237,
151,5,77,32,3,88,27,217,243,194,40,119,21,84,170,88,235,2,154,2,143,200,224,54,77,137,183,104,194,161,141,165,26,61,223,76,88,13,158,81,35,214,186,152,198,143,0,80,55,114,130,160,160,75,66,249,246,201,
162,196,165,181,117,198,249,198,128,84,164,117,237,140,20,26,11,30,169,245,197,128,218,4,154,244,95,124,36,20,13,40,82,252,97,186,64,136,33,101,79,110,16,133,71,64,197,27,223,206,122,131,0,52,189,190,
120,100,24,108,171,20,233,214,80,130,18,144,65,249,153,97,109,0,89,191,231,6,35,6,120,122,114,119,0,27,84,74,148,248,207,206,36,132,64,147,161,123,47,198,79,164,116,194,151,16,168,4,130,90,83,190,8,116,
93,177,16,207,57,161,200,109,12,66,77,113,57,190,131,85,36,240,225,11,72,205,2,95,156,103,77,74,142,171,252,23,20,70,8,59,30,147,28,12,83,69,84,39,151,0,104,122,6,182,91,188,27,248,68,59,13,106,78,241,
81,40,108,246,89,211,222,46,80,95,42,221,227,38,42,80,16,122,241,112,136,32,32,61,15,31,140,106,6,70,191,92,76,202,9,84,154,159,103,39,143,63,247,0,83,185,208,218,73,188,41,147,82,129,223,69,147,37,40,
29,8,4,94,3,74,220,3,80,123,126,112,4,208,41,16,68,91,227,59,77,131,13,88,220,20,158,179,126,200,175,122,223,131,14,201,21,3,137,13,245,172,110,212,168,68,244,94,40,63,92,140,66,104,193,9,79,40,253,6,
63,27,48,240,146,250,245,128,128,181,59,95,0,121,94,12,9,32,157,12,46,154,215,164,124,184,137,173,84,110,107,231,203,243,141,232,160,60,1,35,241,222,61,210,26,54,70,187,242,65,245,115,103,80,48,40,154,
46,132,125,56,32,236,35,125,75,227,223,31,99,177,10,41,217,48,21,128,171,224,194,67,72,0,87,206,238,104,76,59,26,119,190,179,109,41,163,33,108,215,18,72,63,109,20,151,239,195,19,69,139,213,81,254,177,
144,177,170,19,87,205,189,100,167,6,132,85,137,61,110,36,27,109,118,130,111,6,54,11,54,145,7,172,157,8,164,8,1,169,197,36,137,167,176,118,19,215,31,25,80,130,144,223,193,194,143,12,51,136,196,136,223,
100,190,107,148,58,50,171,74,146,245,143,76,73,70,132,94,131,198,110,103,208,127,187,211,34,190,216,218,187,26,12,83,76,85,17,34,61,224,233,72,210,240,110,126,114,123,81,19,161,245,202,36,216,13,79,62,
187,192,176,140,23,182,106,253,113,76,241,171,186,44,79,169,137,36,219,33,18,131,224,126,15,92,119,94,152,12,154,45,64,147,163,206,45,33,224,198,125,71,174,9,81,32,3,93,139,117,241,197,160,58,159,62,77,
117,140,134,155,125,22,159,140,39,24,41,248,29,230,236,138,208,111,141,153,14,155,211,82,124,186,196,205,148,116,40,45,252,224,54,240,129,221,15,123,146,202,214,133,108,33,175,175,27,108,104,1,93,189,
176,2,21,166,61,83,235,128,131,100,39,171,39,214,92,30,77,110,205,31,161,135,176,50,195,193,227,239,196,138,136,128,201,178,183,241,139,188,226,1,79,78,188,112,130,66,10,221,155,225,49,96,10,111,64,135,
217,143,137,216,7,65,252,186,225,217,162,182,162,38,169,243,197,10,150,67,181,81,200,32,20,40,137,105,215,156,34,160,5,33,0,23,206,45,46,160,2,160,1,53,128,72,83,93,32,249,111,17,254,219,6,34,190,62,120,
140,12,119,30,145,233,53,151,160,116,162,4,31,156,168,170,136,117,92,24,142,153,225,40,228,222,8,74,177,8,47,183,10,216,208,3,203,110,25,53,1,23,103,163,193,147,0,21,67,229,60,226,212,47,173,235,39,166,
163,176,9,242,56,0,32,67,218,63,188,20,68,210,52,125,204,172,74,8,5,9,120,31,123,101,58,5,59,235,188,163,46,210,165,75,173,245,112,221,169,14,160,31,189,226,102,108,144,116,176,205,136,32,81,189,174,47,
64,5,158,131,129,22,186,238,19,222,224,102,209,149,26,79,95,57,120,70,87,81,109,186,79,79,171,237,154,146,10,145,40,30,158,254,137,48,68,193,99,185,18,253,241,74,175,61,8,62,154,193,56,29,16,85,22,118,
55,198,26,72,65,236,83,171,186,125,134,84,165,166,128,47,31,68,113,69,85,94,202,170,252,220,42,216,110,142,55,65,122,139,175,156,17,13,104,27,225,196,90,48,212,22,152,136,43,215,171,189,5,224,242,100,
236,63,229,236,5,232,98,100,20,121,171,103,212,53,246,114,198,200,14,212,109,234,97,66,168,38,33,169,215,11,74,196,64,129,111,127,25,36,82,85,190,222,68,221,201,153,71,110,217,59,12,123,24,0,58,153,208,
124,39,224,152,186,9,113,168,116,1,231,9,216,234,30,26,157,31,144,197,221,85,28,143,17,16,250,178,231,24,177,73,213,65,111,76,120,58,195,127,220,6,105,235,60,206,116,130,13,164,99,137,249,144,98,52,51,
220,203,235,82,212,189,226,77,71,96,50,151,192,120,225,146,72,107,106,135,192,96,208,137,149,37,19,226,24,171,177,12,177,93,44,209,188,2,105,26,2,73,60,247,145,187,92,41,86,9,29,233,112,1,84,59,181,66,
159,187,141,169,40,79,167,245,139,71,51,72,136,201,235,56,0,36,118,48,175,4,219,112,210,146,52,176,33,221,139,137,210,0,13,74,251,117,128,77,67,123,123,131,220,4,205,128,146,110,29,137,123,19,102,186,
201,47,13,122,43,102,58,218,137,125,35,112,41,11,80,90,123,127,247,33,161,61,34,126,238,177,93,81,32,234,52,252,245,135,98,2,134,52,195,188,24,148,205,2,200,250,78,34,224,146,5,122,62,61,238,118,90,149,
81,52,239,207,166,18,11,208,182,105,76,41,140,182,72,19,211,90,193,238,14,195,66,106,111,18,41,232,167,231,36,122,74,67,212,152,170,250,13,0,143,7,199,20,196,216,211,221,120,152,172,33,93,144,245,101,
193,238,120,67,208,78,7,0,145,119,161,107,125,98,34,137,17,68,244,76,51,180,20,29,183,167,223,44,46,128,109,171,60,0,75,6,29,218,226,224,42,0,23,64,99,6,10,42,11,77,182,142,17,174,150,187,104,188,45,168,
242,6,22,43,56,130,69,10,29,5,226,31,0,59,99,90,94,183,157,105,210,118,96,93,37,144,242,163,0,6,71,168,37,167,131,53,32,2,150,16,47,156,92,42,96,6,250,2,107,211,32,140,16,163,101,141,163,132,226,210,247,
239,139,136,128,64,161,55,127,94,45,246,147,105,191,187,215,16,208,53,91,65,254,112,30,184,16,17,176,94,223,28,16,12,36,40,1,117,231,215,24,25,70,141,136,105,248,207,227,206,18,131,171,69,79,175,169,151,
12,216,213,17,247,214,111,75,82,248,179,16,50,2,40,148,69,199,225,136,6,211,175,239,130,225,233,136,38,211,232,2,190,198,19,18,6,6,93,2,182,90,237,196,73,232,48,149,30,0,213,243,49,90,187,10,59,116,219,
157,166,128,1,106,250,95,206,39,64,43,209,126,197,80,246,50,39,214,111,34,87,126,130,125,114,228,108,13,87,140,52,82,82,42,31,31,177,202,214,17,208,170,109,250,98,142,210,222,168,60,201,222,3,172,162,
144,129,160,223,175,12,3,34,160,128,61,217,146,162,111,48,133,169,234,215,53,69,219,93,109,70,11,14,173,32,137,249,192,118,178,194,172,248,245,196,63,0,220,6,213,124,6,215,42,234,66,65,77,99,98,146,125,
93,224,172,67,80,128,163,247,120,88,36,11,136,86,186,108,48,136,49,177,0,122,184,174,164,234,203,179,126,150,96,8,150,116,3,166,143,119,45,48,99,183,176,0,187,233,79,108,45,242,147,84,210,143,80,107,47,
161,118,221,160,144,59,115,71,36,44,232,4,180,26,30,64,243,105,64,11,5,125,128,174,50,6,0,208,64,155,245,193,67,91,115,106,117,225,58,195,2,172,42,190,85,112,81,19,72,209,247,49,99,221,128,216,2,206,184,
161,133,101,114,49,215,106,33,243,154,104,132,4,75,231,190,177,108,35,21,72,60,62,115,189,187,94,220,61,53,66,245,225,175,68,200,9,66,16,13,6,167,129,38,12,68,98,52,125,48,124,221,72,8,141,25,63,188,48,
69,89,67,95,38,140,10,211,214,171,238,157,219,95,39,166,33,176,208,105,216,62,151,211,16,10,118,37,68,207,16,239,141,18,17,6,213,155,198,253,175,98,34,247,249,200,66,40,27,241,109,153,96,84,237,167,149,
235,12,204,79,32,38,253,112,6,232,75,220,25,137,208,69,71,98,41,136,3,219,37,44,73,209,196,162,180,154,123,212,134,2,160,94,44,23,182,92,108,65,72,3,96,27,175,12,136,84,94,247,229,58,196,236,9,31,145,
195,233,201,88,86,68,195,2,146,88,26,61,210,98,38,131,177,18,61,107,172,88,41,178,43,13,223,231,6,182,134,33,104,95,35,227,6,37,142,235,106,235,134,200,164,33,82,129,126,152,128,177,160,233,146,152,208,
17,64,147,218,50,252,228,193,33,165,10,92,13,119,2,33,122,62,56,2,2,154,233,5,119,188,15,37,81,218,143,174,140,218,89,22,181,18,219,140,21,80,64,186,15,108,65,220,21,40,211,231,4,217,229,237,105,127,174,
22,102,133,5,166,51,253,190,28,119,177,49,77,211,217,126,50,22,129,237,218,14,58,149,16,16,105,111,124,18,16,238,192,8,135,159,91,138,94,5,141,142,156,34,26,121,10,160,77,225,74,246,68,88,151,17,83,80,
76,234,165,193,136,193,136,199,99,133,190,64,13,160,139,241,193,80,150,133,134,175,127,124,241,228,144,218,9,174,187,197,228,20,116,138,175,163,138,42,85,118,171,92,108,138,148,0,35,179,197,206,215,133,
4,131,189,188,178,30,199,190,48,140,84,54,73,135,234,19,85,232,151,225,114,36,233,145,168,215,208,111,230,226,192,182,188,42,73,237,138,233,179,250,61,162,120,91,195,112,147,32,41,61,54,217,137,54,30,
232,77,125,97,199,165,52,64,128,38,247,145,10,9,128,69,35,175,57,167,244,35,170,155,152,18,112,32,141,225,182,167,168,207,96,25,208,107,163,191,215,35,165,148,176,29,129,216,94,188,227,17,113,5,60,116,
191,140,82,0,0,77,130,44,248,224,1,68,166,176,13,122,56,139,103,73,11,26,30,125,79,167,166,71,145,119,173,72,252,119,149,109,93,247,183,121,15,165,26,9,105,224,25,79,92,235,78,147,179,12,244,214,245,45,
254,67,19,124,42,32,41,162,98,52,47,160,122,100,23,16,26,245,235,235,146,37,186,81,168,214,195,53,217,134,69,160,146,84,141,30,36,227,127,158,55,131,12,138,220,79,123,149,5,189,64,234,221,195,228,49,137,
42,64,108,180,119,246,198,84,147,64,19,75,231,188,162,2,68,106,11,199,65,241,83,100,67,251,198,217,208,105,174,73,228,119,137,216,136,221,155,79,135,179,217,205,233,9,64,192,108,35,99,239,133,81,236,172,
7,222,117,133,29,52,104,248,6,124,226,46,146,236,49,143,114,249,205,98,230,40,232,217,7,142,53,140,172,10,182,232,49,54,209,154,164,47,169,130,200,206,52,190,238,170,105,247,184,3,88,17,0,125,152,13,216,
77,135,215,215,4,123,16,23,183,88,133,118,15,174,255,0,188,26,214,54,30,52,159,60,15,10,21,90,39,161,143,68,15,209,161,250,188,184,37,193,96,26,244,182,156,80,3,197,122,78,198,117,136,231,116,252,139,
76,39,88,41,248,26,231,70,70,192,251,108,200,180,143,76,69,245,117,136,148,168,144,123,92,106,163,80,59,31,29,220,151,93,161,21,117,174,1,209,168,5,112,34,155,91,68,215,215,27,20,136,67,86,79,197,194,
163,139,99,32,251,122,101,64,81,98,26,120,183,136,47,0,174,160,171,233,51,176,168,129,30,247,196,53,4,91,217,191,19,88,176,5,55,209,171,239,233,136,160,180,67,160,189,123,245,195,85,0,130,165,3,185,227,
16,172,104,116,201,172,96,10,64,135,180,165,201,129,131,74,217,149,45,97,40,187,23,111,17,8,27,116,66,187,222,22,115,96,34,136,223,239,136,72,75,133,116,142,121,229,216,88,199,16,154,42,20,232,85,48,98,
58,211,118,83,22,84,20,129,119,160,224,219,13,64,53,91,114,40,176,17,176,250,119,50,41,73,84,79,108,81,82,190,171,146,199,69,212,1,193,16,129,3,169,31,222,10,34,105,26,62,230,94,41,240,14,229,249,153,
253,245,150,96,64,60,130,239,165,176,247,76,101,169,84,160,229,234,129,132,226,128,72,5,249,111,8,53,178,117,4,23,200,89,231,37,118,183,104,64,253,47,94,217,65,224,236,6,130,119,234,131,9,67,162,21,134,
141,189,225,161,93,53,209,42,235,190,255,0,92,168,236,135,136,99,95,25,56,200,212,9,20,252,101,198,49,10,61,38,192,180,246,244,215,106,170,170,171,85,218,174,30,249,159,104,8,25,233,104,134,189,143,93,
220,11,16,149,253,9,167,47,231,191,124,92,9,20,79,244,28,98,77,240,29,87,167,173,16,203,128,164,97,1,68,135,241,150,117,201,160,236,127,6,32,2,140,0,170,253,49,3,55,209,85,173,185,231,167,16,64,219,212,
239,13,34,182,132,116,208,125,120,120,46,26,4,11,94,190,49,41,40,197,40,209,140,210,118,99,195,64,5,148,147,115,193,154,22,211,72,32,248,239,172,83,64,16,66,7,71,207,0,9,84,138,163,254,98,246,219,114,
161,72,3,191,92,166,170,223,116,251,49,148,87,226,178,238,130,47,223,61,43,163,186,117,74,151,215,4,125,49,129,3,227,99,179,206,31,114,245,235,133,193,123,137,175,131,68,181,227,42,62,123,130,84,64,135,
168,166,71,59,242,56,117,45,186,92,78,228,7,207,1,39,88,1,34,10,131,67,223,211,47,138,37,136,110,36,158,117,235,132,102,233,78,174,137,179,211,44,242,18,189,209,79,221,196,101,16,15,184,220,12,71,16,155,
230,191,146,69,247,245,197,31,103,1,145,237,84,10,251,219,134,152,66,182,15,130,247,142,136,68,1,86,175,3,45,34,40,58,254,93,98,85,210,251,10,217,138,37,144,55,210,55,44,71,146,104,79,50,97,66,67,161,
13,122,119,155,107,164,161,212,107,250,203,85,82,40,196,175,140,18,149,82,41,172,174,34,82,234,10,232,63,205,203,43,84,162,145,5,184,212,78,136,166,188,176,228,112,246,50,125,188,101,136,6,136,216,71,
171,112,64,146,41,61,55,137,232,148,61,71,16,90,72,129,212,127,19,129,66,34,170,21,171,142,136,82,54,15,150,96,119,47,85,104,143,251,196,152,173,1,216,181,136,138,36,69,19,209,48,205,161,160,237,166,80,
93,128,194,43,215,68,203,84,162,245,52,98,91,235,194,239,64,21,162,11,250,101,73,40,14,247,187,192,43,2,40,170,111,219,13,36,157,138,106,248,248,196,80,52,39,70,250,247,235,139,129,82,195,192,206,180,
233,59,48,157,23,112,15,42,142,14,131,123,130,90,118,29,102,164,104,39,77,5,215,174,48,82,192,10,244,26,153,188,32,66,50,198,61,252,224,33,35,61,246,223,175,20,18,0,20,55,121,151,121,31,191,94,249,28,
82,215,128,119,244,184,182,16,213,48,23,223,44,171,13,4,20,30,173,224,74,66,162,160,45,255,0,153,178,190,108,42,3,214,108,87,231,219,131,156,142,80,172,236,221,236,203,169,134,194,21,239,172,220,251,65,
124,44,46,24,42,131,148,236,95,12,250,30,185,73,193,0,218,63,9,223,0,2,104,58,0,111,125,92,81,146,188,213,13,122,180,25,235,157,62,52,67,217,1,90,12,247,196,118,244,108,174,223,170,251,102,206,184,129,
64,27,235,231,215,33,148,1,54,176,116,186,49,139,37,21,232,71,121,179,27,96,40,252,240,34,2,87,160,21,110,14,48,138,212,124,59,48,213,211,7,98,126,77,200,250,226,32,138,33,0,29,1,120,69,92,84,129,13,123,
179,172,3,128,32,65,19,195,172,214,246,212,44,170,131,52,224,29,128,174,189,114,104,11,66,172,61,189,120,2,0,26,90,75,252,101,64,2,32,1,123,60,167,0,6,134,189,130,232,211,227,35,136,110,52,39,219,249,
206,244,71,67,165,205,206,174,127,30,152,165,137,8,83,247,143,26,19,35,230,236,72,30,110,72,6,0,92,97,93,149,249,53,142,7,93,12,155,118,242,54,123,102,128,0,0,161,2,120,239,7,65,143,64,150,122,157,97,
129,87,69,95,43,132,81,205,128,111,143,30,217,162,115,132,7,90,240,160,190,30,45,9,0,53,0,123,215,121,162,8,105,68,190,101,235,18,144,36,74,0,123,6,241,223,123,189,223,56,4,70,122,66,254,86,79,100,193,
61,4,81,211,253,9,197,64,81,58,26,108,100,245,194,169,150,80,165,254,176,186,179,100,14,150,123,119,49,246,45,199,113,7,211,19,211,84,149,11,197,162,196,32,85,102,242,213,78,164,136,205,245,128,104,162,
54,157,174,93,21,59,41,238,235,4,181,21,59,2,125,112,2,208,39,192,204,68,30,88,122,138,97,97,181,32,108,117,195,67,42,147,183,96,79,198,2,100,221,157,23,207,213,199,228,168,4,176,156,47,43,42,29,158,113,
26,236,95,93,255,0,120,43,216,149,157,186,192,35,98,187,26,233,186,201,180,140,69,168,125,241,72,81,164,120,43,112,127,64,196,4,66,249,190,48,96,116,236,187,87,93,240,74,48,170,165,106,251,227,128,109,
67,65,123,100,185,37,29,162,160,71,175,125,241,86,206,128,108,181,136,164,72,138,39,162,107,4,109,3,67,182,147,2,157,224,59,81,245,209,131,85,96,41,120,11,125,241,130,171,8,11,160,196,22,216,168,99,79,
27,193,102,63,157,165,239,233,198,203,65,65,118,143,41,188,79,169,101,240,226,113,117,106,110,158,203,241,144,245,143,149,75,233,113,186,133,17,238,55,183,137,64,219,43,1,1,253,228,57,0,25,216,233,231,
63,223,182,21,0,238,11,73,54,224,107,186,136,145,47,192,235,41,85,69,61,21,31,219,43,164,209,133,28,0,164,176,128,0,207,93,28,58,41,235,88,118,170,238,119,158,35,98,52,58,213,14,253,51,91,36,62,228,88,
119,208,228,120,44,217,79,13,242,44,130,166,89,20,19,248,200,0,6,231,206,49,172,118,47,96,63,38,108,50,129,26,61,219,177,244,193,16,5,94,128,85,248,195,100,13,58,106,9,77,146,100,242,92,212,51,64,54,255,
0,24,30,215,89,49,77,172,90,121,197,212,107,111,209,214,100,113,10,83,185,15,237,128,210,34,67,209,110,111,130,145,216,32,133,249,184,197,119,32,68,133,123,129,159,57,70,107,181,168,211,73,222,29,133,
129,244,114,168,222,194,252,190,142,58,185,228,132,78,150,111,199,0,90,21,54,3,94,142,0,152,108,23,97,249,153,191,193,34,195,21,215,86,240,187,13,74,13,62,202,121,206,180,233,59,50,33,145,126,165,161,
239,185,143,201,170,128,38,245,23,172,236,200,80,58,158,190,153,1,168,9,71,174,231,119,6,200,137,117,109,191,36,197,9,165,30,93,56,245,217,69,69,164,221,64,250,99,165,61,61,54,98,162,42,133,179,177,250,
227,106,73,168,19,79,172,197,19,64,85,105,175,166,22,237,217,23,201,175,242,103,118,237,10,145,4,252,228,208,0,132,65,220,19,211,141,215,112,219,41,20,35,211,179,5,80,70,40,177,239,34,32,151,77,162,36,
240,24,252,223,25,20,2,181,1,26,61,156,36,154,2,89,5,252,112,53,192,232,21,93,226,254,128,161,177,9,226,235,4,16,44,43,193,89,140,186,13,16,200,125,186,195,22,146,13,141,61,54,225,215,68,5,237,215,247,
140,103,96,147,217,192,229,96,23,206,137,122,188,15,37,162,211,9,158,196,254,224,254,93,225,181,42,0,171,177,111,227,139,209,81,65,178,14,48,31,88,247,21,63,24,76,244,164,238,13,193,234,129,187,8,154,
234,121,201,42,14,159,244,235,16,170,145,175,22,203,150,254,157,24,139,215,231,37,38,42,155,86,107,132,37,106,2,165,123,232,207,49,111,84,144,113,40,141,109,26,117,53,123,151,5,134,91,18,131,245,235,43,
82,11,48,211,197,175,156,69,188,45,250,151,251,193,94,162,176,237,214,66,8,165,91,39,143,76,150,233,216,73,166,42,194,169,94,192,91,135,233,3,17,136,133,254,48,3,37,179,218,233,223,21,241,160,3,18,158,
83,198,59,59,33,131,49,32,69,0,134,231,74,92,6,25,105,75,31,174,47,104,168,157,146,199,111,27,114,13,180,192,173,56,101,98,161,217,21,243,243,157,245,188,137,64,16,157,4,221,199,67,9,181,41,167,211,188,
102,81,82,167,85,83,88,105,190,158,160,159,156,98,142,0,17,161,28,49,140,65,89,135,88,104,99,21,167,187,214,192,122,134,53,118,157,83,160,62,235,149,67,212,90,235,14,64,3,34,181,123,42,3,175,92,137,238,
19,210,79,62,247,5,17,24,141,31,68,203,124,131,82,90,249,70,83,193,139,31,2,13,78,79,171,162,226,188,171,241,144,167,199,120,132,66,133,32,10,239,104,92,162,118,6,160,175,215,46,141,82,91,73,249,7,8,91,
230,166,203,67,237,113,232,42,186,116,45,244,13,87,211,222,24,177,2,65,67,52,31,7,251,188,175,208,249,193,141,247,218,196,245,68,26,248,146,118,168,158,185,179,238,227,214,166,48,144,129,0,68,83,206,104,
13,9,2,11,222,109,241,247,205,24,208,120,97,175,96,15,182,41,238,237,2,72,203,162,34,101,37,133,178,104,93,179,171,235,131,2,245,189,92,183,218,101,85,85,173,173,219,113,26,17,218,191,38,205,224,80,34,
18,73,19,1,60,26,61,82,28,43,85,152,129,2,244,221,76,28,225,208,21,194,249,60,30,203,216,157,224,211,78,116,2,174,206,205,220,48,35,186,106,233,208,124,240,17,222,17,176,69,134,250,48,80,163,20,163,71,
0,1,6,195,100,158,59,151,10,11,82,160,13,119,215,174,88,246,97,72,58,1,8,227,159,43,242,56,15,99,233,43,130,134,75,1,139,164,95,140,106,40,93,104,54,160,201,177,55,185,103,5,156,64,236,18,73,211,154,87,
198,4,68,179,204,140,71,101,4,5,190,140,245,157,96,207,114,138,110,51,227,18,245,248,56,175,19,103,18,128,142,155,67,72,125,240,166,248,1,13,208,72,189,152,105,21,208,211,40,188,0,62,227,235,130,34,4,
128,100,117,39,159,174,119,3,138,109,71,234,96,93,64,133,237,161,191,124,21,9,17,17,60,38,62,1,129,94,29,61,184,30,101,238,124,5,241,130,214,20,209,15,107,51,195,136,20,213,7,158,1,90,104,66,202,255,0,
152,149,116,195,209,29,227,169,232,79,179,114,196,5,20,216,79,105,135,137,15,73,215,223,41,93,18,131,168,211,252,97,66,170,10,49,43,46,0,83,173,26,200,254,47,10,6,174,161,89,15,93,119,142,138,165,20,137,
95,57,166,154,10,26,141,253,122,192,208,135,177,117,246,235,2,164,21,0,81,61,215,250,195,10,72,19,210,51,17,195,43,95,44,30,224,68,30,200,235,215,174,15,19,101,82,170,215,158,176,150,213,232,162,46,142,
179,76,133,214,213,102,182,241,208,0,2,196,221,216,119,128,96,85,74,108,31,89,115,68,26,134,61,162,151,231,1,131,59,136,151,235,144,44,75,212,211,82,158,252,71,172,64,150,0,127,97,147,103,98,54,59,223,
156,239,70,215,163,35,232,18,165,85,111,156,52,109,228,80,158,221,245,142,208,52,39,70,231,158,4,8,104,18,135,8,138,58,70,39,185,130,172,93,192,106,170,101,201,33,170,85,237,231,211,59,2,9,82,64,186,152,
170,213,87,173,250,26,199,136,161,8,166,172,112,82,83,10,84,141,119,220,111,229,61,50,180,232,159,169,126,110,52,236,112,24,122,212,93,226,63,152,62,174,46,31,67,70,68,94,148,28,32,30,10,180,131,118,72,
247,87,42,196,5,0,55,130,221,60,0,68,183,40,10,159,116,198,39,101,174,192,80,142,252,92,128,45,52,120,13,127,60,9,10,147,75,175,158,238,3,105,5,54,71,163,211,92,244,124,151,170,161,113,20,88,78,228,165,
237,119,233,48,86,42,64,154,223,6,206,57,62,192,78,61,199,228,235,206,41,106,194,153,184,55,231,55,84,35,176,123,143,169,23,222,224,225,212,27,30,167,143,140,222,213,119,175,111,245,194,52,153,140,31,
71,232,166,252,103,98,128,122,233,62,128,208,249,245,205,155,177,87,64,118,190,211,58,23,72,6,168,157,223,198,8,129,43,160,21,111,198,14,4,24,58,119,84,248,203,100,141,133,122,46,203,122,196,1,20,66,32,
104,13,241,98,65,161,218,3,70,245,132,32,5,0,208,120,113,200,217,96,208,170,51,112,96,232,133,117,169,154,132,219,38,39,100,157,241,20,120,32,66,32,159,108,1,1,100,64,79,65,235,198,244,0,53,6,140,3,217,
195,196,101,97,21,31,121,102,121,22,52,242,102,231,174,9,1,138,190,8,201,246,193,77,161,18,161,51,207,190,95,138,158,59,234,95,94,166,60,64,164,13,66,64,12,147,176,160,138,24,72,190,184,170,34,130,189,
129,85,244,12,100,158,130,136,38,231,127,92,101,64,210,69,39,169,35,134,232,158,160,74,215,88,40,136,196,216,154,68,199,79,0,143,100,38,186,64,75,132,109,79,72,27,7,176,137,237,147,1,160,94,130,215,231,
172,88,117,232,77,95,51,211,33,40,4,18,173,103,153,199,66,112,32,165,211,222,73,136,130,142,180,35,95,28,30,192,201,88,163,119,175,92,58,184,178,137,167,17,47,168,14,172,191,89,115,214,52,69,154,117,132,
66,187,18,187,126,55,193,74,118,16,219,214,242,143,83,68,136,189,245,239,128,65,160,218,118,182,101,218,14,213,252,58,205,174,34,128,90,111,187,253,97,17,160,79,129,152,201,61,39,220,81,203,64,20,15,100,
157,245,231,133,2,10,146,43,176,36,126,48,59,62,167,65,250,47,120,172,139,0,164,0,190,120,1,27,42,13,60,223,92,103,59,20,249,193,177,0,40,106,55,231,188,175,1,236,82,125,186,193,42,85,0,40,158,248,97,
73,2,122,70,121,198,112,206,143,165,105,201,100,134,133,217,29,61,61,113,8,119,86,10,90,194,0,170,134,130,237,234,227,25,40,51,162,79,94,16,140,137,33,181,171,239,129,74,210,40,252,152,98,170,6,135,155,
25,216,20,152,149,167,199,89,178,214,45,36,146,248,239,21,101,86,16,190,12,138,22,138,133,17,55,227,219,29,27,151,212,59,188,7,110,106,3,177,60,166,242,47,66,150,80,113,154,12,62,153,220,250,26,171,233,
129,58,180,182,183,179,165,109,193,106,233,96,90,244,244,195,79,24,151,173,139,252,24,6,25,18,160,0,31,86,225,44,216,98,141,55,238,241,14,17,32,85,254,164,197,172,245,153,42,187,91,242,106,252,225,182,
224,118,7,224,126,17,136,247,151,93,4,80,133,75,248,197,8,24,140,21,79,81,241,146,201,47,15,79,187,217,250,56,6,145,121,24,215,233,56,160,136,147,68,233,185,228,99,49,84,0,29,160,79,3,218,215,165,217,
147,77,15,94,59,183,219,208,215,182,10,162,219,8,63,252,24,38,0,36,244,128,99,144,218,135,189,250,159,231,219,8,131,68,128,216,249,110,204,116,72,84,42,219,167,190,240,200,90,49,137,42,83,216,102,44,188,
158,52,199,224,153,7,232,114,2,215,91,212,8,250,123,240,215,96,75,113,16,31,46,110,200,212,242,47,200,198,240,99,244,44,5,247,152,227,118,192,138,61,30,240,228,59,26,160,196,147,188,16,11,5,11,220,28,
82,22,32,10,160,239,205,196,50,72,48,154,109,15,115,141,30,74,88,5,169,174,240,8,155,160,34,139,226,205,24,53,240,65,164,0,108,234,222,59,114,148,129,103,163,227,17,20,72,140,71,194,100,205,37,187,165,
195,239,50,196,81,52,2,124,46,238,26,39,172,145,19,227,80,62,184,63,153,151,88,218,95,199,111,140,186,29,157,2,110,130,64,240,186,249,222,48,205,41,213,108,235,192,112,167,156,235,224,109,158,184,145,
77,49,74,52,102,47,2,155,84,42,55,93,226,169,214,128,132,31,26,241,141,91,75,85,216,118,26,225,169,48,105,88,71,186,246,246,125,176,2,73,70,144,124,53,192,190,17,107,11,169,112,133,96,49,147,88,178,145,
68,14,183,185,174,240,65,20,165,217,178,159,76,121,148,66,170,40,95,199,21,141,142,131,106,239,20,150,130,163,116,39,139,227,9,52,209,84,102,217,150,116,26,53,33,246,235,25,81,41,177,167,125,220,17,236,
80,187,100,196,238,128,159,124,12,82,1,124,154,151,171,195,113,5,82,44,39,140,80,212,76,189,30,155,158,185,184,98,65,79,98,238,207,78,10,151,193,116,146,249,244,198,3,228,143,132,84,192,107,66,147,184,
55,13,156,20,86,200,159,76,48,111,209,68,202,43,84,72,30,45,192,170,175,69,17,122,235,42,128,192,44,117,59,235,132,177,86,137,106,4,223,198,4,43,228,210,47,163,215,5,147,4,168,18,249,225,164,128,166,5,
155,239,227,61,232,37,245,48,87,168,150,30,117,49,136,26,84,45,53,19,121,108,121,130,208,250,98,168,21,74,1,240,45,195,160,160,98,40,136,95,24,89,135,107,218,186,237,120,215,90,0,26,42,119,60,98,85,216,
29,51,115,197,153,64,139,1,38,231,75,188,116,140,182,35,191,174,72,0,184,67,97,211,59,223,22,235,27,165,129,54,57,124,9,26,4,14,168,216,186,39,163,149,110,147,248,95,235,155,0,0,141,4,188,175,187,58,200,
84,138,9,7,164,101,34,137,76,133,84,215,219,3,235,98,243,224,127,56,66,192,179,128,14,187,213,50,105,14,228,13,23,208,102,77,208,10,162,71,79,12,59,35,239,137,200,135,112,186,139,15,169,245,196,93,134,
12,30,64,170,186,89,49,21,20,218,173,92,173,90,17,17,71,88,37,128,196,116,191,113,222,28,176,88,81,210,201,212,15,166,104,250,157,152,32,20,208,158,14,176,105,18,245,5,184,252,88,101,113,136,155,165,158,
157,250,101,125,202,5,217,78,205,93,124,97,171,204,192,123,29,122,142,95,133,46,37,191,115,195,238,56,90,208,50,214,241,214,226,159,70,50,43,165,4,75,216,140,72,227,160,208,111,23,70,248,213,250,38,56,
82,67,52,209,79,62,205,251,121,200,80,32,59,5,234,122,100,209,93,234,75,82,253,113,5,196,64,34,145,239,12,1,2,123,98,161,189,94,32,45,1,96,32,250,229,36,145,136,125,76,179,231,10,53,61,147,120,183,93,
76,190,124,255,0,220,110,139,137,164,6,207,135,17,34,34,79,68,102,21,160,42,249,7,6,8,69,116,1,233,167,70,10,68,200,11,119,54,40,112,96,173,86,119,129,28,162,106,144,93,223,83,6,9,87,95,41,53,14,130,240,
244,116,164,195,5,191,118,43,114,228,98,50,253,231,147,247,199,2,128,213,217,217,61,46,30,22,165,64,26,239,175,92,4,233,154,146,37,233,9,193,172,78,65,236,121,193,69,29,19,18,71,163,190,0,60,197,97,123,
2,93,102,217,249,129,20,30,189,48,221,40,182,210,80,236,103,88,63,32,148,183,106,212,217,211,238,56,134,54,138,168,181,175,126,16,88,186,155,94,143,239,11,16,82,144,85,58,72,190,48,81,72,10,166,131,22,
154,0,130,32,4,144,201,37,192,200,53,97,61,160,66,181,105,255,0,112,81,17,136,209,244,76,158,4,146,248,72,244,56,29,38,213,29,5,241,239,112,82,196,52,65,240,89,154,113,16,10,123,125,248,2,189,66,80,149,
235,233,51,212,66,161,177,28,81,44,136,223,72,225,118,39,103,66,121,235,8,23,14,173,39,243,133,81,180,161,215,134,20,38,160,49,71,108,241,148,112,119,10,186,39,159,22,112,61,101,104,43,35,215,32,165,20,
9,178,239,197,235,4,20,65,73,173,47,158,231,22,109,144,44,2,94,220,238,2,40,35,68,87,198,2,221,104,59,218,227,179,1,69,86,19,4,1,224,208,255,0,185,66,182,140,30,157,224,182,7,146,34,245,214,75,26,5,181,
84,213,94,34,16,116,6,133,190,112,10,21,84,214,193,245,153,72,138,216,211,189,70,95,75,128,160,206,226,37,250,229,138,8,248,155,53,47,207,21,203,16,18,195,179,250,201,114,168,17,52,239,206,119,163,107,
209,139,232,7,112,77,110,29,147,168,26,9,237,46,83,212,224,80,239,220,1,92,150,70,254,99,55,234,190,115,64,77,2,18,234,45,237,136,138,58,78,241,90,146,96,96,192,109,250,226,118,2,6,53,99,125,50,226,132,
106,160,93,86,241,29,8,177,106,0,126,10,178,214,36,139,179,182,118,163,246,97,8,35,211,173,45,225,194,194,0,67,228,22,57,79,66,150,80,101,194,176,161,95,30,79,147,17,253,247,70,27,62,131,135,134,135,73,
5,55,246,224,1,21,141,65,87,236,102,212,214,85,16,155,126,136,97,231,73,44,154,100,249,58,124,49,194,29,144,14,93,118,211,212,125,204,66,209,64,10,87,66,73,215,162,124,224,6,152,216,53,34,61,111,198,19,
241,130,8,128,40,247,169,249,185,37,241,136,73,47,131,129,219,225,48,31,229,125,119,126,142,253,114,41,167,161,161,227,221,134,195,66,208,174,223,14,184,91,69,166,0,148,160,230,152,130,35,64,154,125,38,
110,173,138,245,0,92,84,16,22,4,154,245,177,31,76,20,11,61,2,87,226,100,69,20,36,186,173,246,235,0,88,232,238,211,86,247,233,141,73,84,210,144,208,7,19,249,0,53,3,232,22,29,96,26,5,14,159,12,1,85,234,
222,143,108,27,104,64,42,235,72,92,134,162,180,163,24,145,2,253,120,165,255,0,2,40,131,238,166,5,9,121,16,161,53,234,156,109,130,46,166,204,19,217,195,228,101,136,90,123,203,50,206,244,6,142,155,247,113,
102,42,20,20,26,31,71,174,39,154,68,42,170,64,61,112,175,65,96,210,210,83,189,226,54,57,69,66,7,224,35,226,121,195,74,0,2,0,9,227,16,12,8,128,210,199,4,90,75,87,106,175,17,184,164,109,148,110,53,190,27,
1,100,47,65,123,247,235,22,72,166,180,9,95,195,22,88,160,91,107,60,135,3,174,226,2,151,231,32,196,65,35,168,15,15,73,192,236,12,149,20,108,116,107,14,174,44,162,105,250,226,101,210,32,117,101,252,92,98,
27,90,84,103,211,54,184,180,170,165,123,241,108,173,14,194,179,125,224,53,229,81,177,155,234,224,45,128,141,164,45,202,116,244,74,163,227,172,182,20,96,7,206,156,35,8,8,61,134,31,140,100,158,151,209,99,
248,193,66,117,133,137,211,190,176,18,164,203,0,159,46,51,13,181,157,120,57,169,176,17,83,75,60,101,156,99,42,174,137,219,226,167,22,224,90,15,4,122,228,166,4,232,169,118,245,227,1,213,48,132,233,116,
62,153,75,105,221,77,199,167,108,9,217,239,239,133,1,34,33,61,17,153,109,97,98,88,81,187,115,104,106,234,1,59,74,123,103,120,53,101,53,130,170,220,42,27,18,82,11,219,215,88,130,77,148,232,35,215,231,139,
60,66,74,49,242,245,196,69,216,199,9,193,65,161,229,81,146,108,149,154,141,183,220,3,232,250,225,164,69,216,52,90,71,120,247,218,66,249,175,219,7,48,40,84,68,47,143,108,20,220,254,202,247,192,14,117,49,
32,32,243,228,49,192,1,32,89,84,195,214,112,147,213,244,210,2,244,219,234,198,8,3,210,159,231,16,217,41,48,222,222,56,9,141,181,93,80,7,243,130,10,16,180,136,159,51,24,187,225,69,208,46,190,48,3,67,214,
60,130,30,207,76,223,18,42,141,188,144,110,33,202,135,18,232,231,176,96,162,101,1,81,24,0,119,125,48,18,196,36,226,10,122,71,193,243,190,12,137,21,61,42,218,119,222,176,95,160,110,200,212,159,3,234,239,
187,107,97,179,17,60,59,221,223,178,226,236,175,98,174,237,249,192,243,112,4,4,174,143,111,95,19,52,116,53,1,13,25,167,146,85,177,162,62,61,95,79,76,85,13,140,192,248,22,199,34,33,61,85,119,53,51,76,238,
10,142,146,41,233,142,52,138,182,5,135,192,203,216,16,160,8,46,131,222,112,108,8,111,86,33,64,55,222,92,131,204,83,79,77,239,88,131,151,225,33,131,241,139,152,104,128,132,121,30,255,0,56,52,45,15,102,
52,146,79,206,16,221,1,123,131,49,154,194,164,30,158,125,28,154,149,244,72,18,207,135,12,108,8,163,10,250,24,119,230,164,52,121,154,103,82,210,26,0,6,190,171,199,175,164,69,46,150,61,224,80,16,40,30,196,
99,147,16,188,205,23,173,123,224,141,165,4,71,192,88,224,200,95,111,99,71,206,107,110,196,137,231,228,220,114,200,90,20,29,247,231,43,88,108,155,104,120,209,196,80,79,34,250,224,61,158,185,55,199,88,242,
218,125,99,226,122,227,18,41,6,167,102,253,242,5,12,116,192,131,244,101,129,135,186,189,135,97,196,6,40,81,66,122,224,33,18,27,4,31,13,112,234,148,44,155,208,186,235,40,176,12,119,69,249,197,148,138,32,
58,245,48,130,41,75,179,170,125,49,114,108,10,170,65,127,28,30,219,29,65,85,222,41,45,5,65,104,79,23,198,23,91,69,81,13,179,21,84,94,202,144,251,26,199,138,196,0,6,143,88,99,160,128,189,200,98,118,0,79,
145,195,4,40,13,165,240,166,184,146,34,133,82,234,106,14,81,65,58,16,94,139,128,70,81,5,64,69,237,248,227,111,149,8,124,111,188,15,56,58,86,205,245,129,41,4,108,32,215,191,120,162,174,247,84,153,102,22,
1,55,231,0,194,2,15,99,175,198,32,157,159,105,102,67,6,100,33,240,150,78,26,237,210,144,106,73,190,186,193,8,30,113,7,254,152,218,192,52,104,75,231,141,203,19,188,33,190,223,108,217,150,44,70,137,116,
224,162,45,88,121,214,52,138,53,11,79,191,121,64,29,135,81,244,222,47,138,161,66,248,45,205,221,9,218,35,47,140,97,252,23,116,101,94,96,10,251,25,44,141,253,153,191,119,206,7,100,148,36,19,210,251,51,
168,177,230,205,27,177,102,1,18,176,18,70,116,165,249,195,176,55,218,119,239,100,122,148,58,4,72,206,226,100,234,147,197,37,223,215,190,1,13,164,245,220,126,19,44,236,64,232,10,29,61,220,102,225,96,26,
162,131,216,19,233,146,72,2,41,64,155,135,21,5,58,80,75,53,7,172,182,180,148,200,85,77,125,179,173,250,98,61,3,232,111,86,178,162,223,161,199,226,57,189,143,100,133,67,95,137,155,148,1,76,75,183,176,29,
226,2,145,178,212,128,45,71,242,123,98,169,82,175,106,215,33,182,138,128,154,216,232,160,250,184,225,116,92,35,140,243,39,201,183,190,34,54,19,19,120,61,183,223,135,141,116,94,78,20,65,97,247,237,125,
61,242,149,96,238,206,173,110,68,15,71,26,7,144,215,110,203,216,246,122,152,241,81,179,32,62,204,246,76,103,224,59,246,190,122,239,177,33,20,186,170,27,3,126,12,179,173,226,136,166,207,171,40,72,81,11,
61,47,227,4,95,160,200,221,54,238,159,57,39,129,6,195,190,130,58,247,194,49,81,169,237,154,192,75,2,0,17,29,56,0,40,22,74,18,207,151,14,129,176,164,2,35,93,245,136,128,140,196,71,179,52,249,153,182,132,
0,120,85,219,92,30,117,214,68,195,101,157,56,218,64,39,231,0,211,96,183,225,190,176,1,64,130,16,137,167,94,49,80,83,211,105,191,119,83,32,20,46,192,85,181,157,225,49,218,151,88,46,254,140,239,8,173,181,
36,235,175,60,30,116,17,54,1,209,241,130,128,128,80,29,39,174,17,34,205,134,201,62,178,224,0,84,85,69,119,225,222,90,26,195,112,26,54,17,224,206,76,1,53,5,245,23,221,12,20,171,96,68,66,248,124,240,50,
128,10,39,122,137,172,117,232,118,90,7,230,99,226,74,208,124,61,25,241,192,155,134,74,193,111,87,134,53,166,1,181,132,254,240,177,133,4,33,180,209,37,193,68,40,42,72,24,166,195,80,5,1,215,70,75,46,5,32,
213,132,228,193,71,186,217,251,224,162,35,17,163,232,152,205,4,25,182,9,10,104,224,249,131,220,150,5,234,250,220,86,34,149,33,237,112,140,137,1,79,96,242,28,109,30,145,64,43,203,241,130,56,136,16,104,
137,237,131,17,244,71,95,57,168,67,233,86,19,207,166,2,84,50,192,31,171,130,26,8,3,218,49,40,236,4,249,28,40,4,162,65,74,120,166,184,218,9,10,165,100,215,122,202,41,16,160,2,244,92,44,98,128,116,7,231,
139,96,116,132,16,75,219,130,65,2,17,162,43,222,89,186,66,119,166,227,162,170,194,168,123,245,248,192,64,167,144,135,247,248,192,139,74,36,62,248,25,164,209,83,111,93,123,228,141,7,165,90,154,171,190,
6,5,0,30,23,206,13,224,84,18,160,190,216,26,198,212,73,27,38,175,166,47,221,142,9,246,188,160,125,92,100,32,221,129,163,18,155,152,136,162,68,81,58,137,157,44,6,238,130,103,218,184,241,85,68,130,136,245,
60,76,8,1,86,64,42,175,167,130,51,186,4,165,108,215,174,56,72,110,16,116,190,204,55,170,52,53,36,190,167,130,210,205,252,225,176,61,133,196,138,61,154,114,204,213,1,96,175,174,42,152,208,104,219,214,220,
144,66,151,176,5,214,217,87,189,244,125,2,100,153,109,32,8,243,26,240,190,152,0,108,64,117,69,126,184,84,124,149,48,250,142,69,200,0,68,83,185,107,107,229,195,120,75,40,159,227,43,26,1,214,198,222,71,
62,101,212,97,167,200,68,236,116,230,238,31,66,195,100,119,58,219,214,26,225,220,125,85,108,3,161,162,116,158,157,228,231,48,146,128,68,125,17,242,55,47,140,164,232,1,238,232,75,179,231,94,117,227,45,
84,148,108,49,105,142,85,69,2,52,189,58,205,108,54,50,98,35,246,63,203,181,22,52,49,40,158,77,250,153,167,53,93,208,244,61,184,152,175,10,192,15,110,242,44,192,68,16,154,240,185,60,64,26,20,159,118,164,
197,187,118,187,87,206,55,166,215,65,40,203,49,152,36,158,166,212,117,237,132,235,9,59,208,167,175,108,158,132,22,67,225,243,210,98,97,162,73,186,226,4,23,72,47,117,157,245,155,158,198,251,162,31,211,
16,154,40,175,144,1,193,192,8,123,60,142,138,205,225,236,202,96,149,55,206,238,92,135,82,143,99,31,14,130,19,163,210,23,19,207,131,6,99,19,122,184,246,234,123,122,101,47,248,16,34,14,33,70,234,123,90,
107,165,223,14,33,36,75,26,48,15,65,192,106,207,10,149,240,179,3,16,17,13,239,35,53,188,174,3,245,193,122,7,202,253,24,44,218,138,160,153,170,250,240,225,146,38,21,106,96,96,2,172,217,105,214,13,117,66,
164,64,13,238,226,160,144,0,10,0,107,198,22,4,66,70,150,61,229,74,146,215,106,171,130,96,53,130,129,119,30,188,62,132,128,83,164,221,125,177,237,169,173,20,31,162,227,1,0,69,110,179,207,26,71,64,65,240,
123,193,184,68,82,17,52,35,95,28,107,5,147,107,245,107,70,240,123,5,142,196,126,174,34,94,162,14,180,191,89,113,0,70,205,55,179,233,138,123,246,90,174,222,252,15,210,161,15,141,247,140,145,89,80,67,197,
195,8,169,0,25,184,243,195,112,238,64,81,183,151,227,1,50,66,128,17,61,176,98,62,136,226,36,31,91,101,26,55,175,198,15,19,81,97,31,122,220,70,27,65,244,240,115,162,136,0,211,78,188,99,20,225,150,214,68,
237,223,111,12,208,163,65,160,35,203,155,205,131,162,162,237,235,39,85,32,66,62,93,62,147,23,181,47,117,55,239,132,29,69,40,74,125,60,225,142,72,19,210,51,44,172,52,87,170,211,248,193,138,180,58,14,181,
154,235,74,59,175,235,109,15,108,32,144,133,10,87,236,197,19,72,192,5,85,232,24,57,182,71,101,133,30,251,171,157,31,247,172,232,47,212,131,29,190,176,198,102,84,148,104,251,147,195,154,26,244,122,170,
12,109,128,42,82,55,118,220,12,32,41,30,172,219,175,99,13,126,193,133,9,191,19,46,123,74,168,231,140,239,183,190,10,138,163,93,67,126,252,32,244,83,64,137,38,253,176,178,64,248,74,124,204,128,0,54,15,
149,22,62,216,204,28,54,41,254,112,160,38,72,3,190,231,105,195,25,37,165,213,0,249,118,228,163,193,232,124,153,169,131,0,229,74,2,71,217,139,244,247,200,136,3,52,17,217,10,211,0,196,237,6,157,37,244,61,
177,114,81,141,66,142,189,173,241,88,233,241,73,40,236,133,10,131,234,23,40,128,220,174,34,38,175,88,11,197,78,0,252,15,15,158,156,65,150,195,170,106,34,59,163,227,36,132,74,72,81,215,125,56,120,115,164,
180,129,134,3,194,254,93,170,170,181,118,174,213,112,193,100,67,13,142,227,226,102,128,108,16,134,160,159,24,162,12,68,71,210,56,82,157,29,70,206,231,163,129,136,15,74,135,199,140,73,160,37,145,98,69,
237,50,32,52,110,173,48,248,14,2,117,50,26,73,232,247,156,5,0,8,237,98,22,30,231,19,0,178,137,5,99,219,88,7,163,109,116,48,63,51,25,5,104,233,132,110,161,112,136,218,130,42,29,235,175,206,0,86,9,123,131,
50,9,0,192,34,63,87,167,120,75,173,246,80,37,135,191,7,173,2,168,190,1,24,76,103,72,1,234,203,48,78,164,128,80,0,107,166,239,1,147,66,53,3,53,22,123,226,41,68,69,17,240,154,199,85,9,168,170,46,26,247,
152,51,89,65,208,159,14,42,237,202,205,162,43,226,15,177,114,66,96,208,96,125,177,81,138,33,35,83,109,184,141,8,165,93,181,237,193,99,144,160,160,78,211,219,29,41,111,185,211,146,22,212,36,209,190,253,
242,15,65,211,4,30,250,152,58,66,17,6,244,59,235,132,146,14,160,210,247,249,202,38,3,65,165,214,186,225,81,38,76,154,145,117,214,81,232,49,208,151,229,49,98,110,32,58,189,159,56,32,138,80,118,62,79,166,
110,158,34,170,216,82,251,113,117,104,145,177,90,250,228,206,32,21,186,132,212,246,205,196,80,164,67,108,196,215,99,80,65,31,16,212,192,104,18,132,216,252,224,134,130,0,246,131,194,173,193,26,85,239,173,
14,7,64,12,116,71,234,226,177,186,89,213,107,251,196,1,16,119,234,62,152,138,99,178,213,97,249,107,141,136,164,30,195,93,225,40,142,239,109,135,137,147,81,17,176,155,190,253,226,74,165,182,174,199,23,
33,128,18,39,103,139,144,194,1,7,165,107,241,155,18,75,62,215,121,189,80,14,134,106,126,120,80,189,250,7,64,77,252,96,24,6,186,32,199,159,118,54,176,13,12,9,124,228,93,85,233,233,31,70,95,92,135,17,149,
16,4,219,236,204,217,131,36,136,130,233,39,174,13,68,49,140,107,12,164,140,26,139,31,126,240,84,9,118,132,250,111,28,100,89,62,129,95,153,132,174,232,161,34,141,67,154,74,62,67,212,149,118,232,226,27,
67,168,45,61,158,222,48,148,243,225,0,245,118,193,186,6,33,77,190,165,175,194,184,167,105,173,106,181,195,38,203,68,136,19,216,44,120,5,67,108,93,78,255,0,156,79,186,2,33,176,119,224,7,233,128,168,10,
190,13,190,184,19,7,0,77,61,97,199,1,102,129,141,77,79,76,239,101,13,33,84,107,237,134,203,185,6,201,35,232,16,249,115,69,206,214,78,247,44,80,246,225,116,33,5,137,147,102,244,10,123,153,102,40,92,196,
245,216,155,141,210,119,141,146,224,197,164,155,186,148,95,23,172,85,85,85,123,93,174,46,35,3,85,44,70,139,148,70,72,233,33,240,107,167,207,159,81,214,113,65,222,19,97,196,112,244,105,9,176,79,174,31,
211,41,20,241,27,240,127,151,116,58,139,68,124,2,158,207,88,10,9,65,142,196,238,91,141,201,187,132,66,106,14,34,173,81,181,65,24,31,6,89,146,157,34,47,98,62,249,104,34,140,122,127,250,194,3,117,38,79,
58,213,211,239,134,195,80,34,161,252,235,4,75,13,94,218,219,235,148,240,73,32,34,34,111,3,36,129,147,17,90,111,130,38,133,220,16,116,79,76,109,76,172,64,123,50,252,247,222,79,166,144,7,162,219,167,1,16,
91,85,8,8,197,157,62,152,197,34,98,39,136,53,27,103,158,176,161,100,232,29,9,167,94,49,208,83,19,105,31,53,212,200,2,14,193,132,173,186,239,9,142,220,186,160,187,247,102,184,157,42,162,67,93,112,186,233,
5,160,240,51,109,98,99,163,34,18,128,67,6,204,20,13,144,155,42,79,172,184,40,64,52,208,159,105,142,8,46,16,214,175,158,184,102,192,20,2,8,183,120,16,160,168,14,141,52,117,223,3,82,1,45,191,105,139,64,
166,244,8,63,69,199,196,236,1,212,240,247,235,133,160,31,55,14,129,79,12,43,83,5,88,79,239,5,24,138,24,217,212,152,48,164,10,168,128,125,113,85,74,16,5,0,234,1,145,80,7,82,35,243,136,201,4,46,214,157,
253,240,81,19,73,179,231,29,162,78,132,3,165,15,83,128,70,227,178,84,11,213,245,198,72,172,210,104,190,100,194,139,17,26,168,69,217,241,197,85,48,1,218,139,235,133,110,0,62,68,214,167,182,69,50,21,8,219,
60,226,10,165,247,122,250,96,112,84,160,145,31,147,12,52,26,124,70,36,68,236,68,249,27,131,43,209,16,90,27,217,193,251,84,42,122,53,223,93,224,161,165,69,65,223,69,147,55,250,14,132,1,23,235,215,4,74,
26,224,52,150,87,8,73,16,2,34,43,227,59,155,192,119,166,226,130,232,73,97,61,255,0,249,136,192,248,32,15,77,177,124,30,48,168,42,17,220,211,58,241,112,5,204,101,70,168,34,135,188,25,96,36,171,177,101,
118,241,28,134,192,26,3,229,205,199,154,234,0,176,157,146,161,136,153,184,62,152,172,211,85,86,130,63,25,183,170,53,164,6,122,89,142,119,179,216,86,126,19,16,192,90,1,104,239,207,105,130,82,35,80,17,236,
235,254,225,12,79,188,223,175,151,163,238,97,37,163,32,85,91,231,42,197,40,166,188,158,176,167,176,42,200,105,193,80,136,130,35,17,27,131,58,162,70,15,167,209,113,17,71,177,143,159,227,43,238,72,88,87,
215,24,75,80,65,183,134,173,192,95,32,17,38,83,186,83,21,123,111,70,253,2,97,140,239,168,20,9,177,109,193,57,22,157,27,167,206,223,92,27,149,232,5,143,176,126,112,9,66,128,63,117,220,30,142,143,228,90,
93,149,54,250,96,117,170,0,102,202,12,235,41,106,7,171,184,187,150,204,77,66,196,53,24,26,147,167,179,241,145,106,34,252,143,72,248,77,57,65,54,199,118,23,169,231,10,90,8,37,65,221,212,13,250,247,235,
130,106,10,10,188,7,91,202,67,44,97,176,36,217,191,174,84,10,96,137,65,233,211,134,122,164,171,219,75,114,46,12,20,118,39,145,190,19,6,138,162,242,134,143,110,4,80,207,105,4,241,181,203,50,64,135,67,53,
90,191,57,163,18,0,13,59,187,67,174,25,134,45,48,18,148,179,241,142,241,54,135,69,35,240,224,54,193,39,184,1,241,137,128,192,180,236,215,94,136,250,228,201,157,17,171,235,214,13,89,219,0,236,235,190,178,
65,172,33,161,116,119,117,113,6,136,68,189,161,169,56,57,10,17,10,106,248,241,87,9,171,97,113,54,220,223,167,89,100,29,74,61,52,235,10,106,146,24,9,233,13,100,220,29,65,74,49,55,174,8,98,170,160,147,23,
229,213,240,229,203,73,1,107,173,29,117,194,59,33,181,109,79,70,16,5,239,65,15,109,58,205,219,5,208,244,117,185,192,160,54,85,66,93,42,27,206,180,233,59,48,239,49,64,238,142,190,248,248,42,13,163,123,
96,247,72,10,168,0,47,156,84,26,128,1,64,159,24,125,144,132,77,199,125,229,66,146,215,106,215,130,49,31,65,133,229,61,248,190,137,16,165,133,236,191,24,249,178,107,69,15,164,184,161,32,161,123,190,119,
194,72,80,2,129,237,59,122,192,40,131,10,16,70,154,248,225,74,234,209,20,2,77,78,178,41,24,37,66,181,228,196,101,2,30,110,187,251,231,88,205,212,108,20,7,179,223,131,198,195,178,108,15,159,91,138,158,
205,2,135,210,102,230,70,128,134,193,120,48,73,81,3,179,203,241,145,164,8,80,157,117,175,56,49,31,68,117,222,156,108,159,81,180,70,155,189,225,193,85,21,4,79,95,56,142,54,199,144,166,156,157,34,0,124,
139,50,252,225,145,86,68,243,238,240,71,17,67,93,101,87,217,15,166,51,116,238,186,23,108,242,46,68,178,7,6,124,14,210,99,240,101,90,2,251,240,219,132,91,99,176,74,111,210,239,4,50,66,157,72,229,80,132,
50,128,123,240,192,194,54,26,0,233,139,138,170,109,19,109,88,6,42,108,10,171,239,133,0,18,144,70,248,242,90,224,71,206,64,6,112,109,204,196,25,55,211,125,7,175,105,154,181,10,171,182,30,228,125,6,51,61,
165,124,140,205,17,232,58,170,96,112,45,42,8,151,229,194,141,19,160,54,46,166,110,144,2,187,214,103,180,31,174,31,41,99,104,7,146,60,92,114,25,16,53,181,219,234,156,120,170,185,0,58,155,238,24,87,28,124,
138,15,87,105,136,251,219,61,47,247,21,62,112,134,29,26,164,33,124,171,50,182,193,98,69,232,66,180,135,223,207,15,244,93,144,65,15,32,88,121,125,174,20,68,202,134,150,239,176,99,237,191,92,40,133,130,
167,129,181,196,128,148,18,132,29,168,220,92,145,182,131,193,142,215,179,199,102,22,164,165,233,40,222,87,143,251,136,60,225,83,194,39,72,229,23,8,96,16,1,59,17,60,62,201,194,80,2,13,162,43,89,183,0,20,
198,42,122,91,114,17,46,32,74,131,225,139,118,237,118,175,156,138,241,144,218,165,6,61,100,108,5,64,33,66,76,123,73,18,250,70,225,10,52,81,4,78,231,166,2,38,189,42,25,241,155,5,53,35,164,140,238,100,41,
80,104,208,88,75,122,115,102,16,36,106,61,73,230,112,31,18,181,41,165,129,227,21,8,199,74,42,164,125,28,66,104,86,199,67,3,243,48,143,32,32,8,210,67,89,12,5,35,216,59,59,152,70,216,117,238,67,19,72,64,
78,199,213,48,189,53,180,166,157,30,143,7,154,108,170,110,18,35,211,7,174,217,129,234,203,196,30,0,96,68,238,154,151,103,182,121,228,30,55,22,162,146,197,152,138,86,148,137,232,140,192,108,131,105,181,
168,194,161,131,21,26,62,184,176,27,60,168,143,90,230,152,29,2,129,187,227,33,33,10,34,85,55,187,237,147,197,137,75,106,211,135,155,73,0,168,116,235,219,30,216,210,247,235,247,197,161,20,9,41,239,144,
122,29,59,11,241,50,196,144,68,31,80,183,174,20,106,237,129,16,135,158,187,201,14,128,208,214,158,56,92,44,78,229,136,241,214,84,232,59,208,151,230,101,128,88,32,89,131,17,131,30,158,156,40,160,1,169,
62,167,142,40,187,53,41,189,188,95,140,108,163,53,96,160,185,87,36,160,37,190,119,233,193,17,168,46,34,179,183,171,148,68,81,168,98,52,215,199,15,133,218,41,68,151,79,120,66,129,6,52,9,247,199,113,189,
146,202,215,159,156,64,40,1,218,233,49,196,206,201,182,31,126,46,226,130,26,52,111,110,91,89,181,246,158,39,119,27,196,132,68,124,186,113,117,84,94,213,119,113,43,152,82,2,176,60,123,229,56,15,104,63,
192,24,199,49,54,217,172,87,5,139,71,104,79,33,138,165,85,69,87,106,173,199,139,220,232,109,2,111,174,178,140,154,133,6,222,139,38,91,168,122,208,31,169,226,121,155,23,8,95,247,130,33,5,64,136,151,219,
58,60,109,65,95,162,96,152,133,96,33,118,86,217,188,239,178,76,14,143,126,223,252,98,222,149,14,175,165,184,25,97,177,237,38,189,39,126,255,0,38,11,72,80,195,203,31,204,226,202,179,201,0,166,121,186,200,
98,0,148,209,66,216,58,247,153,83,37,71,218,77,158,148,116,227,172,160,181,20,215,235,130,21,85,24,147,169,160,177,56,152,78,109,117,2,159,156,75,106,34,116,6,18,252,184,202,165,208,93,196,223,5,190,204,
114,49,254,134,208,155,189,220,123,66,218,7,79,134,63,225,6,165,66,5,13,109,247,184,250,146,88,189,19,44,6,202,89,209,192,69,54,120,248,196,21,64,10,144,0,122,174,46,140,25,124,133,51,190,176,32,10,24,
90,222,197,95,159,191,121,176,6,214,216,81,90,32,209,244,199,23,12,181,23,191,80,52,225,242,0,133,103,70,150,50,123,111,206,116,1,99,9,1,232,247,226,73,201,108,29,13,143,185,131,210,214,81,47,211,18,88,
219,68,94,129,79,75,214,5,55,113,142,196,238,91,158,191,18,14,151,80,56,239,76,78,213,4,96,124,25,235,154,1,73,236,222,80,202,70,187,78,252,207,92,58,150,164,232,91,233,227,52,178,41,52,121,245,222,176,
136,168,193,123,67,16,237,234,71,164,88,159,108,79,139,88,80,10,209,231,119,133,160,74,109,2,14,137,188,122,227,29,11,247,20,92,12,130,20,43,210,213,62,56,32,234,82,142,224,34,157,121,206,214,15,170,45,
31,169,132,243,100,187,233,190,189,76,182,168,106,173,4,248,112,113,235,137,130,71,110,188,98,97,97,24,10,22,220,51,220,96,75,66,238,220,150,86,189,194,186,157,125,120,241,192,32,43,179,211,0,33,108,99,
18,159,92,12,183,162,77,93,31,153,112,168,226,221,134,159,166,25,238,106,16,167,142,245,190,36,16,52,40,33,27,111,42,62,11,17,218,157,112,76,144,82,189,55,210,107,18,0,83,122,4,31,156,20,197,4,22,109,
73,239,214,26,111,243,214,93,8,228,237,71,193,120,161,209,144,59,96,226,145,133,20,110,245,154,82,64,85,64,7,206,48,93,64,27,64,2,106,117,128,121,215,98,33,15,61,119,140,199,80,162,49,56,103,12,75,217,
65,232,36,203,144,52,81,2,95,156,168,5,130,150,87,231,188,24,140,25,225,216,228,202,0,118,198,163,124,85,5,128,15,40,224,19,64,13,108,154,61,49,56,80,168,123,51,206,45,65,245,87,15,169,82,130,2,63,38,
25,68,18,61,163,18,131,176,39,200,220,12,36,34,11,67,192,118,141,15,160,141,245,163,14,201,37,131,236,89,50,222,133,0,128,111,174,118,152,196,119,225,19,209,68,248,195,50,36,224,32,150,87,1,64,64,162,
34,43,227,30,146,136,124,13,192,16,19,166,81,155,123,140,235,172,239,190,47,201,45,59,212,195,177,191,128,102,106,201,2,31,163,199,190,0,72,28,26,208,183,217,143,174,121,90,92,43,69,151,85,96,44,3,60,
252,226,54,147,29,46,181,54,189,31,104,250,230,162,243,73,0,235,179,189,61,250,98,127,93,126,191,76,215,129,251,249,49,167,78,234,122,25,224,191,156,68,81,210,40,158,142,15,150,1,234,86,41,149,147,8,247,
165,245,31,68,192,80,10,172,0,170,231,160,54,133,73,178,252,226,58,46,43,162,237,240,142,7,73,84,33,164,33,241,194,4,181,84,85,23,208,196,138,61,140,236,122,248,199,52,216,160,166,195,175,194,199,184,
226,46,234,33,136,236,181,159,183,190,88,80,54,255,0,136,105,151,223,63,160,15,128,152,181,252,192,252,141,118,35,139,17,54,86,186,245,26,86,153,226,230,165,39,77,11,104,59,15,71,55,105,44,7,178,21,79,
79,135,126,180,242,43,21,104,136,117,147,80,139,91,216,243,173,235,216,251,96,245,106,27,178,101,65,69,218,164,86,0,235,142,249,137,54,173,205,7,182,88,122,73,130,4,252,152,1,65,65,80,104,123,229,241,
68,233,14,169,35,223,215,8,194,210,151,174,137,188,51,213,37,94,218,92,81,123,67,236,207,31,92,73,100,18,65,91,33,230,112,68,210,173,64,61,14,251,195,202,48,105,122,3,187,23,172,114,132,0,173,59,186,235,
174,52,35,90,187,69,41,211,138,100,151,208,41,31,140,221,19,109,233,43,198,42,36,1,98,131,93,7,145,245,194,132,206,129,123,59,235,29,52,19,15,78,223,61,97,99,133,96,81,15,35,188,77,9,97,98,246,67,64,112,
146,164,40,86,10,215,138,243,186,218,85,19,78,252,224,5,218,11,214,152,60,154,217,8,62,222,152,61,205,216,104,77,39,120,246,248,223,94,153,35,238,128,74,73,124,250,98,55,190,128,65,158,15,142,59,49,21,
167,186,212,112,152,14,224,194,95,23,7,169,78,133,208,79,60,31,0,107,189,109,69,235,121,214,157,39,102,56,180,148,59,87,20,15,108,17,237,232,73,132,149,2,36,0,23,206,47,46,128,108,232,61,48,251,34,17,
55,189,246,97,134,145,107,181,107,132,29,30,64,209,229,56,4,194,161,75,54,164,223,125,103,91,255,0,239,243,130,15,52,135,159,7,20,121,22,3,204,28,2,56,81,8,239,94,153,169,4,42,160,135,206,46,21,40,67,
125,6,181,233,136,164,130,20,108,177,236,112,167,74,61,222,255,0,126,21,177,13,65,65,47,127,60,108,195,21,173,14,206,250,183,23,70,248,173,161,127,51,9,107,26,66,5,7,191,0,32,42,40,35,94,191,24,12,64,
5,9,236,222,73,138,7,192,139,244,113,212,29,70,198,52,109,236,248,197,254,137,232,42,63,69,169,236,230,205,182,158,212,211,136,36,32,3,229,49,199,243,137,29,164,79,59,243,149,61,38,250,5,252,227,66,5,
163,88,183,125,87,172,221,84,216,237,123,100,239,19,24,64,33,31,46,159,140,186,162,198,216,203,188,108,65,67,205,79,130,130,62,184,116,18,20,240,23,27,21,14,129,184,219,216,164,79,38,34,235,0,98,145,11,
186,237,121,61,238,45,43,96,64,32,147,179,194,121,48,84,67,120,2,235,200,71,89,228,73,123,40,47,137,222,30,193,42,136,18,67,243,150,57,36,61,191,216,217,239,50,192,232,85,19,103,123,233,205,208,81,40,
32,121,19,195,154,109,233,3,42,175,179,120,64,10,170,0,82,38,215,78,6,162,252,181,139,160,221,249,206,251,255,0,102,178,55,52,150,142,199,143,108,222,104,64,134,246,120,73,234,73,225,192,76,192,0,4,0,
52,6,104,13,12,198,36,67,77,214,55,184,223,178,31,228,97,239,134,205,154,245,82,168,16,38,195,199,195,150,170,79,59,164,53,232,79,163,31,19,185,206,234,32,116,240,246,56,83,112,136,26,221,3,240,249,194,
74,52,198,222,68,14,199,234,252,12,34,207,80,73,211,222,44,105,199,238,129,254,68,87,180,113,112,16,133,4,62,231,215,13,147,82,163,37,121,34,117,130,217,65,149,218,183,5,64,98,34,39,132,222,105,73,144,
232,62,155,196,130,68,13,64,61,235,188,50,33,33,124,2,219,144,60,128,8,144,30,58,14,23,24,33,90,211,90,238,38,56,36,90,36,53,4,248,147,13,34,49,19,126,159,108,29,89,216,4,85,25,63,188,48,69,88,33,174,
187,52,101,206,64,89,167,212,157,204,176,83,68,142,195,53,111,88,5,108,108,81,51,192,6,231,3,79,186,33,77,46,50,42,237,196,69,84,126,185,113,96,170,142,134,15,198,8,130,43,17,221,214,181,128,96,41,237,
67,199,115,14,68,27,111,88,214,118,3,61,100,2,29,136,166,91,154,149,14,190,30,156,28,50,210,163,223,128,48,74,5,96,194,246,203,142,140,25,0,216,6,234,124,240,234,134,139,53,84,177,214,39,96,72,252,142,
5,244,217,59,118,48,195,116,222,197,30,196,152,128,16,119,66,71,173,235,22,17,120,23,70,238,90,84,21,5,161,124,143,140,64,24,150,221,168,119,194,152,96,6,130,118,250,99,219,27,239,235,247,197,165,20,18,
126,75,147,105,14,168,82,252,97,226,66,40,47,71,0,68,218,180,130,141,239,5,46,240,187,10,223,161,214,16,85,129,4,32,95,174,48,85,96,54,232,53,172,86,139,33,65,99,187,71,4,89,31,117,106,240,162,228,40,
22,158,94,252,58,181,44,83,116,248,190,179,18,32,15,110,208,126,112,95,137,33,3,79,151,130,65,1,22,128,17,158,125,113,160,197,90,122,67,79,199,2,178,179,96,172,249,189,225,138,244,98,44,76,221,23,74,248,
168,112,224,145,168,160,137,249,203,116,53,157,149,123,220,59,200,147,2,245,127,190,53,246,48,236,22,160,179,171,85,115,163,125,180,52,30,58,239,21,146,81,177,42,190,142,17,233,56,173,87,214,124,230,239,
10,36,16,53,226,254,113,133,0,140,189,2,253,70,22,202,70,190,155,196,200,80,74,164,215,240,228,150,212,48,242,255,0,207,136,11,124,73,112,38,250,147,52,238,245,46,212,104,152,5,162,75,32,20,251,229,35,
130,201,77,158,195,177,241,241,113,107,93,0,72,9,121,169,137,226,98,160,137,100,15,133,183,241,63,81,134,120,232,32,217,190,163,234,118,100,131,54,144,111,229,129,35,223,58,241,214,95,125,158,106,143,
228,7,189,245,48,146,110,67,225,148,73,239,142,166,140,60,4,190,189,113,47,150,166,1,25,99,252,97,8,102,192,36,159,225,235,154,48,134,211,196,251,151,43,178,233,106,120,94,240,169,176,12,128,39,128,179,
213,134,132,23,97,3,25,238,60,30,95,172,72,56,38,169,224,3,193,224,50,135,132,168,236,111,224,136,252,230,144,0,146,246,183,178,176,47,33,26,87,107,238,131,133,68,6,166,227,181,164,246,124,99,84,13,0,
14,129,29,63,253,116,228,72,94,161,165,219,78,182,63,81,233,132,130,34,128,14,161,244,23,209,115,173,127,247,248,192,48,134,228,80,221,119,214,54,79,161,70,205,220,186,49,47,47,53,90,107,233,196,251,116,
13,145,23,242,100,164,4,8,1,216,19,211,136,180,132,130,136,208,141,217,132,81,108,164,15,188,235,11,49,109,131,223,64,207,103,17,217,23,96,236,93,203,231,5,3,106,162,17,178,3,141,65,165,33,85,8,192,250,
99,190,177,64,69,4,112,108,104,105,124,27,135,223,54,109,208,152,79,199,88,74,43,216,175,168,155,243,129,97,36,187,80,59,250,227,247,3,222,162,196,250,152,166,53,157,25,81,243,190,184,119,65,88,44,32,
208,124,102,238,169,20,11,221,28,31,114,192,83,169,123,224,42,42,168,110,3,253,226,41,164,254,107,130,251,0,89,233,155,178,43,65,246,217,145,105,34,66,67,238,235,24,90,163,1,237,113,170,141,64,130,51,
93,220,149,88,161,54,172,39,247,195,56,93,0,87,8,81,105,174,181,245,198,193,29,24,213,145,239,190,240,136,226,221,238,63,214,9,178,144,16,232,234,222,53,12,236,29,17,110,241,57,240,80,10,110,157,112,78,
152,45,159,193,53,137,0,83,125,8,63,56,138,13,128,116,12,79,199,8,98,58,81,130,79,51,198,39,115,101,131,37,199,37,72,36,240,189,151,39,68,26,93,165,244,195,197,85,27,29,23,111,17,40,46,180,1,70,247,243,
133,156,216,14,196,111,247,195,162,26,192,176,82,252,231,159,81,69,136,56,160,218,194,206,171,131,17,131,27,18,143,223,28,140,4,54,234,120,54,195,0,6,170,55,111,140,136,44,4,66,41,215,131,26,169,61,1,
93,4,125,112,169,9,181,90,225,9,232,52,33,11,239,183,6,52,26,14,164,96,162,39,98,39,200,225,234,154,65,216,174,52,203,184,122,208,252,96,247,173,104,158,52,55,215,120,166,173,217,93,19,103,120,55,119,
128,132,3,247,224,48,217,5,6,197,252,179,114,214,18,155,255,0,7,12,27,74,211,84,22,56,178,232,6,145,189,222,240,194,89,138,173,39,182,39,27,67,108,58,62,1,217,228,215,162,59,200,16,216,33,61,17,206,191,
204,64,12,236,53,211,217,117,228,85,168,65,126,71,164,124,38,156,51,181,142,224,31,163,130,192,86,246,104,35,182,158,177,164,164,238,58,0,241,248,28,82,170,175,101,86,252,227,250,154,136,55,61,139,62,
184,16,16,40,157,68,102,19,160,33,189,82,184,43,162,77,160,244,159,9,231,1,2,140,1,85,250,98,19,86,70,170,203,236,98,138,168,199,214,144,122,13,237,202,136,16,214,123,158,46,123,151,30,110,53,162,127,
38,29,77,251,33,151,54,212,143,190,65,68,107,176,247,169,234,33,241,139,25,90,11,213,115,114,156,41,21,189,11,60,167,219,206,119,43,198,95,175,233,24,151,42,17,168,80,251,76,145,61,50,132,56,161,225,228,
241,14,11,136,81,0,64,166,190,120,141,241,65,191,186,105,251,229,52,149,184,169,122,179,21,178,74,14,233,233,159,29,96,196,165,4,82,160,253,176,3,70,221,136,157,7,142,44,46,18,109,90,122,12,108,232,36,
8,129,248,67,0,32,80,84,26,22,111,47,10,17,164,13,82,79,63,92,35,23,101,58,186,38,204,171,210,117,106,211,95,91,142,84,64,124,152,107,2,8,26,172,249,224,224,20,222,144,7,193,229,184,113,208,235,104,232,
189,252,99,18,32,33,74,189,223,28,50,136,161,58,75,187,233,138,100,250,9,88,159,124,37,180,4,125,132,197,86,11,123,2,123,76,52,72,232,159,219,172,216,78,168,7,163,87,241,133,90,130,134,37,209,221,198,
162,182,81,94,211,129,98,82,65,94,143,211,121,178,117,43,68,65,223,227,26,137,173,11,214,151,10,71,14,227,37,63,140,177,53,209,1,52,149,113,210,157,69,254,113,189,29,3,210,76,1,184,208,39,76,255,0,156,
26,163,106,138,170,190,142,240,26,123,108,66,95,23,211,34,208,130,161,208,15,7,194,23,179,106,47,91,196,69,18,35,19,209,48,246,72,4,59,87,1,47,25,118,21,244,48,237,194,27,20,58,90,249,227,190,65,80,176,
0,190,114,3,193,64,236,221,56,3,161,6,43,13,137,38,233,77,95,23,17,144,208,157,21,73,248,225,66,162,8,7,66,125,120,39,107,184,30,84,56,64,107,87,96,93,120,38,106,70,130,116,208,92,80,41,82,5,122,12,214,
128,66,50,150,55,9,237,17,239,247,239,134,40,24,47,169,31,83,198,119,146,249,220,44,47,106,232,247,196,112,135,172,82,2,244,3,175,108,85,24,233,90,43,223,185,150,21,154,72,2,15,87,135,96,40,128,3,90,250,
248,230,147,88,40,99,34,63,92,239,109,142,119,48,36,160,234,145,83,235,234,101,195,54,53,68,125,245,133,163,217,188,111,191,156,66,130,72,40,166,61,251,100,235,137,4,217,252,47,0,74,160,22,1,38,53,78,
45,139,91,219,58,200,69,151,234,8,189,36,217,231,0,205,78,131,254,183,130,212,120,244,4,83,74,221,215,196,205,79,91,59,1,84,62,221,153,186,32,26,250,86,255,0,24,203,232,5,52,11,230,63,26,119,138,128,93,
74,62,200,177,63,217,132,114,80,58,83,186,153,21,136,212,170,46,202,119,235,138,131,8,196,0,166,183,252,240,196,61,42,4,53,239,163,55,103,33,214,141,147,181,184,122,229,124,3,170,162,58,108,187,132,61,
12,12,6,197,72,53,217,223,78,14,64,244,149,80,93,19,191,158,28,152,241,65,65,232,246,86,97,52,65,24,16,42,248,245,226,188,23,111,155,228,106,245,255,0,88,209,16,146,162,171,62,95,11,138,89,224,29,52,141,
117,114,95,181,179,195,49,136,78,105,87,224,242,60,105,216,207,109,98,104,243,131,169,4,144,177,162,83,235,155,112,195,3,64,86,250,99,0,33,117,65,225,231,235,134,207,80,163,37,106,145,58,203,137,65,171,
180,150,224,168,72,161,19,194,55,16,116,174,136,144,250,89,231,139,66,68,13,64,47,130,92,180,54,64,66,93,94,250,196,48,26,145,74,31,71,124,16,158,144,22,86,159,94,178,182,105,73,210,6,147,209,38,31,111,
127,76,31,47,19,144,141,24,31,222,7,178,165,20,191,214,4,112,136,147,182,205,206,229,203,136,86,32,196,22,83,227,15,212,171,86,35,232,175,1,166,189,193,122,31,140,85,74,48,145,46,222,179,64,26,220,78,
141,204,184,58,118,211,202,245,134,122,138,157,129,61,238,0,93,9,240,51,26,63,44,60,34,193,161,181,33,58,147,136,68,26,84,87,122,147,16,132,59,27,5,237,245,196,198,85,1,88,7,158,30,134,105,161,216,203,
243,136,193,20,137,238,96,57,102,192,237,168,152,35,176,152,237,71,199,70,70,136,18,214,163,187,113,64,21,65,3,192,103,143,195,67,26,47,159,108,132,146,41,237,81,245,120,140,162,170,149,85,121,98,49,50,
195,65,245,157,227,205,8,43,58,38,188,241,211,75,192,77,168,244,196,69,29,34,137,232,154,193,166,176,33,229,114,132,154,10,85,31,90,97,185,88,18,73,160,95,24,193,85,128,30,128,107,16,238,74,41,215,125,
224,188,151,189,161,94,252,241,184,80,84,13,49,229,49,62,165,151,195,137,169,101,212,221,123,190,50,28,65,242,212,30,229,198,202,26,4,54,91,219,199,80,136,58,117,23,194,179,216,198,242,2,89,225,30,174,
10,100,61,130,210,77,190,184,26,189,192,138,137,126,152,146,138,12,245,80,126,113,96,0,34,133,7,166,6,194,128,34,15,240,46,10,129,90,22,26,183,249,198,114,154,59,14,189,119,212,196,175,76,116,84,248,51,
96,154,54,213,223,253,110,58,77,32,200,3,188,209,16,52,61,35,95,140,91,41,26,244,17,197,45,65,216,19,95,63,140,35,38,59,80,245,187,68,125,31,62,18,228,20,93,64,94,69,29,96,82,36,245,41,4,68,240,163,113,
226,198,233,52,59,40,246,125,67,131,93,129,149,8,65,247,62,166,189,34,142,158,83,73,63,108,82,244,12,232,189,152,196,180,4,66,143,77,225,44,122,133,35,29,78,204,17,21,68,133,244,28,84,216,170,128,38,155,
211,121,47,169,118,196,143,87,214,2,234,41,176,147,232,240,91,205,222,3,115,121,223,166,45,76,27,64,118,233,7,146,24,0,170,53,132,5,235,171,114,254,123,193,106,80,131,64,107,249,192,72,140,5,16,162,78,
145,195,232,130,72,142,241,217,170,127,243,6,18,164,116,99,69,222,159,89,28,94,133,42,129,208,119,125,3,53,55,64,110,167,172,239,1,21,20,186,182,223,146,99,148,134,143,212,29,29,78,24,201,118,183,163,
89,213,239,18,41,233,173,34,126,48,198,34,118,138,27,174,250,198,200,142,129,54,124,203,163,4,102,53,47,209,215,142,39,143,12,155,55,19,54,192,26,168,4,81,175,78,18,92,148,230,131,176,143,78,240,88,27,
20,88,226,104,82,48,126,1,157,233,196,16,32,212,50,158,103,190,52,136,49,40,149,158,154,226,137,69,96,85,181,153,168,177,20,34,4,122,186,213,200,101,46,84,59,93,25,184,24,198,157,8,107,59,17,161,3,239,
166,224,31,98,5,238,24,130,118,125,165,152,245,17,65,55,5,127,60,63,50,209,71,80,58,207,250,108,49,245,219,135,92,172,5,117,23,124,93,138,168,58,1,31,206,32,158,237,242,45,31,174,19,106,0,166,216,55,243,
155,17,13,216,125,58,158,114,77,83,167,161,243,214,44,9,165,1,227,188,165,83,65,24,136,83,52,200,41,77,171,169,120,95,116,16,168,84,238,24,14,195,90,82,49,245,198,160,83,12,123,69,47,206,11,12,182,42,
15,215,172,63,100,67,83,79,22,250,227,49,218,79,156,39,172,167,93,187,19,235,145,3,69,81,93,246,117,146,82,81,105,52,250,98,172,170,194,30,198,9,5,134,133,17,11,227,219,36,229,27,109,90,242,188,85,210,
224,24,52,242,158,49,54,198,131,220,152,128,69,32,147,115,212,185,12,52,105,75,62,47,88,94,81,245,33,177,118,241,183,32,219,76,10,211,132,87,160,46,145,190,125,111,17,32,22,83,64,77,223,92,92,50,236,137,
52,253,28,122,218,194,167,85,193,136,235,77,217,77,124,226,32,224,0,11,212,112,85,82,0,22,20,114,75,86,144,232,59,2,107,41,244,98,186,213,64,7,125,184,44,136,138,236,163,137,96,210,58,129,63,230,8,132,
8,29,72,254,241,81,98,69,179,115,63,57,91,180,19,80,215,203,103,142,178,12,85,145,239,255,0,30,17,42,169,225,210,159,29,224,187,90,87,99,239,220,199,118,144,178,1,246,223,17,103,177,62,165,76,11,123,4,
86,232,60,39,135,179,27,75,13,136,141,31,83,201,245,195,79,198,29,135,72,247,113,2,170,3,235,228,2,189,209,31,92,94,119,209,23,98,22,189,1,132,68,89,59,41,190,155,183,209,223,174,10,32,193,29,11,174,7,
106,189,138,0,123,250,96,82,149,178,104,187,103,87,43,106,31,28,60,211,243,134,166,212,109,59,147,207,220,215,182,22,134,85,215,194,236,72,155,142,4,81,236,81,249,28,244,20,69,128,73,175,81,133,104,138,
0,8,167,74,233,31,124,168,15,162,111,3,181,72,39,179,123,55,128,205,161,35,100,219,233,134,178,236,16,15,17,226,41,240,184,11,131,208,118,143,136,211,228,49,123,19,214,197,67,15,108,72,165,24,202,52,115,
96,137,67,200,79,172,184,86,213,42,0,131,227,94,49,42,81,5,128,116,80,239,132,9,20,130,250,15,166,3,136,66,64,10,83,95,60,108,213,21,185,45,52,249,243,148,210,70,49,103,204,197,84,75,73,221,58,25,131,
18,148,17,74,131,246,193,0,7,122,32,80,53,103,13,64,112,27,3,168,124,92,211,60,130,4,15,66,248,193,144,66,195,67,231,59,211,141,167,74,72,105,215,174,3,189,37,237,47,35,76,179,208,151,179,74,191,124,70,
81,0,250,35,114,87,245,47,202,177,122,28,136,53,47,213,105,245,12,44,65,82,139,0,212,249,184,129,66,90,33,122,44,199,151,32,20,247,235,120,185,80,68,58,75,188,97,62,80,247,208,199,89,128,139,220,141,197,
118,10,61,129,61,167,247,130,137,15,73,63,46,178,149,116,4,29,70,159,227,5,22,130,140,75,163,243,140,73,214,155,100,127,28,76,181,117,10,232,62,117,222,81,173,74,148,136,47,156,184,73,24,134,150,123,247,
48,116,49,108,90,95,143,25,108,43,189,72,140,75,127,172,116,167,91,235,211,29,246,13,60,13,46,14,216,81,15,79,229,215,19,196,42,169,85,91,231,3,165,78,138,34,245,214,105,224,130,218,170,107,111,215,141,
229,141,1,130,251,226,11,21,90,166,193,234,204,160,5,176,211,125,69,47,206,104,76,182,34,95,174,19,72,164,144,211,82,252,241,62,176,4,176,3,103,227,28,116,8,31,52,249,226,30,130,108,173,175,159,24,72,
202,116,84,213,241,223,88,237,3,66,116,110,77,252,113,48,108,160,232,25,214,157,39,102,19,163,180,3,42,163,150,2,6,221,18,235,188,133,0,37,77,207,140,85,85,87,223,219,22,50,161,8,141,88,224,120,67,61,
191,253,202,217,62,9,143,236,199,50,64,68,2,249,11,6,57,34,46,3,184,31,129,132,101,65,62,35,191,147,45,192,26,171,64,252,229,157,103,74,27,59,175,110,36,34,57,89,179,254,1,136,141,11,175,12,143,121,253,
119,132,160,61,37,252,247,114,25,65,141,90,61,250,102,254,90,107,170,201,140,74,2,33,40,139,28,85,52,35,64,106,195,231,6,39,87,244,8,124,233,236,101,175,33,101,234,163,67,125,178,152,69,86,132,67,115,
78,253,49,107,16,161,73,66,237,227,216,14,52,130,143,160,244,123,26,215,198,111,157,192,40,3,253,230,172,208,128,64,58,125,38,94,96,190,137,217,248,194,93,228,35,84,78,239,227,4,8,18,1,86,251,24,40,165,
46,141,85,118,83,191,179,206,14,165,9,116,192,134,213,194,237,181,228,80,12,186,26,239,186,249,205,69,140,186,102,143,120,3,230,224,201,168,21,218,24,125,176,80,164,58,77,137,142,97,118,131,213,73,131,
150,109,64,138,246,76,151,6,242,90,29,48,138,143,0,138,2,3,54,37,248,202,0,13,98,22,166,142,174,248,13,227,7,1,170,194,123,57,96,35,112,138,39,93,203,144,86,205,14,247,155,158,185,126,214,207,12,193,147,
10,246,11,212,59,56,141,6,233,218,194,73,231,7,18,233,1,99,164,139,235,149,212,64,160,104,5,222,44,3,144,64,30,142,254,184,141,176,70,164,103,169,35,134,42,130,94,201,187,193,68,70,34,34,118,38,241,11,
85,181,146,67,58,223,21,165,0,33,128,46,253,241,185,157,52,196,190,125,6,66,20,209,82,15,32,134,240,30,99,99,229,145,250,176,192,106,136,32,88,252,229,151,113,67,174,167,227,15,183,190,14,224,201,81,70,
198,77,97,85,139,40,154,112,178,164,104,58,179,243,50,133,106,65,140,65,103,227,24,130,187,5,78,159,77,240,70,223,48,43,138,61,77,18,34,247,215,190,8,3,80,47,80,217,248,202,178,59,39,229,215,88,62,196,
116,20,77,233,191,214,64,136,8,61,134,99,56,242,87,201,28,241,116,33,236,117,167,167,130,2,66,169,43,95,158,177,8,54,246,160,189,189,92,69,5,82,84,0,247,249,224,161,34,166,163,70,95,156,70,59,73,246,193,
5,16,82,107,75,231,185,149,0,158,197,39,217,214,41,37,208,5,167,190,8,18,68,79,77,229,189,131,74,209,166,22,197,40,144,83,228,71,172,239,26,144,85,96,170,215,156,64,11,44,52,31,44,131,132,144,118,182,
128,79,94,58,137,32,13,22,190,184,138,68,136,196,244,76,16,66,128,33,229,73,157,129,85,17,186,112,66,178,10,73,32,183,93,226,172,170,194,23,192,99,34,90,148,40,211,13,188,79,220,43,223,211,135,113,75,
64,99,167,151,105,145,122,20,178,131,130,217,66,220,148,127,22,99,16,208,86,186,206,222,76,56,244,188,6,203,117,124,103,229,80,96,255,0,140,93,60,220,59,127,201,185,38,0,46,145,52,121,246,200,189,124,
253,49,196,68,58,120,11,190,238,10,182,0,18,37,233,208,235,36,221,38,16,85,255,0,203,21,12,24,216,148,114,102,48,0,16,143,14,59,65,56,44,9,127,238,38,147,29,29,63,86,40,65,68,169,86,251,98,170,170,171,
218,237,113,10,204,78,192,142,204,182,26,166,153,53,116,154,242,71,223,5,144,238,170,157,161,247,8,122,231,96,164,125,243,90,87,81,194,40,247,168,155,246,192,240,70,151,160,4,95,68,203,165,17,109,197,
209,111,127,124,34,176,20,64,83,213,120,130,33,67,85,135,66,186,92,220,19,128,187,21,243,231,27,206,183,192,76,38,143,158,230,143,57,53,119,68,150,118,123,58,95,46,187,221,82,148,169,78,237,54,220,123,
79,69,63,57,74,129,16,15,138,119,130,148,40,0,77,124,31,28,48,119,125,0,10,128,60,19,247,192,100,242,8,81,125,229,12,217,208,16,29,34,61,117,111,27,254,52,40,5,232,251,250,226,34,137,19,72,233,19,32,137,
30,202,142,134,189,230,64,150,212,1,119,225,118,56,49,12,130,164,72,27,109,235,53,55,72,140,61,103,120,193,208,158,161,119,228,152,226,33,41,121,76,254,184,22,194,26,215,201,103,91,206,181,255,0,223,227,
2,18,166,168,16,223,126,177,17,209,160,66,39,240,50,182,116,90,180,215,97,174,0,18,88,202,66,239,195,112,195,9,90,34,104,215,167,12,247,161,148,36,80,6,111,33,70,14,138,116,143,178,137,133,148,138,32,
58,234,152,65,20,165,41,213,62,152,153,54,5,85,40,95,141,112,51,108,117,27,87,121,174,166,200,34,33,30,174,16,148,161,89,174,242,205,3,70,186,62,221,98,42,37,54,61,244,220,19,196,16,46,216,99,119,64,79,
125,255,0,120,148,161,129,123,154,79,79,60,53,16,104,82,194,120,202,26,135,10,208,196,241,229,193,70,176,21,2,47,158,0,109,186,211,64,159,206,32,223,82,122,34,209,195,78,192,89,218,25,178,8,165,178,120,
244,203,138,244,81,166,39,201,68,135,167,120,29,93,26,81,25,172,52,38,232,88,146,59,235,133,177,84,137,106,7,158,186,193,10,249,54,139,232,245,199,104,33,59,64,30,252,56,64,181,17,140,239,25,142,210,95,
14,3,130,237,163,182,163,39,4,36,168,169,114,74,66,221,166,158,186,197,88,42,154,7,160,183,4,130,129,136,162,33,112,157,109,15,106,233,221,227,109,168,0,104,87,215,219,19,110,200,58,103,140,76,17,97,18,
110,116,165,205,25,214,196,119,245,196,33,68,160,121,55,59,143,1,40,182,150,20,73,252,224,149,232,34,34,55,204,183,21,20,172,33,98,79,227,134,155,238,32,1,15,121,37,240,92,20,7,32,244,43,147,110,161,94,
138,250,96,196,78,198,159,76,97,32,128,10,166,156,2,4,83,0,48,91,106,251,100,40,59,26,48,206,250,214,177,144,210,171,55,89,169,138,165,74,189,175,121,10,204,17,17,71,227,4,227,192,29,72,193,68,77,35,71,
220,194,125,217,8,104,111,150,204,18,68,222,160,183,19,26,99,190,181,103,70,50,93,128,163,178,157,122,35,38,3,54,38,125,23,249,51,86,112,12,189,128,6,7,9,246,238,173,32,27,196,202,184,18,157,232,142,200,
229,253,10,36,89,0,160,234,157,228,85,214,136,143,85,168,251,96,248,210,35,95,4,252,227,193,7,107,105,62,236,236,132,20,57,102,213,126,49,10,27,91,160,77,201,62,129,197,82,138,170,170,213,93,214,230,159,
184,85,128,57,59,5,49,77,121,101,152,112,150,147,111,3,125,117,194,66,194,129,86,135,211,16,199,123,78,177,128,239,0,62,239,166,70,41,49,0,236,116,190,152,25,19,160,89,177,83,131,6,246,121,102,242,5,59,
144,85,190,167,156,24,36,247,210,79,7,92,119,140,174,160,40,97,237,137,20,163,25,70,142,69,197,236,27,51,211,211,59,180,166,32,16,124,107,198,26,128,42,212,72,74,29,240,28,17,16,72,247,246,193,58,144,
116,160,102,186,239,136,107,164,118,59,164,31,190,86,185,91,137,75,235,143,214,24,31,10,233,159,24,105,20,165,235,123,251,97,148,59,217,67,160,122,206,25,109,48,205,218,3,229,126,172,44,97,65,32,170,104,
147,5,20,80,84,144,49,77,134,160,10,3,174,140,220,28,20,131,71,10,234,16,189,180,55,239,136,3,74,19,228,222,75,134,169,94,118,151,174,3,36,182,162,192,30,143,123,128,168,75,68,47,69,152,178,160,128,83,
219,239,56,21,186,9,66,109,231,211,37,230,16,39,73,182,63,100,79,179,112,211,85,10,232,76,32,110,186,162,101,165,80,72,93,26,92,12,74,213,180,75,171,172,108,129,53,85,104,206,248,220,26,64,84,131,215,
223,37,69,82,129,54,11,237,130,10,135,67,90,120,189,206,45,186,40,33,146,246,252,225,240,145,2,108,82,152,13,216,164,237,6,227,88,0,106,22,30,176,4,30,13,15,251,149,229,68,135,223,58,42,30,209,31,29,103,
153,192,109,84,18,175,195,193,197,86,132,128,251,177,216,10,161,42,30,242,224,106,22,195,72,245,20,191,56,220,84,219,71,127,92,165,81,21,215,179,82,158,252,71,168,33,110,136,127,97,146,229,80,68,99,191,
61,231,122,54,189,24,190,128,157,10,155,130,64,157,40,37,241,7,172,164,180,209,232,218,33,246,225,165,162,211,67,30,50,73,167,73,164,124,100,214,176,102,104,247,237,75,244,196,96,14,194,198,188,223,76,
133,32,37,70,194,234,98,171,86,191,233,140,138,20,4,129,227,58,137,96,179,180,123,243,120,85,180,210,0,33,30,238,227,148,244,41,208,131,28,43,10,136,190,1,223,211,39,159,102,158,95,80,77,96,134,9,12,0,
170,249,252,153,208,252,223,193,204,251,86,151,186,93,227,179,17,100,32,237,145,32,39,219,3,217,67,108,240,89,128,176,130,58,129,223,110,245,243,138,28,148,83,122,34,190,41,245,152,4,88,77,28,236,10,223,
117,95,124,123,162,112,85,144,58,127,178,245,24,96,73,112,11,3,93,31,56,81,140,65,33,59,60,31,203,2,28,160,203,66,34,59,183,19,80,60,103,76,120,190,184,84,122,141,141,182,223,68,156,30,181,8,216,155,194,
129,34,127,54,90,24,5,95,79,47,198,65,5,42,4,78,159,55,7,2,23,160,29,220,158,24,74,41,107,202,119,132,66,4,138,214,27,238,255,0,76,180,132,19,70,130,16,226,61,161,6,224,131,84,204,188,232,130,175,145,
254,24,80,139,32,161,35,184,249,245,195,77,243,11,217,236,31,119,2,214,160,80,120,94,199,138,129,36,128,192,66,95,140,219,179,186,35,177,174,151,134,16,176,78,154,152,7,128,214,2,86,120,84,175,133,201,
38,243,67,189,250,103,172,225,194,17,154,11,234,249,189,112,183,11,136,109,81,33,235,133,65,11,3,74,162,83,189,230,145,36,68,64,21,183,20,4,136,32,8,192,201,112,198,153,60,18,8,124,251,48,69,164,181,237,
85,223,16,216,168,109,140,109,225,190,45,134,144,41,160,190,152,240,20,214,131,87,207,179,19,92,16,53,176,242,15,94,3,26,232,5,6,250,252,100,24,144,72,234,17,227,227,129,246,132,177,166,199,88,117,113,
101,29,31,122,235,16,47,73,3,173,63,172,234,182,136,179,79,198,111,97,176,170,237,239,239,192,235,90,16,87,173,247,169,128,68,61,134,197,219,213,194,42,64,218,118,182,111,188,167,73,216,85,125,58,203,
41,70,0,239,190,253,242,4,64,65,236,51,17,99,53,63,36,127,24,108,101,83,123,29,105,235,1,42,76,176,9,242,225,88,109,143,50,52,255,0,25,65,48,17,83,182,120,244,195,204,73,170,172,137,231,223,137,97,12,
30,16,122,251,228,177,2,160,149,7,227,13,181,180,66,110,120,190,153,67,109,216,164,126,248,188,141,77,61,158,230,8,18,69,39,164,114,190,195,98,116,105,134,109,170,72,41,238,79,19,1,88,109,116,7,107,136,
72,42,176,74,183,213,142,1,180,45,19,219,229,243,140,96,217,78,146,122,252,241,85,24,74,40,249,123,226,41,93,138,63,76,58,5,128,6,170,147,26,194,170,34,244,248,110,108,181,37,26,174,174,182,171,227,60,
162,250,25,221,125,105,205,173,73,4,10,235,111,55,37,193,64,111,125,183,229,226,196,43,151,33,44,121,243,133,16,7,177,63,198,121,255,0,177,104,62,219,50,28,113,160,140,189,205,165,194,65,86,205,166,47,
163,211,227,32,42,122,14,107,230,254,113,250,25,132,76,26,3,71,211,198,4,177,5,25,164,221,154,247,192,240,29,30,14,131,227,1,117,58,192,49,54,187,191,24,33,117,105,180,91,189,117,167,6,254,106,216,74,
129,62,112,50,242,204,62,214,241,249,194,137,212,242,190,9,21,90,75,105,51,211,160,135,154,106,101,54,53,172,208,40,192,176,54,255,0,184,160,130,33,6,0,79,56,180,101,1,177,85,125,179,215,234,32,120,71,
183,208,189,121,215,90,132,77,196,162,80,125,156,129,29,13,157,34,144,52,121,63,24,144,76,239,66,218,31,195,179,211,8,154,81,129,35,231,198,15,35,94,162,111,219,35,21,41,10,58,78,207,73,158,112,135,148,
46,142,240,152,160,138,232,8,189,28,107,188,16,106,164,58,27,237,192,54,202,40,26,213,233,221,196,189,48,27,230,159,131,103,173,196,206,40,34,163,209,55,249,194,123,224,74,70,36,146,143,130,251,204,93,
25,2,187,157,53,247,14,50,32,76,0,27,243,239,157,31,18,64,77,60,31,28,45,185,26,41,29,181,51,94,118,238,154,242,161,158,55,61,176,167,168,28,208,6,25,13,155,143,182,8,4,16,17,17,17,248,192,241,164,104,
141,180,89,239,136,165,17,20,71,194,107,28,88,77,69,81,112,251,204,82,212,169,132,223,133,217,137,165,0,174,192,14,214,245,154,209,144,72,147,242,114,105,154,80,19,109,250,122,229,89,70,157,136,135,175,
66,113,180,0,180,131,17,97,249,198,28,67,64,10,171,232,24,32,33,70,51,92,207,85,87,221,246,196,168,41,99,2,15,198,88,26,78,239,74,118,28,65,232,138,138,16,243,243,128,148,72,5,8,58,77,113,229,40,181,132,
132,184,85,113,99,19,78,38,17,216,142,172,143,153,113,2,34,151,101,148,250,103,77,34,170,174,133,159,78,15,109,142,163,106,151,29,151,69,65,68,38,165,194,109,180,85,53,182,98,170,155,68,169,15,177,172,
124,216,164,6,221,233,195,174,4,5,219,37,196,237,128,79,190,8,17,128,109,20,215,125,116,241,2,210,164,84,215,163,132,32,38,81,7,194,251,176,17,149,49,80,34,249,227,103,149,15,99,173,247,133,231,6,138,
223,61,96,81,48,8,136,121,121,202,148,222,234,68,203,120,176,9,243,249,201,1,1,7,160,70,34,70,106,95,20,199,241,128,195,110,146,17,211,185,56,167,245,74,131,93,121,248,192,197,15,58,65,255,0,166,59,218,
9,174,128,123,250,241,184,96,237,12,247,125,179,116,12,82,141,19,215,88,43,212,75,15,58,198,33,81,80,180,240,247,151,0,236,30,135,211,120,171,10,161,163,216,239,1,200,8,109,34,23,198,107,116,70,190,29,
222,2,21,58,128,69,30,165,129,48,106,8,124,37,143,87,108,46,106,165,29,169,119,178,226,185,79,83,167,147,236,49,108,182,65,33,179,115,184,240,72,10,233,97,164,152,116,106,200,18,4,119,128,186,5,118,192,
186,11,131,22,233,235,39,123,164,158,49,128,166,209,233,125,33,147,21,139,83,170,248,60,125,114,161,84,136,196,79,152,252,97,10,77,193,47,76,121,12,164,10,190,222,167,218,177,183,216,0,44,52,227,13,12,
81,215,163,190,178,12,161,218,42,172,241,243,142,210,186,69,129,219,240,10,123,158,249,74,138,64,104,182,29,174,254,94,198,79,4,136,29,104,48,236,157,221,100,74,169,162,18,55,171,185,135,121,94,162,127,
140,212,244,176,33,2,155,169,143,178,98,45,116,42,168,127,135,120,242,139,36,10,58,157,251,228,35,91,104,126,45,83,226,190,115,109,233,220,85,35,116,13,120,92,104,210,69,217,234,243,239,141,131,108,122,
105,184,10,180,240,0,77,233,239,243,130,11,164,171,67,219,175,206,40,2,134,82,167,67,175,56,98,166,45,21,44,240,183,192,237,223,77,164,203,83,73,173,175,176,46,58,231,212,143,128,219,177,232,250,174,46,
248,42,88,20,15,25,25,1,24,167,203,44,193,80,104,5,74,97,13,166,27,87,79,227,30,1,10,170,146,121,139,48,170,105,16,252,142,10,104,38,190,212,96,160,43,105,145,30,252,235,28,3,157,151,119,117,163,250,153,
118,151,3,42,213,106,179,111,43,149,42,23,119,6,142,205,14,210,122,216,161,208,168,189,245,128,253,49,62,17,32,74,148,16,167,160,227,29,152,217,166,186,72,245,32,252,97,186,165,110,157,38,132,240,254,
113,129,162,189,173,237,12,245,209,56,0,186,98,95,135,4,56,65,38,44,208,9,244,7,190,90,101,40,34,66,173,143,119,218,122,224,78,161,165,8,146,248,249,226,192,128,12,223,65,235,46,244,59,45,3,243,49,177,
162,8,29,75,211,235,214,29,250,251,61,103,64,163,85,69,175,62,120,102,152,128,27,90,192,70,40,8,198,166,137,51,84,32,170,136,30,60,226,85,248,5,0,244,134,166,22,24,14,162,35,133,117,4,86,173,15,243,130,
160,105,66,62,136,220,233,104,16,218,82,202,104,244,224,210,65,181,75,0,82,15,173,193,105,84,160,31,23,12,72,136,5,38,223,86,113,177,213,9,64,43,203,238,96,142,34,40,17,17,223,140,117,58,19,93,233,184,
200,192,162,53,66,61,250,97,133,75,216,31,156,16,208,64,30,208,113,163,118,4,251,225,64,44,13,40,166,165,235,174,55,230,66,82,244,247,194,48,7,10,0,122,23,12,80,14,134,132,95,63,28,116,69,113,35,32,246,
228,29,18,145,26,34,211,172,165,222,128,243,27,145,70,90,139,15,207,255,0,48,16,124,32,125,183,129,22,173,33,244,112,91,6,138,145,122,235,37,173,30,74,169,170,187,225,194,81,161,208,45,243,137,176,41,
66,84,23,219,3,80,182,26,69,212,101,249,199,206,70,181,59,250,225,197,160,163,73,26,140,241,115,69,18,169,42,98,205,50,48,43,6,189,198,190,217,101,160,17,181,185,7,88,2,176,21,244,54,224,23,22,104,21,
109,222,216,144,1,162,32,151,114,102,216,166,140,133,178,24,68,186,65,154,98,88,1,72,210,238,15,103,156,109,9,115,238,12,252,178,158,229,130,194,169,138,160,26,26,54,245,183,172,144,66,21,177,11,170,199,
239,128,86,81,247,100,15,156,47,124,111,64,6,62,249,162,115,161,4,90,62,101,250,240,240,168,64,18,11,171,222,242,119,194,74,128,31,163,157,185,155,108,45,62,133,14,10,54,128,54,205,217,212,239,212,124,
56,74,16,170,64,69,235,219,136,11,70,95,86,154,153,233,167,0,241,49,151,106,123,224,138,244,184,173,45,150,223,35,189,121,198,162,77,161,65,137,228,122,233,61,48,55,101,72,154,250,73,250,50,111,212,209,
220,118,4,239,11,212,175,68,247,212,123,19,29,110,128,161,10,39,114,13,232,198,250,151,138,76,193,200,120,46,156,19,74,133,248,200,101,98,7,153,180,43,236,24,44,208,108,69,171,227,58,223,179,206,93,152,
93,128,62,40,253,87,111,151,54,98,133,88,117,122,190,249,180,159,75,209,12,186,245,53,239,132,43,11,210,1,98,117,60,43,130,151,177,104,14,145,35,78,34,26,68,146,110,11,41,1,110,37,121,37,11,241,133,227,
7,106,217,174,241,94,168,18,122,104,215,4,83,64,27,118,95,24,64,45,141,111,103,142,240,0,90,101,179,76,14,65,104,66,62,208,199,216,18,232,122,118,122,112,178,146,20,172,83,104,157,15,227,13,24,132,13,
52,167,76,126,19,26,184,122,83,191,246,52,251,220,5,240,68,216,214,244,98,2,201,189,22,125,103,89,48,115,104,27,42,109,62,56,247,8,34,26,53,125,248,80,204,148,54,181,53,133,128,10,25,18,211,175,59,193,
175,80,81,64,1,124,226,176,144,0,32,0,79,24,88,1,18,68,177,239,4,19,45,93,173,187,225,209,134,29,32,158,211,223,143,10,164,138,88,95,23,26,2,250,35,87,207,179,27,210,8,91,104,60,135,175,17,104,226,2,93,
59,112,18,34,34,144,154,61,31,28,107,5,146,171,211,167,90,239,7,176,88,176,143,189,113,80,236,40,117,90,254,241,132,27,8,169,79,166,33,69,17,85,124,60,251,240,59,69,176,124,79,56,201,21,149,2,30,248,97,
4,32,3,10,251,240,156,251,144,180,43,85,248,194,10,34,104,8,142,252,98,161,224,58,239,77,196,9,61,157,194,123,245,248,193,193,21,173,0,79,95,56,204,182,79,106,49,254,50,135,32,69,78,211,198,245,131,34,
2,162,172,137,219,190,41,130,141,3,65,7,151,223,55,27,7,69,75,183,172,157,87,82,17,178,244,250,99,117,87,186,155,231,206,45,59,102,142,207,127,76,48,36,136,135,68,114,218,194,162,80,40,221,185,188,53,
117,5,59,74,123,103,122,54,189,24,53,100,91,161,85,125,250,197,83,99,106,65,118,227,197,251,97,234,82,242,63,254,111,23,0,134,118,205,234,11,99,230,99,19,80,186,49,242,196,82,61,140,245,201,145,160,3,
170,164,201,49,53,26,177,240,222,241,75,0,238,138,19,81,243,138,189,171,160,222,244,107,58,70,226,64,85,252,60,254,48,32,180,192,234,18,255,0,60,8,122,39,16,1,143,56,255,0,11,224,208,39,171,58,196,214,
230,237,212,247,44,205,40,48,212,195,59,186,191,205,158,73,136,129,18,221,123,112,164,81,59,245,25,247,199,58,76,16,36,53,191,21,63,92,106,44,183,213,131,120,87,251,50,97,80,201,245,130,221,206,207,14,
57,98,81,74,177,243,172,180,27,27,117,84,56,80,80,158,236,1,245,112,162,146,131,112,117,59,102,83,11,54,106,103,65,231,217,191,156,164,42,7,158,235,66,251,105,205,176,16,87,194,18,7,166,40,45,169,106,
80,237,254,44,218,58,237,236,62,155,201,150,173,232,118,29,75,177,241,134,48,45,81,4,54,169,237,76,215,68,74,105,75,230,150,122,150,123,99,81,165,24,18,158,215,167,61,53,50,197,149,122,3,202,179,5,46,
33,169,52,143,168,158,126,135,188,6,4,0,215,193,223,131,24,149,18,13,20,200,112,148,0,17,138,8,233,94,92,163,159,78,197,118,35,228,24,105,5,146,119,35,102,13,10,5,40,47,29,41,134,8,138,129,86,24,145,195,
1,208,131,232,204,112,144,10,132,17,62,88,25,108,149,80,15,67,227,128,154,14,106,150,244,44,242,172,61,243,88,54,232,3,204,135,224,194,67,3,91,82,178,53,189,105,249,202,220,54,41,18,71,212,140,241,28,
4,96,253,5,78,234,17,105,243,147,98,72,196,247,53,132,202,2,166,214,255,0,214,85,80,13,200,175,140,74,30,178,168,3,235,154,33,4,9,7,219,21,152,132,36,106,119,222,89,8,210,187,107,130,6,219,65,69,138,225,
211,235,238,117,141,37,180,68,215,102,255,0,24,254,196,233,138,15,196,197,130,131,0,239,90,239,132,149,4,80,34,16,243,235,132,102,0,168,65,18,107,139,235,179,106,116,18,251,96,107,160,199,68,251,184,177,
55,16,29,89,79,181,193,4,82,131,178,165,62,153,183,24,82,170,4,93,245,174,15,118,221,67,106,95,92,153,196,21,23,97,53,61,179,113,50,21,8,109,152,186,170,247,180,39,193,172,84,162,168,9,17,223,156,35,200,
64,61,166,184,1,88,47,68,114,198,240,177,40,43,44,103,167,1,221,218,199,69,3,167,62,175,120,164,30,51,96,140,27,189,117,23,55,53,108,50,51,28,43,78,112,174,138,63,64,130,228,40,121,206,60,11,10,57,48,
96,127,243,160,92,238,138,155,164,233,7,122,110,175,55,109,150,134,15,35,233,107,247,162,125,210,230,172,60,41,8,22,108,94,37,203,35,50,152,227,244,118,18,15,194,80,121,166,57,52,56,235,55,176,184,101,
174,90,43,189,23,114,18,134,134,9,236,165,74,133,65,219,69,2,0,60,89,8,5,93,82,162,205,189,228,196,171,149,1,165,213,89,138,212,108,251,172,253,38,28,64,156,78,174,236,193,0,78,1,12,7,49,33,211,93,204,
18,166,203,67,34,204,139,40,163,201,33,160,106,183,54,32,197,17,162,93,58,195,76,181,97,231,89,36,64,212,90,125,251,202,128,59,141,73,240,111,47,186,134,143,98,220,7,32,102,210,33,124,140,18,109,45,124,
29,251,241,98,77,176,16,37,110,230,13,143,31,9,3,213,195,212,233,176,80,183,215,76,212,34,11,42,170,143,147,54,154,82,18,17,236,22,60,10,3,182,117,217,49,33,80,248,3,151,18,177,43,188,117,47,160,148,95,
3,143,133,176,111,97,33,222,183,142,194,27,35,122,125,38,69,187,162,178,85,206,131,169,122,182,63,124,218,8,190,153,1,48,34,174,195,242,96,79,255,0,117,143,252,18,112,237,211,180,117,218,251,99,165,93,
98,155,173,11,113,106,201,30,103,64,210,182,12,111,183,106,170,170,174,213,218,228,51,209,7,78,163,70,95,12,112,48,209,18,74,56,162,206,222,215,241,164,248,12,105,124,210,17,55,174,253,252,97,183,190,
72,10,123,53,248,205,210,48,167,232,22,26,184,105,182,171,192,250,72,199,90,38,208,64,26,9,126,184,250,177,180,202,250,45,67,225,50,28,65,216,173,150,84,247,113,82,200,88,136,236,159,86,52,44,24,238,105,
189,248,184,96,111,113,147,116,154,186,249,195,116,192,34,161,237,211,247,199,177,21,252,141,126,232,97,80,95,222,67,5,145,132,60,120,205,88,59,136,74,161,39,213,133,181,104,98,61,141,49,141,208,32,21,
1,18,35,91,22,99,27,169,9,121,222,203,59,186,247,195,128,245,134,154,221,157,97,4,14,181,231,202,33,245,200,10,54,175,136,66,113,46,207,198,118,163,34,197,36,38,32,8,170,205,178,137,245,194,129,65,100,
111,96,135,93,25,59,140,168,229,207,65,109,249,235,211,36,159,76,177,2,33,21,3,127,76,134,6,32,139,101,65,88,60,186,241,132,155,123,87,106,79,78,37,13,65,21,178,58,190,49,1,65,160,233,60,159,92,32,27,
129,61,89,63,23,5,154,13,52,19,237,142,235,183,32,116,22,111,174,17,42,1,129,191,71,29,152,122,177,14,30,42,170,75,70,248,140,32,193,71,231,219,216,145,182,42,88,48,149,14,133,74,177,46,26,232,76,125,
128,172,208,128,105,119,110,60,31,38,111,100,95,124,17,49,7,7,129,136,134,62,233,246,236,133,130,207,84,27,35,215,77,53,17,24,145,247,162,29,55,44,8,5,49,161,97,157,24,34,137,213,106,166,42,83,140,17,
81,23,9,208,55,136,197,135,125,246,100,7,82,138,68,23,11,236,184,72,117,19,178,81,138,125,78,151,57,67,98,114,6,112,130,213,164,242,72,18,12,131,128,174,220,102,45,30,244,152,143,221,11,13,192,186,11,
185,242,157,178,113,108,121,107,49,73,226,29,118,7,118,199,33,43,103,155,173,182,104,97,45,21,3,216,179,18,8,90,54,193,23,119,198,127,170,243,248,167,183,223,120,240,101,198,69,232,127,155,142,30,139,
168,116,39,37,53,214,9,193,167,17,169,22,69,14,125,110,48,109,80,42,241,110,137,193,64,60,196,193,146,142,96,145,11,176,2,137,69,167,68,92,42,76,201,8,98,96,63,114,43,90,126,32,193,0,126,167,254,156,31,
221,160,208,112,165,166,58,201,13,11,74,251,22,99,38,219,144,237,10,122,3,45,56,212,177,142,120,86,176,68,224,203,177,83,78,83,193,36,92,210,7,173,78,210,207,130,218,36,68,176,104,109,132,202,24,75,65,
75,226,196,201,181,112,120,111,48,133,214,35,208,18,78,49,65,16,32,74,42,55,160,70,191,158,231,166,17,140,177,47,128,246,158,47,26,128,179,113,35,48,68,71,48,136,18,37,21,46,232,136,217,218,29,123,228,
140,7,165,90,154,171,190,13,49,177,13,0,190,174,38,240,21,0,168,47,183,166,109,2,65,36,208,143,125,119,138,90,155,221,86,230,242,232,238,146,25,224,234,227,0,236,86,250,49,252,96,152,56,181,134,223,228,
25,104,218,130,2,183,75,233,141,164,116,78,154,135,147,192,221,223,172,36,36,200,5,182,238,229,88,193,20,211,189,245,145,238,79,43,69,59,217,240,62,78,9,82,102,171,65,254,88,40,18,61,19,39,128,120,250,
31,80,72,0,21,95,93,18,143,135,38,66,3,204,107,54,191,73,245,152,0,208,81,228,94,221,169,95,156,85,106,171,234,237,195,240,202,52,162,35,98,246,96,152,26,16,6,148,122,247,226,234,116,235,158,224,61,199,
54,165,217,118,159,76,110,138,33,25,29,131,58,205,154,129,217,216,23,114,244,227,141,96,145,16,86,1,227,128,209,168,206,213,216,208,123,99,118,66,40,164,7,171,214,96,45,65,77,145,208,89,191,76,132,100,
152,64,137,55,92,84,40,193,18,131,211,167,0,21,70,21,237,214,33,128,193,68,162,44,70,250,152,26,10,12,192,211,163,217,224,197,237,201,128,39,70,220,104,215,173,58,154,121,249,192,100,105,96,212,107,196,
147,139,240,20,172,9,74,89,230,117,140,193,17,254,141,31,115,1,182,13,62,128,62,50,151,104,37,110,188,39,166,253,115,90,135,177,169,215,125,76,78,237,26,1,168,245,223,89,35,148,71,66,209,229,125,49,140,
36,78,171,170,26,129,231,139,57,112,73,15,3,192,245,116,100,97,152,202,110,187,149,29,198,254,48,2,233,65,77,89,63,23,15,208,90,80,143,208,199,128,149,208,244,212,222,184,68,128,40,128,77,27,111,43,74,
82,69,182,205,28,51,148,53,180,106,122,48,160,47,122,8,125,157,100,178,137,104,61,3,231,24,43,132,154,69,143,173,140,40,149,229,31,66,55,69,102,84,76,112,251,53,240,194,44,140,48,121,91,218,254,1,43,59,
97,153,120,62,103,252,88,208,38,46,168,69,49,74,118,246,251,40,234,162,1,48,97,238,41,184,243,238,53,138,2,41,35,89,218,19,104,131,90,239,82,121,8,232,14,114,12,104,104,217,112,171,192,12,169,226,104,
234,25,82,152,96,221,221,164,224,115,212,180,32,199,233,197,136,138,133,34,194,138,81,118,134,138,201,134,131,227,189,46,39,220,154,155,34,54,220,156,116,163,1,225,140,119,169,12,20,211,207,146,167,6,
14,131,133,14,1,237,84,148,99,188,50,210,172,180,238,83,195,96,82,136,42,90,185,173,221,53,220,147,196,215,219,52,249,239,179,255,0,76,255,0,233,135,170,223,55,11,77,182,36,238,220,158,247,195,216,227,
198,254,7,147,174,153,161,182,186,187,75,237,134,149,108,52,235,189,223,167,29,223,80,159,41,125,243,253,119,174,127,166,245,207,139,190,238,235,235,198,225,220,241,233,97,115,194,59,111,225,62,171,158,
128,70,158,163,190,252,86,206,170,125,153,254,205,55,127,156,249,172,254,142,253,243,111,107,228,125,110,108,246,58,118,253,55,50,116,117,82,117,46,123,194,239,232,223,227,38,123,211,233,33,127,174,63,
164,77,171,187,253,103,216,101,59,139,232,199,173,119,217,212,212,159,155,199,219,27,60,210,249,178,92,255,0,108,219,228,99,254,251,115,61,13,239,23,237,190,126,179,169,236,73,195,211,110,137,111,134,
187,241,158,7,171,229,63,25,159,77,127,153,109,221,235,190,39,179,183,221,237,253,58,227,221,95,103,47,91,150,89,142,254,234,191,116,190,112,254,120,158,126,126,156,117,95,254,65,248,185,21,59,251,169,
255,0,39,26,222,139,242,31,126,187,188,117,239,34,249,122,186,241,233,158,95,171,79,91,159,118,90,207,129,198,159,71,61,203,223,108,221,240,222,163,53,235,179,188,45,37,180,147,187,244,198,214,219,119,
123,185,173,231,189,31,79,200,185,29,13,186,79,98,79,19,172,175,81,171,231,30,109,122,126,239,249,120,220,242,125,243,71,126,137,235,132,159,162,120,248,158,155,159,134,70,236,235,167,115,223,141,223,
248,88,95,165,207,160,23,221,158,9,234,142,140,179,197,207,42,209,125,91,169,63,172,246,227,252,175,94,125,46,175,121,239,103,237,174,167,143,100,212,235,43,197,163,213,209,239,239,154,52,78,146,79,30,
156,122,181,179,162,92,70,153,43,203,236,190,48,190,45,143,94,147,127,142,52,122,37,186,235,227,175,124,94,159,75,248,191,239,63,219,127,173,240,246,122,250,95,47,19,87,55,118,174,187,175,155,143,86,242,
251,167,191,164,225,239,181,250,223,253,241,227,219,101,157,82,203,171,243,158,179,231,200,247,235,115,59,54,237,39,179,95,78,39,225,102,159,101,246,239,61,30,47,234,179,187,201,231,141,198,89,171,220,
190,50,119,73,23,105,46,236,222,125,122,61,41,249,204,255,218,0,8,1,2,3,1,63,16,192,184,35,197,39,21,51,188,96,229,219,134,176,23,29,112,132,224,102,59,120,174,0,152,247,135,120,135,138,153,219,137,56,
36,199,12,209,148,240,107,145,254,40,28,17,226,58,200,230,206,16,28,40,99,223,21,112,46,61,225,222,116,224,97,157,184,137,192,19,129,142,45,200,229,112,43,130,112,36,224,102,85,195,135,110,93,48,46,34,
113,9,198,142,91,133,116,229,50,23,53,144,98,129,131,173,235,22,51,41,113,131,129,152,150,25,14,204,80,195,77,230,178,222,176,71,71,223,255,0,153,117,189,101,202,60,244,199,190,22,224,47,7,121,1,139,112,
131,2,227,175,241,186,199,120,128,226,88,237,226,184,23,18,60,50,112,51,59,113,19,128,56,247,135,120,183,35,155,195,110,36,56,16,56,53,149,112,174,59,100,113,70,5,196,78,0,156,12,113,110,71,47,0,167,177,
253,224,4,122,207,239,26,39,88,17,38,23,219,131,244,63,206,116,190,249,95,228,255,0,125,242,169,134,110,235,223,248,193,61,73,129,119,222,2,62,38,76,5,62,52,255,0,89,169,221,192,187,134,116,38,118,199,
88,151,92,5,87,42,186,199,163,197,254,156,135,124,95,28,5,199,14,240,107,129,134,118,228,76,91,128,57,43,131,49,253,151,127,190,171,129,113,35,131,140,156,12,197,185,71,16,227,223,10,57,28,217,158,113,
0,224,64,199,190,42,225,92,29,228,112,65,146,184,147,128,39,3,28,81,200,240,2,224,156,82,112,147,136,141,153,237,225,172,107,214,41,125,142,0,184,135,102,64,207,99,30,198,4,76,134,11,217,112,55,70,21,
217,139,248,200,18,103,179,158,201,143,165,128,24,4,137,128,233,131,12,118,228,120,3,143,120,119,133,56,23,12,127,202,235,22,228,78,54,206,220,33,200,230,206,16,14,16,24,247,197,92,11,143,120,119,145,
56,24,103,110,36,224,19,30,240,211,139,114,60,27,112,78,4,156,117,149,121,118,197,185,30,0,92,19,138,78,54,101,206,156,187,113,88,23,18,112,132,224,102,59,114,60,0,227,167,133,19,138,153,219,137,14,22,
178,111,245,63,168,152,254,251,188,73,194,179,103,8,156,41,142,222,43,129,113,211,199,78,6,103,110,68,226,19,30,240,239,22,228,120,59,196,3,129,3,30,42,225,92,118,200,120,16,96,92,73,192,129,199,89,115,
167,29,178,57,5,196,156,77,112,51,22,228,120,3,142,158,20,120,217,157,227,7,11,88,247,194,56,11,147,127,188,111,18,126,169,203,250,144,156,40,226,143,21,192,184,145,225,105,192,204,239,40,56,135,30,248,
107,35,155,48,196,3,132,6,61,241,87,10,227,182,71,21,12,237,196,156,68,224,99,139,112,174,59,100,60,80,100,184,147,128,39,3,28,91,145,224,14,8,241,73,198,206,24,56,83,30,248,107,1,113,215,16,28,12,253,
241,142,45,253,250,230,216,147,6,57,73,192,204,91,149,196,57,219,132,100,92,235,132,3,133,12,118,241,92,11,143,120,119,144,156,12,51,183,18,113,19,30,240,211,139,114,60,17,112,78,6,103,110,36,224,147,
129,142,45,200,240,69,193,56,164,227,102,92,233,194,206,220,86,5,196,143,9,174,6,98,215,35,138,184,7,38,255,0,240,85,224,55,54,206,220,116,200,184,235,132,39,10,98,215,138,224,92,72,241,19,129,76,237,
196,67,136,199,188,49,172,139,193,222,0,224,64,230,174,21,143,120,119,139,114,47,4,184,39,0,14,54,101,228,183,144,241,88,23,18,113,169,192,204,91,145,224,14,8,240,19,141,152,127,129,23,31,240,6,116,195,
188,217,196,39,10,98,215,138,224,92,72,240,164,224,102,45,197,7,39,190,26,200,185,214,29,226,1,192,129,143,124,87,10,224,239,16,240,41,135,120,33,192,129,198,204,174,21,199,108,67,197,6,5,196,156,18,112,
49,197,185,30,0,112,78,41,56,169,199,78,11,59,195,251,179,244,27,200,126,203,250,128,76,235,6,57,14,71,43,129,113,39,10,78,6,98,220,211,151,110,28,69,199,92,32,28,32,49,219,197,92,11,143,120,119,136,156,
12,206,220,73,196,76,123,205,153,92,1,224,239,16,241,80,206,220,73,196,78,6,56,183,35,193,183,4,226,39,27,50,228,78,59,103,110,21,129,113,38,26,63,121,9,192,19,131,78,41,201,175,222,23,18,226,76,25,148,
156,12,197,185,211,142,217,219,142,153,23,58,226,19,133,49,219,145,202,224,92,116,240,164,224,102,118,227,7,17,49,239,14,241,172,139,193,222,33,56,169,157,184,147,136,152,225,167,22,224,47,7,120,39,0,
14,54,101,114,39,29,177,15,21,129,113,39,26,153,211,6,103,110,36,253,225,192,184,145,225,56,24,99,251,198,43,192,115,183,46,153,46,34,113,9,194,152,181,201,149,192,184,145,225,73,192,204,91,140,28,158,
248,107,34,227,172,49,33,192,195,29,185,190,35,30,240,239,26,200,188,29,224,135,3,14,54,101,112,15,29,177,15,21,192,174,36,224,147,129,142,45,202,227,75,130,97,151,246,138,196,143,232,24,103,110,71,28,
57,127,120,97,6,29,228,78,0,156,12,113,71,35,149,192,184,147,138,78,6,101,185,167,46,220,129,113,215,8,7,3,49,219,155,202,224,14,58,112,211,136,76,5,206,176,239,0,28,12,49,219,155,202,224,14,61,225,222,
33,224,83,59,113,39,17,56,24,226,220,174,9,112,78,34,113,179,137,15,219,25,139,92,137,250,46,94,76,64,63,124,4,199,188,24,228,38,71,43,129,92,73,192,147,129,152,171,157,57,118,227,166,2,226,78,33,56,83,
22,188,87,2,226,71,133,30,5,51,183,24,56,25,142,222,43,129,113,239,12,66,113,83,59,113,33,196,76,123,195,78,45,200,240,119,130,112,65,198,206,13,56,25,136,127,125,253,6,12,152,6,39,21,152,23,19,247,69,
196,174,36,193,142,9,56,53,138,184,87,29,185,104,96,92,68,226,19,133,28,91,145,202,224,92,72,240,164,224,102,91,140,28,187,112,214,2,227,167,132,78,42,103,110,48,113,211,30,248,107,1,120,59,193,14,8,49,
205,156,1,224,239,16,241,92,10,225,156,29,126,212,253,33,140,226,176,46,36,120,137,192,204,118,226,39,239,42,225,88,103,110,68,25,46,34,112,4,224,99,139,114,57,92,11,130,113,73,192,204,183,58,114,237,
195,128,92,117,194,19,129,153,110,48,114,123,225,172,5,224,196,3,129,152,237,205,156,0,156,29,226,19,138,152,109,196,156,14,184,24,229,28,172,59,201,127,76,120,137,199,108,135,144,184,145,225,147,129,
152,183,35,63,74,31,208,128,253,159,28,8,48,239,17,56,1,56,52,226,142,71,43,129,92,73,192,147,142,178,175,46,217,219,142,152,11,137,56,66,112,166,45,114,101,112,46,58,121,2,227,174,16,14,6,99,183,35,151,
0,113,239,14,241,15,21,51,183,18,28,116,199,13,56,183,1,120,59,193,14,7,88,27,205,159,165,114,229,96,92,73,192,94,6,98,220,174,0,231,110,17,50,56,233,195,24,56,83,30,248,172,11,137,31,216,1,49,211,135,
121,177,145,202,225,183,18,28,9,56,53,138,188,187,114,233,146,226,78,0,156,40,226,220,153,92,11,137,30,20,156,12,203,114,19,133,49,107,145,202,224,14,58,120,81,226,166,119,140,28,44,123,195,188,107,1,
120,59,193,14,6,25,219,145,49,96,19,14,240,197,31,216,25,139,112,47,16,184,56,137,198,206,33,56,83,33,120,174,5,196,143,17,56,25,142,242,79,214,46,38,241,0,193,142,34,99,222,26,197,92,43,142,220,136,50,
92,68,224,4,224,99,139,114,57,112,43,130,113,73,192,204,171,157,57,118,226,184,23,18,60,41,56,20,206,241,131,151,110,26,192,92,117,134,13,112,51,29,185,19,128,28,123,195,188,67,142,220,169,157,184,147,
130,76,116,254,144,184,137,192,129,198,206,33,56,81,196,60,87,2,226,71,131,129,152,183,40,199,244,69,253,149,112,172,48,239,34,112,65,157,184,137,192,39,6,156,81,200,229,112,219,130,112,36,224,102,85,
206,156,118,206,220,130,226,78,33,56,20,203,115,167,46,220,116,192,92,117,194,19,129,152,237,200,240,7,30,248,81,56,169,157,184,144,197,200,152,247,157,177,111,234,33,198,204,112,43,198,142,33,226,184,
23,18,113,169,192,204,91,138,156,70,118,225,211,35,137,56,64,99,251,23,88,152,51,42,185,33,192,19,30,240,239,20,114,60,27,113,39,2,7,6,178,174,21,199,110,93,48,46,36,226,19,129,152,183,35,149,206,220,
186,96,92,73,194,19,129,152,183,35,151,0,113,211,194,147,138,153,219,140,28,45,99,223,14,153,23,3,14,241,33,201,188,71,128,142,6,56,163,192,204,10,226,78,7,92,12,197,94,46,9,140,225,211,142,184,137,194,
12,91,147,43,147,95,178,2,102,143,27,19,35,155,195,188,64,56,16,56,53,149,112,174,14,242,56,32,201,92,73,192,9,192,199,22,228,114,224,92,19,138,78,18,113,53,192,204,91,145,224,7,18,60,41,56,217,150,227,
7,11,30,248,83,128,188,24,132,197,184,167,232,1,199,188,52,226,31,216,53,138,184,39,151,245,28,222,43,129,113,35,198,167,237,152,152,128,112,137,143,124,87,10,199,188,59,200,156,16,103,110,36,224,137,
193,167,22,228,120,54,224,14,4,156,20,202,188,187,98,220,143,6,220,19,138,78,5,50,220,233,203,183,14,2,226,78,19,92,12,199,110,68,197,192,28,145,253,21,49,223,235,19,199,108,26,224,131,31,220,52,224,102,
45,202,226,28,237,251,106,224,92,52,225,222,68,224,102,118,226,39,16,227,167,14,241,110,71,131,110,0,56,16,56,53,149,112,163,142,217,28,116,192,184,147,129,39,27,50,174,116,225,111,54,226,176,46,36,226,
19,129,152,183,35,192,28,116,240,164,199,120,95,208,51,30,249,5,199,142,156,16,99,222,120,224,4,199,252,26,159,161,19,246,71,88,151,6,103,110,3,56,135,59,112,214,69,224,239,16,14,4,12,115,172,171,133,
113,219,33,226,166,119,137,56,1,56,24,226,220,43,142,217,15,32,184,147,128,39,3,49,110,71,128,56,35,194,147,141,156,48,98,197,158,127,73,130,28,41,142,248,184,38,94,41,56,169,143,248,181,192,184,145,225,
215,234,135,12,121,69,206,184,64,56,64,99,183,138,225,88,225,222,71,3,12,237,196,156,2,99,222,26,113,110,71,131,110,9,192,166,118,226,78,0,78,6,56,183,35,192,23,4,226,147,141,153,115,167,11,59,114,151,
18,97,215,234,127,95,120,147,12,90,199,191,241,86,184,25,139,114,177,253,93,103,120,128,224,166,59,120,174,5,199,79,8,156,12,206,220,72,112,9,143,120,119,139,114,60,29,224,3,129,3,141,153,92,43,30,240,
239,22,228,94,13,184,39,0,14,54,101,115,167,29,179,110,43,2,226,78,25,56,12,199,110,3,251,7,120,193,250,86,225,223,7,121,219,15,241,7,20,120,233,251,6,86,5,206,158,20,78,6,101,174,48,113,14,118,225,172,
143,7,120,128,112,32,99,197,112,174,59,100,60,80,97,222,8,112,32,113,179,43,128,78,59,100,60,86,5,196,156,120,224,102,45,200,240,69,201,28,123,202,126,137,193,193,138,121,51,167,61,228,76,114,46,61,255,
0,138,4,253,189,225,110,3,57,118,225,172,139,142,184,64,56,80,199,190,43,129,113,239,14,243,167,3,51,183,18,113,19,141,153,92,1,224,239,16,241,80,195,110,36,224,147,129,142,45,200,240,21,193,56,137,143,
89,179,132,214,28,60,45,253,19,151,110,58,253,6,40,152,241,219,137,63,195,50,185,223,236,198,27,200,222,36,226,1,194,152,162,241,87,2,227,167,14,241,19,129,153,219,137,56,137,143,120,119,141,100,94,14,
241,9,197,76,237,196,156,68,224,211,139,114,47,6,220,19,129,3,141,153,112,19,129,222,49,226,176,235,244,235,138,224,14,8,241,121,121,56,24,171,254,24,195,245,191,169,1,195,152,183,35,149,192,28,72,240,
162,112,51,59,196,135,17,143,124,53,145,113,214,24,128,112,32,103,156,217,201,239,14,241,172,5,224,239,0,28,0,56,217,149,192,60,118,200,120,169,194,79,212,12,199,33,193,30,41,56,217,143,38,51,147,31,252,
35,26,152,23,29,60,82,112,41,139,115,167,46,220,53,145,113,215,8,7,2,6,59,114,57,92,1,199,188,59,196,57,23,29,97,222,0,56,24,113,179,46,0,227,222,29,226,30,42,97,183,18,112,73,194,199,45,225,200,184,39,
0,152,225,174,34,112,166,67,250,151,244,42,113,14,61,255,0,224,116,226,220,26,229,219,142,152,11,142,184,66,112,131,29,185,28,174,5,199,190,17,56,25,157,184,144,224,64,199,111,21,192,28,123,195,188,67,
197,76,237,196,156,29,112,105,197,185,92,18,224,229,194,142,63,164,202,192,184,147,141,79,208,211,129,92,17,227,167,22,112,193,254,119,108,60,17,129,113,39,16,156,12,197,185,28,174,0,226,71,133,39,3,51,
188,96,228,247,195,88,11,142,158,20,78,42,103,110,48,113,211,30,240,198,176,23,131,188,16,224,64,225,161,135,38,20,92,120,11,137,63,64,102,45,200,254,155,193,174,16,56,28,120,167,2,226,71,252,135,245,
71,15,22,228,114,184,23,18,113,73,192,204,91,157,56,140,237,195,88,11,142,184,72,112,48,206,241,131,142,152,247,195,88,11,142,176,239,18,28,12,51,183,54,112,2,112,119,140,112,229,38,29,227,192,102,45,
230,28,28,116,225,39,236,5,196,143,232,25,142,241,71,249,134,86,5,201,30,41,56,25,138,185,211,142,217,219,142,152,11,142,184,66,112,166,59,114,101,112,46,58,120,107,1,113,39,8,78,6,99,183,35,192,14,61,
225,222,33,56,169,157,184,147,30,249,179,22,224,57,223,9,175,208,107,128,39,26,56,135,244,152,183,133,49,110,40,253,40,76,159,230,59,48,214,87,54,56,237,203,166,5,196,156,66,112,166,45,120,174,5,196,143,
10,39,2,153,222,33,56,25,142,220,142,87,0,113,211,194,137,197,76,239,18,28,116,199,188,59,198,176,57,233,193,6,28,92,52,206,255,0,69,102,5,196,159,178,147,133,191,163,174,20,198,127,151,219,59,242,37,
196,156,1,56,24,226,220,142,92,11,130,112,164,224,83,45,206,156,187,114,3,137,30,20,156,84,206,241,131,147,223,13,96,46,58,195,188,26,253,43,128,60,28,212,195,120,240,167,3,28,91,149,143,236,60,25,28,
152,206,18,127,152,2,112,24,226,142,71,43,129,92,19,138,7,29,98,175,232,59,114,5,196,156,33,56,20,203,115,167,46,220,129,113,39,9,174,6,99,183,35,151,0,121,120,169,157,185,39,4,152,247,134,56,15,29,176,
112,65,146,254,210,78,18,126,137,175,240,159,218,69,51,124,2,112,32,113,214,85,194,184,237,203,166,5,196,156,66,112,51,22,228,114,185,219,59,113,88,11,137,56,66,112,51,22,228,120,1,199,79,10,39,21,14,
92,88,247,135,121,111,39,120,156,12,50,222,64,78,59,100,95,216,52,226,223,208,239,129,156,39,249,66,97,239,13,57,87,10,227,182,71,4,24,23,18,112,2,112,49,197,185,28,174,5,113,35,197,39,9,56,132,224,102,
45,200,240,3,137,30,20,78,42,103,120,193,194,206,220,197,196,142,29,226,107,139,51,183,34,97,195,222,29,229,188,87,13,184,147,246,94,185,151,17,56,137,194,142,33,255,0,44,239,145,6,118,226,78,34,112,49,
197,185,30,2,184,39,20,156,117,150,231,78,59,98,220,143,0,56,39,20,156,84,206,243,167,46,220,41,192,92,72,242,224,204,118,228,78,94,20,76,59,227,183,18,28,28,12,113,87,4,227,251,90,56,135,138,224,92,73,
195,179,252,147,120,137,192,19,29,56,105,197,185,30,13,184,39,2,7,29,101,92,52,227,183,42,12,11,137,56,164,227,172,171,157,57,108,241,88,23,18,113,53,192,204,90,226,51,128,56,35,194,137,135,14,48,113,
211,143,56,171,128,185,211,250,8,51,188,68,253,128,184,195,46,91,134,12,197,191,229,152,183,34,240,119,137,14,4,12,115,172,174,21,193,222,67,197,6,75,137,56,36,224,99,139,115,167,29,177,94,58,96,92,73,
196,39,3,49,110,71,128,56,35,194,137,197,76,119,140,28,116,225,198,176,23,60,240,154,224,102,118,230,206,14,14,241,15,238,118,193,195,134,34,127,148,80,199,190,42,225,88,247,135,121,15,26,25,219,137,14,
34,112,49,197,185,30,8,184,39,20,24,23,18,112,73,192,199,22,228,120,34,224,156,82,113,179,46,116,226,12,237,194,112,46,72,240,245,192,204,181,225,239,0,227,222,24,162,102,223,167,179,245,163,147,147,128,
19,149,167,238,31,184,172,192,185,55,135,120,137,192,161,157,184,136,112,9,143,120,119,141,100,120,59,193,56,16,56,217,149,206,156,26,113,110,69,224,43,130,113,1,198,204,174,116,227,182,109,197,96,92,
72,240,132,224,113,223,15,120,7,29,56,119,195,222,108,206,241,131,135,49,239,246,238,0,159,166,184,109,193,63,201,122,193,76,54,227,7,0,113,239,134,178,47,7,120,0,224,64,230,184,87,7,121,183,20,24,109,
193,14,6,28,108,203,128,156,118,196,60,86,5,196,156,106,112,51,22,228,120,3,135,244,108,227,78,7,30,248,83,129,115,167,14,240,107,39,59,253,98,152,109,199,129,215,3,28,85,201,203,254,41,23,30,248,53,145,
120,59,196,3,129,134,61,241,92,43,30,240,239,16,156,10,103,110,36,224,147,141,153,92,2,112,105,196,60,86,96,92,73,193,39,3,28,91,145,224,5,193,56,137,198,204,94,86,108,241,92,61,240,132,224,102,118,228,
78,0,231,108,159,182,39,131,190,75,254,66,78,32,224,131,24,188,85,192,184,233,195,188,66,112,51,59,113,33,196,76,112,211,139,114,47,7,120,135,138,134,118,226,78,34,112,49,197,185,30,13,184,39,0,156,108,
203,145,56,237,144,184,241,46,36,227,83,151,188,143,0,115,183,10,60,84,203,250,196,228,192,222,32,224,131,59,114,39,0,56,255,0,143,67,22,184,14,87,0,113,35,196,78,6,103,110,36,56,137,157,184,107,35,193,
222,8,112,48,227,103,29,49,239,14,241,110,69,224,239,4,224,131,141,156,1,225,111,33,226,176,46,36,225,229,110,87,0,120,113,19,141,153,222,64,203,130,254,129,56,145,253,3,51,183,34,112,7,30,240,211,138,
57,28,175,236,71,247,204,72,241,169,192,204,91,154,28,70,118,225,172,139,157,112,128,112,48,199,110,71,43,128,56,247,135,120,135,1,120,59,192,7,3,14,54,101,112,7,131,188,67,197,76,237,196,156,18,112,51,
22,229,115,49,50,39,27,56,153,48,215,235,78,6,99,183,34,126,131,20,120,169,134,220,72,112,58,199,145,60,29,231,78,8,50,87,17,63,118,199,45,195,207,151,110,81,113,215,8,7,8,49,219,145,202,224,14,58,112,
239,17,56,20,206,220,72,112,48,199,110,111,43,128,56,247,135,120,135,138,152,109,196,156,14,184,52,226,220,174,14,240,78,29,63,68,76,73,138,56,135,133,152,111,29,57,115,199,3,49,110,71,28,140,123,225,
15,9,57,184,128,199,190,21,112,172,127,65,6,118,226,39,0,38,61,225,222,40,228,188,5,113,6,76,154,224,253,3,190,1,115,67,1,113,19,136,78,20,197,174,71,43,129,113,35,194,147,129,76,239,24,56,140,123,225,
172,139,142,156,59,196,39,2,153,219,137,14,58,99,222,29,226,220,139,193,222,0,56,24,113,179,128,39,233,174,4,156,184,51,22,229,97,195,194,56,217,151,24,56,83,33,121,156,14,40,153,112,140,91,145,224,9,
142,156,184,183,129,112,219,137,14,4,156,117,149,112,174,2,184,241,169,155,88,137,192,39,3,28,91,145,202,224,92,72,240,164,224,102,91,140,28,187,112,214,2,227,174,16,14,6,25,222,48,112,177,239,134,185,
59,192,7,3,12,237,205,156,1,193,222,33,226,166,27,113,39,7,92,12,115,108,7,137,112,78,34,96,224,206,156,41,144,188,86,5,196,143,232,25,142,220,172,152,86,36,112,197,30,43,250,234,225,92,29,242,32,203,
195,135,6,156,91,129,149,192,184,39,20,156,12,203,115,167,46,220,130,226,78,16,156,41,139,94,43,129,113,239,134,217,133,112,89,149,113,120,101,193,222,109,195,108,61,124,98,46,87,23,43,244,202,206,248,
211,88,81,152,223,56,247,134,177,110,87,7,120,38,119,150,107,244,3,135,28,123,226,184,23,18,56,242,51,22,227,250,90,56,185,113,153,127,88,204,91,192,166,118,226,78,41,63,70,248,34,226,76,9,130,78,6,98,
175,232,89,155,228,228,98,166,21,214,35,113,91,134,20,50,185,112,218,102,242,163,140,50,184,147,59,113,9,147,119,13,24,209,56,79,206,75,137,188,33,196,18,92,107,2,19,34,187,197,100,214,4,49,48,214,77,
96,178,76,59,192,7,4,25,222,108,224,14,39,41,149,192,185,39,232,25,139,127,204,191,170,204,112,183,130,184,237,203,67,37,196,153,50,19,128,102,205,193,76,153,46,60,29,247,194,111,38,179,83,38,240,23,36,
227,120,76,101,227,167,5,241,141,253,7,190,27,57,49,147,92,116,199,188,51,120,78,59,114,233,143,232,214,18,254,233,143,248,167,233,115,182,68,226,167,232,56,118,229,188,215,156,103,232,23,27,250,29,184,
108,253,14,154,207,255,218,0,8,1,3,3,1,63,16,197,152,55,136,222,37,201,48,107,200,235,130,50,134,27,224,119,194,92,232,205,112,169,134,61,96,39,16,206,140,27,195,223,14,240,38,71,15,92,230,248,211,194,
239,135,10,113,12,89,131,120,233,225,46,73,148,201,148,98,167,0,241,223,3,94,18,225,215,0,24,179,135,172,237,194,92,232,202,60,42,60,61,96,76,167,14,140,27,194,55,142,242,76,237,195,215,46,217,102,13,
226,183,139,67,239,254,255,0,57,35,140,118,100,102,91,61,242,38,177,20,194,152,99,176,55,129,83,233,145,151,40,225,46,21,43,214,120,79,251,247,193,39,89,219,88,92,81,222,177,173,47,219,255,0,184,244,27,
196,185,19,55,120,237,135,92,4,202,28,61,98,175,9,94,0,120,93,240,245,128,156,67,22,24,55,143,60,37,192,153,78,27,135,19,136,38,117,130,175,2,225,215,16,197,152,108,224,183,132,185,209,130,60,36,195,172,
112,38,83,135,172,26,240,149,225,222,64,198,56,122,229,46,89,131,120,86,240,151,2,101,56,122,196,3,221,254,177,168,125,47,245,128,123,29,101,0,245,175,227,23,238,184,7,220,254,63,249,139,177,209,215,211,
32,223,7,175,175,252,222,106,21,53,227,60,111,219,249,198,123,183,24,214,194,248,198,209,182,153,81,140,22,174,207,239,1,96,7,223,20,33,95,166,119,109,194,148,108,47,179,253,225,162,83,237,136,99,235,
136,29,187,205,111,204,239,234,96,236,62,184,87,111,166,40,112,245,131,190,18,185,209,154,120,84,226,92,9,196,28,116,96,222,19,124,59,192,153,78,30,176,226,111,142,248,173,225,46,26,196,200,98,204,54,
112,91,194,92,9,148,226,140,58,224,38,83,145,175,8,174,29,113,12,89,195,215,36,174,116,96,222,21,188,59,48,38,94,29,24,55,136,222,6,229,102,8,211,148,243,149,141,29,184,20,157,185,227,24,97,205,56,167,
60,119,58,103,21,91,202,226,90,102,32,138,226,4,23,1,229,197,219,115,127,110,35,229,251,225,234,247,138,121,239,24,163,157,131,137,115,163,41,194,166,29,99,214,4,226,31,160,247,195,129,49,103,15,88,56,
247,146,241,167,138,222,30,176,39,19,22,97,190,55,113,49,46,4,202,113,70,29,112,19,41,157,240,53,225,46,29,113,12,89,135,88,231,110,18,231,70,13,120,84,120,122,192,153,78,29,96,222,17,188,119,147,47,29,
48,38,83,135,70,13,226,55,142,242,76,237,192,195,174,38,44,195,124,14,248,75,134,140,167,10,152,117,192,39,16,206,140,26,241,219,14,176,48,38,89,195,215,36,175,232,78,44,122,192,156,67,58,193,188,110,
240,239,2,101,223,15,88,113,55,154,205,60,86,240,151,13,28,67,22,97,179,130,143,9,115,163,6,240,156,58,224,38,83,135,172,26,240,138,243,3,24,227,166,87,19,121,102,13,225,21,227,188,152,199,29,57,70,44,
193,188,86,240,151,2,101,56,84,195,103,0,241,167,58,193,175,3,14,184,9,139,56,151,14,248,75,157,28,170,112,245,128,156,67,28,46,15,124,59,192,153,120,122,195,137,190,52,226,83,43,120,75,129,56,134,44,
193,167,7,124,37,206,178,143,21,135,92,4,202,114,53,225,21,195,174,33,139,56,122,202,226,92,232,193,188,43,120,118,96,76,84,225,235,43,136,57,214,13,225,81,225,41,129,50,156,42,96,222,35,120,211,197,223,
3,14,184,152,179,13,240,119,194,92,232,194,112,169,135,92,2,113,12,232,193,175,9,190,5,48,3,151,135,172,56,74,241,167,138,222,29,224,78,16,98,204,27,196,223,9,112,38,94,71,92,17,148,206,248,21,120,75,
135,92,67,22,97,143,89,92,37,206,140,27,195,110,24,224,76,167,15,88,55,136,57,214,13,225,239,135,102,4,202,112,232,193,188,70,241,167,142,220,14,80,197,152,55,129,111,9,112,214,83,133,76,58,192,192,78,
52,240,55,132,223,33,50,135,15,88,119,137,48,222,117,157,240,175,15,88,19,137,142,176,111,19,121,222,37,192,153,28,116,229,219,46,119,192,183,132,184,104,226,24,179,13,156,3,194,92,232,193,188,85,195,
174,2,101,56,122,193,175,9,94,52,240,199,14,204,9,148,225,235,6,240,138,241,222,76,93,241,211,148,98,204,27,198,239,9,112,38,83,133,76,54,112,13,227,79,3,194,97,215,19,22,114,59,225,46,116,101,188,94,
25,217,128,156,67,29,24,55,132,223,14,242,76,83,135,174,123,113,167,138,222,18,224,67,136,98,204,26,112,81,225,46,117,131,121,29,112,19,41,200,171,194,43,135,92,67,22,112,245,148,113,46,61,96,215,132,
87,152,98,206,30,176,39,16,197,152,55,134,222,18,224,76,167,14,140,27,196,111,26,120,187,228,117,131,33,139,57,22,240,151,58,50,143,10,153,94,7,16,113,49,179,132,223,14,4,197,156,61,114,155,206,178,220,
239,21,30,18,152,9,196,49,102,13,226,55,132,184,19,46,249,116,224,140,161,157,240,42,240,151,13,28,67,22,97,214,61,114,75,157,24,55,134,220,58,226,98,206,30,176,39,16,115,172,27,195,223,9,76,9,148,225,
235,6,241,27,198,158,59,113,211,13,113,49,102,13,206,240,215,9,112,214,83,134,152,117,192,39,26,113,235,7,124,43,112,235,5,50,6,3,174,30,176,239,132,185,214,81,225,91,195,214,2,112,12,88,96,222,35,120,
75,129,50,239,151,78,86,97,30,5,188,37,195,71,16,197,152,108,224,19,132,185,209,131,120,237,135,88,224,76,161,195,129,56,131,157,24,55,135,188,58,224,38,83,135,172,87,132,175,29,240,175,29,51,78,33,139,
48,111,27,188,37,192,152,142,26,97,215,0,241,223,3,94,19,14,184,67,22,113,102,14,241,49,43,131,172,163,194,166,29,99,214,2,113,172,232,193,188,38,243,188,76,0,229,211,151,108,179,52,241,91,194,92,9,196,
49,102,13,56,6,240,151,58,193,175,26,103,78,2,101,14,70,188,37,112,235,244,14,184,9,138,28,61,96,215,132,175,29,228,49,142,30,178,142,33,139,48,111,13,188,37,192,153,78,26,98,188,28,52,241,119,194,92,
58,197,78,25,194,178,220,59,225,46,116,101,28,31,214,116,96,222,19,124,201,139,56,122,230,87,58,193,30,21,188,37,192,156,67,22,96,222,35,120,75,146,101,223,46,156,148,51,190,5,188,37,195,71,16,197,152,
117,143,88,9,148,225,193,175,9,92,241,154,201,139,28,49,235,1,56,131,157,24,55,134,222,29,152,19,41,195,102,43,196,223,26,120,91,225,48,226,24,179,6,241,231,19,18,225,172,166,12,197,201,114,24,70,107,
52,226,107,6,184,51,29,225,215,16,197,156,61,97,223,9,92,235,45,206,241,81,225,235,1,50,153,12,117,131,120,141,225,46,4,203,191,212,44,203,120,22,240,151,2,28,67,22,97,179,128,120,75,157,24,53,225,46,
26,50,153,12,84,195,172,122,192,71,136,57,209,131,120,171,195,129,50,156,61,98,188,37,120,211,194,167,9,76,4,226,24,179,6,241,177,225,46,4,202,112,179,60,112,59,154,51,89,76,45,202,197,112,117,194,7,22,
96,185,105,135,124,37,206,178,156,42,97,214,56,9,148,193,157,24,55,132,175,29,224,76,188,61,114,237,150,101,188,86,240,151,2,101,50,98,204,26,112,13,225,46,117,150,188,142,184,35,40,97,215,0,222,18,231,
88,53,227,182,29,112,19,40,112,245,138,188,37,120,239,33,138,156,61,96,78,33,142,176,111,27,28,27,137,112,38,83,133,152,101,207,57,76,211,193,167,133,133,156,67,22,96,211,132,220,119,137,115,172,166,14,
46,29,99,128,156,189,96,222,19,124,57,3,22,112,245,201,43,157,101,30,21,188,61,96,76,166,67,22,96,222,35,120,75,157,101,228,117,192,98,134,27,224,119,194,92,235,10,120,172,58,224,38,80,195,124,13,120,
75,158,51,79,10,156,61,96,39,16,115,163,6,240,219,195,179,2,101,56,179,7,137,190,35,46,86,241,211,3,195,12,112,55,130,222,18,225,172,167,10,242,9,205,112,107,131,113,48,235,136,98,206,30,178,111,132,174,
116,101,30,21,30,30,176,38,83,135,70,13,226,55,135,121,38,93,241,211,148,203,48,223,2,222,18,224,67,41,144,197,152,52,226,98,134,27,224,91,194,92,52,101,225,83,14,177,235,2,113,7,58,48,111,13,184,117,
142,4,197,14,30,177,94,10,113,205,56,117,138,240,245,135,33,102,109,194,199,132,184,19,41,195,172,54,112,14,92,216,193,172,21,120,23,14,184,129,139,49,83,131,190,18,231,70,81,199,102,42,56,117,142,204,
9,148,205,99,214,13,225,21,227,188,129,151,142,156,166,242,204,27,197,111,9,112,38,83,38,44,193,167,0,222,18,228,153,91,194,92,9,148,200,98,166,27,56,4,120,131,157,96,215,142,216,117,192,76,80,225,235,
7,124,37,115,172,211,194,166,44,118,96,35,131,50,99,172,27,199,158,16,156,4,28,58,57,77,241,167,129,111,27,102,184,245,144,197,152,52,226,174,71,18,225,129,30,21,195,174,2,112,153,227,6,188,37,112,235,
128,12,89,195,215,41,92,235,4,120,86,240,148,192,153,76,152,232,193,188,70,240,151,36,206,220,142,185,89,131,120,6,241,7,58,194,158,71,92,17,138,24,111,129,223,9,92,232,202,60,42,97,214,61,96,39,16,206,
176,172,76,77,224,211,28,9,151,46,41,49,15,8,175,26,120,173,227,166,2,113,12,89,131,112,239,30,18,224,76,166,118,198,231,103,3,141,60,13,120,74,228,215,16,197,156,61,97,111,9,92,232,193,30,21,188,59,48,
38,83,135,70,13,225,27,195,188,0,203,190,58,126,130,204,27,197,111,9,120,187,228,117,196,98,204,239,129,223,9,112,209,148,225,83,14,184,4,120,131,157,24,55,132,222,29,99,130,57,78,14,176,120,106,241,167,
6,33,194,83,1,56,134,44,193,188,110,240,151,2,96,151,30,178,140,233,192,111,129,184,245,130,222,9,112,235,136,98,206,28,141,188,37,115,163,4,120,84,112,235,30,176,38,83,135,70,13,225,27,199,121,3,24,227,
167,41,188,179,6,241,91,194,92,9,148,227,166,116,228,161,131,120,187,225,46,4,202,112,169,134,206,1,188,65,206,176,107,200,235,130,49,67,13,227,172,26,240,151,52,193,47,10,178,56,169,130,48,235,131,163,
6,240,155,227,99,0,102,178,24,48,188,27,99,157,241,91,192,184,80,199,76,134,12,112,223,7,124,37,206,178,156,80,225,215,1,50,156,56,53,225,21,230,6,44,225,235,150,206,117,131,120,86,240,236,192,153,78,
29,96,222,35,120,27,197,111,9,112,38,83,133,76,54,113,27,196,30,54,121,29,113,3,22,97,190,7,124,52,225,163,29,240,169,138,152,41,128,152,117,144,115,172,27,195,222,61,226,83,2,100,28,72,114,155,227,79,
15,120,27,196,166,87,16,197,152,55,128,111,1,92,235,45,225,166,29,112,19,132,29,240,42,240,43,135,92,64,197,152,99,214,85,225,43,157,24,55,133,111,14,204,9,148,225,209,131,120,69,120,239,36,203,190,58,
96,76,167,14,176,111,17,188,119,197,223,3,14,184,152,179,13,240,59,225,46,116,101,56,84,206,156,2,98,100,28,211,6,188,157,113,163,18,97,193,112,149,192,134,105,225,91,195,214,4,226,24,235,6,240,237,145,
196,184,19,47,46,152,55,38,248,239,129,223,9,112,53,142,156,134,44,195,102,57,87,132,185,209,131,120,84,112,235,30,176,38,83,135,172,27,194,43,199,121,49,219,135,174,83,121,102,13,225,21,227,188,156,186,
103,78,33,139,48,111,30,120,75,129,12,167,10,152,117,192,39,18,231,89,107,192,184,117,135,121,38,32,120,57,219,132,174,26,49,69,225,83,13,227,214,2,113,51,172,27,195,111,9,112,38,94,30,176,222,67,38,228,
57,16,229,49,152,113,12,89,134,206,17,188,37,192,153,107,197,24,117,192,76,167,35,94,17,94,97,139,56,122,228,151,22,96,222,30,248,74,96,76,99,135,172,211,137,188,89,131,120,173,225,46,4,202,112,179,6,
156,70,241,7,129,175,33,14,2,98,204,55,131,19,120,55,52,206,248,36,195,19,89,17,226,24,107,6,240,219,200,76,187,225,235,14,38,248,211,197,111,14,77,113,12,89,131,120,27,194,92,235,45,227,87,58,114,166,
119,192,171,194,92,52,113,12,89,195,214,6,240,131,157,24,55,138,184,99,179,2,101,56,116,96,222,32,185,209,131,120,123,225,41,129,50,156,58,193,188,70,241,167,139,190,71,92,70,44,193,184,117,135,124,37,
206,179,78,29,226,166,61,112,9,198,156,116,101,56,37,112,235,14,176,1,202,28,61,97,196,175,232,87,135,102,2,113,12,117,131,120,28,18,224,76,184,117,142,29,113,56,65,224,91,192,184,104,226,24,179,14,184,
4,225,46,116,96,222,18,56,117,142,4,202,112,245,131,94,18,188,105,201,139,56,118,96,76,167,14,140,27,194,43,198,158,46,248,233,154,113,49,102,13,224,183,132,185,38,9,56,92,58,224,17,201,188,211,157,48,
167,14,177,50,195,128,24,181,195,214,61,112,151,58,50,143,10,156,61,96,39,19,29,24,55,132,111,14,240,38,92,74,226,166,2,113,219,13,25,167,138,222,18,225,172,211,0,197,152,108,224,239,132,185,38,91,197,
97,215,1,50,156,56,42,240,149,195,136,98,206,30,178,142,32,227,214,13,120,74,241,222,76,81,195,214,9,196,46,44,193,188,110,240,151,2,101,56,105,155,227,222,7,130,92,235,10,228,112,134,14,184,219,11,112,
27,137,114,76,163,157,49,166,45,112,9,196,51,163,6,240,155,230,76,188,61,97,196,174,117,157,227,214,86,224,87,29,224,78,33,139,48,111,19,132,184,19,45,229,211,131,20,206,248,21,120,75,135,92,67,22,112,
245,129,225,46,116,96,222,30,249,152,179,14,177,235,2,113,7,58,48,111,13,188,37,48,38,83,134,224,222,35,120,239,2,99,182,24,225,167,30,176,214,83,13,240,183,129,188,232,195,120,1,141,48,235,6,2,98,200,
57,215,33,57,129,139,56,122,195,132,185,214,81,226,163,195,214,4,197,12,10,231,76,27,196,223,14,242,76,188,30,93,178,204,239,129,111,9,112,215,16,197,152,108,224,27,194,92,235,6,241,219,14,177,192,153,
67,135,172,9,196,28,232,193,188,54,240,236,192,153,78,30,177,94,17,188,119,197,223,15,88,97,196,48,102,13,199,188,49,211,192,134,79,10,152,241,222,4,225,115,166,91,142,177,239,12,24,0,229,56,112,119,194,
92,232,202,60,42,60,61,96,78,93,96,222,26,120,119,146,101,225,235,148,222,117,157,226,101,223,2,225,163,136,98,204,27,192,111,132,185,214,8,241,88,117,192,76,161,195,214,10,188,37,127,71,108,58,224,38,
80,225,235,21,225,21,227,188,152,179,135,172,9,196,51,172,27,195,120,55,129,49,75,157,51,92,26,113,27,198,156,52,229,175,35,44,200,112,55,134,207,209,214,83,133,76,58,224,39,232,27,194,111,135,120,19,
44,225,235,7,132,174,89,150,241,91,195,188,53,143,89,12,89,131,120,155,225,46,73,155,114,58,224,140,166,119,192,171,194,92,52,113,12,89,134,61,96,35,148,56,112,119,194,87,58,51,79,10,143,15,88,9,196,46,
117,131,120,123,225,41,130,101,49,235,30,177,215,132,120,18,156,86,240,46,26,226,24,179,46,184,27,223,9,113,38,27,113,99,135,88,56,9,250,6,188,38,249,129,139,56,122,195,137,94,47,10,143,14,204,9,148,200,
99,172,27,196,222,58,196,184,19,46,255,0,80,161,157,240,45,225,46,26,56,134,44,195,174,1,188,37,206,176,107,194,92,52,113,12,84,195,172,122,192,78,32,231,70,13,120,109,225,217,129,50,156,61,101,60,38,
248,105,206,217,91,143,124,4,199,78,67,22,96,222,55,112,217,137,114,67,35,134,134,58,112,195,112,113,7,129,87,7,19,14,184,134,44,225,235,14,18,231,89,71,133,120,122,192,153,114,99,163,6,240,155,225,222,
73,151,131,175,208,40,96,222,43,120,75,134,140,185,12,89,131,78,1,188,37,201,50,222,71,92,4,202,24,117,192,60,65,206,176,111,29,176,235,128,153,67,135,172,92,34,188,105,193,138,241,182,2,103,108,134,40,
226,175,1,188,37,192,153,78,43,48,235,244,54,195,88,39,132,186,195,172,76,134,44,197,78,14,248,75,157,101,56,84,195,172,112,19,41,195,131,120,77,241,222,64,197,156,61,97,196,223,20,113,38,43,120,75,129,
50,153,12,89,131,120,136,240,151,36,203,200,235,130,49,67,59,224,91,194,92,235,6,188,142,184,9,148,56,112,119,194,87,141,112,169,195,214,4,195,33,142,140,27,193,111,2,224,76,167,20,98,188,70,241,183,21,
188,57,214,6,67,22,98,167,5,184,151,18,231,88,7,133,76,58,224,39,232,26,240,155,230,24,179,135,172,47,18,231,89,111,10,222,30,176,38,116,200,98,195,6,240,141,225,46,73,157,191,73,49,67,59,224,91,194,92,
52,101,50,24,179,14,184,49,67,13,240,59,225,46,26,50,153,49,83,14,177,235,1,30,32,231,70,13,195,30,58,96,76,80,224,245,131,94,37,225,137,197,111,15,89,99,196,49,102,13,224,19,141,240,214,1,225,166,74,
112,8,224,231,124,13,120,75,135,92,64,197,156,61,97,120,75,157,24,55,133,112,235,30,176,38,83,38,58,48,111,9,94,29,228,14,93,63,65,102,13,226,183,132,184,19,41,144,197,152,108,224,27,194,92,235,5,188,
37,192,153,78,21,48,217,192,39,16,115,172,26,241,219,14,184,9,130,28,61,101,223,9,92,233,195,222,43,112,235,30,176,49,214,67,22,24,55,244,37,192,152,167,14,13,201,112,142,52,240,237,224,92,90,226,24,179,
146,222,18,231,89,71,133,76,58,224,39,232,27,194,111,152,98,206,15,36,222,117,131,120,86,240,148,192,153,76,134,44,193,188,70,240,151,36,253,1,215,16,197,76,26,112,13,226,14,117,131,94,71,92,17,148,56,
112,119,196,188,189,226,167,7,88,9,196,28,29,101,188,5,225,46,4,202,112,122,195,136,222,52,240,107,142,152,184,135,232,45,240,151,58,203,120,87,14,184,9,250,6,188,37,112,226,24,179,135,172,56,75,157,99,
179,133,111,9,76,9,148,225,209,131,120,141,225,222,73,151,124,186,113,49,102,27,226,183,137,114,76,183,145,215,37,12,55,192,239,132,184,104,202,112,169,135,88,225,78,32,231,70,42,113,219,131,102,72,100,
15,6,111,23,9,92,25,154,120,94,30,176,166,6,242,98,204,183,131,111,9,114,107,46,248,92,58,224,56,239,129,175,9,112,235,136,98,206,30,176,225,46,117,150,240,174,29,99,214,4,202,28,58,48,111,8,175,29,228,
49,120,233,250,11,48,111,21,188,37,192,153,78,93,56,152,161,131,120,187,225,46,4,202,112,169,135,92,2,112,2,231,70,13,199,59,97,215,2,24,161,195,214,61,240,149,193,214,105,196,152,168,240,245,151,56,134,
44,193,188,77,241,177,134,53,195,138,112,214,117,131,197,111,9,135,16,197,156,156,37,206,178,222,21,48,235,28,9,151,145,94,7,7,121,3,22,112,245,201,7,44,193,188,42,60,37,192,153,78,22,96,211,136,222,6,
241,119,194,92,9,148,225,83,14,184,6,241,167,130,158,7,32,152,165,228,119,192,185,214,81,195,21,195,30,178,177,222,38,116,96,220,53,143,124,56,19,41,195,134,222,38,40,96,142,38,176,67,131,114,198,26,193,
166,67,22,96,222,60,240,151,58,203,120,84,195,174,2,101,228,107,194,87,14,33,139,49,239,30,176,188,37,206,140,183,133,111,14,204,9,148,225,214,13,226,55,141,57,38,118,228,19,41,194,204,27,196,111,29,228,
206,220,142,184,140,89,131,112,239,14,241,235,18,231,70,83,133,76,241,192,38,29,231,124,13,195,88,239,37,49,192,152,179,22,61,97,194,87,142,248,173,197,153,182,81,194,23,46,21,49,51,78,9,114,76,188,56,
117,192,126,129,223,9,112,235,136,98,204,49,194,222,18,230,152,35,197,92,58,199,172,9,148,225,235,6,240,141,227,188,134,60,58,126,129,102,13,226,55,142,242,101,223,233,33,139,48,111,7,124,37,192,152,37,
225,166,13,56,4,195,188,151,29,24,53,227,206,29,99,129,49,67,7,30,179,183,132,175,2,60,43,195,214,2,113,12,92,43,194,39,4,188,20,120,93,97,215,19,124,119,197,223,9,112,215,16,197,152,117,193,223,9,115,
172,183,134,225,215,0,153,78,30,176,87,132,175,48,197,156,61,114,131,139,48,111,13,188,37,192,152,174,58,114,140,89,131,120,187,225,46,4,202,112,169,134,206,1,30,52,231,88,53,226,111,14,177,192,12,89,
155,112,60,18,231,70,3,244,30,178,135,47,29,24,55,135,188,236,201,172,9,151,142,184,184,59,224,175,21,188,37,48,167,16,197,152,55,130,222,18,224,76,183,135,14,184,9,199,124,45,120,69,112,235,136,98,204,
49,235,1,30,18,231,70,13,225,239,132,166,4,202,112,232,193,188,67,29,96,222,27,120,75,129,50,156,44,193,188,70,241,223,23,124,58,97,215,0,98,204,219,135,190,18,225,172,166,61,226,166,29,99,128,153,102,
105,199,172,223,27,184,117,192,76,89,195,214,3,133,23,41,143,92,43,120,236,192,174,33,139,48,111,30,120,75,146,101,228,117,192,126,129,175,9,112,209,194,23,22,97,214,61,97,71,132,174,116,96,222,59,97,
214,61,96,76,167,14,140,27,194,43,199,121,12,188,59,48,38,83,135,172,87,136,222,52,241,219,142,156,161,139,48,111,7,124,37,193,12,166,61,226,204,58,195,188,6,227,222,105,224,107,192,193,76,27,144,198,
100,114,204,59,225,43,157,101,28,76,84,120,11,145,14,33,142,140,91,226,111,135,120,19,47,14,29,113,56,239,138,222,18,225,174,33,139,48,223,0,142,121,196,185,209,131,121,29,112,19,41,195,214,13,120,74,
241,167,33,140,112,245,149,196,49,235,6,240,138,241,167,133,111,15,89,167,19,22,96,222,60,240,151,2,101,56,84,197,174,35,113,239,52,240,59,227,190,29,112,19,22,114,155,134,18,231,70,65,195,21,30,30,176,
39,8,115,163,130,226,111,132,184,19,1,195,215,41,188,179,59,226,239,132,184,19,136,98,204,27,193,223,9,115,172,166,58,49,214,29,112,70,83,59,224,107,194,43,135,92,67,22,112,245,148,113,46,116,96,222,59,
115,49,103,15,88,19,136,99,172,27,195,111,9,76,9,148,225,209,138,241,27,198,156,13,229,223,3,11,56,5,197,152,239,129,223,9,115,163,40,240,169,131,172,184,31,160,111,9,188,50,25,163,30,15,92,130,241,223,
10,240,245,129,56,134,44,193,188,70,241,222,4,202,112,225,196,197,51,190,5,94,18,225,163,136,98,204,58,199,172,171,194,92,232,193,188,54,225,214,61,96,76,167,15,88,8,241,7,58,193,188,61,240,148,192,153,
78,27,49,94,37,120,211,197,111,42,51,182,67,20,48,111,27,184,119,137,113,214,83,133,76,58,224,19,137,114,176,239,132,174,29,99,130,98,76,137,136,152,37,225,43,157,101,30,21,30,15,88,19,151,88,55,136,222,
18,224,76,167,14,28,76,179,154,222,54,195,71,16,197,152,52,224,225,46,117,131,94,71,92,4,202,112,245,131,94,18,188,107,134,220,58,199,2,101,14,30,177,94,17,94,52,240,169,195,214,4,226,24,179,6,241,71,
27,24,19,41,194,166,24,247,128,222,52,228,194,175,4,97,163,136,98,76,171,131,135,120,152,151,58,50,143,10,152,117,143,88,9,198,156,53,131,120,74,229,202,97,50,56,122,195,137,198,158,43,120,75,129,56,134,
40,96,222,35,120,75,157,101,223,46,156,17,148,48,223,3,94,18,225,196,49,103,15,88,8,229,14,30,176,85,225,43,198,158,22,112,245,129,56,133,206,140,27,195,111,9,112,38,83,13,99,172,183,136,222,52,241,219,
147,17,129,14,33,139,50,153,76,27,141,196,185,209,148,193,197,76,148,196,152,9,198,179,163,6,188,37,112,192,214,67,18,101,92,122,228,149,205,48,15,10,143,15,88,19,136,98,204,27,196,111,14,242,79,208,116,
226,111,40,103,124,11,120,75,134,142,33,139,48,235,128,111,16,115,163,6,240,151,13,25,222,67,22,97,214,61,96,78,32,231,88,55,134,222,29,152,19,20,56,122,197,120,43,134,156,123,202,222,58,97,174,28,81,
133,101,193,110,61,98,92,9,148,197,151,135,92,2,112,135,129,174,56,13,195,174,0,49,103,1,131,139,137,115,163,40,240,168,240,236,192,76,179,46,40,48,110,86,93,240,220,235,59,224,152,245,202,111,22,96,222,
43,120,75,129,12,185,12,89,134,206,1,188,37,206,176,107,197,97,215,1,49,67,14,184,7,136,57,209,131,94,27,112,235,128,153,67,135,172,87,132,87,141,60,43,199,102,108,56,134,89,131,120,243,142,37,192,153,
76,52,227,172,56,141,203,48,142,36,193,87,129,115,76,112,200,206,204,67,130,185,88,222,0,25,24,183,21,28,10,100,76,9,148,192,99,214,13,225,27,195,188,0,197,156,42,25,182,58,205,156,235,6,240,173,225,41,
129,50,153,12,89,131,78,1,188,32,228,153,107,200,235,130,50,134,119,192,171,194,92,235,6,188,142,184,9,138,28,61,96,171,194,87,58,51,79,10,156,61,96,39,16,206,140,28,90,99,223,9,112,38,9,120,235,139,136,
220,185,222,38,242,183,149,204,115,76,89,131,120,59,196,184,224,167,51,24,105,139,112,19,128,112,55,132,174,60,64,197,156,61,114,217,200,100,225,124,37,48,38,83,33,139,48,111,17,188,37,201,63,64,117,202,
134,119,192,183,132,184,104,203,144,197,152,117,192,101,196,12,69,102,32,51,200,201,172,216,57,180,49,222,166,220,28,196,38,118,96,6,66,41,146,204,216,184,196,184,77,78,29,152,19,41,195,214,43,198,207,
26,120,173,224,83,40,49,41,144,197,152,55,134,238,37,224,9,135,10,152,108,200,101,153,28,142,71,10,188,19,14,32,98,204,186,200,184,39,8,196,67,40,241,27,134,61,96,76,113,12,89,131,120,77,240,151,32,114,
179,10,186,203,56,94,0,227,29,229,39,94,112,152,145,232,226,56,8,200,199,179,53,144,79,76,1,220,196,7,171,155,51,172,22,229,214,53,115,181,203,185,225,237,149,130,142,177,163,5,180,194,60,101,22,204,176,
214,23,227,5,27,142,223,56,116,199,102,93,220,70,90,99,214,42,240,149,227,79,10,152,119,143,88,19,19,33,139,51,110,55,113,46,43,12,9,195,172,58,226,113,167,139,190,18,225,103,16,197,152,112,119,194,92,
232,203,120,87,14,3,158,176,111,15,121,110,59,200,24,240,122,229,55,150,96,220,219,59,112,95,67,20,38,37,114,230,134,26,230,157,101,78,142,3,169,151,119,54,113,117,142,217,111,4,205,225,193,223,12,194,
115,219,14,177,235,9,121,112,183,142,216,117,198,179,124,61,114,213,206,220,249,205,99,166,19,150,225,120,243,250,55,203,167,26,191,160,239,134,97,215,45,195,174,14,248,215,27,191,160,225,56,222,61,114,
123,253,13,225,235,150,179,120,94,60,240,204,39,232,116,227,87,244,22,231,255,217,0,0};

const char* MainViewTabConfiguration::background2_jpg = (const char*) resource_MainViewTabConfiguration_background2_jpg;
const int MainViewTabConfiguration::background2_jpgSize = 110571;


//[EndFile] You can add extra defines here...
//[/EndFile]

