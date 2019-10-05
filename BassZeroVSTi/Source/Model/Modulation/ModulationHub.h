/*
  ==============================================================================

    ModulationHub.h
    Created: 4 Oct 2019 10:49:16pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "ModulationFunctionADSR.h"
#include "ModulationFunctionENV.h"
#include "ModulationFunctionLFO.h"
#include "ModulationSourceMacroControl.h"
#include "ModulationSourceMIDI.h"
#include "ModulationSourceBase.h"

#include <vector>

#include <cstddef> // for NULL

class ModulationHub : public SynthDeviceModelComponentBase {

protected:

	
public:

	std::vector<ModulationFunctionADSR*> ADSRs;
	std::vector<ModulationFunctionENV*> ENVs;
	std::vector<ModulationFunctionLFO*> LFOs;
	std::vector<ModulationSourceMacroControl*> MacroControls;
	std::vector<ModulationSourceMIDI*> MIDIs;

	std::vector<String> ListOfSources;
	std::vector<String> ListOfLFOFunctions;

	/// <summary>
  /// Deploys this instance.
  /// </summary>
	void Deploy() override;
	
	ModulationFunctionADSR AddADSR();
	ModulationFunctionENV AddENV();
	ModulationFunctionLFO AddLFO();
	ModulationSourceMacroControl AddMacroControl();

	ModulationSourceMIDI AddMIDI(ModulationSourceMIDIType _midiType, String _shortName, String _longName);
};