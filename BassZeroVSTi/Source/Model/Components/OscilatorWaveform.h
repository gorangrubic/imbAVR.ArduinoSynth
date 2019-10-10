/*
  ==============================================================================

    OscilatorWaveform.h
    Created: 4 Oct 2019 10:05:31pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../Core/ModelComponentWithChildren.h"

class OscilatorWaveform : 
	public SynthDeviceModelComponentBase,
	public ModelComponentWithChildren 
{


public:



	void Deploy();

	OscilatorWaveform();

//	OscilatorWaveform(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }
};