/*
  ==============================================================================

    OPMControlModel.h
    Created: 4 Oct 2019 9:28:21pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../SynthDeviceModelComponentBase.h"
#include "../SynthDeviceModel.h"

#include "OPMSignalUnit.h";
#include "MacroControlLink.h";
#include "OPMControlModel.h"

class OPMControlModel:public SynthDeviceModelComponentBase {

public:

	

	void AddSignalUnit(OPMSignalUnit * SignalUnit, String _shortName, String _longName);
	void AddMacroControlLink(MacroControlLink * SignalControlLink, String _shortName, String _longName);

	std::vector<String> ListOfPitchUnits;
	std::vector<String> ListOfModulationModes;
	std::vector<String> ListOfModulationFunctions;
	std::vector<String> ListOfModulationParameters;

	std::vector<String> ListOfSignalUnits;
	
	// =========================== OPM Signal Units
	OPMSignalUnit WFA = OPMSignalUnit();
	OPMSignalUnit WFB = OPMSignalUnit();
	OPMSignalUnit FLT_RESA = OPMSignalUnit();
	OPMSignalUnit FLT_RESB = OPMSignalUnit();
	OPMSignalUnit PERKA = OPMSignalUnit();
	OPMSignalUnit PERKB = OPMSignalUnit();
	
	
	// =========================== Modulation Macro Controls links
	
	MacroControlLink MODA_MCL1 = MacroControlLink();
	MacroControlLink MODA_MCL2 = MacroControlLink();

	MacroControlLink MODB_MCL1 = MacroControlLink();
	MacroControlLink MODB_MCL2 = MacroControlLink();
	
	MacroControlLink VALA_MCL1 = MacroControlLink();
	MacroControlLink VALB_MCL1 = MacroControlLink();
	MacroControlLink VALC_MCL1 = MacroControlLink();
	MacroControlLink VALC_MCL2 = MacroControlLink();
	
    std::vector<MacroControlLink*> Links;
	std::vector<OPMSignalUnit*> Units;
	
	void Deploy() override;

	OPMControlModel();

	OPMControlModel(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }

};