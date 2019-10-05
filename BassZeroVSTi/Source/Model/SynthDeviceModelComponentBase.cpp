/*
  ==============================================================================

    SynthDeviceModelComponentBase.cpp
    Created: 1 Oct 2019 10:58:56am
    Author:  gorangrubic

  ==============================================================================
*/

#include "SynthDeviceModelComponentBase.h"

void SynthDeviceModelComponentBase::AddChild(SynthDeviceModelComponentBase * child)
{
	ChildComponents.push_back(child);
}

void SynthDeviceModelComponentBase::AddBoolParameter(imbControlParameter * output, String _parameterID, String _parameterLabel, bool initValue, int _ccID, bool _isAutomated)
{
}

void SynthDeviceModelComponentBase::AddCCParameter(imbControlParameter* output, String _parameterID, String _parameterLabel,
	int initValue, int minValue, int maxValue)
{
	AddParameter(output, _parameterID, _parameterLabel, minValue, maxValue, initValue, "", Root->parameterController.GetKnobCCID(), true, imbControlParameterType::Integer);	
}

void SynthDeviceModelComponentBase::AddParameter(imbControlParameter* output,String _parameterID, String _parameterLabel,
	float minValue, float maxValue, float initValue,
	String _parameterUnit,
	int _ccID, bool _isAutomatizable, imbControlParameterType _type)
{
	
	output->Setup(_parameterID, _parameterLabel, minValue, maxValue, initValue, _parameterUnit, _ccID,_isAutomatizable,_type);

	Parameters.push_back(output);
}

void SynthDeviceModelComponentBase::BuildParameters()
{
	processorParameterGroup = juce::AudioProcessorParameterGroup(ShortName, LongName, ".");
	  
	juce::AudioProcessorValueTreeState& vt = Root->SynthProcessor->parameters;
	
	for each (imbControlParameter * par in Parameters)
	{
		par->Connect(Parent);

	}

	for each (SynthDeviceModelComponentBase * child in ChildComponents)
	{
		child->BuildParameters();
	}
}

void SynthDeviceModelComponentBase::PreDeploy(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName)
{
	if (NamePrefix == "") {
		ShortName = _shortName;
	}
	else {
		ShortName = NamePrefix + "_" + _shortName;
	}

	if (LongName == "") {
		LongName = NamePrefix + " " + _shortName;
	} 
	else {
		LongName = _longName;
	}
	

	Root = _root;
	Parent = _parent;


	
}

SynthDeviceModelComponentBase::SynthDeviceModelComponentBase(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName)
{
	PreDeploy(_root, _parent, _shortName, _longName);
}

SynthDeviceModelComponentBase::SynthDeviceModelComponentBase()
{
}
