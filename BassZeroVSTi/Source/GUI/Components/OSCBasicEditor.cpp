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

#include "OSCBasicEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OSCBasicEditor::OSCBasicEditor (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    Title2.reset (new Label ("new label",
                             TRANS("SHAPER")));
    addAndMakeVisible (Title2.get());
    Title2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    Title2->setJustificationType (Justification::centred);
    Title2->setEditable (false, false, false);
    Title2->setColour (Label::backgroundColourId, Colours::aliceblue);
    Title2->setColour (Label::textColourId, Colour (0xff181f22));
    Title2->setColour (TextEditor::textColourId, Colours::black);
    Title2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Title2->setBounds (200, 0, 96, 16);

    Shaper.reset (new SourceMixerComponent (synthState, "Shaper"));
    addAndMakeVisible (Shaper.get());
    Shaper->setBounds (200, 16, 96, 96);

    OSC.reset (new OSCEditor (synthState, "OSC"));
    addAndMakeVisible (OSC.get());
    OSC->setBounds (0, 0, 192, 112);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (330, 120);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OSCBasicEditor::~OSCBasicEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    Title2 = nullptr;
    Shaper = nullptr;
    OSC = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OSCBasicEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OSCBasicEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void OSCBasicEditor::ConstructParameterLayout(std::vector<std::unique_ptr<AudioParameterInt>> params)
{
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OSCBasicEditor" componentName=""
                 parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="330" initialHeight="120">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="4bbeb0561535668a" memberName="Title2" virtualName=""
         explicitFocusOrder="0" pos="200 0 96 16" bkgCol="fff0f8ff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="SHAPER" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="Shaper" id="6dc4e4d5157c3da" memberName="Shaper" virtualName=""
             explicitFocusOrder="0" pos="200 16 96 96" sourceFile="SourceMixerComponent.cpp"
             constructorParams="synthState, &quot;Shaper&quot;"/>
  <JUCERCOMP name="OSC" id="57bcfacd6198a2e" memberName="OSC" virtualName=""
             explicitFocusOrder="0" pos="0 0 192 112" sourceFile="OSCEditor.cpp"
             constructorParams="synthState, &quot;OSC&quot;"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

