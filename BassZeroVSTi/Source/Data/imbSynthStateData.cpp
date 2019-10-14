#include "imbSynthStateData.h"





void imbSynthStateData::SetParameterInFocus(imbControlParameter * parameter)
{
	bool newInFocus = false;
	if (inFocusParameterID != parameter->parameterIDPath) {
		newInFocus = true;
	}

	inFocusParameterID == parameter->parameterIDPath;

	controlDisplayModel->SetParameter(parameter);
}

imbSynthStateData::~imbSynthStateData()
{
}
