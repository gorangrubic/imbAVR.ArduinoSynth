/*
  ==============================================================================

    MainMenuModel.cpp
    Created: 4 Oct 2019 8:25:51pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainMenuModel.h"

//==============================================================================
MainMenuModel::MainMenuModel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

MainMenuModel::~MainMenuModel()
{
}

void MainMenuModel::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("MainMenuModel", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void MainMenuModel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

StringArray MainMenuModel::getMenuBarNames()
{
	const char* const names[] = { "File", "MIDI", "Edit", "Tools", "Help", "DevTools" };

	return StringArray(names);
}

PopupMenu MainMenuModel::getMenuForIndex(int menuIndex, const String &)
{
	PopupMenu menu;

	if (menuIndex == MenuGroupIDS::file) {
		menu.addCommandItem(&commandManager, CommandIDs::file_initState,"Init state");
		menu.addCommandItem(&commandManager, CommandIDs::file_loadPreset, "Load preset");
		menu.addCommandItem(&commandManager, CommandIDs::file_savePreset, "Save preset");
		menu.addCommandItem(&commandManager, CommandIDs::file_loadOPM, "Load OPM");
		menu.addCommandItem(&commandManager, CommandIDs::file_saveOPM, "Save OPM");
		menu.addCommandItem(&commandManager, CommandIDs::file_selectLibrary, "Select library");
		menu.addCommandItem(&commandManager, CommandIDs::file_loadSettings, "Load settings");
		menu.addCommandItem(&commandManager, CommandIDs::file_saveSettings, "Save settings");
	}
	else if (menuIndex == MenuGroupIDS::midi) {
		menu.addCommandItem(&commandManager, CommandIDs::midi_factoryCCMap, "Factory CC map");
		menu.addCommandItem(&commandManager, CommandIDs::midi_loadCCMap, "Load CC map");
		menu.addCommandItem(&commandManager, CommandIDs::midi_saveCCMap, "Save CC map");
		menu.addCommandItem(&commandManager, CommandIDs::midi_editCCMap, "Edit CC map");
		menu.addCommandItem(&commandManager, CommandIDs::midi_presetToMidiInstructions, "Preset to MIDI");
		menu.addCommandItem(&commandManager, CommandIDs::midi_executeMidiInstructions, "Execute MIDI");
		menu.addCommandItem(&commandManager, CommandIDs::midi_inputOutput, "Input Output");
	}
	else if (menuIndex == MenuGroupIDS::edit) {
		menu.addCommandItem(&commandManager, CommandIDs::edit_copy, "Copy");
		menu.addCommandItem(&commandManager, CommandIDs::edit_pasteValues, "Paste values");
		menu.addCommandItem(&commandManager, CommandIDs::edit_pasteCCMaps, "Paste CC maps");
		menu.addCommandItem(&commandManager, CommandIDs::edit_showValues, "Show values");
		menu.addCommandItem(&commandManager, CommandIDs::edit_showCCMap, "Show CC maps");
		menu.addCommandItem(&commandManager, CommandIDs::edit_showBufferState, "Show Buffer state");
		menu.addCommandItem(&commandManager, CommandIDs::edit_showScopeOutline, "Show selection outline");
		menu.addCommandItem(&commandManager, CommandIDs::edit_settings, "Settings");
	}
	else if (menuIndex == MenuGroupIDS::tools) {
		menu.addCommandItem(&commandManager, CommandIDs::tools_screenshot, "Make screenshot");
		menu.addCommandItem(&commandManager, CommandIDs::tools_readhardware, "Read hardware");
		menu.addCommandItem(&commandManager, CommandIDs::tools_writehardware, "Write hardware");
		menu.addCommandItem(&commandManager, CommandIDs::tools_hardwareStateToFile, "Hardware to file");
		menu.addCommandItem(&commandManager, CommandIDs::tools_hardwareStateFromFile, "Hardware from file");		
	}
	else if (menuIndex == MenuGroupIDS::help) {
		menu.addCommandItem(&commandManager, CommandIDs::help_readHardwareSignature, "Synth signature");
		menu.addCommandItem(&commandManager, CommandIDs::help_userManual, "User manual");
		menu.addCommandItem(&commandManager, CommandIDs::help_hardwareUserManual, "Hardware User manual");
		menu.addCommandItem(&commandManager, CommandIDs::help_synthModelReference, "Synth model reference");
		menu.addCommandItem(&commandManager, CommandIDs::help_quickTour, "Quick tour");
		menu.addCommandItem(&commandManager, CommandIDs::help_randomTip, "Random tip");
		menu.addCommandItem(&commandManager, CommandIDs::help_website, "Web site");
		menu.addCommandItem(&commandManager, CommandIDs::help_about, "About");
	}
	else if (menuIndex == MenuGroupIDS::devTools) {
		menu.addCommandItem(&commandManager, CommandIDs::devTools_reportModel, "Report model");
		menu.addCommandItem(&commandManager, CommandIDs::devTools_CCDefine, "Generate CC Define");
		menu.addCommandItem(&commandManager, CommandIDs::devTools_FirmwareModel, "Generate firmware model");
		menu.addCommandItem(&commandManager, CommandIDs::devTools_viewBuffer, "View buffer");
		menu.addCommandItem(&commandManager, CommandIDs::devTools_viewLog, "View log");
	}
}

ApplicationCommandTarget * MainMenuModel::getNextCommandTarget()
{
	return nullptr;
}

void MainMenuModel::getAllCommands(Array<CommandID>& c)
{

	Array<CommandID> commands{ CommandIDs::file_initState,
CommandIDs::file_loadPreset,
CommandIDs::file_savePreset,
CommandIDs::file_loadOPM,
CommandIDs::file_saveOPM,
CommandIDs::file_selectLibrary,
CommandIDs::file_loadSettings,
CommandIDs::file_saveSettings,
CommandIDs::midi_factoryCCMap,
CommandIDs::midi_loadCCMap,
CommandIDs::midi_saveCCMap,
CommandIDs::midi_editCCMap,
CommandIDs::midi_presetToMidiInstructions,
CommandIDs::midi_executeMidiInstructions,
CommandIDs::midi_inputOutput,
CommandIDs::edit_copy,
CommandIDs::edit_pasteValues,
CommandIDs::edit_pasteCCMaps,
CommandIDs::edit_showValues,
CommandIDs::edit_showCCMap,
CommandIDs::edit_showBufferState,
CommandIDs::edit_showScopeOutline,
CommandIDs::edit_settings,
CommandIDs::tools_screenshot,
CommandIDs::tools_readhardware,
CommandIDs::tools_writehardware,
CommandIDs::tools_hardwareStateToFile,
CommandIDs::tools_hardwareStateFromFile,
CommandIDs::help_readHardwareSignature,
CommandIDs::help_userManual,
CommandIDs::help_hardwareUserManual,
CommandIDs::help_synthModelReference,
CommandIDs::help_quickTour,
CommandIDs::help_randomTip,
CommandIDs::help_website,
CommandIDs::help_about,
CommandIDs::devTools_reportModel,
CommandIDs::devTools_CCDefine,
CommandIDs::devTools_FirmwareModel,
CommandIDs::devTools_viewBuffer,
CommandIDs::devTools_viewLog };
	c.addArray(commands);
}

void MainMenuModel::getCommandInfo(CommandID commandID, ApplicationCommandInfo & result)
{
	switch (commandID) {
	case CommandIDs::file_initState:
		result.setInfo("Init state", "Resets all preset and OPM settings to defaults.", "File",0);
		result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_loadPreset:
		result.setInfo("Load preset", "Imports preset from a preset XML file, outside the library", "File", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_savePreset:
		result.setInfo("Save preset", "Exports preset to a preset XML file, outside the library", "File", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_loadOPM:
		result.setInfo("Load OPM", "Imports OPM settings from XML file, without changing other parameters of the current preset\state", "File", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_saveOPM:
		result.setInfo("Save OPM", "Exports OPM settings to XML file, without other parameters of the current preset\state", "File", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_selectLibrary:
		result.setInfo("Select library", "Select another library directory path", "File", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_loadSettings:
		result.setInfo("Load settings", "Import VSTi settings from custom location", "File", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_saveSettings:
		result.setInfo("Save settings", "Export current VSTi settings to a custom location", "File", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_factoryCCMap:
		result.setInfo("Factory CC map", "Resets current CC mapping to factory defaults", "MIDI", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_loadCCMap:
		result.setInfo("Load CC map", "Loads CC map table file", "MIDI", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_saveCCMap:
		result.setInfo("Save CC map", "Saves current CC map table into external file", "MIDI", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_editCCMap:
		result.setInfo("Edit CC map", "Tabelar editor for current CC map", "MIDI", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_presetToMidiInstructions:
		result.setInfo("Preset to MIDI", "Serializes current preset and OPM into sequence of MIDI instructions and saves it to MIDI file", "MIDI", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_executeMidiInstructions:
		result.setInfo("Execute MIDI", "Executes sequence of MIDI instructions imported from a MIDI file", "MIDI", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_inputOutput:
		result.setInfo("Input Output", "Configure devices, MIDI input output routing", "MIDI", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;

	case CommandIDs::edit_copy:
		result.setInfo("Copy", "Stores values and CC mapping of selected component(s) into clipboard", "EDIT", 0);
		result.addDefaultKeypress('c', ModifierKeys::ctrlModifier);
		break;
	case CommandIDs::edit_pasteValues:
		result.setInfo("Paste", "Stores values and CC mapping of selected component(s) into clipboard", "EDIT", 0);
		result.addDefaultKeypress('v', ModifierKeys::ctrlModifier);
		break;
	case CommandIDs::edit_pasteCCMaps:
		result.setInfo("Copy", "Stores values and CC mapping of selected component(s) into clipboard", "EDIT", 0);
		result.addDefaultKeypress('v', ModifierKeys::altModifier);
		break;
	case CommandIDs::edit_showValues:
		result.setInfo("Show values", "Show values for each component in overlayed textbox", "EDIT", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::edit_showCCMap:
		result.setInfo("Show CC map", "In overlayed textbox, shows current CC map settings for each component", "EDIT", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::edit_showBufferState:
		result.setInfo("Show buffer", "Shows current MIDI CC & SysExc messages, waiting for transfer", "EDIT", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::edit_showScopeOutline:
		result.setInfo("Show scope", "Outlines currently selected component(s) - for easier copy'n'paste operations", "EDIT", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::edit_settings:
		result.setInfo("Settings", "VSTi general configuration options", "EDIT", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::tools_screenshot:
		result.setInfo("Screenshot", "Creates screenshot of current GUI state and saves it to output directory", "TOOLS", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::tools_readhardware:
		result.setInfo("Read hardware", "Reads current hardware state", "TOOLS", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::tools_writehardware:
		result.setInfo("Write hardware", "Writes currently loaded hardware state", "TOOLS", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::tools_hardwareStateToFile:
		result.setInfo("Hardware to file", "Exports currently loaded hardware state to file", "TOOLS", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::tools_hardwareStateFromFile:
		result.setInfo("Hardware from file", "Loads hardware state from file", "TOOLS", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;

	case CommandIDs::help_readHardwareSignature:
		result.setInfo("Signature", "Queries synth hardware for firmware version signature", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_userManual:
		result.setInfo("User manual", "Opens VSTi user manual PDF", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_hardwareUserManual:
		result.setInfo("Hardware manual", "Opens general synth user manual PDF", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_synthModelReference:
		result.setInfo("Synth model", "Generates generic reference in TXT file, describing synth model", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_quickTour:
		result.setInfo("Quick tour", "Slide-show quick guide, explaining VSTi and synth basics", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_randomTip:
		result.setInfo("Random tip", "Shows a random tip", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_website:
		result.setInfo("Web site", "Opens BassZero web page in default browser", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_about:
		result.setInfo("About", "Opens About splash screen", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;

	}
}

bool MainMenuModel::perform(const InvocationInfo & info)
{
	return false;
}
