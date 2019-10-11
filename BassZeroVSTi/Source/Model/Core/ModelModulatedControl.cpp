/*
  ==============================================================================

    ModelModulatedControl.cpp
    Created: 5 Oct 2019 2:49:59am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModelModulatedControl.h"

void ModelModulatedControl::Deploy()
{
	AddCCParameter(&ModAmt, "ModAmt", "Modulation direction", 0,-64,64);
	AddCCParameter(&Val, "Val", "Value (dry)", 0, 0, 127);
	
	AddEnumParameter(&ModSrc, "ModSrc", "Modulation source", &parameterControllerPtr->ListOfSources);
}

ModelModulatedControl::ModelModulatedControl()
{
	NamePrefix = "";
}
