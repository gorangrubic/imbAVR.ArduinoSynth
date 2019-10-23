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
enum CommandIDs
{
	file_initState = 1,
	file_loadPreset=2,
	file_savePreset=3,
	file_loadOPM=4,
	file_saveOPM=5,
	file_selectLibrary=6,

	file_rescanLibrary,

	file_loadSettings,
	file_saveSettings,
	file_saveSettingsAs,
	file_close,

	midi_factoryCCMap,
	midi_loadCCMap,
	midi_saveCCMap,
	midi_editCCMap,
	midi_presetToMidiInstructions,
	midi_executeMidiInstructions,

	midi_inputOutput,
	midi_rescan,

	edit_copy,
	edit_pasteValues,
	edit_pasteCCMaps,

	edit_presetInfo,

	edit_showValues,
	edit_showCCMap,
	edit_showBufferState,
	edit_showScopeOutline,

	edit_settings,

	edit_refresh,

	tools_screenshot,
	tools_readhardware,
	tools_writehardware,
	tools_hardwareStateToFile,
	tools_hardwareStateFromFile,

	tools_diagnostic,

	
	

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

enum  MenuGroupIDS {
	file = 0,
	midi = 1,
	edit = 2,
	tools = 3,
	help = 4,
	devTools = 5
};

