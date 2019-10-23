/*
  ==============================================================================

    OPMControlModel.h
    Created: 4 Oct 2019 9:28:21pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Model/Core/SynthDeviceModelComponentBase.h"
#include "../Core/ModelComponentWithChildren.h"
#include "../Core/ModelComponentDescription.h"
#include "../Source/Data/Structures/SharedPointerVector.h"
//#include "../SynthDeviceModel.h"
#include "..\Source\Model\ModelConstructionTools.h"
#include "MacroControlLink.h"
#include "OPMSignalUnit.h"



class OPMControlModel:
	//public ModelComponentDescription,
	public ModelComponentWithChildren {

public:

	

	void AddSignalUnit(OPMSignalUnit * SignalUnit, std::string _shortName, std::string _longName);
	void AddMacroControlLink(MacroControlLink * SignalControlLink, std::string _shortName, std::string _longName);


	SharedPointerVector<MacroControlLink> Links;
	SharedPointerVector<OPMSignalUnit> Units;


	std::shared_ptr<MacroControlLink> GetLink(juce::String name);
	std::shared_ptr<OPMSignalUnit> GetSignalUnit(juce::String name);


 //   std::vector<MacroControlLink*> Links;
	//std::vector<OPMSignalUnit*> Units;
	
	void Deploy(ParameterController & parameterController) ;

	OPMControlModel() :ModelComponentWithChildren("OPM", "OPM","Operation Modes") {}

//	OPMControlModel(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }

};