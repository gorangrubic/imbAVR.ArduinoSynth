/*
  ==============================================================================

    dataElementIndexMap.h
    Created: 25 Oct 2019 10:24:06pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Structures/imbDictionary.h"
class dataElementIndexMap:
	public imbDictionary<int, std::string>
{

public:

	dataElementIndexMap(std::string _defaultValue):imbDictionary(_defaultValue)
	{
		
	}
};