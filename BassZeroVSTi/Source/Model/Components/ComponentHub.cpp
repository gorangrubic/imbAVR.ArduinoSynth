/*
  ==============================================================================

    ComponentHub.cpp
    Created: 5 Oct 2019 12:37:43am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ComponentHub.h"
#include "../Source/Utility/imbSynthTools.h"


void ComponentHub::AddModulatedControl(ModelModulatedControl * output, std::string _shortName, std::string _longName)
{
	AddChild(output);
	modulatedControls.Add(output);
	output->SetDescription(_shortName, _longName);
	//output->SetParent(model, this);
}

void ComponentHub::AddWaveform(OscilatorWaveform * output)
{
	AddChild(output);

	std::string letter = imbSynthTools::GetLetter(oscilatorWaveforms.size());
	std::string _shortName = "WF" + letter;
	std::string _longName = "Waveform " + letter;
	
	oscilatorWaveforms.Add(output);
	output->SetDescription(_shortName, _longName);
	//output->SetParent(model, this);
}

void ComponentHub::AddPerk(OscilatorPerk * output)
{
	AddChild(output);

	std::string letter = imbSynthTools::GetLetter(oscilatorWaveforms.size());
	std::string _shortName = "PERK" + letter;
	std::string _longName = "PERK " + letter;

	oscilatorPerks.Add(output);
	output->SetDescription(_shortName, _longName);
//	output->SetParent(model,this);
}

std::shared_ptr<ModelModulatedControl> ComponentHub::GetModulatedControlByName(juce::String name)
{
	std::shared_ptr<ModelModulatedControl> output = nullptr;

	//juce::String needleString = juce::String(name);

	for each (auto var in modulatedControls)
	{
		if (var->ShortName.equalsIgnoreCase(name)) {
			output = var;
			break;
		}
	}
	
	return output;
}

void ComponentHub::Deploy(ParameterController & parameterController)
{

	for each (auto var in modulatedControls)
	{
		var->Deploy(parameterController);
	}

	for each (auto var in oscilatorPerks)
	{
		var->Deploy( parameterController);
	}

	for each (auto var in oscilatorWaveforms)
	{
		var->Deploy(parameterController);
	}

}


//
//ComponentHub::ComponentHub()
//{
//}
