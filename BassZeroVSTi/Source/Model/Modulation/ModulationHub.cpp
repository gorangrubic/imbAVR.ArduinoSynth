/*
  ==============================================================================

    ModulationHub.cpp
    Created: 4 Oct 2019 10:49:16pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModulationHub.h"

#include "../SynthDeviceModel.h"

std::vector<String> ModulationHub::GetListOfSources()
{
	auto output = std::vector<String>();
}

void ModulationHub::Deploy()
{
}

ModulationFunctionADSR ModulationHub::AddADSR()
{
	ModulationFunctionADSR output = ModulationFunctionADSR();
	auto ptr = &output;
	AddChild(ptr);
	
	String letter = SynthDeviceModel::GetLetter(ADSRs.size);
	output.PreDeploy(Root, Parent, letter, "Attack Decay Sustain Release function " + letter);

	ADSRs.push_back(ptr);

	return output;
}

ModulationFunctionENV ModulationHub::AddENV()
{
	ModulationFunctionENV output = ModulationFunctionENV();
	auto ptr = &output;

	AddChild(ptr);
	String letter = SynthDeviceModel::GetLetter(ENVs.size);
	output.PreDeploy(Root, Parent, letter, "Two-point Envelope " + letter);

	ENVs.push_back(ptr);

	return output;
}

ModulationFunctionLFO ModulationHub::AddLFO()
{
	ModulationFunctionLFO output = ModulationFunctionLFO();
	auto ptr = &output;

	AddChild(ptr);
	String letter = SynthDeviceModel::GetLetter(LFOs.size);
	output.PreDeploy(Root, Parent, letter, "Low Frequency Oscilator " + letter);

	LFOs.push_back(ptr);

	return output;
}

ModulationSourceMacroControl ModulationHub::AddMacroControl()
{
	ModulationSourceMacroControl output = ModulationSourceMacroControl();
	auto ptr = &output;

	AddChild(ptr);
	String letter = SynthDeviceModel::GetLetter(MacroControls.size);
	output.PreDeploy(Root, Parent, "CTRL " + letter, "Control Macro " + letter);

	MacroControls.push_back(ptr);
	

	return output;
}


ModulationSourceMIDI ModulationHub::AddMIDI(ModulationSourceMIDIType _midiType, String _shortName, String _longName)
{
	ModulationSourceMIDI output = ModulationSourceMIDI();
	output.typeMidi = _midiType;

	auto ptr = &output;

	AddChild(ptr);

	output.PreDeploy(Root, Parent, _shortName, _longName);

	MIDIs.push_back(ptr);

	return output;
}
