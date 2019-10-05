/*
  ==============================================================================

    ModulationSourceMIDI.h
    Created: 4 Oct 2019 10:00:31pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ModulationSourceBase.h"


enum ModulationSourceMIDIType {
	unknown = 0,
	velocity,
	note,
	pitchbend,
	aftertouch
};

class ModulationSourceMIDI : public ModulationSourceBase {

public:

	imbControlParameter Value = imbControlParameter();

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy() override;

	ModulationSourceMIDIType typeMidi = ModulationSourceMIDIType::velocity;

	ModulationSourceMIDI();

	ModulationSourceMIDI(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName):ModulationSourceBase(_root, _parent, _shortName, _longName) {	}
};