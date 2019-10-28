/*
  ==============================================================================

    IOManager.h
    Created: 23 Oct 2019 8:39:05am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObjectPropertyBase.h"
#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
#include "../Source/Control/imbControlParameterEnumerations.h"
#include "../Source/Data/Structures/imbDictionary.h"

#include "../Source/Model/Communication/ParameterMapEntry.h"
#include "../Source/Model/Communication/ParameterMap.h"
#include "IOCommunicationStats.h"


#include "../Source/Application/imbSynthStateData.h"

class IOManager {

public:
	
	IOCommunicationStats communicationStats = IOCommunicationStats("IOCommunicationStats", "Communication stats");
	IOBufferStats bufferStats = IOBufferStats("IOBufferStats", "Buffer stats");

	

	void ExecuteNote();

	void ExecuteCCLive();

	void ExecuteCCSustained();

	void ExecuteOPM();

	IOManager();
};