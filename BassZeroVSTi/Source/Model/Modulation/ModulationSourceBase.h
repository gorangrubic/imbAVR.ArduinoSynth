/*
  ==============================================================================

    ModulationSourceBase.h
    Created: 4 Oct 2019 10:00:17pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once




#include "../JuceLibraryCode/JuceHeader.h"


#include "../Source/Data/Model/dataObject.h"

class ModulationSourceBase : public dataObject {

public:

	dataBoolProperty Enabled = dataBoolProperty("Enabled", true, "Enabled", "Sets if modulation source is enabled/active.", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataEnumProperty SlaveTarget = dataEnumProperty("SlaveTarget", 0, "Slave target", "Modulated property of a Slave modulation source", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	bool IsMaster; 

	/// <summary>
	  /// Deploys this instance.
	  /// </summary>
	//virtual void Deploy() = 0;

	ModulationSourceType type = ModulationSourceType::unknown;
	
	ModulationSourceBase(std::string _name = "", std::string _label = "", bool _isMaster=false, std::string _description = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::ccLive)
		: dataObject(_name, _label, _description, "", _helpUrl,_parClass) {
		
		IsMaster = _isMaster;

		Add(&Enabled,true);
		Add(&SlaveTarget, true);
		
	}
	
	//ModulationSourceBase(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) {}
};