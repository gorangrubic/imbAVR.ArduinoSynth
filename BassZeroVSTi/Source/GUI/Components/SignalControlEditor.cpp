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
#include "../Source/GUI/Components/imbSynthGUIComponent.h"

//[/Headers]

#include "SignalControlEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SignalControlEditor::SignalControlEditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
	Deploy(nameSufix.toStdString(), this, synthState);
    //[/Constructor_pre]

    PitchModulation.reset (new SignalChangeEditor (synthState,NameString_Pitch,nameSufix));
    addAndMakeVisible (PitchModulation.get());
    PulsePattern.reset (new PatternEditor8bit());
    addAndMakeVisible (PulsePattern.get());
    PulsePattern->setBounds (136, 208, 110, 16);

    PhaseModulation.reset (new SignalChangeEditor (synthState, NameString_Phase,nameSufix));
    addAndMakeVisible (PhaseModulation.get());
    PhaseModulation->setBounds (8, 48, 112, 130);

    PWMModulation.reset (new SignalChangeEditor (synthState, NameString_PWM,nameSufix));
    addAndMakeVisible (PWMModulation.get());
    ModBytePattern.reset (new PatternEditor8bit());
    addAndMakeVisible (ModBytePattern.get());
    ModBytePattern->setBounds (136, 248, 110, 16);

    label3.reset (new Label ("new label",
                             TRANS("Mod byte")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (136, 232, 132, 12);

    label2.reset (new Label ("new label",
                             TRANS("PHASE\n")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::backgroundColourId, Colour (0xff42a2c8));
    label2->setColour (Label::textColourId, Colours::azure);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4.reset (new Label ("new label",
                             TRANS("PWM")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (Label::backgroundColourId, Colour (0xff42a2c8));
    label4->setColour (Label::textColourId, Colours::azure);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5.reset (new Label ("new label",
                             TRANS("PITCH")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (10.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (Label::backgroundColourId, Colour (0xff42a2c8));
    label5->setColour (Label::textColourId, Colours::azure);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6.reset (new Label ("new label",
                             TRANS("Waveform Pattern")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (136, 192, 132, 12);

    label_SignalName.reset (new Label ("new label",
                                       TRANS("WF A")));
    addAndMakeVisible (label_SignalName.get());
    label_SignalName->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
    label_SignalName->setJustificationType (Justification::centredLeft);
    label_SignalName->setEditable (false, false, false);
    label_SignalName->setColour (Label::backgroundColourId, Colour (0xff42a2c8));
    label_SignalName->setColour (Label::textColourId, Colours::azure);
    label_SignalName->setColour (TextEditor::textColourId, Colours::black);
    label_SignalName->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (256, 330);


    //[Constructor] You can add your own custom stuff here..
	//modelComponent = synthState->model->opmControl.GetSignalUnit(nameSufix);
	modelComponent = std::shared_ptr<OscilatorBase>(synthState->model->GetMemberByPath<OscilatorBase>(NameSuffix));
	SetEnabled(modelComponent->Enabled.GetBoolValue(), modelComponent == nullptr);

	if (!isInErrorState) {
		auto entry = synthState->environment->enums.enum_oscilatorTypes.FindEntry((int)modelComponent->type);
		if (entry != nullptr)
		{
			if (!entry->entryColorHex.empty()) label_SignalName->setColour(Label::backgroundColourId, entry->GetEntryColor());
		}
		label_SignalName->setText(modelComponent->parameterLabel, juce::NotificationType::dontSendNotification);
	}
	else {
		label_SignalName->setText("::GUI ERROR::", juce::NotificationType::dontSendNotification);
	}

    //[/Constructor]
}

SignalControlEditor::~SignalControlEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    PitchModulation = nullptr;
    PulsePattern = nullptr;
    PhaseModulation = nullptr;
    PWMModulation = nullptr;
    ModBytePattern = nullptr;
    label3 = nullptr;
    label2 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    label_SignalName = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SignalControlEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SignalControlEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    PitchModulation->setBounds ((8 + 120) + -120, (48 + 130 - 130) + 130 - -14, 112, 130);
    PWMModulation->setBounds (8 + 120, 48 + 130 - 130, 112, 130);
    label2->setBounds (8 + 0, 48 + -8, 76, 12);
    label4->setBounds ((8 + 120) + 0, (48 + 130 - 130) + -8, 76, 12);
    label5->setBounds (((8 + 120) + -120) + 0, ((48 + 130 - 130) + 130 - -14) + -8, 76, 12);
    label_SignalName->setBounds (8, 8, getWidth() - 16, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SignalControlEditor" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="256" initialHeight="330">
  <BACKGROUND backgroundColour="323e44"/>
  <JUCERCOMP name="PitchModulation" id="7f1d0d3bdc7671de" memberName="PitchModulation"
             virtualName="" explicitFocusOrder="0" pos="-120 -14R 112 130"
             posRelativeX="8f92a8fb69d2fac7" posRelativeY="8f92a8fb69d2fac7"
             sourceFile="SignalChangeEditor.cpp" constructorParams="synthState,NameString_Pitch,nameSufix"/>
  <JUCERCOMP name="PulsePattern" id="3ab1288f6225dbb5" memberName="PulsePattern"
             virtualName="" explicitFocusOrder="0" pos="136 208 110 16" sourceFile="../General/PatternEditor8bit.cpp"
             constructorParams=""/>
  <JUCERCOMP name="PhaseModulation" id="6f9f204dacc67317" memberName="PhaseModulation"
             virtualName="" explicitFocusOrder="0" pos="8 48 112 130" sourceFile="SignalChangeEditor.cpp"
             constructorParams="synthState, NameString_Phase,nameSufix"/>
  <JUCERCOMP name="PWMModulation" id="8f92a8fb69d2fac7" memberName="PWMModulation"
             virtualName="" explicitFocusOrder="0" pos="120 130R 112 130"
             posRelativeX="6f9f204dacc67317" posRelativeY="6f9f204dacc67317"
             sourceFile="SignalChangeEditor.cpp" constructorParams="synthState, NameString_PWM,nameSufix"/>
  <JUCERCOMP name="ModBytePattern" id="cf23902432a626a5" memberName="ModBytePattern"
             virtualName="" explicitFocusOrder="0" pos="136 248 110 16" sourceFile="../General/PatternEditor8bit.cpp"
             constructorParams=""/>
  <LABEL name="new label" id="89a0af3ad6e90739" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="136 232 132 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Mod byte" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="995d370610ffd3e1" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 -8 76 12" posRelativeX="6f9f204dacc67317"
         posRelativeY="6f9f204dacc67317" bkgCol="ff42a2c8" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="PHASE&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="1c22575993c3197d" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="0 -8 76 12" posRelativeX="8f92a8fb69d2fac7"
         posRelativeY="8f92a8fb69d2fac7" bkgCol="ff42a2c8" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="PWM" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a5a86cc31d79c916" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0 -8 76 12" posRelativeX="7f1d0d3bdc7671de"
         posRelativeY="7f1d0d3bdc7671de" bkgCol="ff42a2c8" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="PITCH" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="4001d2e0ab753430" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="136 192 132 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Waveform Pattern" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="889b1fc075c6113d" memberName="label_SignalName"
         virtualName="" explicitFocusOrder="0" pos="8 8 16M 24" bkgCol="ff42a2c8"
         textCol="fff0ffff" edTextCol="ff000000" edBkgCol="0" labelText="WF A"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="14.0" kerning="0.0" bold="1"
         italic="0" justification="33" typefaceStyle="Bold"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

