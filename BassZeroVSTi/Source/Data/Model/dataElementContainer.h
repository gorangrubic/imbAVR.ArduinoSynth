/*
  ==============================================================================

    dataElementContainer.h
    Created: 23 Oct 2019 11:57:38am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/SharedPointerVector.h"

#include "../Source/Data/Model/dataElementBase.h"

#include "dataObjectProperty.h"
#include "dataIntProperty.h"
#include "dataEnumProperty.h"
#include "dataStringProperty.h"
#include "dataBoolProperty.h"
#include "dataEnumEntryProperty.h"

class dataElementContainer : public dataElementBase {

protected:



public:

	template<typename T>
	std::shared_ptr<T> GetPointerByID(juce::String _id, SharedPointerVector<T> & collection)
	{
		std::shared_ptr<T> output = nullptr;

		//juce::String needleString = juce::String(name);

		for each (auto var in collection)
		{
			if (var->parameterID == _id) {
				output = var;
				break;
			}
		}

		return output;
	}

	SharedPointerVector<dataObjectPropertyBase> properties;
	
	std::string name;

	std::string GetPrefix(std::string parentPathPrefix = "");
	std::string GetParameterPath(std::shared_ptr<dataObjectPropertyBase> var, std::string prefix);

	void AddProperty(dataObjectPropertyBase * _property);

	dataObjectPropertyBase * FindProperty(std::string _propertyID);
	

	dataElementContainer(std::string _name = "", std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = ""):dataElementBase(_name,_label,_description,_unit,_helpUrl) {
	
	}

};