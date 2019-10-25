/*
  ==============================================================================

    SynthApplicationEnvironment.h
    Created: 23 Oct 2019 3:27:22pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"

#include "../Source/Application/Help/HelpResourcesManager.h"
#include "../Source/Application/Components/IOPorts.h"
#include "../Source/Application/Files/SynthApplicationFolderCollection.h"

#include "../Source/Data/Model/dataEnumDictionary.h"

class SynthApplicationEnvironment {
 
    public:

		HelpResourcesManager helpManager;
		IOPorts ioPorts;
    	SynthApplicationFolderCollection folders;

		dataEnumDictionary enum_parameterClass = dataEnumDictionary("parameterClass");

		dataEnumDictionary enum_presetNamePrefix = dataEnumDictionary("PresetPrefix","Preset prefixes", "", "", "");

		dataEnumDictionary enum_pitchUnits = dataEnumDictionary("pitchUnits", "Pitch units", "Pitch/frequency unit", "", "");

		dataEnumDictionary enum_signalUnitChangeParameter = dataEnumDictionary("signalUnitChangeParameter", "Preset prefixes", "", "", "");

		dataEnumDictionary enum_signalUnitChange = dataEnumDictionary("signalUnitChange", "Preset prefixes", "", "", "");

		dataEnumDictionary enum_signalUnitChangeMode = dataEnumDictionary("changeFunctions", "Change functions", "", "", "");

		dataEnumDictionary enum_LFOFunctions = dataEnumDictionary("LFOFunctions", "LFO functions", "", "", "");


		dataEnumDictionary enum_macroControlModes = dataEnumDictionary("MacroControlModes", "Macro Control modes", "", "", "");

	
		void init();

	SynthApplicationEnvironment():
		folders(),
		ioPorts(),
		helpManager(folders.FolderHelp)
	{
		init();
	};
    	
};