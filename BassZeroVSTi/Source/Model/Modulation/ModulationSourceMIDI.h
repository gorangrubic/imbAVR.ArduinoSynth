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




class ModulationSourceMIDI : public ModulationSourceBase {

public:

	imbControlParameter Value;

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy(ParameterController & parameterController) ;
	ModulationSourceMIDIType typeMidi = ModulationSourceMIDIType::velocity;

	ModulationSourceMIDI(std::string _name = "", std::string _label = "")
		: ModulationSourceBase(_name, _label, "ADSR functions start with the Initial value. At end of the attack period value reaches the maximum (peak). Afterwards, the value decays to Sustain value and waits for Note Off MIDI event to fall(release) to zero.") {

		type = ModulationSourceType::ADSR;
		Add(&TimeFactor);
		Add(&AttackTime);
		Add(&DecayTime);
		Add(&ReleaseTime);
		Add(&InitValue);
		Add(&SustainValue);
		Add(&VelAsPeak);

		//elementClassRole = "Modulation"
	}

//	ModulationSourceMIDI(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName):ModulationSourceBase(_root, _parent, _shortName, _longName) {	}
};