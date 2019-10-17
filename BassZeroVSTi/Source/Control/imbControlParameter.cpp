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

bool imbControlParameter::SetValue(float _newValue)
{
	if (_newValue < MinValue) _newValue = MinValue;
	if (_newValue > MaxValue) _newValue = MaxValue;

	bool isNewValue = false;

	if (Value != _newValue) {
		isNewValue = true;
	}
	
	Value = _newValue;

	if (isNewValue) {
		updateGUI();
		updateState();
	}

	return isNewValue;
}

void imbControlParameter::detachControl()
{
	if (pSlider != nullptr)
	{
		//delete pSlider;
		pSlider = nullptr;
	}
	if (pComboBox != nullptr) {
		//delete pComboBox;
		pComboBox = nullptr;
	}
	componentType = imbControlParameterComponentType::unassigned;

}

void imbControlParameter::attachControl(Slider * slider)
{
	detachControl();
	componentType = imbControlParameterComponentType::slider;
	
	pSlider = std::shared_ptr<Slider>(slider);//new SliderAttachment(valueTreeState, parameterIDPath, slider);
	pSlider->onValueChange = [&, this] {
		if (!isGUIUpdating) {
			float f = (float) pSlider->getValue();
			SetValue(f);
			onGUIFocus(this);
		}
	};
	updateGUI();
	updateState();
}

void imbControlParameter::attachControl(ComboBox * _comboBox)
{
	detachControl();
	componentType = imbControlParameterComponentType::combobox;
	pComboBox = std::shared_ptr<ComboBox>(_comboBox);
	pComboBox->onChange = [&, this] {
		if (!isGUIUpdating) {
			SetValue(pComboBox->getSelectedId());
			onGUIFocus(this);
		}
	};
	updateGUI();
	updateState();
}

void imbControlParameter::attachControl(ToggleButton * _button)
{
	detachControl();
	componentType = imbControlParameterComponentType::combobox;
	pToggleButton = std::shared_ptr<ToggleButton>(_button);
	pToggleButton->onStateChange = [&, this] {
		if (!isGUIUpdating) {
			auto s = pToggleButton->getToggleState();
			if (s) {
				SetValue(1);
			}
			else {
				SetValue(0);
			}
			onGUIFocus(this);
		}
	};
	updateGUI();
	updateState();
}

void imbControlParameter::attachControl(imbSynthParameterEditor * _editor)
{
	detachControl();
	componentType = imbControlParameterComponentType::imbParameterComponent;
	pParameterEditor = std::shared_ptr<imbSynthParameterEditor>(_editor);
	pParameterEditor->onValueChange = [&, this] {
		if (!isGUIUpdating) {
			SetValue(pParameterEditor->GetValue());
			onGUIFocus(this);
		}
	};
	updateGUI();
	updateState();
}



void imbControlParameter::updateGUI()
{
	isGUIUpdating = true;

	switch (componentType) {

	case imbControlParameterComponentType::combobox:
		
		pComboBox->setSelectedId((int)std::floorf(Value), true);
		break;
	case imbControlParameterComponentType::slider:
		pSlider->setValue(Value, juce::NotificationType::dontSendNotification);
		break;
	case imbControlParameterComponentType::unassigned:

		break;
	case imbControlParameterComponentType::checkbox:
		pToggleButton->setToggleState(Value > 0.5, true);
		break;
	case imbControlParameterComponentType::imbParameterComponent:
		pParameterEditor->SetValue(Value);
		break;
	}
	isGUIUpdating = false;
}

void imbControlParameter::updateState()
{
	isStateUpdating = true;

	pParameter->setValueNotifyingHost(Value);

	isStateUpdating = false;
}






void imbControlParameter::Setup(String _parameterID, String _parameterLabel,
				float minValue, float maxValue, float initValue,
                String _parameterUnit,
                int _ccID, bool _isAutomatizable, imbControlParameterType _type,
	imbControlParameterMessageType _msgFormat) {
                    
	parameterID = _parameterID;
	parameterLabel = _parameterLabel;
	parameterUnit = _parameterUnit;

	if (parameterParentPath.isNotEmpty()) {
		parameterIDPath = parameterParentPath + "" + parameterID;
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

void imbControlParameter::parameterChanged(const String &, float newValue)
{
	if (!isStateUpdating) {
		SetValue(newValue);
	}
}

//std::function<void()> imbControlParameter::onGUIFocus(imbControlParameter * parameter)
//{
//	return std::function<void()>();
//}

void imbControlParameter::attachState(juce::AudioProcessorValueTreeState & parameters)
{
	NormalisableRange<float> valueRange = NormalisableRange<float>(MinValue, MaxValue, IntervalValue);

	pParameter = std::shared_ptr<juce::RangedAudioParameter>(parameters.createAndAddParameter(parameterIDPath,
		parameterID, parameterLabel, valueRange, Value, nullptr, nullptr,
		isMetaValue, isAutomatizable, isDescreteValue,
		category, typeParameter == imbControlParameterType::Boolean));
	
	parameters.addParameterListener(parameterIDPath, this);

	//updateState();
}

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
