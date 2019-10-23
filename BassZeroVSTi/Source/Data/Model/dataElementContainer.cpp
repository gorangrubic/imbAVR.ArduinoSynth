/*
  ==============================================================================

    dataElementContainer.cpp
    Created: 23 Oct 2019 11:57:38am
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataElementContainer.h"

std::string dataElementContainer::GetPrefix(std::string parentPathPrefix)
{
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
}

dataObjectPropertyBase * dataElementContainer::FindProperty(std::string _propertyID)
{
	return GetPointerByID<dataObjectPropertyBase>(_propertyID, properties).get();
}
