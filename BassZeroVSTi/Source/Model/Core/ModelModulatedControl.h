/*
  ==============================================================================

    ModelModulatedControl.h
    Created: 5 Oct 2019 2:49:59am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Model/Core/SynthDeviceModelComponentBase.h"
#include "..\Source\Model\ModelConstructionTools.h"

class ModelModulatedControl:
	public SynthDeviceModelComponentBase {

public:

	imbControlParameter ModAmt;
	imbControlParameter ModSrc;
	imbControlParameter Val;

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy(ParameterController & parameterController);

	ModelModulatedControl();

	/*ModelModulatedControl(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) {
	
		NamePrefix = "";
	
	}*/
	
};