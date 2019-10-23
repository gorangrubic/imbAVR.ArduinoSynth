/*
  ==============================================================================

    dataIntProperty.h
    Created: 23 Oct 2019 12:56:06pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectProperty.h"
class dataIntProperty :public dataObjectProperty {

public:

	bool Set(int _newValue);
	int Get();

	dataIntProperty(std::string _id, int _val, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "")
		:dataObjectProperty(_id, parameterValueType::Integer, _label, _description, _unit, _helpUrl) {
		SetIntValue(_val);
	}
};