/*
  ==============================================================================

    SynthDeviceModel.cpp
    Created: 1 Oct 2019 10:58:41am
    Author:  gorangrubic

  ==============================================================================
*/

#include "SynthDeviceModel.h"

void SynthDeviceModel::PreDeployModel()
{
	
}

void SynthDeviceModel::AfterDeployModel()
{

	 
}

/* MAIN DEPLOY function too call. Executes: PreDeploy, DeployModel and AfterDeploy*/
void SynthDeviceModel::Deploy()
{
	  deploy("");

}

void SynthDeviceModel::ConstructParameters(juce::AudioProcessorValueTreeState & parameters)
{
	  

	deployAutomation(parameters);
	parameters.state = ValueTree("BassZero");
}

void SynthDeviceModel::PrepareEnums(SynthEnumDictionaries & output)
{
	for each (std::shared_ptr<dataElementBase> var in children)
	{
		dataElementBase * var_ptr = var.get();

		if (var->elementClassRole == "MacroControlLink") {
			output.macroControlLinks.AddEntry(var->parameterID, var->parameterLabel, var->parameterHelp);
		} else if (var->elementClassRole == "ModulationFunctionADSR") {
			ModulationSourceBase * _modulationBase = static_cast<ModulationSourceBase*>(var_ptr);
			if (_modulationBase->IsMaster) {
				output.masterModulationSources.AddEntry(var_ptr);
			}
			else {
				output.slaveModulationSources.AddEntry(var_ptr);
			}

			output.modulationSources.AddEntry(var_ptr);
			output.modulationFunctionADSR.AddEntry(var_ptr);

			// to do
		}
		else if (var->elementClassRole == "ModulationFunctionENV") {
			ModulationSourceBase * _modulationBase = static_cast<ModulationSourceBase*>(var_ptr);
			if (_modulationBase->IsMaster) {
				output.masterModulationSources.AddEntry(var_ptr);
			}
			else {
				output.slaveModulationSources.AddEntry(var_ptr);
			}

			output.modulationSources.AddEntry(var_ptr);
			output.modulationFunctionENV.AddEntry(var_ptr);
		}
		else if (var->elementClassRole == "ModulationFunctionLFO") {
			ModulationSourceBase * _modulationBase = static_cast<ModulationSourceBase*>(var_ptr);
			if (_modulationBase->IsMaster) {
				output.masterModulationSources.AddEntry(var_ptr);
			}
			else {
				output.slaveModulationSources.AddEntry(var_ptr);
			}

			output.modulationSources.AddEntry(var_ptr);
			output.modulationFunctionLFO.AddEntry(var_ptr);
		}
		else if (var->elementClassRole == "ModulationSourceMacroControl") {
			ModulationSourceBase * _modulationBase = static_cast<ModulationSourceBase*>(var_ptr);
			if (_modulationBase->IsMaster) {
				output.masterModulationSources.AddEntry(var_ptr);
			}
			else {
				output.slaveModulationSources.AddEntry(var_ptr);
			}

			output.modulationSources.AddEntry(var_ptr);
			output.modulationSourceMacroControl.AddEntry(var_ptr);
		}
		else if (var->elementClassRole == "OscilatorBase") {
			OscilatorBase* _OscilatorBase = static_cast<OscilatorBase*>(var_ptr);

			output.oscilators.AddEntry(var_ptr);
			// to do
		}
		else if (var->elementClassRole == "ModulationFunctionADSR") {
			ModulationFunctionADSR* _ModulationFunctionADSR = static_cast<ModulationFunctionADSR*>(var_ptr);
			// to do
		}
		else if (var->elementClassRole == "ModulationFunctionADSR") {
			ModulationFunctionADSR* _ModulationFunctionADSR = static_cast<ModulationFunctionADSR*>(var_ptr);
			// to do
		}
		else if (var->elementClassRole == "ModulationFunctionADSR") {
			ModulationFunctionADSR* _ModulationFunctionADSR = static_cast<ModulationFunctionADSR*>(var_ptr);
			// to do
		}
		else if (var->elementClassRole == "ModulationFunctionADSR") {
			ModulationFunctionADSR* _ModulationFunctionADSR = static_cast<ModulationFunctionADSR*>(var_ptr);
			// to do
		}
		else if (var->elementClassRole == "ModulationFunctionADSR") {
			ModulationFunctionADSR* _ModulationFunctionADSR = static_cast<ModulationFunctionADSR*>(var.get());
			// to do
		}
		else if (var->elementClassRole == "ModulationFunctionADSR") {
			ModulationFunctionADSR* _ModulationFunctionADSR = static_cast<ModulationFunctionADSR*>(var.get());
			// to do
		}
	}

}
