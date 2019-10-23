/*
  ==============================================================================

    dataObjectProperty.h
    Created: 22 Oct 2019 9:05:51pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "dataObjectPropertyBase.h"

class dataObjectProperty:public dataObjectPropertyBase {

protected:

	
public:

	void updateAll();

	bool SetValue(float _newValue);

	dataObjectProperty(std::string _id, parameterValueType _valType, std::string _label="", std::string _description="", std::string _unit = "", std::string _helpUrl="")
		:dataObjectPropertyBase(_valType,_id,_label,_description,_unit,_helpUrl)  {
		//parameterID = _id;
		//valueType = _valType;
	
		
		//SetHelp(_description, _helpUrl, _unit);
	}
};

