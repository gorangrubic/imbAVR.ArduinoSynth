/*
  ==============================================================================

    ModulationHub.h
    Created: 4 Oct 2019 10:49:16pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../SynthDeviceModelComponentBase.h"
#include "../Core/ModelComponentWithChildren.h"

#include "ModulationFunctionADSR.h"
#include "ModulationFunctionENV.h"
#include "ModulationFunctionLFO.h"
#include "ModulationSourceMacroControl.h"
#include "ModulationSourceMIDI.h"
#include "ModulationSourceBase.h"
//#include "../Core/SharedPointerVector.h"
#include "..\Source\Model\ModelConstructionTools.h"
#include <vector>

#include <cstddef> // for NULL



class ModulationHub : 
//	public SynthDeviceModelComponentBase,
	public ModelComponentWithChildren {


	
public:



	SharedPointerVector<ModulationFunctionADSR> ADSRs{ };
	SharedPointerVector<ModulationFunctionENV> ENVs{ };
	SharedPointerVector<ModulationFunctionLFO> LFOs{ };
	SharedPointerVector<ModulationSourceMacroControl> MacroControls{ };
	SharedPointerVector<ModulationSourceMIDI> MIDIs;



	//std::vector<ModulationFunctionADSR*> ADSRs;
	//std::vector<ModulationFunctionENV*> ENVs;
	//std::vector<ModulationFunctionLFO*> LFOs;
	//std::vector<ModulationSourceMacroControl*> MacroControls;
//	std::vector<ModulationSourceMIDI*> MIDIs;



	/// <summary>
	/// Deploys this instance.
	/// </summary>
	void Deploy(ParameterController & parameterController) ;

	//void Reset();
	
	void AddADSR(ModulationFunctionADSR * output);
	void AddENV(ModulationFunctionENV * output);
	void AddLFO(ModulationFunctionLFO * output);
	void AddMacroControl(ModulationSourceMacroControl * output);

	void AddMIDI(ModulationSourceMIDI * output, ModulationSourceMIDIType _midiType, std::string _shortName, std::string _longName);

	ModulationHub() :ModelComponentWithChildren("MOD", "MOD", "Modulation sources"),
		MIDIs{ SharedPointerVector<ModulationSourceMIDI>() }
	{

	}

};