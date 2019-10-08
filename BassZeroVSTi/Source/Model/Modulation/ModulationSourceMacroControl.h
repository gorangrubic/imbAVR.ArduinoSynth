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

	imbControlParameter Value;

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy();

	ModulationSourceMacroControl();

	//ModulationSourceMacroControl(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName)
	//	:ModulationSourceBase(_root, _parent, _shortName, _longName),
	//	Value()
	//{	}
};