/*
  ==============================================================================

    OPMSignalUnitChange.cpp
    Created: 5 Oct 2019 1:45:04pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "OPMSignalUnitChange.h"


void OPMSignalUnitChange::Deploy()
{

	AddBoolParameter(&Enabled, "Enabled", "Signal Enabled", true, -1, false, imbControlParameterMessageType::sysExMsg);

	AddBoolParameter(&Sync, "Sync", "Restart phase with new Note On", true, -1, false, imbControlParameterMessageType::sysExMsg);

	AddBoolParameter(&Chaos, "Chaos", "Chaos function", true, -1, false, imbControlParameterMessageType::sysExMsg);

	AddCCParameter(&Rate, "Rate", "Change Rate", 0, 0, 127, -1, false, imbControlParameterMessageType::sysExMsg);

	AddCCParameter(&Period, "Period", "Change Period", 0, 0, 127, -1, false, imbControlParameterMessageType::sysExMsg);

	AddCCParameter(&Change, "Change", "Change Period", 0, -64, 64, -1, false, imbControlParameterMessageType::sysExMsg);

	AddEnumParameter(&Function, "Function", "Modulation function",
		&parameterControllerPtr->ListOfModulationFunctions, 0, -1, false, imbControlParameterMessageType::sysExMsg);

	Enabled.SetHelp("If this Signal Generator modulation LFO is running.");

	Sync.SetHelp("When [True] Period will restart to beginning with every Note On. Otherwise, the LFO continues where it stoped with last Note Off.");

	Rate.SetHelp("Number of oscilator cycles per one Change applied. i.e. after what time targeted signal feature will be adjusted according to Change value");

	Period.SetHelp("How long the LFO function lasts, in number of Rate's completed.");

	Function.SetHelp("Curve/Value function used for the LFO. [One-shot] will perform change only for one Period. [Loop] will repeat the same value oscilation in each Period. [Continual] will keep appling change, regardless Period. [Mirror] will perform in inverse direction every second Period.");

	Chaos.SetHelp("Turns the LFO function into Chaos modifier, where Value controls Spread, Period controls how often it changes direction. Rate controls how many times will value change in one Period.");
}

OPMSignalUnitChange::OPMSignalUnitChange()
{
}
