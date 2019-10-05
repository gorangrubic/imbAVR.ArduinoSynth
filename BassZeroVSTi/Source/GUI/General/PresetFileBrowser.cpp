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

#include "PresetFileBrowser.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PresetFileBrowser::PresetFileBrowser (PresetFileBrowserModel * _model)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    treeView.reset (new TreeView ("new treeview"));
    addAndMakeVisible (treeView.get());
    treeView->setDefaultOpenness (true);
    treeView->setColour (TreeView::backgroundColourId, Colours::azure);
    treeView->setColour (TreeView::linesColourId, Colours::beige);

    Load.reset (new TextButton ("new button"));
    addAndMakeVisible (Load.get());
    Load->setButtonText (TRANS("Load"));
    Load->addListener (this);
    Load->setColour (TextButton::buttonColourId, Colour (0xff181f22));

    Save.reset (new TextButton ("new button"));
    addAndMakeVisible (Save.get());
    Save->setButtonText (TRANS("Save"));
    Save->addListener (this);
    Save->setColour (TextButton::buttonColourId, Colour (0xff181f22));

    Refresh.reset (new TextButton ("new button"));
    addAndMakeVisible (Refresh.get());
    Refresh->setButtonText (TRANS("Refresh"));
    Refresh->addListener (this);
    Refresh->setColour (TextButton::buttonColourId, Colour (0xff495358));

    toggle_showFilenames.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggle_showFilenames.get());
    toggle_showFilenames->setButtonText (TRANS("Show filenames"));
    toggle_showFilenames->addListener (this);

    toggle_showFilenames->setBounds (184, 808, 150, 24);

    component.reset (new PathBrowser());
    addAndMakeVisible (component.get());

    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PresetFileBrowser::~PresetFileBrowser()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    treeView = nullptr;
    Load = nullptr;
    Save = nullptr;
    Refresh = nullptr;
    toggle_showFilenames = nullptr;
    component = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PresetFileBrowser::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PresetFileBrowser::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    treeView->setBounds (8, 40, getWidth() - 16, getHeight() - 78);
    Load->setBounds (8, getHeight() - 6 - 24, 80, 24);
    Save->setBounds (8 + 80 - -8, getHeight() - 6 - 24, 80, 24);
    Refresh->setBounds (getWidth() - 8 - 80, getHeight() - 8 - 24, 80, 24);
    component->setBounds (8, 8, getWidth() - 16, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PresetFileBrowser::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == Load.get())
    {
        //[UserButtonCode_Load] -- add your button handler code here..
        //[/UserButtonCode_Load]
    }
    else if (buttonThatWasClicked == Save.get())
    {
        //[UserButtonCode_Save] -- add your button handler code here..
        //[/UserButtonCode_Save]
    }
    else if (buttonThatWasClicked == Refresh.get())
    {
        //[UserButtonCode_Refresh] -- add your button handler code here..
        //[/UserButtonCode_Refresh]
    }
    else if (buttonThatWasClicked == toggle_showFilenames.get())
    {
        //[UserButtonCode_toggle_showFilenames] -- add your button handler code here..
        //[/UserButtonCode_toggle_showFilenames]
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

<JUCER_COMPONENT documentType="Component" className="PresetFileBrowser" componentName=""
                 parentClasses="public Component" constructorParams="PresetFileBrowserModel * _model"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="400" initialHeight="300">
  <BACKGROUND backgroundColour="323e44"/>
  <TREEVIEW name="new treeview" id="f7a9ff75ddcfe5b" memberName="treeView"
            virtualName="" explicitFocusOrder="0" pos="8 40 16M 78M" backgroundColour="fff0ffff"
            linecol="fff5f5dc" rootVisible="1" openByDefault="1"/>
  <TEXTBUTTON name="new button" id="b032298f85b6889b" memberName="Load" virtualName=""
              explicitFocusOrder="0" pos="8 6Rr 80 24" bgColOff="ff181f22"
              buttonText="Load" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d932dee6453393c3" memberName="Save" virtualName=""
              explicitFocusOrder="0" pos="-8R 6Rr 80 24" posRelativeX="b032298f85b6889b"
              bgColOff="ff181f22" buttonText="Save" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d399e7e687bb73dc" memberName="Refresh"
              virtualName="" explicitFocusOrder="0" pos="8Rr 8Rr 80 24" bgColOff="ff495358"
              buttonText="Refresh" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="new toggle button" id="b4dc69e4c7772b74" memberName="toggle_showFilenames"
                virtualName="" explicitFocusOrder="0" pos="184 808 150 24" buttonText="Show filenames"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <JUCERCOMP name="" id="d2dfb90203789c8b" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="8 8 16M 24" sourceFile="PathBrowser.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

