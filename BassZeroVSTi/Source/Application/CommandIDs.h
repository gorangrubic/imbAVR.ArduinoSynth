/*
  ==============================================================================

    CommandIDs.h
    Created: 12 Oct 2019 3:40:52am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
//==============================================================================
	/** A list of the commands that this demo responds to. */
enum class CommandIDs
{
	file_initState = 1,
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

enum class MenuGroupIDS {
	file = 0,
	midi = 1,
	edit = 2,
	tools = 3,
	help = 4,
	devTools = 5
};

