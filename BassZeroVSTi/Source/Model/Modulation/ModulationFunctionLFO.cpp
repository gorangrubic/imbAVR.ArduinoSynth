/*
  ==============================================================================

    ModulationFunctionLFO.cpp
    Created: 4 Oct 2019 8:43:52pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModulationFunctionLFO.h"

void ModulationFunctionLFO::Deploy()
{
}

ModulationFunctionLFO::ModulationFunctionLFO() {
	type = ModulationSourceType::LFO;
	NamePrefix = "LFO";

}

//ModulationFunctionLFO::ModulationFunctionLFO(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {
//	type = ModulationSourceType::LFO;
//	NamePrefix = "LFO";
//}