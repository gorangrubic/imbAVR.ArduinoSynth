/*
  ==============================================================================

    ModulationFunctionADSR.cpp
    Created: 4 Oct 2019 8:41:39pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModulationFunctionADSR.h"

void ModulationFunctionADSR::Deploy()
{
	AddCCParameter(&AttackTime, "Attack", "Attack Time", 5);
	AddCCParameter(&DecayTime, "Decay", "Decay Time", 15);
	AddCCParameter(&ReleaseTime, "Release", "Release Time", 25);

	AddCCParameter(&InitValue, "InitValue", "Initial Value", 0);
	AddCCParameter(&SustainValue, "SustainValue", "Sustain Value", 60);

	//AddParameter(&AttackTime,"Attack", "Attack", 0, 127, 5, "tu", 0, true, imbControlParameterType::Integer);
}

  ModulationFunctionADSR::ModulationFunctionADSR() {
	type = ModulationSourceType::ADSR;
	NamePrefix = "ADSR";
}

//ModulationFunctionADSR::ModulationFunctionADSR(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {
//	type = ModulationSourceType::ADSR;
//	NamePrefix = "ADSR";
//}