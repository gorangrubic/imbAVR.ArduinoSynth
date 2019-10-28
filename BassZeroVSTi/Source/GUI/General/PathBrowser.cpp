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

#include "PathBrowser.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PathBrowser::PathBrowser ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    Path.reset (new Label ("new label",
                           TRANS("c:\\BassZero\\Library")));
    addAndMakeVisible (Path.get());
    Path->setFont (Font ("Helvetica Neue LT Std", 15.00f, Font::plain));
    Path->setJustificationType (Justification::centredLeft);
    Path->setEditable (false, true, false);
    Path->setColour (Label::backgroundColourId, Colour (0xff181f22));
    Path->setColour (TextEditor::textColourId, Colours::black);
    Path->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    Path->addListener (this);

    Browse.reset (new TextButton ("new button"));
    addAndMakeVisible (Browse.get());
    Browse->setButtonText (TRANS("Browse"));
    Browse->addListener (this);
    Browse->setColour (TextButton::buttonColourId, Colour (0xff495358));
    Browse->setColour (TextButton::buttonOnColourId, Colour (0xff495358));

    label.reset (new Label ("new label",
                            TRANS("Path")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::backgroundColourId, Colour (0xff495358));
    label->setColour (Label::textColourId, Colours::azure);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 24);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PathBrowser::~PathBrowser()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    Path = nullptr;
    Browse = nullptr;
    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PathBrowser::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PathBrowser::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    Path->setBounds (1 + 84 - -4, 0, getWidth() - 172, getHeight() - 0);
    Browse->setBounds (getWidth() - 80, 0, 80, getHeight() - 0);
    label->setBounds (1, 0, 84, getHeight() - 0);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PathBrowser::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == Path.get())
    {
        //[UserLabelCode_Path] -- add your label text handling code here..
        //[/UserLabelCode_Path]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}

void PathBrowser::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == Browse.get())
    {
        //[UserButtonCode_Browse] -- add your button handler code here..
        //[/UserButtonCode_Browse]
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

<JUCER_COMPONENT documentType="Component" className="PathBrowser" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="24">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="new label" id="90a0ed2ca4c0eebc" memberName="Path" virtualName=""
         explicitFocusOrder="0" pos="-4R 0 172M 0M" posRelativeX="84f7b5d81fc26926"
         bkgCol="ff181f22" edTextCol="ff000000" edBkgCol="0" labelText="c:\BassZero\Library"
         editableSingleClick="0" editableDoubleClick="1" focusDiscardsChanges="0"
         fontname="Helvetica Neue LT Std" fontsize="15.0" kerning="0.0"
         bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="8e7e026c8158390c" memberName="Browse" virtualName=""
              explicitFocusOrder="0" pos="0Rr 0 80 0M" bgColOff="ff495358"
              bgColOn="ff495358" buttonText="Browse" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="84f7b5d81fc26926" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="1 0 84 0M" bkgCol="ff495358" textCol="fff0ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Path" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

