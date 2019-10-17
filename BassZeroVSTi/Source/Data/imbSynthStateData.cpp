#include "imbSynthStateData.h"





void imbSynthStateData::Initiated()
{
	model->CollectAllParameters(Parameters);

	for each (auto var in Parameters)
	{
		if (var->typeMIDIMessage == imbControlParameterMessageType::ccMIDI) {
			InputToHardwareMap->SetDefault(var->ccID);
			HardwareToOutputMap->SetDefault(var->ccID);
		}

		var->onGUIFocus = [&, this](imbControlParameter * parameter) {
			SetParameterInFocus(parameter);

		};
	}
	
}

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
