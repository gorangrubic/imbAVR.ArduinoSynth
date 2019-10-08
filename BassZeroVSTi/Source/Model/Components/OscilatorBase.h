/*
  ==============================================================================

    OscilatorBase.h
    Created: 4 Oct 2019 10:05:21pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../SynthDeviceModel.h"

class OscilatorBase : public SynthDeviceModelComponentBase {

public:

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	//virtual void Deploy() = 0;
	
	OscilatorBase();

	/*OscilatorBase(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) {

	}*/
};