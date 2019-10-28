/*
  ==============================================================================

    IOBufferStats.h
    Created: 23 Oct 2019 8:39:22am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataObjectProperty.h"

class IOBufferStats :public dataObject {

	
public:

	dataIntProperty noteMessages = dataIntProperty("noteMessages", 0, "Note messages");
	dataIntProperty ccLiveMessages = dataIntProperty("ccLiveMessages", 0, "CC live messages");
	dataIntProperty ccSustainedMessages = dataIntProperty("ccSustainedMessages", 0, "CC sustained messages");
	dataIntProperty opmMessages = dataIntProperty("opmMessages", 0, "OPM messages");
	dataIntProperty forwardedMessages = dataIntProperty("forwardedMessages", 0, "Forwarded messages");

	IOBufferStats(std::string _name, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "") :dataObject(_name, _label, _description, _unit, _helpUrl) {
		Add(&noteMessages);
		Add(&ccLiveMessages);
		Add(&ccSustainedMessages);
		Add(&opmMessages);
		Add(&forwardedMessages);
	}
};