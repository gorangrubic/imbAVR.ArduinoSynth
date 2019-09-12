#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "SPI.h"

#include "spiLinkBuffer.h"


template<typename TData>
class spiSender
{	
	/// <summary>
	/// Chip-select pin
	/// </summary>
	byte pinSS;

	byte pinSSPostDelay = 10;

public:
	spiSender(byte _pinSS);
	void Send(TData data);

};

template<typename TData>
inline spiSender<TData>::spiSender(byte _pinSS)
{
	pinSS = _pinSS;
	pinMode(pinSS, OUTPUT);
}

template<typename TData>
inline void spiSender<TData>::Send(TData data)
{

	spiLinkDataInstance<TData> wrapper;
	wrapper.instance = data;

	digitalWrite(pinSS, LOW);

	for (size_t i = 0; i < sizeof(TData); i++)
	{
		SPI.transfer(wrapper.bytes[i]);
	}
	delay(pinSSPostDelay);
	digitalWrite(pinSS, HIGH);

}
