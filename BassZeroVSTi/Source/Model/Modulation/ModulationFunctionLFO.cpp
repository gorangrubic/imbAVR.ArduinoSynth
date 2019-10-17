/*
  ==============================================================================

    ModulationFunctionLFO.cpp
    Created: 4 Oct 2019 8:43:52pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModulationFunctionLFO.h"

void ModulationFunctionLFO::Deploy(ParameterController & parameterController)
{

	AddCCParameter(parameterController, &Time, "Time", "Cycle time", 25);
	AddCCParameter(parameterController, &TimeFactor, "TimeFactor", "Time multiplier", 1);
	AddCCParameter(parameterController, &Value, "Value", "Peak value", 127);
	
	AddBoolParameter(parameterController, &Retrigger, "Retrigger", "Note-On retrigger",true);
	AddBoolParameter(parameterController, &Loop, "Loop", "Loop", true);

	AddEnumParameter(parameterController, &Function, "Function", "Curve function", &parameterController.ListOfLFOFunctions);
}

ModulationFunctionLFO::ModulationFunctionLFO() {
	type = ModulationSourceType::LFO;
//	NamePrefix = "LFO";

}

//ModulationFunctionLFO::ModulationFunctionLFO(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {
//	type = ModulationSourceType::LFO;
//	NamePrefix = "LFO";
//}