/*
  ==============================================================================

    dataEnumProperty.h
    Created: 23 Oct 2019 12:56:14pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectProperty.h"
#include "dataIntProperty.h"
class dataEnumProperty :public dataIntProperty {

public:


	dataEnumProperty(std::string _id, int _val, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "")
		:dataIntProperty(_id, _val, _label, _description, _unit, _helpUrl) {
		valueType = parameterValueType::Enumeration;
	}

	void SetSource(imbEnumerationList * enumList);
};