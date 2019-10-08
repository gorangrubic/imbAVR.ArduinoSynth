/*
  ==============================================================================

    SynthDeviceModelComponentBase.cpp
    Created: 1 Oct 2019 10:58:56am
    Author:  gorangrubic

  ==============================================================================
*/

#include "SynthDeviceModelComponentBase.h"
#include "../Source/Utility/imbSynthTools.h"


void SynthDeviceModelComponentBase::AddBoolParameter(imbControlParameter * output, String _parameterID, String _parameterLabel, bool initValue, int _ccID, bool _isAutomated, imbControlParameterMessageType _msgFormat)
{
	if (_ccID == -1) _ccID = Root->parameterController.GetProperID(_msgFormat);
	int _initIndexValue = 0;
	if (initValue) _initIndexValue = 1;

	AddParameter(output, _parameterID, _parameterLabel, 0, 1, _initIndexValue, "", _ccID, _isAutomated, imbControlParameterType::Boolean, _msgFormat);
}

void SynthDeviceModelComponentBase::AddEnumParameter(imbControlParameter * output, String _parameterID, String _parameterLabel, std::vector<String>* items, String initValue, int _ccID, bool _isAutomated, imbControlParameterMessageType _msgFormat)
{
	if (_ccID == -1) _ccID = Root->parameterController.GetProperID(_msgFormat);
	int _initIndexValue = 0;

	if (initValue == "") {
		_initIndexValue = 0;
	}
	else {
		_initIndexValue = imbSynthTools::GetIndex(items, initValue);
	}
	AddParameter(output, _parameterID, _parameterLabel, 0, items->size,_initIndexValue , "", _ccID, _isAutomated, imbControlParameterType::Enumeration, _msgFormat);
}

/// <summary>
/// Adds integer parameter, with default settings targeting typical CC MIDI parameter
/// </summary>
/// <param name="output">The output.</param>
/// <param name="_parameterID">The parameter identifier.</param>
/// <param name="_parameterLabel">The parameter label.</param>
/// <param name="initValue">The initialize value.</param>
/// <param name="minValue">The minimum value.</param>
/// <param name="maxValue">The maximum value.</param>
/// <param name="_ccID">The cc identifier.</param>
/// <param name="_isAutomated">if set to <c>true</c> [is automated].</param>
/// <param name="_msgFormat">The MSG format.</param>
void SynthDeviceModelComponentBase::AddCCParameter(imbControlParameter* output, String _parameterID, String _parameterLabel,
	int initValue, int minValue, int maxValue, int _ccID, bool _isAutomated, imbControlParameterMessageType _msgFormat)
{
	//if (_ccID == -1) _ccID = Root->parameterController.GetProperID(_msgFormat);
	AddParameter(output, _parameterID, _parameterLabel, minValue, maxValue, initValue, "", _ccID, _isAutomated, imbControlParameterType::Integer, _msgFormat);
}

void SynthDeviceModelComponentBase::AddParameter(imbControlParameter* output,String _parameterID, String _parameterLabel,
	float minValue, float maxValue, float initValue,
	String _parameterUnit,
	int _ccID, bool _isAutomatizable, imbControlParameterType _type, imbControlParameterMessageType _msgFormat)
{
	
	output->Setup(_parameterID, _parameterLabel, minValue, maxValue, initValue, _parameterUnit, _ccID,_isAutomatizable,_type, _msgFormat);

	Parameters.push_back(output);
}

void SynthDeviceModelComponentBase::BuildParameters()
{
	//processorParameterGroup = juce::AudioProcessorParameterGroup(ShortName, LongName, ".");
	  
	/*juce::AudioProcessorValueTreeState& vt = Root->SynthProcessor->parameters;
	
	for each (imbControlParameter * par in Parameters)
	{
		par->Connect(Parent);

	}

	for each (SynthDeviceModelComponentBase * child in ChildComponents)
	{
		child->BuildParameters();
	}*/
}

void SynthDeviceModelComponentBase::PreDeploy(SynthDeviceModel * _root, ModelComponentDescription * _parent, String _shortName, String _longName)
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

//SynthDeviceModelComponentBase::SynthDeviceModelComponentBase(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName)
//{
//	PreDeploy(_root, _parent, _shortName, _longName);
//}

SynthDeviceModelComponentBase::SynthDeviceModelComponentBase()
{
}
