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

#include "TextContentViewer.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TextContentViewer::TextContentViewer (TextContentModel * model)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    textEditor.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (true);
    textEditor->setReturnKeyStartsNewLine (true);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (TRANS("Textual content\n"));

    saveButton.reset (new TextButton ("saveButton"));
    addAndMakeVisible (saveButton.get());
    saveButton->setButtonText (TRANS("Save"));
    saveButton->addListener (this);
    saveButton->setColour (TextButton::buttonColourId, Colour (0xff181f22));

    copyButton.reset (new TextButton ("copyButton"));
    addAndMakeVisible (copyButton.get());
    copyButton->setTooltip (TRANS("Copy text to clipboard"));
    copyButton->setButtonText (TRANS("Copy"));
    copyButton->addListener (this);
    copyButton->setColour (TextButton::buttonColourId, Colour (0xff181f22));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TextContentViewer::~TextContentViewer()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textEditor = nullptr;
    saveButton = nullptr;
    copyButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TextContentViewer::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TextContentViewer::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textEditor->setBounds (0, 0, getWidth() - 0, getHeight() - 30);
    saveButton->setBounds (2, getHeight() - 26, 120, 24);
    copyButton->setBounds (getWidth() - 122, getHeight() - 26, 120, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TextContentViewer::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == saveButton.get())
    {
        //[UserButtonCode_saveButton] -- add your button handler code here..
        //[/UserButtonCode_saveButton]
    }
    else if (buttonThatWasClicked == copyButton.get())
    {
        //[UserButtonCode_copyButton] -- add your button handler code here..
        //[/UserButtonCode_copyButton]
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

<JUCER_COMPONENT documentType="Component" className="TextContentViewer" componentName=""
                 parentClasses="public Component" constructorParams="TextContentModel * model"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTEDITOR name="new text editor" id="b35639f5cca5fb41" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="0 0 0M 30M" initialText="Textual content&#10;"
              multiline="1" retKeyStartsLine="1" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="saveButton" id="b52d28e1d7f764fd" memberName="saveButton"
              virtualName="" explicitFocusOrder="0" pos="2 26R 120 24" bgColOff="ff181f22"
              buttonText="Save" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="copyButton" id="c780b5d1cfa36645" memberName="copyButton"
              virtualName="" explicitFocusOrder="0" pos="122R 26R 120 24" tooltip="Copy text to clipboard"
              bgColOff="ff181f22" buttonText="Copy" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

