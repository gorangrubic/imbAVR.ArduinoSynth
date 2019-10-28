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

	void updateAll() {
	  updateGUI();
	  updateTooltip();
  }


	bool SetValue(float _newValue) 
  {
	  return setValue(_newValue);
  }



	dataObjectProperty(std::string _id, parameterValueType _valType, std::string _label="", std::string _description="", std::string _unit = "", std::string _helpUrl="", float minValue = 0, float maxValue = 0, parameterClass _parClass= parameterClass::unspecified, dataElementFeatures::_features _features=dataElementFeatures::none, float _value = 0)
		:dataObjectPropertyBase(_valType,_id,_label,_description,_unit,_helpUrl,minValue,maxValue,_parClass)  {
		SetValue(_value);
		features |= _features;

		//parClass = parameterClass::configuration;
		//parameterID = _id;
		//valueType = _valType;
	
		
		//SetHelp(_description, _helpUrl, _unit);
	}
};

