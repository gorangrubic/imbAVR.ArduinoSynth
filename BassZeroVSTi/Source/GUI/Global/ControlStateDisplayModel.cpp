/*
  ==============================================================================

    ControlStateDisplayModel.cpp
    Created: 3 Oct 2019 5:19:29am
    Author:  gorangrubic

  ==============================================================================
*/

#include "ControlStateDisplayModel.h"

#include "../Source/Utility/imbSynthTools.h"

void ControlStateDisplayModel::UpdateParameter(juce::String value, juce::String ccIn, juce::String ccOut)
{
	if (parameter_ptr != nullptr) {

		parameter_ptr->SetValue(imbSynthTools::StringToInt32(value, parameter_ptr->Value));
		parameterValue = juce::String(parameter_ptr->Value);

		if (isCCParameter) {
			parameterCCIn = imbSynthTools::StringToInt32(ccIn, int(parameterCCIn));
			parameterCCOut = imbSynthTools::StringToInt32(ccOut, int(parameterCCOut));


			InputToHardwareMap->Set(parameter_ptr->ccID, parameterCCIn);
			HardwareToOutputMap->Set(parameter_ptr->ccID, parameterCCOut);
		}
	}

}

void ControlStateDisplayModel::SetParameter(imbControlParameter * parameter)
  {
	parameterID = parameter->parameterID + " [ " + parameter->parameterLabel + " ]";
	parameterGroup = parameter->parameterParentPath;
	parameterValue = juce::String(parameter->Value);



	parameterCC = parameter->ccID;
	parameterCCIn = InputToHardwareMap->Get(parameter->ccID);
	parameterCCOut = HardwareToOutputMap->Get(parameter->ccID);

	//parameter_ptr = std::shared_ptr<imbControlParameter>(parameter);
	parameter_ptr = parameter;

	isCCParameter = parameter->typeMIDIMessage == imbControlParameterMessageType::ccMIDI;

  }

ControlStateDisplayModel::ControlStateDisplayModel(std::unique_ptr<ccTranslationMap> & inputToHardwareMap, std::unique_ptr<ccTranslationMap> & hardwareToOutputMap)
:InputToHardwareMap(inputToHardwareMap),
HardwareToOutputMap(hardwareToOutputMap)
	//:InputToHardwareMap( inputToHardwareMap ),
	//HardwareToOutputMap( hardwareToOutputMap )
{
	
	  /*InputToHardwareMap = std::shared_ptr<ccTranslationMap>(inputToHardwareMap);
	  HardwareToOutputMap = std::shared_ptr<ccTranslationMap>(hardwareToOutputMap);*/
}
