/*
  ==============================================================================

    MacroControlLink.h
    Created: 4 Oct 2019 9:27:38pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Control/imbControlParameter.h"
#include "../Source/Model/SynthDeviceModelComponentBase.h"
//#include "../SynthDeviceModel.h"
#include "../SynthDeviceModelComponentBase.h"
//#include "OPMSignalUnitChange.h"
//#include "OPMControlModel.h"

class MacroControlLink :public SynthDeviceModelComponentBase {

public:

//	OPMControlModel * opmParent;

	imbControlParameter ModAmt;
	imbControlParameter Signal;

	imbControlParameter ModTar;
	imbControlParameter ModPar;

	void Deploy() ;

	MacroControlLink();

	//MacroControlLink(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) : SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { };

}; 