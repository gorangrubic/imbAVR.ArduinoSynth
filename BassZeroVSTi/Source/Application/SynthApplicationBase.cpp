/*
  ==============================================================================

    SynthApplicationBase.cpp
    Created: 12 Oct 2019 3:39:01am
    Author:  gorangrubic

  ==============================================================================
*/

#include "SynthApplicationBase.h"

bool SynthApplicationBase::perform(CommandIDs commandID)
  {
	
	switch (commandID) {
	case CommandIDs::file_initState:
		//result.setInfo("Init state", "Resets all preset and OPM settings to defaults.", "File", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		//result.setActive(true);

		break;
	case CommandIDs::file_loadPreset:
		//result.setInfo("Load preset", "Imports preset from a preset XML file, outside the library", "File", 0);
		//result.setActive(true);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_savePreset:
		//result.setInfo("Save preset", "Exports preset to a preset XML file, outside the library", "File", 0);
		//result.setActive(true);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_loadOPM:
		//result.setInfo("Load OPM", "Imports OPM settings from XML file, without changing other parameters of the current preset\state", "File", 0);
		//result.setActive(true);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_saveOPM:
		//result.setInfo("Save OPM", "Exports OPM settings to XML file, without other parameters of the current preset\state", "File", 0);
		//result.setActive(true);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_selectLibrary:
		//result.setInfo("Select library", "Select another library directory path", "File", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_loadSettings:
		//result.setInfo("Load settings", "Import VSTi settings from custom location", "File", 0);
		//result.setActive(true);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::file_saveSettings:
		//result.setInfo("Save settings", "Export current VSTi settings to a custom location", "File", 0);
		//result.setActive(true);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_factoryCCMap:
		//result.setInfo("Factory CC map", "Resets current CC mapping to factory defaults", "MIDI", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_loadCCMap:
		//result.setInfo("Load CC map", "Loads CC map table file", "MIDI", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_saveCCMap:
		//result.setInfo("Save CC map", "Saves current CC map table into external file", "MIDI", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_editCCMap:
		//result.setInfo("Edit CC map", "Tabelar editor for current CC map", "MIDI", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_presetToMidiInstructions:
		//result.setInfo("Preset to MIDI", "Serializes current preset and OPM into sequence of MIDI instructions and saves it to MIDI file", "MIDI", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_executeMidiInstructions:
		//result.setInfo("Execute MIDI", "Executes sequence of MIDI instructions imported from a MIDI file", "MIDI", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::midi_inputOutput:
		//result.setInfo("Input Output", "Configure devices, MIDI input output routing", "MIDI", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;

	case CommandIDs::edit_copy:
		//result.setInfo("Copy", "Stores values and CC mapping of selected component(s) into clipboard", "EDIT", 0);
		//	result.setActive(true);
		//result.addDefaultKeypress('c', ModifierKeys::ctrlModifier);
		break;
	case CommandIDs::edit_pasteValues:
		//result.setInfo("Paste", "Stores values and CC mapping of selected component(s) into clipboard", "EDIT", 0);
		//	result.setActive(true);
		//result.addDefaultKeypress('v', ModifierKeys::ctrlModifier);
		break;
	case CommandIDs::edit_pasteCCMaps:
		//result.setInfo("Copy", "Stores values and CC mapping of selected component(s) into clipboard", "EDIT", 0);
		//	result.setActive(true);
		//result.addDefaultKeypress('v', ModifierKeys::altModifier);
		break;
	case CommandIDs::edit_showValues:
		//result.setInfo("Show values", "Show values for each component in overlayed textbox", "EDIT", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::edit_showCCMap:
		//result.setInfo("Show CC map", "In overlayed textbox, shows current CC map settings for each component", "EDIT", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::edit_showBufferState:
		//result.setInfo("Show buffer", "Shows current MIDI CC & SysExc messages, waiting for transfer", "EDIT", 0);
		//	result.setActive(true);
			//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::edit_showScopeOutline:
		//result.setInfo("Show scope", "Outlines currently selected component(s) - for easier copy'n'paste operations", "EDIT", 0);

		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::edit_settings:
		//result.setInfo("Settings", "VSTi general configuration options", "EDIT", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::tools_screenshot:
		//result.setInfo("Screenshot", "Creates screenshot of current GUI state and saves it to output directory", "TOOLS", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::tools_readhardware:
		//result.setInfo("Read hardware", "Reads current hardware state", "TOOLS", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::tools_writehardware:
		//result.setInfo("Write hardware", "Writes currently loaded hardware state", "TOOLS", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::tools_hardwareStateToFile:
		//result.setInfo("Hardware to file", "Exports currently loaded hardware state to file", "TOOLS", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::tools_hardwareStateFromFile:
		//result.setInfo("Hardware from file", "Loads hardware state from file", "TOOLS", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;

	case CommandIDs::help_readHardwareSignature:
		//result.setInfo("Signature", "Queries synth hardware for firmware version signature", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_userManual:
		//result.setInfo("User manual", "Opens VSTi user manual PDF", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_hardwareUserManual:
		//result.setInfo("Hardware manual", "Opens general synth user manual PDF", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_synthModelReference:
		//result.setInfo("Synth model", "Generates generic reference in TXT file, describing synth model", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_quickTour:
		//result.setInfo("Quick tour", "Slide-show quick guide, explaining VSTi and synth basics", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_randomTip:
		//result.setInfo("Random tip", "Shows a random tip", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_website:
		//result.setInfo("Web site", "Opens BassZero web page in default browser", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::help_about:
		//result.setInfo("About", "Opens About splash screen", "HELP", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;

	case CommandIDs::devTools_reportModel:
		//result.setInfo("Report model", "Reports synth model", "DevTools", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::devTools_CCDefine:
		//result.setInfo("CC Define", "Generates #define instructions for CC values", "DevTools", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::devTools_FirmwareModel:
		//result.setInfo("Firmware model", "Opens About splash screen", "DevTools", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::devTools_viewBuffer:
		//result.setInfo("View Buffer", "Opens About splash screen", "DevTools", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	case CommandIDs::devTools_viewLog:
		//result.setInfo("View log", "Opens log content", "DevTools", 0);
		//result.addDefaultKeypress('i', ModifierKeys::shiftModifier);
		break;
	}


	return true;
  }
