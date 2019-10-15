/*
  ==============================================================================

    SynthDeviceModel.h
    Created: 1 Oct 2019 10:58:41am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Core\ModelComponentDescription.h"


#include "../Model/Core/SharedPointerVector.h"



#include "../Control/ParameterController.h"
#include "../Control/imbControlParameter.h"
//
//#include "Components\OscilatorWaveform.h"
//#include "Components\OscilatorPerk.h"

#include "Modulation\ModulationFunctionADSR.h"
#include "Modulation\ModulationFunctionENV.h"
#include "Modulation\ModulationFunctionLFO.h"
#include "Modulation\ModulationSourceMacroControl.h"
#include "Modulation\ModulationSourceMIDI.h"
#include "Modulation\ModulationSourceBase.h"

#include "..\Source\Model\ModelConstructionTools.h"
#include "../Source/Model/Core/ControlGroup.h"

#include "Modulation\ModulationHub.h"
#include "Components\ComponentHub.h"
#include "OPM\OPMControlModel.h"

#include "../Source/Model/Core/ControlGroup.h"

#include "SynthDeviceModelComponentBase.h"

#define MODULATIONS modulations.
#define OPMCONTROL opmControl.
#define COMPONENTS components.

#include <vector>

//#include "../Source/Control/imbSynthAudioProcessor.h"
static juce::String MODHUB_ID = juce::String("MOD");
static juce::String MODHUB_LABEL = juce::String("Modulation sources");

static juce::String COMP_ID = juce::String("COMP");
static juce::String COMP_LABEL = juce::String("Synth Components");

static juce::String OPM_ID = juce::String("OPM");
static juce::String OPM_LABEL = juce::String("Operation Mode Control");

class SynthDeviceModel : 
	public ModelComponentWithChildren
	//public SynthDeviceModelComponentBase

{ //: {
 


		/// <summary>
	/// The synth processor
	/// </summary>
//	imbSynthAudioProcessor * SynthProcessor;
    
    public:

		ModulationHub modulations;
		ComponentHub components;
		OPMControlModel opmControl;

		//std::unique_ptr<ParameterController> parameterUnique;

	//std::unique_ptr<ModulationHub> modulations;
	//std::unique_ptr<ComponentHub> components;
	//std::unique_ptr<OPMControlModel> opmControl;

		void PreDeployModel();
		void AfterDeployModel();

		
		
		/// <summary>
		/// The parameter controller - machanism for CC / SysExc ID synthnronization
		/// </summary>
		ParameterController parameterController;



		SharedPointerVector<ControlGroup> Groups;
		
		/// <summary>
/// Deploys this instance.
/// </summary>
		void Deploy();

		void ConstructParameters(juce::AudioProcessorValueTreeState & parameters);

		/* Populates specified vector with all parameters defined in the model*/
		void CollectAllParameters(SharedPointerVector<imbControlParameter> & parameters);


		/*Deploys model*/
		virtual void DeployModel() = 0;


		void AddGroup(ControlGroup * output, std::string _shortName, std::string _longName, ControlGroup * group = nullptr);


		SynthDeviceModel() :ModelComponentWithChildren("Main", "Main","Synth"),
			//parameterController(),
			modulations(), 
			components(), 
			opmControl()
		{ 
		
		};

	/*	SynthDeviceModel(String _shortName, String _longName) :SynthDeviceModelComponentBase(NULL, NULL, _shortName, _longName) {
		
		}
    */
};