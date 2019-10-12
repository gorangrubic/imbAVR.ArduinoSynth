/*
  ==============================================================================

    RandomTip.h
    Created: 12 Oct 2019 3:40:06am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class RandomTip {

public:
	std::string Title;
	std::string Message;
	
	RandomTip();

	RandomTip(std::string _title, std::string _message): Title {_title}, Message {_message}
	{

	}
};