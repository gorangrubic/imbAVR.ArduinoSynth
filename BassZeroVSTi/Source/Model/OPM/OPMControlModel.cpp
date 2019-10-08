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
	SignalUnit->PreDeploy(Root, this, _shortName, _longName);
	AddChild(SignalUnit);
	Units.push_back(SignalUnit);
	SignalUnit->Deploy();
}

void OPMControlModel::AddMacroControlLink(MacroControlLink * SignalControlLink, String _shortName, String _longName)
{
	SignalControlLink->PreDeploy(Root, this, _shortName, _longName);
	AddChild(SignalControlLink);
	Links.push_back(SignalControlLink);
	SignalControlLink->Deploy();
}

void OPMControlModel::Deploy()
{
	ListOfModulationFunctions.push_back("One-shot");
	ListOfModulationFunctions.push_back("Loop");
	ListOfModulationFunctions.push_back("Mirror");
	ListOfModulationFunctions.push_back("Continual");

	ListOfPitchUnits.push_back("Semitones");
	ListOfPitchUnits.push_back("Octaves");
	ListOfPitchUnits.push_back("1 Hz");
	ListOfPitchUnits.push_back("10 Hz");
	ListOfPitchUnits.push_back("100 Hz");
	ListOfPitchUnits.push_back("500 Hz");
	ListOfPitchUnits.push_back("1000 Hz");
	ListOfPitchUnits.push_back("2000 Hz");

	ListOfModulationParameters.push_back("OFF");
	ListOfModulationParameters.push_back("Rate");
	ListOfModulationParameters.push_back("Period");
	ListOfModulationParameters.push_back("Change");
	
	ListOfModulationModes.push_back("OFF");
	ListOfModulationModes.push_back("Pitch");
	ListOfModulationModes.push_back("PWM");
	ListOfModulationModes.push_back("Phase");
	

	
}

OPMControlModel::OPMControlModel()
{
}
