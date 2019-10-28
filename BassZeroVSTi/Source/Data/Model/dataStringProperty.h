/*
  ==============================================================================

    dataStringProperty.h
    Created: 23 Oct 2019 12:55:56pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectProperty.h"
class dataStringProperty :public dataObjectProperty {

public:

	bool Set(std::string _newValue){
	return SetStrValue(_newValue);
};

	std::string Get() {
	return GetStringValue().toStdString();
}



	dataStringProperty(std::string _id, std::string _val, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "", parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none)
		:dataObjectProperty(_id, parameterValueType::String, _label, _description, _unit, _helpUrl,0,0,_parClass,_features) {
		SetStrValue(_val);
		elementClassRole = "dataStringProperty";
	}
};