/*
  ==============================================================================

    ModulationSourceBase.h
    Created: 4 Oct 2019 10:00:17pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once




#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Control/imbControlParameter.h"
#include "../Source/Model/Core/SynthDeviceModelComponentBase.h"

#include "../Source/Data/Model/dataObject.h"

class ModulationSourceBase : public dataObject {

public:

	dataBoolProperty Enabled = dataBoolProperty("Enabled", true, "Enabled", "Sets if modulation source is enabled/active.", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	bool IsPrimaryModulationSource; 

	/// <summary>
	  /// Deploys this instance.
	  /// </summary>
	//virtual void Deploy() = 0;

	ModulationSourceType type = ModulationSourceType::unknown;
	
	ModulationSourceBase(std::string _name = "", std::string _label = "", std::string _description = "", std::string _helpUrl = "")
		: dataObject(_name, _label, _description, "", _helpUrl) {

		AddProperty(&Enabled);
	}
	
	//ModulationSourceBase(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) {}
};