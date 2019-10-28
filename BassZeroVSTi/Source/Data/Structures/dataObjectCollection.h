/*
  ==============================================================================

    dataObjectCollection.h
    Created: 25 Oct 2019 11:55:36pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/imbDictionary.h"
#include "../Source/Data/Model/dataObject.h"

class dataObjectCollection :public imbDictionary<std::string, std::shared_ptr<dataObject>> {

public:

	void Add(dataObject * object);

	dataObject * GetObject(std::string path);

	dataElementBase * FindElement(std::string path);

	void Remove(std::string name);

	void ClearAll();

	dataObjectCollection():imbDictionary(nullptr) {

	};
};

void dataObjectCollection::Add(dataObject * object)
{
	Set(object->parameterID, std::shared_ptr<dataObject>(object));
}

dataObject * dataObjectCollection::GetObject(std::string path)
{
	std::string n = imbGeneralTools::GetPathVersion(path, 1, false);
	auto o = Get(n, false);
	if (o == nullptr) return nullptr;
	return o.get();
}

dataElementBase * dataObjectCollection::FindElement(std::string path)
{
	dataObject * o = GetObject(path);
	if (o == nullptr) return nullptr;
	return o->GetMemberByPath<dataElementBase>(path);
}

void dataObjectCollection::Remove(std::string name)
{
	mapOfEntries.erase(name);
}

void dataObjectCollection::ClearAll()
{
	mapOfEntries.clear();
}
