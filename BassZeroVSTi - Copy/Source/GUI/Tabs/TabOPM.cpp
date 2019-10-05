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
#include "../Components/SignalControlEditor.h"
#include "../Components/SignalControlEditor.h"
#include "../Components/SignalControlEditor.h"
#include "../Components/SignalControlEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TabOPM::TabOPM ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    tabbedComponent.reset (new TabbedComponent (TabbedButtonBar::TabsAtBottom));
    addAndMakeVisible (tabbedComponent.get());
    tabbedComponent->setTabBarDepth (30);
    tabbedComponent->addTab (TRANS("WF A"), Colour (0x00181f22), new SignalControlEditor(), true);
    tabbedComponent->addTab (TRANS("WF B"), Colour (0x00d3d3d3), new SignalControlEditor(), true);
    tabbedComponent->addTab (TRANS("FLT"), Colour (0x00d3d3d3), new SignalControlEditor(), true);
    tabbedComponent->addTab (TRANS("PERK A"), Colour (0x00d3d3d3), new SignalControlEditor(), true);
    tabbedComponent->addTab (TRANS("PERK B"), Colour (0x00d3d3d3), new SignalControlEditor(), true);
    tabbedComponent->setCurrentTabIndex (0);

    tabbedComponent->setBounds (0, 0, 508, 360);

    MacroControls.reset (new OPMEditor());
    addAndMakeVisible (MacroControls.get());
    MacroControls->setBounds (512, 0, 320, 360);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (840, 360);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TabOPM::~TabOPM()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    tabbedComponent = nullptr;
    MacroControls = nullptr;


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

<JUCER_COMPONENT documentType="Component" className="TabOPM" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="840" initialHeight="360">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TABBEDCOMPONENT name="new tabbed component" id="e9a100ca63a7a802" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="0 0 508 360" orientation="bottom"
                   tabBarDepth="30" initialTab="0">
    <TAB name="WF A" colour="181f22" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="../Components/SignalControlEditor.cpp"/>
    <TAB name="WF B" colour="d3d3d3" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="../Components/SignalControlEditor.cpp"/>
    <TAB name="FLT" colour="d3d3d3" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="../Components/SignalControlEditor.cpp"/>
    <TAB name="PERK A" colour="d3d3d3" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="../Components/SignalControlEditor.cpp"/>
    <TAB name="PERK B" colour="d3d3d3" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="../Components/SignalControlEditor.cpp"/>
  </TABBEDCOMPONENT>
  <JUCERCOMP name="" id="1aa1163e1a769e07" memberName="MacroControls" virtualName=""
             explicitFocusOrder="0" pos="512 0 320 360" sourceFile="../OPMEditor.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

