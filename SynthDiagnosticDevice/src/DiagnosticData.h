// DiagnosticData.h

#ifndef _DIAGNOSTICDATA_h
#define _DIAGNOSTICDATA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define LOG_SIZE 12

class DiagnosticData {

public:

	String LogMessages[LOG_SIZE];
	byte LogIndex = 0;
	unsigned int LogCount = 1;

	void AddLog(String logMessage);


	byte SynthInBuffer[64];
	byte SynthInBufferIndex = 0;

	byte SignalInBuffer[64];
	byte SignalInBufferIndex = 0;

};

#endif

