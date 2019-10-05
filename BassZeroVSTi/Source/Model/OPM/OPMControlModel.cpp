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

	ListOfModulationParameters.push_back("Rate");
	ListOfModulationParameters.push_back("Period");
	ListOfModulationParameters.push_back("Change");
	
	ListOfModulationModes.push_back("Pitch");
	ListOfModulationModes.push_back("PWM");
	ListOfModulationModes.push_back("Phase");
	

	// =================== Deploying Macro Control Links
	AddMacroControlLink(&MODA_MCL1, "MODA_MCL1", "OPM Macro Modulation A - 1");
	AddMacroControlLink(&MODA_MCL2, "MODA_MCL2", "OPM Macro Modulation A - 2");
	AddMacroControlLink(&MODB_MCL1, "MODB_MCL1", "OPM Macro Modulation B - 1");
	AddMacroControlLink(&MODB_MCL2, "MODB_MCL2", "OPM Macro Modulation B - 2");

	AddMacroControlLink(&VALA_MCL1, "VALA_MCL1", "OPM Macro Value A");
	AddMacroControlLink(&VALB_MCL1, "VALB_MCL1", "OPM Macro Value B");
	AddMacroControlLink(&VALC_MCL1, "VALC_MCL1", "OPM Macro Value C");
	AddMacroControlLink(&VALC_MCL2, "VALC_MCL2", "OPM Macro Value C");

	AddMacroControlLink(&MODA_MCL1, "MODA_MCL1", "OPM Macro Modulation A - 1");


	// =================== OPM COntrol parameters for the signal generator units

	AddSignalUnit(&WFA, "WFA", "Waveform A");
	AddSignalUnit(&WFB, "WFB", "Waveform B");
	
	AddSignalUnit(&FLT_RESA, "FLT_RESA", "Filter Resonance A");
	AddSignalUnit(&FLT_RESB, "FLT_RESB", "Filter Resonance B");
	
	AddSignalUnit(&PERKA, "PERKA", "PERK A");
	AddSignalUnit(&PERKB, "PERKB", "PERK B");
}
