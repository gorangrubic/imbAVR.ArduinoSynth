/*
  ==============================================================================

    SynthEnumDictionaries.h
    Created: 25 Oct 2019 1:55:47pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Source/Control/imbControlParameterEnumerations.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"

#include "../Source/Data/Model/dataEnumDictionary.h"

class SynthEnumDictionaries:public dataObject
{
public:
	dataEnumDictionary enum_parameterClass = dataEnumDictionary("parameterClass");
	dataEnumDictionary enum_presetNamePrefix = dataEnumDictionary("PresetPrefix", "Preset prefixes", "", "", "");
	dataEnumDictionary enum_pitchUnits = dataEnumDictionary("pitchUnits", "Pitch units", "Pitch/frequency unit", "", "");
	dataEnumDictionary enum_signalUnitChangeParameter = dataEnumDictionary("signalUnitChangeParameter", "Preset prefixes", "", "", "");
	dataEnumDictionary enum_signalUnitChange = dataEnumDictionary("signalUnitChange", "Preset prefixes", "", "", "");
	dataEnumDictionary enum_signalUnitChangeMode = dataEnumDictionary("changeFunctions", "Change functions", "", "", "");

	dataEnumDictionary enum_LFOCurves = dataEnumDictionary("LFOCurves", "LFO curves", "", "", "");
	dataEnumDictionary enum_macroControlModes = dataEnumDictionary("MacroControlModes", "Macro Control modes", "", "", "");


	dataEnumDictionary enum_slaveModulationSources = dataEnumDictionary("SlaveMods", "Slave mods", "", "", "");

	dataEnumDictionary enum_oscilatorTypes = dataEnumDictionary("OscilatorTypes", "Types of oscilators", "", "", "");

	void init();

	SynthEnumDictionaries():dataObject("enums")
	{
		
	}
	
};