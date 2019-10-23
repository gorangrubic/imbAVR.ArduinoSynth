/*
  ==============================================================================

    dataObjectPropertyEnumerations.h
    Created: 22 Oct 2019 9:28:19pm
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once

enum class guiAttachedComponentType :unsigned int {
	unassigned = 0,
	slider = 1,
	combobox = 2,
	checkbox = 3,
	/* imb custom component that is editor for this parameter */
	imbParameterComponent = 4,
	texteditor=5,
	textlabel=6
};

enum class parameterClass {
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

enum class parameterType {
	objectProperty=0,
	controlParameter,
};