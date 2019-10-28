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

	dataIntProperty Value = dataIntProperty("Value", 0, "Value", "Peak value of the LFO", "", "", -100, 100, parameterClass::unspecified);

	dataEnumProperty Mode = dataEnumProperty("Mode", 0, "Mode", "Operation mode of the macro control allows interpretation of the Note expression MIDI values: Velocity, Pitchbend, Modulation, Aftertouch...", "", "", parameterClass::opm);

	dataStringProperty macroControlLabel = dataStringProperty("Label", "", "Label", "Label should be a user-frienldy title, suggesting how this macro control parameter alters the sound.","","", parameterClass::configuration);

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy(ParameterController & parameterController);

	ModulationSourceMacroControl(std::string _name = "", std::string _label = "", bool _isMaster = false, parameterClass _parClass = parameterClass::ccLive)
		: ModulationSourceBase(_name, _label, _isMaster, "Macro Controls allow control of more than one synth parameter from single point.") {

		type = ModulationSourceType::Macro;
		elementClassRole = "ModulationSourceMacroControl";
		Add(&Value,true);
		Add(&Mode,true);
		Add(&macroControlLabel, true);
		

		//elementClassRole = "Modulation"
	}

};

void ModulationSourceMacroControl::Deploy(ParameterController & parameterController)
{
	AddCCParameter(parameterController, &Value, "Value", "Value", 64);
}

ModulationSourceMacroControl::ModulationSourceMacroControl():
	Value() {
	type = ModulationSourceType::Macro;
//	NamePrefix = "CTRL";
}
