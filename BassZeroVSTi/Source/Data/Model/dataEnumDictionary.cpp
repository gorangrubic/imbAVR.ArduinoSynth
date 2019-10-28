/*
  ==============================================================================

    dataEnumDictionary.cpp
    Created: 23 Oct 2019 11:57:51am
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataEnumDictionary.h"

void dataEnumDictionary::RemoveAll()
{
	children.clear();
}

void dataEnumDictionary::RemoveEntry(std::string _propertyID)
  {
	size_t i = -1;
	for (size_t pi = 0; pi < children.size(); pi++)
	{
		if (children[pi]->parameterID == _propertyID) {
			i = pi;
			break;
		}
	}

	if (i != -1) {

		children.erase(children.begin() + i, children.begin() + i + 1);
	}
  }

  dataEnumEntryProperty * dataEnumDictionary::FindEntry(std::string _propertyID)
{
	
	return GetPointerByID<dataEnumEntryProperty>(_propertyID, entries).get();
	
}

dataEnumEntryProperty * dataEnumDictionary::FindEntry(int _propertyID)
{
	juce::String output = juce::String(_propertyID);
	return GetPointerByID<dataEnumEntryProperty>(output.toStdString(), entries).get();

}

StringArray dataEnumDictionary::GetEntryIDs()
{
	if (entryList.Count() != entries.size()) {
		RebuildEntryList();
	}

	//for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	auto a = { entryList.Items.begin(),entryList.Items.end() };

	StringArray output({ entryList.Items.begin(),entryList.Items.end() });

	return output;
}

imbEnumerationList * dataEnumDictionary::GetEntryList()
{
	if (entryList.Count() != entries.size() ) {
		RebuildEntryList();
	}
	return &entryList;
}

void dataEnumDictionary::RebuildEntryList()
{
	entryList.ClearAll();

	for each (auto var in entries)
	{
		entryList.Add(var->parameterLabel);
	}


}

void dataEnumDictionary::AddEntry(dataElementBase * item)
{
	int _enum = entries.size();

	if (!Contains(item->parameterID)) {
		auto e = new dataEnumEntryProperty(_enum, item->parameterLabel, item->parameterHelp, item->entryColorHex, item->parameterHelpUrl, item->parameterID);
		entries.Add(e);
		add(e);
		entryList.ClearAll();
	}
}

void dataEnumDictionary::AddEntry(int _enum, std::string _label, std::string _description, std::string _entryColorHex, std::string _helpUrl)
{
	auto e = new dataEnumEntryProperty(_enum, _label, _description, _entryColorHex, _helpUrl);
	if (!Contains(e->parameterID)) {
		entries.Add(e);
		add(e);
		entryList.ClearAll();
	}
}

void dataEnumDictionary::AddEntry(std::string _id, std::string _label, std::string _description, std::string _entryColorHex, std::string _helpUrl)
{
	int _enum = entries.size();
	if (!Contains(_id)) {
		auto e = new dataEnumEntryProperty(_enum, _label, _description, _entryColorHex, _helpUrl, _id);
		entries.Add(e);
		add(e);
		entryList.ClearAll();
	}
}
