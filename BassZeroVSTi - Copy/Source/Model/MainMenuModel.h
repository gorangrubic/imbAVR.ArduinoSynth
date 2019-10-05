/*
  ==============================================================================

    MainMenuModel.h
    Created: 4 Oct 2019 8:25:51pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class MainMenuModel    :    public Component,
                            public ApplicationCommandTarget,
                            public MenuBarModel
{
public:

 //==============================================================================
    /** A list of the commands that this demo responds to. */
    enum CommandIDs
    {
        menuPositionInsideWindow = 1,
        menuPositionGlobalMenuBar,
        menuPositionBurgerMenu,
        outerColourRed,
        outerColourGreen,
        outerColourBlue,
        innerColourRed,
        innerColourGreen,
        innerColourBlue
    };



    MainMenuModel();
    ~MainMenuModel();

    void paint (Graphics&) override;
    void resized() override;
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex (int menuIndex, const String& /*menuName*/) override;
    void menuItemSelected (int /*menuItemID*/, int /*topLevelMenuIndex*/) override {}

    ApplicationCommandTarget* getNextCommandTarget() override;
    
    void getAllCommands (Array<CommandID>& c) override;
    

    void getCommandInfo (CommandID commandID, ApplicationCommandInfo& result) override;
   

    bool perform (const InvocationInfo& info) override
   
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainMenuModel)
};
