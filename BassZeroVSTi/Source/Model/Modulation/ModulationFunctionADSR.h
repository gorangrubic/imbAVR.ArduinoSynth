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

	imbControlParameter AttackTime = imbControlParameter();
	imbControlParameter DecayTime = imbControlParameter();
	imbControlParameter ReleaseTime = imbControlParameter();

	imbControlParameter InitValue = imbControlParameter();
	imbControlParameter SustainValue = imbControlParameter();

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy() override;

	ModulationFunctionADSR();

	ModulationFunctionADSR(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {}

};