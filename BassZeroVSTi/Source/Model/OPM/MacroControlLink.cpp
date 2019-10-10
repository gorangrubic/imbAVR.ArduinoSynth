/*
  ==============================================================================

    MacroControlLink.cpp
    Created: 4 Oct 2019 9:27:38pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "MacroControlLink.h"


void MacroControlLink::Deploy()
{

	AddCCParameter(&ModAmt, "ModAmt", "Modulation amount", 0, -64, 64, -1, false, imbControlParameterMessageType::sysExMsg);

	//AddEnumParameter(&Signal, "Signal", "Signal/oscilator", &opmParent->ListOfSignalUnits, "WFA", -1, false, imbControlParameterMessageType::sysExMsg);

	//AddEnumParameter(&ModTar, "ModTar", "Targeted Change", &opmParent->ListOfModulationModes, "Pitch", -1, false, imbControlParameterMessageType::sysExMsg);

	//AddEnumParameter(&ModPar, "ModPar", "Targeted Parameter", &opmParent->ListOfModulationModes, "Rate", -1, false, imbControlParameterMessageType::sysExMsg);


}

MacroControlLink::MacroControlLink()
{
}
