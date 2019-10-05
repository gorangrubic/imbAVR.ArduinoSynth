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

	imbControlParameter TimeA = imbControlParameter();
	imbControlParameter TimeB = imbControlParameter();
	
	imbControlParameter ValueA = imbControlParameter();
	imbControlParameter ValueB = imbControlParameter();

	/// <summary>
/// Deploys this instance.
/// </summary>
	void Deploy() override;

	ModulationFunctionENV();
	ModulationFunctionENV(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName);

};