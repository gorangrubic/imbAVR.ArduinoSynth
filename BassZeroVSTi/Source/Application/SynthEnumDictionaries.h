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
#include "../Data/Header.h"

//#include "../Source/Control/imbControlParameterEnumerations.h"
//#include "../Source/Data/Model/dataObject.h"
//#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
//
//#include "../Source/Data/Model/dataEnumDictionary.h"

class SynthEnumDictionaries:public dataObject
{
public:
	dataEnumDictionary parameterClass = dataEnumDictionary("parameterClass");
	dataEnumDictionary presetNamePrefix = dataEnumDictionary("presetNamePrefix", "Preset prefixes", "", "", "");
	dataEnumDictionary pitchUnits = dataEnumDictionary("pitchUnits", "Pitch units", "Pitch/frequency unit", "", "");
	dataEnumDictionary signalUnitChangeParameter = dataEnumDictionary("signalUnitChangeParameter", "Preset prefixes", "", "", "");
	dataEnumDictionary signalUnitChange = dataEnumDictionary("signalUnitChange", "Preset prefixes", "", "", "");
	dataEnumDictionary signalUnitChangeMode = dataEnumDictionary("signalUnitChangeMode", "Change functions", "", "", "");

	dataEnumDictionary timeUnit = dataEnumDictionary("timeUnit", "Time unit", "What time unit is used with [Time] and [TimeFactor] to applied (real) time periods?", "", "");
	dataEnumDictionary LFOCurves = dataEnumDictionary("LFOCurves", "LFO curves", "", "", "");
	dataEnumDictionary macroControlModes = dataEnumDictionary("macroControlModes", "Macro Control modes", "", "", "");
	
	dataEnumDictionary oscilatorTypes = dataEnumDictionary("oscilatorTypes", "Types of oscilators", "", "", "");


	// Model enums

	dataEnumDictionary macroControlLinks = dataEnumDictionary("macroControlLinks", "MacroControlLinks", "", "", "");
	dataEnumDictionary modulationMode = dataEnumDictionary("modulationMode", "Modulation mode", "Mode used to combine two signal/values into single result.", "", "");

	dataEnumDictionary slaveModulationSources = dataEnumDictionary("slaveModulationSources", "Slave mods", "", "", "");

	dataEnumDictionary masterModulationSources = dataEnumDictionary("masterModulationSources", "Master mods", "", "", "");

	dataEnumDictionary modulationSources = dataEnumDictionary("modulationSources", "modulationSources", "", "", "");

	dataEnumDictionary oscilators = dataEnumDictionary("oscilators", "oscilators", "", "", "");

	
	dataEnumDictionary modulationFunctionADSR = dataEnumDictionary("modulationFunctionADSR", "modulationSources", "", "", "");
	dataEnumDictionary modulationFunctionENV = dataEnumDictionary("modulationFunctionENV", "modulationSources", "", "", "");
	dataEnumDictionary modulationFunctionLFO = dataEnumDictionary("modulationFunctionLFO", "modulationSources", "", "", "");
	dataEnumDictionary modulationSourceMacroControl = dataEnumDictionary("modulationSourceMacroControl", "modulationSources", "", "", "");


	// library enums
	dataEnumDictionary contributors = dataEnumDictionary("contributors", "", "", "", "");
	dataEnumDictionary groups = dataEnumDictionary("groups", "", "", "", "");
	dataEnumDictionary libraries = dataEnumDictionary("libraries", "", "", "", "");

	dataEnumDictionary keyPressCodes = dataEnumDictionary("keyPressCodes", "", "", "", "");

	dataEnumDictionary keyPressModifiers = dataEnumDictionary("keyPressModifiers", "", "", "", "");

	void init();

	SynthEnumDictionaries():dataObject("enums")
	{
		add(&parameterClass);
		add(&presetNamePrefix);
		add(&pitchUnits);
		add(&signalUnitChangeParameter);
		add(&signalUnitChange);
		add(&signalUnitChangeMode);
		add(&LFOCurves);
		add(&macroControlModes);
		add(&oscilatorTypes);
		
		add(&timeUnit);
		add(&macroControlLinks);
		add(&modulationMode);

		add(&modulationSources);
		add(&slaveModulationSources);
		add(&masterModulationSources);

		add(&oscilators);

		add(&modulationFunctionADSR);
		add(&modulationFunctionENV);
		add(&modulationFunctionLFO);
		add(&modulationSourceMacroControl);
		add(&contributors);

		add(&contributors);
		add(&groups);
		add(&libraries);


		add(&keyPressCodes);

		add(&keyPressModifiers);


	}
	
};