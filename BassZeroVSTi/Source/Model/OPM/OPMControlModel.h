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
#include "../Core/ModelComponentWithChildren.h"
#include "../Core/ModelComponentDescription.h"
//#include "../SynthDeviceModel.h"

#include "MacroControlLink.h"
#include "OPMSignalUnit.h"



class OPMControlModel:
	//public ModelComponentDescription,
	public ModelComponentWithChildren {

public:

	

	void AddSignalUnit(OPMSignalUnit * SignalUnit, String _shortName, String _longName);
	void AddMacroControlLink(MacroControlLink * SignalControlLink, String _shortName, String _longName);


	
	
	
    std::vector<MacroControlLink*> Links;
	std::vector<OPMSignalUnit*> Units;
	
	void Deploy() ;

	OPMControlModel();

//	OPMControlModel(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }

};