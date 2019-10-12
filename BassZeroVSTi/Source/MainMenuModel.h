/*
  ==============================================================================

    MainMenuModel.h
    Created: 4 Oct 2019 8:25:51pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

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
        file_initState=1,
		file_loadPreset,
		file_savePreset,
		file_loadOPM,
		file_saveOPM,
		file_selectLibrary,
		file_loadSettings,
		file_saveSettings,
		midi_factoryCCMap,
		midi_loadCCMap,
		midi_saveCCMap,
		midi_editCCMap,
		midi_presetToMidiInstructions,
		midi_executeMidiInstructions,

		midi_inputOutput,

		edit_copy,
		edit_pasteValues,
		edit_pasteCCMaps,
		edit_showValues,
		edit_showCCMap,
		edit_showBufferState,
		edit_showScopeOutline,

		edit_settings,

		tools_screenshot,
		tools_readhardware,
		tools_writehardware,
		tools_hardwareStateToFile,
		tools_hardwareStateFromFile,
		help_readHardwareSignature,
		help_userManual,
		help_hardwareUserManual,
		help_synthModelReference,
		help_quickTour,
		help_randomTip,
		help_website,
		help_about,
		devTools_reportModel,
		devTools_CCDefine,
		devTools_FirmwareModel,
		devTools_viewBuffer,
		devTools_viewLog
    };

	enum MenuGroupIDS {
		file=0,
		midi=1,
		edit=2,
		tools=3,
		help=4,
		devTools=5
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
   

	bool perform(const InvocationInfo& info) override;
   
    
private:
	ApplicationCommandManager commandManager;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainMenuModel)
};
