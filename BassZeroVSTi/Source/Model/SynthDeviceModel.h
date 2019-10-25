/*
  ==============================================================================

    SynthDeviceModel.h
    Created: 1 Oct 2019 10:58:41am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"

#include "../Source/Model/Components/ModelModulatedControl.h"
#include "../Source/Model/Components/OscilatorBase.h"
#include "../Source/Model/Components/MacroControlLink.h"
#include "../Source/Model/Components/OPMSignalUnitChange.h"


//#include "../Control/ParameterController.h"

//
//#include "Components\OscilatorWaveform.h"
//#include "Components\OscilatorPerk.h"

#include "../Source/Model/Modulation/ModulationFunctionADSR.h"
#include "../Source/Model/Modulation/ModulationFunctionENV.h"
#include "../Source/Model/Modulation/ModulationFunctionLFO.h"
#include "../Source/Model/Modulation/ModulationSourceMacroControl.h"

//#include "../Source/Model/ModelConstructionTools.h"

#include <vector>

//#include "../Source/Control/imbSynthAudioProcessor.h"
//static String MODHUB_ID = String("MOD");
//static String MODHUB_LABEL = String("Modulation sources");
//
//static String COMP_ID = String("COMP");
//static String COMP_LABEL = String("Synth Components");
//
//static String OPM_ID = String("OPM");
//static String OPM_LABEL = String("Operation Mode Control");

class SynthDeviceModel :public dataObject
	//public SynthDeviceModelComponentBase

{
	//: {


	/// <summary>
/// The synth processor
/// </summary>
	//	imbSynthAudioProcessor * SynthProcessor;

public:

	void PreDeployModel();
	void AfterDeployModel();

	
	/// <summary>
/// Deploys this instance.
/// </summary>
	void Deploy();

	void ConstructParameters(AudioProcessorValueTreeState& parameters);

	/* Populates specified vector with all parameters defined in the model*/
	//void CollectAllParameters(SharedPointerVector<imbControlParameter>& parameters);


	/*Deploys model*/
	virtual void DeployModel() = 0;

	std::string version;

	//void AddGroup(ControlGroup* output, std::string _shortName, std::string _longName, ControlGroup* group = nullptr);

	
	SynthDeviceModel(std::string _name = "", std::string _label = "", std::string _version="", std::string _description = "", std::string _helpUrl = "")
		: dataObject(_name, _label, _description, "", _helpUrl) 
	{
				version = _version;
	};

	/*	SynthDeviceModel(String _shortName, String _longName) :SynthDeviceModelComponentBase(NULL, NULL, _shortName, _longName) {
		
		}
    */
};