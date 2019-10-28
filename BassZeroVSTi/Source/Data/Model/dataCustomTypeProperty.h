/*
  ==============================================================================

    dataCustomTypeProperty.h
    Created: 27 Oct 2019 7:00:56pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include <stdio.h>
#include <string.h>

#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectProperty.h"

#include "../Source/Utility/Serialization.h"

template<typename T>
class dataCustomTypeProperty :public dataObjectProperty {

public:

	

	T customValue;


	bool Set(T _newValue) {

		//customData<T> c;
		//c.instance = _newValue;
		//std::string vl = "";
		//vl = vl.append(c.bytes, c.size);

		customValue = _newValue;
		return SetStrValue(Serialization::toString<T>(T _newValue,true));

		/*for (size_t i = 0; i < c.size; i++)
		{
			
			char ch = static_cast<char>(c.bytes[i]);
		}
*/
	};

	T Get() {

		customData<T> c;
		c.instance = _newValue;
		auto vl = GetStrValue();

		vl = vl.append(c.bytes, c.size);
		
		customValue = Serialization::fromString<T>(GetStrValue(), true);

		return customValue;
	};

	dataCustomTypeProperty(std::string _id, T _val, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "", std::string _preferedEditor="", parameterClass _parClass = parameterClass::unspecified, dataElementFeatures::_features _features = dataElementFeatures::none)
		:dataObjectProperty(_id, parameterValueType::customClassProperty, _label, _description, _unit, _helpUrl, 0, 0, _parClass, _features) {
		editorOfPreferenceDefault = _preferedEditor;

		Set(_val);
		if (_parClass == parameterClass::unspecified) {
			parClass = parameterClass::configuration;
		}
		elementClassRole = "dataCustomTypeProperty";

	}
};