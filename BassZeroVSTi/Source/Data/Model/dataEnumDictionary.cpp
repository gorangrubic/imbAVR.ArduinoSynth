/*
  ==============================================================================

    dataEnumDictionary.cpp
    Created: 23 Oct 2019 11:57:51am
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataEnumDictionary.h"

dataEnumEntryProperty * dataEnumDictionary::FindEntry(std::string _propertyID)
{
	
	return GetPointerByID<dataEnumEntryProperty>(_propertyID, entries).get();
	
}

void dataEnumDictionary::AddEntry(int _enum, std::string _label, std::string _description, std::string _entryColorHex, std::string _helpUrl)
{
	entries.Add(new dataEnumEntryProperty(_enum, _label, _description, _entryColorHex, _helpUrl));
}
