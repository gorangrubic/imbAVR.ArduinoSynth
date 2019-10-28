/*
  ==============================================================================

    ParameterMap.h
    Created: 26 Oct 2019 4:07:53am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObjectPropertyBase.h"
#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
#include "../Source/Model/imbControlParameterEnumerations.h"
#include "../Source/Data/Structures/imbDictionary.h"

#include "../Source/Model/Communication/ParameterMapEntry.h"

class ParameterMap:public imbDictionary<int, ParameterMapEntry> {

public:

	ParameterMapEntry * getEntryByPathID(std::string pathID);

	std::string getPathIDByID(int id);

	imbDictionary<std::string, ParameterMapEntry*> entryByPathID;

	int Add(dataObjectPropertyBase * _data);

	imbControlParameterMessageType messageType;

	ParameterMap(imbControlParameterMessageType _messageType);
};



ParameterMapEntry * ParameterMap::getEntryByPathID(std::string pathID)
{
	return entryByPathID.Get(pathID, false);
}

std::string ParameterMap::getPathIDByID(int id)
{
	return Get(id, false).data->parameterIDPath;
}

int ParameterMap::Add(dataObjectPropertyBase * _data)
{
	int i = Count();
	auto pme =  ParameterMapEntry(i, _data);
	Set(i,pme);

	entryByPathID.Set(_data->parameterIDPath, &pme);

	return i;
}

ParameterMap::ParameterMap(imbControlParameterMessageType _messageType)
{
	messageType = _messageType;
}
