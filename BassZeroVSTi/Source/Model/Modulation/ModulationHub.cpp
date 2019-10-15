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


#include "../Source/Model/ModelConstructionTools.h"


//std::vector<String> ModulationHub::GetListOfSources()
//{
//	auto output = std::vector<String>();
//}

std::shared_ptr<ModulationFunctionADSR> ModulationHub::GetADSRByName(juce::String name)
{
return GetModulationSourceByName<ModulationFunctionADSR>(name, ADSRs);
}

  std::shared_ptr<ModulationFunctionENV> ModulationHub::GetENVByName(juce::String name)
  {
	  return GetModulationSourceByName<ModulationFunctionENV>(name, ENVs);
  }

  std::shared_ptr<ModulationFunctionLFO> ModulationHub::GetLFOByName(juce::String name)
  {
	  return GetModulationSourceByName<ModulationFunctionLFO>(name, LFOs);// std::shared_ptr<ModulationFunctionLFO>();
  }

  std::shared_ptr<ModulationSourceMacroControl> ModulationHub::GetMacroByName(juce::String name)
  {
	  return  GetModulationSourceByName<ModulationSourceMacroControl>(name, MacroControls);//		  std::shared_ptr<ModulationSourceMacroControl>();
  }

  std::shared_ptr<ModulationSourceMIDI> ModulationHub::GetMIDIByName(juce::String name)
  {
	  return  GetModulationSourceByName<ModulationSourceMIDI>(name, MIDIs);// std::shared_ptr<ModulationSourceMIDI>();
  }

  /* Call Deploy after adding components externally */
void ModulationHub::Deploy(ParameterController & parameterController)
{


}

void ModulationHub::AddADSR(ModulationFunctionADSR * output)
{
	 
	//auto ptr = &output;
	AddChild(output);
	
	//ParameterController &pc = *parameterControllerPtr;


	std::string letter = imbSynthTools::GetLetter(ADSRs.size());
	output->SetDescription("ADSR_" + letter, "Attack Decay Sustain Release function " + letter); //, &pc);

	ADSRs.Add(output);

	
}

void ModulationHub::AddENV(ModulationFunctionENV * output)
{
	 
	//auto ptr = &output;

	AddChild(output);
	std::string letter = imbSynthTools::GetLetter(ENVs.size());

	//ParameterController &pc = *parameterControllerPtr;

	output->SetDescription("ENV_" + letter, "Two-point Envelope "); // + letter, &pc);

	ENVs.Add(output);

	
}

void ModulationHub::AddLFO(ModulationFunctionLFO * output)
{
	 
	///auto ptr = &output;
//	ParameterController &pc = *parameterControllerPtr;
	AddChild(output);
	std::string letter = imbSynthTools::GetLetter(LFOs.size());
	output->SetDescription("LFO_" + letter, "Low Frequency Oscilator "); // + letter, &pc);

	LFOs.Add(output);

	
}

void ModulationHub::AddMacroControl(ModulationSourceMacroControl * output)
{
	 
//	 //auto ptr = &output;
	//ParameterController &pc = *parameterControllerPtr;

	AddChild(output);
	std::string letter = imbSynthTools::GetLetter(MacroControls.size());
	//output->SetDescription("CTRL " + letter, "Control Macro " + letter, &pc);
	output->SetDescription("CTRL " + letter, "Control Macro "); // +letter, &pc);

	MacroControls.Add(output);
	

	
}


void ModulationHub::AddMIDI(ModulationSourceMIDI * output, ModulationSourceMIDIType _midiType, std::string _shortName, std::string _longName)
{
	
	output->typeMidi = _midiType;

//	ParameterController &pc = *parameterControllerPtr;


	AddChild(output);
	output->SetDescription(_shortName, _longName); //, &pc);
	MIDIs.Add(output);
	
//	MIDIs.Add(_back(output);


}

