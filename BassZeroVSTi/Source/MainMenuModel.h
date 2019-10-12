/*
  ==============================================================================

    MainMenuModel.h
    Created: 4 Oct 2019 8:25:51pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "Application\CommandIDs.h"
#include "Application\SynthApplicationBase.h"

//==============================================================================
/*
*/
class MainMenuModel    :    public Component,
                            public ApplicationCommandTarget,
                            public MenuBarModel
{
public:

 

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
   

	bool perform(const InvocationInfo& info) override;
   
    
private:
	ApplicationCommandManager commandManager;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainMenuModel)
};
