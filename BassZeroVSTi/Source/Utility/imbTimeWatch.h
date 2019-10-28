/*
  ==============================================================================

    imbTimeWatch.h
    Created: 26 Oct 2019 4:03:34am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class imbTimeWatch {

public:

	uint32 lastCheck;

	void Reset() {
		lastCheck = juce::Time::getMillisecondCounter();
	}

	bool Check() {
		
		uint32 newCheck = juce::Time::getMillisecondCounter();
		bool output = false;
		if ((newCheck - lastCheck) > period) {
			output = true;
		}

		lastCheck = newCheck;

		return output;
	}

	uint32 period;

	imbTimeWatch(uint32 _period) {

		period = _period;
		lastCheck = juce::Time::getMillisecondCounter();
	}
};
