/*
  ==============================================================================

    ModulationFunctionADSR.h
    Created: 4 Oct 2019 8:41:39pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ModulationSourceBase.h"



class ModulationFunctionADSR : public ModulationSourceBase {

public:

	imbControlParameter AttackTime;
	imbControlParameter DecayTime;
	imbControlParameter ReleaseTime;

	imbControlParameter InitValue;
	imbControlParameter SustainValue;

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy(ParameterController & parameterController);

	ModulationFunctionADSR();

//	ModulationFunctionADSR(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {}

};