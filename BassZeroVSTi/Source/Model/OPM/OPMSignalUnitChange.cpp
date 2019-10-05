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

	AddBoolParameter(&Chaos, "Chaos", "Overrides selected function to Chaos", true, -1, false, imbControlParameterMessageType::sysExMsg);

	AddCCParameter(&Rate, "Rate", "Change Rate", 0, 0, 127, -1, false, imbControlParameterMessageType::sysExMsg);

	AddCCParameter(&Period, "Period", "Change Period", 0, 0, 127, -1, false, imbControlParameterMessageType::sysExMsg);

	AddCCParameter(&Change, "Change", "Change Period", 0, -64, 64, -1, false, imbControlParameterMessageType::sysExMsg);

	AddEnumParameter(&Function, "Function", "Modulation function",
		&opmParent->ListOfModulationFunctions, "Loop", -1, false, imbControlParameterMessageType::sysExMsg);


}

OPMSignalUnitChange::OPMSignalUnitChange()
{
}
