/*
  ==============================================================================

    RandomTip.h
    Created: 12 Oct 2019 3:40:06am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"

class RandomTip:public dataObject {

public:

	dataStringProperty Title = dataStringProperty("Title", "Tip title", "Title", "");
	dataStringProperty Message = dataStringProperty("Message", "Message", "Message", "");
	dataStringProperty Url = dataStringProperty("Url", "Url", "Url", "");
	
	RandomTip()
	{
		Add(&Title);
		Add(&Message);
		Add(&Url);
	}

	RandomTip(std::string _title, std::string _message, std::string _url)
	{
		Title.SetStrValue(_title);
		Message.SetStrValue(_message);
		Url.SetStrValue(_url);
		
		Add(&Title);
		Add(&Message);
		Add(&Url);
	}
};