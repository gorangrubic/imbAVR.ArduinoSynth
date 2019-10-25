/*
  ==============================================================================

    dataObjectCollection.cpp
    Created: 25 Oct 2019 11:55:36pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataObjectCollection.h"

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
