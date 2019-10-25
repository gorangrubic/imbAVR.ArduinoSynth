/*
  ==============================================================================

    dataObjectPropertyEnumerations.h
    Created: 22 Oct 2019 9:28:19pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

//class dataElementConstants {
//
//	static const std::string RoleClassContainer = "dataElementContainer";
//};

/* this class template is taken from: https://stackoverflow.com/questions/1448396/how-to-use-enums-as-flags-in-c/43213134#43213134 */
/* Author: uliwitness (stackoverflow user: https://stackoverflow.com/users/242278/uliwitness ) */
template<class ENUM, class UNDERLYING = typename std::underlying_type<ENUM>::type>
class SafeEnum
{
public:
	SafeEnum() : mFlags(0) {}
	SafeEnum(ENUM singleFlag) : mFlags(singleFlag) {}
	SafeEnum(const SafeEnum& original) : mFlags(original.mFlags) {}

	SafeEnum&   operator |=(ENUM addValue) { mFlags |= addValue; return *this; }
	SafeEnum    operator |(ENUM addValue) { SafeEnum  result(*this); result |= addValue; return result; }
	SafeEnum&   operator &=(ENUM maskValue) { mFlags &= maskValue; return *this; }
	SafeEnum    operator &(ENUM maskValue) { SafeEnum  result(*this); result &= maskValue; return result; }
	SafeEnum    operator ~() { SafeEnum  result(*this); result.mFlags = ~result.mFlags; return result; }


	explicit operator bool() { return mFlags != 0; }

protected:
	UNDERLYING  mFlags;
};

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
	Byte = 6
};

//enum class parameterType {
//	objectProperty=0,
//	controlParameter,
//};