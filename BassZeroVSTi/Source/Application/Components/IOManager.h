/*
  ==============================================================================

    IOManager.h
    Created: 23 Oct 2019 8:39:05am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "IOCommunicationStats.h"

class IOManager {

public:
	
	IOCommunicationStats communicationStats = IOCommunicationStats("IOCommunicationStats", "Communication stats");
	IOBufferStats bufferStats = IOBufferStats("IOBufferStats", "Buffer stats");

	IOManager();
};