/*
  ==============================================================================

    PitchAndPhaseControl.h
    Created: 15 Oct 2019 2:35:07am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Model/Core/SynthDeviceModelComponentBase.h"

class PitchAndPhaseControl :
	public SynthDeviceModelComponentBase {
 
    public:
    
    	imbControlParameter Pitch;
	    imbControlParameter Phase;
	    

	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy(ParameterController & parameterController);

	PitchAndPhaseControl();
	
    
};