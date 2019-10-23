/*
  ==============================================================================

    dataIntProperty.cpp
    Created: 23 Oct 2019 12:56:06pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataIntProperty.h"
bool dataIntProperty::Set(int _newValue)
{
	return SetIntValue(_newValue);
}

int dataIntProperty::Get()
{
	return GetIntValue();
}