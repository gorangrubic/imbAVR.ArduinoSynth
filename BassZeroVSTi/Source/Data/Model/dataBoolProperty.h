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

	dataBoolProperty(std::string _id, bool _val, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none)
		:dataObjectProperty(_id, parameterValueType::Boolean, _label, _description, _unit, _helpUrl, 0,0,_parClass,_features) {
		SetBoolValue(_val);

		elementClassRole = "dataBoolProperty";
	
	}
};

bool dataBoolProperty::Set(bool _newValue)
{
	return SetBoolValue(_newValue);
}

bool dataBoolProperty::Get()
{
	return GetBoolValue();
}

void dataBoolProperty::Toggle()
{
	Set(!Get());
}