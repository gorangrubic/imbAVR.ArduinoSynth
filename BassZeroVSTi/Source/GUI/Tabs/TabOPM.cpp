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

#include "TabOPM.h"
#include "../Components/SignalControlEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabOPM::TabOPM (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..

    tabbedComponent.reset (new TabbedComponent (TabbedButtonBar::TabsAtBottom));
    addAndMakeVisible (tabbedComponent.get());
    tabbedComponent->setTabBarDepth (30);
    tabbedComponent->addTab (TRANS("WF A"), Colour (0x00d3d3d3), new SignalControlEditor (synthState, "WFA_OSC"), true);
    tabbedComponent->addTab (TRANS("WF B"), Colour (0x00d3d3d3), new SignalControlEditor (synthState, "WFB_OSC"), true);
    tabbedComponent->addTab (TRANS("FLT"), Colour (0x00d3d3d3), new SignalControlEditor (synthState, "FLT_OSC"), true);
    tabbedComponent->addTab (TRANS("PERK A"), Colour (0x00d3d3d3), new SignalControlEditor (synthState, "PERKA_OSC"), true);
    tabbedComponent->addTab (TRANS("PERK B"), Colour (0x00d3d3d3), new SignalControlEditor (synthState, "PERKB_OSC"), true);
    tabbedComponent->setCurrentTabIndex (0);

    tabbedComponent->setBounds (0, 0, 508, 360);
    //[/Constructor_pre]

    MacroControls.reset (new OPMEditor (synthState, "MacroControls"));
    addAndMakeVisible (MacroControls.get());
    MacroControls->setBounds (560, 0, 280, 360);

    tabbedComponent.reset (new TabbedComponent (TabbedButtonBar::TabsAtLeft));
    addAndMakeVisible (tabbedComponent.get());
    tabbedComponent->setTabBarDepth (80);
    tabbedComponent->addTab (TRANS("Tab 0"), Colour (0xff181f22), new SignalControlEditor(), true);
    tabbedComponent->addTab (TRANS("Tab 1"), Colours::lightgrey, 0, false);
    tabbedComponent->addTab (TRANS("Tab 2"), Colour (0xff181f22), 0, false);
    tabbedComponent->setCurrentTabIndex (0);

    Title2.reset (new Label ("new label",
                             TRANS("MOD B")));
    addAndMakeVisible (Title2.get());
    Title2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title2->setJustificationType (Justification::centred);
    Title2->setEditable (false, false, false);
    Title2->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title2->setColour (Label::textColourId, Colour (0xff181f22));
    Title2->setColour (TextEditor::textColourId, Colours::black);
    Title2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title2->setBounds (456, 8, 96, 16);

    VALA.reset (new Slider ("DirectValue"));
    addAndMakeVisible (VALA.get());
    VALA->setTooltip (TRANS("Decay time\n"));
    VALA->setRange (1, 100, 1);
    VALA->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    VALA->setTextBoxStyle (Slider::NoTextBox, true, 50, 10);
    VALA->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    VALA->addListener (this);

    VALA->setBounds (352, 168, 64, 68);

    Title5.reset (new Label ("new label",
                             TRANS("VAL A")));
    addAndMakeVisible (Title5.get());
    Title5->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title5->setJustificationType (Justification::centred);
    Title5->setEditable (false, false, false);
    Title5->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title5->setColour (Label::textColourId, Colour (0xff181f22));
    Title5->setColour (TextEditor::textColourId, Colours::black);
    Title5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title5->setBounds (352, 152, 64, 16);

    Title6.reset (new Label ("new label",
                             TRANS("MOD A")));
    addAndMakeVisible (Title6.get());
    Title6->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title6->setJustificationType (Justification::centred);
    Title6->setEditable (false, false, false);
    Title6->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title6->setColour (Label::textColourId, Colour (0xff181f22));
    Title6->setColour (TextEditor::textColourId, Colours::black);
    Title6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title6->setBounds (352, 8, 96, 16);

    OPM_MODA.reset (new SourceMixerComponent (synthState, "OPM_MODA"));
    addAndMakeVisible (OPM_MODA.get());
    OPM_MODA->setBounds (352, 24, 96, 96);

    OPM_MODB.reset (new SourceMixerComponent (synthState, "OPM_MODB"));
    addAndMakeVisible (OPM_MODB.get());
    OPM_MODB->setBounds (456, 24, 96, 96);

    VALB.reset (new Slider ("DirectValue"));
    addAndMakeVisible (VALB.get());
    VALB->setTooltip (TRANS("Decay time\n"));
    VALB->setRange (1, 100, 1);
    VALB->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    VALB->setTextBoxStyle (Slider::NoTextBox, true, 50, 10);
    VALB->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    VALB->addListener (this);

    VALB->setBounds (416, 168, 64, 68);

    Title3.reset (new Label ("new label",
                             TRANS("VAL B")));
    addAndMakeVisible (Title3.get());
    Title3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title3->setJustificationType (Justification::centred);
    Title3->setEditable (false, false, false);
    Title3->setColour (Label::backgroundColourId, Colours::azure);
    Title3->setColour (Label::textColourId, Colour (0xff181f22));
    Title3->setColour (TextEditor::textColourId, Colours::black);
    Title3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title3->setBounds (416, 152, 64, 16);

    VALC.reset (new Slider ("DirectValue"));
    addAndMakeVisible (VALC.get());
    VALC->setTooltip (TRANS("Decay time\n"));
    VALC->setRange (1, 100, 1);
    VALC->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    VALC->setTextBoxStyle (Slider::NoTextBox, true, 50, 10);
    VALC->setColour (Slider::textBoxOutlineColourId, Colour (0x008e989b));
    VALC->addListener (this);

    VALC->setBounds (480, 168, 64, 68);

    Title4.reset (new Label ("new label",
                             TRANS("VAL C")));
    addAndMakeVisible (Title4.get());
    Title4->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title4->setJustificationType (Justification::centred);
    Title4->setEditable (false, false, false);
    Title4->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title4->setColour (Label::textColourId, Colour (0xff181f22));
    Title4->setColour (TextEditor::textColourId, Colours::black);
    Title4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title4->setBounds (480, 152, 64, 16);


    //[UserPreSize]
	//MODA_MCL1.reset(new OPMToSignalChangeEditor(synthState, "MODA_MCL1"));
	//addAndMakeVisible(MODA_MCL1.get());
	//MODB_MCL1.reset(new OPMToSignalChangeEditor(synthState, "MODB_MCL1"));
	//addAndMakeVisible(MODB_MCL1.get());
	//VALC_MCL1.reset(new OPMToSignalChangeEditor(synthState, "VALC_MCL1"));
	//addAndMakeVisible(VALC_MCL1.get());
	//VALC_MCL2.reset(new OPMToSignalChangeEditor(synthState, "VALC_MCL2"));
	//addAndMakeVisible(VALC_MCL2.get());
	//MODA_MCL2.reset(new OPMToSignalChangeEditor(synthState, "MODA_MCL2"));
	//addAndMakeVisible(MODA_MCL2.get());
	//MODB_MCL2.reset(new OPMToSignalChangeEditor(synthState, "MODB_MCL2"));
	//addAndMakeVisible(MODB_MCL2.get());
    //[/UserPreSize]

    setSize (840, 360);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TabOPM::~TabOPM()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    MacroControls = nullptr;
    tabbedComponent = nullptr;
    Title2 = nullptr;
    VALA = nullptr;
    Title5 = nullptr;
    Title6 = nullptr;
    OPM_MODA = nullptr;
    OPM_MODB = nullptr;
    VALB = nullptr;
    Title3 = nullptr;
    VALC = nullptr;
    Title4 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TabOPM::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TabOPM::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    tabbedComponent->setBounds (0, 0, 340, getHeight() - 0);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TabOPM::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == VALA.get())
    {
        //[UserSliderCode_VALA] -- add your slider handling code here..
        //[/UserSliderCode_VALA]
    }
    else if (sliderThatWasMoved == VALB.get())
    {
        //[UserSliderCode_VALB] -- add your slider handling code here..
        //[/UserSliderCode_VALB]
    }
    else if (sliderThatWasMoved == VALC.get())
    {
        //[UserSliderCode_VALC] -- add your slider handling code here..
        //[/UserSliderCode_VALC]
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

<JUCER_COMPONENT documentType="Component" className="TabOPM" componentName=""
                 parentClasses="public Component" constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="840" initialHeight="360">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="MacroControls" id="1aa1163e1a769e07" memberName="MacroControls"
             virtualName="" explicitFocusOrder="0" pos="560 0 280 360" sourceFile="../Components/OPMEditor.cpp"
             constructorParams="synthState, &quot;MacroControls&quot;"/>
  <TABBEDCOMPONENT name="new tabbed component" id="f3265a66e5be8d09" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="0 0 340 0M" orientation="left"
                   tabBarDepth="80" initialTab="0">
    <TAB name="Tab 0" colour="ff181f22" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="../Components/SignalControlEditor.cpp"/>
    <TAB name="Tab 1" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Tab 2" colour="ff181f22" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <LABEL name="new label" id="ebca27112e99bb6c" memberName="Title2" virtualName=""
         explicitFocusOrder="0" pos="456 8 96 16" bkgCol="fff0f8ff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="MOD B" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="f29fd8d619498ce" memberName="VALA" virtualName=""
          explicitFocusOrder="0" pos="352 168 64 68" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" textboxoutline="8e989b"
          min="1.0" max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="10" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="b54c3a5594317ad7" memberName="Title5" virtualName=""
         explicitFocusOrder="0" pos="352 152 64 16" bkgCol="fff0f8ff"
         textCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="VAL A"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <LABEL name="new label" id="a1c56561ddda84d0" memberName="Title6" virtualName=""
         explicitFocusOrder="0" pos="352 8 96 16" bkgCol="fff0f8ff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="MOD A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="OPM_MODA" id="2864d35105104cbd" memberName="OPM_MODA" virtualName=""
             explicitFocusOrder="0" pos="352 24 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;OPM_MODA&quot;"/>
  <JUCERCOMP name="OPM_MODB" id="1dafcc7e8eda101d" memberName="OPM_MODB" virtualName=""
             explicitFocusOrder="0" pos="456 24 96 96" sourceFile="../Components/SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;OPM_MODB&quot;"/>
  <SLIDER name="DirectValue" id="11a6daa6c6f9aa38" memberName="VALB" virtualName=""
          explicitFocusOrder="0" pos="416 168 64 68" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" textboxoutline="8e989b"
          min="1.0" max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="10" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="5199123e3efd7734" memberName="Title3" virtualName=""
         explicitFocusOrder="0" pos="416 152 64 16" bkgCol="fff0ffff"
         textCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="VAL B"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
  <SLIDER name="DirectValue" id="7bc2a0f57e067caa" memberName="VALC" virtualName=""
          explicitFocusOrder="0" pos="480 168 64 68" posRelativeX="5eeb447276336bd"
          posRelativeY="5eeb447276336bd" tooltip="Decay time&#10;" textboxoutline="8e989b"
          min="1.0" max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="50"
          textBoxHeight="10" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="758209e6b61653a9" memberName="Title4" virtualName=""
         explicitFocusOrder="0" pos="480 152 64 16" bkgCol="fff0f8ff"
         textCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="VAL C"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

