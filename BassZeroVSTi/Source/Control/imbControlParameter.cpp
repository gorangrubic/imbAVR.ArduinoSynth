/*
  ==============================================================================

    imbAVRParameter.cpp
    Created: 28 Sep 2019 2:12:50am
    Author:  gorangrubic

  ==============================================================================
*/



#include "imbControlParameter.h"

#include "../Source/Utility/imbSynthTools.h"
#include "../Source/Model/ModelConstructionTools.h"

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

void imbProcessorParameterListener::parameterValueChanged(int parameterIndex, float newValue)
{
}

void imbProcessorParameterListener::parameterGestureChanged(int parameterIndex, bool gestureIsStarting)
{
}
