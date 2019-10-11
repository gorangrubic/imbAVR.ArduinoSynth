/*
  ==============================================================================

    OPMControlModel.cpp
    Created: 4 Oct 2019 9:28:21pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "OPMControlModel.h"

void OPMControlModel::AddSignalUnit(OPMSignalUnit * SignalUnit, std::string _shortName, std::string _longName)
{
	
	SignalUnit->SetDescription(_shortName, _longName);
	//SignalUnit->SetDescription(_shortName, _longName, parameterControllerPtr);
	AddChild(SignalUnit);
	Units.Add(SignalUnit);
	
	//SignalUnit->SetParent(model, this);
	//SignalUnit->Deploy();
}

void OPMControlModel::AddMacroControlLink(MacroControlLink * SignalControlLink, std::string _shortName, std::string _longName)
{
	//SignalControlLink->SetDescription(_shortName, _longName, parameterControllerPtr);
	SignalControlLink->SetDescription(_shortName, _longName);
	AddChild(SignalControlLink);
	Links.Add(SignalControlLink);
	
}



void OPMControlModel::Deploy(ParameterController & parameterController)
{
	

	
}

//OPMControlModel::OPMControlModel()
//{
//}
