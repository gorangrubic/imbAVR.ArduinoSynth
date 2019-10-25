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
