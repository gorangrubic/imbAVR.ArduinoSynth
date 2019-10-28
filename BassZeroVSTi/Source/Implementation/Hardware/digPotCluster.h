#pragma once

#ifndef _imbAVR_h
#define _imbAVR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#endif

#define DEBUG_CODE

#include <SPI.h>

#include "inttypes.h"

/// <summary>
/// Controls 8 digpots (MPC410-10), using shift register (74CH595N) to save pins on arduino
/// </summary>
class digPotCluster {


	//Pin connected to ST_CP of 74HC595
	byte latchPin = 8;
	//Pin connected to SH_CP of 74HC595
	byte clockPin = 12;
	////Pin connected to DS of 74HC595
	byte dataPin = 11;


	void SetOut(byte data);

public:

	/// <summary>
	/// Sets pins connected to shift register 74HC595N
	/// </summary>
	/// <param name="latch_pin">Latch pin.</param>
	/// <param name="clock_pin">The clock pin.</param>
	/// <param name="data_pin">The data pin.</param>
	void init(byte latch_pin, byte clock_pin, byte data_pin);

	/// <summary>
	/// Values set the last time digpots were updated
	/// </summary>
	byte lastValues[8];

	/// <summary>
	/// Sets values to digpots - if specified value is different from values set last time
	/// </summary>
	/// <param name="dp1">Value for digpot 1</param>
	/// <param name="dp2">Value for digpot 2.</param>
	/// <param name="dp3">Value for digpot 3.</param>
	/// <param name="dp4">Value for digpot 4.</param>
	/// <param name="dp5">Value for digpot 5.</param>
	/// <param name="dp6">Value for digpot 6.</param>
	/// <param name="dp7">Value for digpot 7.</param>
	/// <param name="dp8">Value for digpot 8.</param>
	void Write(byte dp1, byte dp2, byte dp3, byte dp4, byte dp5, byte dp6, byte dp7, byte dp8);

	/// <summary>
	/// Checks if the value differs from stored last value for the digpot specified
	/// </summary>
	/// <param name="dp_id">What dig pot - from 0 to 7</param>
	/// <param name="dp_value">Value to set</param>
	void CheckAndWrite(byte dp_id, byte dp_value);

#ifdef DEBUG_CODE
	void Debug();

#endif


	/// <summary>
	/// Updates value on the digpot, regardless if it differs from stored last value 
	/// </summary>
	/// <param name="dp_id">What dig pot - from 0 to 7</param>
	/// <param name="dp_value">Value to set</param>
	void Write(byte dp_id, byte dp_value);

};