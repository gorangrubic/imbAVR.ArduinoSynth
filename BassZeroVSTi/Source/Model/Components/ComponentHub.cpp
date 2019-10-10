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
	output->PreDeploy(_shortName, _longName);
}

void ComponentHub::AddWaveform(OscilatorWaveform * output)
{
	AddChild(output);

	String letter = imbSynthTools::GetLetter(oscilatorWaveforms.size());
	String _shortName = "WF" + letter;
	String _longName = "Waveform " + letter;
	
	oscilatorWaveforms.push_back(output);
	output->PreDeploy(_shortName, _longName);
}

void ComponentHub::AddPerk(OscilatorPerk * output)
{
	AddChild(output);

	String letter = imbSynthTools::GetLetter(oscilatorWaveforms.size());
	String _shortName = "PERK" + letter;
	String _longName = "PERK " + letter;

	oscilatorPerks.push_back(output);
	output->PreDeploy(_shortName, _longName);
}

void ComponentHub::Deploy()
{
}



ComponentHub::ComponentHub()
{
}
