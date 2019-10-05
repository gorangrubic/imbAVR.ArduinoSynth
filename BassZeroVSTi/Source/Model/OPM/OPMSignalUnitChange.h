/*
  ==============================================================================

    OPMSignalUnitChange.h
    Created: 5 Oct 2019 1:45:04pm
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
#include "../Source/Model/OPM/OPMControlModel.h"


class OPMSignalUnitChange :
	public SignalControlUnitClass,
	public SynthDeviceModelComponentBase
{
public:

	OPMControlModel * opmParent;

	imbControlParameter Enabled = imbControlParameter();
	imbControlParameter Sync = imbControlParameter();
	imbControlParameter Chaos = imbControlParameter();

	imbControlParameter Rate = imbControlParameter();
	imbControlParameter Period = imbControlParameter();
	imbControlParameter Change = imbControlParameter();
	imbControlParameter Function = imbControlParameter();

	void Deploy() override;

	OPMSignalUnitChange();

	OPMSignalUnitChange(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }
};