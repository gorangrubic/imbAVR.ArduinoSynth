/*
  ==============================================================================

    SynthDeviceModelComponentBase.cpp
    Created: 1 Oct 2019 10:58:56am
    Author:  gorangrubic

  ==============================================================================
*/

#include "SynthDeviceModelComponentBase.h"
#include "../Source/Utility/imbSynthTools.h"


void SynthDeviceModelComponentBase::ConstructComponentParameters(ParameterController & parameterController, juce::AudioProcessorValueTreeState & parameters)
  {
	
	/*if (group == nullptr) {
		group = &AudioProcessorParameterGroup(ShortName, LongName, ".");
	}*/
	//AudioProcessorParameterGroup g = ;

	for each (auto var in Parameters)
	{
		
		var->attachState(parameters);
		/*NormalisableRange<float> valueRange = NormalisableRange<float>(var->MinValue, var->MaxValue, var->IntervalValue);

		juce::RangedAudioParameter * rngPar = parameters.createAndAddParameter(var->parameterIDPath,
			var->parameterID, var->parameterLabel, valueRange, var->Value, nullptr, nullptr, 
			var->isMetaValue, var->isAutomatizable, var->isDescreteValue, 
			var->category, var->typeParameter == imbControlParameterType::Boolean);

		parameters.addParameterListener(var->parameterIDPath, var.get());*/
		//rngPar->setValueNotifyingHost()

	//	imbSynthTools::SetParameter(nullptr, *var);
		//modelConstructionTools.SetParameter(nullptr, *var);
//		var->SetParameter(nullptr);
	}
  }

#define CONTROLLER  parameterController.



  std::shared_ptr<imbControlParameter> SynthDeviceModelComponentBase::GetParameter(juce::String name)
  {
	  
	  std::shared_ptr<imbControlParameter> output = nullptr;

	  for each (auto var in Parameters)
	  {
		  if (var->parameterID == name) {
			  output = var;
			  break;
		  }
	  }

	  return output;

  }

  void SynthDeviceModelComponentBase::AddBoolParameter(ParameterController & parameterController, imbControlParameter * output, String _parameterID, String _parameterLabel, bool initValue, int _ccID, bool _isAutomated, imbControlParameterMessageType _msgFormat, String _parameterParentPath)
{
	  if (_ccID == -1) _ccID = CONTROLLER GetProperID(_msgFormat);
	int _initIndexValue = 0;
	if (initValue) _initIndexValue = 1;

	AddParameter(parameterController, output, _parameterID, _parameterLabel, 0, 1, _initIndexValue, "", _ccID, _isAutomated, imbControlParameterType::Boolean, _msgFormat, _parameterParentPath);
}

void SynthDeviceModelComponentBase::AddEnumParameter(ParameterController & parameterController, imbControlParameter * output, String _parameterID, String _parameterLabel, imbEnumerationList* items, int initIndexValue, int _ccID, bool _isAutomated, imbControlParameterMessageType _msgFormat, String _parameterParentPath)
{
	if (_ccID == -1) _ccID = CONTROLLER GetProperID(_msgFormat);

	output->enumerationList = items;
	
	AddParameter(parameterController, output, _parameterID, _parameterLabel, 0, (float) items->Count(),initIndexValue , "", _ccID, _isAutomated, imbControlParameterType::Enumeration, _msgFormat, _parameterParentPath);
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
void SynthDeviceModelComponentBase::AddCCParameter(ParameterController & parameterController, imbControlParameter* output, String _parameterID, String _parameterLabel,
	int initValue, int minValue, int maxValue, int _ccID, bool _isAutomated, imbControlParameterMessageType _msgFormat, String _parameterParentPath)
{
	if (_ccID == -1) _ccID = CONTROLLER GetProperID(_msgFormat);
	AddParameter(parameterController, output, _parameterID, _parameterLabel, minValue, maxValue, initValue, "", _ccID, _isAutomated, imbControlParameterType::Integer, _msgFormat, _parameterParentPath);
}

void SynthDeviceModelComponentBase::AddParameter(ParameterController & parameterController, imbControlParameter* output,String _parameterID, String _parameterLabel,
	float minValue, float maxValue, float initValue,
	String _parameterUnit,
	int _ccID, bool _isAutomatizable, imbControlParameterType _type, imbControlParameterMessageType _msgFormat, String _parameterParentPath)
{

	if (_parameterParentPath.isEmpty()) {
		std::string parentPath = "";

		if (GroupName.isNotEmpty()) {
			parentPath += GroupName.toStdString();
		}

		if (ShortName.isNotEmpty()) {
			if (!parentPath.empty()) parentPath += "_";
			parentPath += ShortName.toStdString();
		}

		output->parameterParentPath = parentPath;
	}
	else {
		output->parameterParentPath = _parameterParentPath.toStdString();
	}
	
	output->Setup(_parameterID, _parameterLabel, minValue, maxValue, initValue, _parameterUnit, _ccID,_isAutomatizable,_type, _msgFormat);

	//std::shared_ptr<imbControlParameter> shared = std::shared_ptr<imbControlParameter>(output);
	Parameters.Add(output);
	//Parameters.push_back(shared);
}

//void SynthDeviceModelComponentBase::BuildParameters()
//{
//	//processorParameterGroup = juce::AudioProcessorParameterGroup(ShortName, LongName, ".");
//	  
//	/*juce::AudioProcessorValueTreeState& vt = Root->SynthProcessor->parameters;
//	
//	for each (imbControlParameter * par in Parameters)
//	{
//		par->Connect(Parent);
//
//	}
//
//	for each (SynthDeviceModelComponentBase * child in ChildComponents)
//	{
//		child->BuildParameters();
//	}*/
//}
//
//void SynthDeviceModelComponentBase::SetParent(SynthDeviceModelComponentBase * _model, ModelComponentWithChildren * _parent, ParameterController * _parameterControllerPtr)
//{
//
//	model = _model;
//	parent = _parent;
//	parameterControllerPtr = _parameterControllerPtr;
//}


//void SynthDeviceModelComponentBase::PreDeploy(String _shortName, String _longName)
//{
//	if (NamePrefix == "") {
//		ShortName = _shortName;
//	}
//	else {
//		ShortName = NamePrefix + "_" + _shortName;
//	}
//
//	if (LongName == "") {
//		LongName = NamePrefix + " " + _shortName;
//	} 
//	else {
//		LongName = _longName;
//	}
//	
//
//	//Root = _root;
//	//Parent = _parent;
//
//}

//SynthDeviceModelComponentBase::SynthDeviceModelComponentBase(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName)
//{
//	PreDeploy(_root, _parent, _shortName, _longName);
//}

//SynthDeviceModelComponentBase::SynthDeviceModelComponentBase()
//{
//}
