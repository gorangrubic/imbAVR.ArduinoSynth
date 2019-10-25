/*
  ==============================================================================

    ModelModulatedControl.h
    Created: 5 Oct 2019 2:49:59am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"


class ModelModulatedControl : public dataObject {

public:

	dataIntProperty ModAmt = dataIntProperty("ModAmt", 0, "Mod. Amount", "Modulation amount and direction","","",-64,64);
	dataEnumProperty ModSrc = dataEnumProperty("ModSrc", 0, "Modulation source", "Modulation function or macro control providing modulation value for this control", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);
	dataIntProperty Val = dataIntProperty("Val", 0, "Value", "Modulation amount and direction","","",0,127);
	

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	//void Deploy(ParameterController & parameterController);

	ModelModulatedControl(std::string _name = "", std::string _label = "", std::string _description = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::ccLive)
		: dataObject(_name, _label, _description, "", _helpUrl,_parClass) {

		elementClassRole = "ModelModulatedControl";
		
	}

	/*ModelModulatedControl(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) {
	
		NamePrefix = "";
	
	}*/
	
};