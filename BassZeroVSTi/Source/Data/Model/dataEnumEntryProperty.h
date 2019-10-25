/*
  ==============================================================================

    dataEnumEntryProperty.h
    Created: 23 Oct 2019 12:58:17pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectProperty.h"
#include "dataIntProperty.h"

class dataEnumEntryProperty :public dataIntProperty {

public:

	

	// dataIntProperty(std::string _id, int _val, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "")
	dataEnumEntryProperty(int _enum, std::string _label = "", std::string _description = "", std::string _entryColorHex = "#FFFFFFFF", std::string _helpUrl = "", std::string _id="")
		:dataIntProperty(juce::String(_enum).toStdString(), _enum, _label, _description, "", _helpUrl) {
		entryColorHex = _entryColorHex;
		elementClassRole = "dataEnumEntryProperty";
		if (!_id.empty()) parameterID = _id;

		//SetIntValue(_val);
	}

};