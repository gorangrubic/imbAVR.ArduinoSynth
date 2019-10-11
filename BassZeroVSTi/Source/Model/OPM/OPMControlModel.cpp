/*
  ==============================================================================

    OPMControlModel.cpp
    Created: 4 Oct 2019 9:28:21pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "OPMControlModel.h"

void OPMControlModel::AddSignalUnit(OPMSignalUnit * SignalUnit, String _shortName, String _longName)
{
	
	AddChild(SignalUnit);
	Units.push_back(SignalUnit);
	SignalUnit->SetDescription(_shortName, _longName, parameterControllerPtr);
	SignalUnit->SetParent(model, this);
	//SignalUnit->Deploy();
}

void OPMControlModel::AddMacroControlLink(MacroControlLink * SignalControlLink, String _shortName, String _longName)
{
	SignalControlLink->SetDescription(_shortName, _longName, parameterControllerPtr);
	AddChild(SignalControlLink);
	Links.push_back(SignalControlLink);
	
}

void OPMControlModel::Deploy()
{
	parameterControllerPtr->ListOfModulationFunctions.Add("One-shot");
	parameterControllerPtr->ListOfModulationFunctions.Add("Loop");
	parameterControllerPtr->ListOfModulationFunctions.Add("Mirror");
	parameterControllerPtr->ListOfModulationFunctions.Add("Continual");

	parameterControllerPtr->ListOfPitchUnits.Add("Semitones");
	parameterControllerPtr->ListOfPitchUnits.Add("Octaves");
	parameterControllerPtr->ListOfPitchUnits.Add("1 Hz");
	parameterControllerPtr->ListOfPitchUnits.Add("10 Hz");
	parameterControllerPtr->ListOfPitchUnits.Add("100 Hz");
	parameterControllerPtr->ListOfPitchUnits.Add("500 Hz");
	parameterControllerPtr->ListOfPitchUnits.Add("1000 Hz");
	parameterControllerPtr->ListOfPitchUnits.Add("2000 Hz");

	parameterControllerPtr->ListOfModulationParameters.Add("OFF");
	parameterControllerPtr->ListOfModulationParameters.Add("Rate");
	parameterControllerPtr->ListOfModulationParameters.Add("Period");
	parameterControllerPtr->ListOfModulationParameters.Add("Change");
	
	parameterControllerPtr->ListOfModulationModes.Add("OFF");
	parameterControllerPtr->ListOfModulationModes.Add("Pitch");
	parameterControllerPtr->ListOfModulationModes.Add("PWM");
	parameterControllerPtr->ListOfModulationModes.Add("Phase");
	
	// ==== registrating units and links
	for each (OPMSignalUnit * var in Units)
	{
		parameterControllerPtr->ListOfSignalUnits.Add(var->ShortName);
	}

	// ===== links

	for each (MacroControlLink * var in Links)
	{
		parameterControllerPtr->ListOfMacroLinks.Add(var->ShortName);
	}
	
}

OPMControlModel::OPMControlModel()
{
}
