/*
  ==============================================================================

    dataElementContainer.cpp
    Created: 23 Oct 2019 11:57:38am
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataElementContainer.h"
#include <vector>

void dataElementContainer::deploy(std::string prefix)
{
	parameterIDPath = GetPrefix(prefix);

	for each (std::shared_ptr<dataElementBase> var in children)
	{
		var->parameterIDPath = GetParameterPath(var, parameterIDPath);

		if (var->features.HasFlag(dataElementFeatures::isElementContainer)) {


			dataElementContainer * c = static_cast<dataElementContainer *>(var.get());
			c->deploy(parameterIDPath);
		}
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


void dataElementContainer::RemoveAll()
{
	children.clear();
	properties.clear();
}

void dataElementContainer::RemoveEntry(std::string _propertyID)
{
	RemovePointerByID(_propertyID, children);
	RemovePointerByID(_propertyID, properties);
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

int dataElementContainer::GetCheckSum(bool forValue, bool forStructure)
{
	int output;



	for each (std::shared_ptr<dataElementBase> var in children)
	{
//		var->parameterIDPath = GetParameterPath(var, parameterIDPath);

		if (var->features.HasFlag(dataElementFeatures::isElementContainer)) {
			dataElementContainer * c = static_cast<dataElementContainer *>(var.get());
			output += c->GetCheckSum(forValue, forStructure);
		}
		else if (var->features.HasFlag(dataElementFeatures::isProperty)) {
			dataObjectPropertyBase * p = static_cast<dataObjectPropertyBase *>(var.get());

			output += p->GetCheckSum(forValue, forStructure);


		}
	}


	return output;
}

void dataElementContainer::Deploy(std::string prefix)
{
	deploy(prefix);
}

void dataElementContainer::GetAllProperties(std::vector<dataObjectPropertyBase*>& allProperties, parameterClass parClass)
{
	for each (std::shared_ptr<dataElementBase> var in children)
	{
		if (var->features.HasFlag(dataElementFeatures::_features::isProperty)) {
			auto p= static_cast<dataObjectPropertyBase*>(var.get());

			if (parClass != parameterClass::unspecified) {
				if (p->parClass == parClass) {
					allProperties.push_back(p);
				}
			}
			else {
				allProperties.push_back(p);
			}

		}
		else if (var->features.HasFlag(dataElementFeatures::_features::isElementContainer)) {
			auto c = static_cast<dataElementContainer*>(var.get());
			c->GetAllProperties(allProperties, parClass);
		}
	
	}
}



