/*
  ==============================================================================

    dataBoolProperty.h
    Created: 23 Oct 2019 12:57:54pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectProperty.h"

class dataBoolProperty :public dataObjectProperty {

public:

	bool Set(bool _newValue);
	bool Get();

	void Toggle();

	dataBoolProperty(std::string _id, bool _val, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "")
		:dataObjectProperty(_id, parameterValueType::Boolean, _label, _description, _unit, _helpUrl) {
		SetBoolValue(_val);
	}
};