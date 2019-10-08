/*
  ==============================================================================

    ComponentHub.h
    Created: 5 Oct 2019 12:37:43am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../Source/Model/Core/ModelComponentWithChildren.h"
#include "../Core/ModelComponentWithChildren.h"
#include "../Core/ModelComponentDescription.h"

// #include "../SynthDeviceModel.h"
#include "../Core/ModelModulatedControl.h"


#include <vector>

#include "OscilatorPerk.h"
#include "OscilatorWaveform.h"



class ComponentHub : 
	public SynthDeviceModelComponentBase,
	public ModelComponentWithChildren {


public:

	std::vector<ModelModulatedControl *> modulatedControls;
	std::vector<OscilatorWaveform *> oscilatorWaveforms;
	std::vector<OscilatorPerk *> oscilatorPerks;

	void Deploy();

	void AddModulatedControl(ModelModulatedControl * output, String _shortName, String _longName);

	void AddWaveform(OscilatorWaveform * output);
	void AddPerk(OscilatorPerk * output);

	ComponentHub();

	//ComponentHub(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }


};