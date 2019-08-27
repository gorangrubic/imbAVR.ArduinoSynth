#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif

#include "SynthState.h"

#define MonitorMessageStartChar 127
#define MonitorMessageHeaderSize 5
#define MonitorMessageEndChar 256
#define MonitorMessageSize_Bytes 137


class MonitorMessage {

public:

	SynthState State;

	unsigned int cT = 0;

	//byte[MonitorMessageSize_Bytes] ToArray();

	
	void SerialWrite(byte Data[MonitorMessageSize_Bytes]);

	void SerialRead(byte Data[MonitorMessageSize_Bytes]);
	
};
