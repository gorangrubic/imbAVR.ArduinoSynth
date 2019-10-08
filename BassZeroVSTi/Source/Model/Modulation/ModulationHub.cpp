/*
  ==============================================================================

    ModulationHub.cpp
    Created: 4 Oct 2019 10:49:16pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModulationHub.h"
#include "../Source/Utility/imbSynthTools.h"
#include "../SynthDeviceModel.h"

//std::vector<String> ModulationHub::GetListOfSources()
//{
//	auto output = std::vector<String>();
//}

/* Call Deploy after adding components externally */
void ModulationHub::Deploy()
{
}

void ModulationHub::AddADSR(ModulationFunctionADSR * output)
{
	 
	//auto ptr = &output;
	AddChild(output);
	
	String letter = imbSynthTools::GetLetter(ADSRs.size);
	output->PreDeploy(Root, Parent, letter, "Attack Decay Sustain Release function " + letter);

	ADSRs.push_back(output);

	
}

void ModulationHub::AddENV(ModulationFunctionENV * output)
{
	 
	//auto ptr = &output;

	AddChild(output);
	String letter = imbSynthTools::GetLetter(ENVs.size);
	output->PreDeploy(Root, Parent, letter, "Two-point Envelope " + letter);

	ENVs.push_back(output);

	
}

void ModulationHub::AddLFO(ModulationFunctionLFO * output)
{
	 
	///auto ptr = &output;

	AddChild(output);
	String letter = imbSynthTools::GetLetter(LFOs.size);
	output->PreDeploy(Root, Parent, letter, "Low Frequency Oscilator " + letter);

	LFOs.push_back(output);

	
}

void ModulationHub::AddMacroControl(ModulationSourceMacroControl * output)
{
	 
	 //auto ptr = &output;

	AddChild(output);
	String letter = imbSynthTools::GetLetter(MacroControls.size);
	output->PreDeploy(Root, Parent, "CTRL " + letter, "Control Macro " + letter);

	MacroControls.push_back(output);
	

	
}


void ModulationHub::AddMIDI(ModulationSourceMIDI * output, ModulationSourceMIDIType _midiType, String _shortName, String _longName)
{
	
	output->typeMidi = _midiType;

	

	AddChild(output);

	output->PreDeploy(Root, Parent, _shortName, _longName);
	
	MIDIs.push_back(output);


}
