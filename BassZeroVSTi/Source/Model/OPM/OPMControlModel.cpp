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



std::shared_ptr<MacroControlLink> OPMControlModel::GetLink(juce::String name)
{
	std::shared_ptr<MacroControlLink> output = nullptr;

	for each (auto var in Links)
	{
		if (var->ShortName.equalsIgnoreCase(name)) {
			output = var;
			break;
		}
	}

	return output;
}

std::shared_ptr<OPMSignalUnit> OPMControlModel::GetSignalUnit(juce::String name)
{
	std::shared_ptr<OPMSignalUnit> output = nullptr;

	for each (auto var in Units)
	{
		if (var->ShortName.equalsIgnoreCase(name)) {
			output = var;
			break;
		}
	}

	return output;
}

void OPMControlModel::Deploy(ParameterController & parameterController)
{
	

	
}

//OPMControlModel::OPMControlModel()
//{
//}
