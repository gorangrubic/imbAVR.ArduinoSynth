/*
  ==============================================================================

    ModulationHub.h
    Created: 4 Oct 2019 10:49:16pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../Source/Model/Core/SynthDeviceModelComponentBase.h"
#include "../Core/ModelComponentWithChildren.h"

#include "ModulationFunctionADSR.h"
#include "ModulationFunctionENV.h"
#include "ModulationFunctionLFO.h"
#include "ModulationSourceMacroControl.h"
#include "ModulationSourceMIDI.h"
#include "ModulationSourceBase.h"
//#include "../Source/Data/Structures/SharedPointerVector.h"
#include "..\Source\Model\ModelConstructionTools.h"
#include <vector>

#include <cstddef> // for NULL

#define PARAMCONTROL parameterController

class ModulationHub : 
//	public SynthDeviceModelComponentBase,
	public ModelComponentWithChildren {

	template<typename T>
	std::shared_ptr<T> GetModulationSourceByName(juce::String name, SharedPointerVector<T> & collection)
	{
		std::shared_ptr<T> output = nullptr;

		//juce::String needleString = juce::String(name);

		for each (auto var in collection)
		{
			if (var->ShortName.equalsIgnoreCase(name)) {
				output = var;
				break;
			}
		}

		return output;
	}
	
public:



	SharedPointerVector<ModulationFunctionADSR> ADSRs{ };
	SharedPointerVector<ModulationFunctionENV> ENVs{ };
	SharedPointerVector<ModulationFunctionLFO> LFOs{ };
	SharedPointerVector<ModulationSourceMacroControl> MacroControls{ };
	SharedPointerVector<ModulationSourceMIDI> MIDIs;

	
	std::shared_ptr<ModulationFunctionADSR> GetADSRByName(juce::String name);
	std::shared_ptr<ModulationFunctionENV> GetENVByName(juce::String name);
	std::shared_ptr<ModulationFunctionLFO> GetLFOByName(juce::String name);
	std::shared_ptr<ModulationSourceMacroControl> GetMacroByName(juce::String name);
	std::shared_ptr<ModulationSourceMIDI> GetMIDIByName(juce::String name);

	//{
	//	std::shared_ptr<ModulationFunctionADSR> output = nullptr;

	//	//juce::String needleString = juce::String(name);

	//	for each (auto var in ADSRs)
	//	{
	//		if (var->ShortName.equalsIgnoreCase(name)) {
	//			output = var;
	//			break;
	//		}
	//	}

	//	return output;
	//}
	//

	//std::vector<ModulationFunctionADSR*> ADSRs;
	//std::vector<ModulationFunctionENV*> ENVs;
	//std::vector<ModulationFunctionLFO*> LFOs;
	//std::vector<ModulationSourceMacroControl*> MacroControls;
//	std::vector<ModulationSourceMIDI*> MIDIs;



	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy(ParameterController & parameterController) ;

	//void Reset();
	
	void AddADSR(ModulationFunctionADSR * output);
	void AddENV(ModulationFunctionENV * output);
	void AddLFO(ModulationFunctionLFO * output);
	void AddMacroControl(ModulationSourceMacroControl * output);

	void AddMIDI(ModulationSourceMIDI * output, ModulationSourceMIDIType _midiType, std::string _shortName, std::string _longName);

	ModulationHub() :ModelComponentWithChildren("MOD", "MOD", "Modulation sources"),
		MIDIs{ SharedPointerVector<ModulationSourceMIDI>() }
	{

	}

};