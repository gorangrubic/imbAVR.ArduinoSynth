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

#include "MainViewTabTools.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainViewTabTools::MainViewTabTools (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    group_IO.reset (new GroupComponent ("new group",
                                        TRANS("Synth state & tools")));
    addAndMakeVisible (group_IO.get());
    group_IO->setTextLabelPosition (Justification::centredLeft);
    group_IO->setColour (GroupComponent::outlineColourId, Colour (0x008e989b));

    group_IO->setBounds (408, 16, 280, 108);

    group_MIDITEST.reset (new GroupComponent ("new group",
                                              TRANS("MIDI test loop")));
    addAndMakeVisible (group_MIDITEST.get());
    group_MIDITEST->setTextLabelPosition (Justification::centredLeft);
    group_MIDITEST->setColour (GroupComponent::outlineColourId, Colour (0x008e989b));

    Read.reset (new TextButton ("new button"));
    addAndMakeVisible (Read.get());
    Read->setButtonText (TRANS("Read hardware"));
    Read->addListener (this);
    Read->setColour (TextButton::buttonColourId, Colour (0xff181f22));

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
    slider_noteDuration->setColour (Slider::thumbColourId, Colour (0xff397daa));
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
    slider_noteDuration2->setColour (Slider::thumbColourId, Colour (0xff397daa));
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
    slider_bpm->setColour (Slider::thumbColourId, Colour (0xff397daa));
    slider_bpm->setColour (Slider::textBoxTextColourId, Colours::azure);
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

    Pitch.reset (new Slider ("new slider"));
    addAndMakeVisible (Pitch.get());
    Pitch->setRange (-12, 12, 1);
    Pitch->setSliderStyle (Slider::LinearHorizontal);
    Pitch->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    Pitch->setColour (Slider::thumbColourId, Colours::azure);
    Pitch->setColour (Slider::textBoxTextColourId, Colours::azure);
    Pitch->setColour (Slider::textBoxHighlightColourId, Colour (0x0042a2c8));
    Pitch->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    Pitch->addListener (this);

    label5.reset (new Label ("new label",
                             TRANS("Pitch")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Velocity.reset (new Slider ("new slider"));
    addAndMakeVisible (Velocity.get());
    Velocity->setRange (0, 100, 1);
    Velocity->setSliderStyle (Slider::LinearHorizontal);
    Velocity->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Velocity->setColour (Slider::thumbColourId, Colour (0xff397daa));
    Velocity->setColour (Slider::textBoxTextColourId, Colours::cadetblue);
    Velocity->addListener (this);

    label4.reset (new Label ("new label",
                             TRANS("Velocity")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Write.reset (new TextButton ("new button"));
    addAndMakeVisible (Write.get());
    Write->setButtonText (TRANS("Write hardware"));
    Write->addListener (this);
    Write->setColour (TextButton::buttonColourId, Colour (0xff1d2427));

    SaveFile.reset (new TextButton ("new button"));
    addAndMakeVisible (SaveFile.get());
    SaveFile->setButtonText (TRANS("Save to file"));
    SaveFile->addListener (this);
    SaveFile->setColour (TextButton::buttonColourId, Colour (0xff1d2427));

    ReadFile.reset (new TextButton ("new button"));
    addAndMakeVisible (ReadFile.get());
    ReadFile->setButtonText (TRANS("Read from file"));
    ReadFile->addListener (this);
    ReadFile->setColour (TextButton::buttonColourId, Colour (0xff1d2427));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (840, 340);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainViewTabTools::~MainViewTabTools()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    group_IO = nullptr;
    group_MIDITEST = nullptr;
    Read = nullptr;
    toggleButton = nullptr;
    slider_noteDuration = nullptr;
    label = nullptr;
    slider_noteDuration2 = nullptr;
    label2 = nullptr;
    slider_bpm = nullptr;
    label3 = nullptr;
    Pitch = nullptr;
    label5 = nullptr;
    Velocity = nullptr;
    label4 = nullptr;
    Write = nullptr;
    SaveFile = nullptr;
    ReadFile = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainViewTabTools::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainViewTabTools::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    group_MIDITEST->setBounds (0, 16, 400, getHeight() - 0);
    Read->setBounds (408 + 15, 16 + 32, 120, 24);
    toggleButton->setBounds (0 + 16, 16 + 288, 150, 24);
    slider_noteDuration->setBounds (0 + 400 - 4 - 260, 16 + 104, 260, 24);
    label->setBounds ((0 + 400 - 4 - 260) + 0 - 100, (16 + 104) + 0, 100, 24);
    slider_noteDuration2->setBounds (0 + 400 - 4 - 260, 16 + 136, 260, 24);
    label2->setBounds ((0 + 400 - 4 - 260) + 0 - 100, (16 + 136) + -8, 100, 24);
    slider_bpm->setBounds (0 + 400 - 4 - 260, 16 + 192, 260, 36);
    label3->setBounds ((0 + 400 - 4 - 260) + 0 - 100, (16 + 192) + 0, 100, 24);
    Pitch->setBounds (0 + 400 - 4 - 260, 16 + 56, 260, 42);
    label5->setBounds ((0 + 400 - 4 - 260) + 0 - 100, (16 + 104) + -47, 100, 36);
    Velocity->setBounds (0 + 400 - 4 - 260, 16 + 24, 260, 24);
    label4->setBounds ((0 + 400 - 4 - 260) + -1 - 100, (16 + 104) + -77, 100, 24);
    Write->setBounds (408 + 15, 16 + 64, 120, 24);
    SaveFile->setBounds (408 + 143, 16 + 32, 120, 24);
    ReadFile->setBounds (408 + 143, 16 + 64, 120, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainViewTabTools::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == Read.get())
    {
        //[UserButtonCode_Read] -- add your button handler code here..
        //[/UserButtonCode_Read]
    }
    else if (buttonThatWasClicked == toggleButton.get())
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
        //[/UserButtonCode_toggleButton]
    }
    else if (buttonThatWasClicked == Write.get())
    {
        //[UserButtonCode_Write] -- add your button handler code here..
        //[/UserButtonCode_Write]
    }
    else if (buttonThatWasClicked == SaveFile.get())
    {
        //[UserButtonCode_SaveFile] -- add your button handler code here..
        //[/UserButtonCode_SaveFile]
    }
    else if (buttonThatWasClicked == ReadFile.get())
    {
        //[UserButtonCode_ReadFile] -- add your button handler code here..
        //[/UserButtonCode_ReadFile]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MainViewTabTools::sliderValueChanged (Slider* sliderThatWasMoved)
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
    else if (sliderThatWasMoved == Pitch.get())
    {
        //[UserSliderCode_Pitch] -- add your slider handling code here..
        //[/UserSliderCode_Pitch]
    }
    else if (sliderThatWasMoved == Velocity.get())
    {
        //[UserSliderCode_Velocity] -- add your slider handling code here..
        //[/UserSliderCode_Velocity]
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

<JUCER_COMPONENT documentType="Component" className="MainViewTabTools" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="840" initialHeight="340">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="new group" id="d44bfedad95ee328" memberName="group_IO"
                  virtualName="" explicitFocusOrder="0" pos="408 16 280 108" outlinecol="8e989b"
                  title="Synth state &amp; tools" textpos="33"/>
  <GROUPCOMPONENT name="new group" id="532fe1565902977" memberName="group_MIDITEST"
                  virtualName="" explicitFocusOrder="0" pos="0 16 400 0M" outlinecol="8e989b"
                  title="MIDI test loop" textpos="33"/>
  <TEXTBUTTON name="new button" id="1eaf3791f3ec0d8" memberName="Read" virtualName=""
              explicitFocusOrder="0" pos="15 32 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ff181f22" buttonText="Read hardware"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="new toggle button" id="f247140d4b3ed493" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="16 288 150 24" posRelativeX="532fe1565902977"
                posRelativeY="532fe1565902977" buttonText="Enable test loop"
                connectedEdges="4" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="new slider" id="b894ad866522ab7a" memberName="slider_noteDuration"
          virtualName="" explicitFocusOrder="0" pos="4Rr 104 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ff397daa" textboxtext="ff5f9ea0"
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
          virtualName="" explicitFocusOrder="0" pos="4Rr 136 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ff397daa" textboxtext="ff5f9ea0"
          min="0.0" max="16.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="2d31deb9a14e9516" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0r -8 100 24" posRelativeX="b894ad866522ab7a"
         posRelativeY="8cdab6a4a52521ea" edTextCol="ff000000" edBkgCol="0"
         labelText="Loop duration" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="90b8d711ec3b5129" memberName="slider_bpm"
          virtualName="" explicitFocusOrder="0" pos="4Rr 192 260 36" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ff397daa" textboxtext="fff0ffff"
          textboxoutline="ff3c3c3c" min="120.0" max="145.0" int="1.0" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="3bffceec306bf2af" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="0r 0 100 24" posRelativeX="90b8d711ec3b5129"
         posRelativeY="90b8d711ec3b5129" edTextCol="ff000000" edBkgCol="0"
         labelText="BPM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="6dcb364d4a3d77a4" memberName="Pitch" virtualName=""
          explicitFocusOrder="0" pos="4Rr 56 260 42" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="fff0ffff" textboxtext="fff0ffff"
          textboxhighlight="42a2c8" textboxoutline="8e989b" min="-12.0"
          max="12.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a4b00718571d2318" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0r -47 100 36" posRelativeX="b894ad866522ab7a"
         posRelativeY="b894ad866522ab7a" edTextCol="ff000000" edBkgCol="0"
         labelText="Pitch" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="fcff0307f3220069" memberName="Velocity"
          virtualName="" explicitFocusOrder="0" pos="4Rr 24 260 24" posRelativeX="532fe1565902977"
          posRelativeY="532fe1565902977" thumbcol="ff397daa" textboxtext="ff5f9ea0"
          min="0.0" max="100.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="91e9398673c967bd" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="-1r -77 100 24" posRelativeX="b894ad866522ab7a"
         posRelativeY="b894ad866522ab7a" edTextCol="ff000000" edBkgCol="0"
         labelText="Velocity" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="895ac3ceb43dfbef" memberName="Write" virtualName=""
              explicitFocusOrder="0" pos="15 64 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ff1d2427" buttonText="Write hardware"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="43d3cf409c52e4d5" memberName="SaveFile"
              virtualName="" explicitFocusOrder="0" pos="143 32 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ff1d2427" buttonText="Save to file"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="58806260c847b610" memberName="ReadFile"
              virtualName="" explicitFocusOrder="0" pos="143 64 120 24" posRelativeX="d44bfedad95ee328"
              posRelativeY="d44bfedad95ee328" bgColOff="ff1d2427" buttonText="Read from file"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

