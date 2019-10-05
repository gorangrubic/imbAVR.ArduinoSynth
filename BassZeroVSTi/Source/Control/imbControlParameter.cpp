/*
  ==============================================================================

    imbAVRParameter.cpp
    Created: 28 Sep 2019 2:12:50am
    Author:  gorangrubic

  ==============================================================================
*/



#include "imbControlParameter.h"



bool imbControlParameter::SetValue(int _newValue)
  {
	  return false;
  }

void imbControlParameter::detachControl()
{
	if (pSliderAttachment != nullptr)
	{
		delete pSliderAttachment;
		pSliderAttachment = nullptr;
	}
}

void imbControlParameter::attachControl(Slider & slider)
{
	detachControl();
	pSliderAttachment = new SliderAttachment(Root->SynthProcessor->parameters, parameterIDPath, slider);

}


void imbControlParameter::Connect(SynthDeviceModelComponentBase * _parent) {
	Parent = _parent;
	Root = Parent->Root;

	parameterIDPath = Parent->ShortName + "_" + parameterID;

	AudioProcessorValueTreeState& valueTreeState = Root->SynthProcessor->parameters;

	std::function<String(float)> valueToTextFunction = floatToText<imbControlParameterType::Boolean>;
	std::function<float(const String&)> textToValueFunction = textToFloat<imbControlParameterType::Boolean>;

	switch (typeParameter) {
		case imbControlParameterType::Float:
			valueToTextFunction = floatToText<imbControlParameterType::Float>;
			textToValueFunction = textToFloat<imbControlParameterType::Float>;
			break;
		case imbControlParameterType::Ratio:
			valueToTextFunction = floatToText<imbControlParameterType::Ratio>;
			textToValueFunction = textToFloat<imbControlParameterType::Ratio>;
			break;
		case imbControlParameterType::Enumeration:
			valueToTextFunction = floatToText<imbControlParameterType::Enumeration>;
			textToValueFunction = textToFloat<imbControlParameterType::Enumeration>;
			break;
		case imbControlParameterType::Integer:
			valueToTextFunction = floatToText<imbControlParameterType::Integer>;
			textToValueFunction = textToFloat<imbControlParameterType::Integer>;
			break;
		case imbControlParameterType::Boolean:
			valueToTextFunction = floatToText<imbControlParameterType::Boolean>;
			textToValueFunction = textToFloat<imbControlParameterType::Boolean>;
			break;
	}

	parameter = valueTreeState.createAndAddParameter(parameterIDPath, parameterID, parameterLabel,
		NormalisableRange<float>(MinValue, MaxValue, IntervalValue),
		imbControlParameter::ProcessValue(Value, typeParameter),
		valueToTextFunction,
		textToValueFunction,
		false,
		isAutomatizable,
		isDescreteValue,
		category,
		typeParameter == imbControlParameterType::Boolean
	);

	
	valueTreeState.addParameterListener(parameterIDPath, &Listener);

}


void imbControlParameter::Setup(String _parameterID, String _parameterLabel, 
				float minValue, float maxValue, float initValue,
                String _parameterUnit,
                int _ccID, bool _isAutomatizable, imbControlParameterType _type,
	imbControlParameterMessageType _msgFormat) {
                    
	parameterID = _parameterID;
	parameterLabel = _parameterLabel;
	parameterUnit = _parameterUnit;
	typeParameter = _type;
	MinValue = minValue;
	MaxValue = maxValue;
	Value = initValue;

	if (_msgFormat != imbControlParameterMessageType::unspecified) {
		typeMIDIMessage = _msgFormat;
	}
	
	AudioProcessorValueTreeState& valueTreeState = Root->SynthProcessor->parameters;

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



bool imbControlParameter::SliderMoved(juce::Slider * sliderThatWasMoved)
{
	if (sliderThatWasMoved == assignedSlider)
	{
		return SetValue(assignedSlider->getValue());
	}
	else {
		return false;
	}
}

void imbControlParameter::SliderUpdate()
{
	assignedSlider->setValue(Value);
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

imbControlParameter::imbControlParameter():Listener(Value)
{
}

imbControlParameter::~imbControlParameter()
{
}