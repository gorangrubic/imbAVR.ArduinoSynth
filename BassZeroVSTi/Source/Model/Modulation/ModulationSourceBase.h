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
#include "../SynthDeviceModelComponentBase.h"


class ModulationSourceBase : public SynthDeviceModelComponentBase {

public:

	/// <summary>
	  /// Deploys this instance.
	  /// </summary>
	//virtual void Deploy() = 0;

	ModulationSourceType type = ModulationSourceType::unknown;
	
	ModulationSourceBase();
	
	//ModulationSourceBase(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) {}
};