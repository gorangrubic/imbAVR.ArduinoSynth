/*
  ==============================================================================

    ModulationSourceMacroControl.h
    Created: 4 Oct 2019 9:59:55pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#include "ModulationSourceBase.h"
class ModulationSourceMacroControl : public ModulationSourceBase {

public:

	dataIntProperty Value = dataIntProperty("Value", 127, "Value", "Peak value of the LFO", "", "", 0, 127, parameterClass::ccLive);

	dataEnumProperty Mode = dataEnumProperty("Mode", 0, "Mode", "Operation mode of the macro control", "", "", parameterClass::opm);

	

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy(ParameterController & parameterController);

	ModulationSourceMacroControl(std::string _name = "", std::string _label = "", bool _isMaster = false)
		: ModulationSourceBase(_name, _label, _isMaster, "Macro Controls allow control of more than one synth parameter from single point.") {

		type = ModulationSourceType::Macro;
		elementClassRole = "ModulationSourceMacroControl";
		Add(&Value);
		Add(&Mode);
		

		//elementClassRole = "Modulation"
	}

};