/*
  ==============================================================================

    OPMSignalUnit.h
    Created: 4 Oct 2019 9:29:49pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../SynthDeviceModel.h"
#include "../../imbAVR.DedicatedSignalGeneratorLibrary/src/SignalChangeInstruction.h"
#include "../../imbAVR.DedicatedSignalGeneratorLibrary/src/SignalControlUnit.h"
#include "../Source/Control/imbControlParameter.h"

#include "../Source/Model/OPM/OPMSignalUnitChange.h"




class OPMSignalUnit:
	public SignalControlUnitClass,
	public SynthDeviceModelComponentBase
{

public:

	imbControlParameter Enabled = imbControlParameter();
	imbControlParameter Sync = imbControlParameter();

	imbControlParameter PitchUnit = imbControlParameter();
	imbControlParameter RelativeToNote = imbControlParameter();
	imbControlParameter DoublePrescalar = imbControlParameter();
	imbControlParameter PWMCycleMode = imbControlParameter();

	imbControlParameter WaveformPattern = imbControlParameter();
	imbControlParameter ModByte = imbControlParameter();

	OPMSignalUnitChange PhaseChange = OPMSignalUnitChange();
	OPMSignalUnitChange PWMChange = OPMSignalUnitChange();
	OPMSignalUnitChange PitchChange = OPMSignalUnitChange();

	OPMSignalUnit OPMSignalUnit();

	OPMSignalUnit OPMSignalUnit(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) : SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { };

	void Deploy() override;

};