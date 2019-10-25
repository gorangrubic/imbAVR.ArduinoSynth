/*
  ==============================================================================

    dataEnumDictionary.h
    Created: 23 Oct 2019 11:57:51am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/SharedPointerVector.h"
#include "dataObjectPropertyBase.h"
#include "../Source/Data/Structures/imbValueSet.h"
#include "../Source/Data/Model/dataElementContainer.h"
#include "dataObjectProperty.h"



class dataEnumDictionary:public dataElementContainer {

public:

	SharedPointerVector<dataEnumEntryProperty> entries;

	dataEnumEntryProperty * FindEntry(std::string _propertyID);

	dataEnumEntryProperty * FindEntry(int _propertyID);

	void AddEntry(int _enum, std::string _label = "", std::string _description = "", std::string _entryColorHex = "#FFFFFFFF", std::string _helpUrl = "");

	void AddEntry(std::string _id, std::string _label = "", std::string _description = "", std::string _entryColorHex = "#FFFFFFFF", std::string _helpUrl = "");

	dataEnumDictionary(std::string _name, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = ""):dataElementContainer(_name,_label,_description,_unit,_helpUrl) {

		elementClassRole = "dataEnumDictionary";
	}

};