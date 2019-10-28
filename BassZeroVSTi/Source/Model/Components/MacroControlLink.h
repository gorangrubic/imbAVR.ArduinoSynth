/*
  ==============================================================================

    MacroControlLink.h
    Created: 4 Oct 2019 9:27:38pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
//#include "../Source/Control/imbControlParameter.h"
//#include "../Source/Model/Core/SynthDeviceModelComponentBase.h"
//#include "../Source/Model/ModelConstructionTools.h"

//#include "../SynthDeviceModel.h"

//#include "OPMSignalUnitChange.h"
//#include "OPMControlModel.h"

class MacroControlLink : public dataObject {

public:

	dataIntProperty ModAmt = dataIntProperty("ModAmt", 0, "Mod. Amount", "Modulation amount and direction","%","",-100,100,parameterClass::opm);
	dataEnumProperty Signal = dataEnumProperty("Signal", 0, "Signal", "Targeted signal", "oscilators", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);
	dataEnumProperty ModTar = dataEnumProperty("ModTar", 0, "Target", "Target of the modulation", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);
	dataEnumProperty ModPar = dataEnumProperty("ModPar", 0, "Parameter", "Parameter being modulated", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);
	
	MacroControlLink(std::string _name = "", std::string _label = "", std::string _description = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::ccLive)
		: dataObject(_name, _label, _description, "", _helpUrl, _parClass) {

		elementClassRole = "MacroControlLink";


	}

	//MacroControlLink(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) : SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { };

}; 