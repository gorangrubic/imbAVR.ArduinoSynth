/*
  ==============================================================================

    SynthDeviceModel.h
    Created: 1 Oct 2019 10:58:41am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Model/Core/ModelComponentDescription.h"

#include "../Control/ParameterController.h"
#include "../Control/imbControlParameter.h"

#include "Components\OscilatorWaveform.h"
#include "Components\OscilatorPerk.h"

#include "Modulation\ModulationFunctionADSR.h"
#include "Modulation\ModulationFunctionENV.h"
#include "Modulation\ModulationFunctionLFO.h"
#include "Modulation\ModulationSourceMacroControl.h"
#include "Modulation\ModulationSourceMIDI.h"
#include "Modulation\ModulationSourceBase.h"


#include "Modulation\ModulationHub.h"
#include "Components\ComponentHub.h"
#include "OPM\OPMControlModel.h"

#include "SynthDeviceModelComponentBase.h"


#include <vector>

#include "../Source/Control/imbSynthAudioProcessor.h"


class SynthDeviceModel : 
	public ModelComponentDescription 

{ //: public SynthDeviceModelComponentBase {
 

		/// <summary>
	/// The synth processor
	/// </summary>
	imbSynthAudioProcessor * SynthProcessor;
    
    public:

		void PreDeployModel();
		void AfterDeployModel();


		
		/// <summary>
		/// The parameter controller - machanism for CC / SysExc ID synthnronization
		/// </summary>
		ParameterController parameterController;

		
		/// <summary>
/// Deploys this instance.
/// </summary>
		void Deploy();

		//virtual void DeployModel(imbSynthAudioProcessor * synthProcessor) = 0;



		SynthDeviceModel();

	/*	SynthDeviceModel(String _shortName, String _longName) :SynthDeviceModelComponentBase(NULL, NULL, _shortName, _longName) {
		
		}
    */
};