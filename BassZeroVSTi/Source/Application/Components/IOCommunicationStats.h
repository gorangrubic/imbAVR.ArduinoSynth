/*
  ==============================================================================

    IOCommunicationStats.h
    Created: 23 Oct 2019 8:39:47am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataObjectProperty.h"
#include "IOBufferStats.h"
class IOCommunicationStats :public dataObject {

public:

	dataIntProperty totalSentToDevice = dataIntProperty("totalSentToDevice", 0);
	dataIntProperty totalRetryCount = dataIntProperty("totalRetryCount", 0);
	dataIntProperty totalFailed = dataIntProperty("totalFailed", 0);
	
	IOBufferStats totalByType = IOBufferStats("TotalByType", "Total by type", "Total messages count by message type");


	IOCommunicationStats(std::string _name, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "") :dataObject(_name, _label, _description, _unit, _helpUrl) {
		Add(&totalSentToDevice);
		Add(&totalRetryCount);
		Add(&totalFailed);
		Add(&totalByType);
	}

};