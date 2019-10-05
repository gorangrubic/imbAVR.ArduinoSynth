#pragma once


#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "HardwareSerial.h"

class LinkQualityMetrics
{	

public:

	///// <summary>
	///// Number of messages to run
	///// </summary>
	unsigned int TestTarget = 500;	
	/// <summary>
	/// Number of Count method called
	/// </summary>
	unsigned int MessageCounted = 0;

	unsigned int ReportCount = 100;
	unsigned int ReportIndex = 0;


	unsigned int SuccessAll = 0;

	unsigned int SuccessOn[8];

	unsigned int SuccessOnFirst = 0;
	unsigned int SuccessOnSecond = 0;
	unsigned int SuccessOnThird = 0;
	unsigned int SuccessOnFourth = 0;

	unsigned int FailAll = 0;
	unsigned int NothingReceived = 0;

	unsigned long StartTime = 0;
	unsigned long LastCountTime = 0;
	

	unsigned int MessageLost = 0;
	unsigned int DataBufferClipping = 0;
	unsigned int InstanceBufferClipping = 0;

	/// <summary>
	/// Counts the specified receive result.
	/// </summary>
	/// <param name="receiveResult">The receive result.</param>
	/// <returns>TRUE if report index is reached</returns>
	bool Count(byte receiveResult);

	void ShortReport(HardwareSerial * hSerial);

	///// <summary>
	///// The control sequence: order of values that ControlValue should follow. When received ControlValue skips n-places in the sequence, we know that n messages are lost
	///// </summary>
	//byte ControlSequence[10] = { 0,1,2,3,4,5,6,7,8,9 };
	//
	///// <summary>
	///// Performs check if any messages are lost by comparing ControlValue (taken from message data) with ControlSequence
	///// </summary>
	///// <param name="ControlValue">The control value.</param>
	//void ControlCall(byte ControlValue);
	//
	///// <summary>
	///// Loop method
	///// </summary>
	//bool Evaluate();




	LinkQualityMetrics();
	~LinkQualityMetrics();
};

