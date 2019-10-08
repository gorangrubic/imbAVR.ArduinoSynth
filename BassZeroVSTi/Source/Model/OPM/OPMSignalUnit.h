/*
  ==============================================================================

    OPMSignalUnit.h
    Created: 4 Oct 2019 9:29:49pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#include "OPMSignalUnitChange.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../SynthDeviceModel.h"
#include "../Source/Control/imbControlParameter.h"
#include "OPMControlModel.h"



class OPMSignalUnit:
	public SynthDeviceModelComponentBase,
	public ModelComponentWithChildren
{

public:

	imbControlParameter Enabled;
	imbControlParameter Sync;

	imbControlParameter PitchUnit;
	imbControlParameter RelativeToNote;
	imbControlParameter DoublePrescalar;
	imbControlParameter PWMCycleMode;

	imbControlParameter WaveformPattern;
	imbControlParameter ModByte;

	OPMSignalUnitChange PhaseChange;
	OPMSignalUnitChange PWMChange;
	OPMSignalUnitChange PitchChange;


	//OPMControlModel * opmParent;

	OPMSignalUnit();

//	OPMSignalUnit(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) : SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { };

	void Deploy() ;

};