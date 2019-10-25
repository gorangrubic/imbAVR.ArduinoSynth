/*
  ==============================================================================

    dataObjectPropertyBase.h
    Created: 22 Oct 2019 9:05:13pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
//#include "../Source/GUI/Components/imbSynthParameterEditor.h"
#include "dataObjectPropertyEnumerations.h"
#include "../Source/Data/Structures/imbEnumerationList.h"
#include "../Source/Utility/imbSynthTools.h"
#include "../Source/Data/Model/dataElementBase.h"


class dataObjectPropertyBase
:public dataElementBase,
public AudioProcessorValueTreeState::Listener {

protected:
	/* indicating if GUI is currently updated by internal source */
	bool isGUIUpdating = false;
	bool isStateUpdating = false;

	//guiAttachedComponentType componentType = guiAttachedComponentType::unassigned;

	//std::shared_ptr<Slider> pSlider;
	//std::shared_ptr<ComboBox> pComboBox;
	//std::shared_ptr<ToggleButton> pToggleButton;
	//std::shared_ptr<TextEditor> pTextEditor;
	//std::shared_ptr<Label> pLabel;
	//std::shared_ptr<imbSynthParameterEditor> pParameterEditor;

	

	bool setValue(float _newValue);

public:

	void attachState(juce::AudioProcessorValueTreeState & parameters);

	//void updateGUI();
	void updateState();
	//void updateTooltip();

	std::shared_ptr<juce::RangedAudioParameter> pParameter;
	   
	void parameterChanged(const String&, float newValue);


	

	parameterValueType valueType = parameterValueType::Float;

	float Value = 0.0;

	
	float MinValue = 0;
	float MaxValue = 0;
	float IntervalValue = 1;

	std::string ValueString = "";

	

	imbEnumerationList * enumerationList = nullptr;

	virtual bool SetValue(float _newValue) = 0;

	bool SetStrValue(std::string _newValue);

	bool SetBoolValue(bool _newValue);

	bool SetIntValue(int _newValue);

	int GetIntValue();

	float GetFloatValue();

	bool GetBoolValue();

	/* returns value remapped to CC range 0-127 */
	char GetCCByteValue();
	bool SetCCByteValue(char _ccValue);
	

	/* Gets String value */
	String GetStringValue();


	virtual void updateAll() = 0;

	void detachControl();

	void updateGUI();
	
	void updateTooltip();

	dataObjectPropertyBase(parameterValueType _valueType = parameterValueType::Float, std::string _name = "", std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = "", float minValue=0, float maxValue=0, parameterClass _parClass = parameterClass::unspecified):dataElementBase(_name,_label,_description,_unit,_helpUrl) {

		parClass = _parClass;

		switch (parClass)
		{
		case parameterClass::unspecified:
			break;
		case parameterClass::ccLive:
			features |= dataElementFeatures::isAutomatizable;
			break;
		case parameterClass::ccSustained:
			features |= dataElementFeatures::isAutomatizable;
			break;
		case parameterClass::opm:
			break;
		case parameterClass::configuration:
			break;
		default:
			break;
		}

		MinValue = minValue;
		MaxValue = maxValue;
		
		switch (_valueType)
		{
		case parameterValueType::Integer:
			IntervalValue = 1;
			break;
		case parameterValueType::Ratio:
			if (MinValue == MaxValue) {
				MinValue = 0;
				MaxValue = 1;
				IntervalValue = 0.05;
			}
			break;
		case parameterValueType::Float:
			if (MinValue != MaxValue) {

				IntervalValue = (MaxValue - MinValue) / 20;
			}
			break;
		case parameterValueType::Enumeration:
			IntervalValue = 1;
			break;
		case parameterValueType::Boolean:
			IntervalValue = 1;
			MinValue = 0;
			MaxValue = 1;
			break;
		case parameterValueType::String:
			break;
		case parameterValueType::Byte:
			break;
		default:
			break;
		}

		if (MinValue != MaxValue) {
			features |= dataElementFeatures::isValueRanged;
		}

		if (MinValue < 0)
		{
			features |= dataElementFeatures::isSignedRange;
		}
		

		valueType = _valueType;
	};
	
};