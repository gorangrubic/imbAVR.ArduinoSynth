/*
  ==============================================================================

    ModelModulatedControl.h
    Created: 5 Oct 2019 2:49:59am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#include "../Source/Model/SynthDeviceModelComponentBase.h"

class ModelModulatedControl:SynthDeviceModelComponentBase {

public:

	imbControlParameter ModAmt = imbControlParameter();
	imbControlParameter ModSrc = imbControlParameter();
	imbControlParameter Val = imbControlParameter();

	/// <summary>
  /// Deploys this instance.
  /// </summary>
	void Deploy() override;

	ModelModulatedControl();

	ModelModulatedControl(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) {
	
		NamePrefix = "";
	
	}
	
};