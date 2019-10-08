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

	imbControlParameter Time;
	imbControlParameter TimeFactor;

	imbControlParameter Value;
	
	imbControlParameter Retrigger;
	imbControlParameter Loop;

	imbControlParameter Function;

	/// <summary>
/// Deploys this instance.
/// </summary>
	void Deploy();

	ModulationFunctionLFO();

	//ModulationFunctionLFO(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {}
};