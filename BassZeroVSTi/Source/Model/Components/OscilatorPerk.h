/*
  ==============================================================================

    OscilatorPerk.h
    Created: 4 Oct 2019 10:05:46pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../Core/ModelComponentWithChildren.h"




class OscilatorPerk : 
	//public SynthDeviceModelComponentBase,
	public ModelComponentWithChildren {

public:



	void Deploy(ParameterController & parameterController);

	OscilatorPerk();

//	OscilatorPerk(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }

};