/*
  ==============================================================================

    dataObjectPropertyBase.h
    Created: 22 Oct 2019 9:05:13pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/GUI/Components/imbSynthParameterEditor.h"
#include "dataObjectPropertyEnumerations.h"
#include "../Source/Data/Structures/imbEnumerationList.h"
#include "../Source/Utility/imbSynthTools.h"
#include "../Source/Data/Model/dataElementBase.h"

class dataObjectPropertyBase:public dataElementBase {

protected:
	/* indicating if GUI is currently updated by internal source */
	bool isGUIUpdating = false;
	bool isStateUpdating = false;

	guiAttachedComponentType componentType = guiAttachedComponentType::unassigned;

	std::shared_ptr<Slider> pSlider;
	std::shared_ptr<ComboBox> pComboBox;
	std::shared_ptr<ToggleButton> pToggleButton;
	std::shared_ptr<TextEditor> pTextEditor;
	std::shared_ptr<Label> pLabel;
	std::shared_ptr<imbSynthParameterEditor> pParameterEditor;



	

	bool setValue(float _newValue);

public:

	parameterValueType valueType = parameterValueType::Float;

	float Value = 0.0;
	std::string ValueString = "";

	parameterType type = parameterType::objectProperty;



	imbEnumerationList * enumerationList = nullptr;

	virtual bool SetValue(float _newValue) = 0;

	bool SetStrValue(std::string _newValue);

	bool SetBoolValue(bool _newValue);

	bool SetIntValue(int _newValue);

	int GetIntValue();

	float GetFloatValue();

	bool GetBoolValue();

	/* Gets String value */
	String GetStringValue();


//	String parameterID = "";
//	String parameterLabel = "";
//
//	// ========================== VSTi parameters
///* Unique parameter ID that is used for ValueTree parameter ID and for storing parameters*/
//	String parameterIDPath;
//
//	/// <summary>
//	/// Short help on this parameter
//	/// </summary>
//	String parameterHelp;
//
//	/// <summary>
//	/// URL with more information on the parameter
//	/// </summary>
//	String parameterHelpUrl;
//
//
//	String parameterUnit;
//
//	/// <summary>
//	/// Error message
//	/// </summary>
//	String Error;
//
//	/// <summary>
///// Sets additional information on this parameter
///// </summary>
///// <param name="_parameterHelp">The parameter help.</param>
///// <param name="_parameterHelpUrl">The parameter help URL.</param>
///// <param name="_parameterUnit">The parameter unit.</param>
//	void SetHelp(String _parameterHelp, String _parameterHelpUrl = "", String _parameterUnit = "");

	std::function<void(std::string idPath)> onGUIFocus = nullptr;

	void attachControl(Slider* _slider);
	void attachControl(ComboBox* _comboBox);
	void attachControl(ToggleButton* _button);
	void attachControl(TextEditor* _textEditor);
	void attachControl(Label* _textLabel);
	void attachControl(imbSynthParameterEditor* _editor);

	juce::Rectangle<int> getBounds();

	virtual void updateAll() = 0;

	void detachControl();

	void updateGUI();
	
	void updateTooltip();

	dataObjectPropertyBase(parameterValueType _valueType = parameterValueType::Float, std::string _name = "", std::string _label = "", std::string _description = "", std::string _unit = "", std::string _helpUrl = ""):dataElementBase(_name,_label,_description,_unit,_helpUrl) {

		valueType = _valueType;
	};
	
};