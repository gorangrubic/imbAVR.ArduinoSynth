/*
  ==============================================================================

    MacroControlLink.h
    Created: 4 Oct 2019 9:27:38pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../SynthDeviceModel.h"
#include "../Source/Model/OPM/OPMSignalUnitChange.h"

#include "../../imbAVR.DedicatedSignalGeneratorLibrary/src/SignalChangeInstruction.h"
#include "../../imbAVR.DedicatedSignalGeneratorLibrary/src/SignalControlUnit.h"
#include "../Source/Control/imbControlParameter.h"
#include "../Source/Model/OPM/OPMControlModel.h"

class MacroControlLink :public SynthDeviceModelComponentBase {

public:

	OPMControlModel * opmParent;

	imbControlParameter ModAmt = imbControlParameter();
	imbControlParameter Signal = imbControlParameter();

	imbControlParameter ModTar = imbControlParameter();
	imbControlParameter ModPar = imbControlParameter();

	void Deploy() override;

	MacroControlLink();

	MacroControlLink(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) : SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { };

}; 