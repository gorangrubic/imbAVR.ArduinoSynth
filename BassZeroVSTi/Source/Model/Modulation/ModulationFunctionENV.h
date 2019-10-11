/*
  ==============================================================================

    ModulationFunctionENV.h
    Created: 4 Oct 2019 8:43:39pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ModulationSourceBase.h"

class ModulationFunctionENV : public ModulationSourceBase {

public:

	imbControlParameter TimeA;
	imbControlParameter TimeB;
	
	imbControlParameter ValueA;
	imbControlParameter ValueB;

	imbControlParameter StartWithB;
	imbControlParameter Loop;

	/// <summary>
/// Deploys this instance.
/// </summary>
	void Deploy(ParameterController & parameterController);

	ModulationFunctionENV();
//	ModulationFunctionENV(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {};

};