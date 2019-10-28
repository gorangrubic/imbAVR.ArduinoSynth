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

	dataBoolProperty ShowValues = dataBoolProperty("ShowValues", false, "Show values", "Show value of the control parameter over its GUI control");
	dataBoolProperty ShowCCMap = dataBoolProperty("ShowCCMap", false, "Show CC map", "Show CC mapping information its GUI control");
//	dataBoolProperty ShowState = dataBoolProperty("ShowCCMap", false, "Show CC map", "Show CC mapping information its GUI control");
	
	dataBoolProperty ShowBufferState = dataBoolProperty("ShowBufferState", false, "");
	dataBoolProperty ShowScopeOutline = dataBoolProperty("ShowScopeOutline", true, "");

	dataBoolProperty ShowTooltip = dataBoolProperty("ShowTooltip", true, "");
	dataBoolProperty ShowRandomTipAtStart = dataBoolProperty("ShowRandomTipAtStart", true, "");

	dataBoolProperty ShowModulationPreview = dataBoolProperty("ShowModulationPreview", true, "Modulation preview", "");

	ViewSettings(std::string _name, std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "") :dataObject(_name, _label, _description, _unit, _helpUrl) {

		Add(&ShowValues);
		Add(&ShowCCMap);
		
		Add(&ShowBufferState);
		Add(&ShowScopeOutline);

		Add(&ShowTooltip);
		Add(&ShowRandomTipAtStart);
		
		Add(&ShowModulationPreview);
		
	}
};