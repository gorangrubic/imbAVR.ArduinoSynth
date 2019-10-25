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

	
	dataIntProperty TimeFactor = dataIntProperty("TimeFactor", 2, "Time Factor", "Multiplier of synth base time unit, applied to all time parameters (A,D,R)", "", "", 1, 5, parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);
	
	dataIntProperty AttackTime = dataIntProperty("AttackTime", 5, "Attack time", "", "", "", 0, 127, parameterClass::ccSustained);
	dataIntProperty DecayTime = dataIntProperty("DecayTime", 25, "Decay time", "", "", "", 0, 127, parameterClass::ccSustained);
	dataIntProperty ReleaseTime = dataIntProperty("ReleaseTime", 25, "Release time", "", "", "", 0, 127, parameterClass::ccSustained);

	dataIntProperty InitValue = dataIntProperty("InitValue", 0, "Initial value", "Value of the function at beginning of note", "", "", 0, 127, parameterClass::ccSustained);
	dataIntProperty SustainValue = dataIntProperty("SustainValue", 65, "Release time", "Value that function keeps during the sustain period", "", "", 0, 127, parameterClass::ccSustained);

	dataBoolProperty VelAsPeak = dataBoolProperty("VelAsPeak", true, "Velocity as peak", "Note velocity defines peak value (reached after attack period), otherwise peak is max. value.", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy(ParameterController & parameterController);

	

	ModulationFunctionADSR(std::string _name = "", std::string _label = "", bool _isMaster = false)
		: ModulationSourceBase(_name, _label, _isMaster, "ADSR functions start with the Initial value. At end of the attack period value reaches the maximum (peak). Afterwards, the value decays to Sustain value and waits for Note Off MIDI event to fall(release) to zero.") {

		type = ModulationSourceType::ADSR;
		elementClassRole = "ModulationFunctionADSR";

		Add(&TimeFactor);
		Add(&AttackTime);
		Add(&DecayTime);
		Add(&ReleaseTime);
		Add(&InitValue);
		Add(&SustainValue);
		Add(&VelAsPeak);

		//elementClassRole = "Modulation"
	}



//	ModulationFunctionADSR(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :ModulationSourceBase(_root, _parent, _shortName, _longName) {}

};