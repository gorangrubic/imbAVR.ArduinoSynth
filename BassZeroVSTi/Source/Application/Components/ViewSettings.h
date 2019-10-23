/*
  ==============================================================================

    ViewSettings.h
    Created: 23 Oct 2019 8:40:21am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"
#include "../Source/Data/Model/dataObjectProperty.h"

class ViewSettings :public dataObject {

public:

	dataBoolProperty ShowValues = dataBoolProperty("ShowValues", false, "");
	dataBoolProperty ShowCCMap = dataBoolProperty("ShowCCMap", false, "");
	dataBoolProperty ShowBufferState = dataBoolProperty("ShowBufferState", false, "");
	dataBoolProperty ShowScopeOutline = dataBoolProperty("ShowScopeOutline", true, "");

	ViewSettings(std::string _name, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "") :dataObject(_name, _label, _description, _unit, _helpUrl) {

	}
};