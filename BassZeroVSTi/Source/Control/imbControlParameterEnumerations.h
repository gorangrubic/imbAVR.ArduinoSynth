/*
  ==============================================================================

    imbControlParameterEnumerations.h
    Created: 8 Oct 2019 3:42:15am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"

enum class ModulationSourceType {
	unknown=0,
	ADSR=1,
	ENV=2,
	LFO=3,
	Macro=4,
	MIDI=5
};

enum class ModulationSourceMIDIType {
	notknown = 0,
	velocity = 1,
	note = 2,
	pitchbend = 3,
	aftertouch = 4
};





/// <summary>
/// Type of MIDI messsage that represents input / output format for this parameter
/// </summary>
enum class  imbControlParameterMessageType {
			
	/// <summary>
	/// Not specified - use default option
	/// </summary>
	unspecified = 0,
	/// <summary>
	/// Parameter is not supported in MIDI communication
	/// </summary>
	NoMIDI = 1,
	/// <summary>
	/// Parameter is described with Control Command MIDI message
	/// </summary>
	ccMIDI = 2,
	/// <summary>
	/// Parameter is described with System Exclusive MIDI message
	/// </summary>
	sysExMsg = 3

};

enum class imbControlParameterType:unsigned int {
	Integer=0,
	Ratio=1,
	Float=2,
	Enumeration=3,
	Boolean=4
};