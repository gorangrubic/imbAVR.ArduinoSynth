/*
  ==============================================================================

    imbAVRParameter.cpp
    Created: 28 Sep 2019 2:12:50am
    Author:  gorangrubic

  ==============================================================================
*/



#include "imbControlParameter.h"

#include "../Source/Utility/imbSynthTools.h"

//#define Root Parent->Root

bool imbControlParameter::SetValue(int _newValue)
  {
	  return false;
  }

//void imbControlParameter::detachControl()
//{
//	if (pSliderAttachment != nullptr)
//	{
//		delete pSliderAttachment;
//		pSliderAttachment = nullptr;
//	}
//}
//
//void imbControlParameter::attachControl(Slider & slider)
//{
//	detachControl();
////	pSliderAttachment = new SliderAttachment(_parent->Root->SynthProcessor->parameters, parameterIDPath, slider);
//
//}






void imbControlParameter::Setup(String _parameterID, String _parameterLabel,
				float minValue, float maxValue, float initValue,
                String _parameterUnit,
                int _ccID, bool _isAutomatizable, imbControlParameterType _type,
	imbControlParameterMessageType _msgFormat) {
                    
	parameterID = _parameterID;
	parameterLabel = _parameterLabel;
	parameterUnit = _parameterUnit;

	if (parameterParentPath != "") {
		parameterIDPath = parameterParentPath + "." + parameterID;
	}
	else {
		parameterIDPath = parameterID;
	}
	

	typeParameter = _type;
	MinValue = minValue;
	MaxValue = maxValue;
	Value = initValue;

	if (_msgFormat != imbControlParameterMessageType::unspecified) {
		typeMIDIMessage = _msgFormat;
	}
	
	//AudioProcessorValueTreeState& valueTreeState = Root->SynthProcessor->parameters;

	ccID = _ccID;

	isAutomatizable = _isAutomatizable;
	isDescreteValue = false;

	switch (typeParameter) {
	case imbControlParameterType::Integer:
		isDescreteValue = true;
		IntervalValue = 1.0f;
		break;
	case imbControlParameterType::Boolean:
		isDescreteValue = true;
		
		break;
	case imbControlParameterType::Enumeration:
		isDescreteValue = true;
		
		break;
	case imbControlParameterType::Float:
		isDescreteValue = false;
		
		break;
	case imbControlParameterType::Ratio:
		isDescreteValue = false;
		
		IntervalValue = 0.01f;
		break;
	}

	

}


//
//bool imbControlParameter::SliderMoved(juce::Slider * sliderThatWasMoved)
//{
//	if (sliderThatWasMoved == assignedSlider)
//	{
//		return SetValue(assignedSlider->getValue());
//	}
//	else {
//		return false;
//	}
//}
//
//void imbControlParameter::SliderUpdate()
//{
//	assignedSlider->setValue(Value);
//}

juce::String imbControlParameter::valueToString(float v, int maxLen)
{
	return juce::String();
}

float imbControlParameter::stringToValue(juce::String input)
{
	return 0.0f;
}

void imbControlParameter::SetHelp(String _parameterHelp, String _parameterHelpUrl, String _parameterUnit)
{
	if (_parameterHelp != "") parameterHelp = _parameterHelp;
	if (_parameterHelpUrl != "") parameterHelpUrl = _parameterHelpUrl;
	if (_parameterUnit != "") parameterUnit = _parameterUnit;
}



void imbControlParameter::SetParameter(std::shared_ptr<ParameterController> parameterControllerPtr, AudioProcessorParameterGroup * group)
{

	NormalisableRange<float> valueRange = NormalisableRange<float>(MinValue, MaxValue, IntervalValue);

	/*pt p = pt(parameterIDPath, parameterID, parameterLabel, valueRange, Value, nullptr, nullptr, isMetaValue, isAutomatizable, isDescreteValue, category, typeParameter == imbControlParameterType::Boolean);
	parameter = &p;
	parameter->addListener(this);
	std::unique_ptr<RangedAudioParameter> ptr = std::unique_ptr<RangedAudioParameter>(&p);*/

	//parameterControllerPtr->parameters->createAndAddParameter(ptr);

	
	//rangedParameter = 
	auto p = parameterControllerPtr->parameters->createAndAddParameter(parameterIDPath, parameterID, parameterLabel, valueRange, Value, nullptr, nullptr, isMetaValue, isAutomatizable, isDescreteValue, category, typeParameter == imbControlParameterType::Boolean);

	//rangedParameter->addListener(this);

	//ptr = std::unique_ptr<RangedAudioParameter>(rangedParameter);

	
	//group->addChild((std::unique_ptr<RangedAudioParameter>) ptr);

	//AudioParameterFloat(const String& parameterID,
	//	const String& parameterName,
	//	NormalisableRange<float> normalisableRange,
	//	float defaultValue,
	//	const String& parameterLabel = String(),
	//	Category parameterCategory = AudioProcessorParameter::genericParameter,
	//	std::function<String(float value, int maximumStringLength)> stringFromValue = nullptr,
	//	std::function<float(const String& text)> valueFromString = nullptr);
	
	//AudioParameterFloat apFloat;

	/*std::function<juce::String(float value, int maximumStringLength)> stringFromValue = std::bind<juce::String>(&valueToString,this);

	std::function<float(juce::String text)> valueFromString = std::bind<float>(&stringToValue, this);

	std::function<String(float, int)> f_v2s = std::bind<String>(&imbControlParameter::valueToString, this);
	std::function<float(juce::String)> f_s2v = std::bind<float>(&imbControlParameter::stringToValue, this);*/

	//switch (typeParameter) {
	//	case imbControlParameterType::Integer:
	//		parameter = &AudioParameterInt(parameterIDPath, parameterID, (int)MinValue, (int)MaxValue, (int)Value, parameterLabel);
	//		parameterControllerPtr->AddParam<AudioParameterInt>(parameter, group);
	//		break;
	//	case imbControlParameterType::Boolean:
	//		parameter = &AudioParameterBool(parameterIDPath, parameterID, false, parameterLabel);
	//		parameterControllerPtr->AddParam<AudioParameterBool>(parameter, group);
	//		break;
	//	case imbControlParameterType::Enumeration:
	//
	//		parameter = &AudioParameterChoice(parameterIDPath, parameterID, enumerationList->GetItems(), (int)Value, parameterLabel);
	//		parameterControllerPtr->AddParam<AudioParameterChoice>(parameter, group);

	//		break;
	//	case imbControlParameterType::Float:
	//		//parameter = &AudioParameterFloat(&parameterIDPath, parameterID, MinValue, MaxValue, Value, category, stringFromValue, valueFromString);
	//		parameter = &AudioParameterFloat(parameterIDPath, parameterID, MinValue, MaxValue, Value);
	//		parameterControllerPtr->AddParam<AudioParameterFloat>(parameter, group);
	//		break;
	//	case imbControlParameterType::Ratio:
	//		parameter = &AudioParameterFloat(parameterIDPath, parameterID, MinValue, MaxValue, Value);
	//		parameterControllerPtr->AddParam<AudioParameterFloat>(parameter, group);
	//		break;
	//}

	//
	//parameter->isAutomatable = isAutomatizable;
	//parameter->isMetaParameter = isMetaValue;
	//parameter->isDiscrete = isDescreteValue;
	//parameter->isBoolean = typeParameter == imbControlParameterType::Boolean;
//	parameter->addListener(this);

	
}

bool imbControlParameter::SetMidiMessage(MidiMessage * message)
{
	return false;
}

juce::MidiMessage imbControlParameter::GetMidiMessage()
{
	juce::MidiMessage msg = juce::MidiMessage();
	//msg.noteOn

	return msg;
}

//imbControlParameter::imbControlParameter()
//:Listener(Value, 1.0F)
//{
//}

imbControlParameter::imbControlParameter()
{
}

imbControlParameter::~imbControlParameter()
{
}