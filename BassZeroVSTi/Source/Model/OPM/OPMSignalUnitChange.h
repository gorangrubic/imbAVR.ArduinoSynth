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
#include "../Source/Control/imbControlParameter.h"
#include "..\Source\Model\ModelConstructionTools.h"

class OPMSignalUnitChange :
	public SynthDeviceModelComponentBase
{
public:

	//OPMControlModel * opmParent;

	imbControlParameter Enabled;
	imbControlParameter Sync;
	imbControlParameter Chaos;

	imbControlParameter Rate;
	imbControlParameter Period;
	imbControlParameter Change;
	imbControlParameter Function;

	void Deploy(ParameterController & parameterController) ;

	OPMSignalUnitChange();

//	OPMSignalUnitChange(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }
};