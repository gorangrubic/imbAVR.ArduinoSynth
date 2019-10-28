/*
  ==============================================================================

    dataObjectPropertyBase.cpp
    Created: 22 Oct 2019 9:05:13pm
    Author:  gorangrubic

  ==============================================================================
*/

#include "dataObjectPropertyBase.h"



bool dataObjectPropertyBase::setValue(float _newValue)
{
	bool isNewValue = false;

	if (Value != _newValue) {
		isNewValue = true;
	}

	Value = _newValue;

	if (isNewValue) {
		updateGUI();
	}

	return isNewValue;
}

void dataObjectPropertyBase::attachState(juce::AudioProcessorValueTreeState & parameters)
{
}

void dataObjectPropertyBase::updateState()
{
}

  void dataObjectPropertyBase::parameterChanged(const String &, float newValue)
  {
  }

  int dataObjectPropertyBase::GetCheckSum(bool forValue, bool forStructure)
  {
	  int output = 0;

	  if (forValue) {

		  if (valueType != parameterValueType::String) {
			  output += GetIntValue();
		  }
		  else {
			  auto s = GetStringValue();
			/*  for (size_t i = 0; i < s.length(); i++)
			  {
				  
			  }*/
			 /* for each (char var in s.getCharPointer)
			  {
				  output += (char)var;
			  }*/
			  output += s.hashCode(); // GetStringValue().length();
		  }

	  }

	  if (forStructure) {

		  juce::String p = parameterIDPath;

		  output += p.hashCode();
		  /*for each (char var in parameterIDPath.getCharPointer)
		  {
			  output += (char)var;
		  }*/
	  }

	  return output;
  }

bool dataObjectPropertyBase::SetStrValue(std::string _newValue)
{
	bool isNewValue = false;
	juce::String jStr = juce::String(_newValue);

	if (valueType == parameterValueType::String || valueType == parameterValueType::customClassProperty) {

		if (ValueString != _newValue) {
			isNewValue = true;
		}

		ValueString = _newValue;
	}
	else if (valueType == parameterValueType::Enumeration) {

		ValueString = _newValue;

		if (enumerationList != nullptr) {
			auto i = enumerationList->IndexOf(juce::String(_newValue));
			if (i > -1) {
				isNewValue = SetIntValue(i);
			}
		}
		else {
			float v = imbSynthTools::StringToFloat(_newValue, Value);
			isNewValue = setValue(v);
		}
	}
	else if (valueType == parameterValueType::Boolean) {

		if (_newValue == "0") {
			isNewValue = SetBoolValue(false);
		}
		else {
			isNewValue = SetBoolValue(true);
		}
	}
	else if (valueType == parameterValueType::Integer) {
		
		int iv = jStr.getIntValue();

		isNewValue = SetIntValue(iv);
	}
	else {
		float v = jStr.getFloatValue(); //imbSynthTools::StringToFloat(_newValue, Value);
		isNewValue = setValue(v);
	}

	return isNewValue;
}

bool dataObjectPropertyBase::SetBoolValue(bool _newValue)
{
	if (_newValue) {
		return SetValue(1);
	}
	else {
		return SetValue(0);
	}
}

bool dataObjectPropertyBase::SetIntValue(int _newValue)
{
	return SetValue((float)_newValue);
}

int dataObjectPropertyBase::GetIntValue()
{
	return (int)std::floorf(Value);
}

float dataObjectPropertyBase::GetFloatValue()
{
	return Value;
}

bool dataObjectPropertyBase::GetBoolValue()
{
	return Value > 0.5;
}

char dataObjectPropertyBase::GetCCByteValue()
{
	auto vRange = MaxValue - MinValue;

	float vUnit = 127 / vRange;

	char ccZeroPoint = (MinValue / vRange) * 127;

	char output = (Value* vUnit) -ccZeroPoint;
	
	/*if (MinValue < 0)
	{
		ccZeroPoint = (std::abs(MinValue) / vRange) * 127;
	} else
	{
		
	}*/
	
	return output;
}

bool dataObjectPropertyBase::SetCCByteValue(char _ccValue)
{
	auto vRange = MaxValue - MinValue;

	float vUnit = 127 / vRange;

	char ccZeroPoint = (MinValue / vRange) * 127;

	float output = (_ccValue + ccZeroPoint) / vUnit;

	return SetValue(output);
	//char output = (Value* vUnit) - ccZeroPoint;
}

String dataObjectPropertyBase::GetStringValue()
{
	juce::String output = juce::String(Value);

	if (valueType == parameterValueType::String || valueType == parameterValueType::customClassProperty) {
		return ValueString;
	}
	else if (valueType == parameterValueType::Enumeration) {
		if (enumerationList != nullptr) {
			auto i = GetIntValue();
			auto entry = enumerationList->AtIndex(i);
			if (entry.isEmpty()) {
				return ValueString;
			}
			else {
				return entry;
			}
		}
		else {
			if (!ValueString.empty()) {
				return juce::String(ValueString);
			}
			return juce::String(Value);
		}
	}
	else if (valueType == parameterValueType::Boolean) {

		if (GetBoolValue()) {
			output = "1";
		}
		else {
			output = "0";
		}

	}
	else {
		auto jStr = juce::String(Value);
		return jStr;
	}
	return output;
}
/*
void dataObjectPropertyBase::attachControl(Slider * _slider)
{
	detachControl();
	componentType = guiAttachedComponentType::slider;

	pSlider = std::shared_ptr<Slider>(_slider);//new SliderAttachment(valueTreeState, parameterIDPath, slider);
	pSlider->onValueChange = [&, this] {
		if (!isGUIUpdating) {
			float f = (float)pSlider->getValue();
			SetValue(f);
			if (onGUIFocus != nullptr) onGUIFocus(parameterIDPath);
		}
	};
	updateAll();
}

void dataObjectPropertyBase::attachControl(ComboBox * _comboBox)
{
	detachControl();
	componentType = guiAttachedComponentType::combobox;
	pComboBox = std::shared_ptr<ComboBox>(_comboBox);
	


	pComboBox->onChange = [&, this] {
		if (!isGUIUpdating) {
			SetValue(pComboBox->getSelectedId());
			if (onGUIFocus != nullptr) {
				onGUIFocus(parameterIDPath);
			}
		}
	};
	updateAll();
}

void dataObjectPropertyBase::attachControl(ToggleButton * _button)
{
	detachControl();
	componentType = guiAttachedComponentType::checkbox;
	pToggleButton = std::shared_ptr<ToggleButton>(_button);
	pToggleButton->onStateChange = [&, this] {
		if (!isGUIUpdating) {
			auto s = pToggleButton->getToggleState();
			SetBoolValue(s);
			if (onGUIFocus != nullptr) onGUIFocus(parameterIDPath);
		}
	};
	updateAll();
}

void dataObjectPropertyBase::attachControl(TextEditor * _textEditor)
{
	detachControl();
	componentType = guiAttachedComponentType::texteditor;
	
	pTextEditor = std::shared_ptr<TextEditor>(_textEditor);
	pTextEditor->onTextChange = [&, this] {
		if (!isGUIUpdating) {
			SetStrValue(pTextEditor->getText().toStdString());
			if (onGUIFocus != nullptr) onGUIFocus(parameterIDPath);
		}
	};
	updateAll();
}

void dataObjectPropertyBase::attachControl(Label * _textLabel)
{
	detachControl();
	componentType = guiAttachedComponentType::textlabel;
	pLabel = std::shared_ptr<Label>(_textLabel);

	updateAll();
}

void dataObjectPropertyBase::attachControl(imbSynthParameterEditor * _editor)
{
	detachControl();
	componentType = guiAttachedComponentType::imbParameterComponent;
	pParameterEditor = std::shared_ptr<imbSynthParameterEditor>(_editor);
	pParameterEditor->onValueChange = [&, this] {
		if (!isGUIUpdating) {
			SetValue(pParameterEditor->GetValue());
			if (onGUIFocus != nullptr) onGUIFocus(parameterIDPath);
		}
	};
	
	updateAll();
}
*/

//void dataObjectPropertyBase::SetHelp(String _parameterHelp, String _parameterHelpUrl, String _parameterUnit)
//{
//
//}

void dataObjectPropertyBase::detachControl()
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
	componentType = guiAttachedComponentType::unassigned;
}


void dataObjectPropertyBase::updateGUI()
{
	isGUIUpdating = true;
	int i = 1;

	switch (componentType) {

	case guiAttachedComponentType::combobox:

		pComboBox->clear(true);

		
		for each (auto var in enumerationList->Items)
		{
			pComboBox->addItem(var, i);
			i++;
		}

		pComboBox->setSelectedId(GetIntValue(), true);
		break;
	case guiAttachedComponentType::slider:
		pSlider->setValue(Value, juce::NotificationType::dontSendNotification);
		break;
	case guiAttachedComponentType::unassigned:

		break;
	case guiAttachedComponentType::checkbox:
		pToggleButton->setToggleState(GetBoolValue(), true);
		break;
	case guiAttachedComponentType::imbParameterComponent:
		pParameterEditor->SetValue(Value);
		break;
	case guiAttachedComponentType::texteditor:
		pTextEditor->setText(GetStringValue(), false);
		break;
	case guiAttachedComponentType::textlabel:
		pLabel->setText(GetStringValue(), juce::NotificationType::dontSendNotification);
		break;
	}
	isGUIUpdating = false;
}

void dataObjectPropertyBase::updateTooltip()
{
		juce::String tooltip_msg = parameterHelp;
	if (!Error.empty()) {
		tooltip_msg.append(" Error: " + Error, 200);
	}

	switch (componentType) {

	case guiAttachedComponentType::combobox:
		pComboBox->setTooltip(tooltip_msg);
		
		break;
	case guiAttachedComponentType::slider:
		//pSlider->setValue(Value, juce::NotificationType::dontSendNotification);
		pSlider->setTooltip(tooltip_msg);
		break;
	case guiAttachedComponentType::unassigned:

		break;
	case guiAttachedComponentType::checkbox:
		pToggleButton->setTooltip(tooltip_msg);
		//pToggleButton->setToggleState(Value > 0.5, true);
		break;
	case guiAttachedComponentType::imbParameterComponent:
		//pParameterEditor->SetValue(Value);
		pParameterEditor->setTooltip(tooltip_msg);
		break;
	case guiAttachedComponentType::textlabel:
		pLabel->setTooltip(tooltip_msg);
		break;
	}
}
