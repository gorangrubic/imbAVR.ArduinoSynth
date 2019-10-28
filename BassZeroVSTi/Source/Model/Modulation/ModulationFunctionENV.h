/*
  ==============================================================================

    ModulationFunctionENV.h
    Created: 4 Oct 2019 8:43:39pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ModulationSourceBase.h"

class ModulationFunctionENV : public ModulationSourceBase {

public:

	dataIntProperty TimeFactorA = dataIntProperty("TimeFactorA", 1, "Time Factor for A", "Multiplier of synth base time unit, applied to Time A", "", "", 1, 5, parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataIntProperty TimeFactorB = dataIntProperty("TimeFactorB", 4, "Time Factor for B", "Multiplier of synth base time unit, applied to Time B", "", "", 1, 5, parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataIntProperty TimeA = dataIntProperty("TimeA", 40, "Time A", "Period to reach Value A, from start", "", "", 0, 127, parameterClass::ccLive);
	dataIntProperty TimeB = dataIntProperty("TimeB", 127, "Time B", "Period to move from Value A to Value B", "", "", 0, 127, parameterClass::ccLive);

	dataEnumProperty TimeUnit = dataEnumProperty("TimeUnit", 0, "Time unit", "Used by modulation functions", "timeUnit", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataIntProperty ValueA = dataIntProperty("ValueA", 100, "Value A", "Value after Time A", "", "", 0, 127, parameterClass::ccLive);
	dataIntProperty ValueB = dataIntProperty("ValueB", 20, "Value B", "Value after Time B and at start (option)", "", "", 0, 127, parameterClass::ccLive);

	dataBoolProperty StartWithB = dataBoolProperty("StartWithB", true, "Start with B", "If value at beginning is Value B, otherwise it is 0", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataBoolProperty Loop = dataBoolProperty("Loop", true, "Loop", "If the function is looped, otherwise it runs only once (per Note On)", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataEnumProperty TimeUnit = dataEnumProperty("TimeUnit", 0, "Time unit", "Used by modulation functions", "timeUnit", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	/// <summary>
/// Deploys this instance.
/// </summary>
	void Deploy(ParameterController & parameterController);

	ModulationFunctionENV(std::string _name = "", std::string _label = "", bool _isMaster = false)
		: ModulationSourceBase(_name, _label, _isMaster, "ENV is two-point interpolated function. Cycle starts with Level B (option), moves to Level A in period defined by Time A and moves back to Level B in period defined by Time B. ") {
		type = ModulationSourceType::ENV;
		elementClassRole = "ModulationFunctionENV";

		layout.OpenBlock("Time", "");

			Add(&TimeFactorA,true);
			Add(&TimeFactorB, true);
			Add(&TimeA, true);
			Add(&TimeB, true);
			Add(&TimeUnit, true);

		layout.CloseBlock();

		layout.OpenBlock("Value", "");
		
			Add(&ValueA, true);
			Add(&ValueB, true);
			Add(&StartWithB, true);
			Add(&Loop, true);

		layout.CloseBlock();


	
		
		

		//elementClassRole = "Modulation"
	}
//	ModulationFunctionENV(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {};

};