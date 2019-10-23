/*
  ==============================================================================

    MacroControlLink.cpp
    Created: 4 Oct 2019 9:27:38pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "MacroControlLink.h"


void MacroControlLink::Deploy(ParameterController & parameterController)
{

	AddCCParameter(parameterController, &ModAmt, "ModAmt", "Modulation amount", 0, -64, 64, -1, false, imbControlParameterMessageType::sysExMsg);
	
	AddEnumParameter(parameterController, &Signal, "Signal", "Signal/oscilator", &parameterController.ListOfSignalUnits,1, -1, false, imbControlParameterMessageType::sysExMsg);

	AddEnumParameter(parameterController, &ModTar, "ModTar", "Targeted Change", &parameterController.ListOfModulationModes, 0, -1, false, imbControlParameterMessageType::sysExMsg);

	AddEnumParameter(parameterController, &ModPar, "ModPar", "Targeted Parameter", &parameterController.ListOfModulationParameters, 0, -1, false, imbControlParameterMessageType::sysExMsg);
}

MacroControlLink::MacroControlLink()
{
}
