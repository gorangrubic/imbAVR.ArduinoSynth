/*
  ==============================================================================

    dataStringProperty.cpp
    Created: 23 Oct 2019 12:55:56pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataStringProperty.h"
bool dataStringProperty::Set(std::string _newValue)
{
	return SetStrValue(_newValue);
}

std::string dataStringProperty::Get()
{
	return GetStringValue().toStdString();
}
