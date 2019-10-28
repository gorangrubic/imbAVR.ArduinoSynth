/*
  ==============================================================================

    ParameterValueMessage.h
    Created: 26 Oct 2019 8:30:30am
    Author:  gorangrubic

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Source/Data/Model/dataObjectPropertyBase.h"
#include "../Source/Data/Model/dataObjectPropertyEnumerations.h"
#include "../Source/Model/imbControlParameterEnumerations.h"

class ParametarValueMessage {

public:

	static imbControlParameterMessageType ParameterClassToMessageType(parameterClass _parClass);
	
	
	imbControlParameterMessageType messageType;
	int id;
	char value;

	ParametarValueMessage(int _id, char _value, imbControlParameterMessageType _messageType);
	ParametarValueMessage(int _id, char _value, parameterClass _parClass);
};

imbControlParameterMessageType ParametarValueMessage::ParameterClassToMessageType(parameterClass _parClass)
{
	imbControlParameterMessageType _messageType = imbControlParameterMessageType::NoMIDI;

	switch (_parClass) {
	case parameterClass::ccLive:
		_messageType = imbControlParameterMessageType::ccMIDI;

		break;
	case parameterClass::ccSustained:
		_messageType = imbControlParameterMessageType::ccMIDI;
		break;
	case parameterClass::opm:
		_messageType = imbControlParameterMessageType::sysExMsg;
		break;
	case parameterClass::configuration:
		break;
	case parameterClass::unspecified:
		break;
	}
	return _messageType;
}

ParametarValueMessage::ParametarValueMessage(int _id, char _value, imbControlParameterMessageType _messageType)
{
	id = _id;
	value = _value;
	messageType = _messageType;
}

  ParametarValueMessage::ParametarValueMessage(int _id, char _value, parameterClass _parClass)
  {
	  id = _id;
	  value = _value;
	  messageType = ParametarValueMessage::ParameterClassToMessageType(_parClass);
  }
