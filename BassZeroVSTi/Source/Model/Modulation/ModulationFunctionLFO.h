/*
  ==============================================================================

    ModulationFunctionLFO.h
    Created: 4 Oct 2019 8:43:52pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#include "ModulationSourceBase.h"

class ModulationFunctionLFO : public ModulationSourceBase {

public:

	

	dataIntProperty Time = dataIntProperty("Time", 50, "Time", "Duration of one LFO cycle", "", "", 0, 100, parameterClass::ccLive);

	dataIntProperty TimeFactor = dataIntProperty("TimeFactor", 10, "Time factor", "Multiplier of synth base time unit, applied to the time parameter", "", "", 0, 100, parameterClass::ccSustained);

	dataEnumProperty TimeUnit = dataEnumProperty("TimeUnit", 0, "Time unit", "Used by modulation functions", "timeUnit", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataIntProperty Value = dataIntProperty("Value", 100, "Value", "Peak value of the LFO", "", "", 0, 100, parameterClass::ccLive);
	
	
	dataBoolProperty Retrigger = dataBoolProperty("Retrigger", true,"Note Retrigger", "Designates if LFO resets with start of new note played", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);


	dataBoolProperty Loop = dataBoolProperty("Loop", true, "Loop", "Designates if LFO runs in loop, otherwise it will run only once with new note played", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataEnumProperty Curve = dataEnumProperty("Curve", 1, "Curve", "Value curve function applied to the LFO", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	

	/// <summary>
/// Deploys this instance.
/// </summary>
	void Deploy(ParameterController & parameterController);

	ModulationFunctionLFO(std::string _name = "", std::string _label = "", bool _isMaster = false)
		: ModulationSourceBase(_name, _label, _isMaster, "LFO functions are oscilating from zero to Value and back to zero, in each cycle (Time x Time Factor). CHAOS function moves from Last Target Value to Current Target Value, where New Target Value	is set to random value between 0 and Spread, after each cycle(Time x Time Factor).") {

		type = ModulationSourceType::LFO;
		elementClassRole = "ModulationFunctionLFO";

		layout.OpenBlock("Time", "");

			Add(&Time, true);
			Add(&TimeFactor, true);
			Add(&TimeUnit, true);

		layout.CloseBlock();

		layout.OpenBlock("Value", "");

			Add(&Value, true);
			Add(&Retrigger, true);
			Add(&Curve, true);
			Add(&Loop, true);

		layout.CloseBlock();

		//elementClassRole = "Modulation"
	}

	//ModulationFunctionLFO(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {}
};