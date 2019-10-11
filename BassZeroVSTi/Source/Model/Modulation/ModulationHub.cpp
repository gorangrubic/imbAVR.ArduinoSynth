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

	// ========================== populates list of sources ===========
	for each (auto var in ADSRs)
	{
		parameterControllerPtr->ListOfSources.Add(var->ShortName);
	}

	for each (auto var in ENVs)
	{
		parameterControllerPtr->ListOfSources.Add(var->ShortName);
	}

	for each (auto var in LFOs)
	{
		parameterControllerPtr->ListOfSources.Add(var->ShortName);
	}

	for each (auto var in MacroControls)
	{
		parameterControllerPtr->ListOfSources.Add(var->ShortName);
	}

	for each (auto var in MIDIs)
	{
		parameterControllerPtr->ListOfSources.Add(var->ShortName);
	}


}

void ModulationHub::AddADSR(ModulationFunctionADSR * output)
{
	 
	//auto ptr = &output;
	AddChild(output);
	
	String letter = imbSynthTools::GetLetter(ADSRs.size());
	output->SetDescription("ADSR_" + letter, "Attack Decay Sustain Release function " + letter, parameterControllerPtr);

	ADSRs.Add(output);

	
}

void ModulationHub::AddENV(ModulationFunctionENV * output)
{
	 
	//auto ptr = &output;

	AddChild(output);
	String letter = imbSynthTools::GetLetter(ENVs.size());
	output->SetDescription("ENV_" + letter, "Two-point Envelope " + letter, parameterControllerPtr);

	ENVs.Add(output);

	
}

void ModulationHub::AddLFO(ModulationFunctionLFO * output)
{
	 
	///auto ptr = &output;

	AddChild(output);
	String letter = imbSynthTools::GetLetter(LFOs.size());
	output->SetDescription("LFO_" + letter, "Low Frequency Oscilator " + letter, parameterControllerPtr);

	LFOs.Add(output);

	
}

void ModulationHub::AddMacroControl(ModulationSourceMacroControl * output)
{
	 
	 //auto ptr = &output;

	AddChild(output);
	String letter = imbSynthTools::GetLetter(MacroControls.size());
	output->SetDescription("CTRL " + letter, "Control Macro " + letter, parameterControllerPtr);

	MacroControls.Add(output);
	

	
}


void ModulationHub::AddMIDI(ModulationSourceMIDI * output, ModulationSourceMIDIType _midiType, String _shortName, String _longName)
{
	
	//output->typeMidi = _midiType;

	

	AddChild(output);
	output->SetDescription(_shortName, _longName, parameterControllerPtr);
	MIDIs.Add(output);
	
//	MIDIs.push_back(output);


}

