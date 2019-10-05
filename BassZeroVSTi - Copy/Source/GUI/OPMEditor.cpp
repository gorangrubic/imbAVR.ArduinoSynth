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

#include "OPMEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OPMEditor::OPMEditor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    modA1.reset (new OPMToSignalChangeEditor());
    addAndMakeVisible (modA1.get());
    modB1.reset (new OPMToSignalChangeEditor());
    addAndMakeVisible (modB1.get());
    valC1.reset (new OPMToSignalChangeEditor());
    addAndMakeVisible (valC1.get());
    valC2.reset (new OPMToSignalChangeEditor());
    addAndMakeVisible (valC2.get());
    labelMODA.reset (new Label ("new label",
                                TRANS("MOD A")));
    addAndMakeVisible (labelMODA.get());
    labelMODA->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
    labelMODA->setJustificationType (Justification::centredLeft);
    labelMODA->setEditable (false, false, false);
    labelMODA->setColour (Label::backgroundColourId, Colours::azure);
    labelMODA->setColour (Label::textColourId, Colour (0xff181f22));
    labelMODA->setColour (TextEditor::textColourId, Colours::black);
    labelMODA->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelMODA->setBounds (0, 2, 160, 18);

    modA2.reset (new OPMToSignalChangeEditor());
    addAndMakeVisible (modA2.get());
    labelMODB.reset (new Label ("new label",
                                TRANS("MOD B")));
    addAndMakeVisible (labelMODB.get());
    labelMODB->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
    labelMODB->setJustificationType (Justification::centredLeft);
    labelMODB->setEditable (false, false, false);
    labelMODB->setColour (Label::backgroundColourId, Colours::azure);
    labelMODB->setColour (Label::textColourId, Colour (0xff181f22));
    labelMODB->setColour (TextEditor::textColourId, Colours::black);
    labelMODB->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    modB2.reset (new OPMToSignalChangeEditor());
    addAndMakeVisible (modB2.get());
    labelMODA3.reset (new Label ("new label",
                                 TRANS("VAL A")));
    addAndMakeVisible (labelMODA3.get());
    labelMODA3->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
    labelMODA3->setJustificationType (Justification::centredLeft);
    labelMODA3->setEditable (false, false, false);
    labelMODA3->setColour (Label::backgroundColourId, Colours::azure);
    labelMODA3->setColour (Label::textColourId, Colour (0xff181f22));
    labelMODA3->setColour (TextEditor::textColourId, Colours::black);
    labelMODA3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelMODA3->setBounds (0, 168, 160, 18);

    labelMODA4.reset (new Label ("new label",
                                 TRANS("VAL B")));
    addAndMakeVisible (labelMODA4.get());
    labelMODA4->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
    labelMODA4->setJustificationType (Justification::centredLeft);
    labelMODA4->setEditable (false, false, false);
    labelMODA4->setColour (Label::backgroundColourId, Colours::azure);
    labelMODA4->setColour (Label::textColourId, Colour (0xff181f22));
    labelMODA4->setColour (TextEditor::textColourId, Colours::black);
    labelMODA4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    valA1.reset (new OPMToSignalChangeEditor());
    addAndMakeVisible (valA1.get());
    valB1.reset (new OPMToSignalChangeEditor());
    addAndMakeVisible (valB1.get());
    LabelVALC.reset (new Label ("new label",
                                TRANS("VAL C")));
    addAndMakeVisible (LabelVALC.get());
    LabelVALC->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Bold"));
    LabelVALC->setJustificationType (Justification::centredLeft);
    LabelVALC->setEditable (false, false, false);
    LabelVALC->setColour (Label::backgroundColourId, Colours::azure);
    LabelVALC->setColour (Label::textColourId, Colour (0xff181f22));
    LabelVALC->setColour (TextEditor::textColourId, Colours::black);
    LabelVALC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    LabelVALC->setBounds (0, 264, 324, 18);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (324, 360);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OPMEditor::~OPMEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    modA1 = nullptr;
    modB1 = nullptr;
    valC1 = nullptr;
    valC2 = nullptr;
    labelMODA = nullptr;
    modA2 = nullptr;
    labelMODB = nullptr;
    modB2 = nullptr;
    labelMODA3 = nullptr;
    labelMODA4 = nullptr;
    valA1 = nullptr;
    valB1 = nullptr;
    LabelVALC = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OPMEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OPMEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    modA1->setBounds (0, 2 + 18, 160, 76);
    modB1->setBounds (0 + 160 - -4, 2 + 18, 160, 76);
    valC1->setBounds (0, 264 + 18, 160, 76);
    valC2->setBounds (0 + 160 - -4, 264 + 18, 160, 76);
    modA2->setBounds (0, (2 + 18) + 76 - 4, 160, 76);
    labelMODB->setBounds (0 + 160 - -4, 2, 160, 18);
    modB2->setBounds ((0 + 160 - -4) + 0, (2 + 18) + 76 - 4, 160, 76);
    labelMODA4->setBounds (0 + 160 - -4, 168, 160, 18);
    valA1->setBounds (0, 168 + 18, 160, 76);
    valB1->setBounds (0 + 160 - -4, (168 + 18) + 0, 160, 76);
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

<JUCER_COMPONENT documentType="Component" className="OPMEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="324" initialHeight="360">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="" id="1474ddf3224b6bf5" memberName="modA1" virtualName=""
             explicitFocusOrder="0" pos="0 0R 160 76" posRelativeY="995d370610ffd3e1"
             sourceFile="Components/OPMToSignalChangeEditor.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="fa8cf6b4b2235e5" memberName="modB1" virtualName=""
             explicitFocusOrder="0" pos="-4R 0R 160 76" posRelativeX="1474ddf3224b6bf5"
             posRelativeY="d5b6addb2e4190e6" sourceFile="Components/OPMToSignalChangeEditor.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="cc6b5c20302ca164" memberName="valC1" virtualName=""
             explicitFocusOrder="0" pos="0 0R 160 76" posRelativeY="ceaeec3d2ebe5aa6"
             sourceFile="Components/OPMToSignalChangeEditor.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="3cd1decada909c47" memberName="valC2" virtualName=""
             explicitFocusOrder="0" pos="-4R 0R 160 76" posRelativeX="cc6b5c20302ca164"
             posRelativeY="ceaeec3d2ebe5aa6" sourceFile="Components/OPMToSignalChangeEditor.cpp"
             constructorParams=""/>
  <LABEL name="new label" id="995d370610ffd3e1" memberName="labelMODA"
         virtualName="" explicitFocusOrder="0" pos="0 2 160 18" posRelativeX="6f9f204dacc67317"
         posRelativeY="6f9f204dacc67317" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="MOD A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
  <JUCERCOMP name="" id="11a6440739bbbbb7" memberName="modA2" virtualName=""
             explicitFocusOrder="0" pos="0 4R 160 76" posRelativeY="1474ddf3224b6bf5"
             sourceFile="Components/OPMToSignalChangeEditor.cpp" constructorParams=""/>
  <LABEL name="new label" id="d5b6addb2e4190e6" memberName="labelMODB"
         virtualName="" explicitFocusOrder="0" pos="-4R 2 160 18" posRelativeX="995d370610ffd3e1"
         posRelativeY="6f9f204dacc67317" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="MOD B" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
  <JUCERCOMP name="" id="1cd4b6143caa5ed8" memberName="modB2" virtualName=""
             explicitFocusOrder="0" pos="0 4R 160 76" posRelativeX="fa8cf6b4b2235e5"
             posRelativeY="fa8cf6b4b2235e5" sourceFile="Components/OPMToSignalChangeEditor.cpp"
             constructorParams=""/>
  <LABEL name="new label" id="17686cde2f9a7ac4" memberName="labelMODA3"
         virtualName="" explicitFocusOrder="0" pos="0 168 160 18" posRelativeX="6f9f204dacc67317"
         posRelativeY="6f9f204dacc67317" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="VAL A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
  <LABEL name="new label" id="345a4deecb86f004" memberName="labelMODA4"
         virtualName="" explicitFocusOrder="0" pos="-4R 168 160 18" posRelativeX="995d370610ffd3e1"
         posRelativeY="6f9f204dacc67317" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="VAL B" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
  <JUCERCOMP name="" id="10d33e3002129c6" memberName="valA1" virtualName=""
             explicitFocusOrder="0" pos="0 0R 160 76" posRelativeY="17686cde2f9a7ac4"
             sourceFile="Components/OPMToSignalChangeEditor.cpp" constructorParams=""/>
  <JUCERCOMP name="" id="ac05be0a6548b1d4" memberName="valB1" virtualName=""
             explicitFocusOrder="0" pos="-4R 0 160 76" posRelativeX="10d33e3002129c6"
             posRelativeY="10d33e3002129c6" sourceFile="Components/OPMToSignalChangeEditor.cpp"
             constructorParams=""/>
  <LABEL name="new label" id="ceaeec3d2ebe5aa6" memberName="LabelVALC"
         virtualName="" explicitFocusOrder="0" pos="0 264 324 18" posRelativeX="6f9f204dacc67317"
         posRelativeY="6f9f204dacc67317" bkgCol="fff0ffff" textCol="ff181f22"
         edTextCol="ff000000" edBkgCol="0" labelText="VAL C" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

