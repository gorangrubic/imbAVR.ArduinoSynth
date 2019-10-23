/*
  ==============================================================================

    dataBoolProperty.cpp
    Created: 23 Oct 2019 12:57:54pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataBoolProperty.h"
bool dataBoolProperty::Set(bool _newValue)
{
	return SetBoolValue(_newValue);
}

bool dataBoolProperty::Get()
{
	return GetBoolValue();
}

void dataBoolProperty::Toggle()
{
	Set(!Get());
}
