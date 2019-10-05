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

#include "MainViewTabPresetManager.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainViewTabPresetManager::MainViewTabPresetManager (imbSynthStateData * synthState, String nameSufix)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    toggle_autoLoadOPM.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggle_autoLoadOPM.get());
    toggle_autoLoadOPM->setTooltip (TRANS("Loads OPM preset required by Sound preset selected"));
    toggle_autoLoadOPM->setButtonText (TRANS("Auto load related OPM"));
    toggle_autoLoadOPM->addListener (this);

    toggle_autoLoadOPM->setBounds (440, 312, 200, 16);

    presetLibraryView.reset (new PresetFileBrowser());
    addAndMakeVisible (presetLibraryView.get());
    presetDefinitionDisplay.reset (new PresetDefinitionEditor());
    addAndMakeVisible (presetDefinitionDisplay.get());

    //[UserPreSize]
    //[/UserPreSize]

    setSize (840, 340);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainViewTabPresetManager::~MainViewTabPresetManager()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    toggle_autoLoadOPM = nullptr;
    presetLibraryView = nullptr;
    presetDefinitionDisplay = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainViewTabPresetManager::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainViewTabPresetManager::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    presetLibraryView->setBounds (0, 0, 440, getHeight() - 4);
    presetDefinitionDisplay->setBounds (440, 8, getWidth() - 448, getHeight() - 40);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainViewTabPresetManager::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggle_autoLoadOPM.get())
    {
        //[UserButtonCode_toggle_autoLoadOPM] -- add your button handler code here..
        //[/UserButtonCode_toggle_autoLoadOPM]
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

<JUCER_COMPONENT documentType="Component" className="MainViewTabPresetManager"
                 componentName="" parentClasses="public Component, public imbSynthGUIComponent"
                 constructorParams="imbSynthStateData * synthState, String nameSufix"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="840" initialHeight="340">
  <BACKGROUND backgroundColour="323e44"/>
  <TOGGLEBUTTON name="new toggle button" id="3527ef824b722831" memberName="toggle_autoLoadOPM"
                virtualName="" explicitFocusOrder="0" pos="440 312 200 16" tooltip="Loads OPM preset required by Sound preset selected"
                buttonText="Auto load related OPM" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <JUCERCOMP name="" id="4a47e8e5c4db0633" memberName="presetLibraryView"
             virtualName="" explicitFocusOrder="0" pos="0 0 440 4M" sourceFile="../../General/PresetFileBrowser.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="b0a6f0fa687bc200" memberName="presetDefinitionDisplay"
             virtualName="" explicitFocusOrder="0" pos="440 8 448M 40M" sourceFile="../../General/PresetDefinitionEditor.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

