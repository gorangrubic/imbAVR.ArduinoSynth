/*
  ==============================================================================

    ComponentBase.h
    Created: 5 Oct 2019 2:49:23am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../SynthDeviceModel.h"

class ComponentBase : public SynthDeviceModelComponentBase {


public:

	/// <summary>
  /// Deploys this instance.
  /// </summary>
	virtual void Deploy() = 0;

};