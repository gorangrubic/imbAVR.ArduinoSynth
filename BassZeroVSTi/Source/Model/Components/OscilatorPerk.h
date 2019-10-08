/*
  ==============================================================================

    OscilatorPerk.h
    Created: 4 Oct 2019 10:05:46pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Core/ModelComponentWithChildren.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../SynthDeviceModel.h"

#include "OscilatorBase.h"

class OscilatorPerk : 
	public SynthDeviceModelComponentBase,
	public ModelComponentWithChildren {

public:



	void Deploy();

	OscilatorPerk();

//	OscilatorPerk(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }

};