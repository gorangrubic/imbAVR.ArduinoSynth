/*
  ==============================================================================

    ModulationFunctionENV.cpp
    Created: 4 Oct 2019 8:43:39pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModulationFunctionENV.h"

void ModulationFunctionENV::Deploy(ParameterController & parameterController)
  {

	AddCCParameter(parameterController,&TimeA, "TimeA", "Time A to B", 40);
	AddCCParameter(parameterController,&TimeB, "TimeB", "Time B to A", 127);
	AddCCParameter(parameterController,&ValueA, "ValueA", "Value A", 100);
	AddCCParameter(parameterController,&ValueB, "ValueB", "Value B", 20);

  }

  ModulationFunctionENV::ModulationFunctionENV() {
	type = ModulationSourceType::ENV;
	NamePrefix = "ENV";
}

//ModulationFunctionENV::ModulationFunctionENV(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {
//	type = ModulationSourceType::ENV;
//	NamePrefix = "ENV";
//}