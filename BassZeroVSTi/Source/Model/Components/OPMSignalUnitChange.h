/*
  ==============================================================================

    OPMSignalUnitChange.h
    Created: 5 Oct 2019 1:45:04pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObject.h"

#define NameString_Phase "Phase"
#define NameString_Pitch "Pitch"
#define NameString_PWM "PWM"
#define LabelString_Phase "Phase Change"
#define LabelString_Pitch "Pitch Change"
#define LabelString_PWM "Pulse-Width Change"

class OPMSignalUnitChange :
	public dataObject

	
{
public:



	dataBoolProperty Enabled = dataBoolProperty("Enabled", true, "Enabled", "Sets if modulation source is enabled/active.", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);
	dataBoolProperty Sync = dataBoolProperty("Enabled", true, "Enabled", "When [True] Period will restart to beginning with every Note On. Otherwise, the LFO continues where it stoped with last Note Off.", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);
	dataBoolProperty Chaos = dataBoolProperty("Enabled", true, "Enabled", "Turns the LFO function into Chaos modifier, where Value controls Spread, Period controls how often it changes direction. Rate controls how many times will value change in one Period.", "", "", parameterClass::opm, dataElementFeatures::_features::doSetValueByContextMenu);

	dataIntProperty Rate = dataIntProperty("Rate", 1, "Rate", "Number of oscilator cycles per one Change applied. i.e. after what time targeted signal feature will be adjusted according to Change value");
	dataIntProperty Period = dataIntProperty("Period", 1, "Period","How long the LFO function lasts, in number of Rate's completed.");
	dataIntProperty Change = dataIntProperty("Change", 1, "Change");

	dataEnumProperty Function = dataEnumProperty("Function", 0, "Function","Curve/Value function used for the LFO. [One-shot] will perform change only for one Period. [Loop] will repeat the same value oscilation in each Period. [Continual] will keep appling change, regardless Period. [Mirror] will perform in inverse direction every second Period.");
	
	OPMSignalUnitChange(std::string _name = "", std::string _label = "", std::string _description = "", std::string _helpUrl = "")
		: dataObject(_name, _label, _description, "", _helpUrl) {

		elementClassRole = "OPMSignalUnitChange";
		
		Add(&Enabled);
		Add(&Sync);
		Add(&Chaos);
		Add(&Rate);
		Add(&Period);
		Add(&Change);
		Add(&Function);
	}

//	OPMSignalUnitChange(SynthDeviceModel * _root, SynthDeviceModelComponentBase * _parent, String _shortName, String _longName) :SynthDeviceModelComponentBase(_root, _parent, _shortName, _longName) { }
};