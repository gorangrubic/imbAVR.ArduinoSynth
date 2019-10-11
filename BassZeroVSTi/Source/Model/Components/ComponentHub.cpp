/*
  ==============================================================================

    ComponentHub.cpp
    Created: 5 Oct 2019 12:37:43am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ComponentHub.h"
#include "../Source/Utility/imbSynthTools.h"


void ComponentHub::AddModulatedControl(ModelModulatedControl * output, String _shortName, String _longName)
{
	AddChild(output);
	modulatedControls.push_back(output);
	output->SetDescription(_shortName, _longName, parameterControllerPtr);
	//output->SetParent(model, this);
}

void ComponentHub::AddWaveform(OscilatorWaveform * output)
{
	AddChild(output);

	String letter = imbSynthTools::GetLetter(oscilatorWaveforms.size());
	String _shortName = "WF" + letter;
	String _longName = "Waveform " + letter;
	
	oscilatorWaveforms.push_back(output);
	output->SetDescription(_shortName, _longName, parameterControllerPtr);
	//output->SetParent(model, this);
}

void ComponentHub::AddPerk(OscilatorPerk * output)
{
	AddChild(output);

	String letter = imbSynthTools::GetLetter(oscilatorWaveforms.size());
	String _shortName = "PERK" + letter;
	String _longName = "PERK " + letter;

	oscilatorPerks.push_back(output);
	output->SetDescription(_shortName, _longName, parameterControllerPtr);
//	output->SetParent(model,this);
}

void ComponentHub::Deploy()
{

	for each (ModelModulatedControl * var in modulatedControls)
	{
		var->Deploy();
	}

	for each (OscilatorPerk * var in oscilatorPerks)
	{
		var->Deploy();
	}

	for each (OscilatorWaveform * var in oscilatorWaveforms)
	{
		var->Deploy();
	}

}


//
//ComponentHub::ComponentHub()
//{
//}
