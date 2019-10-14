/*
  ==============================================================================

    ControlStateDisplayModel.cpp
    Created: 3 Oct 2019 5:19:29am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ControlStateDisplayModel.h"



void ControlStateDisplayModel::SetParameter(imbControlParameter * parameter)
  {
	parameterID = parameter->parameterID + " [ " + parameter->parameterLabel + " ]";
	parameterGroup = parameter->parameterParentPath;
	parameterValue = juce::String(parameter->Value);
  }

  ControlStateDisplayModel::ControlStateDisplayModel()
{
}
