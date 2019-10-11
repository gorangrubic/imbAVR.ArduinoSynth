/*
  ==============================================================================

    ModulationSourceMacroControl.cpp
    Created: 4 Oct 2019 9:59:55pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModulationSourceMacroControl.h"

void ModulationSourceMacroControl::Deploy(ParameterController & parameterController)
{
}

ModulationSourceMacroControl::ModulationSourceMacroControl():
	Value() {
	type = ModulationSourceType::Macro;
	NamePrefix = "CTRL";
}

//ModulationSourceMacroControl::ModulationSourceMacroControl(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName),
//Value()
//{
//	type = ModulationSourceType::Macro;
//	NamePrefix = "CTRL";
//}
