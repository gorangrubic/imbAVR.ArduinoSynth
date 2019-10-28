/*
  ==============================================================================

    dataObjectPropertyEnumerations.h
    Created: 22 Oct 2019 9:28:19pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

#include "../Source/Utility/SafeEnum.h"

namespace dataElementFeatures {
	enum _features :int {
		none = 0,
		isElementContainer = 1 << 0, // binary 0001
		isValueRanged = 1 << 1, // binary 0010
		isAutomatizable = 1 << 2, // binary 0100
		isEditableFromGUI = 1 << 3, // binary 1000
		doReconfigureEditor = 1 << 4,
		doUseAssignedColor = 1 << 5,
		doSetValueByContextMenu = 1 << 6,
		doAllowCopyPaste = 1 << 7,
		hideGUIEditor = 1 << 8,
		/* Element is  */
		isDisabled = 1 << 9,
		/* when true, the parameter will be declared in DAW even if isAutomatizable is flase  */
		doDeclareInValueTree = 1 << 10,		
		/// <summary>
		/// minValue is less than zero, maxValue is above zero
		/// </summary>
		isSignedRange = 1 << 11,
		isProperty = 1<<12,
		/* parameter has fixed value */
		isReadOnly = 1 << 13,
		/* parameter is not saved to file*/
		isTemporary = 1 << 14,
		allowToShowLabel = 1 << 15,
		allowToShowDescription = 1 << 16,
		allowToShowHelpIcon = 1 << 17,
		allowToUseColor = 1 << 18,
	};

	typedef SafeEnum<enum _features> features;
}


enum class guiAttachedComponentType :unsigned int {
	unassigned = 0,
	slider = 1,
	combobox = 2,
	checkbox = 3,
	/* imb custom component that is editor for this parameter */
	imbParameterComponent = 4,
	texteditor=5,
	textlabel=6,
	imbComponent=7,	
	/// <summary>
	/// Assigment bound to a dataObject as group
	/// </summary>
	component = 8,
	/// <summary>
	/// context menu for enum or boolean values
	/// </summary>
	contextMenu = 9,

	parentComponent = 10
};

enum class parameterClass:int {
	/* not specified*/
	unspecified = 0,
	/* parameter is part of preset */
	ccLive = 1,

	ccSustained = 2,
	/* parameter is part of OPM */
	opm = 3,
	configuration = 4,
};




enum class parameterValueType :unsigned int {
	Integer = 0,
	Ratio = 1,
	Float = 2,
	Enumeration = 3,
	Boolean = 4,
	String = 5,
	Byte = 6,

	dataObject = 7,
	dataElementContainer = 8,
	customClassProperty = 9

};

namespace dataObjectPropertyEnumerations {

	enum class enumerationEditorModes :unsigned int {
		normal = 0,
		/* radio group -- for togglebuttin just a chekbox*/
		checkBox = 1,
		popupMenu = 2,
		labelWithPopupMenu = 3,
		textEditorWithPopupMenu = 4,
	};

	enum class sliderModes :unsigned int {
		linear = 0,
		/* radio group -- for togglebuttin just a chekbox*/
		numbers = 1,
		rotational = 2,
		labelWithPopupMenu = 3,
		textEditorWithPopupMenu = 4,
	};

	enum class layout :unsigned int {
		unspecified=0,
		column = 1,
		compactRow = 2,
		
	};

	static std::string GetDefaultEditorOfPreference(parameterValueType valueType) {

		switch (valueType) {
		case parameterValueType::Boolean:
			return "ToggleButton";
			break;
		case parameterValueType::Byte:
			return "PatternEditor8bit";
			break;
		case parameterValueType::dataObject:
			return "dataObjectEditor";
			break;
		case parameterValueType::dataElementContainer:
			return "dataTableEditor";
			break;
		case parameterValueType::customClassProperty:
			break;
		case parameterValueType::Enumeration:
			return "ComboBox";
			break;
		case parameterValueType::Float:
			return "Slider";
			break;
		case parameterValueType::Integer:
			return "Slider";
			break;
		case parameterValueType::Ratio:
			return "Slider";
			break;
		case parameterValueType::String:
			return "TextEditor";
			break;

		}
	}
}

//enum class parameterType {
//	objectProperty=0,
//	controlParameter,
//};