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
#include "../Source/Control/imbControlParameter.h"
#include "../Core/ModelComponentWithChildren.h"
#include "../Core/SharedPointerVector.h";
#include "../Core/ControlGroup.h";
#include "OPMSignalUnitChange.h"
//#include "OPMControlModel.h"
#include "..\Source\Model\ModelConstructionTools.h"


class OPMSignalUnit:
	//public SynthDeviceModelComponentBase,
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

	//OPMSignalUnitChange PhaseChange;
	//OPMSignalUnitChange PWMChange;
	//OPMSignalUnitChange PitchChange;

	SharedPointerVector<OPMSignalUnitChange> ChangeUnits;

	std::shared_ptr<OPMSignalUnitChange> GetUnitChange(String name);

	//OPMControlModel * opmParent;

	OPMSignalUnit();

//	OPMSignalUnit(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) : SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { };

	void Deploy(ParameterController & parameterController) ;
	void AddChangeUnit(OPMSignalUnitChange * output, std::string _shortName, std::string _longName, ControlGroup * group = nullptr);

};