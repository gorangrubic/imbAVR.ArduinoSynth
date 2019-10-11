/*
  ==============================================================================

    ModelModulatedControl.cpp
    Created: 5 Oct 2019 2:49:59am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ModelModulatedControl.h"

void ModelModulatedControl::Deploy(ParameterController & parameterController)
{
	AddCCParameter(parameterController,&ModAmt, "ModAmt", "Modulation direction", 0,-64,64);
	AddCCParameter(parameterController,&Val, "Val", "Value (dry)", 0, 0, 127);
	
	AddEnumParameter(parameterController,&ModSrc, "ModSrc", "Modulation source", &parameterController.ListOfSources);
}

ModelModulatedControl::ModelModulatedControl()
{
	NamePrefix = "";
}
