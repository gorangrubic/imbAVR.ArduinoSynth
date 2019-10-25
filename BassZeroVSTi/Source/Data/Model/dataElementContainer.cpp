/*
  ==============================================================================

    dataElementContainer.cpp
    Created: 23 Oct 2019 11:57:38am
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataElementContainer.h"

void dataElementContainer::deploy(std::string prefix)
{
	parameterIDPath = GetPrefix(prefix);
	for each (auto var in properties)
	{
		var->parameterIDPath = GetParameterPath(var, parameterIDPath);
	}

}

/* Deploys automation and/or DAW visible parameters*/
void dataElementContainer::deployAutomation(juce::AudioProcessorValueTreeState & parameters)
{
	for each (std::shared_ptr<dataObjectPropertyBase> var in properties)
	{
		std::string p_path = var->parameterIDPath;
		bool isAutomatizable = var->features.HasFlag(dataElementFeatures::_features::isAutomatizable);
		bool doDeclareInValueTree = var->features.HasFlag(dataElementFeatures::_features::doDeclareInValueTree);
		bool isDescreteValue = !((var->valueType == parameterValueType::Float) || (var->valueType == parameterValueType::Ratio));
		
		if (isAutomatizable || doDeclareInValueTree)
		{
			NormalisableRange<float> valueRange = NormalisableRange<float>(var->MinValue, var->MaxValue, var->IntervalValue);

			auto pParameter = 
				std::shared_ptr<juce::RangedAudioParameter>(
					parameters.createAndAddParameter(parameterIDPath,
				parameterID, parameterLabel, valueRange, var->Value,
						nullptr, nullptr, false, 
						isAutomatizable, isDescreteValue,
				AudioProcessorParameter::Category::genericParameter,
				(var->valueType == parameterValueType::Boolean)
					)
					);

			parameters.addParameterListener(p_path, var.get());
		}
		
		//var->parameterIDPath = GetParameterPath(var, parameterIDPath);
	}

	for each (auto var in children)
	{
		if (var->features.HasFlag(dataElementFeatures::isElementContainer))
		{
			dataElementContainer * childContainer = static_cast<dataElementContainer*>(var.get());
			childContainer->deployAutomation(parameters);
		}
	}

}

void dataElementContainer::add(dataElementBase * item)
{
	children.Add(item);
}

std::string dataElementContainer::GetPrefix(std::string parentPathPrefix)
{
	if (!parameterIDPath.empty()) return parameterIDPath;

	std::string prefix = name;
	if (!parentPathPrefix.empty()) {
		if (!name.empty()) {
			prefix = parentPathPrefix + "." + name;
		}
		else {
			prefix = parentPathPrefix;
		}
	}
	return prefix;
}

std::string dataElementContainer::GetParameterPath(std::shared_ptr<dataObjectPropertyBase> var, std::string prefix)
{
	std::string p = "";
	if (prefix.empty()) {
		p = var->parameterID;
	}
	else {
		p = prefix + "." + var->parameterID;
	}
	return p;
}

void dataElementContainer::AddProperty(dataObjectPropertyBase * _property)
{
	properties.Add(_property);
	add(dynamic_cast<dataElementBase*>(_property));
}

dataObjectPropertyBase * dataElementContainer::FindProperty(std::string _propertyID)
{
	return GetPointerByID<dataObjectPropertyBase>(_propertyID, properties).get();
}

void dataElementContainer::Deploy(std::string prefix)
{
	deploy(prefix);
}
