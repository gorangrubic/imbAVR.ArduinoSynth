/*
  ==============================================================================

    ParameterMapEntry.h
    Created: 26 Oct 2019 4:07:10am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObjectPropertyBase.h"
//#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
//#include "../Source/Control/imbControlParameterEnumerations.h"

class ParameterMapEntry {

public:

	int id;
	
	std::shared_ptr<dataObjectPropertyBase> data;
	
	ParameterMapEntry(int _id, dataObjectPropertyBase * _data);
	

};

ParameterMapEntry::ParameterMapEntry(int _id, dataObjectPropertyBase * _data)
{
	data = std::shared_ptr<dataObjectPropertyBase>(_data);
	id = _id;
}
